#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha1_service_reference.h"



v1alpha1_service_reference_t *v1alpha1_service_reference_create(
    char *name,
    char *_namespace,
    char *path,
    int port
    ) {
    v1alpha1_service_reference_t *v1alpha1_service_reference_local_var = malloc(sizeof(v1alpha1_service_reference_t));
    if (!v1alpha1_service_reference_local_var) {
        return NULL;
    }
    v1alpha1_service_reference_local_var->name = name;
    v1alpha1_service_reference_local_var->_namespace = _namespace;
    v1alpha1_service_reference_local_var->path = path;
    v1alpha1_service_reference_local_var->port = port;

    return v1alpha1_service_reference_local_var;
}


void v1alpha1_service_reference_free(v1alpha1_service_reference_t *v1alpha1_service_reference) {
    if(NULL == v1alpha1_service_reference){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha1_service_reference->name) {
        free(v1alpha1_service_reference->name);
        v1alpha1_service_reference->name = NULL;
    }
    if (v1alpha1_service_reference->_namespace) {
        free(v1alpha1_service_reference->_namespace);
        v1alpha1_service_reference->_namespace = NULL;
    }
    if (v1alpha1_service_reference->path) {
        free(v1alpha1_service_reference->path);
        v1alpha1_service_reference->path = NULL;
    }
    free(v1alpha1_service_reference);
}

cJSON *v1alpha1_service_reference_convertToJSON(v1alpha1_service_reference_t *v1alpha1_service_reference) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha1_service_reference->name
    if (!v1alpha1_service_reference->name) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "name", v1alpha1_service_reference->name) == NULL) {
    goto fail; //String
    }


    // v1alpha1_service_reference->_namespace
    if (!v1alpha1_service_reference->_namespace) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "namespace", v1alpha1_service_reference->_namespace) == NULL) {
    goto fail; //String
    }


    // v1alpha1_service_reference->path
    if(v1alpha1_service_reference->path) { 
    if(cJSON_AddStringToObject(item, "path", v1alpha1_service_reference->path) == NULL) {
    goto fail; //String
    }
     } 


    // v1alpha1_service_reference->port
    if(v1alpha1_service_reference->port) { 
    if(cJSON_AddNumberToObject(item, "port", v1alpha1_service_reference->port) == NULL) {
    goto fail; //Numeric
    }
     } 

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1alpha1_service_reference_t *v1alpha1_service_reference_parseFromJSON(cJSON *v1alpha1_service_referenceJSON){

    v1alpha1_service_reference_t *v1alpha1_service_reference_local_var = NULL;

    // v1alpha1_service_reference->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1alpha1_service_referenceJSON, "name");
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // v1alpha1_service_reference->_namespace
    cJSON *_namespace = cJSON_GetObjectItemCaseSensitive(v1alpha1_service_referenceJSON, "namespace");
    if (!_namespace) {
        goto end;
    }

    
    if(!cJSON_IsString(_namespace))
    {
    goto end; //String
    }

    // v1alpha1_service_reference->path
    cJSON *path = cJSON_GetObjectItemCaseSensitive(v1alpha1_service_referenceJSON, "path");
    if (path) { 
    if(!cJSON_IsString(path))
    {
    goto end; //String
    }
    }

    // v1alpha1_service_reference->port
    cJSON *port = cJSON_GetObjectItemCaseSensitive(v1alpha1_service_referenceJSON, "port");
    if (port) { 
    if(!cJSON_IsNumber(port))
    {
    goto end; //Numeric
    }
    }


    v1alpha1_service_reference_local_var = v1alpha1_service_reference_create (
        strdup(name->valuestring),
        strdup(_namespace->valuestring),
        path ? strdup(path->valuestring) : NULL,
        port ? port->valuedouble : 0
        );

    return v1alpha1_service_reference_local_var;
end:
    return NULL;

}
