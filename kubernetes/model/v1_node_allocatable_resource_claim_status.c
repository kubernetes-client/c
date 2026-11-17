#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_node_allocatable_resource_claim_status.h"



static v1_node_allocatable_resource_claim_status_t *v1_node_allocatable_resource_claim_status_create_internal(
    list_t *containers,
    list_t *mapping,
    list_t *overhead,
    char *resource_claim_name
    ) {
    v1_node_allocatable_resource_claim_status_t *v1_node_allocatable_resource_claim_status_local_var = malloc(sizeof(v1_node_allocatable_resource_claim_status_t));
    if (!v1_node_allocatable_resource_claim_status_local_var) {
        return NULL;
    }
    memset(v1_node_allocatable_resource_claim_status_local_var, 0, sizeof(v1_node_allocatable_resource_claim_status_t));
    v1_node_allocatable_resource_claim_status_local_var->_library_owned = 1;
    v1_node_allocatable_resource_claim_status_local_var->containers = containers;
    v1_node_allocatable_resource_claim_status_local_var->mapping = mapping;
    v1_node_allocatable_resource_claim_status_local_var->overhead = overhead;
    v1_node_allocatable_resource_claim_status_local_var->resource_claim_name = resource_claim_name;
    return v1_node_allocatable_resource_claim_status_local_var;
}

__attribute__((deprecated)) v1_node_allocatable_resource_claim_status_t *v1_node_allocatable_resource_claim_status_create(
    list_t *containers,
    list_t *mapping,
    list_t *overhead,
    char *resource_claim_name
    ) {
    v1_node_allocatable_resource_claim_status_t *result = v1_node_allocatable_resource_claim_status_create_internal (
        containers,
        mapping,
        overhead,
        resource_claim_name
        );
    if (!result) {
    }
    return result;
}

void v1_node_allocatable_resource_claim_status_free(v1_node_allocatable_resource_claim_status_t *v1_node_allocatable_resource_claim_status) {
    if(NULL == v1_node_allocatable_resource_claim_status){
        return ;
    }
    if(v1_node_allocatable_resource_claim_status->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_node_allocatable_resource_claim_status_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_node_allocatable_resource_claim_status->containers) {
        list_ForEach(listEntry, v1_node_allocatable_resource_claim_status->containers) {
            free(listEntry->data);
        }
        list_freeList(v1_node_allocatable_resource_claim_status->containers);
        v1_node_allocatable_resource_claim_status->containers = NULL;
    }
    if (v1_node_allocatable_resource_claim_status->mapping) {
        list_ForEach(listEntry, v1_node_allocatable_resource_claim_status->mapping) {
            v1_node_allocatable_mapped_resources_free(listEntry->data);
        }
        list_freeList(v1_node_allocatable_resource_claim_status->mapping);
        v1_node_allocatable_resource_claim_status->mapping = NULL;
    }
    if (v1_node_allocatable_resource_claim_status->overhead) {
        list_ForEach(listEntry, v1_node_allocatable_resource_claim_status->overhead) {
            v1_node_allocatable_overhead_resources_free(listEntry->data);
        }
        list_freeList(v1_node_allocatable_resource_claim_status->overhead);
        v1_node_allocatable_resource_claim_status->overhead = NULL;
    }
    if (v1_node_allocatable_resource_claim_status->resource_claim_name) {
        free(v1_node_allocatable_resource_claim_status->resource_claim_name);
        v1_node_allocatable_resource_claim_status->resource_claim_name = NULL;
    }
    free(v1_node_allocatable_resource_claim_status);
}

