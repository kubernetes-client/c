#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_opaque_device_configuration.h"



static v1beta1_opaque_device_configuration_t *v1beta1_opaque_device_configuration_create_internal(
    char *driver,
    object_t *parameters
    ) {
    v1beta1_opaque_device_configuration_t *v1beta1_opaque_device_configuration_local_var = malloc(sizeof(v1beta1_opaque_device_configuration_t));
    if (!v1beta1_opaque_device_configuration_local_var) {
        return NULL;
    }
    memset(v1beta1_opaque_device_configuration_local_var, 0, sizeof(v1beta1_opaque_device_configuration_t));
    v1beta1_opaque_device_configuration_local_var->_library_owned = 1;
    v1beta1_opaque_device_configuration_local_var->driver = driver;
    v1beta1_opaque_device_configuration_local_var->parameters = parameters;
    return v1beta1_opaque_device_configuration_local_var;
}

__attribute__((deprecated)) v1beta1_opaque_device_configuration_t *v1beta1_opaque_device_configuration_create(
    char *driver,
    object_t *parameters
    ) {
    v1beta1_opaque_device_configuration_t *result = v1beta1_opaque_device_configuration_create_internal (
        driver,
        parameters
        );
    if (!result) {
    }
    return result;
}

void v1beta1_opaque_device_configuration_free(v1beta1_opaque_device_configuration_t *v1beta1_opaque_device_configuration) {
    if(NULL == v1beta1_opaque_device_configuration){
        return ;
    }
    if(v1beta1_opaque_device_configuration->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1beta1_opaque_device_configuration_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta1_opaque_device_configuration->driver) {
        free(v1beta1_opaque_device_configuration->driver);
        v1beta1_opaque_device_configuration->driver = NULL;
    }
    if (v1beta1_opaque_device_configuration->parameters) {
        object_free(v1beta1_opaque_device_configuration->parameters);
        v1beta1_opaque_device_configuration->parameters = NULL;
    }
    free(v1beta1_opaque_device_configuration);
}

cJSON *v1beta1_opaque_device_configuration_convertToJSON(v1beta1_opaque_device_configuration_t *v1beta1_opaque_device_configuration) {
    cJSON *item = cJSON_CreateObject();

    // v1beta1_opaque_device_configuration->driver
    if (!v1beta1_opaque_device_configuration->driver) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "driver", v1beta1_opaque_device_configuration->driver) == NULL) {
    goto fail; //String
    }


    // v1beta1_opaque_device_configuration->parameters
    if (!v1beta1_opaque_device_configuration->parameters) {
        goto fail;
    }
    cJSON *parameters_object = object_convertToJSON(v1beta1_opaque_device_configuration->parameters);
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

v1beta1_opaque_device_configuration_t *v1beta1_opaque_device_configuration_parseFromJSON(cJSON *v1beta1_opaque_device_configurationJSON){

    v1beta1_opaque_device_configuration_t *v1beta1_opaque_device_configuration_local_var = NULL;

    char *driver_local_str = NULL;

    // v1beta1_opaque_device_configuration->driver
    cJSON *driver = cJSON_GetObjectItemCaseSensitive(v1beta1_opaque_device_configurationJSON, "driver");
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

    // v1beta1_opaque_device_configuration->parameters
    cJSON *parameters = cJSON_GetObjectItemCaseSensitive(v1beta1_opaque_device_configurationJSON, "parameters");
    if (cJSON_IsNull(parameters)) {
        parameters = NULL;
    }
    if (!parameters) {
        goto end;
    }

    object_t *parameters_local_object = NULL;
    
    parameters_local_object = object_parseFromJSON(parameters); //object


    if (driver && !cJSON_IsNull(driver)) driver_local_str = strdup(driver->valuestring);

    v1beta1_opaque_device_configuration_local_var = v1beta1_opaque_device_configuration_create_internal (
        driver_local_str,
        parameters_local_object
        );

    if (!v1beta1_opaque_device_configuration_local_var) {
        goto end;
    }

    return v1beta1_opaque_device_configuration_local_var;
end:
    if (driver_local_str) {
        free(driver_local_str);
        driver_local_str = NULL;
    }
    return NULL;

}
