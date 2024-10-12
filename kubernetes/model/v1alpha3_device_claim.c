#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha3_device_claim.h"



v1alpha3_device_claim_t *v1alpha3_device_claim_create(
    list_t *config,
    list_t *constraints,
    list_t *requests
    ) {
    v1alpha3_device_claim_t *v1alpha3_device_claim_local_var = malloc(sizeof(v1alpha3_device_claim_t));
    if (!v1alpha3_device_claim_local_var) {
        return NULL;
    }
    v1alpha3_device_claim_local_var->config = config;
    v1alpha3_device_claim_local_var->constraints = constraints;
    v1alpha3_device_claim_local_var->requests = requests;

    return v1alpha3_device_claim_local_var;
}


void v1alpha3_device_claim_free(v1alpha3_device_claim_t *v1alpha3_device_claim) {
    if(NULL == v1alpha3_device_claim){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha3_device_claim->config) {
        list_ForEach(listEntry, v1alpha3_device_claim->config) {
            v1alpha3_device_claim_configuration_free(listEntry->data);
        }
        list_freeList(v1alpha3_device_claim->config);
        v1alpha3_device_claim->config = NULL;
    }
    if (v1alpha3_device_claim->constraints) {
        list_ForEach(listEntry, v1alpha3_device_claim->constraints) {
            v1alpha3_device_constraint_free(listEntry->data);
        }
        list_freeList(v1alpha3_device_claim->constraints);
        v1alpha3_device_claim->constraints = NULL;
    }
    if (v1alpha3_device_claim->requests) {
        list_ForEach(listEntry, v1alpha3_device_claim->requests) {
            v1alpha3_device_request_free(listEntry->data);
        }
        list_freeList(v1alpha3_device_claim->requests);
        v1alpha3_device_claim->requests = NULL;
    }
    free(v1alpha3_device_claim);
}

cJSON *v1alpha3_device_claim_convertToJSON(v1alpha3_device_claim_t *v1alpha3_device_claim) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha3_device_claim->config
    if(v1alpha3_device_claim->config) {
    cJSON *config = cJSON_AddArrayToObject(item, "config");
    if(config == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *configListEntry;
    if (v1alpha3_device_claim->config) {
    list_ForEach(configListEntry, v1alpha3_device_claim->config) {
    cJSON *itemLocal = v1alpha3_device_claim_configuration_convertToJSON(configListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(config, itemLocal);
    }
    }
    }


    // v1alpha3_device_claim->constraints
    if(v1alpha3_device_claim->constraints) {
    cJSON *constraints = cJSON_AddArrayToObject(item, "constraints");
    if(constraints == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *constraintsListEntry;
    if (v1alpha3_device_claim->constraints) {
    list_ForEach(constraintsListEntry, v1alpha3_device_claim->constraints) {
    cJSON *itemLocal = v1alpha3_device_constraint_convertToJSON(constraintsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(constraints, itemLocal);
    }
    }
    }


    // v1alpha3_device_claim->requests
    if(v1alpha3_device_claim->requests) {
    cJSON *requests = cJSON_AddArrayToObject(item, "requests");
    if(requests == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *requestsListEntry;
    if (v1alpha3_device_claim->requests) {
    list_ForEach(requestsListEntry, v1alpha3_device_claim->requests) {
    cJSON *itemLocal = v1alpha3_device_request_convertToJSON(requestsListEntry->data);
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

v1alpha3_device_claim_t *v1alpha3_device_claim_parseFromJSON(cJSON *v1alpha3_device_claimJSON){

    v1alpha3_device_claim_t *v1alpha3_device_claim_local_var = NULL;

    // define the local list for v1alpha3_device_claim->config
    list_t *configList = NULL;

    // define the local list for v1alpha3_device_claim->constraints
    list_t *constraintsList = NULL;

    // define the local list for v1alpha3_device_claim->requests
    list_t *requestsList = NULL;

    // v1alpha3_device_claim->config
    cJSON *config = cJSON_GetObjectItemCaseSensitive(v1alpha3_device_claimJSON, "config");
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
        v1alpha3_device_claim_configuration_t *configItem = v1alpha3_device_claim_configuration_parseFromJSON(config_local_nonprimitive);

        list_addElement(configList, configItem);
    }
    }

    // v1alpha3_device_claim->constraints
    cJSON *constraints = cJSON_GetObjectItemCaseSensitive(v1alpha3_device_claimJSON, "constraints");
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
        v1alpha3_device_constraint_t *constraintsItem = v1alpha3_device_constraint_parseFromJSON(constraints_local_nonprimitive);

        list_addElement(constraintsList, constraintsItem);
    }
    }

    // v1alpha3_device_claim->requests
    cJSON *requests = cJSON_GetObjectItemCaseSensitive(v1alpha3_device_claimJSON, "requests");
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
        v1alpha3_device_request_t *requestsItem = v1alpha3_device_request_parseFromJSON(requests_local_nonprimitive);

        list_addElement(requestsList, requestsItem);
    }
    }


    v1alpha3_device_claim_local_var = v1alpha3_device_claim_create (
        config ? configList : NULL,
        constraints ? constraintsList : NULL,
        requests ? requestsList : NULL
        );

    return v1alpha3_device_claim_local_var;
end:
    if (configList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, configList) {
            v1alpha3_device_claim_configuration_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(configList);
        configList = NULL;
    }
    if (constraintsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, constraintsList) {
            v1alpha3_device_constraint_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(constraintsList);
        constraintsList = NULL;
    }
    if (requestsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, requestsList) {
            v1alpha3_device_request_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(requestsList);
        requestsList = NULL;
    }
    return NULL;

}
