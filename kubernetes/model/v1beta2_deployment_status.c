#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta2_deployment_status.h"



v1beta2_deployment_status_t *v1beta2_deployment_status_create(
    int available_replicas,
    int collision_count,
    list_t *conditions,
    long observed_generation,
    int ready_replicas,
    int replicas,
    int unavailable_replicas,
    int updated_replicas
    ) {
    v1beta2_deployment_status_t *v1beta2_deployment_status_local_var = malloc(sizeof(v1beta2_deployment_status_t));
    if (!v1beta2_deployment_status_local_var) {
        return NULL;
    }
    v1beta2_deployment_status_local_var->available_replicas = available_replicas;
    v1beta2_deployment_status_local_var->collision_count = collision_count;
    v1beta2_deployment_status_local_var->conditions = conditions;
    v1beta2_deployment_status_local_var->observed_generation = observed_generation;
    v1beta2_deployment_status_local_var->ready_replicas = ready_replicas;
    v1beta2_deployment_status_local_var->replicas = replicas;
    v1beta2_deployment_status_local_var->unavailable_replicas = unavailable_replicas;
    v1beta2_deployment_status_local_var->updated_replicas = updated_replicas;

    return v1beta2_deployment_status_local_var;
}


void v1beta2_deployment_status_free(v1beta2_deployment_status_t *v1beta2_deployment_status) {
    if(NULL == v1beta2_deployment_status){
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta2_deployment_status->conditions) {
        list_ForEach(listEntry, v1beta2_deployment_status->conditions) {
            v1beta2_deployment_condition_free(listEntry->data);
        }
        list_free(v1beta2_deployment_status->conditions);
        v1beta2_deployment_status->conditions = NULL;
    }
    free(v1beta2_deployment_status);
}

