#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_volume_attachment_source.h"



v1_volume_attachment_source_t *v1_volume_attachment_source_create(
    v1_persistent_volume_spec_t *inline_volume_spec,
    char *persistent_volume_name
    ) {
    v1_volume_attachment_source_t *v1_volume_attachment_source_local_var = malloc(sizeof(v1_volume_attachment_source_t));
    if (!v1_volume_attachment_source_local_var) {
        return NULL;
    }
    v1_volume_attachment_source_local_var->inline_volume_spec = inline_volume_spec;
    v1_volume_attachment_source_local_var->persistent_volume_name = persistent_volume_name;

    return v1_volume_attachment_source_local_var;
}


void v1_volume_attachment_source_free(v1_volume_attachment_source_t *v1_volume_attachment_source) {
    if(NULL == v1_volume_attachment_source){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_volume_attachment_source->inline_volume_spec) {
        v1_persistent_volume_spec_free(v1_volume_attachment_source->inline_volume_spec);
        v1_volume_attachment_source->inline_volume_spec = NULL;
    }
    if (v1_volume_attachment_source->persistent_volume_name) {
        free(v1_volume_attachment_source->persistent_volume_name);
        v1_volume_attachment_source->persistent_volume_name = NULL;
    }
    free(v1_volume_attachment_source);
}

cJSON *v1_volume_attachment_source_convertToJSON(v1_volume_attachment_source_t *v1_volume_attachment_source) {
    cJSON *item = cJSON_CreateObject();

    // v1_volume_attachment_source->inline_volume_spec
    if(v1_volume_attachment_source->inline_volume_spec) { 
    cJSON *inline_volume_spec_local_JSON = v1_persistent_volume_spec_convertToJSON(v1_volume_attachment_source->inline_volume_spec);
    if(inline_volume_spec_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "inlineVolumeSpec", inline_volume_spec_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1_volume_attachment_source->persistent_volume_name
    if(v1_volume_attachment_source->persistent_volume_name) { 
    if(cJSON_AddStringToObject(item, "persistentVolumeName", v1_volume_attachment_source->persistent_volume_name) == NULL) {
    goto fail; //String
    }
     } 

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_volume_attachment_source_t *v1_volume_attachment_source_parseFromJSON(cJSON *v1_volume_attachment_sourceJSON){

    v1_volume_attachment_source_t *v1_volume_attachment_source_local_var = NULL;

    // v1_volume_attachment_source->inline_volume_spec
    cJSON *inline_volume_spec = cJSON_GetObjectItemCaseSensitive(v1_volume_attachment_sourceJSON, "inlineVolumeSpec");
    v1_persistent_volume_spec_t *inline_volume_spec_local_nonprim = NULL;
    if (inline_volume_spec) { 
    inline_volume_spec_local_nonprim = v1_persistent_volume_spec_parseFromJSON(inline_volume_spec); //nonprimitive
    }

    // v1_volume_attachment_source->persistent_volume_name
    cJSON *persistent_volume_name = cJSON_GetObjectItemCaseSensitive(v1_volume_attachment_sourceJSON, "persistentVolumeName");
    if (persistent_volume_name) { 
    if(!cJSON_IsString(persistent_volume_name))
    {
    goto end; //String
    }
    }


    v1_volume_attachment_source_local_var = v1_volume_attachment_source_create (
        inline_volume_spec ? inline_volume_spec_local_nonprim : NULL,
        persistent_volume_name ? strdup(persistent_volume_name->valuestring) : NULL
        );

    return v1_volume_attachment_source_local_var;
end:
    if (inline_volume_spec_local_nonprim) {
        v1_persistent_volume_spec_free(inline_volume_spec_local_nonprim);
        inline_volume_spec_local_nonprim = NULL;
    }
    return NULL;

}
