#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_pod_resource_claim_status.h"



v1_pod_resource_claim_status_t *v1_pod_resource_claim_status_create(
    char *name,
    char *resource_claim_name
    ) {
    v1_pod_resource_claim_status_t *v1_pod_resource_claim_status_local_var = malloc(sizeof(v1_pod_resource_claim_status_t));
    if (!v1_pod_resource_claim_status_local_var) {
        return NULL;
    }
    v1_pod_resource_claim_status_local_var->name = name;
    v1_pod_resource_claim_status_local_var->resource_claim_name = resource_claim_name;

    return v1_pod_resource_claim_status_local_var;
}


void v1_pod_resource_claim_status_free(v1_pod_resource_claim_status_t *v1_pod_resource_claim_status) {
    if(NULL == v1_pod_resource_claim_status){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_pod_resource_claim_status->name) {
        free(v1_pod_resource_claim_status->name);
        v1_pod_resource_claim_status->name = NULL;
    }
    if (v1_pod_resource_claim_status->resource_claim_name) {
        free(v1_pod_resource_claim_status->resource_claim_name);
        v1_pod_resource_claim_status->resource_claim_name = NULL;
    }
    free(v1_pod_resource_claim_status);
}

cJSON *v1_pod_resource_claim_status_convertToJSON(v1_pod_resource_claim_status_t *v1_pod_resource_claim_status) {
    cJSON *item = cJSON_CreateObject();

    // v1_pod_resource_claim_status->name
    if (!v1_pod_resource_claim_status->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", v1_pod_resource_claim_status->name) == NULL) {
    goto fail; //String
    }


    // v1_pod_resource_claim_status->resource_claim_name
    if(v1_pod_resource_claim_status->resource_claim_name) {
    if(cJSON_AddStringToObject(item, "resourceClaimName", v1_pod_resource_claim_status->resource_claim_name) == NULL) {
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

v1_pod_resource_claim_status_t *v1_pod_resource_claim_status_parseFromJSON(cJSON *v1_pod_resource_claim_statusJSON){

    v1_pod_resource_claim_status_t *v1_pod_resource_claim_status_local_var = NULL;

    // v1_pod_resource_claim_status->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1_pod_resource_claim_statusJSON, "name");
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // v1_pod_resource_claim_status->resource_claim_name
    cJSON *resource_claim_name = cJSON_GetObjectItemCaseSensitive(v1_pod_resource_claim_statusJSON, "resourceClaimName");
    if (resource_claim_name) { 
    if(!cJSON_IsString(resource_claim_name) && !cJSON_IsNull(resource_claim_name))
    {
    goto end; //String
    }
    }


    v1_pod_resource_claim_status_local_var = v1_pod_resource_claim_status_create (
        strdup(name->valuestring),
        resource_claim_name && !cJSON_IsNull(resource_claim_name) ? strdup(resource_claim_name->valuestring) : NULL
        );

    return v1_pod_resource_claim_status_local_var;
end:
    return NULL;

}
