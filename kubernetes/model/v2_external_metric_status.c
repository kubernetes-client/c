#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v2_external_metric_status.h"



static v2_external_metric_status_t *v2_external_metric_status_create_internal(
    v2_metric_value_status_t *current,
    v2_metric_identifier_t *metric
    ) {
    v2_external_metric_status_t *v2_external_metric_status_local_var = malloc(sizeof(v2_external_metric_status_t));
    if (!v2_external_metric_status_local_var) {
        return NULL;
    }
    v2_external_metric_status_local_var->current = current;
    v2_external_metric_status_local_var->metric = metric;

    v2_external_metric_status_local_var->_library_owned = 1;
    return v2_external_metric_status_local_var;
}

__attribute__((deprecated)) v2_external_metric_status_t *v2_external_metric_status_create(
    v2_metric_value_status_t *current,
    v2_metric_identifier_t *metric
    ) {
    return v2_external_metric_status_create_internal (
        current,
        metric
        );
}

void v2_external_metric_status_free(v2_external_metric_status_t *v2_external_metric_status) {
    if(NULL == v2_external_metric_status){
        return ;
    }
    if(v2_external_metric_status->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v2_external_metric_status_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v2_external_metric_status->current) {
        v2_metric_value_status_free(v2_external_metric_status->current);
        v2_external_metric_status->current = NULL;
    }
    if (v2_external_metric_status->metric) {
        v2_metric_identifier_free(v2_external_metric_status->metric);
        v2_external_metric_status->metric = NULL;
    }
    free(v2_external_metric_status);
}

cJSON *v2_external_metric_status_convertToJSON(v2_external_metric_status_t *v2_external_metric_status) {
    cJSON *item = cJSON_CreateObject();

    // v2_external_metric_status->current
    if (!v2_external_metric_status->current) {
        goto fail;
    }
    cJSON *current_local_JSON = v2_metric_value_status_convertToJSON(v2_external_metric_status->current);
    if(current_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "current", current_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // v2_external_metric_status->metric
    if (!v2_external_metric_status->metric) {
        goto fail;
    }
    cJSON *metric_local_JSON = v2_metric_identifier_convertToJSON(v2_external_metric_status->metric);
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

v2_external_metric_status_t *v2_external_metric_status_parseFromJSON(cJSON *v2_external_metric_statusJSON){

    v2_external_metric_status_t *v2_external_metric_status_local_var = NULL;

    // define the local variable for v2_external_metric_status->current
    v2_metric_value_status_t *current_local_nonprim = NULL;

    // define the local variable for v2_external_metric_status->metric
    v2_metric_identifier_t *metric_local_nonprim = NULL;

    // v2_external_metric_status->current
    cJSON *current = cJSON_GetObjectItemCaseSensitive(v2_external_metric_statusJSON, "current");
    if (cJSON_IsNull(current)) {
        current = NULL;
    }
    if (!current) {
        goto end;
    }

    
    current_local_nonprim = v2_metric_value_status_parseFromJSON(current); //nonprimitive

    // v2_external_metric_status->metric
    cJSON *metric = cJSON_GetObjectItemCaseSensitive(v2_external_metric_statusJSON, "metric");
    if (cJSON_IsNull(metric)) {
        metric = NULL;
    }
    if (!metric) {
        goto end;
    }

    
    metric_local_nonprim = v2_metric_identifier_parseFromJSON(metric); //nonprimitive


    v2_external_metric_status_local_var = v2_external_metric_status_create_internal (
        current_local_nonprim,
        metric_local_nonprim
        );

    return v2_external_metric_status_local_var;
end:
    if (current_local_nonprim) {
        v2_metric_value_status_free(current_local_nonprim);
        current_local_nonprim = NULL;
    }
    if (metric_local_nonprim) {
        v2_metric_identifier_free(metric_local_nonprim);
        metric_local_nonprim = NULL;
    }
    return NULL;

}
