#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_node_spec.h"



static v1_node_spec_t *v1_node_spec_create_internal(
    v1_node_config_source_t *config_source,
    char *external_id,
    char *pod_cidr,
    list_t *pod_cidrs,
    char *provider_id,
    list_t *taints,
    int unschedulable
    ) {
    v1_node_spec_t *v1_node_spec_local_var = malloc(sizeof(v1_node_spec_t));
    if (!v1_node_spec_local_var) {
        return NULL;
    }
    v1_node_spec_local_var->config_source = config_source;
    v1_node_spec_local_var->external_id = external_id;
    v1_node_spec_local_var->pod_cidr = pod_cidr;
    v1_node_spec_local_var->pod_cidrs = pod_cidrs;
    v1_node_spec_local_var->provider_id = provider_id;
    v1_node_spec_local_var->taints = taints;
    v1_node_spec_local_var->unschedulable = unschedulable;

    v1_node_spec_local_var->_library_owned = 1;
    return v1_node_spec_local_var;
}

__attribute__((deprecated)) v1_node_spec_t *v1_node_spec_create(
    v1_node_config_source_t *config_source,
    char *external_id,
    char *pod_cidr,
    list_t *pod_cidrs,
    char *provider_id,
    list_t *taints,
    int unschedulable
    ) {
    return v1_node_spec_create_internal (
        config_source,
        external_id,
        pod_cidr,
        pod_cidrs,
        provider_id,
        taints,
        unschedulable
        );
}

void v1_node_spec_free(v1_node_spec_t *v1_node_spec) {
    if(NULL == v1_node_spec){
        return ;
    }
    if(v1_node_spec->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_node_spec_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_node_spec->config_source) {
        v1_node_config_source_free(v1_node_spec->config_source);
        v1_node_spec->config_source = NULL;
    }
    if (v1_node_spec->external_id) {
        free(v1_node_spec->external_id);
        v1_node_spec->external_id = NULL;
    }
    if (v1_node_spec->pod_cidr) {
        free(v1_node_spec->pod_cidr);
        v1_node_spec->pod_cidr = NULL;
    }
    if (v1_node_spec->pod_cidrs) {
        list_ForEach(listEntry, v1_node_spec->pod_cidrs) {
            free(listEntry->data);
        }
        list_freeList(v1_node_spec->pod_cidrs);
        v1_node_spec->pod_cidrs = NULL;
    }
    if (v1_node_spec->provider_id) {
        free(v1_node_spec->provider_id);
        v1_node_spec->provider_id = NULL;
    }
    if (v1_node_spec->taints) {
        list_ForEach(listEntry, v1_node_spec->taints) {
            v1_taint_free(listEntry->data);
        }
        list_freeList(v1_node_spec->taints);
        v1_node_spec->taints = NULL;
    }
    free(v1_node_spec);
}

