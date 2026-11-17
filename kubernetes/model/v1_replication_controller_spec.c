#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_replication_controller_spec.h"



static v1_replication_controller_spec_t *v1_replication_controller_spec_create_internal(
    int *min_ready_seconds,
    int *replicas,
    list_t* selector,
    v1_pod_template_spec_t *_template
    ) {
    v1_replication_controller_spec_t *v1_replication_controller_spec_local_var = malloc(sizeof(v1_replication_controller_spec_t));
    if (!v1_replication_controller_spec_local_var) {
        return NULL;
    }
    memset(v1_replication_controller_spec_local_var, 0, sizeof(v1_replication_controller_spec_t));
    v1_replication_controller_spec_local_var->_library_owned = 1;
    v1_replication_controller_spec_local_var->min_ready_seconds = min_ready_seconds;
    v1_replication_controller_spec_local_var->replicas = replicas;
    v1_replication_controller_spec_local_var->selector = selector;
    v1_replication_controller_spec_local_var->_template = _template;
    return v1_replication_controller_spec_local_var;
}

__attribute__((deprecated)) v1_replication_controller_spec_t *v1_replication_controller_spec_create(
    int *min_ready_seconds,
    int *replicas,
    list_t* selector,
    v1_pod_template_spec_t *_template
    ) {
    int *min_ready_seconds_copy = NULL;
    if (min_ready_seconds) {
        min_ready_seconds_copy = malloc(sizeof(int));
        if (min_ready_seconds_copy) *min_ready_seconds_copy = *min_ready_seconds;
    }
    int *replicas_copy = NULL;
    if (replicas) {
        replicas_copy = malloc(sizeof(int));
        if (replicas_copy) *replicas_copy = *replicas;
    }
    v1_replication_controller_spec_t *result = v1_replication_controller_spec_create_internal (
        min_ready_seconds_copy,
        replicas_copy,
        selector,
        _template
        );
    if (!result) {
        free(min_ready_seconds_copy);
        free(replicas_copy);
    }
    return result;
}

