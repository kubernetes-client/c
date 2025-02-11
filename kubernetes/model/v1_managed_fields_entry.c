#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_managed_fields_entry.h"



static v1_managed_fields_entry_t *v1_managed_fields_entry_create_internal(
    char *api_version,
    char *fields_type,
    object_t *fields_v1,
    char *manager,
    char *operation,
    char *subresource,
    char *time
    ) {
    v1_managed_fields_entry_t *v1_managed_fields_entry_local_var = malloc(sizeof(v1_managed_fields_entry_t));
    if (!v1_managed_fields_entry_local_var) {
        return NULL;
    }
    v1_managed_fields_entry_local_var->api_version = api_version;
    v1_managed_fields_entry_local_var->fields_type = fields_type;
    v1_managed_fields_entry_local_var->fields_v1 = fields_v1;
    v1_managed_fields_entry_local_var->manager = manager;
    v1_managed_fields_entry_local_var->operation = operation;
    v1_managed_fields_entry_local_var->subresource = subresource;
    v1_managed_fields_entry_local_var->time = time;

    v1_managed_fields_entry_local_var->_library_owned = 1;
    return v1_managed_fields_entry_local_var;
}

__attribute__((deprecated)) v1_managed_fields_entry_t *v1_managed_fields_entry_create(
    char *api_version,
    char *fields_type,
    object_t *fields_v1,
    char *manager,
    char *operation,
    char *subresource,
    char *time
    ) {
    return v1_managed_fields_entry_create_internal (
        api_version,
        fields_type,
        fields_v1,
        manager,
        operation,
        subresource,
        time
        );
}

void v1_managed_fields_entry_free(v1_managed_fields_entry_t *v1_managed_fields_entry) {
    if(NULL == v1_managed_fields_entry){
        return ;
    }
    if(v1_managed_fields_entry->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_managed_fields_entry_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_managed_fields_entry->api_version) {
        free(v1_managed_fields_entry->api_version);
        v1_managed_fields_entry->api_version = NULL;
    }
    if (v1_managed_fields_entry->fields_type) {
        free(v1_managed_fields_entry->fields_type);
        v1_managed_fields_entry->fields_type = NULL;
    }
    if (v1_managed_fields_entry->fields_v1) {
        object_free(v1_managed_fields_entry->fields_v1);
        v1_managed_fields_entry->fields_v1 = NULL;
    }
    if (v1_managed_fields_entry->manager) {
        free(v1_managed_fields_entry->manager);
        v1_managed_fields_entry->manager = NULL;
    }
    if (v1_managed_fields_entry->operation) {
        free(v1_managed_fields_entry->operation);
        v1_managed_fields_entry->operation = NULL;
    }
    if (v1_managed_fields_entry->subresource) {
        free(v1_managed_fields_entry->subresource);
        v1_managed_fields_entry->subresource = NULL;
    }
    if (v1_managed_fields_entry->time) {
        free(v1_managed_fields_entry->time);
        v1_managed_fields_entry->time = NULL;
    }
    free(v1_managed_fields_entry);
}

