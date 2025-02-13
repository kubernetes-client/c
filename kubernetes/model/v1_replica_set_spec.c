#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_replica_set_spec.h"



static v1_replica_set_spec_t *v1_replica_set_spec_create_internal(
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

    v1_replica_set_spec_local_var->_library_owned = 1;
    return v1_replica_set_spec_local_var;
}

__attribute__((deprecated)) v1_replica_set_spec_t *v1_replica_set_spec_create(
    int min_ready_seconds,
    int replicas,
    v1_label_selector_t *selector,
    v1_pod_template_spec_t *_template
    ) {
    return v1_replica_set_spec_create_internal (
        min_ready_seconds,
        replicas,
        selector,
        _template
        );
}

void v1_replica_set_spec_free(v1_replica_set_spec_t *v1_replica_set_spec) {
    if(NULL == v1_replica_set_spec){
        return ;
    }
    if(v1_replica_set_spec->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_replica_set_spec_free");
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

    // define the local variable for v1_replica_set_spec->selector
    v1_label_selector_t *selector_local_nonprim = NULL;

    // define the local variable for v1_replica_set_spec->_template
    v1_pod_template_spec_t *_template_local_nonprim = NULL;

    // v1_replica_set_spec->min_ready_seconds
    cJSON *min_ready_seconds = cJSON_GetObjectItemCaseSensitive(v1_replica_set_specJSON, "minReadySeconds");
    if (cJSON_IsNull(min_ready_seconds)) {
        min_ready_seconds = NULL;
    }
    if (min_ready_seconds) { 
    if(!cJSON_IsNumber(min_ready_seconds))
    {
    goto end; //Numeric
    }
    }

    // v1_replica_set_spec->replicas
    cJSON *replicas = cJSON_GetObjectItemCaseSensitive(v1_replica_set_specJSON, "replicas");
    if (cJSON_IsNull(replicas)) {
        replicas = NULL;
    }
    if (replicas) { 
    if(!cJSON_IsNumber(replicas))
    {
    goto end; //Numeric
    }
    }

    // v1_replica_set_spec->selector
    cJSON *selector = cJSON_GetObjectItemCaseSensitive(v1_replica_set_specJSON, "selector");
    if (cJSON_IsNull(selector)) {
        selector = NULL;
    }
    if (!selector) {
        goto end;
    }

    
    selector_local_nonprim = v1_label_selector_parseFromJSON(selector); //nonprimitive

    // v1_replica_set_spec->_template
    cJSON *_template = cJSON_GetObjectItemCaseSensitive(v1_replica_set_specJSON, "template");
    if (cJSON_IsNull(_template)) {
        _template = NULL;
    }
    if (_template) { 
    _template_local_nonprim = v1_pod_template_spec_parseFromJSON(_template); //nonprimitive
    }


    v1_replica_set_spec_local_var = v1_replica_set_spec_create_internal (
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
