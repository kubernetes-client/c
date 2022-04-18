#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_namespace_status.h"


char* phasev1_namespace_status_ToString(kubernetes_v1_namespace_status_PHASE_e phase) {
    char* phaseArray[] =  { "NULL", "Active", "Terminating" };
	return phaseArray[phase];
}

kubernetes_v1_namespace_status_PHASE_e phasev1_namespace_status_FromString(char* phase){
    int stringToReturn = 0;
    char *phaseArray[] =  { "NULL", "Active", "Terminating" };
    size_t sizeofArray = sizeof(phaseArray) / sizeof(phaseArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(phase, phaseArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

v1_namespace_status_t *v1_namespace_status_create(
    list_t *conditions,
    kubernetes_v1_namespace_status_PHASE_e phase
    ) {
    v1_namespace_status_t *v1_namespace_status_local_var = malloc(sizeof(v1_namespace_status_t));
    if (!v1_namespace_status_local_var) {
        return NULL;
    }
    v1_namespace_status_local_var->conditions = conditions;
    v1_namespace_status_local_var->phase = phase;

    return v1_namespace_status_local_var;
}


void v1_namespace_status_free(v1_namespace_status_t *v1_namespace_status) {
    if(NULL == v1_namespace_status){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_namespace_status->conditions) {
        list_ForEach(listEntry, v1_namespace_status->conditions) {
            v1_namespace_condition_free(listEntry->data);
        }
        list_freeList(v1_namespace_status->conditions);
        v1_namespace_status->conditions = NULL;
    }
    free(v1_namespace_status);
}

cJSON *v1_namespace_status_convertToJSON(v1_namespace_status_t *v1_namespace_status) {
    cJSON *item = cJSON_CreateObject();

    // v1_namespace_status->conditions
    if(v1_namespace_status->conditions) {
    cJSON *conditions = cJSON_AddArrayToObject(item, "conditions");
    if(conditions == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *conditionsListEntry;
    if (v1_namespace_status->conditions) {
    list_ForEach(conditionsListEntry, v1_namespace_status->conditions) {
    cJSON *itemLocal = v1_namespace_condition_convertToJSON(conditionsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(conditions, itemLocal);
    }
    }
    }


    // v1_namespace_status->phase
    if(v1_namespace_status->phase != kubernetes_v1_namespace_status_PHASE_NULL) {
    if(cJSON_AddStringToObject(item, "phase", phasev1_namespace_status_ToString(v1_namespace_status->phase)) == NULL)
    {
    goto fail; //Enum
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_namespace_status_t *v1_namespace_status_parseFromJSON(cJSON *v1_namespace_statusJSON){

    v1_namespace_status_t *v1_namespace_status_local_var = NULL;

    // define the local list for v1_namespace_status->conditions
    list_t *conditionsList = NULL;

    // v1_namespace_status->conditions
    cJSON *conditions = cJSON_GetObjectItemCaseSensitive(v1_namespace_statusJSON, "conditions");
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
        v1_namespace_condition_t *conditionsItem = v1_namespace_condition_parseFromJSON(conditions_local_nonprimitive);

        list_addElement(conditionsList, conditionsItem);
    }
    }

    // v1_namespace_status->phase
    cJSON *phase = cJSON_GetObjectItemCaseSensitive(v1_namespace_statusJSON, "phase");
    kubernetes_v1_namespace_status_PHASE_e phaseVariable;
    if (phase) { 
    if(!cJSON_IsString(phase))
    {
    goto end; //Enum
    }
    phaseVariable = phasev1_namespace_status_FromString(phase->valuestring);
    }


    v1_namespace_status_local_var = v1_namespace_status_create (
        conditions ? conditionsList : NULL,
        phase ? phaseVariable : -1
        );

    return v1_namespace_status_local_var;
end:
    if (conditionsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, conditionsList) {
            v1_namespace_condition_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(conditionsList);
        conditionsList = NULL;
    }
    return NULL;

}