cJSON *v1_node_spec_convertToJSON(v1_node_spec_t *v1_node_spec) {
    cJSON *item = cJSON_CreateObject();

    // v1_node_spec->config_source
    if(v1_node_spec->config_source) {
    cJSON *config_source_local_JSON = v1_node_config_source_convertToJSON(v1_node_spec->config_source);
    if(config_source_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "configSource", config_source_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_node_spec->external_id
    if(v1_node_spec->external_id) {
    if(cJSON_AddStringToObject(item, "externalID", v1_node_spec->external_id) == NULL) {
    goto fail; //String
    }
    }


    // v1_node_spec->pod_cidr
    if(v1_node_spec->pod_cidr) {
    if(cJSON_AddStringToObject(item, "podCIDR", v1_node_spec->pod_cidr) == NULL) {
    goto fail; //String
    }
    }


    // v1_node_spec->pod_cidrs
    if(v1_node_spec->pod_cidrs) {
    cJSON *pod_cidrs = cJSON_AddArrayToObject(item, "podCIDRs");
    if(pod_cidrs == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *pod_cidrsListEntry;
    list_ForEach(pod_cidrsListEntry, v1_node_spec->pod_cidrs) {
    if(cJSON_AddStringToObject(pod_cidrs, "", pod_cidrsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // v1_node_spec->provider_id
    if(v1_node_spec->provider_id) {
    if(cJSON_AddStringToObject(item, "providerID", v1_node_spec->provider_id) == NULL) {
    goto fail; //String
    }
    }


    // v1_node_spec->taints
    if(v1_node_spec->taints) {
    cJSON *taints = cJSON_AddArrayToObject(item, "taints");
    if(taints == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *taintsListEntry;
    if (v1_node_spec->taints) {
    list_ForEach(taintsListEntry, v1_node_spec->taints) {
    cJSON *itemLocal = v1_taint_convertToJSON(taintsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(taints, itemLocal);
    }
    }
    }


    // v1_node_spec->unschedulable
    if(v1_node_spec->unschedulable) {
    if(cJSON_AddBoolToObject(item, "unschedulable", v1_node_spec->unschedulable) == NULL) {
    goto fail; //Bool
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_node_spec_t *v1_node_spec_parseFromJSON(cJSON *v1_node_specJSON){

    v1_node_spec_t *v1_node_spec_local_var = NULL;

    // define the local variable for v1_node_spec->config_source
    v1_node_config_source_t *config_source_local_nonprim = NULL;

    // define the local list for v1_node_spec->pod_cidrs
    list_t *pod_cidrsList = NULL;

    // define the local list for v1_node_spec->taints
    list_t *taintsList = NULL;

    // v1_node_spec->config_source
    cJSON *config_source = cJSON_GetObjectItemCaseSensitive(v1_node_specJSON, "configSource");
    if (cJSON_IsNull(config_source)) {
        config_source = NULL;
    }
    if (config_source) { 
    config_source_local_nonprim = v1_node_config_source_parseFromJSON(config_source); //nonprimitive
    }

    // v1_node_spec->external_id
    cJSON *external_id = cJSON_GetObjectItemCaseSensitive(v1_node_specJSON, "externalID");
    if (cJSON_IsNull(external_id)) {
        external_id = NULL;
    }
    if (external_id) { 
    if(!cJSON_IsString(external_id) && !cJSON_IsNull(external_id))
    {
    goto end; //String
    }
    }

    // v1_node_spec->pod_cidr
    cJSON *pod_cidr = cJSON_GetObjectItemCaseSensitive(v1_node_specJSON, "podCIDR");
    if (cJSON_IsNull(pod_cidr)) {
        pod_cidr = NULL;
    }
    if (pod_cidr) { 
    if(!cJSON_IsString(pod_cidr) && !cJSON_IsNull(pod_cidr))
    {
    goto end; //String
    }
    }

    // v1_node_spec->pod_cidrs
    cJSON *pod_cidrs = cJSON_GetObjectItemCaseSensitive(v1_node_specJSON, "podCIDRs");
    if (cJSON_IsNull(pod_cidrs)) {
        pod_cidrs = NULL;
    }
    if (pod_cidrs) { 
    cJSON *pod_cidrs_local = NULL;
    if(!cJSON_IsArray(pod_cidrs)) {
        goto end;//primitive container
    }
    pod_cidrsList = list_createList();

    cJSON_ArrayForEach(pod_cidrs_local, pod_cidrs)
    {
        if(!cJSON_IsString(pod_cidrs_local))
        {
            goto end;
        }
        list_addElement(pod_cidrsList , strdup(pod_cidrs_local->valuestring));
    }
    }

    // v1_node_spec->provider_id
    cJSON *provider_id = cJSON_GetObjectItemCaseSensitive(v1_node_specJSON, "providerID");
    if (cJSON_IsNull(provider_id)) {
        provider_id = NULL;
    }
    if (provider_id) { 
    if(!cJSON_IsString(provider_id) && !cJSON_IsNull(provider_id))
    {
    goto end; //String
    }
    }

    // v1_node_spec->taints
    cJSON *taints = cJSON_GetObjectItemCaseSensitive(v1_node_specJSON, "taints");
    if (cJSON_IsNull(taints)) {
        taints = NULL;
    }
    if (taints) { 
    cJSON *taints_local_nonprimitive = NULL;
    if(!cJSON_IsArray(taints)){
        goto end; //nonprimitive container
    }

    taintsList = list_createList();

    cJSON_ArrayForEach(taints_local_nonprimitive,taints )
    {
        if(!cJSON_IsObject(taints_local_nonprimitive)){
            goto end;
        }
        v1_taint_t *taintsItem = v1_taint_parseFromJSON(taints_local_nonprimitive);

        list_addElement(taintsList, taintsItem);
    }
    }

    // v1_node_spec->unschedulable
    cJSON *unschedulable = cJSON_GetObjectItemCaseSensitive(v1_node_specJSON, "unschedulable");
    if (cJSON_IsNull(unschedulable)) {
        unschedulable = NULL;
    }
    if (unschedulable) { 
    if(!cJSON_IsBool(unschedulable))
    {
    goto end; //Bool
    }
    }


    v1_node_spec_local_var = v1_node_spec_create_internal (
        config_source ? config_source_local_nonprim : NULL,
        external_id && !cJSON_IsNull(external_id) ? strdup(external_id->valuestring) : NULL,
        pod_cidr && !cJSON_IsNull(pod_cidr) ? strdup(pod_cidr->valuestring) : NULL,
        pod_cidrs ? pod_cidrsList : NULL,
        provider_id && !cJSON_IsNull(provider_id) ? strdup(provider_id->valuestring) : NULL,
        taints ? taintsList : NULL,
        unschedulable ? unschedulable->valueint : 0
        );

    return v1_node_spec_local_var;
end:
    if (config_source_local_nonprim) {
        v1_node_config_source_free(config_source_local_nonprim);
        config_source_local_nonprim = NULL;
    }
    if (pod_cidrsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, pod_cidrsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(pod_cidrsList);
        pod_cidrsList = NULL;
    }
    if (taintsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, taintsList) {
            v1_taint_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(taintsList);
        taintsList = NULL;
    }
    return NULL;

}
