#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_job_spec.h"



v1_job_spec_t *v1_job_spec_create(
    long active_deadline_seconds,
    int backoff_limit,
    int completions,
    int manual_selector,
    int parallelism,
    v1_label_selector_t *selector,
    v1_pod_template_spec_t *_template,
    int ttl_seconds_after_finished
    ) {
    v1_job_spec_t *v1_job_spec_local_var = malloc(sizeof(v1_job_spec_t));
    if (!v1_job_spec_local_var) {
        return NULL;
    }
    v1_job_spec_local_var->active_deadline_seconds = active_deadline_seconds;
    v1_job_spec_local_var->backoff_limit = backoff_limit;
    v1_job_spec_local_var->completions = completions;
    v1_job_spec_local_var->manual_selector = manual_selector;
    v1_job_spec_local_var->parallelism = parallelism;
    v1_job_spec_local_var->selector = selector;
    v1_job_spec_local_var->_template = _template;
    v1_job_spec_local_var->ttl_seconds_after_finished = ttl_seconds_after_finished;

    return v1_job_spec_local_var;
}


void v1_job_spec_free(v1_job_spec_t *v1_job_spec) {
    if(NULL == v1_job_spec){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_job_spec->selector) {
        v1_label_selector_free(v1_job_spec->selector);
        v1_job_spec->selector = NULL;
    }
    if (v1_job_spec->_template) {
        v1_pod_template_spec_free(v1_job_spec->_template);
        v1_job_spec->_template = NULL;
    }
    free(v1_job_spec);
}

cJSON *v1_job_spec_convertToJSON(v1_job_spec_t *v1_job_spec) {
    cJSON *item = cJSON_CreateObject();

    // v1_job_spec->active_deadline_seconds
    if(v1_job_spec->active_deadline_seconds) { 
    if(cJSON_AddNumberToObject(item, "activeDeadlineSeconds", v1_job_spec->active_deadline_seconds) == NULL) {
    goto fail; //Numeric
    }
     } 


    // v1_job_spec->backoff_limit
    if(v1_job_spec->backoff_limit) { 
    if(cJSON_AddNumberToObject(item, "backoffLimit", v1_job_spec->backoff_limit) == NULL) {
    goto fail; //Numeric
    }
     } 


    // v1_job_spec->completions
    if(v1_job_spec->completions) { 
    if(cJSON_AddNumberToObject(item, "completions", v1_job_spec->completions) == NULL) {
    goto fail; //Numeric
    }
     } 


    // v1_job_spec->manual_selector
    if(v1_job_spec->manual_selector) { 
    if(cJSON_AddBoolToObject(item, "manualSelector", v1_job_spec->manual_selector) == NULL) {
    goto fail; //Bool
    }
     } 


    // v1_job_spec->parallelism
    if(v1_job_spec->parallelism) { 
    if(cJSON_AddNumberToObject(item, "parallelism", v1_job_spec->parallelism) == NULL) {
    goto fail; //Numeric
    }
     } 


    // v1_job_spec->selector
    if(v1_job_spec->selector) { 
    cJSON *selector_local_JSON = v1_label_selector_convertToJSON(v1_job_spec->selector);
    if(selector_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "selector", selector_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1_job_spec->_template
    if (!v1_job_spec->_template) {
        goto fail;
    }
    
    cJSON *_template_local_JSON = v1_pod_template_spec_convertToJSON(v1_job_spec->_template);
    if(_template_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "template", _template_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // v1_job_spec->ttl_seconds_after_finished
    if(v1_job_spec->ttl_seconds_after_finished) { 
    if(cJSON_AddNumberToObject(item, "ttlSecondsAfterFinished", v1_job_spec->ttl_seconds_after_finished) == NULL) {
    goto fail; //Numeric
    }
     } 

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_job_spec_t *v1_job_spec_parseFromJSON(cJSON *v1_job_specJSON){

    v1_job_spec_t *v1_job_spec_local_var = NULL;

    // v1_job_spec->active_deadline_seconds
    cJSON *active_deadline_seconds = cJSON_GetObjectItemCaseSensitive(v1_job_specJSON, "activeDeadlineSeconds");
    if (active_deadline_seconds) { 
    if(!cJSON_IsNumber(active_deadline_seconds))
    {
    goto end; //Numeric
    }
    }

    // v1_job_spec->backoff_limit
    cJSON *backoff_limit = cJSON_GetObjectItemCaseSensitive(v1_job_specJSON, "backoffLimit");
    if (backoff_limit) { 
    if(!cJSON_IsNumber(backoff_limit))
    {
    goto end; //Numeric
    }
    }

    // v1_job_spec->completions
    cJSON *completions = cJSON_GetObjectItemCaseSensitive(v1_job_specJSON, "completions");
    if (completions) { 
    if(!cJSON_IsNumber(completions))
    {
    goto end; //Numeric
    }
    }

    // v1_job_spec->manual_selector
    cJSON *manual_selector = cJSON_GetObjectItemCaseSensitive(v1_job_specJSON, "manualSelector");
    if (manual_selector) { 
    if(!cJSON_IsBool(manual_selector))
    {
    goto end; //Bool
    }
    }

    // v1_job_spec->parallelism
    cJSON *parallelism = cJSON_GetObjectItemCaseSensitive(v1_job_specJSON, "parallelism");
    if (parallelism) { 
    if(!cJSON_IsNumber(parallelism))
    {
    goto end; //Numeric
    }
    }

    // v1_job_spec->selector
    cJSON *selector = cJSON_GetObjectItemCaseSensitive(v1_job_specJSON, "selector");
    v1_label_selector_t *selector_local_nonprim = NULL;
    if (selector) { 
    selector_local_nonprim = v1_label_selector_parseFromJSON(selector); //nonprimitive
    }

    // v1_job_spec->_template
    cJSON *_template = cJSON_GetObjectItemCaseSensitive(v1_job_specJSON, "template");
    if (!_template) {
        goto end;
    }

    v1_pod_template_spec_t *_template_local_nonprim = NULL;
    
    _template_local_nonprim = v1_pod_template_spec_parseFromJSON(_template); //nonprimitive

    // v1_job_spec->ttl_seconds_after_finished
    cJSON *ttl_seconds_after_finished = cJSON_GetObjectItemCaseSensitive(v1_job_specJSON, "ttlSecondsAfterFinished");
    if (ttl_seconds_after_finished) { 
    if(!cJSON_IsNumber(ttl_seconds_after_finished))
    {
    goto end; //Numeric
    }
    }


    v1_job_spec_local_var = v1_job_spec_create (
        active_deadline_seconds ? active_deadline_seconds->valuedouble : 0,
        backoff_limit ? backoff_limit->valuedouble : 0,
        completions ? completions->valuedouble : 0,
        manual_selector ? manual_selector->valueint : 0,
        parallelism ? parallelism->valuedouble : 0,
        selector ? selector_local_nonprim : NULL,
        _template_local_nonprim,
        ttl_seconds_after_finished ? ttl_seconds_after_finished->valuedouble : 0
        );

    return v1_job_spec_local_var;
end:
    if (selector_local_nonprim) {
        v1_label_selector_free(selector_local_nonprim);
        selector_local_nonprim = NULL;
    }
    if (_template_local_nonprim) {
        v1_pod_template_spec_free(_template_local_nonprim);
        _template_local_nonprim = NULL;
    }
    return NULL;

}
