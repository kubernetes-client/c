#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_controller_revision.h"



v1beta1_controller_revision_t *v1beta1_controller_revision_create(
    char *api_version,
    object_t *data,
    char *kind,
    v1_object_meta_t *metadata,
    long revision
    ) {
    v1beta1_controller_revision_t *v1beta1_controller_revision_local_var = malloc(sizeof(v1beta1_controller_revision_t));
    if (!v1beta1_controller_revision_local_var) {
        return NULL;
    }
    v1beta1_controller_revision_local_var->api_version = api_version;
    v1beta1_controller_revision_local_var->data = data;
    v1beta1_controller_revision_local_var->kind = kind;
    v1beta1_controller_revision_local_var->metadata = metadata;
    v1beta1_controller_revision_local_var->revision = revision;

    return v1beta1_controller_revision_local_var;
}


void v1beta1_controller_revision_free(v1beta1_controller_revision_t *v1beta1_controller_revision) {
    if(NULL == v1beta1_controller_revision){
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta1_controller_revision->api_version) {
        free(v1beta1_controller_revision->api_version);
        v1beta1_controller_revision->api_version = NULL;
    }
    if (v1beta1_controller_revision->data) {
        object_free(v1beta1_controller_revision->data);
        v1beta1_controller_revision->data = NULL;
    }
    if (v1beta1_controller_revision->kind) {
        free(v1beta1_controller_revision->kind);
        v1beta1_controller_revision->kind = NULL;
    }
    if (v1beta1_controller_revision->metadata) {
        v1_object_meta_free(v1beta1_controller_revision->metadata);
        v1beta1_controller_revision->metadata = NULL;
    }
    free(v1beta1_controller_revision);
}

cJSON *v1beta1_controller_revision_convertToJSON(v1beta1_controller_revision_t *v1beta1_controller_revision) {
    cJSON *item = cJSON_CreateObject();

    // v1beta1_controller_revision->api_version
    if(v1beta1_controller_revision->api_version) { 
    if(cJSON_AddStringToObject(item, "apiVersion", v1beta1_controller_revision->api_version) == NULL) {
    goto fail; //String
    }
     } 


    // v1beta1_controller_revision->data
    if(v1beta1_controller_revision->data) { 
    cJSON *data_object = object_convertToJSON(v1beta1_controller_revision->data);
    if(data_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "data", data_object);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1beta1_controller_revision->kind
    if(v1beta1_controller_revision->kind) { 
    if(cJSON_AddStringToObject(item, "kind", v1beta1_controller_revision->kind) == NULL) {
    goto fail; //String
    }
     } 


    // v1beta1_controller_revision->metadata
    if(v1beta1_controller_revision->metadata) { 
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1beta1_controller_revision->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1beta1_controller_revision->revision
    if (!v1beta1_controller_revision->revision) {
        goto fail;
    }
    
    if(cJSON_AddNumberToObject(item, "revision", v1beta1_controller_revision->revision) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1beta1_controller_revision_t *v1beta1_controller_revision_parseFromJSON(cJSON *v1beta1_controller_revisionJSON){

    v1beta1_controller_revision_t *v1beta1_controller_revision_local_var = NULL;

    // v1beta1_controller_revision->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1beta1_controller_revisionJSON, "apiVersion");
    if (api_version) { 
    if(!cJSON_IsString(api_version))
    {
    goto end; //String
    }
    }

    // v1beta1_controller_revision->data
    cJSON *data = cJSON_GetObjectItemCaseSensitive(v1beta1_controller_revisionJSON, "data");
    object_t *data_local_object = NULL;
    if (data) { 
    data_local_object = object_parseFromJSON(data); //object
    }

    // v1beta1_controller_revision->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1beta1_controller_revisionJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // v1beta1_controller_revision->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1beta1_controller_revisionJSON, "metadata");
    v1_object_meta_t *metadata_local_nonprim = NULL;
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1beta1_controller_revision->revision
    cJSON *revision = cJSON_GetObjectItemCaseSensitive(v1beta1_controller_revisionJSON, "revision");
    if (!revision) {
        goto end;
    }

    
    if(!cJSON_IsNumber(revision))
    {
    goto end; //Numeric
    }


    v1beta1_controller_revision_local_var = v1beta1_controller_revision_create (
        api_version ? strdup(api_version->valuestring) : NULL,
        data ? data_local_object : NULL,
        kind ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        revision->valuedouble
        );

    return v1beta1_controller_revision_local_var;
end:
    if (metadata_local_nonprim) {
        v1_object_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    return NULL;

}
