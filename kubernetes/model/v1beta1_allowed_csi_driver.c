#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_allowed_csi_driver.h"



v1beta1_allowed_csi_driver_t *v1beta1_allowed_csi_driver_create(
    char *name
    ) {
    v1beta1_allowed_csi_driver_t *v1beta1_allowed_csi_driver_local_var = malloc(sizeof(v1beta1_allowed_csi_driver_t));
    if (!v1beta1_allowed_csi_driver_local_var) {
        return NULL;
    }
    v1beta1_allowed_csi_driver_local_var->name = name;

    return v1beta1_allowed_csi_driver_local_var;
}


void v1beta1_allowed_csi_driver_free(v1beta1_allowed_csi_driver_t *v1beta1_allowed_csi_driver) {
    if(NULL == v1beta1_allowed_csi_driver){
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta1_allowed_csi_driver->name) {
        free(v1beta1_allowed_csi_driver->name);
        v1beta1_allowed_csi_driver->name = NULL;
    }
    free(v1beta1_allowed_csi_driver);
}

cJSON *v1beta1_allowed_csi_driver_convertToJSON(v1beta1_allowed_csi_driver_t *v1beta1_allowed_csi_driver) {
    cJSON *item = cJSON_CreateObject();

    // v1beta1_allowed_csi_driver->name
    if (!v1beta1_allowed_csi_driver->name) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "name", v1beta1_allowed_csi_driver->name) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1beta1_allowed_csi_driver_t *v1beta1_allowed_csi_driver_parseFromJSON(cJSON *v1beta1_allowed_csi_driverJSON){

    v1beta1_allowed_csi_driver_t *v1beta1_allowed_csi_driver_local_var = NULL;

    // v1beta1_allowed_csi_driver->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1beta1_allowed_csi_driverJSON, "name");
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }


    v1beta1_allowed_csi_driver_local_var = v1beta1_allowed_csi_driver_create (
        strdup(name->valuestring)
        );

    return v1beta1_allowed_csi_driver_local_var;
end:
    return NULL;

}
