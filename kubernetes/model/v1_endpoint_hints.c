#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_endpoint_hints.h"



static v1_endpoint_hints_t *v1_endpoint_hints_create_internal(
    list_t *for_nodes,
    list_t *for_zones
    ) {
    v1_endpoint_hints_t *v1_endpoint_hints_local_var = malloc(sizeof(v1_endpoint_hints_t));
    if (!v1_endpoint_hints_local_var) {
        return NULL;
    }
    v1_endpoint_hints_local_var->for_nodes = for_nodes;
    v1_endpoint_hints_local_var->for_zones = for_zones;

    v1_endpoint_hints_local_var->_library_owned = 1;
    return v1_endpoint_hints_local_var;
}

__attribute__((deprecated)) v1_endpoint_hints_t *v1_endpoint_hints_create(
    list_t *for_nodes,
    list_t *for_zones
    ) {
    return v1_endpoint_hints_create_internal (
        for_nodes,
        for_zones
        );
}

void v1_endpoint_hints_free(v1_endpoint_hints_t *v1_endpoint_hints) {
    if(NULL == v1_endpoint_hints){
        return ;
    }
    if(v1_endpoint_hints->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_endpoint_hints_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_endpoint_hints->for_nodes) {
        list_ForEach(listEntry, v1_endpoint_hints->for_nodes) {
            v1_for_node_free(listEntry->data);
        }
        list_freeList(v1_endpoint_hints->for_nodes);
        v1_endpoint_hints->for_nodes = NULL;
    }
    if (v1_endpoint_hints->for_zones) {
        list_ForEach(listEntry, v1_endpoint_hints->for_zones) {
            v1_for_zone_free(listEntry->data);
        }
        list_freeList(v1_endpoint_hints->for_zones);
        v1_endpoint_hints->for_zones = NULL;
    }
    free(v1_endpoint_hints);
}

cJSON *v1_endpoint_hints_convertToJSON(v1_endpoint_hints_t *v1_endpoint_hints) {
    cJSON *item = cJSON_CreateObject();

    // v1_endpoint_hints->for_nodes
    if(v1_endpoint_hints->for_nodes) {
    cJSON *for_nodes = cJSON_AddArrayToObject(item, "forNodes");
    if(for_nodes == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *for_nodesListEntry;
    if (v1_endpoint_hints->for_nodes) {
    list_ForEach(for_nodesListEntry, v1_endpoint_hints->for_nodes) {
    cJSON *itemLocal = v1_for_node_convertToJSON(for_nodesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(for_nodes, itemLocal);
    }
    }
    }


    // v1_endpoint_hints->for_zones
    if(v1_endpoint_hints->for_zones) {
    cJSON *for_zones = cJSON_AddArrayToObject(item, "forZones");
    if(for_zones == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *for_zonesListEntry;
    if (v1_endpoint_hints->for_zones) {
    list_ForEach(for_zonesListEntry, v1_endpoint_hints->for_zones) {
    cJSON *itemLocal = v1_for_zone_convertToJSON(for_zonesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(for_zones, itemLocal);
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

v1_endpoint_hints_t *v1_endpoint_hints_parseFromJSON(cJSON *v1_endpoint_hintsJSON){

    v1_endpoint_hints_t *v1_endpoint_hints_local_var = NULL;

    // define the local list for v1_endpoint_hints->for_nodes
    list_t *for_nodesList = NULL;

    // define the local list for v1_endpoint_hints->for_zones
    list_t *for_zonesList = NULL;

    // v1_endpoint_hints->for_nodes
    cJSON *for_nodes = cJSON_GetObjectItemCaseSensitive(v1_endpoint_hintsJSON, "forNodes");
    if (cJSON_IsNull(for_nodes)) {
        for_nodes = NULL;
    }
    if (for_nodes) { 
    cJSON *for_nodes_local_nonprimitive = NULL;
    if(!cJSON_IsArray(for_nodes)){
        goto end; //nonprimitive container
    }

    for_nodesList = list_createList();

    cJSON_ArrayForEach(for_nodes_local_nonprimitive,for_nodes )
    {
        if(!cJSON_IsObject(for_nodes_local_nonprimitive)){
            goto end;
        }
        v1_for_node_t *for_nodesItem = v1_for_node_parseFromJSON(for_nodes_local_nonprimitive);

        list_addElement(for_nodesList, for_nodesItem);
    }
    }

    // v1_endpoint_hints->for_zones
    cJSON *for_zones = cJSON_GetObjectItemCaseSensitive(v1_endpoint_hintsJSON, "forZones");
    if (cJSON_IsNull(for_zones)) {
        for_zones = NULL;
    }
    if (for_zones) { 
    cJSON *for_zones_local_nonprimitive = NULL;
    if(!cJSON_IsArray(for_zones)){
        goto end; //nonprimitive container
    }

    for_zonesList = list_createList();

    cJSON_ArrayForEach(for_zones_local_nonprimitive,for_zones )
    {
        if(!cJSON_IsObject(for_zones_local_nonprimitive)){
            goto end;
        }
        v1_for_zone_t *for_zonesItem = v1_for_zone_parseFromJSON(for_zones_local_nonprimitive);

        list_addElement(for_zonesList, for_zonesItem);
    }
    }


    v1_endpoint_hints_local_var = v1_endpoint_hints_create_internal (
        for_nodes ? for_nodesList : NULL,
        for_zones ? for_zonesList : NULL
        );

    return v1_endpoint_hints_local_var;
end:
    if (for_nodesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, for_nodesList) {
            v1_for_node_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(for_nodesList);
        for_nodesList = NULL;
    }
    if (for_zonesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, for_zonesList) {
            v1_for_zone_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(for_zonesList);
        for_zonesList = NULL;
    }
    return NULL;

}
