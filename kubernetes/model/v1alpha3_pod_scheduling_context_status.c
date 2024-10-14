#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha3_pod_scheduling_context_status.h"



v1alpha3_pod_scheduling_context_status_t *v1alpha3_pod_scheduling_context_status_create(
    list_t *resource_claims
    ) {
    v1alpha3_pod_scheduling_context_status_t *v1alpha3_pod_scheduling_context_status_local_var = malloc(sizeof(v1alpha3_pod_scheduling_context_status_t));
    if (!v1alpha3_pod_scheduling_context_status_local_var) {
        return NULL;
    }
    v1alpha3_pod_scheduling_context_status_local_var->resource_claims = resource_claims;

    return v1alpha3_pod_scheduling_context_status_local_var;
}


void v1alpha3_pod_scheduling_context_status_free(v1alpha3_pod_scheduling_context_status_t *v1alpha3_pod_scheduling_context_status) {
    if(NULL == v1alpha3_pod_scheduling_context_status){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha3_pod_scheduling_context_status->resource_claims) {
        list_ForEach(listEntry, v1alpha3_pod_scheduling_context_status->resource_claims) {
            v1alpha3_resource_claim_scheduling_status_free(listEntry->data);
        }
        list_freeList(v1alpha3_pod_scheduling_context_status->resource_claims);
        v1alpha3_pod_scheduling_context_status->resource_claims = NULL;
    }
    free(v1alpha3_pod_scheduling_context_status);
}

cJSON *v1alpha3_pod_scheduling_context_status_convertToJSON(v1alpha3_pod_scheduling_context_status_t *v1alpha3_pod_scheduling_context_status) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha3_pod_scheduling_context_status->resource_claims
    if(v1alpha3_pod_scheduling_context_status->resource_claims) {
    cJSON *resource_claims = cJSON_AddArrayToObject(item, "resourceClaims");
    if(resource_claims == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *resource_claimsListEntry;
    if (v1alpha3_pod_scheduling_context_status->resource_claims) {
    list_ForEach(resource_claimsListEntry, v1alpha3_pod_scheduling_context_status->resource_claims) {
    cJSON *itemLocal = v1alpha3_resource_claim_scheduling_status_convertToJSON(resource_claimsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(resource_claims, itemLocal);
    }
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1alpha3_pod_scheduling_context_status_t *v1alpha3_pod_scheduling_context_status_parseFromJSON(cJSON *v1alpha3_pod_scheduling_context_statusJSON){

    v1alpha3_pod_scheduling_context_status_t *v1alpha3_pod_scheduling_context_status_local_var = NULL;

    // define the local list for v1alpha3_pod_scheduling_context_status->resource_claims
    list_t *resource_claimsList = NULL;

    // v1alpha3_pod_scheduling_context_status->resource_claims
    cJSON *resource_claims = cJSON_GetObjectItemCaseSensitive(v1alpha3_pod_scheduling_context_statusJSON, "resourceClaims");
    if (resource_claims) { 
    cJSON *resource_claims_local_nonprimitive = NULL;
    if(!cJSON_IsArray(resource_claims)){
        goto end; //nonprimitive container
    }

    resource_claimsList = list_createList();

    cJSON_ArrayForEach(resource_claims_local_nonprimitive,resource_claims )
    {
        if(!cJSON_IsObject(resource_claims_local_nonprimitive)){
            goto end;
        }
        v1alpha3_resource_claim_scheduling_status_t *resource_claimsItem = v1alpha3_resource_claim_scheduling_status_parseFromJSON(resource_claims_local_nonprimitive);

        list_addElement(resource_claimsList, resource_claimsItem);
    }
    }


    v1alpha3_pod_scheduling_context_status_local_var = v1alpha3_pod_scheduling_context_status_create (
        resource_claims ? resource_claimsList : NULL
        );

    return v1alpha3_pod_scheduling_context_status_local_var;
end:
    if (resource_claimsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, resource_claimsList) {
            v1alpha3_resource_claim_scheduling_status_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(resource_claimsList);
        resource_claimsList = NULL;
    }
    return NULL;

}
