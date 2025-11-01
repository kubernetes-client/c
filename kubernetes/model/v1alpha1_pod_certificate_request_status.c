#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha1_pod_certificate_request_status.h"



static v1alpha1_pod_certificate_request_status_t *v1alpha1_pod_certificate_request_status_create_internal(
    char *begin_refresh_at,
    char *certificate_chain,
    list_t *conditions,
    char *not_after,
    char *not_before
    ) {
    v1alpha1_pod_certificate_request_status_t *v1alpha1_pod_certificate_request_status_local_var = malloc(sizeof(v1alpha1_pod_certificate_request_status_t));
    if (!v1alpha1_pod_certificate_request_status_local_var) {
        return NULL;
    }
    v1alpha1_pod_certificate_request_status_local_var->begin_refresh_at = begin_refresh_at;
    v1alpha1_pod_certificate_request_status_local_var->certificate_chain = certificate_chain;
    v1alpha1_pod_certificate_request_status_local_var->conditions = conditions;
    v1alpha1_pod_certificate_request_status_local_var->not_after = not_after;
    v1alpha1_pod_certificate_request_status_local_var->not_before = not_before;

    v1alpha1_pod_certificate_request_status_local_var->_library_owned = 1;
    return v1alpha1_pod_certificate_request_status_local_var;
}

__attribute__((deprecated)) v1alpha1_pod_certificate_request_status_t *v1alpha1_pod_certificate_request_status_create(
    char *begin_refresh_at,
    char *certificate_chain,
    list_t *conditions,
    char *not_after,
    char *not_before
    ) {
    return v1alpha1_pod_certificate_request_status_create_internal (
        begin_refresh_at,
        certificate_chain,
        conditions,
        not_after,
        not_before
        );
}

void v1alpha1_pod_certificate_request_status_free(v1alpha1_pod_certificate_request_status_t *v1alpha1_pod_certificate_request_status) {
    if(NULL == v1alpha1_pod_certificate_request_status){
        return ;
    }
    if(v1alpha1_pod_certificate_request_status->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1alpha1_pod_certificate_request_status_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha1_pod_certificate_request_status->begin_refresh_at) {
        free(v1alpha1_pod_certificate_request_status->begin_refresh_at);
        v1alpha1_pod_certificate_request_status->begin_refresh_at = NULL;
    }
    if (v1alpha1_pod_certificate_request_status->certificate_chain) {
        free(v1alpha1_pod_certificate_request_status->certificate_chain);
        v1alpha1_pod_certificate_request_status->certificate_chain = NULL;
    }
    if (v1alpha1_pod_certificate_request_status->conditions) {
        list_ForEach(listEntry, v1alpha1_pod_certificate_request_status->conditions) {
            v1_condition_free(listEntry->data);
        }
        list_freeList(v1alpha1_pod_certificate_request_status->conditions);
        v1alpha1_pod_certificate_request_status->conditions = NULL;
    }
    if (v1alpha1_pod_certificate_request_status->not_after) {
        free(v1alpha1_pod_certificate_request_status->not_after);
        v1alpha1_pod_certificate_request_status->not_after = NULL;
    }
    if (v1alpha1_pod_certificate_request_status->not_before) {
        free(v1alpha1_pod_certificate_request_status->not_before);
        v1alpha1_pod_certificate_request_status->not_before = NULL;
    }
    free(v1alpha1_pod_certificate_request_status);
}

