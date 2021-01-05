#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_managed_fields_entry.h"



v1_managed_fields_entry_t *v1_managed_fields_entry_create(
    char *api_version,
    char *fields_type,
    object_t *fields_v1,
    char *manager,
    char *operation,
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
    v1_managed_fields_entry_local_var->time = time;

    return v1_managed_fields_entry_local_var;
}


void v1_managed_fields_entry_free(v1_managed_fields_entry_t *v1_managed_fields_entry) {
    if(NULL == v1_managed_fields_entry){
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
    if (api_version) { 
    if(!cJSON_IsString(api_version))
    {
    goto end; //String
    }
    }

    // v1_managed_fields_entry->fields_type
    cJSON *fields_type = cJSON_GetObjectItemCaseSensitive(v1_managed_fields_entryJSON, "fieldsType");
    if (fields_type) { 
    if(!cJSON_IsString(fields_type))
    {
    goto end; //String
    }
    }

    // v1_managed_fields_entry->fields_v1
    cJSON *fields_v1 = cJSON_GetObjectItemCaseSensitive(v1_managed_fields_entryJSON, "fieldsV1");
    object_t *fields_v1_local_object = NULL;
    if (fields_v1) { 
    fields_v1_local_object = object_parseFromJSON(fields_v1); //object
    }

    // v1_managed_fields_entry->manager
    cJSON *manager = cJSON_GetObjectItemCaseSensitive(v1_managed_fields_entryJSON, "manager");
    if (manager) { 
    if(!cJSON_IsString(manager))
    {
    goto end; //String
    }
    }

    // v1_managed_fields_entry->operation
    cJSON *operation = cJSON_GetObjectItemCaseSensitive(v1_managed_fields_entryJSON, "operation");
    if (operation) { 
    if(!cJSON_IsString(operation))
    {
    goto end; //String
    }
    }

    // v1_managed_fields_entry->time
    cJSON *time = cJSON_GetObjectItemCaseSensitive(v1_managed_fields_entryJSON, "time");
    if (time) { 
    if(!cJSON_IsString(time))
    {
    goto end; //DateTime
    }
    }


    v1_managed_fields_entry_local_var = v1_managed_fields_entry_create (
        api_version ? strdup(api_version->valuestring) : NULL,
        fields_type ? strdup(fields_type->valuestring) : NULL,
        fields_v1 ? fields_v1_local_object : NULL,
        manager ? strdup(manager->valuestring) : NULL,
        operation ? strdup(operation->valuestring) : NULL,
        time ? strdup(time->valuestring) : NULL
        );

    return v1_managed_fields_entry_local_var;
end:
    return NULL;

}
