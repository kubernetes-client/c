#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha1_param_ref.h"



v1alpha1_param_ref_t *v1alpha1_param_ref_create(
    char *name,
    char *_namespace
    ) {
    v1alpha1_param_ref_t *v1alpha1_param_ref_local_var = malloc(sizeof(v1alpha1_param_ref_t));
    if (!v1alpha1_param_ref_local_var) {
        return NULL;
    }
    v1alpha1_param_ref_local_var->name = name;
    v1alpha1_param_ref_local_var->_namespace = _namespace;

    return v1alpha1_param_ref_local_var;
}


void v1alpha1_param_ref_free(v1alpha1_param_ref_t *v1alpha1_param_ref) {
    if(NULL == v1alpha1_param_ref){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha1_param_ref->name) {
        free(v1alpha1_param_ref->name);
        v1alpha1_param_ref->name = NULL;
    }
    if (v1alpha1_param_ref->_namespace) {
        free(v1alpha1_param_ref->_namespace);
        v1alpha1_param_ref->_namespace = NULL;
    }
    free(v1alpha1_param_ref);
}

cJSON *v1alpha1_param_ref_convertToJSON(v1alpha1_param_ref_t *v1alpha1_param_ref) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha1_param_ref->name
    if(v1alpha1_param_ref->name) {
    if(cJSON_AddStringToObject(item, "name", v1alpha1_param_ref->name) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha1_param_ref->_namespace
    if(v1alpha1_param_ref->_namespace) {
    if(cJSON_AddStringToObject(item, "namespace", v1alpha1_param_ref->_namespace) == NULL) {
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

v1alpha1_param_ref_t *v1alpha1_param_ref_parseFromJSON(cJSON *v1alpha1_param_refJSON){

    v1alpha1_param_ref_t *v1alpha1_param_ref_local_var = NULL;

    // v1alpha1_param_ref->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1alpha1_param_refJSON, "name");
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // v1alpha1_param_ref->_namespace
    cJSON *_namespace = cJSON_GetObjectItemCaseSensitive(v1alpha1_param_refJSON, "namespace");
    if (_namespace) { 
    if(!cJSON_IsString(_namespace) && !cJSON_IsNull(_namespace))
    {
    goto end; //String
    }
    }


    v1alpha1_param_ref_local_var = v1alpha1_param_ref_create (
        name && !cJSON_IsNull(name) ? strdup(name->valuestring) : NULL,
        _namespace && !cJSON_IsNull(_namespace) ? strdup(_namespace->valuestring) : NULL
        );

    return v1alpha1_param_ref_local_var;
end:
    return NULL;

}
