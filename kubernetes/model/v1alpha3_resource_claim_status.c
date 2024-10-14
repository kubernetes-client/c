#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha3_resource_claim_status.h"



v1alpha3_resource_claim_status_t *v1alpha3_resource_claim_status_create(
    v1alpha3_allocation_result_t *allocation,
    int deallocation_requested,
    list_t *reserved_for
    ) {
    v1alpha3_resource_claim_status_t *v1alpha3_resource_claim_status_local_var = malloc(sizeof(v1alpha3_resource_claim_status_t));
    if (!v1alpha3_resource_claim_status_local_var) {
        return NULL;
    }
    v1alpha3_resource_claim_status_local_var->allocation = allocation;
    v1alpha3_resource_claim_status_local_var->deallocation_requested = deallocation_requested;
    v1alpha3_resource_claim_status_local_var->reserved_for = reserved_for;

    return v1alpha3_resource_claim_status_local_var;
}


void v1alpha3_resource_claim_status_free(v1alpha3_resource_claim_status_t *v1alpha3_resource_claim_status) {
    if(NULL == v1alpha3_resource_claim_status){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha3_resource_claim_status->allocation) {
        v1alpha3_allocation_result_free(v1alpha3_resource_claim_status->allocation);
        v1alpha3_resource_claim_status->allocation = NULL;
    }
    if (v1alpha3_resource_claim_status->reserved_for) {
        list_ForEach(listEntry, v1alpha3_resource_claim_status->reserved_for) {
            v1alpha3_resource_claim_consumer_reference_free(listEntry->data);
        }
        list_freeList(v1alpha3_resource_claim_status->reserved_for);
        v1alpha3_resource_claim_status->reserved_for = NULL;
    }
    free(v1alpha3_resource_claim_status);
}

cJSON *v1alpha3_resource_claim_status_convertToJSON(v1alpha3_resource_claim_status_t *v1alpha3_resource_claim_status) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha3_resource_claim_status->allocation
    if(v1alpha3_resource_claim_status->allocation) {
    cJSON *allocation_local_JSON = v1alpha3_allocation_result_convertToJSON(v1alpha3_resource_claim_status->allocation);
    if(allocation_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "allocation", allocation_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1alpha3_resource_claim_status->deallocation_requested
    if(v1alpha3_resource_claim_status->deallocation_requested) {
    if(cJSON_AddBoolToObject(item, "deallocationRequested", v1alpha3_resource_claim_status->deallocation_requested) == NULL) {
    goto fail; //Bool
    }
    }


    // v1alpha3_resource_claim_status->reserved_for
    if(v1alpha3_resource_claim_status->reserved_for) {
    cJSON *reserved_for = cJSON_AddArrayToObject(item, "reservedFor");
    if(reserved_for == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *reserved_forListEntry;
    if (v1alpha3_resource_claim_status->reserved_for) {
    list_ForEach(reserved_forListEntry, v1alpha3_resource_claim_status->reserved_for) {
    cJSON *itemLocal = v1alpha3_resource_claim_consumer_reference_convertToJSON(reserved_forListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(reserved_for, itemLocal);
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

v1alpha3_resource_claim_status_t *v1alpha3_resource_claim_status_parseFromJSON(cJSON *v1alpha3_resource_claim_statusJSON){

    v1alpha3_resource_claim_status_t *v1alpha3_resource_claim_status_local_var = NULL;

    // define the local variable for v1alpha3_resource_claim_status->allocation
    v1alpha3_allocation_result_t *allocation_local_nonprim = NULL;

    // define the local list for v1alpha3_resource_claim_status->reserved_for
    list_t *reserved_forList = NULL;

    // v1alpha3_resource_claim_status->allocation
    cJSON *allocation = cJSON_GetObjectItemCaseSensitive(v1alpha3_resource_claim_statusJSON, "allocation");
    if (allocation) { 
    allocation_local_nonprim = v1alpha3_allocation_result_parseFromJSON(allocation); //nonprimitive
    }

    // v1alpha3_resource_claim_status->deallocation_requested
    cJSON *deallocation_requested = cJSON_GetObjectItemCaseSensitive(v1alpha3_resource_claim_statusJSON, "deallocationRequested");
    if (deallocation_requested) { 
    if(!cJSON_IsBool(deallocation_requested))
    {
    goto end; //Bool
    }
    }

    // v1alpha3_resource_claim_status->reserved_for
    cJSON *reserved_for = cJSON_GetObjectItemCaseSensitive(v1alpha3_resource_claim_statusJSON, "reservedFor");
    if (reserved_for) { 
    cJSON *reserved_for_local_nonprimitive = NULL;
    if(!cJSON_IsArray(reserved_for)){
        goto end; //nonprimitive container
    }

    reserved_forList = list_createList();

    cJSON_ArrayForEach(reserved_for_local_nonprimitive,reserved_for )
    {
        if(!cJSON_IsObject(reserved_for_local_nonprimitive)){
            goto end;
        }
        v1alpha3_resource_claim_consumer_reference_t *reserved_forItem = v1alpha3_resource_claim_consumer_reference_parseFromJSON(reserved_for_local_nonprimitive);

        list_addElement(reserved_forList, reserved_forItem);
    }
    }


    v1alpha3_resource_claim_status_local_var = v1alpha3_resource_claim_status_create (
        allocation ? allocation_local_nonprim : NULL,
        deallocation_requested ? deallocation_requested->valueint : 0,
        reserved_for ? reserved_forList : NULL
        );

    return v1alpha3_resource_claim_status_local_var;
end:
    if (allocation_local_nonprim) {
        v1alpha3_allocation_result_free(allocation_local_nonprim);
        allocation_local_nonprim = NULL;
    }
    if (reserved_forList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, reserved_forList) {
            v1alpha3_resource_claim_consumer_reference_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(reserved_forList);
        reserved_forList = NULL;
    }
    return NULL;

}
