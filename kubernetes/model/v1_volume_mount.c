#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_volume_mount.h"



static v1_volume_mount_t *v1_volume_mount_create_internal(
    char *mount_path,
    char *mount_propagation,
    char *name,
    int read_only,
    char *recursive_read_only,
    char *sub_path,
    char *sub_path_expr
    ) {
    v1_volume_mount_t *v1_volume_mount_local_var = malloc(sizeof(v1_volume_mount_t));
    if (!v1_volume_mount_local_var) {
        return NULL;
    }
    v1_volume_mount_local_var->mount_path = mount_path;
    v1_volume_mount_local_var->mount_propagation = mount_propagation;
    v1_volume_mount_local_var->name = name;
    v1_volume_mount_local_var->read_only = read_only;
    v1_volume_mount_local_var->recursive_read_only = recursive_read_only;
    v1_volume_mount_local_var->sub_path = sub_path;
    v1_volume_mount_local_var->sub_path_expr = sub_path_expr;

    v1_volume_mount_local_var->_library_owned = 1;
    return v1_volume_mount_local_var;
}

__attribute__((deprecated)) v1_volume_mount_t *v1_volume_mount_create(
    char *mount_path,
    char *mount_propagation,
    char *name,
    int read_only,
    char *recursive_read_only,
    char *sub_path,
    char *sub_path_expr
    ) {
    return v1_volume_mount_create_internal (
        mount_path,
        mount_propagation,
        name,
        read_only,
        recursive_read_only,
        sub_path,
        sub_path_expr
        );
}

void v1_volume_mount_free(v1_volume_mount_t *v1_volume_mount) {
    if(NULL == v1_volume_mount){
        return ;
    }
    if(v1_volume_mount->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_volume_mount_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_volume_mount->mount_path) {
        free(v1_volume_mount->mount_path);
        v1_volume_mount->mount_path = NULL;
    }
    if (v1_volume_mount->mount_propagation) {
        free(v1_volume_mount->mount_propagation);
        v1_volume_mount->mount_propagation = NULL;
    }
    if (v1_volume_mount->name) {
        free(v1_volume_mount->name);
        v1_volume_mount->name = NULL;
    }
    if (v1_volume_mount->recursive_read_only) {
        free(v1_volume_mount->recursive_read_only);
        v1_volume_mount->recursive_read_only = NULL;
    }
    if (v1_volume_mount->sub_path) {
        free(v1_volume_mount->sub_path);
        v1_volume_mount->sub_path = NULL;
    }
    if (v1_volume_mount->sub_path_expr) {
        free(v1_volume_mount->sub_path_expr);
        v1_volume_mount->sub_path_expr = NULL;
    }
    free(v1_volume_mount);
}

