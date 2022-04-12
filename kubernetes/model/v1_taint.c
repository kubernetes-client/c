#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_taint.h"


char* effectv1_taint_ToString(kubernetes_v1_taint_EFFECT_e effect) {
    char* effectArray[] =  { "NULL", "NoExecute", "NoSchedule", "PreferNoSchedule" };
	return effectArray[effect];
}

kubernetes_v1_taint_EFFECT_e effectv1_taint_FromString(char* effect){
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

v1_taint_t *v1_taint_create(
    kubernetes_v1_taint_EFFECT_e effect,
    char *key,
    char *time_added,
    char *value
    ) {
    v1_taint_t *v1_taint_local_var = malloc(sizeof(v1_taint_t));
    if (!v1_taint_local_var) {
        return NULL;
    }
    v1_taint_local_var->effect = effect;
    v1_taint_local_var->key = key;
    v1_taint_local_var->time_added = time_added;
    v1_taint_local_var->value = value;

    return v1_taint_local_var;
}


void v1_taint_free(v1_taint_t *v1_taint) {
    if(NULL == v1_taint){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_taint->key) {
        free(v1_taint->key);
        v1_taint->key = NULL;
    }
    if (v1_taint->time_added) {
        free(v1_taint->time_added);
        v1_taint->time_added = NULL;
    }
    if (v1_taint->value) {
        free(v1_taint->value);
        v1_taint->value = NULL;
    }
    free(v1_taint);
}

cJSON *v1_taint_convertToJSON(v1_taint_t *v1_taint) {
    cJSON *item = cJSON_CreateObject();

    // v1_taint->effect
    
    if(cJSON_AddStringToObject(item, "effect", effectv1_taint_ToString(v1_taint->effect)) == NULL)
    {
    goto fail; //Enum
    }


    // v1_taint->key
    if (!v1_taint->key) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "key", v1_taint->key) == NULL) {
    goto fail; //String
    }


    // v1_taint->time_added
    if(v1_taint->time_added) { 
    if(cJSON_AddStringToObject(item, "timeAdded", v1_taint->time_added) == NULL) {
    goto fail; //Date-Time
    }
     } 


    // v1_taint->value
    if(v1_taint->value) { 
    if(cJSON_AddStringToObject(item, "value", v1_taint->value) == NULL) {
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

v1_taint_t *v1_taint_parseFromJSON(cJSON *v1_taintJSON){

    v1_taint_t *v1_taint_local_var = NULL;

    // v1_taint->effect
    cJSON *effect = cJSON_GetObjectItemCaseSensitive(v1_taintJSON, "effect");
    if (!effect) {
        goto end;
    }

    kubernetes_v1_taint_EFFECT_e effectVariable;
    
    if(!cJSON_IsString(effect))
    {
    goto end; //Enum
    }
    effectVariable = effectv1_taint_FromString(effect->valuestring);

    // v1_taint->key
    cJSON *key = cJSON_GetObjectItemCaseSensitive(v1_taintJSON, "key");
    if (!key) {
        goto end;
    }

    
    if(!cJSON_IsString(key))
    {
    goto end; //String
    }

    // v1_taint->time_added
    cJSON *time_added = cJSON_GetObjectItemCaseSensitive(v1_taintJSON, "timeAdded");
    if (time_added) { 
    if(!cJSON_IsString(time_added))
    {
    goto end; //DateTime
    }
    }

    // v1_taint->value
    cJSON *value = cJSON_GetObjectItemCaseSensitive(v1_taintJSON, "value");
    if (value) { 
    if(!cJSON_IsString(value))
    {
    goto end; //String
    }
    }


    v1_taint_local_var = v1_taint_create (
        effectVariable,
        strdup(key->valuestring),
        time_added ? strdup(time_added->valuestring) : NULL,
        value ? strdup(value->valuestring) : NULL
        );

    return v1_taint_local_var;
end:
    return NULL;

}
