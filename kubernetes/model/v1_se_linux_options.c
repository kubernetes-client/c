#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_se_linux_options.h"



v1_se_linux_options_t *v1_se_linux_options_create(
    char *level,
    char *role,
    char *type,
    char *user
    ) {
    v1_se_linux_options_t *v1_se_linux_options_local_var = malloc(sizeof(v1_se_linux_options_t));
    if (!v1_se_linux_options_local_var) {
        return NULL;
    }
    v1_se_linux_options_local_var->level = level;
    v1_se_linux_options_local_var->role = role;
    v1_se_linux_options_local_var->type = type;
    v1_se_linux_options_local_var->user = user;

    return v1_se_linux_options_local_var;
}


void v1_se_linux_options_free(v1_se_linux_options_t *v1_se_linux_options) {
    if(NULL == v1_se_linux_options){
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

    // v1_se_linux_options->level
    cJSON *level = cJSON_GetObjectItemCaseSensitive(v1_se_linux_optionsJSON, "level");
    if (level) { 
    if(!cJSON_IsString(level))
    {
    goto end; //String
    }
    }

    // v1_se_linux_options->role
    cJSON *role = cJSON_GetObjectItemCaseSensitive(v1_se_linux_optionsJSON, "role");
    if (role) { 
    if(!cJSON_IsString(role))
    {
    goto end; //String
    }
    }

    // v1_se_linux_options->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(v1_se_linux_optionsJSON, "type");
    if (type) { 
    if(!cJSON_IsString(type))
    {
    goto end; //String
    }
    }

    // v1_se_linux_options->user
    cJSON *user = cJSON_GetObjectItemCaseSensitive(v1_se_linux_optionsJSON, "user");
    if (user) { 
    if(!cJSON_IsString(user))
    {
    goto end; //String
    }
    }


    v1_se_linux_options_local_var = v1_se_linux_options_create (
        level ? strdup(level->valuestring) : NULL,
        role ? strdup(role->valuestring) : NULL,
        type ? strdup(type->valuestring) : NULL,
        user ? strdup(user->valuestring) : NULL
        );

    return v1_se_linux_options_local_var;
end:
    return NULL;

}
