#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_container_image.h"



static v1_container_image_t *v1_container_image_create_internal(
    list_t *names,
    long size_bytes
    ) {
    v1_container_image_t *v1_container_image_local_var = malloc(sizeof(v1_container_image_t));
    if (!v1_container_image_local_var) {
        return NULL;
    }
    v1_container_image_local_var->names = names;
    v1_container_image_local_var->size_bytes = size_bytes;

    v1_container_image_local_var->_library_owned = 1;
    return v1_container_image_local_var;
}

__attribute__((deprecated)) v1_container_image_t *v1_container_image_create(
    list_t *names,
    long size_bytes
    ) {
    return v1_container_image_create_internal (
        names,
        size_bytes
        );
}

void v1_container_image_free(v1_container_image_t *v1_container_image) {
    if(NULL == v1_container_image){
        return ;
    }
    if(v1_container_image->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_container_image_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_container_image->names) {
        list_ForEach(listEntry, v1_container_image->names) {
            free(listEntry->data);
        }
        list_freeList(v1_container_image->names);
        v1_container_image->names = NULL;
    }
    free(v1_container_image);
}

cJSON *v1_container_image_convertToJSON(v1_container_image_t *v1_container_image) {
    cJSON *item = cJSON_CreateObject();

    // v1_container_image->names
    if(v1_container_image->names) {
    cJSON *names = cJSON_AddArrayToObject(item, "names");
    if(names == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *namesListEntry;
    list_ForEach(namesListEntry, v1_container_image->names) {
    if(cJSON_AddStringToObject(names, "", namesListEntry->data) == NULL)
    {
        goto fail;
    }
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

    // define the local list for v1_container_image->names
    list_t *namesList = NULL;

    // v1_container_image->names
    cJSON *names = cJSON_GetObjectItemCaseSensitive(v1_container_imageJSON, "names");
    if (cJSON_IsNull(names)) {
        names = NULL;
    }
    if (names) { 
    cJSON *names_local = NULL;
    if(!cJSON_IsArray(names)) {
        goto end;//primitive container
    }
    namesList = list_createList();

    cJSON_ArrayForEach(names_local, names)
    {
        if(!cJSON_IsString(names_local))
        {
            goto end;
        }
        list_addElement(namesList , strdup(names_local->valuestring));
    }
    }

    // v1_container_image->size_bytes
    cJSON *size_bytes = cJSON_GetObjectItemCaseSensitive(v1_container_imageJSON, "sizeBytes");
    if (cJSON_IsNull(size_bytes)) {
        size_bytes = NULL;
    }
    if (size_bytes) { 
    if(!cJSON_IsNumber(size_bytes))
    {
    goto end; //Numeric
    }
    }


    v1_container_image_local_var = v1_container_image_create_internal (
        names ? namesList : NULL,
        size_bytes ? size_bytes->valuedouble : 0
        );

    return v1_container_image_local_var;
end:
    if (namesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, namesList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(namesList);
        namesList = NULL;
    }
    return NULL;

}
