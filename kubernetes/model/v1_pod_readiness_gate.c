#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_pod_readiness_gate.h"


char* condition_typev1_pod_readiness_gate_ToString(kubernetes_v1_pod_readiness_gate_CONDITIONTYPE_e condition_type) {
    char* condition_typeArray[] =  { "NULL", "ContainersReady", "Initialized", "PodScheduled", "Ready" };
	return condition_typeArray[condition_type];
}

kubernetes_v1_pod_readiness_gate_CONDITIONTYPE_e condition_typev1_pod_readiness_gate_FromString(char* condition_type){
    int stringToReturn = 0;
    char *condition_typeArray[] =  { "NULL", "ContainersReady", "Initialized", "PodScheduled", "Ready" };
    size_t sizeofArray = sizeof(condition_typeArray) / sizeof(condition_typeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(condition_type, condition_typeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

v1_pod_readiness_gate_t *v1_pod_readiness_gate_create(
    kubernetes_v1_pod_readiness_gate_CONDITIONTYPE_e condition_type
    ) {
    v1_pod_readiness_gate_t *v1_pod_readiness_gate_local_var = malloc(sizeof(v1_pod_readiness_gate_t));
    if (!v1_pod_readiness_gate_local_var) {
        return NULL;
    }
    v1_pod_readiness_gate_local_var->condition_type = condition_type;

    return v1_pod_readiness_gate_local_var;
}


void v1_pod_readiness_gate_free(v1_pod_readiness_gate_t *v1_pod_readiness_gate) {
    if(NULL == v1_pod_readiness_gate){
        return ;
    }
    listEntry_t *listEntry;
    free(v1_pod_readiness_gate);
}

cJSON *v1_pod_readiness_gate_convertToJSON(v1_pod_readiness_gate_t *v1_pod_readiness_gate) {
    cJSON *item = cJSON_CreateObject();

    // v1_pod_readiness_gate->condition_type
    if (kubernetes_v1_pod_readiness_gate_CONDITIONTYPE_NULL == v1_pod_readiness_gate->condition_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "conditionType", condition_typev1_pod_readiness_gate_ToString(v1_pod_readiness_gate->condition_type)) == NULL)
    {
    goto fail; //Enum
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_pod_readiness_gate_t *v1_pod_readiness_gate_parseFromJSON(cJSON *v1_pod_readiness_gateJSON){

    v1_pod_readiness_gate_t *v1_pod_readiness_gate_local_var = NULL;

    // v1_pod_readiness_gate->condition_type
    cJSON *condition_type = cJSON_GetObjectItemCaseSensitive(v1_pod_readiness_gateJSON, "conditionType");
    if (!condition_type) {
        goto end;
    }

    kubernetes_v1_pod_readiness_gate_CONDITIONTYPE_e condition_typeVariable;
    
    if(!cJSON_IsString(condition_type))
    {
    goto end; //Enum
    }
    condition_typeVariable = condition_typev1_pod_readiness_gate_FromString(condition_type->valuestring);


    v1_pod_readiness_gate_local_var = v1_pod_readiness_gate_create (
        condition_typeVariable
        );

    return v1_pod_readiness_gate_local_var;
end:
    return NULL;

}
