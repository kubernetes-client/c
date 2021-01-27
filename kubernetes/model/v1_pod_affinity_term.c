#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_pod_affinity_term.h"



v1_pod_affinity_term_t *v1_pod_affinity_term_create(
    v1_label_selector_t *label_selector,
    list_t *namespaces,
    char *topology_key
    ) {
    v1_pod_affinity_term_t *v1_pod_affinity_term_local_var = malloc(sizeof(v1_pod_affinity_term_t));
    if (!v1_pod_affinity_term_local_var) {
        return NULL;
    }
    v1_pod_affinity_term_local_var->label_selector = label_selector;
    v1_pod_affinity_term_local_var->namespaces = namespaces;
    v1_pod_affinity_term_local_var->topology_key = topology_key;

    return v1_pod_affinity_term_local_var;
}


void v1_pod_affinity_term_free(v1_pod_affinity_term_t *v1_pod_affinity_term) {
    if(NULL == v1_pod_affinity_term){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_pod_affinity_term->label_selector) {
        v1_label_selector_free(v1_pod_affinity_term->label_selector);
        v1_pod_affinity_term->label_selector = NULL;
    }
    if (v1_pod_affinity_term->namespaces) {
        list_ForEach(listEntry, v1_pod_affinity_term->namespaces) {
            free(listEntry->data);
        }
        list_free(v1_pod_affinity_term->namespaces);
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


    // v1_pod_affinity_term->namespaces
    if(v1_pod_affinity_term->namespaces) { 
    cJSON *namespaces = cJSON_AddArrayToObject(item, "namespaces");
    if(namespaces == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *namespacesListEntry;
    list_ForEach(namespacesListEntry, v1_pod_affinity_term->namespaces) {
    if(cJSON_AddStringToObject(namespaces, "", (char*)namespacesListEntry->data) == NULL)
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

    // v1_pod_affinity_term->label_selector
    cJSON *label_selector = cJSON_GetObjectItemCaseSensitive(v1_pod_affinity_termJSON, "labelSelector");
    v1_label_selector_t *label_selector_local_nonprim = NULL;
    if (label_selector) { 
    label_selector_local_nonprim = v1_label_selector_parseFromJSON(label_selector); //nonprimitive
    }

    // v1_pod_affinity_term->namespaces
    cJSON *namespaces = cJSON_GetObjectItemCaseSensitive(v1_pod_affinity_termJSON, "namespaces");
    list_t *namespacesList;
    if (namespaces) { 
    cJSON *namespaces_local;
    if(!cJSON_IsArray(namespaces)) {
        goto end;//primitive container
    }
    namespacesList = list_create();

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
    if (!topology_key) {
        goto end;
    }

    
    if(!cJSON_IsString(topology_key))
    {
    goto end; //String
    }


    v1_pod_affinity_term_local_var = v1_pod_affinity_term_create (
        label_selector ? label_selector_local_nonprim : NULL,
        namespaces ? namespacesList : NULL,
        strdup(topology_key->valuestring)
        );

    return v1_pod_affinity_term_local_var;
end:
    if (label_selector_local_nonprim) {
        v1_label_selector_free(label_selector_local_nonprim);
        label_selector_local_nonprim = NULL;
    }
    return NULL;

}
