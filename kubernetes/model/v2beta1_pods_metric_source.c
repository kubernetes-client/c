#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v2beta1_pods_metric_source.h"



v2beta1_pods_metric_source_t *v2beta1_pods_metric_source_create(
    char *metric_name,
    v1_label_selector_t *selector,
    char *target_average_value
    ) {
    v2beta1_pods_metric_source_t *v2beta1_pods_metric_source_local_var = malloc(sizeof(v2beta1_pods_metric_source_t));
    if (!v2beta1_pods_metric_source_local_var) {
        return NULL;
    }
    v2beta1_pods_metric_source_local_var->metric_name = metric_name;
    v2beta1_pods_metric_source_local_var->selector = selector;
    v2beta1_pods_metric_source_local_var->target_average_value = target_average_value;

    return v2beta1_pods_metric_source_local_var;
}


void v2beta1_pods_metric_source_free(v2beta1_pods_metric_source_t *v2beta1_pods_metric_source) {
    if(NULL == v2beta1_pods_metric_source){
        return ;
    }
    listEntry_t *listEntry;
    if (v2beta1_pods_metric_source->metric_name) {
        free(v2beta1_pods_metric_source->metric_name);
        v2beta1_pods_metric_source->metric_name = NULL;
    }
    if (v2beta1_pods_metric_source->selector) {
        v1_label_selector_free(v2beta1_pods_metric_source->selector);
        v2beta1_pods_metric_source->selector = NULL;
    }
    if (v2beta1_pods_metric_source->target_average_value) {
        free(v2beta1_pods_metric_source->target_average_value);
        v2beta1_pods_metric_source->target_average_value = NULL;
    }
    free(v2beta1_pods_metric_source);
}

cJSON *v2beta1_pods_metric_source_convertToJSON(v2beta1_pods_metric_source_t *v2beta1_pods_metric_source) {
    cJSON *item = cJSON_CreateObject();

    // v2beta1_pods_metric_source->metric_name
    if (!v2beta1_pods_metric_source->metric_name) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "metricName", v2beta1_pods_metric_source->metric_name) == NULL) {
    goto fail; //String
    }


    // v2beta1_pods_metric_source->selector
    if(v2beta1_pods_metric_source->selector) { 
    cJSON *selector_local_JSON = v1_label_selector_convertToJSON(v2beta1_pods_metric_source->selector);
    if(selector_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "selector", selector_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v2beta1_pods_metric_source->target_average_value
    if (!v2beta1_pods_metric_source->target_average_value) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "targetAverageValue", v2beta1_pods_metric_source->target_average_value) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v2beta1_pods_metric_source_t *v2beta1_pods_metric_source_parseFromJSON(cJSON *v2beta1_pods_metric_sourceJSON){

    v2beta1_pods_metric_source_t *v2beta1_pods_metric_source_local_var = NULL;

    // v2beta1_pods_metric_source->metric_name
    cJSON *metric_name = cJSON_GetObjectItemCaseSensitive(v2beta1_pods_metric_sourceJSON, "metricName");
    if (!metric_name) {
        goto end;
    }

    
    if(!cJSON_IsString(metric_name))
    {
    goto end; //String
    }

    // v2beta1_pods_metric_source->selector
    cJSON *selector = cJSON_GetObjectItemCaseSensitive(v2beta1_pods_metric_sourceJSON, "selector");
    v1_label_selector_t *selector_local_nonprim = NULL;
    if (selector) { 
    selector_local_nonprim = v1_label_selector_parseFromJSON(selector); //nonprimitive
    }

    // v2beta1_pods_metric_source->target_average_value
    cJSON *target_average_value = cJSON_GetObjectItemCaseSensitive(v2beta1_pods_metric_sourceJSON, "targetAverageValue");
    if (!target_average_value) {
        goto end;
    }

    
    if(!cJSON_IsString(target_average_value))
    {
    goto end; //String
    }


    v2beta1_pods_metric_source_local_var = v2beta1_pods_metric_source_create (
        strdup(metric_name->valuestring),
        selector ? selector_local_nonprim : NULL,
        strdup(target_average_value->valuestring)
        );

    return v2beta1_pods_metric_source_local_var;
end:
    if (selector_local_nonprim) {
        v1_label_selector_free(selector_local_nonprim);
        selector_local_nonprim = NULL;
    }
    return NULL;

}
