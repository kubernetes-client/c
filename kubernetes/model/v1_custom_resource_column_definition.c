#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_custom_resource_column_definition.h"



static v1_custom_resource_column_definition_t *v1_custom_resource_column_definition_create_internal(
    char *description,
    char *format,
    char *json_path,
    char *name,
    int priority,
    char *type
    ) {
    v1_custom_resource_column_definition_t *v1_custom_resource_column_definition_local_var = malloc(sizeof(v1_custom_resource_column_definition_t));
    if (!v1_custom_resource_column_definition_local_var) {
        return NULL;
    }
    v1_custom_resource_column_definition_local_var->description = description;
    v1_custom_resource_column_definition_local_var->format = format;
    v1_custom_resource_column_definition_local_var->json_path = json_path;
    v1_custom_resource_column_definition_local_var->name = name;
    v1_custom_resource_column_definition_local_var->priority = priority;
    v1_custom_resource_column_definition_local_var->type = type;

    v1_custom_resource_column_definition_local_var->_library_owned = 1;
    return v1_custom_resource_column_definition_local_var;
}

__attribute__((deprecated)) v1_custom_resource_column_definition_t *v1_custom_resource_column_definition_create(
    char *description,
    char *format,
    char *json_path,
    char *name,
    int priority,
    char *type
    ) {
    return v1_custom_resource_column_definition_create_internal (
        description,
        format,
        json_path,
        name,
        priority,
        type
        );
}

void v1_custom_resource_column_definition_free(v1_custom_resource_column_definition_t *v1_custom_resource_column_definition) {
    if(NULL == v1_custom_resource_column_definition){
        return ;
    }
    if(v1_custom_resource_column_definition->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_custom_resource_column_definition_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_custom_resource_column_definition->description) {
        free(v1_custom_resource_column_definition->description);
        v1_custom_resource_column_definition->description = NULL;
    }
    if (v1_custom_resource_column_definition->format) {
        free(v1_custom_resource_column_definition->format);
        v1_custom_resource_column_definition->format = NULL;
    }
    if (v1_custom_resource_column_definition->json_path) {
        free(v1_custom_resource_column_definition->json_path);
        v1_custom_resource_column_definition->json_path = NULL;
    }
    if (v1_custom_resource_column_definition->name) {
        free(v1_custom_resource_column_definition->name);
        v1_custom_resource_column_definition->name = NULL;
    }
    if (v1_custom_resource_column_definition->type) {
        free(v1_custom_resource_column_definition->type);
        v1_custom_resource_column_definition->type = NULL;
    }
    free(v1_custom_resource_column_definition);
}

cJSON *v1_custom_resource_column_definition_convertToJSON(v1_custom_resource_column_definition_t *v1_custom_resource_column_definition) {
    cJSON *item = cJSON_CreateObject();

    // v1_custom_resource_column_definition->description
    if(v1_custom_resource_column_definition->description) {
    if(cJSON_AddStringToObject(item, "description", v1_custom_resource_column_definition->description) == NULL) {
    goto fail; //String
    }
    }


    // v1_custom_resource_column_definition->format
    if(v1_custom_resource_column_definition->format) {
    if(cJSON_AddStringToObject(item, "format", v1_custom_resource_column_definition->format) == NULL) {
    goto fail; //String
    }
    }


    // v1_custom_resource_column_definition->json_path
    if (!v1_custom_resource_column_definition->json_path) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "jsonPath", v1_custom_resource_column_definition->json_path) == NULL) {
    goto fail; //String
    }


    // v1_custom_resource_column_definition->name
    if (!v1_custom_resource_column_definition->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", v1_custom_resource_column_definition->name) == NULL) {
    goto fail; //String
    }


    // v1_custom_resource_column_definition->priority
    if(v1_custom_resource_column_definition->priority) {
    if(cJSON_AddNumberToObject(item, "priority", v1_custom_resource_column_definition->priority) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_custom_resource_column_definition->type
    if (!v1_custom_resource_column_definition->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", v1_custom_resource_column_definition->type) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_custom_resource_column_definition_t *v1_custom_resource_column_definition_parseFromJSON(cJSON *v1_custom_resource_column_definitionJSON){

    v1_custom_resource_column_definition_t *v1_custom_resource_column_definition_local_var = NULL;

    // v1_custom_resource_column_definition->description
    cJSON *description = cJSON_GetObjectItemCaseSensitive(v1_custom_resource_column_definitionJSON, "description");
    if (cJSON_IsNull(description)) {
        description = NULL;
    }
    if (description) { 
    if(!cJSON_IsString(description) && !cJSON_IsNull(description))
    {
    goto end; //String
    }
    }

    // v1_custom_resource_column_definition->format
    cJSON *format = cJSON_GetObjectItemCaseSensitive(v1_custom_resource_column_definitionJSON, "format");
    if (cJSON_IsNull(format)) {
        format = NULL;
    }
    if (format) { 
    if(!cJSON_IsString(format) && !cJSON_IsNull(format))
    {
    goto end; //String
    }
    }

    // v1_custom_resource_column_definition->json_path
    cJSON *json_path = cJSON_GetObjectItemCaseSensitive(v1_custom_resource_column_definitionJSON, "jsonPath");
    if (cJSON_IsNull(json_path)) {
        json_path = NULL;
    }
    if (!json_path) {
        goto end;
    }

    
    if(!cJSON_IsString(json_path))
    {
    goto end; //String
    }

    // v1_custom_resource_column_definition->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1_custom_resource_column_definitionJSON, "name");
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

    // v1_custom_resource_column_definition->priority
    cJSON *priority = cJSON_GetObjectItemCaseSensitive(v1_custom_resource_column_definitionJSON, "priority");
    if (cJSON_IsNull(priority)) {
        priority = NULL;
    }
    if (priority) { 
    if(!cJSON_IsNumber(priority))
    {
    goto end; //Numeric
    }
    }

    // v1_custom_resource_column_definition->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(v1_custom_resource_column_definitionJSON, "type");
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


    v1_custom_resource_column_definition_local_var = v1_custom_resource_column_definition_create_internal (
        description && !cJSON_IsNull(description) ? strdup(description->valuestring) : NULL,
        format && !cJSON_IsNull(format) ? strdup(format->valuestring) : NULL,
        strdup(json_path->valuestring),
        strdup(name->valuestring),
        priority ? priority->valuedouble : 0,
        strdup(type->valuestring)
        );

    return v1_custom_resource_column_definition_local_var;
end:
    return NULL;

}
