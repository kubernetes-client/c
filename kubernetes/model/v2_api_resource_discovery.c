#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v2_api_resource_discovery.h"



static v2_api_resource_discovery_t *v2_api_resource_discovery_create_internal(
    char *resource,
    v1_group_version_kind_t *response_kind,
    char *scope,
    char *singular_resource,
    list_t *verbs,
    list_t *short_names,
    list_t *categories,
    list_t *subresources
    ) {
    v2_api_resource_discovery_t *v2_api_resource_discovery_local_var = malloc(sizeof(v2_api_resource_discovery_t));
    if (!v2_api_resource_discovery_local_var) {
        return NULL;
    }
    memset(v2_api_resource_discovery_local_var, 0, sizeof(v2_api_resource_discovery_t));
    v2_api_resource_discovery_local_var->_library_owned = 1;
    v2_api_resource_discovery_local_var->resource = resource;
    v2_api_resource_discovery_local_var->response_kind = response_kind;
    v2_api_resource_discovery_local_var->scope = scope;
    v2_api_resource_discovery_local_var->singular_resource = singular_resource;
    v2_api_resource_discovery_local_var->verbs = verbs;
    v2_api_resource_discovery_local_var->short_names = short_names;
    v2_api_resource_discovery_local_var->categories = categories;
    v2_api_resource_discovery_local_var->subresources = subresources;
    return v2_api_resource_discovery_local_var;
}

__attribute__((deprecated)) v2_api_resource_discovery_t *v2_api_resource_discovery_create(
    char *resource,
    v1_group_version_kind_t *response_kind,
    char *scope,
    char *singular_resource,
    list_t *verbs,
    list_t *short_names,
    list_t *categories,
    list_t *subresources
    ) {
    v2_api_resource_discovery_t *result = v2_api_resource_discovery_create_internal (
        resource,
        response_kind,
        scope,
        singular_resource,
        verbs,
        short_names,
        categories,
        subresources
        );
    if (!result) {
    }
    return result;
}

void v2_api_resource_discovery_free(v2_api_resource_discovery_t *v2_api_resource_discovery) {
    if(NULL == v2_api_resource_discovery){
        return ;
    }
    if(v2_api_resource_discovery->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v2_api_resource_discovery_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v2_api_resource_discovery->resource) {
        free(v2_api_resource_discovery->resource);
        v2_api_resource_discovery->resource = NULL;
    }
    if (v2_api_resource_discovery->response_kind) {
        v1_group_version_kind_free(v2_api_resource_discovery->response_kind);
        v2_api_resource_discovery->response_kind = NULL;
    }
    if (v2_api_resource_discovery->scope) {
        free(v2_api_resource_discovery->scope);
        v2_api_resource_discovery->scope = NULL;
    }
    if (v2_api_resource_discovery->singular_resource) {
        free(v2_api_resource_discovery->singular_resource);
        v2_api_resource_discovery->singular_resource = NULL;
    }
    if (v2_api_resource_discovery->verbs) {
        list_ForEach(listEntry, v2_api_resource_discovery->verbs) {
            free(listEntry->data);
        }
        list_freeList(v2_api_resource_discovery->verbs);
        v2_api_resource_discovery->verbs = NULL;
    }
    if (v2_api_resource_discovery->short_names) {
        list_ForEach(listEntry, v2_api_resource_discovery->short_names) {
            free(listEntry->data);
        }
        list_freeList(v2_api_resource_discovery->short_names);
        v2_api_resource_discovery->short_names = NULL;
    }
    if (v2_api_resource_discovery->categories) {
        list_ForEach(listEntry, v2_api_resource_discovery->categories) {
            free(listEntry->data);
        }
        list_freeList(v2_api_resource_discovery->categories);
        v2_api_resource_discovery->categories = NULL;
    }
    if (v2_api_resource_discovery->subresources) {
        list_ForEach(listEntry, v2_api_resource_discovery->subresources) {
            v2_api_subresource_discovery_free(listEntry->data);
        }
        list_freeList(v2_api_resource_discovery->subresources);
        v2_api_resource_discovery->subresources = NULL;
    }
    free(v2_api_resource_discovery);
}

