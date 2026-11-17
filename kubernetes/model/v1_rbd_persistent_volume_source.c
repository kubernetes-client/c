#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_rbd_persistent_volume_source.h"



static v1_rbd_persistent_volume_source_t *v1_rbd_persistent_volume_source_create_internal(
    char *fs_type,
    char *image,
    char *keyring,
    list_t *monitors,
    char *pool,
    int *read_only,
    v1_secret_reference_t *secret_ref,
    char *user
    ) {
    v1_rbd_persistent_volume_source_t *v1_rbd_persistent_volume_source_local_var = malloc(sizeof(v1_rbd_persistent_volume_source_t));
    if (!v1_rbd_persistent_volume_source_local_var) {
        return NULL;
    }
    memset(v1_rbd_persistent_volume_source_local_var, 0, sizeof(v1_rbd_persistent_volume_source_t));
    v1_rbd_persistent_volume_source_local_var->_library_owned = 1;
    v1_rbd_persistent_volume_source_local_var->fs_type = fs_type;
    v1_rbd_persistent_volume_source_local_var->image = image;
    v1_rbd_persistent_volume_source_local_var->keyring = keyring;
    v1_rbd_persistent_volume_source_local_var->monitors = monitors;
    v1_rbd_persistent_volume_source_local_var->pool = pool;
    v1_rbd_persistent_volume_source_local_var->read_only = read_only;
    v1_rbd_persistent_volume_source_local_var->secret_ref = secret_ref;
    v1_rbd_persistent_volume_source_local_var->user = user;
    return v1_rbd_persistent_volume_source_local_var;
}

__attribute__((deprecated)) v1_rbd_persistent_volume_source_t *v1_rbd_persistent_volume_source_create(
    char *fs_type,
    char *image,
    char *keyring,
    list_t *monitors,
    char *pool,
    int *read_only,
    v1_secret_reference_t *secret_ref,
    char *user
    ) {
    int *read_only_copy = NULL;
    if (read_only) {
        read_only_copy = malloc(sizeof(int));
        if (read_only_copy) *read_only_copy = *read_only;
    }
    v1_rbd_persistent_volume_source_t *result = v1_rbd_persistent_volume_source_create_internal (
        fs_type,
        image,
        keyring,
        monitors,
        pool,
        read_only_copy,
        secret_ref,
        user
        );
    if (!result) {
        free(read_only_copy);
    }
    return result;
}

void v1_rbd_persistent_volume_source_free(v1_rbd_persistent_volume_source_t *v1_rbd_persistent_volume_source) {
    if(NULL == v1_rbd_persistent_volume_source){
        return ;
    }
    if(v1_rbd_persistent_volume_source->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_rbd_persistent_volume_source_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_rbd_persistent_volume_source->fs_type) {
        free(v1_rbd_persistent_volume_source->fs_type);
        v1_rbd_persistent_volume_source->fs_type = NULL;
    }
    if (v1_rbd_persistent_volume_source->image) {
        free(v1_rbd_persistent_volume_source->image);
        v1_rbd_persistent_volume_source->image = NULL;
    }
    if (v1_rbd_persistent_volume_source->keyring) {
        free(v1_rbd_persistent_volume_source->keyring);
        v1_rbd_persistent_volume_source->keyring = NULL;
    }
    if (v1_rbd_persistent_volume_source->monitors) {
        list_ForEach(listEntry, v1_rbd_persistent_volume_source->monitors) {
            free(listEntry->data);
        }
        list_freeList(v1_rbd_persistent_volume_source->monitors);
        v1_rbd_persistent_volume_source->monitors = NULL;
    }
    if (v1_rbd_persistent_volume_source->pool) {
        free(v1_rbd_persistent_volume_source->pool);
        v1_rbd_persistent_volume_source->pool = NULL;
    }
    if (v1_rbd_persistent_volume_source->read_only) {
        free(v1_rbd_persistent_volume_source->read_only);
        v1_rbd_persistent_volume_source->read_only = NULL;
    }
    if (v1_rbd_persistent_volume_source->secret_ref) {
        v1_secret_reference_free(v1_rbd_persistent_volume_source->secret_ref);
        v1_rbd_persistent_volume_source->secret_ref = NULL;
    }
    if (v1_rbd_persistent_volume_source->user) {
        free(v1_rbd_persistent_volume_source->user);
        v1_rbd_persistent_volume_source->user = NULL;
    }
    free(v1_rbd_persistent_volume_source);
}

