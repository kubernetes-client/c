#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "extensions_v1beta1_deployment_status.h"



extensions_v1beta1_deployment_status_t *extensions_v1beta1_deployment_status_create(
    int available_replicas,
    int collision_count,
    list_t *conditions,
    long observed_generation,
    int ready_replicas,
    int replicas,
    int unavailable_replicas,
    int updated_replicas
    ) {
    extensions_v1beta1_deployment_status_t *extensions_v1beta1_deployment_status_local_var = malloc(sizeof(extensions_v1beta1_deployment_status_t));
    if (!extensions_v1beta1_deployment_status_local_var) {
        return NULL;
    }
    extensions_v1beta1_deployment_status_local_var->available_replicas = available_replicas;
    extensions_v1beta1_deployment_status_local_var->collision_count = collision_count;
    extensions_v1beta1_deployment_status_local_var->conditions = conditions;
    extensions_v1beta1_deployment_status_local_var->observed_generation = observed_generation;
    extensions_v1beta1_deployment_status_local_var->ready_replicas = ready_replicas;
    extensions_v1beta1_deployment_status_local_var->replicas = replicas;
    extensions_v1beta1_deployment_status_local_var->unavailable_replicas = unavailable_replicas;
    extensions_v1beta1_deployment_status_local_var->updated_replicas = updated_replicas;

    return extensions_v1beta1_deployment_status_local_var;
}


void extensions_v1beta1_deployment_status_free(extensions_v1beta1_deployment_status_t *extensions_v1beta1_deployment_status) {
    if(NULL == extensions_v1beta1_deployment_status){
        return ;
    }
    listEntry_t *listEntry;
    if (extensions_v1beta1_deployment_status->conditions) {
        list_ForEach(listEntry, extensions_v1beta1_deployment_status->conditions) {
            extensions_v1beta1_deployment_condition_free(listEntry->data);
        }
        list_free(extensions_v1beta1_deployment_status->conditions);
        extensions_v1beta1_deployment_status->conditions = NULL;
    }
    free(extensions_v1beta1_deployment_status);
}

