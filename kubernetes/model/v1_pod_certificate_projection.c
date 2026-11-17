#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_pod_certificate_projection.h"



static v1_pod_certificate_projection_t *v1_pod_certificate_projection_create_internal(
    char *certificate_chain_path,
    char *credential_bundle_path,
    char *key_path,
    char *key_type,
    int *max_expiration_seconds,
    char *signer_name,
    long *user,
    list_t* user_annotations
    ) {
    v1_pod_certificate_projection_t *v1_pod_certificate_projection_local_var = malloc(sizeof(v1_pod_certificate_projection_t));
    if (!v1_pod_certificate_projection_local_var) {
        return NULL;
    }
    memset(v1_pod_certificate_projection_local_var, 0, sizeof(v1_pod_certificate_projection_t));
    v1_pod_certificate_projection_local_var->_library_owned = 1;
    v1_pod_certificate_projection_local_var->certificate_chain_path = certificate_chain_path;
    v1_pod_certificate_projection_local_var->credential_bundle_path = credential_bundle_path;
    v1_pod_certificate_projection_local_var->key_path = key_path;
    v1_pod_certificate_projection_local_var->key_type = key_type;
    v1_pod_certificate_projection_local_var->max_expiration_seconds = max_expiration_seconds;
    v1_pod_certificate_projection_local_var->signer_name = signer_name;
    v1_pod_certificate_projection_local_var->user = user;
    v1_pod_certificate_projection_local_var->user_annotations = user_annotations;
    return v1_pod_certificate_projection_local_var;
}

