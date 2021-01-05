#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_csi_node_spec.h"



v1beta1_csi_node_spec_t *v1beta1_csi_node_spec_create(
    list_t *drivers
    ) {
    v1beta1_csi_node_spec_t *v1beta1_csi_node_spec_local_var = malloc(sizeof(v1beta1_csi_node_spec_t));
    if (!v1beta1_csi_node_spec_local_var) {
        return NULL;
    }
    v1beta1_csi_node_spec_local_var->drivers = drivers;

    return v1beta1_csi_node_spec_local_var;
}


void v1beta1_csi_node_spec_free(v1beta1_csi_node_spec_t *v1beta1_csi_node_spec) {
    if(NULL == v1beta1_csi_node_spec){
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta1_csi_node_spec->drivers) {
        list_ForEach(listEntry, v1beta1_csi_node_spec->drivers) {
            v1beta1_csi_node_driver_free(listEntry->data);
        }
        list_free(v1beta1_csi_node_spec->drivers);
        v1beta1_csi_node_spec->drivers = NULL;
    }
    free(v1beta1_csi_node_spec);
}

cJSON *v1beta1_csi_node_spec_convertToJSON(v1beta1_csi_node_spec_t *v1beta1_csi_node_spec) {
    cJSON *item = cJSON_CreateObject();

    // v1beta1_csi_node_spec->drivers
    if (!v1beta1_csi_node_spec->drivers) {
        goto fail;
    }
    
    cJSON *drivers = cJSON_AddArrayToObject(item, "drivers");
    if(drivers == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *driversListEntry;
    if (v1beta1_csi_node_spec->drivers) {
    list_ForEach(driversListEntry, v1beta1_csi_node_spec->drivers) {
    cJSON *itemLocal = v1beta1_csi_node_driver_convertToJSON(driversListEntry->data);
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

v1beta1_csi_node_spec_t *v1beta1_csi_node_spec_parseFromJSON(cJSON *v1beta1_csi_node_specJSON){

    v1beta1_csi_node_spec_t *v1beta1_csi_node_spec_local_var = NULL;

    // v1beta1_csi_node_spec->drivers
    cJSON *drivers = cJSON_GetObjectItemCaseSensitive(v1beta1_csi_node_specJSON, "drivers");
    if (!drivers) {
        goto end;
    }

    list_t *driversList;
    
    cJSON *drivers_local_nonprimitive;
    if(!cJSON_IsArray(drivers)){
        goto end; //nonprimitive container
    }

    driversList = list_create();

    cJSON_ArrayForEach(drivers_local_nonprimitive,drivers )
    {
        if(!cJSON_IsObject(drivers_local_nonprimitive)){
            goto end;
        }
        v1beta1_csi_node_driver_t *driversItem = v1beta1_csi_node_driver_parseFromJSON(drivers_local_nonprimitive);

        list_addElement(driversList, driversItem);
    }


    v1beta1_csi_node_spec_local_var = v1beta1_csi_node_spec_create (
        driversList
        );

    return v1beta1_csi_node_spec_local_var;
end:
    return NULL;

}
