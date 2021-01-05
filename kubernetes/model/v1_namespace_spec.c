#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_namespace_spec.h"



v1_namespace_spec_t *v1_namespace_spec_create(
    list_t *finalizers
    ) {
    v1_namespace_spec_t *v1_namespace_spec_local_var = malloc(sizeof(v1_namespace_spec_t));
    if (!v1_namespace_spec_local_var) {
        return NULL;
    }
    v1_namespace_spec_local_var->finalizers = finalizers;

    return v1_namespace_spec_local_var;
}


void v1_namespace_spec_free(v1_namespace_spec_t *v1_namespace_spec) {
    if(NULL == v1_namespace_spec){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_namespace_spec->finalizers) {
        list_ForEach(listEntry, v1_namespace_spec->finalizers) {
            free(listEntry->data);
        }
        list_free(v1_namespace_spec->finalizers);
        v1_namespace_spec->finalizers = NULL;
    }
    free(v1_namespace_spec);
}

cJSON *v1_namespace_spec_convertToJSON(v1_namespace_spec_t *v1_namespace_spec) {
    cJSON *item = cJSON_CreateObject();

    // v1_namespace_spec->finalizers
    if(v1_namespace_spec->finalizers) { 
    cJSON *finalizers = cJSON_AddArrayToObject(item, "finalizers");
    if(finalizers == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *finalizersListEntry;
    list_ForEach(finalizersListEntry, v1_namespace_spec->finalizers) {
    if(cJSON_AddStringToObject(finalizers, "", (char*)finalizersListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_namespace_spec_t *v1_namespace_spec_parseFromJSON(cJSON *v1_namespace_specJSON){

    v1_namespace_spec_t *v1_namespace_spec_local_var = NULL;

    // v1_namespace_spec->finalizers
    cJSON *finalizers = cJSON_GetObjectItemCaseSensitive(v1_namespace_specJSON, "finalizers");
    list_t *finalizersList;
    if (finalizers) { 
    cJSON *finalizers_local;
    if(!cJSON_IsArray(finalizers)) {
        goto end;//primitive container
    }
    finalizersList = list_create();

    cJSON_ArrayForEach(finalizers_local, finalizers)
    {
        if(!cJSON_IsString(finalizers_local))
        {
            goto end;
        }
        list_addElement(finalizersList , strdup(finalizers_local->valuestring));
    }
    }


    v1_namespace_spec_local_var = v1_namespace_spec_create (
        finalizers ? finalizersList : NULL
        );

    return v1_namespace_spec_local_var;
end:
    return NULL;

}