__attribute__((deprecated)) v1_pod_certificate_projection_t *v1_pod_certificate_projection_create(
    char *certificate_chain_path,
    char *credential_bundle_path,
    char *key_path,
    char *key_type,
    int *max_expiration_seconds,
    char *signer_name,
    long *user,
    list_t* user_annotations
    ) {
    int *max_expiration_seconds_copy = NULL;
    if (max_expiration_seconds) {
        max_expiration_seconds_copy = malloc(sizeof(int));
        if (max_expiration_seconds_copy) *max_expiration_seconds_copy = *max_expiration_seconds;
    }
    long *user_copy = NULL;
    if (user) {
        user_copy = malloc(sizeof(long));
        if (user_copy) *user_copy = *user;
    }
    v1_pod_certificate_projection_t *result = v1_pod_certificate_projection_create_internal (
        certificate_chain_path,
        credential_bundle_path,
        key_path,
        key_type,
        max_expiration_seconds_copy,
        signer_name,
        user_copy,
        user_annotations
        );
    if (!result) {
        free(max_expiration_seconds_copy);
        free(user_copy);
    }
    return result;
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
    if (v1_pod_certificate_projection->max_expiration_seconds) {
        free(v1_pod_certificate_projection->max_expiration_seconds);
        v1_pod_certificate_projection->max_expiration_seconds = NULL;
    }
    if (v1_pod_certificate_projection->signer_name) {
        free(v1_pod_certificate_projection->signer_name);
        v1_pod_certificate_projection->signer_name = NULL;
    }
    if (v1_pod_certificate_projection->user) {
        free(v1_pod_certificate_projection->user);
        v1_pod_certificate_projection->user = NULL;
    }
    if (v1_pod_certificate_projection->user_annotations) {
        list_ForEach(listEntry, v1_pod_certificate_projection->user_annotations) {
            keyValuePair_t *localKeyValue = listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_freeList(v1_pod_certificate_projection->user_annotations);
        v1_pod_certificate_projection->user_annotations = NULL;
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
    if(cJSON_AddNumberToObject(item, "maxExpirationSeconds", *v1_pod_certificate_projection->max_expiration_seconds) == NULL) {
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


    // v1_pod_certificate_projection->user
    if(v1_pod_certificate_projection->user) {
    if(cJSON_AddNumberToObject(item, "user", *v1_pod_certificate_projection->user) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_pod_certificate_projection->user_annotations
    if(v1_pod_certificate_projection->user_annotations) {
    cJSON *user_annotations = cJSON_AddObjectToObject(item, "userAnnotations");
    if(user_annotations == NULL) {
        goto fail; //primitive map container
    }
    cJSON *localMapObject = user_annotations;
    listEntry_t *user_annotationsListEntry;
    if (v1_pod_certificate_projection->user_annotations) {
    list_ForEach(user_annotationsListEntry, v1_pod_certificate_projection->user_annotations) {
        keyValuePair_t *localKeyValue = user_annotationsListEntry->data;
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

v1_pod_certificate_projection_t *v1_pod_certificate_projection_parseFromJSON(cJSON *v1_pod_certificate_projectionJSON){

    v1_pod_certificate_projection_t *v1_pod_certificate_projection_local_var = NULL;

    char *certificate_chain_path_local_str = NULL;

    char *credential_bundle_path_local_str = NULL;

    char *key_path_local_str = NULL;

    char *key_type_local_str = NULL;

    // define the local variable for v1_pod_certificate_projection->max_expiration_seconds
    int *max_expiration_seconds_local_var = NULL;

    char *signer_name_local_str = NULL;

    // define the local variable for v1_pod_certificate_projection->user
    long *user_local_var = NULL;

    // define the local map for v1_pod_certificate_projection->user_annotations
    list_t *user_annotationsList = NULL;

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
    max_expiration_seconds_local_var = malloc(sizeof(int));
    if(!max_expiration_seconds_local_var)
    {
        goto end;
    }
    *max_expiration_seconds_local_var = max_expiration_seconds->valuedouble;
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

    // v1_pod_certificate_projection->user
    cJSON *user = cJSON_GetObjectItemCaseSensitive(v1_pod_certificate_projectionJSON, "user");
    if (cJSON_IsNull(user)) {
        user = NULL;
    }
    if (user) { 
    if(!cJSON_IsNumber(user))
    {
    goto end; //Numeric
    }
    user_local_var = malloc(sizeof(long));
    if(!user_local_var)
    {
        goto end;
    }
    *user_local_var = user->valuedouble;
    }

    // v1_pod_certificate_projection->user_annotations
    cJSON *user_annotations = cJSON_GetObjectItemCaseSensitive(v1_pod_certificate_projectionJSON, "userAnnotations");
    if (cJSON_IsNull(user_annotations)) {
        user_annotations = NULL;
    }
    if (user_annotations) { 
    cJSON *user_annotations_local_map = NULL;
    if(!cJSON_IsObject(user_annotations) && !cJSON_IsNull(user_annotations))
    {
        goto end;//primitive map container
    }
    if(cJSON_IsObject(user_annotations))
    {
        user_annotationsList = list_createList();
        keyValuePair_t *localMapKeyPair;
        cJSON_ArrayForEach(user_annotations_local_map, user_annotations)
        {
            cJSON *localMapObject = user_annotations_local_map;
            if(!cJSON_IsString(localMapObject))
            {
                goto end;
            }
            localMapKeyPair = keyValuePair_create(strdup(localMapObject->string),strdup(localMapObject->valuestring));
            list_addElement(user_annotationsList , localMapKeyPair);
        }
    }
    }


    if (certificate_chain_path && !cJSON_IsNull(certificate_chain_path)) certificate_chain_path_local_str = strdup(certificate_chain_path->valuestring);
    if (credential_bundle_path && !cJSON_IsNull(credential_bundle_path)) credential_bundle_path_local_str = strdup(credential_bundle_path->valuestring);
    if (key_path && !cJSON_IsNull(key_path)) key_path_local_str = strdup(key_path->valuestring);
    if (key_type && !cJSON_IsNull(key_type)) key_type_local_str = strdup(key_type->valuestring);
    if (signer_name && !cJSON_IsNull(signer_name)) signer_name_local_str = strdup(signer_name->valuestring);

    v1_pod_certificate_projection_local_var = v1_pod_certificate_projection_create_internal (
        certificate_chain_path_local_str,
        credential_bundle_path_local_str,
        key_path_local_str,
        key_type_local_str,
        max_expiration_seconds_local_var,
        signer_name_local_str,
        user_local_var,
        user_annotations ? user_annotationsList : NULL
        );

    if (!v1_pod_certificate_projection_local_var) {
        goto end;
    }

    return v1_pod_certificate_projection_local_var;
end:
    if (certificate_chain_path_local_str) {
        free(certificate_chain_path_local_str);
        certificate_chain_path_local_str = NULL;
    }
    if (credential_bundle_path_local_str) {
        free(credential_bundle_path_local_str);
        credential_bundle_path_local_str = NULL;
    }
    if (key_path_local_str) {
        free(key_path_local_str);
        key_path_local_str = NULL;
    }
    if (key_type_local_str) {
        free(key_type_local_str);
        key_type_local_str = NULL;
    }
    if (max_expiration_seconds_local_var) {
        free(max_expiration_seconds_local_var);
        max_expiration_seconds_local_var = NULL;
    }
    if (signer_name_local_str) {
        free(signer_name_local_str);
        signer_name_local_str = NULL;
    }
    if (user_local_var) {
        free(user_local_var);
        user_local_var = NULL;
    }
    if (user_annotationsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, user_annotationsList) {
            keyValuePair_t *localKeyValue = listEntry->data;
            free(localKeyValue->key);
            localKeyValue->key = NULL;
            free(localKeyValue->value);
            localKeyValue->value = NULL;
            keyValuePair_free(localKeyValue);
            localKeyValue = NULL;
        }
        list_freeList(user_annotationsList);
        user_annotationsList = NULL;
    }
    return NULL;

}
