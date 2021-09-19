#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_ingress_tls.h"



v1_ingress_tls_t *v1_ingress_tls_create(
    list_t *hosts,
    char *secret_name
    ) {
    v1_ingress_tls_t *v1_ingress_tls_local_var = malloc(sizeof(v1_ingress_tls_t));
    if (!v1_ingress_tls_local_var) {
        return NULL;
    }
    v1_ingress_tls_local_var->hosts = hosts;
    v1_ingress_tls_local_var->secret_name = secret_name;

    return v1_ingress_tls_local_var;
}


void v1_ingress_tls_free(v1_ingress_tls_t *v1_ingress_tls) {
    if(NULL == v1_ingress_tls){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_ingress_tls->hosts) {
        list_ForEach(listEntry, v1_ingress_tls->hosts) {
            free(listEntry->data);
        }
        list_free(v1_ingress_tls->hosts);
        v1_ingress_tls->hosts = NULL;
    }
    if (v1_ingress_tls->secret_name) {
        free(v1_ingress_tls->secret_name);
        v1_ingress_tls->secret_name = NULL;
    }
    free(v1_ingress_tls);
}

cJSON *v1_ingress_tls_convertToJSON(v1_ingress_tls_t *v1_ingress_tls) {
    cJSON *item = cJSON_CreateObject();

    // v1_ingress_tls->hosts
    if(v1_ingress_tls->hosts) { 
    cJSON *hosts = cJSON_AddArrayToObject(item, "hosts");
    if(hosts == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *hostsListEntry;
    list_ForEach(hostsListEntry, v1_ingress_tls->hosts) {
    if(cJSON_AddStringToObject(hosts, "", (char*)hostsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 


    // v1_ingress_tls->secret_name
    if(v1_ingress_tls->secret_name) { 
    if(cJSON_AddStringToObject(item, "secretName", v1_ingress_tls->secret_name) == NULL) {
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

v1_ingress_tls_t *v1_ingress_tls_parseFromJSON(cJSON *v1_ingress_tlsJSON){

    v1_ingress_tls_t *v1_ingress_tls_local_var = NULL;

    // v1_ingress_tls->hosts
    cJSON *hosts = cJSON_GetObjectItemCaseSensitive(v1_ingress_tlsJSON, "hosts");
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

    // v1_ingress_tls->secret_name
    cJSON *secret_name = cJSON_GetObjectItemCaseSensitive(v1_ingress_tlsJSON, "secretName");
    if (secret_name) { 
    if(!cJSON_IsString(secret_name))
    {
    goto end; //String
    }
    }


    v1_ingress_tls_local_var = v1_ingress_tls_create (
        hosts ? hostsList : NULL,
        secret_name ? strdup(secret_name->valuestring) : NULL
        );

    return v1_ingress_tls_local_var;
end:
    return NULL;

}
