#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha3_composite_pod_group_scheduling_constraints.h"



static v1alpha3_composite_pod_group_scheduling_constraints_t *v1alpha3_composite_pod_group_scheduling_constraints_create_internal(
    list_t *topology
    ) {
    v1alpha3_composite_pod_group_scheduling_constraints_t *v1alpha3_composite_pod_group_scheduling_constraints_local_var = malloc(sizeof(v1alpha3_composite_pod_group_scheduling_constraints_t));
    if (!v1alpha3_composite_pod_group_scheduling_constraints_local_var) {
        return NULL;
    }
    memset(v1alpha3_composite_pod_group_scheduling_constraints_local_var, 0, sizeof(v1alpha3_composite_pod_group_scheduling_constraints_t));
    v1alpha3_composite_pod_group_scheduling_constraints_local_var->_library_owned = 1;
    v1alpha3_composite_pod_group_scheduling_constraints_local_var->topology = topology;
    return v1alpha3_composite_pod_group_scheduling_constraints_local_var;
}

__attribute__((deprecated)) v1alpha3_composite_pod_group_scheduling_constraints_t *v1alpha3_composite_pod_group_scheduling_constraints_create(
    list_t *topology
    ) {
    v1alpha3_composite_pod_group_scheduling_constraints_t *result = v1alpha3_composite_pod_group_scheduling_constraints_create_internal (
        topology
        );
    if (!result) {
    }
    return result;
}

void v1alpha3_composite_pod_group_scheduling_constraints_free(v1alpha3_composite_pod_group_scheduling_constraints_t *v1alpha3_composite_pod_group_scheduling_constraints) {
    if(NULL == v1alpha3_composite_pod_group_scheduling_constraints){
        return ;
    }
    if(v1alpha3_composite_pod_group_scheduling_constraints->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1alpha3_composite_pod_group_scheduling_constraints_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha3_composite_pod_group_scheduling_constraints->topology) {
        list_ForEach(listEntry, v1alpha3_composite_pod_group_scheduling_constraints->topology) {
            v1alpha3_topology_constraint_free(listEntry->data);
        }
        list_freeList(v1alpha3_composite_pod_group_scheduling_constraints->topology);
        v1alpha3_composite_pod_group_scheduling_constraints->topology = NULL;
    }
    free(v1alpha3_composite_pod_group_scheduling_constraints);
}

cJSON *v1alpha3_composite_pod_group_scheduling_constraints_convertToJSON(v1alpha3_composite_pod_group_scheduling_constraints_t *v1alpha3_composite_pod_group_scheduling_constraints) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha3_composite_pod_group_scheduling_constraints->topology
    if(v1alpha3_composite_pod_group_scheduling_constraints->topology) {
    cJSON *topology = cJSON_AddArrayToObject(item, "topology");
    if(topology == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *topologyListEntry;
    if (v1alpha3_composite_pod_group_scheduling_constraints->topology) {
    list_ForEach(topologyListEntry, v1alpha3_composite_pod_group_scheduling_constraints->topology) {
    cJSON *itemLocal = v1alpha3_topology_constraint_convertToJSON(topologyListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(topology, itemLocal);
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

v1alpha3_composite_pod_group_scheduling_constraints_t *v1alpha3_composite_pod_group_scheduling_constraints_parseFromJSON(cJSON *v1alpha3_composite_pod_group_scheduling_constraintsJSON){

    v1alpha3_composite_pod_group_scheduling_constraints_t *v1alpha3_composite_pod_group_scheduling_constraints_local_var = NULL;

    // define the local list for v1alpha3_composite_pod_group_scheduling_constraints->topology
    list_t *topologyList = NULL;

    // v1alpha3_composite_pod_group_scheduling_constraints->topology
    cJSON *topology = cJSON_GetObjectItemCaseSensitive(v1alpha3_composite_pod_group_scheduling_constraintsJSON, "topology");
    if (cJSON_IsNull(topology)) {
        topology = NULL;
    }
    if (topology) { 
    cJSON *topology_local_nonprimitive = NULL;
    if(!cJSON_IsArray(topology)){
        goto end; //nonprimitive container
    }

    topologyList = list_createList();

    cJSON_ArrayForEach(topology_local_nonprimitive,topology )
    {
        if(!cJSON_IsObject(topology_local_nonprimitive)){
            goto end;
        }
        v1alpha3_topology_constraint_t *topologyItem = v1alpha3_topology_constraint_parseFromJSON(topology_local_nonprimitive);

        list_addElement(topologyList, topologyItem);
    }
    }



    v1alpha3_composite_pod_group_scheduling_constraints_local_var = v1alpha3_composite_pod_group_scheduling_constraints_create_internal (
        topology ? topologyList : NULL
        );

    if (!v1alpha3_composite_pod_group_scheduling_constraints_local_var) {
        goto end;
    }

    return v1alpha3_composite_pod_group_scheduling_constraints_local_var;
end:
    if (topologyList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, topologyList) {
            v1alpha3_topology_constraint_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(topologyList);
        topologyList = NULL;
    }
    return NULL;

}
