#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_pod_certificate_request_spec.h"



static v1beta1_pod_certificate_request_spec_t *v1beta1_pod_certificate_request_spec_create_internal(
    int *max_expiration_seconds,
    char *node_name,
    char *node_uid,
    char *pkix_public_key,
    char *pod_name,
    char *pod_uid,
    char *proof_of_possession,
    char *service_account_name,
    char *service_account_uid,
    char *signer_name,
    char *stub_pkcs10_request,
    list_t* unverified_user_annotations
    ) {
    v1beta1_pod_certificate_request_spec_t *v1beta1_pod_certificate_request_spec_local_var = malloc(sizeof(v1beta1_pod_certificate_request_spec_t));
    if (!v1beta1_pod_certificate_request_spec_local_var) {
        return NULL;
    }
    memset(v1beta1_pod_certificate_request_spec_local_var, 0, sizeof(v1beta1_pod_certificate_request_spec_t));
    v1beta1_pod_certificate_request_spec_local_var->_library_owned = 1;
    v1beta1_pod_certificate_request_spec_local_var->max_expiration_seconds = max_expiration_seconds;
    v1beta1_pod_certificate_request_spec_local_var->node_name = node_name;
    v1beta1_pod_certificate_request_spec_local_var->node_uid = node_uid;
    v1beta1_pod_certificate_request_spec_local_var->pkix_public_key = pkix_public_key;
    v1beta1_pod_certificate_request_spec_local_var->pod_name = pod_name;
    v1beta1_pod_certificate_request_spec_local_var->pod_uid = pod_uid;
    v1beta1_pod_certificate_request_spec_local_var->proof_of_possession = proof_of_possession;
    v1beta1_pod_certificate_request_spec_local_var->service_account_name = service_account_name;
    v1beta1_pod_certificate_request_spec_local_var->service_account_uid = service_account_uid;
    v1beta1_pod_certificate_request_spec_local_var->signer_name = signer_name;
    v1beta1_pod_certificate_request_spec_local_var->stub_pkcs10_request = stub_pkcs10_request;
    v1beta1_pod_certificate_request_spec_local_var->unverified_user_annotations = unverified_user_annotations;
    return v1beta1_pod_certificate_request_spec_local_var;
}

__attribute__((deprecated)) v1beta1_pod_certificate_request_spec_t *v1beta1_pod_certificate_request_spec_create(
    int *max_expiration_seconds,
    char *node_name,
    char *node_uid,
    char *pkix_public_key,
    char *pod_name,
    char *pod_uid,
    char *proof_of_possession,
    char *service_account_name,
    char *service_account_uid,
    char *signer_name,
    char *stub_pkcs10_request,
    list_t* unverified_user_annotations
    ) {
    int *max_expiration_seconds_copy = NULL;
    if (max_expiration_seconds) {
        max_expiration_seconds_copy = malloc(sizeof(int));
        if (max_expiration_seconds_copy) *max_expiration_seconds_copy = *max_expiration_seconds;
    }
    v1beta1_pod_certificate_request_spec_t *result = v1beta1_pod_certificate_request_spec_create_internal (
        max_expiration_seconds_copy,
        node_name,
        node_uid,
        pkix_public_key,
        pod_name,
        pod_uid,
        proof_of_possession,
        service_account_name,
        service_account_uid,
        signer_name,
        stub_pkcs10_request,
        unverified_user_annotations
        );
    if (!result) {
        free(max_expiration_seconds_copy);
    }
    return result;
}

