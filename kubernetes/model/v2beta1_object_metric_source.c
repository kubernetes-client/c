#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v2beta1_object_metric_source.h"



v2beta1_object_metric_source_t *v2beta1_object_metric_source_create(
    char *average_value,
    char *metric_name,
    v1_label_selector_t *selector,
    v2beta1_cross_version_object_reference_t *target,
    char *target_value
    ) {
    v2beta1_object_metric_source_t *v2beta1_object_metric_source_local_var = malloc(sizeof(v2beta1_object_metric_source_t));
    if (!v2beta1_object_metric_source_local_var) {
        return NULL;
    }
    v2beta1_object_metric_source_local_var->average_value = average_value;
    v2beta1_object_metric_source_local_var->metric_name = metric_name;
    v2beta1_object_metric_source_local_var->selector = selector;
    v2beta1_object_metric_source_local_var->target = target;
    v2beta1_object_metric_source_local_var->target_value = target_value;

    return v2beta1_object_metric_source_local_var;
}


void v2beta1_object_metric_source_free(v2beta1_object_metric_source_t *v2beta1_object_metric_source) {
    if(NULL == v2beta1_object_metric_source){
        return ;
    }
    listEntry_t *listEntry;
    if (v2beta1_object_metric_source->average_value) {
        free(v2beta1_object_metric_source->average_value);
        v2beta1_object_metric_source->average_value = NULL;
    }
    if (v2beta1_object_metric_source->metric_name) {
        free(v2beta1_object_metric_source->metric_name);
        v2beta1_object_metric_source->metric_name = NULL;
    }
    if (v2beta1_object_metric_source->selector) {
        v1_label_selector_free(v2beta1_object_metric_source->selector);
        v2beta1_object_metric_source->selector = NULL;
    }
    if (v2beta1_object_metric_source->target) {
        v2beta1_cross_version_object_reference_free(v2beta1_object_metric_source->target);
        v2beta1_object_metric_source->target = NULL;
    }
    if (v2beta1_object_metric_source->target_value) {
        free(v2beta1_object_metric_source->target_value);
        v2beta1_object_metric_source->target_value = NULL;
    }
    free(v2beta1_object_metric_source);
}

cJSON *v2beta1_object_metric_source_convertToJSON(v2beta1_object_metric_source_t *v2beta1_object_metric_source) {
    cJSON *item = cJSON_CreateObject();

    // v2beta1_object_metric_source->average_value
    if(v2beta1_object_metric_source->average_value) { 
    if(cJSON_AddStringToObject(item, "averageValue", v2beta1_object_metric_source->average_value) == NULL) {
    goto fail; //String
    }
     } 


    // v2beta1_object_metric_source->metric_name
    if (!v2beta1_object_metric_source->metric_name) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "metricName", v2beta1_object_metric_source->metric_name) == NULL) {
    goto fail; //String
    }


    // v2beta1_object_metric_source->selector
    if(v2beta1_object_metric_source->selector) { 
    cJSON *selector_local_JSON = v1_label_selector_convertToJSON(v2beta1_object_metric_source->selector);
    if(selector_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "selector", selector_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v2beta1_object_metric_source->target
    if (!v2beta1_object_metric_source->target) {
        goto fail;
    }
    
    cJSON *target_local_JSON = v2beta1_cross_version_object_reference_convertToJSON(v2beta1_object_metric_source->target);
    if(target_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "target", target_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // v2beta1_object_metric_source->target_value
    if (!v2beta1_object_metric_source->target_value) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "targetValue", v2beta1_object_metric_source->target_value) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v2beta1_object_metric_source_t *v2beta1_object_metric_source_parseFromJSON(cJSON *v2beta1_object_metric_sourceJSON){

    v2beta1_object_metric_source_t *v2beta1_object_metric_source_local_var = NULL;

    // v2beta1_object_metric_source->average_value
    cJSON *average_value = cJSON_GetObjectItemCaseSensitive(v2beta1_object_metric_sourceJSON, "averageValue");
    if (average_value) { 
    if(!cJSON_IsString(average_value))
    {
    goto end; //String
    }
    }

    // v2beta1_object_metric_source->metric_name
    cJSON *metric_name = cJSON_GetObjectItemCaseSensitive(v2beta1_object_metric_sourceJSON, "metricName");
    if (!metric_name) {
        goto end;
    }

    
    if(!cJSON_IsString(metric_name))
    {
    goto end; //String
    }

    // v2beta1_object_metric_source->selector
    cJSON *selector = cJSON_GetObjectItemCaseSensitive(v2beta1_object_metric_sourceJSON, "selector");
    v1_label_selector_t *selector_local_nonprim = NULL;
    if (selector) { 
    selector_local_nonprim = v1_label_selector_parseFromJSON(selector); //nonprimitive
    }

    // v2beta1_object_metric_source->target
    cJSON *target = cJSON_GetObjectItemCaseSensitive(v2beta1_object_metric_sourceJSON, "target");
    if (!target) {
        goto end;
    }

    v2beta1_cross_version_object_reference_t *target_local_nonprim = NULL;
    
    target_local_nonprim = v2beta1_cross_version_object_reference_parseFromJSON(target); //nonprimitive

    // v2beta1_object_metric_source->target_value
    cJSON *target_value = cJSON_GetObjectItemCaseSensitive(v2beta1_object_metric_sourceJSON, "targetValue");
    if (!target_value) {
        goto end;
    }

    
    if(!cJSON_IsString(target_value))
    {
    goto end; //String
    }


    v2beta1_object_metric_source_local_var = v2beta1_object_metric_source_create (
        average_value ? strdup(average_value->valuestring) : NULL,
        strdup(metric_name->valuestring),
        selector ? selector_local_nonprim : NULL,
        target_local_nonprim,
        strdup(target_value->valuestring)
        );

    return v2beta1_object_metric_source_local_var;
end:
    if (selector_local_nonprim) {
        v1_label_selector_free(selector_local_nonprim);
        selector_local_nonprim = NULL;
    }
    if (target_local_nonprim) {
        v2beta1_cross_version_object_reference_free(target_local_nonprim);
        target_local_nonprim = NULL;
    }
    return NULL;

}
