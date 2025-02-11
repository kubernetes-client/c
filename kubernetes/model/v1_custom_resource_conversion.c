#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_custom_resource_conversion.h"



static v1_custom_resource_conversion_t *v1_custom_resource_conversion_create_internal(
    char *strategy,
    v1_webhook_conversion_t *webhook
    ) {
    v1_custom_resource_conversion_t *v1_custom_resource_conversion_local_var = malloc(sizeof(v1_custom_resource_conversion_t));
    if (!v1_custom_resource_conversion_local_var) {
        return NULL;
    }
    v1_custom_resource_conversion_local_var->strategy = strategy;
    v1_custom_resource_conversion_local_var->webhook = webhook;

    v1_custom_resource_conversion_local_var->_library_owned = 1;
    return v1_custom_resource_conversion_local_var;
}

__attribute__((deprecated)) v1_custom_resource_conversion_t *v1_custom_resource_conversion_create(
    char *strategy,
    v1_webhook_conversion_t *webhook
    ) {
    return v1_custom_resource_conversion_create_internal (
        strategy,
        webhook
        );
}

void v1_custom_resource_conversion_free(v1_custom_resource_conversion_t *v1_custom_resource_conversion) {
    if(NULL == v1_custom_resource_conversion){
        return ;
    }
    if(v1_custom_resource_conversion->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_custom_resource_conversion_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_custom_resource_conversion->strategy) {
        free(v1_custom_resource_conversion->strategy);
        v1_custom_resource_conversion->strategy = NULL;
    }
    if (v1_custom_resource_conversion->webhook) {
        v1_webhook_conversion_free(v1_custom_resource_conversion->webhook);
        v1_custom_resource_conversion->webhook = NULL;
    }
    free(v1_custom_resource_conversion);
}

cJSON *v1_custom_resource_conversion_convertToJSON(v1_custom_resource_conversion_t *v1_custom_resource_conversion) {
    cJSON *item = cJSON_CreateObject();

    // v1_custom_resource_conversion->strategy
    if (!v1_custom_resource_conversion->strategy) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "strategy", v1_custom_resource_conversion->strategy) == NULL) {
    goto fail; //String
    }


    // v1_custom_resource_conversion->webhook
    if(v1_custom_resource_conversion->webhook) {
    cJSON *webhook_local_JSON = v1_webhook_conversion_convertToJSON(v1_custom_resource_conversion->webhook);
    if(webhook_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "webhook", webhook_local_JSON);
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

v1_custom_resource_conversion_t *v1_custom_resource_conversion_parseFromJSON(cJSON *v1_custom_resource_conversionJSON){

    v1_custom_resource_conversion_t *v1_custom_resource_conversion_local_var = NULL;

    // define the local variable for v1_custom_resource_conversion->webhook
    v1_webhook_conversion_t *webhook_local_nonprim = NULL;

    // v1_custom_resource_conversion->strategy
    cJSON *strategy = cJSON_GetObjectItemCaseSensitive(v1_custom_resource_conversionJSON, "strategy");
    if (cJSON_IsNull(strategy)) {
        strategy = NULL;
    }
    if (!strategy) {
        goto end;
    }

    
    if(!cJSON_IsString(strategy))
    {
    goto end; //String
    }

    // v1_custom_resource_conversion->webhook
    cJSON *webhook = cJSON_GetObjectItemCaseSensitive(v1_custom_resource_conversionJSON, "webhook");
    if (cJSON_IsNull(webhook)) {
        webhook = NULL;
    }
    if (webhook) { 
    webhook_local_nonprim = v1_webhook_conversion_parseFromJSON(webhook); //nonprimitive
    }


    v1_custom_resource_conversion_local_var = v1_custom_resource_conversion_create_internal (
        strdup(strategy->valuestring),
        webhook ? webhook_local_nonprim : NULL
        );

    return v1_custom_resource_conversion_local_var;
end:
    if (webhook_local_nonprim) {
        v1_webhook_conversion_free(webhook_local_nonprim);
        webhook_local_nonprim = NULL;
    }
    return NULL;

}
