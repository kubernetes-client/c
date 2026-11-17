#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_toleration.h"



static v1_toleration_t *v1_toleration_create_internal(
    char *effect,
    char *key,
    char *_operator,
    long *toleration_seconds,
    char *value
    ) {
    v1_toleration_t *v1_toleration_local_var = malloc(sizeof(v1_toleration_t));
    if (!v1_toleration_local_var) {
        return NULL;
    }
    memset(v1_toleration_local_var, 0, sizeof(v1_toleration_t));
    v1_toleration_local_var->_library_owned = 1;
    v1_toleration_local_var->effect = effect;
    v1_toleration_local_var->key = key;
    v1_toleration_local_var->_operator = _operator;
    v1_toleration_local_var->toleration_seconds = toleration_seconds;
    v1_toleration_local_var->value = value;
    return v1_toleration_local_var;
}

__attribute__((deprecated)) v1_toleration_t *v1_toleration_create(
    char *effect,
    char *key,
    char *_operator,
    long *toleration_seconds,
    char *value
    ) {
    long *toleration_seconds_copy = NULL;
    if (toleration_seconds) {
        toleration_seconds_copy = malloc(sizeof(long));
        if (toleration_seconds_copy) *toleration_seconds_copy = *toleration_seconds;
    }
    v1_toleration_t *result = v1_toleration_create_internal (
        effect,
        key,
        _operator,
        toleration_seconds_copy,
        value
        );
    if (!result) {
        free(toleration_seconds_copy);
    }
    return result;
}

void v1_toleration_free(v1_toleration_t *v1_toleration) {
    if(NULL == v1_toleration){
        return ;
    }
    if(v1_toleration->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_toleration_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_toleration->effect) {
        free(v1_toleration->effect);
        v1_toleration->effect = NULL;
    }
    if (v1_toleration->key) {
        free(v1_toleration->key);
        v1_toleration->key = NULL;
    }
    if (v1_toleration->_operator) {
        free(v1_toleration->_operator);
        v1_toleration->_operator = NULL;
    }
    if (v1_toleration->toleration_seconds) {
        free(v1_toleration->toleration_seconds);
        v1_toleration->toleration_seconds = NULL;
    }
    if (v1_toleration->value) {
        free(v1_toleration->value);
        v1_toleration->value = NULL;
    }
    free(v1_toleration);
}

cJSON *v1_toleration_convertToJSON(v1_toleration_t *v1_toleration) {
    cJSON *item = cJSON_CreateObject();

    // v1_toleration->effect
    if(v1_toleration->effect) {
    if(cJSON_AddStringToObject(item, "effect", v1_toleration->effect) == NULL) {
    goto fail; //String
    }
    }


    // v1_toleration->key
    if(v1_toleration->key) {
    if(cJSON_AddStringToObject(item, "key", v1_toleration->key) == NULL) {
    goto fail; //String
    }
    }


    // v1_toleration->_operator
    if(v1_toleration->_operator) {
    if(cJSON_AddStringToObject(item, "operator", v1_toleration->_operator) == NULL) {
    goto fail; //String
    }
    }


    // v1_toleration->toleration_seconds
    if(v1_toleration->toleration_seconds) {
    if(cJSON_AddNumberToObject(item, "tolerationSeconds", *v1_toleration->toleration_seconds) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_toleration->value
    if(v1_toleration->value) {
    if(cJSON_AddStringToObject(item, "value", v1_toleration->value) == NULL) {
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

v1_toleration_t *v1_toleration_parseFromJSON(cJSON *v1_tolerationJSON){

    v1_toleration_t *v1_toleration_local_var = NULL;

    char *effect_local_str = NULL;

    char *key_local_str = NULL;

    char *_operator_local_str = NULL;

    // define the local variable for v1_toleration->toleration_seconds
    long *toleration_seconds_local_var = NULL;

    char *value_local_str = NULL;

    // v1_toleration->effect
    cJSON *effect = cJSON_GetObjectItemCaseSensitive(v1_tolerationJSON, "effect");
    if (cJSON_IsNull(effect)) {
        effect = NULL;
    }
    if (effect) { 
    if(!cJSON_IsString(effect) && !cJSON_IsNull(effect))
    {
    goto end; //String
    }
    }

    // v1_toleration->key
    cJSON *key = cJSON_GetObjectItemCaseSensitive(v1_tolerationJSON, "key");
    if (cJSON_IsNull(key)) {
        key = NULL;
    }
    if (key) { 
    if(!cJSON_IsString(key) && !cJSON_IsNull(key))
    {
    goto end; //String
    }
    }

    // v1_toleration->_operator
    cJSON *_operator = cJSON_GetObjectItemCaseSensitive(v1_tolerationJSON, "operator");
    if (cJSON_IsNull(_operator)) {
        _operator = NULL;
    }
    if (_operator) { 
    if(!cJSON_IsString(_operator) && !cJSON_IsNull(_operator))
    {
    goto end; //String
    }
    }

    // v1_toleration->toleration_seconds
    cJSON *toleration_seconds = cJSON_GetObjectItemCaseSensitive(v1_tolerationJSON, "tolerationSeconds");
    if (cJSON_IsNull(toleration_seconds)) {
        toleration_seconds = NULL;
    }
    if (toleration_seconds) { 
    if(!cJSON_IsNumber(toleration_seconds))
    {
    goto end; //Numeric
    }
    toleration_seconds_local_var = malloc(sizeof(long));
    if(!toleration_seconds_local_var)
    {
        goto end;
    }
    *toleration_seconds_local_var = toleration_seconds->valuedouble;
    }

    // v1_toleration->value
    cJSON *value = cJSON_GetObjectItemCaseSensitive(v1_tolerationJSON, "value");
    if (cJSON_IsNull(value)) {
        value = NULL;
    }
    if (value) { 
    if(!cJSON_IsString(value) && !cJSON_IsNull(value))
    {
    goto end; //String
    }
    }


    if (effect && !cJSON_IsNull(effect)) effect_local_str = strdup(effect->valuestring);
    if (key && !cJSON_IsNull(key)) key_local_str = strdup(key->valuestring);
    if (_operator && !cJSON_IsNull(_operator)) _operator_local_str = strdup(_operator->valuestring);
    if (value && !cJSON_IsNull(value)) value_local_str = strdup(value->valuestring);

    v1_toleration_local_var = v1_toleration_create_internal (
        effect_local_str,
        key_local_str,
        _operator_local_str,
        toleration_seconds_local_var,
        value_local_str
        );

    if (!v1_toleration_local_var) {
        goto end;
    }

    return v1_toleration_local_var;
end:
    if (effect_local_str) {
        free(effect_local_str);
        effect_local_str = NULL;
    }
    if (key_local_str) {
        free(key_local_str);
        key_local_str = NULL;
    }
    if (_operator_local_str) {
        free(_operator_local_str);
        _operator_local_str = NULL;
    }
    if (toleration_seconds_local_var) {
        free(toleration_seconds_local_var);
        toleration_seconds_local_var = NULL;
    }
    if (value_local_str) {
        free(value_local_str);
        value_local_str = NULL;
    }
    return NULL;

}
