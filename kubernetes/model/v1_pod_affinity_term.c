#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_pod_affinity_term.h"



static v1_pod_affinity_term_t *v1_pod_affinity_term_create_internal(
    v1_label_selector_t *label_selector,
    list_t *match_label_keys,
    list_t *mismatch_label_keys,
    v1_label_selector_t *namespace_selector,
    list_t *namespaces,
    char *topology_key
    ) {
    v1_pod_affinity_term_t *v1_pod_affinity_term_local_var = malloc(sizeof(v1_pod_affinity_term_t));
    if (!v1_pod_affinity_term_local_var) {
        return NULL;
    }
    v1_pod_affinity_term_local_var->label_selector = label_selector;
    v1_pod_affinity_term_local_var->match_label_keys = match_label_keys;
    v1_pod_affinity_term_local_var->mismatch_label_keys = mismatch_label_keys;
    v1_pod_affinity_term_local_var->namespace_selector = namespace_selector;
    v1_pod_affinity_term_local_var->namespaces = namespaces;
    v1_pod_affinity_term_local_var->topology_key = topology_key;

    v1_pod_affinity_term_local_var->_library_owned = 1;
    return v1_pod_affinity_term_local_var;
}

__attribute__((deprecated)) v1_pod_affinity_term_t *v1_pod_affinity_term_create(
    v1_label_selector_t *label_selector,
    list_t *match_label_keys,
    list_t *mismatch_label_keys,
    v1_label_selector_t *namespace_selector,
    list_t *namespaces,
    char *topology_key
    ) {
    return v1_pod_affinity_term_create_internal (
        label_selector,
        match_label_keys,
        mismatch_label_keys,
        namespace_selector,
        namespaces,
        topology_key
        );
}

void v1_pod_affinity_term_free(v1_pod_affinity_term_t *v1_pod_affinity_term) {
    if(NULL == v1_pod_affinity_term){
        return ;
    }
    if(v1_pod_affinity_term->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_pod_affinity_term_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_pod_affinity_term->label_selector) {
        v1_label_selector_free(v1_pod_affinity_term->label_selector);
        v1_pod_affinity_term->label_selector = NULL;
    }
    if (v1_pod_affinity_term->match_label_keys) {
        list_ForEach(listEntry, v1_pod_affinity_term->match_label_keys) {
            free(listEntry->data);
        }
        list_freeList(v1_pod_affinity_term->match_label_keys);
        v1_pod_affinity_term->match_label_keys = NULL;
    }
    if (v1_pod_affinity_term->mismatch_label_keys) {
        list_ForEach(listEntry, v1_pod_affinity_term->mismatch_label_keys) {
            free(listEntry->data);
        }
        list_freeList(v1_pod_affinity_term->mismatch_label_keys);
        v1_pod_affinity_term->mismatch_label_keys = NULL;
    }
    if (v1_pod_affinity_term->namespace_selector) {
        v1_label_selector_free(v1_pod_affinity_term->namespace_selector);
        v1_pod_affinity_term->namespace_selector = NULL;
    }
    if (v1_pod_affinity_term->namespaces) {
        list_ForEach(listEntry, v1_pod_affinity_term->namespaces) {
            free(listEntry->data);
        }
        list_freeList(v1_pod_affinity_term->namespaces);
        v1_pod_affinity_term->namespaces = NULL;
    }
    if (v1_pod_affinity_term->topology_key) {
        free(v1_pod_affinity_term->topology_key);
        v1_pod_affinity_term->topology_key = NULL;
    }
    free(v1_pod_affinity_term);
}

