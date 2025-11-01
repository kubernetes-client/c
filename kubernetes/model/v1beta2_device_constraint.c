#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta2_device_constraint.h"



static v1beta2_device_constraint_t *v1beta2_device_constraint_create_internal(
    char *distinct_attribute,
    char *match_attribute,
    list_t *requests
    ) {
    v1beta2_device_constraint_t *v1beta2_device_constraint_local_var = malloc(sizeof(v1beta2_device_constraint_t));
    if (!v1beta2_device_constraint_local_var) {
        return NULL;
    }
    v1beta2_device_constraint_local_var->distinct_attribute = distinct_attribute;
    v1beta2_device_constraint_local_var->match_attribute = match_attribute;
    v1beta2_device_constraint_local_var->requests = requests;

    v1beta2_device_constraint_local_var->_library_owned = 1;
    return v1beta2_device_constraint_local_var;
}

__attribute__((deprecated)) v1beta2_device_constraint_t *v1beta2_device_constraint_create(
    char *distinct_attribute,
    char *match_attribute,
    list_t *requests
    ) {
    return v1beta2_device_constraint_create_internal (
        distinct_attribute,
        match_attribute,
        requests
        );
}

void v1beta2_device_constraint_free(v1beta2_device_constraint_t *v1beta2_device_constraint) {
    if(NULL == v1beta2_device_constraint){
        return ;
    }
    if(v1beta2_device_constraint->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1beta2_device_constraint_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta2_device_constraint->distinct_attribute) {
        free(v1beta2_device_constraint->distinct_attribute);
        v1beta2_device_constraint->distinct_attribute = NULL;
    }
    if (v1beta2_device_constraint->match_attribute) {
        free(v1beta2_device_constraint->match_attribute);
        v1beta2_device_constraint->match_attribute = NULL;
    }
    if (v1beta2_device_constraint->requests) {
        list_ForEach(listEntry, v1beta2_device_constraint->requests) {
            free(listEntry->data);
        }
        list_freeList(v1beta2_device_constraint->requests);
        v1beta2_device_constraint->requests = NULL;
    }
    free(v1beta2_device_constraint);
}

cJSON *v1beta2_device_constraint_convertToJSON(v1beta2_device_constraint_t *v1beta2_device_constraint) {
    cJSON *item = cJSON_CreateObject();

    // v1beta2_device_constraint->distinct_attribute
    if(v1beta2_device_constraint->distinct_attribute) {
    if(cJSON_AddStringToObject(item, "distinctAttribute", v1beta2_device_constraint->distinct_attribute) == NULL) {
    goto fail; //String
    }
    }


    // v1beta2_device_constraint->match_attribute
    if(v1beta2_device_constraint->match_attribute) {
    if(cJSON_AddStringToObject(item, "matchAttribute", v1beta2_device_constraint->match_attribute) == NULL) {
    goto fail; //String
    }
    }


    // v1beta2_device_constraint->requests
    if(v1beta2_device_constraint->requests) {
    cJSON *requests = cJSON_AddArrayToObject(item, "requests");
    if(requests == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *requestsListEntry;
    list_ForEach(requestsListEntry, v1beta2_device_constraint->requests) {
    if(cJSON_AddStringToObject(requests, "", requestsListEntry->data) == NULL)
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

v1beta2_device_constraint_t *v1beta2_device_constraint_parseFromJSON(cJSON *v1beta2_device_constraintJSON){

    v1beta2_device_constraint_t *v1beta2_device_constraint_local_var = NULL;

    // define the local list for v1beta2_device_constraint->requests
    list_t *requestsList = NULL;

    // v1beta2_device_constraint->distinct_attribute
    cJSON *distinct_attribute = cJSON_GetObjectItemCaseSensitive(v1beta2_device_constraintJSON, "distinctAttribute");
    if (cJSON_IsNull(distinct_attribute)) {
        distinct_attribute = NULL;
    }
    if (distinct_attribute) { 
    if(!cJSON_IsString(distinct_attribute) && !cJSON_IsNull(distinct_attribute))
    {
    goto end; //String
    }
    }

    // v1beta2_device_constraint->match_attribute
    cJSON *match_attribute = cJSON_GetObjectItemCaseSensitive(v1beta2_device_constraintJSON, "matchAttribute");
    if (cJSON_IsNull(match_attribute)) {
        match_attribute = NULL;
    }
    if (match_attribute) { 
    if(!cJSON_IsString(match_attribute) && !cJSON_IsNull(match_attribute))
    {
    goto end; //String
    }
    }

    // v1beta2_device_constraint->requests
    cJSON *requests = cJSON_GetObjectItemCaseSensitive(v1beta2_device_constraintJSON, "requests");
    if (cJSON_IsNull(requests)) {
        requests = NULL;
    }
    if (requests) { 
    cJSON *requests_local = NULL;
    if(!cJSON_IsArray(requests)) {
        goto end;//primitive container
    }
    requestsList = list_createList();

    cJSON_ArrayForEach(requests_local, requests)
    {
        if(!cJSON_IsString(requests_local))
        {
            goto end;
        }
        list_addElement(requestsList , strdup(requests_local->valuestring));
    }
    }


    v1beta2_device_constraint_local_var = v1beta2_device_constraint_create_internal (
        distinct_attribute && !cJSON_IsNull(distinct_attribute) ? strdup(distinct_attribute->valuestring) : NULL,
        match_attribute && !cJSON_IsNull(match_attribute) ? strdup(match_attribute->valuestring) : NULL,
        requests ? requestsList : NULL
        );

    return v1beta2_device_constraint_local_var;
end:
    if (requestsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, requestsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(requestsList);
        requestsList = NULL;
    }
    return NULL;

}
