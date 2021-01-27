#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha1_pod_preset_spec.h"



v1alpha1_pod_preset_spec_t *v1alpha1_pod_preset_spec_create(
    list_t *env,
    list_t *env_from,
    v1_label_selector_t *selector,
    list_t *volume_mounts,
    list_t *volumes
    ) {
    v1alpha1_pod_preset_spec_t *v1alpha1_pod_preset_spec_local_var = malloc(sizeof(v1alpha1_pod_preset_spec_t));
    if (!v1alpha1_pod_preset_spec_local_var) {
        return NULL;
    }
    v1alpha1_pod_preset_spec_local_var->env = env;
    v1alpha1_pod_preset_spec_local_var->env_from = env_from;
    v1alpha1_pod_preset_spec_local_var->selector = selector;
    v1alpha1_pod_preset_spec_local_var->volume_mounts = volume_mounts;
    v1alpha1_pod_preset_spec_local_var->volumes = volumes;

    return v1alpha1_pod_preset_spec_local_var;
}


void v1alpha1_pod_preset_spec_free(v1alpha1_pod_preset_spec_t *v1alpha1_pod_preset_spec) {
    if(NULL == v1alpha1_pod_preset_spec){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha1_pod_preset_spec->env) {
        list_ForEach(listEntry, v1alpha1_pod_preset_spec->env) {
            v1_env_var_free(listEntry->data);
        }
        list_free(v1alpha1_pod_preset_spec->env);
        v1alpha1_pod_preset_spec->env = NULL;
    }
    if (v1alpha1_pod_preset_spec->env_from) {
        list_ForEach(listEntry, v1alpha1_pod_preset_spec->env_from) {
            v1_env_from_source_free(listEntry->data);
        }
        list_free(v1alpha1_pod_preset_spec->env_from);
        v1alpha1_pod_preset_spec->env_from = NULL;
    }
    if (v1alpha1_pod_preset_spec->selector) {
        v1_label_selector_free(v1alpha1_pod_preset_spec->selector);
        v1alpha1_pod_preset_spec->selector = NULL;
    }
    if (v1alpha1_pod_preset_spec->volume_mounts) {
        list_ForEach(listEntry, v1alpha1_pod_preset_spec->volume_mounts) {
            v1_volume_mount_free(listEntry->data);
        }
        list_free(v1alpha1_pod_preset_spec->volume_mounts);
        v1alpha1_pod_preset_spec->volume_mounts = NULL;
    }
    if (v1alpha1_pod_preset_spec->volumes) {
        list_ForEach(listEntry, v1alpha1_pod_preset_spec->volumes) {
            v1_volume_free(listEntry->data);
        }
        list_free(v1alpha1_pod_preset_spec->volumes);
        v1alpha1_pod_preset_spec->volumes = NULL;
    }
    free(v1alpha1_pod_preset_spec);
}

