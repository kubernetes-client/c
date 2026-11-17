#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_volume_mount.h"



static v1_volume_mount_t *v1_volume_mount_create_internal(
    list_t *bind_mount_options,
    char *mount_path,
    char *mount_propagation,
    char *name,
    int *read_only,
    char *recursive_read_only,
    char *sub_path,
    char *sub_path_expr
    ) {
    v1_volume_mount_t *v1_volume_mount_local_var = malloc(sizeof(v1_volume_mount_t));
    if (!v1_volume_mount_local_var) {
        return NULL;
    }
    memset(v1_volume_mount_local_var, 0, sizeof(v1_volume_mount_t));
    v1_volume_mount_local_var->_library_owned = 1;
    v1_volume_mount_local_var->bind_mount_options = bind_mount_options;
    v1_volume_mount_local_var->mount_path = mount_path;
    v1_volume_mount_local_var->mount_propagation = mount_propagation;
    v1_volume_mount_local_var->name = name;
    v1_volume_mount_local_var->read_only = read_only;
    v1_volume_mount_local_var->recursive_read_only = recursive_read_only;
    v1_volume_mount_local_var->sub_path = sub_path;
    v1_volume_mount_local_var->sub_path_expr = sub_path_expr;
    return v1_volume_mount_local_var;
}

__attribute__((deprecated)) v1_volume_mount_t *v1_volume_mount_create(
    list_t *bind_mount_options,
    char *mount_path,
    char *mount_propagation,
    char *name,
    int *read_only,
    char *recursive_read_only,
    char *sub_path,
    char *sub_path_expr
    ) {
    int *read_only_copy = NULL;
    if (read_only) {
        read_only_copy = malloc(sizeof(int));
        if (read_only_copy) *read_only_copy = *read_only;
    }
    v1_volume_mount_t *result = v1_volume_mount_create_internal (
        bind_mount_options,
        mount_path,
        mount_propagation,
        name,
        read_only_copy,
        recursive_read_only,
        sub_path,
        sub_path_expr
        );
    if (!result) {
        free(read_only_copy);
    }
    return result;
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
    if (v1_volume_mount->bind_mount_options) {
        list_ForEach(listEntry, v1_volume_mount->bind_mount_options) {
            free(listEntry->data);
        }
        list_freeList(v1_volume_mount->bind_mount_options);
        v1_volume_mount->bind_mount_options = NULL;
    }
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
    if (v1_volume_mount->read_only) {
        free(v1_volume_mount->read_only);
        v1_volume_mount->read_only = NULL;
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

    // v1_volume_mount->bind_mount_options
    if(v1_volume_mount->bind_mount_options) {
    cJSON *bind_mount_options = cJSON_AddArrayToObject(item, "bindMountOptions");
    if(bind_mount_options == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *bind_mount_optionsListEntry;
    list_ForEach(bind_mount_optionsListEntry, v1_volume_mount->bind_mount_options) {
    if(cJSON_AddStringToObject(bind_mount_options, "", bind_mount_optionsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


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
    if(cJSON_AddBoolToObject(item, "readOnly", *v1_volume_mount->read_only) == NULL) {
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

    // define the local list for v1_volume_mount->bind_mount_options
    list_t *bind_mount_optionsList = NULL;

    char *mount_path_local_str = NULL;

    char *mount_propagation_local_str = NULL;

    char *name_local_str = NULL;

    // define the local variable for v1_volume_mount->read_only
    int *read_only_local_var = NULL;

    char *recursive_read_only_local_str = NULL;

    char *sub_path_local_str = NULL;

    char *sub_path_expr_local_str = NULL;

    // v1_volume_mount->bind_mount_options
    cJSON *bind_mount_options = cJSON_GetObjectItemCaseSensitive(v1_volume_mountJSON, "bindMountOptions");
    if (cJSON_IsNull(bind_mount_options)) {
        bind_mount_options = NULL;
    }
    if (bind_mount_options) { 
    cJSON *bind_mount_options_local = NULL;
    if(!cJSON_IsArray(bind_mount_options)) {
        goto end;//primitive container
    }
    bind_mount_optionsList = list_createList();

    cJSON_ArrayForEach(bind_mount_options_local, bind_mount_options)
    {
        if(!cJSON_IsString(bind_mount_options_local))
        {
            goto end;
        }
        list_addElement(bind_mount_optionsList , strdup(bind_mount_options_local->valuestring));
    }
    }

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
    read_only_local_var = malloc(sizeof(int));
    if(!read_only_local_var)
    {
        goto end;
    }
    *read_only_local_var = read_only->valueint;
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


    if (mount_path && !cJSON_IsNull(mount_path)) mount_path_local_str = strdup(mount_path->valuestring);
    if (mount_propagation && !cJSON_IsNull(mount_propagation)) mount_propagation_local_str = strdup(mount_propagation->valuestring);
    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);
    if (recursive_read_only && !cJSON_IsNull(recursive_read_only)) recursive_read_only_local_str = strdup(recursive_read_only->valuestring);
    if (sub_path && !cJSON_IsNull(sub_path)) sub_path_local_str = strdup(sub_path->valuestring);
    if (sub_path_expr && !cJSON_IsNull(sub_path_expr)) sub_path_expr_local_str = strdup(sub_path_expr->valuestring);

    v1_volume_mount_local_var = v1_volume_mount_create_internal (
        bind_mount_options ? bind_mount_optionsList : NULL,
        mount_path_local_str,
        mount_propagation_local_str,
        name_local_str,
        read_only_local_var,
        recursive_read_only_local_str,
        sub_path_local_str,
        sub_path_expr_local_str
        );

    if (!v1_volume_mount_local_var) {
        goto end;
    }

    return v1_volume_mount_local_var;
end:
    if (bind_mount_optionsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, bind_mount_optionsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(bind_mount_optionsList);
        bind_mount_optionsList = NULL;
    }
    if (mount_path_local_str) {
        free(mount_path_local_str);
        mount_path_local_str = NULL;
    }
    if (mount_propagation_local_str) {
        free(mount_propagation_local_str);
        mount_propagation_local_str = NULL;
    }
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    if (read_only_local_var) {
        free(read_only_local_var);
        read_only_local_var = NULL;
    }
    if (recursive_read_only_local_str) {
        free(recursive_read_only_local_str);
        recursive_read_only_local_str = NULL;
    }
    if (sub_path_local_str) {
        free(sub_path_local_str);
        sub_path_local_str = NULL;
    }
    if (sub_path_expr_local_str) {
        free(sub_path_expr_local_str);
        sub_path_expr_local_str = NULL;
    }
    return NULL;

}
