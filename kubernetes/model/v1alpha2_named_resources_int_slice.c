#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha2_named_resources_int_slice.h"



v1alpha2_named_resources_int_slice_t *v1alpha2_named_resources_int_slice_create(
    list_t *ints
    ) {
    v1alpha2_named_resources_int_slice_t *v1alpha2_named_resources_int_slice_local_var = malloc(sizeof(v1alpha2_named_resources_int_slice_t));
    if (!v1alpha2_named_resources_int_slice_local_var) {
        return NULL;
    }
    v1alpha2_named_resources_int_slice_local_var->ints = ints;

    return v1alpha2_named_resources_int_slice_local_var;
}


void v1alpha2_named_resources_int_slice_free(v1alpha2_named_resources_int_slice_t *v1alpha2_named_resources_int_slice) {
    if(NULL == v1alpha2_named_resources_int_slice){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha2_named_resources_int_slice->ints) {
        list_ForEach(listEntry, v1alpha2_named_resources_int_slice->ints) {
            free(listEntry->data);
        }
        list_freeList(v1alpha2_named_resources_int_slice->ints);
        v1alpha2_named_resources_int_slice->ints = NULL;
    }
    free(v1alpha2_named_resources_int_slice);
}

cJSON *v1alpha2_named_resources_int_slice_convertToJSON(v1alpha2_named_resources_int_slice_t *v1alpha2_named_resources_int_slice) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha2_named_resources_int_slice->ints
    if (!v1alpha2_named_resources_int_slice->ints) {
        goto fail;
    }
    cJSON *ints = cJSON_AddArrayToObject(item, "ints");
    if(ints == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *intsListEntry;
    list_ForEach(intsListEntry, v1alpha2_named_resources_int_slice->ints) {
    if(cJSON_AddNumberToObject(ints, "", *(double *)intsListEntry->data) == NULL)
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

v1alpha2_named_resources_int_slice_t *v1alpha2_named_resources_int_slice_parseFromJSON(cJSON *v1alpha2_named_resources_int_sliceJSON){

    v1alpha2_named_resources_int_slice_t *v1alpha2_named_resources_int_slice_local_var = NULL;

    // define the local list for v1alpha2_named_resources_int_slice->ints
    list_t *intsList = NULL;

    // v1alpha2_named_resources_int_slice->ints
    cJSON *ints = cJSON_GetObjectItemCaseSensitive(v1alpha2_named_resources_int_sliceJSON, "ints");
    if (!ints) {
        goto end;
    }

    
    cJSON *ints_local = NULL;
    if(!cJSON_IsArray(ints)) {
        goto end;//primitive container
    }
    intsList = list_createList();

    cJSON_ArrayForEach(ints_local, ints)
    {
        if(!cJSON_IsNumber(ints_local))
        {
            goto end;
        }
        double *ints_local_value = (double *)calloc(1, sizeof(double));
        if(!ints_local_value)
        {
            goto end;
        }
        *ints_local_value = ints_local->valuedouble;
        list_addElement(intsList , ints_local_value);
    }


    v1alpha2_named_resources_int_slice_local_var = v1alpha2_named_resources_int_slice_create (
        intsList
        );

    return v1alpha2_named_resources_int_slice_local_var;
end:
    if (intsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, intsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(intsList);
        intsList = NULL;
    }
    return NULL;

}
