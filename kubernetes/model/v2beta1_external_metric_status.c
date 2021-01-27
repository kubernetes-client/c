#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v2beta1_external_metric_status.h"



v2beta1_external_metric_status_t *v2beta1_external_metric_status_create(
    char *current_average_value,
    char *current_value,
    char *metric_name,
    v1_label_selector_t *metric_selector
    ) {
    v2beta1_external_metric_status_t *v2beta1_external_metric_status_local_var = malloc(sizeof(v2beta1_external_metric_status_t));
    if (!v2beta1_external_metric_status_local_var) {
        return NULL;
    }
    v2beta1_external_metric_status_local_var->current_average_value = current_average_value;
    v2beta1_external_metric_status_local_var->current_value = current_value;
    v2beta1_external_metric_status_local_var->metric_name = metric_name;
    v2beta1_external_metric_status_local_var->metric_selector = metric_selector;

    return v2beta1_external_metric_status_local_var;
}


void v2beta1_external_metric_status_free(v2beta1_external_metric_status_t *v2beta1_external_metric_status) {
    if(NULL == v2beta1_external_metric_status){
        return ;
    }
    listEntry_t *listEntry;
    if (v2beta1_external_metric_status->current_average_value) {
        free(v2beta1_external_metric_status->current_average_value);
        v2beta1_external_metric_status->current_average_value = NULL;
    }
    if (v2beta1_external_metric_status->current_value) {
        free(v2beta1_external_metric_status->current_value);
        v2beta1_external_metric_status->current_value = NULL;
    }
    if (v2beta1_external_metric_status->metric_name) {
        free(v2beta1_external_metric_status->metric_name);
        v2beta1_external_metric_status->metric_name = NULL;
    }
    if (v2beta1_external_metric_status->metric_selector) {
        v1_label_selector_free(v2beta1_external_metric_status->metric_selector);
        v2beta1_external_metric_status->metric_selector = NULL;
    }
    free(v2beta1_external_metric_status);
}

cJSON *v2beta1_external_metric_status_convertToJSON(v2beta1_external_metric_status_t *v2beta1_external_metric_status) {
    cJSON *item = cJSON_CreateObject();

    // v2beta1_external_metric_status->current_average_value
    if(v2beta1_external_metric_status->current_average_value) { 
    if(cJSON_AddStringToObject(item, "currentAverageValue", v2beta1_external_metric_status->current_average_value) == NULL) {
    goto fail; //String
    }
     } 


    // v2beta1_external_metric_status->current_value
    if (!v2beta1_external_metric_status->current_value) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "currentValue", v2beta1_external_metric_status->current_value) == NULL) {
    goto fail; //String
    }


    // v2beta1_external_metric_status->metric_name
    if (!v2beta1_external_metric_status->metric_name) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "metricName", v2beta1_external_metric_status->metric_name) == NULL) {
    goto fail; //String
    }


    // v2beta1_external_metric_status->metric_selector
    if(v2beta1_external_metric_status->metric_selector) { 
    cJSON *metric_selector_local_JSON = v1_label_selector_convertToJSON(v2beta1_external_metric_status->metric_selector);
    if(metric_selector_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metricSelector", metric_selector_local_JSON);
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

v2beta1_external_metric_status_t *v2beta1_external_metric_status_parseFromJSON(cJSON *v2beta1_external_metric_statusJSON){

    v2beta1_external_metric_status_t *v2beta1_external_metric_status_local_var = NULL;

    // v2beta1_external_metric_status->current_average_value
    cJSON *current_average_value = cJSON_GetObjectItemCaseSensitive(v2beta1_external_metric_statusJSON, "currentAverageValue");
    if (current_average_value) { 
    if(!cJSON_IsString(current_average_value))
    {
    goto end; //String
    }
    }

    // v2beta1_external_metric_status->current_value
    cJSON *current_value = cJSON_GetObjectItemCaseSensitive(v2beta1_external_metric_statusJSON, "currentValue");
    if (!current_value) {
        goto end;
    }

    
    if(!cJSON_IsString(current_value))
    {
    goto end; //String
    }

    // v2beta1_external_metric_status->metric_name
    cJSON *metric_name = cJSON_GetObjectItemCaseSensitive(v2beta1_external_metric_statusJSON, "metricName");
    if (!metric_name) {
        goto end;
    }

    
    if(!cJSON_IsString(metric_name))
    {
    goto end; //String
    }

    // v2beta1_external_metric_status->metric_selector
    cJSON *metric_selector = cJSON_GetObjectItemCaseSensitive(v2beta1_external_metric_statusJSON, "metricSelector");
    v1_label_selector_t *metric_selector_local_nonprim = NULL;
    if (metric_selector) { 
    metric_selector_local_nonprim = v1_label_selector_parseFromJSON(metric_selector); //nonprimitive
    }


    v2beta1_external_metric_status_local_var = v2beta1_external_metric_status_create (
        current_average_value ? strdup(current_average_value->valuestring) : NULL,
        strdup(current_value->valuestring),
        strdup(metric_name->valuestring),
        metric_selector ? metric_selector_local_nonprim : NULL
        );

    return v2beta1_external_metric_status_local_var;
end:
    if (metric_selector_local_nonprim) {
        v1_label_selector_free(metric_selector_local_nonprim);
        metric_selector_local_nonprim = NULL;
    }
    return NULL;

}
