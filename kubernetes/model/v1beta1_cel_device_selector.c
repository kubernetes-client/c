#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_cel_device_selector.h"



static v1beta1_cel_device_selector_t *v1beta1_cel_device_selector_create_internal(
    char *expression
    ) {
    v1beta1_cel_device_selector_t *v1beta1_cel_device_selector_local_var = malloc(sizeof(v1beta1_cel_device_selector_t));
    if (!v1beta1_cel_device_selector_local_var) {
        return NULL;
    }
    v1beta1_cel_device_selector_local_var->expression = expression;

    v1beta1_cel_device_selector_local_var->_library_owned = 1;
    return v1beta1_cel_device_selector_local_var;
}

__attribute__((deprecated)) v1beta1_cel_device_selector_t *v1beta1_cel_device_selector_create(
    char *expression
    ) {
    return v1beta1_cel_device_selector_create_internal (
        expression
        );
}

void v1beta1_cel_device_selector_free(v1beta1_cel_device_selector_t *v1beta1_cel_device_selector) {
    if(NULL == v1beta1_cel_device_selector){
        return ;
    }
    if(v1beta1_cel_device_selector->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1beta1_cel_device_selector_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta1_cel_device_selector->expression) {
        free(v1beta1_cel_device_selector->expression);
        v1beta1_cel_device_selector->expression = NULL;
    }
    free(v1beta1_cel_device_selector);
}

cJSON *v1beta1_cel_device_selector_convertToJSON(v1beta1_cel_device_selector_t *v1beta1_cel_device_selector) {
    cJSON *item = cJSON_CreateObject();

    // v1beta1_cel_device_selector->expression
    if (!v1beta1_cel_device_selector->expression) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "expression", v1beta1_cel_device_selector->expression) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1beta1_cel_device_selector_t *v1beta1_cel_device_selector_parseFromJSON(cJSON *v1beta1_cel_device_selectorJSON){

    v1beta1_cel_device_selector_t *v1beta1_cel_device_selector_local_var = NULL;

    // v1beta1_cel_device_selector->expression
    cJSON *expression = cJSON_GetObjectItemCaseSensitive(v1beta1_cel_device_selectorJSON, "expression");
    if (cJSON_IsNull(expression)) {
        expression = NULL;
    }
    if (!expression) {
        goto end;
    }

    
    if(!cJSON_IsString(expression))
    {
    goto end; //String
    }


    v1beta1_cel_device_selector_local_var = v1beta1_cel_device_selector_create_internal (
        strdup(expression->valuestring)
        );

    return v1beta1_cel_device_selector_local_var;
end:
    return NULL;

}
