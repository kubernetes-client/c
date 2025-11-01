#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_device_counter_consumption.h"



static v1_device_counter_consumption_t *v1_device_counter_consumption_create_internal(
    char *counter_set,
    list_t* counters
    ) {
    v1_device_counter_consumption_t *v1_device_counter_consumption_local_var = malloc(sizeof(v1_device_counter_consumption_t));
    if (!v1_device_counter_consumption_local_var) {
        return NULL;
    }
    v1_device_counter_consumption_local_var->counter_set = counter_set;
    v1_device_counter_consumption_local_var->counters = counters;

    v1_device_counter_consumption_local_var->_library_owned = 1;
    return v1_device_counter_consumption_local_var;
}

__attribute__((deprecated)) v1_device_counter_consumption_t *v1_device_counter_consumption_create(
    char *counter_set,
    list_t* counters
    ) {
    return v1_device_counter_consumption_create_internal (
        counter_set,
        counters
        );
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

    // define the local map for v1_device_counter_consumption->counters
    list_t *countersList = NULL;

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



    v1_device_counter_consumption_local_var = v1_device_counter_consumption_create_internal (
        strdup(counter_set->valuestring),
        countersList
        );

    return v1_device_counter_consumption_local_var;
end:

    // The data type of the elements in v1_device_counter_consumption->counters is currently not supported.

    return NULL;

}
