#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_scale_status.h"



static v1_scale_status_t *v1_scale_status_create_internal(
    int *replicas,
    char *selector
    ) {
    v1_scale_status_t *v1_scale_status_local_var = malloc(sizeof(v1_scale_status_t));
    if (!v1_scale_status_local_var) {
        return NULL;
    }
    memset(v1_scale_status_local_var, 0, sizeof(v1_scale_status_t));
    v1_scale_status_local_var->_library_owned = 1;
    v1_scale_status_local_var->replicas = replicas;
    v1_scale_status_local_var->selector = selector;
    return v1_scale_status_local_var;
}

__attribute__((deprecated)) v1_scale_status_t *v1_scale_status_create(
    int *replicas,
    char *selector
    ) {
    int *replicas_copy = NULL;
    if (replicas) {
        replicas_copy = malloc(sizeof(int));
        if (replicas_copy) *replicas_copy = *replicas;
    }
    v1_scale_status_t *result = v1_scale_status_create_internal (
        replicas_copy,
        selector
        );
    if (!result) {
        free(replicas_copy);
    }
    return result;
}

void v1_scale_status_free(v1_scale_status_t *v1_scale_status) {
    if(NULL == v1_scale_status){
        return ;
    }
    if(v1_scale_status->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_scale_status_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_scale_status->replicas) {
        free(v1_scale_status->replicas);
        v1_scale_status->replicas = NULL;
    }
    if (v1_scale_status->selector) {
        free(v1_scale_status->selector);
        v1_scale_status->selector = NULL;
    }
    free(v1_scale_status);
}

cJSON *v1_scale_status_convertToJSON(v1_scale_status_t *v1_scale_status) {
    cJSON *item = cJSON_CreateObject();

    // v1_scale_status->replicas
    if (!v1_scale_status->replicas) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "replicas", *v1_scale_status->replicas) == NULL) {
    goto fail; //Numeric
    }


    // v1_scale_status->selector
    if(v1_scale_status->selector) {
    if(cJSON_AddStringToObject(item, "selector", v1_scale_status->selector) == NULL) {
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

v1_scale_status_t *v1_scale_status_parseFromJSON(cJSON *v1_scale_statusJSON){

    v1_scale_status_t *v1_scale_status_local_var = NULL;

    // define the local variable for v1_scale_status->replicas
    int *replicas_local_var = NULL;

    char *selector_local_str = NULL;

    // v1_scale_status->replicas
    cJSON *replicas = cJSON_GetObjectItemCaseSensitive(v1_scale_statusJSON, "replicas");
    if (cJSON_IsNull(replicas)) {
        replicas = NULL;
    }
    if (!replicas) {
        goto end;
    }

    
    if(!cJSON_IsNumber(replicas))
    {
    goto end; //Numeric
    }
    replicas_local_var = malloc(sizeof(int));
    if(!replicas_local_var)
    {
        goto end;
    }
    *replicas_local_var = replicas->valuedouble;

    // v1_scale_status->selector
    cJSON *selector = cJSON_GetObjectItemCaseSensitive(v1_scale_statusJSON, "selector");
    if (cJSON_IsNull(selector)) {
        selector = NULL;
    }
    if (selector) { 
    if(!cJSON_IsString(selector) && !cJSON_IsNull(selector))
    {
    goto end; //String
    }
    }


    if (selector && !cJSON_IsNull(selector)) selector_local_str = strdup(selector->valuestring);

    v1_scale_status_local_var = v1_scale_status_create_internal (
        replicas_local_var,
        selector_local_str
        );

    if (!v1_scale_status_local_var) {
        goto end;
    }

    return v1_scale_status_local_var;
end:
    if (replicas_local_var) {
        free(replicas_local_var);
        replicas_local_var = NULL;
    }
    if (selector_local_str) {
        free(selector_local_str);
        selector_local_str = NULL;
    }
    return NULL;

}
