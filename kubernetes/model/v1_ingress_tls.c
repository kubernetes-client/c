#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_ingress_tls.h"



static v1_ingress_tls_t *v1_ingress_tls_create_internal(
    list_t *hosts,
    char *secret_name
    ) {
    v1_ingress_tls_t *v1_ingress_tls_local_var = malloc(sizeof(v1_ingress_tls_t));
    if (!v1_ingress_tls_local_var) {
        return NULL;
    }
    v1_ingress_tls_local_var->hosts = hosts;
    v1_ingress_tls_local_var->secret_name = secret_name;

    v1_ingress_tls_local_var->_library_owned = 1;
    return v1_ingress_tls_local_var;
}

__attribute__((deprecated)) v1_ingress_tls_t *v1_ingress_tls_create(
    list_t *hosts,
    char *secret_name
    ) {
    return v1_ingress_tls_create_internal (
        hosts,
        secret_name
        );
}

void v1_ingress_tls_free(v1_ingress_tls_t *v1_ingress_tls) {
    if(NULL == v1_ingress_tls){
        return ;
    }
    if(v1_ingress_tls->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_ingress_tls_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_ingress_tls->hosts) {
        list_ForEach(listEntry, v1_ingress_tls->hosts) {
            free(listEntry->data);
        }
        list_freeList(v1_ingress_tls->hosts);
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
    if(cJSON_AddStringToObject(hosts, "", hostsListEntry->data) == NULL)
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

    // define the local list for v1_ingress_tls->hosts
    list_t *hostsList = NULL;

    // v1_ingress_tls->hosts
    cJSON *hosts = cJSON_GetObjectItemCaseSensitive(v1_ingress_tlsJSON, "hosts");
    if (cJSON_IsNull(hosts)) {
        hosts = NULL;
    }
    if (hosts) { 
    cJSON *hosts_local = NULL;
    if(!cJSON_IsArray(hosts)) {
        goto end;//primitive container
    }
    hostsList = list_createList();

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
    if (cJSON_IsNull(secret_name)) {
        secret_name = NULL;
    }
    if (secret_name) { 
    if(!cJSON_IsString(secret_name) && !cJSON_IsNull(secret_name))
    {
    goto end; //String
    }
    }


    v1_ingress_tls_local_var = v1_ingress_tls_create_internal (
        hosts ? hostsList : NULL,
        secret_name && !cJSON_IsNull(secret_name) ? strdup(secret_name->valuestring) : NULL
        );

    return v1_ingress_tls_local_var;
end:
    if (hostsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, hostsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(hostsList);
        hostsList = NULL;
    }
    return NULL;

}
