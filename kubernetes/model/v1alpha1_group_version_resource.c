#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha1_group_version_resource.h"



v1alpha1_group_version_resource_t *v1alpha1_group_version_resource_create(
    char *group,
    char *resource,
    char *version
    ) {
    v1alpha1_group_version_resource_t *v1alpha1_group_version_resource_local_var = malloc(sizeof(v1alpha1_group_version_resource_t));
    if (!v1alpha1_group_version_resource_local_var) {
        return NULL;
    }
    v1alpha1_group_version_resource_local_var->group = group;
    v1alpha1_group_version_resource_local_var->resource = resource;
    v1alpha1_group_version_resource_local_var->version = version;

    return v1alpha1_group_version_resource_local_var;
}


void v1alpha1_group_version_resource_free(v1alpha1_group_version_resource_t *v1alpha1_group_version_resource) {
    if(NULL == v1alpha1_group_version_resource){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha1_group_version_resource->group) {
        free(v1alpha1_group_version_resource->group);
        v1alpha1_group_version_resource->group = NULL;
    }
    if (v1alpha1_group_version_resource->resource) {
        free(v1alpha1_group_version_resource->resource);
        v1alpha1_group_version_resource->resource = NULL;
    }
    if (v1alpha1_group_version_resource->version) {
        free(v1alpha1_group_version_resource->version);
        v1alpha1_group_version_resource->version = NULL;
    }
    free(v1alpha1_group_version_resource);
}

cJSON *v1alpha1_group_version_resource_convertToJSON(v1alpha1_group_version_resource_t *v1alpha1_group_version_resource) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha1_group_version_resource->group
    if(v1alpha1_group_version_resource->group) {
    if(cJSON_AddStringToObject(item, "group", v1alpha1_group_version_resource->group) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha1_group_version_resource->resource
    if(v1alpha1_group_version_resource->resource) {
    if(cJSON_AddStringToObject(item, "resource", v1alpha1_group_version_resource->resource) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha1_group_version_resource->version
    if(v1alpha1_group_version_resource->version) {
    if(cJSON_AddStringToObject(item, "version", v1alpha1_group_version_resource->version) == NULL) {
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

v1alpha1_group_version_resource_t *v1alpha1_group_version_resource_parseFromJSON(cJSON *v1alpha1_group_version_resourceJSON){

    v1alpha1_group_version_resource_t *v1alpha1_group_version_resource_local_var = NULL;

    // v1alpha1_group_version_resource->group
    cJSON *group = cJSON_GetObjectItemCaseSensitive(v1alpha1_group_version_resourceJSON, "group");
    if (group) { 
    if(!cJSON_IsString(group) && !cJSON_IsNull(group))
    {
    goto end; //String
    }
    }

    // v1alpha1_group_version_resource->resource
    cJSON *resource = cJSON_GetObjectItemCaseSensitive(v1alpha1_group_version_resourceJSON, "resource");
    if (resource) { 
    if(!cJSON_IsString(resource) && !cJSON_IsNull(resource))
    {
    goto end; //String
    }
    }

    // v1alpha1_group_version_resource->version
    cJSON *version = cJSON_GetObjectItemCaseSensitive(v1alpha1_group_version_resourceJSON, "version");
    if (version) { 
    if(!cJSON_IsString(version) && !cJSON_IsNull(version))
    {
    goto end; //String
    }
    }


    v1alpha1_group_version_resource_local_var = v1alpha1_group_version_resource_create (
        group && !cJSON_IsNull(group) ? strdup(group->valuestring) : NULL,
        resource && !cJSON_IsNull(resource) ? strdup(resource->valuestring) : NULL,
        version && !cJSON_IsNull(version) ? strdup(version->valuestring) : NULL
        );

    return v1alpha1_group_version_resource_local_var;
end:
    return NULL;

}
