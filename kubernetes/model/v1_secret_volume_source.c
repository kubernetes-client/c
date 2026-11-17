#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_secret_volume_source.h"



static v1_secret_volume_source_t *v1_secret_volume_source_create_internal(
    int *default_mode,
    long *default_user,
    list_t *items,
    int *optional,
    char *secret_name
    ) {
    v1_secret_volume_source_t *v1_secret_volume_source_local_var = malloc(sizeof(v1_secret_volume_source_t));
    if (!v1_secret_volume_source_local_var) {
        return NULL;
    }
    memset(v1_secret_volume_source_local_var, 0, sizeof(v1_secret_volume_source_t));
    v1_secret_volume_source_local_var->_library_owned = 1;
    v1_secret_volume_source_local_var->default_mode = default_mode;
    v1_secret_volume_source_local_var->default_user = default_user;
    v1_secret_volume_source_local_var->items = items;
    v1_secret_volume_source_local_var->optional = optional;
    v1_secret_volume_source_local_var->secret_name = secret_name;
    return v1_secret_volume_source_local_var;
}

__attribute__((deprecated)) v1_secret_volume_source_t *v1_secret_volume_source_create(
    int *default_mode,
    long *default_user,
    list_t *items,
    int *optional,
    char *secret_name
    ) {
    int *default_mode_copy = NULL;
    if (default_mode) {
        default_mode_copy = malloc(sizeof(int));
        if (default_mode_copy) *default_mode_copy = *default_mode;
    }
    long *default_user_copy = NULL;
    if (default_user) {
        default_user_copy = malloc(sizeof(long));
        if (default_user_copy) *default_user_copy = *default_user;
    }
    int *optional_copy = NULL;
    if (optional) {
        optional_copy = malloc(sizeof(int));
        if (optional_copy) *optional_copy = *optional;
    }
    v1_secret_volume_source_t *result = v1_secret_volume_source_create_internal (
        default_mode_copy,
        default_user_copy,
        items,
        optional_copy,
        secret_name
        );
    if (!result) {
        free(default_mode_copy);
        free(default_user_copy);
        free(optional_copy);
    }
    return result;
}

void v1_secret_volume_source_free(v1_secret_volume_source_t *v1_secret_volume_source) {
    if(NULL == v1_secret_volume_source){
        return ;
    }
    if(v1_secret_volume_source->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_secret_volume_source_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_secret_volume_source->default_mode) {
        free(v1_secret_volume_source->default_mode);
        v1_secret_volume_source->default_mode = NULL;
    }
    if (v1_secret_volume_source->default_user) {
        free(v1_secret_volume_source->default_user);
        v1_secret_volume_source->default_user = NULL;
    }
    if (v1_secret_volume_source->items) {
        list_ForEach(listEntry, v1_secret_volume_source->items) {
            v1_key_to_path_free(listEntry->data);
        }
        list_freeList(v1_secret_volume_source->items);
        v1_secret_volume_source->items = NULL;
    }
    if (v1_secret_volume_source->optional) {
        free(v1_secret_volume_source->optional);
        v1_secret_volume_source->optional = NULL;
    }
    if (v1_secret_volume_source->secret_name) {
        free(v1_secret_volume_source->secret_name);
        v1_secret_volume_source->secret_name = NULL;
    }
    free(v1_secret_volume_source);
}

