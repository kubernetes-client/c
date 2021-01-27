#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_scale_io_persistent_volume_source.h"



v1_scale_io_persistent_volume_source_t *v1_scale_io_persistent_volume_source_create(
    char *fs_type,
    char *gateway,
    char *protection_domain,
    int read_only,
    v1_secret_reference_t *secret_ref,
    int ssl_enabled,
    char *storage_mode,
    char *storage_pool,
    char *system,
    char *volume_name
    ) {
    v1_scale_io_persistent_volume_source_t *v1_scale_io_persistent_volume_source_local_var = malloc(sizeof(v1_scale_io_persistent_volume_source_t));
    if (!v1_scale_io_persistent_volume_source_local_var) {
        return NULL;
    }
    v1_scale_io_persistent_volume_source_local_var->fs_type = fs_type;
    v1_scale_io_persistent_volume_source_local_var->gateway = gateway;
    v1_scale_io_persistent_volume_source_local_var->protection_domain = protection_domain;
    v1_scale_io_persistent_volume_source_local_var->read_only = read_only;
    v1_scale_io_persistent_volume_source_local_var->secret_ref = secret_ref;
    v1_scale_io_persistent_volume_source_local_var->ssl_enabled = ssl_enabled;
    v1_scale_io_persistent_volume_source_local_var->storage_mode = storage_mode;
    v1_scale_io_persistent_volume_source_local_var->storage_pool = storage_pool;
    v1_scale_io_persistent_volume_source_local_var->system = system;
    v1_scale_io_persistent_volume_source_local_var->volume_name = volume_name;

    return v1_scale_io_persistent_volume_source_local_var;
}


void v1_scale_io_persistent_volume_source_free(v1_scale_io_persistent_volume_source_t *v1_scale_io_persistent_volume_source) {
    if(NULL == v1_scale_io_persistent_volume_source){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_scale_io_persistent_volume_source->fs_type) {
        free(v1_scale_io_persistent_volume_source->fs_type);
        v1_scale_io_persistent_volume_source->fs_type = NULL;
    }
    if (v1_scale_io_persistent_volume_source->gateway) {
        free(v1_scale_io_persistent_volume_source->gateway);
        v1_scale_io_persistent_volume_source->gateway = NULL;
    }
    if (v1_scale_io_persistent_volume_source->protection_domain) {
        free(v1_scale_io_persistent_volume_source->protection_domain);
        v1_scale_io_persistent_volume_source->protection_domain = NULL;
    }
    if (v1_scale_io_persistent_volume_source->secret_ref) {
        v1_secret_reference_free(v1_scale_io_persistent_volume_source->secret_ref);
        v1_scale_io_persistent_volume_source->secret_ref = NULL;
    }
    if (v1_scale_io_persistent_volume_source->storage_mode) {
        free(v1_scale_io_persistent_volume_source->storage_mode);
        v1_scale_io_persistent_volume_source->storage_mode = NULL;
    }
    if (v1_scale_io_persistent_volume_source->storage_pool) {
        free(v1_scale_io_persistent_volume_source->storage_pool);
        v1_scale_io_persistent_volume_source->storage_pool = NULL;
    }
    if (v1_scale_io_persistent_volume_source->system) {
        free(v1_scale_io_persistent_volume_source->system);
        v1_scale_io_persistent_volume_source->system = NULL;
    }
    if (v1_scale_io_persistent_volume_source->volume_name) {
        free(v1_scale_io_persistent_volume_source->volume_name);
        v1_scale_io_persistent_volume_source->volume_name = NULL;
    }
    free(v1_scale_io_persistent_volume_source);
}

