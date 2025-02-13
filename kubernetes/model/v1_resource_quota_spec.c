#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_resource_quota_spec.h"



static v1_resource_quota_spec_t *v1_resource_quota_spec_create_internal(
    list_t* hard,
    v1_scope_selector_t *scope_selector,
    list_t *scopes
    ) {
    v1_resource_quota_spec_t *v1_resource_quota_spec_local_var = malloc(sizeof(v1_resource_quota_spec_t));
    if (!v1_resource_quota_spec_local_var) {
        return NULL;
    }
    v1_resource_quota_spec_local_var->hard = hard;
    v1_resource_quota_spec_local_var->scope_selector = scope_selector;
    v1_resource_quota_spec_local_var->scopes = scopes;

    v1_resource_quota_spec_local_var->_library_owned = 1;
    return v1_resource_quota_spec_local_var;
}

__attribute__((deprecated)) v1_resource_quota_spec_t *v1_resource_quota_spec_create(
    list_t* hard,
    v1_scope_selector_t *scope_selector,
    list_t *scopes
    ) {
    return v1_resource_quota_spec_create_internal (
        hard,
        scope_selector,
        scopes
        );
}

void v1_resource_quota_spec_free(v1_resource_quota_spec_t *v1_resource_quota_spec) {
    if(NULL == v1_resource_quota_spec){
        return ;
    }
    if(v1_resource_quota_spec->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_resource_quota_spec_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_resource_quota_spec->hard) {
        list_ForEach(listEntry, v1_resource_quota_spec->hard) {
            keyValuePair_t *localKeyValue = listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_freeList(v1_resource_quota_spec->hard);
        v1_resource_quota_spec->hard = NULL;
    }
    if (v1_resource_quota_spec->scope_selector) {
        v1_scope_selector_free(v1_resource_quota_spec->scope_selector);
        v1_resource_quota_spec->scope_selector = NULL;
    }
    if (v1_resource_quota_spec->scopes) {
        list_ForEach(listEntry, v1_resource_quota_spec->scopes) {
            free(listEntry->data);
        }
        list_freeList(v1_resource_quota_spec->scopes);
        v1_resource_quota_spec->scopes = NULL;
    }
    free(v1_resource_quota_spec);
}

cJSON *v1_resource_quota_spec_convertToJSON(v1_resource_quota_spec_t *v1_resource_quota_spec) {
    cJSON *item = cJSON_CreateObject();

    // v1_resource_quota_spec->hard
    if(v1_resource_quota_spec->hard) {
    cJSON *hard = cJSON_AddObjectToObject(item, "hard");
    if(hard == NULL) {
        goto fail; //primitive map container
    }
    cJSON *localMapObject = hard;
    listEntry_t *hardListEntry;
    if (v1_resource_quota_spec->hard) {
    list_ForEach(hardListEntry, v1_resource_quota_spec->hard) {
        keyValuePair_t *localKeyValue = hardListEntry->data;
        if(cJSON_AddStringToObject(localMapObject, localKeyValue->key, localKeyValue->value) == NULL)
        {
            goto fail;
        }
    }
    }
    }


    // v1_resource_quota_spec->scope_selector
    if(v1_resource_quota_spec->scope_selector) {
    cJSON *scope_selector_local_JSON = v1_scope_selector_convertToJSON(v1_resource_quota_spec->scope_selector);
    if(scope_selector_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "scopeSelector", scope_selector_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_resource_quota_spec->scopes
    if(v1_resource_quota_spec->scopes) {
    cJSON *scopes = cJSON_AddArrayToObject(item, "scopes");
    if(scopes == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *scopesListEntry;
    list_ForEach(scopesListEntry, v1_resource_quota_spec->scopes) {
    if(cJSON_AddStringToObject(scopes, "", scopesListEntry->data) == NULL)
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

v1_resource_quota_spec_t *v1_resource_quota_spec_parseFromJSON(cJSON *v1_resource_quota_specJSON){

    v1_resource_quota_spec_t *v1_resource_quota_spec_local_var = NULL;

    // define the local map for v1_resource_quota_spec->hard
    list_t *hardList = NULL;

    // define the local variable for v1_resource_quota_spec->scope_selector
    v1_scope_selector_t *scope_selector_local_nonprim = NULL;

    // define the local list for v1_resource_quota_spec->scopes
    list_t *scopesList = NULL;

    // v1_resource_quota_spec->hard
    cJSON *hard = cJSON_GetObjectItemCaseSensitive(v1_resource_quota_specJSON, "hard");
    if (cJSON_IsNull(hard)) {
        hard = NULL;
    }
    if (hard) { 
    cJSON *hard_local_map = NULL;
    if(!cJSON_IsObject(hard) && !cJSON_IsNull(hard))
    {
        goto end;//primitive map container
    }
    if(cJSON_IsObject(hard))
    {
        hardList = list_createList();
        keyValuePair_t *localMapKeyPair;
        cJSON_ArrayForEach(hard_local_map, hard)
        {
            cJSON *localMapObject = hard_local_map;
            if(!cJSON_IsString(localMapObject))
            {
                goto end;
            }
            localMapKeyPair = keyValuePair_create(strdup(localMapObject->string),strdup(localMapObject->valuestring));
            list_addElement(hardList , localMapKeyPair);
        }
    }
    }

    // v1_resource_quota_spec->scope_selector
    cJSON *scope_selector = cJSON_GetObjectItemCaseSensitive(v1_resource_quota_specJSON, "scopeSelector");
    if (cJSON_IsNull(scope_selector)) {
        scope_selector = NULL;
    }
    if (scope_selector) { 
    scope_selector_local_nonprim = v1_scope_selector_parseFromJSON(scope_selector); //nonprimitive
    }

    // v1_resource_quota_spec->scopes
    cJSON *scopes = cJSON_GetObjectItemCaseSensitive(v1_resource_quota_specJSON, "scopes");
    if (cJSON_IsNull(scopes)) {
        scopes = NULL;
    }
    if (scopes) { 
    cJSON *scopes_local = NULL;
    if(!cJSON_IsArray(scopes)) {
        goto end;//primitive container
    }
    scopesList = list_createList();

    cJSON_ArrayForEach(scopes_local, scopes)
    {
        if(!cJSON_IsString(scopes_local))
        {
            goto end;
        }
        list_addElement(scopesList , strdup(scopes_local->valuestring));
    }
    }


    v1_resource_quota_spec_local_var = v1_resource_quota_spec_create_internal (
        hard ? hardList : NULL,
        scope_selector ? scope_selector_local_nonprim : NULL,
        scopes ? scopesList : NULL
        );

    return v1_resource_quota_spec_local_var;
end:
    if (hardList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, hardList) {
            keyValuePair_t *localKeyValue = listEntry->data;
            free(localKeyValue->key);
            localKeyValue->key = NULL;
            free(localKeyValue->value);
            localKeyValue->value = NULL;
            keyValuePair_free(localKeyValue);
            localKeyValue = NULL;
        }
        list_freeList(hardList);
        hardList = NULL;
    }
    if (scope_selector_local_nonprim) {
        v1_scope_selector_free(scope_selector_local_nonprim);
        scope_selector_local_nonprim = NULL;
    }
    if (scopesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, scopesList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(scopesList);
        scopesList = NULL;
    }
    return NULL;

}
