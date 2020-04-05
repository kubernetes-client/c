#ifndef _KUBE_CONFIG_MODEL_H
#define _KUBE_CONFIG_MODEL_H

#ifdef  __cplusplus
extern "C" {
#endif

typedef struct kubeconfig_cluster_t {
    char *name;
    char *server;
    char *certificate_authority_data;
} kubeconfig_cluster_t ;

typedef struct kubeconfig_auth_provider_t {
    char *name;
    char *id_token;
    char *cmd_path;
    char *access_token;
    char *expires_on;
    char *expiry;
    char *idp_certificate_authority_data;
} kubeconfig_auth_provider_t ;

typedef struct kubeconfig_exec_t {
    char *command;
} kubeconfig_exec_t;

typedef struct kubeconfig_user_t {
    char *name;
    char *client_certificate_data;
    char *client_key_data;
    kubeconfig_auth_provider_t *auth_provider;
    kubeconfig_exec_t *exec;
    int insecure_skip_tls_verify;
    char *username;
    char *password;
} kubeconfig_user_t;

typedef struct kubeconfig_context_t {
    char *name;
    char *cluster;
    char *user;
} kubeconfig_context_t ;

typedef struct kubeconfig_t {
    char *fileName;
    char *apiVersion;
    char *preferences;
    char *kind;
    char *current_context;
    kubeconfig_context_t **contexts;
    int  contexts_count;
    kubeconfig_cluster_t **clusters;
    int  clusters_count;
    kubeconfig_user_t **users;
    int  users_count;
} kubeconfig_t;


kubeconfig_auth_provider_t * kubeconfig_auth_provider_create();
void kubeconfig_auth_provider_free(kubeconfig_auth_provider_t *provider);

kubeconfig_exec_t * kubeconfig_exec_create();
void kubeconfig_exec_free(kubeconfig_exec_t *exec);

kubeconfig_cluster_t * kubeconfig_cluster_create();
void kubeconfig_cluster_free(kubeconfig_cluster_t *cluster);
kubeconfig_cluster_t ** kubeconfig_clusters_create(int clusters_count);
void kubeconfig_clusters_free(kubeconfig_cluster_t **clusters, int clusters_count);

kubeconfig_user_t * kubeconfig_user_create();
void kubeconfig_user_free(kubeconfig_user_t *user);
kubeconfig_user_t ** kubeconfig_users_create(int users_count);
void kubeconfig_users_free(kubeconfig_user_t **users, int users_count);

kubeconfig_context_t * kubeconfig_context_create();
void kubeconfig_context_free(kubeconfig_context_t *context);
kubeconfig_context_t ** kubeconfig_contexts_create(int contexts_count);
void kubeconfig_contexts_free(kubeconfig_context_t **contexts, int contexts_count);

kubeconfig_t * kubeconfig_create();
void kubeconfig_free(kubeconfig_t *kubeconfig);

#ifdef  __cplusplus
}
#endif


#endif /* _KUBE_CONFIG_MODEL_H */
