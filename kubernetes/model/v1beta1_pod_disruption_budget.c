#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_pod_disruption_budget.h"



v1beta1_pod_disruption_budget_t *v1beta1_pod_disruption_budget_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1beta1_pod_disruption_budget_spec_t *spec,
    v1beta1_pod_disruption_budget_status_t *status
    ) {
    v1beta1_pod_disruption_budget_t *v1beta1_pod_disruption_budget_local_var = malloc(sizeof(v1beta1_pod_disruption_budget_t));
    if (!v1beta1_pod_disruption_budget_local_var) {
        return NULL;
    }
    v1beta1_pod_disruption_budget_local_var->api_version = api_version;
    v1beta1_pod_disruption_budget_local_var->kind = kind;
    v1beta1_pod_disruption_budget_local_var->metadata = metadata;
    v1beta1_pod_disruption_budget_local_var->spec = spec;
    v1beta1_pod_disruption_budget_local_var->status = status;

    return v1beta1_pod_disruption_budget_local_var;
}


void v1beta1_pod_disruption_budget_free(v1beta1_pod_disruption_budget_t *v1beta1_pod_disruption_budget) {
    if(NULL == v1beta1_pod_disruption_budget){
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta1_pod_disruption_budget->api_version) {
        free(v1beta1_pod_disruption_budget->api_version);
        v1beta1_pod_disruption_budget->api_version = NULL;
    }
    if (v1beta1_pod_disruption_budget->kind) {
        free(v1beta1_pod_disruption_budget->kind);
        v1beta1_pod_disruption_budget->kind = NULL;
    }
    if (v1beta1_pod_disruption_budget->metadata) {
        v1_object_meta_free(v1beta1_pod_disruption_budget->metadata);
        v1beta1_pod_disruption_budget->metadata = NULL;
    }
    if (v1beta1_pod_disruption_budget->spec) {
        v1beta1_pod_disruption_budget_spec_free(v1beta1_pod_disruption_budget->spec);
        v1beta1_pod_disruption_budget->spec = NULL;
    }
    if (v1beta1_pod_disruption_budget->status) {
        v1beta1_pod_disruption_budget_status_free(v1beta1_pod_disruption_budget->status);
        v1beta1_pod_disruption_budget->status = NULL;
    }
    free(v1beta1_pod_disruption_budget);
}

cJSON *v1beta1_pod_disruption_budget_convertToJSON(v1beta1_pod_disruption_budget_t *v1beta1_pod_disruption_budget) {
    cJSON *item = cJSON_CreateObject();

    // v1beta1_pod_disruption_budget->api_version
    if(v1beta1_pod_disruption_budget->api_version) { 
    if(cJSON_AddStringToObject(item, "apiVersion", v1beta1_pod_disruption_budget->api_version) == NULL) {
    goto fail; //String
    }
     } 


    // v1beta1_pod_disruption_budget->kind
    if(v1beta1_pod_disruption_budget->kind) { 
    if(cJSON_AddStringToObject(item, "kind", v1beta1_pod_disruption_budget->kind) == NULL) {
    goto fail; //String
    }
     } 


    // v1beta1_pod_disruption_budget->metadata
    if(v1beta1_pod_disruption_budget->metadata) { 
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1beta1_pod_disruption_budget->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1beta1_pod_disruption_budget->spec
    if(v1beta1_pod_disruption_budget->spec) { 
    cJSON *spec_local_JSON = v1beta1_pod_disruption_budget_spec_convertToJSON(v1beta1_pod_disruption_budget->spec);
    if(spec_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "spec", spec_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1beta1_pod_disruption_budget->status
    if(v1beta1_pod_disruption_budget->status) { 
    cJSON *status_local_JSON = v1beta1_pod_disruption_budget_status_convertToJSON(v1beta1_pod_disruption_budget->status);
    if(status_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "status", status_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1beta1_pod_disruption_budget_t *v1beta1_pod_disruption_budget_parseFromJSON(cJSON *v1beta1_pod_disruption_budgetJSON){

    v1beta1_pod_disruption_budget_t *v1beta1_pod_disruption_budget_local_var = NULL;

    // v1beta1_pod_disruption_budget->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1beta1_pod_disruption_budgetJSON, "apiVersion");
    if (api_version) { 
    if(!cJSON_IsString(api_version))
    {
    goto end; //String
    }
    }

    // v1beta1_pod_disruption_budget->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1beta1_pod_disruption_budgetJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // v1beta1_pod_disruption_budget->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1beta1_pod_disruption_budgetJSON, "metadata");
    v1_object_meta_t *metadata_local_nonprim = NULL;
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1beta1_pod_disruption_budget->spec
    cJSON *spec = cJSON_GetObjectItemCaseSensitive(v1beta1_pod_disruption_budgetJSON, "spec");
    v1beta1_pod_disruption_budget_spec_t *spec_local_nonprim = NULL;
    if (spec) { 
    spec_local_nonprim = v1beta1_pod_disruption_budget_spec_parseFromJSON(spec); //nonprimitive
    }

    // v1beta1_pod_disruption_budget->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(v1beta1_pod_disruption_budgetJSON, "status");
    v1beta1_pod_disruption_budget_status_t *status_local_nonprim = NULL;
    if (status) { 
    status_local_nonprim = v1beta1_pod_disruption_budget_status_parseFromJSON(status); //nonprimitive
    }


    v1beta1_pod_disruption_budget_local_var = v1beta1_pod_disruption_budget_create (
        api_version ? strdup(api_version->valuestring) : NULL,
        kind ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        spec ? spec_local_nonprim : NULL,
        status ? status_local_nonprim : NULL
        );

    return v1beta1_pod_disruption_budget_local_var;
end:
    if (metadata_local_nonprim) {
        v1_object_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    if (spec_local_nonprim) {
        v1beta1_pod_disruption_budget_spec_free(spec_local_nonprim);
        spec_local_nonprim = NULL;
    }
    if (status_local_nonprim) {
        v1beta1_pod_disruption_budget_status_free(status_local_nonprim);
        status_local_nonprim = NULL;
    }
    return NULL;

}
