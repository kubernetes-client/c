#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha1_target_responder.h"



static v1alpha1_target_responder_t *v1alpha1_target_responder_create_internal(
    char *name,
    int *priority,
    char *state
    ) {
    v1alpha1_target_responder_t *v1alpha1_target_responder_local_var = malloc(sizeof(v1alpha1_target_responder_t));
    if (!v1alpha1_target_responder_local_var) {
        return NULL;
    }
    memset(v1alpha1_target_responder_local_var, 0, sizeof(v1alpha1_target_responder_t));
    v1alpha1_target_responder_local_var->_library_owned = 1;
    v1alpha1_target_responder_local_var->name = name;
    v1alpha1_target_responder_local_var->priority = priority;
    v1alpha1_target_responder_local_var->state = state;
    return v1alpha1_target_responder_local_var;
}

__attribute__((deprecated)) v1alpha1_target_responder_t *v1alpha1_target_responder_create(
    char *name,
    int *priority,
    char *state
    ) {
    int *priority_copy = NULL;
    if (priority) {
        priority_copy = malloc(sizeof(int));
        if (priority_copy) *priority_copy = *priority;
    }
    v1alpha1_target_responder_t *result = v1alpha1_target_responder_create_internal (
        name,
        priority_copy,
        state
        );
    if (!result) {
        free(priority_copy);
    }
    return result;
}

void v1alpha1_target_responder_free(v1alpha1_target_responder_t *v1alpha1_target_responder) {
    if(NULL == v1alpha1_target_responder){
        return ;
    }
    if(v1alpha1_target_responder->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1alpha1_target_responder_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha1_target_responder->name) {
        free(v1alpha1_target_responder->name);
        v1alpha1_target_responder->name = NULL;
    }
    if (v1alpha1_target_responder->priority) {
        free(v1alpha1_target_responder->priority);
        v1alpha1_target_responder->priority = NULL;
    }
    if (v1alpha1_target_responder->state) {
        free(v1alpha1_target_responder->state);
        v1alpha1_target_responder->state = NULL;
    }
    free(v1alpha1_target_responder);
}

cJSON *v1alpha1_target_responder_convertToJSON(v1alpha1_target_responder_t *v1alpha1_target_responder) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha1_target_responder->name
    if (!v1alpha1_target_responder->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", v1alpha1_target_responder->name) == NULL) {
    goto fail; //String
    }


    // v1alpha1_target_responder->priority
    if (!v1alpha1_target_responder->priority) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "priority", *v1alpha1_target_responder->priority) == NULL) {
    goto fail; //Numeric
    }


    // v1alpha1_target_responder->state
    if (!v1alpha1_target_responder->state) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "state", v1alpha1_target_responder->state) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1alpha1_target_responder_t *v1alpha1_target_responder_parseFromJSON(cJSON *v1alpha1_target_responderJSON){

    v1alpha1_target_responder_t *v1alpha1_target_responder_local_var = NULL;

    char *name_local_str = NULL;

    // define the local variable for v1alpha1_target_responder->priority
    int *priority_local_var = NULL;

    char *state_local_str = NULL;

    // v1alpha1_target_responder->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1alpha1_target_responderJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // v1alpha1_target_responder->priority
    cJSON *priority = cJSON_GetObjectItemCaseSensitive(v1alpha1_target_responderJSON, "priority");
    if (cJSON_IsNull(priority)) {
        priority = NULL;
    }
    if (!priority) {
        goto end;
    }

    
    if(!cJSON_IsNumber(priority))
    {
    goto end; //Numeric
    }
    priority_local_var = malloc(sizeof(int));
    if(!priority_local_var)
    {
        goto end;
    }
    *priority_local_var = priority->valuedouble;

    // v1alpha1_target_responder->state
    cJSON *state = cJSON_GetObjectItemCaseSensitive(v1alpha1_target_responderJSON, "state");
    if (cJSON_IsNull(state)) {
        state = NULL;
    }
    if (!state) {
        goto end;
    }

    
    if(!cJSON_IsString(state))
    {
    goto end; //String
    }


    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);
    if (state && !cJSON_IsNull(state)) state_local_str = strdup(state->valuestring);

    v1alpha1_target_responder_local_var = v1alpha1_target_responder_create_internal (
        name_local_str,
        priority_local_var,
        state_local_str
        );

    if (!v1alpha1_target_responder_local_var) {
        goto end;
    }

    return v1alpha1_target_responder_local_var;
end:
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    if (priority_local_var) {
        free(priority_local_var);
        priority_local_var = NULL;
    }
    if (state_local_str) {
        free(state_local_str);
        state_local_str = NULL;
    }
    return NULL;

}
