#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "extensions_v1beta1_allowed_flex_volume.h"



extensions_v1beta1_allowed_flex_volume_t *extensions_v1beta1_allowed_flex_volume_create(
    char *driver
    ) {
    extensions_v1beta1_allowed_flex_volume_t *extensions_v1beta1_allowed_flex_volume_local_var = malloc(sizeof(extensions_v1beta1_allowed_flex_volume_t));
    if (!extensions_v1beta1_allowed_flex_volume_local_var) {
        return NULL;
    }
    extensions_v1beta1_allowed_flex_volume_local_var->driver = driver;

    return extensions_v1beta1_allowed_flex_volume_local_var;
}


void extensions_v1beta1_allowed_flex_volume_free(extensions_v1beta1_allowed_flex_volume_t *extensions_v1beta1_allowed_flex_volume) {
    if(NULL == extensions_v1beta1_allowed_flex_volume){
        return ;
    }
    listEntry_t *listEntry;
    if (extensions_v1beta1_allowed_flex_volume->driver) {
        free(extensions_v1beta1_allowed_flex_volume->driver);
        extensions_v1beta1_allowed_flex_volume->driver = NULL;
    }
    free(extensions_v1beta1_allowed_flex_volume);
}

cJSON *extensions_v1beta1_allowed_flex_volume_convertToJSON(extensions_v1beta1_allowed_flex_volume_t *extensions_v1beta1_allowed_flex_volume) {
    cJSON *item = cJSON_CreateObject();

    // extensions_v1beta1_allowed_flex_volume->driver
    if (!extensions_v1beta1_allowed_flex_volume->driver) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "driver", extensions_v1beta1_allowed_flex_volume->driver) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

extensions_v1beta1_allowed_flex_volume_t *extensions_v1beta1_allowed_flex_volume_parseFromJSON(cJSON *extensions_v1beta1_allowed_flex_volumeJSON){

    extensions_v1beta1_allowed_flex_volume_t *extensions_v1beta1_allowed_flex_volume_local_var = NULL;

    // extensions_v1beta1_allowed_flex_volume->driver
    cJSON *driver = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_allowed_flex_volumeJSON, "driver");
    if (!driver) {
        goto end;
    }

    
    if(!cJSON_IsString(driver))
    {
    goto end; //String
    }


    extensions_v1beta1_allowed_flex_volume_local_var = extensions_v1beta1_allowed_flex_volume_create (
        strdup(driver->valuestring)
        );

    return extensions_v1beta1_allowed_flex_volume_local_var;
end:
    return NULL;

}
