#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_resource_quota_spec.h"



v1_resource_quota_spec_t *v1_resource_quota_spec_create(
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

    return v1_resource_quota_spec_local_var;
}


void v1_resource_quota_spec_free(v1_resource_quota_spec_t *v1_resource_quota_spec) {
    if(NULL == v1_resource_quota_spec){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_resource_quota_spec->hard) {
        list_ForEach(listEntry, v1_resource_quota_spec->hard) {
            keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_free(v1_resource_quota_spec->hard);
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
        list_free(v1_resource_quota_spec->scopes);
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
        keyValuePair_t *localKeyValue = (keyValuePair_t*)hardListEntry->data;
        if(cJSON_AddStringToObject(localMapObject, localKeyValue->key, (char*)localKeyValue->value) == NULL)
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
    if(cJSON_AddStringToObject(scopes, "", (char*)scopesListEntry->data) == NULL)
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

    // v1_resource_quota_spec->hard
    cJSON *hard = cJSON_GetObjectItemCaseSensitive(v1_resource_quota_specJSON, "hard");
    list_t *hardList;
    if (hard) { 
    cJSON *hard_local_map;
    if(!cJSON_IsObject(hard)) {
        goto end;//primitive map container
    }
    hardList = list_create();
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

    // v1_resource_quota_spec->scope_selector
    cJSON *scope_selector = cJSON_GetObjectItemCaseSensitive(v1_resource_quota_specJSON, "scopeSelector");
    v1_scope_selector_t *scope_selector_local_nonprim = NULL;
    if (scope_selector) { 
    scope_selector_local_nonprim = v1_scope_selector_parseFromJSON(scope_selector); //nonprimitive
    }

    // v1_resource_quota_spec->scopes
    cJSON *scopes = cJSON_GetObjectItemCaseSensitive(v1_resource_quota_specJSON, "scopes");
    list_t *scopesList;
    if (scopes) { 
    cJSON *scopes_local;
    if(!cJSON_IsArray(scopes)) {
        goto end;//primitive container
    }
    scopesList = list_create();

    cJSON_ArrayForEach(scopes_local, scopes)
    {
        if(!cJSON_IsString(scopes_local))
        {
            goto end;
        }
        list_addElement(scopesList , strdup(scopes_local->valuestring));
    }
    }


    v1_resource_quota_spec_local_var = v1_resource_quota_spec_create (
        hard ? hardList : NULL,
        scope_selector ? scope_selector_local_nonprim : NULL,
        scopes ? scopesList : NULL
        );

    return v1_resource_quota_spec_local_var;
end:
    if (scope_selector_local_nonprim) {
        v1_scope_selector_free(scope_selector_local_nonprim);
        scope_selector_local_nonprim = NULL;
    }
    return NULL;

}
