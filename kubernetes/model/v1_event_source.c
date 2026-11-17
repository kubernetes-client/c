#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_event_source.h"



static v1_event_source_t *v1_event_source_create_internal(
    char *component,
    char *host
    ) {
    v1_event_source_t *v1_event_source_local_var = malloc(sizeof(v1_event_source_t));
    if (!v1_event_source_local_var) {
        return NULL;
    }
    memset(v1_event_source_local_var, 0, sizeof(v1_event_source_t));
    v1_event_source_local_var->_library_owned = 1;
    v1_event_source_local_var->component = component;
    v1_event_source_local_var->host = host;
    return v1_event_source_local_var;
}

__attribute__((deprecated)) v1_event_source_t *v1_event_source_create(
    char *component,
    char *host
    ) {
    v1_event_source_t *result = v1_event_source_create_internal (
        component,
        host
        );
    if (!result) {
    }
    return result;
}

void v1_event_source_free(v1_event_source_t *v1_event_source) {
    if(NULL == v1_event_source){
        return ;
    }
    if(v1_event_source->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_event_source_free");
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

    char *component_local_str = NULL;

    char *host_local_str = NULL;

    // v1_event_source->component
    cJSON *component = cJSON_GetObjectItemCaseSensitive(v1_event_sourceJSON, "component");
    if (cJSON_IsNull(component)) {
        component = NULL;
    }
    if (component) { 
    if(!cJSON_IsString(component) && !cJSON_IsNull(component))
    {
    goto end; //String
    }
    }

    // v1_event_source->host
    cJSON *host = cJSON_GetObjectItemCaseSensitive(v1_event_sourceJSON, "host");
    if (cJSON_IsNull(host)) {
        host = NULL;
    }
    if (host) { 
    if(!cJSON_IsString(host) && !cJSON_IsNull(host))
    {
    goto end; //String
    }
    }


    if (component && !cJSON_IsNull(component)) component_local_str = strdup(component->valuestring);
    if (host && !cJSON_IsNull(host)) host_local_str = strdup(host->valuestring);

    v1_event_source_local_var = v1_event_source_create_internal (
        component_local_str,
        host_local_str
        );

    if (!v1_event_source_local_var) {
        goto end;
    }

    return v1_event_source_local_var;
end:
    if (component_local_str) {
        free(component_local_str);
        component_local_str = NULL;
    }
    if (host_local_str) {
        free(host_local_str);
        host_local_str = NULL;
    }
    return NULL;

}
