#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_service_cidr_spec.h"



v1beta1_service_cidr_spec_t *v1beta1_service_cidr_spec_create(
    list_t *cidrs
    ) {
    v1beta1_service_cidr_spec_t *v1beta1_service_cidr_spec_local_var = malloc(sizeof(v1beta1_service_cidr_spec_t));
    if (!v1beta1_service_cidr_spec_local_var) {
        return NULL;
    }
    v1beta1_service_cidr_spec_local_var->cidrs = cidrs;

    return v1beta1_service_cidr_spec_local_var;
}


void v1beta1_service_cidr_spec_free(v1beta1_service_cidr_spec_t *v1beta1_service_cidr_spec) {
    if(NULL == v1beta1_service_cidr_spec){
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta1_service_cidr_spec->cidrs) {
        list_ForEach(listEntry, v1beta1_service_cidr_spec->cidrs) {
            free(listEntry->data);
        }
        list_freeList(v1beta1_service_cidr_spec->cidrs);
        v1beta1_service_cidr_spec->cidrs = NULL;
    }
    free(v1beta1_service_cidr_spec);
}

cJSON *v1beta1_service_cidr_spec_convertToJSON(v1beta1_service_cidr_spec_t *v1beta1_service_cidr_spec) {
    cJSON *item = cJSON_CreateObject();

    // v1beta1_service_cidr_spec->cidrs
    if(v1beta1_service_cidr_spec->cidrs) {
    cJSON *cidrs = cJSON_AddArrayToObject(item, "cidrs");
    if(cidrs == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *cidrsListEntry;
    list_ForEach(cidrsListEntry, v1beta1_service_cidr_spec->cidrs) {
    if(cJSON_AddStringToObject(cidrs, "", (char*)cidrsListEntry->data) == NULL)
    {
        goto fail;
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

v1beta1_service_cidr_spec_t *v1beta1_service_cidr_spec_parseFromJSON(cJSON *v1beta1_service_cidr_specJSON){

    v1beta1_service_cidr_spec_t *v1beta1_service_cidr_spec_local_var = NULL;

    // define the local list for v1beta1_service_cidr_spec->cidrs
    list_t *cidrsList = NULL;

    // v1beta1_service_cidr_spec->cidrs
    cJSON *cidrs = cJSON_GetObjectItemCaseSensitive(v1beta1_service_cidr_specJSON, "cidrs");
    if (cidrs) { 
    cJSON *cidrs_local = NULL;
    if(!cJSON_IsArray(cidrs)) {
        goto end;//primitive container
    }
    cidrsList = list_createList();

    cJSON_ArrayForEach(cidrs_local, cidrs)
    {
        if(!cJSON_IsString(cidrs_local))
        {
            goto end;
        }
        list_addElement(cidrsList , strdup(cidrs_local->valuestring));
    }
    }


    v1beta1_service_cidr_spec_local_var = v1beta1_service_cidr_spec_create (
        cidrs ? cidrsList : NULL
        );

    return v1beta1_service_cidr_spec_local_var;
end:
    if (cidrsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, cidrsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(cidrsList);
        cidrsList = NULL;
    }
    return NULL;

}
