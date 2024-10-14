#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_container_status.h"



v1_container_status_t *v1_container_status_create(
    list_t* allocated_resources,
    list_t *allocated_resources_status,
    char *container_id,
    char *image,
    char *image_id,
    v1_container_state_t *last_state,
    char *name,
    int ready,
    v1_resource_requirements_t *resources,
    int restart_count,
    int started,
    v1_container_state_t *state,
    v1_container_user_t *user,
    list_t *volume_mounts
    ) {
    v1_container_status_t *v1_container_status_local_var = malloc(sizeof(v1_container_status_t));
    if (!v1_container_status_local_var) {
        return NULL;
    }
    v1_container_status_local_var->allocated_resources = allocated_resources;
    v1_container_status_local_var->allocated_resources_status = allocated_resources_status;
    v1_container_status_local_var->container_id = container_id;
    v1_container_status_local_var->image = image;
    v1_container_status_local_var->image_id = image_id;
    v1_container_status_local_var->last_state = last_state;
    v1_container_status_local_var->name = name;
    v1_container_status_local_var->ready = ready;
    v1_container_status_local_var->resources = resources;
    v1_container_status_local_var->restart_count = restart_count;
    v1_container_status_local_var->started = started;
    v1_container_status_local_var->state = state;
    v1_container_status_local_var->user = user;
    v1_container_status_local_var->volume_mounts = volume_mounts;

    return v1_container_status_local_var;
}


