#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_replica_set_status.h"



static v1_replica_set_status_t *v1_replica_set_status_create_internal(
    int available_replicas,
    list_t *conditions,
    int fully_labeled_replicas,
    long observed_generation,
    int ready_replicas,
    int replicas,
    int terminating_replicas
    ) {
    v1_replica_set_status_t *v1_replica_set_status_local_var = malloc(sizeof(v1_replica_set_status_t));
    if (!v1_replica_set_status_local_var) {
        return NULL;
    }
    v1_replica_set_status_local_var->available_replicas = available_replicas;
    v1_replica_set_status_local_var->conditions = conditions;
    v1_replica_set_status_local_var->fully_labeled_replicas = fully_labeled_replicas;
    v1_replica_set_status_local_var->observed_generation = observed_generation;
    v1_replica_set_status_local_var->ready_replicas = ready_replicas;
    v1_replica_set_status_local_var->replicas = replicas;
    v1_replica_set_status_local_var->terminating_replicas = terminating_replicas;

    v1_replica_set_status_local_var->_library_owned = 1;
    return v1_replica_set_status_local_var;
}

__attribute__((deprecated)) v1_replica_set_status_t *v1_replica_set_status_create(
    int available_replicas,
    list_t *conditions,
    int fully_labeled_replicas,
    long observed_generation,
    int ready_replicas,
    int replicas,
    int terminating_replicas
    ) {
    return v1_replica_set_status_create_internal (
        available_replicas,
        conditions,
        fully_labeled_replicas,
        observed_generation,
        ready_replicas,
        replicas,
        terminating_replicas
        );
}

void v1_replica_set_status_free(v1_replica_set_status_t *v1_replica_set_status) {
    if(NULL == v1_replica_set_status){
        return ;
    }
    if(v1_replica_set_status->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_replica_set_status_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_replica_set_status->conditions) {
        list_ForEach(listEntry, v1_replica_set_status->conditions) {
            v1_replica_set_condition_free(listEntry->data);
        }
        list_freeList(v1_replica_set_status->conditions);
        v1_replica_set_status->conditions = NULL;
    }
    free(v1_replica_set_status);
}

