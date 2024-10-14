#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha3_opaque_device_configuration.h"



v1alpha3_opaque_device_configuration_t *v1alpha3_opaque_device_configuration_create(
    char *driver,
    object_t *parameters
    ) {
    v1alpha3_opaque_device_configuration_t *v1alpha3_opaque_device_configuration_local_var = malloc(sizeof(v1alpha3_opaque_device_configuration_t));
    if (!v1alpha3_opaque_device_configuration_local_var) {
        return NULL;
    }
    v1alpha3_opaque_device_configuration_local_var->driver = driver;
    v1alpha3_opaque_device_configuration_local_var->parameters = parameters;

    return v1alpha3_opaque_device_configuration_local_var;
}


void v1alpha3_opaque_device_configuration_free(v1alpha3_opaque_device_configuration_t *v1alpha3_opaque_device_configuration) {
    if(NULL == v1alpha3_opaque_device_configuration){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha3_opaque_device_configuration->driver) {
        free(v1alpha3_opaque_device_configuration->driver);
        v1alpha3_opaque_device_configuration->driver = NULL;
    }
    if (v1alpha3_opaque_device_configuration->parameters) {
        object_free(v1alpha3_opaque_device_configuration->parameters);
        v1alpha3_opaque_device_configuration->parameters = NULL;
    }
    free(v1alpha3_opaque_device_configuration);
}

cJSON *v1alpha3_opaque_device_configuration_convertToJSON(v1alpha3_opaque_device_configuration_t *v1alpha3_opaque_device_configuration) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha3_opaque_device_configuration->driver
    if (!v1alpha3_opaque_device_configuration->driver) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "driver", v1alpha3_opaque_device_configuration->driver) == NULL) {
    goto fail; //String
    }


    // v1alpha3_opaque_device_configuration->parameters
    if (!v1alpha3_opaque_device_configuration->parameters) {
        goto fail;
    }
    cJSON *parameters_object = object_convertToJSON(v1alpha3_opaque_device_configuration->parameters);
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

v1alpha3_opaque_device_configuration_t *v1alpha3_opaque_device_configuration_parseFromJSON(cJSON *v1alpha3_opaque_device_configurationJSON){

    v1alpha3_opaque_device_configuration_t *v1alpha3_opaque_device_configuration_local_var = NULL;

    // v1alpha3_opaque_device_configuration->driver
    cJSON *driver = cJSON_GetObjectItemCaseSensitive(v1alpha3_opaque_device_configurationJSON, "driver");
    if (!driver) {
        goto end;
    }

    
    if(!cJSON_IsString(driver))
    {
    goto end; //String
    }

    // v1alpha3_opaque_device_configuration->parameters
    cJSON *parameters = cJSON_GetObjectItemCaseSensitive(v1alpha3_opaque_device_configurationJSON, "parameters");
    if (!parameters) {
        goto end;
    }

    object_t *parameters_local_object = NULL;
    
    parameters_local_object = object_parseFromJSON(parameters); //object


    v1alpha3_opaque_device_configuration_local_var = v1alpha3_opaque_device_configuration_create (
        strdup(driver->valuestring),
        parameters_local_object
        );

    return v1alpha3_opaque_device_configuration_local_var;
end:
    return NULL;

}
