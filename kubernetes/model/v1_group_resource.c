#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_group_resource.h"



static v1_group_resource_t *v1_group_resource_create_internal(
    char *group,
    char *resource
    ) {
    v1_group_resource_t *v1_group_resource_local_var = malloc(sizeof(v1_group_resource_t));
    if (!v1_group_resource_local_var) {
        return NULL;
    }
    memset(v1_group_resource_local_var, 0, sizeof(v1_group_resource_t));
    v1_group_resource_local_var->_library_owned = 1;
    v1_group_resource_local_var->group = group;
    v1_group_resource_local_var->resource = resource;
    return v1_group_resource_local_var;
}

__attribute__((deprecated)) v1_group_resource_t *v1_group_resource_create(
    char *group,
    char *resource
    ) {
    v1_group_resource_t *result = v1_group_resource_create_internal (
        group,
        resource
        );
    if (!result) {
    }
    return result;
}

void v1_group_resource_free(v1_group_resource_t *v1_group_resource) {
    if(NULL == v1_group_resource){
        return ;
    }
    if(v1_group_resource->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_group_resource_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_group_resource->group) {
        free(v1_group_resource->group);
        v1_group_resource->group = NULL;
    }
    if (v1_group_resource->resource) {
        free(v1_group_resource->resource);
        v1_group_resource->resource = NULL;
    }
    free(v1_group_resource);
}

cJSON *v1_group_resource_convertToJSON(v1_group_resource_t *v1_group_resource) {
    cJSON *item = cJSON_CreateObject();

    // v1_group_resource->group
    if (!v1_group_resource->group) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "group", v1_group_resource->group) == NULL) {
    goto fail; //String
    }


    // v1_group_resource->resource
    if (!v1_group_resource->resource) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "resource", v1_group_resource->resource) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_group_resource_t *v1_group_resource_parseFromJSON(cJSON *v1_group_resourceJSON){

    v1_group_resource_t *v1_group_resource_local_var = NULL;

    char *group_local_str = NULL;

    char *resource_local_str = NULL;

    // v1_group_resource->group
    cJSON *group = cJSON_GetObjectItemCaseSensitive(v1_group_resourceJSON, "group");
    if (cJSON_IsNull(group)) {
        group = NULL;
    }
    if (!group) {
        goto end;
    }

    
    if(!cJSON_IsString(group))
    {
    goto end; //String
    }

    // v1_group_resource->resource
    cJSON *resource = cJSON_GetObjectItemCaseSensitive(v1_group_resourceJSON, "resource");
    if (cJSON_IsNull(resource)) {
        resource = NULL;
    }
    if (!resource) {
        goto end;
    }

    
    if(!cJSON_IsString(resource))
    {
    goto end; //String
    }


    if (group && !cJSON_IsNull(group)) group_local_str = strdup(group->valuestring);
    if (resource && !cJSON_IsNull(resource)) resource_local_str = strdup(resource->valuestring);

    v1_group_resource_local_var = v1_group_resource_create_internal (
        group_local_str,
        resource_local_str
        );

    if (!v1_group_resource_local_var) {
        goto end;
    }

    return v1_group_resource_local_var;
end:
    if (group_local_str) {
        free(group_local_str);
        group_local_str = NULL;
    }
    if (resource_local_str) {
        free(resource_local_str);
        resource_local_str = NULL;
    }
    return NULL;

}
