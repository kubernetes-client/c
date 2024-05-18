#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha2_vendor_parameters.h"



v1alpha2_vendor_parameters_t *v1alpha2_vendor_parameters_create(
    char *driver_name,
    object_t *parameters
    ) {
    v1alpha2_vendor_parameters_t *v1alpha2_vendor_parameters_local_var = malloc(sizeof(v1alpha2_vendor_parameters_t));
    if (!v1alpha2_vendor_parameters_local_var) {
        return NULL;
    }
    v1alpha2_vendor_parameters_local_var->driver_name = driver_name;
    v1alpha2_vendor_parameters_local_var->parameters = parameters;

    return v1alpha2_vendor_parameters_local_var;
}


void v1alpha2_vendor_parameters_free(v1alpha2_vendor_parameters_t *v1alpha2_vendor_parameters) {
    if(NULL == v1alpha2_vendor_parameters){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha2_vendor_parameters->driver_name) {
        free(v1alpha2_vendor_parameters->driver_name);
        v1alpha2_vendor_parameters->driver_name = NULL;
    }
    if (v1alpha2_vendor_parameters->parameters) {
        object_free(v1alpha2_vendor_parameters->parameters);
        v1alpha2_vendor_parameters->parameters = NULL;
    }
    free(v1alpha2_vendor_parameters);
}

cJSON *v1alpha2_vendor_parameters_convertToJSON(v1alpha2_vendor_parameters_t *v1alpha2_vendor_parameters) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha2_vendor_parameters->driver_name
    if(v1alpha2_vendor_parameters->driver_name) {
    if(cJSON_AddStringToObject(item, "driverName", v1alpha2_vendor_parameters->driver_name) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha2_vendor_parameters->parameters
    if(v1alpha2_vendor_parameters->parameters) {
    cJSON *parameters_object = object_convertToJSON(v1alpha2_vendor_parameters->parameters);
    if(parameters_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "parameters", parameters_object);
    if(item->child == NULL) {
    goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1alpha2_vendor_parameters_t *v1alpha2_vendor_parameters_parseFromJSON(cJSON *v1alpha2_vendor_parametersJSON){

    v1alpha2_vendor_parameters_t *v1alpha2_vendor_parameters_local_var = NULL;

    // v1alpha2_vendor_parameters->driver_name
    cJSON *driver_name = cJSON_GetObjectItemCaseSensitive(v1alpha2_vendor_parametersJSON, "driverName");
    if (driver_name) { 
    if(!cJSON_IsString(driver_name) && !cJSON_IsNull(driver_name))
    {
    goto end; //String
    }
    }

    // v1alpha2_vendor_parameters->parameters
    cJSON *parameters = cJSON_GetObjectItemCaseSensitive(v1alpha2_vendor_parametersJSON, "parameters");
    object_t *parameters_local_object = NULL;
    if (parameters) { 
    parameters_local_object = object_parseFromJSON(parameters); //object
    }


    v1alpha2_vendor_parameters_local_var = v1alpha2_vendor_parameters_create (
        driver_name && !cJSON_IsNull(driver_name) ? strdup(driver_name->valuestring) : NULL,
        parameters ? parameters_local_object : NULL
        );

    return v1alpha2_vendor_parameters_local_var;
end:
    return NULL;

}
