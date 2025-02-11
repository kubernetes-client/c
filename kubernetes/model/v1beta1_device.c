#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_device.h"



static v1beta1_device_t *v1beta1_device_create_internal(
    v1beta1_basic_device_t *basic,
    char *name
    ) {
    v1beta1_device_t *v1beta1_device_local_var = malloc(sizeof(v1beta1_device_t));
    if (!v1beta1_device_local_var) {
        return NULL;
    }
    v1beta1_device_local_var->basic = basic;
    v1beta1_device_local_var->name = name;

    v1beta1_device_local_var->_library_owned = 1;
    return v1beta1_device_local_var;
}

__attribute__((deprecated)) v1beta1_device_t *v1beta1_device_create(
    v1beta1_basic_device_t *basic,
    char *name
    ) {
    return v1beta1_device_create_internal (
        basic,
        name
        );
}

void v1beta1_device_free(v1beta1_device_t *v1beta1_device) {
    if(NULL == v1beta1_device){
        return ;
    }
    if(v1beta1_device->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1beta1_device_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta1_device->basic) {
        v1beta1_basic_device_free(v1beta1_device->basic);
        v1beta1_device->basic = NULL;
    }
    if (v1beta1_device->name) {
        free(v1beta1_device->name);
        v1beta1_device->name = NULL;
    }
    free(v1beta1_device);
}

cJSON *v1beta1_device_convertToJSON(v1beta1_device_t *v1beta1_device) {
    cJSON *item = cJSON_CreateObject();

    // v1beta1_device->basic
    if(v1beta1_device->basic) {
    cJSON *basic_local_JSON = v1beta1_basic_device_convertToJSON(v1beta1_device->basic);
    if(basic_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "basic", basic_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1beta1_device->name
    if (!v1beta1_device->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", v1beta1_device->name) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1beta1_device_t *v1beta1_device_parseFromJSON(cJSON *v1beta1_deviceJSON){

    v1beta1_device_t *v1beta1_device_local_var = NULL;

    // define the local variable for v1beta1_device->basic
    v1beta1_basic_device_t *basic_local_nonprim = NULL;

    // v1beta1_device->basic
    cJSON *basic = cJSON_GetObjectItemCaseSensitive(v1beta1_deviceJSON, "basic");
    if (cJSON_IsNull(basic)) {
        basic = NULL;
    }
    if (basic) { 
    basic_local_nonprim = v1beta1_basic_device_parseFromJSON(basic); //nonprimitive
    }

    // v1beta1_device->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1beta1_deviceJSON, "name");
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


    v1beta1_device_local_var = v1beta1_device_create_internal (
        basic ? basic_local_nonprim : NULL,
        strdup(name->valuestring)
        );

    return v1beta1_device_local_var;
end:
    if (basic_local_nonprim) {
        v1beta1_basic_device_free(basic_local_nonprim);
        basic_local_nonprim = NULL;
    }
    return NULL;

}