cJSON *v1_replica_set_status_convertToJSON(v1_replica_set_status_t *v1_replica_set_status) {
    cJSON *item = cJSON_CreateObject();

    // v1_replica_set_status->available_replicas
    if(v1_replica_set_status->available_replicas) {
    if(cJSON_AddNumberToObject(item, "availableReplicas", v1_replica_set_status->available_replicas) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_replica_set_status->conditions
    if(v1_replica_set_status->conditions) {
    cJSON *conditions = cJSON_AddArrayToObject(item, "conditions");
    if(conditions == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *conditionsListEntry;
    if (v1_replica_set_status->conditions) {
    list_ForEach(conditionsListEntry, v1_replica_set_status->conditions) {
    cJSON *itemLocal = v1_replica_set_condition_convertToJSON(conditionsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(conditions, itemLocal);
    }
    }
    }


    // v1_replica_set_status->fully_labeled_replicas
    if(v1_replica_set_status->fully_labeled_replicas) {
    if(cJSON_AddNumberToObject(item, "fullyLabeledReplicas", v1_replica_set_status->fully_labeled_replicas) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_replica_set_status->observed_generation
    if(v1_replica_set_status->observed_generation) {
    if(cJSON_AddNumberToObject(item, "observedGeneration", v1_replica_set_status->observed_generation) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_replica_set_status->ready_replicas
    if(v1_replica_set_status->ready_replicas) {
    if(cJSON_AddNumberToObject(item, "readyReplicas", v1_replica_set_status->ready_replicas) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_replica_set_status->replicas
    if (!v1_replica_set_status->replicas) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "replicas", v1_replica_set_status->replicas) == NULL) {
    goto fail; //Numeric
    }


    // v1_replica_set_status->terminating_replicas
    if(v1_replica_set_status->terminating_replicas) {
    if(cJSON_AddNumberToObject(item, "terminatingReplicas", v1_replica_set_status->terminating_replicas) == NULL) {
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

v1_replica_set_status_t *v1_replica_set_status_parseFromJSON(cJSON *v1_replica_set_statusJSON){

    v1_replica_set_status_t *v1_replica_set_status_local_var = NULL;

    // define the local list for v1_replica_set_status->conditions
    list_t *conditionsList = NULL;

    // v1_replica_set_status->available_replicas
    cJSON *available_replicas = cJSON_GetObjectItemCaseSensitive(v1_replica_set_statusJSON, "availableReplicas");
    if (cJSON_IsNull(available_replicas)) {
        available_replicas = NULL;
    }
    if (available_replicas) { 
    if(!cJSON_IsNumber(available_replicas))
    {
    goto end; //Numeric
    }
    }

    // v1_replica_set_status->conditions
    cJSON *conditions = cJSON_GetObjectItemCaseSensitive(v1_replica_set_statusJSON, "conditions");
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
        v1_replica_set_condition_t *conditionsItem = v1_replica_set_condition_parseFromJSON(conditions_local_nonprimitive);

        list_addElement(conditionsList, conditionsItem);
    }
    }

    // v1_replica_set_status->fully_labeled_replicas
    cJSON *fully_labeled_replicas = cJSON_GetObjectItemCaseSensitive(v1_replica_set_statusJSON, "fullyLabeledReplicas");
    if (cJSON_IsNull(fully_labeled_replicas)) {
        fully_labeled_replicas = NULL;
    }
    if (fully_labeled_replicas) { 
    if(!cJSON_IsNumber(fully_labeled_replicas))
    {
    goto end; //Numeric
    }
    }

    // v1_replica_set_status->observed_generation
    cJSON *observed_generation = cJSON_GetObjectItemCaseSensitive(v1_replica_set_statusJSON, "observedGeneration");
    if (cJSON_IsNull(observed_generation)) {
        observed_generation = NULL;
    }
    if (observed_generation) { 
    if(!cJSON_IsNumber(observed_generation))
    {
    goto end; //Numeric
    }
    }

    // v1_replica_set_status->ready_replicas
    cJSON *ready_replicas = cJSON_GetObjectItemCaseSensitive(v1_replica_set_statusJSON, "readyReplicas");
    if (cJSON_IsNull(ready_replicas)) {
        ready_replicas = NULL;
    }
    if (ready_replicas) { 
    if(!cJSON_IsNumber(ready_replicas))
    {
    goto end; //Numeric
    }
    }

    // v1_replica_set_status->replicas
    cJSON *replicas = cJSON_GetObjectItemCaseSensitive(v1_replica_set_statusJSON, "replicas");
    if (cJSON_IsNull(replicas)) {
        replicas = NULL;
    }
    if (!replicas) {
        goto end;
    }

    
    if(!cJSON_IsNumber(replicas))
    {
    goto end; //Numeric
    }

    // v1_replica_set_status->terminating_replicas
    cJSON *terminating_replicas = cJSON_GetObjectItemCaseSensitive(v1_replica_set_statusJSON, "terminatingReplicas");
    if (cJSON_IsNull(terminating_replicas)) {
        terminating_replicas = NULL;
    }
    if (terminating_replicas) { 
    if(!cJSON_IsNumber(terminating_replicas))
    {
    goto end; //Numeric
    }
    }


    v1_replica_set_status_local_var = v1_replica_set_status_create_internal (
        available_replicas ? available_replicas->valuedouble : 0,
        conditions ? conditionsList : NULL,
        fully_labeled_replicas ? fully_labeled_replicas->valuedouble : 0,
        observed_generation ? observed_generation->valuedouble : 0,
        ready_replicas ? ready_replicas->valuedouble : 0,
        replicas->valuedouble,
        terminating_replicas ? terminating_replicas->valuedouble : 0
        );

    return v1_replica_set_status_local_var;
end:
    if (conditionsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, conditionsList) {
            v1_replica_set_condition_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(conditionsList);
        conditionsList = NULL;
    }
    return NULL;

}