void v1beta1_pod_certificate_request_spec_free(v1beta1_pod_certificate_request_spec_t *v1beta1_pod_certificate_request_spec) {
    if(NULL == v1beta1_pod_certificate_request_spec){
        return ;
    }
    if(v1beta1_pod_certificate_request_spec->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1beta1_pod_certificate_request_spec_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta1_pod_certificate_request_spec->max_expiration_seconds) {
        free(v1beta1_pod_certificate_request_spec->max_expiration_seconds);
        v1beta1_pod_certificate_request_spec->max_expiration_seconds = NULL;
    }
    if (v1beta1_pod_certificate_request_spec->node_name) {
        free(v1beta1_pod_certificate_request_spec->node_name);
        v1beta1_pod_certificate_request_spec->node_name = NULL;
    }
    if (v1beta1_pod_certificate_request_spec->node_uid) {
        free(v1beta1_pod_certificate_request_spec->node_uid);
        v1beta1_pod_certificate_request_spec->node_uid = NULL;
    }
    if (v1beta1_pod_certificate_request_spec->pkix_public_key) {
        free(v1beta1_pod_certificate_request_spec->pkix_public_key);
        v1beta1_pod_certificate_request_spec->pkix_public_key = NULL;
    }
    if (v1beta1_pod_certificate_request_spec->pod_name) {
        free(v1beta1_pod_certificate_request_spec->pod_name);
        v1beta1_pod_certificate_request_spec->pod_name = NULL;
    }
    if (v1beta1_pod_certificate_request_spec->pod_uid) {
        free(v1beta1_pod_certificate_request_spec->pod_uid);
        v1beta1_pod_certificate_request_spec->pod_uid = NULL;
    }
    if (v1beta1_pod_certificate_request_spec->proof_of_possession) {
        free(v1beta1_pod_certificate_request_spec->proof_of_possession);
        v1beta1_pod_certificate_request_spec->proof_of_possession = NULL;
    }
    if (v1beta1_pod_certificate_request_spec->service_account_name) {
        free(v1beta1_pod_certificate_request_spec->service_account_name);
        v1beta1_pod_certificate_request_spec->service_account_name = NULL;
    }
    if (v1beta1_pod_certificate_request_spec->service_account_uid) {
        free(v1beta1_pod_certificate_request_spec->service_account_uid);
        v1beta1_pod_certificate_request_spec->service_account_uid = NULL;
    }
    if (v1beta1_pod_certificate_request_spec->signer_name) {
        free(v1beta1_pod_certificate_request_spec->signer_name);
        v1beta1_pod_certificate_request_spec->signer_name = NULL;
    }
    if (v1beta1_pod_certificate_request_spec->stub_pkcs10_request) {
        free(v1beta1_pod_certificate_request_spec->stub_pkcs10_request);
        v1beta1_pod_certificate_request_spec->stub_pkcs10_request = NULL;
    }
    if (v1beta1_pod_certificate_request_spec->unverified_user_annotations) {
        list_ForEach(listEntry, v1beta1_pod_certificate_request_spec->unverified_user_annotations) {
            keyValuePair_t *localKeyValue = listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_freeList(v1beta1_pod_certificate_request_spec->unverified_user_annotations);
        v1beta1_pod_certificate_request_spec->unverified_user_annotations = NULL;
    }
    free(v1beta1_pod_certificate_request_spec);
}

cJSON *v1beta1_pod_certificate_request_spec_convertToJSON(v1beta1_pod_certificate_request_spec_t *v1beta1_pod_certificate_request_spec) {
    cJSON *item = cJSON_CreateObject();

    // v1beta1_pod_certificate_request_spec->max_expiration_seconds
    if(v1beta1_pod_certificate_request_spec->max_expiration_seconds) {
    if(cJSON_AddNumberToObject(item, "maxExpirationSeconds", *v1beta1_pod_certificate_request_spec->max_expiration_seconds) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1beta1_pod_certificate_request_spec->node_name
    if (!v1beta1_pod_certificate_request_spec->node_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "nodeName", v1beta1_pod_certificate_request_spec->node_name) == NULL) {
    goto fail; //String
    }


    // v1beta1_pod_certificate_request_spec->node_uid
    if (!v1beta1_pod_certificate_request_spec->node_uid) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "nodeUID", v1beta1_pod_certificate_request_spec->node_uid) == NULL) {
    goto fail; //String
    }


    // v1beta1_pod_certificate_request_spec->pkix_public_key
    if(v1beta1_pod_certificate_request_spec->pkix_public_key) {
    if(cJSON_AddStringToObject(item, "pkixPublicKey", v1beta1_pod_certificate_request_spec->pkix_public_key) == NULL) {
    goto fail; //ByteArray
    }
    }


    // v1beta1_pod_certificate_request_spec->pod_name
    if (!v1beta1_pod_certificate_request_spec->pod_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "podName", v1beta1_pod_certificate_request_spec->pod_name) == NULL) {
    goto fail; //String
    }


    // v1beta1_pod_certificate_request_spec->pod_uid
    if (!v1beta1_pod_certificate_request_spec->pod_uid) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "podUID", v1beta1_pod_certificate_request_spec->pod_uid) == NULL) {
    goto fail; //String
    }


    // v1beta1_pod_certificate_request_spec->proof_of_possession
    if(v1beta1_pod_certificate_request_spec->proof_of_possession) {
    if(cJSON_AddStringToObject(item, "proofOfPossession", v1beta1_pod_certificate_request_spec->proof_of_possession) == NULL) {
    goto fail; //ByteArray
    }
    }


    // v1beta1_pod_certificate_request_spec->service_account_name
    if (!v1beta1_pod_certificate_request_spec->service_account_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "serviceAccountName", v1beta1_pod_certificate_request_spec->service_account_name) == NULL) {
    goto fail; //String
    }


    // v1beta1_pod_certificate_request_spec->service_account_uid
    if (!v1beta1_pod_certificate_request_spec->service_account_uid) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "serviceAccountUID", v1beta1_pod_certificate_request_spec->service_account_uid) == NULL) {
    goto fail; //String
    }


    // v1beta1_pod_certificate_request_spec->signer_name
    if (!v1beta1_pod_certificate_request_spec->signer_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "signerName", v1beta1_pod_certificate_request_spec->signer_name) == NULL) {
    goto fail; //String
    }


    // v1beta1_pod_certificate_request_spec->stub_pkcs10_request
    if (!v1beta1_pod_certificate_request_spec->stub_pkcs10_request) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "stubPKCS10Request", v1beta1_pod_certificate_request_spec->stub_pkcs10_request) == NULL) {
    goto fail; //ByteArray
    }


    // v1beta1_pod_certificate_request_spec->unverified_user_annotations
    if(v1beta1_pod_certificate_request_spec->unverified_user_annotations) {
    cJSON *unverified_user_annotations = cJSON_AddObjectToObject(item, "unverifiedUserAnnotations");
    if(unverified_user_annotations == NULL) {
        goto fail; //primitive map container
    }
    cJSON *localMapObject = unverified_user_annotations;
    listEntry_t *unverified_user_annotationsListEntry;
    if (v1beta1_pod_certificate_request_spec->unverified_user_annotations) {
    list_ForEach(unverified_user_annotationsListEntry, v1beta1_pod_certificate_request_spec->unverified_user_annotations) {
        keyValuePair_t *localKeyValue = unverified_user_annotationsListEntry->data;
        if(cJSON_AddStringToObject(localMapObject, localKeyValue->key, localKeyValue->value) == NULL)
        {
            goto fail;
        }
    }
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1beta1_pod_certificate_request_spec_t *v1beta1_pod_certificate_request_spec_parseFromJSON(cJSON *v1beta1_pod_certificate_request_specJSON){

    v1beta1_pod_certificate_request_spec_t *v1beta1_pod_certificate_request_spec_local_var = NULL;

    // define the local variable for v1beta1_pod_certificate_request_spec->max_expiration_seconds
    int *max_expiration_seconds_local_var = NULL;

    char *node_name_local_str = NULL;

    char *node_uid_local_str = NULL;

    char *pkix_public_key_local_str = NULL;

    char *pod_name_local_str = NULL;

    char *pod_uid_local_str = NULL;

    char *proof_of_possession_local_str = NULL;

    char *service_account_name_local_str = NULL;

    char *service_account_uid_local_str = NULL;

    char *signer_name_local_str = NULL;

    char *stub_pkcs10_request_local_str = NULL;

    // define the local map for v1beta1_pod_certificate_request_spec->unverified_user_annotations
    list_t *unverified_user_annotationsList = NULL;

    // v1beta1_pod_certificate_request_spec->max_expiration_seconds
    cJSON *max_expiration_seconds = cJSON_GetObjectItemCaseSensitive(v1beta1_pod_certificate_request_specJSON, "maxExpirationSeconds");
    if (cJSON_IsNull(max_expiration_seconds)) {
        max_expiration_seconds = NULL;
    }
    if (max_expiration_seconds) { 
    if(!cJSON_IsNumber(max_expiration_seconds))
    {
    goto end; //Numeric
    }
    max_expiration_seconds_local_var = malloc(sizeof(int));
    if(!max_expiration_seconds_local_var)
    {
        goto end;
    }
    *max_expiration_seconds_local_var = max_expiration_seconds->valuedouble;
    }

    // v1beta1_pod_certificate_request_spec->node_name
    cJSON *node_name = cJSON_GetObjectItemCaseSensitive(v1beta1_pod_certificate_request_specJSON, "nodeName");
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

    // v1beta1_pod_certificate_request_spec->node_uid
    cJSON *node_uid = cJSON_GetObjectItemCaseSensitive(v1beta1_pod_certificate_request_specJSON, "nodeUID");
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

    // v1beta1_pod_certificate_request_spec->pkix_public_key
    cJSON *pkix_public_key = cJSON_GetObjectItemCaseSensitive(v1beta1_pod_certificate_request_specJSON, "pkixPublicKey");
    if (cJSON_IsNull(pkix_public_key)) {
        pkix_public_key = NULL;
    }
    if (pkix_public_key) { 
    if(!cJSON_IsString(pkix_public_key))
    {
    goto end; //ByteArray
    }
    }

    // v1beta1_pod_certificate_request_spec->pod_name
    cJSON *pod_name = cJSON_GetObjectItemCaseSensitive(v1beta1_pod_certificate_request_specJSON, "podName");
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

    // v1beta1_pod_certificate_request_spec->pod_uid
    cJSON *pod_uid = cJSON_GetObjectItemCaseSensitive(v1beta1_pod_certificate_request_specJSON, "podUID");
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

    // v1beta1_pod_certificate_request_spec->proof_of_possession
    cJSON *proof_of_possession = cJSON_GetObjectItemCaseSensitive(v1beta1_pod_certificate_request_specJSON, "proofOfPossession");
    if (cJSON_IsNull(proof_of_possession)) {
        proof_of_possession = NULL;
    }
    if (proof_of_possession) { 
    if(!cJSON_IsString(proof_of_possession))
    {
    goto end; //ByteArray
    }
    }

    // v1beta1_pod_certificate_request_spec->service_account_name
    cJSON *service_account_name = cJSON_GetObjectItemCaseSensitive(v1beta1_pod_certificate_request_specJSON, "serviceAccountName");
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

    // v1beta1_pod_certificate_request_spec->service_account_uid
    cJSON *service_account_uid = cJSON_GetObjectItemCaseSensitive(v1beta1_pod_certificate_request_specJSON, "serviceAccountUID");
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

    // v1beta1_pod_certificate_request_spec->signer_name
    cJSON *signer_name = cJSON_GetObjectItemCaseSensitive(v1beta1_pod_certificate_request_specJSON, "signerName");
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

    // v1beta1_pod_certificate_request_spec->stub_pkcs10_request
    cJSON *stub_pkcs10_request = cJSON_GetObjectItemCaseSensitive(v1beta1_pod_certificate_request_specJSON, "stubPKCS10Request");
    if (cJSON_IsNull(stub_pkcs10_request)) {
        stub_pkcs10_request = NULL;
    }
    if (!stub_pkcs10_request) {
        goto end;
    }

    
    if(!cJSON_IsString(stub_pkcs10_request))
    {
    goto end; //ByteArray
    }

    // v1beta1_pod_certificate_request_spec->unverified_user_annotations
    cJSON *unverified_user_annotations = cJSON_GetObjectItemCaseSensitive(v1beta1_pod_certificate_request_specJSON, "unverifiedUserAnnotations");
    if (cJSON_IsNull(unverified_user_annotations)) {
        unverified_user_annotations = NULL;
    }
    if (unverified_user_annotations) { 
    cJSON *unverified_user_annotations_local_map = NULL;
    if(!cJSON_IsObject(unverified_user_annotations) && !cJSON_IsNull(unverified_user_annotations))
    {
        goto end;//primitive map container
    }
    if(cJSON_IsObject(unverified_user_annotations))
    {
        unverified_user_annotationsList = list_createList();
        keyValuePair_t *localMapKeyPair;
        cJSON_ArrayForEach(unverified_user_annotations_local_map, unverified_user_annotations)
        {
            cJSON *localMapObject = unverified_user_annotations_local_map;
            if(!cJSON_IsString(localMapObject))
            {
                goto end;
            }
            localMapKeyPair = keyValuePair_create(strdup(localMapObject->string),strdup(localMapObject->valuestring));
            list_addElement(unverified_user_annotationsList , localMapKeyPair);
        }
    }
    }


    if (node_name && !cJSON_IsNull(node_name)) node_name_local_str = strdup(node_name->valuestring);
    if (node_uid && !cJSON_IsNull(node_uid)) node_uid_local_str = strdup(node_uid->valuestring);
    if (pkix_public_key) pkix_public_key_local_str = strdup(pkix_public_key->valuestring);
    if (pod_name && !cJSON_IsNull(pod_name)) pod_name_local_str = strdup(pod_name->valuestring);
    if (pod_uid && !cJSON_IsNull(pod_uid)) pod_uid_local_str = strdup(pod_uid->valuestring);
    if (proof_of_possession) proof_of_possession_local_str = strdup(proof_of_possession->valuestring);
    if (service_account_name && !cJSON_IsNull(service_account_name)) service_account_name_local_str = strdup(service_account_name->valuestring);
    if (service_account_uid && !cJSON_IsNull(service_account_uid)) service_account_uid_local_str = strdup(service_account_uid->valuestring);
    if (signer_name && !cJSON_IsNull(signer_name)) signer_name_local_str = strdup(signer_name->valuestring);
    if (stub_pkcs10_request) stub_pkcs10_request_local_str = strdup(stub_pkcs10_request->valuestring);

    v1beta1_pod_certificate_request_spec_local_var = v1beta1_pod_certificate_request_spec_create_internal (
        max_expiration_seconds_local_var,
        node_name_local_str,
        node_uid_local_str,
        pkix_public_key_local_str,
        pod_name_local_str,
        pod_uid_local_str,
        proof_of_possession_local_str,
        service_account_name_local_str,
        service_account_uid_local_str,
        signer_name_local_str,
        stub_pkcs10_request_local_str,
        unverified_user_annotations ? unverified_user_annotationsList : NULL
        );

    if (!v1beta1_pod_certificate_request_spec_local_var) {
        goto end;
    }

    return v1beta1_pod_certificate_request_spec_local_var;
end:
    if (max_expiration_seconds_local_var) {
        free(max_expiration_seconds_local_var);
        max_expiration_seconds_local_var = NULL;
    }
    if (node_name_local_str) {
        free(node_name_local_str);
        node_name_local_str = NULL;
    }
    if (node_uid_local_str) {
        free(node_uid_local_str);
        node_uid_local_str = NULL;
    }
    if (pkix_public_key_local_str) {
        free(pkix_public_key_local_str);
        pkix_public_key_local_str = NULL;
    }
    if (pod_name_local_str) {
        free(pod_name_local_str);
        pod_name_local_str = NULL;
    }
    if (pod_uid_local_str) {
        free(pod_uid_local_str);
        pod_uid_local_str = NULL;
    }
    if (proof_of_possession_local_str) {
        free(proof_of_possession_local_str);
        proof_of_possession_local_str = NULL;
    }
    if (service_account_name_local_str) {
        free(service_account_name_local_str);
        service_account_name_local_str = NULL;
    }
    if (service_account_uid_local_str) {
        free(service_account_uid_local_str);
        service_account_uid_local_str = NULL;
    }
    if (signer_name_local_str) {
        free(signer_name_local_str);
        signer_name_local_str = NULL;
    }
    if (stub_pkcs10_request_local_str) {
        free(stub_pkcs10_request_local_str);
        stub_pkcs10_request_local_str = NULL;
    }
    if (unverified_user_annotationsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, unverified_user_annotationsList) {
            keyValuePair_t *localKeyValue = listEntry->data;
            free(localKeyValue->key);
            localKeyValue->key = NULL;
            free(localKeyValue->value);
            localKeyValue->value = NULL;
            keyValuePair_free(localKeyValue);
            localKeyValue = NULL;
        }
        list_freeList(unverified_user_annotationsList);
        unverified_user_annotationsList = NULL;
    }
    return NULL;

}
