#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_resource_pool.h"



static v1_resource_pool_t *v1_resource_pool_create_internal(
    long generation,
    char *name,
    long resource_slice_count
    ) {
    v1_resource_pool_t *v1_resource_pool_local_var = malloc(sizeof(v1_resource_pool_t));
    if (!v1_resource_pool_local_var) {
        return NULL;
    }
    v1_resource_pool_local_var->generation = generation;
    v1_resource_pool_local_var->name = name;
    v1_resource_pool_local_var->resource_slice_count = resource_slice_count;

    v1_resource_pool_local_var->_library_owned = 1;
    return v1_resource_pool_local_var;
}

__attribute__((deprecated)) v1_resource_pool_t *v1_resource_pool_create(
    long generation,
    char *name,
    long resource_slice_count
    ) {
    return v1_resource_pool_create_internal (
        generation,
        name,
        resource_slice_count
        );
}

void v1_resource_pool_free(v1_resource_pool_t *v1_resource_pool) {
    if(NULL == v1_resource_pool){
        return ;
    }
    if(v1_resource_pool->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_resource_pool_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_resource_pool->name) {
        free(v1_resource_pool->name);
        v1_resource_pool->name = NULL;
    }
    free(v1_resource_pool);
}

cJSON *v1_resource_pool_convertToJSON(v1_resource_pool_t *v1_resource_pool) {
    cJSON *item = cJSON_CreateObject();

    // v1_resource_pool->generation
    if (!v1_resource_pool->generation) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "generation", v1_resource_pool->generation) == NULL) {
    goto fail; //Numeric
    }


    // v1_resource_pool->name
    if (!v1_resource_pool->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", v1_resource_pool->name) == NULL) {
    goto fail; //String
    }


    // v1_resource_pool->resource_slice_count
    if (!v1_resource_pool->resource_slice_count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "resourceSliceCount", v1_resource_pool->resource_slice_count) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_resource_pool_t *v1_resource_pool_parseFromJSON(cJSON *v1_resource_poolJSON){

    v1_resource_pool_t *v1_resource_pool_local_var = NULL;

    // v1_resource_pool->generation
    cJSON *generation = cJSON_GetObjectItemCaseSensitive(v1_resource_poolJSON, "generation");
    if (cJSON_IsNull(generation)) {
        generation = NULL;
    }
    if (!generation) {
        goto end;
    }

    
    if(!cJSON_IsNumber(generation))
    {
    goto end; //Numeric
    }

    // v1_resource_pool->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1_resource_poolJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // v1_resource_pool->resource_slice_count
    cJSON *resource_slice_count = cJSON_GetObjectItemCaseSensitive(v1_resource_poolJSON, "resourceSliceCount");
    if (cJSON_IsNull(resource_slice_count)) {
        resource_slice_count = NULL;
    }
    if (!resource_slice_count) {
        goto end;
    }

    
    if(!cJSON_IsNumber(resource_slice_count))
    {
    goto end; //Numeric
    }


    v1_resource_pool_local_var = v1_resource_pool_create_internal (
        generation->valuedouble,
        strdup(name->valuestring),
        resource_slice_count->valuedouble
        );

    return v1_resource_pool_local_var;
end:
    return NULL;

}
