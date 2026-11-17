#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_daemon_set_status.h"



static v1_daemon_set_status_t *v1_daemon_set_status_create_internal(
    int *collision_count,
    list_t *conditions,
    int *current_number_scheduled,
    int *desired_number_scheduled,
    int *number_available,
    int *number_misscheduled,
    int *number_ready,
    int *number_unavailable,
    long *observed_generation,
    int *updated_number_scheduled
    ) {
    v1_daemon_set_status_t *v1_daemon_set_status_local_var = malloc(sizeof(v1_daemon_set_status_t));
    if (!v1_daemon_set_status_local_var) {
        return NULL;
    }
    memset(v1_daemon_set_status_local_var, 0, sizeof(v1_daemon_set_status_t));
    v1_daemon_set_status_local_var->_library_owned = 1;
    v1_daemon_set_status_local_var->collision_count = collision_count;
    v1_daemon_set_status_local_var->conditions = conditions;
    v1_daemon_set_status_local_var->current_number_scheduled = current_number_scheduled;
    v1_daemon_set_status_local_var->desired_number_scheduled = desired_number_scheduled;
    v1_daemon_set_status_local_var->number_available = number_available;
    v1_daemon_set_status_local_var->number_misscheduled = number_misscheduled;
    v1_daemon_set_status_local_var->number_ready = number_ready;
    v1_daemon_set_status_local_var->number_unavailable = number_unavailable;
    v1_daemon_set_status_local_var->observed_generation = observed_generation;
    v1_daemon_set_status_local_var->updated_number_scheduled = updated_number_scheduled;
    return v1_daemon_set_status_local_var;
}

__attribute__((deprecated)) v1_daemon_set_status_t *v1_daemon_set_status_create(
    int *collision_count,
    list_t *conditions,
    int *current_number_scheduled,
    int *desired_number_scheduled,
    int *number_available,
    int *number_misscheduled,
    int *number_ready,
    int *number_unavailable,
    long *observed_generation,
    int *updated_number_scheduled
    ) {
    int *collision_count_copy = NULL;
    if (collision_count) {
        collision_count_copy = malloc(sizeof(int));
        if (collision_count_copy) *collision_count_copy = *collision_count;
    }
    int *current_number_scheduled_copy = NULL;
    if (current_number_scheduled) {
        current_number_scheduled_copy = malloc(sizeof(int));
        if (current_number_scheduled_copy) *current_number_scheduled_copy = *current_number_scheduled;
    }
    int *desired_number_scheduled_copy = NULL;
    if (desired_number_scheduled) {
        desired_number_scheduled_copy = malloc(sizeof(int));
        if (desired_number_scheduled_copy) *desired_number_scheduled_copy = *desired_number_scheduled;
    }
    int *number_available_copy = NULL;
    if (number_available) {
        number_available_copy = malloc(sizeof(int));
        if (number_available_copy) *number_available_copy = *number_available;
    }
    int *number_misscheduled_copy = NULL;
    if (number_misscheduled) {
        number_misscheduled_copy = malloc(sizeof(int));
        if (number_misscheduled_copy) *number_misscheduled_copy = *number_misscheduled;
    }
    int *number_ready_copy = NULL;
    if (number_ready) {
        number_ready_copy = malloc(sizeof(int));
        if (number_ready_copy) *number_ready_copy = *number_ready;
    }
    int *number_unavailable_copy = NULL;
    if (number_unavailable) {
        number_unavailable_copy = malloc(sizeof(int));
        if (number_unavailable_copy) *number_unavailable_copy = *number_unavailable;
    }
    long *observed_generation_copy = NULL;
    if (observed_generation) {
        observed_generation_copy = malloc(sizeof(long));
        if (observed_generation_copy) *observed_generation_copy = *observed_generation;
    }
    int *updated_number_scheduled_copy = NULL;
    if (updated_number_scheduled) {
        updated_number_scheduled_copy = malloc(sizeof(int));
        if (updated_number_scheduled_copy) *updated_number_scheduled_copy = *updated_number_scheduled;
    }
    v1_daemon_set_status_t *result = v1_daemon_set_status_create_internal (
        collision_count_copy,
        conditions,
        current_number_scheduled_copy,
        desired_number_scheduled_copy,
        number_available_copy,
        number_misscheduled_copy,
        number_ready_copy,
        number_unavailable_copy,
        observed_generation_copy,
        updated_number_scheduled_copy
        );
    if (!result) {
        free(collision_count_copy);
        free(current_number_scheduled_copy);
        free(desired_number_scheduled_copy);
        free(number_available_copy);
        free(number_misscheduled_copy);
        free(number_ready_copy);
        free(number_unavailable_copy);
        free(observed_generation_copy);
        free(updated_number_scheduled_copy);
    }
    return result;
}

