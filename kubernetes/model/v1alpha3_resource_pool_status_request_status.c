#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha3_resource_pool_status_request_status.h"



static v1alpha3_resource_pool_status_request_status_t *v1alpha3_resource_pool_status_request_status_create_internal(
    list_t *conditions,
    int *pool_count,
    list_t *pools
    ) {
    v1alpha3_resource_pool_status_request_status_t *v1alpha3_resource_pool_status_request_status_local_var = malloc(sizeof(v1alpha3_resource_pool_status_request_status_t));
    if (!v1alpha3_resource_pool_status_request_status_local_var) {
        return NULL;
    }
    memset(v1alpha3_resource_pool_status_request_status_local_var, 0, sizeof(v1alpha3_resource_pool_status_request_status_t));
    v1alpha3_resource_pool_status_request_status_local_var->_library_owned = 1;
    v1alpha3_resource_pool_status_request_status_local_var->conditions = conditions;
    v1alpha3_resource_pool_status_request_status_local_var->pool_count = pool_count;
    v1alpha3_resource_pool_status_request_status_local_var->pools = pools;
    return v1alpha3_resource_pool_status_request_status_local_var;
}

__attribute__((deprecated)) v1alpha3_resource_pool_status_request_status_t *v1alpha3_resource_pool_status_request_status_create(
    list_t *conditions,
    int *pool_count,
    list_t *pools
    ) {
    int *pool_count_copy = NULL;
    if (pool_count) {
        pool_count_copy = malloc(sizeof(int));
        if (pool_count_copy) *pool_count_copy = *pool_count;
    }
    v1alpha3_resource_pool_status_request_status_t *result = v1alpha3_resource_pool_status_request_status_create_internal (
        conditions,
        pool_count_copy,
        pools
        );
    if (!result) {
        free(pool_count_copy);
    }
    return result;
}

void v1alpha3_resource_pool_status_request_status_free(v1alpha3_resource_pool_status_request_status_t *v1alpha3_resource_pool_status_request_status) {
    if(NULL == v1alpha3_resource_pool_status_request_status){
        return ;
    }
    if(v1alpha3_resource_pool_status_request_status->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1alpha3_resource_pool_status_request_status_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha3_resource_pool_status_request_status->conditions) {
        list_ForEach(listEntry, v1alpha3_resource_pool_status_request_status->conditions) {
            v1_condition_free(listEntry->data);
        }
        list_freeList(v1alpha3_resource_pool_status_request_status->conditions);
        v1alpha3_resource_pool_status_request_status->conditions = NULL;
    }
    if (v1alpha3_resource_pool_status_request_status->pool_count) {
        free(v1alpha3_resource_pool_status_request_status->pool_count);
        v1alpha3_resource_pool_status_request_status->pool_count = NULL;
    }
    if (v1alpha3_resource_pool_status_request_status->pools) {
        list_ForEach(listEntry, v1alpha3_resource_pool_status_request_status->pools) {
            v1alpha3_pool_status_free(listEntry->data);
        }
        list_freeList(v1alpha3_resource_pool_status_request_status->pools);
        v1alpha3_resource_pool_status_request_status->pools = NULL;
    }
    free(v1alpha3_resource_pool_status_request_status);
}

