#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha2_named_resources_resources.h"



v1alpha2_named_resources_resources_t *v1alpha2_named_resources_resources_create(
    list_t *instances
    ) {
    v1alpha2_named_resources_resources_t *v1alpha2_named_resources_resources_local_var = malloc(sizeof(v1alpha2_named_resources_resources_t));
    if (!v1alpha2_named_resources_resources_local_var) {
        return NULL;
    }
    v1alpha2_named_resources_resources_local_var->instances = instances;

    return v1alpha2_named_resources_resources_local_var;
}


void v1alpha2_named_resources_resources_free(v1alpha2_named_resources_resources_t *v1alpha2_named_resources_resources) {
    if(NULL == v1alpha2_named_resources_resources){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha2_named_resources_resources->instances) {
        list_ForEach(listEntry, v1alpha2_named_resources_resources->instances) {
            v1alpha2_named_resources_instance_free(listEntry->data);
        }
        list_freeList(v1alpha2_named_resources_resources->instances);
        v1alpha2_named_resources_resources->instances = NULL;
    }
    free(v1alpha2_named_resources_resources);
}

cJSON *v1alpha2_named_resources_resources_convertToJSON(v1alpha2_named_resources_resources_t *v1alpha2_named_resources_resources) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha2_named_resources_resources->instances
    if (!v1alpha2_named_resources_resources->instances) {
        goto fail;
    }
    cJSON *instances = cJSON_AddArrayToObject(item, "instances");
    if(instances == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *instancesListEntry;
    if (v1alpha2_named_resources_resources->instances) {
    list_ForEach(instancesListEntry, v1alpha2_named_resources_resources->instances) {
    cJSON *itemLocal = v1alpha2_named_resources_instance_convertToJSON(instancesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(instances, itemLocal);
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1alpha2_named_resources_resources_t *v1alpha2_named_resources_resources_parseFromJSON(cJSON *v1alpha2_named_resources_resourcesJSON){

    v1alpha2_named_resources_resources_t *v1alpha2_named_resources_resources_local_var = NULL;

    // define the local list for v1alpha2_named_resources_resources->instances
    list_t *instancesList = NULL;

    // v1alpha2_named_resources_resources->instances
    cJSON *instances = cJSON_GetObjectItemCaseSensitive(v1alpha2_named_resources_resourcesJSON, "instances");
    if (!instances) {
        goto end;
    }

    
    cJSON *instances_local_nonprimitive = NULL;
    if(!cJSON_IsArray(instances)){
        goto end; //nonprimitive container
    }

    instancesList = list_createList();

    cJSON_ArrayForEach(instances_local_nonprimitive,instances )
    {
        if(!cJSON_IsObject(instances_local_nonprimitive)){
            goto end;
        }
        v1alpha2_named_resources_instance_t *instancesItem = v1alpha2_named_resources_instance_parseFromJSON(instances_local_nonprimitive);

        list_addElement(instancesList, instancesItem);
    }


    v1alpha2_named_resources_resources_local_var = v1alpha2_named_resources_resources_create (
        instancesList
        );

    return v1alpha2_named_resources_resources_local_var;
end:
    if (instancesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, instancesList) {
            v1alpha2_named_resources_instance_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(instancesList);
        instancesList = NULL;
    }
    return NULL;

}
