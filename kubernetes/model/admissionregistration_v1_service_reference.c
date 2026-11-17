#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "admissionregistration_v1_service_reference.h"



static admissionregistration_v1_service_reference_t *admissionregistration_v1_service_reference_create_internal(
    char *name,
    char *_namespace,
    char *path,
    int *port
    ) {
    admissionregistration_v1_service_reference_t *admissionregistration_v1_service_reference_local_var = malloc(sizeof(admissionregistration_v1_service_reference_t));
    if (!admissionregistration_v1_service_reference_local_var) {
        return NULL;
    }
    memset(admissionregistration_v1_service_reference_local_var, 0, sizeof(admissionregistration_v1_service_reference_t));
    admissionregistration_v1_service_reference_local_var->_library_owned = 1;
    admissionregistration_v1_service_reference_local_var->name = name;
    admissionregistration_v1_service_reference_local_var->_namespace = _namespace;
    admissionregistration_v1_service_reference_local_var->path = path;
    admissionregistration_v1_service_reference_local_var->port = port;
    return admissionregistration_v1_service_reference_local_var;
}

__attribute__((deprecated)) admissionregistration_v1_service_reference_t *admissionregistration_v1_service_reference_create(
    char *name,
    char *_namespace,
    char *path,
    int *port
    ) {
    int *port_copy = NULL;
    if (port) {
        port_copy = malloc(sizeof(int));
        if (port_copy) *port_copy = *port;
    }
    admissionregistration_v1_service_reference_t *result = admissionregistration_v1_service_reference_create_internal (
        name,
        _namespace,
        path,
        port_copy
        );
    if (!result) {
        free(port_copy);
    }
    return result;
}

void admissionregistration_v1_service_reference_free(admissionregistration_v1_service_reference_t *admissionregistration_v1_service_reference) {
    if(NULL == admissionregistration_v1_service_reference){
        return ;
    }
    if(admissionregistration_v1_service_reference->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "admissionregistration_v1_service_reference_free");
        return ;
    }
    listEntry_t *listEntry;
    if (admissionregistration_v1_service_reference->name) {
        free(admissionregistration_v1_service_reference->name);
        admissionregistration_v1_service_reference->name = NULL;
    }
    if (admissionregistration_v1_service_reference->_namespace) {
        free(admissionregistration_v1_service_reference->_namespace);
        admissionregistration_v1_service_reference->_namespace = NULL;
    }
    if (admissionregistration_v1_service_reference->path) {
        free(admissionregistration_v1_service_reference->path);
        admissionregistration_v1_service_reference->path = NULL;
    }
    if (admissionregistration_v1_service_reference->port) {
        free(admissionregistration_v1_service_reference->port);
        admissionregistration_v1_service_reference->port = NULL;
    }
    free(admissionregistration_v1_service_reference);
}

cJSON *admissionregistration_v1_service_reference_convertToJSON(admissionregistration_v1_service_reference_t *admissionregistration_v1_service_reference) {
    cJSON *item = cJSON_CreateObject();

    // admissionregistration_v1_service_reference->name
    if (!admissionregistration_v1_service_reference->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", admissionregistration_v1_service_reference->name) == NULL) {
    goto fail; //String
    }


    // admissionregistration_v1_service_reference->_namespace
    if (!admissionregistration_v1_service_reference->_namespace) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "namespace", admissionregistration_v1_service_reference->_namespace) == NULL) {
    goto fail; //String
    }


    // admissionregistration_v1_service_reference->path
    if(admissionregistration_v1_service_reference->path) {
    if(cJSON_AddStringToObject(item, "path", admissionregistration_v1_service_reference->path) == NULL) {
    goto fail; //String
    }
    }


    // admissionregistration_v1_service_reference->port
    if(admissionregistration_v1_service_reference->port) {
    if(cJSON_AddNumberToObject(item, "port", *admissionregistration_v1_service_reference->port) == NULL) {
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

admissionregistration_v1_service_reference_t *admissionregistration_v1_service_reference_parseFromJSON(cJSON *admissionregistration_v1_service_referenceJSON){

    admissionregistration_v1_service_reference_t *admissionregistration_v1_service_reference_local_var = NULL;

    char *name_local_str = NULL;

    char *_namespace_local_str = NULL;

    char *path_local_str = NULL;

    // define the local variable for admissionregistration_v1_service_reference->port
    int *port_local_var = NULL;

    // admissionregistration_v1_service_reference->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(admissionregistration_v1_service_referenceJSON, "name");
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

    // admissionregistration_v1_service_reference->_namespace
    cJSON *_namespace = cJSON_GetObjectItemCaseSensitive(admissionregistration_v1_service_referenceJSON, "namespace");
    if (cJSON_IsNull(_namespace)) {
        _namespace = NULL;
    }
    if (!_namespace) {
        goto end;
    }

    
    if(!cJSON_IsString(_namespace))
    {
    goto end; //String
    }

    // admissionregistration_v1_service_reference->path
    cJSON *path = cJSON_GetObjectItemCaseSensitive(admissionregistration_v1_service_referenceJSON, "path");
    if (cJSON_IsNull(path)) {
        path = NULL;
    }
    if (path) { 
    if(!cJSON_IsString(path) && !cJSON_IsNull(path))
    {
    goto end; //String
    }
    }

    // admissionregistration_v1_service_reference->port
    cJSON *port = cJSON_GetObjectItemCaseSensitive(admissionregistration_v1_service_referenceJSON, "port");
    if (cJSON_IsNull(port)) {
        port = NULL;
    }
    if (port) { 
    if(!cJSON_IsNumber(port))
    {
    goto end; //Numeric
    }
    port_local_var = malloc(sizeof(int));
    if(!port_local_var)
    {
        goto end;
    }
    *port_local_var = port->valuedouble;
    }


    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);
    if (_namespace && !cJSON_IsNull(_namespace)) _namespace_local_str = strdup(_namespace->valuestring);
    if (path && !cJSON_IsNull(path)) path_local_str = strdup(path->valuestring);

    admissionregistration_v1_service_reference_local_var = admissionregistration_v1_service_reference_create_internal (
        name_local_str,
        _namespace_local_str,
        path_local_str,
        port_local_var
        );

    if (!admissionregistration_v1_service_reference_local_var) {
        goto end;
    }

    return admissionregistration_v1_service_reference_local_var;
end:
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    if (_namespace_local_str) {
        free(_namespace_local_str);
        _namespace_local_str = NULL;
    }
    if (path_local_str) {
        free(path_local_str);
        path_local_str = NULL;
    }
    if (port_local_var) {
        free(port_local_var);
        port_local_var = NULL;
    }
    return NULL;

}
