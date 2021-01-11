#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_replica_set_spec.h"



v1_replica_set_spec_t *v1_replica_set_spec_create(
    int min_ready_seconds,
    int replicas,
    v1_label_selector_t *selector,
    v1_pod_template_spec_t *_template
    ) {
    v1_replica_set_spec_t *v1_replica_set_spec_local_var = malloc(sizeof(v1_replica_set_spec_t));
    if (!v1_replica_set_spec_local_var) {
        return NULL;
    }
    v1_replica_set_spec_local_var->min_ready_seconds = min_ready_seconds;
    v1_replica_set_spec_local_var->replicas = replicas;
    v1_replica_set_spec_local_var->selector = selector;
    v1_replica_set_spec_local_var->_template = _template;

    return v1_replica_set_spec_local_var;
}


void v1_replica_set_spec_free(v1_replica_set_spec_t *v1_replica_set_spec) {
    if(NULL == v1_replica_set_spec){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_replica_set_spec->selector) {
        v1_label_selector_free(v1_replica_set_spec->selector);
        v1_replica_set_spec->selector = NULL;
    }
    if (v1_replica_set_spec->_template) {
        v1_pod_template_spec_free(v1_replica_set_spec->_template);
        v1_replica_set_spec->_template = NULL;
    }
    free(v1_replica_set_spec);
}

cJSON *v1_replica_set_spec_convertToJSON(v1_replica_set_spec_t *v1_replica_set_spec) {
    cJSON *item = cJSON_CreateObject();

    // v1_replica_set_spec->min_ready_seconds
    if(v1_replica_set_spec->min_ready_seconds) { 
    if(cJSON_AddNumberToObject(item, "minReadySeconds", v1_replica_set_spec->min_ready_seconds) == NULL) {
    goto fail; //Numeric
    }
     } 


    // v1_replica_set_spec->replicas
    if(v1_replica_set_spec->replicas) { 
    if(cJSON_AddNumberToObject(item, "replicas", v1_replica_set_spec->replicas) == NULL) {
    goto fail; //Numeric
    }
     } 


    // v1_replica_set_spec->selector
    if (!v1_replica_set_spec->selector) {
        goto fail;
    }
    
    cJSON *selector_local_JSON = v1_label_selector_convertToJSON(v1_replica_set_spec->selector);
    if(selector_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "selector", selector_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // v1_replica_set_spec->_template
    if(v1_replica_set_spec->_template) { 
    cJSON *_template_local_JSON = v1_pod_template_spec_convertToJSON(v1_replica_set_spec->_template);
    if(_template_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "template", _template_local_JSON);
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

v1_replica_set_spec_t *v1_replica_set_spec_parseFromJSON(cJSON *v1_replica_set_specJSON){

    v1_replica_set_spec_t *v1_replica_set_spec_local_var = NULL;

    // v1_replica_set_spec->min_ready_seconds
    cJSON *min_ready_seconds = cJSON_GetObjectItemCaseSensitive(v1_replica_set_specJSON, "minReadySeconds");
    if (min_ready_seconds) { 
    if(!cJSON_IsNumber(min_ready_seconds))
    {
    goto end; //Numeric
    }
    }

    // v1_replica_set_spec->replicas
    cJSON *replicas = cJSON_GetObjectItemCaseSensitive(v1_replica_set_specJSON, "replicas");
    if (replicas) { 
    if(!cJSON_IsNumber(replicas))
    {
    goto end; //Numeric
    }
    }

    // v1_replica_set_spec->selector
    cJSON *selector = cJSON_GetObjectItemCaseSensitive(v1_replica_set_specJSON, "selector");
    if (!selector) {
        goto end;
    }

    v1_label_selector_t *selector_local_nonprim = NULL;
    
    selector_local_nonprim = v1_label_selector_parseFromJSON(selector); //nonprimitive

    // v1_replica_set_spec->_template
    cJSON *_template = cJSON_GetObjectItemCaseSensitive(v1_replica_set_specJSON, "template");
    v1_pod_template_spec_t *_template_local_nonprim = NULL;
    if (_template) { 
    _template_local_nonprim = v1_pod_template_spec_parseFromJSON(_template); //nonprimitive
    }


    v1_replica_set_spec_local_var = v1_replica_set_spec_create (
        min_ready_seconds ? min_ready_seconds->valuedouble : 0,
        replicas ? replicas->valuedouble : 0,
        selector_local_nonprim,
        _template ? _template_local_nonprim : NULL
        );

    return v1_replica_set_spec_local_var;
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
