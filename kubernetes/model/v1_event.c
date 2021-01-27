#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_event.h"



v1_event_t *v1_event_create(
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
    v1_event_series_t *series,
    v1_event_source_t *source,
    char *type
    ) {
    v1_event_t *v1_event_local_var = malloc(sizeof(v1_event_t));
    if (!v1_event_local_var) {
        return NULL;
    }
    v1_event_local_var->action = action;
    v1_event_local_var->api_version = api_version;
    v1_event_local_var->count = count;
    v1_event_local_var->event_time = event_time;
    v1_event_local_var->first_timestamp = first_timestamp;
    v1_event_local_var->involved_object = involved_object;
    v1_event_local_var->kind = kind;
    v1_event_local_var->last_timestamp = last_timestamp;
    v1_event_local_var->message = message;
    v1_event_local_var->metadata = metadata;
    v1_event_local_var->reason = reason;
    v1_event_local_var->related = related;
    v1_event_local_var->reporting_component = reporting_component;
    v1_event_local_var->reporting_instance = reporting_instance;
    v1_event_local_var->series = series;
    v1_event_local_var->source = source;
    v1_event_local_var->type = type;

    return v1_event_local_var;
}


void v1_event_free(v1_event_t *v1_event) {
    if(NULL == v1_event){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_event->action) {
        free(v1_event->action);
        v1_event->action = NULL;
    }
    if (v1_event->api_version) {
        free(v1_event->api_version);
        v1_event->api_version = NULL;
    }
    if (v1_event->event_time) {
        free(v1_event->event_time);
        v1_event->event_time = NULL;
    }
    if (v1_event->first_timestamp) {
        free(v1_event->first_timestamp);
        v1_event->first_timestamp = NULL;
    }
    if (v1_event->involved_object) {
        v1_object_reference_free(v1_event->involved_object);
        v1_event->involved_object = NULL;
    }
    if (v1_event->kind) {
        free(v1_event->kind);
        v1_event->kind = NULL;
    }
    if (v1_event->last_timestamp) {
        free(v1_event->last_timestamp);
        v1_event->last_timestamp = NULL;
    }
    if (v1_event->message) {
        free(v1_event->message);
        v1_event->message = NULL;
    }
    if (v1_event->metadata) {
        v1_object_meta_free(v1_event->metadata);
        v1_event->metadata = NULL;
    }
    if (v1_event->reason) {
        free(v1_event->reason);
        v1_event->reason = NULL;
    }
    if (v1_event->related) {
        v1_object_reference_free(v1_event->related);
        v1_event->related = NULL;
    }
    if (v1_event->reporting_component) {
        free(v1_event->reporting_component);
        v1_event->reporting_component = NULL;
    }
    if (v1_event->reporting_instance) {
        free(v1_event->reporting_instance);
        v1_event->reporting_instance = NULL;
    }
    if (v1_event->series) {
        v1_event_series_free(v1_event->series);
        v1_event->series = NULL;
    }
    if (v1_event->source) {
        v1_event_source_free(v1_event->source);
        v1_event->source = NULL;
    }
    if (v1_event->type) {
        free(v1_event->type);
        v1_event->type = NULL;
    }
    free(v1_event);
}

