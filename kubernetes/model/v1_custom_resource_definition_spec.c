#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_custom_resource_definition_spec.h"



v1_custom_resource_definition_spec_t *v1_custom_resource_definition_spec_create(
    v1_custom_resource_conversion_t *conversion,
    char *group,
    v1_custom_resource_definition_names_t *names,
    int preserve_unknown_fields,
    char *scope,
    list_t *versions
    ) {
    v1_custom_resource_definition_spec_t *v1_custom_resource_definition_spec_local_var = malloc(sizeof(v1_custom_resource_definition_spec_t));
    if (!v1_custom_resource_definition_spec_local_var) {
        return NULL;
    }
    v1_custom_resource_definition_spec_local_var->conversion = conversion;
    v1_custom_resource_definition_spec_local_var->group = group;
    v1_custom_resource_definition_spec_local_var->names = names;
    v1_custom_resource_definition_spec_local_var->preserve_unknown_fields = preserve_unknown_fields;
    v1_custom_resource_definition_spec_local_var->scope = scope;
    v1_custom_resource_definition_spec_local_var->versions = versions;

    return v1_custom_resource_definition_spec_local_var;
}


void v1_custom_resource_definition_spec_free(v1_custom_resource_definition_spec_t *v1_custom_resource_definition_spec) {
    if(NULL == v1_custom_resource_definition_spec){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_custom_resource_definition_spec->conversion) {
        v1_custom_resource_conversion_free(v1_custom_resource_definition_spec->conversion);
        v1_custom_resource_definition_spec->conversion = NULL;
    }
    if (v1_custom_resource_definition_spec->group) {
        free(v1_custom_resource_definition_spec->group);
        v1_custom_resource_definition_spec->group = NULL;
    }
    if (v1_custom_resource_definition_spec->names) {
        v1_custom_resource_definition_names_free(v1_custom_resource_definition_spec->names);
        v1_custom_resource_definition_spec->names = NULL;
    }
    if (v1_custom_resource_definition_spec->scope) {
        free(v1_custom_resource_definition_spec->scope);
        v1_custom_resource_definition_spec->scope = NULL;
    }
    if (v1_custom_resource_definition_spec->versions) {
        list_ForEach(listEntry, v1_custom_resource_definition_spec->versions) {
            v1_custom_resource_definition_version_free(listEntry->data);
        }
        list_free(v1_custom_resource_definition_spec->versions);
        v1_custom_resource_definition_spec->versions = NULL;
    }
    free(v1_custom_resource_definition_spec);
}

