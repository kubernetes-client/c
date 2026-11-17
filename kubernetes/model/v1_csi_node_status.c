#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_csi_node_status.h"



static v1_csi_node_status_t *v1_csi_node_status_create_internal(
    list_t *storage_health
    ) {
    v1_csi_node_status_t *v1_csi_node_status_local_var = malloc(sizeof(v1_csi_node_status_t));
    if (!v1_csi_node_status_local_var) {
        return NULL;
    }
    memset(v1_csi_node_status_local_var, 0, sizeof(v1_csi_node_status_t));
    v1_csi_node_status_local_var->_library_owned = 1;
    v1_csi_node_status_local_var->storage_health = storage_health;
    return v1_csi_node_status_local_var;
}

__attribute__((deprecated)) v1_csi_node_status_t *v1_csi_node_status_create(
    list_t *storage_health
    ) {
    v1_csi_node_status_t *result = v1_csi_node_status_create_internal (
        storage_health
        );
    if (!result) {
    }
    return result;
}

void v1_csi_node_status_free(v1_csi_node_status_t *v1_csi_node_status) {
    if(NULL == v1_csi_node_status){
        return ;
    }
    if(v1_csi_node_status->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_csi_node_status_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_csi_node_status->storage_health) {
        list_ForEach(listEntry, v1_csi_node_status->storage_health) {
            v1_storage_health_free(listEntry->data);
        }
        list_freeList(v1_csi_node_status->storage_health);
        v1_csi_node_status->storage_health = NULL;
    }
    free(v1_csi_node_status);
}

cJSON *v1_csi_node_status_convertToJSON(v1_csi_node_status_t *v1_csi_node_status) {
    cJSON *item = cJSON_CreateObject();

    // v1_csi_node_status->storage_health
    if(v1_csi_node_status->storage_health) {
    cJSON *storage_health = cJSON_AddArrayToObject(item, "storageHealth");
    if(storage_health == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *storage_healthListEntry;
    if (v1_csi_node_status->storage_health) {
    list_ForEach(storage_healthListEntry, v1_csi_node_status->storage_health) {
    cJSON *itemLocal = v1_storage_health_convertToJSON(storage_healthListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(storage_health, itemLocal);
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

v1_csi_node_status_t *v1_csi_node_status_parseFromJSON(cJSON *v1_csi_node_statusJSON){

    v1_csi_node_status_t *v1_csi_node_status_local_var = NULL;

    // define the local list for v1_csi_node_status->storage_health
    list_t *storage_healthList = NULL;

    // v1_csi_node_status->storage_health
    cJSON *storage_health = cJSON_GetObjectItemCaseSensitive(v1_csi_node_statusJSON, "storageHealth");
    if (cJSON_IsNull(storage_health)) {
        storage_health = NULL;
    }
    if (storage_health) { 
    cJSON *storage_health_local_nonprimitive = NULL;
    if(!cJSON_IsArray(storage_health)){
        goto end; //nonprimitive container
    }

    storage_healthList = list_createList();

    cJSON_ArrayForEach(storage_health_local_nonprimitive,storage_health )
    {
        if(!cJSON_IsObject(storage_health_local_nonprimitive)){
            goto end;
        }
        v1_storage_health_t *storage_healthItem = v1_storage_health_parseFromJSON(storage_health_local_nonprimitive);

        list_addElement(storage_healthList, storage_healthItem);
    }
    }



    v1_csi_node_status_local_var = v1_csi_node_status_create_internal (
        storage_health ? storage_healthList : NULL
        );

    if (!v1_csi_node_status_local_var) {
        goto end;
    }

    return v1_csi_node_status_local_var;
end:
    if (storage_healthList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, storage_healthList) {
            v1_storage_health_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(storage_healthList);
        storage_healthList = NULL;
    }
    return NULL;

}
