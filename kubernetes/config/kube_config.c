#define _GNU_SOURCE
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <libgen.h>
#include <stdbool.h>
#include "kube_config.h"
#include "kube_config_yaml.h"
#include "kube_config_common.h"
#include "exec_provider.h"

#define ENV_KUBECONFIG "KUBECONFIG"
#define ENV_HOME "HOME"
#define KUBE_CONFIG_DEFAULT_LOCATION "%s/.kube/config"
#define KUBE_CONFIG_TEMPFILE_NAME_TEMPLATE "/tmp/kubeconfig-XXXXXX"

static int setBasePath(char **pBasePath, char *basePath)
{
    char *_basePath = strdup(basePath);
    if (_basePath) {
        *pBasePath = _basePath;
        return 0;
    }
    return -1;
}

static bool is_cert_or_key_base64_encoded(const char *data)
{
    if (NULL == strstr(data, "BEGIN")) {
        return true;
    } else {
        return false;           // e.g. "-----BEGIN CERTIFICATE-----\n...\n-----END CERTIFICATE-----"
    }
}

static char *kubeconfig_mk_cert_key_tempfile(const char *data)
{
    static char fname[] = "kubeconfig_mk_tempfile()";

    const char *cert_key_data = NULL;
    int cert_key_data_bytes = 0;

    bool is_data_base64_encoded = is_cert_or_key_base64_encoded(data);
    if (true == is_data_base64_encoded) {
        int decoded_bytes = 0;
        char *b64decode = base64decode(data, strlen(data), &decoded_bytes);
        if (!b64decode || 0 == decoded_bytes) {
            fprintf(stderr, "%s: Base64 decodes failed.\n", fname);
            return NULL;
        }
        cert_key_data = b64decode;
        cert_key_data_bytes = decoded_bytes;
    } else {                    // plain text, no need base64 decode
        cert_key_data = data;
        cert_key_data_bytes = strlen(cert_key_data);
    }

    char tempfile_name_template[] = KUBE_CONFIG_TEMPFILE_NAME_TEMPLATE;
    int fd = mkstemp(tempfile_name_template);
    if (-1 == fd) {
        fprintf(stderr, "%s: Creating temp file for kubeconfig failed with error [%s]\n", fname, strerror(errno));
        return NULL;
    }

    int rc = write(fd, cert_key_data, cert_key_data_bytes);
    close(fd);
    if (true == is_data_base64_encoded && cert_key_data) {
        free((char *) cert_key_data);   // cast "const char *" to "char *" 
        cert_key_data = NULL;
    }
    if (-1 == rc) {
        fprintf(stderr, "%s: Writing temp file failed with error [%s]\n", fname, strerror(errno));
        return NULL;
    }

    return strdup(tempfile_name_template);
}

static void kubeconfig_rm_tempfile(const char *filename)
{
    if (filename) {
        unlink(filename);
    }
}

static void unsetSslConfig(sslConfig_t * sslConfig)
{
    if (!sslConfig) {
        return;
    }

    if (sslConfig->clientCertFile) {
        kubeconfig_rm_tempfile(sslConfig->clientCertFile);
    }
    if (sslConfig->clientKeyFile) {
        kubeconfig_rm_tempfile(sslConfig->clientKeyFile);
    }
    if (sslConfig->CACertFile) {
        kubeconfig_rm_tempfile(sslConfig->CACertFile);
    }
}

static int setSslConfig(sslConfig_t ** pSslConfig, const kubeconfig_property_t * cluster, const kubeconfig_property_t * user)
{
    int rc = 0;
    char *client_cert_file = NULL;
    char *client_key_file = NULL;
    char *ca_file = NULL;
    int insecure_skip_tls_verify = 0;

    if (user) {
        if (user->client_certificate_data) {
            client_cert_file = kubeconfig_mk_cert_key_tempfile(user->client_certificate_data);
        }
        if (user->client_key_data) {
            client_key_file = kubeconfig_mk_cert_key_tempfile(user->client_key_data);
        }
        insecure_skip_tls_verify = user->insecure_skip_tls_verify;
    }

    if (cluster) {
        if ((0 == insecure_skip_tls_verify) && (cluster->certificate_authority_data)) {
            ca_file = kubeconfig_mk_cert_key_tempfile(cluster->certificate_authority_data);
        }
    }

    sslConfig_t *sc = sslConfig_create(client_cert_file, client_key_file, ca_file, insecure_skip_tls_verify);
    if (sc) {
        *pSslConfig = sc;
    } else {
        rc = -1;
    }

    if (client_cert_file) {
        free(client_cert_file);
    }
    if (client_key_file) {
        free(client_key_file);
    }
    if (ca_file) {
        free(ca_file);
    }

    return rc;
}

