#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "apiregistration_v1beta1_service_reference.h"



apiregistration_v1beta1_service_reference_t *apiregistration_v1beta1_service_reference_create(
    char *name,
    char *_namespace,
    int port
    ) {
    apiregistration_v1beta1_service_reference_t *apiregistration_v1beta1_service_reference_local_var = malloc(sizeof(apiregistration_v1beta1_service_reference_t));
    if (!apiregistration_v1beta1_service_reference_local_var) {
        return NULL;
    }
    apiregistration_v1beta1_service_reference_local_var->name = name;
    apiregistration_v1beta1_service_reference_local_var->_namespace = _namespace;
    apiregistration_v1beta1_service_reference_local_var->port = port;

    return apiregistration_v1beta1_service_reference_local_var;
}


void apiregistration_v1beta1_service_reference_free(apiregistration_v1beta1_service_reference_t *apiregistration_v1beta1_service_reference) {
    if(NULL == apiregistration_v1beta1_service_reference){
        return ;
    }
    listEntry_t *listEntry;
    if (apiregistration_v1beta1_service_reference->name) {
        free(apiregistration_v1beta1_service_reference->name);
        apiregistration_v1beta1_service_reference->name = NULL;
    }
    if (apiregistration_v1beta1_service_reference->_namespace) {
        free(apiregistration_v1beta1_service_reference->_namespace);
        apiregistration_v1beta1_service_reference->_namespace = NULL;
    }
    free(apiregistration_v1beta1_service_reference);
}

cJSON *apiregistration_v1beta1_service_reference_convertToJSON(apiregistration_v1beta1_service_reference_t *apiregistration_v1beta1_service_reference) {
    cJSON *item = cJSON_CreateObject();

    // apiregistration_v1beta1_service_reference->name
    if(apiregistration_v1beta1_service_reference->name) { 
    if(cJSON_AddStringToObject(item, "name", apiregistration_v1beta1_service_reference->name) == NULL) {
    goto fail; //String
    }
     } 


    // apiregistration_v1beta1_service_reference->_namespace
    if(apiregistration_v1beta1_service_reference->_namespace) { 
    if(cJSON_AddStringToObject(item, "namespace", apiregistration_v1beta1_service_reference->_namespace) == NULL) {
    goto fail; //String
    }
     } 


    // apiregistration_v1beta1_service_reference->port
    if(apiregistration_v1beta1_service_reference->port) { 
    if(cJSON_AddNumberToObject(item, "port", apiregistration_v1beta1_service_reference->port) == NULL) {
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

apiregistration_v1beta1_service_reference_t *apiregistration_v1beta1_service_reference_parseFromJSON(cJSON *apiregistration_v1beta1_service_referenceJSON){

    apiregistration_v1beta1_service_reference_t *apiregistration_v1beta1_service_reference_local_var = NULL;

    // apiregistration_v1beta1_service_reference->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(apiregistration_v1beta1_service_referenceJSON, "name");
    if (name) { 
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }
    }

    // apiregistration_v1beta1_service_reference->_namespace
    cJSON *_namespace = cJSON_GetObjectItemCaseSensitive(apiregistration_v1beta1_service_referenceJSON, "namespace");
    if (_namespace) { 
    if(!cJSON_IsString(_namespace))
    {
    goto end; //String
    }
    }

    // apiregistration_v1beta1_service_reference->port
    cJSON *port = cJSON_GetObjectItemCaseSensitive(apiregistration_v1beta1_service_referenceJSON, "port");
    if (port) { 
    if(!cJSON_IsNumber(port))
    {
    goto end; //Numeric
    }
    }


    apiregistration_v1beta1_service_reference_local_var = apiregistration_v1beta1_service_reference_create (
        name ? strdup(name->valuestring) : NULL,
        _namespace ? strdup(_namespace->valuestring) : NULL,
        port ? port->valuedouble : 0
        );

    return apiregistration_v1beta1_service_reference_local_var;
end:
    return NULL;

}
