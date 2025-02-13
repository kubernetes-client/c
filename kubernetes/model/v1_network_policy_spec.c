#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_network_policy_spec.h"



static v1_network_policy_spec_t *v1_network_policy_spec_create_internal(
    list_t *egress,
    list_t *ingress,
    v1_label_selector_t *pod_selector,
    list_t *policy_types
    ) {
    v1_network_policy_spec_t *v1_network_policy_spec_local_var = malloc(sizeof(v1_network_policy_spec_t));
    if (!v1_network_policy_spec_local_var) {
        return NULL;
    }
    v1_network_policy_spec_local_var->egress = egress;
    v1_network_policy_spec_local_var->ingress = ingress;
    v1_network_policy_spec_local_var->pod_selector = pod_selector;
    v1_network_policy_spec_local_var->policy_types = policy_types;

    v1_network_policy_spec_local_var->_library_owned = 1;
    return v1_network_policy_spec_local_var;
}

__attribute__((deprecated)) v1_network_policy_spec_t *v1_network_policy_spec_create(
    list_t *egress,
    list_t *ingress,
    v1_label_selector_t *pod_selector,
    list_t *policy_types
    ) {
    return v1_network_policy_spec_create_internal (
        egress,
        ingress,
        pod_selector,
        policy_types
        );
}

void v1_network_policy_spec_free(v1_network_policy_spec_t *v1_network_policy_spec) {
    if(NULL == v1_network_policy_spec){
        return ;
    }
    if(v1_network_policy_spec->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_network_policy_spec_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_network_policy_spec->egress) {
        list_ForEach(listEntry, v1_network_policy_spec->egress) {
            v1_network_policy_egress_rule_free(listEntry->data);
        }
        list_freeList(v1_network_policy_spec->egress);
        v1_network_policy_spec->egress = NULL;
    }
    if (v1_network_policy_spec->ingress) {
        list_ForEach(listEntry, v1_network_policy_spec->ingress) {
            v1_network_policy_ingress_rule_free(listEntry->data);
        }
        list_freeList(v1_network_policy_spec->ingress);
        v1_network_policy_spec->ingress = NULL;
    }
    if (v1_network_policy_spec->pod_selector) {
        v1_label_selector_free(v1_network_policy_spec->pod_selector);
        v1_network_policy_spec->pod_selector = NULL;
    }
    if (v1_network_policy_spec->policy_types) {
        list_ForEach(listEntry, v1_network_policy_spec->policy_types) {
            free(listEntry->data);
        }
        list_freeList(v1_network_policy_spec->policy_types);
        v1_network_policy_spec->policy_types = NULL;
    }
    free(v1_network_policy_spec);
}

