#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha1_service_cidr_status.h"



v1alpha1_service_cidr_status_t *v1alpha1_service_cidr_status_create(
    list_t *conditions
    ) {
    v1alpha1_service_cidr_status_t *v1alpha1_service_cidr_status_local_var = malloc(sizeof(v1alpha1_service_cidr_status_t));
    if (!v1alpha1_service_cidr_status_local_var) {
        return NULL;
    }
    v1alpha1_service_cidr_status_local_var->conditions = conditions;

    return v1alpha1_service_cidr_status_local_var;
}


void v1alpha1_service_cidr_status_free(v1alpha1_service_cidr_status_t *v1alpha1_service_cidr_status) {
    if(NULL == v1alpha1_service_cidr_status){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha1_service_cidr_status->conditions) {
        list_ForEach(listEntry, v1alpha1_service_cidr_status->conditions) {
            v1_condition_free(listEntry->data);
        }
        list_freeList(v1alpha1_service_cidr_status->conditions);
        v1alpha1_service_cidr_status->conditions = NULL;
    }
    free(v1alpha1_service_cidr_status);
}

cJSON *v1alpha1_service_cidr_status_convertToJSON(v1alpha1_service_cidr_status_t *v1alpha1_service_cidr_status) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha1_service_cidr_status->conditions
    if(v1alpha1_service_cidr_status->conditions) {
    cJSON *conditions = cJSON_AddArrayToObject(item, "conditions");
    if(conditions == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *conditionsListEntry;
    if (v1alpha1_service_cidr_status->conditions) {
    list_ForEach(conditionsListEntry, v1alpha1_service_cidr_status->conditions) {
    cJSON *itemLocal = v1_condition_convertToJSON(conditionsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(conditions, itemLocal);
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

v1alpha1_service_cidr_status_t *v1alpha1_service_cidr_status_parseFromJSON(cJSON *v1alpha1_service_cidr_statusJSON){

    v1alpha1_service_cidr_status_t *v1alpha1_service_cidr_status_local_var = NULL;

    // define the local list for v1alpha1_service_cidr_status->conditions
    list_t *conditionsList = NULL;

    // v1alpha1_service_cidr_status->conditions
    cJSON *conditions = cJSON_GetObjectItemCaseSensitive(v1alpha1_service_cidr_statusJSON, "conditions");
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


    v1alpha1_service_cidr_status_local_var = v1alpha1_service_cidr_status_create (
        conditions ? conditionsList : NULL
        );

    return v1alpha1_service_cidr_status_local_var;
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
