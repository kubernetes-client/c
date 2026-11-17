#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha1_eviction_status.h"



static v1alpha1_eviction_status_t *v1alpha1_eviction_status_create_internal(
    list_t *conditions,
    long *observed_generation,
    list_t *requesters,
    list_t *responders,
    list_t *target_responders
    ) {
    v1alpha1_eviction_status_t *v1alpha1_eviction_status_local_var = malloc(sizeof(v1alpha1_eviction_status_t));
    if (!v1alpha1_eviction_status_local_var) {
        return NULL;
    }
    memset(v1alpha1_eviction_status_local_var, 0, sizeof(v1alpha1_eviction_status_t));
    v1alpha1_eviction_status_local_var->_library_owned = 1;
    v1alpha1_eviction_status_local_var->conditions = conditions;
    v1alpha1_eviction_status_local_var->observed_generation = observed_generation;
    v1alpha1_eviction_status_local_var->requesters = requesters;
    v1alpha1_eviction_status_local_var->responders = responders;
    v1alpha1_eviction_status_local_var->target_responders = target_responders;
    return v1alpha1_eviction_status_local_var;
}

__attribute__((deprecated)) v1alpha1_eviction_status_t *v1alpha1_eviction_status_create(
    list_t *conditions,
    long *observed_generation,
    list_t *requesters,
    list_t *responders,
    list_t *target_responders
    ) {
    long *observed_generation_copy = NULL;
    if (observed_generation) {
        observed_generation_copy = malloc(sizeof(long));
        if (observed_generation_copy) *observed_generation_copy = *observed_generation;
    }
    v1alpha1_eviction_status_t *result = v1alpha1_eviction_status_create_internal (
        conditions,
        observed_generation_copy,
        requesters,
        responders,
        target_responders
        );
    if (!result) {
        free(observed_generation_copy);
    }
    return result;
}

void v1alpha1_eviction_status_free(v1alpha1_eviction_status_t *v1alpha1_eviction_status) {
    if(NULL == v1alpha1_eviction_status){
        return ;
    }
    if(v1alpha1_eviction_status->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1alpha1_eviction_status_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha1_eviction_status->conditions) {
        list_ForEach(listEntry, v1alpha1_eviction_status->conditions) {
            v1_condition_free(listEntry->data);
        }
        list_freeList(v1alpha1_eviction_status->conditions);
        v1alpha1_eviction_status->conditions = NULL;
    }
    if (v1alpha1_eviction_status->observed_generation) {
        free(v1alpha1_eviction_status->observed_generation);
        v1alpha1_eviction_status->observed_generation = NULL;
    }
    if (v1alpha1_eviction_status->requesters) {
        list_ForEach(listEntry, v1alpha1_eviction_status->requesters) {
            v1alpha1_requester_free(listEntry->data);
        }
        list_freeList(v1alpha1_eviction_status->requesters);
        v1alpha1_eviction_status->requesters = NULL;
    }
    if (v1alpha1_eviction_status->responders) {
        list_ForEach(listEntry, v1alpha1_eviction_status->responders) {
            v1alpha1_responder_status_free(listEntry->data);
        }
        list_freeList(v1alpha1_eviction_status->responders);
        v1alpha1_eviction_status->responders = NULL;
    }
    if (v1alpha1_eviction_status->target_responders) {
        list_ForEach(listEntry, v1alpha1_eviction_status->target_responders) {
            v1alpha1_target_responder_free(listEntry->data);
        }
        list_freeList(v1alpha1_eviction_status->target_responders);
        v1alpha1_eviction_status->target_responders = NULL;
    }
    free(v1alpha1_eviction_status);
}

