#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_event.h"



v1beta1_event_t *v1beta1_event_create(
    char *action,
    char *api_version,
    int deprecated_count,
    char *deprecated_first_timestamp,
    char *deprecated_last_timestamp,
    v1_event_source_t *deprecated_source,
    char *event_time,
    char *kind,
    v1_object_meta_t *metadata,
    char *note,
    char *reason,
    v1_object_reference_t *regarding,
    v1_object_reference_t *related,
    char *reporting_controller,
    char *reporting_instance,
    v1beta1_event_series_t *series,
    char *type
    ) {
    v1beta1_event_t *v1beta1_event_local_var = malloc(sizeof(v1beta1_event_t));
    if (!v1beta1_event_local_var) {
        return NULL;
    }
    v1beta1_event_local_var->action = action;
    v1beta1_event_local_var->api_version = api_version;
    v1beta1_event_local_var->deprecated_count = deprecated_count;
    v1beta1_event_local_var->deprecated_first_timestamp = deprecated_first_timestamp;
    v1beta1_event_local_var->deprecated_last_timestamp = deprecated_last_timestamp;
    v1beta1_event_local_var->deprecated_source = deprecated_source;
    v1beta1_event_local_var->event_time = event_time;
    v1beta1_event_local_var->kind = kind;
    v1beta1_event_local_var->metadata = metadata;
    v1beta1_event_local_var->note = note;
    v1beta1_event_local_var->reason = reason;
    v1beta1_event_local_var->regarding = regarding;
    v1beta1_event_local_var->related = related;
    v1beta1_event_local_var->reporting_controller = reporting_controller;
    v1beta1_event_local_var->reporting_instance = reporting_instance;
    v1beta1_event_local_var->series = series;
    v1beta1_event_local_var->type = type;

    return v1beta1_event_local_var;
}


void v1beta1_event_free(v1beta1_event_t *v1beta1_event) {
    if(NULL == v1beta1_event){
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta1_event->action) {
        free(v1beta1_event->action);
        v1beta1_event->action = NULL;
    }
    if (v1beta1_event->api_version) {
        free(v1beta1_event->api_version);
        v1beta1_event->api_version = NULL;
    }
    if (v1beta1_event->deprecated_first_timestamp) {
        free(v1beta1_event->deprecated_first_timestamp);
        v1beta1_event->deprecated_first_timestamp = NULL;
    }
    if (v1beta1_event->deprecated_last_timestamp) {
        free(v1beta1_event->deprecated_last_timestamp);
        v1beta1_event->deprecated_last_timestamp = NULL;
    }
    if (v1beta1_event->deprecated_source) {
        v1_event_source_free(v1beta1_event->deprecated_source);
        v1beta1_event->deprecated_source = NULL;
    }
    if (v1beta1_event->event_time) {
        free(v1beta1_event->event_time);
        v1beta1_event->event_time = NULL;
    }
    if (v1beta1_event->kind) {
        free(v1beta1_event->kind);
        v1beta1_event->kind = NULL;
    }
    if (v1beta1_event->metadata) {
        v1_object_meta_free(v1beta1_event->metadata);
        v1beta1_event->metadata = NULL;
    }
    if (v1beta1_event->note) {
        free(v1beta1_event->note);
        v1beta1_event->note = NULL;
    }
    if (v1beta1_event->reason) {
        free(v1beta1_event->reason);
        v1beta1_event->reason = NULL;
    }
    if (v1beta1_event->regarding) {
        v1_object_reference_free(v1beta1_event->regarding);
        v1beta1_event->regarding = NULL;
    }
    if (v1beta1_event->related) {
        v1_object_reference_free(v1beta1_event->related);
        v1beta1_event->related = NULL;
    }
    if (v1beta1_event->reporting_controller) {
        free(v1beta1_event->reporting_controller);
        v1beta1_event->reporting_controller = NULL;
    }
    if (v1beta1_event->reporting_instance) {
        free(v1beta1_event->reporting_instance);
        v1beta1_event->reporting_instance = NULL;
    }
    if (v1beta1_event->series) {
        v1beta1_event_series_free(v1beta1_event->series);
        v1beta1_event->series = NULL;
    }
    if (v1beta1_event->type) {
        free(v1beta1_event->type);
        v1beta1_event->type = NULL;
    }
    free(v1beta1_event);
}

