#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_secret_reference.h"



static v1_secret_reference_t *v1_secret_reference_create_internal(
    char *name,
    char *_namespace
    ) {
    v1_secret_reference_t *v1_secret_reference_local_var = malloc(sizeof(v1_secret_reference_t));
    if (!v1_secret_reference_local_var) {
        return NULL;
    }
    memset(v1_secret_reference_local_var, 0, sizeof(v1_secret_reference_t));
    v1_secret_reference_local_var->_library_owned = 1;
    v1_secret_reference_local_var->name = name;
    v1_secret_reference_local_var->_namespace = _namespace;
    return v1_secret_reference_local_var;
}

__attribute__((deprecated)) v1_secret_reference_t *v1_secret_reference_create(
    char *name,
    char *_namespace
    ) {
    v1_secret_reference_t *result = v1_secret_reference_create_internal (
        name,
        _namespace
        );
    if (!result) {
    }
    return result;
}

void v1_secret_reference_free(v1_secret_reference_t *v1_secret_reference) {
    if(NULL == v1_secret_reference){
        return ;
    }
    if(v1_secret_reference->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_secret_reference_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_secret_reference->name) {
        free(v1_secret_reference->name);
        v1_secret_reference->name = NULL;
    }
    if (v1_secret_reference->_namespace) {
        free(v1_secret_reference->_namespace);
        v1_secret_reference->_namespace = NULL;
    }
    free(v1_secret_reference);
}

cJSON *v1_secret_reference_convertToJSON(v1_secret_reference_t *v1_secret_reference) {
    cJSON *item = cJSON_CreateObject();

    // v1_secret_reference->name
    if(v1_secret_reference->name) {
    if(cJSON_AddStringToObject(item, "name", v1_secret_reference->name) == NULL) {
    goto fail; //String
    }
    }


    // v1_secret_reference->_namespace
    if(v1_secret_reference->_namespace) {
    if(cJSON_AddStringToObject(item, "namespace", v1_secret_reference->_namespace) == NULL) {
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

v1_secret_reference_t *v1_secret_reference_parseFromJSON(cJSON *v1_secret_referenceJSON){

    v1_secret_reference_t *v1_secret_reference_local_var = NULL;

    char *name_local_str = NULL;

    char *_namespace_local_str = NULL;

    // v1_secret_reference->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1_secret_referenceJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // v1_secret_reference->_namespace
    cJSON *_namespace = cJSON_GetObjectItemCaseSensitive(v1_secret_referenceJSON, "namespace");
    if (cJSON_IsNull(_namespace)) {
        _namespace = NULL;
    }
    if (_namespace) { 
    if(!cJSON_IsString(_namespace) && !cJSON_IsNull(_namespace))
    {
    goto end; //String
    }
    }


    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);
    if (_namespace && !cJSON_IsNull(_namespace)) _namespace_local_str = strdup(_namespace->valuestring);

    v1_secret_reference_local_var = v1_secret_reference_create_internal (
        name_local_str,
        _namespace_local_str
        );

    if (!v1_secret_reference_local_var) {
        goto end;
    }

    return v1_secret_reference_local_var;
end:
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    if (_namespace_local_str) {
        free(_namespace_local_str);
        _namespace_local_str = NULL;
    }
    return NULL;

}
