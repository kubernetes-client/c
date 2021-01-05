#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_non_resource_attributes.h"



v1_non_resource_attributes_t *v1_non_resource_attributes_create(
    char *path,
    char *verb
    ) {
    v1_non_resource_attributes_t *v1_non_resource_attributes_local_var = malloc(sizeof(v1_non_resource_attributes_t));
    if (!v1_non_resource_attributes_local_var) {
        return NULL;
    }
    v1_non_resource_attributes_local_var->path = path;
    v1_non_resource_attributes_local_var->verb = verb;

    return v1_non_resource_attributes_local_var;
}


void v1_non_resource_attributes_free(v1_non_resource_attributes_t *v1_non_resource_attributes) {
    if(NULL == v1_non_resource_attributes){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_non_resource_attributes->path) {
        free(v1_non_resource_attributes->path);
        v1_non_resource_attributes->path = NULL;
    }
    if (v1_non_resource_attributes->verb) {
        free(v1_non_resource_attributes->verb);
        v1_non_resource_attributes->verb = NULL;
    }
    free(v1_non_resource_attributes);
}

cJSON *v1_non_resource_attributes_convertToJSON(v1_non_resource_attributes_t *v1_non_resource_attributes) {
    cJSON *item = cJSON_CreateObject();

    // v1_non_resource_attributes->path
    if(v1_non_resource_attributes->path) { 
    if(cJSON_AddStringToObject(item, "path", v1_non_resource_attributes->path) == NULL) {
    goto fail; //String
    }
     } 


    // v1_non_resource_attributes->verb
    if(v1_non_resource_attributes->verb) { 
    if(cJSON_AddStringToObject(item, "verb", v1_non_resource_attributes->verb) == NULL) {
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

v1_non_resource_attributes_t *v1_non_resource_attributes_parseFromJSON(cJSON *v1_non_resource_attributesJSON){

    v1_non_resource_attributes_t *v1_non_resource_attributes_local_var = NULL;

    // v1_non_resource_attributes->path
    cJSON *path = cJSON_GetObjectItemCaseSensitive(v1_non_resource_attributesJSON, "path");
    if (path) { 
    if(!cJSON_IsString(path))
    {
    goto end; //String
    }
    }

    // v1_non_resource_attributes->verb
    cJSON *verb = cJSON_GetObjectItemCaseSensitive(v1_non_resource_attributesJSON, "verb");
    if (verb) { 
    if(!cJSON_IsString(verb))
    {
    goto end; //String
    }
    }


    v1_non_resource_attributes_local_var = v1_non_resource_attributes_create (
        path ? strdup(path->valuestring) : NULL,
        verb ? strdup(verb->valuestring) : NULL
        );

    return v1_non_resource_attributes_local_var;
end:
    return NULL;

}
