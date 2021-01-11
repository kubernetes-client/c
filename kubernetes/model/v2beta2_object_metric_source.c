#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v2beta2_object_metric_source.h"



v2beta2_object_metric_source_t *v2beta2_object_metric_source_create(
    v2beta2_cross_version_object_reference_t *described_object,
    v2beta2_metric_identifier_t *metric,
    v2beta2_metric_target_t *target
    ) {
    v2beta2_object_metric_source_t *v2beta2_object_metric_source_local_var = malloc(sizeof(v2beta2_object_metric_source_t));
    if (!v2beta2_object_metric_source_local_var) {
        return NULL;
    }
    v2beta2_object_metric_source_local_var->described_object = described_object;
    v2beta2_object_metric_source_local_var->metric = metric;
    v2beta2_object_metric_source_local_var->target = target;

    return v2beta2_object_metric_source_local_var;
}


void v2beta2_object_metric_source_free(v2beta2_object_metric_source_t *v2beta2_object_metric_source) {
    if(NULL == v2beta2_object_metric_source){
        return ;
    }
    listEntry_t *listEntry;
    if (v2beta2_object_metric_source->described_object) {
        v2beta2_cross_version_object_reference_free(v2beta2_object_metric_source->described_object);
        v2beta2_object_metric_source->described_object = NULL;
    }
    if (v2beta2_object_metric_source->metric) {
        v2beta2_metric_identifier_free(v2beta2_object_metric_source->metric);
        v2beta2_object_metric_source->metric = NULL;
    }
    if (v2beta2_object_metric_source->target) {
        v2beta2_metric_target_free(v2beta2_object_metric_source->target);
        v2beta2_object_metric_source->target = NULL;
    }
    free(v2beta2_object_metric_source);
}

cJSON *v2beta2_object_metric_source_convertToJSON(v2beta2_object_metric_source_t *v2beta2_object_metric_source) {
    cJSON *item = cJSON_CreateObject();

    // v2beta2_object_metric_source->described_object
    if (!v2beta2_object_metric_source->described_object) {
        goto fail;
    }
    
    cJSON *described_object_local_JSON = v2beta2_cross_version_object_reference_convertToJSON(v2beta2_object_metric_source->described_object);
    if(described_object_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "describedObject", described_object_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // v2beta2_object_metric_source->metric
    if (!v2beta2_object_metric_source->metric) {
        goto fail;
    }
    
    cJSON *metric_local_JSON = v2beta2_metric_identifier_convertToJSON(v2beta2_object_metric_source->metric);
    if(metric_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metric", metric_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // v2beta2_object_metric_source->target
    if (!v2beta2_object_metric_source->target) {
        goto fail;
    }
    
    cJSON *target_local_JSON = v2beta2_metric_target_convertToJSON(v2beta2_object_metric_source->target);
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

v2beta2_object_metric_source_t *v2beta2_object_metric_source_parseFromJSON(cJSON *v2beta2_object_metric_sourceJSON){

    v2beta2_object_metric_source_t *v2beta2_object_metric_source_local_var = NULL;

    // v2beta2_object_metric_source->described_object
    cJSON *described_object = cJSON_GetObjectItemCaseSensitive(v2beta2_object_metric_sourceJSON, "describedObject");
    if (!described_object) {
        goto end;
    }

    v2beta2_cross_version_object_reference_t *described_object_local_nonprim = NULL;
    
    described_object_local_nonprim = v2beta2_cross_version_object_reference_parseFromJSON(described_object); //nonprimitive

    // v2beta2_object_metric_source->metric
    cJSON *metric = cJSON_GetObjectItemCaseSensitive(v2beta2_object_metric_sourceJSON, "metric");
    if (!metric) {
        goto end;
    }

    v2beta2_metric_identifier_t *metric_local_nonprim = NULL;
    
    metric_local_nonprim = v2beta2_metric_identifier_parseFromJSON(metric); //nonprimitive

    // v2beta2_object_metric_source->target
    cJSON *target = cJSON_GetObjectItemCaseSensitive(v2beta2_object_metric_sourceJSON, "target");
    if (!target) {
        goto end;
    }

    v2beta2_metric_target_t *target_local_nonprim = NULL;
    
    target_local_nonprim = v2beta2_metric_target_parseFromJSON(target); //nonprimitive


    v2beta2_object_metric_source_local_var = v2beta2_object_metric_source_create (
        described_object_local_nonprim,
        metric_local_nonprim,
        target_local_nonprim
        );

    return v2beta2_object_metric_source_local_var;
end:
    if (described_object_local_nonprim) {
        v2beta2_cross_version_object_reference_free(described_object_local_nonprim);
        described_object_local_nonprim = NULL;
    }
    if (metric_local_nonprim) {
        v2beta2_metric_identifier_free(metric_local_nonprim);
        metric_local_nonprim = NULL;
    }
    if (target_local_nonprim) {
        v2beta2_metric_target_free(target_local_nonprim);
        target_local_nonprim = NULL;
    }
    return NULL;

}
