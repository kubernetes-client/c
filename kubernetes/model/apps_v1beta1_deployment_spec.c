#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "apps_v1beta1_deployment_spec.h"



apps_v1beta1_deployment_spec_t *apps_v1beta1_deployment_spec_create(
    int min_ready_seconds,
    int paused,
    int progress_deadline_seconds,
    int replicas,
    int revision_history_limit,
    apps_v1beta1_rollback_config_t *rollback_to,
    v1_label_selector_t *selector,
    apps_v1beta1_deployment_strategy_t *strategy,
    v1_pod_template_spec_t *_template
    ) {
    apps_v1beta1_deployment_spec_t *apps_v1beta1_deployment_spec_local_var = malloc(sizeof(apps_v1beta1_deployment_spec_t));
    if (!apps_v1beta1_deployment_spec_local_var) {
        return NULL;
    }
    apps_v1beta1_deployment_spec_local_var->min_ready_seconds = min_ready_seconds;
    apps_v1beta1_deployment_spec_local_var->paused = paused;
    apps_v1beta1_deployment_spec_local_var->progress_deadline_seconds = progress_deadline_seconds;
    apps_v1beta1_deployment_spec_local_var->replicas = replicas;
    apps_v1beta1_deployment_spec_local_var->revision_history_limit = revision_history_limit;
    apps_v1beta1_deployment_spec_local_var->rollback_to = rollback_to;
    apps_v1beta1_deployment_spec_local_var->selector = selector;
    apps_v1beta1_deployment_spec_local_var->strategy = strategy;
    apps_v1beta1_deployment_spec_local_var->_template = _template;

    return apps_v1beta1_deployment_spec_local_var;
}


void apps_v1beta1_deployment_spec_free(apps_v1beta1_deployment_spec_t *apps_v1beta1_deployment_spec) {
    if(NULL == apps_v1beta1_deployment_spec){
        return ;
    }
    listEntry_t *listEntry;
    if (apps_v1beta1_deployment_spec->rollback_to) {
        apps_v1beta1_rollback_config_free(apps_v1beta1_deployment_spec->rollback_to);
        apps_v1beta1_deployment_spec->rollback_to = NULL;
    }
    if (apps_v1beta1_deployment_spec->selector) {
        v1_label_selector_free(apps_v1beta1_deployment_spec->selector);
        apps_v1beta1_deployment_spec->selector = NULL;
    }
    if (apps_v1beta1_deployment_spec->strategy) {
        apps_v1beta1_deployment_strategy_free(apps_v1beta1_deployment_spec->strategy);
        apps_v1beta1_deployment_spec->strategy = NULL;
    }
    if (apps_v1beta1_deployment_spec->_template) {
        v1_pod_template_spec_free(apps_v1beta1_deployment_spec->_template);
        apps_v1beta1_deployment_spec->_template = NULL;
    }
    free(apps_v1beta1_deployment_spec);
}

