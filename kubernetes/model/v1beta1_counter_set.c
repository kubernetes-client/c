#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_counter_set.h"



static v1beta1_counter_set_t *v1beta1_counter_set_create_internal(
    list_t* counters,
    char *name
    ) {
    v1beta1_counter_set_t *v1beta1_counter_set_local_var = malloc(sizeof(v1beta1_counter_set_t));
    if (!v1beta1_counter_set_local_var) {
        return NULL;
    }
    memset(v1beta1_counter_set_local_var, 0, sizeof(v1beta1_counter_set_t));
    v1beta1_counter_set_local_var->_library_owned = 1;
    v1beta1_counter_set_local_var->counters = counters;
    v1beta1_counter_set_local_var->name = name;
    return v1beta1_counter_set_local_var;
}

__attribute__((deprecated)) v1beta1_counter_set_t *v1beta1_counter_set_create(
    list_t* counters,
    char *name
    ) {
    v1beta1_counter_set_t *result = v1beta1_counter_set_create_internal (
        counters,
        name
        );
    if (!result) {
    }
    return result;
}

void v1beta1_counter_set_free(v1beta1_counter_set_t *v1beta1_counter_set) {
    if(NULL == v1beta1_counter_set){
        return ;
    }
    if(v1beta1_counter_set->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1beta1_counter_set_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta1_counter_set->counters) {
        list_ForEach(listEntry, v1beta1_counter_set->counters) {
            keyValuePair_t *localKeyValue = listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_freeList(v1beta1_counter_set->counters);
        v1beta1_counter_set->counters = NULL;
    }
    if (v1beta1_counter_set->name) {
        free(v1beta1_counter_set->name);
        v1beta1_counter_set->name = NULL;
    }
    free(v1beta1_counter_set);
}

cJSON *v1beta1_counter_set_convertToJSON(v1beta1_counter_set_t *v1beta1_counter_set) {
    cJSON *item = cJSON_CreateObject();

    // v1beta1_counter_set->counters
    if (!v1beta1_counter_set->counters) {
        goto fail;
    }
    cJSON *counters = cJSON_AddObjectToObject(item, "counters");
    if(counters == NULL) {
        goto fail; //primitive map container
    }
    cJSON *localMapObject = counters;
    listEntry_t *countersListEntry;
    if (v1beta1_counter_set->counters) {
    list_ForEach(countersListEntry, v1beta1_counter_set->counters) {
        keyValuePair_t *localKeyValue = countersListEntry->data;
    }
    }


    // v1beta1_counter_set->name
    if (!v1beta1_counter_set->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", v1beta1_counter_set->name) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1beta1_counter_set_t *v1beta1_counter_set_parseFromJSON(cJSON *v1beta1_counter_setJSON){

    v1beta1_counter_set_t *v1beta1_counter_set_local_var = NULL;

    // define the local map for v1beta1_counter_set->counters
    list_t *countersList = NULL;

    char *name_local_str = NULL;

    // v1beta1_counter_set->counters
    cJSON *counters = cJSON_GetObjectItemCaseSensitive(v1beta1_counter_setJSON, "counters");
    if (cJSON_IsNull(counters)) {
        counters = NULL;
    }
    if (!counters) {
        goto end;
    }

    

    // The data type of the elements in v1beta1_counter_set->counters is currently not supported.


    // v1beta1_counter_set->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1beta1_counter_setJSON, "name");
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

    v1beta1_counter_set_local_var = v1beta1_counter_set_create_internal (
        countersList,
        name_local_str
        );

    if (!v1beta1_counter_set_local_var) {
        goto end;
    }

    return v1beta1_counter_set_local_var;
end:

    // The data type of the elements in v1beta1_counter_set->counters is currently not supported.

    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    return NULL;

}
