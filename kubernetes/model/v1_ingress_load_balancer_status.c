#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_ingress_load_balancer_status.h"



static v1_ingress_load_balancer_status_t *v1_ingress_load_balancer_status_create_internal(
    list_t *ingress
    ) {
    v1_ingress_load_balancer_status_t *v1_ingress_load_balancer_status_local_var = malloc(sizeof(v1_ingress_load_balancer_status_t));
    if (!v1_ingress_load_balancer_status_local_var) {
        return NULL;
    }
    v1_ingress_load_balancer_status_local_var->ingress = ingress;

    v1_ingress_load_balancer_status_local_var->_library_owned = 1;
    return v1_ingress_load_balancer_status_local_var;
}

__attribute__((deprecated)) v1_ingress_load_balancer_status_t *v1_ingress_load_balancer_status_create(
    list_t *ingress
    ) {
    return v1_ingress_load_balancer_status_create_internal (
        ingress
        );
}

void v1_ingress_load_balancer_status_free(v1_ingress_load_balancer_status_t *v1_ingress_load_balancer_status) {
    if(NULL == v1_ingress_load_balancer_status){
        return ;
    }
    if(v1_ingress_load_balancer_status->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_ingress_load_balancer_status_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_ingress_load_balancer_status->ingress) {
        list_ForEach(listEntry, v1_ingress_load_balancer_status->ingress) {
            v1_ingress_load_balancer_ingress_free(listEntry->data);
        }
        list_freeList(v1_ingress_load_balancer_status->ingress);
        v1_ingress_load_balancer_status->ingress = NULL;
    }
    free(v1_ingress_load_balancer_status);
}

cJSON *v1_ingress_load_balancer_status_convertToJSON(v1_ingress_load_balancer_status_t *v1_ingress_load_balancer_status) {
    cJSON *item = cJSON_CreateObject();

    // v1_ingress_load_balancer_status->ingress
    if(v1_ingress_load_balancer_status->ingress) {
    cJSON *ingress = cJSON_AddArrayToObject(item, "ingress");
    if(ingress == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *ingressListEntry;
    if (v1_ingress_load_balancer_status->ingress) {
    list_ForEach(ingressListEntry, v1_ingress_load_balancer_status->ingress) {
    cJSON *itemLocal = v1_ingress_load_balancer_ingress_convertToJSON(ingressListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(ingress, itemLocal);
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

v1_ingress_load_balancer_status_t *v1_ingress_load_balancer_status_parseFromJSON(cJSON *v1_ingress_load_balancer_statusJSON){

    v1_ingress_load_balancer_status_t *v1_ingress_load_balancer_status_local_var = NULL;

    // define the local list for v1_ingress_load_balancer_status->ingress
    list_t *ingressList = NULL;

    // v1_ingress_load_balancer_status->ingress
    cJSON *ingress = cJSON_GetObjectItemCaseSensitive(v1_ingress_load_balancer_statusJSON, "ingress");
    if (cJSON_IsNull(ingress)) {
        ingress = NULL;
    }
    if (ingress) { 
    cJSON *ingress_local_nonprimitive = NULL;
    if(!cJSON_IsArray(ingress)){
        goto end; //nonprimitive container
    }

    ingressList = list_createList();

    cJSON_ArrayForEach(ingress_local_nonprimitive,ingress )
    {
        if(!cJSON_IsObject(ingress_local_nonprimitive)){
            goto end;
        }
        v1_ingress_load_balancer_ingress_t *ingressItem = v1_ingress_load_balancer_ingress_parseFromJSON(ingress_local_nonprimitive);

        list_addElement(ingressList, ingressItem);
    }
    }


    v1_ingress_load_balancer_status_local_var = v1_ingress_load_balancer_status_create_internal (
        ingress ? ingressList : NULL
        );

    return v1_ingress_load_balancer_status_local_var;
end:
    if (ingressList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, ingressList) {
            v1_ingress_load_balancer_ingress_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(ingressList);
        ingressList = NULL;
    }
    return NULL;

}
