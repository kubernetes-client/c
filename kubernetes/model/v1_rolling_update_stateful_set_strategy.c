#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_rolling_update_stateful_set_strategy.h"



static v1_rolling_update_stateful_set_strategy_t *v1_rolling_update_stateful_set_strategy_create_internal(
    int_or_string_t *max_unavailable,
    int partition
    ) {
    v1_rolling_update_stateful_set_strategy_t *v1_rolling_update_stateful_set_strategy_local_var = malloc(sizeof(v1_rolling_update_stateful_set_strategy_t));
    if (!v1_rolling_update_stateful_set_strategy_local_var) {
        return NULL;
    }
    v1_rolling_update_stateful_set_strategy_local_var->max_unavailable = max_unavailable;
    v1_rolling_update_stateful_set_strategy_local_var->partition = partition;

    v1_rolling_update_stateful_set_strategy_local_var->_library_owned = 1;
    return v1_rolling_update_stateful_set_strategy_local_var;
}

__attribute__((deprecated)) v1_rolling_update_stateful_set_strategy_t *v1_rolling_update_stateful_set_strategy_create(
    int_or_string_t *max_unavailable,
    int partition
    ) {
    return v1_rolling_update_stateful_set_strategy_create_internal (
        max_unavailable,
        partition
        );
}

void v1_rolling_update_stateful_set_strategy_free(v1_rolling_update_stateful_set_strategy_t *v1_rolling_update_stateful_set_strategy) {
    if(NULL == v1_rolling_update_stateful_set_strategy){
        return ;
    }
    if(v1_rolling_update_stateful_set_strategy->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_rolling_update_stateful_set_strategy_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_rolling_update_stateful_set_strategy->max_unavailable) {
        int_or_string_free(v1_rolling_update_stateful_set_strategy->max_unavailable);
        v1_rolling_update_stateful_set_strategy->max_unavailable = NULL;
    }
    free(v1_rolling_update_stateful_set_strategy);
}

cJSON *v1_rolling_update_stateful_set_strategy_convertToJSON(v1_rolling_update_stateful_set_strategy_t *v1_rolling_update_stateful_set_strategy) {
    cJSON *item = cJSON_CreateObject();

    // v1_rolling_update_stateful_set_strategy->max_unavailable
    if(v1_rolling_update_stateful_set_strategy->max_unavailable) {
    cJSON *max_unavailable_local_JSON = int_or_string_convertToJSON(v1_rolling_update_stateful_set_strategy->max_unavailable);
    if(max_unavailable_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "maxUnavailable", max_unavailable_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // v1_rolling_update_stateful_set_strategy->partition
    if(v1_rolling_update_stateful_set_strategy->partition) {
    if(cJSON_AddNumberToObject(item, "partition", v1_rolling_update_stateful_set_strategy->partition) == NULL) {
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

v1_rolling_update_stateful_set_strategy_t *v1_rolling_update_stateful_set_strategy_parseFromJSON(cJSON *v1_rolling_update_stateful_set_strategyJSON){

    v1_rolling_update_stateful_set_strategy_t *v1_rolling_update_stateful_set_strategy_local_var = NULL;

    // define the local variable for v1_rolling_update_stateful_set_strategy->max_unavailable
    int_or_string_t *max_unavailable_local_nonprim = NULL;

    // v1_rolling_update_stateful_set_strategy->max_unavailable
    cJSON *max_unavailable = cJSON_GetObjectItemCaseSensitive(v1_rolling_update_stateful_set_strategyJSON, "maxUnavailable");
    if (cJSON_IsNull(max_unavailable)) {
        max_unavailable = NULL;
    }
    if (max_unavailable) { 
    max_unavailable_local_nonprim = int_or_string_parseFromJSON(max_unavailable); //custom
    }

    // v1_rolling_update_stateful_set_strategy->partition
    cJSON *partition = cJSON_GetObjectItemCaseSensitive(v1_rolling_update_stateful_set_strategyJSON, "partition");
    if (cJSON_IsNull(partition)) {
        partition = NULL;
    }
    if (partition) { 
    if(!cJSON_IsNumber(partition))
    {
    goto end; //Numeric
    }
    }


    v1_rolling_update_stateful_set_strategy_local_var = v1_rolling_update_stateful_set_strategy_create_internal (
        max_unavailable ? max_unavailable_local_nonprim : NULL,
        partition ? partition->valuedouble : 0
        );

    return v1_rolling_update_stateful_set_strategy_local_var;
end:
    if (max_unavailable_local_nonprim) {
        int_or_string_free(max_unavailable_local_nonprim);
        max_unavailable_local_nonprim = NULL;
    }
    return NULL;

}