cJSON *extensions_v1beta1_deployment_status_convertToJSON(extensions_v1beta1_deployment_status_t *extensions_v1beta1_deployment_status) {
    cJSON *item = cJSON_CreateObject();

    // extensions_v1beta1_deployment_status->available_replicas
    if(extensions_v1beta1_deployment_status->available_replicas) { 
    if(cJSON_AddNumberToObject(item, "availableReplicas", extensions_v1beta1_deployment_status->available_replicas) == NULL) {
    goto fail; //Numeric
    }
     } 


    // extensions_v1beta1_deployment_status->collision_count
    if(extensions_v1beta1_deployment_status->collision_count) { 
    if(cJSON_AddNumberToObject(item, "collisionCount", extensions_v1beta1_deployment_status->collision_count) == NULL) {
    goto fail; //Numeric
    }
     } 


    // extensions_v1beta1_deployment_status->conditions
    if(extensions_v1beta1_deployment_status->conditions) { 
    cJSON *conditions = cJSON_AddArrayToObject(item, "conditions");
    if(conditions == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *conditionsListEntry;
    if (extensions_v1beta1_deployment_status->conditions) {
    list_ForEach(conditionsListEntry, extensions_v1beta1_deployment_status->conditions) {
    cJSON *itemLocal = extensions_v1beta1_deployment_condition_convertToJSON(conditionsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(conditions, itemLocal);
    }
    }
     } 


    // extensions_v1beta1_deployment_status->observed_generation
    if(extensions_v1beta1_deployment_status->observed_generation) { 
    if(cJSON_AddNumberToObject(item, "observedGeneration", extensions_v1beta1_deployment_status->observed_generation) == NULL) {
    goto fail; //Numeric
    }
     } 


    // extensions_v1beta1_deployment_status->ready_replicas
    if(extensions_v1beta1_deployment_status->ready_replicas) { 
    if(cJSON_AddNumberToObject(item, "readyReplicas", extensions_v1beta1_deployment_status->ready_replicas) == NULL) {
    goto fail; //Numeric
    }
     } 


    // extensions_v1beta1_deployment_status->replicas
    if(extensions_v1beta1_deployment_status->replicas) { 
    if(cJSON_AddNumberToObject(item, "replicas", extensions_v1beta1_deployment_status->replicas) == NULL) {
    goto fail; //Numeric
    }
     } 


    // extensions_v1beta1_deployment_status->unavailable_replicas
    if(extensions_v1beta1_deployment_status->unavailable_replicas) { 
    if(cJSON_AddNumberToObject(item, "unavailableReplicas", extensions_v1beta1_deployment_status->unavailable_replicas) == NULL) {
    goto fail; //Numeric
    }
     } 


    // extensions_v1beta1_deployment_status->updated_replicas
    if(extensions_v1beta1_deployment_status->updated_replicas) { 
    if(cJSON_AddNumberToObject(item, "updatedReplicas", extensions_v1beta1_deployment_status->updated_replicas) == NULL) {
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

extensions_v1beta1_deployment_status_t *extensions_v1beta1_deployment_status_parseFromJSON(cJSON *extensions_v1beta1_deployment_statusJSON){

    extensions_v1beta1_deployment_status_t *extensions_v1beta1_deployment_status_local_var = NULL;

    // extensions_v1beta1_deployment_status->available_replicas
    cJSON *available_replicas = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_deployment_statusJSON, "availableReplicas");
    if (available_replicas) { 
    if(!cJSON_IsNumber(available_replicas))
    {
    goto end; //Numeric
    }
    }

    // extensions_v1beta1_deployment_status->collision_count
    cJSON *collision_count = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_deployment_statusJSON, "collisionCount");
    if (collision_count) { 
    if(!cJSON_IsNumber(collision_count))
    {
    goto end; //Numeric
    }
    }

    // extensions_v1beta1_deployment_status->conditions
    cJSON *conditions = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_deployment_statusJSON, "conditions");
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
        extensions_v1beta1_deployment_condition_t *conditionsItem = extensions_v1beta1_deployment_condition_parseFromJSON(conditions_local_nonprimitive);

        list_addElement(conditionsList, conditionsItem);
    }
    }

    // extensions_v1beta1_deployment_status->observed_generation
    cJSON *observed_generation = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_deployment_statusJSON, "observedGeneration");
    if (observed_generation) { 
    if(!cJSON_IsNumber(observed_generation))
    {
    goto end; //Numeric
    }
    }

    // extensions_v1beta1_deployment_status->ready_replicas
    cJSON *ready_replicas = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_deployment_statusJSON, "readyReplicas");
    if (ready_replicas) { 
    if(!cJSON_IsNumber(ready_replicas))
    {
    goto end; //Numeric
    }
    }

    // extensions_v1beta1_deployment_status->replicas
    cJSON *replicas = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_deployment_statusJSON, "replicas");
    if (replicas) { 
    if(!cJSON_IsNumber(replicas))
    {
    goto end; //Numeric
    }
    }

    // extensions_v1beta1_deployment_status->unavailable_replicas
    cJSON *unavailable_replicas = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_deployment_statusJSON, "unavailableReplicas");
    if (unavailable_replicas) { 
    if(!cJSON_IsNumber(unavailable_replicas))
    {
    goto end; //Numeric
    }
    }

    // extensions_v1beta1_deployment_status->updated_replicas
    cJSON *updated_replicas = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_deployment_statusJSON, "updatedReplicas");
    if (updated_replicas) { 
    if(!cJSON_IsNumber(updated_replicas))
    {
    goto end; //Numeric
    }
    }


    extensions_v1beta1_deployment_status_local_var = extensions_v1beta1_deployment_status_create (
        available_replicas ? available_replicas->valuedouble : 0,
        collision_count ? collision_count->valuedouble : 0,
        conditions ? conditionsList : NULL,
        observed_generation ? observed_generation->valuedouble : 0,
        ready_replicas ? ready_replicas->valuedouble : 0,
        replicas ? replicas->valuedouble : 0,
        unavailable_replicas ? unavailable_replicas->valuedouble : 0,
        updated_replicas ? updated_replicas->valuedouble : 0
        );

    return extensions_v1beta1_deployment_status_local_var;
end:
    return NULL;

}
