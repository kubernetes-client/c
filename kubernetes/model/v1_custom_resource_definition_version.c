#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_custom_resource_definition_version.h"



v1_custom_resource_definition_version_t *v1_custom_resource_definition_version_create(
    list_t *additional_printer_columns,
    char *name,
    v1_custom_resource_validation_t *schema,
    int served,
    int storage,
    v1_custom_resource_subresources_t *subresources
    ) {
    v1_custom_resource_definition_version_t *v1_custom_resource_definition_version_local_var = malloc(sizeof(v1_custom_resource_definition_version_t));
    if (!v1_custom_resource_definition_version_local_var) {
        return NULL;
    }
    v1_custom_resource_definition_version_local_var->additional_printer_columns = additional_printer_columns;
    v1_custom_resource_definition_version_local_var->name = name;
    v1_custom_resource_definition_version_local_var->schema = schema;
    v1_custom_resource_definition_version_local_var->served = served;
    v1_custom_resource_definition_version_local_var->storage = storage;
    v1_custom_resource_definition_version_local_var->subresources = subresources;

    return v1_custom_resource_definition_version_local_var;
}


void v1_custom_resource_definition_version_free(v1_custom_resource_definition_version_t *v1_custom_resource_definition_version) {
    if(NULL == v1_custom_resource_definition_version){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_custom_resource_definition_version->additional_printer_columns) {
        list_ForEach(listEntry, v1_custom_resource_definition_version->additional_printer_columns) {
            v1_custom_resource_column_definition_free(listEntry->data);
        }
        list_free(v1_custom_resource_definition_version->additional_printer_columns);
        v1_custom_resource_definition_version->additional_printer_columns = NULL;
    }
    if (v1_custom_resource_definition_version->name) {
        free(v1_custom_resource_definition_version->name);
        v1_custom_resource_definition_version->name = NULL;
    }
    if (v1_custom_resource_definition_version->schema) {
        v1_custom_resource_validation_free(v1_custom_resource_definition_version->schema);
        v1_custom_resource_definition_version->schema = NULL;
    }
    if (v1_custom_resource_definition_version->subresources) {
        v1_custom_resource_subresources_free(v1_custom_resource_definition_version->subresources);
        v1_custom_resource_definition_version->subresources = NULL;
    }
    free(v1_custom_resource_definition_version);
}

