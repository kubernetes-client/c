#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_watch_event.h"



v1_watch_event_t *v1_watch_event_create(
    object_t *object,
    char *type
    ) {
    v1_watch_event_t *v1_watch_event_local_var = malloc(sizeof(v1_watch_event_t));
    if (!v1_watch_event_local_var) {
        return NULL;
    }
    v1_watch_event_local_var->object = object;
    v1_watch_event_local_var->type = type;

    return v1_watch_event_local_var;
}


void v1_watch_event_free(v1_watch_event_t *v1_watch_event) {
    if(NULL == v1_watch_event){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_watch_event->object) {
        object_free(v1_watch_event->object);
        v1_watch_event->object = NULL;
    }
    if (v1_watch_event->type) {
        free(v1_watch_event->type);
        v1_watch_event->type = NULL;
    }
    free(v1_watch_event);
}

cJSON *v1_watch_event_convertToJSON(v1_watch_event_t *v1_watch_event) {
    cJSON *item = cJSON_CreateObject();

    // v1_watch_event->object
    if (!v1_watch_event->object) {
        goto fail;
    }
    
    cJSON *object_object = object_convertToJSON(v1_watch_event->object);
    if(object_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "object", object_object);
    if(item->child == NULL) {
    goto fail;
    }


    // v1_watch_event->type
    if (!v1_watch_event->type) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "type", v1_watch_event->type) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_watch_event_t *v1_watch_event_parseFromJSON(cJSON *v1_watch_eventJSON){

    v1_watch_event_t *v1_watch_event_local_var = NULL;

    // v1_watch_event->object
    cJSON *object = cJSON_GetObjectItemCaseSensitive(v1_watch_eventJSON, "object");
    if (!object) {
        goto end;
    }

    object_t *object_local_object = NULL;
    
    object_local_object = object_parseFromJSON(object); //object

    // v1_watch_event->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(v1_watch_eventJSON, "type");
    if (!type) {
        goto end;
    }

    
    if(!cJSON_IsString(type))
    {
    goto end; //String
    }


    v1_watch_event_local_var = v1_watch_event_create (
        object_local_object,
        strdup(type->valuestring)
        );

    return v1_watch_event_local_var;
end:
    return NULL;

}
