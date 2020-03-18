#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_secret_reference.h"



v1_secret_reference_t *v1_secret_reference_create(
    char *name,
    char *namespace
    ) {
    v1_secret_reference_t *v1_secret_reference_local_var = malloc(sizeof(v1_secret_reference_t));
    if (!v1_secret_reference_local_var) {
        return NULL;
    }
    v1_secret_reference_local_var->name = name;
    v1_secret_reference_local_var->namespace = namespace;

    return v1_secret_reference_local_var;
}


void v1_secret_reference_free(v1_secret_reference_t *v1_secret_reference) {
    if(NULL == v1_secret_reference){
        return ;
    }
    listEntry_t *listEntry;
    free(v1_secret_reference->name);
    free(v1_secret_reference->namespace);
    free(v1_secret_reference);
}

cJSON *v1_secret_reference_convertToJSON(v1_secret_reference_t *v1_secret_reference) {
    cJSON *item = cJSON_CreateObject();

    // v1_secret_reference->name
    if(v1_secret_reference->name) { 
    if(cJSON_AddStringToObject(item, "name", v1_secret_reference->name) == NULL) {
    goto fail; //String
    }
     } 


    // v1_secret_reference->namespace
    if(v1_secret_reference->namespace) { 
    if(cJSON_AddStringToObject(item, "namespace", v1_secret_reference->namespace) == NULL) {
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

v1_secret_reference_t *v1_secret_reference_parseFromJSON(cJSON *v1_secret_referenceJSON){

    v1_secret_reference_t *v1_secret_reference_local_var = NULL;

    // v1_secret_reference->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1_secret_referenceJSON, "name");
    if (name) { 
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }
    }

    // v1_secret_reference->namespace
    cJSON *namespace = cJSON_GetObjectItemCaseSensitive(v1_secret_referenceJSON, "namespace");
    if (namespace) { 
    if(!cJSON_IsString(namespace))
    {
    goto end; //String
    }
    }


    v1_secret_reference_local_var = v1_secret_reference_create (
        name ? strdup(name->valuestring) : NULL,
        namespace ? strdup(namespace->valuestring) : NULL
        );

    return v1_secret_reference_local_var;
end:
    return NULL;

}
