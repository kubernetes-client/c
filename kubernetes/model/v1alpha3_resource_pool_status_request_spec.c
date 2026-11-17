#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha3_resource_pool_status_request_spec.h"



static v1alpha3_resource_pool_status_request_spec_t *v1alpha3_resource_pool_status_request_spec_create_internal(
    char *default_partition_type_attribute,
    char *driver,
    int *limit,
    char *pool_name
    ) {
    v1alpha3_resource_pool_status_request_spec_t *v1alpha3_resource_pool_status_request_spec_local_var = malloc(sizeof(v1alpha3_resource_pool_status_request_spec_t));
    if (!v1alpha3_resource_pool_status_request_spec_local_var) {
        return NULL;
    }
    memset(v1alpha3_resource_pool_status_request_spec_local_var, 0, sizeof(v1alpha3_resource_pool_status_request_spec_t));
    v1alpha3_resource_pool_status_request_spec_local_var->_library_owned = 1;
    v1alpha3_resource_pool_status_request_spec_local_var->default_partition_type_attribute = default_partition_type_attribute;
    v1alpha3_resource_pool_status_request_spec_local_var->driver = driver;
    v1alpha3_resource_pool_status_request_spec_local_var->limit = limit;
    v1alpha3_resource_pool_status_request_spec_local_var->pool_name = pool_name;
    return v1alpha3_resource_pool_status_request_spec_local_var;
}

__attribute__((deprecated)) v1alpha3_resource_pool_status_request_spec_t *v1alpha3_resource_pool_status_request_spec_create(
    char *default_partition_type_attribute,
    char *driver,
    int *limit,
    char *pool_name
    ) {
    int *limit_copy = NULL;
    if (limit) {
        limit_copy = malloc(sizeof(int));
        if (limit_copy) *limit_copy = *limit;
    }
    v1alpha3_resource_pool_status_request_spec_t *result = v1alpha3_resource_pool_status_request_spec_create_internal (
        default_partition_type_attribute,
        driver,
        limit_copy,
        pool_name
        );
    if (!result) {
        free(limit_copy);
    }
    return result;
}

void v1alpha3_resource_pool_status_request_spec_free(v1alpha3_resource_pool_status_request_spec_t *v1alpha3_resource_pool_status_request_spec) {
    if(NULL == v1alpha3_resource_pool_status_request_spec){
        return ;
    }
    if(v1alpha3_resource_pool_status_request_spec->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1alpha3_resource_pool_status_request_spec_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha3_resource_pool_status_request_spec->default_partition_type_attribute) {
        free(v1alpha3_resource_pool_status_request_spec->default_partition_type_attribute);
        v1alpha3_resource_pool_status_request_spec->default_partition_type_attribute = NULL;
    }
    if (v1alpha3_resource_pool_status_request_spec->driver) {
        free(v1alpha3_resource_pool_status_request_spec->driver);
        v1alpha3_resource_pool_status_request_spec->driver = NULL;
    }
    if (v1alpha3_resource_pool_status_request_spec->limit) {
        free(v1alpha3_resource_pool_status_request_spec->limit);
        v1alpha3_resource_pool_status_request_spec->limit = NULL;
    }
    if (v1alpha3_resource_pool_status_request_spec->pool_name) {
        free(v1alpha3_resource_pool_status_request_spec->pool_name);
        v1alpha3_resource_pool_status_request_spec->pool_name = NULL;
    }
    free(v1alpha3_resource_pool_status_request_spec);
}

