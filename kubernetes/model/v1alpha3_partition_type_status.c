#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha3_partition_type_status.h"



static v1alpha3_partition_type_status_t *v1alpha3_partition_type_status_create_internal(
    int *allocatable,
    char *attribute,
    int *total,
    char *type
    ) {
    v1alpha3_partition_type_status_t *v1alpha3_partition_type_status_local_var = malloc(sizeof(v1alpha3_partition_type_status_t));
    if (!v1alpha3_partition_type_status_local_var) {
        return NULL;
    }
    memset(v1alpha3_partition_type_status_local_var, 0, sizeof(v1alpha3_partition_type_status_t));
    v1alpha3_partition_type_status_local_var->_library_owned = 1;
    v1alpha3_partition_type_status_local_var->allocatable = allocatable;
    v1alpha3_partition_type_status_local_var->attribute = attribute;
    v1alpha3_partition_type_status_local_var->total = total;
    v1alpha3_partition_type_status_local_var->type = type;
    return v1alpha3_partition_type_status_local_var;
}

__attribute__((deprecated)) v1alpha3_partition_type_status_t *v1alpha3_partition_type_status_create(
    int *allocatable,
    char *attribute,
    int *total,
    char *type
    ) {
    int *allocatable_copy = NULL;
    if (allocatable) {
        allocatable_copy = malloc(sizeof(int));
        if (allocatable_copy) *allocatable_copy = *allocatable;
    }
    int *total_copy = NULL;
    if (total) {
        total_copy = malloc(sizeof(int));
        if (total_copy) *total_copy = *total;
    }
    v1alpha3_partition_type_status_t *result = v1alpha3_partition_type_status_create_internal (
        allocatable_copy,
        attribute,
        total_copy,
        type
        );
    if (!result) {
        free(allocatable_copy);
        free(total_copy);
    }
    return result;
}

void v1alpha3_partition_type_status_free(v1alpha3_partition_type_status_t *v1alpha3_partition_type_status) {
    if(NULL == v1alpha3_partition_type_status){
        return ;
    }
    if(v1alpha3_partition_type_status->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1alpha3_partition_type_status_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha3_partition_type_status->allocatable) {
        free(v1alpha3_partition_type_status->allocatable);
        v1alpha3_partition_type_status->allocatable = NULL;
    }
    if (v1alpha3_partition_type_status->attribute) {
        free(v1alpha3_partition_type_status->attribute);
        v1alpha3_partition_type_status->attribute = NULL;
    }
    if (v1alpha3_partition_type_status->total) {
        free(v1alpha3_partition_type_status->total);
        v1alpha3_partition_type_status->total = NULL;
    }
    if (v1alpha3_partition_type_status->type) {
        free(v1alpha3_partition_type_status->type);
        v1alpha3_partition_type_status->type = NULL;
    }
    free(v1alpha3_partition_type_status);
}

cJSON *v1alpha3_partition_type_status_convertToJSON(v1alpha3_partition_type_status_t *v1alpha3_partition_type_status) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha3_partition_type_status->allocatable
    if (!v1alpha3_partition_type_status->allocatable) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "allocatable", *v1alpha3_partition_type_status->allocatable) == NULL) {
    goto fail; //Numeric
    }


    // v1alpha3_partition_type_status->attribute
    if (!v1alpha3_partition_type_status->attribute) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "attribute", v1alpha3_partition_type_status->attribute) == NULL) {
    goto fail; //String
    }


    // v1alpha3_partition_type_status->total
    if (!v1alpha3_partition_type_status->total) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "total", *v1alpha3_partition_type_status->total) == NULL) {
    goto fail; //Numeric
    }


    // v1alpha3_partition_type_status->type
    if (!v1alpha3_partition_type_status->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", v1alpha3_partition_type_status->type) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1alpha3_partition_type_status_t *v1alpha3_partition_type_status_parseFromJSON(cJSON *v1alpha3_partition_type_statusJSON){

    v1alpha3_partition_type_status_t *v1alpha3_partition_type_status_local_var = NULL;

    // define the local variable for v1alpha3_partition_type_status->allocatable
    int *allocatable_local_var = NULL;

    char *attribute_local_str = NULL;

    // define the local variable for v1alpha3_partition_type_status->total
    int *total_local_var = NULL;

    char *type_local_str = NULL;

    // v1alpha3_partition_type_status->allocatable
    cJSON *allocatable = cJSON_GetObjectItemCaseSensitive(v1alpha3_partition_type_statusJSON, "allocatable");
    if (cJSON_IsNull(allocatable)) {
        allocatable = NULL;
    }
    if (!allocatable) {
        goto end;
    }

    
    if(!cJSON_IsNumber(allocatable))
    {
    goto end; //Numeric
    }
    allocatable_local_var = malloc(sizeof(int));
    if(!allocatable_local_var)
    {
        goto end;
    }
    *allocatable_local_var = allocatable->valuedouble;

    // v1alpha3_partition_type_status->attribute
    cJSON *attribute = cJSON_GetObjectItemCaseSensitive(v1alpha3_partition_type_statusJSON, "attribute");
    if (cJSON_IsNull(attribute)) {
        attribute = NULL;
    }
    if (!attribute) {
        goto end;
    }

    
    if(!cJSON_IsString(attribute))
    {
    goto end; //String
    }

    // v1alpha3_partition_type_status->total
    cJSON *total = cJSON_GetObjectItemCaseSensitive(v1alpha3_partition_type_statusJSON, "total");
    if (cJSON_IsNull(total)) {
        total = NULL;
    }
    if (!total) {
        goto end;
    }

    
    if(!cJSON_IsNumber(total))
    {
    goto end; //Numeric
    }
    total_local_var = malloc(sizeof(int));
    if(!total_local_var)
    {
        goto end;
    }
    *total_local_var = total->valuedouble;

    // v1alpha3_partition_type_status->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(v1alpha3_partition_type_statusJSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    if (!type) {
        goto end;
    }

    
    if(!cJSON_IsString(type))
    {
    goto end; //String
    }


    if (attribute && !cJSON_IsNull(attribute)) attribute_local_str = strdup(attribute->valuestring);
    if (type && !cJSON_IsNull(type)) type_local_str = strdup(type->valuestring);

    v1alpha3_partition_type_status_local_var = v1alpha3_partition_type_status_create_internal (
        allocatable_local_var,
        attribute_local_str,
        total_local_var,
        type_local_str
        );

    if (!v1alpha3_partition_type_status_local_var) {
        goto end;
    }

    return v1alpha3_partition_type_status_local_var;
end:
    if (allocatable_local_var) {
        free(allocatable_local_var);
        allocatable_local_var = NULL;
    }
    if (attribute_local_str) {
        free(attribute_local_str);
        attribute_local_str = NULL;
    }
    if (total_local_var) {
        free(total_local_var);
        total_local_var = NULL;
    }
    if (type_local_str) {
        free(type_local_str);
        type_local_str = NULL;
    }
    return NULL;

}