cJSON *v1alpha1_pod_certificate_request_status_convertToJSON(v1alpha1_pod_certificate_request_status_t *v1alpha1_pod_certificate_request_status) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha1_pod_certificate_request_status->begin_refresh_at
    if(v1alpha1_pod_certificate_request_status->begin_refresh_at) {
    if(cJSON_AddStringToObject(item, "beginRefreshAt", v1alpha1_pod_certificate_request_status->begin_refresh_at) == NULL) {
    goto fail; //Date-Time
    }
    }


    // v1alpha1_pod_certificate_request_status->certificate_chain
    if(v1alpha1_pod_certificate_request_status->certificate_chain) {
    if(cJSON_AddStringToObject(item, "certificateChain", v1alpha1_pod_certificate_request_status->certificate_chain) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha1_pod_certificate_request_status->conditions
    if(v1alpha1_pod_certificate_request_status->conditions) {
    cJSON *conditions = cJSON_AddArrayToObject(item, "conditions");
    if(conditions == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *conditionsListEntry;
    if (v1alpha1_pod_certificate_request_status->conditions) {
    list_ForEach(conditionsListEntry, v1alpha1_pod_certificate_request_status->conditions) {
    cJSON *itemLocal = v1_condition_convertToJSON(conditionsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(conditions, itemLocal);
    }
    }
    }


    // v1alpha1_pod_certificate_request_status->not_after
    if(v1alpha1_pod_certificate_request_status->not_after) {
    if(cJSON_AddStringToObject(item, "notAfter", v1alpha1_pod_certificate_request_status->not_after) == NULL) {
    goto fail; //Date-Time
    }
    }


    // v1alpha1_pod_certificate_request_status->not_before
    if(v1alpha1_pod_certificate_request_status->not_before) {
    if(cJSON_AddStringToObject(item, "notBefore", v1alpha1_pod_certificate_request_status->not_before) == NULL) {
    goto fail; //Date-Time
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1alpha1_pod_certificate_request_status_t *v1alpha1_pod_certificate_request_status_parseFromJSON(cJSON *v1alpha1_pod_certificate_request_statusJSON){

    v1alpha1_pod_certificate_request_status_t *v1alpha1_pod_certificate_request_status_local_var = NULL;

    // define the local list for v1alpha1_pod_certificate_request_status->conditions
    list_t *conditionsList = NULL;

    // v1alpha1_pod_certificate_request_status->begin_refresh_at
    cJSON *begin_refresh_at = cJSON_GetObjectItemCaseSensitive(v1alpha1_pod_certificate_request_statusJSON, "beginRefreshAt");
    if (cJSON_IsNull(begin_refresh_at)) {
        begin_refresh_at = NULL;
    }
    if (begin_refresh_at) { 
    if(!cJSON_IsString(begin_refresh_at) && !cJSON_IsNull(begin_refresh_at))
    {
    goto end; //DateTime
    }
    }

    // v1alpha1_pod_certificate_request_status->certificate_chain
    cJSON *certificate_chain = cJSON_GetObjectItemCaseSensitive(v1alpha1_pod_certificate_request_statusJSON, "certificateChain");
    if (cJSON_IsNull(certificate_chain)) {
        certificate_chain = NULL;
    }
    if (certificate_chain) { 
    if(!cJSON_IsString(certificate_chain) && !cJSON_IsNull(certificate_chain))
    {
    goto end; //String
    }
    }

    // v1alpha1_pod_certificate_request_status->conditions
    cJSON *conditions = cJSON_GetObjectItemCaseSensitive(v1alpha1_pod_certificate_request_statusJSON, "conditions");
    if (cJSON_IsNull(conditions)) {
        conditions = NULL;
    }
    if (conditions) { 
    cJSON *conditions_local_nonprimitive = NULL;
    if(!cJSON_IsArray(conditions)){
        goto end; //nonprimitive container
    }

    conditionsList = list_createList();

    cJSON_ArrayForEach(conditions_local_nonprimitive,conditions )
    {
        if(!cJSON_IsObject(conditions_local_nonprimitive)){
            goto end;
        }
        v1_condition_t *conditionsItem = v1_condition_parseFromJSON(conditions_local_nonprimitive);

        list_addElement(conditionsList, conditionsItem);
    }
    }

    // v1alpha1_pod_certificate_request_status->not_after
    cJSON *not_after = cJSON_GetObjectItemCaseSensitive(v1alpha1_pod_certificate_request_statusJSON, "notAfter");
    if (cJSON_IsNull(not_after)) {
        not_after = NULL;
    }
    if (not_after) { 
    if(!cJSON_IsString(not_after) && !cJSON_IsNull(not_after))
    {
    goto end; //DateTime
    }
    }

    // v1alpha1_pod_certificate_request_status->not_before
    cJSON *not_before = cJSON_GetObjectItemCaseSensitive(v1alpha1_pod_certificate_request_statusJSON, "notBefore");
    if (cJSON_IsNull(not_before)) {
        not_before = NULL;
    }
    if (not_before) { 
    if(!cJSON_IsString(not_before) && !cJSON_IsNull(not_before))
    {
    goto end; //DateTime
    }
    }


    v1alpha1_pod_certificate_request_status_local_var = v1alpha1_pod_certificate_request_status_create_internal (
        begin_refresh_at && !cJSON_IsNull(begin_refresh_at) ? strdup(begin_refresh_at->valuestring) : NULL,
        certificate_chain && !cJSON_IsNull(certificate_chain) ? strdup(certificate_chain->valuestring) : NULL,
        conditions ? conditionsList : NULL,
        not_after && !cJSON_IsNull(not_after) ? strdup(not_after->valuestring) : NULL,
        not_before && !cJSON_IsNull(not_before) ? strdup(not_before->valuestring) : NULL
        );

    return v1alpha1_pod_certificate_request_status_local_var;
end:
    if (conditionsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, conditionsList) {
            v1_condition_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(conditionsList);
        conditionsList = NULL;
    }
    return NULL;

}