void v1_daemon_set_status_free(v1_daemon_set_status_t *v1_daemon_set_status) {
    if(NULL == v1_daemon_set_status){
        return ;
    }
    if(v1_daemon_set_status->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_daemon_set_status_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_daemon_set_status->collision_count) {
        free(v1_daemon_set_status->collision_count);
        v1_daemon_set_status->collision_count = NULL;
    }
    if (v1_daemon_set_status->conditions) {
        list_ForEach(listEntry, v1_daemon_set_status->conditions) {
            v1_daemon_set_condition_free(listEntry->data);
        }
        list_freeList(v1_daemon_set_status->conditions);
        v1_daemon_set_status->conditions = NULL;
    }
    if (v1_daemon_set_status->current_number_scheduled) {
        free(v1_daemon_set_status->current_number_scheduled);
        v1_daemon_set_status->current_number_scheduled = NULL;
    }
    if (v1_daemon_set_status->desired_number_scheduled) {
        free(v1_daemon_set_status->desired_number_scheduled);
        v1_daemon_set_status->desired_number_scheduled = NULL;
    }
    if (v1_daemon_set_status->number_available) {
        free(v1_daemon_set_status->number_available);
        v1_daemon_set_status->number_available = NULL;
    }
    if (v1_daemon_set_status->number_misscheduled) {
        free(v1_daemon_set_status->number_misscheduled);
        v1_daemon_set_status->number_misscheduled = NULL;
    }
    if (v1_daemon_set_status->number_ready) {
        free(v1_daemon_set_status->number_ready);
        v1_daemon_set_status->number_ready = NULL;
    }
    if (v1_daemon_set_status->number_unavailable) {
        free(v1_daemon_set_status->number_unavailable);
        v1_daemon_set_status->number_unavailable = NULL;
    }
    if (v1_daemon_set_status->observed_generation) {
        free(v1_daemon_set_status->observed_generation);
        v1_daemon_set_status->observed_generation = NULL;
    }
    if (v1_daemon_set_status->updated_number_scheduled) {
        free(v1_daemon_set_status->updated_number_scheduled);
        v1_daemon_set_status->updated_number_scheduled = NULL;
    }
    free(v1_daemon_set_status);
}

