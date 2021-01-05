#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_replication_controller_status.h"



v1_replication_controller_status_t *v1_replication_controller_status_create(
    int available_replicas,
    list_t *conditions,
    int fully_labeled_replicas,
    long observed_generation,
    int ready_replicas,
    int replicas
    ) {
    v1_replication_controller_status_t *v1_replication_controller_status_local_var = malloc(sizeof(v1_replication_controller_status_t));
    if (!v1_replication_controller_status_local_var) {
        return NULL;
    }
    v1_replication_controller_status_local_var->available_replicas = available_replicas;
    v1_replication_controller_status_local_var->conditions = conditions;
    v1_replication_controller_status_local_var->fully_labeled_replicas = fully_labeled_replicas;
    v1_replication_controller_status_local_var->observed_generation = observed_generation;
    v1_replication_controller_status_local_var->ready_replicas = ready_replicas;
    v1_replication_controller_status_local_var->replicas = replicas;

    return v1_replication_controller_status_local_var;
}


void v1_replication_controller_status_free(v1_replication_controller_status_t *v1_replication_controller_status) {
    if(NULL == v1_replication_controller_status){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_replication_controller_status->conditions) {
        list_ForEach(listEntry, v1_replication_controller_status->conditions) {
            v1_replication_controller_condition_free(listEntry->data);
        }
        list_free(v1_replication_controller_status->conditions);
        v1_replication_controller_status->conditions = NULL;
    }
    free(v1_replication_controller_status);
}

cJSON *v1_replication_controller_status_convertToJSON(v1_replication_controller_status_t *v1_replication_controller_status) {
    cJSON *item = cJSON_CreateObject();

    // v1_replication_controller_status->available_replicas
    if(v1_replication_controller_status->available_replicas) { 
    if(cJSON_AddNumberToObject(item, "availableReplicas", v1_replication_controller_status->available_replicas) == NULL) {
    goto fail; //Numeric
    }
     } 


    // v1_replication_controller_status->conditions
    if(v1_replication_controller_status->conditions) { 
    cJSON *conditions = cJSON_AddArrayToObject(item, "conditions");
    if(conditions == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *conditionsListEntry;
    if (v1_replication_controller_status->conditions) {
    list_ForEach(conditionsListEntry, v1_replication_controller_status->conditions) {
    cJSON *itemLocal = v1_replication_controller_condition_convertToJSON(conditionsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(conditions, itemLocal);
    }
    }
     } 


    // v1_replication_controller_status->fully_labeled_replicas
    if(v1_replication_controller_status->fully_labeled_replicas) { 
    if(cJSON_AddNumberToObject(item, "fullyLabeledReplicas", v1_replication_controller_status->fully_labeled_replicas) == NULL) {
    goto fail; //Numeric
    }
     } 


    // v1_replication_controller_status->observed_generation
    if(v1_replication_controller_status->observed_generation) { 
    if(cJSON_AddNumberToObject(item, "observedGeneration", v1_replication_controller_status->observed_generation) == NULL) {
    goto fail; //Numeric
    }
     } 


    // v1_replication_controller_status->ready_replicas
    if(v1_replication_controller_status->ready_replicas) { 
    if(cJSON_AddNumberToObject(item, "readyReplicas", v1_replication_controller_status->ready_replicas) == NULL) {
    goto fail; //Numeric
    }
     } 


    // v1_replication_controller_status->replicas
    if (!v1_replication_controller_status->replicas) {
        goto fail;
    }
    
    if(cJSON_AddNumberToObject(item, "replicas", v1_replication_controller_status->replicas) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_replication_controller_status_t *v1_replication_controller_status_parseFromJSON(cJSON *v1_replication_controller_statusJSON){

    v1_replication_controller_status_t *v1_replication_controller_status_local_var = NULL;

    // v1_replication_controller_status->available_replicas
    cJSON *available_replicas = cJSON_GetObjectItemCaseSensitive(v1_replication_controller_statusJSON, "availableReplicas");
    if (available_replicas) { 
    if(!cJSON_IsNumber(available_replicas))
    {
    goto end; //Numeric
    }
    }

    // v1_replication_controller_status->conditions
    cJSON *conditions = cJSON_GetObjectItemCaseSensitive(v1_replication_controller_statusJSON, "conditions");
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
        v1_replication_controller_condition_t *conditionsItem = v1_replication_controller_condition_parseFromJSON(conditions_local_nonprimitive);

        list_addElement(conditionsList, conditionsItem);
    }
    }

    // v1_replication_controller_status->fully_labeled_replicas
    cJSON *fully_labeled_replicas = cJSON_GetObjectItemCaseSensitive(v1_replication_controller_statusJSON, "fullyLabeledReplicas");
    if (fully_labeled_replicas) { 
    if(!cJSON_IsNumber(fully_labeled_replicas))
    {
    goto end; //Numeric
    }
    }

    // v1_replication_controller_status->observed_generation
    cJSON *observed_generation = cJSON_GetObjectItemCaseSensitive(v1_replication_controller_statusJSON, "observedGeneration");
    if (observed_generation) { 
    if(!cJSON_IsNumber(observed_generation))
    {
    goto end; //Numeric
    }
    }

    // v1_replication_controller_status->ready_replicas
    cJSON *ready_replicas = cJSON_GetObjectItemCaseSensitive(v1_replication_controller_statusJSON, "readyReplicas");
    if (ready_replicas) { 
    if(!cJSON_IsNumber(ready_replicas))
    {
    goto end; //Numeric
    }
    }

    // v1_replication_controller_status->replicas
    cJSON *replicas = cJSON_GetObjectItemCaseSensitive(v1_replication_controller_statusJSON, "replicas");
    if (!replicas) {
        goto end;
    }

    
    if(!cJSON_IsNumber(replicas))
    {
    goto end; //Numeric
    }


    v1_replication_controller_status_local_var = v1_replication_controller_status_create (
        available_replicas ? available_replicas->valuedouble : 0,
        conditions ? conditionsList : NULL,
        fully_labeled_replicas ? fully_labeled_replicas->valuedouble : 0,
        observed_generation ? observed_generation->valuedouble : 0,
        ready_replicas ? ready_replicas->valuedouble : 0,
        replicas->valuedouble
        );

    return v1_replication_controller_status_local_var;
end:
    return NULL;

}
