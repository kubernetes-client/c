#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha2_named_resources_instance.h"



v1alpha2_named_resources_instance_t *v1alpha2_named_resources_instance_create(
    list_t *attributes,
    char *name
    ) {
    v1alpha2_named_resources_instance_t *v1alpha2_named_resources_instance_local_var = malloc(sizeof(v1alpha2_named_resources_instance_t));
    if (!v1alpha2_named_resources_instance_local_var) {
        return NULL;
    }
    v1alpha2_named_resources_instance_local_var->attributes = attributes;
    v1alpha2_named_resources_instance_local_var->name = name;

    return v1alpha2_named_resources_instance_local_var;
}


void v1alpha2_named_resources_instance_free(v1alpha2_named_resources_instance_t *v1alpha2_named_resources_instance) {
    if(NULL == v1alpha2_named_resources_instance){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha2_named_resources_instance->attributes) {
        list_ForEach(listEntry, v1alpha2_named_resources_instance->attributes) {
            v1alpha2_named_resources_attribute_free(listEntry->data);
        }
        list_freeList(v1alpha2_named_resources_instance->attributes);
        v1alpha2_named_resources_instance->attributes = NULL;
    }
    if (v1alpha2_named_resources_instance->name) {
        free(v1alpha2_named_resources_instance->name);
        v1alpha2_named_resources_instance->name = NULL;
    }
    free(v1alpha2_named_resources_instance);
}

cJSON *v1alpha2_named_resources_instance_convertToJSON(v1alpha2_named_resources_instance_t *v1alpha2_named_resources_instance) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha2_named_resources_instance->attributes
    if(v1alpha2_named_resources_instance->attributes) {
    cJSON *attributes = cJSON_AddArrayToObject(item, "attributes");
    if(attributes == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *attributesListEntry;
    if (v1alpha2_named_resources_instance->attributes) {
    list_ForEach(attributesListEntry, v1alpha2_named_resources_instance->attributes) {
    cJSON *itemLocal = v1alpha2_named_resources_attribute_convertToJSON(attributesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(attributes, itemLocal);
    }
    }
    }


    // v1alpha2_named_resources_instance->name
    if (!v1alpha2_named_resources_instance->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", v1alpha2_named_resources_instance->name) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1alpha2_named_resources_instance_t *v1alpha2_named_resources_instance_parseFromJSON(cJSON *v1alpha2_named_resources_instanceJSON){

    v1alpha2_named_resources_instance_t *v1alpha2_named_resources_instance_local_var = NULL;

    // define the local list for v1alpha2_named_resources_instance->attributes
    list_t *attributesList = NULL;

    // v1alpha2_named_resources_instance->attributes
    cJSON *attributes = cJSON_GetObjectItemCaseSensitive(v1alpha2_named_resources_instanceJSON, "attributes");
    if (attributes) { 
    cJSON *attributes_local_nonprimitive = NULL;
    if(!cJSON_IsArray(attributes)){
        goto end; //nonprimitive container
    }

    attributesList = list_createList();

    cJSON_ArrayForEach(attributes_local_nonprimitive,attributes )
    {
        if(!cJSON_IsObject(attributes_local_nonprimitive)){
            goto end;
        }
        v1alpha2_named_resources_attribute_t *attributesItem = v1alpha2_named_resources_attribute_parseFromJSON(attributes_local_nonprimitive);

        list_addElement(attributesList, attributesItem);
    }
    }

    // v1alpha2_named_resources_instance->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1alpha2_named_resources_instanceJSON, "name");
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }


    v1alpha2_named_resources_instance_local_var = v1alpha2_named_resources_instance_create (
        attributes ? attributesList : NULL,
        strdup(name->valuestring)
        );

    return v1alpha2_named_resources_instance_local_var;
end:
    if (attributesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, attributesList) {
            v1alpha2_named_resources_attribute_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(attributesList);
        attributesList = NULL;
    }
    return NULL;

}
