#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha1_pod_certificate_request_spec.h"



static v1alpha1_pod_certificate_request_spec_t *v1alpha1_pod_certificate_request_spec_create_internal(
    int max_expiration_seconds,
    char *node_name,
    char *node_uid,
    char *pkix_public_key,
    char *pod_name,
    char *pod_uid,
    char *proof_of_possession,
    char *service_account_name,
    char *service_account_uid,
    char *signer_name
    ) {
    v1alpha1_pod_certificate_request_spec_t *v1alpha1_pod_certificate_request_spec_local_var = malloc(sizeof(v1alpha1_pod_certificate_request_spec_t));
    if (!v1alpha1_pod_certificate_request_spec_local_var) {
        return NULL;
    }
    v1alpha1_pod_certificate_request_spec_local_var->max_expiration_seconds = max_expiration_seconds;
    v1alpha1_pod_certificate_request_spec_local_var->node_name = node_name;
    v1alpha1_pod_certificate_request_spec_local_var->node_uid = node_uid;
    v1alpha1_pod_certificate_request_spec_local_var->pkix_public_key = pkix_public_key;
    v1alpha1_pod_certificate_request_spec_local_var->pod_name = pod_name;
    v1alpha1_pod_certificate_request_spec_local_var->pod_uid = pod_uid;
    v1alpha1_pod_certificate_request_spec_local_var->proof_of_possession = proof_of_possession;
    v1alpha1_pod_certificate_request_spec_local_var->service_account_name = service_account_name;
    v1alpha1_pod_certificate_request_spec_local_var->service_account_uid = service_account_uid;
    v1alpha1_pod_certificate_request_spec_local_var->signer_name = signer_name;

    v1alpha1_pod_certificate_request_spec_local_var->_library_owned = 1;
    return v1alpha1_pod_certificate_request_spec_local_var;
}

__attribute__((deprecated)) v1alpha1_pod_certificate_request_spec_t *v1alpha1_pod_certificate_request_spec_create(
    int max_expiration_seconds,
    char *node_name,
    char *node_uid,
    char *pkix_public_key,
    char *pod_name,
    char *pod_uid,
    char *proof_of_possession,
    char *service_account_name,
    char *service_account_uid,
    char *signer_name
    ) {
    return v1alpha1_pod_certificate_request_spec_create_internal (
        max_expiration_seconds,
        node_name,
        node_uid,
        pkix_public_key,
        pod_name,
        pod_uid,
        proof_of_possession,
        service_account_name,
        service_account_uid,
        signer_name
        );
}

void v1alpha1_pod_certificate_request_spec_free(v1alpha1_pod_certificate_request_spec_t *v1alpha1_pod_certificate_request_spec) {
    if(NULL == v1alpha1_pod_certificate_request_spec){
        return ;
    }
    if(v1alpha1_pod_certificate_request_spec->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1alpha1_pod_certificate_request_spec_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha1_pod_certificate_request_spec->node_name) {
        free(v1alpha1_pod_certificate_request_spec->node_name);
        v1alpha1_pod_certificate_request_spec->node_name = NULL;
    }
    if (v1alpha1_pod_certificate_request_spec->node_uid) {
        free(v1alpha1_pod_certificate_request_spec->node_uid);
        v1alpha1_pod_certificate_request_spec->node_uid = NULL;
    }
    if (v1alpha1_pod_certificate_request_spec->pkix_public_key) {
        free(v1alpha1_pod_certificate_request_spec->pkix_public_key);
        v1alpha1_pod_certificate_request_spec->pkix_public_key = NULL;
    }
    if (v1alpha1_pod_certificate_request_spec->pod_name) {
        free(v1alpha1_pod_certificate_request_spec->pod_name);
        v1alpha1_pod_certificate_request_spec->pod_name = NULL;
    }
    if (v1alpha1_pod_certificate_request_spec->pod_uid) {
        free(v1alpha1_pod_certificate_request_spec->pod_uid);
        v1alpha1_pod_certificate_request_spec->pod_uid = NULL;
    }
    if (v1alpha1_pod_certificate_request_spec->proof_of_possession) {
        free(v1alpha1_pod_certificate_request_spec->proof_of_possession);
        v1alpha1_pod_certificate_request_spec->proof_of_possession = NULL;
    }
    if (v1alpha1_pod_certificate_request_spec->service_account_name) {
        free(v1alpha1_pod_certificate_request_spec->service_account_name);
        v1alpha1_pod_certificate_request_spec->service_account_name = NULL;
    }
    if (v1alpha1_pod_certificate_request_spec->service_account_uid) {
        free(v1alpha1_pod_certificate_request_spec->service_account_uid);
        v1alpha1_pod_certificate_request_spec->service_account_uid = NULL;
    }
    if (v1alpha1_pod_certificate_request_spec->signer_name) {
        free(v1alpha1_pod_certificate_request_spec->signer_name);
        v1alpha1_pod_certificate_request_spec->signer_name = NULL;
    }
    free(v1alpha1_pod_certificate_request_spec);
}

