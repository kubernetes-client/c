#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_topology_spread_constraint.h"



static v1_topology_spread_constraint_t *v1_topology_spread_constraint_create_internal(
    v1_label_selector_t *label_selector,
    list_t *match_label_keys,
    int *max_skew,
    int *min_domains,
    char *node_affinity_policy,
    char *node_taints_policy,
    char *topology_key,
    char *when_unsatisfiable
    ) {
    v1_topology_spread_constraint_t *v1_topology_spread_constraint_local_var = malloc(sizeof(v1_topology_spread_constraint_t));
    if (!v1_topology_spread_constraint_local_var) {
        return NULL;
    }
    memset(v1_topology_spread_constraint_local_var, 0, sizeof(v1_topology_spread_constraint_t));
    v1_topology_spread_constraint_local_var->_library_owned = 1;
    v1_topology_spread_constraint_local_var->label_selector = label_selector;
    v1_topology_spread_constraint_local_var->match_label_keys = match_label_keys;
    v1_topology_spread_constraint_local_var->max_skew = max_skew;
    v1_topology_spread_constraint_local_var->min_domains = min_domains;
    v1_topology_spread_constraint_local_var->node_affinity_policy = node_affinity_policy;
    v1_topology_spread_constraint_local_var->node_taints_policy = node_taints_policy;
    v1_topology_spread_constraint_local_var->topology_key = topology_key;
    v1_topology_spread_constraint_local_var->when_unsatisfiable = when_unsatisfiable;
    return v1_topology_spread_constraint_local_var;
}

__attribute__((deprecated)) v1_topology_spread_constraint_t *v1_topology_spread_constraint_create(
    v1_label_selector_t *label_selector,
    list_t *match_label_keys,
    int *max_skew,
    int *min_domains,
    char *node_affinity_policy,
    char *node_taints_policy,
    char *topology_key,
    char *when_unsatisfiable
    ) {
    int *max_skew_copy = NULL;
    if (max_skew) {
        max_skew_copy = malloc(sizeof(int));
        if (max_skew_copy) *max_skew_copy = *max_skew;
    }
    int *min_domains_copy = NULL;
    if (min_domains) {
        min_domains_copy = malloc(sizeof(int));
        if (min_domains_copy) *min_domains_copy = *min_domains;
    }
    v1_topology_spread_constraint_t *result = v1_topology_spread_constraint_create_internal (
        label_selector,
        match_label_keys,
        max_skew_copy,
        min_domains_copy,
        node_affinity_policy,
        node_taints_policy,
        topology_key,
        when_unsatisfiable
        );
    if (!result) {
        free(max_skew_copy);
        free(min_domains_copy);
    }
    return result;
}

void v1_topology_spread_constraint_free(v1_topology_spread_constraint_t *v1_topology_spread_constraint) {
    if(NULL == v1_topology_spread_constraint){
        return ;
    }
    if(v1_topology_spread_constraint->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_topology_spread_constraint_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_topology_spread_constraint->label_selector) {
        v1_label_selector_free(v1_topology_spread_constraint->label_selector);
        v1_topology_spread_constraint->label_selector = NULL;
    }
    if (v1_topology_spread_constraint->match_label_keys) {
        list_ForEach(listEntry, v1_topology_spread_constraint->match_label_keys) {
            free(listEntry->data);
        }
        list_freeList(v1_topology_spread_constraint->match_label_keys);
        v1_topology_spread_constraint->match_label_keys = NULL;
    }
    if (v1_topology_spread_constraint->max_skew) {
        free(v1_topology_spread_constraint->max_skew);
        v1_topology_spread_constraint->max_skew = NULL;
    }
    if (v1_topology_spread_constraint->min_domains) {
        free(v1_topology_spread_constraint->min_domains);
        v1_topology_spread_constraint->min_domains = NULL;
    }
    if (v1_topology_spread_constraint->node_affinity_policy) {
        free(v1_topology_spread_constraint->node_affinity_policy);
        v1_topology_spread_constraint->node_affinity_policy = NULL;
    }
    if (v1_topology_spread_constraint->node_taints_policy) {
        free(v1_topology_spread_constraint->node_taints_policy);
        v1_topology_spread_constraint->node_taints_policy = NULL;
    }
    if (v1_topology_spread_constraint->topology_key) {
        free(v1_topology_spread_constraint->topology_key);
        v1_topology_spread_constraint->topology_key = NULL;
    }
    if (v1_topology_spread_constraint->when_unsatisfiable) {
        free(v1_topology_spread_constraint->when_unsatisfiable);
        v1_topology_spread_constraint->when_unsatisfiable = NULL;
    }
    free(v1_topology_spread_constraint);
}

