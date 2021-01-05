#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_owner_reference.h"



v1_owner_reference_t *v1_owner_reference_create(
    char *api_version,
    int block_owner_deletion,
    int controller,
    char *kind,
    char *name,
    char *uid
    ) {
    v1_owner_reference_t *v1_owner_reference_local_var = malloc(sizeof(v1_owner_reference_t));
    if (!v1_owner_reference_local_var) {
        return NULL;
    }
    v1_owner_reference_local_var->api_version = api_version;
    v1_owner_reference_local_var->block_owner_deletion = block_owner_deletion;
    v1_owner_reference_local_var->controller = controller;
    v1_owner_reference_local_var->kind = kind;
    v1_owner_reference_local_var->name = name;
    v1_owner_reference_local_var->uid = uid;

    return v1_owner_reference_local_var;
}


void v1_owner_reference_free(v1_owner_reference_t *v1_owner_reference) {
    if(NULL == v1_owner_reference){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_owner_reference->api_version) {
        free(v1_owner_reference->api_version);
        v1_owner_reference->api_version = NULL;
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
    if(cJSON_AddBoolToObject(item, "blockOwnerDeletion", v1_owner_reference->block_owner_deletion) == NULL) {
    goto fail; //Bool
    }
     } 


    // v1_owner_reference->controller
    if(v1_owner_reference->controller) { 
    if(cJSON_AddBoolToObject(item, "controller", v1_owner_reference->controller) == NULL) {
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

    // v1_owner_reference->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1_owner_referenceJSON, "apiVersion");
    if (!api_version) {
        goto end;
    }

    
    if(!cJSON_IsString(api_version))
    {
    goto end; //String
    }

    // v1_owner_reference->block_owner_deletion
    cJSON *block_owner_deletion = cJSON_GetObjectItemCaseSensitive(v1_owner_referenceJSON, "blockOwnerDeletion");
    if (block_owner_deletion) { 
    if(!cJSON_IsBool(block_owner_deletion))
    {
    goto end; //Bool
    }
    }

    // v1_owner_reference->controller
    cJSON *controller = cJSON_GetObjectItemCaseSensitive(v1_owner_referenceJSON, "controller");
    if (controller) { 
    if(!cJSON_IsBool(controller))
    {
    goto end; //Bool
    }
    }

    // v1_owner_reference->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_owner_referenceJSON, "kind");
    if (!kind) {
        goto end;
    }

    
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }

    // v1_owner_reference->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1_owner_referenceJSON, "name");
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // v1_owner_reference->uid
    cJSON *uid = cJSON_GetObjectItemCaseSensitive(v1_owner_referenceJSON, "uid");
    if (!uid) {
        goto end;
    }

    
    if(!cJSON_IsString(uid))
    {
    goto end; //String
    }


    v1_owner_reference_local_var = v1_owner_reference_create (
        strdup(api_version->valuestring),
        block_owner_deletion ? block_owner_deletion->valueint : 0,
        controller ? controller->valueint : 0,
        strdup(kind->valuestring),
        strdup(name->valuestring),
        strdup(uid->valuestring)
        );

    return v1_owner_reference_local_var;
end:
    return NULL;

}
