#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha3_counter_set.h"



static v1alpha3_counter_set_t *v1alpha3_counter_set_create_internal(
    list_t* counters,
    char *name
    ) {
    v1alpha3_counter_set_t *v1alpha3_counter_set_local_var = malloc(sizeof(v1alpha3_counter_set_t));
    if (!v1alpha3_counter_set_local_var) {
        return NULL;
    }
    v1alpha3_counter_set_local_var->counters = counters;
    v1alpha3_counter_set_local_var->name = name;

    v1alpha3_counter_set_local_var->_library_owned = 1;
    return v1alpha3_counter_set_local_var;
}

__attribute__((deprecated)) v1alpha3_counter_set_t *v1alpha3_counter_set_create(
    list_t* counters,
    char *name
    ) {
    return v1alpha3_counter_set_create_internal (
        counters,
        name
        );
}

void v1alpha3_counter_set_free(v1alpha3_counter_set_t *v1alpha3_counter_set) {
    if(NULL == v1alpha3_counter_set){
        return ;
    }
    if(v1alpha3_counter_set->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1alpha3_counter_set_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha3_counter_set->counters) {
        list_ForEach(listEntry, v1alpha3_counter_set->counters) {
            keyValuePair_t *localKeyValue = listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_freeList(v1alpha3_counter_set->counters);
        v1alpha3_counter_set->counters = NULL;
    }
    if (v1alpha3_counter_set->name) {
        free(v1alpha3_counter_set->name);
        v1alpha3_counter_set->name = NULL;
    }
    free(v1alpha3_counter_set);
}

cJSON *v1alpha3_counter_set_convertToJSON(v1alpha3_counter_set_t *v1alpha3_counter_set) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha3_counter_set->counters
    if (!v1alpha3_counter_set->counters) {
        goto fail;
    }
    cJSON *counters = cJSON_AddObjectToObject(item, "counters");
    if(counters == NULL) {
        goto fail; //primitive map container
    }
    cJSON *localMapObject = counters;
    listEntry_t *countersListEntry;
    if (v1alpha3_counter_set->counters) {
    list_ForEach(countersListEntry, v1alpha3_counter_set->counters) {
        keyValuePair_t *localKeyValue = countersListEntry->data;
    }
    }


    // v1alpha3_counter_set->name
    if (!v1alpha3_counter_set->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", v1alpha3_counter_set->name) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1alpha3_counter_set_t *v1alpha3_counter_set_parseFromJSON(cJSON *v1alpha3_counter_setJSON){

    v1alpha3_counter_set_t *v1alpha3_counter_set_local_var = NULL;

    // define the local map for v1alpha3_counter_set->counters
    list_t *countersList = NULL;

    // v1alpha3_counter_set->counters
    cJSON *counters = cJSON_GetObjectItemCaseSensitive(v1alpha3_counter_setJSON, "counters");
    if (cJSON_IsNull(counters)) {
        counters = NULL;
    }
    if (!counters) {
        goto end;
    }

    

    // The data type of the elements in v1alpha3_counter_set->counters is currently not supported.


    // v1alpha3_counter_set->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1alpha3_counter_setJSON, "name");
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


    v1alpha3_counter_set_local_var = v1alpha3_counter_set_create_internal (
        countersList,
        strdup(name->valuestring)
        );

    return v1alpha3_counter_set_local_var;
end:

    // The data type of the elements in v1alpha3_counter_set->counters is currently not supported.

    return NULL;

}
