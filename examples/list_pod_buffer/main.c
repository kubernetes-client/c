#include <config/kube_config.h>
#include <api/CoreV1API.h>
#include <stdio.h>

#define ENV_KUBECONFIG "KUBECONFIG"
#ifndef _WIN32
#define ENV_HOME "HOME"
#else
#define ENV_HOME "USERPROFILE"
#endif

#define KUBE_CONFIG_DEFAULT_LOCATION "%s/.kube/config"

static char *getWorkingConfigFile(const char *configFileNamePassedIn)
{
    char *configFileName = NULL;
    const char *kubeconfig_env = NULL;
    const char *homedir_env = NULL;

    if (configFileNamePassedIn) {
        configFileName = strdup(configFileNamePassedIn);
    } else {
#if defined(HAVE_SECURE_GETENV)
        kubeconfig_env = secure_getenv(ENV_KUBECONFIG);
#elif defined(HAVE_GETENV)
        kubeconfig_env = getenv(ENV_KUBECONFIG);
#endif
        if (kubeconfig_env) {
            configFileName = strdup(kubeconfig_env);
        } else {
#if defined(HAVE_SECURE_GETENV)
            homedir_env = secure_getenv(ENV_HOME);
#elif defined(HAVE_GETENV)
            homedir_env = getenv(ENV_HOME);
#endif
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

static char *getFileData(const char *filePath)
{
    char *data = NULL;
    char *kubeConfigFile = getWorkingConfigFile(filePath);
    if (kubeConfigFile) {
        FILE *kubeFile = fopen(kubeConfigFile, "r");
        if (kubeFile) {
            fseek(kubeFile, 0, SEEK_END);
            long fsize = ftell(kubeFile);
            fseek(kubeFile, 0, SEEK_SET);

            data = calloc(1, fsize + 1);
            if (data) {
                fread(data, 1, fsize, kubeFile);
            }

            fclose(kubeFile);
        } else {
            printf("Could not open %s!\n", kubeConfigFile);
        }

        free(kubeConfigFile);
    } else {
        printf("Could not determine the path to kubernetes configuration file! Tried: ENV_KUBECONFIG = %s and ENV_HOME = %s\n",
            getenv(ENV_KUBECONFIG), getenv(ENV_HOME) );
    }
    

    return data;
}

void list_pod(apiClient_t * apiClient)
{
    v1_pod_list_t *pod_list = NULL;
    pod_list = CoreV1API_listNamespacedPod(apiClient, "default",    /*namespace */
                                           NULL,    /* pretty */
                                           NULL,    /* allowWatchBookmarks */
                                           NULL,    /* continue */
                                           NULL,    /* fieldSelector */
                                           NULL,    /* labelSelector */
                                           NULL,    /* limit */
                                           NULL,    /* resourceVersion */
                                           NULL,    /* resourceVersionMatch */
                                           NULL,    /* sendInitialEvents */
                                           NULL,    /* timeoutSeconds */
                                           NULL /* watch */
        );
    printf("The return code of HTTP request=%ld\n", apiClient->response_code);
    if (pod_list) {
        printf("Get pod list:\n");
        listEntry_t *listEntry = NULL;
        v1_pod_t *pod = NULL;
        list_ForEach(listEntry, pod_list->items) {
            pod = listEntry->data;
            printf("\tThe pod name: %s\n", pod->metadata->name);
        }
        v1_pod_list_free(pod_list);
        pod_list = NULL;
    } else {
        printf("Cannot get any pod.\n");
    }
}

int main()
{
    char *basePath = NULL;
    sslConfig_t *sslConfig = NULL;
    list_t *apiKeys = NULL;

    char *dataBuffer = getFileData(NULL);   /* NULL means loading configuration from $HOME/.kube/config */
    if (dataBuffer == NULL) {
        printf("Cannot get kubernetes configuration from file.\n");
        return -1;
    }

    int rc = load_kube_config_buffer(&basePath, &sslConfig, &apiKeys, dataBuffer);
    if (rc != 0) {
        printf("Cannot load kubernetes configuration.\n");
        return -1;
    }
    apiClient_t *apiClient = apiClient_create_with_base_path(basePath, sslConfig, apiKeys);
    if (!apiClient) {
        printf("Cannot create a kubernetes client.\n");
        return -1;
    }

    list_pod(apiClient);

    apiClient_free(apiClient);
    apiClient = NULL;
    free_client_config(basePath, sslConfig, apiKeys);
    basePath = NULL;
    sslConfig = NULL;
    apiKeys = NULL;
    apiClient_unsetupGlobalEnv();
    free(dataBuffer);
    dataBuffer = NULL;

    return 0;
}
