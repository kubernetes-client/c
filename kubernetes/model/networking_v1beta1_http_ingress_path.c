#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "networking_v1beta1_http_ingress_path.h"



networking_v1beta1_http_ingress_path_t *networking_v1beta1_http_ingress_path_create(
    networking_v1beta1_ingress_backend_t *backend,
    char *path
    ) {
    networking_v1beta1_http_ingress_path_t *networking_v1beta1_http_ingress_path_local_var = malloc(sizeof(networking_v1beta1_http_ingress_path_t));
    if (!networking_v1beta1_http_ingress_path_local_var) {
        return NULL;
    }
    networking_v1beta1_http_ingress_path_local_var->backend = backend;
    networking_v1beta1_http_ingress_path_local_var->path = path;

    return networking_v1beta1_http_ingress_path_local_var;
}


void networking_v1beta1_http_ingress_path_free(networking_v1beta1_http_ingress_path_t *networking_v1beta1_http_ingress_path) {
    if(NULL == networking_v1beta1_http_ingress_path){
        return ;
    }
    listEntry_t *listEntry;
    if (networking_v1beta1_http_ingress_path->backend) {
        networking_v1beta1_ingress_backend_free(networking_v1beta1_http_ingress_path->backend);
        networking_v1beta1_http_ingress_path->backend = NULL;
    }
    if (networking_v1beta1_http_ingress_path->path) {
        free(networking_v1beta1_http_ingress_path->path);
        networking_v1beta1_http_ingress_path->path = NULL;
    }
    free(networking_v1beta1_http_ingress_path);
}

cJSON *networking_v1beta1_http_ingress_path_convertToJSON(networking_v1beta1_http_ingress_path_t *networking_v1beta1_http_ingress_path) {
    cJSON *item = cJSON_CreateObject();

    // networking_v1beta1_http_ingress_path->backend
    if (!networking_v1beta1_http_ingress_path->backend) {
        goto fail;
    }
    
    cJSON *backend_local_JSON = networking_v1beta1_ingress_backend_convertToJSON(networking_v1beta1_http_ingress_path->backend);
    if(backend_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "backend", backend_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // networking_v1beta1_http_ingress_path->path
    if(networking_v1beta1_http_ingress_path->path) { 
    if(cJSON_AddStringToObject(item, "path", networking_v1beta1_http_ingress_path->path) == NULL) {
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

networking_v1beta1_http_ingress_path_t *networking_v1beta1_http_ingress_path_parseFromJSON(cJSON *networking_v1beta1_http_ingress_pathJSON){

    networking_v1beta1_http_ingress_path_t *networking_v1beta1_http_ingress_path_local_var = NULL;

    // networking_v1beta1_http_ingress_path->backend
    cJSON *backend = cJSON_GetObjectItemCaseSensitive(networking_v1beta1_http_ingress_pathJSON, "backend");
    if (!backend) {
        goto end;
    }

    networking_v1beta1_ingress_backend_t *backend_local_nonprim = NULL;
    
    backend_local_nonprim = networking_v1beta1_ingress_backend_parseFromJSON(backend); //nonprimitive

    // networking_v1beta1_http_ingress_path->path
    cJSON *path = cJSON_GetObjectItemCaseSensitive(networking_v1beta1_http_ingress_pathJSON, "path");
    if (path) { 
    if(!cJSON_IsString(path))
    {
    goto end; //String
    }
    }


    networking_v1beta1_http_ingress_path_local_var = networking_v1beta1_http_ingress_path_create (
        backend_local_nonprim,
        path ? strdup(path->valuestring) : NULL
        );

    return networking_v1beta1_http_ingress_path_local_var;
end:
    if (backend_local_nonprim) {
        networking_v1beta1_ingress_backend_free(backend_local_nonprim);
        backend_local_nonprim = NULL;
    }
    return NULL;

}