void v1_replication_controller_spec_free(v1_replication_controller_spec_t *v1_replication_controller_spec) {
    if(NULL == v1_replication_controller_spec){
        return ;
    }
    if(v1_replication_controller_spec->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_replication_controller_spec_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_replication_controller_spec->min_ready_seconds) {
        free(v1_replication_controller_spec->min_ready_seconds);
        v1_replication_controller_spec->min_ready_seconds = NULL;
    }
    if (v1_replication_controller_spec->replicas) {
        free(v1_replication_controller_spec->replicas);
        v1_replication_controller_spec->replicas = NULL;
    }
    if (v1_replication_controller_spec->selector) {
        list_ForEach(listEntry, v1_replication_controller_spec->selector) {
            keyValuePair_t *localKeyValue = listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_freeList(v1_replication_controller_spec->selector);
        v1_replication_controller_spec->selector = NULL;
    }
    if (v1_replication_controller_spec->_template) {
        v1_pod_template_spec_free(v1_replication_controller_spec->_template);
        v1_replication_controller_spec->_template = NULL;
    }
    free(v1_replication_controller_spec);
}

cJSON *v1_replication_controller_spec_convertToJSON(v1_replication_controller_spec_t *v1_replication_controller_spec) {
    cJSON *item = cJSON_CreateObject();

    // v1_replication_controller_spec->min_ready_seconds
    if(v1_replication_controller_spec->min_ready_seconds) {
    if(cJSON_AddNumberToObject(item, "minReadySeconds", *v1_replication_controller_spec->min_ready_seconds) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_replication_controller_spec->replicas
    if(v1_replication_controller_spec->replicas) {
    if(cJSON_AddNumberToObject(item, "replicas", *v1_replication_controller_spec->replicas) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_replication_controller_spec->selector
    if(v1_replication_controller_spec->selector) {
    cJSON *selector = cJSON_AddObjectToObject(item, "selector");
    if(selector == NULL) {
        goto fail; //primitive map container
    }
    cJSON *localMapObject = selector;
    listEntry_t *selectorListEntry;
    if (v1_replication_controller_spec->selector) {
    list_ForEach(selectorListEntry, v1_replication_controller_spec->selector) {
        keyValuePair_t *localKeyValue = selectorListEntry->data;
        if(cJSON_AddStringToObject(localMapObject, localKeyValue->key, localKeyValue->value) == NULL)
        {
            goto fail;
        }
    }
    }
    }


    // v1_replication_controller_spec->_template
    if(v1_replication_controller_spec->_template) {
    cJSON *_template_local_JSON = v1_pod_template_spec_convertToJSON(v1_replication_controller_spec->_template);
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

v1_replication_controller_spec_t *v1_replication_controller_spec_parseFromJSON(cJSON *v1_replication_controller_specJSON){

    v1_replication_controller_spec_t *v1_replication_controller_spec_local_var = NULL;

    // define the local variable for v1_replication_controller_spec->min_ready_seconds
    int *min_ready_seconds_local_var = NULL;

    // define the local variable for v1_replication_controller_spec->replicas
    int *replicas_local_var = NULL;

    // define the local map for v1_replication_controller_spec->selector
    list_t *selectorList = NULL;

    // define the local variable for v1_replication_controller_spec->_template
    v1_pod_template_spec_t *_template_local_nonprim = NULL;

    // v1_replication_controller_spec->min_ready_seconds
    cJSON *min_ready_seconds = cJSON_GetObjectItemCaseSensitive(v1_replication_controller_specJSON, "minReadySeconds");
    if (cJSON_IsNull(min_ready_seconds)) {
        min_ready_seconds = NULL;
    }
    if (min_ready_seconds) { 
    if(!cJSON_IsNumber(min_ready_seconds))
    {
    goto end; //Numeric
    }
    min_ready_seconds_local_var = malloc(sizeof(int));
    if(!min_ready_seconds_local_var)
    {
        goto end;
    }
    *min_ready_seconds_local_var = min_ready_seconds->valuedouble;
    }

    // v1_replication_controller_spec->replicas
    cJSON *replicas = cJSON_GetObjectItemCaseSensitive(v1_replication_controller_specJSON, "replicas");
    if (cJSON_IsNull(replicas)) {
        replicas = NULL;
    }
    if (replicas) { 
    if(!cJSON_IsNumber(replicas))
    {
    goto end; //Numeric
    }
    replicas_local_var = malloc(sizeof(int));
    if(!replicas_local_var)
    {
        goto end;
    }
    *replicas_local_var = replicas->valuedouble;
    }

    // v1_replication_controller_spec->selector
    cJSON *selector = cJSON_GetObjectItemCaseSensitive(v1_replication_controller_specJSON, "selector");
    if (cJSON_IsNull(selector)) {
        selector = NULL;
    }
    if (selector) { 
    cJSON *selector_local_map = NULL;
    if(!cJSON_IsObject(selector) && !cJSON_IsNull(selector))
    {
        goto end;//primitive map container
    }
    if(cJSON_IsObject(selector))
    {
        selectorList = list_createList();
        keyValuePair_t *localMapKeyPair;
        cJSON_ArrayForEach(selector_local_map, selector)
        {
            cJSON *localMapObject = selector_local_map;
            if(!cJSON_IsString(localMapObject))
            {
                goto end;
            }
            localMapKeyPair = keyValuePair_create(strdup(localMapObject->string),strdup(localMapObject->valuestring));
            list_addElement(selectorList , localMapKeyPair);
        }
    }
    }

    // v1_replication_controller_spec->_template
    cJSON *_template = cJSON_GetObjectItemCaseSensitive(v1_replication_controller_specJSON, "template");
    if (cJSON_IsNull(_template)) {
        _template = NULL;
    }
    if (_template) { 
    _template_local_nonprim = v1_pod_template_spec_parseFromJSON(_template); //nonprimitive
    }



    v1_replication_controller_spec_local_var = v1_replication_controller_spec_create_internal (
        min_ready_seconds_local_var,
        replicas_local_var,
        selector ? selectorList : NULL,
        _template ? _template_local_nonprim : NULL
        );

    if (!v1_replication_controller_spec_local_var) {
        goto end;
    }

    return v1_replication_controller_spec_local_var;
end:
    if (min_ready_seconds_local_var) {
        free(min_ready_seconds_local_var);
        min_ready_seconds_local_var = NULL;
    }
    if (replicas_local_var) {
        free(replicas_local_var);
        replicas_local_var = NULL;
    }
    if (selectorList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, selectorList) {
            keyValuePair_t *localKeyValue = listEntry->data;
            free(localKeyValue->key);
            localKeyValue->key = NULL;
            free(localKeyValue->value);
            localKeyValue->value = NULL;
            keyValuePair_free(localKeyValue);
            localKeyValue = NULL;
        }
        list_freeList(selectorList);
        selectorList = NULL;
    }
    if (_template_local_nonprim) {
        v1_pod_template_spec_free(_template_local_nonprim);
        _template_local_nonprim = NULL;
    }
    return NULL;

}
