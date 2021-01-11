#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta2_stateful_set_spec.h"



v1beta2_stateful_set_spec_t *v1beta2_stateful_set_spec_create(
    char *pod_management_policy,
    int replicas,
    int revision_history_limit,
    v1_label_selector_t *selector,
    char *service_name,
    v1_pod_template_spec_t *_template,
    v1beta2_stateful_set_update_strategy_t *update_strategy,
    list_t *volume_claim_templates
    ) {
    v1beta2_stateful_set_spec_t *v1beta2_stateful_set_spec_local_var = malloc(sizeof(v1beta2_stateful_set_spec_t));
    if (!v1beta2_stateful_set_spec_local_var) {
        return NULL;
    }
    v1beta2_stateful_set_spec_local_var->pod_management_policy = pod_management_policy;
    v1beta2_stateful_set_spec_local_var->replicas = replicas;
    v1beta2_stateful_set_spec_local_var->revision_history_limit = revision_history_limit;
    v1beta2_stateful_set_spec_local_var->selector = selector;
    v1beta2_stateful_set_spec_local_var->service_name = service_name;
    v1beta2_stateful_set_spec_local_var->_template = _template;
    v1beta2_stateful_set_spec_local_var->update_strategy = update_strategy;
    v1beta2_stateful_set_spec_local_var->volume_claim_templates = volume_claim_templates;

    return v1beta2_stateful_set_spec_local_var;
}


void v1beta2_stateful_set_spec_free(v1beta2_stateful_set_spec_t *v1beta2_stateful_set_spec) {
    if(NULL == v1beta2_stateful_set_spec){
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta2_stateful_set_spec->pod_management_policy) {
        free(v1beta2_stateful_set_spec->pod_management_policy);
        v1beta2_stateful_set_spec->pod_management_policy = NULL;
    }
    if (v1beta2_stateful_set_spec->selector) {
        v1_label_selector_free(v1beta2_stateful_set_spec->selector);
        v1beta2_stateful_set_spec->selector = NULL;
    }
    if (v1beta2_stateful_set_spec->service_name) {
        free(v1beta2_stateful_set_spec->service_name);
        v1beta2_stateful_set_spec->service_name = NULL;
    }
    if (v1beta2_stateful_set_spec->_template) {
        v1_pod_template_spec_free(v1beta2_stateful_set_spec->_template);
        v1beta2_stateful_set_spec->_template = NULL;
    }
    if (v1beta2_stateful_set_spec->update_strategy) {
        v1beta2_stateful_set_update_strategy_free(v1beta2_stateful_set_spec->update_strategy);
        v1beta2_stateful_set_spec->update_strategy = NULL;
    }
    if (v1beta2_stateful_set_spec->volume_claim_templates) {
        list_ForEach(listEntry, v1beta2_stateful_set_spec->volume_claim_templates) {
            v1_persistent_volume_claim_free(listEntry->data);
        }
        list_free(v1beta2_stateful_set_spec->volume_claim_templates);
        v1beta2_stateful_set_spec->volume_claim_templates = NULL;
    }
    free(v1beta2_stateful_set_spec);
}