static int setApiKeys(list_t ** pApiKeys, const char *token)
{
    static char fname[] = "setApiKeys()";

    list_t *apiKeys = list_create();
    if (!apiKeys) {
        fprintf(stderr, "%s: Cannot allocate the memory for api key list for kubernetes service.\n", fname);
        return -1;
    }

    char tokenValue[BEARER_TOKEN_BUFFER_SIZE];
    memset(tokenValue, 0, sizeof(tokenValue));
    snprintf(tokenValue, BEARER_TOKEN_BUFFER_SIZE, BEARER_TOKEN_TEMPLATE, token);
    keyValuePair_t *keyPairToken = keyValuePair_create(strdup(AUTH_TOKEN_KEY), strdup(tokenValue));
    list_addElement(apiKeys, keyPairToken);

    *pApiKeys = apiKeys;
    return 0;
}

static char *getWorkingConfigFile(const char *configFileNamePassedIn)
{
    char *configFileName = NULL;
    const char *kubeconfig_env = NULL;
    const char *homedir_env = NULL;

    if (configFileNamePassedIn) {
        configFileName = strdup(configFileNamePassedIn);
    } else {
        kubeconfig_env = secure_getenv(ENV_KUBECONFIG);
        if (kubeconfig_env) {
            configFileName = strdup(kubeconfig_env);
        } else {
            homedir_env = secure_getenv(ENV_HOME);
            if (homedir_env) {
                int configFileNameSize = strlen(homedir_env) + strlen(KUBE_CONFIG_DEFAULT_LOCATION) + 1;
                configFileName = calloc(configFileNameSize, sizeof(char));
                if (configFileName) {
                    snprintf(configFileName, configFileNameSize, KUBE_CONFIG_DEFAULT_LOCATION, homedir_env);
                }
            }
        }
    }

    return configFileName;
}

static kubeconfig_property_t *kubeconfig_get_current_property(kubeconfig_property_t ** properties, int properties_count, const char *property_name)
{
    kubeconfig_property_t *current_property = NULL;

    if (NULL == properties || NULL == property_name) {
        return NULL;
    }

    for (int i = 0; i < properties_count; i++) {
        if (0 == strcmp(properties[i]->name, property_name)) {
            current_property = properties[i];
            break;
        }
    }

    return current_property;
}

static int kubeconfig_exec(kubeconfig_property_t * current_user)
{
    static char fname[] = "kubeconfig_exec()";
    int rc = 0;

    ExecCredential_t *exec_output = exec_credential_create();
    if (!exec_output) {
        fprintf(stderr, "%s: Cannot allocate memory for exec credential.[%s]\n", fname, strerror(errno));
        return -1;
    }

    rc = kube_exec_and_get_result(exec_output, current_user->exec);
    if (0 != rc) {
        fprintf(stderr, "%s: The kubeconfig exec failed.\n", fname);
        goto end;
    }
    if (!exec_output->status) {
        rc = -1;
        fprintf(stderr, "%s: The kubeconfig exec result is not valid.\n", fname);
        goto end;
    }
    if (EXEC_CREDENTIAL_TYPE_TOKEN == exec_output->status->type && exec_output->status->token) {
        current_user->token = strdup(exec_output->status->token);
    } else if (exec_output->status->clientCertificateData && exec_output->status->clientKeyData) {
        current_user->client_certificate_data = strdup(exec_output->status->clientCertificateData);
        current_user->client_key_data = strdup(exec_output->status->clientKeyData);
    } else {
        rc = -1;
        fprintf(stderr, "%s: Cannot get the authentication infomation from the kubeconfig exec result.\n", fname);
        goto end;
    }

  end:
    exec_credential_free(exec_output);
    exec_output = NULL;
    return rc;
}

