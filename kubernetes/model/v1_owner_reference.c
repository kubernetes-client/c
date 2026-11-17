#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_owner_reference.h"



static v1_owner_reference_t *v1_owner_reference_create_internal(
    char *api_version,
    int *block_owner_deletion,
    int *controller,
    char *kind,
    char *name,
    char *uid
    ) {
    v1_owner_reference_t *v1_owner_reference_local_var = malloc(sizeof(v1_owner_reference_t));
    if (!v1_owner_reference_local_var) {
        return NULL;
    }
    memset(v1_owner_reference_local_var, 0, sizeof(v1_owner_reference_t));
    v1_owner_reference_local_var->_library_owned = 1;
    v1_owner_reference_local_var->api_version = api_version;
    v1_owner_reference_local_var->block_owner_deletion = block_owner_deletion;
    v1_owner_reference_local_var->controller = controller;
    v1_owner_reference_local_var->kind = kind;
    v1_owner_reference_local_var->name = name;
    v1_owner_reference_local_var->uid = uid;
    return v1_owner_reference_local_var;
}

__attribute__((deprecated)) v1_owner_reference_t *v1_owner_reference_create(
    char *api_version,
    int *block_owner_deletion,
    int *controller,
    char *kind,
    char *name,
    char *uid
    ) {
    int *block_owner_deletion_copy = NULL;
    if (block_owner_deletion) {
        block_owner_deletion_copy = malloc(sizeof(int));
        if (block_owner_deletion_copy) *block_owner_deletion_copy = *block_owner_deletion;
    }
    int *controller_copy = NULL;
    if (controller) {
        controller_copy = malloc(sizeof(int));
        if (controller_copy) *controller_copy = *controller;
    }
    v1_owner_reference_t *result = v1_owner_reference_create_internal (
        api_version,
        block_owner_deletion_copy,
        controller_copy,
        kind,
        name,
        uid
        );
    if (!result) {
        free(block_owner_deletion_copy);
        free(controller_copy);
    }
    return result;
}

void v1_owner_reference_free(v1_owner_reference_t *v1_owner_reference) {
    if(NULL == v1_owner_reference){
        return ;
    }
    if(v1_owner_reference->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_owner_reference_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_owner_reference->api_version) {
        free(v1_owner_reference->api_version);
        v1_owner_reference->api_version = NULL;
    }
    if (v1_owner_reference->block_owner_deletion) {
        free(v1_owner_reference->block_owner_deletion);
        v1_owner_reference->block_owner_deletion = NULL;
    }
    if (v1_owner_reference->controller) {
        free(v1_owner_reference->controller);
        v1_owner_reference->controller = NULL;
    }
    if (v1_owner_reference->kind) {
        free(v1_owner_reference->kind);
        v1_owner_reference->kind = NULL;
    }
    if (v1_owner_reference->name) {
        free(v1_owner_reference->name);
        v1_owner_reference->name = NULL;
    }
    if (v1_owner_reference->uid) {
        free(v1_owner_reference->uid);
        v1_owner_reference->uid = NULL;
    }
    free(v1_owner_reference);
}

