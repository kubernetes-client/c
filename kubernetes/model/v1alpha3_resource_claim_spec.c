#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha3_resource_claim_spec.h"



static v1alpha3_resource_claim_spec_t *v1alpha3_resource_claim_spec_create_internal(
    v1alpha3_device_claim_t *devices
    ) {
    v1alpha3_resource_claim_spec_t *v1alpha3_resource_claim_spec_local_var = malloc(sizeof(v1alpha3_resource_claim_spec_t));
    if (!v1alpha3_resource_claim_spec_local_var) {
        return NULL;
    }
    v1alpha3_resource_claim_spec_local_var->devices = devices;

    v1alpha3_resource_claim_spec_local_var->_library_owned = 1;
    return v1alpha3_resource_claim_spec_local_var;
}

__attribute__((deprecated)) v1alpha3_resource_claim_spec_t *v1alpha3_resource_claim_spec_create(
    v1alpha3_device_claim_t *devices
    ) {
    return v1alpha3_resource_claim_spec_create_internal (
        devices
        );
}

void v1alpha3_resource_claim_spec_free(v1alpha3_resource_claim_spec_t *v1alpha3_resource_claim_spec) {
    if(NULL == v1alpha3_resource_claim_spec){
        return ;
    }
    if(v1alpha3_resource_claim_spec->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1alpha3_resource_claim_spec_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha3_resource_claim_spec->devices) {
        v1alpha3_device_claim_free(v1alpha3_resource_claim_spec->devices);
        v1alpha3_resource_claim_spec->devices = NULL;
    }
    free(v1alpha3_resource_claim_spec);
}

cJSON *v1alpha3_resource_claim_spec_convertToJSON(v1alpha3_resource_claim_spec_t *v1alpha3_resource_claim_spec) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha3_resource_claim_spec->devices
    if(v1alpha3_resource_claim_spec->devices) {
    cJSON *devices_local_JSON = v1alpha3_device_claim_convertToJSON(v1alpha3_resource_claim_spec->devices);
    if(devices_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "devices", devices_local_JSON);
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

v1alpha3_resource_claim_spec_t *v1alpha3_resource_claim_spec_parseFromJSON(cJSON *v1alpha3_resource_claim_specJSON){

    v1alpha3_resource_claim_spec_t *v1alpha3_resource_claim_spec_local_var = NULL;

    // define the local variable for v1alpha3_resource_claim_spec->devices
    v1alpha3_device_claim_t *devices_local_nonprim = NULL;

    // v1alpha3_resource_claim_spec->devices
    cJSON *devices = cJSON_GetObjectItemCaseSensitive(v1alpha3_resource_claim_specJSON, "devices");
    if (cJSON_IsNull(devices)) {
        devices = NULL;
    }
    if (devices) { 
    devices_local_nonprim = v1alpha3_device_claim_parseFromJSON(devices); //nonprimitive
    }


    v1alpha3_resource_claim_spec_local_var = v1alpha3_resource_claim_spec_create_internal (
        devices ? devices_local_nonprim : NULL
        );

    return v1alpha3_resource_claim_spec_local_var;
end:
    if (devices_local_nonprim) {
        v1alpha3_device_claim_free(devices_local_nonprim);
        devices_local_nonprim = NULL;
    }
    return NULL;

}
