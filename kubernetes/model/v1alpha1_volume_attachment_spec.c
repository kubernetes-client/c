#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha1_volume_attachment_spec.h"



v1alpha1_volume_attachment_spec_t *v1alpha1_volume_attachment_spec_create(
    char *attacher,
    char *node_name,
    v1alpha1_volume_attachment_source_t *source
    ) {
    v1alpha1_volume_attachment_spec_t *v1alpha1_volume_attachment_spec_local_var = malloc(sizeof(v1alpha1_volume_attachment_spec_t));
    if (!v1alpha1_volume_attachment_spec_local_var) {
        return NULL;
    }
    v1alpha1_volume_attachment_spec_local_var->attacher = attacher;
    v1alpha1_volume_attachment_spec_local_var->node_name = node_name;
    v1alpha1_volume_attachment_spec_local_var->source = source;

    return v1alpha1_volume_attachment_spec_local_var;
}


void v1alpha1_volume_attachment_spec_free(v1alpha1_volume_attachment_spec_t *v1alpha1_volume_attachment_spec) {
    if(NULL == v1alpha1_volume_attachment_spec){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha1_volume_attachment_spec->attacher) {
        free(v1alpha1_volume_attachment_spec->attacher);
        v1alpha1_volume_attachment_spec->attacher = NULL;
    }
    if (v1alpha1_volume_attachment_spec->node_name) {
        free(v1alpha1_volume_attachment_spec->node_name);
        v1alpha1_volume_attachment_spec->node_name = NULL;
    }
    if (v1alpha1_volume_attachment_spec->source) {
        v1alpha1_volume_attachment_source_free(v1alpha1_volume_attachment_spec->source);
        v1alpha1_volume_attachment_spec->source = NULL;
    }
    free(v1alpha1_volume_attachment_spec);
}

cJSON *v1alpha1_volume_attachment_spec_convertToJSON(v1alpha1_volume_attachment_spec_t *v1alpha1_volume_attachment_spec) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha1_volume_attachment_spec->attacher
    if (!v1alpha1_volume_attachment_spec->attacher) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "attacher", v1alpha1_volume_attachment_spec->attacher) == NULL) {
    goto fail; //String
    }


    // v1alpha1_volume_attachment_spec->node_name
    if (!v1alpha1_volume_attachment_spec->node_name) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "nodeName", v1alpha1_volume_attachment_spec->node_name) == NULL) {
    goto fail; //String
    }


    // v1alpha1_volume_attachment_spec->source
    if (!v1alpha1_volume_attachment_spec->source) {
        goto fail;
    }
    
    cJSON *source_local_JSON = v1alpha1_volume_attachment_source_convertToJSON(v1alpha1_volume_attachment_spec->source);
    if(source_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "source", source_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1alpha1_volume_attachment_spec_t *v1alpha1_volume_attachment_spec_parseFromJSON(cJSON *v1alpha1_volume_attachment_specJSON){

    v1alpha1_volume_attachment_spec_t *v1alpha1_volume_attachment_spec_local_var = NULL;

    // v1alpha1_volume_attachment_spec->attacher
    cJSON *attacher = cJSON_GetObjectItemCaseSensitive(v1alpha1_volume_attachment_specJSON, "attacher");
    if (!attacher) {
        goto end;
    }

    
    if(!cJSON_IsString(attacher))
    {
    goto end; //String
    }

    // v1alpha1_volume_attachment_spec->node_name
    cJSON *node_name = cJSON_GetObjectItemCaseSensitive(v1alpha1_volume_attachment_specJSON, "nodeName");
    if (!node_name) {
        goto end;
    }

    
    if(!cJSON_IsString(node_name))
    {
    goto end; //String
    }

    // v1alpha1_volume_attachment_spec->source
    cJSON *source = cJSON_GetObjectItemCaseSensitive(v1alpha1_volume_attachment_specJSON, "source");
    if (!source) {
        goto end;
    }

    v1alpha1_volume_attachment_source_t *source_local_nonprim = NULL;
    
    source_local_nonprim = v1alpha1_volume_attachment_source_parseFromJSON(source); //nonprimitive


    v1alpha1_volume_attachment_spec_local_var = v1alpha1_volume_attachment_spec_create (
        strdup(attacher->valuestring),
        strdup(node_name->valuestring),
        source_local_nonprim
        );

    return v1alpha1_volume_attachment_spec_local_var;
end:
    if (source_local_nonprim) {
        v1alpha1_volume_attachment_source_free(source_local_nonprim);
        source_local_nonprim = NULL;
    }
    return NULL;

}
