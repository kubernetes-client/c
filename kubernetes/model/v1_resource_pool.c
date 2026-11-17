#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_resource_pool.h"



static v1_resource_pool_t *v1_resource_pool_create_internal(
    long *generation,
    char *name,
    long *resource_slice_count
    ) {
    v1_resource_pool_t *v1_resource_pool_local_var = malloc(sizeof(v1_resource_pool_t));
    if (!v1_resource_pool_local_var) {
        return NULL;
    }
    memset(v1_resource_pool_local_var, 0, sizeof(v1_resource_pool_t));
    v1_resource_pool_local_var->_library_owned = 1;
    v1_resource_pool_local_var->generation = generation;
    v1_resource_pool_local_var->name = name;
    v1_resource_pool_local_var->resource_slice_count = resource_slice_count;
    return v1_resource_pool_local_var;
}

__attribute__((deprecated)) v1_resource_pool_t *v1_resource_pool_create(
    long *generation,
    char *name,
    long *resource_slice_count
    ) {
    long *generation_copy = NULL;
    if (generation) {
        generation_copy = malloc(sizeof(long));
        if (generation_copy) *generation_copy = *generation;
    }
    long *resource_slice_count_copy = NULL;
    if (resource_slice_count) {
        resource_slice_count_copy = malloc(sizeof(long));
        if (resource_slice_count_copy) *resource_slice_count_copy = *resource_slice_count;
    }
    v1_resource_pool_t *result = v1_resource_pool_create_internal (
        generation_copy,
        name,
        resource_slice_count_copy
        );
    if (!result) {
        free(generation_copy);
        free(resource_slice_count_copy);
    }
    return result;
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
    if (v1_resource_pool->generation) {
        free(v1_resource_pool->generation);
        v1_resource_pool->generation = NULL;
    }
    if (v1_resource_pool->name) {
        free(v1_resource_pool->name);
        v1_resource_pool->name = NULL;
    }
    if (v1_resource_pool->resource_slice_count) {
        free(v1_resource_pool->resource_slice_count);
        v1_resource_pool->resource_slice_count = NULL;
    }
    free(v1_resource_pool);
}

cJSON *v1_resource_pool_convertToJSON(v1_resource_pool_t *v1_resource_pool) {
    cJSON *item = cJSON_CreateObject();

    // v1_resource_pool->generation
    if (!v1_resource_pool->generation) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "generation", *v1_resource_pool->generation) == NULL) {
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
    if(cJSON_AddNumberToObject(item, "resourceSliceCount", *v1_resource_pool->resource_slice_count) == NULL) {
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

    // define the local variable for v1_resource_pool->generation
    long *generation_local_var = NULL;

    char *name_local_str = NULL;

    // define the local variable for v1_resource_pool->resource_slice_count
    long *resource_slice_count_local_var = NULL;

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
    generation_local_var = malloc(sizeof(long));
    if(!generation_local_var)
    {
        goto end;
    }
    *generation_local_var = generation->valuedouble;

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
    resource_slice_count_local_var = malloc(sizeof(long));
    if(!resource_slice_count_local_var)
    {
        goto end;
    }
    *resource_slice_count_local_var = resource_slice_count->valuedouble;


    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);

    v1_resource_pool_local_var = v1_resource_pool_create_internal (
        generation_local_var,
        name_local_str,
        resource_slice_count_local_var
        );

    if (!v1_resource_pool_local_var) {
        goto end;
    }

    return v1_resource_pool_local_var;
end:
    if (generation_local_var) {
        free(generation_local_var);
        generation_local_var = NULL;
    }
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    if (resource_slice_count_local_var) {
        free(resource_slice_count_local_var);
        resource_slice_count_local_var = NULL;
    }
    return NULL;

}
