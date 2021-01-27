#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v2beta2_resource_metric_status.h"



v2beta2_resource_metric_status_t *v2beta2_resource_metric_status_create(
    v2beta2_metric_value_status_t *current,
    char *name
    ) {
    v2beta2_resource_metric_status_t *v2beta2_resource_metric_status_local_var = malloc(sizeof(v2beta2_resource_metric_status_t));
    if (!v2beta2_resource_metric_status_local_var) {
        return NULL;
    }
    v2beta2_resource_metric_status_local_var->current = current;
    v2beta2_resource_metric_status_local_var->name = name;

    return v2beta2_resource_metric_status_local_var;
}


void v2beta2_resource_metric_status_free(v2beta2_resource_metric_status_t *v2beta2_resource_metric_status) {
    if(NULL == v2beta2_resource_metric_status){
        return ;
    }
    listEntry_t *listEntry;
    if (v2beta2_resource_metric_status->current) {
        v2beta2_metric_value_status_free(v2beta2_resource_metric_status->current);
        v2beta2_resource_metric_status->current = NULL;
    }
    if (v2beta2_resource_metric_status->name) {
        free(v2beta2_resource_metric_status->name);
        v2beta2_resource_metric_status->name = NULL;
    }
    free(v2beta2_resource_metric_status);
}

cJSON *v2beta2_resource_metric_status_convertToJSON(v2beta2_resource_metric_status_t *v2beta2_resource_metric_status) {
    cJSON *item = cJSON_CreateObject();

    // v2beta2_resource_metric_status->current
    if (!v2beta2_resource_metric_status->current) {
        goto fail;
    }
    
    cJSON *current_local_JSON = v2beta2_metric_value_status_convertToJSON(v2beta2_resource_metric_status->current);
    if(current_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "current", current_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // v2beta2_resource_metric_status->name
    if (!v2beta2_resource_metric_status->name) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "name", v2beta2_resource_metric_status->name) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v2beta2_resource_metric_status_t *v2beta2_resource_metric_status_parseFromJSON(cJSON *v2beta2_resource_metric_statusJSON){

    v2beta2_resource_metric_status_t *v2beta2_resource_metric_status_local_var = NULL;

    // v2beta2_resource_metric_status->current
    cJSON *current = cJSON_GetObjectItemCaseSensitive(v2beta2_resource_metric_statusJSON, "current");
    if (!current) {
        goto end;
    }

    v2beta2_metric_value_status_t *current_local_nonprim = NULL;
    
    current_local_nonprim = v2beta2_metric_value_status_parseFromJSON(current); //nonprimitive

    // v2beta2_resource_metric_status->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v2beta2_resource_metric_statusJSON, "name");
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }


    v2beta2_resource_metric_status_local_var = v2beta2_resource_metric_status_create (
        current_local_nonprim,
        strdup(name->valuestring)
        );

    return v2beta2_resource_metric_status_local_var;
end:
    if (current_local_nonprim) {
        v2beta2_metric_value_status_free(current_local_nonprim);
        current_local_nonprim = NULL;
    }
    return NULL;

}