cJSON *v1beta2_deployment_status_convertToJSON(v1beta2_deployment_status_t *v1beta2_deployment_status) {
    cJSON *item = cJSON_CreateObject();

    // v1beta2_deployment_status->available_replicas
    if(v1beta2_deployment_status->available_replicas) { 
    if(cJSON_AddNumberToObject(item, "availableReplicas", v1beta2_deployment_status->available_replicas) == NULL) {
    goto fail; //Numeric
    }
     } 


    // v1beta2_deployment_status->collision_count
    if(v1beta2_deployment_status->collision_count) { 
    if(cJSON_AddNumberToObject(item, "collisionCount", v1beta2_deployment_status->collision_count) == NULL) {
    goto fail; //Numeric
    }
     } 


    // v1beta2_deployment_status->conditions
    if(v1beta2_deployment_status->conditions) { 
    cJSON *conditions = cJSON_AddArrayToObject(item, "conditions");
    if(conditions == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *conditionsListEntry;
    if (v1beta2_deployment_status->conditions) {
    list_ForEach(conditionsListEntry, v1beta2_deployment_status->conditions) {
    cJSON *itemLocal = v1beta2_deployment_condition_convertToJSON(conditionsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(conditions, itemLocal);
    }
    }
     } 


    // v1beta2_deployment_status->observed_generation
    if(v1beta2_deployment_status->observed_generation) { 
    if(cJSON_AddNumberToObject(item, "observedGeneration", v1beta2_deployment_status->observed_generation) == NULL) {
    goto fail; //Numeric
    }
     } 


    // v1beta2_deployment_status->ready_replicas
    if(v1beta2_deployment_status->ready_replicas) { 
    if(cJSON_AddNumberToObject(item, "readyReplicas", v1beta2_deployment_status->ready_replicas) == NULL) {
    goto fail; //Numeric
    }
     } 


    // v1beta2_deployment_status->replicas
    if(v1beta2_deployment_status->replicas) { 
    if(cJSON_AddNumberToObject(item, "replicas", v1beta2_deployment_status->replicas) == NULL) {
    goto fail; //Numeric
    }
     } 


    // v1beta2_deployment_status->unavailable_replicas
    if(v1beta2_deployment_status->unavailable_replicas) { 
    if(cJSON_AddNumberToObject(item, "unavailableReplicas", v1beta2_deployment_status->unavailable_replicas) == NULL) {
    goto fail; //Numeric
    }
     } 


    // v1beta2_deployment_status->updated_replicas
    if(v1beta2_deployment_status->updated_replicas) { 
    if(cJSON_AddNumberToObject(item, "updatedReplicas", v1beta2_deployment_status->updated_replicas) == NULL) {
    goto fail; //Numeric
    }
     } 

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1beta2_deployment_status_t *v1beta2_deployment_status_parseFromJSON(cJSON *v1beta2_deployment_statusJSON){

    v1beta2_deployment_status_t *v1beta2_deployment_status_local_var = NULL;

    // v1beta2_deployment_status->available_replicas
    cJSON *available_replicas = cJSON_GetObjectItemCaseSensitive(v1beta2_deployment_statusJSON, "availableReplicas");
    if (available_replicas) { 
    if(!cJSON_IsNumber(available_replicas))
    {
    goto end; //Numeric
    }
    }

    // v1beta2_deployment_status->collision_count
    cJSON *collision_count = cJSON_GetObjectItemCaseSensitive(v1beta2_deployment_statusJSON, "collisionCount");
    if (collision_count) { 
    if(!cJSON_IsNumber(collision_count))
    {
    goto end; //Numeric
    }
    }

    // v1beta2_deployment_status->conditions
    cJSON *conditions = cJSON_GetObjectItemCaseSensitive(v1beta2_deployment_statusJSON, "conditions");
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
        v1beta2_deployment_condition_t *conditionsItem = v1beta2_deployment_condition_parseFromJSON(conditions_local_nonprimitive);

        list_addElement(conditionsList, conditionsItem);
    }
    }

    // v1beta2_deployment_status->observed_generation
    cJSON *observed_generation = cJSON_GetObjectItemCaseSensitive(v1beta2_deployment_statusJSON, "observedGeneration");
    if (observed_generation) { 
    if(!cJSON_IsNumber(observed_generation))
    {
    goto end; //Numeric
    }
    }

    // v1beta2_deployment_status->ready_replicas
    cJSON *ready_replicas = cJSON_GetObjectItemCaseSensitive(v1beta2_deployment_statusJSON, "readyReplicas");
    if (ready_replicas) { 
    if(!cJSON_IsNumber(ready_replicas))
    {
    goto end; //Numeric
    }
    }

    // v1beta2_deployment_status->replicas
    cJSON *replicas = cJSON_GetObjectItemCaseSensitive(v1beta2_deployment_statusJSON, "replicas");
    if (replicas) { 
    if(!cJSON_IsNumber(replicas))
    {
    goto end; //Numeric
    }
    }

    // v1beta2_deployment_status->unavailable_replicas
    cJSON *unavailable_replicas = cJSON_GetObjectItemCaseSensitive(v1beta2_deployment_statusJSON, "unavailableReplicas");
    if (unavailable_replicas) { 
    if(!cJSON_IsNumber(unavailable_replicas))
    {
    goto end; //Numeric
    }
    }

    // v1beta2_deployment_status->updated_replicas
    cJSON *updated_replicas = cJSON_GetObjectItemCaseSensitive(v1beta2_deployment_statusJSON, "updatedReplicas");
    if (updated_replicas) { 
    if(!cJSON_IsNumber(updated_replicas))
    {
    goto end; //Numeric
    }
    }


    v1beta2_deployment_status_local_var = v1beta2_deployment_status_create (
        available_replicas ? available_replicas->valuedouble : 0,
        collision_count ? collision_count->valuedouble : 0,
        conditions ? conditionsList : NULL,
        observed_generation ? observed_generation->valuedouble : 0,
        ready_replicas ? ready_replicas->valuedouble : 0,
        replicas ? replicas->valuedouble : 0,
        unavailable_replicas ? unavailable_replicas->valuedouble : 0,
        updated_replicas ? updated_replicas->valuedouble : 0
        );

    return v1beta2_deployment_status_local_var;
end:
    return NULL;

}
