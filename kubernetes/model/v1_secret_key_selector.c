#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_secret_key_selector.h"



v1_secret_key_selector_t *v1_secret_key_selector_create(
    char *key,
    char *name,
    int optional
    ) {
    v1_secret_key_selector_t *v1_secret_key_selector_local_var = malloc(sizeof(v1_secret_key_selector_t));
    if (!v1_secret_key_selector_local_var) {
        return NULL;
    }
    v1_secret_key_selector_local_var->key = key;
    v1_secret_key_selector_local_var->name = name;
    v1_secret_key_selector_local_var->optional = optional;

    return v1_secret_key_selector_local_var;
}


void v1_secret_key_selector_free(v1_secret_key_selector_t *v1_secret_key_selector) {
    if(NULL == v1_secret_key_selector){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_secret_key_selector->key) {
        free(v1_secret_key_selector->key);
        v1_secret_key_selector->key = NULL;
    }
    if (v1_secret_key_selector->name) {
        free(v1_secret_key_selector->name);
        v1_secret_key_selector->name = NULL;
    }
    free(v1_secret_key_selector);
}

cJSON *v1_secret_key_selector_convertToJSON(v1_secret_key_selector_t *v1_secret_key_selector) {
    cJSON *item = cJSON_CreateObject();

    // v1_secret_key_selector->key
    if (!v1_secret_key_selector->key) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "key", v1_secret_key_selector->key) == NULL) {
    goto fail; //String
    }


    // v1_secret_key_selector->name
    if(v1_secret_key_selector->name) { 
    if(cJSON_AddStringToObject(item, "name", v1_secret_key_selector->name) == NULL) {
    goto fail; //String
    }
     } 


    // v1_secret_key_selector->optional
    if(v1_secret_key_selector->optional) { 
    if(cJSON_AddBoolToObject(item, "optional", v1_secret_key_selector->optional) == NULL) {
    goto fail; //Bool
    }
     } 

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_secret_key_selector_t *v1_secret_key_selector_parseFromJSON(cJSON *v1_secret_key_selectorJSON){

    v1_secret_key_selector_t *v1_secret_key_selector_local_var = NULL;

    // v1_secret_key_selector->key
    cJSON *key = cJSON_GetObjectItemCaseSensitive(v1_secret_key_selectorJSON, "key");
    if (!key) {
        goto end;
    }

    
    if(!cJSON_IsString(key))
    {
    goto end; //String
    }

    // v1_secret_key_selector->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1_secret_key_selectorJSON, "name");
    if (name) { 
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }
    }

    // v1_secret_key_selector->optional
    cJSON *optional = cJSON_GetObjectItemCaseSensitive(v1_secret_key_selectorJSON, "optional");
    if (optional) { 
    if(!cJSON_IsBool(optional))
    {
    goto end; //Bool
    }
    }


    v1_secret_key_selector_local_var = v1_secret_key_selector_create (
        strdup(key->valuestring),
        name ? strdup(name->valuestring) : NULL,
        optional ? optional->valueint : 0
        );

    return v1_secret_key_selector_local_var;
end:
    return NULL;

}
