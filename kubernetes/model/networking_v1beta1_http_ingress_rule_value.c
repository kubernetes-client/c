#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "networking_v1beta1_http_ingress_rule_value.h"



networking_v1beta1_http_ingress_rule_value_t *networking_v1beta1_http_ingress_rule_value_create(
    list_t *paths
    ) {
    networking_v1beta1_http_ingress_rule_value_t *networking_v1beta1_http_ingress_rule_value_local_var = malloc(sizeof(networking_v1beta1_http_ingress_rule_value_t));
    if (!networking_v1beta1_http_ingress_rule_value_local_var) {
        return NULL;
    }
    networking_v1beta1_http_ingress_rule_value_local_var->paths = paths;

    return networking_v1beta1_http_ingress_rule_value_local_var;
}


void networking_v1beta1_http_ingress_rule_value_free(networking_v1beta1_http_ingress_rule_value_t *networking_v1beta1_http_ingress_rule_value) {
    if(NULL == networking_v1beta1_http_ingress_rule_value){
        return ;
    }
    listEntry_t *listEntry;
    if (networking_v1beta1_http_ingress_rule_value->paths) {
        list_ForEach(listEntry, networking_v1beta1_http_ingress_rule_value->paths) {
            networking_v1beta1_http_ingress_path_free(listEntry->data);
        }
        list_free(networking_v1beta1_http_ingress_rule_value->paths);
        networking_v1beta1_http_ingress_rule_value->paths = NULL;
    }
    free(networking_v1beta1_http_ingress_rule_value);
}

cJSON *networking_v1beta1_http_ingress_rule_value_convertToJSON(networking_v1beta1_http_ingress_rule_value_t *networking_v1beta1_http_ingress_rule_value) {
    cJSON *item = cJSON_CreateObject();

    // networking_v1beta1_http_ingress_rule_value->paths
    if (!networking_v1beta1_http_ingress_rule_value->paths) {
        goto fail;
    }
    
    cJSON *paths = cJSON_AddArrayToObject(item, "paths");
    if(paths == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *pathsListEntry;
    if (networking_v1beta1_http_ingress_rule_value->paths) {
    list_ForEach(pathsListEntry, networking_v1beta1_http_ingress_rule_value->paths) {
    cJSON *itemLocal = networking_v1beta1_http_ingress_path_convertToJSON(pathsListEntry->data);
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

networking_v1beta1_http_ingress_rule_value_t *networking_v1beta1_http_ingress_rule_value_parseFromJSON(cJSON *networking_v1beta1_http_ingress_rule_valueJSON){

    networking_v1beta1_http_ingress_rule_value_t *networking_v1beta1_http_ingress_rule_value_local_var = NULL;

    // networking_v1beta1_http_ingress_rule_value->paths
    cJSON *paths = cJSON_GetObjectItemCaseSensitive(networking_v1beta1_http_ingress_rule_valueJSON, "paths");
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
        networking_v1beta1_http_ingress_path_t *pathsItem = networking_v1beta1_http_ingress_path_parseFromJSON(paths_local_nonprimitive);

        list_addElement(pathsList, pathsItem);
    }


    networking_v1beta1_http_ingress_rule_value_local_var = networking_v1beta1_http_ingress_rule_value_create (
        pathsList
        );

    return networking_v1beta1_http_ingress_rule_value_local_var;
end:
    return NULL;

}
