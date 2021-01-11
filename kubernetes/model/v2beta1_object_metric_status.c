#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v2beta1_object_metric_status.h"



v2beta1_object_metric_status_t *v2beta1_object_metric_status_create(
    char *average_value,
    char *current_value,
    char *metric_name,
    v1_label_selector_t *selector,
    v2beta1_cross_version_object_reference_t *target
    ) {
    v2beta1_object_metric_status_t *v2beta1_object_metric_status_local_var = malloc(sizeof(v2beta1_object_metric_status_t));
    if (!v2beta1_object_metric_status_local_var) {
        return NULL;
    }
    v2beta1_object_metric_status_local_var->average_value = average_value;
    v2beta1_object_metric_status_local_var->current_value = current_value;
    v2beta1_object_metric_status_local_var->metric_name = metric_name;
    v2beta1_object_metric_status_local_var->selector = selector;
    v2beta1_object_metric_status_local_var->target = target;

    return v2beta1_object_metric_status_local_var;
}


void v2beta1_object_metric_status_free(v2beta1_object_metric_status_t *v2beta1_object_metric_status) {
    if(NULL == v2beta1_object_metric_status){
        return ;
    }
    listEntry_t *listEntry;
    if (v2beta1_object_metric_status->average_value) {
        free(v2beta1_object_metric_status->average_value);
        v2beta1_object_metric_status->average_value = NULL;
    }
    if (v2beta1_object_metric_status->current_value) {
        free(v2beta1_object_metric_status->current_value);
        v2beta1_object_metric_status->current_value = NULL;
    }
    if (v2beta1_object_metric_status->metric_name) {
        free(v2beta1_object_metric_status->metric_name);
        v2beta1_object_metric_status->metric_name = NULL;
    }
    if (v2beta1_object_metric_status->selector) {
        v1_label_selector_free(v2beta1_object_metric_status->selector);
        v2beta1_object_metric_status->selector = NULL;
    }
    if (v2beta1_object_metric_status->target) {
        v2beta1_cross_version_object_reference_free(v2beta1_object_metric_status->target);
        v2beta1_object_metric_status->target = NULL;
    }
    free(v2beta1_object_metric_status);
}

cJSON *v2beta1_object_metric_status_convertToJSON(v2beta1_object_metric_status_t *v2beta1_object_metric_status) {
    cJSON *item = cJSON_CreateObject();

    // v2beta1_object_metric_status->average_value
    if(v2beta1_object_metric_status->average_value) { 
    if(cJSON_AddStringToObject(item, "averageValue", v2beta1_object_metric_status->average_value) == NULL) {
    goto fail; //String
    }
     } 


    // v2beta1_object_metric_status->current_value
    if (!v2beta1_object_metric_status->current_value) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "currentValue", v2beta1_object_metric_status->current_value) == NULL) {
    goto fail; //String
    }


    // v2beta1_object_metric_status->metric_name
    if (!v2beta1_object_metric_status->metric_name) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "metricName", v2beta1_object_metric_status->metric_name) == NULL) {
    goto fail; //String
    }


    // v2beta1_object_metric_status->selector
    if(v2beta1_object_metric_status->selector) { 
    cJSON *selector_local_JSON = v1_label_selector_convertToJSON(v2beta1_object_metric_status->selector);
    if(selector_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "selector", selector_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v2beta1_object_metric_status->target
    if (!v2beta1_object_metric_status->target) {
        goto fail;
    }
    
    cJSON *target_local_JSON = v2beta1_cross_version_object_reference_convertToJSON(v2beta1_object_metric_status->target);
    if(target_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "target", target_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v2beta1_object_metric_status_t *v2beta1_object_metric_status_parseFromJSON(cJSON *v2beta1_object_metric_statusJSON){

    v2beta1_object_metric_status_t *v2beta1_object_metric_status_local_var = NULL;

    // v2beta1_object_metric_status->average_value
    cJSON *average_value = cJSON_GetObjectItemCaseSensitive(v2beta1_object_metric_statusJSON, "averageValue");
    if (average_value) { 
    if(!cJSON_IsString(average_value))
    {
    goto end; //String
    }
    }

    // v2beta1_object_metric_status->current_value
    cJSON *current_value = cJSON_GetObjectItemCaseSensitive(v2beta1_object_metric_statusJSON, "currentValue");
    if (!current_value) {
        goto end;
    }

    
    if(!cJSON_IsString(current_value))
    {
    goto end; //String
    }

    // v2beta1_object_metric_status->metric_name
    cJSON *metric_name = cJSON_GetObjectItemCaseSensitive(v2beta1_object_metric_statusJSON, "metricName");
    if (!metric_name) {
        goto end;
    }

    
    if(!cJSON_IsString(metric_name))
    {
    goto end; //String
    }

    // v2beta1_object_metric_status->selector
    cJSON *selector = cJSON_GetObjectItemCaseSensitive(v2beta1_object_metric_statusJSON, "selector");
    v1_label_selector_t *selector_local_nonprim = NULL;
    if (selector) { 
    selector_local_nonprim = v1_label_selector_parseFromJSON(selector); //nonprimitive
    }

    // v2beta1_object_metric_status->target
    cJSON *target = cJSON_GetObjectItemCaseSensitive(v2beta1_object_metric_statusJSON, "target");
    if (!target) {
        goto end;
    }

    v2beta1_cross_version_object_reference_t *target_local_nonprim = NULL;
    
    target_local_nonprim = v2beta1_cross_version_object_reference_parseFromJSON(target); //nonprimitive


    v2beta1_object_metric_status_local_var = v2beta1_object_metric_status_create (
        average_value ? strdup(average_value->valuestring) : NULL,
        strdup(current_value->valuestring),
        strdup(metric_name->valuestring),
        selector ? selector_local_nonprim : NULL,
        target_local_nonprim
        );

    return v2beta1_object_metric_status_local_var;
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
