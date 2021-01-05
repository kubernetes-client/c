#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_local_object_reference.h"



v1_local_object_reference_t *v1_local_object_reference_create(
    char *name
    ) {
    v1_local_object_reference_t *v1_local_object_reference_local_var = malloc(sizeof(v1_local_object_reference_t));
    if (!v1_local_object_reference_local_var) {
        return NULL;
    }
    v1_local_object_reference_local_var->name = name;

    return v1_local_object_reference_local_var;
}


void v1_local_object_reference_free(v1_local_object_reference_t *v1_local_object_reference) {
    if(NULL == v1_local_object_reference){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_local_object_reference->name) {
        free(v1_local_object_reference->name);
        v1_local_object_reference->name = NULL;
    }
    free(v1_local_object_reference);
}

cJSON *v1_local_object_reference_convertToJSON(v1_local_object_reference_t *v1_local_object_reference) {
    cJSON *item = cJSON_CreateObject();

    // v1_local_object_reference->name
    if(v1_local_object_reference->name) { 
    if(cJSON_AddStringToObject(item, "name", v1_local_object_reference->name) == NULL) {
    goto fail; //String
    }
     } 

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_local_object_reference_t *v1_local_object_reference_parseFromJSON(cJSON *v1_local_object_referenceJSON){

    v1_local_object_reference_t *v1_local_object_reference_local_var = NULL;

    // v1_local_object_reference->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1_local_object_referenceJSON, "name");
    if (name) { 
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }
    }


    v1_local_object_reference_local_var = v1_local_object_reference_create (
        name ? strdup(name->valuestring) : NULL
        );

    return v1_local_object_reference_local_var;
end:
    return NULL;

}