cJSON *v1_secret_volume_source_convertToJSON(v1_secret_volume_source_t *v1_secret_volume_source) {
    cJSON *item = cJSON_CreateObject();

    // v1_secret_volume_source->default_mode
    if(v1_secret_volume_source->default_mode) {
    if(cJSON_AddNumberToObject(item, "defaultMode", *v1_secret_volume_source->default_mode) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_secret_volume_source->default_user
    if(v1_secret_volume_source->default_user) {
    if(cJSON_AddNumberToObject(item, "defaultUser", *v1_secret_volume_source->default_user) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_secret_volume_source->items
    if(v1_secret_volume_source->items) {
    cJSON *items = cJSON_AddArrayToObject(item, "items");
    if(items == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *itemsListEntry;
    if (v1_secret_volume_source->items) {
    list_ForEach(itemsListEntry, v1_secret_volume_source->items) {
    cJSON *itemLocal = v1_key_to_path_convertToJSON(itemsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(items, itemLocal);
    }
    }
    }


    // v1_secret_volume_source->optional
    if(v1_secret_volume_source->optional) {
    if(cJSON_AddBoolToObject(item, "optional", *v1_secret_volume_source->optional) == NULL) {
    goto fail; //Bool
    }
    }


    // v1_secret_volume_source->secret_name
    if(v1_secret_volume_source->secret_name) {
    if(cJSON_AddStringToObject(item, "secretName", v1_secret_volume_source->secret_name) == NULL) {
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

v1_secret_volume_source_t *v1_secret_volume_source_parseFromJSON(cJSON *v1_secret_volume_sourceJSON){

    v1_secret_volume_source_t *v1_secret_volume_source_local_var = NULL;

    // define the local variable for v1_secret_volume_source->default_mode
    int *default_mode_local_var = NULL;

    // define the local variable for v1_secret_volume_source->default_user
    long *default_user_local_var = NULL;

    // define the local list for v1_secret_volume_source->items
    list_t *itemsList = NULL;

    // define the local variable for v1_secret_volume_source->optional
    int *optional_local_var = NULL;

    char *secret_name_local_str = NULL;

    // v1_secret_volume_source->default_mode
    cJSON *default_mode = cJSON_GetObjectItemCaseSensitive(v1_secret_volume_sourceJSON, "defaultMode");
    if (cJSON_IsNull(default_mode)) {
        default_mode = NULL;
    }
    if (default_mode) { 
    if(!cJSON_IsNumber(default_mode))
    {
    goto end; //Numeric
    }
    default_mode_local_var = malloc(sizeof(int));
    if(!default_mode_local_var)
    {
        goto end;
    }
    *default_mode_local_var = default_mode->valuedouble;
    }

    // v1_secret_volume_source->default_user
    cJSON *default_user = cJSON_GetObjectItemCaseSensitive(v1_secret_volume_sourceJSON, "defaultUser");
    if (cJSON_IsNull(default_user)) {
        default_user = NULL;
    }
    if (default_user) { 
    if(!cJSON_IsNumber(default_user))
    {
    goto end; //Numeric
    }
    default_user_local_var = malloc(sizeof(long));
    if(!default_user_local_var)
    {
        goto end;
    }
    *default_user_local_var = default_user->valuedouble;
    }

    // v1_secret_volume_source->items
    cJSON *items = cJSON_GetObjectItemCaseSensitive(v1_secret_volume_sourceJSON, "items");
    if (cJSON_IsNull(items)) {
        items = NULL;
    }
    if (items) { 
    cJSON *items_local_nonprimitive = NULL;
    if(!cJSON_IsArray(items)){
        goto end; //nonprimitive container
    }

    itemsList = list_createList();

    cJSON_ArrayForEach(items_local_nonprimitive,items )
    {
        if(!cJSON_IsObject(items_local_nonprimitive)){
            goto end;
        }
        v1_key_to_path_t *itemsItem = v1_key_to_path_parseFromJSON(items_local_nonprimitive);

        list_addElement(itemsList, itemsItem);
    }
    }

    // v1_secret_volume_source->optional
    cJSON *optional = cJSON_GetObjectItemCaseSensitive(v1_secret_volume_sourceJSON, "optional");
    if (cJSON_IsNull(optional)) {
        optional = NULL;
    }
    if (optional) { 
    if(!cJSON_IsBool(optional))
    {
    goto end; //Bool
    }
    optional_local_var = malloc(sizeof(int));
    if(!optional_local_var)
    {
        goto end;
    }
    *optional_local_var = optional->valueint;
    }

    // v1_secret_volume_source->secret_name
    cJSON *secret_name = cJSON_GetObjectItemCaseSensitive(v1_secret_volume_sourceJSON, "secretName");
    if (cJSON_IsNull(secret_name)) {
        secret_name = NULL;
    }
    if (secret_name) { 
    if(!cJSON_IsString(secret_name) && !cJSON_IsNull(secret_name))
    {
    goto end; //String
    }
    }


    if (secret_name && !cJSON_IsNull(secret_name)) secret_name_local_str = strdup(secret_name->valuestring);

    v1_secret_volume_source_local_var = v1_secret_volume_source_create_internal (
        default_mode_local_var,
        default_user_local_var,
        items ? itemsList : NULL,
        optional_local_var,
        secret_name_local_str
        );

    if (!v1_secret_volume_source_local_var) {
        goto end;
    }

    return v1_secret_volume_source_local_var;
end:
    if (default_mode_local_var) {
        free(default_mode_local_var);
        default_mode_local_var = NULL;
    }
    if (default_user_local_var) {
        free(default_user_local_var);
        default_user_local_var = NULL;
    }
    if (itemsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, itemsList) {
            v1_key_to_path_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(itemsList);
        itemsList = NULL;
    }
    if (optional_local_var) {
        free(optional_local_var);
        optional_local_var = NULL;
    }
    if (secret_name_local_str) {
        free(secret_name_local_str);
        secret_name_local_str = NULL;
    }
    return NULL;

}
