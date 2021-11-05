#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_http_ingress_path.h"



v1_http_ingress_path_t *v1_http_ingress_path_create(
    v1_ingress_backend_t *backend,
    char *path,
    char *path_type
    ) {
    v1_http_ingress_path_t *v1_http_ingress_path_local_var = malloc(sizeof(v1_http_ingress_path_t));
    if (!v1_http_ingress_path_local_var) {
        return NULL;
    }
    v1_http_ingress_path_local_var->backend = backend;
    v1_http_ingress_path_local_var->path = path;
    v1_http_ingress_path_local_var->path_type = path_type;

    return v1_http_ingress_path_local_var;
}


void v1_http_ingress_path_free(v1_http_ingress_path_t *v1_http_ingress_path) {
    if(NULL == v1_http_ingress_path){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_http_ingress_path->backend) {
        v1_ingress_backend_free(v1_http_ingress_path->backend);
        v1_http_ingress_path->backend = NULL;
    }
    if (v1_http_ingress_path->path) {
        free(v1_http_ingress_path->path);
        v1_http_ingress_path->path = NULL;
    }
    if (v1_http_ingress_path->path_type) {
        free(v1_http_ingress_path->path_type);
        v1_http_ingress_path->path_type = NULL;
    }
    free(v1_http_ingress_path);
}

cJSON *v1_http_ingress_path_convertToJSON(v1_http_ingress_path_t *v1_http_ingress_path) {
    cJSON *item = cJSON_CreateObject();

    // v1_http_ingress_path->backend
    if (!v1_http_ingress_path->backend) {
        goto fail;
    }
    
    cJSON *backend_local_JSON = v1_ingress_backend_convertToJSON(v1_http_ingress_path->backend);
    if(backend_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "backend", backend_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // v1_http_ingress_path->path
    if(v1_http_ingress_path->path) { 
    if(cJSON_AddStringToObject(item, "path", v1_http_ingress_path->path) == NULL) {
    goto fail; //String
    }
     } 


    // v1_http_ingress_path->path_type
    if (!v1_http_ingress_path->path_type) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "pathType", v1_http_ingress_path->path_type) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_http_ingress_path_t *v1_http_ingress_path_parseFromJSON(cJSON *v1_http_ingress_pathJSON){

    v1_http_ingress_path_t *v1_http_ingress_path_local_var = NULL;

    // define the local variable for v1_http_ingress_path->backend
    v1_ingress_backend_t *backend_local_nonprim = NULL;

    // v1_http_ingress_path->backend
    cJSON *backend = cJSON_GetObjectItemCaseSensitive(v1_http_ingress_pathJSON, "backend");
    if (!backend) {
        goto end;
    }

    
    backend_local_nonprim = v1_ingress_backend_parseFromJSON(backend); //nonprimitive

    // v1_http_ingress_path->path
    cJSON *path = cJSON_GetObjectItemCaseSensitive(v1_http_ingress_pathJSON, "path");
    if (path) { 
    if(!cJSON_IsString(path))
    {
    goto end; //String
    }
    }

    // v1_http_ingress_path->path_type
    cJSON *path_type = cJSON_GetObjectItemCaseSensitive(v1_http_ingress_pathJSON, "pathType");
    if (!path_type) {
        goto end;
    }

    
    if(!cJSON_IsString(path_type))
    {
    goto end; //String
    }


    v1_http_ingress_path_local_var = v1_http_ingress_path_create (
        backend_local_nonprim,
        path ? strdup(path->valuestring) : NULL,
        strdup(path_type->valuestring)
        );

    return v1_http_ingress_path_local_var;
end:
    if (backend_local_nonprim) {
        v1_ingress_backend_free(backend_local_nonprim);
        backend_local_nonprim = NULL;
    }
    return NULL;

}