cJSON *v1_custom_resource_definition_spec_convertToJSON(v1_custom_resource_definition_spec_t *v1_custom_resource_definition_spec) {
    cJSON *item = cJSON_CreateObject();

    // v1_custom_resource_definition_spec->conversion
    if(v1_custom_resource_definition_spec->conversion) { 
    cJSON *conversion_local_JSON = v1_custom_resource_conversion_convertToJSON(v1_custom_resource_definition_spec->conversion);
    if(conversion_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "conversion", conversion_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1_custom_resource_definition_spec->group
    if (!v1_custom_resource_definition_spec->group) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "group", v1_custom_resource_definition_spec->group) == NULL) {
    goto fail; //String
    }


    // v1_custom_resource_definition_spec->names
    if (!v1_custom_resource_definition_spec->names) {
        goto fail;
    }
    
    cJSON *names_local_JSON = v1_custom_resource_definition_names_convertToJSON(v1_custom_resource_definition_spec->names);
    if(names_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "names", names_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // v1_custom_resource_definition_spec->preserve_unknown_fields
    if(v1_custom_resource_definition_spec->preserve_unknown_fields) { 
    if(cJSON_AddBoolToObject(item, "preserveUnknownFields", v1_custom_resource_definition_spec->preserve_unknown_fields) == NULL) {
    goto fail; //Bool
    }
     } 


    // v1_custom_resource_definition_spec->scope
    if (!v1_custom_resource_definition_spec->scope) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "scope", v1_custom_resource_definition_spec->scope) == NULL) {
    goto fail; //String
    }


    // v1_custom_resource_definition_spec->versions
    if (!v1_custom_resource_definition_spec->versions) {
        goto fail;
    }
    
    cJSON *versions = cJSON_AddArrayToObject(item, "versions");
    if(versions == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *versionsListEntry;
    if (v1_custom_resource_definition_spec->versions) {
    list_ForEach(versionsListEntry, v1_custom_resource_definition_spec->versions) {
    cJSON *itemLocal = v1_custom_resource_definition_version_convertToJSON(versionsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(versions, itemLocal);
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_custom_resource_definition_spec_t *v1_custom_resource_definition_spec_parseFromJSON(cJSON *v1_custom_resource_definition_specJSON){

    v1_custom_resource_definition_spec_t *v1_custom_resource_definition_spec_local_var = NULL;

    // v1_custom_resource_definition_spec->conversion
    cJSON *conversion = cJSON_GetObjectItemCaseSensitive(v1_custom_resource_definition_specJSON, "conversion");
    v1_custom_resource_conversion_t *conversion_local_nonprim = NULL;
    if (conversion) { 
    conversion_local_nonprim = v1_custom_resource_conversion_parseFromJSON(conversion); //nonprimitive
    }

    // v1_custom_resource_definition_spec->group
    cJSON *group = cJSON_GetObjectItemCaseSensitive(v1_custom_resource_definition_specJSON, "group");
    if (!group) {
        goto end;
    }

    
    if(!cJSON_IsString(group))
    {
    goto end; //String
    }

    // v1_custom_resource_definition_spec->names
    cJSON *names = cJSON_GetObjectItemCaseSensitive(v1_custom_resource_definition_specJSON, "names");
    if (!names) {
        goto end;
    }

    v1_custom_resource_definition_names_t *names_local_nonprim = NULL;
    
    names_local_nonprim = v1_custom_resource_definition_names_parseFromJSON(names); //nonprimitive

    // v1_custom_resource_definition_spec->preserve_unknown_fields
    cJSON *preserve_unknown_fields = cJSON_GetObjectItemCaseSensitive(v1_custom_resource_definition_specJSON, "preserveUnknownFields");
    if (preserve_unknown_fields) { 
    if(!cJSON_IsBool(preserve_unknown_fields))
    {
    goto end; //Bool
    }
    }

    // v1_custom_resource_definition_spec->scope
    cJSON *scope = cJSON_GetObjectItemCaseSensitive(v1_custom_resource_definition_specJSON, "scope");
    if (!scope) {
        goto end;
    }

    
    if(!cJSON_IsString(scope))
    {
    goto end; //String
    }

    // v1_custom_resource_definition_spec->versions
    cJSON *versions = cJSON_GetObjectItemCaseSensitive(v1_custom_resource_definition_specJSON, "versions");
    if (!versions) {
        goto end;
    }

    list_t *versionsList;
    
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
        v1_custom_resource_definition_version_t *versionsItem = v1_custom_resource_definition_version_parseFromJSON(versions_local_nonprimitive);

        list_addElement(versionsList, versionsItem);
    }


    v1_custom_resource_definition_spec_local_var = v1_custom_resource_definition_spec_create (
        conversion ? conversion_local_nonprim : NULL,
        strdup(group->valuestring),
        names_local_nonprim,
        preserve_unknown_fields ? preserve_unknown_fields->valueint : 0,
        strdup(scope->valuestring),
        versionsList
        );

    return v1_custom_resource_definition_spec_local_var;
end:
    if (conversion_local_nonprim) {
        v1_custom_resource_conversion_free(conversion_local_nonprim);
        conversion_local_nonprim = NULL;
    }
    if (names_local_nonprim) {
        v1_custom_resource_definition_names_free(names_local_nonprim);
        names_local_nonprim = NULL;
    }
    return NULL;

}
