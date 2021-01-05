#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_bound_object_reference.h"



v1_bound_object_reference_t *v1_bound_object_reference_create(
    char *api_version,
    char *kind,
    char *name,
    char *uid
    ) {
    v1_bound_object_reference_t *v1_bound_object_reference_local_var = malloc(sizeof(v1_bound_object_reference_t));
    if (!v1_bound_object_reference_local_var) {
        return NULL;
    }
    v1_bound_object_reference_local_var->api_version = api_version;
    v1_bound_object_reference_local_var->kind = kind;
    v1_bound_object_reference_local_var->name = name;
    v1_bound_object_reference_local_var->uid = uid;

    return v1_bound_object_reference_local_var;
}


void v1_bound_object_reference_free(v1_bound_object_reference_t *v1_bound_object_reference) {
    if(NULL == v1_bound_object_reference){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_bound_object_reference->api_version) {
        free(v1_bound_object_reference->api_version);
        v1_bound_object_reference->api_version = NULL;
    }
    if (v1_bound_object_reference->kind) {
        free(v1_bound_object_reference->kind);
        v1_bound_object_reference->kind = NULL;
    }
    if (v1_bound_object_reference->name) {
        free(v1_bound_object_reference->name);
        v1_bound_object_reference->name = NULL;
    }
    if (v1_bound_object_reference->uid) {
        free(v1_bound_object_reference->uid);
        v1_bound_object_reference->uid = NULL;
    }
    free(v1_bound_object_reference);
}

cJSON *v1_bound_object_reference_convertToJSON(v1_bound_object_reference_t *v1_bound_object_reference) {
    cJSON *item = cJSON_CreateObject();

    // v1_bound_object_reference->api_version
    if(v1_bound_object_reference->api_version) { 
    if(cJSON_AddStringToObject(item, "apiVersion", v1_bound_object_reference->api_version) == NULL) {
    goto fail; //String
    }
     } 


    // v1_bound_object_reference->kind
    if(v1_bound_object_reference->kind) { 
    if(cJSON_AddStringToObject(item, "kind", v1_bound_object_reference->kind) == NULL) {
    goto fail; //String
    }
     } 


    // v1_bound_object_reference->name
    if(v1_bound_object_reference->name) { 
    if(cJSON_AddStringToObject(item, "name", v1_bound_object_reference->name) == NULL) {
    goto fail; //String
    }
     } 


    // v1_bound_object_reference->uid
    if(v1_bound_object_reference->uid) { 
    if(cJSON_AddStringToObject(item, "uid", v1_bound_object_reference->uid) == NULL) {
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

v1_bound_object_reference_t *v1_bound_object_reference_parseFromJSON(cJSON *v1_bound_object_referenceJSON){

    v1_bound_object_reference_t *v1_bound_object_reference_local_var = NULL;

    // v1_bound_object_reference->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1_bound_object_referenceJSON, "apiVersion");
    if (api_version) { 
    if(!cJSON_IsString(api_version))
    {
    goto end; //String
    }
    }

    // v1_bound_object_reference->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_bound_object_referenceJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // v1_bound_object_reference->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1_bound_object_referenceJSON, "name");
    if (name) { 
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }
    }

    // v1_bound_object_reference->uid
    cJSON *uid = cJSON_GetObjectItemCaseSensitive(v1_bound_object_referenceJSON, "uid");
    if (uid) { 
    if(!cJSON_IsString(uid))
    {
    goto end; //String
    }
    }


    v1_bound_object_reference_local_var = v1_bound_object_reference_create (
        api_version ? strdup(api_version->valuestring) : NULL,
        kind ? strdup(kind->valuestring) : NULL,
        name ? strdup(name->valuestring) : NULL,
        uid ? strdup(uid->valuestring) : NULL
        );

    return v1_bound_object_reference_local_var;
end:
    return NULL;

}
