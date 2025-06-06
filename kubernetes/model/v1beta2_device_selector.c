#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta2_device_selector.h"



static v1beta2_device_selector_t *v1beta2_device_selector_create_internal(
    v1beta2_cel_device_selector_t *cel
    ) {
    v1beta2_device_selector_t *v1beta2_device_selector_local_var = malloc(sizeof(v1beta2_device_selector_t));
    if (!v1beta2_device_selector_local_var) {
        return NULL;
    }
    v1beta2_device_selector_local_var->cel = cel;

    v1beta2_device_selector_local_var->_library_owned = 1;
    return v1beta2_device_selector_local_var;
}

__attribute__((deprecated)) v1beta2_device_selector_t *v1beta2_device_selector_create(
    v1beta2_cel_device_selector_t *cel
    ) {
    return v1beta2_device_selector_create_internal (
        cel
        );
}

void v1beta2_device_selector_free(v1beta2_device_selector_t *v1beta2_device_selector) {
    if(NULL == v1beta2_device_selector){
        return ;
    }
    if(v1beta2_device_selector->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1beta2_device_selector_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta2_device_selector->cel) {
        v1beta2_cel_device_selector_free(v1beta2_device_selector->cel);
        v1beta2_device_selector->cel = NULL;
    }
    free(v1beta2_device_selector);
}

cJSON *v1beta2_device_selector_convertToJSON(v1beta2_device_selector_t *v1beta2_device_selector) {
    cJSON *item = cJSON_CreateObject();

    // v1beta2_device_selector->cel
    if(v1beta2_device_selector->cel) {
    cJSON *cel_local_JSON = v1beta2_cel_device_selector_convertToJSON(v1beta2_device_selector->cel);
    if(cel_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "cel", cel_local_JSON);
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

v1beta2_device_selector_t *v1beta2_device_selector_parseFromJSON(cJSON *v1beta2_device_selectorJSON){

    v1beta2_device_selector_t *v1beta2_device_selector_local_var = NULL;

    // define the local variable for v1beta2_device_selector->cel
    v1beta2_cel_device_selector_t *cel_local_nonprim = NULL;

    // v1beta2_device_selector->cel
    cJSON *cel = cJSON_GetObjectItemCaseSensitive(v1beta2_device_selectorJSON, "cel");
    if (cJSON_IsNull(cel)) {
        cel = NULL;
    }
    if (cel) { 
    cel_local_nonprim = v1beta2_cel_device_selector_parseFromJSON(cel); //nonprimitive
    }


    v1beta2_device_selector_local_var = v1beta2_device_selector_create_internal (
        cel ? cel_local_nonprim : NULL
        );

    return v1beta2_device_selector_local_var;
end:
    if (cel_local_nonprim) {
        v1beta2_cel_device_selector_free(cel_local_nonprim);
        cel_local_nonprim = NULL;
    }
    return NULL;

}
