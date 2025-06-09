#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta2_device_capacity.h"



static v1beta2_device_capacity_t *v1beta2_device_capacity_create_internal(
    char *value
    ) {
    v1beta2_device_capacity_t *v1beta2_device_capacity_local_var = malloc(sizeof(v1beta2_device_capacity_t));
    if (!v1beta2_device_capacity_local_var) {
        return NULL;
    }
    v1beta2_device_capacity_local_var->value = value;

    v1beta2_device_capacity_local_var->_library_owned = 1;
    return v1beta2_device_capacity_local_var;
}

__attribute__((deprecated)) v1beta2_device_capacity_t *v1beta2_device_capacity_create(
    char *value
    ) {
    return v1beta2_device_capacity_create_internal (
        value
        );
}

void v1beta2_device_capacity_free(v1beta2_device_capacity_t *v1beta2_device_capacity) {
    if(NULL == v1beta2_device_capacity){
        return ;
    }
    if(v1beta2_device_capacity->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1beta2_device_capacity_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta2_device_capacity->value) {
        free(v1beta2_device_capacity->value);
        v1beta2_device_capacity->value = NULL;
    }
    free(v1beta2_device_capacity);
}

cJSON *v1beta2_device_capacity_convertToJSON(v1beta2_device_capacity_t *v1beta2_device_capacity) {
    cJSON *item = cJSON_CreateObject();

    // v1beta2_device_capacity->value
    if (!v1beta2_device_capacity->value) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "value", v1beta2_device_capacity->value) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1beta2_device_capacity_t *v1beta2_device_capacity_parseFromJSON(cJSON *v1beta2_device_capacityJSON){

    v1beta2_device_capacity_t *v1beta2_device_capacity_local_var = NULL;

    // v1beta2_device_capacity->value
    cJSON *value = cJSON_GetObjectItemCaseSensitive(v1beta2_device_capacityJSON, "value");
    if (cJSON_IsNull(value)) {
        value = NULL;
    }
    if (!value) {
        goto end;
    }

    
    if(!cJSON_IsString(value))
    {
    goto end; //String
    }


    v1beta2_device_capacity_local_var = v1beta2_device_capacity_create_internal (
        strdup(value->valuestring)
        );

    return v1beta2_device_capacity_local_var;
end:
    return NULL;

}
