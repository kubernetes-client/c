#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha3_device_constraint.h"



v1alpha3_device_constraint_t *v1alpha3_device_constraint_create(
    char *match_attribute,
    list_t *requests
    ) {
    v1alpha3_device_constraint_t *v1alpha3_device_constraint_local_var = malloc(sizeof(v1alpha3_device_constraint_t));
    if (!v1alpha3_device_constraint_local_var) {
        return NULL;
    }
    v1alpha3_device_constraint_local_var->match_attribute = match_attribute;
    v1alpha3_device_constraint_local_var->requests = requests;

    return v1alpha3_device_constraint_local_var;
}


void v1alpha3_device_constraint_free(v1alpha3_device_constraint_t *v1alpha3_device_constraint) {
    if(NULL == v1alpha3_device_constraint){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha3_device_constraint->match_attribute) {
        free(v1alpha3_device_constraint->match_attribute);
        v1alpha3_device_constraint->match_attribute = NULL;
    }
    if (v1alpha3_device_constraint->requests) {
        list_ForEach(listEntry, v1alpha3_device_constraint->requests) {
            free(listEntry->data);
        }
        list_freeList(v1alpha3_device_constraint->requests);
        v1alpha3_device_constraint->requests = NULL;
    }
    free(v1alpha3_device_constraint);
}

cJSON *v1alpha3_device_constraint_convertToJSON(v1alpha3_device_constraint_t *v1alpha3_device_constraint) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha3_device_constraint->match_attribute
    if(v1alpha3_device_constraint->match_attribute) {
    if(cJSON_AddStringToObject(item, "matchAttribute", v1alpha3_device_constraint->match_attribute) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha3_device_constraint->requests
    if(v1alpha3_device_constraint->requests) {
    cJSON *requests = cJSON_AddArrayToObject(item, "requests");
    if(requests == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *requestsListEntry;
    list_ForEach(requestsListEntry, v1alpha3_device_constraint->requests) {
    if(cJSON_AddStringToObject(requests, "", (char*)requestsListEntry->data) == NULL)
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

v1alpha3_device_constraint_t *v1alpha3_device_constraint_parseFromJSON(cJSON *v1alpha3_device_constraintJSON){

    v1alpha3_device_constraint_t *v1alpha3_device_constraint_local_var = NULL;

    // define the local list for v1alpha3_device_constraint->requests
    list_t *requestsList = NULL;

    // v1alpha3_device_constraint->match_attribute
    cJSON *match_attribute = cJSON_GetObjectItemCaseSensitive(v1alpha3_device_constraintJSON, "matchAttribute");
    if (match_attribute) { 
    if(!cJSON_IsString(match_attribute) && !cJSON_IsNull(match_attribute))
    {
    goto end; //String
    }
    }

    // v1alpha3_device_constraint->requests
    cJSON *requests = cJSON_GetObjectItemCaseSensitive(v1alpha3_device_constraintJSON, "requests");
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


    v1alpha3_device_constraint_local_var = v1alpha3_device_constraint_create (
        match_attribute && !cJSON_IsNull(match_attribute) ? strdup(match_attribute->valuestring) : NULL,
        requests ? requestsList : NULL
        );

    return v1alpha3_device_constraint_local_var;
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
