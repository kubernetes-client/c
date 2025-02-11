#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_host_ip.h"



static v1_host_ip_t *v1_host_ip_create_internal(
    char *ip
    ) {
    v1_host_ip_t *v1_host_ip_local_var = malloc(sizeof(v1_host_ip_t));
    if (!v1_host_ip_local_var) {
        return NULL;
    }
    v1_host_ip_local_var->ip = ip;

    v1_host_ip_local_var->_library_owned = 1;
    return v1_host_ip_local_var;
}

__attribute__((deprecated)) v1_host_ip_t *v1_host_ip_create(
    char *ip
    ) {
    return v1_host_ip_create_internal (
        ip
        );
}

void v1_host_ip_free(v1_host_ip_t *v1_host_ip) {
    if(NULL == v1_host_ip){
        return ;
    }
    if(v1_host_ip->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_host_ip_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_host_ip->ip) {
        free(v1_host_ip->ip);
        v1_host_ip->ip = NULL;
    }
    free(v1_host_ip);
}

cJSON *v1_host_ip_convertToJSON(v1_host_ip_t *v1_host_ip) {
    cJSON *item = cJSON_CreateObject();

    // v1_host_ip->ip
    if (!v1_host_ip->ip) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "ip", v1_host_ip->ip) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_host_ip_t *v1_host_ip_parseFromJSON(cJSON *v1_host_ipJSON){

    v1_host_ip_t *v1_host_ip_local_var = NULL;

    // v1_host_ip->ip
    cJSON *ip = cJSON_GetObjectItemCaseSensitive(v1_host_ipJSON, "ip");
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


    v1_host_ip_local_var = v1_host_ip_create_internal (
        strdup(ip->valuestring)
        );

    return v1_host_ip_local_var;
end:
    return NULL;

}
