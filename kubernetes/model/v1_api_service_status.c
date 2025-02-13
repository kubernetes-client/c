#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_api_service_status.h"



static v1_api_service_status_t *v1_api_service_status_create_internal(
    list_t *conditions
    ) {
    v1_api_service_status_t *v1_api_service_status_local_var = malloc(sizeof(v1_api_service_status_t));
    if (!v1_api_service_status_local_var) {
        return NULL;
    }
    v1_api_service_status_local_var->conditions = conditions;

    v1_api_service_status_local_var->_library_owned = 1;
    return v1_api_service_status_local_var;
}

__attribute__((deprecated)) v1_api_service_status_t *v1_api_service_status_create(
    list_t *conditions
    ) {
    return v1_api_service_status_create_internal (
        conditions
        );
}

void v1_api_service_status_free(v1_api_service_status_t *v1_api_service_status) {
    if(NULL == v1_api_service_status){
        return ;
    }
    if(v1_api_service_status->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_api_service_status_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_api_service_status->conditions) {
        list_ForEach(listEntry, v1_api_service_status->conditions) {
            v1_api_service_condition_free(listEntry->data);
        }
        list_freeList(v1_api_service_status->conditions);
        v1_api_service_status->conditions = NULL;
    }
    free(v1_api_service_status);
}

cJSON *v1_api_service_status_convertToJSON(v1_api_service_status_t *v1_api_service_status) {
    cJSON *item = cJSON_CreateObject();

    // v1_api_service_status->conditions
    if(v1_api_service_status->conditions) {
    cJSON *conditions = cJSON_AddArrayToObject(item, "conditions");
    if(conditions == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *conditionsListEntry;
    if (v1_api_service_status->conditions) {
    list_ForEach(conditionsListEntry, v1_api_service_status->conditions) {
    cJSON *itemLocal = v1_api_service_condition_convertToJSON(conditionsListEntry->data);
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

v1_api_service_status_t *v1_api_service_status_parseFromJSON(cJSON *v1_api_service_statusJSON){

    v1_api_service_status_t *v1_api_service_status_local_var = NULL;

    // define the local list for v1_api_service_status->conditions
    list_t *conditionsList = NULL;

    // v1_api_service_status->conditions
    cJSON *conditions = cJSON_GetObjectItemCaseSensitive(v1_api_service_statusJSON, "conditions");
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
        v1_api_service_condition_t *conditionsItem = v1_api_service_condition_parseFromJSON(conditions_local_nonprimitive);

        list_addElement(conditionsList, conditionsItem);
    }
    }


    v1_api_service_status_local_var = v1_api_service_status_create_internal (
        conditions ? conditionsList : NULL
        );

    return v1_api_service_status_local_var;
end:
    if (conditionsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, conditionsList) {
            v1_api_service_condition_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(conditionsList);
        conditionsList = NULL;
    }
    return NULL;

}
