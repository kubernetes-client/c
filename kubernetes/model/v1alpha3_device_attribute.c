#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha3_device_attribute.h"



v1alpha3_device_attribute_t *v1alpha3_device_attribute_create(
    int _bool,
    long _int,
    char *string,
    char *version
    ) {
    v1alpha3_device_attribute_t *v1alpha3_device_attribute_local_var = malloc(sizeof(v1alpha3_device_attribute_t));
    if (!v1alpha3_device_attribute_local_var) {
        return NULL;
    }
    v1alpha3_device_attribute_local_var->_bool = _bool;
    v1alpha3_device_attribute_local_var->_int = _int;
    v1alpha3_device_attribute_local_var->string = string;
    v1alpha3_device_attribute_local_var->version = version;

    return v1alpha3_device_attribute_local_var;
}


void v1alpha3_device_attribute_free(v1alpha3_device_attribute_t *v1alpha3_device_attribute) {
    if(NULL == v1alpha3_device_attribute){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha3_device_attribute->string) {
        free(v1alpha3_device_attribute->string);
        v1alpha3_device_attribute->string = NULL;
    }
    if (v1alpha3_device_attribute->version) {
        free(v1alpha3_device_attribute->version);
        v1alpha3_device_attribute->version = NULL;
    }
    free(v1alpha3_device_attribute);
}

cJSON *v1alpha3_device_attribute_convertToJSON(v1alpha3_device_attribute_t *v1alpha3_device_attribute) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha3_device_attribute->_bool
    if(v1alpha3_device_attribute->_bool) {
    if(cJSON_AddBoolToObject(item, "bool", v1alpha3_device_attribute->_bool) == NULL) {
    goto fail; //Bool
    }
    }


    // v1alpha3_device_attribute->_int
    if(v1alpha3_device_attribute->_int) {
    if(cJSON_AddNumberToObject(item, "int", v1alpha3_device_attribute->_int) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1alpha3_device_attribute->string
    if(v1alpha3_device_attribute->string) {
    if(cJSON_AddStringToObject(item, "string", v1alpha3_device_attribute->string) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha3_device_attribute->version
    if(v1alpha3_device_attribute->version) {
    if(cJSON_AddStringToObject(item, "version", v1alpha3_device_attribute->version) == NULL) {
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

v1alpha3_device_attribute_t *v1alpha3_device_attribute_parseFromJSON(cJSON *v1alpha3_device_attributeJSON){

    v1alpha3_device_attribute_t *v1alpha3_device_attribute_local_var = NULL;

    // v1alpha3_device_attribute->_bool
    cJSON *_bool = cJSON_GetObjectItemCaseSensitive(v1alpha3_device_attributeJSON, "bool");
    if (_bool) { 
    if(!cJSON_IsBool(_bool))
    {
    goto end; //Bool
    }
    }

    // v1alpha3_device_attribute->_int
    cJSON *_int = cJSON_GetObjectItemCaseSensitive(v1alpha3_device_attributeJSON, "int");
    if (_int) { 
    if(!cJSON_IsNumber(_int))
    {
    goto end; //Numeric
    }
    }

    // v1alpha3_device_attribute->string
    cJSON *string = cJSON_GetObjectItemCaseSensitive(v1alpha3_device_attributeJSON, "string");
    if (string) { 
    if(!cJSON_IsString(string) && !cJSON_IsNull(string))
    {
    goto end; //String
    }
    }

    // v1alpha3_device_attribute->version
    cJSON *version = cJSON_GetObjectItemCaseSensitive(v1alpha3_device_attributeJSON, "version");
    if (version) { 
    if(!cJSON_IsString(version) && !cJSON_IsNull(version))
    {
    goto end; //String
    }
    }


    v1alpha3_device_attribute_local_var = v1alpha3_device_attribute_create (
        _bool ? _bool->valueint : 0,
        _int ? _int->valuedouble : 0,
        string && !cJSON_IsNull(string) ? strdup(string->valuestring) : NULL,
        version && !cJSON_IsNull(version) ? strdup(version->valuestring) : NULL
        );

    return v1alpha3_device_attribute_local_var;
end:
    return NULL;

}
