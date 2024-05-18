#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha2_named_resources_attribute.h"



v1alpha2_named_resources_attribute_t *v1alpha2_named_resources_attribute_create(
    int _bool,
    long _int,
    v1alpha2_named_resources_int_slice_t *int_slice,
    char *name,
    char *quantity,
    char *string,
    v1alpha2_named_resources_string_slice_t *string_slice,
    char *version
    ) {
    v1alpha2_named_resources_attribute_t *v1alpha2_named_resources_attribute_local_var = malloc(sizeof(v1alpha2_named_resources_attribute_t));
    if (!v1alpha2_named_resources_attribute_local_var) {
        return NULL;
    }
    v1alpha2_named_resources_attribute_local_var->_bool = _bool;
    v1alpha2_named_resources_attribute_local_var->_int = _int;
    v1alpha2_named_resources_attribute_local_var->int_slice = int_slice;
    v1alpha2_named_resources_attribute_local_var->name = name;
    v1alpha2_named_resources_attribute_local_var->quantity = quantity;
    v1alpha2_named_resources_attribute_local_var->string = string;
    v1alpha2_named_resources_attribute_local_var->string_slice = string_slice;
    v1alpha2_named_resources_attribute_local_var->version = version;

    return v1alpha2_named_resources_attribute_local_var;
}


void v1alpha2_named_resources_attribute_free(v1alpha2_named_resources_attribute_t *v1alpha2_named_resources_attribute) {
    if(NULL == v1alpha2_named_resources_attribute){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha2_named_resources_attribute->int_slice) {
        v1alpha2_named_resources_int_slice_free(v1alpha2_named_resources_attribute->int_slice);
        v1alpha2_named_resources_attribute->int_slice = NULL;
    }
    if (v1alpha2_named_resources_attribute->name) {
        free(v1alpha2_named_resources_attribute->name);
        v1alpha2_named_resources_attribute->name = NULL;
    }
    if (v1alpha2_named_resources_attribute->quantity) {
        free(v1alpha2_named_resources_attribute->quantity);
        v1alpha2_named_resources_attribute->quantity = NULL;
    }
    if (v1alpha2_named_resources_attribute->string) {
        free(v1alpha2_named_resources_attribute->string);
        v1alpha2_named_resources_attribute->string = NULL;
    }
    if (v1alpha2_named_resources_attribute->string_slice) {
        v1alpha2_named_resources_string_slice_free(v1alpha2_named_resources_attribute->string_slice);
        v1alpha2_named_resources_attribute->string_slice = NULL;
    }
    if (v1alpha2_named_resources_attribute->version) {
        free(v1alpha2_named_resources_attribute->version);
        v1alpha2_named_resources_attribute->version = NULL;
    }
    free(v1alpha2_named_resources_attribute);
}

