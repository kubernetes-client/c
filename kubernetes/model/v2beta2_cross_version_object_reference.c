#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v2beta2_cross_version_object_reference.h"



v2beta2_cross_version_object_reference_t *v2beta2_cross_version_object_reference_create(
    char *api_version,
    char *kind,
    char *name
    ) {
    v2beta2_cross_version_object_reference_t *v2beta2_cross_version_object_reference_local_var = malloc(sizeof(v2beta2_cross_version_object_reference_t));
    if (!v2beta2_cross_version_object_reference_local_var) {
        return NULL;
    }
    v2beta2_cross_version_object_reference_local_var->api_version = api_version;
    v2beta2_cross_version_object_reference_local_var->kind = kind;
    v2beta2_cross_version_object_reference_local_var->name = name;

    return v2beta2_cross_version_object_reference_local_var;
}


void v2beta2_cross_version_object_reference_free(v2beta2_cross_version_object_reference_t *v2beta2_cross_version_object_reference) {
    if(NULL == v2beta2_cross_version_object_reference){
        return ;
    }
    listEntry_t *listEntry;
    if (v2beta2_cross_version_object_reference->api_version) {
        free(v2beta2_cross_version_object_reference->api_version);
        v2beta2_cross_version_object_reference->api_version = NULL;
    }
    if (v2beta2_cross_version_object_reference->kind) {
        free(v2beta2_cross_version_object_reference->kind);
        v2beta2_cross_version_object_reference->kind = NULL;
    }
    if (v2beta2_cross_version_object_reference->name) {
        free(v2beta2_cross_version_object_reference->name);
        v2beta2_cross_version_object_reference->name = NULL;
    }
    free(v2beta2_cross_version_object_reference);
}

cJSON *v2beta2_cross_version_object_reference_convertToJSON(v2beta2_cross_version_object_reference_t *v2beta2_cross_version_object_reference) {
    cJSON *item = cJSON_CreateObject();

    // v2beta2_cross_version_object_reference->api_version
    if(v2beta2_cross_version_object_reference->api_version) { 
    if(cJSON_AddStringToObject(item, "apiVersion", v2beta2_cross_version_object_reference->api_version) == NULL) {
    goto fail; //String
    }
     } 


    // v2beta2_cross_version_object_reference->kind
    if (!v2beta2_cross_version_object_reference->kind) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "kind", v2beta2_cross_version_object_reference->kind) == NULL) {
    goto fail; //String
    }


    // v2beta2_cross_version_object_reference->name
    if (!v2beta2_cross_version_object_reference->name) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "name", v2beta2_cross_version_object_reference->name) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v2beta2_cross_version_object_reference_t *v2beta2_cross_version_object_reference_parseFromJSON(cJSON *v2beta2_cross_version_object_referenceJSON){

    v2beta2_cross_version_object_reference_t *v2beta2_cross_version_object_reference_local_var = NULL;

    // v2beta2_cross_version_object_reference->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v2beta2_cross_version_object_referenceJSON, "apiVersion");
    if (api_version) { 
    if(!cJSON_IsString(api_version))
    {
    goto end; //String
    }
    }

    // v2beta2_cross_version_object_reference->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v2beta2_cross_version_object_referenceJSON, "kind");
    if (!kind) {
        goto end;
    }

    
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }

    // v2beta2_cross_version_object_reference->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v2beta2_cross_version_object_referenceJSON, "name");
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }


    v2beta2_cross_version_object_reference_local_var = v2beta2_cross_version_object_reference_create (
        api_version ? strdup(api_version->valuestring) : NULL,
        strdup(kind->valuestring),
        strdup(name->valuestring)
        );

    return v2beta2_cross_version_object_reference_local_var;
end:
    return NULL;

}
