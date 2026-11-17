#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha3_composite_pod_group_status.h"



static v1alpha3_composite_pod_group_status_t *v1alpha3_composite_pod_group_status_create_internal(
    list_t *conditions
    ) {
    v1alpha3_composite_pod_group_status_t *v1alpha3_composite_pod_group_status_local_var = malloc(sizeof(v1alpha3_composite_pod_group_status_t));
    if (!v1alpha3_composite_pod_group_status_local_var) {
        return NULL;
    }
    memset(v1alpha3_composite_pod_group_status_local_var, 0, sizeof(v1alpha3_composite_pod_group_status_t));
    v1alpha3_composite_pod_group_status_local_var->_library_owned = 1;
    v1alpha3_composite_pod_group_status_local_var->conditions = conditions;
    return v1alpha3_composite_pod_group_status_local_var;
}

__attribute__((deprecated)) v1alpha3_composite_pod_group_status_t *v1alpha3_composite_pod_group_status_create(
    list_t *conditions
    ) {
    v1alpha3_composite_pod_group_status_t *result = v1alpha3_composite_pod_group_status_create_internal (
        conditions
        );
    if (!result) {
    }
    return result;
}

void v1alpha3_composite_pod_group_status_free(v1alpha3_composite_pod_group_status_t *v1alpha3_composite_pod_group_status) {
    if(NULL == v1alpha3_composite_pod_group_status){
        return ;
    }
    if(v1alpha3_composite_pod_group_status->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1alpha3_composite_pod_group_status_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha3_composite_pod_group_status->conditions) {
        list_ForEach(listEntry, v1alpha3_composite_pod_group_status->conditions) {
            v1_condition_free(listEntry->data);
        }
        list_freeList(v1alpha3_composite_pod_group_status->conditions);
        v1alpha3_composite_pod_group_status->conditions = NULL;
    }
    free(v1alpha3_composite_pod_group_status);
}

cJSON *v1alpha3_composite_pod_group_status_convertToJSON(v1alpha3_composite_pod_group_status_t *v1alpha3_composite_pod_group_status) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha3_composite_pod_group_status->conditions
    if(v1alpha3_composite_pod_group_status->conditions) {
    cJSON *conditions = cJSON_AddArrayToObject(item, "conditions");
    if(conditions == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *conditionsListEntry;
    if (v1alpha3_composite_pod_group_status->conditions) {
    list_ForEach(conditionsListEntry, v1alpha3_composite_pod_group_status->conditions) {
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

v1alpha3_composite_pod_group_status_t *v1alpha3_composite_pod_group_status_parseFromJSON(cJSON *v1alpha3_composite_pod_group_statusJSON){

    v1alpha3_composite_pod_group_status_t *v1alpha3_composite_pod_group_status_local_var = NULL;

    // define the local list for v1alpha3_composite_pod_group_status->conditions
    list_t *conditionsList = NULL;

    // v1alpha3_composite_pod_group_status->conditions
    cJSON *conditions = cJSON_GetObjectItemCaseSensitive(v1alpha3_composite_pod_group_statusJSON, "conditions");
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



    v1alpha3_composite_pod_group_status_local_var = v1alpha3_composite_pod_group_status_create_internal (
        conditions ? conditionsList : NULL
        );

    if (!v1alpha3_composite_pod_group_status_local_var) {
        goto end;
    }

    return v1alpha3_composite_pod_group_status_local_var;
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
