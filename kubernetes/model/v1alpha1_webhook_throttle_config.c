#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha1_webhook_throttle_config.h"



v1alpha1_webhook_throttle_config_t *v1alpha1_webhook_throttle_config_create(
    long burst,
    long qps
    ) {
    v1alpha1_webhook_throttle_config_t *v1alpha1_webhook_throttle_config_local_var = malloc(sizeof(v1alpha1_webhook_throttle_config_t));
    if (!v1alpha1_webhook_throttle_config_local_var) {
        return NULL;
    }
    v1alpha1_webhook_throttle_config_local_var->burst = burst;
    v1alpha1_webhook_throttle_config_local_var->qps = qps;

    return v1alpha1_webhook_throttle_config_local_var;
}


void v1alpha1_webhook_throttle_config_free(v1alpha1_webhook_throttle_config_t *v1alpha1_webhook_throttle_config) {
    if(NULL == v1alpha1_webhook_throttle_config){
        return ;
    }
    listEntry_t *listEntry;
    free(v1alpha1_webhook_throttle_config);
}

cJSON *v1alpha1_webhook_throttle_config_convertToJSON(v1alpha1_webhook_throttle_config_t *v1alpha1_webhook_throttle_config) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha1_webhook_throttle_config->burst
    if(v1alpha1_webhook_throttle_config->burst) { 
    if(cJSON_AddNumberToObject(item, "burst", v1alpha1_webhook_throttle_config->burst) == NULL) {
    goto fail; //Numeric
    }
     } 


    // v1alpha1_webhook_throttle_config->qps
    if(v1alpha1_webhook_throttle_config->qps) { 
    if(cJSON_AddNumberToObject(item, "qps", v1alpha1_webhook_throttle_config->qps) == NULL) {
    goto fail; //Numeric
    }
     } 

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1alpha1_webhook_throttle_config_t *v1alpha1_webhook_throttle_config_parseFromJSON(cJSON *v1alpha1_webhook_throttle_configJSON){

    v1alpha1_webhook_throttle_config_t *v1alpha1_webhook_throttle_config_local_var = NULL;

    // v1alpha1_webhook_throttle_config->burst
    cJSON *burst = cJSON_GetObjectItemCaseSensitive(v1alpha1_webhook_throttle_configJSON, "burst");
    if (burst) { 
    if(!cJSON_IsNumber(burst))
    {
    goto end; //Numeric
    }
    }

    // v1alpha1_webhook_throttle_config->qps
    cJSON *qps = cJSON_GetObjectItemCaseSensitive(v1alpha1_webhook_throttle_configJSON, "qps");
    if (qps) { 
    if(!cJSON_IsNumber(qps))
    {
    goto end; //Numeric
    }
    }


    v1alpha1_webhook_throttle_config_local_var = v1alpha1_webhook_throttle_config_create (
        burst ? burst->valuedouble : 0,
        qps ? qps->valuedouble : 0
        );

    return v1alpha1_webhook_throttle_config_local_var;
end:
    return NULL;

}
