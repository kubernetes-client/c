#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_http_ingress_rule_value.h"



v1_http_ingress_rule_value_t *v1_http_ingress_rule_value_create(
    list_t *paths
    ) {
    v1_http_ingress_rule_value_t *v1_http_ingress_rule_value_local_var = malloc(sizeof(v1_http_ingress_rule_value_t));
    if (!v1_http_ingress_rule_value_local_var) {
        return NULL;
    }
    v1_http_ingress_rule_value_local_var->paths = paths;

    return v1_http_ingress_rule_value_local_var;
}


void v1_http_ingress_rule_value_free(v1_http_ingress_rule_value_t *v1_http_ingress_rule_value) {
    if(NULL == v1_http_ingress_rule_value){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_http_ingress_rule_value->paths) {
        list_ForEach(listEntry, v1_http_ingress_rule_value->paths) {
            v1_http_ingress_path_free(listEntry->data);
        }
        list_free(v1_http_ingress_rule_value->paths);
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

    // v1_http_ingress_rule_value->paths
    cJSON *paths = cJSON_GetObjectItemCaseSensitive(v1_http_ingress_rule_valueJSON, "paths");
    if (!paths) {
        goto end;
    }

    list_t *pathsList;
    
    cJSON *paths_local_nonprimitive;
    if(!cJSON_IsArray(paths)){
        goto end; //nonprimitive container
    }

    pathsList = list_create();

    cJSON_ArrayForEach(paths_local_nonprimitive,paths )
    {
        if(!cJSON_IsObject(paths_local_nonprimitive)){
            goto end;
        }
        v1_http_ingress_path_t *pathsItem = v1_http_ingress_path_parseFromJSON(paths_local_nonprimitive);

        list_addElement(pathsList, pathsItem);
    }


    v1_http_ingress_rule_value_local_var = v1_http_ingress_rule_value_create (
        pathsList
        );

    return v1_http_ingress_rule_value_local_var;
end:
    return NULL;

}
