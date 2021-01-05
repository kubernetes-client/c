#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_api_service_status.h"



v1beta1_api_service_status_t *v1beta1_api_service_status_create(
    list_t *conditions
    ) {
    v1beta1_api_service_status_t *v1beta1_api_service_status_local_var = malloc(sizeof(v1beta1_api_service_status_t));
    if (!v1beta1_api_service_status_local_var) {
        return NULL;
    }
    v1beta1_api_service_status_local_var->conditions = conditions;

    return v1beta1_api_service_status_local_var;
}


void v1beta1_api_service_status_free(v1beta1_api_service_status_t *v1beta1_api_service_status) {
    if(NULL == v1beta1_api_service_status){
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta1_api_service_status->conditions) {
        list_ForEach(listEntry, v1beta1_api_service_status->conditions) {
            v1beta1_api_service_condition_free(listEntry->data);
        }
        list_free(v1beta1_api_service_status->conditions);
        v1beta1_api_service_status->conditions = NULL;
    }
    free(v1beta1_api_service_status);
}

cJSON *v1beta1_api_service_status_convertToJSON(v1beta1_api_service_status_t *v1beta1_api_service_status) {
    cJSON *item = cJSON_CreateObject();

    // v1beta1_api_service_status->conditions
    if(v1beta1_api_service_status->conditions) { 
    cJSON *conditions = cJSON_AddArrayToObject(item, "conditions");
    if(conditions == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *conditionsListEntry;
    if (v1beta1_api_service_status->conditions) {
    list_ForEach(conditionsListEntry, v1beta1_api_service_status->conditions) {
    cJSON *itemLocal = v1beta1_api_service_condition_convertToJSON(conditionsListEntry->data);
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

v1beta1_api_service_status_t *v1beta1_api_service_status_parseFromJSON(cJSON *v1beta1_api_service_statusJSON){

    v1beta1_api_service_status_t *v1beta1_api_service_status_local_var = NULL;

    // v1beta1_api_service_status->conditions
    cJSON *conditions = cJSON_GetObjectItemCaseSensitive(v1beta1_api_service_statusJSON, "conditions");
    list_t *conditionsList;
    if (conditions) { 
    cJSON *conditions_local_nonprimitive;
    if(!cJSON_IsArray(conditions)){
        goto end; //nonprimitive container
    }

    conditionsList = list_create();

    cJSON_ArrayForEach(conditions_local_nonprimitive,conditions )
    {
        if(!cJSON_IsObject(conditions_local_nonprimitive)){
            goto end;
        }
        v1beta1_api_service_condition_t *conditionsItem = v1beta1_api_service_condition_parseFromJSON(conditions_local_nonprimitive);

        list_addElement(conditionsList, conditionsItem);
    }
    }


    v1beta1_api_service_status_local_var = v1beta1_api_service_status_create (
        conditions ? conditionsList : NULL
        );

    return v1beta1_api_service_status_local_var;
end:
    return NULL;

}