cJSON *v1alpha1_pod_preset_spec_convertToJSON(v1alpha1_pod_preset_spec_t *v1alpha1_pod_preset_spec) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha1_pod_preset_spec->env
    if(v1alpha1_pod_preset_spec->env) { 
    cJSON *env = cJSON_AddArrayToObject(item, "env");
    if(env == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *envListEntry;
    if (v1alpha1_pod_preset_spec->env) {
    list_ForEach(envListEntry, v1alpha1_pod_preset_spec->env) {
    cJSON *itemLocal = v1_env_var_convertToJSON(envListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(env, itemLocal);
    }
    }
     } 


    // v1alpha1_pod_preset_spec->env_from
    if(v1alpha1_pod_preset_spec->env_from) { 
    cJSON *env_from = cJSON_AddArrayToObject(item, "envFrom");
    if(env_from == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *env_fromListEntry;
    if (v1alpha1_pod_preset_spec->env_from) {
    list_ForEach(env_fromListEntry, v1alpha1_pod_preset_spec->env_from) {
    cJSON *itemLocal = v1_env_from_source_convertToJSON(env_fromListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(env_from, itemLocal);
    }
    }
     } 


    // v1alpha1_pod_preset_spec->selector
    if(v1alpha1_pod_preset_spec->selector) { 
    cJSON *selector_local_JSON = v1_label_selector_convertToJSON(v1alpha1_pod_preset_spec->selector);
    if(selector_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "selector", selector_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1alpha1_pod_preset_spec->volume_mounts
    if(v1alpha1_pod_preset_spec->volume_mounts) { 
    cJSON *volume_mounts = cJSON_AddArrayToObject(item, "volumeMounts");
    if(volume_mounts == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *volume_mountsListEntry;
    if (v1alpha1_pod_preset_spec->volume_mounts) {
    list_ForEach(volume_mountsListEntry, v1alpha1_pod_preset_spec->volume_mounts) {
    cJSON *itemLocal = v1_volume_mount_convertToJSON(volume_mountsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(volume_mounts, itemLocal);
    }
    }
     } 


    // v1alpha1_pod_preset_spec->volumes
    if(v1alpha1_pod_preset_spec->volumes) { 
    cJSON *volumes = cJSON_AddArrayToObject(item, "volumes");
    if(volumes == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *volumesListEntry;
    if (v1alpha1_pod_preset_spec->volumes) {
    list_ForEach(volumesListEntry, v1alpha1_pod_preset_spec->volumes) {
    cJSON *itemLocal = v1_volume_convertToJSON(volumesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(volumes, itemLocal);
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

v1alpha1_pod_preset_spec_t *v1alpha1_pod_preset_spec_parseFromJSON(cJSON *v1alpha1_pod_preset_specJSON){

    v1alpha1_pod_preset_spec_t *v1alpha1_pod_preset_spec_local_var = NULL;

    // v1alpha1_pod_preset_spec->env
    cJSON *env = cJSON_GetObjectItemCaseSensitive(v1alpha1_pod_preset_specJSON, "env");
    list_t *envList;
    if (env) { 
    cJSON *env_local_nonprimitive;
    if(!cJSON_IsArray(env)){
        goto end; //nonprimitive container
    }

    envList = list_create();

    cJSON_ArrayForEach(env_local_nonprimitive,env )
    {
        if(!cJSON_IsObject(env_local_nonprimitive)){
            goto end;
        }
        v1_env_var_t *envItem = v1_env_var_parseFromJSON(env_local_nonprimitive);

        list_addElement(envList, envItem);
    }
    }

    // v1alpha1_pod_preset_spec->env_from
    cJSON *env_from = cJSON_GetObjectItemCaseSensitive(v1alpha1_pod_preset_specJSON, "envFrom");
    list_t *env_fromList;
    if (env_from) { 
    cJSON *env_from_local_nonprimitive;
    if(!cJSON_IsArray(env_from)){
        goto end; //nonprimitive container
    }

    env_fromList = list_create();

    cJSON_ArrayForEach(env_from_local_nonprimitive,env_from )
    {
        if(!cJSON_IsObject(env_from_local_nonprimitive)){
            goto end;
        }
        v1_env_from_source_t *env_fromItem = v1_env_from_source_parseFromJSON(env_from_local_nonprimitive);

        list_addElement(env_fromList, env_fromItem);
    }
    }

    // v1alpha1_pod_preset_spec->selector
    cJSON *selector = cJSON_GetObjectItemCaseSensitive(v1alpha1_pod_preset_specJSON, "selector");
    v1_label_selector_t *selector_local_nonprim = NULL;
    if (selector) { 
    selector_local_nonprim = v1_label_selector_parseFromJSON(selector); //nonprimitive
    }

    // v1alpha1_pod_preset_spec->volume_mounts
    cJSON *volume_mounts = cJSON_GetObjectItemCaseSensitive(v1alpha1_pod_preset_specJSON, "volumeMounts");
    list_t *volume_mountsList;
    if (volume_mounts) { 
    cJSON *volume_mounts_local_nonprimitive;
    if(!cJSON_IsArray(volume_mounts)){
        goto end; //nonprimitive container
    }

    volume_mountsList = list_create();

    cJSON_ArrayForEach(volume_mounts_local_nonprimitive,volume_mounts )
    {
        if(!cJSON_IsObject(volume_mounts_local_nonprimitive)){
            goto end;
        }
        v1_volume_mount_t *volume_mountsItem = v1_volume_mount_parseFromJSON(volume_mounts_local_nonprimitive);

        list_addElement(volume_mountsList, volume_mountsItem);
    }
    }

    // v1alpha1_pod_preset_spec->volumes
    cJSON *volumes = cJSON_GetObjectItemCaseSensitive(v1alpha1_pod_preset_specJSON, "volumes");
    list_t *volumesList;
    if (volumes) { 
    cJSON *volumes_local_nonprimitive;
    if(!cJSON_IsArray(volumes)){
        goto end; //nonprimitive container
    }

    volumesList = list_create();

    cJSON_ArrayForEach(volumes_local_nonprimitive,volumes )
    {
        if(!cJSON_IsObject(volumes_local_nonprimitive)){
            goto end;
        }
        v1_volume_t *volumesItem = v1_volume_parseFromJSON(volumes_local_nonprimitive);

        list_addElement(volumesList, volumesItem);
    }
    }


    v1alpha1_pod_preset_spec_local_var = v1alpha1_pod_preset_spec_create (
        env ? envList : NULL,
        env_from ? env_fromList : NULL,
        selector ? selector_local_nonprim : NULL,
        volume_mounts ? volume_mountsList : NULL,
        volumes ? volumesList : NULL
        );

    return v1alpha1_pod_preset_spec_local_var;
end:
    if (selector_local_nonprim) {
        v1_label_selector_free(selector_local_nonprim);
        selector_local_nonprim = NULL;
    }
    return NULL;

}
