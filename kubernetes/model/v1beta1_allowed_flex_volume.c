#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_allowed_flex_volume.h"



v1beta1_allowed_flex_volume_t *v1beta1_allowed_flex_volume_create(
    char *driver
    ) {
    v1beta1_allowed_flex_volume_t *v1beta1_allowed_flex_volume_local_var = malloc(sizeof(v1beta1_allowed_flex_volume_t));
    if (!v1beta1_allowed_flex_volume_local_var) {
        return NULL;
    }
    v1beta1_allowed_flex_volume_local_var->driver = driver;

    return v1beta1_allowed_flex_volume_local_var;
}


void v1beta1_allowed_flex_volume_free(v1beta1_allowed_flex_volume_t *v1beta1_allowed_flex_volume) {
    if(NULL == v1beta1_allowed_flex_volume){
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta1_allowed_flex_volume->driver) {
        free(v1beta1_allowed_flex_volume->driver);
        v1beta1_allowed_flex_volume->driver = NULL;
    }
    free(v1beta1_allowed_flex_volume);
}

cJSON *v1beta1_allowed_flex_volume_convertToJSON(v1beta1_allowed_flex_volume_t *v1beta1_allowed_flex_volume) {
    cJSON *item = cJSON_CreateObject();

    // v1beta1_allowed_flex_volume->driver
    if (!v1beta1_allowed_flex_volume->driver) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "driver", v1beta1_allowed_flex_volume->driver) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1beta1_allowed_flex_volume_t *v1beta1_allowed_flex_volume_parseFromJSON(cJSON *v1beta1_allowed_flex_volumeJSON){

    v1beta1_allowed_flex_volume_t *v1beta1_allowed_flex_volume_local_var = NULL;

    // v1beta1_allowed_flex_volume->driver
    cJSON *driver = cJSON_GetObjectItemCaseSensitive(v1beta1_allowed_flex_volumeJSON, "driver");
    if (!driver) {
        goto end;
    }

    
    if(!cJSON_IsString(driver))
    {
    goto end; //String
    }


    v1beta1_allowed_flex_volume_local_var = v1beta1_allowed_flex_volume_create (
        strdup(driver->valuestring)
        );

    return v1beta1_allowed_flex_volume_local_var;
end:
    return NULL;

}
