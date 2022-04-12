#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_toleration.h"


char* effectv1_toleration_ToString(kubernetes_v1_toleration_EFFECT_e effect) {
    char* effectArray[] =  { "NULL", "NoExecute", "NoSchedule", "PreferNoSchedule" };
	return effectArray[effect];
}

kubernetes_v1_toleration_EFFECT_e effectv1_toleration_FromString(char* effect){
    int stringToReturn = 0;
    char *effectArray[] =  { "NULL", "NoExecute", "NoSchedule", "PreferNoSchedule" };
    size_t sizeofArray = sizeof(effectArray) / sizeof(effectArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(effect, effectArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}
char* _operatorv1_toleration_ToString(kubernetes_v1_toleration_OPERATOR_e _operator) {
    char* _operatorArray[] =  { "NULL", "Equal", "Exists" };
	return _operatorArray[_operator];
}

kubernetes_v1_toleration_OPERATOR_e _operatorv1_toleration_FromString(char* _operator){
    int stringToReturn = 0;
    char *_operatorArray[] =  { "NULL", "Equal", "Exists" };
    size_t sizeofArray = sizeof(_operatorArray) / sizeof(_operatorArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(_operator, _operatorArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

v1_toleration_t *v1_toleration_create(
    kubernetes_v1_toleration_EFFECT_e effect,
    char *key,
    kubernetes_v1_toleration_OPERATOR_e _operator,
    long toleration_seconds,
    char *value
    ) {
    v1_toleration_t *v1_toleration_local_var = malloc(sizeof(v1_toleration_t));
    if (!v1_toleration_local_var) {
        return NULL;
    }
    v1_toleration_local_var->effect = effect;
    v1_toleration_local_var->key = key;
    v1_toleration_local_var->_operator = _operator;
    v1_toleration_local_var->toleration_seconds = toleration_seconds;
    v1_toleration_local_var->value = value;

    return v1_toleration_local_var;
}


void v1_toleration_free(v1_toleration_t *v1_toleration) {
    if(NULL == v1_toleration){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_toleration->key) {
        free(v1_toleration->key);
        v1_toleration->key = NULL;
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
    
    if(cJSON_AddStringToObject(item, "effect", effectv1_toleration_ToString(v1_toleration->effect)) == NULL)
    {
    goto fail; //Enum
    }
    


    // v1_toleration->key
    if(v1_toleration->key) { 
    if(cJSON_AddStringToObject(item, "key", v1_toleration->key) == NULL) {
    goto fail; //String
    }
     } 


    // v1_toleration->_operator
    
    if(cJSON_AddStringToObject(item, "operator", _operatorv1_toleration_ToString(v1_toleration->_operator)) == NULL)
    {
    goto fail; //Enum
    }
    


    // v1_toleration->toleration_seconds
    if(v1_toleration->toleration_seconds) { 
    if(cJSON_AddNumberToObject(item, "tolerationSeconds", v1_toleration->toleration_seconds) == NULL) {
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

    // v1_toleration->effect
    cJSON *effect = cJSON_GetObjectItemCaseSensitive(v1_tolerationJSON, "effect");
    kubernetes_v1_toleration_EFFECT_e effectVariable;
    if (effect) { 
    if(!cJSON_IsString(effect))
    {
    goto end; //Enum
    }
    effectVariable = effectv1_toleration_FromString(effect->valuestring);
    }

    // v1_toleration->key
    cJSON *key = cJSON_GetObjectItemCaseSensitive(v1_tolerationJSON, "key");
    if (key) { 
    if(!cJSON_IsString(key))
    {
    goto end; //String
    }
    }

    // v1_toleration->_operator
    cJSON *_operator = cJSON_GetObjectItemCaseSensitive(v1_tolerationJSON, "operator");
    kubernetes_v1_toleration_OPERATOR_e _operatorVariable;
    if (_operator) { 
    if(!cJSON_IsString(_operator))
    {
    goto end; //Enum
    }
    _operatorVariable = _operatorv1_toleration_FromString(_operator->valuestring);
    }

    // v1_toleration->toleration_seconds
    cJSON *toleration_seconds = cJSON_GetObjectItemCaseSensitive(v1_tolerationJSON, "tolerationSeconds");
    if (toleration_seconds) { 
    if(!cJSON_IsNumber(toleration_seconds))
    {
    goto end; //Numeric
    }
    }

    // v1_toleration->value
    cJSON *value = cJSON_GetObjectItemCaseSensitive(v1_tolerationJSON, "value");
    if (value) { 
    if(!cJSON_IsString(value))
    {
    goto end; //String
    }
    }


    v1_toleration_local_var = v1_toleration_create (
        effect ? effectVariable : -1,
        key ? strdup(key->valuestring) : NULL,
        _operator ? _operatorVariable : -1,
        toleration_seconds ? toleration_seconds->valuedouble : 0,
        value ? strdup(value->valuestring) : NULL
        );

    return v1_toleration_local_var;
end:
    return NULL;

}