cJSON *v1_pod_affinity_term_convertToJSON(v1_pod_affinity_term_t *v1_pod_affinity_term) {
    cJSON *item = cJSON_CreateObject();

    // v1_pod_affinity_term->label_selector
    if(v1_pod_affinity_term->label_selector) {
    cJSON *label_selector_local_JSON = v1_label_selector_convertToJSON(v1_pod_affinity_term->label_selector);
    if(label_selector_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "labelSelector", label_selector_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_pod_affinity_term->match_label_keys
    if(v1_pod_affinity_term->match_label_keys) {
    cJSON *match_label_keys = cJSON_AddArrayToObject(item, "matchLabelKeys");
    if(match_label_keys == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *match_label_keysListEntry;
    list_ForEach(match_label_keysListEntry, v1_pod_affinity_term->match_label_keys) {
    if(cJSON_AddStringToObject(match_label_keys, "", match_label_keysListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // v1_pod_affinity_term->mismatch_label_keys
    if(v1_pod_affinity_term->mismatch_label_keys) {
    cJSON *mismatch_label_keys = cJSON_AddArrayToObject(item, "mismatchLabelKeys");
    if(mismatch_label_keys == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *mismatch_label_keysListEntry;
    list_ForEach(mismatch_label_keysListEntry, v1_pod_affinity_term->mismatch_label_keys) {
    if(cJSON_AddStringToObject(mismatch_label_keys, "", mismatch_label_keysListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // v1_pod_affinity_term->namespace_selector
    if(v1_pod_affinity_term->namespace_selector) {
    cJSON *namespace_selector_local_JSON = v1_label_selector_convertToJSON(v1_pod_affinity_term->namespace_selector);
    if(namespace_selector_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "namespaceSelector", namespace_selector_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_pod_affinity_term->namespaces
    if(v1_pod_affinity_term->namespaces) {
    cJSON *namespaces = cJSON_AddArrayToObject(item, "namespaces");
    if(namespaces == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *namespacesListEntry;
    list_ForEach(namespacesListEntry, v1_pod_affinity_term->namespaces) {
    if(cJSON_AddStringToObject(namespaces, "", namespacesListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // v1_pod_affinity_term->topology_key
    if (!v1_pod_affinity_term->topology_key) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "topologyKey", v1_pod_affinity_term->topology_key) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_pod_affinity_term_t *v1_pod_affinity_term_parseFromJSON(cJSON *v1_pod_affinity_termJSON){

    v1_pod_affinity_term_t *v1_pod_affinity_term_local_var = NULL;

    // define the local variable for v1_pod_affinity_term->label_selector
    v1_label_selector_t *label_selector_local_nonprim = NULL;

    // define the local list for v1_pod_affinity_term->match_label_keys
    list_t *match_label_keysList = NULL;

    // define the local list for v1_pod_affinity_term->mismatch_label_keys
    list_t *mismatch_label_keysList = NULL;

    // define the local variable for v1_pod_affinity_term->namespace_selector
    v1_label_selector_t *namespace_selector_local_nonprim = NULL;

    // define the local list for v1_pod_affinity_term->namespaces
    list_t *namespacesList = NULL;

    // v1_pod_affinity_term->label_selector
    cJSON *label_selector = cJSON_GetObjectItemCaseSensitive(v1_pod_affinity_termJSON, "labelSelector");
    if (cJSON_IsNull(label_selector)) {
        label_selector = NULL;
    }
    if (label_selector) { 
    label_selector_local_nonprim = v1_label_selector_parseFromJSON(label_selector); //nonprimitive
    }

    // v1_pod_affinity_term->match_label_keys
    cJSON *match_label_keys = cJSON_GetObjectItemCaseSensitive(v1_pod_affinity_termJSON, "matchLabelKeys");
    if (cJSON_IsNull(match_label_keys)) {
        match_label_keys = NULL;
    }
    if (match_label_keys) { 
    cJSON *match_label_keys_local = NULL;
    if(!cJSON_IsArray(match_label_keys)) {
        goto end;//primitive container
    }
    match_label_keysList = list_createList();

    cJSON_ArrayForEach(match_label_keys_local, match_label_keys)
    {
        if(!cJSON_IsString(match_label_keys_local))
        {
            goto end;
        }
        list_addElement(match_label_keysList , strdup(match_label_keys_local->valuestring));
    }
    }

    // v1_pod_affinity_term->mismatch_label_keys
    cJSON *mismatch_label_keys = cJSON_GetObjectItemCaseSensitive(v1_pod_affinity_termJSON, "mismatchLabelKeys");
    if (cJSON_IsNull(mismatch_label_keys)) {
        mismatch_label_keys = NULL;
    }
    if (mismatch_label_keys) { 
    cJSON *mismatch_label_keys_local = NULL;
    if(!cJSON_IsArray(mismatch_label_keys)) {
        goto end;//primitive container
    }
    mismatch_label_keysList = list_createList();

    cJSON_ArrayForEach(mismatch_label_keys_local, mismatch_label_keys)
    {
        if(!cJSON_IsString(mismatch_label_keys_local))
        {
            goto end;
        }
        list_addElement(mismatch_label_keysList , strdup(mismatch_label_keys_local->valuestring));
    }
    }

    // v1_pod_affinity_term->namespace_selector
    cJSON *namespace_selector = cJSON_GetObjectItemCaseSensitive(v1_pod_affinity_termJSON, "namespaceSelector");
    if (cJSON_IsNull(namespace_selector)) {
        namespace_selector = NULL;
    }
    if (namespace_selector) { 
    namespace_selector_local_nonprim = v1_label_selector_parseFromJSON(namespace_selector); //nonprimitive
    }

    // v1_pod_affinity_term->namespaces
    cJSON *namespaces = cJSON_GetObjectItemCaseSensitive(v1_pod_affinity_termJSON, "namespaces");
    if (cJSON_IsNull(namespaces)) {
        namespaces = NULL;
    }
    if (namespaces) { 
    cJSON *namespaces_local = NULL;
    if(!cJSON_IsArray(namespaces)) {
        goto end;//primitive container
    }
    namespacesList = list_createList();

    cJSON_ArrayForEach(namespaces_local, namespaces)
    {
        if(!cJSON_IsString(namespaces_local))
        {
            goto end;
        }
        list_addElement(namespacesList , strdup(namespaces_local->valuestring));
    }
    }

    // v1_pod_affinity_term->topology_key
    cJSON *topology_key = cJSON_GetObjectItemCaseSensitive(v1_pod_affinity_termJSON, "topologyKey");
    if (cJSON_IsNull(topology_key)) {
        topology_key = NULL;
    }
    if (!topology_key) {
        goto end;
    }

    
    if(!cJSON_IsString(topology_key))
    {
    goto end; //String
    }


    v1_pod_affinity_term_local_var = v1_pod_affinity_term_create_internal (
        label_selector ? label_selector_local_nonprim : NULL,
        match_label_keys ? match_label_keysList : NULL,
        mismatch_label_keys ? mismatch_label_keysList : NULL,
        namespace_selector ? namespace_selector_local_nonprim : NULL,
        namespaces ? namespacesList : NULL,
        strdup(topology_key->valuestring)
        );

    return v1_pod_affinity_term_local_var;
end:
    if (label_selector_local_nonprim) {
        v1_label_selector_free(label_selector_local_nonprim);
        label_selector_local_nonprim = NULL;
    }
    if (match_label_keysList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, match_label_keysList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(match_label_keysList);
        match_label_keysList = NULL;
    }
    if (mismatch_label_keysList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, mismatch_label_keysList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(mismatch_label_keysList);
        mismatch_label_keysList = NULL;
    }
    if (namespace_selector_local_nonprim) {
        v1_label_selector_free(namespace_selector_local_nonprim);
        namespace_selector_local_nonprim = NULL;
    }
    if (namespacesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, namespacesList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(namespacesList);
        namespacesList = NULL;
    }
    return NULL;

}
