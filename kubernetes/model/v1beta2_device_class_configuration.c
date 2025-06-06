#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta2_device_class_configuration.h"



static v1beta2_device_class_configuration_t *v1beta2_device_class_configuration_create_internal(
    v1beta2_opaque_device_configuration_t *opaque
    ) {
    v1beta2_device_class_configuration_t *v1beta2_device_class_configuration_local_var = malloc(sizeof(v1beta2_device_class_configuration_t));
    if (!v1beta2_device_class_configuration_local_var) {
        return NULL;
    }
    v1beta2_device_class_configuration_local_var->opaque = opaque;

    v1beta2_device_class_configuration_local_var->_library_owned = 1;
    return v1beta2_device_class_configuration_local_var;
}

__attribute__((deprecated)) v1beta2_device_class_configuration_t *v1beta2_device_class_configuration_create(
    v1beta2_opaque_device_configuration_t *opaque
    ) {
    return v1beta2_device_class_configuration_create_internal (
        opaque
        );
}

void v1beta2_device_class_configuration_free(v1beta2_device_class_configuration_t *v1beta2_device_class_configuration) {
    if(NULL == v1beta2_device_class_configuration){
        return ;
    }
    if(v1beta2_device_class_configuration->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1beta2_device_class_configuration_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta2_device_class_configuration->opaque) {
        v1beta2_opaque_device_configuration_free(v1beta2_device_class_configuration->opaque);
        v1beta2_device_class_configuration->opaque = NULL;
    }
    free(v1beta2_device_class_configuration);
}

cJSON *v1beta2_device_class_configuration_convertToJSON(v1beta2_device_class_configuration_t *v1beta2_device_class_configuration) {
    cJSON *item = cJSON_CreateObject();

    // v1beta2_device_class_configuration->opaque
    if(v1beta2_device_class_configuration->opaque) {
    cJSON *opaque_local_JSON = v1beta2_opaque_device_configuration_convertToJSON(v1beta2_device_class_configuration->opaque);
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

v1beta2_device_class_configuration_t *v1beta2_device_class_configuration_parseFromJSON(cJSON *v1beta2_device_class_configurationJSON){

    v1beta2_device_class_configuration_t *v1beta2_device_class_configuration_local_var = NULL;

    // define the local variable for v1beta2_device_class_configuration->opaque
    v1beta2_opaque_device_configuration_t *opaque_local_nonprim = NULL;

    // v1beta2_device_class_configuration->opaque
    cJSON *opaque = cJSON_GetObjectItemCaseSensitive(v1beta2_device_class_configurationJSON, "opaque");
    if (cJSON_IsNull(opaque)) {
        opaque = NULL;
    }
    if (opaque) { 
    opaque_local_nonprim = v1beta2_opaque_device_configuration_parseFromJSON(opaque); //nonprimitive
    }


    v1beta2_device_class_configuration_local_var = v1beta2_device_class_configuration_create_internal (
        opaque ? opaque_local_nonprim : NULL
        );

    return v1beta2_device_class_configuration_local_var;
end:
    if (opaque_local_nonprim) {
        v1beta2_opaque_device_configuration_free(opaque_local_nonprim);
        opaque_local_nonprim = NULL;
    }
    return NULL;

}
