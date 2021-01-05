#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_user_info.h"



v1beta1_user_info_t *v1beta1_user_info_create(
    list_t* extra,
    list_t *groups,
    char *uid,
    char *username
    ) {
    v1beta1_user_info_t *v1beta1_user_info_local_var = malloc(sizeof(v1beta1_user_info_t));
    if (!v1beta1_user_info_local_var) {
        return NULL;
    }
    v1beta1_user_info_local_var->extra = extra;
    v1beta1_user_info_local_var->groups = groups;
    v1beta1_user_info_local_var->uid = uid;
    v1beta1_user_info_local_var->username = username;

    return v1beta1_user_info_local_var;
}


void v1beta1_user_info_free(v1beta1_user_info_t *v1beta1_user_info) {
    if(NULL == v1beta1_user_info){
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta1_user_info->extra) {
        list_ForEach(listEntry, v1beta1_user_info->extra) {
            keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_free(v1beta1_user_info->extra);
        v1beta1_user_info->extra = NULL;
    }
    if (v1beta1_user_info->groups) {
        list_ForEach(listEntry, v1beta1_user_info->groups) {
            free(listEntry->data);
        }
        list_free(v1beta1_user_info->groups);
        v1beta1_user_info->groups = NULL;
    }
    if (v1beta1_user_info->uid) {
        free(v1beta1_user_info->uid);
        v1beta1_user_info->uid = NULL;
    }
    if (v1beta1_user_info->username) {
        free(v1beta1_user_info->username);
        v1beta1_user_info->username = NULL;
    }
    free(v1beta1_user_info);
}

cJSON *v1beta1_user_info_convertToJSON(v1beta1_user_info_t *v1beta1_user_info) {
    cJSON *item = cJSON_CreateObject();

    // v1beta1_user_info->extra
    if(v1beta1_user_info->extra) { 
    cJSON *extra = cJSON_AddObjectToObject(item, "extra");
    if(extra == NULL) {
        goto fail; //primitive map container
    }
    cJSON *localMapObject = extra;
    listEntry_t *extraListEntry;
    if (v1beta1_user_info->extra) {
    list_ForEach(extraListEntry, v1beta1_user_info->extra) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)extraListEntry->data;
    }
    }
     } 


    // v1beta1_user_info->groups
    if(v1beta1_user_info->groups) { 
    cJSON *groups = cJSON_AddArrayToObject(item, "groups");
    if(groups == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *groupsListEntry;
    list_ForEach(groupsListEntry, v1beta1_user_info->groups) {
    if(cJSON_AddStringToObject(groups, "", (char*)groupsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 


    // v1beta1_user_info->uid
    if(v1beta1_user_info->uid) { 
    if(cJSON_AddStringToObject(item, "uid", v1beta1_user_info->uid) == NULL) {
    goto fail; //String
    }
     } 


    // v1beta1_user_info->username
    if(v1beta1_user_info->username) { 
    if(cJSON_AddStringToObject(item, "username", v1beta1_user_info->username) == NULL) {
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

v1beta1_user_info_t *v1beta1_user_info_parseFromJSON(cJSON *v1beta1_user_infoJSON){

    v1beta1_user_info_t *v1beta1_user_info_local_var = NULL;

    // v1beta1_user_info->extra
    cJSON *extra = cJSON_GetObjectItemCaseSensitive(v1beta1_user_infoJSON, "extra");
    list_t *extraList;
    if (extra) { 
    cJSON *extra_local_map;
    if(!cJSON_IsObject(extra)) {
        goto end;//primitive map container
    }
    extraList = list_create();
    keyValuePair_t *localMapKeyPair;
    cJSON_ArrayForEach(extra_local_map, extra)
    {
		cJSON *localMapObject = extra_local_map;
        list_addElement(extraList , localMapKeyPair);
    }
    }

    // v1beta1_user_info->groups
    cJSON *groups = cJSON_GetObjectItemCaseSensitive(v1beta1_user_infoJSON, "groups");
    list_t *groupsList;
    if (groups) { 
    cJSON *groups_local;
    if(!cJSON_IsArray(groups)) {
        goto end;//primitive container
    }
    groupsList = list_create();

    cJSON_ArrayForEach(groups_local, groups)
    {
        if(!cJSON_IsString(groups_local))
        {
            goto end;
        }
        list_addElement(groupsList , strdup(groups_local->valuestring));
    }
    }

    // v1beta1_user_info->uid
    cJSON *uid = cJSON_GetObjectItemCaseSensitive(v1beta1_user_infoJSON, "uid");
    if (uid) { 
    if(!cJSON_IsString(uid))
    {
    goto end; //String
    }
    }

    // v1beta1_user_info->username
    cJSON *username = cJSON_GetObjectItemCaseSensitive(v1beta1_user_infoJSON, "username");
    if (username) { 
    if(!cJSON_IsString(username))
    {
    goto end; //String
    }
    }


    v1beta1_user_info_local_var = v1beta1_user_info_create (
        extra ? extraList : NULL,
        groups ? groupsList : NULL,
        uid ? strdup(uid->valuestring) : NULL,
        username ? strdup(username->valuestring) : NULL
        );

    return v1beta1_user_info_local_var;
end:
    return NULL;

}
