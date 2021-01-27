#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "extensions_v1beta1_deployment_spec.h"



extensions_v1beta1_deployment_spec_t *extensions_v1beta1_deployment_spec_create(
    int min_ready_seconds,
    int paused,
    int progress_deadline_seconds,
    int replicas,
    int revision_history_limit,
    extensions_v1beta1_rollback_config_t *rollback_to,
    v1_label_selector_t *selector,
    extensions_v1beta1_deployment_strategy_t *strategy,
    v1_pod_template_spec_t *_template
    ) {
    extensions_v1beta1_deployment_spec_t *extensions_v1beta1_deployment_spec_local_var = malloc(sizeof(extensions_v1beta1_deployment_spec_t));
    if (!extensions_v1beta1_deployment_spec_local_var) {
        return NULL;
    }
    extensions_v1beta1_deployment_spec_local_var->min_ready_seconds = min_ready_seconds;
    extensions_v1beta1_deployment_spec_local_var->paused = paused;
    extensions_v1beta1_deployment_spec_local_var->progress_deadline_seconds = progress_deadline_seconds;
    extensions_v1beta1_deployment_spec_local_var->replicas = replicas;
    extensions_v1beta1_deployment_spec_local_var->revision_history_limit = revision_history_limit;
    extensions_v1beta1_deployment_spec_local_var->rollback_to = rollback_to;
    extensions_v1beta1_deployment_spec_local_var->selector = selector;
    extensions_v1beta1_deployment_spec_local_var->strategy = strategy;
    extensions_v1beta1_deployment_spec_local_var->_template = _template;

    return extensions_v1beta1_deployment_spec_local_var;
}


void extensions_v1beta1_deployment_spec_free(extensions_v1beta1_deployment_spec_t *extensions_v1beta1_deployment_spec) {
    if(NULL == extensions_v1beta1_deployment_spec){
        return ;
    }
    listEntry_t *listEntry;
    if (extensions_v1beta1_deployment_spec->rollback_to) {
        extensions_v1beta1_rollback_config_free(extensions_v1beta1_deployment_spec->rollback_to);
        extensions_v1beta1_deployment_spec->rollback_to = NULL;
    }
    if (extensions_v1beta1_deployment_spec->selector) {
        v1_label_selector_free(extensions_v1beta1_deployment_spec->selector);
        extensions_v1beta1_deployment_spec->selector = NULL;
    }
    if (extensions_v1beta1_deployment_spec->strategy) {
        extensions_v1beta1_deployment_strategy_free(extensions_v1beta1_deployment_spec->strategy);
        extensions_v1beta1_deployment_spec->strategy = NULL;
    }
    if (extensions_v1beta1_deployment_spec->_template) {
        v1_pod_template_spec_free(extensions_v1beta1_deployment_spec->_template);
        extensions_v1beta1_deployment_spec->_template = NULL;
    }
    free(extensions_v1beta1_deployment_spec);
}

