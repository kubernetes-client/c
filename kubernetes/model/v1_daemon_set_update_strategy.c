#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_daemon_set_update_strategy.h"



static v1_daemon_set_update_strategy_t *v1_daemon_set_update_strategy_create_internal(
    v1_rolling_update_daemon_set_t *rolling_update,
    char *type
    ) {
    v1_daemon_set_update_strategy_t *v1_daemon_set_update_strategy_local_var = malloc(sizeof(v1_daemon_set_update_strategy_t));
    if (!v1_daemon_set_update_strategy_local_var) {
        return NULL;
    }
    v1_daemon_set_update_strategy_local_var->rolling_update = rolling_update;
    v1_daemon_set_update_strategy_local_var->type = type;

    v1_daemon_set_update_strategy_local_var->_library_owned = 1;
    return v1_daemon_set_update_strategy_local_var;
}

__attribute__((deprecated)) v1_daemon_set_update_strategy_t *v1_daemon_set_update_strategy_create(
    v1_rolling_update_daemon_set_t *rolling_update,
    char *type
    ) {
    return v1_daemon_set_update_strategy_create_internal (
        rolling_update,
        type
        );
}

void v1_daemon_set_update_strategy_free(v1_daemon_set_update_strategy_t *v1_daemon_set_update_strategy) {
    if(NULL == v1_daemon_set_update_strategy){
        return ;
    }
    if(v1_daemon_set_update_strategy->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_daemon_set_update_strategy_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_daemon_set_update_strategy->rolling_update) {
        v1_rolling_update_daemon_set_free(v1_daemon_set_update_strategy->rolling_update);
        v1_daemon_set_update_strategy->rolling_update = NULL;
    }
    if (v1_daemon_set_update_strategy->type) {
        free(v1_daemon_set_update_strategy->type);
        v1_daemon_set_update_strategy->type = NULL;
    }
    free(v1_daemon_set_update_strategy);
}

cJSON *v1_daemon_set_update_strategy_convertToJSON(v1_daemon_set_update_strategy_t *v1_daemon_set_update_strategy) {
    cJSON *item = cJSON_CreateObject();

    // v1_daemon_set_update_strategy->rolling_update
    if(v1_daemon_set_update_strategy->rolling_update) {
    cJSON *rolling_update_local_JSON = v1_rolling_update_daemon_set_convertToJSON(v1_daemon_set_update_strategy->rolling_update);
    if(rolling_update_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "rollingUpdate", rolling_update_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_daemon_set_update_strategy->type
    if(v1_daemon_set_update_strategy->type) {
    if(cJSON_AddStringToObject(item, "type", v1_daemon_set_update_strategy->type) == NULL) {
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

v1_daemon_set_update_strategy_t *v1_daemon_set_update_strategy_parseFromJSON(cJSON *v1_daemon_set_update_strategyJSON){

    v1_daemon_set_update_strategy_t *v1_daemon_set_update_strategy_local_var = NULL;

    // define the local variable for v1_daemon_set_update_strategy->rolling_update
    v1_rolling_update_daemon_set_t *rolling_update_local_nonprim = NULL;

    // v1_daemon_set_update_strategy->rolling_update
    cJSON *rolling_update = cJSON_GetObjectItemCaseSensitive(v1_daemon_set_update_strategyJSON, "rollingUpdate");
    if (cJSON_IsNull(rolling_update)) {
        rolling_update = NULL;
    }
    if (rolling_update) { 
    rolling_update_local_nonprim = v1_rolling_update_daemon_set_parseFromJSON(rolling_update); //nonprimitive
    }

    // v1_daemon_set_update_strategy->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(v1_daemon_set_update_strategyJSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    if (type) { 
    if(!cJSON_IsString(type) && !cJSON_IsNull(type))
    {
    goto end; //String
    }
    }


    v1_daemon_set_update_strategy_local_var = v1_daemon_set_update_strategy_create_internal (
        rolling_update ? rolling_update_local_nonprim : NULL,
        type && !cJSON_IsNull(type) ? strdup(type->valuestring) : NULL
        );

    return v1_daemon_set_update_strategy_local_var;
end:
    if (rolling_update_local_nonprim) {
        v1_rolling_update_daemon_set_free(rolling_update_local_nonprim);
        rolling_update_local_nonprim = NULL;
    }
    return NULL;

}
