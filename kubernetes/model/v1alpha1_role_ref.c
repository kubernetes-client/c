#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha1_role_ref.h"



v1alpha1_role_ref_t *v1alpha1_role_ref_create(
    char *api_group,
    char *kind,
    char *name
    ) {
    v1alpha1_role_ref_t *v1alpha1_role_ref_local_var = malloc(sizeof(v1alpha1_role_ref_t));
    if (!v1alpha1_role_ref_local_var) {
        return NULL;
    }
    v1alpha1_role_ref_local_var->api_group = api_group;
    v1alpha1_role_ref_local_var->kind = kind;
    v1alpha1_role_ref_local_var->name = name;

    return v1alpha1_role_ref_local_var;
}


void v1alpha1_role_ref_free(v1alpha1_role_ref_t *v1alpha1_role_ref) {
    if(NULL == v1alpha1_role_ref){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha1_role_ref->api_group) {
        free(v1alpha1_role_ref->api_group);
        v1alpha1_role_ref->api_group = NULL;
    }
    if (v1alpha1_role_ref->kind) {
        free(v1alpha1_role_ref->kind);
        v1alpha1_role_ref->kind = NULL;
    }
    if (v1alpha1_role_ref->name) {
        free(v1alpha1_role_ref->name);
        v1alpha1_role_ref->name = NULL;
    }
    free(v1alpha1_role_ref);
}

cJSON *v1alpha1_role_ref_convertToJSON(v1alpha1_role_ref_t *v1alpha1_role_ref) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha1_role_ref->api_group
    if (!v1alpha1_role_ref->api_group) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "apiGroup", v1alpha1_role_ref->api_group) == NULL) {
    goto fail; //String
    }


    // v1alpha1_role_ref->kind
    if (!v1alpha1_role_ref->kind) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "kind", v1alpha1_role_ref->kind) == NULL) {
    goto fail; //String
    }


    // v1alpha1_role_ref->name
    if (!v1alpha1_role_ref->name) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "name", v1alpha1_role_ref->name) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1alpha1_role_ref_t *v1alpha1_role_ref_parseFromJSON(cJSON *v1alpha1_role_refJSON){

    v1alpha1_role_ref_t *v1alpha1_role_ref_local_var = NULL;

    // v1alpha1_role_ref->api_group
    cJSON *api_group = cJSON_GetObjectItemCaseSensitive(v1alpha1_role_refJSON, "apiGroup");
    if (!api_group) {
        goto end;
    }

    
    if(!cJSON_IsString(api_group))
    {
    goto end; //String
    }

    // v1alpha1_role_ref->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1alpha1_role_refJSON, "kind");
    if (!kind) {
        goto end;
    }

    
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }

    // v1alpha1_role_ref->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1alpha1_role_refJSON, "name");
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }


    v1alpha1_role_ref_local_var = v1alpha1_role_ref_create (
        strdup(api_group->valuestring),
        strdup(kind->valuestring),
        strdup(name->valuestring)
        );

    return v1alpha1_role_ref_local_var;
end:
    return NULL;

}
