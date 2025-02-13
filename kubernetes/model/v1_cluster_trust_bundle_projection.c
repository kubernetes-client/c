#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_cluster_trust_bundle_projection.h"



static v1_cluster_trust_bundle_projection_t *v1_cluster_trust_bundle_projection_create_internal(
    v1_label_selector_t *label_selector,
    char *name,
    int optional,
    char *path,
    char *signer_name
    ) {
    v1_cluster_trust_bundle_projection_t *v1_cluster_trust_bundle_projection_local_var = malloc(sizeof(v1_cluster_trust_bundle_projection_t));
    if (!v1_cluster_trust_bundle_projection_local_var) {
        return NULL;
    }
    v1_cluster_trust_bundle_projection_local_var->label_selector = label_selector;
    v1_cluster_trust_bundle_projection_local_var->name = name;
    v1_cluster_trust_bundle_projection_local_var->optional = optional;
    v1_cluster_trust_bundle_projection_local_var->path = path;
    v1_cluster_trust_bundle_projection_local_var->signer_name = signer_name;

    v1_cluster_trust_bundle_projection_local_var->_library_owned = 1;
    return v1_cluster_trust_bundle_projection_local_var;
}

__attribute__((deprecated)) v1_cluster_trust_bundle_projection_t *v1_cluster_trust_bundle_projection_create(
    v1_label_selector_t *label_selector,
    char *name,
    int optional,
    char *path,
    char *signer_name
    ) {
    return v1_cluster_trust_bundle_projection_create_internal (
        label_selector,
        name,
        optional,
        path,
        signer_name
        );
}

void v1_cluster_trust_bundle_projection_free(v1_cluster_trust_bundle_projection_t *v1_cluster_trust_bundle_projection) {
    if(NULL == v1_cluster_trust_bundle_projection){
        return ;
    }
    if(v1_cluster_trust_bundle_projection->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_cluster_trust_bundle_projection_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_cluster_trust_bundle_projection->label_selector) {
        v1_label_selector_free(v1_cluster_trust_bundle_projection->label_selector);
        v1_cluster_trust_bundle_projection->label_selector = NULL;
    }
    if (v1_cluster_trust_bundle_projection->name) {
        free(v1_cluster_trust_bundle_projection->name);
        v1_cluster_trust_bundle_projection->name = NULL;
    }
    if (v1_cluster_trust_bundle_projection->path) {
        free(v1_cluster_trust_bundle_projection->path);
        v1_cluster_trust_bundle_projection->path = NULL;
    }
    if (v1_cluster_trust_bundle_projection->signer_name) {
        free(v1_cluster_trust_bundle_projection->signer_name);
        v1_cluster_trust_bundle_projection->signer_name = NULL;
    }
    free(v1_cluster_trust_bundle_projection);
}

cJSON *v1_cluster_trust_bundle_projection_convertToJSON(v1_cluster_trust_bundle_projection_t *v1_cluster_trust_bundle_projection) {
    cJSON *item = cJSON_CreateObject();

    // v1_cluster_trust_bundle_projection->label_selector
    if(v1_cluster_trust_bundle_projection->label_selector) {
    cJSON *label_selector_local_JSON = v1_label_selector_convertToJSON(v1_cluster_trust_bundle_projection->label_selector);
    if(label_selector_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "labelSelector", label_selector_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_cluster_trust_bundle_projection->name
    if(v1_cluster_trust_bundle_projection->name) {
    if(cJSON_AddStringToObject(item, "name", v1_cluster_trust_bundle_projection->name) == NULL) {
    goto fail; //String
    }
    }


    // v1_cluster_trust_bundle_projection->optional
    if(v1_cluster_trust_bundle_projection->optional) {
    if(cJSON_AddBoolToObject(item, "optional", v1_cluster_trust_bundle_projection->optional) == NULL) {
    goto fail; //Bool
    }
    }


    // v1_cluster_trust_bundle_projection->path
    if (!v1_cluster_trust_bundle_projection->path) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "path", v1_cluster_trust_bundle_projection->path) == NULL) {
    goto fail; //String
    }


    // v1_cluster_trust_bundle_projection->signer_name
    if(v1_cluster_trust_bundle_projection->signer_name) {
    if(cJSON_AddStringToObject(item, "signerName", v1_cluster_trust_bundle_projection->signer_name) == NULL) {
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

v1_cluster_trust_bundle_projection_t *v1_cluster_trust_bundle_projection_parseFromJSON(cJSON *v1_cluster_trust_bundle_projectionJSON){

    v1_cluster_trust_bundle_projection_t *v1_cluster_trust_bundle_projection_local_var = NULL;

    // define the local variable for v1_cluster_trust_bundle_projection->label_selector
    v1_label_selector_t *label_selector_local_nonprim = NULL;

    // v1_cluster_trust_bundle_projection->label_selector
    cJSON *label_selector = cJSON_GetObjectItemCaseSensitive(v1_cluster_trust_bundle_projectionJSON, "labelSelector");
    if (cJSON_IsNull(label_selector)) {
        label_selector = NULL;
    }
    if (label_selector) { 
    label_selector_local_nonprim = v1_label_selector_parseFromJSON(label_selector); //nonprimitive
    }

    // v1_cluster_trust_bundle_projection->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1_cluster_trust_bundle_projectionJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // v1_cluster_trust_bundle_projection->optional
    cJSON *optional = cJSON_GetObjectItemCaseSensitive(v1_cluster_trust_bundle_projectionJSON, "optional");
    if (cJSON_IsNull(optional)) {
        optional = NULL;
    }
    if (optional) { 
    if(!cJSON_IsBool(optional))
    {
    goto end; //Bool
    }
    }

    // v1_cluster_trust_bundle_projection->path
    cJSON *path = cJSON_GetObjectItemCaseSensitive(v1_cluster_trust_bundle_projectionJSON, "path");
    if (cJSON_IsNull(path)) {
        path = NULL;
    }
    if (!path) {
        goto end;
    }

    
    if(!cJSON_IsString(path))
    {
    goto end; //String
    }

    // v1_cluster_trust_bundle_projection->signer_name
    cJSON *signer_name = cJSON_GetObjectItemCaseSensitive(v1_cluster_trust_bundle_projectionJSON, "signerName");
    if (cJSON_IsNull(signer_name)) {
        signer_name = NULL;
    }
    if (signer_name) { 
    if(!cJSON_IsString(signer_name) && !cJSON_IsNull(signer_name))
    {
    goto end; //String
    }
    }


    v1_cluster_trust_bundle_projection_local_var = v1_cluster_trust_bundle_projection_create_internal (
        label_selector ? label_selector_local_nonprim : NULL,
        name && !cJSON_IsNull(name) ? strdup(name->valuestring) : NULL,
        optional ? optional->valueint : 0,
        strdup(path->valuestring),
        signer_name && !cJSON_IsNull(signer_name) ? strdup(signer_name->valuestring) : NULL
        );

    return v1_cluster_trust_bundle_projection_local_var;
end:
    if (label_selector_local_nonprim) {
        v1_label_selector_free(label_selector_local_nonprim);
        label_selector_local_nonprim = NULL;
    }
    return NULL;

}