cJSON *extensions_v1beta1_deployment_spec_convertToJSON(extensions_v1beta1_deployment_spec_t *extensions_v1beta1_deployment_spec) {
    cJSON *item = cJSON_CreateObject();

    // extensions_v1beta1_deployment_spec->min_ready_seconds
    if(extensions_v1beta1_deployment_spec->min_ready_seconds) { 
    if(cJSON_AddNumberToObject(item, "minReadySeconds", extensions_v1beta1_deployment_spec->min_ready_seconds) == NULL) {
    goto fail; //Numeric
    }
     } 


    // extensions_v1beta1_deployment_spec->paused
    if(extensions_v1beta1_deployment_spec->paused) { 
    if(cJSON_AddBoolToObject(item, "paused", extensions_v1beta1_deployment_spec->paused) == NULL) {
    goto fail; //Bool
    }
     } 


    // extensions_v1beta1_deployment_spec->progress_deadline_seconds
    if(extensions_v1beta1_deployment_spec->progress_deadline_seconds) { 
    if(cJSON_AddNumberToObject(item, "progressDeadlineSeconds", extensions_v1beta1_deployment_spec->progress_deadline_seconds) == NULL) {
    goto fail; //Numeric
    }
     } 


    // extensions_v1beta1_deployment_spec->replicas
    if(extensions_v1beta1_deployment_spec->replicas) { 
    if(cJSON_AddNumberToObject(item, "replicas", extensions_v1beta1_deployment_spec->replicas) == NULL) {
    goto fail; //Numeric
    }
     } 


    // extensions_v1beta1_deployment_spec->revision_history_limit
    if(extensions_v1beta1_deployment_spec->revision_history_limit) { 
    if(cJSON_AddNumberToObject(item, "revisionHistoryLimit", extensions_v1beta1_deployment_spec->revision_history_limit) == NULL) {
    goto fail; //Numeric
    }
     } 


    // extensions_v1beta1_deployment_spec->rollback_to
    if(extensions_v1beta1_deployment_spec->rollback_to) { 
    cJSON *rollback_to_local_JSON = extensions_v1beta1_rollback_config_convertToJSON(extensions_v1beta1_deployment_spec->rollback_to);
    if(rollback_to_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "rollbackTo", rollback_to_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // extensions_v1beta1_deployment_spec->selector
    if(extensions_v1beta1_deployment_spec->selector) { 
    cJSON *selector_local_JSON = v1_label_selector_convertToJSON(extensions_v1beta1_deployment_spec->selector);
    if(selector_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "selector", selector_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // extensions_v1beta1_deployment_spec->strategy
    if(extensions_v1beta1_deployment_spec->strategy) { 
    cJSON *strategy_local_JSON = extensions_v1beta1_deployment_strategy_convertToJSON(extensions_v1beta1_deployment_spec->strategy);
    if(strategy_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "strategy", strategy_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // extensions_v1beta1_deployment_spec->_template
    if (!extensions_v1beta1_deployment_spec->_template) {
        goto fail;
    }
    
    cJSON *_template_local_JSON = v1_pod_template_spec_convertToJSON(extensions_v1beta1_deployment_spec->_template);
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

extensions_v1beta1_deployment_spec_t *extensions_v1beta1_deployment_spec_parseFromJSON(cJSON *extensions_v1beta1_deployment_specJSON){

    extensions_v1beta1_deployment_spec_t *extensions_v1beta1_deployment_spec_local_var = NULL;

    // extensions_v1beta1_deployment_spec->min_ready_seconds
    cJSON *min_ready_seconds = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_deployment_specJSON, "minReadySeconds");
    if (min_ready_seconds) { 
    if(!cJSON_IsNumber(min_ready_seconds))
    {
    goto end; //Numeric
    }
    }

    // extensions_v1beta1_deployment_spec->paused
    cJSON *paused = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_deployment_specJSON, "paused");
    if (paused) { 
    if(!cJSON_IsBool(paused))
    {
    goto end; //Bool
    }
    }

    // extensions_v1beta1_deployment_spec->progress_deadline_seconds
    cJSON *progress_deadline_seconds = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_deployment_specJSON, "progressDeadlineSeconds");
    if (progress_deadline_seconds) { 
    if(!cJSON_IsNumber(progress_deadline_seconds))
    {
    goto end; //Numeric
    }
    }

    // extensions_v1beta1_deployment_spec->replicas
    cJSON *replicas = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_deployment_specJSON, "replicas");
    if (replicas) { 
    if(!cJSON_IsNumber(replicas))
    {
    goto end; //Numeric
    }
    }

    // extensions_v1beta1_deployment_spec->revision_history_limit
    cJSON *revision_history_limit = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_deployment_specJSON, "revisionHistoryLimit");
    if (revision_history_limit) { 
    if(!cJSON_IsNumber(revision_history_limit))
    {
    goto end; //Numeric
    }
    }

    // extensions_v1beta1_deployment_spec->rollback_to
    cJSON *rollback_to = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_deployment_specJSON, "rollbackTo");
    extensions_v1beta1_rollback_config_t *rollback_to_local_nonprim = NULL;
    if (rollback_to) { 
    rollback_to_local_nonprim = extensions_v1beta1_rollback_config_parseFromJSON(rollback_to); //nonprimitive
    }

    // extensions_v1beta1_deployment_spec->selector
    cJSON *selector = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_deployment_specJSON, "selector");
    v1_label_selector_t *selector_local_nonprim = NULL;
    if (selector) { 
    selector_local_nonprim = v1_label_selector_parseFromJSON(selector); //nonprimitive
    }

    // extensions_v1beta1_deployment_spec->strategy
    cJSON *strategy = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_deployment_specJSON, "strategy");
    extensions_v1beta1_deployment_strategy_t *strategy_local_nonprim = NULL;
    if (strategy) { 
    strategy_local_nonprim = extensions_v1beta1_deployment_strategy_parseFromJSON(strategy); //nonprimitive
    }

    // extensions_v1beta1_deployment_spec->_template
    cJSON *_template = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_deployment_specJSON, "template");
    if (!_template) {
        goto end;
    }

    v1_pod_template_spec_t *_template_local_nonprim = NULL;
    
    _template_local_nonprim = v1_pod_template_spec_parseFromJSON(_template); //nonprimitive


    extensions_v1beta1_deployment_spec_local_var = extensions_v1beta1_deployment_spec_create (
        min_ready_seconds ? min_ready_seconds->valuedouble : 0,
        paused ? paused->valueint : 0,
        progress_deadline_seconds ? progress_deadline_seconds->valuedouble : 0,
        replicas ? replicas->valuedouble : 0,
        revision_history_limit ? revision_history_limit->valuedouble : 0,
        rollback_to ? rollback_to_local_nonprim : NULL,
        selector ? selector_local_nonprim : NULL,
        strategy ? strategy_local_nonprim : NULL,
        _template_local_nonprim
        );

    return extensions_v1beta1_deployment_spec_local_var;
end:
    if (rollback_to_local_nonprim) {
        extensions_v1beta1_rollback_config_free(rollback_to_local_nonprim);
        rollback_to_local_nonprim = NULL;
    }
    if (selector_local_nonprim) {
        v1_label_selector_free(selector_local_nonprim);
        selector_local_nonprim = NULL;
    }
    if (strategy_local_nonprim) {
        extensions_v1beta1_deployment_strategy_free(strategy_local_nonprim);
        strategy_local_nonprim = NULL;
    }
    if (_template_local_nonprim) {
        v1_pod_template_spec_free(_template_local_nonprim);
        _template_local_nonprim = NULL;
    }
    return NULL;

}
