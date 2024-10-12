#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha3_device_allocation_result.h"



v1alpha3_device_allocation_result_t *v1alpha3_device_allocation_result_create(
    list_t *config,
    list_t *results
    ) {
    v1alpha3_device_allocation_result_t *v1alpha3_device_allocation_result_local_var = malloc(sizeof(v1alpha3_device_allocation_result_t));
    if (!v1alpha3_device_allocation_result_local_var) {
        return NULL;
    }
    v1alpha3_device_allocation_result_local_var->config = config;
    v1alpha3_device_allocation_result_local_var->results = results;

    return v1alpha3_device_allocation_result_local_var;
}


void v1alpha3_device_allocation_result_free(v1alpha3_device_allocation_result_t *v1alpha3_device_allocation_result) {
    if(NULL == v1alpha3_device_allocation_result){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha3_device_allocation_result->config) {
        list_ForEach(listEntry, v1alpha3_device_allocation_result->config) {
            v1alpha3_device_allocation_configuration_free(listEntry->data);
        }
        list_freeList(v1alpha3_device_allocation_result->config);
        v1alpha3_device_allocation_result->config = NULL;
    }
    if (v1alpha3_device_allocation_result->results) {
        list_ForEach(listEntry, v1alpha3_device_allocation_result->results) {
            v1alpha3_device_request_allocation_result_free(listEntry->data);
        }
        list_freeList(v1alpha3_device_allocation_result->results);
        v1alpha3_device_allocation_result->results = NULL;
    }
    free(v1alpha3_device_allocation_result);
}

cJSON *v1alpha3_device_allocation_result_convertToJSON(v1alpha3_device_allocation_result_t *v1alpha3_device_allocation_result) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha3_device_allocation_result->config
    if(v1alpha3_device_allocation_result->config) {
    cJSON *config = cJSON_AddArrayToObject(item, "config");
    if(config == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *configListEntry;
    if (v1alpha3_device_allocation_result->config) {
    list_ForEach(configListEntry, v1alpha3_device_allocation_result->config) {
    cJSON *itemLocal = v1alpha3_device_allocation_configuration_convertToJSON(configListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(config, itemLocal);
    }
    }
    }


    // v1alpha3_device_allocation_result->results
    if(v1alpha3_device_allocation_result->results) {
    cJSON *results = cJSON_AddArrayToObject(item, "results");
    if(results == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *resultsListEntry;
    if (v1alpha3_device_allocation_result->results) {
    list_ForEach(resultsListEntry, v1alpha3_device_allocation_result->results) {
    cJSON *itemLocal = v1alpha3_device_request_allocation_result_convertToJSON(resultsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(results, itemLocal);
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

v1alpha3_device_allocation_result_t *v1alpha3_device_allocation_result_parseFromJSON(cJSON *v1alpha3_device_allocation_resultJSON){

    v1alpha3_device_allocation_result_t *v1alpha3_device_allocation_result_local_var = NULL;

    // define the local list for v1alpha3_device_allocation_result->config
    list_t *configList = NULL;

    // define the local list for v1alpha3_device_allocation_result->results
    list_t *resultsList = NULL;

    // v1alpha3_device_allocation_result->config
    cJSON *config = cJSON_GetObjectItemCaseSensitive(v1alpha3_device_allocation_resultJSON, "config");
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
        v1alpha3_device_allocation_configuration_t *configItem = v1alpha3_device_allocation_configuration_parseFromJSON(config_local_nonprimitive);

        list_addElement(configList, configItem);
    }
    }

    // v1alpha3_device_allocation_result->results
    cJSON *results = cJSON_GetObjectItemCaseSensitive(v1alpha3_device_allocation_resultJSON, "results");
    if (results) { 
    cJSON *results_local_nonprimitive = NULL;
    if(!cJSON_IsArray(results)){
        goto end; //nonprimitive container
    }

    resultsList = list_createList();

    cJSON_ArrayForEach(results_local_nonprimitive,results )
    {
        if(!cJSON_IsObject(results_local_nonprimitive)){
            goto end;
        }
        v1alpha3_device_request_allocation_result_t *resultsItem = v1alpha3_device_request_allocation_result_parseFromJSON(results_local_nonprimitive);

        list_addElement(resultsList, resultsItem);
    }
    }


    v1alpha3_device_allocation_result_local_var = v1alpha3_device_allocation_result_create (
        config ? configList : NULL,
        results ? resultsList : NULL
        );

    return v1alpha3_device_allocation_result_local_var;
end:
    if (configList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, configList) {
            v1alpha3_device_allocation_configuration_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(configList);
        configList = NULL;
    }
    if (resultsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, resultsList) {
            v1alpha3_device_request_allocation_result_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(resultsList);
        resultsList = NULL;
    }
    return NULL;

}
