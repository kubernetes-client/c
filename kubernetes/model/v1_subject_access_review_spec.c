#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_subject_access_review_spec.h"



v1_subject_access_review_spec_t *v1_subject_access_review_spec_create(
    list_t* extra,
    list_t *groups,
    v1_non_resource_attributes_t *non_resource_attributes,
    v1_resource_attributes_t *resource_attributes,
    char *uid,
    char *user
    ) {
    v1_subject_access_review_spec_t *v1_subject_access_review_spec_local_var = malloc(sizeof(v1_subject_access_review_spec_t));
    if (!v1_subject_access_review_spec_local_var) {
        return NULL;
    }
    v1_subject_access_review_spec_local_var->extra = extra;
    v1_subject_access_review_spec_local_var->groups = groups;
    v1_subject_access_review_spec_local_var->non_resource_attributes = non_resource_attributes;
    v1_subject_access_review_spec_local_var->resource_attributes = resource_attributes;
    v1_subject_access_review_spec_local_var->uid = uid;
    v1_subject_access_review_spec_local_var->user = user;

    return v1_subject_access_review_spec_local_var;
}


void v1_subject_access_review_spec_free(v1_subject_access_review_spec_t *v1_subject_access_review_spec) {
    if(NULL == v1_subject_access_review_spec){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_subject_access_review_spec->extra) {
        list_ForEach(listEntry, v1_subject_access_review_spec->extra) {
            keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_free(v1_subject_access_review_spec->extra);
        v1_subject_access_review_spec->extra = NULL;
    }
    if (v1_subject_access_review_spec->groups) {
        list_ForEach(listEntry, v1_subject_access_review_spec->groups) {
            free(listEntry->data);
        }
        list_free(v1_subject_access_review_spec->groups);
        v1_subject_access_review_spec->groups = NULL;
    }
    if (v1_subject_access_review_spec->non_resource_attributes) {
        v1_non_resource_attributes_free(v1_subject_access_review_spec->non_resource_attributes);
        v1_subject_access_review_spec->non_resource_attributes = NULL;
    }
    if (v1_subject_access_review_spec->resource_attributes) {
        v1_resource_attributes_free(v1_subject_access_review_spec->resource_attributes);
        v1_subject_access_review_spec->resource_attributes = NULL;
    }
    if (v1_subject_access_review_spec->uid) {
        free(v1_subject_access_review_spec->uid);
        v1_subject_access_review_spec->uid = NULL;
    }
    if (v1_subject_access_review_spec->user) {
        free(v1_subject_access_review_spec->user);
        v1_subject_access_review_spec->user = NULL;
    }
    free(v1_subject_access_review_spec);
}

cJSON *v1_subject_access_review_spec_convertToJSON(v1_subject_access_review_spec_t *v1_subject_access_review_spec) {
    cJSON *item = cJSON_CreateObject();

    // v1_subject_access_review_spec->extra
    if(v1_subject_access_review_spec->extra) { 
    cJSON *extra = cJSON_AddObjectToObject(item, "extra");
    if(extra == NULL) {
        goto fail; //primitive map container
    }
    cJSON *localMapObject = extra;
    listEntry_t *extraListEntry;
    if (v1_subject_access_review_spec->extra) {
    list_ForEach(extraListEntry, v1_subject_access_review_spec->extra) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)extraListEntry->data;
    }
    }
     } 


    // v1_subject_access_review_spec->groups
    if(v1_subject_access_review_spec->groups) { 
    cJSON *groups = cJSON_AddArrayToObject(item, "groups");
    if(groups == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *groupsListEntry;
    list_ForEach(groupsListEntry, v1_subject_access_review_spec->groups) {
    if(cJSON_AddStringToObject(groups, "", (char*)groupsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 


    // v1_subject_access_review_spec->non_resource_attributes
    if(v1_subject_access_review_spec->non_resource_attributes) { 
    cJSON *non_resource_attributes_local_JSON = v1_non_resource_attributes_convertToJSON(v1_subject_access_review_spec->non_resource_attributes);
    if(non_resource_attributes_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "nonResourceAttributes", non_resource_attributes_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1_subject_access_review_spec->resource_attributes
    if(v1_subject_access_review_spec->resource_attributes) { 
    cJSON *resource_attributes_local_JSON = v1_resource_attributes_convertToJSON(v1_subject_access_review_spec->resource_attributes);
    if(resource_attributes_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "resourceAttributes", resource_attributes_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1_subject_access_review_spec->uid
    if(v1_subject_access_review_spec->uid) { 
    if(cJSON_AddStringToObject(item, "uid", v1_subject_access_review_spec->uid) == NULL) {
    goto fail; //String
    }
     } 


    // v1_subject_access_review_spec->user
    if(v1_subject_access_review_spec->user) { 
    if(cJSON_AddStringToObject(item, "user", v1_subject_access_review_spec->user) == NULL) {
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

v1_subject_access_review_spec_t *v1_subject_access_review_spec_parseFromJSON(cJSON *v1_subject_access_review_specJSON){

    v1_subject_access_review_spec_t *v1_subject_access_review_spec_local_var = NULL;

    // v1_subject_access_review_spec->extra
    cJSON *extra = cJSON_GetObjectItemCaseSensitive(v1_subject_access_review_specJSON, "extra");
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

    // v1_subject_access_review_spec->groups
    cJSON *groups = cJSON_GetObjectItemCaseSensitive(v1_subject_access_review_specJSON, "groups");
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

    // v1_subject_access_review_spec->non_resource_attributes
    cJSON *non_resource_attributes = cJSON_GetObjectItemCaseSensitive(v1_subject_access_review_specJSON, "nonResourceAttributes");
    v1_non_resource_attributes_t *non_resource_attributes_local_nonprim = NULL;
    if (non_resource_attributes) { 
    non_resource_attributes_local_nonprim = v1_non_resource_attributes_parseFromJSON(non_resource_attributes); //nonprimitive
    }

    // v1_subject_access_review_spec->resource_attributes
    cJSON *resource_attributes = cJSON_GetObjectItemCaseSensitive(v1_subject_access_review_specJSON, "resourceAttributes");
    v1_resource_attributes_t *resource_attributes_local_nonprim = NULL;
    if (resource_attributes) { 
    resource_attributes_local_nonprim = v1_resource_attributes_parseFromJSON(resource_attributes); //nonprimitive
    }

    // v1_subject_access_review_spec->uid
    cJSON *uid = cJSON_GetObjectItemCaseSensitive(v1_subject_access_review_specJSON, "uid");
    if (uid) { 
    if(!cJSON_IsString(uid))
    {
    goto end; //String
    }
    }

    // v1_subject_access_review_spec->user
    cJSON *user = cJSON_GetObjectItemCaseSensitive(v1_subject_access_review_specJSON, "user");
    if (user) { 
    if(!cJSON_IsString(user))
    {
    goto end; //String
    }
    }


    v1_subject_access_review_spec_local_var = v1_subject_access_review_spec_create (
        extra ? extraList : NULL,
        groups ? groupsList : NULL,
        non_resource_attributes ? non_resource_attributes_local_nonprim : NULL,
        resource_attributes ? resource_attributes_local_nonprim : NULL,
        uid ? strdup(uid->valuestring) : NULL,
        user ? strdup(user->valuestring) : NULL
        );

    return v1_subject_access_review_spec_local_var;
end:
    if (non_resource_attributes_local_nonprim) {
        v1_non_resource_attributes_free(non_resource_attributes_local_nonprim);
        non_resource_attributes_local_nonprim = NULL;
    }
    if (resource_attributes_local_nonprim) {
        v1_resource_attributes_free(resource_attributes_local_nonprim);
        resource_attributes_local_nonprim = NULL;
    }
    return NULL;

}
