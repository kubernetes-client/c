#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_stateful_set_spec.h"



static v1_stateful_set_spec_t *v1_stateful_set_spec_create_internal(
    int *min_ready_seconds,
    v1_stateful_set_ordinals_t *ordinals,
    v1_stateful_set_persistent_volume_claim_retention_policy_t *persistent_volume_claim_retention_policy,
    char *pod_management_policy,
    int *replicas,
    int *revision_history_limit,
    v1_label_selector_t *selector,
    char *service_name,
    v1_pod_template_spec_t *_template,
    v1_stateful_set_update_strategy_t *update_strategy,
    list_t *volume_claim_templates
    ) {
    v1_stateful_set_spec_t *v1_stateful_set_spec_local_var = malloc(sizeof(v1_stateful_set_spec_t));
    if (!v1_stateful_set_spec_local_var) {
        return NULL;
    }
    memset(v1_stateful_set_spec_local_var, 0, sizeof(v1_stateful_set_spec_t));
    v1_stateful_set_spec_local_var->_library_owned = 1;
    v1_stateful_set_spec_local_var->min_ready_seconds = min_ready_seconds;
    v1_stateful_set_spec_local_var->ordinals = ordinals;
    v1_stateful_set_spec_local_var->persistent_volume_claim_retention_policy = persistent_volume_claim_retention_policy;
    v1_stateful_set_spec_local_var->pod_management_policy = pod_management_policy;
    v1_stateful_set_spec_local_var->replicas = replicas;
    v1_stateful_set_spec_local_var->revision_history_limit = revision_history_limit;
    v1_stateful_set_spec_local_var->selector = selector;
    v1_stateful_set_spec_local_var->service_name = service_name;
    v1_stateful_set_spec_local_var->_template = _template;
    v1_stateful_set_spec_local_var->update_strategy = update_strategy;
    v1_stateful_set_spec_local_var->volume_claim_templates = volume_claim_templates;
    return v1_stateful_set_spec_local_var;
}

__attribute__((deprecated)) v1_stateful_set_spec_t *v1_stateful_set_spec_create(
    int *min_ready_seconds,
    v1_stateful_set_ordinals_t *ordinals,
    v1_stateful_set_persistent_volume_claim_retention_policy_t *persistent_volume_claim_retention_policy,
    char *pod_management_policy,
    int *replicas,
    int *revision_history_limit,
    v1_label_selector_t *selector,
    char *service_name,
    v1_pod_template_spec_t *_template,
    v1_stateful_set_update_strategy_t *update_strategy,
    list_t *volume_claim_templates
    ) {
    int *min_ready_seconds_copy = NULL;
    if (min_ready_seconds) {
        min_ready_seconds_copy = malloc(sizeof(int));
        if (min_ready_seconds_copy) *min_ready_seconds_copy = *min_ready_seconds;
    }
    int *replicas_copy = NULL;
    if (replicas) {
        replicas_copy = malloc(sizeof(int));
        if (replicas_copy) *replicas_copy = *replicas;
    }
    int *revision_history_limit_copy = NULL;
    if (revision_history_limit) {
        revision_history_limit_copy = malloc(sizeof(int));
        if (revision_history_limit_copy) *revision_history_limit_copy = *revision_history_limit;
    }
    v1_stateful_set_spec_t *result = v1_stateful_set_spec_create_internal (
        min_ready_seconds_copy,
        ordinals,
        persistent_volume_claim_retention_policy,
        pod_management_policy,
        replicas_copy,
        revision_history_limit_copy,
        selector,
        service_name,
        _template,
        update_strategy,
        volume_claim_templates
        );
    if (!result) {
        free(min_ready_seconds_copy);
        free(replicas_copy);
        free(revision_history_limit_copy);
    }
    return result;
}

