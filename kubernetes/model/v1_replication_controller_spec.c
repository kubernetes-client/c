#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_replication_controller_spec.h"



v1_replication_controller_spec_t *v1_replication_controller_spec_create(
    int min_ready_seconds,
    int replicas,
    list_t* selector,
    v1_pod_template_spec_t *_template
    ) {
    v1_replication_controller_spec_t *v1_replication_controller_spec_local_var = malloc(sizeof(v1_replication_controller_spec_t));
    if (!v1_replication_controller_spec_local_var) {
        return NULL;
    }
    v1_replication_controller_spec_local_var->min_ready_seconds = min_ready_seconds;
    v1_replication_controller_spec_local_var->replicas = replicas;
    v1_replication_controller_spec_local_var->selector = selector;
    v1_replication_controller_spec_local_var->_template = _template;

    return v1_replication_controller_spec_local_var;
}


void v1_replication_controller_spec_free(v1_replication_controller_spec_t *v1_replication_controller_spec) {
    if(NULL == v1_replication_controller_spec){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_replication_controller_spec->selector) {
        list_ForEach(listEntry, v1_replication_controller_spec->selector) {
            keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_free(v1_replication_controller_spec->selector);
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
    if(cJSON_AddNumberToObject(item, "minReadySeconds", v1_replication_controller_spec->min_ready_seconds) == NULL) {
    goto fail; //Numeric
    }
     } 


    // v1_replication_controller_spec->replicas
    if(v1_replication_controller_spec->replicas) { 
    if(cJSON_AddNumberToObject(item, "replicas", v1_replication_controller_spec->replicas) == NULL) {
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
        keyValuePair_t *localKeyValue = (keyValuePair_t*)selectorListEntry->data;
        if(cJSON_AddStringToObject(localMapObject, localKeyValue->key, (char*)localKeyValue->value) == NULL)
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

    // v1_replication_controller_spec->min_ready_seconds
    cJSON *min_ready_seconds = cJSON_GetObjectItemCaseSensitive(v1_replication_controller_specJSON, "minReadySeconds");
    if (min_ready_seconds) { 
    if(!cJSON_IsNumber(min_ready_seconds))
    {
    goto end; //Numeric
    }
    }

    // v1_replication_controller_spec->replicas
    cJSON *replicas = cJSON_GetObjectItemCaseSensitive(v1_replication_controller_specJSON, "replicas");
    if (replicas) { 
    if(!cJSON_IsNumber(replicas))
    {
    goto end; //Numeric
    }
    }

    // v1_replication_controller_spec->selector
    cJSON *selector = cJSON_GetObjectItemCaseSensitive(v1_replication_controller_specJSON, "selector");
    list_t *selectorList;
    if (selector) { 
    cJSON *selector_local_map;
    if(!cJSON_IsObject(selector)) {
        goto end;//primitive map container
    }
    selectorList = list_create();
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

    // v1_replication_controller_spec->_template
    cJSON *_template = cJSON_GetObjectItemCaseSensitive(v1_replication_controller_specJSON, "template");
    v1_pod_template_spec_t *_template_local_nonprim = NULL;
    if (_template) { 
    _template_local_nonprim = v1_pod_template_spec_parseFromJSON(_template); //nonprimitive
    }


    v1_replication_controller_spec_local_var = v1_replication_controller_spec_create (
        min_ready_seconds ? min_ready_seconds->valuedouble : 0,
        replicas ? replicas->valuedouble : 0,
        selector ? selectorList : NULL,
        _template ? _template_local_nonprim : NULL
        );

    return v1_replication_controller_spec_local_var;
end:
    if (_template_local_nonprim) {
        v1_pod_template_spec_free(_template_local_nonprim);
        _template_local_nonprim = NULL;
    }
    return NULL;

}
