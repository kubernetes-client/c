#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_pod_certificate_projection.h"



static v1_pod_certificate_projection_t *v1_pod_certificate_projection_create_internal(
    char *certificate_chain_path,
    char *credential_bundle_path,
    char *key_path,
    char *key_type,
    int max_expiration_seconds,
    char *signer_name
    ) {
    v1_pod_certificate_projection_t *v1_pod_certificate_projection_local_var = malloc(sizeof(v1_pod_certificate_projection_t));
    if (!v1_pod_certificate_projection_local_var) {
        return NULL;
    }
    v1_pod_certificate_projection_local_var->certificate_chain_path = certificate_chain_path;
    v1_pod_certificate_projection_local_var->credential_bundle_path = credential_bundle_path;
    v1_pod_certificate_projection_local_var->key_path = key_path;
    v1_pod_certificate_projection_local_var->key_type = key_type;
    v1_pod_certificate_projection_local_var->max_expiration_seconds = max_expiration_seconds;
    v1_pod_certificate_projection_local_var->signer_name = signer_name;

    v1_pod_certificate_projection_local_var->_library_owned = 1;
    return v1_pod_certificate_projection_local_var;
}

__attribute__((deprecated)) v1_pod_certificate_projection_t *v1_pod_certificate_projection_create(
    char *certificate_chain_path,
    char *credential_bundle_path,
    char *key_path,
    char *key_type,
    int max_expiration_seconds,
    char *signer_name
    ) {
    return v1_pod_certificate_projection_create_internal (
        certificate_chain_path,
        credential_bundle_path,
        key_path,
        key_type,
        max_expiration_seconds,
        signer_name
        );
}

void v1_pod_certificate_projection_free(v1_pod_certificate_projection_t *v1_pod_certificate_projection) {
    if(NULL == v1_pod_certificate_projection){
        return ;
    }
    if(v1_pod_certificate_projection->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_pod_certificate_projection_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_pod_certificate_projection->certificate_chain_path) {
        free(v1_pod_certificate_projection->certificate_chain_path);
        v1_pod_certificate_projection->certificate_chain_path = NULL;
    }
    if (v1_pod_certificate_projection->credential_bundle_path) {
        free(v1_pod_certificate_projection->credential_bundle_path);
        v1_pod_certificate_projection->credential_bundle_path = NULL;
    }
    if (v1_pod_certificate_projection->key_path) {
        free(v1_pod_certificate_projection->key_path);
        v1_pod_certificate_projection->key_path = NULL;
    }
    if (v1_pod_certificate_projection->key_type) {
        free(v1_pod_certificate_projection->key_type);
        v1_pod_certificate_projection->key_type = NULL;
    }
    if (v1_pod_certificate_projection->signer_name) {
        free(v1_pod_certificate_projection->signer_name);
        v1_pod_certificate_projection->signer_name = NULL;
    }
    free(v1_pod_certificate_projection);
}

