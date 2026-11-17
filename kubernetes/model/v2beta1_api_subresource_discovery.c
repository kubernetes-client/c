#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v2beta1_api_subresource_discovery.h"



static v2beta1_api_subresource_discovery_t *v2beta1_api_subresource_discovery_create_internal(
    char *subresource,
    v1_group_version_kind_t *response_kind,
    list_t *verbs,
    list_t *accepted_types
    ) {
    v2beta1_api_subresource_discovery_t *v2beta1_api_subresource_discovery_local_var = malloc(sizeof(v2beta1_api_subresource_discovery_t));
    if (!v2beta1_api_subresource_discovery_local_var) {
        return NULL;
    }
    memset(v2beta1_api_subresource_discovery_local_var, 0, sizeof(v2beta1_api_subresource_discovery_t));
    v2beta1_api_subresource_discovery_local_var->_library_owned = 1;
    v2beta1_api_subresource_discovery_local_var->subresource = subresource;
    v2beta1_api_subresource_discovery_local_var->response_kind = response_kind;
    v2beta1_api_subresource_discovery_local_var->verbs = verbs;
    v2beta1_api_subresource_discovery_local_var->accepted_types = accepted_types;
    return v2beta1_api_subresource_discovery_local_var;
}

__attribute__((deprecated)) v2beta1_api_subresource_discovery_t *v2beta1_api_subresource_discovery_create(
    char *subresource,
    v1_group_version_kind_t *response_kind,
    list_t *verbs,
    list_t *accepted_types
    ) {
    v2beta1_api_subresource_discovery_t *result = v2beta1_api_subresource_discovery_create_internal (
        subresource,
        response_kind,
        verbs,
        accepted_types
        );
    if (!result) {
    }
    return result;
}

void v2beta1_api_subresource_discovery_free(v2beta1_api_subresource_discovery_t *v2beta1_api_subresource_discovery) {
    if(NULL == v2beta1_api_subresource_discovery){
        return ;
    }
    if(v2beta1_api_subresource_discovery->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v2beta1_api_subresource_discovery_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v2beta1_api_subresource_discovery->subresource) {
        free(v2beta1_api_subresource_discovery->subresource);
        v2beta1_api_subresource_discovery->subresource = NULL;
    }
    if (v2beta1_api_subresource_discovery->response_kind) {
        v1_group_version_kind_free(v2beta1_api_subresource_discovery->response_kind);
        v2beta1_api_subresource_discovery->response_kind = NULL;
    }
    if (v2beta1_api_subresource_discovery->verbs) {
        list_ForEach(listEntry, v2beta1_api_subresource_discovery->verbs) {
            free(listEntry->data);
        }
        list_freeList(v2beta1_api_subresource_discovery->verbs);
        v2beta1_api_subresource_discovery->verbs = NULL;
    }
    if (v2beta1_api_subresource_discovery->accepted_types) {
        list_ForEach(listEntry, v2beta1_api_subresource_discovery->accepted_types) {
            v1_group_version_kind_free(listEntry->data);
        }
        list_freeList(v2beta1_api_subresource_discovery->accepted_types);
        v2beta1_api_subresource_discovery->accepted_types = NULL;
    }
    free(v2beta1_api_subresource_discovery);
}

