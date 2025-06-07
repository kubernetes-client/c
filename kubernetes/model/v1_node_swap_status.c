#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_node_swap_status.h"



static v1_node_swap_status_t *v1_node_swap_status_create_internal(
    long capacity
    ) {
    v1_node_swap_status_t *v1_node_swap_status_local_var = malloc(sizeof(v1_node_swap_status_t));
    if (!v1_node_swap_status_local_var) {
        return NULL;
    }
    v1_node_swap_status_local_var->capacity = capacity;

    v1_node_swap_status_local_var->_library_owned = 1;
    return v1_node_swap_status_local_var;
}

__attribute__((deprecated)) v1_node_swap_status_t *v1_node_swap_status_create(
    long capacity
    ) {
    return v1_node_swap_status_create_internal (
        capacity
        );
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
    free(v1_node_swap_status);
}

cJSON *v1_node_swap_status_convertToJSON(v1_node_swap_status_t *v1_node_swap_status) {
    cJSON *item = cJSON_CreateObject();

    // v1_node_swap_status->capacity
    if(v1_node_swap_status->capacity) {
    if(cJSON_AddNumberToObject(item, "capacity", v1_node_swap_status->capacity) == NULL) {
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
    }


    v1_node_swap_status_local_var = v1_node_swap_status_create_internal (
        capacity ? capacity->valuedouble : 0
        );

    return v1_node_swap_status_local_var;
end:
    return NULL;

}
