#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_session_affinity_config.h"



static v1_session_affinity_config_t *v1_session_affinity_config_create_internal(
    v1_client_ip_config_t *client_ip
    ) {
    v1_session_affinity_config_t *v1_session_affinity_config_local_var = malloc(sizeof(v1_session_affinity_config_t));
    if (!v1_session_affinity_config_local_var) {
        return NULL;
    }
    v1_session_affinity_config_local_var->client_ip = client_ip;

    v1_session_affinity_config_local_var->_library_owned = 1;
    return v1_session_affinity_config_local_var;
}

__attribute__((deprecated)) v1_session_affinity_config_t *v1_session_affinity_config_create(
    v1_client_ip_config_t *client_ip
    ) {
    return v1_session_affinity_config_create_internal (
        client_ip
        );
}

void v1_session_affinity_config_free(v1_session_affinity_config_t *v1_session_affinity_config) {
    if(NULL == v1_session_affinity_config){
        return ;
    }
    if(v1_session_affinity_config->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_session_affinity_config_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_session_affinity_config->client_ip) {
        v1_client_ip_config_free(v1_session_affinity_config->client_ip);
        v1_session_affinity_config->client_ip = NULL;
    }
    free(v1_session_affinity_config);
}

cJSON *v1_session_affinity_config_convertToJSON(v1_session_affinity_config_t *v1_session_affinity_config) {
    cJSON *item = cJSON_CreateObject();

    // v1_session_affinity_config->client_ip
    if(v1_session_affinity_config->client_ip) {
    cJSON *client_ip_local_JSON = v1_client_ip_config_convertToJSON(v1_session_affinity_config->client_ip);
    if(client_ip_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "clientIP", client_ip_local_JSON);
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

v1_session_affinity_config_t *v1_session_affinity_config_parseFromJSON(cJSON *v1_session_affinity_configJSON){

    v1_session_affinity_config_t *v1_session_affinity_config_local_var = NULL;

    // define the local variable for v1_session_affinity_config->client_ip
    v1_client_ip_config_t *client_ip_local_nonprim = NULL;

    // v1_session_affinity_config->client_ip
    cJSON *client_ip = cJSON_GetObjectItemCaseSensitive(v1_session_affinity_configJSON, "clientIP");
    if (cJSON_IsNull(client_ip)) {
        client_ip = NULL;
    }
    if (client_ip) { 
    client_ip_local_nonprim = v1_client_ip_config_parseFromJSON(client_ip); //nonprimitive
    }


    v1_session_affinity_config_local_var = v1_session_affinity_config_create_internal (
        client_ip ? client_ip_local_nonprim : NULL
        );

    return v1_session_affinity_config_local_var;
end:
    if (client_ip_local_nonprim) {
        v1_client_ip_config_free(client_ip_local_nonprim);
        client_ip_local_nonprim = NULL;
    }
    return NULL;

}
