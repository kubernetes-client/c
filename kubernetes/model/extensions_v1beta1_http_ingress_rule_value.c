#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "extensions_v1beta1_http_ingress_rule_value.h"



extensions_v1beta1_http_ingress_rule_value_t *extensions_v1beta1_http_ingress_rule_value_create(
    list_t *paths
    ) {
    extensions_v1beta1_http_ingress_rule_value_t *extensions_v1beta1_http_ingress_rule_value_local_var = malloc(sizeof(extensions_v1beta1_http_ingress_rule_value_t));
    if (!extensions_v1beta1_http_ingress_rule_value_local_var) {
        return NULL;
    }
    extensions_v1beta1_http_ingress_rule_value_local_var->paths = paths;

    return extensions_v1beta1_http_ingress_rule_value_local_var;
}


void extensions_v1beta1_http_ingress_rule_value_free(extensions_v1beta1_http_ingress_rule_value_t *extensions_v1beta1_http_ingress_rule_value) {
    if(NULL == extensions_v1beta1_http_ingress_rule_value){
        return ;
    }
    listEntry_t *listEntry;
    if (extensions_v1beta1_http_ingress_rule_value->paths) {
        list_ForEach(listEntry, extensions_v1beta1_http_ingress_rule_value->paths) {
            extensions_v1beta1_http_ingress_path_free(listEntry->data);
        }
        list_free(extensions_v1beta1_http_ingress_rule_value->paths);
        extensions_v1beta1_http_ingress_rule_value->paths = NULL;
    }
    free(extensions_v1beta1_http_ingress_rule_value);
}

cJSON *extensions_v1beta1_http_ingress_rule_value_convertToJSON(extensions_v1beta1_http_ingress_rule_value_t *extensions_v1beta1_http_ingress_rule_value) {
    cJSON *item = cJSON_CreateObject();

    // extensions_v1beta1_http_ingress_rule_value->paths
    if (!extensions_v1beta1_http_ingress_rule_value->paths) {
        goto fail;
    }
    
    cJSON *paths = cJSON_AddArrayToObject(item, "paths");
    if(paths == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *pathsListEntry;
    if (extensions_v1beta1_http_ingress_rule_value->paths) {
    list_ForEach(pathsListEntry, extensions_v1beta1_http_ingress_rule_value->paths) {
    cJSON *itemLocal = extensions_v1beta1_http_ingress_path_convertToJSON(pathsListEntry->data);
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

extensions_v1beta1_http_ingress_rule_value_t *extensions_v1beta1_http_ingress_rule_value_parseFromJSON(cJSON *extensions_v1beta1_http_ingress_rule_valueJSON){

    extensions_v1beta1_http_ingress_rule_value_t *extensions_v1beta1_http_ingress_rule_value_local_var = NULL;

    // extensions_v1beta1_http_ingress_rule_value->paths
    cJSON *paths = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_http_ingress_rule_valueJSON, "paths");
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
        extensions_v1beta1_http_ingress_path_t *pathsItem = extensions_v1beta1_http_ingress_path_parseFromJSON(paths_local_nonprimitive);

        list_addElement(pathsList, pathsItem);
    }


    extensions_v1beta1_http_ingress_rule_value_local_var = extensions_v1beta1_http_ingress_rule_value_create (
        pathsList
        );

    return extensions_v1beta1_http_ingress_rule_value_local_var;
end:
    return NULL;

}