cJSON *v1_pod_certificate_projection_convertToJSON(v1_pod_certificate_projection_t *v1_pod_certificate_projection) {
    cJSON *item = cJSON_CreateObject();

    // v1_pod_certificate_projection->certificate_chain_path
    if(v1_pod_certificate_projection->certificate_chain_path) {
    if(cJSON_AddStringToObject(item, "certificateChainPath", v1_pod_certificate_projection->certificate_chain_path) == NULL) {
    goto fail; //String
    }
    }


    // v1_pod_certificate_projection->credential_bundle_path
    if(v1_pod_certificate_projection->credential_bundle_path) {
    if(cJSON_AddStringToObject(item, "credentialBundlePath", v1_pod_certificate_projection->credential_bundle_path) == NULL) {
    goto fail; //String
    }
    }


    // v1_pod_certificate_projection->key_path
    if(v1_pod_certificate_projection->key_path) {
    if(cJSON_AddStringToObject(item, "keyPath", v1_pod_certificate_projection->key_path) == NULL) {
    goto fail; //String
    }
    }


    // v1_pod_certificate_projection->key_type
    if (!v1_pod_certificate_projection->key_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "keyType", v1_pod_certificate_projection->key_type) == NULL) {
    goto fail; //String
    }


    // v1_pod_certificate_projection->max_expiration_seconds
    if(v1_pod_certificate_projection->max_expiration_seconds) {
    if(cJSON_AddNumberToObject(item, "maxExpirationSeconds", v1_pod_certificate_projection->max_expiration_seconds) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_pod_certificate_projection->signer_name
    if (!v1_pod_certificate_projection->signer_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "signerName", v1_pod_certificate_projection->signer_name) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_pod_certificate_projection_t *v1_pod_certificate_projection_parseFromJSON(cJSON *v1_pod_certificate_projectionJSON){

    v1_pod_certificate_projection_t *v1_pod_certificate_projection_local_var = NULL;

    // v1_pod_certificate_projection->certificate_chain_path
    cJSON *certificate_chain_path = cJSON_GetObjectItemCaseSensitive(v1_pod_certificate_projectionJSON, "certificateChainPath");
    if (cJSON_IsNull(certificate_chain_path)) {
        certificate_chain_path = NULL;
    }
    if (certificate_chain_path) { 
    if(!cJSON_IsString(certificate_chain_path) && !cJSON_IsNull(certificate_chain_path))
    {
    goto end; //String
    }
    }

    // v1_pod_certificate_projection->credential_bundle_path
    cJSON *credential_bundle_path = cJSON_GetObjectItemCaseSensitive(v1_pod_certificate_projectionJSON, "credentialBundlePath");
    if (cJSON_IsNull(credential_bundle_path)) {
        credential_bundle_path = NULL;
    }
    if (credential_bundle_path) { 
    if(!cJSON_IsString(credential_bundle_path) && !cJSON_IsNull(credential_bundle_path))
    {
    goto end; //String
    }
    }

    // v1_pod_certificate_projection->key_path
    cJSON *key_path = cJSON_GetObjectItemCaseSensitive(v1_pod_certificate_projectionJSON, "keyPath");
    if (cJSON_IsNull(key_path)) {
        key_path = NULL;
    }
    if (key_path) { 
    if(!cJSON_IsString(key_path) && !cJSON_IsNull(key_path))
    {
    goto end; //String
    }
    }

    // v1_pod_certificate_projection->key_type
    cJSON *key_type = cJSON_GetObjectItemCaseSensitive(v1_pod_certificate_projectionJSON, "keyType");
    if (cJSON_IsNull(key_type)) {
        key_type = NULL;
    }
    if (!key_type) {
        goto end;
    }

    
    if(!cJSON_IsString(key_type))
    {
    goto end; //String
    }

    // v1_pod_certificate_projection->max_expiration_seconds
    cJSON *max_expiration_seconds = cJSON_GetObjectItemCaseSensitive(v1_pod_certificate_projectionJSON, "maxExpirationSeconds");
    if (cJSON_IsNull(max_expiration_seconds)) {
        max_expiration_seconds = NULL;
    }
    if (max_expiration_seconds) { 
    if(!cJSON_IsNumber(max_expiration_seconds))
    {
    goto end; //Numeric
    }
    }

    // v1_pod_certificate_projection->signer_name
    cJSON *signer_name = cJSON_GetObjectItemCaseSensitive(v1_pod_certificate_projectionJSON, "signerName");
    if (cJSON_IsNull(signer_name)) {
        signer_name = NULL;
    }
    if (!signer_name) {
        goto end;
    }

    
    if(!cJSON_IsString(signer_name))
    {
    goto end; //String
    }


    v1_pod_certificate_projection_local_var = v1_pod_certificate_projection_create_internal (
        certificate_chain_path && !cJSON_IsNull(certificate_chain_path) ? strdup(certificate_chain_path->valuestring) : NULL,
        credential_bundle_path && !cJSON_IsNull(credential_bundle_path) ? strdup(credential_bundle_path->valuestring) : NULL,
        key_path && !cJSON_IsNull(key_path) ? strdup(key_path->valuestring) : NULL,
        strdup(key_type->valuestring),
        max_expiration_seconds ? max_expiration_seconds->valuedouble : 0,
        strdup(signer_name->valuestring)
        );

    return v1_pod_certificate_projection_local_var;
end:
    return NULL;

}
