#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "apps_v1beta1_deployment.h"



apps_v1beta1_deployment_t *apps_v1beta1_deployment_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    apps_v1beta1_deployment_spec_t *spec,
    apps_v1beta1_deployment_status_t *status
    ) {
    apps_v1beta1_deployment_t *apps_v1beta1_deployment_local_var = malloc(sizeof(apps_v1beta1_deployment_t));
    if (!apps_v1beta1_deployment_local_var) {
        return NULL;
    }
    apps_v1beta1_deployment_local_var->api_version = api_version;
    apps_v1beta1_deployment_local_var->kind = kind;
    apps_v1beta1_deployment_local_var->metadata = metadata;
    apps_v1beta1_deployment_local_var->spec = spec;
    apps_v1beta1_deployment_local_var->status = status;

    return apps_v1beta1_deployment_local_var;
}


void apps_v1beta1_deployment_free(apps_v1beta1_deployment_t *apps_v1beta1_deployment) {
    if(NULL == apps_v1beta1_deployment){
        return ;
    }
    listEntry_t *listEntry;
    if (apps_v1beta1_deployment->api_version) {
        free(apps_v1beta1_deployment->api_version);
        apps_v1beta1_deployment->api_version = NULL;
    }
    if (apps_v1beta1_deployment->kind) {
        free(apps_v1beta1_deployment->kind);
        apps_v1beta1_deployment->kind = NULL;
    }
    if (apps_v1beta1_deployment->metadata) {
        v1_object_meta_free(apps_v1beta1_deployment->metadata);
        apps_v1beta1_deployment->metadata = NULL;
    }
    if (apps_v1beta1_deployment->spec) {
        apps_v1beta1_deployment_spec_free(apps_v1beta1_deployment->spec);
        apps_v1beta1_deployment->spec = NULL;
    }
    if (apps_v1beta1_deployment->status) {
        apps_v1beta1_deployment_status_free(apps_v1beta1_deployment->status);
        apps_v1beta1_deployment->status = NULL;
    }
    free(apps_v1beta1_deployment);
}

cJSON *apps_v1beta1_deployment_convertToJSON(apps_v1beta1_deployment_t *apps_v1beta1_deployment) {
    cJSON *item = cJSON_CreateObject();

    // apps_v1beta1_deployment->api_version
    if(apps_v1beta1_deployment->api_version) { 
    if(cJSON_AddStringToObject(item, "apiVersion", apps_v1beta1_deployment->api_version) == NULL) {
    goto fail; //String
    }
     } 


    // apps_v1beta1_deployment->kind
    if(apps_v1beta1_deployment->kind) { 
    if(cJSON_AddStringToObject(item, "kind", apps_v1beta1_deployment->kind) == NULL) {
    goto fail; //String
    }
     } 


    // apps_v1beta1_deployment->metadata
    if(apps_v1beta1_deployment->metadata) { 
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(apps_v1beta1_deployment->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // apps_v1beta1_deployment->spec
    if(apps_v1beta1_deployment->spec) { 
    cJSON *spec_local_JSON = apps_v1beta1_deployment_spec_convertToJSON(apps_v1beta1_deployment->spec);
    if(spec_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "spec", spec_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // apps_v1beta1_deployment->status
    if(apps_v1beta1_deployment->status) { 
    cJSON *status_local_JSON = apps_v1beta1_deployment_status_convertToJSON(apps_v1beta1_deployment->status);
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

apps_v1beta1_deployment_t *apps_v1beta1_deployment_parseFromJSON(cJSON *apps_v1beta1_deploymentJSON){

    apps_v1beta1_deployment_t *apps_v1beta1_deployment_local_var = NULL;

    // apps_v1beta1_deployment->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(apps_v1beta1_deploymentJSON, "apiVersion");
    if (api_version) { 
    if(!cJSON_IsString(api_version))
    {
    goto end; //String
    }
    }

    // apps_v1beta1_deployment->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(apps_v1beta1_deploymentJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // apps_v1beta1_deployment->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(apps_v1beta1_deploymentJSON, "metadata");
    v1_object_meta_t *metadata_local_nonprim = NULL;
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // apps_v1beta1_deployment->spec
    cJSON *spec = cJSON_GetObjectItemCaseSensitive(apps_v1beta1_deploymentJSON, "spec");
    apps_v1beta1_deployment_spec_t *spec_local_nonprim = NULL;
    if (spec) { 
    spec_local_nonprim = apps_v1beta1_deployment_spec_parseFromJSON(spec); //nonprimitive
    }

    // apps_v1beta1_deployment->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(apps_v1beta1_deploymentJSON, "status");
    apps_v1beta1_deployment_status_t *status_local_nonprim = NULL;
    if (status) { 
    status_local_nonprim = apps_v1beta1_deployment_status_parseFromJSON(status); //nonprimitive
    }


    apps_v1beta1_deployment_local_var = apps_v1beta1_deployment_create (
        api_version ? strdup(api_version->valuestring) : NULL,
        kind ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        spec ? spec_local_nonprim : NULL,
        status ? status_local_nonprim : NULL
        );

    return apps_v1beta1_deployment_local_var;
end:
    if (metadata_local_nonprim) {
        v1_object_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    if (spec_local_nonprim) {
        apps_v1beta1_deployment_spec_free(spec_local_nonprim);
        spec_local_nonprim = NULL;
    }
    if (status_local_nonprim) {
        apps_v1beta1_deployment_status_free(status_local_nonprim);
        status_local_nonprim = NULL;
    }
    return NULL;

}
