#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_deployment_strategy.h"



v1_deployment_strategy_t *v1_deployment_strategy_create(
    v1_rolling_update_deployment_t *rolling_update,
    char *type
    ) {
    v1_deployment_strategy_t *v1_deployment_strategy_local_var = malloc(sizeof(v1_deployment_strategy_t));
    if (!v1_deployment_strategy_local_var) {
        return NULL;
    }
    v1_deployment_strategy_local_var->rolling_update = rolling_update;
    v1_deployment_strategy_local_var->type = type;

    return v1_deployment_strategy_local_var;
}


void v1_deployment_strategy_free(v1_deployment_strategy_t *v1_deployment_strategy) {
    if(NULL == v1_deployment_strategy){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_deployment_strategy->rolling_update) {
        v1_rolling_update_deployment_free(v1_deployment_strategy->rolling_update);
        v1_deployment_strategy->rolling_update = NULL;
    }
    if (v1_deployment_strategy->type) {
        free(v1_deployment_strategy->type);
        v1_deployment_strategy->type = NULL;
    }
    free(v1_deployment_strategy);
}

cJSON *v1_deployment_strategy_convertToJSON(v1_deployment_strategy_t *v1_deployment_strategy) {
    cJSON *item = cJSON_CreateObject();

    // v1_deployment_strategy->rolling_update
    if(v1_deployment_strategy->rolling_update) { 
    cJSON *rolling_update_local_JSON = v1_rolling_update_deployment_convertToJSON(v1_deployment_strategy->rolling_update);
    if(rolling_update_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "rollingUpdate", rolling_update_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1_deployment_strategy->type
    if(v1_deployment_strategy->type) { 
    if(cJSON_AddStringToObject(item, "type", v1_deployment_strategy->type) == NULL) {
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

v1_deployment_strategy_t *v1_deployment_strategy_parseFromJSON(cJSON *v1_deployment_strategyJSON){

    v1_deployment_strategy_t *v1_deployment_strategy_local_var = NULL;

    // v1_deployment_strategy->rolling_update
    cJSON *rolling_update = cJSON_GetObjectItemCaseSensitive(v1_deployment_strategyJSON, "rollingUpdate");
    v1_rolling_update_deployment_t *rolling_update_local_nonprim = NULL;
    if (rolling_update) { 
    rolling_update_local_nonprim = v1_rolling_update_deployment_parseFromJSON(rolling_update); //nonprimitive
    }

    // v1_deployment_strategy->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(v1_deployment_strategyJSON, "type");
    if (type) { 
    if(!cJSON_IsString(type))
    {
    goto end; //String
    }
    }


    v1_deployment_strategy_local_var = v1_deployment_strategy_create (
        rolling_update ? rolling_update_local_nonprim : NULL,
        type ? strdup(type->valuestring) : NULL
        );

    return v1_deployment_strategy_local_var;
end:
    if (rolling_update_local_nonprim) {
        v1_rolling_update_deployment_free(rolling_update_local_nonprim);
        rolling_update_local_nonprim = NULL;
    }
    return NULL;

}
