#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "extensions_v1beta1_http_ingress_path.h"



extensions_v1beta1_http_ingress_path_t *extensions_v1beta1_http_ingress_path_create(
    extensions_v1beta1_ingress_backend_t *backend,
    char *path
    ) {
    extensions_v1beta1_http_ingress_path_t *extensions_v1beta1_http_ingress_path_local_var = malloc(sizeof(extensions_v1beta1_http_ingress_path_t));
    if (!extensions_v1beta1_http_ingress_path_local_var) {
        return NULL;
    }
    extensions_v1beta1_http_ingress_path_local_var->backend = backend;
    extensions_v1beta1_http_ingress_path_local_var->path = path;

    return extensions_v1beta1_http_ingress_path_local_var;
}


void extensions_v1beta1_http_ingress_path_free(extensions_v1beta1_http_ingress_path_t *extensions_v1beta1_http_ingress_path) {
    if(NULL == extensions_v1beta1_http_ingress_path){
        return ;
    }
    listEntry_t *listEntry;
    if (extensions_v1beta1_http_ingress_path->backend) {
        extensions_v1beta1_ingress_backend_free(extensions_v1beta1_http_ingress_path->backend);
        extensions_v1beta1_http_ingress_path->backend = NULL;
    }
    if (extensions_v1beta1_http_ingress_path->path) {
        free(extensions_v1beta1_http_ingress_path->path);
        extensions_v1beta1_http_ingress_path->path = NULL;
    }
    free(extensions_v1beta1_http_ingress_path);
}

cJSON *extensions_v1beta1_http_ingress_path_convertToJSON(extensions_v1beta1_http_ingress_path_t *extensions_v1beta1_http_ingress_path) {
    cJSON *item = cJSON_CreateObject();

    // extensions_v1beta1_http_ingress_path->backend
    if (!extensions_v1beta1_http_ingress_path->backend) {
        goto fail;
    }
    
    cJSON *backend_local_JSON = extensions_v1beta1_ingress_backend_convertToJSON(extensions_v1beta1_http_ingress_path->backend);
    if(backend_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "backend", backend_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // extensions_v1beta1_http_ingress_path->path
    if(extensions_v1beta1_http_ingress_path->path) { 
    if(cJSON_AddStringToObject(item, "path", extensions_v1beta1_http_ingress_path->path) == NULL) {
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

extensions_v1beta1_http_ingress_path_t *extensions_v1beta1_http_ingress_path_parseFromJSON(cJSON *extensions_v1beta1_http_ingress_pathJSON){

    extensions_v1beta1_http_ingress_path_t *extensions_v1beta1_http_ingress_path_local_var = NULL;

    // extensions_v1beta1_http_ingress_path->backend
    cJSON *backend = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_http_ingress_pathJSON, "backend");
    if (!backend) {
        goto end;
    }

    extensions_v1beta1_ingress_backend_t *backend_local_nonprim = NULL;
    
    backend_local_nonprim = extensions_v1beta1_ingress_backend_parseFromJSON(backend); //nonprimitive

    // extensions_v1beta1_http_ingress_path->path
    cJSON *path = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_http_ingress_pathJSON, "path");
    if (path) { 
    if(!cJSON_IsString(path))
    {
    goto end; //String
    }
    }


    extensions_v1beta1_http_ingress_path_local_var = extensions_v1beta1_http_ingress_path_create (
        backend_local_nonprim,
        path ? strdup(path->valuestring) : NULL
        );

    return extensions_v1beta1_http_ingress_path_local_var;
end:
    if (backend_local_nonprim) {
        extensions_v1beta1_ingress_backend_free(backend_local_nonprim);
        backend_local_nonprim = NULL;
    }
    return NULL;

}