cJSON *v1alpha3_resource_pool_status_request_status_convertToJSON(v1alpha3_resource_pool_status_request_status_t *v1alpha3_resource_pool_status_request_status) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha3_resource_pool_status_request_status->conditions
    if(v1alpha3_resource_pool_status_request_status->conditions) {
    cJSON *conditions = cJSON_AddArrayToObject(item, "conditions");
    if(conditions == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *conditionsListEntry;
    if (v1alpha3_resource_pool_status_request_status->conditions) {
    list_ForEach(conditionsListEntry, v1alpha3_resource_pool_status_request_status->conditions) {
    cJSON *itemLocal = v1_condition_convertToJSON(conditionsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(conditions, itemLocal);
    }
    }
    }


    // v1alpha3_resource_pool_status_request_status->pool_count
    if (!v1alpha3_resource_pool_status_request_status->pool_count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "poolCount", *v1alpha3_resource_pool_status_request_status->pool_count) == NULL) {
    goto fail; //Numeric
    }


    // v1alpha3_resource_pool_status_request_status->pools
    if(v1alpha3_resource_pool_status_request_status->pools) {
    cJSON *pools = cJSON_AddArrayToObject(item, "pools");
    if(pools == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *poolsListEntry;
    if (v1alpha3_resource_pool_status_request_status->pools) {
    list_ForEach(poolsListEntry, v1alpha3_resource_pool_status_request_status->pools) {
    cJSON *itemLocal = v1alpha3_pool_status_convertToJSON(poolsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(pools, itemLocal);
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

v1alpha3_resource_pool_status_request_status_t *v1alpha3_resource_pool_status_request_status_parseFromJSON(cJSON *v1alpha3_resource_pool_status_request_statusJSON){

    v1alpha3_resource_pool_status_request_status_t *v1alpha3_resource_pool_status_request_status_local_var = NULL;

    // define the local list for v1alpha3_resource_pool_status_request_status->conditions
    list_t *conditionsList = NULL;

    // define the local variable for v1alpha3_resource_pool_status_request_status->pool_count
    int *pool_count_local_var = NULL;

    // define the local list for v1alpha3_resource_pool_status_request_status->pools
    list_t *poolsList = NULL;

    // v1alpha3_resource_pool_status_request_status->conditions
    cJSON *conditions = cJSON_GetObjectItemCaseSensitive(v1alpha3_resource_pool_status_request_statusJSON, "conditions");
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

    // v1alpha3_resource_pool_status_request_status->pool_count
    cJSON *pool_count = cJSON_GetObjectItemCaseSensitive(v1alpha3_resource_pool_status_request_statusJSON, "poolCount");
    if (cJSON_IsNull(pool_count)) {
        pool_count = NULL;
    }
    if (!pool_count) {
        goto end;
    }

    
    if(!cJSON_IsNumber(pool_count))
    {
    goto end; //Numeric
    }
    pool_count_local_var = malloc(sizeof(int));
    if(!pool_count_local_var)
    {
        goto end;
    }
    *pool_count_local_var = pool_count->valuedouble;

    // v1alpha3_resource_pool_status_request_status->pools
    cJSON *pools = cJSON_GetObjectItemCaseSensitive(v1alpha3_resource_pool_status_request_statusJSON, "pools");
    if (cJSON_IsNull(pools)) {
        pools = NULL;
    }
    if (pools) { 
    cJSON *pools_local_nonprimitive = NULL;
    if(!cJSON_IsArray(pools)){
        goto end; //nonprimitive container
    }

    poolsList = list_createList();

    cJSON_ArrayForEach(pools_local_nonprimitive,pools )
    {
        if(!cJSON_IsObject(pools_local_nonprimitive)){
            goto end;
        }
        v1alpha3_pool_status_t *poolsItem = v1alpha3_pool_status_parseFromJSON(pools_local_nonprimitive);

        list_addElement(poolsList, poolsItem);
    }
    }



    v1alpha3_resource_pool_status_request_status_local_var = v1alpha3_resource_pool_status_request_status_create_internal (
        conditions ? conditionsList : NULL,
        pool_count_local_var,
        pools ? poolsList : NULL
        );

    if (!v1alpha3_resource_pool_status_request_status_local_var) {
        goto end;
    }

    return v1alpha3_resource_pool_status_request_status_local_var;
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
    if (pool_count_local_var) {
        free(pool_count_local_var);
        pool_count_local_var = NULL;
    }
    if (poolsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, poolsList) {
            v1alpha3_pool_status_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(poolsList);
        poolsList = NULL;
    }
    return NULL;

}
