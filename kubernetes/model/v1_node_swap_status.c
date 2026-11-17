#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_node_swap_status.h"



static v1_node_swap_status_t *v1_node_swap_status_create_internal(
    long *capacity
    ) {
    v1_node_swap_status_t *v1_node_swap_status_local_var = malloc(sizeof(v1_node_swap_status_t));
    if (!v1_node_swap_status_local_var) {
        return NULL;
    }
    memset(v1_node_swap_status_local_var, 0, sizeof(v1_node_swap_status_t));
    v1_node_swap_status_local_var->_library_owned = 1;
    v1_node_swap_status_local_var->capacity = capacity;
    return v1_node_swap_status_local_var;
}

__attribute__((deprecated)) v1_node_swap_status_t *v1_node_swap_status_create(
    long *capacity
    ) {
    long *capacity_copy = NULL;
    if (capacity) {
        capacity_copy = malloc(sizeof(long));
        if (capacity_copy) *capacity_copy = *capacity;
    }
    v1_node_swap_status_t *result = v1_node_swap_status_create_internal (
        capacity_copy
        );
    if (!result) {
        free(capacity_copy);
    }
    return result;
}

void v1_node_swap_status_free(v1_node_swap_status_t *v1_node_swap_status) {
    if(NULL == v1_node_swap_status){
        return ;
    }
    if(v1_node_swap_status->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_node_swap_status_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_node_swap_status->capacity) {
        free(v1_node_swap_status->capacity);
        v1_node_swap_status->capacity = NULL;
    }
    free(v1_node_swap_status);
}

cJSON *v1_node_swap_status_convertToJSON(v1_node_swap_status_t *v1_node_swap_status) {
    cJSON *item = cJSON_CreateObject();

    // v1_node_swap_status->capacity
    if(v1_node_swap_status->capacity) {
    if(cJSON_AddNumberToObject(item, "capacity", *v1_node_swap_status->capacity) == NULL) {
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

v1_node_swap_status_t *v1_node_swap_status_parseFromJSON(cJSON *v1_node_swap_statusJSON){

    v1_node_swap_status_t *v1_node_swap_status_local_var = NULL;

    // define the local variable for v1_node_swap_status->capacity
    long *capacity_local_var = NULL;

    // v1_node_swap_status->capacity
    cJSON *capacity = cJSON_GetObjectItemCaseSensitive(v1_node_swap_statusJSON, "capacity");
    if (cJSON_IsNull(capacity)) {
        capacity = NULL;
    }
    if (capacity) { 
    if(!cJSON_IsNumber(capacity))
    {
    goto end; //Numeric
    }
    capacity_local_var = malloc(sizeof(long));
    if(!capacity_local_var)
    {
        goto end;
    }
    *capacity_local_var = capacity->valuedouble;
    }



    v1_node_swap_status_local_var = v1_node_swap_status_create_internal (
        capacity_local_var
        );

    if (!v1_node_swap_status_local_var) {
        goto end;
    }

    return v1_node_swap_status_local_var;
end:
    if (capacity_local_var) {
        free(capacity_local_var);
        capacity_local_var = NULL;
    }
    return NULL;

}
