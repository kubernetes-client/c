#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_device_attribute.h"



static v1_device_attribute_t *v1_device_attribute_create_internal(
    int _bool,
    long _int,
    char *string,
    char *version
    ) {
    v1_device_attribute_t *v1_device_attribute_local_var = malloc(sizeof(v1_device_attribute_t));
    if (!v1_device_attribute_local_var) {
        return NULL;
    }
    v1_device_attribute_local_var->_bool = _bool;
    v1_device_attribute_local_var->_int = _int;
    v1_device_attribute_local_var->string = string;
    v1_device_attribute_local_var->version = version;

    v1_device_attribute_local_var->_library_owned = 1;
    return v1_device_attribute_local_var;
}

__attribute__((deprecated)) v1_device_attribute_t *v1_device_attribute_create(
    int _bool,
    long _int,
    char *string,
    char *version
    ) {
    return v1_device_attribute_create_internal (
        _bool,
        _int,
        string,
        version
        );
}

void v1_device_attribute_free(v1_device_attribute_t *v1_device_attribute) {
    if(NULL == v1_device_attribute){
        return ;
    }
    if(v1_device_attribute->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_device_attribute_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_device_attribute->string) {
        free(v1_device_attribute->string);
        v1_device_attribute->string = NULL;
    }
    if (v1_device_attribute->version) {
        free(v1_device_attribute->version);
        v1_device_attribute->version = NULL;
    }
    free(v1_device_attribute);
}

cJSON *v1_device_attribute_convertToJSON(v1_device_attribute_t *v1_device_attribute) {
    cJSON *item = cJSON_CreateObject();

    // v1_device_attribute->_bool
    if(v1_device_attribute->_bool) {
    if(cJSON_AddBoolToObject(item, "bool", v1_device_attribute->_bool) == NULL) {
    goto fail; //Bool
    }
    }


    // v1_device_attribute->_int
    if(v1_device_attribute->_int) {
    if(cJSON_AddNumberToObject(item, "int", v1_device_attribute->_int) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_device_attribute->string
    if(v1_device_attribute->string) {
    if(cJSON_AddStringToObject(item, "string", v1_device_attribute->string) == NULL) {
    goto fail; //String
    }
    }


    // v1_device_attribute->version
    if(v1_device_attribute->version) {
    if(cJSON_AddStringToObject(item, "version", v1_device_attribute->version) == NULL) {
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

v1_device_attribute_t *v1_device_attribute_parseFromJSON(cJSON *v1_device_attributeJSON){

    v1_device_attribute_t *v1_device_attribute_local_var = NULL;

    // v1_device_attribute->_bool
    cJSON *_bool = cJSON_GetObjectItemCaseSensitive(v1_device_attributeJSON, "bool");
    if (cJSON_IsNull(_bool)) {
        _bool = NULL;
    }
    if (_bool) { 
    if(!cJSON_IsBool(_bool))
    {
    goto end; //Bool
    }
    }

    // v1_device_attribute->_int
    cJSON *_int = cJSON_GetObjectItemCaseSensitive(v1_device_attributeJSON, "int");
    if (cJSON_IsNull(_int)) {
        _int = NULL;
    }
    if (_int) { 
    if(!cJSON_IsNumber(_int))
    {
    goto end; //Numeric
    }
    }

    // v1_device_attribute->string
    cJSON *string = cJSON_GetObjectItemCaseSensitive(v1_device_attributeJSON, "string");
    if (cJSON_IsNull(string)) {
        string = NULL;
    }
    if (string) { 
    if(!cJSON_IsString(string) && !cJSON_IsNull(string))
    {
    goto end; //String
    }
    }

    // v1_device_attribute->version
    cJSON *version = cJSON_GetObjectItemCaseSensitive(v1_device_attributeJSON, "version");
    if (cJSON_IsNull(version)) {
        version = NULL;
    }
    if (version) { 
    if(!cJSON_IsString(version) && !cJSON_IsNull(version))
    {
    goto end; //String
    }
    }


    v1_device_attribute_local_var = v1_device_attribute_create_internal (
        _bool ? _bool->valueint : 0,
        _int ? _int->valuedouble : 0,
        string && !cJSON_IsNull(string) ? strdup(string->valuestring) : NULL,
        version && !cJSON_IsNull(version) ? strdup(version->valuestring) : NULL
        );

    return v1_device_attribute_local_var;
end:
    return NULL;

}
