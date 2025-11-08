#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_device_toleration.h"



static v1_device_toleration_t *v1_device_toleration_create_internal(
    char *effect,
    char *key,
    char *_operator,
    long toleration_seconds,
    char *value
    ) {
    v1_device_toleration_t *v1_device_toleration_local_var = malloc(sizeof(v1_device_toleration_t));
    if (!v1_device_toleration_local_var) {
        return NULL;
    }
    v1_device_toleration_local_var->effect = effect;
    v1_device_toleration_local_var->key = key;
    v1_device_toleration_local_var->_operator = _operator;
    v1_device_toleration_local_var->toleration_seconds = toleration_seconds;
    v1_device_toleration_local_var->value = value;

    v1_device_toleration_local_var->_library_owned = 1;
    return v1_device_toleration_local_var;
}

__attribute__((deprecated)) v1_device_toleration_t *v1_device_toleration_create(
    char *effect,
    char *key,
    char *_operator,
    long toleration_seconds,
    char *value
    ) {
    return v1_device_toleration_create_internal (
        effect,
        key,
        _operator,
        toleration_seconds,
        value
        );
}

void v1_device_toleration_free(v1_device_toleration_t *v1_device_toleration) {
    if(NULL == v1_device_toleration){
        return ;
    }
    if(v1_device_toleration->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_device_toleration_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_device_toleration->effect) {
        free(v1_device_toleration->effect);
        v1_device_toleration->effect = NULL;
    }
    if (v1_device_toleration->key) {
        free(v1_device_toleration->key);
        v1_device_toleration->key = NULL;
    }
    if (v1_device_toleration->_operator) {
        free(v1_device_toleration->_operator);
        v1_device_toleration->_operator = NULL;
    }
    if (v1_device_toleration->value) {
        free(v1_device_toleration->value);
        v1_device_toleration->value = NULL;
    }
    free(v1_device_toleration);
}

cJSON *v1_device_toleration_convertToJSON(v1_device_toleration_t *v1_device_toleration) {
    cJSON *item = cJSON_CreateObject();

    // v1_device_toleration->effect
    if(v1_device_toleration->effect) {
    if(cJSON_AddStringToObject(item, "effect", v1_device_toleration->effect) == NULL) {
    goto fail; //String
    }
    }


    // v1_device_toleration->key
    if(v1_device_toleration->key) {
    if(cJSON_AddStringToObject(item, "key", v1_device_toleration->key) == NULL) {
    goto fail; //String
    }
    }


    // v1_device_toleration->_operator
    if(v1_device_toleration->_operator) {
    if(cJSON_AddStringToObject(item, "operator", v1_device_toleration->_operator) == NULL) {
    goto fail; //String
    }
    }


    // v1_device_toleration->toleration_seconds
    if(v1_device_toleration->toleration_seconds) {
    if(cJSON_AddNumberToObject(item, "tolerationSeconds", v1_device_toleration->toleration_seconds) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_device_toleration->value
    if(v1_device_toleration->value) {
    if(cJSON_AddStringToObject(item, "value", v1_device_toleration->value) == NULL) {
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

v1_device_toleration_t *v1_device_toleration_parseFromJSON(cJSON *v1_device_tolerationJSON){

    v1_device_toleration_t *v1_device_toleration_local_var = NULL;

    // v1_device_toleration->effect
    cJSON *effect = cJSON_GetObjectItemCaseSensitive(v1_device_tolerationJSON, "effect");
    if (cJSON_IsNull(effect)) {
        effect = NULL;
    }
    if (effect) { 
    if(!cJSON_IsString(effect) && !cJSON_IsNull(effect))
    {
    goto end; //String
    }
    }

    // v1_device_toleration->key
    cJSON *key = cJSON_GetObjectItemCaseSensitive(v1_device_tolerationJSON, "key");
    if (cJSON_IsNull(key)) {
        key = NULL;
    }
    if (key) { 
    if(!cJSON_IsString(key) && !cJSON_IsNull(key))
    {
    goto end; //String
    }
    }

    // v1_device_toleration->_operator
    cJSON *_operator = cJSON_GetObjectItemCaseSensitive(v1_device_tolerationJSON, "operator");
    if (cJSON_IsNull(_operator)) {
        _operator = NULL;
    }
    if (_operator) { 
    if(!cJSON_IsString(_operator) && !cJSON_IsNull(_operator))
    {
    goto end; //String
    }
    }

    // v1_device_toleration->toleration_seconds
    cJSON *toleration_seconds = cJSON_GetObjectItemCaseSensitive(v1_device_tolerationJSON, "tolerationSeconds");
    if (cJSON_IsNull(toleration_seconds)) {
        toleration_seconds = NULL;
    }
    if (toleration_seconds) { 
    if(!cJSON_IsNumber(toleration_seconds))
    {
    goto end; //Numeric
    }
    }

    // v1_device_toleration->value
    cJSON *value = cJSON_GetObjectItemCaseSensitive(v1_device_tolerationJSON, "value");
    if (cJSON_IsNull(value)) {
        value = NULL;
    }
    if (value) { 
    if(!cJSON_IsString(value) && !cJSON_IsNull(value))
    {
    goto end; //String
    }
    }


    v1_device_toleration_local_var = v1_device_toleration_create_internal (
        effect && !cJSON_IsNull(effect) ? strdup(effect->valuestring) : NULL,
        key && !cJSON_IsNull(key) ? strdup(key->valuestring) : NULL,
        _operator && !cJSON_IsNull(_operator) ? strdup(_operator->valuestring) : NULL,
        toleration_seconds ? toleration_seconds->valuedouble : 0,
        value && !cJSON_IsNull(value) ? strdup(value->valuestring) : NULL
        );

    return v1_device_toleration_local_var;
end:
    return NULL;

}
