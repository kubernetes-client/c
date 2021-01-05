#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "extensions_v1beta1_allowed_csi_driver.h"



extensions_v1beta1_allowed_csi_driver_t *extensions_v1beta1_allowed_csi_driver_create(
    char *name
    ) {
    extensions_v1beta1_allowed_csi_driver_t *extensions_v1beta1_allowed_csi_driver_local_var = malloc(sizeof(extensions_v1beta1_allowed_csi_driver_t));
    if (!extensions_v1beta1_allowed_csi_driver_local_var) {
        return NULL;
    }
    extensions_v1beta1_allowed_csi_driver_local_var->name = name;

    return extensions_v1beta1_allowed_csi_driver_local_var;
}


void extensions_v1beta1_allowed_csi_driver_free(extensions_v1beta1_allowed_csi_driver_t *extensions_v1beta1_allowed_csi_driver) {
    if(NULL == extensions_v1beta1_allowed_csi_driver){
        return ;
    }
    listEntry_t *listEntry;
    if (extensions_v1beta1_allowed_csi_driver->name) {
        free(extensions_v1beta1_allowed_csi_driver->name);
        extensions_v1beta1_allowed_csi_driver->name = NULL;
    }
    free(extensions_v1beta1_allowed_csi_driver);
}

cJSON *extensions_v1beta1_allowed_csi_driver_convertToJSON(extensions_v1beta1_allowed_csi_driver_t *extensions_v1beta1_allowed_csi_driver) {
    cJSON *item = cJSON_CreateObject();

    // extensions_v1beta1_allowed_csi_driver->name
    if (!extensions_v1beta1_allowed_csi_driver->name) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "name", extensions_v1beta1_allowed_csi_driver->name) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

extensions_v1beta1_allowed_csi_driver_t *extensions_v1beta1_allowed_csi_driver_parseFromJSON(cJSON *extensions_v1beta1_allowed_csi_driverJSON){

    extensions_v1beta1_allowed_csi_driver_t *extensions_v1beta1_allowed_csi_driver_local_var = NULL;

    // extensions_v1beta1_allowed_csi_driver->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_allowed_csi_driverJSON, "name");
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }


    extensions_v1beta1_allowed_csi_driver_local_var = extensions_v1beta1_allowed_csi_driver_create (
        strdup(name->valuestring)
        );

    return extensions_v1beta1_allowed_csi_driver_local_var;
end:
    return NULL;

}
