#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v2beta2_metric_identifier.h"



v2beta2_metric_identifier_t *v2beta2_metric_identifier_create(
    char *name,
    v1_label_selector_t *selector
    ) {
    v2beta2_metric_identifier_t *v2beta2_metric_identifier_local_var = malloc(sizeof(v2beta2_metric_identifier_t));
    if (!v2beta2_metric_identifier_local_var) {
        return NULL;
    }
    v2beta2_metric_identifier_local_var->name = name;
    v2beta2_metric_identifier_local_var->selector = selector;

    return v2beta2_metric_identifier_local_var;
}


void v2beta2_metric_identifier_free(v2beta2_metric_identifier_t *v2beta2_metric_identifier) {
    if(NULL == v2beta2_metric_identifier){
        return ;
    }
    listEntry_t *listEntry;
    if (v2beta2_metric_identifier->name) {
        free(v2beta2_metric_identifier->name);
        v2beta2_metric_identifier->name = NULL;
    }
    if (v2beta2_metric_identifier->selector) {
        v1_label_selector_free(v2beta2_metric_identifier->selector);
        v2beta2_metric_identifier->selector = NULL;
    }
    free(v2beta2_metric_identifier);
}

cJSON *v2beta2_metric_identifier_convertToJSON(v2beta2_metric_identifier_t *v2beta2_metric_identifier) {
    cJSON *item = cJSON_CreateObject();

    // v2beta2_metric_identifier->name
    if (!v2beta2_metric_identifier->name) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "name", v2beta2_metric_identifier->name) == NULL) {
    goto fail; //String
    }


    // v2beta2_metric_identifier->selector
    if(v2beta2_metric_identifier->selector) { 
    cJSON *selector_local_JSON = v1_label_selector_convertToJSON(v2beta2_metric_identifier->selector);
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

v2beta2_metric_identifier_t *v2beta2_metric_identifier_parseFromJSON(cJSON *v2beta2_metric_identifierJSON){

    v2beta2_metric_identifier_t *v2beta2_metric_identifier_local_var = NULL;

    // v2beta2_metric_identifier->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v2beta2_metric_identifierJSON, "name");
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // v2beta2_metric_identifier->selector
    cJSON *selector = cJSON_GetObjectItemCaseSensitive(v2beta2_metric_identifierJSON, "selector");
    v1_label_selector_t *selector_local_nonprim = NULL;
    if (selector) { 
    selector_local_nonprim = v1_label_selector_parseFromJSON(selector); //nonprimitive
    }


    v2beta2_metric_identifier_local_var = v2beta2_metric_identifier_create (
        strdup(name->valuestring),
        selector ? selector_local_nonprim : NULL
        );

    return v2beta2_metric_identifier_local_var;
end:
    if (selector_local_nonprim) {
        v1_label_selector_free(selector_local_nonprim);
        selector_local_nonprim = NULL;
    }
    return NULL;

}
