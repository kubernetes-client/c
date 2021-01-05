#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_container_image.h"



v1_container_image_t *v1_container_image_create(
    list_t *names,
    long size_bytes
    ) {
    v1_container_image_t *v1_container_image_local_var = malloc(sizeof(v1_container_image_t));
    if (!v1_container_image_local_var) {
        return NULL;
    }
    v1_container_image_local_var->names = names;
    v1_container_image_local_var->size_bytes = size_bytes;

    return v1_container_image_local_var;
}


void v1_container_image_free(v1_container_image_t *v1_container_image) {
    if(NULL == v1_container_image){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_container_image->names) {
        list_ForEach(listEntry, v1_container_image->names) {
            free(listEntry->data);
        }
        list_free(v1_container_image->names);
        v1_container_image->names = NULL;
    }
    free(v1_container_image);
}

cJSON *v1_container_image_convertToJSON(v1_container_image_t *v1_container_image) {
    cJSON *item = cJSON_CreateObject();

    // v1_container_image->names
    if (!v1_container_image->names) {
        goto fail;
    }
    
    cJSON *names = cJSON_AddArrayToObject(item, "names");
    if(names == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *namesListEntry;
    list_ForEach(namesListEntry, v1_container_image->names) {
    if(cJSON_AddStringToObject(names, "", (char*)namesListEntry->data) == NULL)
    {
        goto fail;
    }
    }


    // v1_container_image->size_bytes
    if(v1_container_image->size_bytes) { 
    if(cJSON_AddNumberToObject(item, "sizeBytes", v1_container_image->size_bytes) == NULL) {
    goto fail; //Numeric
    }
     } 

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_container_image_t *v1_container_image_parseFromJSON(cJSON *v1_container_imageJSON){

    v1_container_image_t *v1_container_image_local_var = NULL;

    // v1_container_image->names
    cJSON *names = cJSON_GetObjectItemCaseSensitive(v1_container_imageJSON, "names");
    if (!names) {
        goto end;
    }

    list_t *namesList;
    
    cJSON *names_local;
    if(!cJSON_IsArray(names)) {
        goto end;//primitive container
    }
    namesList = list_create();

    cJSON_ArrayForEach(names_local, names)
    {
        if(!cJSON_IsString(names_local))
        {
            goto end;
        }
        list_addElement(namesList , strdup(names_local->valuestring));
    }

    // v1_container_image->size_bytes
    cJSON *size_bytes = cJSON_GetObjectItemCaseSensitive(v1_container_imageJSON, "sizeBytes");
    if (size_bytes) { 
    if(!cJSON_IsNumber(size_bytes))
    {
    goto end; //Numeric
    }
    }


    v1_container_image_local_var = v1_container_image_create (
        namesList,
        size_bytes ? size_bytes->valuedouble : 0
        );

    return v1_container_image_local_var;
end:
    return NULL;

}
