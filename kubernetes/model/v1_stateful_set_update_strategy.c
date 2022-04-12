#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_stateful_set_update_strategy.h"


char* typev1_stateful_set_update_strategy_ToString(kubernetes_v1_stateful_set_update_strategy_TYPE_e type) {
    char* typeArray[] =  { "NULL", "OnDelete", "RollingUpdate" };
	return typeArray[type];
}

kubernetes_v1_stateful_set_update_strategy_TYPE_e typev1_stateful_set_update_strategy_FromString(char* type){
    int stringToReturn = 0;
    char *typeArray[] =  { "NULL", "OnDelete", "RollingUpdate" };
    size_t sizeofArray = sizeof(typeArray) / sizeof(typeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(type, typeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

v1_stateful_set_update_strategy_t *v1_stateful_set_update_strategy_create(
    v1_rolling_update_stateful_set_strategy_t *rolling_update,
    kubernetes_v1_stateful_set_update_strategy_TYPE_e type
    ) {
    v1_stateful_set_update_strategy_t *v1_stateful_set_update_strategy_local_var = malloc(sizeof(v1_stateful_set_update_strategy_t));
    if (!v1_stateful_set_update_strategy_local_var) {
        return NULL;
    }
    v1_stateful_set_update_strategy_local_var->rolling_update = rolling_update;
    v1_stateful_set_update_strategy_local_var->type = type;

    return v1_stateful_set_update_strategy_local_var;
}


void v1_stateful_set_update_strategy_free(v1_stateful_set_update_strategy_t *v1_stateful_set_update_strategy) {
    if(NULL == v1_stateful_set_update_strategy){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_stateful_set_update_strategy->rolling_update) {
        v1_rolling_update_stateful_set_strategy_free(v1_stateful_set_update_strategy->rolling_update);
        v1_stateful_set_update_strategy->rolling_update = NULL;
    }
    free(v1_stateful_set_update_strategy);
}

cJSON *v1_stateful_set_update_strategy_convertToJSON(v1_stateful_set_update_strategy_t *v1_stateful_set_update_strategy) {
    cJSON *item = cJSON_CreateObject();

    // v1_stateful_set_update_strategy->rolling_update
    if(v1_stateful_set_update_strategy->rolling_update) { 
    cJSON *rolling_update_local_JSON = v1_rolling_update_stateful_set_strategy_convertToJSON(v1_stateful_set_update_strategy->rolling_update);
    if(rolling_update_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "rollingUpdate", rolling_update_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1_stateful_set_update_strategy->type
    
    if(cJSON_AddStringToObject(item, "type", typev1_stateful_set_update_strategy_ToString(v1_stateful_set_update_strategy->type)) == NULL)
    {
    goto fail; //Enum
    }
    

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_stateful_set_update_strategy_t *v1_stateful_set_update_strategy_parseFromJSON(cJSON *v1_stateful_set_update_strategyJSON){

    v1_stateful_set_update_strategy_t *v1_stateful_set_update_strategy_local_var = NULL;

    // define the local variable for v1_stateful_set_update_strategy->rolling_update
    v1_rolling_update_stateful_set_strategy_t *rolling_update_local_nonprim = NULL;

    // v1_stateful_set_update_strategy->rolling_update
    cJSON *rolling_update = cJSON_GetObjectItemCaseSensitive(v1_stateful_set_update_strategyJSON, "rollingUpdate");
    if (rolling_update) { 
    rolling_update_local_nonprim = v1_rolling_update_stateful_set_strategy_parseFromJSON(rolling_update); //nonprimitive
    }

    // v1_stateful_set_update_strategy->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(v1_stateful_set_update_strategyJSON, "type");
    kubernetes_v1_stateful_set_update_strategy_TYPE_e typeVariable;
    if (type) { 
    if(!cJSON_IsString(type))
    {
    goto end; //Enum
    }
    typeVariable = typev1_stateful_set_update_strategy_FromString(type->valuestring);
    }


    v1_stateful_set_update_strategy_local_var = v1_stateful_set_update_strategy_create (
        rolling_update ? rolling_update_local_nonprim : NULL,
        type ? typeVariable : -1
        );

    return v1_stateful_set_update_strategy_local_var;
end:
    if (rolling_update_local_nonprim) {
        v1_rolling_update_stateful_set_strategy_free(rolling_update_local_nonprim);
        rolling_update_local_nonprim = NULL;
    }
    return NULL;

}
