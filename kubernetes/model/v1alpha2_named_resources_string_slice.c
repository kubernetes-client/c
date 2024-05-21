#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha2_named_resources_string_slice.h"



v1alpha2_named_resources_string_slice_t *v1alpha2_named_resources_string_slice_create(
    list_t *strings
    ) {
    v1alpha2_named_resources_string_slice_t *v1alpha2_named_resources_string_slice_local_var = malloc(sizeof(v1alpha2_named_resources_string_slice_t));
    if (!v1alpha2_named_resources_string_slice_local_var) {
        return NULL;
    }
    v1alpha2_named_resources_string_slice_local_var->strings = strings;

    return v1alpha2_named_resources_string_slice_local_var;
}


void v1alpha2_named_resources_string_slice_free(v1alpha2_named_resources_string_slice_t *v1alpha2_named_resources_string_slice) {
    if(NULL == v1alpha2_named_resources_string_slice){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha2_named_resources_string_slice->strings) {
        list_ForEach(listEntry, v1alpha2_named_resources_string_slice->strings) {
            free(listEntry->data);
        }
        list_freeList(v1alpha2_named_resources_string_slice->strings);
        v1alpha2_named_resources_string_slice->strings = NULL;
    }
    free(v1alpha2_named_resources_string_slice);
}

cJSON *v1alpha2_named_resources_string_slice_convertToJSON(v1alpha2_named_resources_string_slice_t *v1alpha2_named_resources_string_slice) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha2_named_resources_string_slice->strings
    if (!v1alpha2_named_resources_string_slice->strings) {
        goto fail;
    }
    cJSON *strings = cJSON_AddArrayToObject(item, "strings");
    if(strings == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *stringsListEntry;
    list_ForEach(stringsListEntry, v1alpha2_named_resources_string_slice->strings) {
    if(cJSON_AddStringToObject(strings, "", (char*)stringsListEntry->data) == NULL)
    {
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

v1alpha2_named_resources_string_slice_t *v1alpha2_named_resources_string_slice_parseFromJSON(cJSON *v1alpha2_named_resources_string_sliceJSON){

    v1alpha2_named_resources_string_slice_t *v1alpha2_named_resources_string_slice_local_var = NULL;

    // define the local list for v1alpha2_named_resources_string_slice->strings
    list_t *stringsList = NULL;

    // v1alpha2_named_resources_string_slice->strings
    cJSON *strings = cJSON_GetObjectItemCaseSensitive(v1alpha2_named_resources_string_sliceJSON, "strings");
    if (!strings) {
        goto end;
    }

    
    cJSON *strings_local = NULL;
    if(!cJSON_IsArray(strings)) {
        goto end;//primitive container
    }
    stringsList = list_createList();

    cJSON_ArrayForEach(strings_local, strings)
    {
        if(!cJSON_IsString(strings_local))
        {
            goto end;
        }
        list_addElement(stringsList , strdup(strings_local->valuestring));
    }


    v1alpha2_named_resources_string_slice_local_var = v1alpha2_named_resources_string_slice_create (
        stringsList
        );

    return v1alpha2_named_resources_string_slice_local_var;
end:
    if (stringsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, stringsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(stringsList);
        stringsList = NULL;
    }
    return NULL;

}
