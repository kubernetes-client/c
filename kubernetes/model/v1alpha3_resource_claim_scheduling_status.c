#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha3_resource_claim_scheduling_status.h"



v1alpha3_resource_claim_scheduling_status_t *v1alpha3_resource_claim_scheduling_status_create(
    char *name,
    list_t *unsuitable_nodes
    ) {
    v1alpha3_resource_claim_scheduling_status_t *v1alpha3_resource_claim_scheduling_status_local_var = malloc(sizeof(v1alpha3_resource_claim_scheduling_status_t));
    if (!v1alpha3_resource_claim_scheduling_status_local_var) {
        return NULL;
    }
    v1alpha3_resource_claim_scheduling_status_local_var->name = name;
    v1alpha3_resource_claim_scheduling_status_local_var->unsuitable_nodes = unsuitable_nodes;

    return v1alpha3_resource_claim_scheduling_status_local_var;
}


void v1alpha3_resource_claim_scheduling_status_free(v1alpha3_resource_claim_scheduling_status_t *v1alpha3_resource_claim_scheduling_status) {
    if(NULL == v1alpha3_resource_claim_scheduling_status){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha3_resource_claim_scheduling_status->name) {
        free(v1alpha3_resource_claim_scheduling_status->name);
        v1alpha3_resource_claim_scheduling_status->name = NULL;
    }
    if (v1alpha3_resource_claim_scheduling_status->unsuitable_nodes) {
        list_ForEach(listEntry, v1alpha3_resource_claim_scheduling_status->unsuitable_nodes) {
            free(listEntry->data);
        }
        list_freeList(v1alpha3_resource_claim_scheduling_status->unsuitable_nodes);
        v1alpha3_resource_claim_scheduling_status->unsuitable_nodes = NULL;
    }
    free(v1alpha3_resource_claim_scheduling_status);
}

cJSON *v1alpha3_resource_claim_scheduling_status_convertToJSON(v1alpha3_resource_claim_scheduling_status_t *v1alpha3_resource_claim_scheduling_status) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha3_resource_claim_scheduling_status->name
    if (!v1alpha3_resource_claim_scheduling_status->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", v1alpha3_resource_claim_scheduling_status->name) == NULL) {
    goto fail; //String
    }


    // v1alpha3_resource_claim_scheduling_status->unsuitable_nodes
    if(v1alpha3_resource_claim_scheduling_status->unsuitable_nodes) {
    cJSON *unsuitable_nodes = cJSON_AddArrayToObject(item, "unsuitableNodes");
    if(unsuitable_nodes == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *unsuitable_nodesListEntry;
    list_ForEach(unsuitable_nodesListEntry, v1alpha3_resource_claim_scheduling_status->unsuitable_nodes) {
    if(cJSON_AddStringToObject(unsuitable_nodes, "", (char*)unsuitable_nodesListEntry->data) == NULL)
    {
        goto fail;
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

v1alpha3_resource_claim_scheduling_status_t *v1alpha3_resource_claim_scheduling_status_parseFromJSON(cJSON *v1alpha3_resource_claim_scheduling_statusJSON){

    v1alpha3_resource_claim_scheduling_status_t *v1alpha3_resource_claim_scheduling_status_local_var = NULL;

    // define the local list for v1alpha3_resource_claim_scheduling_status->unsuitable_nodes
    list_t *unsuitable_nodesList = NULL;

    // v1alpha3_resource_claim_scheduling_status->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1alpha3_resource_claim_scheduling_statusJSON, "name");
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // v1alpha3_resource_claim_scheduling_status->unsuitable_nodes
    cJSON *unsuitable_nodes = cJSON_GetObjectItemCaseSensitive(v1alpha3_resource_claim_scheduling_statusJSON, "unsuitableNodes");
    if (unsuitable_nodes) { 
    cJSON *unsuitable_nodes_local = NULL;
    if(!cJSON_IsArray(unsuitable_nodes)) {
        goto end;//primitive container
    }
    unsuitable_nodesList = list_createList();

    cJSON_ArrayForEach(unsuitable_nodes_local, unsuitable_nodes)
    {
        if(!cJSON_IsString(unsuitable_nodes_local))
        {
            goto end;
        }
        list_addElement(unsuitable_nodesList , strdup(unsuitable_nodes_local->valuestring));
    }
    }


    v1alpha3_resource_claim_scheduling_status_local_var = v1alpha3_resource_claim_scheduling_status_create (
        strdup(name->valuestring),
        unsuitable_nodes ? unsuitable_nodesList : NULL
        );

    return v1alpha3_resource_claim_scheduling_status_local_var;
end:
    if (unsuitable_nodesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, unsuitable_nodesList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(unsuitable_nodesList);
        unsuitable_nodesList = NULL;
    }
    return NULL;

}
