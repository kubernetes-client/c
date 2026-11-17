#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_sleep_action.h"



static v1_sleep_action_t *v1_sleep_action_create_internal(
    long *seconds
    ) {
    v1_sleep_action_t *v1_sleep_action_local_var = malloc(sizeof(v1_sleep_action_t));
    if (!v1_sleep_action_local_var) {
        return NULL;
    }
    memset(v1_sleep_action_local_var, 0, sizeof(v1_sleep_action_t));
    v1_sleep_action_local_var->_library_owned = 1;
    v1_sleep_action_local_var->seconds = seconds;
    return v1_sleep_action_local_var;
}

__attribute__((deprecated)) v1_sleep_action_t *v1_sleep_action_create(
    long *seconds
    ) {
    long *seconds_copy = NULL;
    if (seconds) {
        seconds_copy = malloc(sizeof(long));
        if (seconds_copy) *seconds_copy = *seconds;
    }
    v1_sleep_action_t *result = v1_sleep_action_create_internal (
        seconds_copy
        );
    if (!result) {
        free(seconds_copy);
    }
    return result;
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
    if (v1_sleep_action->seconds) {
        free(v1_sleep_action->seconds);
        v1_sleep_action->seconds = NULL;
    }
    free(v1_sleep_action);
}

cJSON *v1_sleep_action_convertToJSON(v1_sleep_action_t *v1_sleep_action) {
    cJSON *item = cJSON_CreateObject();

    // v1_sleep_action->seconds
    if (!v1_sleep_action->seconds) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "seconds", *v1_sleep_action->seconds) == NULL) {
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

    // define the local variable for v1_sleep_action->seconds
    long *seconds_local_var = NULL;

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
    seconds_local_var = malloc(sizeof(long));
    if(!seconds_local_var)
    {
        goto end;
    }
    *seconds_local_var = seconds->valuedouble;



    v1_sleep_action_local_var = v1_sleep_action_create_internal (
        seconds_local_var
        );

    if (!v1_sleep_action_local_var) {
        goto end;
    }

    return v1_sleep_action_local_var;
end:
    if (seconds_local_var) {
        free(seconds_local_var);
        seconds_local_var = NULL;
    }
    return NULL;

}
