#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_stateful_set_ordinals.h"



static v1_stateful_set_ordinals_t *v1_stateful_set_ordinals_create_internal(
    int *start
    ) {
    v1_stateful_set_ordinals_t *v1_stateful_set_ordinals_local_var = malloc(sizeof(v1_stateful_set_ordinals_t));
    if (!v1_stateful_set_ordinals_local_var) {
        return NULL;
    }
    memset(v1_stateful_set_ordinals_local_var, 0, sizeof(v1_stateful_set_ordinals_t));
    v1_stateful_set_ordinals_local_var->_library_owned = 1;
    v1_stateful_set_ordinals_local_var->start = start;
    return v1_stateful_set_ordinals_local_var;
}

__attribute__((deprecated)) v1_stateful_set_ordinals_t *v1_stateful_set_ordinals_create(
    int *start
    ) {
    int *start_copy = NULL;
    if (start) {
        start_copy = malloc(sizeof(int));
        if (start_copy) *start_copy = *start;
    }
    v1_stateful_set_ordinals_t *result = v1_stateful_set_ordinals_create_internal (
        start_copy
        );
    if (!result) {
        free(start_copy);
    }
    return result;
}

void v1_stateful_set_ordinals_free(v1_stateful_set_ordinals_t *v1_stateful_set_ordinals) {
    if(NULL == v1_stateful_set_ordinals){
        return ;
    }
    if(v1_stateful_set_ordinals->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_stateful_set_ordinals_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_stateful_set_ordinals->start) {
        free(v1_stateful_set_ordinals->start);
        v1_stateful_set_ordinals->start = NULL;
    }
    free(v1_stateful_set_ordinals);
}

cJSON *v1_stateful_set_ordinals_convertToJSON(v1_stateful_set_ordinals_t *v1_stateful_set_ordinals) {
    cJSON *item = cJSON_CreateObject();

    // v1_stateful_set_ordinals->start
    if(v1_stateful_set_ordinals->start) {
    if(cJSON_AddNumberToObject(item, "start", *v1_stateful_set_ordinals->start) == NULL) {
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

v1_stateful_set_ordinals_t *v1_stateful_set_ordinals_parseFromJSON(cJSON *v1_stateful_set_ordinalsJSON){

    v1_stateful_set_ordinals_t *v1_stateful_set_ordinals_local_var = NULL;

    // define the local variable for v1_stateful_set_ordinals->start
    int *start_local_var = NULL;

    // v1_stateful_set_ordinals->start
    cJSON *start = cJSON_GetObjectItemCaseSensitive(v1_stateful_set_ordinalsJSON, "start");
    if (cJSON_IsNull(start)) {
        start = NULL;
    }
    if (start) { 
    if(!cJSON_IsNumber(start))
    {
    goto end; //Numeric
    }
    start_local_var = malloc(sizeof(int));
    if(!start_local_var)
    {
        goto end;
    }
    *start_local_var = start->valuedouble;
    }



    v1_stateful_set_ordinals_local_var = v1_stateful_set_ordinals_create_internal (
        start_local_var
        );

    if (!v1_stateful_set_ordinals_local_var) {
        goto end;
    }

    return v1_stateful_set_ordinals_local_var;
end:
    if (start_local_var) {
        free(start_local_var);
        start_local_var = NULL;
    }
    return NULL;

}