static int kubeconfig_update_exec_command_path(kubeconfig_property_t * exec, const char *kube_config_file)
{
    static char fname[] = "kubeconfig_update_exec_command_path()";
    int rc = 0;

    if (!exec->command || 0 == strlen(exec->command)) {
        return 0;
    }

    char *kube_config_file_copy = NULL;
    char *original_command = NULL;
    if ('/' != exec->command[0]) {  // relative path e.g. "./bin/" or "bin/"
        kube_config_file_copy = strdup(kube_config_file);
        if (NULL == kube_config_file_copy) {
            fprintf(stderr, "%s: Cannot allocate memory for temp kube config file name.[%s]\n", fname, strerror(errno));
            return -1;
        }
        const char *kube_config_dirname = dirname(kube_config_file_copy);
        original_command = exec->command;
        int new_command_length = strlen(kube_config_dirname) + strlen("/") + strlen(original_command) + 1 /* 1 for the terminal of string */ ;
        exec->command = calloc(1, new_command_length);
        if (!exec->command) {
            fprintf(stderr, "%s: Cannot allocate memory for exec new command.[%s]\n", fname, strerror(errno));
            exec->command = original_command;   //restore original exec->command, its memory will be freed outside
            rc = -1;
            goto end;
        }
        snprintf(exec->command, new_command_length, "%s/%s", kube_config_dirname, original_command);
        if (original_command) {
            free(original_command);
        }
    }

  end:
    if (kube_config_file_copy) {
        free(kube_config_file_copy);
        kube_config_file_copy = NULL;
    }

    return rc;
}

int load_kube_config(char **pBasePath, sslConfig_t ** pSslConfig, list_t ** pApiKeys, const char *configFileName)
{
    static char fname[] = "load_kube_config()";
    int rc = 0;
    const kubeconfig_property_t *current_context = NULL;
    const kubeconfig_property_t *current_cluster = NULL;
    kubeconfig_property_t *current_user = NULL;

    kubeconfig_t *kubeconfig = kubeconfig_create();
    if (!kubeconfig) {
        fprintf(stderr, "%s: Cannot create kubeconfig.[%s]\n", fname, strerror(errno));
        return -1;
    }

    kubeconfig->fileName = getWorkingConfigFile(configFileName);
    rc = kubeyaml_load_kubeconfig(kubeconfig);
    if (0 != rc) {
        fprintf(stderr, "%s: Cannot load the kubeconfig %s\n", fname, kubeconfig->fileName);
        rc = -1;
        goto end;
    }

    current_context = kubeconfig_get_current_property(kubeconfig->contexts, kubeconfig->contexts_count, kubeconfig->current_context);
    if (!current_context) {
        fprintf(stderr, "%s: Cannot get the current context by the kubeconfig.\n", fname);
        rc = -1;
        goto end;
    }

    current_cluster = kubeconfig_get_current_property(kubeconfig->clusters, kubeconfig->clusters_count, current_context->cluster);
    if (!current_cluster) {
        fprintf(stderr, "%s: Cannot get the current cluster information by the kubeconfig.\n", fname);
        rc = -1;
        goto end;
    }

    current_user = kubeconfig_get_current_property(kubeconfig->users, kubeconfig->users_count, current_context->user);
    if (!current_user) {
        fprintf(stderr, "%s: Cannot get the current user information by the kubeconfig.\n", fname);
        rc = -1;
        goto end;
    }

    if (current_user && current_user->exec) {
        rc = kubeconfig_update_exec_command_path(current_user->exec, kubeconfig->fileName);
        if (0 != rc) {
            fprintf(stderr, "%s: Cannot update exec command path.\n", fname);
            goto end;
        }
        rc = kubeconfig_exec(current_user);
        if (0 != rc) {
            fprintf(stderr, "%s: Cannot exec command in kubeconfig.\n", fname);
            goto end;
        }
    }

    if (current_cluster && current_cluster->server) {
        rc = setBasePath(pBasePath, current_cluster->server);
        if (0 != rc) {
            fprintf(stderr, "%s: Cannot set the base path for API server.\n", fname);
            goto end;
        }
    }

    if (current_cluster || current_user) {
        rc = setSslConfig(pSslConfig, current_cluster, current_user);
        if (0 != rc) {
            fprintf(stderr, "%s: Cannot set the SSL Configuration for the client.\n", fname);
            goto end;
        }
    }

    if (current_user && current_user->token) {
        rc = setApiKeys(pApiKeys, current_user->token);
        if (0 != rc) {
            fprintf(stderr, "%s: Cannot set token for the client.\n", fname);
            goto end;
        }
    }

  end:
    kubeconfig_free(kubeconfig);
    kubeconfig = NULL;
    return rc;
}

void free_client_config(char *basePath, sslConfig_t * sslConfig, list_t * apiKeys)
{
    if (basePath) {
        free(basePath);
    }

    if (sslConfig) {
        unsetSslConfig(sslConfig);
        sslConfig_free(sslConfig);
    }

    if (apiKeys) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, apiKeys) {
            keyValuePair_t *pair = listEntry->data;
            if (pair->key) {
                free(pair->key);
            }
            if (pair->value) {
                free(pair->value);
            }
            keyValuePair_free(pair);
        }
        list_free(apiKeys);
    }
}
