#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_device_derived_attribute.h"



static v1_device_derived_attribute_t *v1_device_derived_attribute_create_internal(
    char *expression,
    char *name
    ) {
    v1_device_derived_attribute_t *v1_device_derived_attribute_local_var = malloc(sizeof(v1_device_derived_attribute_t));
    if (!v1_device_derived_attribute_local_var) {
        return NULL;
    }
    memset(v1_device_derived_attribute_local_var, 0, sizeof(v1_device_derived_attribute_t));
    v1_device_derived_attribute_local_var->_library_owned = 1;
    v1_device_derived_attribute_local_var->expression = expression;
    v1_device_derived_attribute_local_var->name = name;
    return v1_device_derived_attribute_local_var;
}

__attribute__((deprecated)) v1_device_derived_attribute_t *v1_device_derived_attribute_create(
    char *expression,
    char *name
    ) {
    v1_device_derived_attribute_t *result = v1_device_derived_attribute_create_internal (
        expression,
        name
        );
    if (!result) {
    }
    return result;
}

void v1_device_derived_attribute_free(v1_device_derived_attribute_t *v1_device_derived_attribute) {
    if(NULL == v1_device_derived_attribute){
        return ;
    }
    if(v1_device_derived_attribute->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_device_derived_attribute_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_device_derived_attribute->expression) {
        free(v1_device_derived_attribute->expression);
        v1_device_derived_attribute->expression = NULL;
    }
    if (v1_device_derived_attribute->name) {
        free(v1_device_derived_attribute->name);
        v1_device_derived_attribute->name = NULL;
    }
    free(v1_device_derived_attribute);
}

cJSON *v1_device_derived_attribute_convertToJSON(v1_device_derived_attribute_t *v1_device_derived_attribute) {
    cJSON *item = cJSON_CreateObject();

    // v1_device_derived_attribute->expression
    if (!v1_device_derived_attribute->expression) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "expression", v1_device_derived_attribute->expression) == NULL) {
    goto fail; //String
    }


    // v1_device_derived_attribute->name
    if (!v1_device_derived_attribute->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", v1_device_derived_attribute->name) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_device_derived_attribute_t *v1_device_derived_attribute_parseFromJSON(cJSON *v1_device_derived_attributeJSON){

    v1_device_derived_attribute_t *v1_device_derived_attribute_local_var = NULL;

    char *expression_local_str = NULL;

    char *name_local_str = NULL;

    // v1_device_derived_attribute->expression
    cJSON *expression = cJSON_GetObjectItemCaseSensitive(v1_device_derived_attributeJSON, "expression");
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

    // v1_device_derived_attribute->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1_device_derived_attributeJSON, "name");
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


    if (expression && !cJSON_IsNull(expression)) expression_local_str = strdup(expression->valuestring);
    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);

    v1_device_derived_attribute_local_var = v1_device_derived_attribute_create_internal (
        expression_local_str,
        name_local_str
        );

    if (!v1_device_derived_attribute_local_var) {
        goto end;
    }

    return v1_device_derived_attribute_local_var;
end:
    if (expression_local_str) {
        free(expression_local_str);
        expression_local_str = NULL;
    }
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    return NULL;

}
