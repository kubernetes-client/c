#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_volume_status.h"



static v1_volume_status_t *v1_volume_status_create_internal(
    v1_image_volume_status_t *image
    ) {
    v1_volume_status_t *v1_volume_status_local_var = malloc(sizeof(v1_volume_status_t));
    if (!v1_volume_status_local_var) {
        return NULL;
    }
    memset(v1_volume_status_local_var, 0, sizeof(v1_volume_status_t));
    v1_volume_status_local_var->_library_owned = 1;
    v1_volume_status_local_var->image = image;
    return v1_volume_status_local_var;
}

__attribute__((deprecated)) v1_volume_status_t *v1_volume_status_create(
    v1_image_volume_status_t *image
    ) {
    v1_volume_status_t *result = v1_volume_status_create_internal (
        image
        );
    if (!result) {
    }
    return result;
}

void v1_volume_status_free(v1_volume_status_t *v1_volume_status) {
    if(NULL == v1_volume_status){
        return ;
    }
    if(v1_volume_status->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_volume_status_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_volume_status->image) {
        v1_image_volume_status_free(v1_volume_status->image);
        v1_volume_status->image = NULL;
    }
    free(v1_volume_status);
}

cJSON *v1_volume_status_convertToJSON(v1_volume_status_t *v1_volume_status) {
    cJSON *item = cJSON_CreateObject();

    // v1_volume_status->image
    if(v1_volume_status->image) {
    cJSON *image_local_JSON = v1_image_volume_status_convertToJSON(v1_volume_status->image);
    if(image_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "image", image_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_volume_status_t *v1_volume_status_parseFromJSON(cJSON *v1_volume_statusJSON){

    v1_volume_status_t *v1_volume_status_local_var = NULL;

    // define the local variable for v1_volume_status->image
    v1_image_volume_status_t *image_local_nonprim = NULL;

    // v1_volume_status->image
    cJSON *image = cJSON_GetObjectItemCaseSensitive(v1_volume_statusJSON, "image");
    if (cJSON_IsNull(image)) {
        image = NULL;
    }
    if (image) { 
    image_local_nonprim = v1_image_volume_status_parseFromJSON(image); //nonprimitive
    }



    v1_volume_status_local_var = v1_volume_status_create_internal (
        image ? image_local_nonprim : NULL
        );

    if (!v1_volume_status_local_var) {
        goto end;
    }

    return v1_volume_status_local_var;
end:
    if (image_local_nonprim) {
        v1_image_volume_status_free(image_local_nonprim);
        image_local_nonprim = NULL;
    }
    return NULL;

}
