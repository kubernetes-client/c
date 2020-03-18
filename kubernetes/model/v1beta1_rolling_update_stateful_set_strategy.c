#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_rolling_update_stateful_set_strategy.h"



v1beta1_rolling_update_stateful_set_strategy_t *v1beta1_rolling_update_stateful_set_strategy_create(
    int partition
    ) {
    v1beta1_rolling_update_stateful_set_strategy_t *v1beta1_rolling_update_stateful_set_strategy_local_var = malloc(sizeof(v1beta1_rolling_update_stateful_set_strategy_t));
    if (!v1beta1_rolling_update_stateful_set_strategy_local_var) {
        return NULL;
    }
    v1beta1_rolling_update_stateful_set_strategy_local_var->partition = partition;

    return v1beta1_rolling_update_stateful_set_strategy_local_var;
}


void v1beta1_rolling_update_stateful_set_strategy_free(v1beta1_rolling_update_stateful_set_strategy_t *v1beta1_rolling_update_stateful_set_strategy) {
    if(NULL == v1beta1_rolling_update_stateful_set_strategy){
        return ;
    }
    listEntry_t *listEntry;
    free(v1beta1_rolling_update_stateful_set_strategy);
}

cJSON *v1beta1_rolling_update_stateful_set_strategy_convertToJSON(v1beta1_rolling_update_stateful_set_strategy_t *v1beta1_rolling_update_stateful_set_strategy) {
    cJSON *item = cJSON_CreateObject();

    // v1beta1_rolling_update_stateful_set_strategy->partition
    if(v1beta1_rolling_update_stateful_set_strategy->partition) { 
    if(cJSON_AddNumberToObject(item, "partition", v1beta1_rolling_update_stateful_set_strategy->partition) == NULL) {
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

v1beta1_rolling_update_stateful_set_strategy_t *v1beta1_rolling_update_stateful_set_strategy_parseFromJSON(cJSON *v1beta1_rolling_update_stateful_set_strategyJSON){

    v1beta1_rolling_update_stateful_set_strategy_t *v1beta1_rolling_update_stateful_set_strategy_local_var = NULL;

    // v1beta1_rolling_update_stateful_set_strategy->partition
    cJSON *partition = cJSON_GetObjectItemCaseSensitive(v1beta1_rolling_update_stateful_set_strategyJSON, "partition");
    if (partition) { 
    if(!cJSON_IsNumber(partition))
    {
    goto end; //Numeric
    }
    }


    v1beta1_rolling_update_stateful_set_strategy_local_var = v1beta1_rolling_update_stateful_set_strategy_create (
        partition ? partition->valuedouble : 0
        );

    return v1beta1_rolling_update_stateful_set_strategy_local_var;
end:
    return NULL;

}
