#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_topology_selector_label_requirement.h"



v1_topology_selector_label_requirement_t *v1_topology_selector_label_requirement_create(
    char *key,
    list_t *values
    ) {
    v1_topology_selector_label_requirement_t *v1_topology_selector_label_requirement_local_var = malloc(sizeof(v1_topology_selector_label_requirement_t));
    if (!v1_topology_selector_label_requirement_local_var) {
        return NULL;
    }
    v1_topology_selector_label_requirement_local_var->key = key;
    v1_topology_selector_label_requirement_local_var->values = values;

    return v1_topology_selector_label_requirement_local_var;
}


void v1_topology_selector_label_requirement_free(v1_topology_selector_label_requirement_t *v1_topology_selector_label_requirement) {
    if(NULL == v1_topology_selector_label_requirement){
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
        list_free(v1_topology_selector_label_requirement->values);
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
    if(cJSON_AddStringToObject(values, "", (char*)valuesListEntry->data) == NULL)
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

    // v1_topology_selector_label_requirement->key
    cJSON *key = cJSON_GetObjectItemCaseSensitive(v1_topology_selector_label_requirementJSON, "key");
    if (!key) {
        goto end;
    }

    
    if(!cJSON_IsString(key))
    {
    goto end; //String
    }

    // v1_topology_selector_label_requirement->values
    cJSON *values = cJSON_GetObjectItemCaseSensitive(v1_topology_selector_label_requirementJSON, "values");
    if (!values) {
        goto end;
    }

    list_t *valuesList;
    
    cJSON *values_local;
    if(!cJSON_IsArray(values)) {
        goto end;//primitive container
    }
    valuesList = list_create();

    cJSON_ArrayForEach(values_local, values)
    {
        if(!cJSON_IsString(values_local))
        {
            goto end;
        }
        list_addElement(valuesList , strdup(values_local->valuestring));
    }


    v1_topology_selector_label_requirement_local_var = v1_topology_selector_label_requirement_create (
        strdup(key->valuestring),
        valuesList
        );

    return v1_topology_selector_label_requirement_local_var;
end:
    return NULL;

}
