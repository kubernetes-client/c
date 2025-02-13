#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_volume_projection.h"



static v1_volume_projection_t *v1_volume_projection_create_internal(
    v1_cluster_trust_bundle_projection_t *cluster_trust_bundle,
    v1_config_map_projection_t *config_map,
    v1_downward_api_projection_t *downward_api,
    v1_secret_projection_t *secret,
    v1_service_account_token_projection_t *service_account_token
    ) {
    v1_volume_projection_t *v1_volume_projection_local_var = malloc(sizeof(v1_volume_projection_t));
    if (!v1_volume_projection_local_var) {
        return NULL;
    }
    v1_volume_projection_local_var->cluster_trust_bundle = cluster_trust_bundle;
    v1_volume_projection_local_var->config_map = config_map;
    v1_volume_projection_local_var->downward_api = downward_api;
    v1_volume_projection_local_var->secret = secret;
    v1_volume_projection_local_var->service_account_token = service_account_token;

    v1_volume_projection_local_var->_library_owned = 1;
    return v1_volume_projection_local_var;
}

__attribute__((deprecated)) v1_volume_projection_t *v1_volume_projection_create(
    v1_cluster_trust_bundle_projection_t *cluster_trust_bundle,
    v1_config_map_projection_t *config_map,
    v1_downward_api_projection_t *downward_api,
    v1_secret_projection_t *secret,
    v1_service_account_token_projection_t *service_account_token
    ) {
    return v1_volume_projection_create_internal (
        cluster_trust_bundle,
        config_map,
        downward_api,
        secret,
        service_account_token
        );
}

void v1_volume_projection_free(v1_volume_projection_t *v1_volume_projection) {
    if(NULL == v1_volume_projection){
        return ;
    }
    if(v1_volume_projection->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_volume_projection_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_volume_projection->cluster_trust_bundle) {
        v1_cluster_trust_bundle_projection_free(v1_volume_projection->cluster_trust_bundle);
        v1_volume_projection->cluster_trust_bundle = NULL;
    }
    if (v1_volume_projection->config_map) {
        v1_config_map_projection_free(v1_volume_projection->config_map);
        v1_volume_projection->config_map = NULL;
    }
    if (v1_volume_projection->downward_api) {
        v1_downward_api_projection_free(v1_volume_projection->downward_api);
        v1_volume_projection->downward_api = NULL;
    }
    if (v1_volume_projection->secret) {
        v1_secret_projection_free(v1_volume_projection->secret);
        v1_volume_projection->secret = NULL;
    }
    if (v1_volume_projection->service_account_token) {
        v1_service_account_token_projection_free(v1_volume_projection->service_account_token);
        v1_volume_projection->service_account_token = NULL;
    }
    free(v1_volume_projection);
}

