#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_storage_health.h"



static v1_storage_health_t *v1_storage_health_create_internal(
    list_t *health_conditions,
    char *name
    ) {
    v1_storage_health_t *v1_storage_health_local_var = malloc(sizeof(v1_storage_health_t));
    if (!v1_storage_health_local_var) {
        return NULL;
    }
    memset(v1_storage_health_local_var, 0, sizeof(v1_storage_health_t));
    v1_storage_health_local_var->_library_owned = 1;
    v1_storage_health_local_var->health_conditions = health_conditions;
    v1_storage_health_local_var->name = name;
    return v1_storage_health_local_var;
}

__attribute__((deprecated)) v1_storage_health_t *v1_storage_health_create(
    list_t *health_conditions,
    char *name
    ) {
    v1_storage_health_t *result = v1_storage_health_create_internal (
        health_conditions,
        name
        );
    if (!result) {
    }
    return result;
}

void v1_storage_health_free(v1_storage_health_t *v1_storage_health) {
    if(NULL == v1_storage_health){
        return ;
    }
    if(v1_storage_health->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_storage_health_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_storage_health->health_conditions) {
        list_ForEach(listEntry, v1_storage_health->health_conditions) {
            v1_storage_health_condition_free(listEntry->data);
        }
        list_freeList(v1_storage_health->health_conditions);
        v1_storage_health->health_conditions = NULL;
    }
    if (v1_storage_health->name) {
        free(v1_storage_health->name);
        v1_storage_health->name = NULL;
    }
    free(v1_storage_health);
}

cJSON *v1_storage_health_convertToJSON(v1_storage_health_t *v1_storage_health) {
    cJSON *item = cJSON_CreateObject();

    // v1_storage_health->health_conditions
    if(v1_storage_health->health_conditions) {
    cJSON *health_conditions = cJSON_AddArrayToObject(item, "healthConditions");
    if(health_conditions == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *health_conditionsListEntry;
    if (v1_storage_health->health_conditions) {
    list_ForEach(health_conditionsListEntry, v1_storage_health->health_conditions) {
    cJSON *itemLocal = v1_storage_health_condition_convertToJSON(health_conditionsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(health_conditions, itemLocal);
    }
    }
    }


    // v1_storage_health->name
    if (!v1_storage_health->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", v1_storage_health->name) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_storage_health_t *v1_storage_health_parseFromJSON(cJSON *v1_storage_healthJSON){

    v1_storage_health_t *v1_storage_health_local_var = NULL;

    // define the local list for v1_storage_health->health_conditions
    list_t *health_conditionsList = NULL;

    char *name_local_str = NULL;

    // v1_storage_health->health_conditions
    cJSON *health_conditions = cJSON_GetObjectItemCaseSensitive(v1_storage_healthJSON, "healthConditions");
    if (cJSON_IsNull(health_conditions)) {
        health_conditions = NULL;
    }
    if (health_conditions) { 
    cJSON *health_conditions_local_nonprimitive = NULL;
    if(!cJSON_IsArray(health_conditions)){
        goto end; //nonprimitive container
    }

    health_conditionsList = list_createList();

    cJSON_ArrayForEach(health_conditions_local_nonprimitive,health_conditions )
    {
        if(!cJSON_IsObject(health_conditions_local_nonprimitive)){
            goto end;
        }
        v1_storage_health_condition_t *health_conditionsItem = v1_storage_health_condition_parseFromJSON(health_conditions_local_nonprimitive);

        list_addElement(health_conditionsList, health_conditionsItem);
    }
    }

    // v1_storage_health->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1_storage_healthJSON, "name");
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


    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);

    v1_storage_health_local_var = v1_storage_health_create_internal (
        health_conditions ? health_conditionsList : NULL,
        name_local_str
        );

    if (!v1_storage_health_local_var) {
        goto end;
    }

    return v1_storage_health_local_var;
end:
    if (health_conditionsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, health_conditionsList) {
            v1_storage_health_condition_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(health_conditionsList);
        health_conditionsList = NULL;
    }
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    return NULL;

}
