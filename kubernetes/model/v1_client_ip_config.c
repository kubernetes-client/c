#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_client_ip_config.h"



static v1_client_ip_config_t *v1_client_ip_config_create_internal(
    int timeout_seconds
    ) {
    v1_client_ip_config_t *v1_client_ip_config_local_var = malloc(sizeof(v1_client_ip_config_t));
    if (!v1_client_ip_config_local_var) {
        return NULL;
    }
    v1_client_ip_config_local_var->timeout_seconds = timeout_seconds;

    v1_client_ip_config_local_var->_library_owned = 1;
    return v1_client_ip_config_local_var;
}

__attribute__((deprecated)) v1_client_ip_config_t *v1_client_ip_config_create(
    int timeout_seconds
    ) {
    return v1_client_ip_config_create_internal (
        timeout_seconds
        );
}

void v1_client_ip_config_free(v1_client_ip_config_t *v1_client_ip_config) {
    if(NULL == v1_client_ip_config){
        return ;
    }
    if(v1_client_ip_config->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_client_ip_config_free");
        return ;
    }
    listEntry_t *listEntry;
    free(v1_client_ip_config);
}

cJSON *v1_client_ip_config_convertToJSON(v1_client_ip_config_t *v1_client_ip_config) {
    cJSON *item = cJSON_CreateObject();

    // v1_client_ip_config->timeout_seconds
    if(v1_client_ip_config->timeout_seconds) {
    if(cJSON_AddNumberToObject(item, "timeoutSeconds", v1_client_ip_config->timeout_seconds) == NULL) {
    goto fail; //Numeric
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_client_ip_config_t *v1_client_ip_config_parseFromJSON(cJSON *v1_client_ip_configJSON){

    v1_client_ip_config_t *v1_client_ip_config_local_var = NULL;

    // v1_client_ip_config->timeout_seconds
    cJSON *timeout_seconds = cJSON_GetObjectItemCaseSensitive(v1_client_ip_configJSON, "timeoutSeconds");
    if (cJSON_IsNull(timeout_seconds)) {
        timeout_seconds = NULL;
    }
    if (timeout_seconds) { 
    if(!cJSON_IsNumber(timeout_seconds))
    {
    goto end; //Numeric
    }
    }


    v1_client_ip_config_local_var = v1_client_ip_config_create_internal (
        timeout_seconds ? timeout_seconds->valuedouble : 0
        );

    return v1_client_ip_config_local_var;
end:
    return NULL;

}
