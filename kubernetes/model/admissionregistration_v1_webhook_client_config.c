#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "admissionregistration_v1_webhook_client_config.h"



static admissionregistration_v1_webhook_client_config_t *admissionregistration_v1_webhook_client_config_create_internal(
    char *ca_bundle,
    admissionregistration_v1_service_reference_t *service,
    char *url
    ) {
    admissionregistration_v1_webhook_client_config_t *admissionregistration_v1_webhook_client_config_local_var = malloc(sizeof(admissionregistration_v1_webhook_client_config_t));
    if (!admissionregistration_v1_webhook_client_config_local_var) {
        return NULL;
    }
    admissionregistration_v1_webhook_client_config_local_var->ca_bundle = ca_bundle;
    admissionregistration_v1_webhook_client_config_local_var->service = service;
    admissionregistration_v1_webhook_client_config_local_var->url = url;

    admissionregistration_v1_webhook_client_config_local_var->_library_owned = 1;
    return admissionregistration_v1_webhook_client_config_local_var;
}

__attribute__((deprecated)) admissionregistration_v1_webhook_client_config_t *admissionregistration_v1_webhook_client_config_create(
    char *ca_bundle,
    admissionregistration_v1_service_reference_t *service,
    char *url
    ) {
    return admissionregistration_v1_webhook_client_config_create_internal (
        ca_bundle,
        service,
        url
        );
}

void admissionregistration_v1_webhook_client_config_free(admissionregistration_v1_webhook_client_config_t *admissionregistration_v1_webhook_client_config) {
    if(NULL == admissionregistration_v1_webhook_client_config){
        return ;
    }
    if(admissionregistration_v1_webhook_client_config->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "admissionregistration_v1_webhook_client_config_free");
        return ;
    }
    listEntry_t *listEntry;
    if (admissionregistration_v1_webhook_client_config->ca_bundle) {
        free(admissionregistration_v1_webhook_client_config->ca_bundle);
        admissionregistration_v1_webhook_client_config->ca_bundle = NULL;
    }
    if (admissionregistration_v1_webhook_client_config->service) {
        admissionregistration_v1_service_reference_free(admissionregistration_v1_webhook_client_config->service);
        admissionregistration_v1_webhook_client_config->service = NULL;
    }
    if (admissionregistration_v1_webhook_client_config->url) {
        free(admissionregistration_v1_webhook_client_config->url);
        admissionregistration_v1_webhook_client_config->url = NULL;
    }
    free(admissionregistration_v1_webhook_client_config);
}

cJSON *admissionregistration_v1_webhook_client_config_convertToJSON(admissionregistration_v1_webhook_client_config_t *admissionregistration_v1_webhook_client_config) {
    cJSON *item = cJSON_CreateObject();

    // admissionregistration_v1_webhook_client_config->ca_bundle
    if(admissionregistration_v1_webhook_client_config->ca_bundle) {
    if(cJSON_AddStringToObject(item, "caBundle", admissionregistration_v1_webhook_client_config->ca_bundle) == NULL) {
    goto fail; //ByteArray
    }
    }


    // admissionregistration_v1_webhook_client_config->service
    if(admissionregistration_v1_webhook_client_config->service) {
    cJSON *service_local_JSON = admissionregistration_v1_service_reference_convertToJSON(admissionregistration_v1_webhook_client_config->service);
    if(service_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "service", service_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // admissionregistration_v1_webhook_client_config->url
    if(admissionregistration_v1_webhook_client_config->url) {
    if(cJSON_AddStringToObject(item, "url", admissionregistration_v1_webhook_client_config->url) == NULL) {
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

admissionregistration_v1_webhook_client_config_t *admissionregistration_v1_webhook_client_config_parseFromJSON(cJSON *admissionregistration_v1_webhook_client_configJSON){

    admissionregistration_v1_webhook_client_config_t *admissionregistration_v1_webhook_client_config_local_var = NULL;

    // define the local variable for admissionregistration_v1_webhook_client_config->service
    admissionregistration_v1_service_reference_t *service_local_nonprim = NULL;

    // admissionregistration_v1_webhook_client_config->ca_bundle
    cJSON *ca_bundle = cJSON_GetObjectItemCaseSensitive(admissionregistration_v1_webhook_client_configJSON, "caBundle");
    if (cJSON_IsNull(ca_bundle)) {
        ca_bundle = NULL;
    }
    if (ca_bundle) { 
    if(!cJSON_IsString(ca_bundle))
    {
    goto end; //ByteArray
    }
    }

    // admissionregistration_v1_webhook_client_config->service
    cJSON *service = cJSON_GetObjectItemCaseSensitive(admissionregistration_v1_webhook_client_configJSON, "service");
    if (cJSON_IsNull(service)) {
        service = NULL;
    }
    if (service) { 
    service_local_nonprim = admissionregistration_v1_service_reference_parseFromJSON(service); //nonprimitive
    }

    // admissionregistration_v1_webhook_client_config->url
    cJSON *url = cJSON_GetObjectItemCaseSensitive(admissionregistration_v1_webhook_client_configJSON, "url");
    if (cJSON_IsNull(url)) {
        url = NULL;
    }
    if (url) { 
    if(!cJSON_IsString(url) && !cJSON_IsNull(url))
    {
    goto end; //String
    }
    }


    admissionregistration_v1_webhook_client_config_local_var = admissionregistration_v1_webhook_client_config_create_internal (
        ca_bundle ? strdup(ca_bundle->valuestring) : NULL,
        service ? service_local_nonprim : NULL,
        url && !cJSON_IsNull(url) ? strdup(url->valuestring) : NULL
        );

    return admissionregistration_v1_webhook_client_config_local_var;
end:
    if (service_local_nonprim) {
        admissionregistration_v1_service_reference_free(service_local_nonprim);
        service_local_nonprim = NULL;
    }
    return NULL;

}