cJSON *v2beta1_api_subresource_discovery_convertToJSON(v2beta1_api_subresource_discovery_t *v2beta1_api_subresource_discovery) {
    cJSON *item = cJSON_CreateObject();

    // v2beta1_api_subresource_discovery->subresource
    if (!v2beta1_api_subresource_discovery->subresource) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "subresource", v2beta1_api_subresource_discovery->subresource) == NULL) {
    goto fail; //String
    }


    // v2beta1_api_subresource_discovery->response_kind
    if(v2beta1_api_subresource_discovery->response_kind) {
    cJSON *response_kind_local_JSON = v1_group_version_kind_convertToJSON(v2beta1_api_subresource_discovery->response_kind);
    if(response_kind_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "responseKind", response_kind_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v2beta1_api_subresource_discovery->verbs
    if (!v2beta1_api_subresource_discovery->verbs) {
        goto fail;
    }
    cJSON *verbs = cJSON_AddArrayToObject(item, "verbs");
    if(verbs == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *verbsListEntry;
    list_ForEach(verbsListEntry, v2beta1_api_subresource_discovery->verbs) {
    if(cJSON_AddStringToObject(verbs, "", verbsListEntry->data) == NULL)
    {
        goto fail;
    }
    }


    // v2beta1_api_subresource_discovery->accepted_types
    if(v2beta1_api_subresource_discovery->accepted_types) {
    cJSON *accepted_types = cJSON_AddArrayToObject(item, "acceptedTypes");
    if(accepted_types == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *accepted_typesListEntry;
    if (v2beta1_api_subresource_discovery->accepted_types) {
    list_ForEach(accepted_typesListEntry, v2beta1_api_subresource_discovery->accepted_types) {
    cJSON *itemLocal = v1_group_version_kind_convertToJSON(accepted_typesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(accepted_types, itemLocal);
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

v2beta1_api_subresource_discovery_t *v2beta1_api_subresource_discovery_parseFromJSON(cJSON *v2beta1_api_subresource_discoveryJSON){

    v2beta1_api_subresource_discovery_t *v2beta1_api_subresource_discovery_local_var = NULL;

    char *subresource_local_str = NULL;

    // define the local variable for v2beta1_api_subresource_discovery->response_kind
    v1_group_version_kind_t *response_kind_local_nonprim = NULL;

    // define the local list for v2beta1_api_subresource_discovery->verbs
    list_t *verbsList = NULL;

    // define the local list for v2beta1_api_subresource_discovery->accepted_types
    list_t *accepted_typesList = NULL;

    // v2beta1_api_subresource_discovery->subresource
    cJSON *subresource = cJSON_GetObjectItemCaseSensitive(v2beta1_api_subresource_discoveryJSON, "subresource");
    if (cJSON_IsNull(subresource)) {
        subresource = NULL;
    }
    if (!subresource) {
        goto end;
    }

    
    if(!cJSON_IsString(subresource))
    {
    goto end; //String
    }

    // v2beta1_api_subresource_discovery->response_kind
    cJSON *response_kind = cJSON_GetObjectItemCaseSensitive(v2beta1_api_subresource_discoveryJSON, "responseKind");
    if (cJSON_IsNull(response_kind)) {
        response_kind = NULL;
    }
    if (response_kind) { 
    response_kind_local_nonprim = v1_group_version_kind_parseFromJSON(response_kind); //nonprimitive
    }

    // v2beta1_api_subresource_discovery->verbs
    cJSON *verbs = cJSON_GetObjectItemCaseSensitive(v2beta1_api_subresource_discoveryJSON, "verbs");
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

    // v2beta1_api_subresource_discovery->accepted_types
    cJSON *accepted_types = cJSON_GetObjectItemCaseSensitive(v2beta1_api_subresource_discoveryJSON, "acceptedTypes");
    if (cJSON_IsNull(accepted_types)) {
        accepted_types = NULL;
    }
    if (accepted_types) { 
    cJSON *accepted_types_local_nonprimitive = NULL;
    if(!cJSON_IsArray(accepted_types)){
        goto end; //nonprimitive container
    }

    accepted_typesList = list_createList();

    cJSON_ArrayForEach(accepted_types_local_nonprimitive,accepted_types )
    {
        if(!cJSON_IsObject(accepted_types_local_nonprimitive)){
            goto end;
        }
        v1_group_version_kind_t *accepted_typesItem = v1_group_version_kind_parseFromJSON(accepted_types_local_nonprimitive);

        list_addElement(accepted_typesList, accepted_typesItem);
    }
    }


    if (subresource && !cJSON_IsNull(subresource)) subresource_local_str = strdup(subresource->valuestring);

    v2beta1_api_subresource_discovery_local_var = v2beta1_api_subresource_discovery_create_internal (
        subresource_local_str,
        response_kind ? response_kind_local_nonprim : NULL,
        verbsList,
        accepted_types ? accepted_typesList : NULL
        );

    if (!v2beta1_api_subresource_discovery_local_var) {
        goto end;
    }

    return v2beta1_api_subresource_discovery_local_var;
end:
    if (subresource_local_str) {
        free(subresource_local_str);
        subresource_local_str = NULL;
    }
    if (response_kind_local_nonprim) {
        v1_group_version_kind_free(response_kind_local_nonprim);
        response_kind_local_nonprim = NULL;
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
    if (accepted_typesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, accepted_typesList) {
            v1_group_version_kind_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(accepted_typesList);
        accepted_typesList = NULL;
    }
    return NULL;

}