void v1_stateful_set_spec_free(v1_stateful_set_spec_t *v1_stateful_set_spec) {
    if(NULL == v1_stateful_set_spec){
        return ;
    }
    if(v1_stateful_set_spec->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_stateful_set_spec_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_stateful_set_spec->min_ready_seconds) {
        free(v1_stateful_set_spec->min_ready_seconds);
        v1_stateful_set_spec->min_ready_seconds = NULL;
    }
    if (v1_stateful_set_spec->ordinals) {
        v1_stateful_set_ordinals_free(v1_stateful_set_spec->ordinals);
        v1_stateful_set_spec->ordinals = NULL;
    }
    if (v1_stateful_set_spec->persistent_volume_claim_retention_policy) {
        v1_stateful_set_persistent_volume_claim_retention_policy_free(v1_stateful_set_spec->persistent_volume_claim_retention_policy);
        v1_stateful_set_spec->persistent_volume_claim_retention_policy = NULL;
    }
    if (v1_stateful_set_spec->pod_management_policy) {
        free(v1_stateful_set_spec->pod_management_policy);
        v1_stateful_set_spec->pod_management_policy = NULL;
    }
    if (v1_stateful_set_spec->replicas) {
        free(v1_stateful_set_spec->replicas);
        v1_stateful_set_spec->replicas = NULL;
    }
    if (v1_stateful_set_spec->revision_history_limit) {
        free(v1_stateful_set_spec->revision_history_limit);
        v1_stateful_set_spec->revision_history_limit = NULL;
    }
    if (v1_stateful_set_spec->selector) {
        v1_label_selector_free(v1_stateful_set_spec->selector);
        v1_stateful_set_spec->selector = NULL;
    }
    if (v1_stateful_set_spec->service_name) {
        free(v1_stateful_set_spec->service_name);
        v1_stateful_set_spec->service_name = NULL;
    }
    if (v1_stateful_set_spec->_template) {
        v1_pod_template_spec_free(v1_stateful_set_spec->_template);
        v1_stateful_set_spec->_template = NULL;
    }
    if (v1_stateful_set_spec->update_strategy) {
        v1_stateful_set_update_strategy_free(v1_stateful_set_spec->update_strategy);
        v1_stateful_set_spec->update_strategy = NULL;
    }
    if (v1_stateful_set_spec->volume_claim_templates) {
        list_ForEach(listEntry, v1_stateful_set_spec->volume_claim_templates) {
            v1_persistent_volume_claim_free(listEntry->data);
        }
        list_freeList(v1_stateful_set_spec->volume_claim_templates);
        v1_stateful_set_spec->volume_claim_templates = NULL;
    }
    free(v1_stateful_set_spec);
}

