#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_seccomp_profile.h"


char* typev1_seccomp_profile_ToString(kubernetes_v1_seccomp_profile_TYPE_e type) {
    char* typeArray[] =  { "NULL", "Localhost", "RuntimeDefault", "Unconfined" };
	return typeArray[type];
}

kubernetes_v1_seccomp_profile_TYPE_e typev1_seccomp_profile_FromString(char* type){
    int stringToReturn = 0;
    char *typeArray[] =  { "NULL", "Localhost", "RuntimeDefault", "Unconfined" };
    size_t sizeofArray = sizeof(typeArray) / sizeof(typeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(type, typeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

v1_seccomp_profile_t *v1_seccomp_profile_create(
    char *localhost_profile,
    kubernetes_v1_seccomp_profile_TYPE_e type
    ) {
    v1_seccomp_profile_t *v1_seccomp_profile_local_var = malloc(sizeof(v1_seccomp_profile_t));
    if (!v1_seccomp_profile_local_var) {
        return NULL;
    }
    v1_seccomp_profile_local_var->localhost_profile = localhost_profile;
    v1_seccomp_profile_local_var->type = type;

    return v1_seccomp_profile_local_var;
}


void v1_seccomp_profile_free(v1_seccomp_profile_t *v1_seccomp_profile) {
    if(NULL == v1_seccomp_profile){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_seccomp_profile->localhost_profile) {
        free(v1_seccomp_profile->localhost_profile);
        v1_seccomp_profile->localhost_profile = NULL;
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
    
    if(cJSON_AddStringToObject(item, "type", typev1_seccomp_profile_ToString(v1_seccomp_profile->type)) == NULL)
    {
    goto fail; //Enum
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
    if (localhost_profile) { 
    if(!cJSON_IsString(localhost_profile))
    {
    goto end; //String
    }
    }

    // v1_seccomp_profile->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(v1_seccomp_profileJSON, "type");
    if (!type) {
        goto end;
    }

    kubernetes_v1_seccomp_profile_TYPE_e typeVariable;
    
    if(!cJSON_IsString(type))
    {
    goto end; //Enum
    }
    typeVariable = typev1_seccomp_profile_FromString(type->valuestring);


    v1_seccomp_profile_local_var = v1_seccomp_profile_create (
        localhost_profile ? strdup(localhost_profile->valuestring) : NULL,
        typeVariable
        );

    return v1_seccomp_profile_local_var;
end:
    return NULL;

}
