#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_container_status.h"



v1_container_status_t *v1_container_status_create(
    char *container_id,
    char *image,
    char *image_id,
    v1_container_state_t *last_state,
    char *name,
    int ready,
    int restart_count,
    int started,
    v1_container_state_t *state
    ) {
    v1_container_status_t *v1_container_status_local_var = malloc(sizeof(v1_container_status_t));
    if (!v1_container_status_local_var) {
        return NULL;
    }
    v1_container_status_local_var->container_id = container_id;
    v1_container_status_local_var->image = image;
    v1_container_status_local_var->image_id = image_id;
    v1_container_status_local_var->last_state = last_state;
    v1_container_status_local_var->name = name;
    v1_container_status_local_var->ready = ready;
    v1_container_status_local_var->restart_count = restart_count;
    v1_container_status_local_var->started = started;
    v1_container_status_local_var->state = state;

    return v1_container_status_local_var;
}


void v1_container_status_free(v1_container_status_t *v1_container_status) {
    if(NULL == v1_container_status){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_container_status->container_id) {
        free(v1_container_status->container_id);
        v1_container_status->container_id = NULL;
    }
    if (v1_container_status->image) {
        free(v1_container_status->image);
        v1_container_status->image = NULL;
    }
    if (v1_container_status->image_id) {
        free(v1_container_status->image_id);
        v1_container_status->image_id = NULL;
    }
    if (v1_container_status->last_state) {
        v1_container_state_free(v1_container_status->last_state);
        v1_container_status->last_state = NULL;
    }
    if (v1_container_status->name) {
        free(v1_container_status->name);
        v1_container_status->name = NULL;
    }
    if (v1_container_status->state) {
        v1_container_state_free(v1_container_status->state);
        v1_container_status->state = NULL;
    }
    free(v1_container_status);
}

cJSON *v1_container_status_convertToJSON(v1_container_status_t *v1_container_status) {
    cJSON *item = cJSON_CreateObject();

    // v1_container_status->container_id
    if(v1_container_status->container_id) { 
    if(cJSON_AddStringToObject(item, "containerID", v1_container_status->container_id) == NULL) {
    goto fail; //String
    }
     } 


    // v1_container_status->image
    if (!v1_container_status->image) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "image", v1_container_status->image) == NULL) {
    goto fail; //String
    }


    // v1_container_status->image_id
    if (!v1_container_status->image_id) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "imageID", v1_container_status->image_id) == NULL) {
    goto fail; //String
    }


    // v1_container_status->last_state
    if(v1_container_status->last_state) { 
    cJSON *last_state_local_JSON = v1_container_state_convertToJSON(v1_container_status->last_state);
    if(last_state_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "lastState", last_state_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1_container_status->name
    if (!v1_container_status->name) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "name", v1_container_status->name) == NULL) {
    goto fail; //String
    }


    // v1_container_status->ready
    if (!v1_container_status->ready) {
        goto fail;
    }
    
    if(cJSON_AddBoolToObject(item, "ready", v1_container_status->ready) == NULL) {
    goto fail; //Bool
    }


    // v1_container_status->restart_count
    if (!v1_container_status->restart_count) {
        goto fail;
    }
    
    if(cJSON_AddNumberToObject(item, "restartCount", v1_container_status->restart_count) == NULL) {
    goto fail; //Numeric
    }


    // v1_container_status->started
    if(v1_container_status->started) { 
    if(cJSON_AddBoolToObject(item, "started", v1_container_status->started) == NULL) {
    goto fail; //Bool
    }
     } 


    // v1_container_status->state
    if(v1_container_status->state) { 
    cJSON *state_local_JSON = v1_container_state_convertToJSON(v1_container_status->state);
    if(state_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "state", state_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_container_status_t *v1_container_status_parseFromJSON(cJSON *v1_container_statusJSON){

    v1_container_status_t *v1_container_status_local_var = NULL;

    // v1_container_status->container_id
    cJSON *container_id = cJSON_GetObjectItemCaseSensitive(v1_container_statusJSON, "containerID");
    if (container_id) { 
    if(!cJSON_IsString(container_id))
    {
    goto end; //String
    }
    }

    // v1_container_status->image
    cJSON *image = cJSON_GetObjectItemCaseSensitive(v1_container_statusJSON, "image");
    if (!image) {
        goto end;
    }

    
    if(!cJSON_IsString(image))
    {
    goto end; //String
    }

    // v1_container_status->image_id
    cJSON *image_id = cJSON_GetObjectItemCaseSensitive(v1_container_statusJSON, "imageID");
    if (!image_id) {
        goto end;
    }

    
    if(!cJSON_IsString(image_id))
    {
    goto end; //String
    }

    // v1_container_status->last_state
    cJSON *last_state = cJSON_GetObjectItemCaseSensitive(v1_container_statusJSON, "lastState");
    v1_container_state_t *last_state_local_nonprim = NULL;
    if (last_state) { 
    last_state_local_nonprim = v1_container_state_parseFromJSON(last_state); //nonprimitive
    }

    // v1_container_status->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1_container_statusJSON, "name");
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // v1_container_status->ready
    cJSON *ready = cJSON_GetObjectItemCaseSensitive(v1_container_statusJSON, "ready");
    if (!ready) {
        goto end;
    }

    
    if(!cJSON_IsBool(ready))
    {
    goto end; //Bool
    }

    // v1_container_status->restart_count
    cJSON *restart_count = cJSON_GetObjectItemCaseSensitive(v1_container_statusJSON, "restartCount");
    if (!restart_count) {
        goto end;
    }

    
    if(!cJSON_IsNumber(restart_count))
    {
    goto end; //Numeric
    }

    // v1_container_status->started
    cJSON *started = cJSON_GetObjectItemCaseSensitive(v1_container_statusJSON, "started");
    if (started) { 
    if(!cJSON_IsBool(started))
    {
    goto end; //Bool
    }
    }

    // v1_container_status->state
    cJSON *state = cJSON_GetObjectItemCaseSensitive(v1_container_statusJSON, "state");
    v1_container_state_t *state_local_nonprim = NULL;
    if (state) { 
    state_local_nonprim = v1_container_state_parseFromJSON(state); //nonprimitive
    }


    v1_container_status_local_var = v1_container_status_create (
        container_id ? strdup(container_id->valuestring) : NULL,
        strdup(image->valuestring),
        strdup(image_id->valuestring),
        last_state ? last_state_local_nonprim : NULL,
        strdup(name->valuestring),
        ready->valueint,
        restart_count->valuedouble,
        started ? started->valueint : 0,
        state ? state_local_nonprim : NULL
        );

    return v1_container_status_local_var;
end:
    if (last_state_local_nonprim) {
        v1_container_state_free(last_state_local_nonprim);
        last_state_local_nonprim = NULL;
    }
    if (state_local_nonprim) {
        v1_container_state_free(state_local_nonprim);
        state_local_nonprim = NULL;
    }
    return NULL;

}
