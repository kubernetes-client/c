#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "networking_v1beta1_ingress_tls.h"



networking_v1beta1_ingress_tls_t *networking_v1beta1_ingress_tls_create(
    list_t *hosts,
    char *secret_name
    ) {
    networking_v1beta1_ingress_tls_t *networking_v1beta1_ingress_tls_local_var = malloc(sizeof(networking_v1beta1_ingress_tls_t));
    if (!networking_v1beta1_ingress_tls_local_var) {
        return NULL;
    }
    networking_v1beta1_ingress_tls_local_var->hosts = hosts;
    networking_v1beta1_ingress_tls_local_var->secret_name = secret_name;

    return networking_v1beta1_ingress_tls_local_var;
}


void networking_v1beta1_ingress_tls_free(networking_v1beta1_ingress_tls_t *networking_v1beta1_ingress_tls) {
    if(NULL == networking_v1beta1_ingress_tls){
        return ;
    }
    listEntry_t *listEntry;
    if (networking_v1beta1_ingress_tls->hosts) {
        list_ForEach(listEntry, networking_v1beta1_ingress_tls->hosts) {
            free(listEntry->data);
        }
        list_free(networking_v1beta1_ingress_tls->hosts);
        networking_v1beta1_ingress_tls->hosts = NULL;
    }
    if (networking_v1beta1_ingress_tls->secret_name) {
        free(networking_v1beta1_ingress_tls->secret_name);
        networking_v1beta1_ingress_tls->secret_name = NULL;
    }
    free(networking_v1beta1_ingress_tls);
}

cJSON *networking_v1beta1_ingress_tls_convertToJSON(networking_v1beta1_ingress_tls_t *networking_v1beta1_ingress_tls) {
    cJSON *item = cJSON_CreateObject();

    // networking_v1beta1_ingress_tls->hosts
    if(networking_v1beta1_ingress_tls->hosts) { 
    cJSON *hosts = cJSON_AddArrayToObject(item, "hosts");
    if(hosts == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *hostsListEntry;
    list_ForEach(hostsListEntry, networking_v1beta1_ingress_tls->hosts) {
    if(cJSON_AddStringToObject(hosts, "", (char*)hostsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 


    // networking_v1beta1_ingress_tls->secret_name
    if(networking_v1beta1_ingress_tls->secret_name) { 
    if(cJSON_AddStringToObject(item, "secretName", networking_v1beta1_ingress_tls->secret_name) == NULL) {
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

networking_v1beta1_ingress_tls_t *networking_v1beta1_ingress_tls_parseFromJSON(cJSON *networking_v1beta1_ingress_tlsJSON){

    networking_v1beta1_ingress_tls_t *networking_v1beta1_ingress_tls_local_var = NULL;

    // networking_v1beta1_ingress_tls->hosts
    cJSON *hosts = cJSON_GetObjectItemCaseSensitive(networking_v1beta1_ingress_tlsJSON, "hosts");
    list_t *hostsList;
    if (hosts) { 
    cJSON *hosts_local;
    if(!cJSON_IsArray(hosts)) {
        goto end;//primitive container
    }
    hostsList = list_create();

    cJSON_ArrayForEach(hosts_local, hosts)
    {
        if(!cJSON_IsString(hosts_local))
        {
            goto end;
        }
        list_addElement(hostsList , strdup(hosts_local->valuestring));
    }
    }

    // networking_v1beta1_ingress_tls->secret_name
    cJSON *secret_name = cJSON_GetObjectItemCaseSensitive(networking_v1beta1_ingress_tlsJSON, "secretName");
    if (secret_name) { 
    if(!cJSON_IsString(secret_name))
    {
    goto end; //String
    }
    }


    networking_v1beta1_ingress_tls_local_var = networking_v1beta1_ingress_tls_create (
        hosts ? hostsList : NULL,
        secret_name ? strdup(secret_name->valuestring) : NULL
        );

    return networking_v1beta1_ingress_tls_local_var;
end:
    return NULL;

}
