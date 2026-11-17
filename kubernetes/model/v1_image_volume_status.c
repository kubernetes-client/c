#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_image_volume_status.h"



static v1_image_volume_status_t *v1_image_volume_status_create_internal(
    char *image_ref
    ) {
    v1_image_volume_status_t *v1_image_volume_status_local_var = malloc(sizeof(v1_image_volume_status_t));
    if (!v1_image_volume_status_local_var) {
        return NULL;
    }
    memset(v1_image_volume_status_local_var, 0, sizeof(v1_image_volume_status_t));
    v1_image_volume_status_local_var->_library_owned = 1;
    v1_image_volume_status_local_var->image_ref = image_ref;
    return v1_image_volume_status_local_var;
}

__attribute__((deprecated)) v1_image_volume_status_t *v1_image_volume_status_create(
    char *image_ref
    ) {
    v1_image_volume_status_t *result = v1_image_volume_status_create_internal (
        image_ref
        );
    if (!result) {
    }
    return result;
}

void v1_image_volume_status_free(v1_image_volume_status_t *v1_image_volume_status) {
    if(NULL == v1_image_volume_status){
        return ;
    }
    if(v1_image_volume_status->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_image_volume_status_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_image_volume_status->image_ref) {
        free(v1_image_volume_status->image_ref);
        v1_image_volume_status->image_ref = NULL;
    }
    free(v1_image_volume_status);
}

cJSON *v1_image_volume_status_convertToJSON(v1_image_volume_status_t *v1_image_volume_status) {
    cJSON *item = cJSON_CreateObject();

    // v1_image_volume_status->image_ref
    if (!v1_image_volume_status->image_ref) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "imageRef", v1_image_volume_status->image_ref) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_image_volume_status_t *v1_image_volume_status_parseFromJSON(cJSON *v1_image_volume_statusJSON){

    v1_image_volume_status_t *v1_image_volume_status_local_var = NULL;

    char *image_ref_local_str = NULL;

    // v1_image_volume_status->image_ref
    cJSON *image_ref = cJSON_GetObjectItemCaseSensitive(v1_image_volume_statusJSON, "imageRef");
    if (cJSON_IsNull(image_ref)) {
        image_ref = NULL;
    }
    if (!image_ref) {
        goto end;
    }

    
    if(!cJSON_IsString(image_ref))
    {
    goto end; //String
    }


    if (image_ref && !cJSON_IsNull(image_ref)) image_ref_local_str = strdup(image_ref->valuestring);

    v1_image_volume_status_local_var = v1_image_volume_status_create_internal (
        image_ref_local_str
        );

    if (!v1_image_volume_status_local_var) {
        goto end;
    }

    return v1_image_volume_status_local_var;
end:
    if (image_ref_local_str) {
        free(image_ref_local_str);
        image_ref_local_str = NULL;
    }
    return NULL;

}
