#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_custom_resource_definition_spec.h"



v1beta1_custom_resource_definition_spec_t *v1beta1_custom_resource_definition_spec_create(
    list_t *additional_printer_columns,
    v1beta1_custom_resource_conversion_t *conversion,
    char *group,
    v1beta1_custom_resource_definition_names_t *names,
    int preserve_unknown_fields,
    char *scope,
    v1beta1_custom_resource_subresources_t *subresources,
    v1beta1_custom_resource_validation_t *validation,
    char *version,
    list_t *versions
    ) {
    v1beta1_custom_resource_definition_spec_t *v1beta1_custom_resource_definition_spec_local_var = malloc(sizeof(v1beta1_custom_resource_definition_spec_t));
    if (!v1beta1_custom_resource_definition_spec_local_var) {
        return NULL;
    }
    v1beta1_custom_resource_definition_spec_local_var->additional_printer_columns = additional_printer_columns;
    v1beta1_custom_resource_definition_spec_local_var->conversion = conversion;
    v1beta1_custom_resource_definition_spec_local_var->group = group;
    v1beta1_custom_resource_definition_spec_local_var->names = names;
    v1beta1_custom_resource_definition_spec_local_var->preserve_unknown_fields = preserve_unknown_fields;
    v1beta1_custom_resource_definition_spec_local_var->scope = scope;
    v1beta1_custom_resource_definition_spec_local_var->subresources = subresources;
    v1beta1_custom_resource_definition_spec_local_var->validation = validation;
    v1beta1_custom_resource_definition_spec_local_var->version = version;
    v1beta1_custom_resource_definition_spec_local_var->versions = versions;

    return v1beta1_custom_resource_definition_spec_local_var;
}


void v1beta1_custom_resource_definition_spec_free(v1beta1_custom_resource_definition_spec_t *v1beta1_custom_resource_definition_spec) {
    if(NULL == v1beta1_custom_resource_definition_spec){
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta1_custom_resource_definition_spec->additional_printer_columns) {
        list_ForEach(listEntry, v1beta1_custom_resource_definition_spec->additional_printer_columns) {
            v1beta1_custom_resource_column_definition_free(listEntry->data);
        }
        list_free(v1beta1_custom_resource_definition_spec->additional_printer_columns);
        v1beta1_custom_resource_definition_spec->additional_printer_columns = NULL;
    }
    if (v1beta1_custom_resource_definition_spec->conversion) {
        v1beta1_custom_resource_conversion_free(v1beta1_custom_resource_definition_spec->conversion);
        v1beta1_custom_resource_definition_spec->conversion = NULL;
    }
    if (v1beta1_custom_resource_definition_spec->group) {
        free(v1beta1_custom_resource_definition_spec->group);
        v1beta1_custom_resource_definition_spec->group = NULL;
    }
    if (v1beta1_custom_resource_definition_spec->names) {
        v1beta1_custom_resource_definition_names_free(v1beta1_custom_resource_definition_spec->names);
        v1beta1_custom_resource_definition_spec->names = NULL;
    }
    if (v1beta1_custom_resource_definition_spec->scope) {
        free(v1beta1_custom_resource_definition_spec->scope);
        v1beta1_custom_resource_definition_spec->scope = NULL;
    }
    if (v1beta1_custom_resource_definition_spec->subresources) {
        v1beta1_custom_resource_subresources_free(v1beta1_custom_resource_definition_spec->subresources);
        v1beta1_custom_resource_definition_spec->subresources = NULL;
    }
    if (v1beta1_custom_resource_definition_spec->validation) {
        v1beta1_custom_resource_validation_free(v1beta1_custom_resource_definition_spec->validation);
        v1beta1_custom_resource_definition_spec->validation = NULL;
    }
    if (v1beta1_custom_resource_definition_spec->version) {
        free(v1beta1_custom_resource_definition_spec->version);
        v1beta1_custom_resource_definition_spec->version = NULL;
    }
    if (v1beta1_custom_resource_definition_spec->versions) {
        list_ForEach(listEntry, v1beta1_custom_resource_definition_spec->versions) {
            v1beta1_custom_resource_definition_version_free(listEntry->data);
        }
        list_free(v1beta1_custom_resource_definition_spec->versions);
        v1beta1_custom_resource_definition_spec->versions = NULL;
    }
    free(v1beta1_custom_resource_definition_spec);
}

