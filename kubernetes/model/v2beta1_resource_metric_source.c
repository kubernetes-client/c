#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v2beta1_resource_metric_source.h"



v2beta1_resource_metric_source_t *v2beta1_resource_metric_source_create(
    char *name,
    int target_average_utilization,
    char *target_average_value
    ) {
    v2beta1_resource_metric_source_t *v2beta1_resource_metric_source_local_var = malloc(sizeof(v2beta1_resource_metric_source_t));
    if (!v2beta1_resource_metric_source_local_var) {
        return NULL;
    }
    v2beta1_resource_metric_source_local_var->name = name;
    v2beta1_resource_metric_source_local_var->target_average_utilization = target_average_utilization;
    v2beta1_resource_metric_source_local_var->target_average_value = target_average_value;

    return v2beta1_resource_metric_source_local_var;
}


void v2beta1_resource_metric_source_free(v2beta1_resource_metric_source_t *v2beta1_resource_metric_source) {
    if(NULL == v2beta1_resource_metric_source){
        return ;
    }
    listEntry_t *listEntry;
    if (v2beta1_resource_metric_source->name) {
        free(v2beta1_resource_metric_source->name);
        v2beta1_resource_metric_source->name = NULL;
    }
    if (v2beta1_resource_metric_source->target_average_value) {
        free(v2beta1_resource_metric_source->target_average_value);
        v2beta1_resource_metric_source->target_average_value = NULL;
    }
    free(v2beta1_resource_metric_source);
}

cJSON *v2beta1_resource_metric_source_convertToJSON(v2beta1_resource_metric_source_t *v2beta1_resource_metric_source) {
    cJSON *item = cJSON_CreateObject();

    // v2beta1_resource_metric_source->name
    if (!v2beta1_resource_metric_source->name) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "name", v2beta1_resource_metric_source->name) == NULL) {
    goto fail; //String
    }


    // v2beta1_resource_metric_source->target_average_utilization
    if(v2beta1_resource_metric_source->target_average_utilization) { 
    if(cJSON_AddNumberToObject(item, "targetAverageUtilization", v2beta1_resource_metric_source->target_average_utilization) == NULL) {
    goto fail; //Numeric
    }
     } 


    // v2beta1_resource_metric_source->target_average_value
    if(v2beta1_resource_metric_source->target_average_value) { 
    if(cJSON_AddStringToObject(item, "targetAverageValue", v2beta1_resource_metric_source->target_average_value) == NULL) {
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

v2beta1_resource_metric_source_t *v2beta1_resource_metric_source_parseFromJSON(cJSON *v2beta1_resource_metric_sourceJSON){

    v2beta1_resource_metric_source_t *v2beta1_resource_metric_source_local_var = NULL;

    // v2beta1_resource_metric_source->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v2beta1_resource_metric_sourceJSON, "name");
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // v2beta1_resource_metric_source->target_average_utilization
    cJSON *target_average_utilization = cJSON_GetObjectItemCaseSensitive(v2beta1_resource_metric_sourceJSON, "targetAverageUtilization");
    if (target_average_utilization) { 
    if(!cJSON_IsNumber(target_average_utilization))
    {
    goto end; //Numeric
    }
    }

    // v2beta1_resource_metric_source->target_average_value
    cJSON *target_average_value = cJSON_GetObjectItemCaseSensitive(v2beta1_resource_metric_sourceJSON, "targetAverageValue");
    if (target_average_value) { 
    if(!cJSON_IsString(target_average_value))
    {
    goto end; //String
    }
    }


    v2beta1_resource_metric_source_local_var = v2beta1_resource_metric_source_create (
        strdup(name->valuestring),
        target_average_utilization ? target_average_utilization->valuedouble : 0,
        target_average_value ? strdup(target_average_value->valuestring) : NULL
        );

    return v2beta1_resource_metric_source_local_var;
end:
    return NULL;

}
