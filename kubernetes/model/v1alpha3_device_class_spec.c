#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha3_device_class_spec.h"



v1alpha3_device_class_spec_t *v1alpha3_device_class_spec_create(
    list_t *config,
    list_t *selectors,
    v1_node_selector_t *suitable_nodes
    ) {
    v1alpha3_device_class_spec_t *v1alpha3_device_class_spec_local_var = malloc(sizeof(v1alpha3_device_class_spec_t));
    if (!v1alpha3_device_class_spec_local_var) {
        return NULL;
    }
    v1alpha3_device_class_spec_local_var->config = config;
    v1alpha3_device_class_spec_local_var->selectors = selectors;
    v1alpha3_device_class_spec_local_var->suitable_nodes = suitable_nodes;

    return v1alpha3_device_class_spec_local_var;
}


void v1alpha3_device_class_spec_free(v1alpha3_device_class_spec_t *v1alpha3_device_class_spec) {
    if(NULL == v1alpha3_device_class_spec){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha3_device_class_spec->config) {
        list_ForEach(listEntry, v1alpha3_device_class_spec->config) {
            v1alpha3_device_class_configuration_free(listEntry->data);
        }
        list_freeList(v1alpha3_device_class_spec->config);
        v1alpha3_device_class_spec->config = NULL;
    }
    if (v1alpha3_device_class_spec->selectors) {
        list_ForEach(listEntry, v1alpha3_device_class_spec->selectors) {
            v1alpha3_device_selector_free(listEntry->data);
        }
        list_freeList(v1alpha3_device_class_spec->selectors);
        v1alpha3_device_class_spec->selectors = NULL;
    }
    if (v1alpha3_device_class_spec->suitable_nodes) {
        v1_node_selector_free(v1alpha3_device_class_spec->suitable_nodes);
        v1alpha3_device_class_spec->suitable_nodes = NULL;
    }
    free(v1alpha3_device_class_spec);
}

cJSON *v1alpha3_device_class_spec_convertToJSON(v1alpha3_device_class_spec_t *v1alpha3_device_class_spec) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha3_device_class_spec->config
    if(v1alpha3_device_class_spec->config) {
    cJSON *config = cJSON_AddArrayToObject(item, "config");
    if(config == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *configListEntry;
    if (v1alpha3_device_class_spec->config) {
    list_ForEach(configListEntry, v1alpha3_device_class_spec->config) {
    cJSON *itemLocal = v1alpha3_device_class_configuration_convertToJSON(configListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(config, itemLocal);
    }
    }
    }


    // v1alpha3_device_class_spec->selectors
    if(v1alpha3_device_class_spec->selectors) {
    cJSON *selectors = cJSON_AddArrayToObject(item, "selectors");
    if(selectors == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *selectorsListEntry;
    if (v1alpha3_device_class_spec->selectors) {
    list_ForEach(selectorsListEntry, v1alpha3_device_class_spec->selectors) {
    cJSON *itemLocal = v1alpha3_device_selector_convertToJSON(selectorsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(selectors, itemLocal);
    }
    }
    }


    // v1alpha3_device_class_spec->suitable_nodes
    if(v1alpha3_device_class_spec->suitable_nodes) {
    cJSON *suitable_nodes_local_JSON = v1_node_selector_convertToJSON(v1alpha3_device_class_spec->suitable_nodes);
    if(suitable_nodes_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "suitableNodes", suitable_nodes_local_JSON);
    if(item->child == NULL) {
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

v1alpha3_device_class_spec_t *v1alpha3_device_class_spec_parseFromJSON(cJSON *v1alpha3_device_class_specJSON){

    v1alpha3_device_class_spec_t *v1alpha3_device_class_spec_local_var = NULL;

    // define the local list for v1alpha3_device_class_spec->config
    list_t *configList = NULL;

    // define the local list for v1alpha3_device_class_spec->selectors
    list_t *selectorsList = NULL;

    // define the local variable for v1alpha3_device_class_spec->suitable_nodes
    v1_node_selector_t *suitable_nodes_local_nonprim = NULL;

    // v1alpha3_device_class_spec->config
    cJSON *config = cJSON_GetObjectItemCaseSensitive(v1alpha3_device_class_specJSON, "config");
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
        v1alpha3_device_class_configuration_t *configItem = v1alpha3_device_class_configuration_parseFromJSON(config_local_nonprimitive);

        list_addElement(configList, configItem);
    }
    }

    // v1alpha3_device_class_spec->selectors
    cJSON *selectors = cJSON_GetObjectItemCaseSensitive(v1alpha3_device_class_specJSON, "selectors");
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
        v1alpha3_device_selector_t *selectorsItem = v1alpha3_device_selector_parseFromJSON(selectors_local_nonprimitive);

        list_addElement(selectorsList, selectorsItem);
    }
    }

    // v1alpha3_device_class_spec->suitable_nodes
    cJSON *suitable_nodes = cJSON_GetObjectItemCaseSensitive(v1alpha3_device_class_specJSON, "suitableNodes");
    if (suitable_nodes) { 
    suitable_nodes_local_nonprim = v1_node_selector_parseFromJSON(suitable_nodes); //nonprimitive
    }


    v1alpha3_device_class_spec_local_var = v1alpha3_device_class_spec_create (
        config ? configList : NULL,
        selectors ? selectorsList : NULL,
        suitable_nodes ? suitable_nodes_local_nonprim : NULL
        );

    return v1alpha3_device_class_spec_local_var;
end:
    if (configList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, configList) {
            v1alpha3_device_class_configuration_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(configList);
        configList = NULL;
    }
    if (selectorsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, selectorsList) {
            v1alpha3_device_selector_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(selectorsList);
        selectorsList = NULL;
    }
    if (suitable_nodes_local_nonprim) {
        v1_node_selector_free(suitable_nodes_local_nonprim);
        suitable_nodes_local_nonprim = NULL;
    }
    return NULL;

}
