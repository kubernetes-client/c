#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_preconditions.h"



static v1_preconditions_t *v1_preconditions_create_internal(
    char *resource_version,
    char *uid
    ) {
    v1_preconditions_t *v1_preconditions_local_var = malloc(sizeof(v1_preconditions_t));
    if (!v1_preconditions_local_var) {
        return NULL;
    }
    v1_preconditions_local_var->resource_version = resource_version;
    v1_preconditions_local_var->uid = uid;

    v1_preconditions_local_var->_library_owned = 1;
    return v1_preconditions_local_var;
}

__attribute__((deprecated)) v1_preconditions_t *v1_preconditions_create(
    char *resource_version,
    char *uid
    ) {
    return v1_preconditions_create_internal (
        resource_version,
        uid
        );
}

void v1_preconditions_free(v1_preconditions_t *v1_preconditions) {
    if(NULL == v1_preconditions){
        return ;
    }
    if(v1_preconditions->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_preconditions_free");
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
    if (cJSON_IsNull(resource_version)) {
        resource_version = NULL;
    }
    if (resource_version) { 
    if(!cJSON_IsString(resource_version) && !cJSON_IsNull(resource_version))
    {
    goto end; //String
    }
    }

    // v1_preconditions->uid
    cJSON *uid = cJSON_GetObjectItemCaseSensitive(v1_preconditionsJSON, "uid");
    if (cJSON_IsNull(uid)) {
        uid = NULL;
    }
    if (uid) { 
    if(!cJSON_IsString(uid) && !cJSON_IsNull(uid))
    {
    goto end; //String
    }
    }


    v1_preconditions_local_var = v1_preconditions_create_internal (
        resource_version && !cJSON_IsNull(resource_version) ? strdup(resource_version->valuestring) : NULL,
        uid && !cJSON_IsNull(uid) ? strdup(uid->valuestring) : NULL
        );

    return v1_preconditions_local_var;
end:
    return NULL;

}
