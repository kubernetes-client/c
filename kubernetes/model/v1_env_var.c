#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_env_var.h"



v1_env_var_t *v1_env_var_create(
    char *name,
    char *value,
    v1_env_var_source_t *value_from
    ) {
    v1_env_var_t *v1_env_var_local_var = malloc(sizeof(v1_env_var_t));
    if (!v1_env_var_local_var) {
        return NULL;
    }
    v1_env_var_local_var->name = name;
    v1_env_var_local_var->value = value;
    v1_env_var_local_var->value_from = value_from;

    return v1_env_var_local_var;
}


void v1_env_var_free(v1_env_var_t *v1_env_var) {
    if(NULL == v1_env_var){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_env_var->name) {
        free(v1_env_var->name);
        v1_env_var->name = NULL;
    }
    if (v1_env_var->value) {
        free(v1_env_var->value);
        v1_env_var->value = NULL;
    }
    if (v1_env_var->value_from) {
        v1_env_var_source_free(v1_env_var->value_from);
        v1_env_var->value_from = NULL;
    }
    free(v1_env_var);
}

cJSON *v1_env_var_convertToJSON(v1_env_var_t *v1_env_var) {
    cJSON *item = cJSON_CreateObject();

    // v1_env_var->name
    if (!v1_env_var->name) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "name", v1_env_var->name) == NULL) {
    goto fail; //String
    }


    // v1_env_var->value
    if(v1_env_var->value) { 
    if(cJSON_AddStringToObject(item, "value", v1_env_var->value) == NULL) {
    goto fail; //String
    }
     } 


    // v1_env_var->value_from
    if(v1_env_var->value_from) { 
    cJSON *value_from_local_JSON = v1_env_var_source_convertToJSON(v1_env_var->value_from);
    if(value_from_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "valueFrom", value_from_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_env_var_t *v1_env_var_parseFromJSON(cJSON *v1_env_varJSON){

    v1_env_var_t *v1_env_var_local_var = NULL;

    // v1_env_var->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1_env_varJSON, "name");
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // v1_env_var->value
    cJSON *value = cJSON_GetObjectItemCaseSensitive(v1_env_varJSON, "value");
    if (value) { 
    if(!cJSON_IsString(value))
    {
    goto end; //String
    }
    }

    // v1_env_var->value_from
    cJSON *value_from = cJSON_GetObjectItemCaseSensitive(v1_env_varJSON, "valueFrom");
    v1_env_var_source_t *value_from_local_nonprim = NULL;
    if (value_from) { 
    value_from_local_nonprim = v1_env_var_source_parseFromJSON(value_from); //nonprimitive
    }


    v1_env_var_local_var = v1_env_var_create (
        strdup(name->valuestring),
        value ? strdup(value->valuestring) : NULL,
        value_from ? value_from_local_nonprim : NULL
        );

    return v1_env_var_local_var;
end:
    if (value_from_local_nonprim) {
        v1_env_var_source_free(value_from_local_nonprim);
        value_from_local_nonprim = NULL;
    }
    return NULL;

}
