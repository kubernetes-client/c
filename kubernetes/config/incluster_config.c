#define _GNU_SOURCE
#include <stdlib.h>
#ifndef _WIN32
#include <unistd.h>
#endif
#include <sys/stat.h>
#include <errno.h>
#include "incluster_config.h"
#include "kube_config_common.h"

#define SERVICE_HOST_ENV_NAME "KUBERNETES_SERVICE_HOST"
#define SERVICE_PORT_ENV_NAME "KUBERNETES_SERVICE_PORT"
#define SERVICE_HTTPS_PREFIX "https://"
#define SERVICE_TOKEN_FILENAME "/var/run/secrets/kubernetes.io/serviceaccount/token"
#define SERVICE_CERT_FILENAME "/var/run/secrets/kubernetes.io/serviceaccount/ca.crt"

static int checkServiceAccountFile(const char *fileName)
{
    static char fname[] = "checkServiceAccountFile()";

    if (!fileName) {
        fprintf(stderr, "%s: The file name must be specified.\n", fname);
        return -1;
    }

    struct stat info;
    if (-1 == stat(fileName, &info)) {
        switch (errno) {
        case ENOENT:
            fprintf(stderr, "%s: The file %s does not exist.[%s]\n", fname, fileName, strerror(errno));
            return -1;
        case EACCES:
            fprintf(stderr, "%s: No permission to read the file %s.[%s]\n", fname, fileName, strerror(errno));
            return -1;
        default:
            fprintf(stderr, "%s: Cannot retrieve the information of file %s.[%s]\n", fname, fileName, strerror(errno));
            return -1;
        }
    }

    return 0;
}

static int setBasePathInCluster(char **pBasePath)
{
    static char fname[] = "setBasePathInCluster()";

#ifndef _WIN32
    const char *service_host_env = secure_getenv(SERVICE_HOST_ENV_NAME);
#else
    const char *service_host_env = getenv(SERVICE_HOST_ENV_NAME);
#endif
    if (!service_host_env) {
        fprintf(stderr, "%s: Cannot retrieve the kubernetes service host inside a pod by the env %s.\n", fname, SERVICE_HOST_ENV_NAME);
        return -1;
    }
#ifndef _WIN32
    const char *service_port_env = secure_getenv(SERVICE_PORT_ENV_NAME);
#else
    const char *service_port_env = getenv(SERVICE_PORT_ENV_NAME);
#endif
    if (!service_port_env) {
        fprintf(stderr, "%s: Cannot retrieve the kubernetes service port inside a pod by the env %s.\n", fname, SERVICE_PORT_ENV_NAME);
        return -1;
    }

    int basePathSize = strlen(SERVICE_HTTPS_PREFIX) + strlen(service_host_env) + strlen(service_port_env) + 2 /* 1 for ':', 1 for '\0' */ ;
    char *basePath = calloc(basePathSize, sizeof(char));
    if (!basePath) {
        fprintf(stderr, "%s: Cannot allocate the memory for base path for kubernetes service.\n", fname);
        return -1;
    }

    snprintf(basePath, basePathSize, "%s%s:%s", SERVICE_HTTPS_PREFIX, service_host_env, service_port_env);
    *pBasePath = basePath;
    return 0;
}

static int setSslConfigInCluster(sslConfig_t ** pSslConfig, const char *caFileName)
{
    static char fname[] = "setSslConfigInCluster()";

    if (0 != checkServiceAccountFile(caFileName)) {
        fprintf(stderr, "%s: Cannot retrieve the CA for kubernetes service in the pod.\n", fname);
        return -1;
    }

    sslConfig_t *sc = sslConfig_create(NULL,    /* client certificate */
                                       NULL,    /* client private key */
                                       caFileName,  /* CA file */
                                       0    /* 0 means the server certificate is required to be verified by CA */
        );
    if (!sc) {
        return -1;
    }

    *pSslConfig = sc;
    return 0;
}

static int readTokenInCluster(char *token, int token_buf_size)
{
    static char fname[] = "readTokenInCluster()";

    if (0 != checkServiceAccountFile(SERVICE_TOKEN_FILENAME)) {
        fprintf(stderr, "%s: Cannot retrieve the token for kubernetes service in the pod.\n", fname);
        return -1;
    }

    FILE *fp;
    fp = fopen(SERVICE_TOKEN_FILENAME, "r");
    if (NULL == fp) {
        fprintf(stderr, "%s: Failed to open file %s.[%s]", fname, SERVICE_TOKEN_FILENAME, strerror(errno));
        return -1;
    }

    char *read_str = fgets(token, token_buf_size, fp);
    fclose(fp);
    if (NULL == read_str) {
        fprintf(stderr, "%s: Cannot read token from the file %s.[%s]", fname, SERVICE_TOKEN_FILENAME, strerror(errno));
        return -1;
    }

    return 0;
}

static int setApiKeysInCluster(list_t ** pApiKeys)
{
    static char fname[] = "setApiKeysInCluster()";

    list_t *apiKeys = list_create();
    if (!apiKeys) {
        fprintf(stderr, "%s: Cannot allocate the memory for api kyes for kubernetes service.\n", fname);
        return -1;
    }

    char token[BEARER_TOKEN_BUFFER_SIZE];
    memset(token, 0, sizeof(token));
    if (0 == readTokenInCluster(token, BEARER_TOKEN_BUFFER_SIZE)) {
        char tokenValue[BEARER_TOKEN_BUFFER_SIZE];
        memset(tokenValue, 0, sizeof(tokenValue));
        snprintf(tokenValue, BEARER_TOKEN_BUFFER_SIZE, BEARER_TOKEN_TEMPLATE, token);
        keyValuePair_t *keyPairToken = keyValuePair_create(strdup(AUTH_TOKEN_KEY), strdup(tokenValue));
        list_addElement(apiKeys, keyPairToken);
    } else {
        fprintf(stderr, "%s: Cannot retrieve the service token in the pod.", fname);
        return -1;
    }

    *pApiKeys = apiKeys;
    return 0;
}

int load_incluster_config(char **pBasePath, sslConfig_t ** pSslConfig, list_t ** pApiKeys)
{
    static char fname[] = "load_incluster_config()";

    if (0 != setBasePathInCluster(pBasePath)) {
        fprintf(stderr, "%s: Cannot set the base path for API server inside cluster.\n", fname);
        return -1;
    }

    if (0 != setSslConfigInCluster(pSslConfig, SERVICE_CERT_FILENAME)) {
        fprintf(stderr, "%s: Cannot set the SSL Configuration for the client inside cluster.\n", fname);
        return -1;
    }

    if (0 != setApiKeysInCluster(pApiKeys)) {
        fprintf(stderr, "%s: Cannot set the service tokens for the client inside cluster.\n", fname);
        return -1;
    }

    return 0;
}
