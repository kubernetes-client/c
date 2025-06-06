#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta2_device_claim.h"



static v1beta2_device_claim_t *v1beta2_device_claim_create_internal(
    list_t *config,
    list_t *constraints,
    list_t *requests
    ) {
    v1beta2_device_claim_t *v1beta2_device_claim_local_var = malloc(sizeof(v1beta2_device_claim_t));
    if (!v1beta2_device_claim_local_var) {
        return NULL;
    }
    v1beta2_device_claim_local_var->config = config;
    v1beta2_device_claim_local_var->constraints = constraints;
    v1beta2_device_claim_local_var->requests = requests;

    v1beta2_device_claim_local_var->_library_owned = 1;
    return v1beta2_device_claim_local_var;
}

__attribute__((deprecated)) v1beta2_device_claim_t *v1beta2_device_claim_create(
    list_t *config,
    list_t *constraints,
    list_t *requests
    ) {
    return v1beta2_device_claim_create_internal (
        config,
        constraints,
        requests
        );
}

void v1beta2_device_claim_free(v1beta2_device_claim_t *v1beta2_device_claim) {
    if(NULL == v1beta2_device_claim){
        return ;
    }
    if(v1beta2_device_claim->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1beta2_device_claim_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta2_device_claim->config) {
        list_ForEach(listEntry, v1beta2_device_claim->config) {
            v1beta2_device_claim_configuration_free(listEntry->data);
        }
        list_freeList(v1beta2_device_claim->config);
        v1beta2_device_claim->config = NULL;
    }
    if (v1beta2_device_claim->constraints) {
        list_ForEach(listEntry, v1beta2_device_claim->constraints) {
            v1beta2_device_constraint_free(listEntry->data);
        }
        list_freeList(v1beta2_device_claim->constraints);
        v1beta2_device_claim->constraints = NULL;
    }
    if (v1beta2_device_claim->requests) {
        list_ForEach(listEntry, v1beta2_device_claim->requests) {
            v1beta2_device_request_free(listEntry->data);
        }
        list_freeList(v1beta2_device_claim->requests);
        v1beta2_device_claim->requests = NULL;
    }
    free(v1beta2_device_claim);
}

cJSON *v1beta2_device_claim_convertToJSON(v1beta2_device_claim_t *v1beta2_device_claim) {
    cJSON *item = cJSON_CreateObject();

    // v1beta2_device_claim->config
    if(v1beta2_device_claim->config) {
    cJSON *config = cJSON_AddArrayToObject(item, "config");
    if(config == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *configListEntry;
    if (v1beta2_device_claim->config) {
    list_ForEach(configListEntry, v1beta2_device_claim->config) {
    cJSON *itemLocal = v1beta2_device_claim_configuration_convertToJSON(configListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(config, itemLocal);
    }
    }
    }


    // v1beta2_device_claim->constraints
    if(v1beta2_device_claim->constraints) {
    cJSON *constraints = cJSON_AddArrayToObject(item, "constraints");
    if(constraints == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *constraintsListEntry;
    if (v1beta2_device_claim->constraints) {
    list_ForEach(constraintsListEntry, v1beta2_device_claim->constraints) {
    cJSON *itemLocal = v1beta2_device_constraint_convertToJSON(constraintsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(constraints, itemLocal);
    }
    }
    }


    // v1beta2_device_claim->requests
    if(v1beta2_device_claim->requests) {
    cJSON *requests = cJSON_AddArrayToObject(item, "requests");
    if(requests == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *requestsListEntry;
    if (v1beta2_device_claim->requests) {
    list_ForEach(requestsListEntry, v1beta2_device_claim->requests) {
    cJSON *itemLocal = v1beta2_device_request_convertToJSON(requestsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(requests, itemLocal);
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

v1beta2_device_claim_t *v1beta2_device_claim_parseFromJSON(cJSON *v1beta2_device_claimJSON){

    v1beta2_device_claim_t *v1beta2_device_claim_local_var = NULL;

    // define the local list for v1beta2_device_claim->config
    list_t *configList = NULL;

    // define the local list for v1beta2_device_claim->constraints
    list_t *constraintsList = NULL;

    // define the local list for v1beta2_device_claim->requests
    list_t *requestsList = NULL;

    // v1beta2_device_claim->config
    cJSON *config = cJSON_GetObjectItemCaseSensitive(v1beta2_device_claimJSON, "config");
    if (cJSON_IsNull(config)) {
        config = NULL;
    }
    if (config) { 
    cJSON *config_local_nonprimitive = NULL;
    if(!cJSON_IsArray(config)){
        goto end; //nonprimitive container
    }

    configList = list_createList();

    cJSON_ArrayForEach(config_local_nonprimitive,config )
    {
        if(!cJSON_IsObject(config_local_nonprimitive)){
            goto end;
        }
        v1beta2_device_claim_configuration_t *configItem = v1beta2_device_claim_configuration_parseFromJSON(config_local_nonprimitive);

        list_addElement(configList, configItem);
    }
    }

    // v1beta2_device_claim->constraints
    cJSON *constraints = cJSON_GetObjectItemCaseSensitive(v1beta2_device_claimJSON, "constraints");
    if (cJSON_IsNull(constraints)) {
        constraints = NULL;
    }
    if (constraints) { 
    cJSON *constraints_local_nonprimitive = NULL;
    if(!cJSON_IsArray(constraints)){
        goto end; //nonprimitive container
    }

    constraintsList = list_createList();

    cJSON_ArrayForEach(constraints_local_nonprimitive,constraints )
    {
        if(!cJSON_IsObject(constraints_local_nonprimitive)){
            goto end;
        }
        v1beta2_device_constraint_t *constraintsItem = v1beta2_device_constraint_parseFromJSON(constraints_local_nonprimitive);

        list_addElement(constraintsList, constraintsItem);
    }
    }

    // v1beta2_device_claim->requests
    cJSON *requests = cJSON_GetObjectItemCaseSensitive(v1beta2_device_claimJSON, "requests");
    if (cJSON_IsNull(requests)) {
        requests = NULL;
    }
    if (requests) { 
    cJSON *requests_local_nonprimitive = NULL;
    if(!cJSON_IsArray(requests)){
        goto end; //nonprimitive container
    }

    requestsList = list_createList();

    cJSON_ArrayForEach(requests_local_nonprimitive,requests )
    {
        if(!cJSON_IsObject(requests_local_nonprimitive)){
            goto end;
        }
        v1beta2_device_request_t *requestsItem = v1beta2_device_request_parseFromJSON(requests_local_nonprimitive);

        list_addElement(requestsList, requestsItem);
    }
    }


    v1beta2_device_claim_local_var = v1beta2_device_claim_create_internal (
        config ? configList : NULL,
        constraints ? constraintsList : NULL,
        requests ? requestsList : NULL
        );

    return v1beta2_device_claim_local_var;
end:
    if (configList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, configList) {
            v1beta2_device_claim_configuration_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(configList);
        configList = NULL;
    }
    if (constraintsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, constraintsList) {
            v1beta2_device_constraint_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(constraintsList);
        constraintsList = NULL;
    }
    if (requestsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, requestsList) {
            v1beta2_device_request_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(requestsList);
        requestsList = NULL;
    }
    return NULL;

}
