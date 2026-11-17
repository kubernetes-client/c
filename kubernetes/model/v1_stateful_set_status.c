#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_stateful_set_status.h"



static v1_stateful_set_status_t *v1_stateful_set_status_create_internal(
    int *available_replicas,
    int *collision_count,
    list_t *conditions,
    int *current_replicas,
    char *current_revision,
    long *observed_generation,
    int *ready_replicas,
    int *replicas,
    char *update_revision,
    int *updated_replicas
    ) {
    v1_stateful_set_status_t *v1_stateful_set_status_local_var = malloc(sizeof(v1_stateful_set_status_t));
    if (!v1_stateful_set_status_local_var) {
        return NULL;
    }
    memset(v1_stateful_set_status_local_var, 0, sizeof(v1_stateful_set_status_t));
    v1_stateful_set_status_local_var->_library_owned = 1;
    v1_stateful_set_status_local_var->available_replicas = available_replicas;
    v1_stateful_set_status_local_var->collision_count = collision_count;
    v1_stateful_set_status_local_var->conditions = conditions;
    v1_stateful_set_status_local_var->current_replicas = current_replicas;
    v1_stateful_set_status_local_var->current_revision = current_revision;
    v1_stateful_set_status_local_var->observed_generation = observed_generation;
    v1_stateful_set_status_local_var->ready_replicas = ready_replicas;
    v1_stateful_set_status_local_var->replicas = replicas;
    v1_stateful_set_status_local_var->update_revision = update_revision;
    v1_stateful_set_status_local_var->updated_replicas = updated_replicas;
    return v1_stateful_set_status_local_var;
}

__attribute__((deprecated)) v1_stateful_set_status_t *v1_stateful_set_status_create(
    int *available_replicas,
    int *collision_count,
    list_t *conditions,
    int *current_replicas,
    char *current_revision,
    long *observed_generation,
    int *ready_replicas,
    int *replicas,
    char *update_revision,
    int *updated_replicas
    ) {
    int *available_replicas_copy = NULL;
    if (available_replicas) {
        available_replicas_copy = malloc(sizeof(int));
        if (available_replicas_copy) *available_replicas_copy = *available_replicas;
    }
    int *collision_count_copy = NULL;
    if (collision_count) {
        collision_count_copy = malloc(sizeof(int));
        if (collision_count_copy) *collision_count_copy = *collision_count;
    }
    int *current_replicas_copy = NULL;
    if (current_replicas) {
        current_replicas_copy = malloc(sizeof(int));
        if (current_replicas_copy) *current_replicas_copy = *current_replicas;
    }
    long *observed_generation_copy = NULL;
    if (observed_generation) {
        observed_generation_copy = malloc(sizeof(long));
        if (observed_generation_copy) *observed_generation_copy = *observed_generation;
    }
    int *ready_replicas_copy = NULL;
    if (ready_replicas) {
        ready_replicas_copy = malloc(sizeof(int));
        if (ready_replicas_copy) *ready_replicas_copy = *ready_replicas;
    }
    int *replicas_copy = NULL;
    if (replicas) {
        replicas_copy = malloc(sizeof(int));
        if (replicas_copy) *replicas_copy = *replicas;
    }
    int *updated_replicas_copy = NULL;
    if (updated_replicas) {
        updated_replicas_copy = malloc(sizeof(int));
        if (updated_replicas_copy) *updated_replicas_copy = *updated_replicas;
    }
    v1_stateful_set_status_t *result = v1_stateful_set_status_create_internal (
        available_replicas_copy,
        collision_count_copy,
        conditions,
        current_replicas_copy,
        current_revision,
        observed_generation_copy,
        ready_replicas_copy,
        replicas_copy,
        update_revision,
        updated_replicas_copy
        );
    if (!result) {
        free(available_replicas_copy);
        free(collision_count_copy);
        free(current_replicas_copy);
        free(observed_generation_copy);
        free(ready_replicas_copy);
        free(replicas_copy);
        free(updated_replicas_copy);
    }
    return result;
}

