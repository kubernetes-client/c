#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_role_ref.h"



static v1_role_ref_t *v1_role_ref_create_internal(
    char *api_group,
    char *kind,
    char *name
    ) {
    v1_role_ref_t *v1_role_ref_local_var = malloc(sizeof(v1_role_ref_t));
    if (!v1_role_ref_local_var) {
        return NULL;
    }
    v1_role_ref_local_var->api_group = api_group;
    v1_role_ref_local_var->kind = kind;
    v1_role_ref_local_var->name = name;

    v1_role_ref_local_var->_library_owned = 1;
    return v1_role_ref_local_var;
}

__attribute__((deprecated)) v1_role_ref_t *v1_role_ref_create(
    char *api_group,
    char *kind,
    char *name
    ) {
    return v1_role_ref_create_internal (
        api_group,
        kind,
        name
        );
}

void v1_role_ref_free(v1_role_ref_t *v1_role_ref) {
    if(NULL == v1_role_ref){
        return ;
    }
    if(v1_role_ref->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_role_ref_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_role_ref->api_group) {
        free(v1_role_ref->api_group);
        v1_role_ref->api_group = NULL;
    }
    if (v1_role_ref->kind) {
        free(v1_role_ref->kind);
        v1_role_ref->kind = NULL;
    }
    if (v1_role_ref->name) {
        free(v1_role_ref->name);
        v1_role_ref->name = NULL;
    }
    free(v1_role_ref);
}

cJSON *v1_role_ref_convertToJSON(v1_role_ref_t *v1_role_ref) {
    cJSON *item = cJSON_CreateObject();

    // v1_role_ref->api_group
    if (!v1_role_ref->api_group) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "apiGroup", v1_role_ref->api_group) == NULL) {
    goto fail; //String
    }


    // v1_role_ref->kind
    if (!v1_role_ref->kind) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "kind", v1_role_ref->kind) == NULL) {
    goto fail; //String
    }


    // v1_role_ref->name
    if (!v1_role_ref->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", v1_role_ref->name) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_role_ref_t *v1_role_ref_parseFromJSON(cJSON *v1_role_refJSON){

    v1_role_ref_t *v1_role_ref_local_var = NULL;

    // v1_role_ref->api_group
    cJSON *api_group = cJSON_GetObjectItemCaseSensitive(v1_role_refJSON, "apiGroup");
    if (cJSON_IsNull(api_group)) {
        api_group = NULL;
    }
    if (!api_group) {
        goto end;
    }

    
    if(!cJSON_IsString(api_group))
    {
    goto end; //String
    }

    // v1_role_ref->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_role_refJSON, "kind");
    if (cJSON_IsNull(kind)) {
        kind = NULL;
    }
    if (!kind) {
        goto end;
    }

    
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }

    // v1_role_ref->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1_role_refJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }


    v1_role_ref_local_var = v1_role_ref_create_internal (
        strdup(api_group->valuestring),
        strdup(kind->valuestring),
        strdup(name->valuestring)
        );

    return v1_role_ref_local_var;
end:
    return NULL;

}
