#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_device_capacity.h"



static v1_device_capacity_t *v1_device_capacity_create_internal(
    v1_capacity_request_policy_t *request_policy,
    char *value
    ) {
    v1_device_capacity_t *v1_device_capacity_local_var = malloc(sizeof(v1_device_capacity_t));
    if (!v1_device_capacity_local_var) {
        return NULL;
    }
    v1_device_capacity_local_var->request_policy = request_policy;
    v1_device_capacity_local_var->value = value;

    v1_device_capacity_local_var->_library_owned = 1;
    return v1_device_capacity_local_var;
}

__attribute__((deprecated)) v1_device_capacity_t *v1_device_capacity_create(
    v1_capacity_request_policy_t *request_policy,
    char *value
    ) {
    return v1_device_capacity_create_internal (
        request_policy,
        value
        );
}

void v1_device_capacity_free(v1_device_capacity_t *v1_device_capacity) {
    if(NULL == v1_device_capacity){
        return ;
    }
    if(v1_device_capacity->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_device_capacity_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_device_capacity->request_policy) {
        v1_capacity_request_policy_free(v1_device_capacity->request_policy);
        v1_device_capacity->request_policy = NULL;
    }
    if (v1_device_capacity->value) {
        free(v1_device_capacity->value);
        v1_device_capacity->value = NULL;
    }
    free(v1_device_capacity);
}

cJSON *v1_device_capacity_convertToJSON(v1_device_capacity_t *v1_device_capacity) {
    cJSON *item = cJSON_CreateObject();

    // v1_device_capacity->request_policy
    if(v1_device_capacity->request_policy) {
    cJSON *request_policy_local_JSON = v1_capacity_request_policy_convertToJSON(v1_device_capacity->request_policy);
    if(request_policy_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "requestPolicy", request_policy_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_device_capacity->value
    if (!v1_device_capacity->value) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "value", v1_device_capacity->value) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_device_capacity_t *v1_device_capacity_parseFromJSON(cJSON *v1_device_capacityJSON){

    v1_device_capacity_t *v1_device_capacity_local_var = NULL;

    // define the local variable for v1_device_capacity->request_policy
    v1_capacity_request_policy_t *request_policy_local_nonprim = NULL;

    // v1_device_capacity->request_policy
    cJSON *request_policy = cJSON_GetObjectItemCaseSensitive(v1_device_capacityJSON, "requestPolicy");
    if (cJSON_IsNull(request_policy)) {
        request_policy = NULL;
    }
    if (request_policy) { 
    request_policy_local_nonprim = v1_capacity_request_policy_parseFromJSON(request_policy); //nonprimitive
    }

    // v1_device_capacity->value
    cJSON *value = cJSON_GetObjectItemCaseSensitive(v1_device_capacityJSON, "value");
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


    v1_device_capacity_local_var = v1_device_capacity_create_internal (
        request_policy ? request_policy_local_nonprim : NULL,
        strdup(value->valuestring)
        );

    return v1_device_capacity_local_var;
end:
    if (request_policy_local_nonprim) {
        v1_capacity_request_policy_free(request_policy_local_nonprim);
        request_policy_local_nonprim = NULL;
    }
    return NULL;

}
