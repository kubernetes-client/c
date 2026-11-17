#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha3_composite_pod_group.h"



static v1alpha3_composite_pod_group_t *v1alpha3_composite_pod_group_create_internal(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1alpha3_composite_pod_group_spec_t *spec,
    v1alpha3_composite_pod_group_status_t *status
    ) {
    v1alpha3_composite_pod_group_t *v1alpha3_composite_pod_group_local_var = malloc(sizeof(v1alpha3_composite_pod_group_t));
    if (!v1alpha3_composite_pod_group_local_var) {
        return NULL;
    }
    memset(v1alpha3_composite_pod_group_local_var, 0, sizeof(v1alpha3_composite_pod_group_t));
    v1alpha3_composite_pod_group_local_var->_library_owned = 1;
    v1alpha3_composite_pod_group_local_var->api_version = api_version;
    v1alpha3_composite_pod_group_local_var->kind = kind;
    v1alpha3_composite_pod_group_local_var->metadata = metadata;
    v1alpha3_composite_pod_group_local_var->spec = spec;
    v1alpha3_composite_pod_group_local_var->status = status;
    return v1alpha3_composite_pod_group_local_var;
}

__attribute__((deprecated)) v1alpha3_composite_pod_group_t *v1alpha3_composite_pod_group_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1alpha3_composite_pod_group_spec_t *spec,
    v1alpha3_composite_pod_group_status_t *status
    ) {
    v1alpha3_composite_pod_group_t *result = v1alpha3_composite_pod_group_create_internal (
        api_version,
        kind,
        metadata,
        spec,
        status
        );
    if (!result) {
    }
    return result;
}

void v1alpha3_composite_pod_group_free(v1alpha3_composite_pod_group_t *v1alpha3_composite_pod_group) {
    if(NULL == v1alpha3_composite_pod_group){
        return ;
    }
    if(v1alpha3_composite_pod_group->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1alpha3_composite_pod_group_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha3_composite_pod_group->api_version) {
        free(v1alpha3_composite_pod_group->api_version);
        v1alpha3_composite_pod_group->api_version = NULL;
    }
    if (v1alpha3_composite_pod_group->kind) {
        free(v1alpha3_composite_pod_group->kind);
        v1alpha3_composite_pod_group->kind = NULL;
    }
    if (v1alpha3_composite_pod_group->metadata) {
        v1_object_meta_free(v1alpha3_composite_pod_group->metadata);
        v1alpha3_composite_pod_group->metadata = NULL;
    }
    if (v1alpha3_composite_pod_group->spec) {
        v1alpha3_composite_pod_group_spec_free(v1alpha3_composite_pod_group->spec);
        v1alpha3_composite_pod_group->spec = NULL;
    }
    if (v1alpha3_composite_pod_group->status) {
        v1alpha3_composite_pod_group_status_free(v1alpha3_composite_pod_group->status);
        v1alpha3_composite_pod_group->status = NULL;
    }
    free(v1alpha3_composite_pod_group);
}

