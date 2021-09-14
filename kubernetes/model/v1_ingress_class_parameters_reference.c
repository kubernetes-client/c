#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_ingress_class_parameters_reference.h"



v1_ingress_class_parameters_reference_t *v1_ingress_class_parameters_reference_create(
    char *api_group,
    char *kind,
    char *name,
    char *_namespace,
    char *scope
    ) {
    v1_ingress_class_parameters_reference_t *v1_ingress_class_parameters_reference_local_var = malloc(sizeof(v1_ingress_class_parameters_reference_t));
    if (!v1_ingress_class_parameters_reference_local_var) {
        return NULL;
    }
    v1_ingress_class_parameters_reference_local_var->api_group = api_group;
    v1_ingress_class_parameters_reference_local_var->kind = kind;
    v1_ingress_class_parameters_reference_local_var->name = name;
    v1_ingress_class_parameters_reference_local_var->_namespace = _namespace;
    v1_ingress_class_parameters_reference_local_var->scope = scope;

    return v1_ingress_class_parameters_reference_local_var;
}


void v1_ingress_class_parameters_reference_free(v1_ingress_class_parameters_reference_t *v1_ingress_class_parameters_reference) {
    if(NULL == v1_ingress_class_parameters_reference){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_ingress_class_parameters_reference->api_group) {
        free(v1_ingress_class_parameters_reference->api_group);
        v1_ingress_class_parameters_reference->api_group = NULL;
    }
    if (v1_ingress_class_parameters_reference->kind) {
        free(v1_ingress_class_parameters_reference->kind);
        v1_ingress_class_parameters_reference->kind = NULL;
    }
    if (v1_ingress_class_parameters_reference->name) {
        free(v1_ingress_class_parameters_reference->name);
        v1_ingress_class_parameters_reference->name = NULL;
    }
    if (v1_ingress_class_parameters_reference->_namespace) {
        free(v1_ingress_class_parameters_reference->_namespace);
        v1_ingress_class_parameters_reference->_namespace = NULL;
    }
    if (v1_ingress_class_parameters_reference->scope) {
        free(v1_ingress_class_parameters_reference->scope);
        v1_ingress_class_parameters_reference->scope = NULL;
    }
    free(v1_ingress_class_parameters_reference);
}

cJSON *v1_ingress_class_parameters_reference_convertToJSON(v1_ingress_class_parameters_reference_t *v1_ingress_class_parameters_reference) {
    cJSON *item = cJSON_CreateObject();

    // v1_ingress_class_parameters_reference->api_group
    if(v1_ingress_class_parameters_reference->api_group) { 
    if(cJSON_AddStringToObject(item, "apiGroup", v1_ingress_class_parameters_reference->api_group) == NULL) {
    goto fail; //String
    }
     } 


    // v1_ingress_class_parameters_reference->kind
    if (!v1_ingress_class_parameters_reference->kind) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "kind", v1_ingress_class_parameters_reference->kind) == NULL) {
    goto fail; //String
    }


    // v1_ingress_class_parameters_reference->name
    if (!v1_ingress_class_parameters_reference->name) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "name", v1_ingress_class_parameters_reference->name) == NULL) {
    goto fail; //String
    }


    // v1_ingress_class_parameters_reference->_namespace
    if(v1_ingress_class_parameters_reference->_namespace) { 
    if(cJSON_AddStringToObject(item, "namespace", v1_ingress_class_parameters_reference->_namespace) == NULL) {
    goto fail; //String
    }
     } 


    // v1_ingress_class_parameters_reference->scope
    if(v1_ingress_class_parameters_reference->scope) { 
    if(cJSON_AddStringToObject(item, "scope", v1_ingress_class_parameters_reference->scope) == NULL) {
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

v1_ingress_class_parameters_reference_t *v1_ingress_class_parameters_reference_parseFromJSON(cJSON *v1_ingress_class_parameters_referenceJSON){

    v1_ingress_class_parameters_reference_t *v1_ingress_class_parameters_reference_local_var = NULL;

    // v1_ingress_class_parameters_reference->api_group
    cJSON *api_group = cJSON_GetObjectItemCaseSensitive(v1_ingress_class_parameters_referenceJSON, "apiGroup");
    if (api_group) { 
    if(!cJSON_IsString(api_group))
    {
    goto end; //String
    }
    }

    // v1_ingress_class_parameters_reference->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_ingress_class_parameters_referenceJSON, "kind");
    if (!kind) {
        goto end;
    }

    
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }

    // v1_ingress_class_parameters_reference->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1_ingress_class_parameters_referenceJSON, "name");
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // v1_ingress_class_parameters_reference->_namespace
    cJSON *_namespace = cJSON_GetObjectItemCaseSensitive(v1_ingress_class_parameters_referenceJSON, "namespace");
    if (_namespace) { 
    if(!cJSON_IsString(_namespace))
    {
    goto end; //String
    }
    }

    // v1_ingress_class_parameters_reference->scope
    cJSON *scope = cJSON_GetObjectItemCaseSensitive(v1_ingress_class_parameters_referenceJSON, "scope");
    if (scope) { 
    if(!cJSON_IsString(scope))
    {
    goto end; //String
    }
    }


    v1_ingress_class_parameters_reference_local_var = v1_ingress_class_parameters_reference_create (
        api_group ? strdup(api_group->valuestring) : NULL,
        strdup(kind->valuestring),
        strdup(name->valuestring),
        _namespace ? strdup(_namespace->valuestring) : NULL,
        scope ? strdup(scope->valuestring) : NULL
        );

    return v1_ingress_class_parameters_reference_local_var;
end:
    return NULL;

}
