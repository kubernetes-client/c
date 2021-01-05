#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v2alpha1_cron_job_status.h"



v2alpha1_cron_job_status_t *v2alpha1_cron_job_status_create(
    list_t *active,
    char *last_schedule_time
    ) {
    v2alpha1_cron_job_status_t *v2alpha1_cron_job_status_local_var = malloc(sizeof(v2alpha1_cron_job_status_t));
    if (!v2alpha1_cron_job_status_local_var) {
        return NULL;
    }
    v2alpha1_cron_job_status_local_var->active = active;
    v2alpha1_cron_job_status_local_var->last_schedule_time = last_schedule_time;

    return v2alpha1_cron_job_status_local_var;
}


void v2alpha1_cron_job_status_free(v2alpha1_cron_job_status_t *v2alpha1_cron_job_status) {
    if(NULL == v2alpha1_cron_job_status){
        return ;
    }
    listEntry_t *listEntry;
    if (v2alpha1_cron_job_status->active) {
        list_ForEach(listEntry, v2alpha1_cron_job_status->active) {
            v1_object_reference_free(listEntry->data);
        }
        list_free(v2alpha1_cron_job_status->active);
        v2alpha1_cron_job_status->active = NULL;
    }
    if (v2alpha1_cron_job_status->last_schedule_time) {
        free(v2alpha1_cron_job_status->last_schedule_time);
        v2alpha1_cron_job_status->last_schedule_time = NULL;
    }
    free(v2alpha1_cron_job_status);
}

cJSON *v2alpha1_cron_job_status_convertToJSON(v2alpha1_cron_job_status_t *v2alpha1_cron_job_status) {
    cJSON *item = cJSON_CreateObject();

    // v2alpha1_cron_job_status->active
    if(v2alpha1_cron_job_status->active) { 
    cJSON *active = cJSON_AddArrayToObject(item, "active");
    if(active == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *activeListEntry;
    if (v2alpha1_cron_job_status->active) {
    list_ForEach(activeListEntry, v2alpha1_cron_job_status->active) {
    cJSON *itemLocal = v1_object_reference_convertToJSON(activeListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(active, itemLocal);
    }
    }
     } 


    // v2alpha1_cron_job_status->last_schedule_time
    if(v2alpha1_cron_job_status->last_schedule_time) { 
    if(cJSON_AddStringToObject(item, "lastScheduleTime", v2alpha1_cron_job_status->last_schedule_time) == NULL) {
    goto fail; //Date-Time
    }
     } 

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v2alpha1_cron_job_status_t *v2alpha1_cron_job_status_parseFromJSON(cJSON *v2alpha1_cron_job_statusJSON){

    v2alpha1_cron_job_status_t *v2alpha1_cron_job_status_local_var = NULL;

    // v2alpha1_cron_job_status->active
    cJSON *active = cJSON_GetObjectItemCaseSensitive(v2alpha1_cron_job_statusJSON, "active");
    list_t *activeList;
    if (active) { 
    cJSON *active_local_nonprimitive;
    if(!cJSON_IsArray(active)){
        goto end; //nonprimitive container
    }

    activeList = list_create();

    cJSON_ArrayForEach(active_local_nonprimitive,active )
    {
        if(!cJSON_IsObject(active_local_nonprimitive)){
            goto end;
        }
        v1_object_reference_t *activeItem = v1_object_reference_parseFromJSON(active_local_nonprimitive);

        list_addElement(activeList, activeItem);
    }
    }

    // v2alpha1_cron_job_status->last_schedule_time
    cJSON *last_schedule_time = cJSON_GetObjectItemCaseSensitive(v2alpha1_cron_job_statusJSON, "lastScheduleTime");
    if (last_schedule_time) { 
    if(!cJSON_IsString(last_schedule_time))
    {
    goto end; //DateTime
    }
    }


    v2alpha1_cron_job_status_local_var = v2alpha1_cron_job_status_create (
        active ? activeList : NULL,
        last_schedule_time ? strdup(last_schedule_time->valuestring) : NULL
        );

    return v2alpha1_cron_job_status_local_var;
end:
    return NULL;

}
