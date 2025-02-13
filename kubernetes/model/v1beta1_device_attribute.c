#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_device_attribute.h"



static v1beta1_device_attribute_t *v1beta1_device_attribute_create_internal(
    int _bool,
    long _int,
    char *string,
    char *version
    ) {
    v1beta1_device_attribute_t *v1beta1_device_attribute_local_var = malloc(sizeof(v1beta1_device_attribute_t));
    if (!v1beta1_device_attribute_local_var) {
        return NULL;
    }
    v1beta1_device_attribute_local_var->_bool = _bool;
    v1beta1_device_attribute_local_var->_int = _int;
    v1beta1_device_attribute_local_var->string = string;
    v1beta1_device_attribute_local_var->version = version;

    v1beta1_device_attribute_local_var->_library_owned = 1;
    return v1beta1_device_attribute_local_var;
}

__attribute__((deprecated)) v1beta1_device_attribute_t *v1beta1_device_attribute_create(
    int _bool,
    long _int,
    char *string,
    char *version
    ) {
    return v1beta1_device_attribute_create_internal (
        _bool,
        _int,
        string,
        version
        );
}

void v1beta1_device_attribute_free(v1beta1_device_attribute_t *v1beta1_device_attribute) {
    if(NULL == v1beta1_device_attribute){
        return ;
    }
    if(v1beta1_device_attribute->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1beta1_device_attribute_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta1_device_attribute->string) {
        free(v1beta1_device_attribute->string);
        v1beta1_device_attribute->string = NULL;
    }
    if (v1beta1_device_attribute->version) {
        free(v1beta1_device_attribute->version);
        v1beta1_device_attribute->version = NULL;
    }
    free(v1beta1_device_attribute);
}

cJSON *v1beta1_device_attribute_convertToJSON(v1beta1_device_attribute_t *v1beta1_device_attribute) {
    cJSON *item = cJSON_CreateObject();

    // v1beta1_device_attribute->_bool
    if(v1beta1_device_attribute->_bool) {
    if(cJSON_AddBoolToObject(item, "bool", v1beta1_device_attribute->_bool) == NULL) {
    goto fail; //Bool
    }
    }


    // v1beta1_device_attribute->_int
    if(v1beta1_device_attribute->_int) {
    if(cJSON_AddNumberToObject(item, "int", v1beta1_device_attribute->_int) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1beta1_device_attribute->string
    if(v1beta1_device_attribute->string) {
    if(cJSON_AddStringToObject(item, "string", v1beta1_device_attribute->string) == NULL) {
    goto fail; //String
    }
    }


    // v1beta1_device_attribute->version
    if(v1beta1_device_attribute->version) {
    if(cJSON_AddStringToObject(item, "version", v1beta1_device_attribute->version) == NULL) {
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

v1beta1_device_attribute_t *v1beta1_device_attribute_parseFromJSON(cJSON *v1beta1_device_attributeJSON){

    v1beta1_device_attribute_t *v1beta1_device_attribute_local_var = NULL;

    // v1beta1_device_attribute->_bool
    cJSON *_bool = cJSON_GetObjectItemCaseSensitive(v1beta1_device_attributeJSON, "bool");
    if (cJSON_IsNull(_bool)) {
        _bool = NULL;
    }
    if (_bool) { 
    if(!cJSON_IsBool(_bool))
    {
    goto end; //Bool
    }
    }

    // v1beta1_device_attribute->_int
    cJSON *_int = cJSON_GetObjectItemCaseSensitive(v1beta1_device_attributeJSON, "int");
    if (cJSON_IsNull(_int)) {
        _int = NULL;
    }
    if (_int) { 
    if(!cJSON_IsNumber(_int))
    {
    goto end; //Numeric
    }
    }

    // v1beta1_device_attribute->string
    cJSON *string = cJSON_GetObjectItemCaseSensitive(v1beta1_device_attributeJSON, "string");
    if (cJSON_IsNull(string)) {
        string = NULL;
    }
    if (string) { 
    if(!cJSON_IsString(string) && !cJSON_IsNull(string))
    {
    goto end; //String
    }
    }

    // v1beta1_device_attribute->version
    cJSON *version = cJSON_GetObjectItemCaseSensitive(v1beta1_device_attributeJSON, "version");
    if (cJSON_IsNull(version)) {
        version = NULL;
    }
    if (version) { 
    if(!cJSON_IsString(version) && !cJSON_IsNull(version))
    {
    goto end; //String
    }
    }


    v1beta1_device_attribute_local_var = v1beta1_device_attribute_create_internal (
        _bool ? _bool->valueint : 0,
        _int ? _int->valuedouble : 0,
        string && !cJSON_IsNull(string) ? strdup(string->valuestring) : NULL,
        version && !cJSON_IsNull(version) ? strdup(version->valuestring) : NULL
        );

    return v1beta1_device_attribute_local_var;
end:
    return NULL;

}
