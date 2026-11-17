#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha3_pod_group_resource_claim_status.h"



static v1alpha3_pod_group_resource_claim_status_t *v1alpha3_pod_group_resource_claim_status_create_internal(
    char *name,
    char *resource_claim_name
    ) {
    v1alpha3_pod_group_resource_claim_status_t *v1alpha3_pod_group_resource_claim_status_local_var = malloc(sizeof(v1alpha3_pod_group_resource_claim_status_t));
    if (!v1alpha3_pod_group_resource_claim_status_local_var) {
        return NULL;
    }
    memset(v1alpha3_pod_group_resource_claim_status_local_var, 0, sizeof(v1alpha3_pod_group_resource_claim_status_t));
    v1alpha3_pod_group_resource_claim_status_local_var->_library_owned = 1;
    v1alpha3_pod_group_resource_claim_status_local_var->name = name;
    v1alpha3_pod_group_resource_claim_status_local_var->resource_claim_name = resource_claim_name;
    return v1alpha3_pod_group_resource_claim_status_local_var;
}

__attribute__((deprecated)) v1alpha3_pod_group_resource_claim_status_t *v1alpha3_pod_group_resource_claim_status_create(
    char *name,
    char *resource_claim_name
    ) {
    v1alpha3_pod_group_resource_claim_status_t *result = v1alpha3_pod_group_resource_claim_status_create_internal (
        name,
        resource_claim_name
        );
    if (!result) {
    }
    return result;
}

void v1alpha3_pod_group_resource_claim_status_free(v1alpha3_pod_group_resource_claim_status_t *v1alpha3_pod_group_resource_claim_status) {
    if(NULL == v1alpha3_pod_group_resource_claim_status){
        return ;
    }
    if(v1alpha3_pod_group_resource_claim_status->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1alpha3_pod_group_resource_claim_status_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha3_pod_group_resource_claim_status->name) {
        free(v1alpha3_pod_group_resource_claim_status->name);
        v1alpha3_pod_group_resource_claim_status->name = NULL;
    }
    if (v1alpha3_pod_group_resource_claim_status->resource_claim_name) {
        free(v1alpha3_pod_group_resource_claim_status->resource_claim_name);
        v1alpha3_pod_group_resource_claim_status->resource_claim_name = NULL;
    }
    free(v1alpha3_pod_group_resource_claim_status);
}

cJSON *v1alpha3_pod_group_resource_claim_status_convertToJSON(v1alpha3_pod_group_resource_claim_status_t *v1alpha3_pod_group_resource_claim_status) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha3_pod_group_resource_claim_status->name
    if (!v1alpha3_pod_group_resource_claim_status->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", v1alpha3_pod_group_resource_claim_status->name) == NULL) {
    goto fail; //String
    }


    // v1alpha3_pod_group_resource_claim_status->resource_claim_name
    if(v1alpha3_pod_group_resource_claim_status->resource_claim_name) {
    if(cJSON_AddStringToObject(item, "resourceClaimName", v1alpha3_pod_group_resource_claim_status->resource_claim_name) == NULL) {
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

v1alpha3_pod_group_resource_claim_status_t *v1alpha3_pod_group_resource_claim_status_parseFromJSON(cJSON *v1alpha3_pod_group_resource_claim_statusJSON){

    v1alpha3_pod_group_resource_claim_status_t *v1alpha3_pod_group_resource_claim_status_local_var = NULL;

    char *name_local_str = NULL;

    char *resource_claim_name_local_str = NULL;

    // v1alpha3_pod_group_resource_claim_status->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1alpha3_pod_group_resource_claim_statusJSON, "name");
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

    // v1alpha3_pod_group_resource_claim_status->resource_claim_name
    cJSON *resource_claim_name = cJSON_GetObjectItemCaseSensitive(v1alpha3_pod_group_resource_claim_statusJSON, "resourceClaimName");
    if (cJSON_IsNull(resource_claim_name)) {
        resource_claim_name = NULL;
    }
    if (resource_claim_name) { 
    if(!cJSON_IsString(resource_claim_name) && !cJSON_IsNull(resource_claim_name))
    {
    goto end; //String
    }
    }


    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);
    if (resource_claim_name && !cJSON_IsNull(resource_claim_name)) resource_claim_name_local_str = strdup(resource_claim_name->valuestring);

    v1alpha3_pod_group_resource_claim_status_local_var = v1alpha3_pod_group_resource_claim_status_create_internal (
        name_local_str,
        resource_claim_name_local_str
        );

    if (!v1alpha3_pod_group_resource_claim_status_local_var) {
        goto end;
    }

    return v1alpha3_pod_group_resource_claim_status_local_var;
end:
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    if (resource_claim_name_local_str) {
        free(resource_claim_name_local_str);
        resource_claim_name_local_str = NULL;
    }
    return NULL;

}
