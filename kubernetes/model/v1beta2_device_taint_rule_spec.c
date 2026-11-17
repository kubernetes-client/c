#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta2_device_taint_rule_spec.h"



static v1beta2_device_taint_rule_spec_t *v1beta2_device_taint_rule_spec_create_internal(
    v1beta2_device_taint_selector_t *device_selector,
    v1beta2_device_taint_t *taint
    ) {
    v1beta2_device_taint_rule_spec_t *v1beta2_device_taint_rule_spec_local_var = malloc(sizeof(v1beta2_device_taint_rule_spec_t));
    if (!v1beta2_device_taint_rule_spec_local_var) {
        return NULL;
    }
    memset(v1beta2_device_taint_rule_spec_local_var, 0, sizeof(v1beta2_device_taint_rule_spec_t));
    v1beta2_device_taint_rule_spec_local_var->_library_owned = 1;
    v1beta2_device_taint_rule_spec_local_var->device_selector = device_selector;
    v1beta2_device_taint_rule_spec_local_var->taint = taint;
    return v1beta2_device_taint_rule_spec_local_var;
}

__attribute__((deprecated)) v1beta2_device_taint_rule_spec_t *v1beta2_device_taint_rule_spec_create(
    v1beta2_device_taint_selector_t *device_selector,
    v1beta2_device_taint_t *taint
    ) {
    v1beta2_device_taint_rule_spec_t *result = v1beta2_device_taint_rule_spec_create_internal (
        device_selector,
        taint
        );
    if (!result) {
    }
    return result;
}

void v1beta2_device_taint_rule_spec_free(v1beta2_device_taint_rule_spec_t *v1beta2_device_taint_rule_spec) {
    if(NULL == v1beta2_device_taint_rule_spec){
        return ;
    }
    if(v1beta2_device_taint_rule_spec->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1beta2_device_taint_rule_spec_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta2_device_taint_rule_spec->device_selector) {
        v1beta2_device_taint_selector_free(v1beta2_device_taint_rule_spec->device_selector);
        v1beta2_device_taint_rule_spec->device_selector = NULL;
    }
    if (v1beta2_device_taint_rule_spec->taint) {
        v1beta2_device_taint_free(v1beta2_device_taint_rule_spec->taint);
        v1beta2_device_taint_rule_spec->taint = NULL;
    }
    free(v1beta2_device_taint_rule_spec);
}

cJSON *v1beta2_device_taint_rule_spec_convertToJSON(v1beta2_device_taint_rule_spec_t *v1beta2_device_taint_rule_spec) {
    cJSON *item = cJSON_CreateObject();

    // v1beta2_device_taint_rule_spec->device_selector
    if(v1beta2_device_taint_rule_spec->device_selector) {
    cJSON *device_selector_local_JSON = v1beta2_device_taint_selector_convertToJSON(v1beta2_device_taint_rule_spec->device_selector);
    if(device_selector_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "deviceSelector", device_selector_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1beta2_device_taint_rule_spec->taint
    if (!v1beta2_device_taint_rule_spec->taint) {
        goto fail;
    }
    cJSON *taint_local_JSON = v1beta2_device_taint_convertToJSON(v1beta2_device_taint_rule_spec->taint);
    if(taint_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "taint", taint_local_JSON);
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

v1beta2_device_taint_rule_spec_t *v1beta2_device_taint_rule_spec_parseFromJSON(cJSON *v1beta2_device_taint_rule_specJSON){

    v1beta2_device_taint_rule_spec_t *v1beta2_device_taint_rule_spec_local_var = NULL;

    // define the local variable for v1beta2_device_taint_rule_spec->device_selector
    v1beta2_device_taint_selector_t *device_selector_local_nonprim = NULL;

    // define the local variable for v1beta2_device_taint_rule_spec->taint
    v1beta2_device_taint_t *taint_local_nonprim = NULL;

    // v1beta2_device_taint_rule_spec->device_selector
    cJSON *device_selector = cJSON_GetObjectItemCaseSensitive(v1beta2_device_taint_rule_specJSON, "deviceSelector");
    if (cJSON_IsNull(device_selector)) {
        device_selector = NULL;
    }
    if (device_selector) { 
    device_selector_local_nonprim = v1beta2_device_taint_selector_parseFromJSON(device_selector); //nonprimitive
    }

    // v1beta2_device_taint_rule_spec->taint
    cJSON *taint = cJSON_GetObjectItemCaseSensitive(v1beta2_device_taint_rule_specJSON, "taint");
    if (cJSON_IsNull(taint)) {
        taint = NULL;
    }
    if (!taint) {
        goto end;
    }

    
    taint_local_nonprim = v1beta2_device_taint_parseFromJSON(taint); //nonprimitive



    v1beta2_device_taint_rule_spec_local_var = v1beta2_device_taint_rule_spec_create_internal (
        device_selector ? device_selector_local_nonprim : NULL,
        taint_local_nonprim
        );

    if (!v1beta2_device_taint_rule_spec_local_var) {
        goto end;
    }

    return v1beta2_device_taint_rule_spec_local_var;
end:
    if (device_selector_local_nonprim) {
        v1beta2_device_taint_selector_free(device_selector_local_nonprim);
        device_selector_local_nonprim = NULL;
    }
    if (taint_local_nonprim) {
        v1beta2_device_taint_free(taint_local_nonprim);
        taint_local_nonprim = NULL;
    }
    return NULL;

}
