#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_host_port_range.h"



v1beta1_host_port_range_t *v1beta1_host_port_range_create(
    int max,
    int min
    ) {
    v1beta1_host_port_range_t *v1beta1_host_port_range_local_var = malloc(sizeof(v1beta1_host_port_range_t));
    if (!v1beta1_host_port_range_local_var) {
        return NULL;
    }
    v1beta1_host_port_range_local_var->max = max;
    v1beta1_host_port_range_local_var->min = min;

    return v1beta1_host_port_range_local_var;
}


void v1beta1_host_port_range_free(v1beta1_host_port_range_t *v1beta1_host_port_range) {
    if(NULL == v1beta1_host_port_range){
        return ;
    }
    listEntry_t *listEntry;
    free(v1beta1_host_port_range);
}

cJSON *v1beta1_host_port_range_convertToJSON(v1beta1_host_port_range_t *v1beta1_host_port_range) {
    cJSON *item = cJSON_CreateObject();

    // v1beta1_host_port_range->max
    if (!v1beta1_host_port_range->max) {
        goto fail;
    }
    
    if(cJSON_AddNumberToObject(item, "max", v1beta1_host_port_range->max) == NULL) {
    goto fail; //Numeric
    }


    // v1beta1_host_port_range->min
    if (!v1beta1_host_port_range->min) {
        goto fail;
    }
    
    if(cJSON_AddNumberToObject(item, "min", v1beta1_host_port_range->min) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1beta1_host_port_range_t *v1beta1_host_port_range_parseFromJSON(cJSON *v1beta1_host_port_rangeJSON){

    v1beta1_host_port_range_t *v1beta1_host_port_range_local_var = NULL;

    // v1beta1_host_port_range->max
    cJSON *max = cJSON_GetObjectItemCaseSensitive(v1beta1_host_port_rangeJSON, "max");
    if (!max) {
        goto end;
    }

    
    if(!cJSON_IsNumber(max))
    {
    goto end; //Numeric
    }

    // v1beta1_host_port_range->min
    cJSON *min = cJSON_GetObjectItemCaseSensitive(v1beta1_host_port_rangeJSON, "min");
    if (!min) {
        goto end;
    }

    
    if(!cJSON_IsNumber(min))
    {
    goto end; //Numeric
    }


    v1beta1_host_port_range_local_var = v1beta1_host_port_range_create (
        max->valuedouble,
        min->valuedouble
        );

    return v1beta1_host_port_range_local_var;
end:
    return NULL;

}