cJSON *v1alpha2_named_resources_attribute_convertToJSON(v1alpha2_named_resources_attribute_t *v1alpha2_named_resources_attribute) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha2_named_resources_attribute->_bool
    if(v1alpha2_named_resources_attribute->_bool) {
    if(cJSON_AddBoolToObject(item, "bool", v1alpha2_named_resources_attribute->_bool) == NULL) {
    goto fail; //Bool
    }
    }


    // v1alpha2_named_resources_attribute->_int
    if(v1alpha2_named_resources_attribute->_int) {
    if(cJSON_AddNumberToObject(item, "int", v1alpha2_named_resources_attribute->_int) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1alpha2_named_resources_attribute->int_slice
    if(v1alpha2_named_resources_attribute->int_slice) {
    cJSON *int_slice_local_JSON = v1alpha2_named_resources_int_slice_convertToJSON(v1alpha2_named_resources_attribute->int_slice);
    if(int_slice_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "intSlice", int_slice_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1alpha2_named_resources_attribute->name
    if (!v1alpha2_named_resources_attribute->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", v1alpha2_named_resources_attribute->name) == NULL) {
    goto fail; //String
    }


    // v1alpha2_named_resources_attribute->quantity
    if(v1alpha2_named_resources_attribute->quantity) {
    if(cJSON_AddStringToObject(item, "quantity", v1alpha2_named_resources_attribute->quantity) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha2_named_resources_attribute->string
    if(v1alpha2_named_resources_attribute->string) {
    if(cJSON_AddStringToObject(item, "string", v1alpha2_named_resources_attribute->string) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha2_named_resources_attribute->string_slice
    if(v1alpha2_named_resources_attribute->string_slice) {
    cJSON *string_slice_local_JSON = v1alpha2_named_resources_string_slice_convertToJSON(v1alpha2_named_resources_attribute->string_slice);
    if(string_slice_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "stringSlice", string_slice_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1alpha2_named_resources_attribute->version
    if(v1alpha2_named_resources_attribute->version) {
    if(cJSON_AddStringToObject(item, "version", v1alpha2_named_resources_attribute->version) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1alpha2_named_resources_attribute_t *v1alpha2_named_resources_attribute_parseFromJSON(cJSON *v1alpha2_named_resources_attributeJSON){

    v1alpha2_named_resources_attribute_t *v1alpha2_named_resources_attribute_local_var = NULL;

    // define the local variable for v1alpha2_named_resources_attribute->int_slice
    v1alpha2_named_resources_int_slice_t *int_slice_local_nonprim = NULL;

    // define the local variable for v1alpha2_named_resources_attribute->string_slice
    v1alpha2_named_resources_string_slice_t *string_slice_local_nonprim = NULL;

    // v1alpha2_named_resources_attribute->_bool
    cJSON *_bool = cJSON_GetObjectItemCaseSensitive(v1alpha2_named_resources_attributeJSON, "bool");
    if (_bool) { 
    if(!cJSON_IsBool(_bool))
    {
    goto end; //Bool
    }
    }

    // v1alpha2_named_resources_attribute->_int
    cJSON *_int = cJSON_GetObjectItemCaseSensitive(v1alpha2_named_resources_attributeJSON, "int");
    if (_int) { 
    if(!cJSON_IsNumber(_int))
    {
    goto end; //Numeric
    }
    }

    // v1alpha2_named_resources_attribute->int_slice
    cJSON *int_slice = cJSON_GetObjectItemCaseSensitive(v1alpha2_named_resources_attributeJSON, "intSlice");
    if (int_slice) { 
    int_slice_local_nonprim = v1alpha2_named_resources_int_slice_parseFromJSON(int_slice); //nonprimitive
    }

    // v1alpha2_named_resources_attribute->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1alpha2_named_resources_attributeJSON, "name");
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // v1alpha2_named_resources_attribute->quantity
    cJSON *quantity = cJSON_GetObjectItemCaseSensitive(v1alpha2_named_resources_attributeJSON, "quantity");
    if (quantity) { 
    if(!cJSON_IsString(quantity) && !cJSON_IsNull(quantity))
    {
    goto end; //String
    }
    }

    // v1alpha2_named_resources_attribute->string
    cJSON *string = cJSON_GetObjectItemCaseSensitive(v1alpha2_named_resources_attributeJSON, "string");
    if (string) { 
    if(!cJSON_IsString(string) && !cJSON_IsNull(string))
    {
    goto end; //String
    }
    }

    // v1alpha2_named_resources_attribute->string_slice
    cJSON *string_slice = cJSON_GetObjectItemCaseSensitive(v1alpha2_named_resources_attributeJSON, "stringSlice");
    if (string_slice) { 
    string_slice_local_nonprim = v1alpha2_named_resources_string_slice_parseFromJSON(string_slice); //nonprimitive
    }

    // v1alpha2_named_resources_attribute->version
    cJSON *version = cJSON_GetObjectItemCaseSensitive(v1alpha2_named_resources_attributeJSON, "version");
    if (version) { 
    if(!cJSON_IsString(version) && !cJSON_IsNull(version))
    {
    goto end; //String
    }
    }


    v1alpha2_named_resources_attribute_local_var = v1alpha2_named_resources_attribute_create (
        _bool ? _bool->valueint : 0,
        _int ? _int->valuedouble : 0,
        int_slice ? int_slice_local_nonprim : NULL,
        strdup(name->valuestring),
        quantity && !cJSON_IsNull(quantity) ? strdup(quantity->valuestring) : NULL,
        string && !cJSON_IsNull(string) ? strdup(string->valuestring) : NULL,
        string_slice ? string_slice_local_nonprim : NULL,
        version && !cJSON_IsNull(version) ? strdup(version->valuestring) : NULL
        );

    return v1alpha2_named_resources_attribute_local_var;
end:
    if (int_slice_local_nonprim) {
        v1alpha2_named_resources_int_slice_free(int_slice_local_nonprim);
        int_slice_local_nonprim = NULL;
    }
    if (string_slice_local_nonprim) {
        v1alpha2_named_resources_string_slice_free(string_slice_local_nonprim);
        string_slice_local_nonprim = NULL;
    }
    return NULL;

}
