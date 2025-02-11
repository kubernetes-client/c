#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_container_resize_policy.h"



static v1_container_resize_policy_t *v1_container_resize_policy_create_internal(
    char *resource_name,
    char *restart_policy
    ) {
    v1_container_resize_policy_t *v1_container_resize_policy_local_var = malloc(sizeof(v1_container_resize_policy_t));
    if (!v1_container_resize_policy_local_var) {
        return NULL;
    }
    v1_container_resize_policy_local_var->resource_name = resource_name;
    v1_container_resize_policy_local_var->restart_policy = restart_policy;

    v1_container_resize_policy_local_var->_library_owned = 1;
    return v1_container_resize_policy_local_var;
}

__attribute__((deprecated)) v1_container_resize_policy_t *v1_container_resize_policy_create(
    char *resource_name,
    char *restart_policy
    ) {
    return v1_container_resize_policy_create_internal (
        resource_name,
        restart_policy
        );
}

void v1_container_resize_policy_free(v1_container_resize_policy_t *v1_container_resize_policy) {
    if(NULL == v1_container_resize_policy){
        return ;
    }
    if(v1_container_resize_policy->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_container_resize_policy_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_container_resize_policy->resource_name) {
        free(v1_container_resize_policy->resource_name);
        v1_container_resize_policy->resource_name = NULL;
    }
    if (v1_container_resize_policy->restart_policy) {
        free(v1_container_resize_policy->restart_policy);
        v1_container_resize_policy->restart_policy = NULL;
    }
    free(v1_container_resize_policy);
}

cJSON *v1_container_resize_policy_convertToJSON(v1_container_resize_policy_t *v1_container_resize_policy) {
    cJSON *item = cJSON_CreateObject();

    // v1_container_resize_policy->resource_name
    if (!v1_container_resize_policy->resource_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "resourceName", v1_container_resize_policy->resource_name) == NULL) {
    goto fail; //String
    }


    // v1_container_resize_policy->restart_policy
    if (!v1_container_resize_policy->restart_policy) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "restartPolicy", v1_container_resize_policy->restart_policy) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_container_resize_policy_t *v1_container_resize_policy_parseFromJSON(cJSON *v1_container_resize_policyJSON){

    v1_container_resize_policy_t *v1_container_resize_policy_local_var = NULL;

    // v1_container_resize_policy->resource_name
    cJSON *resource_name = cJSON_GetObjectItemCaseSensitive(v1_container_resize_policyJSON, "resourceName");
    if (cJSON_IsNull(resource_name)) {
        resource_name = NULL;
    }
    if (!resource_name) {
        goto end;
    }

    
    if(!cJSON_IsString(resource_name))
    {
    goto end; //String
    }

    // v1_container_resize_policy->restart_policy
    cJSON *restart_policy = cJSON_GetObjectItemCaseSensitive(v1_container_resize_policyJSON, "restartPolicy");
    if (cJSON_IsNull(restart_policy)) {
        restart_policy = NULL;
    }
    if (!restart_policy) {
        goto end;
    }

    
    if(!cJSON_IsString(restart_policy))
    {
    goto end; //String
    }


    v1_container_resize_policy_local_var = v1_container_resize_policy_create_internal (
        strdup(resource_name->valuestring),
        strdup(restart_policy->valuestring)
        );

    return v1_container_resize_policy_local_var;
end:
    return NULL;

}
