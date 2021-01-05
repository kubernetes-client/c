#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "policy_v1beta1_allowed_flex_volume.h"



policy_v1beta1_allowed_flex_volume_t *policy_v1beta1_allowed_flex_volume_create(
    char *driver
    ) {
    policy_v1beta1_allowed_flex_volume_t *policy_v1beta1_allowed_flex_volume_local_var = malloc(sizeof(policy_v1beta1_allowed_flex_volume_t));
    if (!policy_v1beta1_allowed_flex_volume_local_var) {
        return NULL;
    }
    policy_v1beta1_allowed_flex_volume_local_var->driver = driver;

    return policy_v1beta1_allowed_flex_volume_local_var;
}


void policy_v1beta1_allowed_flex_volume_free(policy_v1beta1_allowed_flex_volume_t *policy_v1beta1_allowed_flex_volume) {
    if(NULL == policy_v1beta1_allowed_flex_volume){
        return ;
    }
    listEntry_t *listEntry;
    if (policy_v1beta1_allowed_flex_volume->driver) {
        free(policy_v1beta1_allowed_flex_volume->driver);
        policy_v1beta1_allowed_flex_volume->driver = NULL;
    }
    free(policy_v1beta1_allowed_flex_volume);
}

cJSON *policy_v1beta1_allowed_flex_volume_convertToJSON(policy_v1beta1_allowed_flex_volume_t *policy_v1beta1_allowed_flex_volume) {
    cJSON *item = cJSON_CreateObject();

    // policy_v1beta1_allowed_flex_volume->driver
    if (!policy_v1beta1_allowed_flex_volume->driver) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "driver", policy_v1beta1_allowed_flex_volume->driver) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

policy_v1beta1_allowed_flex_volume_t *policy_v1beta1_allowed_flex_volume_parseFromJSON(cJSON *policy_v1beta1_allowed_flex_volumeJSON){

    policy_v1beta1_allowed_flex_volume_t *policy_v1beta1_allowed_flex_volume_local_var = NULL;

    // policy_v1beta1_allowed_flex_volume->driver
    cJSON *driver = cJSON_GetObjectItemCaseSensitive(policy_v1beta1_allowed_flex_volumeJSON, "driver");
    if (!driver) {
        goto end;
    }

    
    if(!cJSON_IsString(driver))
    {
    goto end; //String
    }


    policy_v1beta1_allowed_flex_volume_local_var = policy_v1beta1_allowed_flex_volume_create (
        strdup(driver->valuestring)
        );

    return policy_v1beta1_allowed_flex_volume_local_var;
end:
    return NULL;

}
