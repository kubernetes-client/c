#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta2_deployment_spec.h"



v1beta2_deployment_spec_t *v1beta2_deployment_spec_create(
    int min_ready_seconds,
    int paused,
    int progress_deadline_seconds,
    int replicas,
    int revision_history_limit,
    v1_label_selector_t *selector,
    v1beta2_deployment_strategy_t *strategy,
    v1_pod_template_spec_t *_template
    ) {
    v1beta2_deployment_spec_t *v1beta2_deployment_spec_local_var = malloc(sizeof(v1beta2_deployment_spec_t));
    if (!v1beta2_deployment_spec_local_var) {
        return NULL;
    }
    v1beta2_deployment_spec_local_var->min_ready_seconds = min_ready_seconds;
    v1beta2_deployment_spec_local_var->paused = paused;
    v1beta2_deployment_spec_local_var->progress_deadline_seconds = progress_deadline_seconds;
    v1beta2_deployment_spec_local_var->replicas = replicas;
    v1beta2_deployment_spec_local_var->revision_history_limit = revision_history_limit;
    v1beta2_deployment_spec_local_var->selector = selector;
    v1beta2_deployment_spec_local_var->strategy = strategy;
    v1beta2_deployment_spec_local_var->_template = _template;

    return v1beta2_deployment_spec_local_var;
}


void v1beta2_deployment_spec_free(v1beta2_deployment_spec_t *v1beta2_deployment_spec) {
    if(NULL == v1beta2_deployment_spec){
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta2_deployment_spec->selector) {
        v1_label_selector_free(v1beta2_deployment_spec->selector);
        v1beta2_deployment_spec->selector = NULL;
    }
    if (v1beta2_deployment_spec->strategy) {
        v1beta2_deployment_strategy_free(v1beta2_deployment_spec->strategy);
        v1beta2_deployment_spec->strategy = NULL;
    }
    if (v1beta2_deployment_spec->_template) {
        v1_pod_template_spec_free(v1beta2_deployment_spec->_template);
        v1beta2_deployment_spec->_template = NULL;
    }
    free(v1beta2_deployment_spec);
}

