#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "core_v1_event.h"



core_v1_event_t *core_v1_event_create(
    char *action,
    char *api_version,
    int count,
    char *event_time,
    char *first_timestamp,
    v1_object_reference_t *involved_object,
    char *kind,
    char *last_timestamp,
    char *message,
    v1_object_meta_t *metadata,
    char *reason,
    v1_object_reference_t *related,
    char *reporting_component,
    char *reporting_instance,
    core_v1_event_series_t *series,
    v1_event_source_t *source,
    char *type
    ) {
    core_v1_event_t *core_v1_event_local_var = malloc(sizeof(core_v1_event_t));
    if (!core_v1_event_local_var) {
        return NULL;
    }
    core_v1_event_local_var->action = action;
    core_v1_event_local_var->api_version = api_version;
    core_v1_event_local_var->count = count;
    core_v1_event_local_var->event_time = event_time;
    core_v1_event_local_var->first_timestamp = first_timestamp;
    core_v1_event_local_var->involved_object = involved_object;
    core_v1_event_local_var->kind = kind;
    core_v1_event_local_var->last_timestamp = last_timestamp;
    core_v1_event_local_var->message = message;
    core_v1_event_local_var->metadata = metadata;
    core_v1_event_local_var->reason = reason;
    core_v1_event_local_var->related = related;
    core_v1_event_local_var->reporting_component = reporting_component;
    core_v1_event_local_var->reporting_instance = reporting_instance;
    core_v1_event_local_var->series = series;
    core_v1_event_local_var->source = source;
    core_v1_event_local_var->type = type;

    return core_v1_event_local_var;
}


void core_v1_event_free(core_v1_event_t *core_v1_event) {
    if(NULL == core_v1_event){
        return ;
    }
    listEntry_t *listEntry;
    if (core_v1_event->action) {
        free(core_v1_event->action);
        core_v1_event->action = NULL;
    }
    if (core_v1_event->api_version) {
        free(core_v1_event->api_version);
        core_v1_event->api_version = NULL;
    }
    if (core_v1_event->event_time) {
        free(core_v1_event->event_time);
        core_v1_event->event_time = NULL;
    }
    if (core_v1_event->first_timestamp) {
        free(core_v1_event->first_timestamp);
        core_v1_event->first_timestamp = NULL;
    }
    if (core_v1_event->involved_object) {
        v1_object_reference_free(core_v1_event->involved_object);
        core_v1_event->involved_object = NULL;
    }
    if (core_v1_event->kind) {
        free(core_v1_event->kind);
        core_v1_event->kind = NULL;
    }
    if (core_v1_event->last_timestamp) {
        free(core_v1_event->last_timestamp);
        core_v1_event->last_timestamp = NULL;
    }
    if (core_v1_event->message) {
        free(core_v1_event->message);
        core_v1_event->message = NULL;
    }
    if (core_v1_event->metadata) {
        v1_object_meta_free(core_v1_event->metadata);
        core_v1_event->metadata = NULL;
    }
    if (core_v1_event->reason) {
        free(core_v1_event->reason);
        core_v1_event->reason = NULL;
    }
    if (core_v1_event->related) {
        v1_object_reference_free(core_v1_event->related);
        core_v1_event->related = NULL;
    }
    if (core_v1_event->reporting_component) {
        free(core_v1_event->reporting_component);
        core_v1_event->reporting_component = NULL;
    }
    if (core_v1_event->reporting_instance) {
        free(core_v1_event->reporting_instance);
        core_v1_event->reporting_instance = NULL;
    }
    if (core_v1_event->series) {
        core_v1_event_series_free(core_v1_event->series);
        core_v1_event->series = NULL;
    }
    if (core_v1_event->source) {
        v1_event_source_free(core_v1_event->source);
        core_v1_event->source = NULL;
    }
    if (core_v1_event->type) {
        free(core_v1_event->type);
        core_v1_event->type = NULL;
    }
    free(core_v1_event);
}

