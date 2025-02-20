#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_pod_template.h"



static v1_pod_template_t *v1_pod_template_create_internal(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1_pod_template_spec_t *_template
    ) {
    v1_pod_template_t *v1_pod_template_local_var = malloc(sizeof(v1_pod_template_t));
    if (!v1_pod_template_local_var) {
        return NULL;
    }
    v1_pod_template_local_var->api_version = api_version;
    v1_pod_template_local_var->kind = kind;
    v1_pod_template_local_var->metadata = metadata;
    v1_pod_template_local_var->_template = _template;

    v1_pod_template_local_var->_library_owned = 1;
    return v1_pod_template_local_var;
}

__attribute__((deprecated)) v1_pod_template_t *v1_pod_template_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1_pod_template_spec_t *_template
    ) {
    return v1_pod_template_create_internal (
        api_version,
        kind,
        metadata,
        _template
        );
}

void v1_pod_template_free(v1_pod_template_t *v1_pod_template) {
    if(NULL == v1_pod_template){
        return ;
    }
    if(v1_pod_template->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_pod_template_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_pod_template->api_version) {
        free(v1_pod_template->api_version);
        v1_pod_template->api_version = NULL;
    }
    if (v1_pod_template->kind) {
        free(v1_pod_template->kind);
        v1_pod_template->kind = NULL;
    }
    if (v1_pod_template->metadata) {
        v1_object_meta_free(v1_pod_template->metadata);
        v1_pod_template->metadata = NULL;
    }
    if (v1_pod_template->_template) {
        v1_pod_template_spec_free(v1_pod_template->_template);
        v1_pod_template->_template = NULL;
    }
    free(v1_pod_template);
}

cJSON *v1_pod_template_convertToJSON(v1_pod_template_t *v1_pod_template) {
    cJSON *item = cJSON_CreateObject();

    // v1_pod_template->api_version
    if(v1_pod_template->api_version) {
    if(cJSON_AddStringToObject(item, "apiVersion", v1_pod_template->api_version) == NULL) {
    goto fail; //String
    }
    }


    // v1_pod_template->kind
    if(v1_pod_template->kind) {
    if(cJSON_AddStringToObject(item, "kind", v1_pod_template->kind) == NULL) {
    goto fail; //String
    }
    }


    // v1_pod_template->metadata
    if(v1_pod_template->metadata) {
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1_pod_template->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_pod_template->_template
    if(v1_pod_template->_template) {
    cJSON *_template_local_JSON = v1_pod_template_spec_convertToJSON(v1_pod_template->_template);
    if(_template_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "template", _template_local_JSON);
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

v1_pod_template_t *v1_pod_template_parseFromJSON(cJSON *v1_pod_templateJSON){

    v1_pod_template_t *v1_pod_template_local_var = NULL;

    // define the local variable for v1_pod_template->metadata
    v1_object_meta_t *metadata_local_nonprim = NULL;

    // define the local variable for v1_pod_template->_template
    v1_pod_template_spec_t *_template_local_nonprim = NULL;

    // v1_pod_template->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1_pod_templateJSON, "apiVersion");
    if (cJSON_IsNull(api_version)) {
        api_version = NULL;
    }
    if (api_version) { 
    if(!cJSON_IsString(api_version) && !cJSON_IsNull(api_version))
    {
    goto end; //String
    }
    }

    // v1_pod_template->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_pod_templateJSON, "kind");
    if (cJSON_IsNull(kind)) {
        kind = NULL;
    }
    if (kind) { 
    if(!cJSON_IsString(kind) && !cJSON_IsNull(kind))
    {
    goto end; //String
    }
    }

    // v1_pod_template->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1_pod_templateJSON, "metadata");
    if (cJSON_IsNull(metadata)) {
        metadata = NULL;
    }
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1_pod_template->_template
    cJSON *_template = cJSON_GetObjectItemCaseSensitive(v1_pod_templateJSON, "template");
    if (cJSON_IsNull(_template)) {
        _template = NULL;
    }
    if (_template) { 
    _template_local_nonprim = v1_pod_template_spec_parseFromJSON(_template); //nonprimitive
    }


    v1_pod_template_local_var = v1_pod_template_create_internal (
        api_version && !cJSON_IsNull(api_version) ? strdup(api_version->valuestring) : NULL,
        kind && !cJSON_IsNull(kind) ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        _template ? _template_local_nonprim : NULL
        );

    return v1_pod_template_local_var;
end:
    if (metadata_local_nonprim) {
        v1_object_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    if (_template_local_nonprim) {
        v1_pod_template_spec_free(_template_local_nonprim);
        _template_local_nonprim = NULL;
    }
    return NULL;

}
