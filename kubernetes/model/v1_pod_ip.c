#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_pod_ip.h"



v1_pod_ip_t *v1_pod_ip_create(
    char *ip
    ) {
    v1_pod_ip_t *v1_pod_ip_local_var = malloc(sizeof(v1_pod_ip_t));
    if (!v1_pod_ip_local_var) {
        return NULL;
    }
    v1_pod_ip_local_var->ip = ip;

    return v1_pod_ip_local_var;
}


void v1_pod_ip_free(v1_pod_ip_t *v1_pod_ip) {
    if(NULL == v1_pod_ip){
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
    if(v1_pod_ip->ip) { 
    if(cJSON_AddStringToObject(item, "ip", v1_pod_ip->ip) == NULL) {
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

v1_pod_ip_t *v1_pod_ip_parseFromJSON(cJSON *v1_pod_ipJSON){

    v1_pod_ip_t *v1_pod_ip_local_var = NULL;

    // v1_pod_ip->ip
    cJSON *ip = cJSON_GetObjectItemCaseSensitive(v1_pod_ipJSON, "ip");
    if (ip) { 
    if(!cJSON_IsString(ip))
    {
    goto end; //String
    }
    }


    v1_pod_ip_local_var = v1_pod_ip_create (
        ip ? strdup(ip->valuestring) : NULL
        );

    return v1_pod_ip_local_var;
end:
    return NULL;

}
