#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_node_affinity.h"



static v1_node_affinity_t *v1_node_affinity_create_internal(
    list_t *preferred_during_scheduling_ignored_during_execution,
    v1_node_selector_t *required_during_scheduling_ignored_during_execution
    ) {
    v1_node_affinity_t *v1_node_affinity_local_var = malloc(sizeof(v1_node_affinity_t));
    if (!v1_node_affinity_local_var) {
        return NULL;
    }
    v1_node_affinity_local_var->preferred_during_scheduling_ignored_during_execution = preferred_during_scheduling_ignored_during_execution;
    v1_node_affinity_local_var->required_during_scheduling_ignored_during_execution = required_during_scheduling_ignored_during_execution;

    v1_node_affinity_local_var->_library_owned = 1;
    return v1_node_affinity_local_var;
}

__attribute__((deprecated)) v1_node_affinity_t *v1_node_affinity_create(
    list_t *preferred_during_scheduling_ignored_during_execution,
    v1_node_selector_t *required_during_scheduling_ignored_during_execution
    ) {
    return v1_node_affinity_create_internal (
        preferred_during_scheduling_ignored_during_execution,
        required_during_scheduling_ignored_during_execution
        );
}

void v1_node_affinity_free(v1_node_affinity_t *v1_node_affinity) {
    if(NULL == v1_node_affinity){
        return ;
    }
    if(v1_node_affinity->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_node_affinity_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_node_affinity->preferred_during_scheduling_ignored_during_execution) {
        list_ForEach(listEntry, v1_node_affinity->preferred_during_scheduling_ignored_during_execution) {
            v1_preferred_scheduling_term_free(listEntry->data);
        }
        list_freeList(v1_node_affinity->preferred_during_scheduling_ignored_during_execution);
        v1_node_affinity->preferred_during_scheduling_ignored_during_execution = NULL;
    }
    if (v1_node_affinity->required_during_scheduling_ignored_during_execution) {
        v1_node_selector_free(v1_node_affinity->required_during_scheduling_ignored_during_execution);
        v1_node_affinity->required_during_scheduling_ignored_during_execution = NULL;
    }
    free(v1_node_affinity);
}

cJSON *v1_node_affinity_convertToJSON(v1_node_affinity_t *v1_node_affinity) {
    cJSON *item = cJSON_CreateObject();

    // v1_node_affinity->preferred_during_scheduling_ignored_during_execution
    if(v1_node_affinity->preferred_during_scheduling_ignored_during_execution) {
    cJSON *preferred_during_scheduling_ignored_during_execution = cJSON_AddArrayToObject(item, "preferredDuringSchedulingIgnoredDuringExecution");
    if(preferred_during_scheduling_ignored_during_execution == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *preferred_during_scheduling_ignored_during_executionListEntry;
    if (v1_node_affinity->preferred_during_scheduling_ignored_during_execution) {
    list_ForEach(preferred_during_scheduling_ignored_during_executionListEntry, v1_node_affinity->preferred_during_scheduling_ignored_during_execution) {
    cJSON *itemLocal = v1_preferred_scheduling_term_convertToJSON(preferred_during_scheduling_ignored_during_executionListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(preferred_during_scheduling_ignored_during_execution, itemLocal);
    }
    }
    }


    // v1_node_affinity->required_during_scheduling_ignored_during_execution
    if(v1_node_affinity->required_during_scheduling_ignored_during_execution) {
    cJSON *required_during_scheduling_ignored_during_execution_local_JSON = v1_node_selector_convertToJSON(v1_node_affinity->required_during_scheduling_ignored_during_execution);
    if(required_during_scheduling_ignored_during_execution_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "requiredDuringSchedulingIgnoredDuringExecution", required_during_scheduling_ignored_during_execution_local_JSON);
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

v1_node_affinity_t *v1_node_affinity_parseFromJSON(cJSON *v1_node_affinityJSON){

    v1_node_affinity_t *v1_node_affinity_local_var = NULL;

    // define the local list for v1_node_affinity->preferred_during_scheduling_ignored_during_execution
    list_t *preferred_during_scheduling_ignored_during_executionList = NULL;

    // define the local variable for v1_node_affinity->required_during_scheduling_ignored_during_execution
    v1_node_selector_t *required_during_scheduling_ignored_during_execution_local_nonprim = NULL;

    // v1_node_affinity->preferred_during_scheduling_ignored_during_execution
    cJSON *preferred_during_scheduling_ignored_during_execution = cJSON_GetObjectItemCaseSensitive(v1_node_affinityJSON, "preferredDuringSchedulingIgnoredDuringExecution");
    if (cJSON_IsNull(preferred_during_scheduling_ignored_during_execution)) {
        preferred_during_scheduling_ignored_during_execution = NULL;
    }
    if (preferred_during_scheduling_ignored_during_execution) { 
    cJSON *preferred_during_scheduling_ignored_during_execution_local_nonprimitive = NULL;
    if(!cJSON_IsArray(preferred_during_scheduling_ignored_during_execution)){
        goto end; //nonprimitive container
    }

    preferred_during_scheduling_ignored_during_executionList = list_createList();

    cJSON_ArrayForEach(preferred_during_scheduling_ignored_during_execution_local_nonprimitive,preferred_during_scheduling_ignored_during_execution )
    {
        if(!cJSON_IsObject(preferred_during_scheduling_ignored_during_execution_local_nonprimitive)){
            goto end;
        }
        v1_preferred_scheduling_term_t *preferred_during_scheduling_ignored_during_executionItem = v1_preferred_scheduling_term_parseFromJSON(preferred_during_scheduling_ignored_during_execution_local_nonprimitive);

        list_addElement(preferred_during_scheduling_ignored_during_executionList, preferred_during_scheduling_ignored_during_executionItem);
    }
    }

    // v1_node_affinity->required_during_scheduling_ignored_during_execution
    cJSON *required_during_scheduling_ignored_during_execution = cJSON_GetObjectItemCaseSensitive(v1_node_affinityJSON, "requiredDuringSchedulingIgnoredDuringExecution");
    if (cJSON_IsNull(required_during_scheduling_ignored_during_execution)) {
        required_during_scheduling_ignored_during_execution = NULL;
    }
    if (required_during_scheduling_ignored_during_execution) { 
    required_during_scheduling_ignored_during_execution_local_nonprim = v1_node_selector_parseFromJSON(required_during_scheduling_ignored_during_execution); //nonprimitive
    }


    v1_node_affinity_local_var = v1_node_affinity_create_internal (
        preferred_during_scheduling_ignored_during_execution ? preferred_during_scheduling_ignored_during_executionList : NULL,
        required_during_scheduling_ignored_during_execution ? required_during_scheduling_ignored_during_execution_local_nonprim : NULL
        );

    return v1_node_affinity_local_var;
end:
    if (preferred_during_scheduling_ignored_during_executionList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, preferred_during_scheduling_ignored_during_executionList) {
            v1_preferred_scheduling_term_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(preferred_during_scheduling_ignored_during_executionList);
        preferred_during_scheduling_ignored_during_executionList = NULL;
    }
    if (required_during_scheduling_ignored_during_execution_local_nonprim) {
        v1_node_selector_free(required_during_scheduling_ignored_during_execution_local_nonprim);
        required_during_scheduling_ignored_during_execution_local_nonprim = NULL;
    }
    return NULL;

}
