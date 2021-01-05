#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v2beta2_metric_value_status.h"



v2beta2_metric_value_status_t *v2beta2_metric_value_status_create(
    int average_utilization,
    char *average_value,
    char *value
    ) {
    v2beta2_metric_value_status_t *v2beta2_metric_value_status_local_var = malloc(sizeof(v2beta2_metric_value_status_t));
    if (!v2beta2_metric_value_status_local_var) {
        return NULL;
    }
    v2beta2_metric_value_status_local_var->average_utilization = average_utilization;
    v2beta2_metric_value_status_local_var->average_value = average_value;
    v2beta2_metric_value_status_local_var->value = value;

    return v2beta2_metric_value_status_local_var;
}


void v2beta2_metric_value_status_free(v2beta2_metric_value_status_t *v2beta2_metric_value_status) {
    if(NULL == v2beta2_metric_value_status){
        return ;
    }
    listEntry_t *listEntry;
    if (v2beta2_metric_value_status->average_value) {
        free(v2beta2_metric_value_status->average_value);
        v2beta2_metric_value_status->average_value = NULL;
    }
    if (v2beta2_metric_value_status->value) {
        free(v2beta2_metric_value_status->value);
        v2beta2_metric_value_status->value = NULL;
    }
    free(v2beta2_metric_value_status);
}

cJSON *v2beta2_metric_value_status_convertToJSON(v2beta2_metric_value_status_t *v2beta2_metric_value_status) {
    cJSON *item = cJSON_CreateObject();

    // v2beta2_metric_value_status->average_utilization
    if(v2beta2_metric_value_status->average_utilization) { 
    if(cJSON_AddNumberToObject(item, "averageUtilization", v2beta2_metric_value_status->average_utilization) == NULL) {
    goto fail; //Numeric
    }
     } 


    // v2beta2_metric_value_status->average_value
    if(v2beta2_metric_value_status->average_value) { 
    if(cJSON_AddStringToObject(item, "averageValue", v2beta2_metric_value_status->average_value) == NULL) {
    goto fail; //String
    }
     } 


    // v2beta2_metric_value_status->value
    if(v2beta2_metric_value_status->value) { 
    if(cJSON_AddStringToObject(item, "value", v2beta2_metric_value_status->value) == NULL) {
    goto fail; //String
    }
     } 

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v2beta2_metric_value_status_t *v2beta2_metric_value_status_parseFromJSON(cJSON *v2beta2_metric_value_statusJSON){

    v2beta2_metric_value_status_t *v2beta2_metric_value_status_local_var = NULL;

    // v2beta2_metric_value_status->average_utilization
    cJSON *average_utilization = cJSON_GetObjectItemCaseSensitive(v2beta2_metric_value_statusJSON, "averageUtilization");
    if (average_utilization) { 
    if(!cJSON_IsNumber(average_utilization))
    {
    goto end; //Numeric
    }
    }

    // v2beta2_metric_value_status->average_value
    cJSON *average_value = cJSON_GetObjectItemCaseSensitive(v2beta2_metric_value_statusJSON, "averageValue");
    if (average_value) { 
    if(!cJSON_IsString(average_value))
    {
    goto end; //String
    }
    }

    // v2beta2_metric_value_status->value
    cJSON *value = cJSON_GetObjectItemCaseSensitive(v2beta2_metric_value_statusJSON, "value");
    if (value) { 
    if(!cJSON_IsString(value))
    {
    goto end; //String
    }
    }


    v2beta2_metric_value_status_local_var = v2beta2_metric_value_status_create (
        average_utilization ? average_utilization->valuedouble : 0,
        average_value ? strdup(average_value->valuestring) : NULL,
        value ? strdup(value->valuestring) : NULL
        );

    return v2beta2_metric_value_status_local_var;
end:
    return NULL;

}
