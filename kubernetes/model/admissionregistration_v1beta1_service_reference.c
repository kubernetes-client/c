#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "admissionregistration_v1beta1_service_reference.h"



admissionregistration_v1beta1_service_reference_t *admissionregistration_v1beta1_service_reference_create(
    char *name,
    char *_namespace,
    char *path,
    int port
    ) {
    admissionregistration_v1beta1_service_reference_t *admissionregistration_v1beta1_service_reference_local_var = malloc(sizeof(admissionregistration_v1beta1_service_reference_t));
    if (!admissionregistration_v1beta1_service_reference_local_var) {
        return NULL;
    }
    admissionregistration_v1beta1_service_reference_local_var->name = name;
    admissionregistration_v1beta1_service_reference_local_var->_namespace = _namespace;
    admissionregistration_v1beta1_service_reference_local_var->path = path;
    admissionregistration_v1beta1_service_reference_local_var->port = port;

    return admissionregistration_v1beta1_service_reference_local_var;
}


void admissionregistration_v1beta1_service_reference_free(admissionregistration_v1beta1_service_reference_t *admissionregistration_v1beta1_service_reference) {
    if(NULL == admissionregistration_v1beta1_service_reference){
        return ;
    }
    listEntry_t *listEntry;
    if (admissionregistration_v1beta1_service_reference->name) {
        free(admissionregistration_v1beta1_service_reference->name);
        admissionregistration_v1beta1_service_reference->name = NULL;
    }
    if (admissionregistration_v1beta1_service_reference->_namespace) {
        free(admissionregistration_v1beta1_service_reference->_namespace);
        admissionregistration_v1beta1_service_reference->_namespace = NULL;
    }
    if (admissionregistration_v1beta1_service_reference->path) {
        free(admissionregistration_v1beta1_service_reference->path);
        admissionregistration_v1beta1_service_reference->path = NULL;
    }
    free(admissionregistration_v1beta1_service_reference);
}

cJSON *admissionregistration_v1beta1_service_reference_convertToJSON(admissionregistration_v1beta1_service_reference_t *admissionregistration_v1beta1_service_reference) {
    cJSON *item = cJSON_CreateObject();

    // admissionregistration_v1beta1_service_reference->name
    if (!admissionregistration_v1beta1_service_reference->name) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "name", admissionregistration_v1beta1_service_reference->name) == NULL) {
    goto fail; //String
    }


    // admissionregistration_v1beta1_service_reference->_namespace
    if (!admissionregistration_v1beta1_service_reference->_namespace) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "namespace", admissionregistration_v1beta1_service_reference->_namespace) == NULL) {
    goto fail; //String
    }


    // admissionregistration_v1beta1_service_reference->path
    if(admissionregistration_v1beta1_service_reference->path) { 
    if(cJSON_AddStringToObject(item, "path", admissionregistration_v1beta1_service_reference->path) == NULL) {
    goto fail; //String
    }
     } 


    // admissionregistration_v1beta1_service_reference->port
    if(admissionregistration_v1beta1_service_reference->port) { 
    if(cJSON_AddNumberToObject(item, "port", admissionregistration_v1beta1_service_reference->port) == NULL) {
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

admissionregistration_v1beta1_service_reference_t *admissionregistration_v1beta1_service_reference_parseFromJSON(cJSON *admissionregistration_v1beta1_service_referenceJSON){

    admissionregistration_v1beta1_service_reference_t *admissionregistration_v1beta1_service_reference_local_var = NULL;

    // admissionregistration_v1beta1_service_reference->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(admissionregistration_v1beta1_service_referenceJSON, "name");
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // admissionregistration_v1beta1_service_reference->_namespace
    cJSON *_namespace = cJSON_GetObjectItemCaseSensitive(admissionregistration_v1beta1_service_referenceJSON, "namespace");
    if (!_namespace) {
        goto end;
    }

    
    if(!cJSON_IsString(_namespace))
    {
    goto end; //String
    }

    // admissionregistration_v1beta1_service_reference->path
    cJSON *path = cJSON_GetObjectItemCaseSensitive(admissionregistration_v1beta1_service_referenceJSON, "path");
    if (path) { 
    if(!cJSON_IsString(path))
    {
    goto end; //String
    }
    }

    // admissionregistration_v1beta1_service_reference->port
    cJSON *port = cJSON_GetObjectItemCaseSensitive(admissionregistration_v1beta1_service_referenceJSON, "port");
    if (port) { 
    if(!cJSON_IsNumber(port))
    {
    goto end; //Numeric
    }
    }


    admissionregistration_v1beta1_service_reference_local_var = admissionregistration_v1beta1_service_reference_create (
        strdup(name->valuestring),
        strdup(_namespace->valuestring),
        path ? strdup(path->valuestring) : NULL,
        port ? port->valuedouble : 0
        );

    return admissionregistration_v1beta1_service_reference_local_var;
end:
    return NULL;

}
