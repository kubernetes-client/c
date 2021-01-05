#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_load_balancer_status.h"



v1_load_balancer_status_t *v1_load_balancer_status_create(
    list_t *ingress
    ) {
    v1_load_balancer_status_t *v1_load_balancer_status_local_var = malloc(sizeof(v1_load_balancer_status_t));
    if (!v1_load_balancer_status_local_var) {
        return NULL;
    }
    v1_load_balancer_status_local_var->ingress = ingress;

    return v1_load_balancer_status_local_var;
}


void v1_load_balancer_status_free(v1_load_balancer_status_t *v1_load_balancer_status) {
    if(NULL == v1_load_balancer_status){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_load_balancer_status->ingress) {
        list_ForEach(listEntry, v1_load_balancer_status->ingress) {
            v1_load_balancer_ingress_free(listEntry->data);
        }
        list_free(v1_load_balancer_status->ingress);
        v1_load_balancer_status->ingress = NULL;
    }
    free(v1_load_balancer_status);
}

cJSON *v1_load_balancer_status_convertToJSON(v1_load_balancer_status_t *v1_load_balancer_status) {
    cJSON *item = cJSON_CreateObject();

    // v1_load_balancer_status->ingress
    if(v1_load_balancer_status->ingress) { 
    cJSON *ingress = cJSON_AddArrayToObject(item, "ingress");
    if(ingress == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *ingressListEntry;
    if (v1_load_balancer_status->ingress) {
    list_ForEach(ingressListEntry, v1_load_balancer_status->ingress) {
    cJSON *itemLocal = v1_load_balancer_ingress_convertToJSON(ingressListEntry->data);
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

v1_load_balancer_status_t *v1_load_balancer_status_parseFromJSON(cJSON *v1_load_balancer_statusJSON){

    v1_load_balancer_status_t *v1_load_balancer_status_local_var = NULL;

    // v1_load_balancer_status->ingress
    cJSON *ingress = cJSON_GetObjectItemCaseSensitive(v1_load_balancer_statusJSON, "ingress");
    list_t *ingressList;
    if (ingress) { 
    cJSON *ingress_local_nonprimitive;
    if(!cJSON_IsArray(ingress)){
        goto end; //nonprimitive container
    }

    ingressList = list_create();

    cJSON_ArrayForEach(ingress_local_nonprimitive,ingress )
    {
        if(!cJSON_IsObject(ingress_local_nonprimitive)){
            goto end;
        }
        v1_load_balancer_ingress_t *ingressItem = v1_load_balancer_ingress_parseFromJSON(ingress_local_nonprimitive);

        list_addElement(ingressList, ingressItem);
    }
    }


    v1_load_balancer_status_local_var = v1_load_balancer_status_create (
        ingress ? ingressList : NULL
        );

    return v1_load_balancer_status_local_var;
end:
    return NULL;

}
