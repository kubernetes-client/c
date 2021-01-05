#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_preconditions.h"



v1_preconditions_t *v1_preconditions_create(
    char *resource_version,
    char *uid
    ) {
    v1_preconditions_t *v1_preconditions_local_var = malloc(sizeof(v1_preconditions_t));
    if (!v1_preconditions_local_var) {
        return NULL;
    }
    v1_preconditions_local_var->resource_version = resource_version;
    v1_preconditions_local_var->uid = uid;

    return v1_preconditions_local_var;
}


void v1_preconditions_free(v1_preconditions_t *v1_preconditions) {
    if(NULL == v1_preconditions){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_preconditions->resource_version) {
        free(v1_preconditions->resource_version);
        v1_preconditions->resource_version = NULL;
    }
    if (v1_preconditions->uid) {
        free(v1_preconditions->uid);
        v1_preconditions->uid = NULL;
    }
    free(v1_preconditions);
}

cJSON *v1_preconditions_convertToJSON(v1_preconditions_t *v1_preconditions) {
    cJSON *item = cJSON_CreateObject();

    // v1_preconditions->resource_version
    if(v1_preconditions->resource_version) { 
    if(cJSON_AddStringToObject(item, "resourceVersion", v1_preconditions->resource_version) == NULL) {
    goto fail; //String
    }
     } 


    // v1_preconditions->uid
    if(v1_preconditions->uid) { 
    if(cJSON_AddStringToObject(item, "uid", v1_preconditions->uid) == NULL) {
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

v1_preconditions_t *v1_preconditions_parseFromJSON(cJSON *v1_preconditionsJSON){

    v1_preconditions_t *v1_preconditions_local_var = NULL;

    // v1_preconditions->resource_version
    cJSON *resource_version = cJSON_GetObjectItemCaseSensitive(v1_preconditionsJSON, "resourceVersion");
    if (resource_version) { 
    if(!cJSON_IsString(resource_version))
    {
    goto end; //String
    }
    }

    // v1_preconditions->uid
    cJSON *uid = cJSON_GetObjectItemCaseSensitive(v1_preconditionsJSON, "uid");
    if (uid) { 
    if(!cJSON_IsString(uid))
    {
    goto end; //String
    }
    }


    v1_preconditions_local_var = v1_preconditions_create (
        resource_version ? strdup(resource_version->valuestring) : NULL,
        uid ? strdup(uid->valuestring) : NULL
        );

    return v1_preconditions_local_var;
end:
    return NULL;

}
