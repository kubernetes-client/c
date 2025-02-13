#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_http_ingress_rule_value.h"



static v1_http_ingress_rule_value_t *v1_http_ingress_rule_value_create_internal(
    list_t *paths
    ) {
    v1_http_ingress_rule_value_t *v1_http_ingress_rule_value_local_var = malloc(sizeof(v1_http_ingress_rule_value_t));
    if (!v1_http_ingress_rule_value_local_var) {
        return NULL;
    }
    v1_http_ingress_rule_value_local_var->paths = paths;

    v1_http_ingress_rule_value_local_var->_library_owned = 1;
    return v1_http_ingress_rule_value_local_var;
}

__attribute__((deprecated)) v1_http_ingress_rule_value_t *v1_http_ingress_rule_value_create(
    list_t *paths
    ) {
    return v1_http_ingress_rule_value_create_internal (
        paths
        );
}

void v1_http_ingress_rule_value_free(v1_http_ingress_rule_value_t *v1_http_ingress_rule_value) {
    if(NULL == v1_http_ingress_rule_value){
        return ;
    }
    if(v1_http_ingress_rule_value->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_http_ingress_rule_value_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_http_ingress_rule_value->paths) {
        list_ForEach(listEntry, v1_http_ingress_rule_value->paths) {
            v1_http_ingress_path_free(listEntry->data);
        }
        list_freeList(v1_http_ingress_rule_value->paths);
        v1_http_ingress_rule_value->paths = NULL;
    }
    free(v1_http_ingress_rule_value);
}

cJSON *v1_http_ingress_rule_value_convertToJSON(v1_http_ingress_rule_value_t *v1_http_ingress_rule_value) {
    cJSON *item = cJSON_CreateObject();

    // v1_http_ingress_rule_value->paths
    if (!v1_http_ingress_rule_value->paths) {
        goto fail;
    }
    cJSON *paths = cJSON_AddArrayToObject(item, "paths");
    if(paths == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *pathsListEntry;
    if (v1_http_ingress_rule_value->paths) {
    list_ForEach(pathsListEntry, v1_http_ingress_rule_value->paths) {
    cJSON *itemLocal = v1_http_ingress_path_convertToJSON(pathsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(paths, itemLocal);
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_http_ingress_rule_value_t *v1_http_ingress_rule_value_parseFromJSON(cJSON *v1_http_ingress_rule_valueJSON){

    v1_http_ingress_rule_value_t *v1_http_ingress_rule_value_local_var = NULL;

    // define the local list for v1_http_ingress_rule_value->paths
    list_t *pathsList = NULL;

    // v1_http_ingress_rule_value->paths
    cJSON *paths = cJSON_GetObjectItemCaseSensitive(v1_http_ingress_rule_valueJSON, "paths");
    if (cJSON_IsNull(paths)) {
        paths = NULL;
    }
    if (!paths) {
        goto end;
    }

    
    cJSON *paths_local_nonprimitive = NULL;
    if(!cJSON_IsArray(paths)){
        goto end; //nonprimitive container
    }

    pathsList = list_createList();

    cJSON_ArrayForEach(paths_local_nonprimitive,paths )
    {
        if(!cJSON_IsObject(paths_local_nonprimitive)){
            goto end;
        }
        v1_http_ingress_path_t *pathsItem = v1_http_ingress_path_parseFromJSON(paths_local_nonprimitive);

        list_addElement(pathsList, pathsItem);
    }


    v1_http_ingress_rule_value_local_var = v1_http_ingress_rule_value_create_internal (
        pathsList
        );

    return v1_http_ingress_rule_value_local_var;
end:
    if (pathsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, pathsList) {
            v1_http_ingress_path_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(pathsList);
        pathsList = NULL;
    }
    return NULL;

}
