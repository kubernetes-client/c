#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_certificate_signing_request_spec.h"



v1beta1_certificate_signing_request_spec_t *v1beta1_certificate_signing_request_spec_create(
    list_t* extra,
    list_t *groups,
    char *request,
    char *uid,
    list_t *usages,
    char *username
    ) {
    v1beta1_certificate_signing_request_spec_t *v1beta1_certificate_signing_request_spec_local_var = malloc(sizeof(v1beta1_certificate_signing_request_spec_t));
    if (!v1beta1_certificate_signing_request_spec_local_var) {
        return NULL;
    }
    v1beta1_certificate_signing_request_spec_local_var->extra = extra;
    v1beta1_certificate_signing_request_spec_local_var->groups = groups;
    v1beta1_certificate_signing_request_spec_local_var->request = request;
    v1beta1_certificate_signing_request_spec_local_var->uid = uid;
    v1beta1_certificate_signing_request_spec_local_var->usages = usages;
    v1beta1_certificate_signing_request_spec_local_var->username = username;

    return v1beta1_certificate_signing_request_spec_local_var;
}


void v1beta1_certificate_signing_request_spec_free(v1beta1_certificate_signing_request_spec_t *v1beta1_certificate_signing_request_spec) {
    if(NULL == v1beta1_certificate_signing_request_spec){
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta1_certificate_signing_request_spec->extra) {
        list_ForEach(listEntry, v1beta1_certificate_signing_request_spec->extra) {
            keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_free(v1beta1_certificate_signing_request_spec->extra);
        v1beta1_certificate_signing_request_spec->extra = NULL;
    }
    if (v1beta1_certificate_signing_request_spec->groups) {
        list_ForEach(listEntry, v1beta1_certificate_signing_request_spec->groups) {
            free(listEntry->data);
        }
        list_free(v1beta1_certificate_signing_request_spec->groups);
        v1beta1_certificate_signing_request_spec->groups = NULL;
    }
    if (v1beta1_certificate_signing_request_spec->request) {
        free(v1beta1_certificate_signing_request_spec->request);
        v1beta1_certificate_signing_request_spec->request = NULL;
    }
    if (v1beta1_certificate_signing_request_spec->uid) {
        free(v1beta1_certificate_signing_request_spec->uid);
        v1beta1_certificate_signing_request_spec->uid = NULL;
    }
    if (v1beta1_certificate_signing_request_spec->usages) {
        list_ForEach(listEntry, v1beta1_certificate_signing_request_spec->usages) {
            free(listEntry->data);
        }
        list_free(v1beta1_certificate_signing_request_spec->usages);
        v1beta1_certificate_signing_request_spec->usages = NULL;
    }
    if (v1beta1_certificate_signing_request_spec->username) {
        free(v1beta1_certificate_signing_request_spec->username);
        v1beta1_certificate_signing_request_spec->username = NULL;
    }
    free(v1beta1_certificate_signing_request_spec);
}

cJSON *v1beta1_certificate_signing_request_spec_convertToJSON(v1beta1_certificate_signing_request_spec_t *v1beta1_certificate_signing_request_spec) {
    cJSON *item = cJSON_CreateObject();

    // v1beta1_certificate_signing_request_spec->extra
    if(v1beta1_certificate_signing_request_spec->extra) { 
    cJSON *extra = cJSON_AddObjectToObject(item, "extra");
    if(extra == NULL) {
        goto fail; //primitive map container
    }
    cJSON *localMapObject = extra;
    listEntry_t *extraListEntry;
    if (v1beta1_certificate_signing_request_spec->extra) {
    list_ForEach(extraListEntry, v1beta1_certificate_signing_request_spec->extra) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)extraListEntry->data;
    }
    }
     } 


    // v1beta1_certificate_signing_request_spec->groups
    if(v1beta1_certificate_signing_request_spec->groups) { 
    cJSON *groups = cJSON_AddArrayToObject(item, "groups");
    if(groups == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *groupsListEntry;
    list_ForEach(groupsListEntry, v1beta1_certificate_signing_request_spec->groups) {
    if(cJSON_AddStringToObject(groups, "", (char*)groupsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 


    // v1beta1_certificate_signing_request_spec->request
    if (!v1beta1_certificate_signing_request_spec->request) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "request", v1beta1_certificate_signing_request_spec->request) == NULL) {
    goto fail; //ByteArray
    }


    // v1beta1_certificate_signing_request_spec->uid
    if(v1beta1_certificate_signing_request_spec->uid) { 
    if(cJSON_AddStringToObject(item, "uid", v1beta1_certificate_signing_request_spec->uid) == NULL) {
    goto fail; //String
    }
     } 


    // v1beta1_certificate_signing_request_spec->usages
    if(v1beta1_certificate_signing_request_spec->usages) { 
    cJSON *usages = cJSON_AddArrayToObject(item, "usages");
    if(usages == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *usagesListEntry;
    list_ForEach(usagesListEntry, v1beta1_certificate_signing_request_spec->usages) {
    if(cJSON_AddStringToObject(usages, "", (char*)usagesListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 


    // v1beta1_certificate_signing_request_spec->username
    if(v1beta1_certificate_signing_request_spec->username) { 
    if(cJSON_AddStringToObject(item, "username", v1beta1_certificate_signing_request_spec->username) == NULL) {
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

v1beta1_certificate_signing_request_spec_t *v1beta1_certificate_signing_request_spec_parseFromJSON(cJSON *v1beta1_certificate_signing_request_specJSON){

    v1beta1_certificate_signing_request_spec_t *v1beta1_certificate_signing_request_spec_local_var = NULL;

    // v1beta1_certificate_signing_request_spec->extra
    cJSON *extra = cJSON_GetObjectItemCaseSensitive(v1beta1_certificate_signing_request_specJSON, "extra");
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

    // v1beta1_certificate_signing_request_spec->groups
    cJSON *groups = cJSON_GetObjectItemCaseSensitive(v1beta1_certificate_signing_request_specJSON, "groups");
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

    // v1beta1_certificate_signing_request_spec->request
    cJSON *request = cJSON_GetObjectItemCaseSensitive(v1beta1_certificate_signing_request_specJSON, "request");
    if (!request) {
        goto end;
    }

    
    if(!cJSON_IsString(request))
    {
    goto end; //ByteArray
    }

    // v1beta1_certificate_signing_request_spec->uid
    cJSON *uid = cJSON_GetObjectItemCaseSensitive(v1beta1_certificate_signing_request_specJSON, "uid");
    if (uid) { 
    if(!cJSON_IsString(uid))
    {
    goto end; //String
    }
    }

    // v1beta1_certificate_signing_request_spec->usages
    cJSON *usages = cJSON_GetObjectItemCaseSensitive(v1beta1_certificate_signing_request_specJSON, "usages");
    list_t *usagesList;
    if (usages) { 
    cJSON *usages_local;
    if(!cJSON_IsArray(usages)) {
        goto end;//primitive container
    }
    usagesList = list_create();

    cJSON_ArrayForEach(usages_local, usages)
    {
        if(!cJSON_IsString(usages_local))
        {
            goto end;
        }
        list_addElement(usagesList , strdup(usages_local->valuestring));
    }
    }

    // v1beta1_certificate_signing_request_spec->username
    cJSON *username = cJSON_GetObjectItemCaseSensitive(v1beta1_certificate_signing_request_specJSON, "username");
    if (username) { 
    if(!cJSON_IsString(username))
    {
    goto end; //String
    }
    }


    v1beta1_certificate_signing_request_spec_local_var = v1beta1_certificate_signing_request_spec_create (
        extra ? extraList : NULL,
        groups ? groupsList : NULL,
        strdup(request->valuestring),
        uid ? strdup(uid->valuestring) : NULL,
        usages ? usagesList : NULL,
        username ? strdup(username->valuestring) : NULL
        );

    return v1beta1_certificate_signing_request_spec_local_var;
end:
    return NULL;

}
