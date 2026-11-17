#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_volume_attachment_spec.h"



static v1_volume_attachment_spec_t *v1_volume_attachment_spec_create_internal(
    char *attacher,
    char *node_name,
    v1_volume_attachment_source_t *source
    ) {
    v1_volume_attachment_spec_t *v1_volume_attachment_spec_local_var = malloc(sizeof(v1_volume_attachment_spec_t));
    if (!v1_volume_attachment_spec_local_var) {
        return NULL;
    }
    memset(v1_volume_attachment_spec_local_var, 0, sizeof(v1_volume_attachment_spec_t));
    v1_volume_attachment_spec_local_var->_library_owned = 1;
    v1_volume_attachment_spec_local_var->attacher = attacher;
    v1_volume_attachment_spec_local_var->node_name = node_name;
    v1_volume_attachment_spec_local_var->source = source;
    return v1_volume_attachment_spec_local_var;
}

__attribute__((deprecated)) v1_volume_attachment_spec_t *v1_volume_attachment_spec_create(
    char *attacher,
    char *node_name,
    v1_volume_attachment_source_t *source
    ) {
    v1_volume_attachment_spec_t *result = v1_volume_attachment_spec_create_internal (
        attacher,
        node_name,
        source
        );
    if (!result) {
    }
    return result;
}

void v1_volume_attachment_spec_free(v1_volume_attachment_spec_t *v1_volume_attachment_spec) {
    if(NULL == v1_volume_attachment_spec){
        return ;
    }
    if(v1_volume_attachment_spec->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_volume_attachment_spec_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_volume_attachment_spec->attacher) {
        free(v1_volume_attachment_spec->attacher);
        v1_volume_attachment_spec->attacher = NULL;
    }
    if (v1_volume_attachment_spec->node_name) {
        free(v1_volume_attachment_spec->node_name);
        v1_volume_attachment_spec->node_name = NULL;
    }
    if (v1_volume_attachment_spec->source) {
        v1_volume_attachment_source_free(v1_volume_attachment_spec->source);
        v1_volume_attachment_spec->source = NULL;
    }
    free(v1_volume_attachment_spec);
}

cJSON *v1_volume_attachment_spec_convertToJSON(v1_volume_attachment_spec_t *v1_volume_attachment_spec) {
    cJSON *item = cJSON_CreateObject();

    // v1_volume_attachment_spec->attacher
    if (!v1_volume_attachment_spec->attacher) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "attacher", v1_volume_attachment_spec->attacher) == NULL) {
    goto fail; //String
    }


    // v1_volume_attachment_spec->node_name
    if (!v1_volume_attachment_spec->node_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "nodeName", v1_volume_attachment_spec->node_name) == NULL) {
    goto fail; //String
    }


    // v1_volume_attachment_spec->source
    if (!v1_volume_attachment_spec->source) {
        goto fail;
    }
    cJSON *source_local_JSON = v1_volume_attachment_source_convertToJSON(v1_volume_attachment_spec->source);
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

v1_volume_attachment_spec_t *v1_volume_attachment_spec_parseFromJSON(cJSON *v1_volume_attachment_specJSON){

    v1_volume_attachment_spec_t *v1_volume_attachment_spec_local_var = NULL;

    char *attacher_local_str = NULL;

    char *node_name_local_str = NULL;

    // define the local variable for v1_volume_attachment_spec->source
    v1_volume_attachment_source_t *source_local_nonprim = NULL;

    // v1_volume_attachment_spec->attacher
    cJSON *attacher = cJSON_GetObjectItemCaseSensitive(v1_volume_attachment_specJSON, "attacher");
    if (cJSON_IsNull(attacher)) {
        attacher = NULL;
    }
    if (!attacher) {
        goto end;
    }

    
    if(!cJSON_IsString(attacher))
    {
    goto end; //String
    }

    // v1_volume_attachment_spec->node_name
    cJSON *node_name = cJSON_GetObjectItemCaseSensitive(v1_volume_attachment_specJSON, "nodeName");
    if (cJSON_IsNull(node_name)) {
        node_name = NULL;
    }
    if (!node_name) {
        goto end;
    }

    
    if(!cJSON_IsString(node_name))
    {
    goto end; //String
    }

    // v1_volume_attachment_spec->source
    cJSON *source = cJSON_GetObjectItemCaseSensitive(v1_volume_attachment_specJSON, "source");
    if (cJSON_IsNull(source)) {
        source = NULL;
    }
    if (!source) {
        goto end;
    }

    
    source_local_nonprim = v1_volume_attachment_source_parseFromJSON(source); //nonprimitive


    if (attacher && !cJSON_IsNull(attacher)) attacher_local_str = strdup(attacher->valuestring);
    if (node_name && !cJSON_IsNull(node_name)) node_name_local_str = strdup(node_name->valuestring);

    v1_volume_attachment_spec_local_var = v1_volume_attachment_spec_create_internal (
        attacher_local_str,
        node_name_local_str,
        source_local_nonprim
        );

    if (!v1_volume_attachment_spec_local_var) {
        goto end;
    }

    return v1_volume_attachment_spec_local_var;
end:
    if (attacher_local_str) {
        free(attacher_local_str);
        attacher_local_str = NULL;
    }
    if (node_name_local_str) {
        free(node_name_local_str);
        node_name_local_str = NULL;
    }
    if (source_local_nonprim) {
        v1_volume_attachment_source_free(source_local_nonprim);
        source_local_nonprim = NULL;
    }
    return NULL;

}
