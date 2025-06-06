#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta2_device_class_spec.h"



static v1beta2_device_class_spec_t *v1beta2_device_class_spec_create_internal(
    list_t *config,
    list_t *selectors
    ) {
    v1beta2_device_class_spec_t *v1beta2_device_class_spec_local_var = malloc(sizeof(v1beta2_device_class_spec_t));
    if (!v1beta2_device_class_spec_local_var) {
        return NULL;
    }
    v1beta2_device_class_spec_local_var->config = config;
    v1beta2_device_class_spec_local_var->selectors = selectors;

    v1beta2_device_class_spec_local_var->_library_owned = 1;
    return v1beta2_device_class_spec_local_var;
}

__attribute__((deprecated)) v1beta2_device_class_spec_t *v1beta2_device_class_spec_create(
    list_t *config,
    list_t *selectors
    ) {
    return v1beta2_device_class_spec_create_internal (
        config,
        selectors
        );
}

void v1beta2_device_class_spec_free(v1beta2_device_class_spec_t *v1beta2_device_class_spec) {
    if(NULL == v1beta2_device_class_spec){
        return ;
    }
    if(v1beta2_device_class_spec->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1beta2_device_class_spec_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta2_device_class_spec->config) {
        list_ForEach(listEntry, v1beta2_device_class_spec->config) {
            v1beta2_device_class_configuration_free(listEntry->data);
        }
        list_freeList(v1beta2_device_class_spec->config);
        v1beta2_device_class_spec->config = NULL;
    }
    if (v1beta2_device_class_spec->selectors) {
        list_ForEach(listEntry, v1beta2_device_class_spec->selectors) {
            v1beta2_device_selector_free(listEntry->data);
        }
        list_freeList(v1beta2_device_class_spec->selectors);
        v1beta2_device_class_spec->selectors = NULL;
    }
    free(v1beta2_device_class_spec);
}

cJSON *v1beta2_device_class_spec_convertToJSON(v1beta2_device_class_spec_t *v1beta2_device_class_spec) {
    cJSON *item = cJSON_CreateObject();

    // v1beta2_device_class_spec->config
    if(v1beta2_device_class_spec->config) {
    cJSON *config = cJSON_AddArrayToObject(item, "config");
    if(config == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *configListEntry;
    if (v1beta2_device_class_spec->config) {
    list_ForEach(configListEntry, v1beta2_device_class_spec->config) {
    cJSON *itemLocal = v1beta2_device_class_configuration_convertToJSON(configListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(config, itemLocal);
    }
    }
    }


    // v1beta2_device_class_spec->selectors
    if(v1beta2_device_class_spec->selectors) {
    cJSON *selectors = cJSON_AddArrayToObject(item, "selectors");
    if(selectors == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *selectorsListEntry;
    if (v1beta2_device_class_spec->selectors) {
    list_ForEach(selectorsListEntry, v1beta2_device_class_spec->selectors) {
    cJSON *itemLocal = v1beta2_device_selector_convertToJSON(selectorsListEntry->data);
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

v1beta2_device_class_spec_t *v1beta2_device_class_spec_parseFromJSON(cJSON *v1beta2_device_class_specJSON){

    v1beta2_device_class_spec_t *v1beta2_device_class_spec_local_var = NULL;

    // define the local list for v1beta2_device_class_spec->config
    list_t *configList = NULL;

    // define the local list for v1beta2_device_class_spec->selectors
    list_t *selectorsList = NULL;

    // v1beta2_device_class_spec->config
    cJSON *config = cJSON_GetObjectItemCaseSensitive(v1beta2_device_class_specJSON, "config");
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
        v1beta2_device_class_configuration_t *configItem = v1beta2_device_class_configuration_parseFromJSON(config_local_nonprimitive);

        list_addElement(configList, configItem);
    }
    }

    // v1beta2_device_class_spec->selectors
    cJSON *selectors = cJSON_GetObjectItemCaseSensitive(v1beta2_device_class_specJSON, "selectors");
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
        v1beta2_device_selector_t *selectorsItem = v1beta2_device_selector_parseFromJSON(selectors_local_nonprimitive);

        list_addElement(selectorsList, selectorsItem);
    }
    }


    v1beta2_device_class_spec_local_var = v1beta2_device_class_spec_create_internal (
        config ? configList : NULL,
        selectors ? selectorsList : NULL
        );

    return v1beta2_device_class_spec_local_var;
end:
    if (configList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, configList) {
            v1beta2_device_class_configuration_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(configList);
        configList = NULL;
    }
    if (selectorsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, selectorsList) {
            v1beta2_device_selector_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(selectorsList);
        selectorsList = NULL;
    }
    return NULL;

}
