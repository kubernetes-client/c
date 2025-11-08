#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_device_selector.h"



static v1_device_selector_t *v1_device_selector_create_internal(
    v1_cel_device_selector_t *cel
    ) {
    v1_device_selector_t *v1_device_selector_local_var = malloc(sizeof(v1_device_selector_t));
    if (!v1_device_selector_local_var) {
        return NULL;
    }
    v1_device_selector_local_var->cel = cel;

    v1_device_selector_local_var->_library_owned = 1;
    return v1_device_selector_local_var;
}

__attribute__((deprecated)) v1_device_selector_t *v1_device_selector_create(
    v1_cel_device_selector_t *cel
    ) {
    return v1_device_selector_create_internal (
        cel
        );
}

void v1_device_selector_free(v1_device_selector_t *v1_device_selector) {
    if(NULL == v1_device_selector){
        return ;
    }
    if(v1_device_selector->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_device_selector_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_device_selector->cel) {
        v1_cel_device_selector_free(v1_device_selector->cel);
        v1_device_selector->cel = NULL;
    }
    free(v1_device_selector);
}

cJSON *v1_device_selector_convertToJSON(v1_device_selector_t *v1_device_selector) {
    cJSON *item = cJSON_CreateObject();

    // v1_device_selector->cel
    if(v1_device_selector->cel) {
    cJSON *cel_local_JSON = v1_cel_device_selector_convertToJSON(v1_device_selector->cel);
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

v1_device_selector_t *v1_device_selector_parseFromJSON(cJSON *v1_device_selectorJSON){

    v1_device_selector_t *v1_device_selector_local_var = NULL;

    // define the local variable for v1_device_selector->cel
    v1_cel_device_selector_t *cel_local_nonprim = NULL;

    // v1_device_selector->cel
    cJSON *cel = cJSON_GetObjectItemCaseSensitive(v1_device_selectorJSON, "cel");
    if (cJSON_IsNull(cel)) {
        cel = NULL;
    }
    if (cel) { 
    cel_local_nonprim = v1_cel_device_selector_parseFromJSON(cel); //nonprimitive
    }


    v1_device_selector_local_var = v1_device_selector_create_internal (
        cel ? cel_local_nonprim : NULL
        );

    return v1_device_selector_local_var;
end:
    if (cel_local_nonprim) {
        v1_cel_device_selector_free(cel_local_nonprim);
        cel_local_nonprim = NULL;
    }
    return NULL;

}
