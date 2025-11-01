#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_cel_device_selector.h"



static v1_cel_device_selector_t *v1_cel_device_selector_create_internal(
    char *expression
    ) {
    v1_cel_device_selector_t *v1_cel_device_selector_local_var = malloc(sizeof(v1_cel_device_selector_t));
    if (!v1_cel_device_selector_local_var) {
        return NULL;
    }
    v1_cel_device_selector_local_var->expression = expression;

    v1_cel_device_selector_local_var->_library_owned = 1;
    return v1_cel_device_selector_local_var;
}

__attribute__((deprecated)) v1_cel_device_selector_t *v1_cel_device_selector_create(
    char *expression
    ) {
    return v1_cel_device_selector_create_internal (
        expression
        );
}

void v1_cel_device_selector_free(v1_cel_device_selector_t *v1_cel_device_selector) {
    if(NULL == v1_cel_device_selector){
        return ;
    }
    if(v1_cel_device_selector->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_cel_device_selector_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_cel_device_selector->expression) {
        free(v1_cel_device_selector->expression);
        v1_cel_device_selector->expression = NULL;
    }
    free(v1_cel_device_selector);
}

cJSON *v1_cel_device_selector_convertToJSON(v1_cel_device_selector_t *v1_cel_device_selector) {
    cJSON *item = cJSON_CreateObject();

    // v1_cel_device_selector->expression
    if (!v1_cel_device_selector->expression) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "expression", v1_cel_device_selector->expression) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_cel_device_selector_t *v1_cel_device_selector_parseFromJSON(cJSON *v1_cel_device_selectorJSON){

    v1_cel_device_selector_t *v1_cel_device_selector_local_var = NULL;

    // v1_cel_device_selector->expression
    cJSON *expression = cJSON_GetObjectItemCaseSensitive(v1_cel_device_selectorJSON, "expression");
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


    v1_cel_device_selector_local_var = v1_cel_device_selector_create_internal (
        strdup(expression->valuestring)
        );

    return v1_cel_device_selector_local_var;
end:
    return NULL;

}
