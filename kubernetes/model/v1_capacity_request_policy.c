#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_capacity_request_policy.h"



static v1_capacity_request_policy_t *v1_capacity_request_policy_create_internal(
    char *_default,
    v1_capacity_request_policy_range_t *valid_range,
    list_t *valid_values
    ) {
    v1_capacity_request_policy_t *v1_capacity_request_policy_local_var = malloc(sizeof(v1_capacity_request_policy_t));
    if (!v1_capacity_request_policy_local_var) {
        return NULL;
    }
    v1_capacity_request_policy_local_var->_default = _default;
    v1_capacity_request_policy_local_var->valid_range = valid_range;
    v1_capacity_request_policy_local_var->valid_values = valid_values;

    v1_capacity_request_policy_local_var->_library_owned = 1;
    return v1_capacity_request_policy_local_var;
}

__attribute__((deprecated)) v1_capacity_request_policy_t *v1_capacity_request_policy_create(
    char *_default,
    v1_capacity_request_policy_range_t *valid_range,
    list_t *valid_values
    ) {
    return v1_capacity_request_policy_create_internal (
        _default,
        valid_range,
        valid_values
        );
}

void v1_capacity_request_policy_free(v1_capacity_request_policy_t *v1_capacity_request_policy) {
    if(NULL == v1_capacity_request_policy){
        return ;
    }
    if(v1_capacity_request_policy->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_capacity_request_policy_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_capacity_request_policy->_default) {
        free(v1_capacity_request_policy->_default);
        v1_capacity_request_policy->_default = NULL;
    }
    if (v1_capacity_request_policy->valid_range) {
        v1_capacity_request_policy_range_free(v1_capacity_request_policy->valid_range);
        v1_capacity_request_policy->valid_range = NULL;
    }
    if (v1_capacity_request_policy->valid_values) {
        list_ForEach(listEntry, v1_capacity_request_policy->valid_values) {
            free(listEntry->data);
        }
        list_freeList(v1_capacity_request_policy->valid_values);
        v1_capacity_request_policy->valid_values = NULL;
    }
    free(v1_capacity_request_policy);
}

cJSON *v1_capacity_request_policy_convertToJSON(v1_capacity_request_policy_t *v1_capacity_request_policy) {
    cJSON *item = cJSON_CreateObject();

    // v1_capacity_request_policy->_default
    if(v1_capacity_request_policy->_default) {
    if(cJSON_AddStringToObject(item, "default", v1_capacity_request_policy->_default) == NULL) {
    goto fail; //String
    }
    }


    // v1_capacity_request_policy->valid_range
    if(v1_capacity_request_policy->valid_range) {
    cJSON *valid_range_local_JSON = v1_capacity_request_policy_range_convertToJSON(v1_capacity_request_policy->valid_range);
    if(valid_range_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "validRange", valid_range_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_capacity_request_policy->valid_values
    if(v1_capacity_request_policy->valid_values) {
    cJSON *valid_values = cJSON_AddArrayToObject(item, "validValues");
    if(valid_values == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *valid_valuesListEntry;
    list_ForEach(valid_valuesListEntry, v1_capacity_request_policy->valid_values) {
    if(cJSON_AddStringToObject(valid_values, "", valid_valuesListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_capacity_request_policy_t *v1_capacity_request_policy_parseFromJSON(cJSON *v1_capacity_request_policyJSON){

    v1_capacity_request_policy_t *v1_capacity_request_policy_local_var = NULL;

    // define the local variable for v1_capacity_request_policy->valid_range
    v1_capacity_request_policy_range_t *valid_range_local_nonprim = NULL;

    // define the local list for v1_capacity_request_policy->valid_values
    list_t *valid_valuesList = NULL;

    // v1_capacity_request_policy->_default
    cJSON *_default = cJSON_GetObjectItemCaseSensitive(v1_capacity_request_policyJSON, "default");
    if (cJSON_IsNull(_default)) {
        _default = NULL;
    }
    if (_default) { 
    if(!cJSON_IsString(_default) && !cJSON_IsNull(_default))
    {
    goto end; //String
    }
    }

    // v1_capacity_request_policy->valid_range
    cJSON *valid_range = cJSON_GetObjectItemCaseSensitive(v1_capacity_request_policyJSON, "validRange");
    if (cJSON_IsNull(valid_range)) {
        valid_range = NULL;
    }
    if (valid_range) { 
    valid_range_local_nonprim = v1_capacity_request_policy_range_parseFromJSON(valid_range); //nonprimitive
    }

    // v1_capacity_request_policy->valid_values
    cJSON *valid_values = cJSON_GetObjectItemCaseSensitive(v1_capacity_request_policyJSON, "validValues");
    if (cJSON_IsNull(valid_values)) {
        valid_values = NULL;
    }
    if (valid_values) { 
    cJSON *valid_values_local = NULL;
    if(!cJSON_IsArray(valid_values)) {
        goto end;//primitive container
    }
    valid_valuesList = list_createList();

    cJSON_ArrayForEach(valid_values_local, valid_values)
    {
        if(!cJSON_IsString(valid_values_local))
        {
            goto end;
        }
        list_addElement(valid_valuesList , strdup(valid_values_local->valuestring));
    }
    }


    v1_capacity_request_policy_local_var = v1_capacity_request_policy_create_internal (
        _default && !cJSON_IsNull(_default) ? strdup(_default->valuestring) : NULL,
        valid_range ? valid_range_local_nonprim : NULL,
        valid_values ? valid_valuesList : NULL
        );

    return v1_capacity_request_policy_local_var;
end:
    if (valid_range_local_nonprim) {
        v1_capacity_request_policy_range_free(valid_range_local_nonprim);
        valid_range_local_nonprim = NULL;
    }
    if (valid_valuesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, valid_valuesList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(valid_valuesList);
        valid_valuesList = NULL;
    }
    return NULL;

}
