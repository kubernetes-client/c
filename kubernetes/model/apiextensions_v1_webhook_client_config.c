#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "apiextensions_v1_webhook_client_config.h"



static apiextensions_v1_webhook_client_config_t *apiextensions_v1_webhook_client_config_create_internal(
    char *ca_bundle,
    apiextensions_v1_service_reference_t *service,
    char *url
    ) {
    apiextensions_v1_webhook_client_config_t *apiextensions_v1_webhook_client_config_local_var = malloc(sizeof(apiextensions_v1_webhook_client_config_t));
    if (!apiextensions_v1_webhook_client_config_local_var) {
        return NULL;
    }
    memset(apiextensions_v1_webhook_client_config_local_var, 0, sizeof(apiextensions_v1_webhook_client_config_t));
    apiextensions_v1_webhook_client_config_local_var->_library_owned = 1;
    apiextensions_v1_webhook_client_config_local_var->ca_bundle = ca_bundle;
    apiextensions_v1_webhook_client_config_local_var->service = service;
    apiextensions_v1_webhook_client_config_local_var->url = url;
    return apiextensions_v1_webhook_client_config_local_var;
}

__attribute__((deprecated)) apiextensions_v1_webhook_client_config_t *apiextensions_v1_webhook_client_config_create(
    char *ca_bundle,
    apiextensions_v1_service_reference_t *service,
    char *url
    ) {
    apiextensions_v1_webhook_client_config_t *result = apiextensions_v1_webhook_client_config_create_internal (
        ca_bundle,
        service,
        url
        );
    if (!result) {
    }
    return result;
}

void apiextensions_v1_webhook_client_config_free(apiextensions_v1_webhook_client_config_t *apiextensions_v1_webhook_client_config) {
    if(NULL == apiextensions_v1_webhook_client_config){
        return ;
    }
    if(apiextensions_v1_webhook_client_config->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "apiextensions_v1_webhook_client_config_free");
        return ;
    }
    listEntry_t *listEntry;
    if (apiextensions_v1_webhook_client_config->ca_bundle) {
        free(apiextensions_v1_webhook_client_config->ca_bundle);
        apiextensions_v1_webhook_client_config->ca_bundle = NULL;
    }
    if (apiextensions_v1_webhook_client_config->service) {
        apiextensions_v1_service_reference_free(apiextensions_v1_webhook_client_config->service);
        apiextensions_v1_webhook_client_config->service = NULL;
    }
    if (apiextensions_v1_webhook_client_config->url) {
        free(apiextensions_v1_webhook_client_config->url);
        apiextensions_v1_webhook_client_config->url = NULL;
    }
    free(apiextensions_v1_webhook_client_config);
}

cJSON *apiextensions_v1_webhook_client_config_convertToJSON(apiextensions_v1_webhook_client_config_t *apiextensions_v1_webhook_client_config) {
    cJSON *item = cJSON_CreateObject();

    // apiextensions_v1_webhook_client_config->ca_bundle
    if(apiextensions_v1_webhook_client_config->ca_bundle) {
    if(cJSON_AddStringToObject(item, "caBundle", apiextensions_v1_webhook_client_config->ca_bundle) == NULL) {
    goto fail; //ByteArray
    }
    }


    // apiextensions_v1_webhook_client_config->service
    if(apiextensions_v1_webhook_client_config->service) {
    cJSON *service_local_JSON = apiextensions_v1_service_reference_convertToJSON(apiextensions_v1_webhook_client_config->service);
    if(service_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "service", service_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // apiextensions_v1_webhook_client_config->url
    if(apiextensions_v1_webhook_client_config->url) {
    if(cJSON_AddStringToObject(item, "url", apiextensions_v1_webhook_client_config->url) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

apiextensions_v1_webhook_client_config_t *apiextensions_v1_webhook_client_config_parseFromJSON(cJSON *apiextensions_v1_webhook_client_configJSON){

    apiextensions_v1_webhook_client_config_t *apiextensions_v1_webhook_client_config_local_var = NULL;

    char *ca_bundle_local_str = NULL;

    // define the local variable for apiextensions_v1_webhook_client_config->service
    apiextensions_v1_service_reference_t *service_local_nonprim = NULL;

    char *url_local_str = NULL;

    // apiextensions_v1_webhook_client_config->ca_bundle
    cJSON *ca_bundle = cJSON_GetObjectItemCaseSensitive(apiextensions_v1_webhook_client_configJSON, "caBundle");
    if (cJSON_IsNull(ca_bundle)) {
        ca_bundle = NULL;
    }
    if (ca_bundle) { 
    if(!cJSON_IsString(ca_bundle))
    {
    goto end; //ByteArray
    }
    }

    // apiextensions_v1_webhook_client_config->service
    cJSON *service = cJSON_GetObjectItemCaseSensitive(apiextensions_v1_webhook_client_configJSON, "service");
    if (cJSON_IsNull(service)) {
        service = NULL;
    }
    if (service) { 
    service_local_nonprim = apiextensions_v1_service_reference_parseFromJSON(service); //nonprimitive
    }

    // apiextensions_v1_webhook_client_config->url
    cJSON *url = cJSON_GetObjectItemCaseSensitive(apiextensions_v1_webhook_client_configJSON, "url");
    if (cJSON_IsNull(url)) {
        url = NULL;
    }
    if (url) { 
    if(!cJSON_IsString(url) && !cJSON_IsNull(url))
    {
    goto end; //String
    }
    }


    if (ca_bundle) ca_bundle_local_str = strdup(ca_bundle->valuestring);
    if (url && !cJSON_IsNull(url)) url_local_str = strdup(url->valuestring);

    apiextensions_v1_webhook_client_config_local_var = apiextensions_v1_webhook_client_config_create_internal (
        ca_bundle_local_str,
        service ? service_local_nonprim : NULL,
        url_local_str
        );

    if (!apiextensions_v1_webhook_client_config_local_var) {
        goto end;
    }

    return apiextensions_v1_webhook_client_config_local_var;
end:
    if (ca_bundle_local_str) {
        free(ca_bundle_local_str);
        ca_bundle_local_str = NULL;
    }
    if (service_local_nonprim) {
        apiextensions_v1_service_reference_free(service_local_nonprim);
        service_local_nonprim = NULL;
    }
    if (url_local_str) {
        free(url_local_str);
        url_local_str = NULL;
    }
    return NULL;

}
