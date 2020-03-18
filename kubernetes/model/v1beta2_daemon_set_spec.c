#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta2_daemon_set_spec.h"



v1beta2_daemon_set_spec_t *v1beta2_daemon_set_spec_create(
    int min_ready_seconds,
    int revision_history_limit,
    v1_label_selector_t *selector,
    v1_pod_template_spec_t *template,
    v1beta2_daemon_set_update_strategy_t *update_strategy
    ) {
    v1beta2_daemon_set_spec_t *v1beta2_daemon_set_spec_local_var = malloc(sizeof(v1beta2_daemon_set_spec_t));
    if (!v1beta2_daemon_set_spec_local_var) {
        return NULL;
    }
    v1beta2_daemon_set_spec_local_var->min_ready_seconds = min_ready_seconds;
    v1beta2_daemon_set_spec_local_var->revision_history_limit = revision_history_limit;
    v1beta2_daemon_set_spec_local_var->selector = selector;
    v1beta2_daemon_set_spec_local_var->template = template;
    v1beta2_daemon_set_spec_local_var->update_strategy = update_strategy;

    return v1beta2_daemon_set_spec_local_var;
}


void v1beta2_daemon_set_spec_free(v1beta2_daemon_set_spec_t *v1beta2_daemon_set_spec) {
    if(NULL == v1beta2_daemon_set_spec){
        return ;
    }
    listEntry_t *listEntry;
    v1_label_selector_free(v1beta2_daemon_set_spec->selector);
    v1_pod_template_spec_free(v1beta2_daemon_set_spec->template);
    v1beta2_daemon_set_update_strategy_free(v1beta2_daemon_set_spec->update_strategy);
    free(v1beta2_daemon_set_spec);
}

cJSON *v1beta2_daemon_set_spec_convertToJSON(v1beta2_daemon_set_spec_t *v1beta2_daemon_set_spec) {
    cJSON *item = cJSON_CreateObject();

    // v1beta2_daemon_set_spec->min_ready_seconds
    if(v1beta2_daemon_set_spec->min_ready_seconds) { 
    if(cJSON_AddNumberToObject(item, "minReadySeconds", v1beta2_daemon_set_spec->min_ready_seconds) == NULL) {
    goto fail; //Numeric
    }
     } 


    // v1beta2_daemon_set_spec->revision_history_limit
    if(v1beta2_daemon_set_spec->revision_history_limit) { 
    if(cJSON_AddNumberToObject(item, "revisionHistoryLimit", v1beta2_daemon_set_spec->revision_history_limit) == NULL) {
    goto fail; //Numeric
    }
     } 


    // v1beta2_daemon_set_spec->selector
    if (!v1beta2_daemon_set_spec->selector) {
        goto fail;
    }
    
    cJSON *selector_local_JSON = v1_label_selector_convertToJSON(v1beta2_daemon_set_spec->selector);
    if(selector_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "selector", selector_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // v1beta2_daemon_set_spec->template
    if (!v1beta2_daemon_set_spec->template) {
        goto fail;
    }
    
    cJSON *template_local_JSON = v1_pod_template_spec_convertToJSON(v1beta2_daemon_set_spec->template);
    if(template_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "template", template_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // v1beta2_daemon_set_spec->update_strategy
    if(v1beta2_daemon_set_spec->update_strategy) { 
    cJSON *update_strategy_local_JSON = v1beta2_daemon_set_update_strategy_convertToJSON(v1beta2_daemon_set_spec->update_strategy);
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

v1beta2_daemon_set_spec_t *v1beta2_daemon_set_spec_parseFromJSON(cJSON *v1beta2_daemon_set_specJSON){

    v1beta2_daemon_set_spec_t *v1beta2_daemon_set_spec_local_var = NULL;

    // v1beta2_daemon_set_spec->min_ready_seconds
    cJSON *min_ready_seconds = cJSON_GetObjectItemCaseSensitive(v1beta2_daemon_set_specJSON, "minReadySeconds");
    if (min_ready_seconds) { 
    if(!cJSON_IsNumber(min_ready_seconds))
    {
    goto end; //Numeric
    }
    }

    // v1beta2_daemon_set_spec->revision_history_limit
    cJSON *revision_history_limit = cJSON_GetObjectItemCaseSensitive(v1beta2_daemon_set_specJSON, "revisionHistoryLimit");
    if (revision_history_limit) { 
    if(!cJSON_IsNumber(revision_history_limit))
    {
    goto end; //Numeric
    }
    }

    // v1beta2_daemon_set_spec->selector
    cJSON *selector = cJSON_GetObjectItemCaseSensitive(v1beta2_daemon_set_specJSON, "selector");
    if (!selector) {
        goto end;
    }

    v1_label_selector_t *selector_local_nonprim = NULL;
    
    selector_local_nonprim = v1_label_selector_parseFromJSON(selector); //nonprimitive

    // v1beta2_daemon_set_spec->template
    cJSON *template = cJSON_GetObjectItemCaseSensitive(v1beta2_daemon_set_specJSON, "template");
    if (!template) {
        goto end;
    }

    v1_pod_template_spec_t *template_local_nonprim = NULL;
    
    template_local_nonprim = v1_pod_template_spec_parseFromJSON(template); //nonprimitive

    // v1beta2_daemon_set_spec->update_strategy
    cJSON *update_strategy = cJSON_GetObjectItemCaseSensitive(v1beta2_daemon_set_specJSON, "updateStrategy");
    v1beta2_daemon_set_update_strategy_t *update_strategy_local_nonprim = NULL;
    if (update_strategy) { 
    update_strategy_local_nonprim = v1beta2_daemon_set_update_strategy_parseFromJSON(update_strategy); //nonprimitive
    }


    v1beta2_daemon_set_spec_local_var = v1beta2_daemon_set_spec_create (
        min_ready_seconds ? min_ready_seconds->valuedouble : 0,
        revision_history_limit ? revision_history_limit->valuedouble : 0,
        selector_local_nonprim,
        template_local_nonprim,
        update_strategy ? update_strategy_local_nonprim : NULL
        );

    return v1beta2_daemon_set_spec_local_var;
end:
    return NULL;

}
