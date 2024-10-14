#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha3_device_class_configuration.h"



v1alpha3_device_class_configuration_t *v1alpha3_device_class_configuration_create(
    v1alpha3_opaque_device_configuration_t *opaque
    ) {
    v1alpha3_device_class_configuration_t *v1alpha3_device_class_configuration_local_var = malloc(sizeof(v1alpha3_device_class_configuration_t));
    if (!v1alpha3_device_class_configuration_local_var) {
        return NULL;
    }
    v1alpha3_device_class_configuration_local_var->opaque = opaque;

    return v1alpha3_device_class_configuration_local_var;
}


void v1alpha3_device_class_configuration_free(v1alpha3_device_class_configuration_t *v1alpha3_device_class_configuration) {
    if(NULL == v1alpha3_device_class_configuration){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha3_device_class_configuration->opaque) {
        v1alpha3_opaque_device_configuration_free(v1alpha3_device_class_configuration->opaque);
        v1alpha3_device_class_configuration->opaque = NULL;
    }
    free(v1alpha3_device_class_configuration);
}

cJSON *v1alpha3_device_class_configuration_convertToJSON(v1alpha3_device_class_configuration_t *v1alpha3_device_class_configuration) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha3_device_class_configuration->opaque
    if(v1alpha3_device_class_configuration->opaque) {
    cJSON *opaque_local_JSON = v1alpha3_opaque_device_configuration_convertToJSON(v1alpha3_device_class_configuration->opaque);
    if(opaque_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "opaque", opaque_local_JSON);
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

v1alpha3_device_class_configuration_t *v1alpha3_device_class_configuration_parseFromJSON(cJSON *v1alpha3_device_class_configurationJSON){

    v1alpha3_device_class_configuration_t *v1alpha3_device_class_configuration_local_var = NULL;

    // define the local variable for v1alpha3_device_class_configuration->opaque
    v1alpha3_opaque_device_configuration_t *opaque_local_nonprim = NULL;

    // v1alpha3_device_class_configuration->opaque
    cJSON *opaque = cJSON_GetObjectItemCaseSensitive(v1alpha3_device_class_configurationJSON, "opaque");
    if (opaque) { 
    opaque_local_nonprim = v1alpha3_opaque_device_configuration_parseFromJSON(opaque); //nonprimitive
    }


    v1alpha3_device_class_configuration_local_var = v1alpha3_device_class_configuration_create (
        opaque ? opaque_local_nonprim : NULL
        );

    return v1alpha3_device_class_configuration_local_var;
end:
    if (opaque_local_nonprim) {
        v1alpha3_opaque_device_configuration_free(opaque_local_nonprim);
        opaque_local_nonprim = NULL;
    }
    return NULL;

}
