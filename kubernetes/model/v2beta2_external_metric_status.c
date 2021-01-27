#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v2beta2_external_metric_status.h"



v2beta2_external_metric_status_t *v2beta2_external_metric_status_create(
    v2beta2_metric_value_status_t *current,
    v2beta2_metric_identifier_t *metric
    ) {
    v2beta2_external_metric_status_t *v2beta2_external_metric_status_local_var = malloc(sizeof(v2beta2_external_metric_status_t));
    if (!v2beta2_external_metric_status_local_var) {
        return NULL;
    }
    v2beta2_external_metric_status_local_var->current = current;
    v2beta2_external_metric_status_local_var->metric = metric;

    return v2beta2_external_metric_status_local_var;
}


void v2beta2_external_metric_status_free(v2beta2_external_metric_status_t *v2beta2_external_metric_status) {
    if(NULL == v2beta2_external_metric_status){
        return ;
    }
    listEntry_t *listEntry;
    if (v2beta2_external_metric_status->current) {
        v2beta2_metric_value_status_free(v2beta2_external_metric_status->current);
        v2beta2_external_metric_status->current = NULL;
    }
    if (v2beta2_external_metric_status->metric) {
        v2beta2_metric_identifier_free(v2beta2_external_metric_status->metric);
        v2beta2_external_metric_status->metric = NULL;
    }
    free(v2beta2_external_metric_status);
}

cJSON *v2beta2_external_metric_status_convertToJSON(v2beta2_external_metric_status_t *v2beta2_external_metric_status) {
    cJSON *item = cJSON_CreateObject();

    // v2beta2_external_metric_status->current
    if (!v2beta2_external_metric_status->current) {
        goto fail;
    }
    
    cJSON *current_local_JSON = v2beta2_metric_value_status_convertToJSON(v2beta2_external_metric_status->current);
    if(current_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "current", current_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // v2beta2_external_metric_status->metric
    if (!v2beta2_external_metric_status->metric) {
        goto fail;
    }
    
    cJSON *metric_local_JSON = v2beta2_metric_identifier_convertToJSON(v2beta2_external_metric_status->metric);
    if(metric_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metric", metric_local_JSON);
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

v2beta2_external_metric_status_t *v2beta2_external_metric_status_parseFromJSON(cJSON *v2beta2_external_metric_statusJSON){

    v2beta2_external_metric_status_t *v2beta2_external_metric_status_local_var = NULL;

    // v2beta2_external_metric_status->current
    cJSON *current = cJSON_GetObjectItemCaseSensitive(v2beta2_external_metric_statusJSON, "current");
    if (!current) {
        goto end;
    }

    v2beta2_metric_value_status_t *current_local_nonprim = NULL;
    
    current_local_nonprim = v2beta2_metric_value_status_parseFromJSON(current); //nonprimitive

    // v2beta2_external_metric_status->metric
    cJSON *metric = cJSON_GetObjectItemCaseSensitive(v2beta2_external_metric_statusJSON, "metric");
    if (!metric) {
        goto end;
    }

    v2beta2_metric_identifier_t *metric_local_nonprim = NULL;
    
    metric_local_nonprim = v2beta2_metric_identifier_parseFromJSON(metric); //nonprimitive


    v2beta2_external_metric_status_local_var = v2beta2_external_metric_status_create (
        current_local_nonprim,
        metric_local_nonprim
        );

    return v2beta2_external_metric_status_local_var;
end:
    if (current_local_nonprim) {
        v2beta2_metric_value_status_free(current_local_nonprim);
        current_local_nonprim = NULL;
    }
    if (metric_local_nonprim) {
        v2beta2_metric_identifier_free(metric_local_nonprim);
        metric_local_nonprim = NULL;
    }
    return NULL;

}
