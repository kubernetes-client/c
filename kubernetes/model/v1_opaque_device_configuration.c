#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_opaque_device_configuration.h"



static v1_opaque_device_configuration_t *v1_opaque_device_configuration_create_internal(
    char *driver,
    object_t *parameters
    ) {
    v1_opaque_device_configuration_t *v1_opaque_device_configuration_local_var = malloc(sizeof(v1_opaque_device_configuration_t));
    if (!v1_opaque_device_configuration_local_var) {
        return NULL;
    }
    v1_opaque_device_configuration_local_var->driver = driver;
    v1_opaque_device_configuration_local_var->parameters = parameters;

    v1_opaque_device_configuration_local_var->_library_owned = 1;
    return v1_opaque_device_configuration_local_var;
}

__attribute__((deprecated)) v1_opaque_device_configuration_t *v1_opaque_device_configuration_create(
    char *driver,
    object_t *parameters
    ) {
    return v1_opaque_device_configuration_create_internal (
        driver,
        parameters
        );
}

void v1_opaque_device_configuration_free(v1_opaque_device_configuration_t *v1_opaque_device_configuration) {
    if(NULL == v1_opaque_device_configuration){
        return ;
    }
    if(v1_opaque_device_configuration->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_opaque_device_configuration_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_opaque_device_configuration->driver) {
        free(v1_opaque_device_configuration->driver);
        v1_opaque_device_configuration->driver = NULL;
    }
    if (v1_opaque_device_configuration->parameters) {
        object_free(v1_opaque_device_configuration->parameters);
        v1_opaque_device_configuration->parameters = NULL;
    }
    free(v1_opaque_device_configuration);
}

cJSON *v1_opaque_device_configuration_convertToJSON(v1_opaque_device_configuration_t *v1_opaque_device_configuration) {
    cJSON *item = cJSON_CreateObject();

    // v1_opaque_device_configuration->driver
    if (!v1_opaque_device_configuration->driver) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "driver", v1_opaque_device_configuration->driver) == NULL) {
    goto fail; //String
    }


    // v1_opaque_device_configuration->parameters
    if (!v1_opaque_device_configuration->parameters) {
        goto fail;
    }
    cJSON *parameters_object = object_convertToJSON(v1_opaque_device_configuration->parameters);
    if(parameters_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "parameters", parameters_object);
    if(item->child == NULL) {
    goto fail;
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_opaque_device_configuration_t *v1_opaque_device_configuration_parseFromJSON(cJSON *v1_opaque_device_configurationJSON){

    v1_opaque_device_configuration_t *v1_opaque_device_configuration_local_var = NULL;

    // v1_opaque_device_configuration->driver
    cJSON *driver = cJSON_GetObjectItemCaseSensitive(v1_opaque_device_configurationJSON, "driver");
    if (cJSON_IsNull(driver)) {
        driver = NULL;
    }
    if (!driver) {
        goto end;
    }

    
    if(!cJSON_IsString(driver))
    {
    goto end; //String
    }

    // v1_opaque_device_configuration->parameters
    cJSON *parameters = cJSON_GetObjectItemCaseSensitive(v1_opaque_device_configurationJSON, "parameters");
    if (cJSON_IsNull(parameters)) {
        parameters = NULL;
    }
    if (!parameters) {
        goto end;
    }

    object_t *parameters_local_object = NULL;
    
    parameters_local_object = object_parseFromJSON(parameters); //object


    v1_opaque_device_configuration_local_var = v1_opaque_device_configuration_create_internal (
        strdup(driver->valuestring),
        parameters_local_object
        );

    return v1_opaque_device_configuration_local_var;
end:
    return NULL;

}
