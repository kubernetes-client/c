#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_role.h"



static v1_role_t *v1_role_create_internal(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    list_t *rules
    ) {
    v1_role_t *v1_role_local_var = malloc(sizeof(v1_role_t));
    if (!v1_role_local_var) {
        return NULL;
    }
    v1_role_local_var->api_version = api_version;
    v1_role_local_var->kind = kind;
    v1_role_local_var->metadata = metadata;
    v1_role_local_var->rules = rules;

    v1_role_local_var->_library_owned = 1;
    return v1_role_local_var;
}

__attribute__((deprecated)) v1_role_t *v1_role_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    list_t *rules
    ) {
    return v1_role_create_internal (
        api_version,
        kind,
        metadata,
        rules
        );
}

void v1_role_free(v1_role_t *v1_role) {
    if(NULL == v1_role){
        return ;
    }
    if(v1_role->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_role_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_role->api_version) {
        free(v1_role->api_version);
        v1_role->api_version = NULL;
    }
    if (v1_role->kind) {
        free(v1_role->kind);
        v1_role->kind = NULL;
    }
    if (v1_role->metadata) {
        v1_object_meta_free(v1_role->metadata);
        v1_role->metadata = NULL;
    }
    if (v1_role->rules) {
        list_ForEach(listEntry, v1_role->rules) {
            v1_policy_rule_free(listEntry->data);
        }
        list_freeList(v1_role->rules);
        v1_role->rules = NULL;
    }
    free(v1_role);
}

cJSON *v1_role_convertToJSON(v1_role_t *v1_role) {
    cJSON *item = cJSON_CreateObject();

    // v1_role->api_version
    if(v1_role->api_version) {
    if(cJSON_AddStringToObject(item, "apiVersion", v1_role->api_version) == NULL) {
    goto fail; //String
    }
    }


    // v1_role->kind
    if(v1_role->kind) {
    if(cJSON_AddStringToObject(item, "kind", v1_role->kind) == NULL) {
    goto fail; //String
    }
    }


    // v1_role->metadata
    if(v1_role->metadata) {
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1_role->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_role->rules
    if(v1_role->rules) {
    cJSON *rules = cJSON_AddArrayToObject(item, "rules");
    if(rules == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *rulesListEntry;
    if (v1_role->rules) {
    list_ForEach(rulesListEntry, v1_role->rules) {
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

v1_role_t *v1_role_parseFromJSON(cJSON *v1_roleJSON){

    v1_role_t *v1_role_local_var = NULL;

    // define the local variable for v1_role->metadata
    v1_object_meta_t *metadata_local_nonprim = NULL;

    // define the local list for v1_role->rules
    list_t *rulesList = NULL;

    // v1_role->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1_roleJSON, "apiVersion");
    if (cJSON_IsNull(api_version)) {
        api_version = NULL;
    }
    if (api_version) { 
    if(!cJSON_IsString(api_version) && !cJSON_IsNull(api_version))
    {
    goto end; //String
    }
    }

    // v1_role->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_roleJSON, "kind");
    if (cJSON_IsNull(kind)) {
        kind = NULL;
    }
    if (kind) { 
    if(!cJSON_IsString(kind) && !cJSON_IsNull(kind))
    {
    goto end; //String
    }
    }

    // v1_role->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1_roleJSON, "metadata");
    if (cJSON_IsNull(metadata)) {
        metadata = NULL;
    }
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1_role->rules
    cJSON *rules = cJSON_GetObjectItemCaseSensitive(v1_roleJSON, "rules");
    if (cJSON_IsNull(rules)) {
        rules = NULL;
    }
    if (rules) { 
    cJSON *rules_local_nonprimitive = NULL;
    if(!cJSON_IsArray(rules)){
        goto end; //nonprimitive container
    }

    rulesList = list_createList();

    cJSON_ArrayForEach(rules_local_nonprimitive,rules )
    {
        if(!cJSON_IsObject(rules_local_nonprimitive)){
            goto end;
        }
        v1_policy_rule_t *rulesItem = v1_policy_rule_parseFromJSON(rules_local_nonprimitive);

        list_addElement(rulesList, rulesItem);
    }
    }


    v1_role_local_var = v1_role_create_internal (
        api_version && !cJSON_IsNull(api_version) ? strdup(api_version->valuestring) : NULL,
        kind && !cJSON_IsNull(kind) ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        rules ? rulesList : NULL
        );

    return v1_role_local_var;
end:
    if (metadata_local_nonprim) {
        v1_object_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    if (rulesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, rulesList) {
            v1_policy_rule_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(rulesList);
        rulesList = NULL;
    }
    return NULL;

}