cJSON *v1beta2_stateful_set_spec_convertToJSON(v1beta2_stateful_set_spec_t *v1beta2_stateful_set_spec) {
    cJSON *item = cJSON_CreateObject();

    // v1beta2_stateful_set_spec->pod_management_policy
    if(v1beta2_stateful_set_spec->pod_management_policy) { 
    if(cJSON_AddStringToObject(item, "podManagementPolicy", v1beta2_stateful_set_spec->pod_management_policy) == NULL) {
    goto fail; //String
    }
     } 


    // v1beta2_stateful_set_spec->replicas
    if(v1beta2_stateful_set_spec->replicas) { 
    if(cJSON_AddNumberToObject(item, "replicas", v1beta2_stateful_set_spec->replicas) == NULL) {
    goto fail; //Numeric
    }
     } 


    // v1beta2_stateful_set_spec->revision_history_limit
    if(v1beta2_stateful_set_spec->revision_history_limit) { 
    if(cJSON_AddNumberToObject(item, "revisionHistoryLimit", v1beta2_stateful_set_spec->revision_history_limit) == NULL) {
    goto fail; //Numeric
    }
     } 


    // v1beta2_stateful_set_spec->selector
    if (!v1beta2_stateful_set_spec->selector) {
        goto fail;
    }
    
    cJSON *selector_local_JSON = v1_label_selector_convertToJSON(v1beta2_stateful_set_spec->selector);
    if(selector_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "selector", selector_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // v1beta2_stateful_set_spec->service_name
    if (!v1beta2_stateful_set_spec->service_name) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "serviceName", v1beta2_stateful_set_spec->service_name) == NULL) {
    goto fail; //String
    }


    // v1beta2_stateful_set_spec->_template
    if (!v1beta2_stateful_set_spec->_template) {
        goto fail;
    }
    
    cJSON *_template_local_JSON = v1_pod_template_spec_convertToJSON(v1beta2_stateful_set_spec->_template);
    if(_template_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "template", _template_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // v1beta2_stateful_set_spec->update_strategy
    if(v1beta2_stateful_set_spec->update_strategy) { 
    cJSON *update_strategy_local_JSON = v1beta2_stateful_set_update_strategy_convertToJSON(v1beta2_stateful_set_spec->update_strategy);
    if(update_strategy_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "updateStrategy", update_strategy_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1beta2_stateful_set_spec->volume_claim_templates
    if(v1beta2_stateful_set_spec->volume_claim_templates) { 
    cJSON *volume_claim_templates = cJSON_AddArrayToObject(item, "volumeClaimTemplates");
    if(volume_claim_templates == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *volume_claim_templatesListEntry;
    if (v1beta2_stateful_set_spec->volume_claim_templates) {
    list_ForEach(volume_claim_templatesListEntry, v1beta2_stateful_set_spec->volume_claim_templates) {
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

v1beta2_stateful_set_spec_t *v1beta2_stateful_set_spec_parseFromJSON(cJSON *v1beta2_stateful_set_specJSON){

    v1beta2_stateful_set_spec_t *v1beta2_stateful_set_spec_local_var = NULL;

    // v1beta2_stateful_set_spec->pod_management_policy
    cJSON *pod_management_policy = cJSON_GetObjectItemCaseSensitive(v1beta2_stateful_set_specJSON, "podManagementPolicy");
    if (pod_management_policy) { 
    if(!cJSON_IsString(pod_management_policy))
    {
    goto end; //String
    }
    }

    // v1beta2_stateful_set_spec->replicas
    cJSON *replicas = cJSON_GetObjectItemCaseSensitive(v1beta2_stateful_set_specJSON, "replicas");
    if (replicas) { 
    if(!cJSON_IsNumber(replicas))
    {
    goto end; //Numeric
    }
    }

    // v1beta2_stateful_set_spec->revision_history_limit
    cJSON *revision_history_limit = cJSON_GetObjectItemCaseSensitive(v1beta2_stateful_set_specJSON, "revisionHistoryLimit");
    if (revision_history_limit) { 
    if(!cJSON_IsNumber(revision_history_limit))
    {
    goto end; //Numeric
    }
    }

    // v1beta2_stateful_set_spec->selector
    cJSON *selector = cJSON_GetObjectItemCaseSensitive(v1beta2_stateful_set_specJSON, "selector");
    if (!selector) {
        goto end;
    }

    v1_label_selector_t *selector_local_nonprim = NULL;
    
    selector_local_nonprim = v1_label_selector_parseFromJSON(selector); //nonprimitive

    // v1beta2_stateful_set_spec->service_name
    cJSON *service_name = cJSON_GetObjectItemCaseSensitive(v1beta2_stateful_set_specJSON, "serviceName");
    if (!service_name) {
        goto end;
    }

    
    if(!cJSON_IsString(service_name))
    {
    goto end; //String
    }

    // v1beta2_stateful_set_spec->_template
    cJSON *_template = cJSON_GetObjectItemCaseSensitive(v1beta2_stateful_set_specJSON, "template");
    if (!_template) {
        goto end;
    }

    v1_pod_template_spec_t *_template_local_nonprim = NULL;
    
    _template_local_nonprim = v1_pod_template_spec_parseFromJSON(_template); //nonprimitive

    // v1beta2_stateful_set_spec->update_strategy
    cJSON *update_strategy = cJSON_GetObjectItemCaseSensitive(v1beta2_stateful_set_specJSON, "updateStrategy");
    v1beta2_stateful_set_update_strategy_t *update_strategy_local_nonprim = NULL;
    if (update_strategy) { 
    update_strategy_local_nonprim = v1beta2_stateful_set_update_strategy_parseFromJSON(update_strategy); //nonprimitive
    }

    // v1beta2_stateful_set_spec->volume_claim_templates
    cJSON *volume_claim_templates = cJSON_GetObjectItemCaseSensitive(v1beta2_stateful_set_specJSON, "volumeClaimTemplates");
    list_t *volume_claim_templatesList;
    if (volume_claim_templates) { 
    cJSON *volume_claim_templates_local_nonprimitive;
    if(!cJSON_IsArray(volume_claim_templates)){
        goto end; //nonprimitive container
    }

    volume_claim_templatesList = list_create();

    cJSON_ArrayForEach(volume_claim_templates_local_nonprimitive,volume_claim_templates )
    {
        if(!cJSON_IsObject(volume_claim_templates_local_nonprimitive)){
            goto end;
        }
        v1_persistent_volume_claim_t *volume_claim_templatesItem = v1_persistent_volume_claim_parseFromJSON(volume_claim_templates_local_nonprimitive);

        list_addElement(volume_claim_templatesList, volume_claim_templatesItem);
    }
    }


    v1beta2_stateful_set_spec_local_var = v1beta2_stateful_set_spec_create (
        pod_management_policy ? strdup(pod_management_policy->valuestring) : NULL,
        replicas ? replicas->valuedouble : 0,
        revision_history_limit ? revision_history_limit->valuedouble : 0,
        selector_local_nonprim,
        strdup(service_name->valuestring),
        _template_local_nonprim,
        update_strategy ? update_strategy_local_nonprim : NULL,
        volume_claim_templates ? volume_claim_templatesList : NULL
        );

    return v1beta2_stateful_set_spec_local_var;
end:
    if (selector_local_nonprim) {
        v1_label_selector_free(selector_local_nonprim);
        selector_local_nonprim = NULL;
    }
    if (_template_local_nonprim) {
        v1_pod_template_spec_free(_template_local_nonprim);
        _template_local_nonprim = NULL;
    }
    if (update_strategy_local_nonprim) {
        v1beta2_stateful_set_update_strategy_free(update_strategy_local_nonprim);
        update_strategy_local_nonprim = NULL;
    }
    return NULL;

}
