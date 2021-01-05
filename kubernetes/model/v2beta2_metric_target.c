#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v2beta2_metric_target.h"



v2beta2_metric_target_t *v2beta2_metric_target_create(
    int average_utilization,
    char *average_value,
    char *type,
    char *value
    ) {
    v2beta2_metric_target_t *v2beta2_metric_target_local_var = malloc(sizeof(v2beta2_metric_target_t));
    if (!v2beta2_metric_target_local_var) {
        return NULL;
    }
    v2beta2_metric_target_local_var->average_utilization = average_utilization;
    v2beta2_metric_target_local_var->average_value = average_value;
    v2beta2_metric_target_local_var->type = type;
    v2beta2_metric_target_local_var->value = value;

    return v2beta2_metric_target_local_var;
}


void v2beta2_metric_target_free(v2beta2_metric_target_t *v2beta2_metric_target) {
    if(NULL == v2beta2_metric_target){
        return ;
    }
    listEntry_t *listEntry;
    if (v2beta2_metric_target->average_value) {
        free(v2beta2_metric_target->average_value);
        v2beta2_metric_target->average_value = NULL;
    }
    if (v2beta2_metric_target->type) {
        free(v2beta2_metric_target->type);
        v2beta2_metric_target->type = NULL;
    }
    if (v2beta2_metric_target->value) {
        free(v2beta2_metric_target->value);
        v2beta2_metric_target->value = NULL;
    }
    free(v2beta2_metric_target);
}

cJSON *v2beta2_metric_target_convertToJSON(v2beta2_metric_target_t *v2beta2_metric_target) {
    cJSON *item = cJSON_CreateObject();

    // v2beta2_metric_target->average_utilization
    if(v2beta2_metric_target->average_utilization) { 
    if(cJSON_AddNumberToObject(item, "averageUtilization", v2beta2_metric_target->average_utilization) == NULL) {
    goto fail; //Numeric
    }
     } 


    // v2beta2_metric_target->average_value
    if(v2beta2_metric_target->average_value) { 
    if(cJSON_AddStringToObject(item, "averageValue", v2beta2_metric_target->average_value) == NULL) {
    goto fail; //String
    }
     } 


    // v2beta2_metric_target->type
    if (!v2beta2_metric_target->type) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "type", v2beta2_metric_target->type) == NULL) {
    goto fail; //String
    }


    // v2beta2_metric_target->value
    if(v2beta2_metric_target->value) { 
    if(cJSON_AddStringToObject(item, "value", v2beta2_metric_target->value) == NULL) {
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

v2beta2_metric_target_t *v2beta2_metric_target_parseFromJSON(cJSON *v2beta2_metric_targetJSON){

    v2beta2_metric_target_t *v2beta2_metric_target_local_var = NULL;

    // v2beta2_metric_target->average_utilization
    cJSON *average_utilization = cJSON_GetObjectItemCaseSensitive(v2beta2_metric_targetJSON, "averageUtilization");
    if (average_utilization) { 
    if(!cJSON_IsNumber(average_utilization))
    {
    goto end; //Numeric
    }
    }

    // v2beta2_metric_target->average_value
    cJSON *average_value = cJSON_GetObjectItemCaseSensitive(v2beta2_metric_targetJSON, "averageValue");
    if (average_value) { 
    if(!cJSON_IsString(average_value))
    {
    goto end; //String
    }
    }

    // v2beta2_metric_target->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(v2beta2_metric_targetJSON, "type");
    if (!type) {
        goto end;
    }

    
    if(!cJSON_IsString(type))
    {
    goto end; //String
    }

    // v2beta2_metric_target->value
    cJSON *value = cJSON_GetObjectItemCaseSensitive(v2beta2_metric_targetJSON, "value");
    if (value) { 
    if(!cJSON_IsString(value))
    {
    goto end; //String
    }
    }


    v2beta2_metric_target_local_var = v2beta2_metric_target_create (
        average_utilization ? average_utilization->valuedouble : 0,
        average_value ? strdup(average_value->valuestring) : NULL,
        strdup(type->valuestring),
        value ? strdup(value->valuestring) : NULL
        );

    return v2beta2_metric_target_local_var;
end:
    return NULL;

}