cJSON *apps_v1beta1_deployment_spec_convertToJSON(apps_v1beta1_deployment_spec_t *apps_v1beta1_deployment_spec) {
    cJSON *item = cJSON_CreateObject();

    // apps_v1beta1_deployment_spec->min_ready_seconds
    if(apps_v1beta1_deployment_spec->min_ready_seconds) { 
    if(cJSON_AddNumberToObject(item, "minReadySeconds", apps_v1beta1_deployment_spec->min_ready_seconds) == NULL) {
    goto fail; //Numeric
    }
     } 


    // apps_v1beta1_deployment_spec->paused
    if(apps_v1beta1_deployment_spec->paused) { 
    if(cJSON_AddBoolToObject(item, "paused", apps_v1beta1_deployment_spec->paused) == NULL) {
    goto fail; //Bool
    }
     } 


    // apps_v1beta1_deployment_spec->progress_deadline_seconds
    if(apps_v1beta1_deployment_spec->progress_deadline_seconds) { 
    if(cJSON_AddNumberToObject(item, "progressDeadlineSeconds", apps_v1beta1_deployment_spec->progress_deadline_seconds) == NULL) {
    goto fail; //Numeric
    }
     } 


    // apps_v1beta1_deployment_spec->replicas
    if(apps_v1beta1_deployment_spec->replicas) { 
    if(cJSON_AddNumberToObject(item, "replicas", apps_v1beta1_deployment_spec->replicas) == NULL) {
    goto fail; //Numeric
    }
     } 


    // apps_v1beta1_deployment_spec->revision_history_limit
    if(apps_v1beta1_deployment_spec->revision_history_limit) { 
    if(cJSON_AddNumberToObject(item, "revisionHistoryLimit", apps_v1beta1_deployment_spec->revision_history_limit) == NULL) {
    goto fail; //Numeric
    }
     } 


    // apps_v1beta1_deployment_spec->rollback_to
    if(apps_v1beta1_deployment_spec->rollback_to) { 
    cJSON *rollback_to_local_JSON = apps_v1beta1_rollback_config_convertToJSON(apps_v1beta1_deployment_spec->rollback_to);
    if(rollback_to_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "rollbackTo", rollback_to_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // apps_v1beta1_deployment_spec->selector
    if(apps_v1beta1_deployment_spec->selector) { 
    cJSON *selector_local_JSON = v1_label_selector_convertToJSON(apps_v1beta1_deployment_spec->selector);
    if(selector_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "selector", selector_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // apps_v1beta1_deployment_spec->strategy
    if(apps_v1beta1_deployment_spec->strategy) { 
    cJSON *strategy_local_JSON = apps_v1beta1_deployment_strategy_convertToJSON(apps_v1beta1_deployment_spec->strategy);
    if(strategy_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "strategy", strategy_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // apps_v1beta1_deployment_spec->_template
    if (!apps_v1beta1_deployment_spec->_template) {
        goto fail;
    }
    
    cJSON *_template_local_JSON = v1_pod_template_spec_convertToJSON(apps_v1beta1_deployment_spec->_template);
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

apps_v1beta1_deployment_spec_t *apps_v1beta1_deployment_spec_parseFromJSON(cJSON *apps_v1beta1_deployment_specJSON){

    apps_v1beta1_deployment_spec_t *apps_v1beta1_deployment_spec_local_var = NULL;

    // apps_v1beta1_deployment_spec->min_ready_seconds
    cJSON *min_ready_seconds = cJSON_GetObjectItemCaseSensitive(apps_v1beta1_deployment_specJSON, "minReadySeconds");
    if (min_ready_seconds) { 
    if(!cJSON_IsNumber(min_ready_seconds))
    {
    goto end; //Numeric
    }
    }

    // apps_v1beta1_deployment_spec->paused
    cJSON *paused = cJSON_GetObjectItemCaseSensitive(apps_v1beta1_deployment_specJSON, "paused");
    if (paused) { 
    if(!cJSON_IsBool(paused))
    {
    goto end; //Bool
    }
    }

    // apps_v1beta1_deployment_spec->progress_deadline_seconds
    cJSON *progress_deadline_seconds = cJSON_GetObjectItemCaseSensitive(apps_v1beta1_deployment_specJSON, "progressDeadlineSeconds");
    if (progress_deadline_seconds) { 
    if(!cJSON_IsNumber(progress_deadline_seconds))
    {
    goto end; //Numeric
    }
    }

    // apps_v1beta1_deployment_spec->replicas
    cJSON *replicas = cJSON_GetObjectItemCaseSensitive(apps_v1beta1_deployment_specJSON, "replicas");
    if (replicas) { 
    if(!cJSON_IsNumber(replicas))
    {
    goto end; //Numeric
    }
    }

    // apps_v1beta1_deployment_spec->revision_history_limit
    cJSON *revision_history_limit = cJSON_GetObjectItemCaseSensitive(apps_v1beta1_deployment_specJSON, "revisionHistoryLimit");
    if (revision_history_limit) { 
    if(!cJSON_IsNumber(revision_history_limit))
    {
    goto end; //Numeric
    }
    }

    // apps_v1beta1_deployment_spec->rollback_to
    cJSON *rollback_to = cJSON_GetObjectItemCaseSensitive(apps_v1beta1_deployment_specJSON, "rollbackTo");
    apps_v1beta1_rollback_config_t *rollback_to_local_nonprim = NULL;
    if (rollback_to) { 
    rollback_to_local_nonprim = apps_v1beta1_rollback_config_parseFromJSON(rollback_to); //nonprimitive
    }

    // apps_v1beta1_deployment_spec->selector
    cJSON *selector = cJSON_GetObjectItemCaseSensitive(apps_v1beta1_deployment_specJSON, "selector");
    v1_label_selector_t *selector_local_nonprim = NULL;
    if (selector) { 
    selector_local_nonprim = v1_label_selector_parseFromJSON(selector); //nonprimitive
    }

    // apps_v1beta1_deployment_spec->strategy
    cJSON *strategy = cJSON_GetObjectItemCaseSensitive(apps_v1beta1_deployment_specJSON, "strategy");
    apps_v1beta1_deployment_strategy_t *strategy_local_nonprim = NULL;
    if (strategy) { 
    strategy_local_nonprim = apps_v1beta1_deployment_strategy_parseFromJSON(strategy); //nonprimitive
    }

    // apps_v1beta1_deployment_spec->_template
    cJSON *_template = cJSON_GetObjectItemCaseSensitive(apps_v1beta1_deployment_specJSON, "template");
    if (!_template) {
        goto end;
    }

    v1_pod_template_spec_t *_template_local_nonprim = NULL;
    
    _template_local_nonprim = v1_pod_template_spec_parseFromJSON(_template); //nonprimitive


    apps_v1beta1_deployment_spec_local_var = apps_v1beta1_deployment_spec_create (
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

    return apps_v1beta1_deployment_spec_local_var;
end:
    if (rollback_to_local_nonprim) {
        apps_v1beta1_rollback_config_free(rollback_to_local_nonprim);
        rollback_to_local_nonprim = NULL;
    }
    if (selector_local_nonprim) {
        v1_label_selector_free(selector_local_nonprim);
        selector_local_nonprim = NULL;
    }
    if (strategy_local_nonprim) {
        apps_v1beta1_deployment_strategy_free(strategy_local_nonprim);
        strategy_local_nonprim = NULL;
    }
    if (_template_local_nonprim) {
        v1_pod_template_spec_free(_template_local_nonprim);
        _template_local_nonprim = NULL;
    }
    return NULL;

}
