#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_service_account.h"



v1_service_account_t *v1_service_account_create(
    char *api_version,
    int automount_service_account_token,
    list_t *image_pull_secrets,
    char *kind,
    v1_object_meta_t *metadata,
    list_t *secrets
    ) {
    v1_service_account_t *v1_service_account_local_var = malloc(sizeof(v1_service_account_t));
    if (!v1_service_account_local_var) {
        return NULL;
    }
    v1_service_account_local_var->api_version = api_version;
    v1_service_account_local_var->automount_service_account_token = automount_service_account_token;
    v1_service_account_local_var->image_pull_secrets = image_pull_secrets;
    v1_service_account_local_var->kind = kind;
    v1_service_account_local_var->metadata = metadata;
    v1_service_account_local_var->secrets = secrets;

    return v1_service_account_local_var;
}


void v1_service_account_free(v1_service_account_t *v1_service_account) {
    if(NULL == v1_service_account){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_service_account->api_version) {
        free(v1_service_account->api_version);
        v1_service_account->api_version = NULL;
    }
    if (v1_service_account->image_pull_secrets) {
        list_ForEach(listEntry, v1_service_account->image_pull_secrets) {
            v1_local_object_reference_free(listEntry->data);
        }
        list_free(v1_service_account->image_pull_secrets);
        v1_service_account->image_pull_secrets = NULL;
    }
    if (v1_service_account->kind) {
        free(v1_service_account->kind);
        v1_service_account->kind = NULL;
    }
    if (v1_service_account->metadata) {
        v1_object_meta_free(v1_service_account->metadata);
        v1_service_account->metadata = NULL;
    }
    if (v1_service_account->secrets) {
        list_ForEach(listEntry, v1_service_account->secrets) {
            v1_object_reference_free(listEntry->data);
        }
        list_free(v1_service_account->secrets);
        v1_service_account->secrets = NULL;
    }
    free(v1_service_account);
}

cJSON *v1_service_account_convertToJSON(v1_service_account_t *v1_service_account) {
    cJSON *item = cJSON_CreateObject();

    // v1_service_account->api_version
    if(v1_service_account->api_version) { 
    if(cJSON_AddStringToObject(item, "apiVersion", v1_service_account->api_version) == NULL) {
    goto fail; //String
    }
     } 


    // v1_service_account->automount_service_account_token
    if(v1_service_account->automount_service_account_token) { 
    if(cJSON_AddBoolToObject(item, "automountServiceAccountToken", v1_service_account->automount_service_account_token) == NULL) {
    goto fail; //Bool
    }
     } 


    // v1_service_account->image_pull_secrets
    if(v1_service_account->image_pull_secrets) { 
    cJSON *image_pull_secrets = cJSON_AddArrayToObject(item, "imagePullSecrets");
    if(image_pull_secrets == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *image_pull_secretsListEntry;
    if (v1_service_account->image_pull_secrets) {
    list_ForEach(image_pull_secretsListEntry, v1_service_account->image_pull_secrets) {
    cJSON *itemLocal = v1_local_object_reference_convertToJSON(image_pull_secretsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(image_pull_secrets, itemLocal);
    }
    }
     } 


    // v1_service_account->kind
    if(v1_service_account->kind) { 
    if(cJSON_AddStringToObject(item, "kind", v1_service_account->kind) == NULL) {
    goto fail; //String
    }
     } 


    // v1_service_account->metadata
    if(v1_service_account->metadata) { 
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1_service_account->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1_service_account->secrets
    if(v1_service_account->secrets) { 
    cJSON *secrets = cJSON_AddArrayToObject(item, "secrets");
    if(secrets == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *secretsListEntry;
    if (v1_service_account->secrets) {
    list_ForEach(secretsListEntry, v1_service_account->secrets) {
    cJSON *itemLocal = v1_object_reference_convertToJSON(secretsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(secrets, itemLocal);
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

v1_service_account_t *v1_service_account_parseFromJSON(cJSON *v1_service_accountJSON){

    v1_service_account_t *v1_service_account_local_var = NULL;

    // v1_service_account->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1_service_accountJSON, "apiVersion");
    if (api_version) { 
    if(!cJSON_IsString(api_version))
    {
    goto end; //String
    }
    }

    // v1_service_account->automount_service_account_token
    cJSON *automount_service_account_token = cJSON_GetObjectItemCaseSensitive(v1_service_accountJSON, "automountServiceAccountToken");
    if (automount_service_account_token) { 
    if(!cJSON_IsBool(automount_service_account_token))
    {
    goto end; //Bool
    }
    }

    // v1_service_account->image_pull_secrets
    cJSON *image_pull_secrets = cJSON_GetObjectItemCaseSensitive(v1_service_accountJSON, "imagePullSecrets");
    list_t *image_pull_secretsList;
    if (image_pull_secrets) { 
    cJSON *image_pull_secrets_local_nonprimitive;
    if(!cJSON_IsArray(image_pull_secrets)){
        goto end; //nonprimitive container
    }

    image_pull_secretsList = list_create();

    cJSON_ArrayForEach(image_pull_secrets_local_nonprimitive,image_pull_secrets )
    {
        if(!cJSON_IsObject(image_pull_secrets_local_nonprimitive)){
            goto end;
        }
        v1_local_object_reference_t *image_pull_secretsItem = v1_local_object_reference_parseFromJSON(image_pull_secrets_local_nonprimitive);

        list_addElement(image_pull_secretsList, image_pull_secretsItem);
    }
    }

    // v1_service_account->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_service_accountJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // v1_service_account->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1_service_accountJSON, "metadata");
    v1_object_meta_t *metadata_local_nonprim = NULL;
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1_service_account->secrets
    cJSON *secrets = cJSON_GetObjectItemCaseSensitive(v1_service_accountJSON, "secrets");
    list_t *secretsList;
    if (secrets) { 
    cJSON *secrets_local_nonprimitive;
    if(!cJSON_IsArray(secrets)){
        goto end; //nonprimitive container
    }

    secretsList = list_create();

    cJSON_ArrayForEach(secrets_local_nonprimitive,secrets )
    {
        if(!cJSON_IsObject(secrets_local_nonprimitive)){
            goto end;
        }
        v1_object_reference_t *secretsItem = v1_object_reference_parseFromJSON(secrets_local_nonprimitive);

        list_addElement(secretsList, secretsItem);
    }
    }


    v1_service_account_local_var = v1_service_account_create (
        api_version ? strdup(api_version->valuestring) : NULL,
        automount_service_account_token ? automount_service_account_token->valueint : 0,
        image_pull_secrets ? image_pull_secretsList : NULL,
        kind ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        secrets ? secretsList : NULL
        );

    return v1_service_account_local_var;
end:
    if (metadata_local_nonprim) {
        v1_object_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    return NULL;

}
