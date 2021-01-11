#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha1_webhook.h"



v1alpha1_webhook_t *v1alpha1_webhook_create(
    v1alpha1_webhook_client_config_t *client_config,
    v1alpha1_webhook_throttle_config_t *throttle
    ) {
    v1alpha1_webhook_t *v1alpha1_webhook_local_var = malloc(sizeof(v1alpha1_webhook_t));
    if (!v1alpha1_webhook_local_var) {
        return NULL;
    }
    v1alpha1_webhook_local_var->client_config = client_config;
    v1alpha1_webhook_local_var->throttle = throttle;

    return v1alpha1_webhook_local_var;
}


void v1alpha1_webhook_free(v1alpha1_webhook_t *v1alpha1_webhook) {
    if(NULL == v1alpha1_webhook){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha1_webhook->client_config) {
        v1alpha1_webhook_client_config_free(v1alpha1_webhook->client_config);
        v1alpha1_webhook->client_config = NULL;
    }
    if (v1alpha1_webhook->throttle) {
        v1alpha1_webhook_throttle_config_free(v1alpha1_webhook->throttle);
        v1alpha1_webhook->throttle = NULL;
    }
    free(v1alpha1_webhook);
}

cJSON *v1alpha1_webhook_convertToJSON(v1alpha1_webhook_t *v1alpha1_webhook) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha1_webhook->client_config
    if (!v1alpha1_webhook->client_config) {
        goto fail;
    }
    
    cJSON *client_config_local_JSON = v1alpha1_webhook_client_config_convertToJSON(v1alpha1_webhook->client_config);
    if(client_config_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "clientConfig", client_config_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // v1alpha1_webhook->throttle
    if(v1alpha1_webhook->throttle) { 
    cJSON *throttle_local_JSON = v1alpha1_webhook_throttle_config_convertToJSON(v1alpha1_webhook->throttle);
    if(throttle_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "throttle", throttle_local_JSON);
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

v1alpha1_webhook_t *v1alpha1_webhook_parseFromJSON(cJSON *v1alpha1_webhookJSON){

    v1alpha1_webhook_t *v1alpha1_webhook_local_var = NULL;

    // v1alpha1_webhook->client_config
    cJSON *client_config = cJSON_GetObjectItemCaseSensitive(v1alpha1_webhookJSON, "clientConfig");
    if (!client_config) {
        goto end;
    }

    v1alpha1_webhook_client_config_t *client_config_local_nonprim = NULL;
    
    client_config_local_nonprim = v1alpha1_webhook_client_config_parseFromJSON(client_config); //nonprimitive

    // v1alpha1_webhook->throttle
    cJSON *throttle = cJSON_GetObjectItemCaseSensitive(v1alpha1_webhookJSON, "throttle");
    v1alpha1_webhook_throttle_config_t *throttle_local_nonprim = NULL;
    if (throttle) { 
    throttle_local_nonprim = v1alpha1_webhook_throttle_config_parseFromJSON(throttle); //nonprimitive
    }


    v1alpha1_webhook_local_var = v1alpha1_webhook_create (
        client_config_local_nonprim,
        throttle ? throttle_local_nonprim : NULL
        );

    return v1alpha1_webhook_local_var;
end:
    if (client_config_local_nonprim) {
        v1alpha1_webhook_client_config_free(client_config_local_nonprim);
        client_config_local_nonprim = NULL;
    }
    if (throttle_local_nonprim) {
        v1alpha1_webhook_throttle_config_free(throttle_local_nonprim);
        throttle_local_nonprim = NULL;
    }
    return NULL;

}