cJSON *v1_event_convertToJSON(v1_event_t *v1_event) {
    cJSON *item = cJSON_CreateObject();

    // v1_event->action
    if(v1_event->action) { 
    if(cJSON_AddStringToObject(item, "action", v1_event->action) == NULL) {
    goto fail; //String
    }
     } 


    // v1_event->api_version
    if(v1_event->api_version) { 
    if(cJSON_AddStringToObject(item, "apiVersion", v1_event->api_version) == NULL) {
    goto fail; //String
    }
     } 


    // v1_event->count
    if(v1_event->count) { 
    if(cJSON_AddNumberToObject(item, "count", v1_event->count) == NULL) {
    goto fail; //Numeric
    }
     } 


    // v1_event->event_time
    if(v1_event->event_time) { 
    if(cJSON_AddStringToObject(item, "eventTime", v1_event->event_time) == NULL) {
    goto fail; //Date-Time
    }
     } 


    // v1_event->first_timestamp
    if(v1_event->first_timestamp) { 
    if(cJSON_AddStringToObject(item, "firstTimestamp", v1_event->first_timestamp) == NULL) {
    goto fail; //Date-Time
    }
     } 


    // v1_event->involved_object
    if (!v1_event->involved_object) {
        goto fail;
    }
    
    cJSON *involved_object_local_JSON = v1_object_reference_convertToJSON(v1_event->involved_object);
    if(involved_object_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "involvedObject", involved_object_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // v1_event->kind
    if(v1_event->kind) { 
    if(cJSON_AddStringToObject(item, "kind", v1_event->kind) == NULL) {
    goto fail; //String
    }
     } 


    // v1_event->last_timestamp
    if(v1_event->last_timestamp) { 
    if(cJSON_AddStringToObject(item, "lastTimestamp", v1_event->last_timestamp) == NULL) {
    goto fail; //Date-Time
    }
     } 


    // v1_event->message
    if(v1_event->message) { 
    if(cJSON_AddStringToObject(item, "message", v1_event->message) == NULL) {
    goto fail; //String
    }
     } 


    // v1_event->metadata
    if (!v1_event->metadata) {
        goto fail;
    }
    
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1_event->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // v1_event->reason
    if(v1_event->reason) { 
    if(cJSON_AddStringToObject(item, "reason", v1_event->reason) == NULL) {
    goto fail; //String
    }
     } 


    // v1_event->related
    if(v1_event->related) { 
    cJSON *related_local_JSON = v1_object_reference_convertToJSON(v1_event->related);
    if(related_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "related", related_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1_event->reporting_component
    if(v1_event->reporting_component) { 
    if(cJSON_AddStringToObject(item, "reportingComponent", v1_event->reporting_component) == NULL) {
    goto fail; //String
    }
     } 


    // v1_event->reporting_instance
    if(v1_event->reporting_instance) { 
    if(cJSON_AddStringToObject(item, "reportingInstance", v1_event->reporting_instance) == NULL) {
    goto fail; //String
    }
     } 


    // v1_event->series
    if(v1_event->series) { 
    cJSON *series_local_JSON = v1_event_series_convertToJSON(v1_event->series);
    if(series_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "series", series_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1_event->source
    if(v1_event->source) { 
    cJSON *source_local_JSON = v1_event_source_convertToJSON(v1_event->source);
    if(source_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "source", source_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1_event->type
    if(v1_event->type) { 
    if(cJSON_AddStringToObject(item, "type", v1_event->type) == NULL) {
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

v1_event_t *v1_event_parseFromJSON(cJSON *v1_eventJSON){

    v1_event_t *v1_event_local_var = NULL;

    // v1_event->action
    cJSON *action = cJSON_GetObjectItemCaseSensitive(v1_eventJSON, "action");
    if (action) { 
    if(!cJSON_IsString(action))
    {
    goto end; //String
    }
    }

    // v1_event->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1_eventJSON, "apiVersion");
    if (api_version) { 
    if(!cJSON_IsString(api_version))
    {
    goto end; //String
    }
    }

    // v1_event->count
    cJSON *count = cJSON_GetObjectItemCaseSensitive(v1_eventJSON, "count");
    if (count) { 
    if(!cJSON_IsNumber(count))
    {
    goto end; //Numeric
    }
    }

    // v1_event->event_time
    cJSON *event_time = cJSON_GetObjectItemCaseSensitive(v1_eventJSON, "eventTime");
    if (event_time) { 
    if(!cJSON_IsString(event_time))
    {
    goto end; //DateTime
    }
    }

    // v1_event->first_timestamp
    cJSON *first_timestamp = cJSON_GetObjectItemCaseSensitive(v1_eventJSON, "firstTimestamp");
    if (first_timestamp) { 
    if(!cJSON_IsString(first_timestamp))
    {
    goto end; //DateTime
    }
    }

    // v1_event->involved_object
    cJSON *involved_object = cJSON_GetObjectItemCaseSensitive(v1_eventJSON, "involvedObject");
    if (!involved_object) {
        goto end;
    }

    v1_object_reference_t *involved_object_local_nonprim = NULL;
    
    involved_object_local_nonprim = v1_object_reference_parseFromJSON(involved_object); //nonprimitive

    // v1_event->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_eventJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // v1_event->last_timestamp
    cJSON *last_timestamp = cJSON_GetObjectItemCaseSensitive(v1_eventJSON, "lastTimestamp");
    if (last_timestamp) { 
    if(!cJSON_IsString(last_timestamp))
    {
    goto end; //DateTime
    }
    }

    // v1_event->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(v1_eventJSON, "message");
    if (message) { 
    if(!cJSON_IsString(message))
    {
    goto end; //String
    }
    }

    // v1_event->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1_eventJSON, "metadata");
    if (!metadata) {
        goto end;
    }

    v1_object_meta_t *metadata_local_nonprim = NULL;
    
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive

    // v1_event->reason
    cJSON *reason = cJSON_GetObjectItemCaseSensitive(v1_eventJSON, "reason");
    if (reason) { 
    if(!cJSON_IsString(reason))
    {
    goto end; //String
    }
    }

    // v1_event->related
    cJSON *related = cJSON_GetObjectItemCaseSensitive(v1_eventJSON, "related");
    v1_object_reference_t *related_local_nonprim = NULL;
    if (related) { 
    related_local_nonprim = v1_object_reference_parseFromJSON(related); //nonprimitive
    }

    // v1_event->reporting_component
    cJSON *reporting_component = cJSON_GetObjectItemCaseSensitive(v1_eventJSON, "reportingComponent");
    if (reporting_component) { 
    if(!cJSON_IsString(reporting_component))
    {
    goto end; //String
    }
    }

    // v1_event->reporting_instance
    cJSON *reporting_instance = cJSON_GetObjectItemCaseSensitive(v1_eventJSON, "reportingInstance");
    if (reporting_instance) { 
    if(!cJSON_IsString(reporting_instance))
    {
    goto end; //String
    }
    }

    // v1_event->series
    cJSON *series = cJSON_GetObjectItemCaseSensitive(v1_eventJSON, "series");
    v1_event_series_t *series_local_nonprim = NULL;
    if (series) { 
    series_local_nonprim = v1_event_series_parseFromJSON(series); //nonprimitive
    }

    // v1_event->source
    cJSON *source = cJSON_GetObjectItemCaseSensitive(v1_eventJSON, "source");
    v1_event_source_t *source_local_nonprim = NULL;
    if (source) { 
    source_local_nonprim = v1_event_source_parseFromJSON(source); //nonprimitive
    }

    // v1_event->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(v1_eventJSON, "type");
    if (type) { 
    if(!cJSON_IsString(type))
    {
    goto end; //String
    }
    }


    v1_event_local_var = v1_event_create (
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

    return v1_event_local_var;
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
        v1_event_series_free(series_local_nonprim);
        series_local_nonprim = NULL;
    }
    if (source_local_nonprim) {
        v1_event_source_free(source_local_nonprim);
        source_local_nonprim = NULL;
    }
    return NULL;

}