cJSON *v1_managed_fields_entry_convertToJSON(v1_managed_fields_entry_t *v1_managed_fields_entry) {
    cJSON *item = cJSON_CreateObject();

    // v1_managed_fields_entry->api_version
    if(v1_managed_fields_entry->api_version) {
    if(cJSON_AddStringToObject(item, "apiVersion", v1_managed_fields_entry->api_version) == NULL) {
    goto fail; //String
    }
    }


    // v1_managed_fields_entry->fields_type
    if(v1_managed_fields_entry->fields_type) {
    if(cJSON_AddStringToObject(item, "fieldsType", v1_managed_fields_entry->fields_type) == NULL) {
    goto fail; //String
    }
    }


    // v1_managed_fields_entry->fields_v1
    if(v1_managed_fields_entry->fields_v1) {
    cJSON *fields_v1_object = object_convertToJSON(v1_managed_fields_entry->fields_v1);
    if(fields_v1_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "fieldsV1", fields_v1_object);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_managed_fields_entry->manager
    if(v1_managed_fields_entry->manager) {
    if(cJSON_AddStringToObject(item, "manager", v1_managed_fields_entry->manager) == NULL) {
    goto fail; //String
    }
    }


    // v1_managed_fields_entry->operation
    if(v1_managed_fields_entry->operation) {
    if(cJSON_AddStringToObject(item, "operation", v1_managed_fields_entry->operation) == NULL) {
    goto fail; //String
    }
    }


    // v1_managed_fields_entry->subresource
    if(v1_managed_fields_entry->subresource) {
    if(cJSON_AddStringToObject(item, "subresource", v1_managed_fields_entry->subresource) == NULL) {
    goto fail; //String
    }
    }


    // v1_managed_fields_entry->time
    if(v1_managed_fields_entry->time) {
    if(cJSON_AddStringToObject(item, "time", v1_managed_fields_entry->time) == NULL) {
    goto fail; //Date-Time
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_managed_fields_entry_t *v1_managed_fields_entry_parseFromJSON(cJSON *v1_managed_fields_entryJSON){

    v1_managed_fields_entry_t *v1_managed_fields_entry_local_var = NULL;

    // v1_managed_fields_entry->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1_managed_fields_entryJSON, "apiVersion");
    if (cJSON_IsNull(api_version)) {
        api_version = NULL;
    }
    if (api_version) { 
    if(!cJSON_IsString(api_version) && !cJSON_IsNull(api_version))
    {
    goto end; //String
    }
    }

    // v1_managed_fields_entry->fields_type
    cJSON *fields_type = cJSON_GetObjectItemCaseSensitive(v1_managed_fields_entryJSON, "fieldsType");
    if (cJSON_IsNull(fields_type)) {
        fields_type = NULL;
    }
    if (fields_type) { 
    if(!cJSON_IsString(fields_type) && !cJSON_IsNull(fields_type))
    {
    goto end; //String
    }
    }

    // v1_managed_fields_entry->fields_v1
    cJSON *fields_v1 = cJSON_GetObjectItemCaseSensitive(v1_managed_fields_entryJSON, "fieldsV1");
    if (cJSON_IsNull(fields_v1)) {
        fields_v1 = NULL;
    }
    object_t *fields_v1_local_object = NULL;
    if (fields_v1) { 
    fields_v1_local_object = object_parseFromJSON(fields_v1); //object
    }

    // v1_managed_fields_entry->manager
    cJSON *manager = cJSON_GetObjectItemCaseSensitive(v1_managed_fields_entryJSON, "manager");
    if (cJSON_IsNull(manager)) {
        manager = NULL;
    }
    if (manager) { 
    if(!cJSON_IsString(manager) && !cJSON_IsNull(manager))
    {
    goto end; //String
    }
    }

    // v1_managed_fields_entry->operation
    cJSON *operation = cJSON_GetObjectItemCaseSensitive(v1_managed_fields_entryJSON, "operation");
    if (cJSON_IsNull(operation)) {
        operation = NULL;
    }
    if (operation) { 
    if(!cJSON_IsString(operation) && !cJSON_IsNull(operation))
    {
    goto end; //String
    }
    }

    // v1_managed_fields_entry->subresource
    cJSON *subresource = cJSON_GetObjectItemCaseSensitive(v1_managed_fields_entryJSON, "subresource");
    if (cJSON_IsNull(subresource)) {
        subresource = NULL;
    }
    if (subresource) { 
    if(!cJSON_IsString(subresource) && !cJSON_IsNull(subresource))
    {
    goto end; //String
    }
    }

    // v1_managed_fields_entry->time
    cJSON *time = cJSON_GetObjectItemCaseSensitive(v1_managed_fields_entryJSON, "time");
    if (cJSON_IsNull(time)) {
        time = NULL;
    }
    if (time) { 
    if(!cJSON_IsString(time) && !cJSON_IsNull(time))
    {
    goto end; //DateTime
    }
    }


    v1_managed_fields_entry_local_var = v1_managed_fields_entry_create_internal (
        api_version && !cJSON_IsNull(api_version) ? strdup(api_version->valuestring) : NULL,
        fields_type && !cJSON_IsNull(fields_type) ? strdup(fields_type->valuestring) : NULL,
        fields_v1 ? fields_v1_local_object : NULL,
        manager && !cJSON_IsNull(manager) ? strdup(manager->valuestring) : NULL,
        operation && !cJSON_IsNull(operation) ? strdup(operation->valuestring) : NULL,
        subresource && !cJSON_IsNull(subresource) ? strdup(subresource->valuestring) : NULL,
        time && !cJSON_IsNull(time) ? strdup(time->valuestring) : NULL
        );

    return v1_managed_fields_entry_local_var;
end:
    return NULL;

}