cJSON *v2_api_resource_discovery_convertToJSON(v2_api_resource_discovery_t *v2_api_resource_discovery) {
    cJSON *item = cJSON_CreateObject();

    // v2_api_resource_discovery->resource
    if (!v2_api_resource_discovery->resource) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "resource", v2_api_resource_discovery->resource) == NULL) {
    goto fail; //String
    }


    // v2_api_resource_discovery->response_kind
    if(v2_api_resource_discovery->response_kind) {
    cJSON *response_kind_local_JSON = v1_group_version_kind_convertToJSON(v2_api_resource_discovery->response_kind);
    if(response_kind_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "responseKind", response_kind_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v2_api_resource_discovery->scope
    if (!v2_api_resource_discovery->scope) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "scope", v2_api_resource_discovery->scope) == NULL) {
    goto fail; //String
    }


    // v2_api_resource_discovery->singular_resource
    if (!v2_api_resource_discovery->singular_resource) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "singularResource", v2_api_resource_discovery->singular_resource) == NULL) {
    goto fail; //String
    }


    // v2_api_resource_discovery->verbs
    if (!v2_api_resource_discovery->verbs) {
        goto fail;
    }
    cJSON *verbs = cJSON_AddArrayToObject(item, "verbs");
    if(verbs == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *verbsListEntry;
    list_ForEach(verbsListEntry, v2_api_resource_discovery->verbs) {
    if(cJSON_AddStringToObject(verbs, "", verbsListEntry->data) == NULL)
    {
        goto fail;
    }
    }


    // v2_api_resource_discovery->short_names
    if(v2_api_resource_discovery->short_names) {
    cJSON *short_names = cJSON_AddArrayToObject(item, "shortNames");
    if(short_names == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *short_namesListEntry;
    list_ForEach(short_namesListEntry, v2_api_resource_discovery->short_names) {
    if(cJSON_AddStringToObject(short_names, "", short_namesListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // v2_api_resource_discovery->categories
    if(v2_api_resource_discovery->categories) {
    cJSON *categories = cJSON_AddArrayToObject(item, "categories");
    if(categories == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *categoriesListEntry;
    list_ForEach(categoriesListEntry, v2_api_resource_discovery->categories) {
    if(cJSON_AddStringToObject(categories, "", categoriesListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // v2_api_resource_discovery->subresources
    if(v2_api_resource_discovery->subresources) {
    cJSON *subresources = cJSON_AddArrayToObject(item, "subresources");
    if(subresources == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *subresourcesListEntry;
    if (v2_api_resource_discovery->subresources) {
    list_ForEach(subresourcesListEntry, v2_api_resource_discovery->subresources) {
    cJSON *itemLocal = v2_api_subresource_discovery_convertToJSON(subresourcesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(subresources, itemLocal);
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

v2_api_resource_discovery_t *v2_api_resource_discovery_parseFromJSON(cJSON *v2_api_resource_discoveryJSON){

    v2_api_resource_discovery_t *v2_api_resource_discovery_local_var = NULL;

    char *resource_local_str = NULL;

    // define the local variable for v2_api_resource_discovery->response_kind
    v1_group_version_kind_t *response_kind_local_nonprim = NULL;

    char *scope_local_str = NULL;

    char *singular_resource_local_str = NULL;

    // define the local list for v2_api_resource_discovery->verbs
    list_t *verbsList = NULL;

    // define the local list for v2_api_resource_discovery->short_names
    list_t *short_namesList = NULL;

    // define the local list for v2_api_resource_discovery->categories
    list_t *categoriesList = NULL;

    // define the local list for v2_api_resource_discovery->subresources
    list_t *subresourcesList = NULL;

    // v2_api_resource_discovery->resource
    cJSON *resource = cJSON_GetObjectItemCaseSensitive(v2_api_resource_discoveryJSON, "resource");
    if (cJSON_IsNull(resource)) {
        resource = NULL;
    }
    if (!resource) {
        goto end;
    }

    
    if(!cJSON_IsString(resource))
    {
    goto end; //String
    }

    // v2_api_resource_discovery->response_kind
    cJSON *response_kind = cJSON_GetObjectItemCaseSensitive(v2_api_resource_discoveryJSON, "responseKind");
    if (cJSON_IsNull(response_kind)) {
        response_kind = NULL;
    }
    if (response_kind) { 
    response_kind_local_nonprim = v1_group_version_kind_parseFromJSON(response_kind); //nonprimitive
    }

    // v2_api_resource_discovery->scope
    cJSON *scope = cJSON_GetObjectItemCaseSensitive(v2_api_resource_discoveryJSON, "scope");
    if (cJSON_IsNull(scope)) {
        scope = NULL;
    }
    if (!scope) {
        goto end;
    }

    
    if(!cJSON_IsString(scope))
    {
    goto end; //String
    }

    // v2_api_resource_discovery->singular_resource
    cJSON *singular_resource = cJSON_GetObjectItemCaseSensitive(v2_api_resource_discoveryJSON, "singularResource");
    if (cJSON_IsNull(singular_resource)) {
        singular_resource = NULL;
    }
    if (!singular_resource) {
        goto end;
    }

    
    if(!cJSON_IsString(singular_resource))
    {
    goto end; //String
    }

    // v2_api_resource_discovery->verbs
    cJSON *verbs = cJSON_GetObjectItemCaseSensitive(v2_api_resource_discoveryJSON, "verbs");
    if (cJSON_IsNull(verbs)) {
        verbs = NULL;
    }
    if (!verbs) {
        goto end;
    }

    
    cJSON *verbs_local = NULL;
    if(!cJSON_IsArray(verbs)) {
        goto end;//primitive container
    }
    verbsList = list_createList();

    cJSON_ArrayForEach(verbs_local, verbs)
    {
        if(!cJSON_IsString(verbs_local))
        {
            goto end;
        }
        list_addElement(verbsList , strdup(verbs_local->valuestring));
    }

    // v2_api_resource_discovery->short_names
    cJSON *short_names = cJSON_GetObjectItemCaseSensitive(v2_api_resource_discoveryJSON, "shortNames");
    if (cJSON_IsNull(short_names)) {
        short_names = NULL;
    }
    if (short_names) { 
    cJSON *short_names_local = NULL;
    if(!cJSON_IsArray(short_names)) {
        goto end;//primitive container
    }
    short_namesList = list_createList();

    cJSON_ArrayForEach(short_names_local, short_names)
    {
        if(!cJSON_IsString(short_names_local))
        {
            goto end;
        }
        list_addElement(short_namesList , strdup(short_names_local->valuestring));
    }
    }

    // v2_api_resource_discovery->categories
    cJSON *categories = cJSON_GetObjectItemCaseSensitive(v2_api_resource_discoveryJSON, "categories");
    if (cJSON_IsNull(categories)) {
        categories = NULL;
    }
    if (categories) { 
    cJSON *categories_local = NULL;
    if(!cJSON_IsArray(categories)) {
        goto end;//primitive container
    }
    categoriesList = list_createList();

    cJSON_ArrayForEach(categories_local, categories)
    {
        if(!cJSON_IsString(categories_local))
        {
            goto end;
        }
        list_addElement(categoriesList , strdup(categories_local->valuestring));
    }
    }

    // v2_api_resource_discovery->subresources
    cJSON *subresources = cJSON_GetObjectItemCaseSensitive(v2_api_resource_discoveryJSON, "subresources");
    if (cJSON_IsNull(subresources)) {
        subresources = NULL;
    }
    if (subresources) { 
    cJSON *subresources_local_nonprimitive = NULL;
    if(!cJSON_IsArray(subresources)){
        goto end; //nonprimitive container
    }

    subresourcesList = list_createList();

    cJSON_ArrayForEach(subresources_local_nonprimitive,subresources )
    {
        if(!cJSON_IsObject(subresources_local_nonprimitive)){
            goto end;
        }
        v2_api_subresource_discovery_t *subresourcesItem = v2_api_subresource_discovery_parseFromJSON(subresources_local_nonprimitive);

        list_addElement(subresourcesList, subresourcesItem);
    }
    }


    if (resource && !cJSON_IsNull(resource)) resource_local_str = strdup(resource->valuestring);
    if (scope && !cJSON_IsNull(scope)) scope_local_str = strdup(scope->valuestring);
    if (singular_resource && !cJSON_IsNull(singular_resource)) singular_resource_local_str = strdup(singular_resource->valuestring);

    v2_api_resource_discovery_local_var = v2_api_resource_discovery_create_internal (
        resource_local_str,
        response_kind ? response_kind_local_nonprim : NULL,
        scope_local_str,
        singular_resource_local_str,
        verbsList,
        short_names ? short_namesList : NULL,
        categories ? categoriesList : NULL,
        subresources ? subresourcesList : NULL
        );

    if (!v2_api_resource_discovery_local_var) {
        goto end;
    }

    return v2_api_resource_discovery_local_var;
end:
    if (resource_local_str) {
        free(resource_local_str);
        resource_local_str = NULL;
    }
    if (response_kind_local_nonprim) {
        v1_group_version_kind_free(response_kind_local_nonprim);
        response_kind_local_nonprim = NULL;
    }
    if (scope_local_str) {
        free(scope_local_str);
        scope_local_str = NULL;
    }
    if (singular_resource_local_str) {
        free(singular_resource_local_str);
        singular_resource_local_str = NULL;
    }
    if (verbsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, verbsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(verbsList);
        verbsList = NULL;
    }
    if (short_namesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, short_namesList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(short_namesList);
        short_namesList = NULL;
    }
    if (categoriesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, categoriesList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(categoriesList);
        categoriesList = NULL;
    }
    if (subresourcesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, subresourcesList) {
            v2_api_subresource_discovery_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(subresourcesList);
        subresourcesList = NULL;
    }
    return NULL;

}
