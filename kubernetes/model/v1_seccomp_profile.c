#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_seccomp_profile.h"



static v1_seccomp_profile_t *v1_seccomp_profile_create_internal(
    char *localhost_profile,
    char *type
    ) {
    v1_seccomp_profile_t *v1_seccomp_profile_local_var = malloc(sizeof(v1_seccomp_profile_t));
    if (!v1_seccomp_profile_local_var) {
        return NULL;
    }
    v1_seccomp_profile_local_var->localhost_profile = localhost_profile;
    v1_seccomp_profile_local_var->type = type;

    v1_seccomp_profile_local_var->_library_owned = 1;
    return v1_seccomp_profile_local_var;
}

__attribute__((deprecated)) v1_seccomp_profile_t *v1_seccomp_profile_create(
    char *localhost_profile,
    char *type
    ) {
    return v1_seccomp_profile_create_internal (
        localhost_profile,
        type
        );
}

void v1_seccomp_profile_free(v1_seccomp_profile_t *v1_seccomp_profile) {
    if(NULL == v1_seccomp_profile){
        return ;
    }
    if(v1_seccomp_profile->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_seccomp_profile_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_seccomp_profile->localhost_profile) {
        free(v1_seccomp_profile->localhost_profile);
        v1_seccomp_profile->localhost_profile = NULL;
    }
    if (v1_seccomp_profile->type) {
        free(v1_seccomp_profile->type);
        v1_seccomp_profile->type = NULL;
    }
    free(v1_seccomp_profile);
}

cJSON *v1_seccomp_profile_convertToJSON(v1_seccomp_profile_t *v1_seccomp_profile) {
    cJSON *item = cJSON_CreateObject();

    // v1_seccomp_profile->localhost_profile
    if(v1_seccomp_profile->localhost_profile) {
    if(cJSON_AddStringToObject(item, "localhostProfile", v1_seccomp_profile->localhost_profile) == NULL) {
    goto fail; //String
    }
    }


    // v1_seccomp_profile->type
    if (!v1_seccomp_profile->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", v1_seccomp_profile->type) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_seccomp_profile_t *v1_seccomp_profile_parseFromJSON(cJSON *v1_seccomp_profileJSON){

    v1_seccomp_profile_t *v1_seccomp_profile_local_var = NULL;

    // v1_seccomp_profile->localhost_profile
    cJSON *localhost_profile = cJSON_GetObjectItemCaseSensitive(v1_seccomp_profileJSON, "localhostProfile");
    if (cJSON_IsNull(localhost_profile)) {
        localhost_profile = NULL;
    }
    if (localhost_profile) { 
    if(!cJSON_IsString(localhost_profile) && !cJSON_IsNull(localhost_profile))
    {
    goto end; //String
    }
    }

    // v1_seccomp_profile->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(v1_seccomp_profileJSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    if (!type) {
        goto end;
    }

    
    if(!cJSON_IsString(type))
    {
    goto end; //String
    }


    v1_seccomp_profile_local_var = v1_seccomp_profile_create_internal (
        localhost_profile && !cJSON_IsNull(localhost_profile) ? strdup(localhost_profile->valuestring) : NULL,
        strdup(type->valuestring)
        );

    return v1_seccomp_profile_local_var;
end:
    return NULL;

}
