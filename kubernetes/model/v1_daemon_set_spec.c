#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_daemon_set_spec.h"



v1_daemon_set_spec_t *v1_daemon_set_spec_create(
    int min_ready_seconds,
    int revision_history_limit,
    v1_label_selector_t *selector,
    v1_pod_template_spec_t *_template,
    v1_daemon_set_update_strategy_t *update_strategy
    ) {
    v1_daemon_set_spec_t *v1_daemon_set_spec_local_var = malloc(sizeof(v1_daemon_set_spec_t));
    if (!v1_daemon_set_spec_local_var) {
        return NULL;
    }
    v1_daemon_set_spec_local_var->min_ready_seconds = min_ready_seconds;
    v1_daemon_set_spec_local_var->revision_history_limit = revision_history_limit;
    v1_daemon_set_spec_local_var->selector = selector;
    v1_daemon_set_spec_local_var->_template = _template;
    v1_daemon_set_spec_local_var->update_strategy = update_strategy;

    return v1_daemon_set_spec_local_var;
}


void v1_daemon_set_spec_free(v1_daemon_set_spec_t *v1_daemon_set_spec) {
    if(NULL == v1_daemon_set_spec){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_daemon_set_spec->selector) {
        v1_label_selector_free(v1_daemon_set_spec->selector);
        v1_daemon_set_spec->selector = NULL;
    }
    if (v1_daemon_set_spec->_template) {
        v1_pod_template_spec_free(v1_daemon_set_spec->_template);
        v1_daemon_set_spec->_template = NULL;
    }
    if (v1_daemon_set_spec->update_strategy) {
        v1_daemon_set_update_strategy_free(v1_daemon_set_spec->update_strategy);
        v1_daemon_set_spec->update_strategy = NULL;
    }
    free(v1_daemon_set_spec);
}

cJSON *v1_daemon_set_spec_convertToJSON(v1_daemon_set_spec_t *v1_daemon_set_spec) {
    cJSON *item = cJSON_CreateObject();

    // v1_daemon_set_spec->min_ready_seconds
    if(v1_daemon_set_spec->min_ready_seconds) { 
    if(cJSON_AddNumberToObject(item, "minReadySeconds", v1_daemon_set_spec->min_ready_seconds) == NULL) {
    goto fail; //Numeric
    }
     } 


    // v1_daemon_set_spec->revision_history_limit
    if(v1_daemon_set_spec->revision_history_limit) { 
    if(cJSON_AddNumberToObject(item, "revisionHistoryLimit", v1_daemon_set_spec->revision_history_limit) == NULL) {
    goto fail; //Numeric
    }
     } 


    // v1_daemon_set_spec->selector
    if (!v1_daemon_set_spec->selector) {
        goto fail;
    }
    
    cJSON *selector_local_JSON = v1_label_selector_convertToJSON(v1_daemon_set_spec->selector);
    if(selector_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "selector", selector_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // v1_daemon_set_spec->_template
    if (!v1_daemon_set_spec->_template) {
        goto fail;
    }
    
    cJSON *_template_local_JSON = v1_pod_template_spec_convertToJSON(v1_daemon_set_spec->_template);
    if(_template_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "template", _template_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // v1_daemon_set_spec->update_strategy
    if(v1_daemon_set_spec->update_strategy) { 
    cJSON *update_strategy_local_JSON = v1_daemon_set_update_strategy_convertToJSON(v1_daemon_set_spec->update_strategy);
    if(update_strategy_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "updateStrategy", update_strategy_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_daemon_set_spec_t *v1_daemon_set_spec_parseFromJSON(cJSON *v1_daemon_set_specJSON){

    v1_daemon_set_spec_t *v1_daemon_set_spec_local_var = NULL;

    // v1_daemon_set_spec->min_ready_seconds
    cJSON *min_ready_seconds = cJSON_GetObjectItemCaseSensitive(v1_daemon_set_specJSON, "minReadySeconds");
    if (min_ready_seconds) { 
    if(!cJSON_IsNumber(min_ready_seconds))
    {
    goto end; //Numeric
    }
    }

    // v1_daemon_set_spec->revision_history_limit
    cJSON *revision_history_limit = cJSON_GetObjectItemCaseSensitive(v1_daemon_set_specJSON, "revisionHistoryLimit");
    if (revision_history_limit) { 
    if(!cJSON_IsNumber(revision_history_limit))
    {
    goto end; //Numeric
    }
    }

    // v1_daemon_set_spec->selector
    cJSON *selector = cJSON_GetObjectItemCaseSensitive(v1_daemon_set_specJSON, "selector");
    if (!selector) {
        goto end;
    }

    v1_label_selector_t *selector_local_nonprim = NULL;
    
    selector_local_nonprim = v1_label_selector_parseFromJSON(selector); //nonprimitive

    // v1_daemon_set_spec->_template
    cJSON *_template = cJSON_GetObjectItemCaseSensitive(v1_daemon_set_specJSON, "template");
    if (!_template) {
        goto end;
    }

    v1_pod_template_spec_t *_template_local_nonprim = NULL;
    
    _template_local_nonprim = v1_pod_template_spec_parseFromJSON(_template); //nonprimitive

    // v1_daemon_set_spec->update_strategy
    cJSON *update_strategy = cJSON_GetObjectItemCaseSensitive(v1_daemon_set_specJSON, "updateStrategy");
    v1_daemon_set_update_strategy_t *update_strategy_local_nonprim = NULL;
    if (update_strategy) { 
    update_strategy_local_nonprim = v1_daemon_set_update_strategy_parseFromJSON(update_strategy); //nonprimitive
    }


    v1_daemon_set_spec_local_var = v1_daemon_set_spec_create (
        min_ready_seconds ? min_ready_seconds->valuedouble : 0,
        revision_history_limit ? revision_history_limit->valuedouble : 0,
        selector_local_nonprim,
        _template_local_nonprim,
        update_strategy ? update_strategy_local_nonprim : NULL
        );

    return v1_daemon_set_spec_local_var;
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
        v1_daemon_set_update_strategy_free(update_strategy_local_nonprim);
        update_strategy_local_nonprim = NULL;
    }
    return NULL;

}
