#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_quobyte_volume_source.h"



static v1_quobyte_volume_source_t *v1_quobyte_volume_source_create_internal(
    char *group,
    int *read_only,
    char *registry,
    char *tenant,
    char *user,
    char *volume
    ) {
    v1_quobyte_volume_source_t *v1_quobyte_volume_source_local_var = malloc(sizeof(v1_quobyte_volume_source_t));
    if (!v1_quobyte_volume_source_local_var) {
        return NULL;
    }
    memset(v1_quobyte_volume_source_local_var, 0, sizeof(v1_quobyte_volume_source_t));
    v1_quobyte_volume_source_local_var->_library_owned = 1;
    v1_quobyte_volume_source_local_var->group = group;
    v1_quobyte_volume_source_local_var->read_only = read_only;
    v1_quobyte_volume_source_local_var->registry = registry;
    v1_quobyte_volume_source_local_var->tenant = tenant;
    v1_quobyte_volume_source_local_var->user = user;
    v1_quobyte_volume_source_local_var->volume = volume;
    return v1_quobyte_volume_source_local_var;
}

__attribute__((deprecated)) v1_quobyte_volume_source_t *v1_quobyte_volume_source_create(
    char *group,
    int *read_only,
    char *registry,
    char *tenant,
    char *user,
    char *volume
    ) {
    int *read_only_copy = NULL;
    if (read_only) {
        read_only_copy = malloc(sizeof(int));
        if (read_only_copy) *read_only_copy = *read_only;
    }
    v1_quobyte_volume_source_t *result = v1_quobyte_volume_source_create_internal (
        group,
        read_only_copy,
        registry,
        tenant,
        user,
        volume
        );
    if (!result) {
        free(read_only_copy);
    }
    return result;
}

void v1_quobyte_volume_source_free(v1_quobyte_volume_source_t *v1_quobyte_volume_source) {
    if(NULL == v1_quobyte_volume_source){
        return ;
    }
    if(v1_quobyte_volume_source->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_quobyte_volume_source_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_quobyte_volume_source->group) {
        free(v1_quobyte_volume_source->group);
        v1_quobyte_volume_source->group = NULL;
    }
    if (v1_quobyte_volume_source->read_only) {
        free(v1_quobyte_volume_source->read_only);
        v1_quobyte_volume_source->read_only = NULL;
    }
    if (v1_quobyte_volume_source->registry) {
        free(v1_quobyte_volume_source->registry);
        v1_quobyte_volume_source->registry = NULL;
    }
    if (v1_quobyte_volume_source->tenant) {
        free(v1_quobyte_volume_source->tenant);
        v1_quobyte_volume_source->tenant = NULL;
    }
    if (v1_quobyte_volume_source->user) {
        free(v1_quobyte_volume_source->user);
        v1_quobyte_volume_source->user = NULL;
    }
    if (v1_quobyte_volume_source->volume) {
        free(v1_quobyte_volume_source->volume);
        v1_quobyte_volume_source->volume = NULL;
    }
    free(v1_quobyte_volume_source);
}

