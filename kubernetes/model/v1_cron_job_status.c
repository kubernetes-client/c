#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_cron_job_status.h"



static v1_cron_job_status_t *v1_cron_job_status_create_internal(
    list_t *active,
    char *last_schedule_time,
    char *last_successful_time
    ) {
    v1_cron_job_status_t *v1_cron_job_status_local_var = malloc(sizeof(v1_cron_job_status_t));
    if (!v1_cron_job_status_local_var) {
        return NULL;
    }
    v1_cron_job_status_local_var->active = active;
    v1_cron_job_status_local_var->last_schedule_time = last_schedule_time;
    v1_cron_job_status_local_var->last_successful_time = last_successful_time;

    v1_cron_job_status_local_var->_library_owned = 1;
    return v1_cron_job_status_local_var;
}

__attribute__((deprecated)) v1_cron_job_status_t *v1_cron_job_status_create(
    list_t *active,
    char *last_schedule_time,
    char *last_successful_time
    ) {
    return v1_cron_job_status_create_internal (
        active,
        last_schedule_time,
        last_successful_time
        );
}

void v1_cron_job_status_free(v1_cron_job_status_t *v1_cron_job_status) {
    if(NULL == v1_cron_job_status){
        return ;
    }
    if(v1_cron_job_status->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_cron_job_status_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_cron_job_status->active) {
        list_ForEach(listEntry, v1_cron_job_status->active) {
            v1_object_reference_free(listEntry->data);
        }
        list_freeList(v1_cron_job_status->active);
        v1_cron_job_status->active = NULL;
    }
    if (v1_cron_job_status->last_schedule_time) {
        free(v1_cron_job_status->last_schedule_time);
        v1_cron_job_status->last_schedule_time = NULL;
    }
    if (v1_cron_job_status->last_successful_time) {
        free(v1_cron_job_status->last_successful_time);
        v1_cron_job_status->last_successful_time = NULL;
    }
    free(v1_cron_job_status);
}

cJSON *v1_cron_job_status_convertToJSON(v1_cron_job_status_t *v1_cron_job_status) {
    cJSON *item = cJSON_CreateObject();

    // v1_cron_job_status->active
    if(v1_cron_job_status->active) {
    cJSON *active = cJSON_AddArrayToObject(item, "active");
    if(active == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *activeListEntry;
    if (v1_cron_job_status->active) {
    list_ForEach(activeListEntry, v1_cron_job_status->active) {
    cJSON *itemLocal = v1_object_reference_convertToJSON(activeListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(active, itemLocal);
    }
    }
    }


    // v1_cron_job_status->last_schedule_time
    if(v1_cron_job_status->last_schedule_time) {
    if(cJSON_AddStringToObject(item, "lastScheduleTime", v1_cron_job_status->last_schedule_time) == NULL) {
    goto fail; //Date-Time
    }
    }


    // v1_cron_job_status->last_successful_time
    if(v1_cron_job_status->last_successful_time) {
    if(cJSON_AddStringToObject(item, "lastSuccessfulTime", v1_cron_job_status->last_successful_time) == NULL) {
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

v1_cron_job_status_t *v1_cron_job_status_parseFromJSON(cJSON *v1_cron_job_statusJSON){

    v1_cron_job_status_t *v1_cron_job_status_local_var = NULL;

    // define the local list for v1_cron_job_status->active
    list_t *activeList = NULL;

    // v1_cron_job_status->active
    cJSON *active = cJSON_GetObjectItemCaseSensitive(v1_cron_job_statusJSON, "active");
    if (cJSON_IsNull(active)) {
        active = NULL;
    }
    if (active) { 
    cJSON *active_local_nonprimitive = NULL;
    if(!cJSON_IsArray(active)){
        goto end; //nonprimitive container
    }

    activeList = list_createList();

    cJSON_ArrayForEach(active_local_nonprimitive,active )
    {
        if(!cJSON_IsObject(active_local_nonprimitive)){
            goto end;
        }
        v1_object_reference_t *activeItem = v1_object_reference_parseFromJSON(active_local_nonprimitive);

        list_addElement(activeList, activeItem);
    }
    }

    // v1_cron_job_status->last_schedule_time
    cJSON *last_schedule_time = cJSON_GetObjectItemCaseSensitive(v1_cron_job_statusJSON, "lastScheduleTime");
    if (cJSON_IsNull(last_schedule_time)) {
        last_schedule_time = NULL;
    }
    if (last_schedule_time) { 
    if(!cJSON_IsString(last_schedule_time) && !cJSON_IsNull(last_schedule_time))
    {
    goto end; //DateTime
    }
    }

    // v1_cron_job_status->last_successful_time
    cJSON *last_successful_time = cJSON_GetObjectItemCaseSensitive(v1_cron_job_statusJSON, "lastSuccessfulTime");
    if (cJSON_IsNull(last_successful_time)) {
        last_successful_time = NULL;
    }
    if (last_successful_time) { 
    if(!cJSON_IsString(last_successful_time) && !cJSON_IsNull(last_successful_time))
    {
    goto end; //DateTime
    }
    }


    v1_cron_job_status_local_var = v1_cron_job_status_create_internal (
        active ? activeList : NULL,
        last_schedule_time && !cJSON_IsNull(last_schedule_time) ? strdup(last_schedule_time->valuestring) : NULL,
        last_successful_time && !cJSON_IsNull(last_successful_time) ? strdup(last_successful_time->valuestring) : NULL
        );

    return v1_cron_job_status_local_var;
end:
    if (activeList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, activeList) {
            v1_object_reference_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(activeList);
        activeList = NULL;
    }
    return NULL;

}
