#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_pod_template.h"



v1_pod_template_t *v1_pod_template_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1_pod_template_spec_t *template
    ) {
    v1_pod_template_t *v1_pod_template_local_var = malloc(sizeof(v1_pod_template_t));
    if (!v1_pod_template_local_var) {
        return NULL;
    }
    v1_pod_template_local_var->api_version = api_version;
    v1_pod_template_local_var->kind = kind;
    v1_pod_template_local_var->metadata = metadata;
    v1_pod_template_local_var->template = template;

    return v1_pod_template_local_var;
}


void v1_pod_template_free(v1_pod_template_t *v1_pod_template) {
    if(NULL == v1_pod_template){
        return ;
    }
    listEntry_t *listEntry;
    free(v1_pod_template->api_version);
    free(v1_pod_template->kind);
    v1_object_meta_free(v1_pod_template->metadata);
    v1_pod_template_spec_free(v1_pod_template->template);
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


    // v1_pod_template->template
    if(v1_pod_template->template) { 
    cJSON *template_local_JSON = v1_pod_template_spec_convertToJSON(v1_pod_template->template);
    if(template_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "template", template_local_JSON);
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

    // v1_pod_template->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1_pod_templateJSON, "apiVersion");
    if (api_version) { 
    if(!cJSON_IsString(api_version))
    {
    goto end; //String
    }
    }

    // v1_pod_template->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_pod_templateJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // v1_pod_template->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1_pod_templateJSON, "metadata");
    v1_object_meta_t *metadata_local_nonprim = NULL;
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1_pod_template->template
    cJSON *template = cJSON_GetObjectItemCaseSensitive(v1_pod_templateJSON, "template");
    v1_pod_template_spec_t *template_local_nonprim = NULL;
    if (template) { 
    template_local_nonprim = v1_pod_template_spec_parseFromJSON(template); //nonprimitive
    }


    v1_pod_template_local_var = v1_pod_template_create (
        api_version ? strdup(api_version->valuestring) : NULL,
        kind ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        template ? template_local_nonprim : NULL
        );

    return v1_pod_template_local_var;
end:
    return NULL;

}
