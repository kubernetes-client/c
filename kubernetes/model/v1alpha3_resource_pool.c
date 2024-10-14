#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha3_resource_pool.h"



v1alpha3_resource_pool_t *v1alpha3_resource_pool_create(
    long generation,
    char *name,
    long resource_slice_count
    ) {
    v1alpha3_resource_pool_t *v1alpha3_resource_pool_local_var = malloc(sizeof(v1alpha3_resource_pool_t));
    if (!v1alpha3_resource_pool_local_var) {
        return NULL;
    }
    v1alpha3_resource_pool_local_var->generation = generation;
    v1alpha3_resource_pool_local_var->name = name;
    v1alpha3_resource_pool_local_var->resource_slice_count = resource_slice_count;

    return v1alpha3_resource_pool_local_var;
}


void v1alpha3_resource_pool_free(v1alpha3_resource_pool_t *v1alpha3_resource_pool) {
    if(NULL == v1alpha3_resource_pool){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha3_resource_pool->name) {
        free(v1alpha3_resource_pool->name);
        v1alpha3_resource_pool->name = NULL;
    }
    free(v1alpha3_resource_pool);
}

cJSON *v1alpha3_resource_pool_convertToJSON(v1alpha3_resource_pool_t *v1alpha3_resource_pool) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha3_resource_pool->generation
    if (!v1alpha3_resource_pool->generation) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "generation", v1alpha3_resource_pool->generation) == NULL) {
    goto fail; //Numeric
    }


    // v1alpha3_resource_pool->name
    if (!v1alpha3_resource_pool->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", v1alpha3_resource_pool->name) == NULL) {
    goto fail; //String
    }


    // v1alpha3_resource_pool->resource_slice_count
    if (!v1alpha3_resource_pool->resource_slice_count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "resourceSliceCount", v1alpha3_resource_pool->resource_slice_count) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1alpha3_resource_pool_t *v1alpha3_resource_pool_parseFromJSON(cJSON *v1alpha3_resource_poolJSON){

    v1alpha3_resource_pool_t *v1alpha3_resource_pool_local_var = NULL;

    // v1alpha3_resource_pool->generation
    cJSON *generation = cJSON_GetObjectItemCaseSensitive(v1alpha3_resource_poolJSON, "generation");
    if (!generation) {
        goto end;
    }

    
    if(!cJSON_IsNumber(generation))
    {
    goto end; //Numeric
    }

    // v1alpha3_resource_pool->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1alpha3_resource_poolJSON, "name");
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // v1alpha3_resource_pool->resource_slice_count
    cJSON *resource_slice_count = cJSON_GetObjectItemCaseSensitive(v1alpha3_resource_poolJSON, "resourceSliceCount");
    if (!resource_slice_count) {
        goto end;
    }

    
    if(!cJSON_IsNumber(resource_slice_count))
    {
    goto end; //Numeric
    }


    v1alpha3_resource_pool_local_var = v1alpha3_resource_pool_create (
        generation->valuedouble,
        strdup(name->valuestring),
        resource_slice_count->valuedouble
        );

    return v1alpha3_resource_pool_local_var;
end:
    return NULL;

}
