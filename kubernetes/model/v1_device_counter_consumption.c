#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_device_counter_consumption.h"



static v1_device_counter_consumption_t *v1_device_counter_consumption_create_internal(
    list_t *compatibility_groups,
    char *counter_set,
    list_t* counters
    ) {
    v1_device_counter_consumption_t *v1_device_counter_consumption_local_var = malloc(sizeof(v1_device_counter_consumption_t));
    if (!v1_device_counter_consumption_local_var) {
        return NULL;
    }
    memset(v1_device_counter_consumption_local_var, 0, sizeof(v1_device_counter_consumption_t));
    v1_device_counter_consumption_local_var->_library_owned = 1;
    v1_device_counter_consumption_local_var->compatibility_groups = compatibility_groups;
    v1_device_counter_consumption_local_var->counter_set = counter_set;
    v1_device_counter_consumption_local_var->counters = counters;
    return v1_device_counter_consumption_local_var;
}

__attribute__((deprecated)) v1_device_counter_consumption_t *v1_device_counter_consumption_create(
    list_t *compatibility_groups,
    char *counter_set,
    list_t* counters
    ) {
    v1_device_counter_consumption_t *result = v1_device_counter_consumption_create_internal (
        compatibility_groups,
        counter_set,
        counters
        );
    if (!result) {
    }
    return result;
}

void v1_device_counter_consumption_free(v1_device_counter_consumption_t *v1_device_counter_consumption) {
    if(NULL == v1_device_counter_consumption){
        return ;
    }
    if(v1_device_counter_consumption->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_device_counter_consumption_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_device_counter_consumption->compatibility_groups) {
        list_ForEach(listEntry, v1_device_counter_consumption->compatibility_groups) {
            free(listEntry->data);
        }
        list_freeList(v1_device_counter_consumption->compatibility_groups);
        v1_device_counter_consumption->compatibility_groups = NULL;
    }
    if (v1_device_counter_consumption->counter_set) {
        free(v1_device_counter_consumption->counter_set);
        v1_device_counter_consumption->counter_set = NULL;
    }
    if (v1_device_counter_consumption->counters) {
        list_ForEach(listEntry, v1_device_counter_consumption->counters) {
            keyValuePair_t *localKeyValue = listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_freeList(v1_device_counter_consumption->counters);
        v1_device_counter_consumption->counters = NULL;
    }
    free(v1_device_counter_consumption);
}

cJSON *v1_device_counter_consumption_convertToJSON(v1_device_counter_consumption_t *v1_device_counter_consumption) {
    cJSON *item = cJSON_CreateObject();

    // v1_device_counter_consumption->compatibility_groups
    if(v1_device_counter_consumption->compatibility_groups) {
    cJSON *compatibility_groups = cJSON_AddArrayToObject(item, "compatibilityGroups");
    if(compatibility_groups == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *compatibility_groupsListEntry;
    list_ForEach(compatibility_groupsListEntry, v1_device_counter_consumption->compatibility_groups) {
    if(cJSON_AddStringToObject(compatibility_groups, "", compatibility_groupsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // v1_device_counter_consumption->counter_set
    if (!v1_device_counter_consumption->counter_set) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "counterSet", v1_device_counter_consumption->counter_set) == NULL) {
    goto fail; //String
    }


    // v1_device_counter_consumption->counters
    if (!v1_device_counter_consumption->counters) {
        goto fail;
    }
    cJSON *counters = cJSON_AddObjectToObject(item, "counters");
    if(counters == NULL) {
        goto fail; //primitive map container
    }
    cJSON *localMapObject = counters;
    listEntry_t *countersListEntry;
    if (v1_device_counter_consumption->counters) {
    list_ForEach(countersListEntry, v1_device_counter_consumption->counters) {
        keyValuePair_t *localKeyValue = countersListEntry->data;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_device_counter_consumption_t *v1_device_counter_consumption_parseFromJSON(cJSON *v1_device_counter_consumptionJSON){

    v1_device_counter_consumption_t *v1_device_counter_consumption_local_var = NULL;

    // define the local list for v1_device_counter_consumption->compatibility_groups
    list_t *compatibility_groupsList = NULL;

    char *counter_set_local_str = NULL;

    // define the local map for v1_device_counter_consumption->counters
    list_t *countersList = NULL;

    // v1_device_counter_consumption->compatibility_groups
    cJSON *compatibility_groups = cJSON_GetObjectItemCaseSensitive(v1_device_counter_consumptionJSON, "compatibilityGroups");
    if (cJSON_IsNull(compatibility_groups)) {
        compatibility_groups = NULL;
    }
    if (compatibility_groups) { 
    cJSON *compatibility_groups_local = NULL;
    if(!cJSON_IsArray(compatibility_groups)) {
        goto end;//primitive container
    }
    compatibility_groupsList = list_createList();

    cJSON_ArrayForEach(compatibility_groups_local, compatibility_groups)
    {
        if(!cJSON_IsString(compatibility_groups_local))
        {
            goto end;
        }
        list_addElement(compatibility_groupsList , strdup(compatibility_groups_local->valuestring));
    }
    }

    // v1_device_counter_consumption->counter_set
    cJSON *counter_set = cJSON_GetObjectItemCaseSensitive(v1_device_counter_consumptionJSON, "counterSet");
    if (cJSON_IsNull(counter_set)) {
        counter_set = NULL;
    }
    if (!counter_set) {
        goto end;
    }

    
    if(!cJSON_IsString(counter_set))
    {
    goto end; //String
    }

    // v1_device_counter_consumption->counters
    cJSON *counters = cJSON_GetObjectItemCaseSensitive(v1_device_counter_consumptionJSON, "counters");
    if (cJSON_IsNull(counters)) {
        counters = NULL;
    }
    if (!counters) {
        goto end;
    }

    

    // The data type of the elements in v1_device_counter_consumption->counters is currently not supported.



    if (counter_set && !cJSON_IsNull(counter_set)) counter_set_local_str = strdup(counter_set->valuestring);

    v1_device_counter_consumption_local_var = v1_device_counter_consumption_create_internal (
        compatibility_groups ? compatibility_groupsList : NULL,
        counter_set_local_str,
        countersList
        );

    if (!v1_device_counter_consumption_local_var) {
        goto end;
    }

    return v1_device_counter_consumption_local_var;
end:
    if (compatibility_groupsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, compatibility_groupsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(compatibility_groupsList);
        compatibility_groupsList = NULL;
    }
    if (counter_set_local_str) {
        free(counter_set_local_str);
        counter_set_local_str = NULL;
    }

    // The data type of the elements in v1_device_counter_consumption->counters is currently not supported.

    return NULL;

}