cJSON *v1_topology_spread_constraint_convertToJSON(v1_topology_spread_constraint_t *v1_topology_spread_constraint) {
    cJSON *item = cJSON_CreateObject();

    // v1_topology_spread_constraint->label_selector
    if(v1_topology_spread_constraint->label_selector) {
    cJSON *label_selector_local_JSON = v1_label_selector_convertToJSON(v1_topology_spread_constraint->label_selector);
    if(label_selector_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "labelSelector", label_selector_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_topology_spread_constraint->match_label_keys
    if(v1_topology_spread_constraint->match_label_keys) {
    cJSON *match_label_keys = cJSON_AddArrayToObject(item, "matchLabelKeys");
    if(match_label_keys == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *match_label_keysListEntry;
    list_ForEach(match_label_keysListEntry, v1_topology_spread_constraint->match_label_keys) {
    if(cJSON_AddStringToObject(match_label_keys, "", match_label_keysListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // v1_topology_spread_constraint->max_skew
    if (!v1_topology_spread_constraint->max_skew) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "maxSkew", *v1_topology_spread_constraint->max_skew) == NULL) {
    goto fail; //Numeric
    }


    // v1_topology_spread_constraint->min_domains
    if(v1_topology_spread_constraint->min_domains) {
    if(cJSON_AddNumberToObject(item, "minDomains", *v1_topology_spread_constraint->min_domains) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_topology_spread_constraint->node_affinity_policy
    if(v1_topology_spread_constraint->node_affinity_policy) {
    if(cJSON_AddStringToObject(item, "nodeAffinityPolicy", v1_topology_spread_constraint->node_affinity_policy) == NULL) {
    goto fail; //String
    }
    }


    // v1_topology_spread_constraint->node_taints_policy
    if(v1_topology_spread_constraint->node_taints_policy) {
    if(cJSON_AddStringToObject(item, "nodeTaintsPolicy", v1_topology_spread_constraint->node_taints_policy) == NULL) {
    goto fail; //String
    }
    }


    // v1_topology_spread_constraint->topology_key
    if (!v1_topology_spread_constraint->topology_key) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "topologyKey", v1_topology_spread_constraint->topology_key) == NULL) {
    goto fail; //String
    }


    // v1_topology_spread_constraint->when_unsatisfiable
    if (!v1_topology_spread_constraint->when_unsatisfiable) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "whenUnsatisfiable", v1_topology_spread_constraint->when_unsatisfiable) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_topology_spread_constraint_t *v1_topology_spread_constraint_parseFromJSON(cJSON *v1_topology_spread_constraintJSON){

    v1_topology_spread_constraint_t *v1_topology_spread_constraint_local_var = NULL;

    // define the local variable for v1_topology_spread_constraint->label_selector
    v1_label_selector_t *label_selector_local_nonprim = NULL;

    // define the local list for v1_topology_spread_constraint->match_label_keys
    list_t *match_label_keysList = NULL;

    // define the local variable for v1_topology_spread_constraint->max_skew
    int *max_skew_local_var = NULL;

    // define the local variable for v1_topology_spread_constraint->min_domains
    int *min_domains_local_var = NULL;

    char *node_affinity_policy_local_str = NULL;

    char *node_taints_policy_local_str = NULL;

    char *topology_key_local_str = NULL;

    char *when_unsatisfiable_local_str = NULL;

    // v1_topology_spread_constraint->label_selector
    cJSON *label_selector = cJSON_GetObjectItemCaseSensitive(v1_topology_spread_constraintJSON, "labelSelector");
    if (cJSON_IsNull(label_selector)) {
        label_selector = NULL;
    }
    if (label_selector) { 
    label_selector_local_nonprim = v1_label_selector_parseFromJSON(label_selector); //nonprimitive
    }

    // v1_topology_spread_constraint->match_label_keys
    cJSON *match_label_keys = cJSON_GetObjectItemCaseSensitive(v1_topology_spread_constraintJSON, "matchLabelKeys");
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

    // v1_topology_spread_constraint->max_skew
    cJSON *max_skew = cJSON_GetObjectItemCaseSensitive(v1_topology_spread_constraintJSON, "maxSkew");
    if (cJSON_IsNull(max_skew)) {
        max_skew = NULL;
    }
    if (!max_skew) {
        goto end;
    }

    
    if(!cJSON_IsNumber(max_skew))
    {
    goto end; //Numeric
    }
    max_skew_local_var = malloc(sizeof(int));
    if(!max_skew_local_var)
    {
        goto end;
    }
    *max_skew_local_var = max_skew->valuedouble;

    // v1_topology_spread_constraint->min_domains
    cJSON *min_domains = cJSON_GetObjectItemCaseSensitive(v1_topology_spread_constraintJSON, "minDomains");
    if (cJSON_IsNull(min_domains)) {
        min_domains = NULL;
    }
    if (min_domains) { 
    if(!cJSON_IsNumber(min_domains))
    {
    goto end; //Numeric
    }
    min_domains_local_var = malloc(sizeof(int));
    if(!min_domains_local_var)
    {
        goto end;
    }
    *min_domains_local_var = min_domains->valuedouble;
    }

    // v1_topology_spread_constraint->node_affinity_policy
    cJSON *node_affinity_policy = cJSON_GetObjectItemCaseSensitive(v1_topology_spread_constraintJSON, "nodeAffinityPolicy");
    if (cJSON_IsNull(node_affinity_policy)) {
        node_affinity_policy = NULL;
    }
    if (node_affinity_policy) { 
    if(!cJSON_IsString(node_affinity_policy) && !cJSON_IsNull(node_affinity_policy))
    {
    goto end; //String
    }
    }

    // v1_topology_spread_constraint->node_taints_policy
    cJSON *node_taints_policy = cJSON_GetObjectItemCaseSensitive(v1_topology_spread_constraintJSON, "nodeTaintsPolicy");
    if (cJSON_IsNull(node_taints_policy)) {
        node_taints_policy = NULL;
    }
    if (node_taints_policy) { 
    if(!cJSON_IsString(node_taints_policy) && !cJSON_IsNull(node_taints_policy))
    {
    goto end; //String
    }
    }

    // v1_topology_spread_constraint->topology_key
    cJSON *topology_key = cJSON_GetObjectItemCaseSensitive(v1_topology_spread_constraintJSON, "topologyKey");
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

    // v1_topology_spread_constraint->when_unsatisfiable
    cJSON *when_unsatisfiable = cJSON_GetObjectItemCaseSensitive(v1_topology_spread_constraintJSON, "whenUnsatisfiable");
    if (cJSON_IsNull(when_unsatisfiable)) {
        when_unsatisfiable = NULL;
    }
    if (!when_unsatisfiable) {
        goto end;
    }

    
    if(!cJSON_IsString(when_unsatisfiable))
    {
    goto end; //String
    }


    if (node_affinity_policy && !cJSON_IsNull(node_affinity_policy)) node_affinity_policy_local_str = strdup(node_affinity_policy->valuestring);
    if (node_taints_policy && !cJSON_IsNull(node_taints_policy)) node_taints_policy_local_str = strdup(node_taints_policy->valuestring);
    if (topology_key && !cJSON_IsNull(topology_key)) topology_key_local_str = strdup(topology_key->valuestring);
    if (when_unsatisfiable && !cJSON_IsNull(when_unsatisfiable)) when_unsatisfiable_local_str = strdup(when_unsatisfiable->valuestring);

    v1_topology_spread_constraint_local_var = v1_topology_spread_constraint_create_internal (
        label_selector ? label_selector_local_nonprim : NULL,
        match_label_keys ? match_label_keysList : NULL,
        max_skew_local_var,
        min_domains_local_var,
        node_affinity_policy_local_str,
        node_taints_policy_local_str,
        topology_key_local_str,
        when_unsatisfiable_local_str
        );

    if (!v1_topology_spread_constraint_local_var) {
        goto end;
    }

    return v1_topology_spread_constraint_local_var;
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
    if (max_skew_local_var) {
        free(max_skew_local_var);
        max_skew_local_var = NULL;
    }
    if (min_domains_local_var) {
        free(min_domains_local_var);
        min_domains_local_var = NULL;
    }
    if (node_affinity_policy_local_str) {
        free(node_affinity_policy_local_str);
        node_affinity_policy_local_str = NULL;
    }
    if (node_taints_policy_local_str) {
        free(node_taints_policy_local_str);
        node_taints_policy_local_str = NULL;
    }
    if (topology_key_local_str) {
        free(topology_key_local_str);
        topology_key_local_str = NULL;
    }
    if (when_unsatisfiable_local_str) {
        free(when_unsatisfiable_local_str);
        when_unsatisfiable_local_str = NULL;
    }
    return NULL;

}
