#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_event_source.h"



v1_event_source_t *v1_event_source_create(
    char *component,
    char *host
    ) {
    v1_event_source_t *v1_event_source_local_var = malloc(sizeof(v1_event_source_t));
    if (!v1_event_source_local_var) {
        return NULL;
    }
    v1_event_source_local_var->component = component;
    v1_event_source_local_var->host = host;

    return v1_event_source_local_var;
}


void v1_event_source_free(v1_event_source_t *v1_event_source) {
    if(NULL == v1_event_source){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_event_source->component) {
        free(v1_event_source->component);
        v1_event_source->component = NULL;
    }
    if (v1_event_source->host) {
        free(v1_event_source->host);
        v1_event_source->host = NULL;
    }
    free(v1_event_source);
}

cJSON *v1_event_source_convertToJSON(v1_event_source_t *v1_event_source) {
    cJSON *item = cJSON_CreateObject();

    // v1_event_source->component
    if(v1_event_source->component) { 
    if(cJSON_AddStringToObject(item, "component", v1_event_source->component) == NULL) {
    goto fail; //String
    }
     } 


    // v1_event_source->host
    if(v1_event_source->host) { 
    if(cJSON_AddStringToObject(item, "host", v1_event_source->host) == NULL) {
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

v1_event_source_t *v1_event_source_parseFromJSON(cJSON *v1_event_sourceJSON){

    v1_event_source_t *v1_event_source_local_var = NULL;

    // v1_event_source->component
    cJSON *component = cJSON_GetObjectItemCaseSensitive(v1_event_sourceJSON, "component");
    if (component) { 
    if(!cJSON_IsString(component))
    {
    goto end; //String
    }
    }

    // v1_event_source->host
    cJSON *host = cJSON_GetObjectItemCaseSensitive(v1_event_sourceJSON, "host");
    if (host) { 
    if(!cJSON_IsString(host))
    {
    goto end; //String
    }
    }


    v1_event_source_local_var = v1_event_source_create (
        component ? strdup(component->valuestring) : NULL,
        host ? strdup(host->valuestring) : NULL
        );

    return v1_event_source_local_var;
end:
    return NULL;

}
