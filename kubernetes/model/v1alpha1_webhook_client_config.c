#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha1_webhook_client_config.h"



v1alpha1_webhook_client_config_t *v1alpha1_webhook_client_config_create(
    char *ca_bundle,
    v1alpha1_service_reference_t *service,
    char *url
    ) {
    v1alpha1_webhook_client_config_t *v1alpha1_webhook_client_config_local_var = malloc(sizeof(v1alpha1_webhook_client_config_t));
    if (!v1alpha1_webhook_client_config_local_var) {
        return NULL;
    }
    v1alpha1_webhook_client_config_local_var->ca_bundle = ca_bundle;
    v1alpha1_webhook_client_config_local_var->service = service;
    v1alpha1_webhook_client_config_local_var->url = url;

    return v1alpha1_webhook_client_config_local_var;
}


void v1alpha1_webhook_client_config_free(v1alpha1_webhook_client_config_t *v1alpha1_webhook_client_config) {
    if(NULL == v1alpha1_webhook_client_config){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha1_webhook_client_config->ca_bundle) {
        free(v1alpha1_webhook_client_config->ca_bundle);
        v1alpha1_webhook_client_config->ca_bundle = NULL;
    }
    if (v1alpha1_webhook_client_config->service) {
        v1alpha1_service_reference_free(v1alpha1_webhook_client_config->service);
        v1alpha1_webhook_client_config->service = NULL;
    }
    if (v1alpha1_webhook_client_config->url) {
        free(v1alpha1_webhook_client_config->url);
        v1alpha1_webhook_client_config->url = NULL;
    }
    free(v1alpha1_webhook_client_config);
}

cJSON *v1alpha1_webhook_client_config_convertToJSON(v1alpha1_webhook_client_config_t *v1alpha1_webhook_client_config) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha1_webhook_client_config->ca_bundle
    if(v1alpha1_webhook_client_config->ca_bundle) { 
    if(cJSON_AddStringToObject(item, "caBundle", v1alpha1_webhook_client_config->ca_bundle) == NULL) {
    goto fail; //ByteArray
    }
     } 


    // v1alpha1_webhook_client_config->service
    if(v1alpha1_webhook_client_config->service) { 
    cJSON *service_local_JSON = v1alpha1_service_reference_convertToJSON(v1alpha1_webhook_client_config->service);
    if(service_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "service", service_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1alpha1_webhook_client_config->url
    if(v1alpha1_webhook_client_config->url) { 
    if(cJSON_AddStringToObject(item, "url", v1alpha1_webhook_client_config->url) == NULL) {
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

v1alpha1_webhook_client_config_t *v1alpha1_webhook_client_config_parseFromJSON(cJSON *v1alpha1_webhook_client_configJSON){

    v1alpha1_webhook_client_config_t *v1alpha1_webhook_client_config_local_var = NULL;

    // v1alpha1_webhook_client_config->ca_bundle
    cJSON *ca_bundle = cJSON_GetObjectItemCaseSensitive(v1alpha1_webhook_client_configJSON, "caBundle");
    if (ca_bundle) { 
    if(!cJSON_IsString(ca_bundle))
    {
    goto end; //ByteArray
    }
    }

    // v1alpha1_webhook_client_config->service
    cJSON *service = cJSON_GetObjectItemCaseSensitive(v1alpha1_webhook_client_configJSON, "service");
    v1alpha1_service_reference_t *service_local_nonprim = NULL;
    if (service) { 
    service_local_nonprim = v1alpha1_service_reference_parseFromJSON(service); //nonprimitive
    }

    // v1alpha1_webhook_client_config->url
    cJSON *url = cJSON_GetObjectItemCaseSensitive(v1alpha1_webhook_client_configJSON, "url");
    if (url) { 
    if(!cJSON_IsString(url))
    {
    goto end; //String
    }
    }


    v1alpha1_webhook_client_config_local_var = v1alpha1_webhook_client_config_create (
        ca_bundle ? strdup(ca_bundle->valuestring) : NULL,
        service ? service_local_nonprim : NULL,
        url ? strdup(url->valuestring) : NULL
        );

    return v1alpha1_webhook_client_config_local_var;
end:
    if (service_local_nonprim) {
        v1alpha1_service_reference_free(service_local_nonprim);
        service_local_nonprim = NULL;
    }
    return NULL;

}
