#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_deployment_spec.h"



static v1_deployment_spec_t *v1_deployment_spec_create_internal(
    int min_ready_seconds,
    int paused,
    int progress_deadline_seconds,
    int replicas,
    int revision_history_limit,
    v1_label_selector_t *selector,
    v1_deployment_strategy_t *strategy,
    v1_pod_template_spec_t *_template
    ) {
    v1_deployment_spec_t *v1_deployment_spec_local_var = malloc(sizeof(v1_deployment_spec_t));
    if (!v1_deployment_spec_local_var) {
        return NULL;
    }
    v1_deployment_spec_local_var->min_ready_seconds = min_ready_seconds;
    v1_deployment_spec_local_var->paused = paused;
    v1_deployment_spec_local_var->progress_deadline_seconds = progress_deadline_seconds;
    v1_deployment_spec_local_var->replicas = replicas;
    v1_deployment_spec_local_var->revision_history_limit = revision_history_limit;
    v1_deployment_spec_local_var->selector = selector;
    v1_deployment_spec_local_var->strategy = strategy;
    v1_deployment_spec_local_var->_template = _template;

    v1_deployment_spec_local_var->_library_owned = 1;
    return v1_deployment_spec_local_var;
}

__attribute__((deprecated)) v1_deployment_spec_t *v1_deployment_spec_create(
    int min_ready_seconds,
    int paused,
    int progress_deadline_seconds,
    int replicas,
    int revision_history_limit,
    v1_label_selector_t *selector,
    v1_deployment_strategy_t *strategy,
    v1_pod_template_spec_t *_template
    ) {
    return v1_deployment_spec_create_internal (
        min_ready_seconds,
        paused,
        progress_deadline_seconds,
        replicas,
        revision_history_limit,
        selector,
        strategy,
        _template
        );
}

void v1_deployment_spec_free(v1_deployment_spec_t *v1_deployment_spec) {
    if(NULL == v1_deployment_spec){
        return ;
    }
    if(v1_deployment_spec->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_deployment_spec_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_deployment_spec->selector) {
        v1_label_selector_free(v1_deployment_spec->selector);
        v1_deployment_spec->selector = NULL;
    }
    if (v1_deployment_spec->strategy) {
        v1_deployment_strategy_free(v1_deployment_spec->strategy);
        v1_deployment_spec->strategy = NULL;
    }
    if (v1_deployment_spec->_template) {
        v1_pod_template_spec_free(v1_deployment_spec->_template);
        v1_deployment_spec->_template = NULL;
    }
    free(v1_deployment_spec);
}

