#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_taint.h"



v1_taint_t *v1_taint_create(
    char *effect,
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
    if (v1_taint->effect) {
        free(v1_taint->effect);
        v1_taint->effect = NULL;
    }
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
    if (!v1_taint->effect) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "effect", v1_taint->effect) == NULL) {
    goto fail; //String
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

    
    if(!cJSON_IsString(effect))
    {
    goto end; //String
    }

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
        strdup(effect->valuestring),
        strdup(key->valuestring),
        time_added ? strdup(time_added->valuestring) : NULL,
        value ? strdup(value->valuestring) : NULL
        );

    return v1_taint_local_var;
end:
    return NULL;

}