cJSON *v1_quobyte_volume_source_convertToJSON(v1_quobyte_volume_source_t *v1_quobyte_volume_source) {
    cJSON *item = cJSON_CreateObject();

    // v1_quobyte_volume_source->group
    if(v1_quobyte_volume_source->group) {
    if(cJSON_AddStringToObject(item, "group", v1_quobyte_volume_source->group) == NULL) {
    goto fail; //String
    }
    }


    // v1_quobyte_volume_source->read_only
    if(v1_quobyte_volume_source->read_only) {
    if(cJSON_AddBoolToObject(item, "readOnly", *v1_quobyte_volume_source->read_only) == NULL) {
    goto fail; //Bool
    }
    }


    // v1_quobyte_volume_source->registry
    if (!v1_quobyte_volume_source->registry) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "registry", v1_quobyte_volume_source->registry) == NULL) {
    goto fail; //String
    }


    // v1_quobyte_volume_source->tenant
    if(v1_quobyte_volume_source->tenant) {
    if(cJSON_AddStringToObject(item, "tenant", v1_quobyte_volume_source->tenant) == NULL) {
    goto fail; //String
    }
    }


    // v1_quobyte_volume_source->user
    if(v1_quobyte_volume_source->user) {
    if(cJSON_AddStringToObject(item, "user", v1_quobyte_volume_source->user) == NULL) {
    goto fail; //String
    }
    }


    // v1_quobyte_volume_source->volume
    if (!v1_quobyte_volume_source->volume) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "volume", v1_quobyte_volume_source->volume) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_quobyte_volume_source_t *v1_quobyte_volume_source_parseFromJSON(cJSON *v1_quobyte_volume_sourceJSON){

    v1_quobyte_volume_source_t *v1_quobyte_volume_source_local_var = NULL;

    char *group_local_str = NULL;

    // define the local variable for v1_quobyte_volume_source->read_only
    int *read_only_local_var = NULL;

    char *registry_local_str = NULL;

    char *tenant_local_str = NULL;

    char *user_local_str = NULL;

    char *volume_local_str = NULL;

    // v1_quobyte_volume_source->group
    cJSON *group = cJSON_GetObjectItemCaseSensitive(v1_quobyte_volume_sourceJSON, "group");
    if (cJSON_IsNull(group)) {
        group = NULL;
    }
    if (group) { 
    if(!cJSON_IsString(group) && !cJSON_IsNull(group))
    {
    goto end; //String
    }
    }

    // v1_quobyte_volume_source->read_only
    cJSON *read_only = cJSON_GetObjectItemCaseSensitive(v1_quobyte_volume_sourceJSON, "readOnly");
    if (cJSON_IsNull(read_only)) {
        read_only = NULL;
    }
    if (read_only) { 
    if(!cJSON_IsBool(read_only))
    {
    goto end; //Bool
    }
    read_only_local_var = malloc(sizeof(int));
    if(!read_only_local_var)
    {
        goto end;
    }
    *read_only_local_var = read_only->valueint;
    }

    // v1_quobyte_volume_source->registry
    cJSON *registry = cJSON_GetObjectItemCaseSensitive(v1_quobyte_volume_sourceJSON, "registry");
    if (cJSON_IsNull(registry)) {
        registry = NULL;
    }
    if (!registry) {
        goto end;
    }

    
    if(!cJSON_IsString(registry))
    {
    goto end; //String
    }

    // v1_quobyte_volume_source->tenant
    cJSON *tenant = cJSON_GetObjectItemCaseSensitive(v1_quobyte_volume_sourceJSON, "tenant");
    if (cJSON_IsNull(tenant)) {
        tenant = NULL;
    }
    if (tenant) { 
    if(!cJSON_IsString(tenant) && !cJSON_IsNull(tenant))
    {
    goto end; //String
    }
    }

    // v1_quobyte_volume_source->user
    cJSON *user = cJSON_GetObjectItemCaseSensitive(v1_quobyte_volume_sourceJSON, "user");
    if (cJSON_IsNull(user)) {
        user = NULL;
    }
    if (user) { 
    if(!cJSON_IsString(user) && !cJSON_IsNull(user))
    {
    goto end; //String
    }
    }

    // v1_quobyte_volume_source->volume
    cJSON *volume = cJSON_GetObjectItemCaseSensitive(v1_quobyte_volume_sourceJSON, "volume");
    if (cJSON_IsNull(volume)) {
        volume = NULL;
    }
    if (!volume) {
        goto end;
    }

    
    if(!cJSON_IsString(volume))
    {
    goto end; //String
    }


    if (group && !cJSON_IsNull(group)) group_local_str = strdup(group->valuestring);
    if (registry && !cJSON_IsNull(registry)) registry_local_str = strdup(registry->valuestring);
    if (tenant && !cJSON_IsNull(tenant)) tenant_local_str = strdup(tenant->valuestring);
    if (user && !cJSON_IsNull(user)) user_local_str = strdup(user->valuestring);
    if (volume && !cJSON_IsNull(volume)) volume_local_str = strdup(volume->valuestring);

    v1_quobyte_volume_source_local_var = v1_quobyte_volume_source_create_internal (
        group_local_str,
        read_only_local_var,
        registry_local_str,
        tenant_local_str,
        user_local_str,
        volume_local_str
        );

    if (!v1_quobyte_volume_source_local_var) {
        goto end;
    }

    return v1_quobyte_volume_source_local_var;
end:
    if (group_local_str) {
        free(group_local_str);
        group_local_str = NULL;
    }
    if (read_only_local_var) {
        free(read_only_local_var);
        read_only_local_var = NULL;
    }
    if (registry_local_str) {
        free(registry_local_str);
        registry_local_str = NULL;
    }
    if (tenant_local_str) {
        free(tenant_local_str);
        tenant_local_str = NULL;
    }
    if (user_local_str) {
        free(user_local_str);
        user_local_str = NULL;
    }
    if (volume_local_str) {
        free(volume_local_str);
        volume_local_str = NULL;
    }
    return NULL;

}
