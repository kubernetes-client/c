#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_api_group_list.h"



v1_api_group_list_t *v1_api_group_list_create(
    char *api_version,
    list_t *groups,
    char *kind
    ) {
    v1_api_group_list_t *v1_api_group_list_local_var = malloc(sizeof(v1_api_group_list_t));
    if (!v1_api_group_list_local_var) {
        return NULL;
    }
    v1_api_group_list_local_var->api_version = api_version;
    v1_api_group_list_local_var->groups = groups;
    v1_api_group_list_local_var->kind = kind;

    return v1_api_group_list_local_var;
}


void v1_api_group_list_free(v1_api_group_list_t *v1_api_group_list) {
    if(NULL == v1_api_group_list){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_api_group_list->api_version) {
        free(v1_api_group_list->api_version);
        v1_api_group_list->api_version = NULL;
    }
    if (v1_api_group_list->groups) {
        list_ForEach(listEntry, v1_api_group_list->groups) {
            v1_api_group_free(listEntry->data);
        }
        list_free(v1_api_group_list->groups);
        v1_api_group_list->groups = NULL;
    }
    if (v1_api_group_list->kind) {
        free(v1_api_group_list->kind);
        v1_api_group_list->kind = NULL;
    }
    free(v1_api_group_list);
}

cJSON *v1_api_group_list_convertToJSON(v1_api_group_list_t *v1_api_group_list) {
    cJSON *item = cJSON_CreateObject();

    // v1_api_group_list->api_version
    if(v1_api_group_list->api_version) { 
    if(cJSON_AddStringToObject(item, "apiVersion", v1_api_group_list->api_version) == NULL) {
    goto fail; //String
    }
     } 


    // v1_api_group_list->groups
    if (!v1_api_group_list->groups) {
        goto fail;
    }
    
    cJSON *groups = cJSON_AddArrayToObject(item, "groups");
    if(groups == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *groupsListEntry;
    if (v1_api_group_list->groups) {
    list_ForEach(groupsListEntry, v1_api_group_list->groups) {
    cJSON *itemLocal = v1_api_group_convertToJSON(groupsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(groups, itemLocal);
    }
    }


    // v1_api_group_list->kind
    if(v1_api_group_list->kind) { 
    if(cJSON_AddStringToObject(item, "kind", v1_api_group_list->kind) == NULL) {
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

v1_api_group_list_t *v1_api_group_list_parseFromJSON(cJSON *v1_api_group_listJSON){

    v1_api_group_list_t *v1_api_group_list_local_var = NULL;

    // v1_api_group_list->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1_api_group_listJSON, "apiVersion");
    if (api_version) { 
    if(!cJSON_IsString(api_version))
    {
    goto end; //String
    }
    }

    // v1_api_group_list->groups
    cJSON *groups = cJSON_GetObjectItemCaseSensitive(v1_api_group_listJSON, "groups");
    if (!groups) {
        goto end;
    }

    list_t *groupsList;
    
    cJSON *groups_local_nonprimitive;
    if(!cJSON_IsArray(groups)){
        goto end; //nonprimitive container
    }

    groupsList = list_create();

    cJSON_ArrayForEach(groups_local_nonprimitive,groups )
    {
        if(!cJSON_IsObject(groups_local_nonprimitive)){
            goto end;
        }
        v1_api_group_t *groupsItem = v1_api_group_parseFromJSON(groups_local_nonprimitive);

        list_addElement(groupsList, groupsItem);
    }

    // v1_api_group_list->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_api_group_listJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }


    v1_api_group_list_local_var = v1_api_group_list_create (
        api_version ? strdup(api_version->valuestring) : NULL,
        groupsList,
        kind ? strdup(kind->valuestring) : NULL
        );

    return v1_api_group_list_local_var;
end:
    return NULL;

}