cJSON *v1beta1_event_convertToJSON(v1beta1_event_t *v1beta1_event) {
    cJSON *item = cJSON_CreateObject();

    // v1beta1_event->action
    if(v1beta1_event->action) { 
    if(cJSON_AddStringToObject(item, "action", v1beta1_event->action) == NULL) {
    goto fail; //String
    }
     } 


    // v1beta1_event->api_version
    if(v1beta1_event->api_version) { 
    if(cJSON_AddStringToObject(item, "apiVersion", v1beta1_event->api_version) == NULL) {
    goto fail; //String
    }
     } 


    // v1beta1_event->deprecated_count
    if(v1beta1_event->deprecated_count) { 
    if(cJSON_AddNumberToObject(item, "deprecatedCount", v1beta1_event->deprecated_count) == NULL) {
    goto fail; //Numeric
    }
     } 


    // v1beta1_event->deprecated_first_timestamp
    if(v1beta1_event->deprecated_first_timestamp) { 
    if(cJSON_AddStringToObject(item, "deprecatedFirstTimestamp", v1beta1_event->deprecated_first_timestamp) == NULL) {
    goto fail; //Date-Time
    }
     } 


    // v1beta1_event->deprecated_last_timestamp
    if(v1beta1_event->deprecated_last_timestamp) { 
    if(cJSON_AddStringToObject(item, "deprecatedLastTimestamp", v1beta1_event->deprecated_last_timestamp) == NULL) {
    goto fail; //Date-Time
    }
     } 


    // v1beta1_event->deprecated_source
    if(v1beta1_event->deprecated_source) { 
    cJSON *deprecated_source_local_JSON = v1_event_source_convertToJSON(v1beta1_event->deprecated_source);
    if(deprecated_source_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "deprecatedSource", deprecated_source_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1beta1_event->event_time
    if (!v1beta1_event->event_time) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "eventTime", v1beta1_event->event_time) == NULL) {
    goto fail; //Date-Time
    }


    // v1beta1_event->kind
    if(v1beta1_event->kind) { 
    if(cJSON_AddStringToObject(item, "kind", v1beta1_event->kind) == NULL) {
    goto fail; //String
    }
     } 


    // v1beta1_event->metadata
    if(v1beta1_event->metadata) { 
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1beta1_event->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1beta1_event->note
    if(v1beta1_event->note) { 
    if(cJSON_AddStringToObject(item, "note", v1beta1_event->note) == NULL) {
    goto fail; //String
    }
     } 


    // v1beta1_event->reason
    if(v1beta1_event->reason) { 
    if(cJSON_AddStringToObject(item, "reason", v1beta1_event->reason) == NULL) {
    goto fail; //String
    }
     } 


    // v1beta1_event->regarding
    if(v1beta1_event->regarding) { 
    cJSON *regarding_local_JSON = v1_object_reference_convertToJSON(v1beta1_event->regarding);
    if(regarding_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "regarding", regarding_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1beta1_event->related
    if(v1beta1_event->related) { 
    cJSON *related_local_JSON = v1_object_reference_convertToJSON(v1beta1_event->related);
    if(related_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "related", related_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1beta1_event->reporting_controller
    if(v1beta1_event->reporting_controller) { 
    if(cJSON_AddStringToObject(item, "reportingController", v1beta1_event->reporting_controller) == NULL) {
    goto fail; //String
    }
     } 


    // v1beta1_event->reporting_instance
    if(v1beta1_event->reporting_instance) { 
    if(cJSON_AddStringToObject(item, "reportingInstance", v1beta1_event->reporting_instance) == NULL) {
    goto fail; //String
    }
     } 


    // v1beta1_event->series
    if(v1beta1_event->series) { 
    cJSON *series_local_JSON = v1beta1_event_series_convertToJSON(v1beta1_event->series);
    if(series_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "series", series_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1beta1_event->type
    if(v1beta1_event->type) { 
    if(cJSON_AddStringToObject(item, "type", v1beta1_event->type) == NULL) {
    goto fail; //String
    }
     } 

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1beta1_event_t *v1beta1_event_parseFromJSON(cJSON *v1beta1_eventJSON){

    v1beta1_event_t *v1beta1_event_local_var = NULL;

    // v1beta1_event->action
    cJSON *action = cJSON_GetObjectItemCaseSensitive(v1beta1_eventJSON, "action");
    if (action) { 
    if(!cJSON_IsString(action))
    {
    goto end; //String
    }
    }

    // v1beta1_event->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1beta1_eventJSON, "apiVersion");
    if (api_version) { 
    if(!cJSON_IsString(api_version))
    {
    goto end; //String
    }
    }

    // v1beta1_event->deprecated_count
    cJSON *deprecated_count = cJSON_GetObjectItemCaseSensitive(v1beta1_eventJSON, "deprecatedCount");
    if (deprecated_count) { 
    if(!cJSON_IsNumber(deprecated_count))
    {
    goto end; //Numeric
    }
    }

    // v1beta1_event->deprecated_first_timestamp
    cJSON *deprecated_first_timestamp = cJSON_GetObjectItemCaseSensitive(v1beta1_eventJSON, "deprecatedFirstTimestamp");
    if (deprecated_first_timestamp) { 
    if(!cJSON_IsString(deprecated_first_timestamp))
    {
    goto end; //DateTime
    }
    }

    // v1beta1_event->deprecated_last_timestamp
    cJSON *deprecated_last_timestamp = cJSON_GetObjectItemCaseSensitive(v1beta1_eventJSON, "deprecatedLastTimestamp");
    if (deprecated_last_timestamp) { 
    if(!cJSON_IsString(deprecated_last_timestamp))
    {
    goto end; //DateTime
    }
    }

    // v1beta1_event->deprecated_source
    cJSON *deprecated_source = cJSON_GetObjectItemCaseSensitive(v1beta1_eventJSON, "deprecatedSource");
    v1_event_source_t *deprecated_source_local_nonprim = NULL;
    if (deprecated_source) { 
    deprecated_source_local_nonprim = v1_event_source_parseFromJSON(deprecated_source); //nonprimitive
    }

    // v1beta1_event->event_time
    cJSON *event_time = cJSON_GetObjectItemCaseSensitive(v1beta1_eventJSON, "eventTime");
    if (!event_time) {
        goto end;
    }

    
    if(!cJSON_IsString(event_time))
    {
    goto end; //DateTime
    }

    // v1beta1_event->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1beta1_eventJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // v1beta1_event->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1beta1_eventJSON, "metadata");
    v1_object_meta_t *metadata_local_nonprim = NULL;
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1beta1_event->note
    cJSON *note = cJSON_GetObjectItemCaseSensitive(v1beta1_eventJSON, "note");
    if (note) { 
    if(!cJSON_IsString(note))
    {
    goto end; //String
    }
    }

    // v1beta1_event->reason
    cJSON *reason = cJSON_GetObjectItemCaseSensitive(v1beta1_eventJSON, "reason");
    if (reason) { 
    if(!cJSON_IsString(reason))
    {
    goto end; //String
    }
    }

    // v1beta1_event->regarding
    cJSON *regarding = cJSON_GetObjectItemCaseSensitive(v1beta1_eventJSON, "regarding");
    v1_object_reference_t *regarding_local_nonprim = NULL;
    if (regarding) { 
    regarding_local_nonprim = v1_object_reference_parseFromJSON(regarding); //nonprimitive
    }

    // v1beta1_event->related
    cJSON *related = cJSON_GetObjectItemCaseSensitive(v1beta1_eventJSON, "related");
    v1_object_reference_t *related_local_nonprim = NULL;
    if (related) { 
    related_local_nonprim = v1_object_reference_parseFromJSON(related); //nonprimitive
    }

    // v1beta1_event->reporting_controller
    cJSON *reporting_controller = cJSON_GetObjectItemCaseSensitive(v1beta1_eventJSON, "reportingController");
    if (reporting_controller) { 
    if(!cJSON_IsString(reporting_controller))
    {
    goto end; //String
    }
    }

    // v1beta1_event->reporting_instance
    cJSON *reporting_instance = cJSON_GetObjectItemCaseSensitive(v1beta1_eventJSON, "reportingInstance");
    if (reporting_instance) { 
    if(!cJSON_IsString(reporting_instance))
    {
    goto end; //String
    }
    }

    // v1beta1_event->series
    cJSON *series = cJSON_GetObjectItemCaseSensitive(v1beta1_eventJSON, "series");
    v1beta1_event_series_t *series_local_nonprim = NULL;
    if (series) { 
    series_local_nonprim = v1beta1_event_series_parseFromJSON(series); //nonprimitive
    }

    // v1beta1_event->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(v1beta1_eventJSON, "type");
    if (type) { 
    if(!cJSON_IsString(type))
    {
    goto end; //String
    }
    }


    v1beta1_event_local_var = v1beta1_event_create (
        action ? strdup(action->valuestring) : NULL,
        api_version ? strdup(api_version->valuestring) : NULL,
        deprecated_count ? deprecated_count->valuedouble : 0,
        deprecated_first_timestamp ? strdup(deprecated_first_timestamp->valuestring) : NULL,
        deprecated_last_timestamp ? strdup(deprecated_last_timestamp->valuestring) : NULL,
        deprecated_source ? deprecated_source_local_nonprim : NULL,
        strdup(event_time->valuestring),
        kind ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        note ? strdup(note->valuestring) : NULL,
        reason ? strdup(reason->valuestring) : NULL,
        regarding ? regarding_local_nonprim : NULL,
        related ? related_local_nonprim : NULL,
        reporting_controller ? strdup(reporting_controller->valuestring) : NULL,
        reporting_instance ? strdup(reporting_instance->valuestring) : NULL,
        series ? series_local_nonprim : NULL,
        type ? strdup(type->valuestring) : NULL
        );

    return v1beta1_event_local_var;
end:
    if (deprecated_source_local_nonprim) {
        v1_event_source_free(deprecated_source_local_nonprim);
        deprecated_source_local_nonprim = NULL;
    }
    if (metadata_local_nonprim) {
        v1_object_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    if (regarding_local_nonprim) {
        v1_object_reference_free(regarding_local_nonprim);
        regarding_local_nonprim = NULL;
    }
    if (related_local_nonprim) {
        v1_object_reference_free(related_local_nonprim);
        related_local_nonprim = NULL;
    }
    if (series_local_nonprim) {
        v1beta1_event_series_free(series_local_nonprim);
        series_local_nonprim = NULL;
    }
    return NULL;

}
