#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_cluster_role.h"



v1_cluster_role_t *v1_cluster_role_create(
    v1_aggregation_rule_t *aggregation_rule,
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    list_t *rules
    ) {
    v1_cluster_role_t *v1_cluster_role_local_var = malloc(sizeof(v1_cluster_role_t));
    if (!v1_cluster_role_local_var) {
        return NULL;
    }
    v1_cluster_role_local_var->aggregation_rule = aggregation_rule;
    v1_cluster_role_local_var->api_version = api_version;
    v1_cluster_role_local_var->kind = kind;
    v1_cluster_role_local_var->metadata = metadata;
    v1_cluster_role_local_var->rules = rules;

    return v1_cluster_role_local_var;
}


void v1_cluster_role_free(v1_cluster_role_t *v1_cluster_role) {
    if(NULL == v1_cluster_role){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_cluster_role->aggregation_rule) {
        v1_aggregation_rule_free(v1_cluster_role->aggregation_rule);
        v1_cluster_role->aggregation_rule = NULL;
    }
    if (v1_cluster_role->api_version) {
        free(v1_cluster_role->api_version);
        v1_cluster_role->api_version = NULL;
    }
    if (v1_cluster_role->kind) {
        free(v1_cluster_role->kind);
        v1_cluster_role->kind = NULL;
    }
    if (v1_cluster_role->metadata) {
        v1_object_meta_free(v1_cluster_role->metadata);
        v1_cluster_role->metadata = NULL;
    }
    if (v1_cluster_role->rules) {
        list_ForEach(listEntry, v1_cluster_role->rules) {
            v1_policy_rule_free(listEntry->data);
        }
        list_free(v1_cluster_role->rules);
        v1_cluster_role->rules = NULL;
    }
    free(v1_cluster_role);
}

cJSON *v1_cluster_role_convertToJSON(v1_cluster_role_t *v1_cluster_role) {
    cJSON *item = cJSON_CreateObject();

    // v1_cluster_role->aggregation_rule
    if(v1_cluster_role->aggregation_rule) { 
    cJSON *aggregation_rule_local_JSON = v1_aggregation_rule_convertToJSON(v1_cluster_role->aggregation_rule);
    if(aggregation_rule_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "aggregationRule", aggregation_rule_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1_cluster_role->api_version
    if(v1_cluster_role->api_version) { 
    if(cJSON_AddStringToObject(item, "apiVersion", v1_cluster_role->api_version) == NULL) {
    goto fail; //String
    }
     } 


    // v1_cluster_role->kind
    if(v1_cluster_role->kind) { 
    if(cJSON_AddStringToObject(item, "kind", v1_cluster_role->kind) == NULL) {
    goto fail; //String
    }
     } 


    // v1_cluster_role->metadata
    if(v1_cluster_role->metadata) { 
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1_cluster_role->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1_cluster_role->rules
    if(v1_cluster_role->rules) { 
    cJSON *rules = cJSON_AddArrayToObject(item, "rules");
    if(rules == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *rulesListEntry;
    if (v1_cluster_role->rules) {
    list_ForEach(rulesListEntry, v1_cluster_role->rules) {
    cJSON *itemLocal = v1_policy_rule_convertToJSON(rulesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(rules, itemLocal);
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

v1_cluster_role_t *v1_cluster_role_parseFromJSON(cJSON *v1_cluster_roleJSON){

    v1_cluster_role_t *v1_cluster_role_local_var = NULL;

    // v1_cluster_role->aggregation_rule
    cJSON *aggregation_rule = cJSON_GetObjectItemCaseSensitive(v1_cluster_roleJSON, "aggregationRule");
    v1_aggregation_rule_t *aggregation_rule_local_nonprim = NULL;
    if (aggregation_rule) { 
    aggregation_rule_local_nonprim = v1_aggregation_rule_parseFromJSON(aggregation_rule); //nonprimitive
    }

    // v1_cluster_role->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1_cluster_roleJSON, "apiVersion");
    if (api_version) { 
    if(!cJSON_IsString(api_version))
    {
    goto end; //String
    }
    }

    // v1_cluster_role->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_cluster_roleJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // v1_cluster_role->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1_cluster_roleJSON, "metadata");
    v1_object_meta_t *metadata_local_nonprim = NULL;
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1_cluster_role->rules
    cJSON *rules = cJSON_GetObjectItemCaseSensitive(v1_cluster_roleJSON, "rules");
    list_t *rulesList;
    if (rules) { 
    cJSON *rules_local_nonprimitive;
    if(!cJSON_IsArray(rules)){
        goto end; //nonprimitive container
    }

    rulesList = list_create();

    cJSON_ArrayForEach(rules_local_nonprimitive,rules )
    {
        if(!cJSON_IsObject(rules_local_nonprimitive)){
            goto end;
        }
        v1_policy_rule_t *rulesItem = v1_policy_rule_parseFromJSON(rules_local_nonprimitive);

        list_addElement(rulesList, rulesItem);
    }
    }


    v1_cluster_role_local_var = v1_cluster_role_create (
        aggregation_rule ? aggregation_rule_local_nonprim : NULL,
        api_version ? strdup(api_version->valuestring) : NULL,
        kind ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        rules ? rulesList : NULL
        );

    return v1_cluster_role_local_var;
end:
    if (aggregation_rule_local_nonprim) {
        v1_aggregation_rule_free(aggregation_rule_local_nonprim);
        aggregation_rule_local_nonprim = NULL;
    }
    if (metadata_local_nonprim) {
        v1_object_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    return NULL;

}
