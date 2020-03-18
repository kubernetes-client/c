#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "extensions_v1beta1_host_port_range.h"



extensions_v1beta1_host_port_range_t *extensions_v1beta1_host_port_range_create(
    int max,
    int min
    ) {
    extensions_v1beta1_host_port_range_t *extensions_v1beta1_host_port_range_local_var = malloc(sizeof(extensions_v1beta1_host_port_range_t));
    if (!extensions_v1beta1_host_port_range_local_var) {
        return NULL;
    }
    extensions_v1beta1_host_port_range_local_var->max = max;
    extensions_v1beta1_host_port_range_local_var->min = min;

    return extensions_v1beta1_host_port_range_local_var;
}


void extensions_v1beta1_host_port_range_free(extensions_v1beta1_host_port_range_t *extensions_v1beta1_host_port_range) {
    if(NULL == extensions_v1beta1_host_port_range){
        return ;
    }
    listEntry_t *listEntry;
    free(extensions_v1beta1_host_port_range);
}

cJSON *extensions_v1beta1_host_port_range_convertToJSON(extensions_v1beta1_host_port_range_t *extensions_v1beta1_host_port_range) {
    cJSON *item = cJSON_CreateObject();

    // extensions_v1beta1_host_port_range->max
    if (!extensions_v1beta1_host_port_range->max) {
        goto fail;
    }
    
    if(cJSON_AddNumberToObject(item, "max", extensions_v1beta1_host_port_range->max) == NULL) {
    goto fail; //Numeric
    }


    // extensions_v1beta1_host_port_range->min
    if (!extensions_v1beta1_host_port_range->min) {
        goto fail;
    }
    
    if(cJSON_AddNumberToObject(item, "min", extensions_v1beta1_host_port_range->min) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

extensions_v1beta1_host_port_range_t *extensions_v1beta1_host_port_range_parseFromJSON(cJSON *extensions_v1beta1_host_port_rangeJSON){

    extensions_v1beta1_host_port_range_t *extensions_v1beta1_host_port_range_local_var = NULL;

    // extensions_v1beta1_host_port_range->max
    cJSON *max = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_host_port_rangeJSON, "max");
    if (!max) {
        goto end;
    }

    
    if(!cJSON_IsNumber(max))
    {
    goto end; //Numeric
    }

    // extensions_v1beta1_host_port_range->min
    cJSON *min = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_host_port_rangeJSON, "min");
    if (!min) {
        goto end;
    }

    
    if(!cJSON_IsNumber(min))
    {
    goto end; //Numeric
    }


    extensions_v1beta1_host_port_range_local_var = extensions_v1beta1_host_port_range_create (
        max->valuedouble,
        min->valuedouble
        );

    return extensions_v1beta1_host_port_range_local_var;
end:
    return NULL;

}
