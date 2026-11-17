#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_pod_ip.h"



static v1_pod_ip_t *v1_pod_ip_create_internal(
    char *ip
    ) {
    v1_pod_ip_t *v1_pod_ip_local_var = malloc(sizeof(v1_pod_ip_t));
    if (!v1_pod_ip_local_var) {
        return NULL;
    }
    memset(v1_pod_ip_local_var, 0, sizeof(v1_pod_ip_t));
    v1_pod_ip_local_var->_library_owned = 1;
    v1_pod_ip_local_var->ip = ip;
    return v1_pod_ip_local_var;
}

__attribute__((deprecated)) v1_pod_ip_t *v1_pod_ip_create(
    char *ip
    ) {
    v1_pod_ip_t *result = v1_pod_ip_create_internal (
        ip
        );
    if (!result) {
    }
    return result;
}

void v1_pod_ip_free(v1_pod_ip_t *v1_pod_ip) {
    if(NULL == v1_pod_ip){
        return ;
    }
    if(v1_pod_ip->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_pod_ip_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_pod_ip->ip) {
        free(v1_pod_ip->ip);
        v1_pod_ip->ip = NULL;
    }
    free(v1_pod_ip);
}

cJSON *v1_pod_ip_convertToJSON(v1_pod_ip_t *v1_pod_ip) {
    cJSON *item = cJSON_CreateObject();

    // v1_pod_ip->ip
    if (!v1_pod_ip->ip) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "ip", v1_pod_ip->ip) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_pod_ip_t *v1_pod_ip_parseFromJSON(cJSON *v1_pod_ipJSON){

    v1_pod_ip_t *v1_pod_ip_local_var = NULL;

    char *ip_local_str = NULL;

    // v1_pod_ip->ip
    cJSON *ip = cJSON_GetObjectItemCaseSensitive(v1_pod_ipJSON, "ip");
    if (cJSON_IsNull(ip)) {
        ip = NULL;
    }
    if (!ip) {
        goto end;
    }

    
    if(!cJSON_IsString(ip))
    {
    goto end; //String
    }


    if (ip && !cJSON_IsNull(ip)) ip_local_str = strdup(ip->valuestring);

    v1_pod_ip_local_var = v1_pod_ip_create_internal (
        ip_local_str
        );

    if (!v1_pod_ip_local_var) {
        goto end;
    }

    return v1_pod_ip_local_var;
end:
    if (ip_local_str) {
        free(ip_local_str);
        ip_local_str = NULL;
    }
    return NULL;

}