cJSON *v1_network_policy_spec_convertToJSON(v1_network_policy_spec_t *v1_network_policy_spec) {
    cJSON *item = cJSON_CreateObject();

    // v1_network_policy_spec->egress
    if(v1_network_policy_spec->egress) {
    cJSON *egress = cJSON_AddArrayToObject(item, "egress");
    if(egress == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *egressListEntry;
    if (v1_network_policy_spec->egress) {
    list_ForEach(egressListEntry, v1_network_policy_spec->egress) {
    cJSON *itemLocal = v1_network_policy_egress_rule_convertToJSON(egressListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(egress, itemLocal);
    }
    }
    }


    // v1_network_policy_spec->ingress
    if(v1_network_policy_spec->ingress) {
    cJSON *ingress = cJSON_AddArrayToObject(item, "ingress");
    if(ingress == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *ingressListEntry;
    if (v1_network_policy_spec->ingress) {
    list_ForEach(ingressListEntry, v1_network_policy_spec->ingress) {
    cJSON *itemLocal = v1_network_policy_ingress_rule_convertToJSON(ingressListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(ingress, itemLocal);
    }
    }
    }


    // v1_network_policy_spec->pod_selector
    if (!v1_network_policy_spec->pod_selector) {
        goto fail;
    }
    cJSON *pod_selector_local_JSON = v1_label_selector_convertToJSON(v1_network_policy_spec->pod_selector);
    if(pod_selector_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "podSelector", pod_selector_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // v1_network_policy_spec->policy_types
    if(v1_network_policy_spec->policy_types) {
    cJSON *policy_types = cJSON_AddArrayToObject(item, "policyTypes");
    if(policy_types == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *policy_typesListEntry;
    list_ForEach(policy_typesListEntry, v1_network_policy_spec->policy_types) {
    if(cJSON_AddStringToObject(policy_types, "", policy_typesListEntry->data) == NULL)
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

v1_network_policy_spec_t *v1_network_policy_spec_parseFromJSON(cJSON *v1_network_policy_specJSON){

    v1_network_policy_spec_t *v1_network_policy_spec_local_var = NULL;

    // define the local list for v1_network_policy_spec->egress
    list_t *egressList = NULL;

    // define the local list for v1_network_policy_spec->ingress
    list_t *ingressList = NULL;

    // define the local variable for v1_network_policy_spec->pod_selector
    v1_label_selector_t *pod_selector_local_nonprim = NULL;

    // define the local list for v1_network_policy_spec->policy_types
    list_t *policy_typesList = NULL;

    // v1_network_policy_spec->egress
    cJSON *egress = cJSON_GetObjectItemCaseSensitive(v1_network_policy_specJSON, "egress");
    if (cJSON_IsNull(egress)) {
        egress = NULL;
    }
    if (egress) { 
    cJSON *egress_local_nonprimitive = NULL;
    if(!cJSON_IsArray(egress)){
        goto end; //nonprimitive container
    }

    egressList = list_createList();

    cJSON_ArrayForEach(egress_local_nonprimitive,egress )
    {
        if(!cJSON_IsObject(egress_local_nonprimitive)){
            goto end;
        }
        v1_network_policy_egress_rule_t *egressItem = v1_network_policy_egress_rule_parseFromJSON(egress_local_nonprimitive);

        list_addElement(egressList, egressItem);
    }
    }

    // v1_network_policy_spec->ingress
    cJSON *ingress = cJSON_GetObjectItemCaseSensitive(v1_network_policy_specJSON, "ingress");
    if (cJSON_IsNull(ingress)) {
        ingress = NULL;
    }
    if (ingress) { 
    cJSON *ingress_local_nonprimitive = NULL;
    if(!cJSON_IsArray(ingress)){
        goto end; //nonprimitive container
    }

    ingressList = list_createList();

    cJSON_ArrayForEach(ingress_local_nonprimitive,ingress )
    {
        if(!cJSON_IsObject(ingress_local_nonprimitive)){
            goto end;
        }
        v1_network_policy_ingress_rule_t *ingressItem = v1_network_policy_ingress_rule_parseFromJSON(ingress_local_nonprimitive);

        list_addElement(ingressList, ingressItem);
    }
    }

    // v1_network_policy_spec->pod_selector
    cJSON *pod_selector = cJSON_GetObjectItemCaseSensitive(v1_network_policy_specJSON, "podSelector");
    if (cJSON_IsNull(pod_selector)) {
        pod_selector = NULL;
    }
    if (!pod_selector) {
        goto end;
    }

    
    pod_selector_local_nonprim = v1_label_selector_parseFromJSON(pod_selector); //nonprimitive

    // v1_network_policy_spec->policy_types
    cJSON *policy_types = cJSON_GetObjectItemCaseSensitive(v1_network_policy_specJSON, "policyTypes");
    if (cJSON_IsNull(policy_types)) {
        policy_types = NULL;
    }
    if (policy_types) { 
    cJSON *policy_types_local = NULL;
    if(!cJSON_IsArray(policy_types)) {
        goto end;//primitive container
    }
    policy_typesList = list_createList();

    cJSON_ArrayForEach(policy_types_local, policy_types)
    {
        if(!cJSON_IsString(policy_types_local))
        {
            goto end;
        }
        list_addElement(policy_typesList , strdup(policy_types_local->valuestring));
    }
    }


    v1_network_policy_spec_local_var = v1_network_policy_spec_create_internal (
        egress ? egressList : NULL,
        ingress ? ingressList : NULL,
        pod_selector_local_nonprim,
        policy_types ? policy_typesList : NULL
        );

    return v1_network_policy_spec_local_var;
end:
    if (egressList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, egressList) {
            v1_network_policy_egress_rule_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(egressList);
        egressList = NULL;
    }
    if (ingressList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, ingressList) {
            v1_network_policy_ingress_rule_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(ingressList);
        ingressList = NULL;
    }
    if (pod_selector_local_nonprim) {
        v1_label_selector_free(pod_selector_local_nonprim);
        pod_selector_local_nonprim = NULL;
    }
    if (policy_typesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, policy_typesList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(policy_typesList);
        policy_typesList = NULL;
    }
    return NULL;

}