cJSON *v1_volume_mount_convertToJSON(v1_volume_mount_t *v1_volume_mount) {
    cJSON *item = cJSON_CreateObject();

    // v1_volume_mount->mount_path
    if (!v1_volume_mount->mount_path) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "mountPath", v1_volume_mount->mount_path) == NULL) {
    goto fail; //String
    }


    // v1_volume_mount->mount_propagation
    if(v1_volume_mount->mount_propagation) {
    if(cJSON_AddStringToObject(item, "mountPropagation", v1_volume_mount->mount_propagation) == NULL) {
    goto fail; //String
    }
    }


    // v1_volume_mount->name
    if (!v1_volume_mount->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", v1_volume_mount->name) == NULL) {
    goto fail; //String
    }


    // v1_volume_mount->read_only
    if(v1_volume_mount->read_only) {
    if(cJSON_AddBoolToObject(item, "readOnly", v1_volume_mount->read_only) == NULL) {
    goto fail; //Bool
    }
    }


    // v1_volume_mount->recursive_read_only
    if(v1_volume_mount->recursive_read_only) {
    if(cJSON_AddStringToObject(item, "recursiveReadOnly", v1_volume_mount->recursive_read_only) == NULL) {
    goto fail; //String
    }
    }


    // v1_volume_mount->sub_path
    if(v1_volume_mount->sub_path) {
    if(cJSON_AddStringToObject(item, "subPath", v1_volume_mount->sub_path) == NULL) {
    goto fail; //String
    }
    }


    // v1_volume_mount->sub_path_expr
    if(v1_volume_mount->sub_path_expr) {
    if(cJSON_AddStringToObject(item, "subPathExpr", v1_volume_mount->sub_path_expr) == NULL) {
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

v1_volume_mount_t *v1_volume_mount_parseFromJSON(cJSON *v1_volume_mountJSON){

    v1_volume_mount_t *v1_volume_mount_local_var = NULL;

    // v1_volume_mount->mount_path
    cJSON *mount_path = cJSON_GetObjectItemCaseSensitive(v1_volume_mountJSON, "mountPath");
    if (cJSON_IsNull(mount_path)) {
        mount_path = NULL;
    }
    if (!mount_path) {
        goto end;
    }

    
    if(!cJSON_IsString(mount_path))
    {
    goto end; //String
    }

    // v1_volume_mount->mount_propagation
    cJSON *mount_propagation = cJSON_GetObjectItemCaseSensitive(v1_volume_mountJSON, "mountPropagation");
    if (cJSON_IsNull(mount_propagation)) {
        mount_propagation = NULL;
    }
    if (mount_propagation) { 
    if(!cJSON_IsString(mount_propagation) && !cJSON_IsNull(mount_propagation))
    {
    goto end; //String
    }
    }

    // v1_volume_mount->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1_volume_mountJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // v1_volume_mount->read_only
    cJSON *read_only = cJSON_GetObjectItemCaseSensitive(v1_volume_mountJSON, "readOnly");
    if (cJSON_IsNull(read_only)) {
        read_only = NULL;
    }
    if (read_only) { 
    if(!cJSON_IsBool(read_only))
    {
    goto end; //Bool
    }
    }

    // v1_volume_mount->recursive_read_only
    cJSON *recursive_read_only = cJSON_GetObjectItemCaseSensitive(v1_volume_mountJSON, "recursiveReadOnly");
    if (cJSON_IsNull(recursive_read_only)) {
        recursive_read_only = NULL;
    }
    if (recursive_read_only) { 
    if(!cJSON_IsString(recursive_read_only) && !cJSON_IsNull(recursive_read_only))
    {
    goto end; //String
    }
    }

    // v1_volume_mount->sub_path
    cJSON *sub_path = cJSON_GetObjectItemCaseSensitive(v1_volume_mountJSON, "subPath");
    if (cJSON_IsNull(sub_path)) {
        sub_path = NULL;
    }
    if (sub_path) { 
    if(!cJSON_IsString(sub_path) && !cJSON_IsNull(sub_path))
    {
    goto end; //String
    }
    }

    // v1_volume_mount->sub_path_expr
    cJSON *sub_path_expr = cJSON_GetObjectItemCaseSensitive(v1_volume_mountJSON, "subPathExpr");
    if (cJSON_IsNull(sub_path_expr)) {
        sub_path_expr = NULL;
    }
    if (sub_path_expr) { 
    if(!cJSON_IsString(sub_path_expr) && !cJSON_IsNull(sub_path_expr))
    {
    goto end; //String
    }
    }


    v1_volume_mount_local_var = v1_volume_mount_create_internal (
        strdup(mount_path->valuestring),
        mount_propagation && !cJSON_IsNull(mount_propagation) ? strdup(mount_propagation->valuestring) : NULL,
        strdup(name->valuestring),
        read_only ? read_only->valueint : 0,
        recursive_read_only && !cJSON_IsNull(recursive_read_only) ? strdup(recursive_read_only->valuestring) : NULL,
        sub_path && !cJSON_IsNull(sub_path) ? strdup(sub_path->valuestring) : NULL,
        sub_path_expr && !cJSON_IsNull(sub_path_expr) ? strdup(sub_path_expr->valuestring) : NULL
        );

    return v1_volume_mount_local_var;
end:
    return NULL;

}
