#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_host_alias.h"



static v1_host_alias_t *v1_host_alias_create_internal(
    list_t *hostnames,
    char *ip
    ) {
    v1_host_alias_t *v1_host_alias_local_var = malloc(sizeof(v1_host_alias_t));
    if (!v1_host_alias_local_var) {
        return NULL;
    }
    v1_host_alias_local_var->hostnames = hostnames;
    v1_host_alias_local_var->ip = ip;

    v1_host_alias_local_var->_library_owned = 1;
    return v1_host_alias_local_var;
}

__attribute__((deprecated)) v1_host_alias_t *v1_host_alias_create(
    list_t *hostnames,
    char *ip
    ) {
    return v1_host_alias_create_internal (
        hostnames,
        ip
        );
}

void v1_host_alias_free(v1_host_alias_t *v1_host_alias) {
    if(NULL == v1_host_alias){
        return ;
    }
    if(v1_host_alias->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_host_alias_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_host_alias->hostnames) {
        list_ForEach(listEntry, v1_host_alias->hostnames) {
            free(listEntry->data);
        }
        list_freeList(v1_host_alias->hostnames);
        v1_host_alias->hostnames = NULL;
    }
    if (v1_host_alias->ip) {
        free(v1_host_alias->ip);
        v1_host_alias->ip = NULL;
    }
    free(v1_host_alias);
}

cJSON *v1_host_alias_convertToJSON(v1_host_alias_t *v1_host_alias) {
    cJSON *item = cJSON_CreateObject();

    // v1_host_alias->hostnames
    if(v1_host_alias->hostnames) {
    cJSON *hostnames = cJSON_AddArrayToObject(item, "hostnames");
    if(hostnames == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *hostnamesListEntry;
    list_ForEach(hostnamesListEntry, v1_host_alias->hostnames) {
    if(cJSON_AddStringToObject(hostnames, "", hostnamesListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // v1_host_alias->ip
    if (!v1_host_alias->ip) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "ip", v1_host_alias->ip) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_host_alias_t *v1_host_alias_parseFromJSON(cJSON *v1_host_aliasJSON){

    v1_host_alias_t *v1_host_alias_local_var = NULL;

    // define the local list for v1_host_alias->hostnames
    list_t *hostnamesList = NULL;

    // v1_host_alias->hostnames
    cJSON *hostnames = cJSON_GetObjectItemCaseSensitive(v1_host_aliasJSON, "hostnames");
    if (cJSON_IsNull(hostnames)) {
        hostnames = NULL;
    }
    if (hostnames) { 
    cJSON *hostnames_local = NULL;
    if(!cJSON_IsArray(hostnames)) {
        goto end;//primitive container
    }
    hostnamesList = list_createList();

    cJSON_ArrayForEach(hostnames_local, hostnames)
    {
        if(!cJSON_IsString(hostnames_local))
        {
            goto end;
        }
        list_addElement(hostnamesList , strdup(hostnames_local->valuestring));
    }
    }

    // v1_host_alias->ip
    cJSON *ip = cJSON_GetObjectItemCaseSensitive(v1_host_aliasJSON, "ip");
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


    v1_host_alias_local_var = v1_host_alias_create_internal (
        hostnames ? hostnamesList : NULL,
        strdup(ip->valuestring)
        );

    return v1_host_alias_local_var;
end:
    if (hostnamesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, hostnamesList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(hostnamesList);
        hostnamesList = NULL;
    }
    return NULL;

}
