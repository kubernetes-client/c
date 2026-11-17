#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v2_cross_version_object_reference.h"



static v2_cross_version_object_reference_t *v2_cross_version_object_reference_create_internal(
    char *api_version,
    char *kind,
    char *name
    ) {
    v2_cross_version_object_reference_t *v2_cross_version_object_reference_local_var = malloc(sizeof(v2_cross_version_object_reference_t));
    if (!v2_cross_version_object_reference_local_var) {
        return NULL;
    }
    memset(v2_cross_version_object_reference_local_var, 0, sizeof(v2_cross_version_object_reference_t));
    v2_cross_version_object_reference_local_var->_library_owned = 1;
    v2_cross_version_object_reference_local_var->api_version = api_version;
    v2_cross_version_object_reference_local_var->kind = kind;
    v2_cross_version_object_reference_local_var->name = name;
    return v2_cross_version_object_reference_local_var;
}

__attribute__((deprecated)) v2_cross_version_object_reference_t *v2_cross_version_object_reference_create(
    char *api_version,
    char *kind,
    char *name
    ) {
    v2_cross_version_object_reference_t *result = v2_cross_version_object_reference_create_internal (
        api_version,
        kind,
        name
        );
    if (!result) {
    }
    return result;
}

void v2_cross_version_object_reference_free(v2_cross_version_object_reference_t *v2_cross_version_object_reference) {
    if(NULL == v2_cross_version_object_reference){
        return ;
    }
    if(v2_cross_version_object_reference->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v2_cross_version_object_reference_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v2_cross_version_object_reference->api_version) {
        free(v2_cross_version_object_reference->api_version);
        v2_cross_version_object_reference->api_version = NULL;
    }
    if (v2_cross_version_object_reference->kind) {
        free(v2_cross_version_object_reference->kind);
        v2_cross_version_object_reference->kind = NULL;
    }
    if (v2_cross_version_object_reference->name) {
        free(v2_cross_version_object_reference->name);
        v2_cross_version_object_reference->name = NULL;
    }
    free(v2_cross_version_object_reference);
}

cJSON *v2_cross_version_object_reference_convertToJSON(v2_cross_version_object_reference_t *v2_cross_version_object_reference) {
    cJSON *item = cJSON_CreateObject();

    // v2_cross_version_object_reference->api_version
    if(v2_cross_version_object_reference->api_version) {
    if(cJSON_AddStringToObject(item, "apiVersion", v2_cross_version_object_reference->api_version) == NULL) {
    goto fail; //String
    }
    }


    // v2_cross_version_object_reference->kind
    if (!v2_cross_version_object_reference->kind) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "kind", v2_cross_version_object_reference->kind) == NULL) {
    goto fail; //String
    }


    // v2_cross_version_object_reference->name
    if (!v2_cross_version_object_reference->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", v2_cross_version_object_reference->name) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v2_cross_version_object_reference_t *v2_cross_version_object_reference_parseFromJSON(cJSON *v2_cross_version_object_referenceJSON){

    v2_cross_version_object_reference_t *v2_cross_version_object_reference_local_var = NULL;

    char *api_version_local_str = NULL;

    char *kind_local_str = NULL;

    char *name_local_str = NULL;

    // v2_cross_version_object_reference->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v2_cross_version_object_referenceJSON, "apiVersion");
    if (cJSON_IsNull(api_version)) {
        api_version = NULL;
    }
    if (api_version) { 
    if(!cJSON_IsString(api_version) && !cJSON_IsNull(api_version))
    {
    goto end; //String
    }
    }

    // v2_cross_version_object_reference->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v2_cross_version_object_referenceJSON, "kind");
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

    // v2_cross_version_object_reference->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v2_cross_version_object_referenceJSON, "name");
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


    if (api_version && !cJSON_IsNull(api_version)) api_version_local_str = strdup(api_version->valuestring);
    if (kind && !cJSON_IsNull(kind)) kind_local_str = strdup(kind->valuestring);
    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);

    v2_cross_version_object_reference_local_var = v2_cross_version_object_reference_create_internal (
        api_version_local_str,
        kind_local_str,
        name_local_str
        );

    if (!v2_cross_version_object_reference_local_var) {
        goto end;
    }

    return v2_cross_version_object_reference_local_var;
end:
    if (api_version_local_str) {
        free(api_version_local_str);
        api_version_local_str = NULL;
    }
    if (kind_local_str) {
        free(kind_local_str);
        kind_local_str = NULL;
    }
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    return NULL;

}
