#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_cron_job.h"



static v1_cron_job_t *v1_cron_job_create_internal(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1_cron_job_spec_t *spec,
    v1_cron_job_status_t *status
    ) {
    v1_cron_job_t *v1_cron_job_local_var = malloc(sizeof(v1_cron_job_t));
    if (!v1_cron_job_local_var) {
        return NULL;
    }
    v1_cron_job_local_var->api_version = api_version;
    v1_cron_job_local_var->kind = kind;
    v1_cron_job_local_var->metadata = metadata;
    v1_cron_job_local_var->spec = spec;
    v1_cron_job_local_var->status = status;

    v1_cron_job_local_var->_library_owned = 1;
    return v1_cron_job_local_var;
}

__attribute__((deprecated)) v1_cron_job_t *v1_cron_job_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1_cron_job_spec_t *spec,
    v1_cron_job_status_t *status
    ) {
    return v1_cron_job_create_internal (
        api_version,
        kind,
        metadata,
        spec,
        status
        );
}

void v1_cron_job_free(v1_cron_job_t *v1_cron_job) {
    if(NULL == v1_cron_job){
        return ;
    }
    if(v1_cron_job->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_cron_job_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_cron_job->api_version) {
        free(v1_cron_job->api_version);
        v1_cron_job->api_version = NULL;
    }
    if (v1_cron_job->kind) {
        free(v1_cron_job->kind);
        v1_cron_job->kind = NULL;
    }
    if (v1_cron_job->metadata) {
        v1_object_meta_free(v1_cron_job->metadata);
        v1_cron_job->metadata = NULL;
    }
    if (v1_cron_job->spec) {
        v1_cron_job_spec_free(v1_cron_job->spec);
        v1_cron_job->spec = NULL;
    }
    if (v1_cron_job->status) {
        v1_cron_job_status_free(v1_cron_job->status);
        v1_cron_job->status = NULL;
    }
    free(v1_cron_job);
}

cJSON *v1_cron_job_convertToJSON(v1_cron_job_t *v1_cron_job) {
    cJSON *item = cJSON_CreateObject();

    // v1_cron_job->api_version
    if(v1_cron_job->api_version) {
    if(cJSON_AddStringToObject(item, "apiVersion", v1_cron_job->api_version) == NULL) {
    goto fail; //String
    }
    }


    // v1_cron_job->kind
    if(v1_cron_job->kind) {
    if(cJSON_AddStringToObject(item, "kind", v1_cron_job->kind) == NULL) {
    goto fail; //String
    }
    }


    // v1_cron_job->metadata
    if(v1_cron_job->metadata) {
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1_cron_job->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_cron_job->spec
    if(v1_cron_job->spec) {
    cJSON *spec_local_JSON = v1_cron_job_spec_convertToJSON(v1_cron_job->spec);
    if(spec_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "spec", spec_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_cron_job->status
    if(v1_cron_job->status) {
    cJSON *status_local_JSON = v1_cron_job_status_convertToJSON(v1_cron_job->status);
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

v1_cron_job_t *v1_cron_job_parseFromJSON(cJSON *v1_cron_jobJSON){

    v1_cron_job_t *v1_cron_job_local_var = NULL;

    // define the local variable for v1_cron_job->metadata
    v1_object_meta_t *metadata_local_nonprim = NULL;

    // define the local variable for v1_cron_job->spec
    v1_cron_job_spec_t *spec_local_nonprim = NULL;

    // define the local variable for v1_cron_job->status
    v1_cron_job_status_t *status_local_nonprim = NULL;

    // v1_cron_job->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1_cron_jobJSON, "apiVersion");
    if (cJSON_IsNull(api_version)) {
        api_version = NULL;
    }
    if (api_version) { 
    if(!cJSON_IsString(api_version) && !cJSON_IsNull(api_version))
    {
    goto end; //String
    }
    }

    // v1_cron_job->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_cron_jobJSON, "kind");
    if (cJSON_IsNull(kind)) {
        kind = NULL;
    }
    if (kind) { 
    if(!cJSON_IsString(kind) && !cJSON_IsNull(kind))
    {
    goto end; //String
    }
    }

    // v1_cron_job->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1_cron_jobJSON, "metadata");
    if (cJSON_IsNull(metadata)) {
        metadata = NULL;
    }
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1_cron_job->spec
    cJSON *spec = cJSON_GetObjectItemCaseSensitive(v1_cron_jobJSON, "spec");
    if (cJSON_IsNull(spec)) {
        spec = NULL;
    }
    if (spec) { 
    spec_local_nonprim = v1_cron_job_spec_parseFromJSON(spec); //nonprimitive
    }

    // v1_cron_job->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(v1_cron_jobJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (status) { 
    status_local_nonprim = v1_cron_job_status_parseFromJSON(status); //nonprimitive
    }


    v1_cron_job_local_var = v1_cron_job_create_internal (
        api_version && !cJSON_IsNull(api_version) ? strdup(api_version->valuestring) : NULL,
        kind && !cJSON_IsNull(kind) ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        spec ? spec_local_nonprim : NULL,
        status ? status_local_nonprim : NULL
        );

    return v1_cron_job_local_var;
end:
    if (metadata_local_nonprim) {
        v1_object_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    if (spec_local_nonprim) {
        v1_cron_job_spec_free(spec_local_nonprim);
        spec_local_nonprim = NULL;
    }
    if (status_local_nonprim) {
        v1_cron_job_status_free(status_local_nonprim);
        status_local_nonprim = NULL;
    }
    return NULL;

}