cJSON *v1_node_allocatable_resource_claim_status_convertToJSON(v1_node_allocatable_resource_claim_status_t *v1_node_allocatable_resource_claim_status) {
    cJSON *item = cJSON_CreateObject();

    // v1_node_allocatable_resource_claim_status->containers
    if(v1_node_allocatable_resource_claim_status->containers) {
    cJSON *containers = cJSON_AddArrayToObject(item, "containers");
    if(containers == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *containersListEntry;
    list_ForEach(containersListEntry, v1_node_allocatable_resource_claim_status->containers) {
    if(cJSON_AddStringToObject(containers, "", containersListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // v1_node_allocatable_resource_claim_status->mapping
    if(v1_node_allocatable_resource_claim_status->mapping) {
    cJSON *mapping = cJSON_AddArrayToObject(item, "mapping");
    if(mapping == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *mappingListEntry;
    if (v1_node_allocatable_resource_claim_status->mapping) {
    list_ForEach(mappingListEntry, v1_node_allocatable_resource_claim_status->mapping) {
    cJSON *itemLocal = v1_node_allocatable_mapped_resources_convertToJSON(mappingListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(mapping, itemLocal);
    }
    }
    }


    // v1_node_allocatable_resource_claim_status->overhead
    if(v1_node_allocatable_resource_claim_status->overhead) {
    cJSON *overhead = cJSON_AddArrayToObject(item, "overhead");
    if(overhead == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *overheadListEntry;
    if (v1_node_allocatable_resource_claim_status->overhead) {
    list_ForEach(overheadListEntry, v1_node_allocatable_resource_claim_status->overhead) {
    cJSON *itemLocal = v1_node_allocatable_overhead_resources_convertToJSON(overheadListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(overhead, itemLocal);
    }
    }
    }


    // v1_node_allocatable_resource_claim_status->resource_claim_name
    if (!v1_node_allocatable_resource_claim_status->resource_claim_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "resourceClaimName", v1_node_allocatable_resource_claim_status->resource_claim_name) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_node_allocatable_resource_claim_status_t *v1_node_allocatable_resource_claim_status_parseFromJSON(cJSON *v1_node_allocatable_resource_claim_statusJSON){

    v1_node_allocatable_resource_claim_status_t *v1_node_allocatable_resource_claim_status_local_var = NULL;

    // define the local list for v1_node_allocatable_resource_claim_status->containers
    list_t *containersList = NULL;

    // define the local list for v1_node_allocatable_resource_claim_status->mapping
    list_t *mappingList = NULL;

    // define the local list for v1_node_allocatable_resource_claim_status->overhead
    list_t *overheadList = NULL;

    char *resource_claim_name_local_str = NULL;

    // v1_node_allocatable_resource_claim_status->containers
    cJSON *containers = cJSON_GetObjectItemCaseSensitive(v1_node_allocatable_resource_claim_statusJSON, "containers");
    if (cJSON_IsNull(containers)) {
        containers = NULL;
    }
    if (containers) { 
    cJSON *containers_local = NULL;
    if(!cJSON_IsArray(containers)) {
        goto end;//primitive container
    }
    containersList = list_createList();

    cJSON_ArrayForEach(containers_local, containers)
    {
        if(!cJSON_IsString(containers_local))
        {
            goto end;
        }
        list_addElement(containersList , strdup(containers_local->valuestring));
    }
    }

    // v1_node_allocatable_resource_claim_status->mapping
    cJSON *mapping = cJSON_GetObjectItemCaseSensitive(v1_node_allocatable_resource_claim_statusJSON, "mapping");
    if (cJSON_IsNull(mapping)) {
        mapping = NULL;
    }
    if (mapping) { 
    cJSON *mapping_local_nonprimitive = NULL;
    if(!cJSON_IsArray(mapping)){
        goto end; //nonprimitive container
    }

    mappingList = list_createList();

    cJSON_ArrayForEach(mapping_local_nonprimitive,mapping )
    {
        if(!cJSON_IsObject(mapping_local_nonprimitive)){
            goto end;
        }
        v1_node_allocatable_mapped_resources_t *mappingItem = v1_node_allocatable_mapped_resources_parseFromJSON(mapping_local_nonprimitive);

        list_addElement(mappingList, mappingItem);
    }
    }

    // v1_node_allocatable_resource_claim_status->overhead
    cJSON *overhead = cJSON_GetObjectItemCaseSensitive(v1_node_allocatable_resource_claim_statusJSON, "overhead");
    if (cJSON_IsNull(overhead)) {
        overhead = NULL;
    }
    if (overhead) { 
    cJSON *overhead_local_nonprimitive = NULL;
    if(!cJSON_IsArray(overhead)){
        goto end; //nonprimitive container
    }

    overheadList = list_createList();

    cJSON_ArrayForEach(overhead_local_nonprimitive,overhead )
    {
        if(!cJSON_IsObject(overhead_local_nonprimitive)){
            goto end;
        }
        v1_node_allocatable_overhead_resources_t *overheadItem = v1_node_allocatable_overhead_resources_parseFromJSON(overhead_local_nonprimitive);

        list_addElement(overheadList, overheadItem);
    }
    }

    // v1_node_allocatable_resource_claim_status->resource_claim_name
    cJSON *resource_claim_name = cJSON_GetObjectItemCaseSensitive(v1_node_allocatable_resource_claim_statusJSON, "resourceClaimName");
    if (cJSON_IsNull(resource_claim_name)) {
        resource_claim_name = NULL;
    }
    if (!resource_claim_name) {
        goto end;
    }

    
    if(!cJSON_IsString(resource_claim_name))
    {
    goto end; //String
    }


    if (resource_claim_name && !cJSON_IsNull(resource_claim_name)) resource_claim_name_local_str = strdup(resource_claim_name->valuestring);

    v1_node_allocatable_resource_claim_status_local_var = v1_node_allocatable_resource_claim_status_create_internal (
        containers ? containersList : NULL,
        mapping ? mappingList : NULL,
        overhead ? overheadList : NULL,
        resource_claim_name_local_str
        );

    if (!v1_node_allocatable_resource_claim_status_local_var) {
        goto end;
    }

    return v1_node_allocatable_resource_claim_status_local_var;
end:
    if (containersList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, containersList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(containersList);
        containersList = NULL;
    }
    if (mappingList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, mappingList) {
            v1_node_allocatable_mapped_resources_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(mappingList);
        mappingList = NULL;
    }
    if (overheadList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, overheadList) {
            v1_node_allocatable_overhead_resources_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(overheadList);
        overheadList = NULL;
    }
    if (resource_claim_name_local_str) {
        free(resource_claim_name_local_str);
        resource_claim_name_local_str = NULL;
    }
    return NULL;

}