cJSON *v1alpha3_composite_pod_group_convertToJSON(v1alpha3_composite_pod_group_t *v1alpha3_composite_pod_group) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha3_composite_pod_group->api_version
    if(v1alpha3_composite_pod_group->api_version) {
    if(cJSON_AddStringToObject(item, "apiVersion", v1alpha3_composite_pod_group->api_version) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha3_composite_pod_group->kind
    if(v1alpha3_composite_pod_group->kind) {
    if(cJSON_AddStringToObject(item, "kind", v1alpha3_composite_pod_group->kind) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha3_composite_pod_group->metadata
    if(v1alpha3_composite_pod_group->metadata) {
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1alpha3_composite_pod_group->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1alpha3_composite_pod_group->spec
    if (!v1alpha3_composite_pod_group->spec) {
        goto fail;
    }
    cJSON *spec_local_JSON = v1alpha3_composite_pod_group_spec_convertToJSON(v1alpha3_composite_pod_group->spec);
    if(spec_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "spec", spec_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // v1alpha3_composite_pod_group->status
    if(v1alpha3_composite_pod_group->status) {
    cJSON *status_local_JSON = v1alpha3_composite_pod_group_status_convertToJSON(v1alpha3_composite_pod_group->status);
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

v1alpha3_composite_pod_group_t *v1alpha3_composite_pod_group_parseFromJSON(cJSON *v1alpha3_composite_pod_groupJSON){

    v1alpha3_composite_pod_group_t *v1alpha3_composite_pod_group_local_var = NULL;

    char *api_version_local_str = NULL;

    char *kind_local_str = NULL;

    // define the local variable for v1alpha3_composite_pod_group->metadata
    v1_object_meta_t *metadata_local_nonprim = NULL;

    // define the local variable for v1alpha3_composite_pod_group->spec
    v1alpha3_composite_pod_group_spec_t *spec_local_nonprim = NULL;

    // define the local variable for v1alpha3_composite_pod_group->status
    v1alpha3_composite_pod_group_status_t *status_local_nonprim = NULL;

    // v1alpha3_composite_pod_group->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1alpha3_composite_pod_groupJSON, "apiVersion");
    if (cJSON_IsNull(api_version)) {
        api_version = NULL;
    }
    if (api_version) { 
    if(!cJSON_IsString(api_version) && !cJSON_IsNull(api_version))
    {
    goto end; //String
    }
    }

    // v1alpha3_composite_pod_group->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1alpha3_composite_pod_groupJSON, "kind");
    if (cJSON_IsNull(kind)) {
        kind = NULL;
    }
    if (kind) { 
    if(!cJSON_IsString(kind) && !cJSON_IsNull(kind))
    {
    goto end; //String
    }
    }

    // v1alpha3_composite_pod_group->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1alpha3_composite_pod_groupJSON, "metadata");
    if (cJSON_IsNull(metadata)) {
        metadata = NULL;
    }
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1alpha3_composite_pod_group->spec
    cJSON *spec = cJSON_GetObjectItemCaseSensitive(v1alpha3_composite_pod_groupJSON, "spec");
    if (cJSON_IsNull(spec)) {
        spec = NULL;
    }
    if (!spec) {
        goto end;
    }

    
    spec_local_nonprim = v1alpha3_composite_pod_group_spec_parseFromJSON(spec); //nonprimitive

    // v1alpha3_composite_pod_group->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(v1alpha3_composite_pod_groupJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (status) { 
    status_local_nonprim = v1alpha3_composite_pod_group_status_parseFromJSON(status); //nonprimitive
    }


    if (api_version && !cJSON_IsNull(api_version)) api_version_local_str = strdup(api_version->valuestring);
    if (kind && !cJSON_IsNull(kind)) kind_local_str = strdup(kind->valuestring);

    v1alpha3_composite_pod_group_local_var = v1alpha3_composite_pod_group_create_internal (
        api_version_local_str,
        kind_local_str,
        metadata ? metadata_local_nonprim : NULL,
        spec_local_nonprim,
        status ? status_local_nonprim : NULL
        );

    if (!v1alpha3_composite_pod_group_local_var) {
        goto end;
    }

    return v1alpha3_composite_pod_group_local_var;
end:
    if (api_version_local_str) {
        free(api_version_local_str);
        api_version_local_str = NULL;
    }
    if (kind_local_str) {
        free(kind_local_str);
        kind_local_str = NULL;
    }
    if (metadata_local_nonprim) {
        v1_object_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    if (spec_local_nonprim) {
        v1alpha3_composite_pod_group_spec_free(spec_local_nonprim);
        spec_local_nonprim = NULL;
    }
    if (status_local_nonprim) {
        v1alpha3_composite_pod_group_status_free(status_local_nonprim);
        status_local_nonprim = NULL;
    }
    return NULL;

}
