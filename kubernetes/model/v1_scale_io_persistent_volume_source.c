#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_scale_io_persistent_volume_source.h"



static v1_scale_io_persistent_volume_source_t *v1_scale_io_persistent_volume_source_create_internal(
    char *fs_type,
    char *gateway,
    char *protection_domain,
    int *read_only,
    v1_secret_reference_t *secret_ref,
    int *ssl_enabled,
    char *storage_mode,
    char *storage_pool,
    char *system,
    char *volume_name
    ) {
    v1_scale_io_persistent_volume_source_t *v1_scale_io_persistent_volume_source_local_var = malloc(sizeof(v1_scale_io_persistent_volume_source_t));
    if (!v1_scale_io_persistent_volume_source_local_var) {
        return NULL;
    }
    memset(v1_scale_io_persistent_volume_source_local_var, 0, sizeof(v1_scale_io_persistent_volume_source_t));
    v1_scale_io_persistent_volume_source_local_var->_library_owned = 1;
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

__attribute__((deprecated)) v1_scale_io_persistent_volume_source_t *v1_scale_io_persistent_volume_source_create(
    char *fs_type,
    char *gateway,
    char *protection_domain,
    int *read_only,
    v1_secret_reference_t *secret_ref,
    int *ssl_enabled,
    char *storage_mode,
    char *storage_pool,
    char *system,
    char *volume_name
    ) {
    int *read_only_copy = NULL;
    if (read_only) {
        read_only_copy = malloc(sizeof(int));
        if (read_only_copy) *read_only_copy = *read_only;
    }
    int *ssl_enabled_copy = NULL;
    if (ssl_enabled) {
        ssl_enabled_copy = malloc(sizeof(int));
        if (ssl_enabled_copy) *ssl_enabled_copy = *ssl_enabled;
    }
    v1_scale_io_persistent_volume_source_t *result = v1_scale_io_persistent_volume_source_create_internal (
        fs_type,
        gateway,
        protection_domain,
        read_only_copy,
        secret_ref,
        ssl_enabled_copy,
        storage_mode,
        storage_pool,
        system,
        volume_name
        );
    if (!result) {
        free(read_only_copy);
        free(ssl_enabled_copy);
    }
    return result;
}

void v1_scale_io_persistent_volume_source_free(v1_scale_io_persistent_volume_source_t *v1_scale_io_persistent_volume_source) {
    if(NULL == v1_scale_io_persistent_volume_source){
        return ;
    }
    if(v1_scale_io_persistent_volume_source->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_scale_io_persistent_volume_source_free");
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
    if (v1_scale_io_persistent_volume_source->read_only) {
        free(v1_scale_io_persistent_volume_source->read_only);
        v1_scale_io_persistent_volume_source->read_only = NULL;
    }
    if (v1_scale_io_persistent_volume_source->secret_ref) {
        v1_secret_reference_free(v1_scale_io_persistent_volume_source->secret_ref);
        v1_scale_io_persistent_volume_source->secret_ref = NULL;
    }
    if (v1_scale_io_persistent_volume_source->ssl_enabled) {
        free(v1_scale_io_persistent_volume_source->ssl_enabled);
        v1_scale_io_persistent_volume_source->ssl_enabled = NULL;
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
    if(cJSON_AddBoolToObject(item, "readOnly", *v1_scale_io_persistent_volume_source->read_only) == NULL) {
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
    if(cJSON_AddBoolToObject(item, "sslEnabled", *v1_scale_io_persistent_volume_source->ssl_enabled) == NULL) {
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

    char *fs_type_local_str = NULL;

    char *gateway_local_str = NULL;

    char *protection_domain_local_str = NULL;

    // define the local variable for v1_scale_io_persistent_volume_source->read_only
    int *read_only_local_var = NULL;

    // define the local variable for v1_scale_io_persistent_volume_source->secret_ref
    v1_secret_reference_t *secret_ref_local_nonprim = NULL;

    // define the local variable for v1_scale_io_persistent_volume_source->ssl_enabled
    int *ssl_enabled_local_var = NULL;

    char *storage_mode_local_str = NULL;

    char *storage_pool_local_str = NULL;

    char *system_local_str = NULL;

    char *volume_name_local_str = NULL;

    // v1_scale_io_persistent_volume_source->fs_type
    cJSON *fs_type = cJSON_GetObjectItemCaseSensitive(v1_scale_io_persistent_volume_sourceJSON, "fsType");
    if (cJSON_IsNull(fs_type)) {
        fs_type = NULL;
    }
    if (fs_type) { 
    if(!cJSON_IsString(fs_type) && !cJSON_IsNull(fs_type))
    {
    goto end; //String
    }
    }

    // v1_scale_io_persistent_volume_source->gateway
    cJSON *gateway = cJSON_GetObjectItemCaseSensitive(v1_scale_io_persistent_volume_sourceJSON, "gateway");
    if (cJSON_IsNull(gateway)) {
        gateway = NULL;
    }
    if (!gateway) {
        goto end;
    }

    
    if(!cJSON_IsString(gateway))
    {
    goto end; //String
    }

    // v1_scale_io_persistent_volume_source->protection_domain
    cJSON *protection_domain = cJSON_GetObjectItemCaseSensitive(v1_scale_io_persistent_volume_sourceJSON, "protectionDomain");
    if (cJSON_IsNull(protection_domain)) {
        protection_domain = NULL;
    }
    if (protection_domain) { 
    if(!cJSON_IsString(protection_domain) && !cJSON_IsNull(protection_domain))
    {
    goto end; //String
    }
    }

    // v1_scale_io_persistent_volume_source->read_only
    cJSON *read_only = cJSON_GetObjectItemCaseSensitive(v1_scale_io_persistent_volume_sourceJSON, "readOnly");
    if (cJSON_IsNull(read_only)) {
        read_only = NULL;
    }
    if (read_only) { 
    if(!cJSON_IsBool(read_only))
    {
    goto end; //Bool
    }
    read_only_local_var = malloc(sizeof(int));
    if(!read_only_local_var)
    {
        goto end;
    }
    *read_only_local_var = read_only->valueint;
    }

    // v1_scale_io_persistent_volume_source->secret_ref
    cJSON *secret_ref = cJSON_GetObjectItemCaseSensitive(v1_scale_io_persistent_volume_sourceJSON, "secretRef");
    if (cJSON_IsNull(secret_ref)) {
        secret_ref = NULL;
    }
    if (!secret_ref) {
        goto end;
    }

    
    secret_ref_local_nonprim = v1_secret_reference_parseFromJSON(secret_ref); //nonprimitive

    // v1_scale_io_persistent_volume_source->ssl_enabled
    cJSON *ssl_enabled = cJSON_GetObjectItemCaseSensitive(v1_scale_io_persistent_volume_sourceJSON, "sslEnabled");
    if (cJSON_IsNull(ssl_enabled)) {
        ssl_enabled = NULL;
    }
    if (ssl_enabled) { 
    if(!cJSON_IsBool(ssl_enabled))
    {
    goto end; //Bool
    }
    ssl_enabled_local_var = malloc(sizeof(int));
    if(!ssl_enabled_local_var)
    {
        goto end;
    }
    *ssl_enabled_local_var = ssl_enabled->valueint;
    }

    // v1_scale_io_persistent_volume_source->storage_mode
    cJSON *storage_mode = cJSON_GetObjectItemCaseSensitive(v1_scale_io_persistent_volume_sourceJSON, "storageMode");
    if (cJSON_IsNull(storage_mode)) {
        storage_mode = NULL;
    }
    if (storage_mode) { 
    if(!cJSON_IsString(storage_mode) && !cJSON_IsNull(storage_mode))
    {
    goto end; //String
    }
    }

    // v1_scale_io_persistent_volume_source->storage_pool
    cJSON *storage_pool = cJSON_GetObjectItemCaseSensitive(v1_scale_io_persistent_volume_sourceJSON, "storagePool");
    if (cJSON_IsNull(storage_pool)) {
        storage_pool = NULL;
    }
    if (storage_pool) { 
    if(!cJSON_IsString(storage_pool) && !cJSON_IsNull(storage_pool))
    {
    goto end; //String
    }
    }

    // v1_scale_io_persistent_volume_source->system
    cJSON *system = cJSON_GetObjectItemCaseSensitive(v1_scale_io_persistent_volume_sourceJSON, "system");
    if (cJSON_IsNull(system)) {
        system = NULL;
    }
    if (!system) {
        goto end;
    }

    
    if(!cJSON_IsString(system))
    {
    goto end; //String
    }

    // v1_scale_io_persistent_volume_source->volume_name
    cJSON *volume_name = cJSON_GetObjectItemCaseSensitive(v1_scale_io_persistent_volume_sourceJSON, "volumeName");
    if (cJSON_IsNull(volume_name)) {
        volume_name = NULL;
    }
    if (volume_name) { 
    if(!cJSON_IsString(volume_name) && !cJSON_IsNull(volume_name))
    {
    goto end; //String
    }
    }


    if (fs_type && !cJSON_IsNull(fs_type)) fs_type_local_str = strdup(fs_type->valuestring);
    if (gateway && !cJSON_IsNull(gateway)) gateway_local_str = strdup(gateway->valuestring);
    if (protection_domain && !cJSON_IsNull(protection_domain)) protection_domain_local_str = strdup(protection_domain->valuestring);
    if (storage_mode && !cJSON_IsNull(storage_mode)) storage_mode_local_str = strdup(storage_mode->valuestring);
    if (storage_pool && !cJSON_IsNull(storage_pool)) storage_pool_local_str = strdup(storage_pool->valuestring);
    if (system && !cJSON_IsNull(system)) system_local_str = strdup(system->valuestring);
    if (volume_name && !cJSON_IsNull(volume_name)) volume_name_local_str = strdup(volume_name->valuestring);

    v1_scale_io_persistent_volume_source_local_var = v1_scale_io_persistent_volume_source_create_internal (
        fs_type_local_str,
        gateway_local_str,
        protection_domain_local_str,
        read_only_local_var,
        secret_ref_local_nonprim,
        ssl_enabled_local_var,
        storage_mode_local_str,
        storage_pool_local_str,
        system_local_str,
        volume_name_local_str
        );

    if (!v1_scale_io_persistent_volume_source_local_var) {
        goto end;
    }

    return v1_scale_io_persistent_volume_source_local_var;
end:
    if (fs_type_local_str) {
        free(fs_type_local_str);
        fs_type_local_str = NULL;
    }
    if (gateway_local_str) {
        free(gateway_local_str);
        gateway_local_str = NULL;
    }
    if (protection_domain_local_str) {
        free(protection_domain_local_str);
        protection_domain_local_str = NULL;
    }
    if (read_only_local_var) {
        free(read_only_local_var);
        read_only_local_var = NULL;
    }
    if (secret_ref_local_nonprim) {
        v1_secret_reference_free(secret_ref_local_nonprim);
        secret_ref_local_nonprim = NULL;
    }
    if (ssl_enabled_local_var) {
        free(ssl_enabled_local_var);
        ssl_enabled_local_var = NULL;
    }
    if (storage_mode_local_str) {
        free(storage_mode_local_str);
        storage_mode_local_str = NULL;
    }
    if (storage_pool_local_str) {
        free(storage_pool_local_str);
        storage_pool_local_str = NULL;
    }
    if (system_local_str) {
        free(system_local_str);
        system_local_str = NULL;
    }
    if (volume_name_local_str) {
        free(volume_name_local_str);
        volume_name_local_str = NULL;
    }
    return NULL;

}