cJSON *v1beta1_custom_resource_definition_spec_convertToJSON(v1beta1_custom_resource_definition_spec_t *v1beta1_custom_resource_definition_spec) {
    cJSON *item = cJSON_CreateObject();

    // v1beta1_custom_resource_definition_spec->additional_printer_columns
    if(v1beta1_custom_resource_definition_spec->additional_printer_columns) { 
    cJSON *additional_printer_columns = cJSON_AddArrayToObject(item, "additionalPrinterColumns");
    if(additional_printer_columns == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *additional_printer_columnsListEntry;
    if (v1beta1_custom_resource_definition_spec->additional_printer_columns) {
    list_ForEach(additional_printer_columnsListEntry, v1beta1_custom_resource_definition_spec->additional_printer_columns) {
    cJSON *itemLocal = v1beta1_custom_resource_column_definition_convertToJSON(additional_printer_columnsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(additional_printer_columns, itemLocal);
    }
    }
     } 


    // v1beta1_custom_resource_definition_spec->conversion
    if(v1beta1_custom_resource_definition_spec->conversion) { 
    cJSON *conversion_local_JSON = v1beta1_custom_resource_conversion_convertToJSON(v1beta1_custom_resource_definition_spec->conversion);
    if(conversion_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "conversion", conversion_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1beta1_custom_resource_definition_spec->group
    if (!v1beta1_custom_resource_definition_spec->group) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "group", v1beta1_custom_resource_definition_spec->group) == NULL) {
    goto fail; //String
    }


    // v1beta1_custom_resource_definition_spec->names
    if (!v1beta1_custom_resource_definition_spec->names) {
        goto fail;
    }
    
    cJSON *names_local_JSON = v1beta1_custom_resource_definition_names_convertToJSON(v1beta1_custom_resource_definition_spec->names);
    if(names_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "names", names_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // v1beta1_custom_resource_definition_spec->preserve_unknown_fields
    if(v1beta1_custom_resource_definition_spec->preserve_unknown_fields) { 
    if(cJSON_AddBoolToObject(item, "preserveUnknownFields", v1beta1_custom_resource_definition_spec->preserve_unknown_fields) == NULL) {
    goto fail; //Bool
    }
     } 


    // v1beta1_custom_resource_definition_spec->scope
    if (!v1beta1_custom_resource_definition_spec->scope) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "scope", v1beta1_custom_resource_definition_spec->scope) == NULL) {
    goto fail; //String
    }


    // v1beta1_custom_resource_definition_spec->subresources
    if(v1beta1_custom_resource_definition_spec->subresources) { 
    cJSON *subresources_local_JSON = v1beta1_custom_resource_subresources_convertToJSON(v1beta1_custom_resource_definition_spec->subresources);
    if(subresources_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "subresources", subresources_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1beta1_custom_resource_definition_spec->validation
    if(v1beta1_custom_resource_definition_spec->validation) { 
    cJSON *validation_local_JSON = v1beta1_custom_resource_validation_convertToJSON(v1beta1_custom_resource_definition_spec->validation);
    if(validation_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "validation", validation_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1beta1_custom_resource_definition_spec->version
    if(v1beta1_custom_resource_definition_spec->version) { 
    if(cJSON_AddStringToObject(item, "version", v1beta1_custom_resource_definition_spec->version) == NULL) {
    goto fail; //String
    }
     } 


    // v1beta1_custom_resource_definition_spec->versions
    if(v1beta1_custom_resource_definition_spec->versions) { 
    cJSON *versions = cJSON_AddArrayToObject(item, "versions");
    if(versions == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *versionsListEntry;
    if (v1beta1_custom_resource_definition_spec->versions) {
    list_ForEach(versionsListEntry, v1beta1_custom_resource_definition_spec->versions) {
    cJSON *itemLocal = v1beta1_custom_resource_definition_version_convertToJSON(versionsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(versions, itemLocal);
    }
    }
     } 

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1beta1_custom_resource_definition_spec_t *v1beta1_custom_resource_definition_spec_parseFromJSON(cJSON *v1beta1_custom_resource_definition_specJSON){

    v1beta1_custom_resource_definition_spec_t *v1beta1_custom_resource_definition_spec_local_var = NULL;

    // v1beta1_custom_resource_definition_spec->additional_printer_columns
    cJSON *additional_printer_columns = cJSON_GetObjectItemCaseSensitive(v1beta1_custom_resource_definition_specJSON, "additionalPrinterColumns");
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
        v1beta1_custom_resource_column_definition_t *additional_printer_columnsItem = v1beta1_custom_resource_column_definition_parseFromJSON(additional_printer_columns_local_nonprimitive);

        list_addElement(additional_printer_columnsList, additional_printer_columnsItem);
    }
    }

    // v1beta1_custom_resource_definition_spec->conversion
    cJSON *conversion = cJSON_GetObjectItemCaseSensitive(v1beta1_custom_resource_definition_specJSON, "conversion");
    v1beta1_custom_resource_conversion_t *conversion_local_nonprim = NULL;
    if (conversion) { 
    conversion_local_nonprim = v1beta1_custom_resource_conversion_parseFromJSON(conversion); //nonprimitive
    }

    // v1beta1_custom_resource_definition_spec->group
    cJSON *group = cJSON_GetObjectItemCaseSensitive(v1beta1_custom_resource_definition_specJSON, "group");
    if (!group) {
        goto end;
    }

    
    if(!cJSON_IsString(group))
    {
    goto end; //String
    }

    // v1beta1_custom_resource_definition_spec->names
    cJSON *names = cJSON_GetObjectItemCaseSensitive(v1beta1_custom_resource_definition_specJSON, "names");
    if (!names) {
        goto end;
    }

    v1beta1_custom_resource_definition_names_t *names_local_nonprim = NULL;
    
    names_local_nonprim = v1beta1_custom_resource_definition_names_parseFromJSON(names); //nonprimitive

    // v1beta1_custom_resource_definition_spec->preserve_unknown_fields
    cJSON *preserve_unknown_fields = cJSON_GetObjectItemCaseSensitive(v1beta1_custom_resource_definition_specJSON, "preserveUnknownFields");
    if (preserve_unknown_fields) { 
    if(!cJSON_IsBool(preserve_unknown_fields))
    {
    goto end; //Bool
    }
    }

    // v1beta1_custom_resource_definition_spec->scope
    cJSON *scope = cJSON_GetObjectItemCaseSensitive(v1beta1_custom_resource_definition_specJSON, "scope");
    if (!scope) {
        goto end;
    }

    
    if(!cJSON_IsString(scope))
    {
    goto end; //String
    }

    // v1beta1_custom_resource_definition_spec->subresources
    cJSON *subresources = cJSON_GetObjectItemCaseSensitive(v1beta1_custom_resource_definition_specJSON, "subresources");
    v1beta1_custom_resource_subresources_t *subresources_local_nonprim = NULL;
    if (subresources) { 
    subresources_local_nonprim = v1beta1_custom_resource_subresources_parseFromJSON(subresources); //nonprimitive
    }

    // v1beta1_custom_resource_definition_spec->validation
    cJSON *validation = cJSON_GetObjectItemCaseSensitive(v1beta1_custom_resource_definition_specJSON, "validation");
    v1beta1_custom_resource_validation_t *validation_local_nonprim = NULL;
    if (validation) { 
    validation_local_nonprim = v1beta1_custom_resource_validation_parseFromJSON(validation); //nonprimitive
    }

    // v1beta1_custom_resource_definition_spec->version
    cJSON *version = cJSON_GetObjectItemCaseSensitive(v1beta1_custom_resource_definition_specJSON, "version");
    if (version) { 
    if(!cJSON_IsString(version))
    {
    goto end; //String
    }
    }

    // v1beta1_custom_resource_definition_spec->versions
    cJSON *versions = cJSON_GetObjectItemCaseSensitive(v1beta1_custom_resource_definition_specJSON, "versions");
    list_t *versionsList;
    if (versions) { 
    cJSON *versions_local_nonprimitive;
    if(!cJSON_IsArray(versions)){
        goto end; //nonprimitive container
    }

    versionsList = list_create();

    cJSON_ArrayForEach(versions_local_nonprimitive,versions )
    {
        if(!cJSON_IsObject(versions_local_nonprimitive)){
            goto end;
        }
        v1beta1_custom_resource_definition_version_t *versionsItem = v1beta1_custom_resource_definition_version_parseFromJSON(versions_local_nonprimitive);

        list_addElement(versionsList, versionsItem);
    }
    }


    v1beta1_custom_resource_definition_spec_local_var = v1beta1_custom_resource_definition_spec_create (
        additional_printer_columns ? additional_printer_columnsList : NULL,
        conversion ? conversion_local_nonprim : NULL,
        strdup(group->valuestring),
        names_local_nonprim,
        preserve_unknown_fields ? preserve_unknown_fields->valueint : 0,
        strdup(scope->valuestring),
        subresources ? subresources_local_nonprim : NULL,
        validation ? validation_local_nonprim : NULL,
        version ? strdup(version->valuestring) : NULL,
        versions ? versionsList : NULL
        );

    return v1beta1_custom_resource_definition_spec_local_var;
end:
    if (conversion_local_nonprim) {
        v1beta1_custom_resource_conversion_free(conversion_local_nonprim);
        conversion_local_nonprim = NULL;
    }
    if (names_local_nonprim) {
        v1beta1_custom_resource_definition_names_free(names_local_nonprim);
        names_local_nonprim = NULL;
    }
    if (subresources_local_nonprim) {
        v1beta1_custom_resource_subresources_free(subresources_local_nonprim);
        subresources_local_nonprim = NULL;
    }
    if (validation_local_nonprim) {
        v1beta1_custom_resource_validation_free(validation_local_nonprim);
        validation_local_nonprim = NULL;
    }
    return NULL;

}
