#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_device_class_spec.h"



static v1_device_class_spec_t *v1_device_class_spec_create_internal(
    list_t *config,
    char *extended_resource_name,
    list_t *selectors
    ) {
    v1_device_class_spec_t *v1_device_class_spec_local_var = malloc(sizeof(v1_device_class_spec_t));
    if (!v1_device_class_spec_local_var) {
        return NULL;
    }
    v1_device_class_spec_local_var->config = config;
    v1_device_class_spec_local_var->extended_resource_name = extended_resource_name;
    v1_device_class_spec_local_var->selectors = selectors;

    v1_device_class_spec_local_var->_library_owned = 1;
    return v1_device_class_spec_local_var;
}

__attribute__((deprecated)) v1_device_class_spec_t *v1_device_class_spec_create(
    list_t *config,
    char *extended_resource_name,
    list_t *selectors
    ) {
    return v1_device_class_spec_create_internal (
        config,
        extended_resource_name,
        selectors
        );
}

void v1_device_class_spec_free(v1_device_class_spec_t *v1_device_class_spec) {
    if(NULL == v1_device_class_spec){
        return ;
    }
    if(v1_device_class_spec->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_device_class_spec_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_device_class_spec->config) {
        list_ForEach(listEntry, v1_device_class_spec->config) {
            v1_device_class_configuration_free(listEntry->data);
        }
        list_freeList(v1_device_class_spec->config);
        v1_device_class_spec->config = NULL;
    }
    if (v1_device_class_spec->extended_resource_name) {
        free(v1_device_class_spec->extended_resource_name);
        v1_device_class_spec->extended_resource_name = NULL;
    }
    if (v1_device_class_spec->selectors) {
        list_ForEach(listEntry, v1_device_class_spec->selectors) {
            v1_device_selector_free(listEntry->data);
        }
        list_freeList(v1_device_class_spec->selectors);
        v1_device_class_spec->selectors = NULL;
    }
    free(v1_device_class_spec);
}

cJSON *v1_device_class_spec_convertToJSON(v1_device_class_spec_t *v1_device_class_spec) {
    cJSON *item = cJSON_CreateObject();

    // v1_device_class_spec->config
    if(v1_device_class_spec->config) {
    cJSON *config = cJSON_AddArrayToObject(item, "config");
    if(config == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *configListEntry;
    if (v1_device_class_spec->config) {
    list_ForEach(configListEntry, v1_device_class_spec->config) {
    cJSON *itemLocal = v1_device_class_configuration_convertToJSON(configListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(config, itemLocal);
    }
    }
    }


    // v1_device_class_spec->extended_resource_name
    if(v1_device_class_spec->extended_resource_name) {
    if(cJSON_AddStringToObject(item, "extendedResourceName", v1_device_class_spec->extended_resource_name) == NULL) {
    goto fail; //String
    }
    }


    // v1_device_class_spec->selectors
    if(v1_device_class_spec->selectors) {
    cJSON *selectors = cJSON_AddArrayToObject(item, "selectors");
    if(selectors == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *selectorsListEntry;
    if (v1_device_class_spec->selectors) {
    list_ForEach(selectorsListEntry, v1_device_class_spec->selectors) {
    cJSON *itemLocal = v1_device_selector_convertToJSON(selectorsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(selectors, itemLocal);
    }
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_device_class_spec_t *v1_device_class_spec_parseFromJSON(cJSON *v1_device_class_specJSON){

    v1_device_class_spec_t *v1_device_class_spec_local_var = NULL;

    // define the local list for v1_device_class_spec->config
    list_t *configList = NULL;

    // define the local list for v1_device_class_spec->selectors
    list_t *selectorsList = NULL;

    // v1_device_class_spec->config
    cJSON *config = cJSON_GetObjectItemCaseSensitive(v1_device_class_specJSON, "config");
    if (cJSON_IsNull(config)) {
        config = NULL;
    }
    if (config) { 
    cJSON *config_local_nonprimitive = NULL;
    if(!cJSON_IsArray(config)){
        goto end; //nonprimitive container
    }

    configList = list_createList();

    cJSON_ArrayForEach(config_local_nonprimitive,config )
    {
        if(!cJSON_IsObject(config_local_nonprimitive)){
            goto end;
        }
        v1_device_class_configuration_t *configItem = v1_device_class_configuration_parseFromJSON(config_local_nonprimitive);

        list_addElement(configList, configItem);
    }
    }

    // v1_device_class_spec->extended_resource_name
    cJSON *extended_resource_name = cJSON_GetObjectItemCaseSensitive(v1_device_class_specJSON, "extendedResourceName");
    if (cJSON_IsNull(extended_resource_name)) {
        extended_resource_name = NULL;
    }
    if (extended_resource_name) { 
    if(!cJSON_IsString(extended_resource_name) && !cJSON_IsNull(extended_resource_name))
    {
    goto end; //String
    }
    }

    // v1_device_class_spec->selectors
    cJSON *selectors = cJSON_GetObjectItemCaseSensitive(v1_device_class_specJSON, "selectors");
    if (cJSON_IsNull(selectors)) {
        selectors = NULL;
    }
    if (selectors) { 
    cJSON *selectors_local_nonprimitive = NULL;
    if(!cJSON_IsArray(selectors)){
        goto end; //nonprimitive container
    }

    selectorsList = list_createList();

    cJSON_ArrayForEach(selectors_local_nonprimitive,selectors )
    {
        if(!cJSON_IsObject(selectors_local_nonprimitive)){
            goto end;
        }
        v1_device_selector_t *selectorsItem = v1_device_selector_parseFromJSON(selectors_local_nonprimitive);

        list_addElement(selectorsList, selectorsItem);
    }
    }


    v1_device_class_spec_local_var = v1_device_class_spec_create_internal (
        config ? configList : NULL,
        extended_resource_name && !cJSON_IsNull(extended_resource_name) ? strdup(extended_resource_name->valuestring) : NULL,
        selectors ? selectorsList : NULL
        );

    return v1_device_class_spec_local_var;
end:
    if (configList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, configList) {
            v1_device_class_configuration_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(configList);
        configList = NULL;
    }
    if (selectorsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, selectorsList) {
            v1_device_selector_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(selectorsList);
        selectorsList = NULL;
    }
    return NULL;

}
