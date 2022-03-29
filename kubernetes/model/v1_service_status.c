#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_service_status.h"



v1_service_status_t *v1_service_status_create(
    list_t *conditions,
    v1_load_balancer_status_t *load_balancer
    ) {
    v1_service_status_t *v1_service_status_local_var = malloc(sizeof(v1_service_status_t));
    if (!v1_service_status_local_var) {
        return NULL;
    }
    v1_service_status_local_var->conditions = conditions;
    v1_service_status_local_var->load_balancer = load_balancer;

    return v1_service_status_local_var;
}


void v1_service_status_free(v1_service_status_t *v1_service_status) {
    if(NULL == v1_service_status){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_service_status->conditions) {
        list_ForEach(listEntry, v1_service_status->conditions) {
            v1_condition_free(listEntry->data);
        }
        list_freeList(v1_service_status->conditions);
        v1_service_status->conditions = NULL;
    }
    if (v1_service_status->load_balancer) {
        v1_load_balancer_status_free(v1_service_status->load_balancer);
        v1_service_status->load_balancer = NULL;
    }
    free(v1_service_status);
}

cJSON *v1_service_status_convertToJSON(v1_service_status_t *v1_service_status) {
    cJSON *item = cJSON_CreateObject();

    // v1_service_status->conditions
    if(v1_service_status->conditions) { 
    cJSON *conditions = cJSON_AddArrayToObject(item, "conditions");
    if(conditions == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *conditionsListEntry;
    if (v1_service_status->conditions) {
    list_ForEach(conditionsListEntry, v1_service_status->conditions) {
    cJSON *itemLocal = v1_condition_convertToJSON(conditionsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(conditions, itemLocal);
    }
    }
     } 


    // v1_service_status->load_balancer
    if(v1_service_status->load_balancer) { 
    cJSON *load_balancer_local_JSON = v1_load_balancer_status_convertToJSON(v1_service_status->load_balancer);
    if(load_balancer_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "loadBalancer", load_balancer_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_service_status_t *v1_service_status_parseFromJSON(cJSON *v1_service_statusJSON){

    v1_service_status_t *v1_service_status_local_var = NULL;

    // define the local list for v1_service_status->conditions
    list_t *conditionsList = NULL;

    // define the local variable for v1_service_status->load_balancer
    v1_load_balancer_status_t *load_balancer_local_nonprim = NULL;

    // v1_service_status->conditions
    cJSON *conditions = cJSON_GetObjectItemCaseSensitive(v1_service_statusJSON, "conditions");
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

    // v1_service_status->load_balancer
    cJSON *load_balancer = cJSON_GetObjectItemCaseSensitive(v1_service_statusJSON, "loadBalancer");
    if (load_balancer) { 
    load_balancer_local_nonprim = v1_load_balancer_status_parseFromJSON(load_balancer); //nonprimitive
    }


    v1_service_status_local_var = v1_service_status_create (
        conditions ? conditionsList : NULL,
        load_balancer ? load_balancer_local_nonprim : NULL
        );

    return v1_service_status_local_var;
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
    if (load_balancer_local_nonprim) {
        v1_load_balancer_status_free(load_balancer_local_nonprim);
        load_balancer_local_nonprim = NULL;
    }
    return NULL;

}
