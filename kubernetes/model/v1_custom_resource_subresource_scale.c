#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_custom_resource_subresource_scale.h"



v1_custom_resource_subresource_scale_t *v1_custom_resource_subresource_scale_create(
    char *label_selector_path,
    char *spec_replicas_path,
    char *status_replicas_path
    ) {
    v1_custom_resource_subresource_scale_t *v1_custom_resource_subresource_scale_local_var = malloc(sizeof(v1_custom_resource_subresource_scale_t));
    if (!v1_custom_resource_subresource_scale_local_var) {
        return NULL;
    }
    v1_custom_resource_subresource_scale_local_var->label_selector_path = label_selector_path;
    v1_custom_resource_subresource_scale_local_var->spec_replicas_path = spec_replicas_path;
    v1_custom_resource_subresource_scale_local_var->status_replicas_path = status_replicas_path;

    return v1_custom_resource_subresource_scale_local_var;
}


void v1_custom_resource_subresource_scale_free(v1_custom_resource_subresource_scale_t *v1_custom_resource_subresource_scale) {
    if(NULL == v1_custom_resource_subresource_scale){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_custom_resource_subresource_scale->label_selector_path) {
        free(v1_custom_resource_subresource_scale->label_selector_path);
        v1_custom_resource_subresource_scale->label_selector_path = NULL;
    }
    if (v1_custom_resource_subresource_scale->spec_replicas_path) {
        free(v1_custom_resource_subresource_scale->spec_replicas_path);
        v1_custom_resource_subresource_scale->spec_replicas_path = NULL;
    }
    if (v1_custom_resource_subresource_scale->status_replicas_path) {
        free(v1_custom_resource_subresource_scale->status_replicas_path);
        v1_custom_resource_subresource_scale->status_replicas_path = NULL;
    }
    free(v1_custom_resource_subresource_scale);
}

cJSON *v1_custom_resource_subresource_scale_convertToJSON(v1_custom_resource_subresource_scale_t *v1_custom_resource_subresource_scale) {
    cJSON *item = cJSON_CreateObject();

    // v1_custom_resource_subresource_scale->label_selector_path
    if(v1_custom_resource_subresource_scale->label_selector_path) { 
    if(cJSON_AddStringToObject(item, "labelSelectorPath", v1_custom_resource_subresource_scale->label_selector_path) == NULL) {
    goto fail; //String
    }
     } 


    // v1_custom_resource_subresource_scale->spec_replicas_path
    if (!v1_custom_resource_subresource_scale->spec_replicas_path) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "specReplicasPath", v1_custom_resource_subresource_scale->spec_replicas_path) == NULL) {
    goto fail; //String
    }


    // v1_custom_resource_subresource_scale->status_replicas_path
    if (!v1_custom_resource_subresource_scale->status_replicas_path) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "statusReplicasPath", v1_custom_resource_subresource_scale->status_replicas_path) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_custom_resource_subresource_scale_t *v1_custom_resource_subresource_scale_parseFromJSON(cJSON *v1_custom_resource_subresource_scaleJSON){

    v1_custom_resource_subresource_scale_t *v1_custom_resource_subresource_scale_local_var = NULL;

    // v1_custom_resource_subresource_scale->label_selector_path
    cJSON *label_selector_path = cJSON_GetObjectItemCaseSensitive(v1_custom_resource_subresource_scaleJSON, "labelSelectorPath");
    if (label_selector_path) { 
    if(!cJSON_IsString(label_selector_path))
    {
    goto end; //String
    }
    }

    // v1_custom_resource_subresource_scale->spec_replicas_path
    cJSON *spec_replicas_path = cJSON_GetObjectItemCaseSensitive(v1_custom_resource_subresource_scaleJSON, "specReplicasPath");
    if (!spec_replicas_path) {
        goto end;
    }

    
    if(!cJSON_IsString(spec_replicas_path))
    {
    goto end; //String
    }

    // v1_custom_resource_subresource_scale->status_replicas_path
    cJSON *status_replicas_path = cJSON_GetObjectItemCaseSensitive(v1_custom_resource_subresource_scaleJSON, "statusReplicasPath");
    if (!status_replicas_path) {
        goto end;
    }

    
    if(!cJSON_IsString(status_replicas_path))
    {
    goto end; //String
    }


    v1_custom_resource_subresource_scale_local_var = v1_custom_resource_subresource_scale_create (
        label_selector_path ? strdup(label_selector_path->valuestring) : NULL,
        strdup(spec_replicas_path->valuestring),
        strdup(status_replicas_path->valuestring)
        );

    return v1_custom_resource_subresource_scale_local_var;
end:
    return NULL;

}
