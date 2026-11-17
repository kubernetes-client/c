#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_group_version_kind.h"



static v1_group_version_kind_t *v1_group_version_kind_create_internal(
    char *group,
    char *version,
    char *kind
    ) {
    v1_group_version_kind_t *v1_group_version_kind_local_var = malloc(sizeof(v1_group_version_kind_t));
    if (!v1_group_version_kind_local_var) {
        return NULL;
    }
    memset(v1_group_version_kind_local_var, 0, sizeof(v1_group_version_kind_t));
    v1_group_version_kind_local_var->_library_owned = 1;
    v1_group_version_kind_local_var->group = group;
    v1_group_version_kind_local_var->version = version;
    v1_group_version_kind_local_var->kind = kind;
    return v1_group_version_kind_local_var;
}

__attribute__((deprecated)) v1_group_version_kind_t *v1_group_version_kind_create(
    char *group,
    char *version,
    char *kind
    ) {
    v1_group_version_kind_t *result = v1_group_version_kind_create_internal (
        group,
        version,
        kind
        );
    if (!result) {
    }
    return result;
}

void v1_group_version_kind_free(v1_group_version_kind_t *v1_group_version_kind) {
    if(NULL == v1_group_version_kind){
        return ;
    }
    if(v1_group_version_kind->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_group_version_kind_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_group_version_kind->group) {
        free(v1_group_version_kind->group);
        v1_group_version_kind->group = NULL;
    }
    if (v1_group_version_kind->version) {
        free(v1_group_version_kind->version);
        v1_group_version_kind->version = NULL;
    }
    if (v1_group_version_kind->kind) {
        free(v1_group_version_kind->kind);
        v1_group_version_kind->kind = NULL;
    }
    free(v1_group_version_kind);
}

cJSON *v1_group_version_kind_convertToJSON(v1_group_version_kind_t *v1_group_version_kind) {
    cJSON *item = cJSON_CreateObject();

    // v1_group_version_kind->group
    if(v1_group_version_kind->group) {
    if(cJSON_AddStringToObject(item, "group", v1_group_version_kind->group) == NULL) {
    goto fail; //String
    }
    }


    // v1_group_version_kind->version
    if(v1_group_version_kind->version) {
    if(cJSON_AddStringToObject(item, "version", v1_group_version_kind->version) == NULL) {
    goto fail; //String
    }
    }


    // v1_group_version_kind->kind
    if(v1_group_version_kind->kind) {
    if(cJSON_AddStringToObject(item, "kind", v1_group_version_kind->kind) == NULL) {
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

v1_group_version_kind_t *v1_group_version_kind_parseFromJSON(cJSON *v1_group_version_kindJSON){

    v1_group_version_kind_t *v1_group_version_kind_local_var = NULL;

    char *group_local_str = NULL;

    char *version_local_str = NULL;

    char *kind_local_str = NULL;

    // v1_group_version_kind->group
    cJSON *group = cJSON_GetObjectItemCaseSensitive(v1_group_version_kindJSON, "group");
    if (cJSON_IsNull(group)) {
        group = NULL;
    }
    if (group) { 
    if(!cJSON_IsString(group) && !cJSON_IsNull(group))
    {
    goto end; //String
    }
    }

    // v1_group_version_kind->version
    cJSON *version = cJSON_GetObjectItemCaseSensitive(v1_group_version_kindJSON, "version");
    if (cJSON_IsNull(version)) {
        version = NULL;
    }
    if (version) { 
    if(!cJSON_IsString(version) && !cJSON_IsNull(version))
    {
    goto end; //String
    }
    }

    // v1_group_version_kind->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_group_version_kindJSON, "kind");
    if (cJSON_IsNull(kind)) {
        kind = NULL;
    }
    if (kind) { 
    if(!cJSON_IsString(kind) && !cJSON_IsNull(kind))
    {
    goto end; //String
    }
    }


    if (group && !cJSON_IsNull(group)) group_local_str = strdup(group->valuestring);
    if (version && !cJSON_IsNull(version)) version_local_str = strdup(version->valuestring);
    if (kind && !cJSON_IsNull(kind)) kind_local_str = strdup(kind->valuestring);

    v1_group_version_kind_local_var = v1_group_version_kind_create_internal (
        group_local_str,
        version_local_str,
        kind_local_str
        );

    if (!v1_group_version_kind_local_var) {
        goto end;
    }

    return v1_group_version_kind_local_var;
end:
    if (group_local_str) {
        free(group_local_str);
        group_local_str = NULL;
    }
    if (version_local_str) {
        free(version_local_str);
        version_local_str = NULL;
    }
    if (kind_local_str) {
        free(kind_local_str);
        kind_local_str = NULL;
    }
    return NULL;

}