cJSON *core_v1_event_convertToJSON(core_v1_event_t *core_v1_event) {
    cJSON *item = cJSON_CreateObject();

    // core_v1_event->action
    if(core_v1_event->action) {
    if(cJSON_AddStringToObject(item, "action", core_v1_event->action) == NULL) {
    goto fail; //String
    }
    }


    // core_v1_event->api_version
    if(core_v1_event->api_version) {
    if(cJSON_AddStringToObject(item, "apiVersion", core_v1_event->api_version) == NULL) {
    goto fail; //String
    }
    }


    // core_v1_event->count
    if(core_v1_event->count) {
    if(cJSON_AddNumberToObject(item, "count", core_v1_event->count) == NULL) {
    goto fail; //Numeric
    }
    }


    // core_v1_event->event_time
    if(core_v1_event->event_time) {
    if(cJSON_AddStringToObject(item, "eventTime", core_v1_event->event_time) == NULL) {
    goto fail; //Date-Time
    }
    }


    // core_v1_event->first_timestamp
    if(core_v1_event->first_timestamp) {
    if(cJSON_AddStringToObject(item, "firstTimestamp", core_v1_event->first_timestamp) == NULL) {
    goto fail; //Date-Time
    }
    }


    // core_v1_event->involved_object
    if (!core_v1_event->involved_object) {
        goto fail;
    }
    cJSON *involved_object_local_JSON = v1_object_reference_convertToJSON(core_v1_event->involved_object);
    if(involved_object_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "involvedObject", involved_object_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // core_v1_event->kind
    if(core_v1_event->kind) {
    if(cJSON_AddStringToObject(item, "kind", core_v1_event->kind) == NULL) {
    goto fail; //String
    }
    }


    // core_v1_event->last_timestamp
    if(core_v1_event->last_timestamp) {
    if(cJSON_AddStringToObject(item, "lastTimestamp", core_v1_event->last_timestamp) == NULL) {
    goto fail; //Date-Time
    }
    }


    // core_v1_event->message
    if(core_v1_event->message) {
    if(cJSON_AddStringToObject(item, "message", core_v1_event->message) == NULL) {
    goto fail; //String
    }
    }


    // core_v1_event->metadata
    if (!core_v1_event->metadata) {
        goto fail;
    }
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(core_v1_event->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // core_v1_event->reason
    if(core_v1_event->reason) {
    if(cJSON_AddStringToObject(item, "reason", core_v1_event->reason) == NULL) {
    goto fail; //String
    }
    }


    // core_v1_event->related
    if(core_v1_event->related) {
    cJSON *related_local_JSON = v1_object_reference_convertToJSON(core_v1_event->related);
    if(related_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "related", related_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // core_v1_event->reporting_component
    if(core_v1_event->reporting_component) {
    if(cJSON_AddStringToObject(item, "reportingComponent", core_v1_event->reporting_component) == NULL) {
    goto fail; //String
    }
    }


    // core_v1_event->reporting_instance
    if(core_v1_event->reporting_instance) {
    if(cJSON_AddStringToObject(item, "reportingInstance", core_v1_event->reporting_instance) == NULL) {
    goto fail; //String
    }
    }


    // core_v1_event->series
    if(core_v1_event->series) {
    cJSON *series_local_JSON = core_v1_event_series_convertToJSON(core_v1_event->series);
    if(series_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "series", series_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // core_v1_event->source
    if(core_v1_event->source) {
    cJSON *source_local_JSON = v1_event_source_convertToJSON(core_v1_event->source);
    if(source_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "source", source_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // core_v1_event->type
    if(core_v1_event->type) {
    if(cJSON_AddStringToObject(item, "type", core_v1_event->type) == NULL) {
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

core_v1_event_t *core_v1_event_parseFromJSON(cJSON *core_v1_eventJSON){

    core_v1_event_t *core_v1_event_local_var = NULL;

    // define the local variable for core_v1_event->involved_object
    v1_object_reference_t *involved_object_local_nonprim = NULL;

    // define the local variable for core_v1_event->metadata
    v1_object_meta_t *metadata_local_nonprim = NULL;

    // define the local variable for core_v1_event->related
    v1_object_reference_t *related_local_nonprim = NULL;

    // define the local variable for core_v1_event->series
    core_v1_event_series_t *series_local_nonprim = NULL;

    // define the local variable for core_v1_event->source
    v1_event_source_t *source_local_nonprim = NULL;

    // core_v1_event->action
    cJSON *action = cJSON_GetObjectItemCaseSensitive(core_v1_eventJSON, "action");
    if (action) { 
    if(!cJSON_IsString(action))
    {
    goto end; //String
    }
    }

    // core_v1_event->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(core_v1_eventJSON, "apiVersion");
    if (api_version) { 
    if(!cJSON_IsString(api_version))
    {
    goto end; //String
    }
    }

    // core_v1_event->count
    cJSON *count = cJSON_GetObjectItemCaseSensitive(core_v1_eventJSON, "count");
    if (count) { 
    if(!cJSON_IsNumber(count))
    {
    goto end; //Numeric
    }
    }

    // core_v1_event->event_time
    cJSON *event_time = cJSON_GetObjectItemCaseSensitive(core_v1_eventJSON, "eventTime");
    if (event_time) { 
    if(!cJSON_IsString(event_time))
    {
    goto end; //DateTime
    }
    }

    // core_v1_event->first_timestamp
    cJSON *first_timestamp = cJSON_GetObjectItemCaseSensitive(core_v1_eventJSON, "firstTimestamp");
    if (first_timestamp) { 
    if(!cJSON_IsString(first_timestamp))
    {
    goto end; //DateTime
    }
    }

    // core_v1_event->involved_object
    cJSON *involved_object = cJSON_GetObjectItemCaseSensitive(core_v1_eventJSON, "involvedObject");
    if (!involved_object) {
        goto end;
    }

    
    involved_object_local_nonprim = v1_object_reference_parseFromJSON(involved_object); //nonprimitive

    // core_v1_event->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(core_v1_eventJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // core_v1_event->last_timestamp
    cJSON *last_timestamp = cJSON_GetObjectItemCaseSensitive(core_v1_eventJSON, "lastTimestamp");
    if (last_timestamp) { 
    if(!cJSON_IsString(last_timestamp))
    {
    goto end; //DateTime
    }
    }

    // core_v1_event->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(core_v1_eventJSON, "message");
    if (message) { 
    if(!cJSON_IsString(message))
    {
    goto end; //String
    }
    }

    // core_v1_event->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(core_v1_eventJSON, "metadata");
    if (!metadata) {
        goto end;
    }

    
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive

    // core_v1_event->reason
    cJSON *reason = cJSON_GetObjectItemCaseSensitive(core_v1_eventJSON, "reason");
    if (reason) { 
    if(!cJSON_IsString(reason))
    {
    goto end; //String
    }
    }

    // core_v1_event->related
    cJSON *related = cJSON_GetObjectItemCaseSensitive(core_v1_eventJSON, "related");
    if (related) { 
    related_local_nonprim = v1_object_reference_parseFromJSON(related); //nonprimitive
    }

    // core_v1_event->reporting_component
    cJSON *reporting_component = cJSON_GetObjectItemCaseSensitive(core_v1_eventJSON, "reportingComponent");
    if (reporting_component) { 
    if(!cJSON_IsString(reporting_component))
    {
    goto end; //String
    }
    }

    // core_v1_event->reporting_instance
    cJSON *reporting_instance = cJSON_GetObjectItemCaseSensitive(core_v1_eventJSON, "reportingInstance");
    if (reporting_instance) { 
    if(!cJSON_IsString(reporting_instance))
    {
    goto end; //String
    }
    }

    // core_v1_event->series
    cJSON *series = cJSON_GetObjectItemCaseSensitive(core_v1_eventJSON, "series");
    if (series) { 
    series_local_nonprim = core_v1_event_series_parseFromJSON(series); //nonprimitive
    }

    // core_v1_event->source
    cJSON *source = cJSON_GetObjectItemCaseSensitive(core_v1_eventJSON, "source");
    if (source) { 
    source_local_nonprim = v1_event_source_parseFromJSON(source); //nonprimitive
    }

    // core_v1_event->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(core_v1_eventJSON, "type");
    if (type) { 
    if(!cJSON_IsString(type))
    {
    goto end; //String
    }
    }


    core_v1_event_local_var = core_v1_event_create (
        action ? strdup(action->valuestring) : NULL,
        api_version ? strdup(api_version->valuestring) : NULL,
        count ? count->valuedouble : 0,
        event_time ? strdup(event_time->valuestring) : NULL,
        first_timestamp ? strdup(first_timestamp->valuestring) : NULL,
        involved_object_local_nonprim,
        kind ? strdup(kind->valuestring) : NULL,
        last_timestamp ? strdup(last_timestamp->valuestring) : NULL,
        message ? strdup(message->valuestring) : NULL,
        metadata_local_nonprim,
        reason ? strdup(reason->valuestring) : NULL,
        related ? related_local_nonprim : NULL,
        reporting_component ? strdup(reporting_component->valuestring) : NULL,
        reporting_instance ? strdup(reporting_instance->valuestring) : NULL,
        series ? series_local_nonprim : NULL,
        source ? source_local_nonprim : NULL,
        type ? strdup(type->valuestring) : NULL
        );

    return core_v1_event_local_var;
end:
    if (involved_object_local_nonprim) {
        v1_object_reference_free(involved_object_local_nonprim);
        involved_object_local_nonprim = NULL;
    }
    if (metadata_local_nonprim) {
        v1_object_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    if (related_local_nonprim) {
        v1_object_reference_free(related_local_nonprim);
        related_local_nonprim = NULL;
    }
    if (series_local_nonprim) {
        core_v1_event_series_free(series_local_nonprim);
        series_local_nonprim = NULL;
    }
    if (source_local_nonprim) {
        v1_event_source_free(source_local_nonprim);
        source_local_nonprim = NULL;
    }
    return NULL;

}