void v1_stateful_set_status_free(v1_stateful_set_status_t *v1_stateful_set_status) {
    if(NULL == v1_stateful_set_status){
        return ;
    }
    if(v1_stateful_set_status->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_stateful_set_status_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_stateful_set_status->available_replicas) {
        free(v1_stateful_set_status->available_replicas);
        v1_stateful_set_status->available_replicas = NULL;
    }
    if (v1_stateful_set_status->collision_count) {
        free(v1_stateful_set_status->collision_count);
        v1_stateful_set_status->collision_count = NULL;
    }
    if (v1_stateful_set_status->conditions) {
        list_ForEach(listEntry, v1_stateful_set_status->conditions) {
            v1_stateful_set_condition_free(listEntry->data);
        }
        list_freeList(v1_stateful_set_status->conditions);
        v1_stateful_set_status->conditions = NULL;
    }
    if (v1_stateful_set_status->current_replicas) {
        free(v1_stateful_set_status->current_replicas);
        v1_stateful_set_status->current_replicas = NULL;
    }
    if (v1_stateful_set_status->current_revision) {
        free(v1_stateful_set_status->current_revision);
        v1_stateful_set_status->current_revision = NULL;
    }
    if (v1_stateful_set_status->observed_generation) {
        free(v1_stateful_set_status->observed_generation);
        v1_stateful_set_status->observed_generation = NULL;
    }
    if (v1_stateful_set_status->ready_replicas) {
        free(v1_stateful_set_status->ready_replicas);
        v1_stateful_set_status->ready_replicas = NULL;
    }
    if (v1_stateful_set_status->replicas) {
        free(v1_stateful_set_status->replicas);
        v1_stateful_set_status->replicas = NULL;
    }
    if (v1_stateful_set_status->update_revision) {
        free(v1_stateful_set_status->update_revision);
        v1_stateful_set_status->update_revision = NULL;
    }
    if (v1_stateful_set_status->updated_replicas) {
        free(v1_stateful_set_status->updated_replicas);
        v1_stateful_set_status->updated_replicas = NULL;
    }
    free(v1_stateful_set_status);
}