cJSON *v1_scale_io_persistent_volume_source_convertToJSON(v1_scale_io_persistent_volume_source_t *v1_scale_io_persistent_volume_source) {
    cJSON *item = cJSON_CreateObject();

    // v1_scale_io_persistent_volume_source->fs_type
    if(v1_scale_io_persistent_volume_source->fs_type) { 
    if(cJSON_AddStringToObject(item, "fsType", v1_scale_io_persistent_volume_source->fs_type) == NULL) {
    goto fail; //String
    }
     } 


    // v1_scale_io_persistent_volume_source->gateway
    if (!v1_scale_io_persistent_volume_source->gateway) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "gateway", v1_scale_io_persistent_volume_source->gateway) == NULL) {
    goto fail; //String
    }


    // v1_scale_io_persistent_volume_source->protection_domain
    if(v1_scale_io_persistent_volume_source->protection_domain) { 
    if(cJSON_AddStringToObject(item, "protectionDomain", v1_scale_io_persistent_volume_source->protection_domain) == NULL) {
    goto fail; //String
    }
     } 


    // v1_scale_io_persistent_volume_source->read_only
    if(v1_scale_io_persistent_volume_source->read_only) { 
    if(cJSON_AddBoolToObject(item, "readOnly", v1_scale_io_persistent_volume_source->read_only) == NULL) {
    goto fail; //Bool
    }
     } 


    // v1_scale_io_persistent_volume_source->secret_ref
    if (!v1_scale_io_persistent_volume_source->secret_ref) {
        goto fail;
    }
    
    cJSON *secret_ref_local_JSON = v1_secret_reference_convertToJSON(v1_scale_io_persistent_volume_source->secret_ref);
    if(secret_ref_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "secretRef", secret_ref_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // v1_scale_io_persistent_volume_source->ssl_enabled
    if(v1_scale_io_persistent_volume_source->ssl_enabled) { 
    if(cJSON_AddBoolToObject(item, "sslEnabled", v1_scale_io_persistent_volume_source->ssl_enabled) == NULL) {
    goto fail; //Bool
    }
     } 


    // v1_scale_io_persistent_volume_source->storage_mode
    if(v1_scale_io_persistent_volume_source->storage_mode) { 
    if(cJSON_AddStringToObject(item, "storageMode", v1_scale_io_persistent_volume_source->storage_mode) == NULL) {
    goto fail; //String
    }
     } 


    // v1_scale_io_persistent_volume_source->storage_pool
    if(v1_scale_io_persistent_volume_source->storage_pool) { 
    if(cJSON_AddStringToObject(item, "storagePool", v1_scale_io_persistent_volume_source->storage_pool) == NULL) {
    goto fail; //String
    }
     } 


    // v1_scale_io_persistent_volume_source->system
    if (!v1_scale_io_persistent_volume_source->system) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "system", v1_scale_io_persistent_volume_source->system) == NULL) {
    goto fail; //String
    }


    // v1_scale_io_persistent_volume_source->volume_name
    if(v1_scale_io_persistent_volume_source->volume_name) { 
    if(cJSON_AddStringToObject(item, "volumeName", v1_scale_io_persistent_volume_source->volume_name) == NULL) {
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

v1_scale_io_persistent_volume_source_t *v1_scale_io_persistent_volume_source_parseFromJSON(cJSON *v1_scale_io_persistent_volume_sourceJSON){

    v1_scale_io_persistent_volume_source_t *v1_scale_io_persistent_volume_source_local_var = NULL;

    // v1_scale_io_persistent_volume_source->fs_type
    cJSON *fs_type = cJSON_GetObjectItemCaseSensitive(v1_scale_io_persistent_volume_sourceJSON, "fsType");
    if (fs_type) { 
    if(!cJSON_IsString(fs_type))
    {
    goto end; //String
    }
    }

    // v1_scale_io_persistent_volume_source->gateway
    cJSON *gateway = cJSON_GetObjectItemCaseSensitive(v1_scale_io_persistent_volume_sourceJSON, "gateway");
    if (!gateway) {
        goto end;
    }

    
    if(!cJSON_IsString(gateway))
    {
    goto end; //String
    }

    // v1_scale_io_persistent_volume_source->protection_domain
    cJSON *protection_domain = cJSON_GetObjectItemCaseSensitive(v1_scale_io_persistent_volume_sourceJSON, "protectionDomain");
    if (protection_domain) { 
    if(!cJSON_IsString(protection_domain))
    {
    goto end; //String
    }
    }

    // v1_scale_io_persistent_volume_source->read_only
    cJSON *read_only = cJSON_GetObjectItemCaseSensitive(v1_scale_io_persistent_volume_sourceJSON, "readOnly");
    if (read_only) { 
    if(!cJSON_IsBool(read_only))
    {
    goto end; //Bool
    }
    }

    // v1_scale_io_persistent_volume_source->secret_ref
    cJSON *secret_ref = cJSON_GetObjectItemCaseSensitive(v1_scale_io_persistent_volume_sourceJSON, "secretRef");
    if (!secret_ref) {
        goto end;
    }

    v1_secret_reference_t *secret_ref_local_nonprim = NULL;
    
    secret_ref_local_nonprim = v1_secret_reference_parseFromJSON(secret_ref); //nonprimitive

    // v1_scale_io_persistent_volume_source->ssl_enabled
    cJSON *ssl_enabled = cJSON_GetObjectItemCaseSensitive(v1_scale_io_persistent_volume_sourceJSON, "sslEnabled");
    if (ssl_enabled) { 
    if(!cJSON_IsBool(ssl_enabled))
    {
    goto end; //Bool
    }
    }

    // v1_scale_io_persistent_volume_source->storage_mode
    cJSON *storage_mode = cJSON_GetObjectItemCaseSensitive(v1_scale_io_persistent_volume_sourceJSON, "storageMode");
    if (storage_mode) { 
    if(!cJSON_IsString(storage_mode))
    {
    goto end; //String
    }
    }

    // v1_scale_io_persistent_volume_source->storage_pool
    cJSON *storage_pool = cJSON_GetObjectItemCaseSensitive(v1_scale_io_persistent_volume_sourceJSON, "storagePool");
    if (storage_pool) { 
    if(!cJSON_IsString(storage_pool))
    {
    goto end; //String
    }
    }

    // v1_scale_io_persistent_volume_source->system
    cJSON *system = cJSON_GetObjectItemCaseSensitive(v1_scale_io_persistent_volume_sourceJSON, "system");
    if (!system) {
        goto end;
    }

    
    if(!cJSON_IsString(system))
    {
    goto end; //String
    }

    // v1_scale_io_persistent_volume_source->volume_name
    cJSON *volume_name = cJSON_GetObjectItemCaseSensitive(v1_scale_io_persistent_volume_sourceJSON, "volumeName");
    if (volume_name) { 
    if(!cJSON_IsString(volume_name))
    {
    goto end; //String
    }
    }


    v1_scale_io_persistent_volume_source_local_var = v1_scale_io_persistent_volume_source_create (
        fs_type ? strdup(fs_type->valuestring) : NULL,
        strdup(gateway->valuestring),
        protection_domain ? strdup(protection_domain->valuestring) : NULL,
        read_only ? read_only->valueint : 0,
        secret_ref_local_nonprim,
        ssl_enabled ? ssl_enabled->valueint : 0,
        storage_mode ? strdup(storage_mode->valuestring) : NULL,
        storage_pool ? strdup(storage_pool->valuestring) : NULL,
        strdup(system->valuestring),
        volume_name ? strdup(volume_name->valuestring) : NULL
        );

    return v1_scale_io_persistent_volume_source_local_var;
end:
    if (secret_ref_local_nonprim) {
        v1_secret_reference_free(secret_ref_local_nonprim);
        secret_ref_local_nonprim = NULL;
    }
    return NULL;

}
