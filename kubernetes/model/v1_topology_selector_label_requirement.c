#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_topology_selector_label_requirement.h"



static v1_topology_selector_label_requirement_t *v1_topology_selector_label_requirement_create_internal(
    char *key,
    list_t *values
    ) {
    v1_topology_selector_label_requirement_t *v1_topology_selector_label_requirement_local_var = malloc(sizeof(v1_topology_selector_label_requirement_t));
    if (!v1_topology_selector_label_requirement_local_var) {
        return NULL;
    }
    v1_topology_selector_label_requirement_local_var->key = key;
    v1_topology_selector_label_requirement_local_var->values = values;

    v1_topology_selector_label_requirement_local_var->_library_owned = 1;
    return v1_topology_selector_label_requirement_local_var;
}

__attribute__((deprecated)) v1_topology_selector_label_requirement_t *v1_topology_selector_label_requirement_create(
    char *key,
    list_t *values
    ) {
    return v1_topology_selector_label_requirement_create_internal (
        key,
        values
        );
}

void v1_topology_selector_label_requirement_free(v1_topology_selector_label_requirement_t *v1_topology_selector_label_requirement) {
    if(NULL == v1_topology_selector_label_requirement){
        return ;
    }
    if(v1_topology_selector_label_requirement->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_topology_selector_label_requirement_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_topology_selector_label_requirement->key) {
        free(v1_topology_selector_label_requirement->key);
        v1_topology_selector_label_requirement->key = NULL;
    }
    if (v1_topology_selector_label_requirement->values) {
        list_ForEach(listEntry, v1_topology_selector_label_requirement->values) {
            free(listEntry->data);
        }
        list_freeList(v1_topology_selector_label_requirement->values);
        v1_topology_selector_label_requirement->values = NULL;
    }
    free(v1_topology_selector_label_requirement);
}

cJSON *v1_topology_selector_label_requirement_convertToJSON(v1_topology_selector_label_requirement_t *v1_topology_selector_label_requirement) {
    cJSON *item = cJSON_CreateObject();

    // v1_topology_selector_label_requirement->key
    if (!v1_topology_selector_label_requirement->key) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "key", v1_topology_selector_label_requirement->key) == NULL) {
    goto fail; //String
    }


    // v1_topology_selector_label_requirement->values
    if (!v1_topology_selector_label_requirement->values) {
        goto fail;
    }
    cJSON *values = cJSON_AddArrayToObject(item, "values");
    if(values == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *valuesListEntry;
    list_ForEach(valuesListEntry, v1_topology_selector_label_requirement->values) {
    if(cJSON_AddStringToObject(values, "", valuesListEntry->data) == NULL)
    {
        goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_topology_selector_label_requirement_t *v1_topology_selector_label_requirement_parseFromJSON(cJSON *v1_topology_selector_label_requirementJSON){

    v1_topology_selector_label_requirement_t *v1_topology_selector_label_requirement_local_var = NULL;

    // define the local list for v1_topology_selector_label_requirement->values
    list_t *valuesList = NULL;

    // v1_topology_selector_label_requirement->key
    cJSON *key = cJSON_GetObjectItemCaseSensitive(v1_topology_selector_label_requirementJSON, "key");
    if (cJSON_IsNull(key)) {
        key = NULL;
    }
    if (!key) {
        goto end;
    }

    
    if(!cJSON_IsString(key))
    {
    goto end; //String
    }

    // v1_topology_selector_label_requirement->values
    cJSON *values = cJSON_GetObjectItemCaseSensitive(v1_topology_selector_label_requirementJSON, "values");
    if (cJSON_IsNull(values)) {
        values = NULL;
    }
    if (!values) {
        goto end;
    }

    
    cJSON *values_local = NULL;
    if(!cJSON_IsArray(values)) {
        goto end;//primitive container
    }
    valuesList = list_createList();

    cJSON_ArrayForEach(values_local, values)
    {
        if(!cJSON_IsString(values_local))
        {
            goto end;
        }
        list_addElement(valuesList , strdup(values_local->valuestring));
    }


    v1_topology_selector_label_requirement_local_var = v1_topology_selector_label_requirement_create_internal (
        strdup(key->valuestring),
        valuesList
        );

    return v1_topology_selector_label_requirement_local_var;
end:
    if (valuesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, valuesList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(valuesList);
        valuesList = NULL;
    }
    return NULL;

}
