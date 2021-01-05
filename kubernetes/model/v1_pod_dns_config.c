#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_pod_dns_config.h"



v1_pod_dns_config_t *v1_pod_dns_config_create(
    list_t *nameservers,
    list_t *options,
    list_t *searches
    ) {
    v1_pod_dns_config_t *v1_pod_dns_config_local_var = malloc(sizeof(v1_pod_dns_config_t));
    if (!v1_pod_dns_config_local_var) {
        return NULL;
    }
    v1_pod_dns_config_local_var->nameservers = nameservers;
    v1_pod_dns_config_local_var->options = options;
    v1_pod_dns_config_local_var->searches = searches;

    return v1_pod_dns_config_local_var;
}


void v1_pod_dns_config_free(v1_pod_dns_config_t *v1_pod_dns_config) {
    if(NULL == v1_pod_dns_config){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_pod_dns_config->nameservers) {
        list_ForEach(listEntry, v1_pod_dns_config->nameservers) {
            free(listEntry->data);
        }
        list_free(v1_pod_dns_config->nameservers);
        v1_pod_dns_config->nameservers = NULL;
    }
    if (v1_pod_dns_config->options) {
        list_ForEach(listEntry, v1_pod_dns_config->options) {
            v1_pod_dns_config_option_free(listEntry->data);
        }
        list_free(v1_pod_dns_config->options);
        v1_pod_dns_config->options = NULL;
    }
    if (v1_pod_dns_config->searches) {
        list_ForEach(listEntry, v1_pod_dns_config->searches) {
            free(listEntry->data);
        }
        list_free(v1_pod_dns_config->searches);
        v1_pod_dns_config->searches = NULL;
    }
    free(v1_pod_dns_config);
}

cJSON *v1_pod_dns_config_convertToJSON(v1_pod_dns_config_t *v1_pod_dns_config) {
    cJSON *item = cJSON_CreateObject();

    // v1_pod_dns_config->nameservers
    if(v1_pod_dns_config->nameservers) { 
    cJSON *nameservers = cJSON_AddArrayToObject(item, "nameservers");
    if(nameservers == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *nameserversListEntry;
    list_ForEach(nameserversListEntry, v1_pod_dns_config->nameservers) {
    if(cJSON_AddStringToObject(nameservers, "", (char*)nameserversListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 


    // v1_pod_dns_config->options
    if(v1_pod_dns_config->options) { 
    cJSON *options = cJSON_AddArrayToObject(item, "options");
    if(options == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *optionsListEntry;
    if (v1_pod_dns_config->options) {
    list_ForEach(optionsListEntry, v1_pod_dns_config->options) {
    cJSON *itemLocal = v1_pod_dns_config_option_convertToJSON(optionsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(options, itemLocal);
    }
    }
     } 


    // v1_pod_dns_config->searches
    if(v1_pod_dns_config->searches) { 
    cJSON *searches = cJSON_AddArrayToObject(item, "searches");
    if(searches == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *searchesListEntry;
    list_ForEach(searchesListEntry, v1_pod_dns_config->searches) {
    if(cJSON_AddStringToObject(searches, "", (char*)searchesListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_pod_dns_config_t *v1_pod_dns_config_parseFromJSON(cJSON *v1_pod_dns_configJSON){

    v1_pod_dns_config_t *v1_pod_dns_config_local_var = NULL;

    // v1_pod_dns_config->nameservers
    cJSON *nameservers = cJSON_GetObjectItemCaseSensitive(v1_pod_dns_configJSON, "nameservers");
    list_t *nameserversList;
    if (nameservers) { 
    cJSON *nameservers_local;
    if(!cJSON_IsArray(nameservers)) {
        goto end;//primitive container
    }
    nameserversList = list_create();

    cJSON_ArrayForEach(nameservers_local, nameservers)
    {
        if(!cJSON_IsString(nameservers_local))
        {
            goto end;
        }
        list_addElement(nameserversList , strdup(nameservers_local->valuestring));
    }
    }

    // v1_pod_dns_config->options
    cJSON *options = cJSON_GetObjectItemCaseSensitive(v1_pod_dns_configJSON, "options");
    list_t *optionsList;
    if (options) { 
    cJSON *options_local_nonprimitive;
    if(!cJSON_IsArray(options)){
        goto end; //nonprimitive container
    }

    optionsList = list_create();

    cJSON_ArrayForEach(options_local_nonprimitive,options )
    {
        if(!cJSON_IsObject(options_local_nonprimitive)){
            goto end;
        }
        v1_pod_dns_config_option_t *optionsItem = v1_pod_dns_config_option_parseFromJSON(options_local_nonprimitive);

        list_addElement(optionsList, optionsItem);
    }
    }

    // v1_pod_dns_config->searches
    cJSON *searches = cJSON_GetObjectItemCaseSensitive(v1_pod_dns_configJSON, "searches");
    list_t *searchesList;
    if (searches) { 
    cJSON *searches_local;
    if(!cJSON_IsArray(searches)) {
        goto end;//primitive container
    }
    searchesList = list_create();

    cJSON_ArrayForEach(searches_local, searches)
    {
        if(!cJSON_IsString(searches_local))
        {
            goto end;
        }
        list_addElement(searchesList , strdup(searches_local->valuestring));
    }
    }


    v1_pod_dns_config_local_var = v1_pod_dns_config_create (
        nameservers ? nameserversList : NULL,
        options ? optionsList : NULL,
        searches ? searchesList : NULL
        );

    return v1_pod_dns_config_local_var;
end:
    return NULL;

}
