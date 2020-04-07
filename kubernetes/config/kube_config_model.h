#ifndef _KUBE_CONFIG_MODEL_H
#define _KUBE_CONFIG_MODEL_H

#ifdef  __cplusplus
extern "C" {
#endif

typedef struct kubeconfig_auth_provider_t {
    char *name;
    char *id_token;
    char *cmd_path;
    char *access_token;
    char *expires_on;
    char *expiry;
    char *idp_certificate_authority_data;
} kubeconfig_auth_provider_t;

typedef struct kubeconfig_exec_t {
    char *command;
} kubeconfig_exec_t;

typedef enum kubeconfig_property_type_t {
    KUBECONFIG_PROPERTY_TYPE_CONTEXT = 1,
    KUBECONFIG_PROPERTY_TYPE_CLUSTER,
    KUBECONFIG_PROPERTY_TYPE_USER
} kubeconfig_property_type_t;

typedef struct kubeconfig_property_t {
    kubeconfig_property_type_t type;
    char *name;
    union {
        struct {            /* context */
            char *cluster;
            char *user;
        };
        struct {            /* cluster */
            char *server;
            char *certificate_authority_data;
        };
        struct {            /* user */
            char *client_certificate_data;
            char *client_key_data;
            kubeconfig_auth_provider_t *auth_provider;
            kubeconfig_exec_t *exec;
            int insecure_skip_tls_verify;
            char *username;
            char *password;
        };
    };
} kubeconfig_property_t;

typedef struct kubeconfig_t {
    char *fileName;
    char *apiVersion;
    char *preferences;
    char *kind;
    char *current_context;
    kubeconfig_property_t **contexts;
    int contexts_count;
    kubeconfig_property_t **clusters;
    int clusters_count;
    kubeconfig_property_t **users;
    int users_count;
} kubeconfig_t;

kubeconfig_auth_provider_t *kubeconfig_auth_provider_create();
void kubeconfig_auth_provider_free(kubeconfig_auth_provider_t * provider);

kubeconfig_exec_t *kubeconfig_exec_create();
void kubeconfig_exec_free(kubeconfig_exec_t * exec);

kubeconfig_property_t *kubeconfig_property_create(kubeconfig_property_type_t type);
void kubeconfig_property_free(kubeconfig_property_t * property);

kubeconfig_property_t **kubeconfig_properties_create(int contexts_count, kubeconfig_property_type_t type);
void kubeconfig_properties_free(kubeconfig_property_t ** properties, int properties_count);

kubeconfig_t *kubeconfig_create();
void kubeconfig_free(kubeconfig_t * kubeconfig);

#ifdef  __cplusplus
}
#endif
#endif                          /* _KUBE_CONFIG_MODEL_H */
