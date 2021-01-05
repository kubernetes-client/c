#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "policy_v1beta1_allowed_host_path.h"



policy_v1beta1_allowed_host_path_t *policy_v1beta1_allowed_host_path_create(
    char *path_prefix,
    int read_only
    ) {
    policy_v1beta1_allowed_host_path_t *policy_v1beta1_allowed_host_path_local_var = malloc(sizeof(policy_v1beta1_allowed_host_path_t));
    if (!policy_v1beta1_allowed_host_path_local_var) {
        return NULL;
    }
    policy_v1beta1_allowed_host_path_local_var->path_prefix = path_prefix;
    policy_v1beta1_allowed_host_path_local_var->read_only = read_only;

    return policy_v1beta1_allowed_host_path_local_var;
}


void policy_v1beta1_allowed_host_path_free(policy_v1beta1_allowed_host_path_t *policy_v1beta1_allowed_host_path) {
    if(NULL == policy_v1beta1_allowed_host_path){
        return ;
    }
    listEntry_t *listEntry;
    if (policy_v1beta1_allowed_host_path->path_prefix) {
        free(policy_v1beta1_allowed_host_path->path_prefix);
        policy_v1beta1_allowed_host_path->path_prefix = NULL;
    }
    free(policy_v1beta1_allowed_host_path);
}

cJSON *policy_v1beta1_allowed_host_path_convertToJSON(policy_v1beta1_allowed_host_path_t *policy_v1beta1_allowed_host_path) {
    cJSON *item = cJSON_CreateObject();

    // policy_v1beta1_allowed_host_path->path_prefix
    if(policy_v1beta1_allowed_host_path->path_prefix) { 
    if(cJSON_AddStringToObject(item, "pathPrefix", policy_v1beta1_allowed_host_path->path_prefix) == NULL) {
    goto fail; //String
    }
     } 


    // policy_v1beta1_allowed_host_path->read_only
    if(policy_v1beta1_allowed_host_path->read_only) { 
    if(cJSON_AddBoolToObject(item, "readOnly", policy_v1beta1_allowed_host_path->read_only) == NULL) {
    goto fail; //Bool
    }
     } 

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

policy_v1beta1_allowed_host_path_t *policy_v1beta1_allowed_host_path_parseFromJSON(cJSON *policy_v1beta1_allowed_host_pathJSON){

    policy_v1beta1_allowed_host_path_t *policy_v1beta1_allowed_host_path_local_var = NULL;

    // policy_v1beta1_allowed_host_path->path_prefix
    cJSON *path_prefix = cJSON_GetObjectItemCaseSensitive(policy_v1beta1_allowed_host_pathJSON, "pathPrefix");
    if (path_prefix) { 
    if(!cJSON_IsString(path_prefix))
    {
    goto end; //String
    }
    }

    // policy_v1beta1_allowed_host_path->read_only
    cJSON *read_only = cJSON_GetObjectItemCaseSensitive(policy_v1beta1_allowed_host_pathJSON, "readOnly");
    if (read_only) { 
    if(!cJSON_IsBool(read_only))
    {
    goto end; //Bool
    }
    }


    policy_v1beta1_allowed_host_path_local_var = policy_v1beta1_allowed_host_path_create (
        path_prefix ? strdup(path_prefix->valuestring) : NULL,
        read_only ? read_only->valueint : 0
        );

    return policy_v1beta1_allowed_host_path_local_var;
end:
    return NULL;

}
