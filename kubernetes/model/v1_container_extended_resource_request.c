#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_container_extended_resource_request.h"



static v1_container_extended_resource_request_t *v1_container_extended_resource_request_create_internal(
    char *container_name,
    char *request_name,
    char *resource_name
    ) {
    v1_container_extended_resource_request_t *v1_container_extended_resource_request_local_var = malloc(sizeof(v1_container_extended_resource_request_t));
    if (!v1_container_extended_resource_request_local_var) {
        return NULL;
    }
    memset(v1_container_extended_resource_request_local_var, 0, sizeof(v1_container_extended_resource_request_t));
    v1_container_extended_resource_request_local_var->_library_owned = 1;
    v1_container_extended_resource_request_local_var->container_name = container_name;
    v1_container_extended_resource_request_local_var->request_name = request_name;
    v1_container_extended_resource_request_local_var->resource_name = resource_name;
    return v1_container_extended_resource_request_local_var;
}

__attribute__((deprecated)) v1_container_extended_resource_request_t *v1_container_extended_resource_request_create(
    char *container_name,
    char *request_name,
    char *resource_name
    ) {
    v1_container_extended_resource_request_t *result = v1_container_extended_resource_request_create_internal (
        container_name,
        request_name,
        resource_name
        );
    if (!result) {
    }
    return result;
}

void v1_container_extended_resource_request_free(v1_container_extended_resource_request_t *v1_container_extended_resource_request) {
    if(NULL == v1_container_extended_resource_request){
        return ;
    }
    if(v1_container_extended_resource_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_container_extended_resource_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_container_extended_resource_request->container_name) {
        free(v1_container_extended_resource_request->container_name);
        v1_container_extended_resource_request->container_name = NULL;
    }
    if (v1_container_extended_resource_request->request_name) {
        free(v1_container_extended_resource_request->request_name);
        v1_container_extended_resource_request->request_name = NULL;
    }
    if (v1_container_extended_resource_request->resource_name) {
        free(v1_container_extended_resource_request->resource_name);
        v1_container_extended_resource_request->resource_name = NULL;
    }
    free(v1_container_extended_resource_request);
}

cJSON *v1_container_extended_resource_request_convertToJSON(v1_container_extended_resource_request_t *v1_container_extended_resource_request) {
    cJSON *item = cJSON_CreateObject();

    // v1_container_extended_resource_request->container_name
    if (!v1_container_extended_resource_request->container_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "containerName", v1_container_extended_resource_request->container_name) == NULL) {
    goto fail; //String
    }


    // v1_container_extended_resource_request->request_name
    if (!v1_container_extended_resource_request->request_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "requestName", v1_container_extended_resource_request->request_name) == NULL) {
    goto fail; //String
    }


    // v1_container_extended_resource_request->resource_name
    if (!v1_container_extended_resource_request->resource_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "resourceName", v1_container_extended_resource_request->resource_name) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_container_extended_resource_request_t *v1_container_extended_resource_request_parseFromJSON(cJSON *v1_container_extended_resource_requestJSON){

    v1_container_extended_resource_request_t *v1_container_extended_resource_request_local_var = NULL;

    char *container_name_local_str = NULL;

    char *request_name_local_str = NULL;

    char *resource_name_local_str = NULL;

    // v1_container_extended_resource_request->container_name
    cJSON *container_name = cJSON_GetObjectItemCaseSensitive(v1_container_extended_resource_requestJSON, "containerName");
    if (cJSON_IsNull(container_name)) {
        container_name = NULL;
    }
    if (!container_name) {
        goto end;
    }

    
    if(!cJSON_IsString(container_name))
    {
    goto end; //String
    }

    // v1_container_extended_resource_request->request_name
    cJSON *request_name = cJSON_GetObjectItemCaseSensitive(v1_container_extended_resource_requestJSON, "requestName");
    if (cJSON_IsNull(request_name)) {
        request_name = NULL;
    }
    if (!request_name) {
        goto end;
    }

    
    if(!cJSON_IsString(request_name))
    {
    goto end; //String
    }

    // v1_container_extended_resource_request->resource_name
    cJSON *resource_name = cJSON_GetObjectItemCaseSensitive(v1_container_extended_resource_requestJSON, "resourceName");
    if (cJSON_IsNull(resource_name)) {
        resource_name = NULL;
    }
    if (!resource_name) {
        goto end;
    }

    
    if(!cJSON_IsString(resource_name))
    {
    goto end; //String
    }


    if (container_name && !cJSON_IsNull(container_name)) container_name_local_str = strdup(container_name->valuestring);
    if (request_name && !cJSON_IsNull(request_name)) request_name_local_str = strdup(request_name->valuestring);
    if (resource_name && !cJSON_IsNull(resource_name)) resource_name_local_str = strdup(resource_name->valuestring);

    v1_container_extended_resource_request_local_var = v1_container_extended_resource_request_create_internal (
        container_name_local_str,
        request_name_local_str,
        resource_name_local_str
        );

    if (!v1_container_extended_resource_request_local_var) {
        goto end;
    }

    return v1_container_extended_resource_request_local_var;
end:
    if (container_name_local_str) {
        free(container_name_local_str);
        container_name_local_str = NULL;
    }
    if (request_name_local_str) {
        free(request_name_local_str);
        request_name_local_str = NULL;
    }
    if (resource_name_local_str) {
        free(resource_name_local_str);
        resource_name_local_str = NULL;
    }
    return NULL;

}