cJSON *v1alpha1_pod_certificate_request_spec_convertToJSON(v1alpha1_pod_certificate_request_spec_t *v1alpha1_pod_certificate_request_spec) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha1_pod_certificate_request_spec->max_expiration_seconds
    if(v1alpha1_pod_certificate_request_spec->max_expiration_seconds) {
    if(cJSON_AddNumberToObject(item, "maxExpirationSeconds", v1alpha1_pod_certificate_request_spec->max_expiration_seconds) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1alpha1_pod_certificate_request_spec->node_name
    if (!v1alpha1_pod_certificate_request_spec->node_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "nodeName", v1alpha1_pod_certificate_request_spec->node_name) == NULL) {
    goto fail; //String
    }


    // v1alpha1_pod_certificate_request_spec->node_uid
    if (!v1alpha1_pod_certificate_request_spec->node_uid) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "nodeUID", v1alpha1_pod_certificate_request_spec->node_uid) == NULL) {
    goto fail; //String
    }


    // v1alpha1_pod_certificate_request_spec->pkix_public_key
    if (!v1alpha1_pod_certificate_request_spec->pkix_public_key) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "pkixPublicKey", v1alpha1_pod_certificate_request_spec->pkix_public_key) == NULL) {
    goto fail; //ByteArray
    }


    // v1alpha1_pod_certificate_request_spec->pod_name
    if (!v1alpha1_pod_certificate_request_spec->pod_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "podName", v1alpha1_pod_certificate_request_spec->pod_name) == NULL) {
    goto fail; //String
    }


    // v1alpha1_pod_certificate_request_spec->pod_uid
    if (!v1alpha1_pod_certificate_request_spec->pod_uid) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "podUID", v1alpha1_pod_certificate_request_spec->pod_uid) == NULL) {
    goto fail; //String
    }


    // v1alpha1_pod_certificate_request_spec->proof_of_possession
    if (!v1alpha1_pod_certificate_request_spec->proof_of_possession) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "proofOfPossession", v1alpha1_pod_certificate_request_spec->proof_of_possession) == NULL) {
    goto fail; //ByteArray
    }


    // v1alpha1_pod_certificate_request_spec->service_account_name
    if (!v1alpha1_pod_certificate_request_spec->service_account_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "serviceAccountName", v1alpha1_pod_certificate_request_spec->service_account_name) == NULL) {
    goto fail; //String
    }


    // v1alpha1_pod_certificate_request_spec->service_account_uid
    if (!v1alpha1_pod_certificate_request_spec->service_account_uid) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "serviceAccountUID", v1alpha1_pod_certificate_request_spec->service_account_uid) == NULL) {
    goto fail; //String
    }


    // v1alpha1_pod_certificate_request_spec->signer_name
    if (!v1alpha1_pod_certificate_request_spec->signer_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "signerName", v1alpha1_pod_certificate_request_spec->signer_name) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1alpha1_pod_certificate_request_spec_t *v1alpha1_pod_certificate_request_spec_parseFromJSON(cJSON *v1alpha1_pod_certificate_request_specJSON){

    v1alpha1_pod_certificate_request_spec_t *v1alpha1_pod_certificate_request_spec_local_var = NULL;

    // v1alpha1_pod_certificate_request_spec->max_expiration_seconds
    cJSON *max_expiration_seconds = cJSON_GetObjectItemCaseSensitive(v1alpha1_pod_certificate_request_specJSON, "maxExpirationSeconds");
    if (cJSON_IsNull(max_expiration_seconds)) {
        max_expiration_seconds = NULL;
    }
    if (max_expiration_seconds) { 
    if(!cJSON_IsNumber(max_expiration_seconds))
    {
    goto end; //Numeric
    }
    }

    // v1alpha1_pod_certificate_request_spec->node_name
    cJSON *node_name = cJSON_GetObjectItemCaseSensitive(v1alpha1_pod_certificate_request_specJSON, "nodeName");
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

    // v1alpha1_pod_certificate_request_spec->node_uid
    cJSON *node_uid = cJSON_GetObjectItemCaseSensitive(v1alpha1_pod_certificate_request_specJSON, "nodeUID");
    if (cJSON_IsNull(node_uid)) {
        node_uid = NULL;
    }
    if (!node_uid) {
        goto end;
    }

    
    if(!cJSON_IsString(node_uid))
    {
    goto end; //String
    }

    // v1alpha1_pod_certificate_request_spec->pkix_public_key
    cJSON *pkix_public_key = cJSON_GetObjectItemCaseSensitive(v1alpha1_pod_certificate_request_specJSON, "pkixPublicKey");
    if (cJSON_IsNull(pkix_public_key)) {
        pkix_public_key = NULL;
    }
    if (!pkix_public_key) {
        goto end;
    }

    
    if(!cJSON_IsString(pkix_public_key))
    {
    goto end; //ByteArray
    }

    // v1alpha1_pod_certificate_request_spec->pod_name
    cJSON *pod_name = cJSON_GetObjectItemCaseSensitive(v1alpha1_pod_certificate_request_specJSON, "podName");
    if (cJSON_IsNull(pod_name)) {
        pod_name = NULL;
    }
    if (!pod_name) {
        goto end;
    }

    
    if(!cJSON_IsString(pod_name))
    {
    goto end; //String
    }

    // v1alpha1_pod_certificate_request_spec->pod_uid
    cJSON *pod_uid = cJSON_GetObjectItemCaseSensitive(v1alpha1_pod_certificate_request_specJSON, "podUID");
    if (cJSON_IsNull(pod_uid)) {
        pod_uid = NULL;
    }
    if (!pod_uid) {
        goto end;
    }

    
    if(!cJSON_IsString(pod_uid))
    {
    goto end; //String
    }

    // v1alpha1_pod_certificate_request_spec->proof_of_possession
    cJSON *proof_of_possession = cJSON_GetObjectItemCaseSensitive(v1alpha1_pod_certificate_request_specJSON, "proofOfPossession");
    if (cJSON_IsNull(proof_of_possession)) {
        proof_of_possession = NULL;
    }
    if (!proof_of_possession) {
        goto end;
    }

    
    if(!cJSON_IsString(proof_of_possession))
    {
    goto end; //ByteArray
    }

    // v1alpha1_pod_certificate_request_spec->service_account_name
    cJSON *service_account_name = cJSON_GetObjectItemCaseSensitive(v1alpha1_pod_certificate_request_specJSON, "serviceAccountName");
    if (cJSON_IsNull(service_account_name)) {
        service_account_name = NULL;
    }
    if (!service_account_name) {
        goto end;
    }

    
    if(!cJSON_IsString(service_account_name))
    {
    goto end; //String
    }

    // v1alpha1_pod_certificate_request_spec->service_account_uid
    cJSON *service_account_uid = cJSON_GetObjectItemCaseSensitive(v1alpha1_pod_certificate_request_specJSON, "serviceAccountUID");
    if (cJSON_IsNull(service_account_uid)) {
        service_account_uid = NULL;
    }
    if (!service_account_uid) {
        goto end;
    }

    
    if(!cJSON_IsString(service_account_uid))
    {
    goto end; //String
    }

    // v1alpha1_pod_certificate_request_spec->signer_name
    cJSON *signer_name = cJSON_GetObjectItemCaseSensitive(v1alpha1_pod_certificate_request_specJSON, "signerName");
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


    v1alpha1_pod_certificate_request_spec_local_var = v1alpha1_pod_certificate_request_spec_create_internal (
        max_expiration_seconds ? max_expiration_seconds->valuedouble : 0,
        strdup(node_name->valuestring),
        strdup(node_uid->valuestring),
        strdup(pkix_public_key->valuestring),
        strdup(pod_name->valuestring),
        strdup(pod_uid->valuestring),
        strdup(proof_of_possession->valuestring),
        strdup(service_account_name->valuestring),
        strdup(service_account_uid->valuestring),
        strdup(signer_name->valuestring)
        );

    return v1alpha1_pod_certificate_request_spec_local_var;
end:
    return NULL;

}
