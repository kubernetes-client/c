#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "apps_v1beta1_deployment_rollback.h"



apps_v1beta1_deployment_rollback_t *apps_v1beta1_deployment_rollback_create(
    char *api_version,
    char *kind,
    char *name,
    apps_v1beta1_rollback_config_t *rollback_to,
    list_t* updated_annotations
    ) {
    apps_v1beta1_deployment_rollback_t *apps_v1beta1_deployment_rollback_local_var = malloc(sizeof(apps_v1beta1_deployment_rollback_t));
    if (!apps_v1beta1_deployment_rollback_local_var) {
        return NULL;
    }
    apps_v1beta1_deployment_rollback_local_var->api_version = api_version;
    apps_v1beta1_deployment_rollback_local_var->kind = kind;
    apps_v1beta1_deployment_rollback_local_var->name = name;
    apps_v1beta1_deployment_rollback_local_var->rollback_to = rollback_to;
    apps_v1beta1_deployment_rollback_local_var->updated_annotations = updated_annotations;

    return apps_v1beta1_deployment_rollback_local_var;
}


void apps_v1beta1_deployment_rollback_free(apps_v1beta1_deployment_rollback_t *apps_v1beta1_deployment_rollback) {
    if(NULL == apps_v1beta1_deployment_rollback){
        return ;
    }
    listEntry_t *listEntry;
    if (apps_v1beta1_deployment_rollback->api_version) {
        free(apps_v1beta1_deployment_rollback->api_version);
        apps_v1beta1_deployment_rollback->api_version = NULL;
    }
    if (apps_v1beta1_deployment_rollback->kind) {
        free(apps_v1beta1_deployment_rollback->kind);
        apps_v1beta1_deployment_rollback->kind = NULL;
    }
    if (apps_v1beta1_deployment_rollback->name) {
        free(apps_v1beta1_deployment_rollback->name);
        apps_v1beta1_deployment_rollback->name = NULL;
    }
    if (apps_v1beta1_deployment_rollback->rollback_to) {
        apps_v1beta1_rollback_config_free(apps_v1beta1_deployment_rollback->rollback_to);
        apps_v1beta1_deployment_rollback->rollback_to = NULL;
    }
    if (apps_v1beta1_deployment_rollback->updated_annotations) {
        list_ForEach(listEntry, apps_v1beta1_deployment_rollback->updated_annotations) {
            keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_free(apps_v1beta1_deployment_rollback->updated_annotations);
        apps_v1beta1_deployment_rollback->updated_annotations = NULL;
    }
    free(apps_v1beta1_deployment_rollback);
}

cJSON *apps_v1beta1_deployment_rollback_convertToJSON(apps_v1beta1_deployment_rollback_t *apps_v1beta1_deployment_rollback) {
    cJSON *item = cJSON_CreateObject();

    // apps_v1beta1_deployment_rollback->api_version
    if(apps_v1beta1_deployment_rollback->api_version) { 
    if(cJSON_AddStringToObject(item, "apiVersion", apps_v1beta1_deployment_rollback->api_version) == NULL) {
    goto fail; //String
    }
     } 


    // apps_v1beta1_deployment_rollback->kind
    if(apps_v1beta1_deployment_rollback->kind) { 
    if(cJSON_AddStringToObject(item, "kind", apps_v1beta1_deployment_rollback->kind) == NULL) {
    goto fail; //String
    }
     } 


    // apps_v1beta1_deployment_rollback->name
    if (!apps_v1beta1_deployment_rollback->name) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "name", apps_v1beta1_deployment_rollback->name) == NULL) {
    goto fail; //String
    }


    // apps_v1beta1_deployment_rollback->rollback_to
    if (!apps_v1beta1_deployment_rollback->rollback_to) {
        goto fail;
    }
    
    cJSON *rollback_to_local_JSON = apps_v1beta1_rollback_config_convertToJSON(apps_v1beta1_deployment_rollback->rollback_to);
    if(rollback_to_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "rollbackTo", rollback_to_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // apps_v1beta1_deployment_rollback->updated_annotations
    if(apps_v1beta1_deployment_rollback->updated_annotations) { 
    cJSON *updated_annotations = cJSON_AddObjectToObject(item, "updatedAnnotations");
    if(updated_annotations == NULL) {
        goto fail; //primitive map container
    }
    cJSON *localMapObject = updated_annotations;
    listEntry_t *updated_annotationsListEntry;
    if (apps_v1beta1_deployment_rollback->updated_annotations) {
    list_ForEach(updated_annotationsListEntry, apps_v1beta1_deployment_rollback->updated_annotations) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)updated_annotationsListEntry->data;
        if(cJSON_AddStringToObject(localMapObject, localKeyValue->key, (char*)localKeyValue->value) == NULL)
        {
            goto fail;
        }
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

apps_v1beta1_deployment_rollback_t *apps_v1beta1_deployment_rollback_parseFromJSON(cJSON *apps_v1beta1_deployment_rollbackJSON){

    apps_v1beta1_deployment_rollback_t *apps_v1beta1_deployment_rollback_local_var = NULL;

    // apps_v1beta1_deployment_rollback->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(apps_v1beta1_deployment_rollbackJSON, "apiVersion");
    if (api_version) { 
    if(!cJSON_IsString(api_version))
    {
    goto end; //String
    }
    }

    // apps_v1beta1_deployment_rollback->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(apps_v1beta1_deployment_rollbackJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // apps_v1beta1_deployment_rollback->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(apps_v1beta1_deployment_rollbackJSON, "name");
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // apps_v1beta1_deployment_rollback->rollback_to
    cJSON *rollback_to = cJSON_GetObjectItemCaseSensitive(apps_v1beta1_deployment_rollbackJSON, "rollbackTo");
    if (!rollback_to) {
        goto end;
    }

    apps_v1beta1_rollback_config_t *rollback_to_local_nonprim = NULL;
    
    rollback_to_local_nonprim = apps_v1beta1_rollback_config_parseFromJSON(rollback_to); //nonprimitive

    // apps_v1beta1_deployment_rollback->updated_annotations
    cJSON *updated_annotations = cJSON_GetObjectItemCaseSensitive(apps_v1beta1_deployment_rollbackJSON, "updatedAnnotations");
    list_t *updated_annotationsList;
    if (updated_annotations) { 
    cJSON *updated_annotations_local_map;
    if(!cJSON_IsObject(updated_annotations)) {
        goto end;//primitive map container
    }
    updated_annotationsList = list_create();
    keyValuePair_t *localMapKeyPair;
    cJSON_ArrayForEach(updated_annotations_local_map, updated_annotations)
    {
		cJSON *localMapObject = updated_annotations_local_map;
        if(!cJSON_IsString(localMapObject))
        {
            goto end;
        }
        localMapKeyPair = keyValuePair_create(strdup(localMapObject->string),strdup(localMapObject->valuestring));
        list_addElement(updated_annotationsList , localMapKeyPair);
    }
    }


    apps_v1beta1_deployment_rollback_local_var = apps_v1beta1_deployment_rollback_create (
        api_version ? strdup(api_version->valuestring) : NULL,
        kind ? strdup(kind->valuestring) : NULL,
        strdup(name->valuestring),
        rollback_to_local_nonprim,
        updated_annotations ? updated_annotationsList : NULL
        );

    return apps_v1beta1_deployment_rollback_local_var;
end:
    if (rollback_to_local_nonprim) {
        apps_v1beta1_rollback_config_free(rollback_to_local_nonprim);
        rollback_to_local_nonprim = NULL;
    }
    return NULL;

}