cJSON *v1_rbd_persistent_volume_source_convertToJSON(v1_rbd_persistent_volume_source_t *v1_rbd_persistent_volume_source) {
    cJSON *item = cJSON_CreateObject();

    // v1_rbd_persistent_volume_source->fs_type
    if(v1_rbd_persistent_volume_source->fs_type) {
    if(cJSON_AddStringToObject(item, "fsType", v1_rbd_persistent_volume_source->fs_type) == NULL) {
    goto fail; //String
    }
    }


    // v1_rbd_persistent_volume_source->image
    if (!v1_rbd_persistent_volume_source->image) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "image", v1_rbd_persistent_volume_source->image) == NULL) {
    goto fail; //String
    }


    // v1_rbd_persistent_volume_source->keyring
    if(v1_rbd_persistent_volume_source->keyring) {
    if(cJSON_AddStringToObject(item, "keyring", v1_rbd_persistent_volume_source->keyring) == NULL) {
    goto fail; //String
    }
    }


    // v1_rbd_persistent_volume_source->monitors
    if (!v1_rbd_persistent_volume_source->monitors) {
        goto fail;
    }
    cJSON *monitors = cJSON_AddArrayToObject(item, "monitors");
    if(monitors == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *monitorsListEntry;
    list_ForEach(monitorsListEntry, v1_rbd_persistent_volume_source->monitors) {
    if(cJSON_AddStringToObject(monitors, "", monitorsListEntry->data) == NULL)
    {
        goto fail;
    }
    }


    // v1_rbd_persistent_volume_source->pool
    if(v1_rbd_persistent_volume_source->pool) {
    if(cJSON_AddStringToObject(item, "pool", v1_rbd_persistent_volume_source->pool) == NULL) {
    goto fail; //String
    }
    }


    // v1_rbd_persistent_volume_source->read_only
    if(v1_rbd_persistent_volume_source->read_only) {
    if(cJSON_AddBoolToObject(item, "readOnly", *v1_rbd_persistent_volume_source->read_only) == NULL) {
    goto fail; //Bool
    }
    }


    // v1_rbd_persistent_volume_source->secret_ref
    if(v1_rbd_persistent_volume_source->secret_ref) {
    cJSON *secret_ref_local_JSON = v1_secret_reference_convertToJSON(v1_rbd_persistent_volume_source->secret_ref);
    if(secret_ref_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "secretRef", secret_ref_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_rbd_persistent_volume_source->user
    if(v1_rbd_persistent_volume_source->user) {
    if(cJSON_AddStringToObject(item, "user", v1_rbd_persistent_volume_source->user) == NULL) {
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

v1_rbd_persistent_volume_source_t *v1_rbd_persistent_volume_source_parseFromJSON(cJSON *v1_rbd_persistent_volume_sourceJSON){

    v1_rbd_persistent_volume_source_t *v1_rbd_persistent_volume_source_local_var = NULL;

    char *fs_type_local_str = NULL;

    char *image_local_str = NULL;

    char *keyring_local_str = NULL;

    // define the local list for v1_rbd_persistent_volume_source->monitors
    list_t *monitorsList = NULL;

    char *pool_local_str = NULL;

    // define the local variable for v1_rbd_persistent_volume_source->read_only
    int *read_only_local_var = NULL;

    // define the local variable for v1_rbd_persistent_volume_source->secret_ref
    v1_secret_reference_t *secret_ref_local_nonprim = NULL;

    char *user_local_str = NULL;

    // v1_rbd_persistent_volume_source->fs_type
    cJSON *fs_type = cJSON_GetObjectItemCaseSensitive(v1_rbd_persistent_volume_sourceJSON, "fsType");
    if (cJSON_IsNull(fs_type)) {
        fs_type = NULL;
    }
    if (fs_type) { 
    if(!cJSON_IsString(fs_type) && !cJSON_IsNull(fs_type))
    {
    goto end; //String
    }
    }

    // v1_rbd_persistent_volume_source->image
    cJSON *image = cJSON_GetObjectItemCaseSensitive(v1_rbd_persistent_volume_sourceJSON, "image");
    if (cJSON_IsNull(image)) {
        image = NULL;
    }
    if (!image) {
        goto end;
    }

    
    if(!cJSON_IsString(image))
    {
    goto end; //String
    }

    // v1_rbd_persistent_volume_source->keyring
    cJSON *keyring = cJSON_GetObjectItemCaseSensitive(v1_rbd_persistent_volume_sourceJSON, "keyring");
    if (cJSON_IsNull(keyring)) {
        keyring = NULL;
    }
    if (keyring) { 
    if(!cJSON_IsString(keyring) && !cJSON_IsNull(keyring))
    {
    goto end; //String
    }
    }

    // v1_rbd_persistent_volume_source->monitors
    cJSON *monitors = cJSON_GetObjectItemCaseSensitive(v1_rbd_persistent_volume_sourceJSON, "monitors");
    if (cJSON_IsNull(monitors)) {
        monitors = NULL;
    }
    if (!monitors) {
        goto end;
    }

    
    cJSON *monitors_local = NULL;
    if(!cJSON_IsArray(monitors)) {
        goto end;//primitive container
    }
    monitorsList = list_createList();

    cJSON_ArrayForEach(monitors_local, monitors)
    {
        if(!cJSON_IsString(monitors_local))
        {
            goto end;
        }
        list_addElement(monitorsList , strdup(monitors_local->valuestring));
    }

    // v1_rbd_persistent_volume_source->pool
    cJSON *pool = cJSON_GetObjectItemCaseSensitive(v1_rbd_persistent_volume_sourceJSON, "pool");
    if (cJSON_IsNull(pool)) {
        pool = NULL;
    }
    if (pool) { 
    if(!cJSON_IsString(pool) && !cJSON_IsNull(pool))
    {
    goto end; //String
    }
    }

    // v1_rbd_persistent_volume_source->read_only
    cJSON *read_only = cJSON_GetObjectItemCaseSensitive(v1_rbd_persistent_volume_sourceJSON, "readOnly");
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

    // v1_rbd_persistent_volume_source->secret_ref
    cJSON *secret_ref = cJSON_GetObjectItemCaseSensitive(v1_rbd_persistent_volume_sourceJSON, "secretRef");
    if (cJSON_IsNull(secret_ref)) {
        secret_ref = NULL;
    }
    if (secret_ref) { 
    secret_ref_local_nonprim = v1_secret_reference_parseFromJSON(secret_ref); //nonprimitive
    }

    // v1_rbd_persistent_volume_source->user
    cJSON *user = cJSON_GetObjectItemCaseSensitive(v1_rbd_persistent_volume_sourceJSON, "user");
    if (cJSON_IsNull(user)) {
        user = NULL;
    }
    if (user) { 
    if(!cJSON_IsString(user) && !cJSON_IsNull(user))
    {
    goto end; //String
    }
    }


    if (fs_type && !cJSON_IsNull(fs_type)) fs_type_local_str = strdup(fs_type->valuestring);
    if (image && !cJSON_IsNull(image)) image_local_str = strdup(image->valuestring);
    if (keyring && !cJSON_IsNull(keyring)) keyring_local_str = strdup(keyring->valuestring);
    if (pool && !cJSON_IsNull(pool)) pool_local_str = strdup(pool->valuestring);
    if (user && !cJSON_IsNull(user)) user_local_str = strdup(user->valuestring);

    v1_rbd_persistent_volume_source_local_var = v1_rbd_persistent_volume_source_create_internal (
        fs_type_local_str,
        image_local_str,
        keyring_local_str,
        monitorsList,
        pool_local_str,
        read_only_local_var,
        secret_ref ? secret_ref_local_nonprim : NULL,
        user_local_str
        );

    if (!v1_rbd_persistent_volume_source_local_var) {
        goto end;
    }

    return v1_rbd_persistent_volume_source_local_var;
end:
    if (fs_type_local_str) {
        free(fs_type_local_str);
        fs_type_local_str = NULL;
    }
    if (image_local_str) {
        free(image_local_str);
        image_local_str = NULL;
    }
    if (keyring_local_str) {
        free(keyring_local_str);
        keyring_local_str = NULL;
    }
    if (monitorsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, monitorsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(monitorsList);
        monitorsList = NULL;
    }
    if (pool_local_str) {
        free(pool_local_str);
        pool_local_str = NULL;
    }
    if (read_only_local_var) {
        free(read_only_local_var);
        read_only_local_var = NULL;
    }
    if (secret_ref_local_nonprim) {
        v1_secret_reference_free(secret_ref_local_nonprim);
        secret_ref_local_nonprim = NULL;
    }
    if (user_local_str) {
        free(user_local_str);
        user_local_str = NULL;
    }
    return NULL;

}
