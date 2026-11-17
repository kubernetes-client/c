#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_se_linux_options.h"



static v1_se_linux_options_t *v1_se_linux_options_create_internal(
    char *level,
    char *role,
    char *type,
    char *user
    ) {
    v1_se_linux_options_t *v1_se_linux_options_local_var = malloc(sizeof(v1_se_linux_options_t));
    if (!v1_se_linux_options_local_var) {
        return NULL;
    }
    memset(v1_se_linux_options_local_var, 0, sizeof(v1_se_linux_options_t));
    v1_se_linux_options_local_var->_library_owned = 1;
    v1_se_linux_options_local_var->level = level;
    v1_se_linux_options_local_var->role = role;
    v1_se_linux_options_local_var->type = type;
    v1_se_linux_options_local_var->user = user;
    return v1_se_linux_options_local_var;
}

__attribute__((deprecated)) v1_se_linux_options_t *v1_se_linux_options_create(
    char *level,
    char *role,
    char *type,
    char *user
    ) {
    v1_se_linux_options_t *result = v1_se_linux_options_create_internal (
        level,
        role,
        type,
        user
        );
    if (!result) {
    }
    return result;
}

void v1_se_linux_options_free(v1_se_linux_options_t *v1_se_linux_options) {
    if(NULL == v1_se_linux_options){
        return ;
    }
    if(v1_se_linux_options->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_se_linux_options_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_se_linux_options->level) {
        free(v1_se_linux_options->level);
        v1_se_linux_options->level = NULL;
    }
    if (v1_se_linux_options->role) {
        free(v1_se_linux_options->role);
        v1_se_linux_options->role = NULL;
    }
    if (v1_se_linux_options->type) {
        free(v1_se_linux_options->type);
        v1_se_linux_options->type = NULL;
    }
    if (v1_se_linux_options->user) {
        free(v1_se_linux_options->user);
        v1_se_linux_options->user = NULL;
    }
    free(v1_se_linux_options);
}

cJSON *v1_se_linux_options_convertToJSON(v1_se_linux_options_t *v1_se_linux_options) {
    cJSON *item = cJSON_CreateObject();

    // v1_se_linux_options->level
    if(v1_se_linux_options->level) {
    if(cJSON_AddStringToObject(item, "level", v1_se_linux_options->level) == NULL) {
    goto fail; //String
    }
    }


    // v1_se_linux_options->role
    if(v1_se_linux_options->role) {
    if(cJSON_AddStringToObject(item, "role", v1_se_linux_options->role) == NULL) {
    goto fail; //String
    }
    }


    // v1_se_linux_options->type
    if(v1_se_linux_options->type) {
    if(cJSON_AddStringToObject(item, "type", v1_se_linux_options->type) == NULL) {
    goto fail; //String
    }
    }


    // v1_se_linux_options->user
    if(v1_se_linux_options->user) {
    if(cJSON_AddStringToObject(item, "user", v1_se_linux_options->user) == NULL) {
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

v1_se_linux_options_t *v1_se_linux_options_parseFromJSON(cJSON *v1_se_linux_optionsJSON){

    v1_se_linux_options_t *v1_se_linux_options_local_var = NULL;

    char *level_local_str = NULL;

    char *role_local_str = NULL;

    char *type_local_str = NULL;

    char *user_local_str = NULL;

    // v1_se_linux_options->level
    cJSON *level = cJSON_GetObjectItemCaseSensitive(v1_se_linux_optionsJSON, "level");
    if (cJSON_IsNull(level)) {
        level = NULL;
    }
    if (level) { 
    if(!cJSON_IsString(level) && !cJSON_IsNull(level))
    {
    goto end; //String
    }
    }

    // v1_se_linux_options->role
    cJSON *role = cJSON_GetObjectItemCaseSensitive(v1_se_linux_optionsJSON, "role");
    if (cJSON_IsNull(role)) {
        role = NULL;
    }
    if (role) { 
    if(!cJSON_IsString(role) && !cJSON_IsNull(role))
    {
    goto end; //String
    }
    }

    // v1_se_linux_options->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(v1_se_linux_optionsJSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    if (type) { 
    if(!cJSON_IsString(type) && !cJSON_IsNull(type))
    {
    goto end; //String
    }
    }

    // v1_se_linux_options->user
    cJSON *user = cJSON_GetObjectItemCaseSensitive(v1_se_linux_optionsJSON, "user");
    if (cJSON_IsNull(user)) {
        user = NULL;
    }
    if (user) { 
    if(!cJSON_IsString(user) && !cJSON_IsNull(user))
    {
    goto end; //String
    }
    }


    if (level && !cJSON_IsNull(level)) level_local_str = strdup(level->valuestring);
    if (role && !cJSON_IsNull(role)) role_local_str = strdup(role->valuestring);
    if (type && !cJSON_IsNull(type)) type_local_str = strdup(type->valuestring);
    if (user && !cJSON_IsNull(user)) user_local_str = strdup(user->valuestring);

    v1_se_linux_options_local_var = v1_se_linux_options_create_internal (
        level_local_str,
        role_local_str,
        type_local_str,
        user_local_str
        );

    if (!v1_se_linux_options_local_var) {
        goto end;
    }

    return v1_se_linux_options_local_var;
end:
    if (level_local_str) {
        free(level_local_str);
        level_local_str = NULL;
    }
    if (role_local_str) {
        free(role_local_str);
        role_local_str = NULL;
    }
    if (type_local_str) {
        free(type_local_str);
        type_local_str = NULL;
    }
    if (user_local_str) {
        free(user_local_str);
        user_local_str = NULL;
    }
    return NULL;

}
