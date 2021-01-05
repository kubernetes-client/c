#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v2beta1_resource_metric_status.h"



v2beta1_resource_metric_status_t *v2beta1_resource_metric_status_create(
    int current_average_utilization,
    char *current_average_value,
    char *name
    ) {
    v2beta1_resource_metric_status_t *v2beta1_resource_metric_status_local_var = malloc(sizeof(v2beta1_resource_metric_status_t));
    if (!v2beta1_resource_metric_status_local_var) {
        return NULL;
    }
    v2beta1_resource_metric_status_local_var->current_average_utilization = current_average_utilization;
    v2beta1_resource_metric_status_local_var->current_average_value = current_average_value;
    v2beta1_resource_metric_status_local_var->name = name;

    return v2beta1_resource_metric_status_local_var;
}


void v2beta1_resource_metric_status_free(v2beta1_resource_metric_status_t *v2beta1_resource_metric_status) {
    if(NULL == v2beta1_resource_metric_status){
        return ;
    }
    listEntry_t *listEntry;
    if (v2beta1_resource_metric_status->current_average_value) {
        free(v2beta1_resource_metric_status->current_average_value);
        v2beta1_resource_metric_status->current_average_value = NULL;
    }
    if (v2beta1_resource_metric_status->name) {
        free(v2beta1_resource_metric_status->name);
        v2beta1_resource_metric_status->name = NULL;
    }
    free(v2beta1_resource_metric_status);
}

cJSON *v2beta1_resource_metric_status_convertToJSON(v2beta1_resource_metric_status_t *v2beta1_resource_metric_status) {
    cJSON *item = cJSON_CreateObject();

    // v2beta1_resource_metric_status->current_average_utilization
    if(v2beta1_resource_metric_status->current_average_utilization) { 
    if(cJSON_AddNumberToObject(item, "currentAverageUtilization", v2beta1_resource_metric_status->current_average_utilization) == NULL) {
    goto fail; //Numeric
    }
     } 


    // v2beta1_resource_metric_status->current_average_value
    if (!v2beta1_resource_metric_status->current_average_value) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "currentAverageValue", v2beta1_resource_metric_status->current_average_value) == NULL) {
    goto fail; //String
    }


    // v2beta1_resource_metric_status->name
    if (!v2beta1_resource_metric_status->name) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "name", v2beta1_resource_metric_status->name) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v2beta1_resource_metric_status_t *v2beta1_resource_metric_status_parseFromJSON(cJSON *v2beta1_resource_metric_statusJSON){

    v2beta1_resource_metric_status_t *v2beta1_resource_metric_status_local_var = NULL;

    // v2beta1_resource_metric_status->current_average_utilization
    cJSON *current_average_utilization = cJSON_GetObjectItemCaseSensitive(v2beta1_resource_metric_statusJSON, "currentAverageUtilization");
    if (current_average_utilization) { 
    if(!cJSON_IsNumber(current_average_utilization))
    {
    goto end; //Numeric
    }
    }

    // v2beta1_resource_metric_status->current_average_value
    cJSON *current_average_value = cJSON_GetObjectItemCaseSensitive(v2beta1_resource_metric_statusJSON, "currentAverageValue");
    if (!current_average_value) {
        goto end;
    }

    
    if(!cJSON_IsString(current_average_value))
    {
    goto end; //String
    }

    // v2beta1_resource_metric_status->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v2beta1_resource_metric_statusJSON, "name");
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }


    v2beta1_resource_metric_status_local_var = v2beta1_resource_metric_status_create (
        current_average_utilization ? current_average_utilization->valuedouble : 0,
        strdup(current_average_value->valuestring),
        strdup(name->valuestring)
        );

    return v2beta1_resource_metric_status_local_var;
end:
    return NULL;

}
