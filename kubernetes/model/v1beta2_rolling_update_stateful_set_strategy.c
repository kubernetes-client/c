#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta2_rolling_update_stateful_set_strategy.h"



v1beta2_rolling_update_stateful_set_strategy_t *v1beta2_rolling_update_stateful_set_strategy_create(
    int partition
    ) {
    v1beta2_rolling_update_stateful_set_strategy_t *v1beta2_rolling_update_stateful_set_strategy_local_var = malloc(sizeof(v1beta2_rolling_update_stateful_set_strategy_t));
    if (!v1beta2_rolling_update_stateful_set_strategy_local_var) {
        return NULL;
    }
    v1beta2_rolling_update_stateful_set_strategy_local_var->partition = partition;

    return v1beta2_rolling_update_stateful_set_strategy_local_var;
}


void v1beta2_rolling_update_stateful_set_strategy_free(v1beta2_rolling_update_stateful_set_strategy_t *v1beta2_rolling_update_stateful_set_strategy) {
    if(NULL == v1beta2_rolling_update_stateful_set_strategy){
        return ;
    }
    listEntry_t *listEntry;
    free(v1beta2_rolling_update_stateful_set_strategy);
}

cJSON *v1beta2_rolling_update_stateful_set_strategy_convertToJSON(v1beta2_rolling_update_stateful_set_strategy_t *v1beta2_rolling_update_stateful_set_strategy) {
    cJSON *item = cJSON_CreateObject();

    // v1beta2_rolling_update_stateful_set_strategy->partition
    if(v1beta2_rolling_update_stateful_set_strategy->partition) { 
    if(cJSON_AddNumberToObject(item, "partition", v1beta2_rolling_update_stateful_set_strategy->partition) == NULL) {
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

v1beta2_rolling_update_stateful_set_strategy_t *v1beta2_rolling_update_stateful_set_strategy_parseFromJSON(cJSON *v1beta2_rolling_update_stateful_set_strategyJSON){

    v1beta2_rolling_update_stateful_set_strategy_t *v1beta2_rolling_update_stateful_set_strategy_local_var = NULL;

    // v1beta2_rolling_update_stateful_set_strategy->partition
    cJSON *partition = cJSON_GetObjectItemCaseSensitive(v1beta2_rolling_update_stateful_set_strategyJSON, "partition");
    if (partition) { 
    if(!cJSON_IsNumber(partition))
    {
    goto end; //Numeric
    }
    }


    v1beta2_rolling_update_stateful_set_strategy_local_var = v1beta2_rolling_update_stateful_set_strategy_create (
        partition ? partition->valuedouble : 0
        );

    return v1beta2_rolling_update_stateful_set_strategy_local_var;
end:
    return NULL;

}
