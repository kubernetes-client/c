#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_csi_node_spec.h"



static v1_csi_node_spec_t *v1_csi_node_spec_create_internal(
    list_t *drivers
    ) {
    v1_csi_node_spec_t *v1_csi_node_spec_local_var = malloc(sizeof(v1_csi_node_spec_t));
    if (!v1_csi_node_spec_local_var) {
        return NULL;
    }
    v1_csi_node_spec_local_var->drivers = drivers;

    v1_csi_node_spec_local_var->_library_owned = 1;
    return v1_csi_node_spec_local_var;
}

__attribute__((deprecated)) v1_csi_node_spec_t *v1_csi_node_spec_create(
    list_t *drivers
    ) {
    return v1_csi_node_spec_create_internal (
        drivers
        );
}

void v1_csi_node_spec_free(v1_csi_node_spec_t *v1_csi_node_spec) {
    if(NULL == v1_csi_node_spec){
        return ;
    }
    if(v1_csi_node_spec->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_csi_node_spec_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_csi_node_spec->drivers) {
        list_ForEach(listEntry, v1_csi_node_spec->drivers) {
            v1_csi_node_driver_free(listEntry->data);
        }
        list_freeList(v1_csi_node_spec->drivers);
        v1_csi_node_spec->drivers = NULL;
    }
    free(v1_csi_node_spec);
}

cJSON *v1_csi_node_spec_convertToJSON(v1_csi_node_spec_t *v1_csi_node_spec) {
    cJSON *item = cJSON_CreateObject();

    // v1_csi_node_spec->drivers
    if (!v1_csi_node_spec->drivers) {
        goto fail;
    }
    cJSON *drivers = cJSON_AddArrayToObject(item, "drivers");
    if(drivers == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *driversListEntry;
    if (v1_csi_node_spec->drivers) {
    list_ForEach(driversListEntry, v1_csi_node_spec->drivers) {
    cJSON *itemLocal = v1_csi_node_driver_convertToJSON(driversListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(drivers, itemLocal);
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_csi_node_spec_t *v1_csi_node_spec_parseFromJSON(cJSON *v1_csi_node_specJSON){

    v1_csi_node_spec_t *v1_csi_node_spec_local_var = NULL;

    // define the local list for v1_csi_node_spec->drivers
    list_t *driversList = NULL;

    // v1_csi_node_spec->drivers
    cJSON *drivers = cJSON_GetObjectItemCaseSensitive(v1_csi_node_specJSON, "drivers");
    if (cJSON_IsNull(drivers)) {
        drivers = NULL;
    }
    if (!drivers) {
        goto end;
    }

    
    cJSON *drivers_local_nonprimitive = NULL;
    if(!cJSON_IsArray(drivers)){
        goto end; //nonprimitive container
    }

    driversList = list_createList();

    cJSON_ArrayForEach(drivers_local_nonprimitive,drivers )
    {
        if(!cJSON_IsObject(drivers_local_nonprimitive)){
            goto end;
        }
        v1_csi_node_driver_t *driversItem = v1_csi_node_driver_parseFromJSON(drivers_local_nonprimitive);

        list_addElement(driversList, driversItem);
    }


    v1_csi_node_spec_local_var = v1_csi_node_spec_create_internal (
        driversList
        );

    return v1_csi_node_spec_local_var;
end:
    if (driversList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, driversList) {
            v1_csi_node_driver_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(driversList);
        driversList = NULL;
    }
    return NULL;

}
