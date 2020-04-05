#include "kube_config_model.h"
#include <stdlib.h>

kubeconfig_auth_provider_t *kubeconfig_auth_provider_create()
{
    kubeconfig_auth_provider_t *provider = calloc(1, sizeof(kubeconfig_auth_provider_t));
    return provider;
}

void kubeconfig_auth_provider_free(kubeconfig_auth_provider_t * provider)
{
    if (!provider) {
        return;
    }

    if (provider->name) {
        free(provider->name);
    }
    if (provider->id_token) {
        free(provider->id_token);
    }
    if (provider->cmd_path) {
        free(provider->cmd_path);
    }
    if (provider->access_token) {
        free(provider->access_token);
    }
    if (provider->expires_on) {
        free(provider->expires_on);
    }
    if (provider->expiry) {
        free(provider->expiry);
    }
    if (provider->idp_certificate_authority_data) {
        free(provider->idp_certificate_authority_data);
    }

    free(provider);
}

kubeconfig_exec_t *kubeconfig_exec_create()
{
    kubeconfig_exec_t *exec = calloc(1, sizeof(kubeconfig_exec_t));
    return exec;
}

void kubeconfig_exec_free(kubeconfig_exec_t * exec)
{
    if (!exec) {
        return;
    }

    if (exec->command) {
        free(exec->command);
    }

    free(exec);
}

kubeconfig_cluster_t *kubeconfig_cluster_create()
{
    kubeconfig_cluster_t *cluster = calloc(1, sizeof(kubeconfig_cluster_t));
    return cluster;
}

void kubeconfig_cluster_free(kubeconfig_cluster_t * cluster)
{
    if (!cluster) {
        return;
    }

    if (cluster->name) {
        free(cluster->name);
    }
    if (cluster->server) {
        free(cluster->server);
    }
    if (cluster->certificate_authority_data) {
        free(cluster->certificate_authority_data);
    }

    free(cluster);
}

kubeconfig_cluster_t **kubeconfig_clusters_create(int clusters_count)
{
    kubeconfig_cluster_t **clusters = (kubeconfig_cluster_t **) calloc(clusters_count, sizeof(kubeconfig_cluster_t *));
    int i = 0;
    for (i = 0; i < clusters_count; i++) {
        clusters[i] = kubeconfig_cluster_create();
    }
    return clusters;
}

void kubeconfig_clusters_free(kubeconfig_cluster_t ** clusters, int cluster_count)
{
    if (!clusters) {
        return;
    }

    int i = 0;
    for (i = 0; i < cluster_count; i++) {
        if (clusters[i]) {
            kubeconfig_cluster_free(clusters[i]);
            clusters[i] = NULL;
        }
    }
    free(clusters);
}

kubeconfig_user_t *kubeconfig_user_create()
{
    kubeconfig_user_t *user = calloc(1, sizeof(kubeconfig_user_t));
    return user;
}

void kubeconfig_user_free(kubeconfig_user_t * user)
{
    if (!user) {
        return;
    }

    if (user->name) {
        free(user->name);
    }
    if (user->client_certificate_data) {
        free(user->client_certificate_data);
    }
    if (user->client_key_data) {
        free(user->client_key_data);
    }
    if (user->username) {
        free(user->username);
    }
    if (user->password) {
        free(user->password);
    }
    if (user->auth_provider) {
        kubeconfig_auth_provider_free(user->auth_provider);
    }
    if (user->exec) {
        kubeconfig_exec_free(user->exec);
    }

    free(user);
}

kubeconfig_user_t **kubeconfig_users_create(int users_count)
{
    kubeconfig_user_t **users = (kubeconfig_user_t **) calloc(users_count, sizeof(kubeconfig_user_t *));
    int i = 0;
    for (i = 0; i < users_count; i++) {
        users[i] = kubeconfig_user_create();
    }
    return users;
}

void kubeconfig_users_free(kubeconfig_user_t ** users, int users_count)
{
    if (!users) {
        return;
    }

    int i = 0;
    for (i = 0; i < users_count; i++) {
        if (users[i]) {
            kubeconfig_user_free(users[i]);
            users[i] = NULL;
        }
    }
    free(users);
}

kubeconfig_context_t *kubeconfig_context_create()
{
    kubeconfig_context_t *context = calloc(1, sizeof(kubeconfig_context_t));
    return context;
}

void kubeconfig_context_free(kubeconfig_context_t * context)
{
    if (!context) {
        return;
    }

    if (context->name) {
        free(context->name);
    }
    if (context->cluster) {
        free(context->cluster);
    }
    if (context->user) {
        free(context->user);
    }

    free(context);
}

kubeconfig_context_t **kubeconfig_contexts_create(int contexts_count)
{
    kubeconfig_context_t **contexts = (kubeconfig_context_t **) calloc(contexts_count, sizeof(kubeconfig_context_t *));
    int i = 0;
    for (i = 0; i < contexts_count; i++) {
        contexts[i] = kubeconfig_context_create();
    }
    return contexts;
}

void kubeconfig_contexts_free(kubeconfig_context_t ** contexts, int context_count)
{
    if (!contexts) {
        return;
    }

    int i = 0;
    for (i = 0; i < context_count; i++) {
        if (contexts[i]) {
            kubeconfig_context_free(contexts[i]);
            contexts[i] = NULL;
        }
    }
    free(contexts);
}

kubeconfig_t *kubeconfig_create()
{
    kubeconfig_t *config = calloc(1, sizeof(kubeconfig_t));
    return config;
}

void kubeconfig_free(kubeconfig_t * kubeconfig)
{
    if (!kubeconfig) {
        return;
    }

    if (kubeconfig->fileName) {
        free(kubeconfig->fileName);
    }
    if (kubeconfig->apiVersion) {
        free(kubeconfig->apiVersion);
    }
    if (kubeconfig->kind) {
        free(kubeconfig->kind);
    }
    if (kubeconfig->preferences) {
        free(kubeconfig->preferences);
    }
    if (kubeconfig->current_context) {
        free(kubeconfig->current_context);
    }
    if (kubeconfig->clusters) {
        kubeconfig_clusters_free(kubeconfig->clusters, kubeconfig->clusters_count);
    }
    if (kubeconfig->users) {
        kubeconfig_users_free(kubeconfig->users, kubeconfig->users_count);
    }
    if (kubeconfig->contexts) {
        kubeconfig_contexts_free(kubeconfig->contexts, kubeconfig->contexts_count);
    }

    free(kubeconfig);

}
