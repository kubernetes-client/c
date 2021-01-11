#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "apps_v1beta1_deployment_strategy.h"



apps_v1beta1_deployment_strategy_t *apps_v1beta1_deployment_strategy_create(
    apps_v1beta1_rolling_update_deployment_t *rolling_update,
    char *type
    ) {
    apps_v1beta1_deployment_strategy_t *apps_v1beta1_deployment_strategy_local_var = malloc(sizeof(apps_v1beta1_deployment_strategy_t));
    if (!apps_v1beta1_deployment_strategy_local_var) {
        return NULL;
    }
    apps_v1beta1_deployment_strategy_local_var->rolling_update = rolling_update;
    apps_v1beta1_deployment_strategy_local_var->type = type;

    return apps_v1beta1_deployment_strategy_local_var;
}


void apps_v1beta1_deployment_strategy_free(apps_v1beta1_deployment_strategy_t *apps_v1beta1_deployment_strategy) {
    if(NULL == apps_v1beta1_deployment_strategy){
        return ;
    }
    listEntry_t *listEntry;
    if (apps_v1beta1_deployment_strategy->rolling_update) {
        apps_v1beta1_rolling_update_deployment_free(apps_v1beta1_deployment_strategy->rolling_update);
        apps_v1beta1_deployment_strategy->rolling_update = NULL;
    }
    if (apps_v1beta1_deployment_strategy->type) {
        free(apps_v1beta1_deployment_strategy->type);
        apps_v1beta1_deployment_strategy->type = NULL;
    }
    free(apps_v1beta1_deployment_strategy);
}

cJSON *apps_v1beta1_deployment_strategy_convertToJSON(apps_v1beta1_deployment_strategy_t *apps_v1beta1_deployment_strategy) {
    cJSON *item = cJSON_CreateObject();

    // apps_v1beta1_deployment_strategy->rolling_update
    if(apps_v1beta1_deployment_strategy->rolling_update) { 
    cJSON *rolling_update_local_JSON = apps_v1beta1_rolling_update_deployment_convertToJSON(apps_v1beta1_deployment_strategy->rolling_update);
    if(rolling_update_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "rollingUpdate", rolling_update_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // apps_v1beta1_deployment_strategy->type
    if(apps_v1beta1_deployment_strategy->type) { 
    if(cJSON_AddStringToObject(item, "type", apps_v1beta1_deployment_strategy->type) == NULL) {
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

apps_v1beta1_deployment_strategy_t *apps_v1beta1_deployment_strategy_parseFromJSON(cJSON *apps_v1beta1_deployment_strategyJSON){

    apps_v1beta1_deployment_strategy_t *apps_v1beta1_deployment_strategy_local_var = NULL;

    // apps_v1beta1_deployment_strategy->rolling_update
    cJSON *rolling_update = cJSON_GetObjectItemCaseSensitive(apps_v1beta1_deployment_strategyJSON, "rollingUpdate");
    apps_v1beta1_rolling_update_deployment_t *rolling_update_local_nonprim = NULL;
    if (rolling_update) { 
    rolling_update_local_nonprim = apps_v1beta1_rolling_update_deployment_parseFromJSON(rolling_update); //nonprimitive
    }

    // apps_v1beta1_deployment_strategy->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(apps_v1beta1_deployment_strategyJSON, "type");
    if (type) { 
    if(!cJSON_IsString(type))
    {
    goto end; //String
    }
    }


    apps_v1beta1_deployment_strategy_local_var = apps_v1beta1_deployment_strategy_create (
        rolling_update ? rolling_update_local_nonprim : NULL,
        type ? strdup(type->valuestring) : NULL
        );

    return apps_v1beta1_deployment_strategy_local_var;
end:
    if (rolling_update_local_nonprim) {
        apps_v1beta1_rolling_update_deployment_free(rolling_update_local_nonprim);
        rolling_update_local_nonprim = NULL;
    }
    return NULL;

}
