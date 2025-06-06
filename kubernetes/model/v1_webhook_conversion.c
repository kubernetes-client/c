#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_webhook_conversion.h"



static v1_webhook_conversion_t *v1_webhook_conversion_create_internal(
    apiextensions_v1_webhook_client_config_t *client_config,
    list_t *conversion_review_versions
    ) {
    v1_webhook_conversion_t *v1_webhook_conversion_local_var = malloc(sizeof(v1_webhook_conversion_t));
    if (!v1_webhook_conversion_local_var) {
        return NULL;
    }
    v1_webhook_conversion_local_var->client_config = client_config;
    v1_webhook_conversion_local_var->conversion_review_versions = conversion_review_versions;

    v1_webhook_conversion_local_var->_library_owned = 1;
    return v1_webhook_conversion_local_var;
}

__attribute__((deprecated)) v1_webhook_conversion_t *v1_webhook_conversion_create(
    apiextensions_v1_webhook_client_config_t *client_config,
    list_t *conversion_review_versions
    ) {
    return v1_webhook_conversion_create_internal (
        client_config,
        conversion_review_versions
        );
}

void v1_webhook_conversion_free(v1_webhook_conversion_t *v1_webhook_conversion) {
    if(NULL == v1_webhook_conversion){
        return ;
    }
    if(v1_webhook_conversion->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_webhook_conversion_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_webhook_conversion->client_config) {
        apiextensions_v1_webhook_client_config_free(v1_webhook_conversion->client_config);
        v1_webhook_conversion->client_config = NULL;
    }
    if (v1_webhook_conversion->conversion_review_versions) {
        list_ForEach(listEntry, v1_webhook_conversion->conversion_review_versions) {
            free(listEntry->data);
        }
        list_freeList(v1_webhook_conversion->conversion_review_versions);
        v1_webhook_conversion->conversion_review_versions = NULL;
    }
    free(v1_webhook_conversion);
}

cJSON *v1_webhook_conversion_convertToJSON(v1_webhook_conversion_t *v1_webhook_conversion) {
    cJSON *item = cJSON_CreateObject();

    // v1_webhook_conversion->client_config
    if(v1_webhook_conversion->client_config) {
    cJSON *client_config_local_JSON = apiextensions_v1_webhook_client_config_convertToJSON(v1_webhook_conversion->client_config);
    if(client_config_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "clientConfig", client_config_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_webhook_conversion->conversion_review_versions
    if (!v1_webhook_conversion->conversion_review_versions) {
        goto fail;
    }
    cJSON *conversion_review_versions = cJSON_AddArrayToObject(item, "conversionReviewVersions");
    if(conversion_review_versions == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *conversion_review_versionsListEntry;
    list_ForEach(conversion_review_versionsListEntry, v1_webhook_conversion->conversion_review_versions) {
    if(cJSON_AddStringToObject(conversion_review_versions, "", conversion_review_versionsListEntry->data) == NULL)
    {
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

v1_webhook_conversion_t *v1_webhook_conversion_parseFromJSON(cJSON *v1_webhook_conversionJSON){

    v1_webhook_conversion_t *v1_webhook_conversion_local_var = NULL;

    // define the local variable for v1_webhook_conversion->client_config
    apiextensions_v1_webhook_client_config_t *client_config_local_nonprim = NULL;

    // define the local list for v1_webhook_conversion->conversion_review_versions
    list_t *conversion_review_versionsList = NULL;

    // v1_webhook_conversion->client_config
    cJSON *client_config = cJSON_GetObjectItemCaseSensitive(v1_webhook_conversionJSON, "clientConfig");
    if (cJSON_IsNull(client_config)) {
        client_config = NULL;
    }
    if (client_config) { 
    client_config_local_nonprim = apiextensions_v1_webhook_client_config_parseFromJSON(client_config); //nonprimitive
    }

    // v1_webhook_conversion->conversion_review_versions
    cJSON *conversion_review_versions = cJSON_GetObjectItemCaseSensitive(v1_webhook_conversionJSON, "conversionReviewVersions");
    if (cJSON_IsNull(conversion_review_versions)) {
        conversion_review_versions = NULL;
    }
    if (!conversion_review_versions) {
        goto end;
    }

    
    cJSON *conversion_review_versions_local = NULL;
    if(!cJSON_IsArray(conversion_review_versions)) {
        goto end;//primitive container
    }
    conversion_review_versionsList = list_createList();

    cJSON_ArrayForEach(conversion_review_versions_local, conversion_review_versions)
    {
        if(!cJSON_IsString(conversion_review_versions_local))
        {
            goto end;
        }
        list_addElement(conversion_review_versionsList , strdup(conversion_review_versions_local->valuestring));
    }


    v1_webhook_conversion_local_var = v1_webhook_conversion_create_internal (
        client_config ? client_config_local_nonprim : NULL,
        conversion_review_versionsList
        );

    return v1_webhook_conversion_local_var;
end:
    if (client_config_local_nonprim) {
        apiextensions_v1_webhook_client_config_free(client_config_local_nonprim);
        client_config_local_nonprim = NULL;
    }
    if (conversion_review_versionsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, conversion_review_versionsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(conversion_review_versionsList);
        conversion_review_versionsList = NULL;
    }
    return NULL;

}
