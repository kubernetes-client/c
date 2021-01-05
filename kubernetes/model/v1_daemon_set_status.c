#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_daemon_set_status.h"



v1_daemon_set_status_t *v1_daemon_set_status_create(
    int collision_count,
    list_t *conditions,
    int current_number_scheduled,
    int desired_number_scheduled,
    int number_available,
    int number_misscheduled,
    int number_ready,
    int number_unavailable,
    long observed_generation,
    int updated_number_scheduled
    ) {
    v1_daemon_set_status_t *v1_daemon_set_status_local_var = malloc(sizeof(v1_daemon_set_status_t));
    if (!v1_daemon_set_status_local_var) {
        return NULL;
    }
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


void v1_daemon_set_status_free(v1_daemon_set_status_t *v1_daemon_set_status) {
    if(NULL == v1_daemon_set_status){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_daemon_set_status->conditions) {
        list_ForEach(listEntry, v1_daemon_set_status->conditions) {
            v1_daemon_set_condition_free(listEntry->data);
        }
        list_free(v1_daemon_set_status->conditions);
        v1_daemon_set_status->conditions = NULL;
    }
    free(v1_daemon_set_status);
}

cJSON *v1_daemon_set_status_convertToJSON(v1_daemon_set_status_t *v1_daemon_set_status) {
    cJSON *item = cJSON_CreateObject();

    // v1_daemon_set_status->collision_count
    if(v1_daemon_set_status->collision_count) { 
    if(cJSON_AddNumberToObject(item, "collisionCount", v1_daemon_set_status->collision_count) == NULL) {
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
    
    if(cJSON_AddNumberToObject(item, "currentNumberScheduled", v1_daemon_set_status->current_number_scheduled) == NULL) {
    goto fail; //Numeric
    }


    // v1_daemon_set_status->desired_number_scheduled
    if (!v1_daemon_set_status->desired_number_scheduled) {
        goto fail;
    }
    
    if(cJSON_AddNumberToObject(item, "desiredNumberScheduled", v1_daemon_set_status->desired_number_scheduled) == NULL) {
    goto fail; //Numeric
    }


    // v1_daemon_set_status->number_available
    if(v1_daemon_set_status->number_available) { 
    if(cJSON_AddNumberToObject(item, "numberAvailable", v1_daemon_set_status->number_available) == NULL) {
    goto fail; //Numeric
    }
     } 


    // v1_daemon_set_status->number_misscheduled
    if (!v1_daemon_set_status->number_misscheduled) {
        goto fail;
    }
    
    if(cJSON_AddNumberToObject(item, "numberMisscheduled", v1_daemon_set_status->number_misscheduled) == NULL) {
    goto fail; //Numeric
    }


    // v1_daemon_set_status->number_ready
    if (!v1_daemon_set_status->number_ready) {
        goto fail;
    }
    
    if(cJSON_AddNumberToObject(item, "numberReady", v1_daemon_set_status->number_ready) == NULL) {
    goto fail; //Numeric
    }


    // v1_daemon_set_status->number_unavailable
    if(v1_daemon_set_status->number_unavailable) { 
    if(cJSON_AddNumberToObject(item, "numberUnavailable", v1_daemon_set_status->number_unavailable) == NULL) {
    goto fail; //Numeric
    }
     } 


    // v1_daemon_set_status->observed_generation
    if(v1_daemon_set_status->observed_generation) { 
    if(cJSON_AddNumberToObject(item, "observedGeneration", v1_daemon_set_status->observed_generation) == NULL) {
    goto fail; //Numeric
    }
     } 


    // v1_daemon_set_status->updated_number_scheduled
    if(v1_daemon_set_status->updated_number_scheduled) { 
    if(cJSON_AddNumberToObject(item, "updatedNumberScheduled", v1_daemon_set_status->updated_number_scheduled) == NULL) {
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

    // v1_daemon_set_status->collision_count
    cJSON *collision_count = cJSON_GetObjectItemCaseSensitive(v1_daemon_set_statusJSON, "collisionCount");
    if (collision_count) { 
    if(!cJSON_IsNumber(collision_count))
    {
    goto end; //Numeric
    }
    }

    // v1_daemon_set_status->conditions
    cJSON *conditions = cJSON_GetObjectItemCaseSensitive(v1_daemon_set_statusJSON, "conditions");
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
        v1_daemon_set_condition_t *conditionsItem = v1_daemon_set_condition_parseFromJSON(conditions_local_nonprimitive);

        list_addElement(conditionsList, conditionsItem);
    }
    }

    // v1_daemon_set_status->current_number_scheduled
    cJSON *current_number_scheduled = cJSON_GetObjectItemCaseSensitive(v1_daemon_set_statusJSON, "currentNumberScheduled");
    if (!current_number_scheduled) {
        goto end;
    }

    
    if(!cJSON_IsNumber(current_number_scheduled))
    {
    goto end; //Numeric
    }

    // v1_daemon_set_status->desired_number_scheduled
    cJSON *desired_number_scheduled = cJSON_GetObjectItemCaseSensitive(v1_daemon_set_statusJSON, "desiredNumberScheduled");
    if (!desired_number_scheduled) {
        goto end;
    }

    
    if(!cJSON_IsNumber(desired_number_scheduled))
    {
    goto end; //Numeric
    }

    // v1_daemon_set_status->number_available
    cJSON *number_available = cJSON_GetObjectItemCaseSensitive(v1_daemon_set_statusJSON, "numberAvailable");
    if (number_available) { 
    if(!cJSON_IsNumber(number_available))
    {
    goto end; //Numeric
    }
    }

    // v1_daemon_set_status->number_misscheduled
    cJSON *number_misscheduled = cJSON_GetObjectItemCaseSensitive(v1_daemon_set_statusJSON, "numberMisscheduled");
    if (!number_misscheduled) {
        goto end;
    }

    
    if(!cJSON_IsNumber(number_misscheduled))
    {
    goto end; //Numeric
    }

    // v1_daemon_set_status->number_ready
    cJSON *number_ready = cJSON_GetObjectItemCaseSensitive(v1_daemon_set_statusJSON, "numberReady");
    if (!number_ready) {
        goto end;
    }

    
    if(!cJSON_IsNumber(number_ready))
    {
    goto end; //Numeric
    }

    // v1_daemon_set_status->number_unavailable
    cJSON *number_unavailable = cJSON_GetObjectItemCaseSensitive(v1_daemon_set_statusJSON, "numberUnavailable");
    if (number_unavailable) { 
    if(!cJSON_IsNumber(number_unavailable))
    {
    goto end; //Numeric
    }
    }

    // v1_daemon_set_status->observed_generation
    cJSON *observed_generation = cJSON_GetObjectItemCaseSensitive(v1_daemon_set_statusJSON, "observedGeneration");
    if (observed_generation) { 
    if(!cJSON_IsNumber(observed_generation))
    {
    goto end; //Numeric
    }
    }

    // v1_daemon_set_status->updated_number_scheduled
    cJSON *updated_number_scheduled = cJSON_GetObjectItemCaseSensitive(v1_daemon_set_statusJSON, "updatedNumberScheduled");
    if (updated_number_scheduled) { 
    if(!cJSON_IsNumber(updated_number_scheduled))
    {
    goto end; //Numeric
    }
    }


    v1_daemon_set_status_local_var = v1_daemon_set_status_create (
        collision_count ? collision_count->valuedouble : 0,
        conditions ? conditionsList : NULL,
        current_number_scheduled->valuedouble,
        desired_number_scheduled->valuedouble,
        number_available ? number_available->valuedouble : 0,
        number_misscheduled->valuedouble,
        number_ready->valuedouble,
        number_unavailable ? number_unavailable->valuedouble : 0,
        observed_generation ? observed_generation->valuedouble : 0,
        updated_number_scheduled ? updated_number_scheduled->valuedouble : 0
        );

    return v1_daemon_set_status_local_var;
end:
    return NULL;

}