cJSON *v1alpha1_eviction_status_convertToJSON(v1alpha1_eviction_status_t *v1alpha1_eviction_status) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha1_eviction_status->conditions
    if(v1alpha1_eviction_status->conditions) {
    cJSON *conditions = cJSON_AddArrayToObject(item, "conditions");
    if(conditions == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *conditionsListEntry;
    if (v1alpha1_eviction_status->conditions) {
    list_ForEach(conditionsListEntry, v1alpha1_eviction_status->conditions) {
    cJSON *itemLocal = v1_condition_convertToJSON(conditionsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(conditions, itemLocal);
    }
    }
    }


    // v1alpha1_eviction_status->observed_generation
    if(v1alpha1_eviction_status->observed_generation) {
    if(cJSON_AddNumberToObject(item, "observedGeneration", *v1alpha1_eviction_status->observed_generation) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1alpha1_eviction_status->requesters
    if(v1alpha1_eviction_status->requesters) {
    cJSON *requesters = cJSON_AddArrayToObject(item, "requesters");
    if(requesters == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *requestersListEntry;
    if (v1alpha1_eviction_status->requesters) {
    list_ForEach(requestersListEntry, v1alpha1_eviction_status->requesters) {
    cJSON *itemLocal = v1alpha1_requester_convertToJSON(requestersListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(requesters, itemLocal);
    }
    }
    }


    // v1alpha1_eviction_status->responders
    if(v1alpha1_eviction_status->responders) {
    cJSON *responders = cJSON_AddArrayToObject(item, "responders");
    if(responders == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *respondersListEntry;
    if (v1alpha1_eviction_status->responders) {
    list_ForEach(respondersListEntry, v1alpha1_eviction_status->responders) {
    cJSON *itemLocal = v1alpha1_responder_status_convertToJSON(respondersListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(responders, itemLocal);
    }
    }
    }


    // v1alpha1_eviction_status->target_responders
    if(v1alpha1_eviction_status->target_responders) {
    cJSON *target_responders = cJSON_AddArrayToObject(item, "targetResponders");
    if(target_responders == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *target_respondersListEntry;
    if (v1alpha1_eviction_status->target_responders) {
    list_ForEach(target_respondersListEntry, v1alpha1_eviction_status->target_responders) {
    cJSON *itemLocal = v1alpha1_target_responder_convertToJSON(target_respondersListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(target_responders, itemLocal);
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

v1alpha1_eviction_status_t *v1alpha1_eviction_status_parseFromJSON(cJSON *v1alpha1_eviction_statusJSON){

    v1alpha1_eviction_status_t *v1alpha1_eviction_status_local_var = NULL;

    // define the local list for v1alpha1_eviction_status->conditions
    list_t *conditionsList = NULL;

    // define the local variable for v1alpha1_eviction_status->observed_generation
    long *observed_generation_local_var = NULL;

    // define the local list for v1alpha1_eviction_status->requesters
    list_t *requestersList = NULL;

    // define the local list for v1alpha1_eviction_status->responders
    list_t *respondersList = NULL;

    // define the local list for v1alpha1_eviction_status->target_responders
    list_t *target_respondersList = NULL;

    // v1alpha1_eviction_status->conditions
    cJSON *conditions = cJSON_GetObjectItemCaseSensitive(v1alpha1_eviction_statusJSON, "conditions");
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

    // v1alpha1_eviction_status->observed_generation
    cJSON *observed_generation = cJSON_GetObjectItemCaseSensitive(v1alpha1_eviction_statusJSON, "observedGeneration");
    if (cJSON_IsNull(observed_generation)) {
        observed_generation = NULL;
    }
    if (observed_generation) { 
    if(!cJSON_IsNumber(observed_generation))
    {
    goto end; //Numeric
    }
    observed_generation_local_var = malloc(sizeof(long));
    if(!observed_generation_local_var)
    {
        goto end;
    }
    *observed_generation_local_var = observed_generation->valuedouble;
    }

    // v1alpha1_eviction_status->requesters
    cJSON *requesters = cJSON_GetObjectItemCaseSensitive(v1alpha1_eviction_statusJSON, "requesters");
    if (cJSON_IsNull(requesters)) {
        requesters = NULL;
    }
    if (requesters) { 
    cJSON *requesters_local_nonprimitive = NULL;
    if(!cJSON_IsArray(requesters)){
        goto end; //nonprimitive container
    }

    requestersList = list_createList();

    cJSON_ArrayForEach(requesters_local_nonprimitive,requesters )
    {
        if(!cJSON_IsObject(requesters_local_nonprimitive)){
            goto end;
        }
        v1alpha1_requester_t *requestersItem = v1alpha1_requester_parseFromJSON(requesters_local_nonprimitive);

        list_addElement(requestersList, requestersItem);
    }
    }

    // v1alpha1_eviction_status->responders
    cJSON *responders = cJSON_GetObjectItemCaseSensitive(v1alpha1_eviction_statusJSON, "responders");
    if (cJSON_IsNull(responders)) {
        responders = NULL;
    }
    if (responders) { 
    cJSON *responders_local_nonprimitive = NULL;
    if(!cJSON_IsArray(responders)){
        goto end; //nonprimitive container
    }

    respondersList = list_createList();

    cJSON_ArrayForEach(responders_local_nonprimitive,responders )
    {
        if(!cJSON_IsObject(responders_local_nonprimitive)){
            goto end;
        }
        v1alpha1_responder_status_t *respondersItem = v1alpha1_responder_status_parseFromJSON(responders_local_nonprimitive);

        list_addElement(respondersList, respondersItem);
    }
    }

    // v1alpha1_eviction_status->target_responders
    cJSON *target_responders = cJSON_GetObjectItemCaseSensitive(v1alpha1_eviction_statusJSON, "targetResponders");
    if (cJSON_IsNull(target_responders)) {
        target_responders = NULL;
    }
    if (target_responders) { 
    cJSON *target_responders_local_nonprimitive = NULL;
    if(!cJSON_IsArray(target_responders)){
        goto end; //nonprimitive container
    }

    target_respondersList = list_createList();

    cJSON_ArrayForEach(target_responders_local_nonprimitive,target_responders )
    {
        if(!cJSON_IsObject(target_responders_local_nonprimitive)){
            goto end;
        }
        v1alpha1_target_responder_t *target_respondersItem = v1alpha1_target_responder_parseFromJSON(target_responders_local_nonprimitive);

        list_addElement(target_respondersList, target_respondersItem);
    }
    }



    v1alpha1_eviction_status_local_var = v1alpha1_eviction_status_create_internal (
        conditions ? conditionsList : NULL,
        observed_generation_local_var,
        requesters ? requestersList : NULL,
        responders ? respondersList : NULL,
        target_responders ? target_respondersList : NULL
        );

    if (!v1alpha1_eviction_status_local_var) {
        goto end;
    }

    return v1alpha1_eviction_status_local_var;
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
    if (observed_generation_local_var) {
        free(observed_generation_local_var);
        observed_generation_local_var = NULL;
    }
    if (requestersList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, requestersList) {
            v1alpha1_requester_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(requestersList);
        requestersList = NULL;
    }
    if (respondersList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, respondersList) {
            v1alpha1_responder_status_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(respondersList);
        respondersList = NULL;
    }
    if (target_respondersList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, target_respondersList) {
            v1alpha1_target_responder_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(target_respondersList);
        target_respondersList = NULL;
    }
    return NULL;

}