cJSON *v1_stateful_set_spec_convertToJSON(v1_stateful_set_spec_t *v1_stateful_set_spec) {
    cJSON *item = cJSON_CreateObject();

    // v1_stateful_set_spec->min_ready_seconds
    if(v1_stateful_set_spec->min_ready_seconds) {
    if(cJSON_AddNumberToObject(item, "minReadySeconds", *v1_stateful_set_spec->min_ready_seconds) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_stateful_set_spec->ordinals
    if(v1_stateful_set_spec->ordinals) {
    cJSON *ordinals_local_JSON = v1_stateful_set_ordinals_convertToJSON(v1_stateful_set_spec->ordinals);
    if(ordinals_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "ordinals", ordinals_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_stateful_set_spec->persistent_volume_claim_retention_policy
    if(v1_stateful_set_spec->persistent_volume_claim_retention_policy) {
    cJSON *persistent_volume_claim_retention_policy_local_JSON = v1_stateful_set_persistent_volume_claim_retention_policy_convertToJSON(v1_stateful_set_spec->persistent_volume_claim_retention_policy);
    if(persistent_volume_claim_retention_policy_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "persistentVolumeClaimRetentionPolicy", persistent_volume_claim_retention_policy_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_stateful_set_spec->pod_management_policy
    if(v1_stateful_set_spec->pod_management_policy) {
    if(cJSON_AddStringToObject(item, "podManagementPolicy", v1_stateful_set_spec->pod_management_policy) == NULL) {
    goto fail; //String
    }
    }


    // v1_stateful_set_spec->replicas
    if(v1_stateful_set_spec->replicas) {
    if(cJSON_AddNumberToObject(item, "replicas", *v1_stateful_set_spec->replicas) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_stateful_set_spec->revision_history_limit
    if(v1_stateful_set_spec->revision_history_limit) {
    if(cJSON_AddNumberToObject(item, "revisionHistoryLimit", *v1_stateful_set_spec->revision_history_limit) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_stateful_set_spec->selector
    if (!v1_stateful_set_spec->selector) {
        goto fail;
    }
    cJSON *selector_local_JSON = v1_label_selector_convertToJSON(v1_stateful_set_spec->selector);
    if(selector_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "selector", selector_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // v1_stateful_set_spec->service_name
    if(v1_stateful_set_spec->service_name) {
    if(cJSON_AddStringToObject(item, "serviceName", v1_stateful_set_spec->service_name) == NULL) {
    goto fail; //String
    }
    }


    // v1_stateful_set_spec->_template
    if (!v1_stateful_set_spec->_template) {
        goto fail;
    }
    cJSON *_template_local_JSON = v1_pod_template_spec_convertToJSON(v1_stateful_set_spec->_template);
    if(_template_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "template", _template_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // v1_stateful_set_spec->update_strategy
    if(v1_stateful_set_spec->update_strategy) {
    cJSON *update_strategy_local_JSON = v1_stateful_set_update_strategy_convertToJSON(v1_stateful_set_spec->update_strategy);
    if(update_strategy_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "updateStrategy", update_strategy_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_stateful_set_spec->volume_claim_templates
    if(v1_stateful_set_spec->volume_claim_templates) {
    cJSON *volume_claim_templates = cJSON_AddArrayToObject(item, "volumeClaimTemplates");
    if(volume_claim_templates == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *volume_claim_templatesListEntry;
    if (v1_stateful_set_spec->volume_claim_templates) {
    list_ForEach(volume_claim_templatesListEntry, v1_stateful_set_spec->volume_claim_templates) {
    cJSON *itemLocal = v1_persistent_volume_claim_convertToJSON(volume_claim_templatesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(volume_claim_templates, itemLocal);
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

v1_stateful_set_spec_t *v1_stateful_set_spec_parseFromJSON(cJSON *v1_stateful_set_specJSON){

    v1_stateful_set_spec_t *v1_stateful_set_spec_local_var = NULL;

    // define the local variable for v1_stateful_set_spec->min_ready_seconds
    int *min_ready_seconds_local_var = NULL;

    // define the local variable for v1_stateful_set_spec->ordinals
    v1_stateful_set_ordinals_t *ordinals_local_nonprim = NULL;

    // define the local variable for v1_stateful_set_spec->persistent_volume_claim_retention_policy
    v1_stateful_set_persistent_volume_claim_retention_policy_t *persistent_volume_claim_retention_policy_local_nonprim = NULL;

    char *pod_management_policy_local_str = NULL;

    // define the local variable for v1_stateful_set_spec->replicas
    int *replicas_local_var = NULL;

    // define the local variable for v1_stateful_set_spec->revision_history_limit
    int *revision_history_limit_local_var = NULL;

    // define the local variable for v1_stateful_set_spec->selector
    v1_label_selector_t *selector_local_nonprim = NULL;

    char *service_name_local_str = NULL;

    // define the local variable for v1_stateful_set_spec->_template
    v1_pod_template_spec_t *_template_local_nonprim = NULL;

    // define the local variable for v1_stateful_set_spec->update_strategy
    v1_stateful_set_update_strategy_t *update_strategy_local_nonprim = NULL;

    // define the local list for v1_stateful_set_spec->volume_claim_templates
    list_t *volume_claim_templatesList = NULL;

    // v1_stateful_set_spec->min_ready_seconds
    cJSON *min_ready_seconds = cJSON_GetObjectItemCaseSensitive(v1_stateful_set_specJSON, "minReadySeconds");
    if (cJSON_IsNull(min_ready_seconds)) {
        min_ready_seconds = NULL;
    }
    if (min_ready_seconds) { 
    if(!cJSON_IsNumber(min_ready_seconds))
    {
    goto end; //Numeric
    }
    min_ready_seconds_local_var = malloc(sizeof(int));
    if(!min_ready_seconds_local_var)
    {
        goto end;
    }
    *min_ready_seconds_local_var = min_ready_seconds->valuedouble;
    }

    // v1_stateful_set_spec->ordinals
    cJSON *ordinals = cJSON_GetObjectItemCaseSensitive(v1_stateful_set_specJSON, "ordinals");
    if (cJSON_IsNull(ordinals)) {
        ordinals = NULL;
    }
    if (ordinals) { 
    ordinals_local_nonprim = v1_stateful_set_ordinals_parseFromJSON(ordinals); //nonprimitive
    }

    // v1_stateful_set_spec->persistent_volume_claim_retention_policy
    cJSON *persistent_volume_claim_retention_policy = cJSON_GetObjectItemCaseSensitive(v1_stateful_set_specJSON, "persistentVolumeClaimRetentionPolicy");
    if (cJSON_IsNull(persistent_volume_claim_retention_policy)) {
        persistent_volume_claim_retention_policy = NULL;
    }
    if (persistent_volume_claim_retention_policy) { 
    persistent_volume_claim_retention_policy_local_nonprim = v1_stateful_set_persistent_volume_claim_retention_policy_parseFromJSON(persistent_volume_claim_retention_policy); //nonprimitive
    }

    // v1_stateful_set_spec->pod_management_policy
    cJSON *pod_management_policy = cJSON_GetObjectItemCaseSensitive(v1_stateful_set_specJSON, "podManagementPolicy");
    if (cJSON_IsNull(pod_management_policy)) {
        pod_management_policy = NULL;
    }
    if (pod_management_policy) { 
    if(!cJSON_IsString(pod_management_policy) && !cJSON_IsNull(pod_management_policy))
    {
    goto end; //String
    }
    }

    // v1_stateful_set_spec->replicas
    cJSON *replicas = cJSON_GetObjectItemCaseSensitive(v1_stateful_set_specJSON, "replicas");
    if (cJSON_IsNull(replicas)) {
        replicas = NULL;
    }
    if (replicas) { 
    if(!cJSON_IsNumber(replicas))
    {
    goto end; //Numeric
    }
    replicas_local_var = malloc(sizeof(int));
    if(!replicas_local_var)
    {
        goto end;
    }
    *replicas_local_var = replicas->valuedouble;
    }

    // v1_stateful_set_spec->revision_history_limit
    cJSON *revision_history_limit = cJSON_GetObjectItemCaseSensitive(v1_stateful_set_specJSON, "revisionHistoryLimit");
    if (cJSON_IsNull(revision_history_limit)) {
        revision_history_limit = NULL;
    }
    if (revision_history_limit) { 
    if(!cJSON_IsNumber(revision_history_limit))
    {
    goto end; //Numeric
    }
    revision_history_limit_local_var = malloc(sizeof(int));
    if(!revision_history_limit_local_var)
    {
        goto end;
    }
    *revision_history_limit_local_var = revision_history_limit->valuedouble;
    }

    // v1_stateful_set_spec->selector
    cJSON *selector = cJSON_GetObjectItemCaseSensitive(v1_stateful_set_specJSON, "selector");
    if (cJSON_IsNull(selector)) {
        selector = NULL;
    }
    if (!selector) {
        goto end;
    }

    
    selector_local_nonprim = v1_label_selector_parseFromJSON(selector); //nonprimitive

    // v1_stateful_set_spec->service_name
    cJSON *service_name = cJSON_GetObjectItemCaseSensitive(v1_stateful_set_specJSON, "serviceName");
    if (cJSON_IsNull(service_name)) {
        service_name = NULL;
    }
    if (service_name) { 
    if(!cJSON_IsString(service_name) && !cJSON_IsNull(service_name))
    {
    goto end; //String
    }
    }

    // v1_stateful_set_spec->_template
    cJSON *_template = cJSON_GetObjectItemCaseSensitive(v1_stateful_set_specJSON, "template");
    if (cJSON_IsNull(_template)) {
        _template = NULL;
    }
    if (!_template) {
        goto end;
    }

    
    _template_local_nonprim = v1_pod_template_spec_parseFromJSON(_template); //nonprimitive

    // v1_stateful_set_spec->update_strategy
    cJSON *update_strategy = cJSON_GetObjectItemCaseSensitive(v1_stateful_set_specJSON, "updateStrategy");
    if (cJSON_IsNull(update_strategy)) {
        update_strategy = NULL;
    }
    if (update_strategy) { 
    update_strategy_local_nonprim = v1_stateful_set_update_strategy_parseFromJSON(update_strategy); //nonprimitive
    }

    // v1_stateful_set_spec->volume_claim_templates
    cJSON *volume_claim_templates = cJSON_GetObjectItemCaseSensitive(v1_stateful_set_specJSON, "volumeClaimTemplates");
    if (cJSON_IsNull(volume_claim_templates)) {
        volume_claim_templates = NULL;
    }
    if (volume_claim_templates) { 
    cJSON *volume_claim_templates_local_nonprimitive = NULL;
    if(!cJSON_IsArray(volume_claim_templates)){
        goto end; //nonprimitive container
    }

    volume_claim_templatesList = list_createList();

    cJSON_ArrayForEach(volume_claim_templates_local_nonprimitive,volume_claim_templates )
    {
        if(!cJSON_IsObject(volume_claim_templates_local_nonprimitive)){
            goto end;
        }
        v1_persistent_volume_claim_t *volume_claim_templatesItem = v1_persistent_volume_claim_parseFromJSON(volume_claim_templates_local_nonprimitive);

        list_addElement(volume_claim_templatesList, volume_claim_templatesItem);
    }
    }


    if (pod_management_policy && !cJSON_IsNull(pod_management_policy)) pod_management_policy_local_str = strdup(pod_management_policy->valuestring);
    if (service_name && !cJSON_IsNull(service_name)) service_name_local_str = strdup(service_name->valuestring);

    v1_stateful_set_spec_local_var = v1_stateful_set_spec_create_internal (
        min_ready_seconds_local_var,
        ordinals ? ordinals_local_nonprim : NULL,
        persistent_volume_claim_retention_policy ? persistent_volume_claim_retention_policy_local_nonprim : NULL,
        pod_management_policy_local_str,
        replicas_local_var,
        revision_history_limit_local_var,
        selector_local_nonprim,
        service_name_local_str,
        _template_local_nonprim,
        update_strategy ? update_strategy_local_nonprim : NULL,
        volume_claim_templates ? volume_claim_templatesList : NULL
        );

    if (!v1_stateful_set_spec_local_var) {
        goto end;
    }

    return v1_stateful_set_spec_local_var;
end:
    if (min_ready_seconds_local_var) {
        free(min_ready_seconds_local_var);
        min_ready_seconds_local_var = NULL;
    }
    if (ordinals_local_nonprim) {
        v1_stateful_set_ordinals_free(ordinals_local_nonprim);
        ordinals_local_nonprim = NULL;
    }
    if (persistent_volume_claim_retention_policy_local_nonprim) {
        v1_stateful_set_persistent_volume_claim_retention_policy_free(persistent_volume_claim_retention_policy_local_nonprim);
        persistent_volume_claim_retention_policy_local_nonprim = NULL;
    }
    if (pod_management_policy_local_str) {
        free(pod_management_policy_local_str);
        pod_management_policy_local_str = NULL;
    }
    if (replicas_local_var) {
        free(replicas_local_var);
        replicas_local_var = NULL;
    }
    if (revision_history_limit_local_var) {
        free(revision_history_limit_local_var);
        revision_history_limit_local_var = NULL;
    }
    if (selector_local_nonprim) {
        v1_label_selector_free(selector_local_nonprim);
        selector_local_nonprim = NULL;
    }
    if (service_name_local_str) {
        free(service_name_local_str);
        service_name_local_str = NULL;
    }
    if (_template_local_nonprim) {
        v1_pod_template_spec_free(_template_local_nonprim);
        _template_local_nonprim = NULL;
    }
    if (update_strategy_local_nonprim) {
        v1_stateful_set_update_strategy_free(update_strategy_local_nonprim);
        update_strategy_local_nonprim = NULL;
    }
    if (volume_claim_templatesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, volume_claim_templatesList) {
            v1_persistent_volume_claim_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(volume_claim_templatesList);
        volume_claim_templatesList = NULL;
    }
    return NULL;

}