cJSON *v1_daemon_set_status_convertToJSON(v1_daemon_set_status_t *v1_daemon_set_status) {
    cJSON *item = cJSON_CreateObject();

    // v1_daemon_set_status->collision_count
    if(v1_daemon_set_status->collision_count) {
    if(cJSON_AddNumberToObject(item, "collisionCount", *v1_daemon_set_status->collision_count) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_daemon_set_status->conditions
    if(v1_daemon_set_status->conditions) {
    cJSON *conditions = cJSON_AddArrayToObject(item, "conditions");
    if(conditions == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *conditionsListEntry;
    if (v1_daemon_set_status->conditions) {
    list_ForEach(conditionsListEntry, v1_daemon_set_status->conditions) {
    cJSON *itemLocal = v1_daemon_set_condition_convertToJSON(conditionsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(conditions, itemLocal);
    }
    }
    }


    // v1_daemon_set_status->current_number_scheduled
    if (!v1_daemon_set_status->current_number_scheduled) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "currentNumberScheduled", *v1_daemon_set_status->current_number_scheduled) == NULL) {
    goto fail; //Numeric
    }


    // v1_daemon_set_status->desired_number_scheduled
    if (!v1_daemon_set_status->desired_number_scheduled) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "desiredNumberScheduled", *v1_daemon_set_status->desired_number_scheduled) == NULL) {
    goto fail; //Numeric
    }


    // v1_daemon_set_status->number_available
    if(v1_daemon_set_status->number_available) {
    if(cJSON_AddNumberToObject(item, "numberAvailable", *v1_daemon_set_status->number_available) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_daemon_set_status->number_misscheduled
    if (!v1_daemon_set_status->number_misscheduled) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "numberMisscheduled", *v1_daemon_set_status->number_misscheduled) == NULL) {
    goto fail; //Numeric
    }


    // v1_daemon_set_status->number_ready
    if (!v1_daemon_set_status->number_ready) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "numberReady", *v1_daemon_set_status->number_ready) == NULL) {
    goto fail; //Numeric
    }


    // v1_daemon_set_status->number_unavailable
    if(v1_daemon_set_status->number_unavailable) {
    if(cJSON_AddNumberToObject(item, "numberUnavailable", *v1_daemon_set_status->number_unavailable) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_daemon_set_status->observed_generation
    if(v1_daemon_set_status->observed_generation) {
    if(cJSON_AddNumberToObject(item, "observedGeneration", *v1_daemon_set_status->observed_generation) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_daemon_set_status->updated_number_scheduled
    if(v1_daemon_set_status->updated_number_scheduled) {
    if(cJSON_AddNumberToObject(item, "updatedNumberScheduled", *v1_daemon_set_status->updated_number_scheduled) == NULL) {
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

v1_daemon_set_status_t *v1_daemon_set_status_parseFromJSON(cJSON *v1_daemon_set_statusJSON){

    v1_daemon_set_status_t *v1_daemon_set_status_local_var = NULL;

    // define the local variable for v1_daemon_set_status->collision_count
    int *collision_count_local_var = NULL;

    // define the local list for v1_daemon_set_status->conditions
    list_t *conditionsList = NULL;

    // define the local variable for v1_daemon_set_status->current_number_scheduled
    int *current_number_scheduled_local_var = NULL;

    // define the local variable for v1_daemon_set_status->desired_number_scheduled
    int *desired_number_scheduled_local_var = NULL;

    // define the local variable for v1_daemon_set_status->number_available
    int *number_available_local_var = NULL;

    // define the local variable for v1_daemon_set_status->number_misscheduled
    int *number_misscheduled_local_var = NULL;

    // define the local variable for v1_daemon_set_status->number_ready
    int *number_ready_local_var = NULL;

    // define the local variable for v1_daemon_set_status->number_unavailable
    int *number_unavailable_local_var = NULL;

    // define the local variable for v1_daemon_set_status->observed_generation
    long *observed_generation_local_var = NULL;

    // define the local variable for v1_daemon_set_status->updated_number_scheduled
    int *updated_number_scheduled_local_var = NULL;

    // v1_daemon_set_status->collision_count
    cJSON *collision_count = cJSON_GetObjectItemCaseSensitive(v1_daemon_set_statusJSON, "collisionCount");
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

    // v1_daemon_set_status->conditions
    cJSON *conditions = cJSON_GetObjectItemCaseSensitive(v1_daemon_set_statusJSON, "conditions");
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
        v1_daemon_set_condition_t *conditionsItem = v1_daemon_set_condition_parseFromJSON(conditions_local_nonprimitive);

        list_addElement(conditionsList, conditionsItem);
    }
    }

    // v1_daemon_set_status->current_number_scheduled
    cJSON *current_number_scheduled = cJSON_GetObjectItemCaseSensitive(v1_daemon_set_statusJSON, "currentNumberScheduled");
    if (cJSON_IsNull(current_number_scheduled)) {
        current_number_scheduled = NULL;
    }
    if (!current_number_scheduled) {
        goto end;
    }

    
    if(!cJSON_IsNumber(current_number_scheduled))
    {
    goto end; //Numeric
    }
    current_number_scheduled_local_var = malloc(sizeof(int));
    if(!current_number_scheduled_local_var)
    {
        goto end;
    }
    *current_number_scheduled_local_var = current_number_scheduled->valuedouble;

    // v1_daemon_set_status->desired_number_scheduled
    cJSON *desired_number_scheduled = cJSON_GetObjectItemCaseSensitive(v1_daemon_set_statusJSON, "desiredNumberScheduled");
    if (cJSON_IsNull(desired_number_scheduled)) {
        desired_number_scheduled = NULL;
    }
    if (!desired_number_scheduled) {
        goto end;
    }

    
    if(!cJSON_IsNumber(desired_number_scheduled))
    {
    goto end; //Numeric
    }
    desired_number_scheduled_local_var = malloc(sizeof(int));
    if(!desired_number_scheduled_local_var)
    {
        goto end;
    }
    *desired_number_scheduled_local_var = desired_number_scheduled->valuedouble;

    // v1_daemon_set_status->number_available
    cJSON *number_available = cJSON_GetObjectItemCaseSensitive(v1_daemon_set_statusJSON, "numberAvailable");
    if (cJSON_IsNull(number_available)) {
        number_available = NULL;
    }
    if (number_available) { 
    if(!cJSON_IsNumber(number_available))
    {
    goto end; //Numeric
    }
    number_available_local_var = malloc(sizeof(int));
    if(!number_available_local_var)
    {
        goto end;
    }
    *number_available_local_var = number_available->valuedouble;
    }

    // v1_daemon_set_status->number_misscheduled
    cJSON *number_misscheduled = cJSON_GetObjectItemCaseSensitive(v1_daemon_set_statusJSON, "numberMisscheduled");
    if (cJSON_IsNull(number_misscheduled)) {
        number_misscheduled = NULL;
    }
    if (!number_misscheduled) {
        goto end;
    }

    
    if(!cJSON_IsNumber(number_misscheduled))
    {
    goto end; //Numeric
    }
    number_misscheduled_local_var = malloc(sizeof(int));
    if(!number_misscheduled_local_var)
    {
        goto end;
    }
    *number_misscheduled_local_var = number_misscheduled->valuedouble;

    // v1_daemon_set_status->number_ready
    cJSON *number_ready = cJSON_GetObjectItemCaseSensitive(v1_daemon_set_statusJSON, "numberReady");
    if (cJSON_IsNull(number_ready)) {
        number_ready = NULL;
    }
    if (!number_ready) {
        goto end;
    }

    
    if(!cJSON_IsNumber(number_ready))
    {
    goto end; //Numeric
    }
    number_ready_local_var = malloc(sizeof(int));
    if(!number_ready_local_var)
    {
        goto end;
    }
    *number_ready_local_var = number_ready->valuedouble;

    // v1_daemon_set_status->number_unavailable
    cJSON *number_unavailable = cJSON_GetObjectItemCaseSensitive(v1_daemon_set_statusJSON, "numberUnavailable");
    if (cJSON_IsNull(number_unavailable)) {
        number_unavailable = NULL;
    }
    if (number_unavailable) { 
    if(!cJSON_IsNumber(number_unavailable))
    {
    goto end; //Numeric
    }
    number_unavailable_local_var = malloc(sizeof(int));
    if(!number_unavailable_local_var)
    {
        goto end;
    }
    *number_unavailable_local_var = number_unavailable->valuedouble;
    }

    // v1_daemon_set_status->observed_generation
    cJSON *observed_generation = cJSON_GetObjectItemCaseSensitive(v1_daemon_set_statusJSON, "observedGeneration");
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

    // v1_daemon_set_status->updated_number_scheduled
    cJSON *updated_number_scheduled = cJSON_GetObjectItemCaseSensitive(v1_daemon_set_statusJSON, "updatedNumberScheduled");
    if (cJSON_IsNull(updated_number_scheduled)) {
        updated_number_scheduled = NULL;
    }
    if (updated_number_scheduled) { 
    if(!cJSON_IsNumber(updated_number_scheduled))
    {
    goto end; //Numeric
    }
    updated_number_scheduled_local_var = malloc(sizeof(int));
    if(!updated_number_scheduled_local_var)
    {
        goto end;
    }
    *updated_number_scheduled_local_var = updated_number_scheduled->valuedouble;
    }



    v1_daemon_set_status_local_var = v1_daemon_set_status_create_internal (
        collision_count_local_var,
        conditions ? conditionsList : NULL,
        current_number_scheduled_local_var,
        desired_number_scheduled_local_var,
        number_available_local_var,
        number_misscheduled_local_var,
        number_ready_local_var,
        number_unavailable_local_var,
        observed_generation_local_var,
        updated_number_scheduled_local_var
        );

    if (!v1_daemon_set_status_local_var) {
        goto end;
    }

    return v1_daemon_set_status_local_var;
end:
    if (collision_count_local_var) {
        free(collision_count_local_var);
        collision_count_local_var = NULL;
    }
    if (conditionsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, conditionsList) {
            v1_daemon_set_condition_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(conditionsList);
        conditionsList = NULL;
    }
    if (current_number_scheduled_local_var) {
        free(current_number_scheduled_local_var);
        current_number_scheduled_local_var = NULL;
    }
    if (desired_number_scheduled_local_var) {
        free(desired_number_scheduled_local_var);
        desired_number_scheduled_local_var = NULL;
    }
    if (number_available_local_var) {
        free(number_available_local_var);
        number_available_local_var = NULL;
    }
    if (number_misscheduled_local_var) {
        free(number_misscheduled_local_var);
        number_misscheduled_local_var = NULL;
    }
    if (number_ready_local_var) {
        free(number_ready_local_var);
        number_ready_local_var = NULL;
    }
    if (number_unavailable_local_var) {
        free(number_unavailable_local_var);
        number_unavailable_local_var = NULL;
    }
    if (observed_generation_local_var) {
        free(observed_generation_local_var);
        observed_generation_local_var = NULL;
    }
    if (updated_number_scheduled_local_var) {
        free(updated_number_scheduled_local_var);
        updated_number_scheduled_local_var = NULL;
    }
    return NULL;

}