cJSON *v1_volume_projection_convertToJSON(v1_volume_projection_t *v1_volume_projection) {
    cJSON *item = cJSON_CreateObject();

    // v1_volume_projection->cluster_trust_bundle
    if(v1_volume_projection->cluster_trust_bundle) {
    cJSON *cluster_trust_bundle_local_JSON = v1_cluster_trust_bundle_projection_convertToJSON(v1_volume_projection->cluster_trust_bundle);
    if(cluster_trust_bundle_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "clusterTrustBundle", cluster_trust_bundle_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_volume_projection->config_map
    if(v1_volume_projection->config_map) {
    cJSON *config_map_local_JSON = v1_config_map_projection_convertToJSON(v1_volume_projection->config_map);
    if(config_map_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "configMap", config_map_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_volume_projection->downward_api
    if(v1_volume_projection->downward_api) {
    cJSON *downward_api_local_JSON = v1_downward_api_projection_convertToJSON(v1_volume_projection->downward_api);
    if(downward_api_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "downwardAPI", downward_api_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_volume_projection->secret
    if(v1_volume_projection->secret) {
    cJSON *secret_local_JSON = v1_secret_projection_convertToJSON(v1_volume_projection->secret);
    if(secret_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "secret", secret_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_volume_projection->service_account_token
    if(v1_volume_projection->service_account_token) {
    cJSON *service_account_token_local_JSON = v1_service_account_token_projection_convertToJSON(v1_volume_projection->service_account_token);
    if(service_account_token_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "serviceAccountToken", service_account_token_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_volume_projection_t *v1_volume_projection_parseFromJSON(cJSON *v1_volume_projectionJSON){

    v1_volume_projection_t *v1_volume_projection_local_var = NULL;

    // define the local variable for v1_volume_projection->cluster_trust_bundle
    v1_cluster_trust_bundle_projection_t *cluster_trust_bundle_local_nonprim = NULL;

    // define the local variable for v1_volume_projection->config_map
    v1_config_map_projection_t *config_map_local_nonprim = NULL;

    // define the local variable for v1_volume_projection->downward_api
    v1_downward_api_projection_t *downward_api_local_nonprim = NULL;

    // define the local variable for v1_volume_projection->secret
    v1_secret_projection_t *secret_local_nonprim = NULL;

    // define the local variable for v1_volume_projection->service_account_token
    v1_service_account_token_projection_t *service_account_token_local_nonprim = NULL;

    // v1_volume_projection->cluster_trust_bundle
    cJSON *cluster_trust_bundle = cJSON_GetObjectItemCaseSensitive(v1_volume_projectionJSON, "clusterTrustBundle");
    if (cJSON_IsNull(cluster_trust_bundle)) {
        cluster_trust_bundle = NULL;
    }
    if (cluster_trust_bundle) { 
    cluster_trust_bundle_local_nonprim = v1_cluster_trust_bundle_projection_parseFromJSON(cluster_trust_bundle); //nonprimitive
    }

    // v1_volume_projection->config_map
    cJSON *config_map = cJSON_GetObjectItemCaseSensitive(v1_volume_projectionJSON, "configMap");
    if (cJSON_IsNull(config_map)) {
        config_map = NULL;
    }
    if (config_map) { 
    config_map_local_nonprim = v1_config_map_projection_parseFromJSON(config_map); //nonprimitive
    }

    // v1_volume_projection->downward_api
    cJSON *downward_api = cJSON_GetObjectItemCaseSensitive(v1_volume_projectionJSON, "downwardAPI");
    if (cJSON_IsNull(downward_api)) {
        downward_api = NULL;
    }
    if (downward_api) { 
    downward_api_local_nonprim = v1_downward_api_projection_parseFromJSON(downward_api); //nonprimitive
    }

    // v1_volume_projection->secret
    cJSON *secret = cJSON_GetObjectItemCaseSensitive(v1_volume_projectionJSON, "secret");
    if (cJSON_IsNull(secret)) {
        secret = NULL;
    }
    if (secret) { 
    secret_local_nonprim = v1_secret_projection_parseFromJSON(secret); //nonprimitive
    }

    // v1_volume_projection->service_account_token
    cJSON *service_account_token = cJSON_GetObjectItemCaseSensitive(v1_volume_projectionJSON, "serviceAccountToken");
    if (cJSON_IsNull(service_account_token)) {
        service_account_token = NULL;
    }
    if (service_account_token) { 
    service_account_token_local_nonprim = v1_service_account_token_projection_parseFromJSON(service_account_token); //nonprimitive
    }


    v1_volume_projection_local_var = v1_volume_projection_create_internal (
        cluster_trust_bundle ? cluster_trust_bundle_local_nonprim : NULL,
        config_map ? config_map_local_nonprim : NULL,
        downward_api ? downward_api_local_nonprim : NULL,
        secret ? secret_local_nonprim : NULL,
        service_account_token ? service_account_token_local_nonprim : NULL
        );

    return v1_volume_projection_local_var;
end:
    if (cluster_trust_bundle_local_nonprim) {
        v1_cluster_trust_bundle_projection_free(cluster_trust_bundle_local_nonprim);
        cluster_trust_bundle_local_nonprim = NULL;
    }
    if (config_map_local_nonprim) {
        v1_config_map_projection_free(config_map_local_nonprim);
        config_map_local_nonprim = NULL;
    }
    if (downward_api_local_nonprim) {
        v1_downward_api_projection_free(downward_api_local_nonprim);
        downward_api_local_nonprim = NULL;
    }
    if (secret_local_nonprim) {
        v1_secret_projection_free(secret_local_nonprim);
        secret_local_nonprim = NULL;
    }
    if (service_account_token_local_nonprim) {
        v1_service_account_token_projection_free(service_account_token_local_nonprim);
        service_account_token_local_nonprim = NULL;
    }
    return NULL;

}
