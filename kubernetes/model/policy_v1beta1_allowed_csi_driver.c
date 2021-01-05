#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "policy_v1beta1_allowed_csi_driver.h"



policy_v1beta1_allowed_csi_driver_t *policy_v1beta1_allowed_csi_driver_create(
    char *name
    ) {
    policy_v1beta1_allowed_csi_driver_t *policy_v1beta1_allowed_csi_driver_local_var = malloc(sizeof(policy_v1beta1_allowed_csi_driver_t));
    if (!policy_v1beta1_allowed_csi_driver_local_var) {
        return NULL;
    }
    policy_v1beta1_allowed_csi_driver_local_var->name = name;

    return policy_v1beta1_allowed_csi_driver_local_var;
}


void policy_v1beta1_allowed_csi_driver_free(policy_v1beta1_allowed_csi_driver_t *policy_v1beta1_allowed_csi_driver) {
    if(NULL == policy_v1beta1_allowed_csi_driver){
        return ;
    }
    listEntry_t *listEntry;
    if (policy_v1beta1_allowed_csi_driver->name) {
        free(policy_v1beta1_allowed_csi_driver->name);
        policy_v1beta1_allowed_csi_driver->name = NULL;
    }
    free(policy_v1beta1_allowed_csi_driver);
}

cJSON *policy_v1beta1_allowed_csi_driver_convertToJSON(policy_v1beta1_allowed_csi_driver_t *policy_v1beta1_allowed_csi_driver) {
    cJSON *item = cJSON_CreateObject();

    // policy_v1beta1_allowed_csi_driver->name
    if (!policy_v1beta1_allowed_csi_driver->name) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "name", policy_v1beta1_allowed_csi_driver->name) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

policy_v1beta1_allowed_csi_driver_t *policy_v1beta1_allowed_csi_driver_parseFromJSON(cJSON *policy_v1beta1_allowed_csi_driverJSON){

    policy_v1beta1_allowed_csi_driver_t *policy_v1beta1_allowed_csi_driver_local_var = NULL;

    // policy_v1beta1_allowed_csi_driver->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(policy_v1beta1_allowed_csi_driverJSON, "name");
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }


    policy_v1beta1_allowed_csi_driver_local_var = policy_v1beta1_allowed_csi_driver_create (
        strdup(name->valuestring)
        );

    return policy_v1beta1_allowed_csi_driver_local_var;
end:
    return NULL;

}
