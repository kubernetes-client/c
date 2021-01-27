#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_custom_resource_conversion.h"



v1beta1_custom_resource_conversion_t *v1beta1_custom_resource_conversion_create(
    list_t *conversion_review_versions,
    char *strategy,
    apiextensions_v1beta1_webhook_client_config_t *webhook_client_config
    ) {
    v1beta1_custom_resource_conversion_t *v1beta1_custom_resource_conversion_local_var = malloc(sizeof(v1beta1_custom_resource_conversion_t));
    if (!v1beta1_custom_resource_conversion_local_var) {
        return NULL;
    }
    v1beta1_custom_resource_conversion_local_var->conversion_review_versions = conversion_review_versions;
    v1beta1_custom_resource_conversion_local_var->strategy = strategy;
    v1beta1_custom_resource_conversion_local_var->webhook_client_config = webhook_client_config;

    return v1beta1_custom_resource_conversion_local_var;
}


void v1beta1_custom_resource_conversion_free(v1beta1_custom_resource_conversion_t *v1beta1_custom_resource_conversion) {
    if(NULL == v1beta1_custom_resource_conversion){
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta1_custom_resource_conversion->conversion_review_versions) {
        list_ForEach(listEntry, v1beta1_custom_resource_conversion->conversion_review_versions) {
            free(listEntry->data);
        }
        list_free(v1beta1_custom_resource_conversion->conversion_review_versions);
        v1beta1_custom_resource_conversion->conversion_review_versions = NULL;
    }
    if (v1beta1_custom_resource_conversion->strategy) {
        free(v1beta1_custom_resource_conversion->strategy);
        v1beta1_custom_resource_conversion->strategy = NULL;
    }
    if (v1beta1_custom_resource_conversion->webhook_client_config) {
        apiextensions_v1beta1_webhook_client_config_free(v1beta1_custom_resource_conversion->webhook_client_config);
        v1beta1_custom_resource_conversion->webhook_client_config = NULL;
    }
    free(v1beta1_custom_resource_conversion);
}

cJSON *v1beta1_custom_resource_conversion_convertToJSON(v1beta1_custom_resource_conversion_t *v1beta1_custom_resource_conversion) {
    cJSON *item = cJSON_CreateObject();

    // v1beta1_custom_resource_conversion->conversion_review_versions
    if(v1beta1_custom_resource_conversion->conversion_review_versions) { 
    cJSON *conversion_review_versions = cJSON_AddArrayToObject(item, "conversionReviewVersions");
    if(conversion_review_versions == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *conversion_review_versionsListEntry;
    list_ForEach(conversion_review_versionsListEntry, v1beta1_custom_resource_conversion->conversion_review_versions) {
    if(cJSON_AddStringToObject(conversion_review_versions, "", (char*)conversion_review_versionsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 


    // v1beta1_custom_resource_conversion->strategy
    if (!v1beta1_custom_resource_conversion->strategy) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "strategy", v1beta1_custom_resource_conversion->strategy) == NULL) {
    goto fail; //String
    }


    // v1beta1_custom_resource_conversion->webhook_client_config
    if(v1beta1_custom_resource_conversion->webhook_client_config) { 
    cJSON *webhook_client_config_local_JSON = apiextensions_v1beta1_webhook_client_config_convertToJSON(v1beta1_custom_resource_conversion->webhook_client_config);
    if(webhook_client_config_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "webhookClientConfig", webhook_client_config_local_JSON);
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

v1beta1_custom_resource_conversion_t *v1beta1_custom_resource_conversion_parseFromJSON(cJSON *v1beta1_custom_resource_conversionJSON){

    v1beta1_custom_resource_conversion_t *v1beta1_custom_resource_conversion_local_var = NULL;

    // v1beta1_custom_resource_conversion->conversion_review_versions
    cJSON *conversion_review_versions = cJSON_GetObjectItemCaseSensitive(v1beta1_custom_resource_conversionJSON, "conversionReviewVersions");
    list_t *conversion_review_versionsList;
    if (conversion_review_versions) { 
    cJSON *conversion_review_versions_local;
    if(!cJSON_IsArray(conversion_review_versions)) {
        goto end;//primitive container
    }
    conversion_review_versionsList = list_create();

    cJSON_ArrayForEach(conversion_review_versions_local, conversion_review_versions)
    {
        if(!cJSON_IsString(conversion_review_versions_local))
        {
            goto end;
        }
        list_addElement(conversion_review_versionsList , strdup(conversion_review_versions_local->valuestring));
    }
    }

    // v1beta1_custom_resource_conversion->strategy
    cJSON *strategy = cJSON_GetObjectItemCaseSensitive(v1beta1_custom_resource_conversionJSON, "strategy");
    if (!strategy) {
        goto end;
    }

    
    if(!cJSON_IsString(strategy))
    {
    goto end; //String
    }

    // v1beta1_custom_resource_conversion->webhook_client_config
    cJSON *webhook_client_config = cJSON_GetObjectItemCaseSensitive(v1beta1_custom_resource_conversionJSON, "webhookClientConfig");
    apiextensions_v1beta1_webhook_client_config_t *webhook_client_config_local_nonprim = NULL;
    if (webhook_client_config) { 
    webhook_client_config_local_nonprim = apiextensions_v1beta1_webhook_client_config_parseFromJSON(webhook_client_config); //nonprimitive
    }


    v1beta1_custom_resource_conversion_local_var = v1beta1_custom_resource_conversion_create (
        conversion_review_versions ? conversion_review_versionsList : NULL,
        strdup(strategy->valuestring),
        webhook_client_config ? webhook_client_config_local_nonprim : NULL
        );

    return v1beta1_custom_resource_conversion_local_var;
end:
    if (webhook_client_config_local_nonprim) {
        apiextensions_v1beta1_webhook_client_config_free(webhook_client_config_local_nonprim);
        webhook_client_config_local_nonprim = NULL;
    }
    return NULL;

}
