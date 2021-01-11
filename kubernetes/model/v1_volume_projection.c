#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_volume_projection.h"



v1_volume_projection_t *v1_volume_projection_create(
    v1_config_map_projection_t *config_map,
    v1_downward_api_projection_t *downward_api,
    v1_secret_projection_t *secret,
    v1_service_account_token_projection_t *service_account_token
    ) {
    v1_volume_projection_t *v1_volume_projection_local_var = malloc(sizeof(v1_volume_projection_t));
    if (!v1_volume_projection_local_var) {
        return NULL;
    }
    v1_volume_projection_local_var->config_map = config_map;
    v1_volume_projection_local_var->downward_api = downward_api;
    v1_volume_projection_local_var->secret = secret;
    v1_volume_projection_local_var->service_account_token = service_account_token;

    return v1_volume_projection_local_var;
}


void v1_volume_projection_free(v1_volume_projection_t *v1_volume_projection) {
    if(NULL == v1_volume_projection){
        return ;
    }
    listEntry_t *listEntry;
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

    // v1_volume_projection->config_map
    cJSON *config_map = cJSON_GetObjectItemCaseSensitive(v1_volume_projectionJSON, "configMap");
    v1_config_map_projection_t *config_map_local_nonprim = NULL;
    if (config_map) { 
    config_map_local_nonprim = v1_config_map_projection_parseFromJSON(config_map); //nonprimitive
    }

    // v1_volume_projection->downward_api
    cJSON *downward_api = cJSON_GetObjectItemCaseSensitive(v1_volume_projectionJSON, "downwardAPI");
    v1_downward_api_projection_t *downward_api_local_nonprim = NULL;
    if (downward_api) { 
    downward_api_local_nonprim = v1_downward_api_projection_parseFromJSON(downward_api); //nonprimitive
    }

    // v1_volume_projection->secret
    cJSON *secret = cJSON_GetObjectItemCaseSensitive(v1_volume_projectionJSON, "secret");
    v1_secret_projection_t *secret_local_nonprim = NULL;
    if (secret) { 
    secret_local_nonprim = v1_secret_projection_parseFromJSON(secret); //nonprimitive
    }

    // v1_volume_projection->service_account_token
    cJSON *service_account_token = cJSON_GetObjectItemCaseSensitive(v1_volume_projectionJSON, "serviceAccountToken");
    v1_service_account_token_projection_t *service_account_token_local_nonprim = NULL;
    if (service_account_token) { 
    service_account_token_local_nonprim = v1_service_account_token_projection_parseFromJSON(service_account_token); //nonprimitive
    }


    v1_volume_projection_local_var = v1_volume_projection_create (
        config_map ? config_map_local_nonprim : NULL,
        downward_api ? downward_api_local_nonprim : NULL,
        secret ? secret_local_nonprim : NULL,
        service_account_token ? service_account_token_local_nonprim : NULL
        );

    return v1_volume_projection_local_var;
end:
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
