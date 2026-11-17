#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_storage_version_migration_status.h"



static v1_storage_version_migration_status_t *v1_storage_version_migration_status_create_internal(
    list_t *conditions,
    char *resource_version
    ) {
    v1_storage_version_migration_status_t *v1_storage_version_migration_status_local_var = malloc(sizeof(v1_storage_version_migration_status_t));
    if (!v1_storage_version_migration_status_local_var) {
        return NULL;
    }
    memset(v1_storage_version_migration_status_local_var, 0, sizeof(v1_storage_version_migration_status_t));
    v1_storage_version_migration_status_local_var->_library_owned = 1;
    v1_storage_version_migration_status_local_var->conditions = conditions;
    v1_storage_version_migration_status_local_var->resource_version = resource_version;
    return v1_storage_version_migration_status_local_var;
}

__attribute__((deprecated)) v1_storage_version_migration_status_t *v1_storage_version_migration_status_create(
    list_t *conditions,
    char *resource_version
    ) {
    v1_storage_version_migration_status_t *result = v1_storage_version_migration_status_create_internal (
        conditions,
        resource_version
        );
    if (!result) {
    }
    return result;
}

void v1_storage_version_migration_status_free(v1_storage_version_migration_status_t *v1_storage_version_migration_status) {
    if(NULL == v1_storage_version_migration_status){
        return ;
    }
    if(v1_storage_version_migration_status->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_storage_version_migration_status_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_storage_version_migration_status->conditions) {
        list_ForEach(listEntry, v1_storage_version_migration_status->conditions) {
            v1_condition_free(listEntry->data);
        }
        list_freeList(v1_storage_version_migration_status->conditions);
        v1_storage_version_migration_status->conditions = NULL;
    }
    if (v1_storage_version_migration_status->resource_version) {
        free(v1_storage_version_migration_status->resource_version);
        v1_storage_version_migration_status->resource_version = NULL;
    }
    free(v1_storage_version_migration_status);
}

cJSON *v1_storage_version_migration_status_convertToJSON(v1_storage_version_migration_status_t *v1_storage_version_migration_status) {
    cJSON *item = cJSON_CreateObject();

    // v1_storage_version_migration_status->conditions
    if(v1_storage_version_migration_status->conditions) {
    cJSON *conditions = cJSON_AddArrayToObject(item, "conditions");
    if(conditions == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *conditionsListEntry;
    if (v1_storage_version_migration_status->conditions) {
    list_ForEach(conditionsListEntry, v1_storage_version_migration_status->conditions) {
    cJSON *itemLocal = v1_condition_convertToJSON(conditionsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(conditions, itemLocal);
    }
    }
    }


    // v1_storage_version_migration_status->resource_version
    if(v1_storage_version_migration_status->resource_version) {
    if(cJSON_AddStringToObject(item, "resourceVersion", v1_storage_version_migration_status->resource_version) == NULL) {
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

v1_storage_version_migration_status_t *v1_storage_version_migration_status_parseFromJSON(cJSON *v1_storage_version_migration_statusJSON){

    v1_storage_version_migration_status_t *v1_storage_version_migration_status_local_var = NULL;

    // define the local list for v1_storage_version_migration_status->conditions
    list_t *conditionsList = NULL;

    char *resource_version_local_str = NULL;

    // v1_storage_version_migration_status->conditions
    cJSON *conditions = cJSON_GetObjectItemCaseSensitive(v1_storage_version_migration_statusJSON, "conditions");
    if (cJSON_IsNull(conditions)) {
        conditions = NULL;
    }
    if (conditions) { 
    cJSON *conditions_local_nonprimitive = NULL;
    if(!cJSON_IsArray(conditions)){
        goto end; //nonprimitive container
    }

    conditionsList = list_createList();

    cJSON_ArrayForEach(conditions_local_nonprimitive,conditions )
    {
        if(!cJSON_IsObject(conditions_local_nonprimitive)){
            goto end;
        }
        v1_condition_t *conditionsItem = v1_condition_parseFromJSON(conditions_local_nonprimitive);

        list_addElement(conditionsList, conditionsItem);
    }
    }

    // v1_storage_version_migration_status->resource_version
    cJSON *resource_version = cJSON_GetObjectItemCaseSensitive(v1_storage_version_migration_statusJSON, "resourceVersion");
    if (cJSON_IsNull(resource_version)) {
        resource_version = NULL;
    }
    if (resource_version) { 
    if(!cJSON_IsString(resource_version) && !cJSON_IsNull(resource_version))
    {
    goto end; //String
    }
    }


    if (resource_version && !cJSON_IsNull(resource_version)) resource_version_local_str = strdup(resource_version->valuestring);

    v1_storage_version_migration_status_local_var = v1_storage_version_migration_status_create_internal (
        conditions ? conditionsList : NULL,
        resource_version_local_str
        );

    if (!v1_storage_version_migration_status_local_var) {
        goto end;
    }

    return v1_storage_version_migration_status_local_var;
end:
    if (conditionsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, conditionsList) {
            v1_condition_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(conditionsList);
        conditionsList = NULL;
    }
    if (resource_version_local_str) {
        free(resource_version_local_str);
        resource_version_local_str = NULL;
    }
    return NULL;

}
