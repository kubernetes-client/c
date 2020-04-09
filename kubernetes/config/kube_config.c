#define _GNU_SOURCE
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include "kube_config.h"
#include "kube_config_yaml.h"

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

static char *kubeconfig_mk_cert_key_tempfile(const char *b64data)
{
    static char fname[] = "kubeconfig_mk_tempfile()";

    int decoded_bytes = 0;
    char *b64decode = base64decode(b64data, strlen(b64data), &decoded_bytes);
    if (!b64decode || 0 == decoded_bytes) {
        fprintf(stderr, "%s: Base64 decodes failed.\n", fname);
        return NULL;
    }

    char tempfile_name_template[] = KUBE_CONFIG_TEMPFILE_NAME_TEMPLATE;
    int fd = mkstemp(tempfile_name_template);
    if (-1 == fd) {
        fprintf(stderr, "%s: Creating temp file for kubeconfig failed with error [%s]\n", fname, strerror(errno));
        return NULL;
    }

    int rc = write(fd, b64decode, decoded_bytes);
    close(fd);
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

static int setApiKeys(list_t ** pApiKeys, const kubeconfig_property_t * user)
{
    list_t *apiKeys = list_create();
    if (apiKeys) {

        /* under development for the token based authentication */

        *pApiKeys = apiKeys;
        return 0;
    }
    return -1;
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

static const kubeconfig_property_t *kubeconfig_get_current_property(kubeconfig_property_t ** properties, int properties_count, const char *property_name)
{
    const kubeconfig_property_t *current_property = NULL;

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

int load_kube_config(char **pBasePath, sslConfig_t ** pSslConfig, list_t ** pApiKeys, const char *configFileName)
{
    static char fname[] = "load_kube_config()";

    int rc = 0;

    const kubeconfig_property_t *current_context = NULL;
    const kubeconfig_property_t *current_cluster = NULL;
    const kubeconfig_property_t *current_user = NULL;

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

    if (current_user) {
        rc = setApiKeys(pApiKeys, current_user);
        if (0 != rc) {
            fprintf(stderr, "%s: Cannot set the tokens for the client.\n", fname);
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
        list_free(apiKeys);
    }
}
