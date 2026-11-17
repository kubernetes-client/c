#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_eviction_responder.h"



static v1_eviction_responder_t *v1_eviction_responder_create_internal(
    char *name,
    int *priority
    ) {
    v1_eviction_responder_t *v1_eviction_responder_local_var = malloc(sizeof(v1_eviction_responder_t));
    if (!v1_eviction_responder_local_var) {
        return NULL;
    }
    memset(v1_eviction_responder_local_var, 0, sizeof(v1_eviction_responder_t));
    v1_eviction_responder_local_var->_library_owned = 1;
    v1_eviction_responder_local_var->name = name;
    v1_eviction_responder_local_var->priority = priority;
    return v1_eviction_responder_local_var;
}

__attribute__((deprecated)) v1_eviction_responder_t *v1_eviction_responder_create(
    char *name,
    int *priority
    ) {
    int *priority_copy = NULL;
    if (priority) {
        priority_copy = malloc(sizeof(int));
        if (priority_copy) *priority_copy = *priority;
    }
    v1_eviction_responder_t *result = v1_eviction_responder_create_internal (
        name,
        priority_copy
        );
    if (!result) {
        free(priority_copy);
    }
    return result;
}

void v1_eviction_responder_free(v1_eviction_responder_t *v1_eviction_responder) {
    if(NULL == v1_eviction_responder){
        return ;
    }
    if(v1_eviction_responder->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_eviction_responder_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_eviction_responder->name) {
        free(v1_eviction_responder->name);
        v1_eviction_responder->name = NULL;
    }
    if (v1_eviction_responder->priority) {
        free(v1_eviction_responder->priority);
        v1_eviction_responder->priority = NULL;
    }
    free(v1_eviction_responder);
}

cJSON *v1_eviction_responder_convertToJSON(v1_eviction_responder_t *v1_eviction_responder) {
    cJSON *item = cJSON_CreateObject();

    // v1_eviction_responder->name
    if (!v1_eviction_responder->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", v1_eviction_responder->name) == NULL) {
    goto fail; //String
    }


    // v1_eviction_responder->priority
    if (!v1_eviction_responder->priority) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "priority", *v1_eviction_responder->priority) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_eviction_responder_t *v1_eviction_responder_parseFromJSON(cJSON *v1_eviction_responderJSON){

    v1_eviction_responder_t *v1_eviction_responder_local_var = NULL;

    char *name_local_str = NULL;

    // define the local variable for v1_eviction_responder->priority
    int *priority_local_var = NULL;

    // v1_eviction_responder->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1_eviction_responderJSON, "name");
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

    // v1_eviction_responder->priority
    cJSON *priority = cJSON_GetObjectItemCaseSensitive(v1_eviction_responderJSON, "priority");
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


    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);

    v1_eviction_responder_local_var = v1_eviction_responder_create_internal (
        name_local_str,
        priority_local_var
        );

    if (!v1_eviction_responder_local_var) {
        goto end;
    }

    return v1_eviction_responder_local_var;
end:
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    if (priority_local_var) {
        free(priority_local_var);
        priority_local_var = NULL;
    }
    return NULL;

}