cJSON *v1_owner_reference_convertToJSON(v1_owner_reference_t *v1_owner_reference) {
    cJSON *item = cJSON_CreateObject();

    // v1_owner_reference->api_version
    if (!v1_owner_reference->api_version) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "apiVersion", v1_owner_reference->api_version) == NULL) {
    goto fail; //String
    }


    // v1_owner_reference->block_owner_deletion
    if(v1_owner_reference->block_owner_deletion) {
    if(cJSON_AddBoolToObject(item, "blockOwnerDeletion", *v1_owner_reference->block_owner_deletion) == NULL) {
    goto fail; //Bool
    }
    }


    // v1_owner_reference->controller
    if(v1_owner_reference->controller) {
    if(cJSON_AddBoolToObject(item, "controller", *v1_owner_reference->controller) == NULL) {
    goto fail; //Bool
    }
    }


    // v1_owner_reference->kind
    if (!v1_owner_reference->kind) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "kind", v1_owner_reference->kind) == NULL) {
    goto fail; //String
    }


    // v1_owner_reference->name
    if (!v1_owner_reference->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", v1_owner_reference->name) == NULL) {
    goto fail; //String
    }


    // v1_owner_reference->uid
    if (!v1_owner_reference->uid) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "uid", v1_owner_reference->uid) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_owner_reference_t *v1_owner_reference_parseFromJSON(cJSON *v1_owner_referenceJSON){

    v1_owner_reference_t *v1_owner_reference_local_var = NULL;

    char *api_version_local_str = NULL;

    // define the local variable for v1_owner_reference->block_owner_deletion
    int *block_owner_deletion_local_var = NULL;

    // define the local variable for v1_owner_reference->controller
    int *controller_local_var = NULL;

    char *kind_local_str = NULL;

    char *name_local_str = NULL;

    char *uid_local_str = NULL;

    // v1_owner_reference->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1_owner_referenceJSON, "apiVersion");
    if (cJSON_IsNull(api_version)) {
        api_version = NULL;
    }
    if (!api_version) {
        goto end;
    }

    
    if(!cJSON_IsString(api_version))
    {
    goto end; //String
    }

    // v1_owner_reference->block_owner_deletion
    cJSON *block_owner_deletion = cJSON_GetObjectItemCaseSensitive(v1_owner_referenceJSON, "blockOwnerDeletion");
    if (cJSON_IsNull(block_owner_deletion)) {
        block_owner_deletion = NULL;
    }
    if (block_owner_deletion) { 
    if(!cJSON_IsBool(block_owner_deletion))
    {
    goto end; //Bool
    }
    block_owner_deletion_local_var = malloc(sizeof(int));
    if(!block_owner_deletion_local_var)
    {
        goto end;
    }
    *block_owner_deletion_local_var = block_owner_deletion->valueint;
    }

    // v1_owner_reference->controller
    cJSON *controller = cJSON_GetObjectItemCaseSensitive(v1_owner_referenceJSON, "controller");
    if (cJSON_IsNull(controller)) {
        controller = NULL;
    }
    if (controller) { 
    if(!cJSON_IsBool(controller))
    {
    goto end; //Bool
    }
    controller_local_var = malloc(sizeof(int));
    if(!controller_local_var)
    {
        goto end;
    }
    *controller_local_var = controller->valueint;
    }

    // v1_owner_reference->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_owner_referenceJSON, "kind");
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

    // v1_owner_reference->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1_owner_referenceJSON, "name");
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

    // v1_owner_reference->uid
    cJSON *uid = cJSON_GetObjectItemCaseSensitive(v1_owner_referenceJSON, "uid");
    if (cJSON_IsNull(uid)) {
        uid = NULL;
    }
    if (!uid) {
        goto end;
    }

    
    if(!cJSON_IsString(uid))
    {
    goto end; //String
    }


    if (api_version && !cJSON_IsNull(api_version)) api_version_local_str = strdup(api_version->valuestring);
    if (kind && !cJSON_IsNull(kind)) kind_local_str = strdup(kind->valuestring);
    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);
    if (uid && !cJSON_IsNull(uid)) uid_local_str = strdup(uid->valuestring);

    v1_owner_reference_local_var = v1_owner_reference_create_internal (
        api_version_local_str,
        block_owner_deletion_local_var,
        controller_local_var,
        kind_local_str,
        name_local_str,
        uid_local_str
        );

    if (!v1_owner_reference_local_var) {
        goto end;
    }

    return v1_owner_reference_local_var;
end:
    if (api_version_local_str) {
        free(api_version_local_str);
        api_version_local_str = NULL;
    }
    if (block_owner_deletion_local_var) {
        free(block_owner_deletion_local_var);
        block_owner_deletion_local_var = NULL;
    }
    if (controller_local_var) {
        free(controller_local_var);
        controller_local_var = NULL;
    }
    if (kind_local_str) {
        free(kind_local_str);
        kind_local_str = NULL;
    }
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    if (uid_local_str) {
        free(uid_local_str);
        uid_local_str = NULL;
    }
    return NULL;

}
