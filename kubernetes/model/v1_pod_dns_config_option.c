#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_pod_dns_config_option.h"



v1_pod_dns_config_option_t *v1_pod_dns_config_option_create(
    char *name,
    char *value
    ) {
    v1_pod_dns_config_option_t *v1_pod_dns_config_option_local_var = malloc(sizeof(v1_pod_dns_config_option_t));
    if (!v1_pod_dns_config_option_local_var) {
        return NULL;
    }
    v1_pod_dns_config_option_local_var->name = name;
    v1_pod_dns_config_option_local_var->value = value;

    return v1_pod_dns_config_option_local_var;
}


void v1_pod_dns_config_option_free(v1_pod_dns_config_option_t *v1_pod_dns_config_option) {
    if(NULL == v1_pod_dns_config_option){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_pod_dns_config_option->name) {
        free(v1_pod_dns_config_option->name);
        v1_pod_dns_config_option->name = NULL;
    }
    if (v1_pod_dns_config_option->value) {
        free(v1_pod_dns_config_option->value);
        v1_pod_dns_config_option->value = NULL;
    }
    free(v1_pod_dns_config_option);
}

cJSON *v1_pod_dns_config_option_convertToJSON(v1_pod_dns_config_option_t *v1_pod_dns_config_option) {
    cJSON *item = cJSON_CreateObject();

    // v1_pod_dns_config_option->name
    if(v1_pod_dns_config_option->name) { 
    if(cJSON_AddStringToObject(item, "name", v1_pod_dns_config_option->name) == NULL) {
    goto fail; //String
    }
     } 


    // v1_pod_dns_config_option->value
    if(v1_pod_dns_config_option->value) { 
    if(cJSON_AddStringToObject(item, "value", v1_pod_dns_config_option->value) == NULL) {
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

v1_pod_dns_config_option_t *v1_pod_dns_config_option_parseFromJSON(cJSON *v1_pod_dns_config_optionJSON){

    v1_pod_dns_config_option_t *v1_pod_dns_config_option_local_var = NULL;

    // v1_pod_dns_config_option->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1_pod_dns_config_optionJSON, "name");
    if (name) { 
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }
    }

    // v1_pod_dns_config_option->value
    cJSON *value = cJSON_GetObjectItemCaseSensitive(v1_pod_dns_config_optionJSON, "value");
    if (value) { 
    if(!cJSON_IsString(value))
    {
    goto end; //String
    }
    }


    v1_pod_dns_config_option_local_var = v1_pod_dns_config_option_create (
        name ? strdup(name->valuestring) : NULL,
        value ? strdup(value->valuestring) : NULL
        );

    return v1_pod_dns_config_option_local_var;
end:
    return NULL;

}