cJSON *v1_custom_resource_definition_version_convertToJSON(v1_custom_resource_definition_version_t *v1_custom_resource_definition_version) {
    cJSON *item = cJSON_CreateObject();

    // v1_custom_resource_definition_version->additional_printer_columns
    if(v1_custom_resource_definition_version->additional_printer_columns) { 
    cJSON *additional_printer_columns = cJSON_AddArrayToObject(item, "additionalPrinterColumns");
    if(additional_printer_columns == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *additional_printer_columnsListEntry;
    if (v1_custom_resource_definition_version->additional_printer_columns) {
    list_ForEach(additional_printer_columnsListEntry, v1_custom_resource_definition_version->additional_printer_columns) {
    cJSON *itemLocal = v1_custom_resource_column_definition_convertToJSON(additional_printer_columnsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(additional_printer_columns, itemLocal);
    }
    }
     } 


    // v1_custom_resource_definition_version->name
    if (!v1_custom_resource_definition_version->name) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "name", v1_custom_resource_definition_version->name) == NULL) {
    goto fail; //String
    }


    // v1_custom_resource_definition_version->schema
    if(v1_custom_resource_definition_version->schema) { 
    cJSON *schema_local_JSON = v1_custom_resource_validation_convertToJSON(v1_custom_resource_definition_version->schema);
    if(schema_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "schema", schema_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1_custom_resource_definition_version->served
    if (!v1_custom_resource_definition_version->served) {
        goto fail;
    }
    
    if(cJSON_AddBoolToObject(item, "served", v1_custom_resource_definition_version->served) == NULL) {
    goto fail; //Bool
    }


    // v1_custom_resource_definition_version->storage
    if (!v1_custom_resource_definition_version->storage) {
        goto fail;
    }
    
    if(cJSON_AddBoolToObject(item, "storage", v1_custom_resource_definition_version->storage) == NULL) {
    goto fail; //Bool
    }


    // v1_custom_resource_definition_version->subresources
    if(v1_custom_resource_definition_version->subresources) { 
    cJSON *subresources_local_JSON = v1_custom_resource_subresources_convertToJSON(v1_custom_resource_definition_version->subresources);
    if(subresources_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "subresources", subresources_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_custom_resource_definition_version_t *v1_custom_resource_definition_version_parseFromJSON(cJSON *v1_custom_resource_definition_versionJSON){

    v1_custom_resource_definition_version_t *v1_custom_resource_definition_version_local_var = NULL;

    // v1_custom_resource_definition_version->additional_printer_columns
    cJSON *additional_printer_columns = cJSON_GetObjectItemCaseSensitive(v1_custom_resource_definition_versionJSON, "additionalPrinterColumns");
    list_t *additional_printer_columnsList;
    if (additional_printer_columns) { 
    cJSON *additional_printer_columns_local_nonprimitive;
    if(!cJSON_IsArray(additional_printer_columns)){
        goto end; //nonprimitive container
    }

    additional_printer_columnsList = list_create();

    cJSON_ArrayForEach(additional_printer_columns_local_nonprimitive,additional_printer_columns )
    {
        if(!cJSON_IsObject(additional_printer_columns_local_nonprimitive)){
            goto end;
        }
        v1_custom_resource_column_definition_t *additional_printer_columnsItem = v1_custom_resource_column_definition_parseFromJSON(additional_printer_columns_local_nonprimitive);

        list_addElement(additional_printer_columnsList, additional_printer_columnsItem);
    }
    }

    // v1_custom_resource_definition_version->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1_custom_resource_definition_versionJSON, "name");
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // v1_custom_resource_definition_version->schema
    cJSON *schema = cJSON_GetObjectItemCaseSensitive(v1_custom_resource_definition_versionJSON, "schema");
    v1_custom_resource_validation_t *schema_local_nonprim = NULL;
    if (schema) { 
    schema_local_nonprim = v1_custom_resource_validation_parseFromJSON(schema); //nonprimitive
    }

    // v1_custom_resource_definition_version->served
    cJSON *served = cJSON_GetObjectItemCaseSensitive(v1_custom_resource_definition_versionJSON, "served");
    if (!served) {
        goto end;
    }

    
    if(!cJSON_IsBool(served))
    {
    goto end; //Bool
    }

    // v1_custom_resource_definition_version->storage
    cJSON *storage = cJSON_GetObjectItemCaseSensitive(v1_custom_resource_definition_versionJSON, "storage");
    if (!storage) {
        goto end;
    }

    
    if(!cJSON_IsBool(storage))
    {
    goto end; //Bool
    }

    // v1_custom_resource_definition_version->subresources
    cJSON *subresources = cJSON_GetObjectItemCaseSensitive(v1_custom_resource_definition_versionJSON, "subresources");
    v1_custom_resource_subresources_t *subresources_local_nonprim = NULL;
    if (subresources) { 
    subresources_local_nonprim = v1_custom_resource_subresources_parseFromJSON(subresources); //nonprimitive
    }


    v1_custom_resource_definition_version_local_var = v1_custom_resource_definition_version_create (
        additional_printer_columns ? additional_printer_columnsList : NULL,
        strdup(name->valuestring),
        schema ? schema_local_nonprim : NULL,
        served->valueint,
        storage->valueint,
        subresources ? subresources_local_nonprim : NULL
        );

    return v1_custom_resource_definition_version_local_var;
end:
    if (schema_local_nonprim) {
        v1_custom_resource_validation_free(schema_local_nonprim);
        schema_local_nonprim = NULL;
    }
    if (subresources_local_nonprim) {
        v1_custom_resource_subresources_free(subresources_local_nonprim);
        subresources_local_nonprim = NULL;
    }
    return NULL;

}
