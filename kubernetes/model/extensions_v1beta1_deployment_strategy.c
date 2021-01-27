#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "extensions_v1beta1_deployment_strategy.h"



extensions_v1beta1_deployment_strategy_t *extensions_v1beta1_deployment_strategy_create(
    extensions_v1beta1_rolling_update_deployment_t *rolling_update,
    char *type
    ) {
    extensions_v1beta1_deployment_strategy_t *extensions_v1beta1_deployment_strategy_local_var = malloc(sizeof(extensions_v1beta1_deployment_strategy_t));
    if (!extensions_v1beta1_deployment_strategy_local_var) {
        return NULL;
    }
    extensions_v1beta1_deployment_strategy_local_var->rolling_update = rolling_update;
    extensions_v1beta1_deployment_strategy_local_var->type = type;

    return extensions_v1beta1_deployment_strategy_local_var;
}


void extensions_v1beta1_deployment_strategy_free(extensions_v1beta1_deployment_strategy_t *extensions_v1beta1_deployment_strategy) {
    if(NULL == extensions_v1beta1_deployment_strategy){
        return ;
    }
    listEntry_t *listEntry;
    if (extensions_v1beta1_deployment_strategy->rolling_update) {
        extensions_v1beta1_rolling_update_deployment_free(extensions_v1beta1_deployment_strategy->rolling_update);
        extensions_v1beta1_deployment_strategy->rolling_update = NULL;
    }
    if (extensions_v1beta1_deployment_strategy->type) {
        free(extensions_v1beta1_deployment_strategy->type);
        extensions_v1beta1_deployment_strategy->type = NULL;
    }
    free(extensions_v1beta1_deployment_strategy);
}

cJSON *extensions_v1beta1_deployment_strategy_convertToJSON(extensions_v1beta1_deployment_strategy_t *extensions_v1beta1_deployment_strategy) {
    cJSON *item = cJSON_CreateObject();

    // extensions_v1beta1_deployment_strategy->rolling_update
    if(extensions_v1beta1_deployment_strategy->rolling_update) { 
    cJSON *rolling_update_local_JSON = extensions_v1beta1_rolling_update_deployment_convertToJSON(extensions_v1beta1_deployment_strategy->rolling_update);
    if(rolling_update_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "rollingUpdate", rolling_update_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // extensions_v1beta1_deployment_strategy->type
    if(extensions_v1beta1_deployment_strategy->type) { 
    if(cJSON_AddStringToObject(item, "type", extensions_v1beta1_deployment_strategy->type) == NULL) {
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

extensions_v1beta1_deployment_strategy_t *extensions_v1beta1_deployment_strategy_parseFromJSON(cJSON *extensions_v1beta1_deployment_strategyJSON){

    extensions_v1beta1_deployment_strategy_t *extensions_v1beta1_deployment_strategy_local_var = NULL;

    // extensions_v1beta1_deployment_strategy->rolling_update
    cJSON *rolling_update = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_deployment_strategyJSON, "rollingUpdate");
    extensions_v1beta1_rolling_update_deployment_t *rolling_update_local_nonprim = NULL;
    if (rolling_update) { 
    rolling_update_local_nonprim = extensions_v1beta1_rolling_update_deployment_parseFromJSON(rolling_update); //nonprimitive
    }

    // extensions_v1beta1_deployment_strategy->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_deployment_strategyJSON, "type");
    if (type) { 
    if(!cJSON_IsString(type))
    {
    goto end; //String
    }
    }


    extensions_v1beta1_deployment_strategy_local_var = extensions_v1beta1_deployment_strategy_create (
        rolling_update ? rolling_update_local_nonprim : NULL,
        type ? strdup(type->valuestring) : NULL
        );

    return extensions_v1beta1_deployment_strategy_local_var;
end:
    if (rolling_update_local_nonprim) {
        extensions_v1beta1_rolling_update_deployment_free(rolling_update_local_nonprim);
        rolling_update_local_nonprim = NULL;
    }
    return NULL;

}