cJSON *v1alpha3_resource_pool_status_request_spec_convertToJSON(v1alpha3_resource_pool_status_request_spec_t *v1alpha3_resource_pool_status_request_spec) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha3_resource_pool_status_request_spec->default_partition_type_attribute
    if(v1alpha3_resource_pool_status_request_spec->default_partition_type_attribute) {
    if(cJSON_AddStringToObject(item, "defaultPartitionTypeAttribute", v1alpha3_resource_pool_status_request_spec->default_partition_type_attribute) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha3_resource_pool_status_request_spec->driver
    if (!v1alpha3_resource_pool_status_request_spec->driver) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "driver", v1alpha3_resource_pool_status_request_spec->driver) == NULL) {
    goto fail; //String
    }


    // v1alpha3_resource_pool_status_request_spec->limit
    if(v1alpha3_resource_pool_status_request_spec->limit) {
    if(cJSON_AddNumberToObject(item, "limit", *v1alpha3_resource_pool_status_request_spec->limit) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1alpha3_resource_pool_status_request_spec->pool_name
    if(v1alpha3_resource_pool_status_request_spec->pool_name) {
    if(cJSON_AddStringToObject(item, "poolName", v1alpha3_resource_pool_status_request_spec->pool_name) == NULL) {
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

v1alpha3_resource_pool_status_request_spec_t *v1alpha3_resource_pool_status_request_spec_parseFromJSON(cJSON *v1alpha3_resource_pool_status_request_specJSON){

    v1alpha3_resource_pool_status_request_spec_t *v1alpha3_resource_pool_status_request_spec_local_var = NULL;

    char *default_partition_type_attribute_local_str = NULL;

    char *driver_local_str = NULL;

    // define the local variable for v1alpha3_resource_pool_status_request_spec->limit
    int *limit_local_var = NULL;

    char *pool_name_local_str = NULL;

    // v1alpha3_resource_pool_status_request_spec->default_partition_type_attribute
    cJSON *default_partition_type_attribute = cJSON_GetObjectItemCaseSensitive(v1alpha3_resource_pool_status_request_specJSON, "defaultPartitionTypeAttribute");
    if (cJSON_IsNull(default_partition_type_attribute)) {
        default_partition_type_attribute = NULL;
    }
    if (default_partition_type_attribute) { 
    if(!cJSON_IsString(default_partition_type_attribute) && !cJSON_IsNull(default_partition_type_attribute))
    {
    goto end; //String
    }
    }

    // v1alpha3_resource_pool_status_request_spec->driver
    cJSON *driver = cJSON_GetObjectItemCaseSensitive(v1alpha3_resource_pool_status_request_specJSON, "driver");
    if (cJSON_IsNull(driver)) {
        driver = NULL;
    }
    if (!driver) {
        goto end;
    }

    
    if(!cJSON_IsString(driver))
    {
    goto end; //String
    }

    // v1alpha3_resource_pool_status_request_spec->limit
    cJSON *limit = cJSON_GetObjectItemCaseSensitive(v1alpha3_resource_pool_status_request_specJSON, "limit");
    if (cJSON_IsNull(limit)) {
        limit = NULL;
    }
    if (limit) { 
    if(!cJSON_IsNumber(limit))
    {
    goto end; //Numeric
    }
    limit_local_var = malloc(sizeof(int));
    if(!limit_local_var)
    {
        goto end;
    }
    *limit_local_var = limit->valuedouble;
    }

    // v1alpha3_resource_pool_status_request_spec->pool_name
    cJSON *pool_name = cJSON_GetObjectItemCaseSensitive(v1alpha3_resource_pool_status_request_specJSON, "poolName");
    if (cJSON_IsNull(pool_name)) {
        pool_name = NULL;
    }
    if (pool_name) { 
    if(!cJSON_IsString(pool_name) && !cJSON_IsNull(pool_name))
    {
    goto end; //String
    }
    }


    if (default_partition_type_attribute && !cJSON_IsNull(default_partition_type_attribute)) default_partition_type_attribute_local_str = strdup(default_partition_type_attribute->valuestring);
    if (driver && !cJSON_IsNull(driver)) driver_local_str = strdup(driver->valuestring);
    if (pool_name && !cJSON_IsNull(pool_name)) pool_name_local_str = strdup(pool_name->valuestring);

    v1alpha3_resource_pool_status_request_spec_local_var = v1alpha3_resource_pool_status_request_spec_create_internal (
        default_partition_type_attribute_local_str,
        driver_local_str,
        limit_local_var,
        pool_name_local_str
        );

    if (!v1alpha3_resource_pool_status_request_spec_local_var) {
        goto end;
    }

    return v1alpha3_resource_pool_status_request_spec_local_var;
end:
    if (default_partition_type_attribute_local_str) {
        free(default_partition_type_attribute_local_str);
        default_partition_type_attribute_local_str = NULL;
    }
    if (driver_local_str) {
        free(driver_local_str);
        driver_local_str = NULL;
    }
    if (limit_local_var) {
        free(limit_local_var);
        limit_local_var = NULL;
    }
    if (pool_name_local_str) {
        free(pool_name_local_str);
        pool_name_local_str = NULL;
    }
    return NULL;

}
