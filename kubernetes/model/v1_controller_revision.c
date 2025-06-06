#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_controller_revision.h"



static v1_controller_revision_t *v1_controller_revision_create_internal(
    char *api_version,
    object_t *data,
    char *kind,
    v1_object_meta_t *metadata,
    long revision
    ) {
    v1_controller_revision_t *v1_controller_revision_local_var = malloc(sizeof(v1_controller_revision_t));
    if (!v1_controller_revision_local_var) {
        return NULL;
    }
    v1_controller_revision_local_var->api_version = api_version;
    v1_controller_revision_local_var->data = data;
    v1_controller_revision_local_var->kind = kind;
    v1_controller_revision_local_var->metadata = metadata;
    v1_controller_revision_local_var->revision = revision;

    v1_controller_revision_local_var->_library_owned = 1;
    return v1_controller_revision_local_var;
}

__attribute__((deprecated)) v1_controller_revision_t *v1_controller_revision_create(
    char *api_version,
    object_t *data,
    char *kind,
    v1_object_meta_t *metadata,
    long revision
    ) {
    return v1_controller_revision_create_internal (
        api_version,
        data,
        kind,
        metadata,
        revision
        );
}

void v1_controller_revision_free(v1_controller_revision_t *v1_controller_revision) {
    if(NULL == v1_controller_revision){
        return ;
    }
    if(v1_controller_revision->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_controller_revision_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_controller_revision->api_version) {
        free(v1_controller_revision->api_version);
        v1_controller_revision->api_version = NULL;
    }
    if (v1_controller_revision->data) {
        object_free(v1_controller_revision->data);
        v1_controller_revision->data = NULL;
    }
    if (v1_controller_revision->kind) {
        free(v1_controller_revision->kind);
        v1_controller_revision->kind = NULL;
    }
    if (v1_controller_revision->metadata) {
        v1_object_meta_free(v1_controller_revision->metadata);
        v1_controller_revision->metadata = NULL;
    }
    free(v1_controller_revision);
}

cJSON *v1_controller_revision_convertToJSON(v1_controller_revision_t *v1_controller_revision) {
    cJSON *item = cJSON_CreateObject();

    // v1_controller_revision->api_version
    if(v1_controller_revision->api_version) {
    if(cJSON_AddStringToObject(item, "apiVersion", v1_controller_revision->api_version) == NULL) {
    goto fail; //String
    }
    }


    // v1_controller_revision->data
    if(v1_controller_revision->data) {
    cJSON *data_object = object_convertToJSON(v1_controller_revision->data);
    if(data_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "data", data_object);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_controller_revision->kind
    if(v1_controller_revision->kind) {
    if(cJSON_AddStringToObject(item, "kind", v1_controller_revision->kind) == NULL) {
    goto fail; //String
    }
    }


    // v1_controller_revision->metadata
    if(v1_controller_revision->metadata) {
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1_controller_revision->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_controller_revision->revision
    if (!v1_controller_revision->revision) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "revision", v1_controller_revision->revision) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_controller_revision_t *v1_controller_revision_parseFromJSON(cJSON *v1_controller_revisionJSON){

    v1_controller_revision_t *v1_controller_revision_local_var = NULL;

    // define the local variable for v1_controller_revision->metadata
    v1_object_meta_t *metadata_local_nonprim = NULL;

    // v1_controller_revision->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1_controller_revisionJSON, "apiVersion");
    if (cJSON_IsNull(api_version)) {
        api_version = NULL;
    }
    if (api_version) { 
    if(!cJSON_IsString(api_version) && !cJSON_IsNull(api_version))
    {
    goto end; //String
    }
    }

    // v1_controller_revision->data
    cJSON *data = cJSON_GetObjectItemCaseSensitive(v1_controller_revisionJSON, "data");
    if (cJSON_IsNull(data)) {
        data = NULL;
    }
    object_t *data_local_object = NULL;
    if (data) { 
    data_local_object = object_parseFromJSON(data); //object
    }

    // v1_controller_revision->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_controller_revisionJSON, "kind");
    if (cJSON_IsNull(kind)) {
        kind = NULL;
    }
    if (kind) { 
    if(!cJSON_IsString(kind) && !cJSON_IsNull(kind))
    {
    goto end; //String
    }
    }

    // v1_controller_revision->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1_controller_revisionJSON, "metadata");
    if (cJSON_IsNull(metadata)) {
        metadata = NULL;
    }
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1_controller_revision->revision
    cJSON *revision = cJSON_GetObjectItemCaseSensitive(v1_controller_revisionJSON, "revision");
    if (cJSON_IsNull(revision)) {
        revision = NULL;
    }
    if (!revision) {
        goto end;
    }

    
    if(!cJSON_IsNumber(revision))
    {
    goto end; //Numeric
    }


    v1_controller_revision_local_var = v1_controller_revision_create_internal (
        api_version && !cJSON_IsNull(api_version) ? strdup(api_version->valuestring) : NULL,
        data ? data_local_object : NULL,
        kind && !cJSON_IsNull(kind) ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        revision->valuedouble
        );

    return v1_controller_revision_local_var;
end:
    if (metadata_local_nonprim) {
        v1_object_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    return NULL;

}