cJSON *v1_deployment_spec_convertToJSON(v1_deployment_spec_t *v1_deployment_spec) {
    cJSON *item = cJSON_CreateObject();

    // v1_deployment_spec->min_ready_seconds
    if(v1_deployment_spec->min_ready_seconds) {
    if(cJSON_AddNumberToObject(item, "minReadySeconds", v1_deployment_spec->min_ready_seconds) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_deployment_spec->paused
    if(v1_deployment_spec->paused) {
    if(cJSON_AddBoolToObject(item, "paused", v1_deployment_spec->paused) == NULL) {
    goto fail; //Bool
    }
    }


    // v1_deployment_spec->progress_deadline_seconds
    if(v1_deployment_spec->progress_deadline_seconds) {
    if(cJSON_AddNumberToObject(item, "progressDeadlineSeconds", v1_deployment_spec->progress_deadline_seconds) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_deployment_spec->replicas
    if(v1_deployment_spec->replicas) {
    if(cJSON_AddNumberToObject(item, "replicas", v1_deployment_spec->replicas) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_deployment_spec->revision_history_limit
    if(v1_deployment_spec->revision_history_limit) {
    if(cJSON_AddNumberToObject(item, "revisionHistoryLimit", v1_deployment_spec->revision_history_limit) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_deployment_spec->selector
    if (!v1_deployment_spec->selector) {
        goto fail;
    }
    cJSON *selector_local_JSON = v1_label_selector_convertToJSON(v1_deployment_spec->selector);
    if(selector_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "selector", selector_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // v1_deployment_spec->strategy
    if(v1_deployment_spec->strategy) {
    cJSON *strategy_local_JSON = v1_deployment_strategy_convertToJSON(v1_deployment_spec->strategy);
    if(strategy_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "strategy", strategy_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_deployment_spec->_template
    if (!v1_deployment_spec->_template) {
        goto fail;
    }
    cJSON *_template_local_JSON = v1_pod_template_spec_convertToJSON(v1_deployment_spec->_template);
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

v1_deployment_spec_t *v1_deployment_spec_parseFromJSON(cJSON *v1_deployment_specJSON){

    v1_deployment_spec_t *v1_deployment_spec_local_var = NULL;

    // define the local variable for v1_deployment_spec->selector
    v1_label_selector_t *selector_local_nonprim = NULL;

    // define the local variable for v1_deployment_spec->strategy
    v1_deployment_strategy_t *strategy_local_nonprim = NULL;

    // define the local variable for v1_deployment_spec->_template
    v1_pod_template_spec_t *_template_local_nonprim = NULL;

    // v1_deployment_spec->min_ready_seconds
    cJSON *min_ready_seconds = cJSON_GetObjectItemCaseSensitive(v1_deployment_specJSON, "minReadySeconds");
    if (cJSON_IsNull(min_ready_seconds)) {
        min_ready_seconds = NULL;
    }
    if (min_ready_seconds) { 
    if(!cJSON_IsNumber(min_ready_seconds))
    {
    goto end; //Numeric
    }
    }

    // v1_deployment_spec->paused
    cJSON *paused = cJSON_GetObjectItemCaseSensitive(v1_deployment_specJSON, "paused");
    if (cJSON_IsNull(paused)) {
        paused = NULL;
    }
    if (paused) { 
    if(!cJSON_IsBool(paused))
    {
    goto end; //Bool
    }
    }

    // v1_deployment_spec->progress_deadline_seconds
    cJSON *progress_deadline_seconds = cJSON_GetObjectItemCaseSensitive(v1_deployment_specJSON, "progressDeadlineSeconds");
    if (cJSON_IsNull(progress_deadline_seconds)) {
        progress_deadline_seconds = NULL;
    }
    if (progress_deadline_seconds) { 
    if(!cJSON_IsNumber(progress_deadline_seconds))
    {
    goto end; //Numeric
    }
    }

    // v1_deployment_spec->replicas
    cJSON *replicas = cJSON_GetObjectItemCaseSensitive(v1_deployment_specJSON, "replicas");
    if (cJSON_IsNull(replicas)) {
        replicas = NULL;
    }
    if (replicas) { 
    if(!cJSON_IsNumber(replicas))
    {
    goto end; //Numeric
    }
    }

    // v1_deployment_spec->revision_history_limit
    cJSON *revision_history_limit = cJSON_GetObjectItemCaseSensitive(v1_deployment_specJSON, "revisionHistoryLimit");
    if (cJSON_IsNull(revision_history_limit)) {
        revision_history_limit = NULL;
    }
    if (revision_history_limit) { 
    if(!cJSON_IsNumber(revision_history_limit))
    {
    goto end; //Numeric
    }
    }

    // v1_deployment_spec->selector
    cJSON *selector = cJSON_GetObjectItemCaseSensitive(v1_deployment_specJSON, "selector");
    if (cJSON_IsNull(selector)) {
        selector = NULL;
    }
    if (!selector) {
        goto end;
    }

    
    selector_local_nonprim = v1_label_selector_parseFromJSON(selector); //nonprimitive

    // v1_deployment_spec->strategy
    cJSON *strategy = cJSON_GetObjectItemCaseSensitive(v1_deployment_specJSON, "strategy");
    if (cJSON_IsNull(strategy)) {
        strategy = NULL;
    }
    if (strategy) { 
    strategy_local_nonprim = v1_deployment_strategy_parseFromJSON(strategy); //nonprimitive
    }

    // v1_deployment_spec->_template
    cJSON *_template = cJSON_GetObjectItemCaseSensitive(v1_deployment_specJSON, "template");
    if (cJSON_IsNull(_template)) {
        _template = NULL;
    }
    if (!_template) {
        goto end;
    }

    
    _template_local_nonprim = v1_pod_template_spec_parseFromJSON(_template); //nonprimitive


    v1_deployment_spec_local_var = v1_deployment_spec_create_internal (
        min_ready_seconds ? min_ready_seconds->valuedouble : 0,
        paused ? paused->valueint : 0,
        progress_deadline_seconds ? progress_deadline_seconds->valuedouble : 0,
        replicas ? replicas->valuedouble : 0,
        revision_history_limit ? revision_history_limit->valuedouble : 0,
        selector_local_nonprim,
        strategy ? strategy_local_nonprim : NULL,
        _template_local_nonprim
        );

    return v1_deployment_spec_local_var;
end:
    if (selector_local_nonprim) {
        v1_label_selector_free(selector_local_nonprim);
        selector_local_nonprim = NULL;
    }
    if (strategy_local_nonprim) {
        v1_deployment_strategy_free(strategy_local_nonprim);
        strategy_local_nonprim = NULL;
    }
    if (_template_local_nonprim) {
        v1_pod_template_spec_free(_template_local_nonprim);
        _template_local_nonprim = NULL;
    }
    return NULL;

}