cJSON *v1_stateful_set_status_convertToJSON(v1_stateful_set_status_t *v1_stateful_set_status) {
    cJSON *item = cJSON_CreateObject();

    // v1_stateful_set_status->available_replicas
    if(v1_stateful_set_status->available_replicas) {
    if(cJSON_AddNumberToObject(item, "availableReplicas", *v1_stateful_set_status->available_replicas) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_stateful_set_status->collision_count
    if(v1_stateful_set_status->collision_count) {
    if(cJSON_AddNumberToObject(item, "collisionCount", *v1_stateful_set_status->collision_count) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_stateful_set_status->conditions
    if(v1_stateful_set_status->conditions) {
    cJSON *conditions = cJSON_AddArrayToObject(item, "conditions");
    if(conditions == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *conditionsListEntry;
    if (v1_stateful_set_status->conditions) {
    list_ForEach(conditionsListEntry, v1_stateful_set_status->conditions) {
    cJSON *itemLocal = v1_stateful_set_condition_convertToJSON(conditionsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(conditions, itemLocal);
    }
    }
    }


    // v1_stateful_set_status->current_replicas
    if(v1_stateful_set_status->current_replicas) {
    if(cJSON_AddNumberToObject(item, "currentReplicas", *v1_stateful_set_status->current_replicas) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_stateful_set_status->current_revision
    if(v1_stateful_set_status->current_revision) {
    if(cJSON_AddStringToObject(item, "currentRevision", v1_stateful_set_status->current_revision) == NULL) {
    goto fail; //String
    }
    }


    // v1_stateful_set_status->observed_generation
    if(v1_stateful_set_status->observed_generation) {
    if(cJSON_AddNumberToObject(item, "observedGeneration", *v1_stateful_set_status->observed_generation) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_stateful_set_status->ready_replicas
    if(v1_stateful_set_status->ready_replicas) {
    if(cJSON_AddNumberToObject(item, "readyReplicas", *v1_stateful_set_status->ready_replicas) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_stateful_set_status->replicas
    if (!v1_stateful_set_status->replicas) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "replicas", *v1_stateful_set_status->replicas) == NULL) {
    goto fail; //Numeric
    }


    // v1_stateful_set_status->update_revision
    if(v1_stateful_set_status->update_revision) {
    if(cJSON_AddStringToObject(item, "updateRevision", v1_stateful_set_status->update_revision) == NULL) {
    goto fail; //String
    }
    }


    // v1_stateful_set_status->updated_replicas
    if(v1_stateful_set_status->updated_replicas) {
    if(cJSON_AddNumberToObject(item, "updatedReplicas", *v1_stateful_set_status->updated_replicas) == NULL) {
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

v1_stateful_set_status_t *v1_stateful_set_status_parseFromJSON(cJSON *v1_stateful_set_statusJSON){

    v1_stateful_set_status_t *v1_stateful_set_status_local_var = NULL;

    // define the local variable for v1_stateful_set_status->available_replicas
    int *available_replicas_local_var = NULL;

    // define the local variable for v1_stateful_set_status->collision_count
    int *collision_count_local_var = NULL;

    // define the local list for v1_stateful_set_status->conditions
    list_t *conditionsList = NULL;

    // define the local variable for v1_stateful_set_status->current_replicas
    int *current_replicas_local_var = NULL;

    char *current_revision_local_str = NULL;

    // define the local variable for v1_stateful_set_status->observed_generation
    long *observed_generation_local_var = NULL;

    // define the local variable for v1_stateful_set_status->ready_replicas
    int *ready_replicas_local_var = NULL;

    // define the local variable for v1_stateful_set_status->replicas
    int *replicas_local_var = NULL;

    char *update_revision_local_str = NULL;

    // define the local variable for v1_stateful_set_status->updated_replicas
    int *updated_replicas_local_var = NULL;

    // v1_stateful_set_status->available_replicas
    cJSON *available_replicas = cJSON_GetObjectItemCaseSensitive(v1_stateful_set_statusJSON, "availableReplicas");
    if (cJSON_IsNull(available_replicas)) {
        available_replicas = NULL;
    }
    if (available_replicas) { 
    if(!cJSON_IsNumber(available_replicas))
    {
    goto end; //Numeric
    }
    available_replicas_local_var = malloc(sizeof(int));
    if(!available_replicas_local_var)
    {
        goto end;
    }
    *available_replicas_local_var = available_replicas->valuedouble;
    }

    // v1_stateful_set_status->collision_count
    cJSON *collision_count = cJSON_GetObjectItemCaseSensitive(v1_stateful_set_statusJSON, "collisionCount");
    if (cJSON_IsNull(collision_count)) {
        collision_count = NULL;
    }
    if (collision_count) { 
    if(!cJSON_IsNumber(collision_count))
    {
    goto end; //Numeric
    }
    collision_count_local_var = malloc(sizeof(int));
    if(!collision_count_local_var)
    {
        goto end;
    }
    *collision_count_local_var = collision_count->valuedouble;
    }

    // v1_stateful_set_status->conditions
    cJSON *conditions = cJSON_GetObjectItemCaseSensitive(v1_stateful_set_statusJSON, "conditions");
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
        v1_stateful_set_condition_t *conditionsItem = v1_stateful_set_condition_parseFromJSON(conditions_local_nonprimitive);

        list_addElement(conditionsList, conditionsItem);
    }
    }

    // v1_stateful_set_status->current_replicas
    cJSON *current_replicas = cJSON_GetObjectItemCaseSensitive(v1_stateful_set_statusJSON, "currentReplicas");
    if (cJSON_IsNull(current_replicas)) {
        current_replicas = NULL;
    }
    if (current_replicas) { 
    if(!cJSON_IsNumber(current_replicas))
    {
    goto end; //Numeric
    }
    current_replicas_local_var = malloc(sizeof(int));
    if(!current_replicas_local_var)
    {
        goto end;
    }
    *current_replicas_local_var = current_replicas->valuedouble;
    }

    // v1_stateful_set_status->current_revision
    cJSON *current_revision = cJSON_GetObjectItemCaseSensitive(v1_stateful_set_statusJSON, "currentRevision");
    if (cJSON_IsNull(current_revision)) {
        current_revision = NULL;
    }
    if (current_revision) { 
    if(!cJSON_IsString(current_revision) && !cJSON_IsNull(current_revision))
    {
    goto end; //String
    }
    }

    // v1_stateful_set_status->observed_generation
    cJSON *observed_generation = cJSON_GetObjectItemCaseSensitive(v1_stateful_set_statusJSON, "observedGeneration");
    if (cJSON_IsNull(observed_generation)) {
        observed_generation = NULL;
    }
    if (observed_generation) { 
    if(!cJSON_IsNumber(observed_generation))
    {
    goto end; //Numeric
    }
    observed_generation_local_var = malloc(sizeof(long));
    if(!observed_generation_local_var)
    {
        goto end;
    }
    *observed_generation_local_var = observed_generation->valuedouble;
    }

    // v1_stateful_set_status->ready_replicas
    cJSON *ready_replicas = cJSON_GetObjectItemCaseSensitive(v1_stateful_set_statusJSON, "readyReplicas");
    if (cJSON_IsNull(ready_replicas)) {
        ready_replicas = NULL;
    }
    if (ready_replicas) { 
    if(!cJSON_IsNumber(ready_replicas))
    {
    goto end; //Numeric
    }
    ready_replicas_local_var = malloc(sizeof(int));
    if(!ready_replicas_local_var)
    {
        goto end;
    }
    *ready_replicas_local_var = ready_replicas->valuedouble;
    }

    // v1_stateful_set_status->replicas
    cJSON *replicas = cJSON_GetObjectItemCaseSensitive(v1_stateful_set_statusJSON, "replicas");
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
    replicas_local_var = malloc(sizeof(int));
    if(!replicas_local_var)
    {
        goto end;
    }
    *replicas_local_var = replicas->valuedouble;

    // v1_stateful_set_status->update_revision
    cJSON *update_revision = cJSON_GetObjectItemCaseSensitive(v1_stateful_set_statusJSON, "updateRevision");
    if (cJSON_IsNull(update_revision)) {
        update_revision = NULL;
    }
    if (update_revision) { 
    if(!cJSON_IsString(update_revision) && !cJSON_IsNull(update_revision))
    {
    goto end; //String
    }
    }

    // v1_stateful_set_status->updated_replicas
    cJSON *updated_replicas = cJSON_GetObjectItemCaseSensitive(v1_stateful_set_statusJSON, "updatedReplicas");
    if (cJSON_IsNull(updated_replicas)) {
        updated_replicas = NULL;
    }
    if (updated_replicas) { 
    if(!cJSON_IsNumber(updated_replicas))
    {
    goto end; //Numeric
    }
    updated_replicas_local_var = malloc(sizeof(int));
    if(!updated_replicas_local_var)
    {
        goto end;
    }
    *updated_replicas_local_var = updated_replicas->valuedouble;
    }


    if (current_revision && !cJSON_IsNull(current_revision)) current_revision_local_str = strdup(current_revision->valuestring);
    if (update_revision && !cJSON_IsNull(update_revision)) update_revision_local_str = strdup(update_revision->valuestring);

    v1_stateful_set_status_local_var = v1_stateful_set_status_create_internal (
        available_replicas_local_var,
        collision_count_local_var,
        conditions ? conditionsList : NULL,
        current_replicas_local_var,
        current_revision_local_str,
        observed_generation_local_var,
        ready_replicas_local_var,
        replicas_local_var,
        update_revision_local_str,
        updated_replicas_local_var
        );

    if (!v1_stateful_set_status_local_var) {
        goto end;
    }

    return v1_stateful_set_status_local_var;
end:
    if (available_replicas_local_var) {
        free(available_replicas_local_var);
        available_replicas_local_var = NULL;
    }
    if (collision_count_local_var) {
        free(collision_count_local_var);
        collision_count_local_var = NULL;
    }
    if (conditionsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, conditionsList) {
            v1_stateful_set_condition_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(conditionsList);
        conditionsList = NULL;
    }
    if (current_replicas_local_var) {
        free(current_replicas_local_var);
        current_replicas_local_var = NULL;
    }
    if (current_revision_local_str) {
        free(current_revision_local_str);
        current_revision_local_str = NULL;
    }
    if (observed_generation_local_var) {
        free(observed_generation_local_var);
        observed_generation_local_var = NULL;
    }
    if (ready_replicas_local_var) {
        free(ready_replicas_local_var);
        ready_replicas_local_var = NULL;
    }
    if (replicas_local_var) {
        free(replicas_local_var);
        replicas_local_var = NULL;
    }
    if (update_revision_local_str) {
        free(update_revision_local_str);
        update_revision_local_str = NULL;
    }
    if (updated_replicas_local_var) {
        free(updated_replicas_local_var);
        updated_replicas_local_var = NULL;
    }
    return NULL;

}