void v1_container_status_free(v1_container_status_t *v1_container_status) {
    if(NULL == v1_container_status){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_container_status->allocated_resources) {
        list_ForEach(listEntry, v1_container_status->allocated_resources) {
            keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_freeList(v1_container_status->allocated_resources);
        v1_container_status->allocated_resources = NULL;
    }
    if (v1_container_status->allocated_resources_status) {
        list_ForEach(listEntry, v1_container_status->allocated_resources_status) {
            v1_resource_status_free(listEntry->data);
        }
        list_freeList(v1_container_status->allocated_resources_status);
        v1_container_status->allocated_resources_status = NULL;
    }
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
    if (v1_container_status->resources) {
        v1_resource_requirements_free(v1_container_status->resources);
        v1_container_status->resources = NULL;
    }
    if (v1_container_status->state) {
        v1_container_state_free(v1_container_status->state);
        v1_container_status->state = NULL;
    }
    if (v1_container_status->user) {
        v1_container_user_free(v1_container_status->user);
        v1_container_status->user = NULL;
    }
    if (v1_container_status->volume_mounts) {
        list_ForEach(listEntry, v1_container_status->volume_mounts) {
            v1_volume_mount_status_free(listEntry->data);
        }
        list_freeList(v1_container_status->volume_mounts);
        v1_container_status->volume_mounts = NULL;
    }
    free(v1_container_status);
}

cJSON *v1_container_status_convertToJSON(v1_container_status_t *v1_container_status) {
    cJSON *item = cJSON_CreateObject();

    // v1_container_status->allocated_resources
    if(v1_container_status->allocated_resources) {
    cJSON *allocated_resources = cJSON_AddObjectToObject(item, "allocatedResources");
    if(allocated_resources == NULL) {
        goto fail; //primitive map container
    }
    cJSON *localMapObject = allocated_resources;
    listEntry_t *allocated_resourcesListEntry;
    if (v1_container_status->allocated_resources) {
    list_ForEach(allocated_resourcesListEntry, v1_container_status->allocated_resources) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)allocated_resourcesListEntry->data;
        if(cJSON_AddStringToObject(localMapObject, localKeyValue->key, (char*)localKeyValue->value) == NULL)
        {
            goto fail;
        }
    }
    }
    }


    // v1_container_status->allocated_resources_status
    if(v1_container_status->allocated_resources_status) {
    cJSON *allocated_resources_status = cJSON_AddArrayToObject(item, "allocatedResourcesStatus");
    if(allocated_resources_status == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *allocated_resources_statusListEntry;
    if (v1_container_status->allocated_resources_status) {
    list_ForEach(allocated_resources_statusListEntry, v1_container_status->allocated_resources_status) {
    cJSON *itemLocal = v1_resource_status_convertToJSON(allocated_resources_statusListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(allocated_resources_status, itemLocal);
    }
    }
    }


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


    // v1_container_status->resources
    if(v1_container_status->resources) {
    cJSON *resources_local_JSON = v1_resource_requirements_convertToJSON(v1_container_status->resources);
    if(resources_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "resources", resources_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
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


    // v1_container_status->user
    if(v1_container_status->user) {
    cJSON *user_local_JSON = v1_container_user_convertToJSON(v1_container_status->user);
    if(user_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "user", user_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_container_status->volume_mounts
    if(v1_container_status->volume_mounts) {
    cJSON *volume_mounts = cJSON_AddArrayToObject(item, "volumeMounts");
    if(volume_mounts == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *volume_mountsListEntry;
    if (v1_container_status->volume_mounts) {
    list_ForEach(volume_mountsListEntry, v1_container_status->volume_mounts) {
    cJSON *itemLocal = v1_volume_mount_status_convertToJSON(volume_mountsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(volume_mounts, itemLocal);
    }
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

    // define the local map for v1_container_status->allocated_resources
    list_t *allocated_resourcesList = NULL;

    // define the local list for v1_container_status->allocated_resources_status
    list_t *allocated_resources_statusList = NULL;

    // define the local variable for v1_container_status->last_state
    v1_container_state_t *last_state_local_nonprim = NULL;

    // define the local variable for v1_container_status->resources
    v1_resource_requirements_t *resources_local_nonprim = NULL;

    // define the local variable for v1_container_status->state
    v1_container_state_t *state_local_nonprim = NULL;

    // define the local variable for v1_container_status->user
    v1_container_user_t *user_local_nonprim = NULL;

    // define the local list for v1_container_status->volume_mounts
    list_t *volume_mountsList = NULL;

    // v1_container_status->allocated_resources
    cJSON *allocated_resources = cJSON_GetObjectItemCaseSensitive(v1_container_statusJSON, "allocatedResources");
    if (allocated_resources) { 
    cJSON *allocated_resources_local_map = NULL;
    if(!cJSON_IsObject(allocated_resources) && !cJSON_IsNull(allocated_resources))
    {
        goto end;//primitive map container
    }
    if(cJSON_IsObject(allocated_resources))
    {
        allocated_resourcesList = list_createList();
        keyValuePair_t *localMapKeyPair;
        cJSON_ArrayForEach(allocated_resources_local_map, allocated_resources)
        {
            cJSON *localMapObject = allocated_resources_local_map;
            if(!cJSON_IsString(localMapObject))
            {
                goto end;
            }
            localMapKeyPair = keyValuePair_create(strdup(localMapObject->string),strdup(localMapObject->valuestring));
            list_addElement(allocated_resourcesList , localMapKeyPair);
        }
    }
    }

    // v1_container_status->allocated_resources_status
    cJSON *allocated_resources_status = cJSON_GetObjectItemCaseSensitive(v1_container_statusJSON, "allocatedResourcesStatus");
    if (allocated_resources_status) { 
    cJSON *allocated_resources_status_local_nonprimitive = NULL;
    if(!cJSON_IsArray(allocated_resources_status)){
        goto end; //nonprimitive container
    }

    allocated_resources_statusList = list_createList();

    cJSON_ArrayForEach(allocated_resources_status_local_nonprimitive,allocated_resources_status )
    {
        if(!cJSON_IsObject(allocated_resources_status_local_nonprimitive)){
            goto end;
        }
        v1_resource_status_t *allocated_resources_statusItem = v1_resource_status_parseFromJSON(allocated_resources_status_local_nonprimitive);

        list_addElement(allocated_resources_statusList, allocated_resources_statusItem);
    }
    }

    // v1_container_status->container_id
    cJSON *container_id = cJSON_GetObjectItemCaseSensitive(v1_container_statusJSON, "containerID");
    if (container_id) { 
    if(!cJSON_IsString(container_id) && !cJSON_IsNull(container_id))
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

    // v1_container_status->resources
    cJSON *resources = cJSON_GetObjectItemCaseSensitive(v1_container_statusJSON, "resources");
    if (resources) { 
    resources_local_nonprim = v1_resource_requirements_parseFromJSON(resources); //nonprimitive
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
    if (state) { 
    state_local_nonprim = v1_container_state_parseFromJSON(state); //nonprimitive
    }

    // v1_container_status->user
    cJSON *user = cJSON_GetObjectItemCaseSensitive(v1_container_statusJSON, "user");
    if (user) { 
    user_local_nonprim = v1_container_user_parseFromJSON(user); //nonprimitive
    }

    // v1_container_status->volume_mounts
    cJSON *volume_mounts = cJSON_GetObjectItemCaseSensitive(v1_container_statusJSON, "volumeMounts");
    if (volume_mounts) { 
    cJSON *volume_mounts_local_nonprimitive = NULL;
    if(!cJSON_IsArray(volume_mounts)){
        goto end; //nonprimitive container
    }

    volume_mountsList = list_createList();

    cJSON_ArrayForEach(volume_mounts_local_nonprimitive,volume_mounts )
    {
        if(!cJSON_IsObject(volume_mounts_local_nonprimitive)){
            goto end;
        }
        v1_volume_mount_status_t *volume_mountsItem = v1_volume_mount_status_parseFromJSON(volume_mounts_local_nonprimitive);

        list_addElement(volume_mountsList, volume_mountsItem);
    }
    }


    v1_container_status_local_var = v1_container_status_create (
        allocated_resources ? allocated_resourcesList : NULL,
        allocated_resources_status ? allocated_resources_statusList : NULL,
        container_id && !cJSON_IsNull(container_id) ? strdup(container_id->valuestring) : NULL,
        strdup(image->valuestring),
        strdup(image_id->valuestring),
        last_state ? last_state_local_nonprim : NULL,
        strdup(name->valuestring),
        ready->valueint,
        resources ? resources_local_nonprim : NULL,
        restart_count->valuedouble,
        started ? started->valueint : 0,
        state ? state_local_nonprim : NULL,
        user ? user_local_nonprim : NULL,
        volume_mounts ? volume_mountsList : NULL
        );

    return v1_container_status_local_var;
end:
    if (allocated_resourcesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, allocated_resourcesList) {
            keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
            free(localKeyValue->key);
            localKeyValue->key = NULL;
            free(localKeyValue->value);
            localKeyValue->value = NULL;
            keyValuePair_free(localKeyValue);
            localKeyValue = NULL;
        }
        list_freeList(allocated_resourcesList);
        allocated_resourcesList = NULL;
    }
    if (allocated_resources_statusList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, allocated_resources_statusList) {
            v1_resource_status_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(allocated_resources_statusList);
        allocated_resources_statusList = NULL;
    }
    if (last_state_local_nonprim) {
        v1_container_state_free(last_state_local_nonprim);
        last_state_local_nonprim = NULL;
    }
    if (resources_local_nonprim) {
        v1_resource_requirements_free(resources_local_nonprim);
        resources_local_nonprim = NULL;
    }
    if (state_local_nonprim) {
        v1_container_state_free(state_local_nonprim);
        state_local_nonprim = NULL;
    }
    if (user_local_nonprim) {
        v1_container_user_free(user_local_nonprim);
        user_local_nonprim = NULL;
    }
    if (volume_mountsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, volume_mountsList) {
            v1_volume_mount_status_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(volume_mountsList);
        volume_mountsList = NULL;
    }
    return NULL;

}
