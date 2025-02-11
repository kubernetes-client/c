#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_sleep_action.h"



static v1_sleep_action_t *v1_sleep_action_create_internal(
    long seconds
    ) {
    v1_sleep_action_t *v1_sleep_action_local_var = malloc(sizeof(v1_sleep_action_t));
    if (!v1_sleep_action_local_var) {
        return NULL;
    }
    v1_sleep_action_local_var->seconds = seconds;

    v1_sleep_action_local_var->_library_owned = 1;
    return v1_sleep_action_local_var;
}

__attribute__((deprecated)) v1_sleep_action_t *v1_sleep_action_create(
    long seconds
    ) {
    return v1_sleep_action_create_internal (
        seconds
        );
}

void v1_sleep_action_free(v1_sleep_action_t *v1_sleep_action) {
    if(NULL == v1_sleep_action){
        return ;
    }
    if(v1_sleep_action->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_sleep_action_free");
        return ;
    }
    listEntry_t *listEntry;
    free(v1_sleep_action);
}

cJSON *v1_sleep_action_convertToJSON(v1_sleep_action_t *v1_sleep_action) {
    cJSON *item = cJSON_CreateObject();

    // v1_sleep_action->seconds
    if (!v1_sleep_action->seconds) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "seconds", v1_sleep_action->seconds) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_sleep_action_t *v1_sleep_action_parseFromJSON(cJSON *v1_sleep_actionJSON){

    v1_sleep_action_t *v1_sleep_action_local_var = NULL;

    // v1_sleep_action->seconds
    cJSON *seconds = cJSON_GetObjectItemCaseSensitive(v1_sleep_actionJSON, "seconds");
    if (cJSON_IsNull(seconds)) {
        seconds = NULL;
    }
    if (!seconds) {
        goto end;
    }

    
    if(!cJSON_IsNumber(seconds))
    {
    goto end; //Numeric
    }


    v1_sleep_action_local_var = v1_sleep_action_create_internal (
        seconds->valuedouble
        );

    return v1_sleep_action_local_var;
end:
    return NULL;

}