cJSON *v1beta2_deployment_spec_convertToJSON(v1beta2_deployment_spec_t *v1beta2_deployment_spec) {
    cJSON *item = cJSON_CreateObject();

    // v1beta2_deployment_spec->min_ready_seconds
    if(v1beta2_deployment_spec->min_ready_seconds) { 
    if(cJSON_AddNumberToObject(item, "minReadySeconds", v1beta2_deployment_spec->min_ready_seconds) == NULL) {
    goto fail; //Numeric
    }
     } 


    // v1beta2_deployment_spec->paused
    if(v1beta2_deployment_spec->paused) { 
    if(cJSON_AddBoolToObject(item, "paused", v1beta2_deployment_spec->paused) == NULL) {
    goto fail; //Bool
    }
     } 


    // v1beta2_deployment_spec->progress_deadline_seconds
    if(v1beta2_deployment_spec->progress_deadline_seconds) { 
    if(cJSON_AddNumberToObject(item, "progressDeadlineSeconds", v1beta2_deployment_spec->progress_deadline_seconds) == NULL) {
    goto fail; //Numeric
    }
     } 


    // v1beta2_deployment_spec->replicas
    if(v1beta2_deployment_spec->replicas) { 
    if(cJSON_AddNumberToObject(item, "replicas", v1beta2_deployment_spec->replicas) == NULL) {
    goto fail; //Numeric
    }
     } 


    // v1beta2_deployment_spec->revision_history_limit
    if(v1beta2_deployment_spec->revision_history_limit) { 
    if(cJSON_AddNumberToObject(item, "revisionHistoryLimit", v1beta2_deployment_spec->revision_history_limit) == NULL) {
    goto fail; //Numeric
    }
     } 


    // v1beta2_deployment_spec->selector
    if (!v1beta2_deployment_spec->selector) {
        goto fail;
    }
    
    cJSON *selector_local_JSON = v1_label_selector_convertToJSON(v1beta2_deployment_spec->selector);
    if(selector_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "selector", selector_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // v1beta2_deployment_spec->strategy
    if(v1beta2_deployment_spec->strategy) { 
    cJSON *strategy_local_JSON = v1beta2_deployment_strategy_convertToJSON(v1beta2_deployment_spec->strategy);
    if(strategy_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "strategy", strategy_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1beta2_deployment_spec->_template
    if (!v1beta2_deployment_spec->_template) {
        goto fail;
    }
    
    cJSON *_template_local_JSON = v1_pod_template_spec_convertToJSON(v1beta2_deployment_spec->_template);
    if(_template_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "template", _template_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1beta2_deployment_spec_t *v1beta2_deployment_spec_parseFromJSON(cJSON *v1beta2_deployment_specJSON){

    v1beta2_deployment_spec_t *v1beta2_deployment_spec_local_var = NULL;

    // v1beta2_deployment_spec->min_ready_seconds
    cJSON *min_ready_seconds = cJSON_GetObjectItemCaseSensitive(v1beta2_deployment_specJSON, "minReadySeconds");
    if (min_ready_seconds) { 
    if(!cJSON_IsNumber(min_ready_seconds))
    {
    goto end; //Numeric
    }
    }

    // v1beta2_deployment_spec->paused
    cJSON *paused = cJSON_GetObjectItemCaseSensitive(v1beta2_deployment_specJSON, "paused");
    if (paused) { 
    if(!cJSON_IsBool(paused))
    {
    goto end; //Bool
    }
    }

    // v1beta2_deployment_spec->progress_deadline_seconds
    cJSON *progress_deadline_seconds = cJSON_GetObjectItemCaseSensitive(v1beta2_deployment_specJSON, "progressDeadlineSeconds");
    if (progress_deadline_seconds) { 
    if(!cJSON_IsNumber(progress_deadline_seconds))
    {
    goto end; //Numeric
    }
    }

    // v1beta2_deployment_spec->replicas
    cJSON *replicas = cJSON_GetObjectItemCaseSensitive(v1beta2_deployment_specJSON, "replicas");
    if (replicas) { 
    if(!cJSON_IsNumber(replicas))
    {
    goto end; //Numeric
    }
    }

    // v1beta2_deployment_spec->revision_history_limit
    cJSON *revision_history_limit = cJSON_GetObjectItemCaseSensitive(v1beta2_deployment_specJSON, "revisionHistoryLimit");
    if (revision_history_limit) { 
    if(!cJSON_IsNumber(revision_history_limit))
    {
    goto end; //Numeric
    }
    }

    // v1beta2_deployment_spec->selector
    cJSON *selector = cJSON_GetObjectItemCaseSensitive(v1beta2_deployment_specJSON, "selector");
    if (!selector) {
        goto end;
    }

    v1_label_selector_t *selector_local_nonprim = NULL;
    
    selector_local_nonprim = v1_label_selector_parseFromJSON(selector); //nonprimitive

    // v1beta2_deployment_spec->strategy
    cJSON *strategy = cJSON_GetObjectItemCaseSensitive(v1beta2_deployment_specJSON, "strategy");
    v1beta2_deployment_strategy_t *strategy_local_nonprim = NULL;
    if (strategy) { 
    strategy_local_nonprim = v1beta2_deployment_strategy_parseFromJSON(strategy); //nonprimitive
    }

    // v1beta2_deployment_spec->_template
    cJSON *_template = cJSON_GetObjectItemCaseSensitive(v1beta2_deployment_specJSON, "template");
    if (!_template) {
        goto end;
    }

    v1_pod_template_spec_t *_template_local_nonprim = NULL;
    
    _template_local_nonprim = v1_pod_template_spec_parseFromJSON(_template); //nonprimitive


    v1beta2_deployment_spec_local_var = v1beta2_deployment_spec_create (
        min_ready_seconds ? min_ready_seconds->valuedouble : 0,
        paused ? paused->valueint : 0,
        progress_deadline_seconds ? progress_deadline_seconds->valuedouble : 0,
        replicas ? replicas->valuedouble : 0,
        revision_history_limit ? revision_history_limit->valuedouble : 0,
        selector_local_nonprim,
        strategy ? strategy_local_nonprim : NULL,
        _template_local_nonprim
        );

    return v1beta2_deployment_spec_local_var;
end:
    if (selector_local_nonprim) {
        v1_label_selector_free(selector_local_nonprim);
        selector_local_nonprim = NULL;
    }
    if (strategy_local_nonprim) {
        v1beta2_deployment_strategy_free(strategy_local_nonprim);
        strategy_local_nonprim = NULL;
    }
    if (_template_local_nonprim) {
        v1_pod_template_spec_free(_template_local_nonprim);
        _template_local_nonprim = NULL;
    }
    return NULL;

}
