#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_param_ref.h"



v1beta1_param_ref_t *v1beta1_param_ref_create(
    char *name,
    char *_namespace,
    char *parameter_not_found_action,
    v1_label_selector_t *selector
    ) {
    v1beta1_param_ref_t *v1beta1_param_ref_local_var = malloc(sizeof(v1beta1_param_ref_t));
    if (!v1beta1_param_ref_local_var) {
        return NULL;
    }
    v1beta1_param_ref_local_var->name = name;
    v1beta1_param_ref_local_var->_namespace = _namespace;
    v1beta1_param_ref_local_var->parameter_not_found_action = parameter_not_found_action;
    v1beta1_param_ref_local_var->selector = selector;

    return v1beta1_param_ref_local_var;
}


void v1beta1_param_ref_free(v1beta1_param_ref_t *v1beta1_param_ref) {
    if(NULL == v1beta1_param_ref){
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta1_param_ref->name) {
        free(v1beta1_param_ref->name);
        v1beta1_param_ref->name = NULL;
    }
    if (v1beta1_param_ref->_namespace) {
        free(v1beta1_param_ref->_namespace);
        v1beta1_param_ref->_namespace = NULL;
    }
    if (v1beta1_param_ref->parameter_not_found_action) {
        free(v1beta1_param_ref->parameter_not_found_action);
        v1beta1_param_ref->parameter_not_found_action = NULL;
    }
    if (v1beta1_param_ref->selector) {
        v1_label_selector_free(v1beta1_param_ref->selector);
        v1beta1_param_ref->selector = NULL;
    }
    free(v1beta1_param_ref);
}

cJSON *v1beta1_param_ref_convertToJSON(v1beta1_param_ref_t *v1beta1_param_ref) {
    cJSON *item = cJSON_CreateObject();

    // v1beta1_param_ref->name
    if(v1beta1_param_ref->name) {
    if(cJSON_AddStringToObject(item, "name", v1beta1_param_ref->name) == NULL) {
    goto fail; //String
    }
    }


    // v1beta1_param_ref->_namespace
    if(v1beta1_param_ref->_namespace) {
    if(cJSON_AddStringToObject(item, "namespace", v1beta1_param_ref->_namespace) == NULL) {
    goto fail; //String
    }
    }


    // v1beta1_param_ref->parameter_not_found_action
    if(v1beta1_param_ref->parameter_not_found_action) {
    if(cJSON_AddStringToObject(item, "parameterNotFoundAction", v1beta1_param_ref->parameter_not_found_action) == NULL) {
    goto fail; //String
    }
    }


    // v1beta1_param_ref->selector
    if(v1beta1_param_ref->selector) {
    cJSON *selector_local_JSON = v1_label_selector_convertToJSON(v1beta1_param_ref->selector);
    if(selector_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "selector", selector_local_JSON);
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

v1beta1_param_ref_t *v1beta1_param_ref_parseFromJSON(cJSON *v1beta1_param_refJSON){

    v1beta1_param_ref_t *v1beta1_param_ref_local_var = NULL;

    // define the local variable for v1beta1_param_ref->selector
    v1_label_selector_t *selector_local_nonprim = NULL;

    // v1beta1_param_ref->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1beta1_param_refJSON, "name");
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // v1beta1_param_ref->_namespace
    cJSON *_namespace = cJSON_GetObjectItemCaseSensitive(v1beta1_param_refJSON, "namespace");
    if (_namespace) { 
    if(!cJSON_IsString(_namespace) && !cJSON_IsNull(_namespace))
    {
    goto end; //String
    }
    }

    // v1beta1_param_ref->parameter_not_found_action
    cJSON *parameter_not_found_action = cJSON_GetObjectItemCaseSensitive(v1beta1_param_refJSON, "parameterNotFoundAction");
    if (parameter_not_found_action) { 
    if(!cJSON_IsString(parameter_not_found_action) && !cJSON_IsNull(parameter_not_found_action))
    {
    goto end; //String
    }
    }

    // v1beta1_param_ref->selector
    cJSON *selector = cJSON_GetObjectItemCaseSensitive(v1beta1_param_refJSON, "selector");
    if (selector) { 
    selector_local_nonprim = v1_label_selector_parseFromJSON(selector); //nonprimitive
    }


    v1beta1_param_ref_local_var = v1beta1_param_ref_create (
        name && !cJSON_IsNull(name) ? strdup(name->valuestring) : NULL,
        _namespace && !cJSON_IsNull(_namespace) ? strdup(_namespace->valuestring) : NULL,
        parameter_not_found_action && !cJSON_IsNull(parameter_not_found_action) ? strdup(parameter_not_found_action->valuestring) : NULL,
        selector ? selector_local_nonprim : NULL
        );

    return v1beta1_param_ref_local_var;
end:
    if (selector_local_nonprim) {
        v1_label_selector_free(selector_local_nonprim);
        selector_local_nonprim = NULL;
    }
    return NULL;

}
