#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_certificate_signing_request_status.h"



v1beta1_certificate_signing_request_status_t *v1beta1_certificate_signing_request_status_create(
    char *certificate,
    list_t *conditions
    ) {
    v1beta1_certificate_signing_request_status_t *v1beta1_certificate_signing_request_status_local_var = malloc(sizeof(v1beta1_certificate_signing_request_status_t));
    if (!v1beta1_certificate_signing_request_status_local_var) {
        return NULL;
    }
    v1beta1_certificate_signing_request_status_local_var->certificate = certificate;
    v1beta1_certificate_signing_request_status_local_var->conditions = conditions;

    return v1beta1_certificate_signing_request_status_local_var;
}


void v1beta1_certificate_signing_request_status_free(v1beta1_certificate_signing_request_status_t *v1beta1_certificate_signing_request_status) {
    if(NULL == v1beta1_certificate_signing_request_status){
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta1_certificate_signing_request_status->certificate) {
        free(v1beta1_certificate_signing_request_status->certificate);
        v1beta1_certificate_signing_request_status->certificate = NULL;
    }
    if (v1beta1_certificate_signing_request_status->conditions) {
        list_ForEach(listEntry, v1beta1_certificate_signing_request_status->conditions) {
            v1beta1_certificate_signing_request_condition_free(listEntry->data);
        }
        list_free(v1beta1_certificate_signing_request_status->conditions);
        v1beta1_certificate_signing_request_status->conditions = NULL;
    }
    free(v1beta1_certificate_signing_request_status);
}

cJSON *v1beta1_certificate_signing_request_status_convertToJSON(v1beta1_certificate_signing_request_status_t *v1beta1_certificate_signing_request_status) {
    cJSON *item = cJSON_CreateObject();

    // v1beta1_certificate_signing_request_status->certificate
    if(v1beta1_certificate_signing_request_status->certificate) { 
    if(cJSON_AddStringToObject(item, "certificate", v1beta1_certificate_signing_request_status->certificate) == NULL) {
    goto fail; //ByteArray
    }
     } 


    // v1beta1_certificate_signing_request_status->conditions
    if(v1beta1_certificate_signing_request_status->conditions) { 
    cJSON *conditions = cJSON_AddArrayToObject(item, "conditions");
    if(conditions == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *conditionsListEntry;
    if (v1beta1_certificate_signing_request_status->conditions) {
    list_ForEach(conditionsListEntry, v1beta1_certificate_signing_request_status->conditions) {
    cJSON *itemLocal = v1beta1_certificate_signing_request_condition_convertToJSON(conditionsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(conditions, itemLocal);
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

v1beta1_certificate_signing_request_status_t *v1beta1_certificate_signing_request_status_parseFromJSON(cJSON *v1beta1_certificate_signing_request_statusJSON){

    v1beta1_certificate_signing_request_status_t *v1beta1_certificate_signing_request_status_local_var = NULL;

    // v1beta1_certificate_signing_request_status->certificate
    cJSON *certificate = cJSON_GetObjectItemCaseSensitive(v1beta1_certificate_signing_request_statusJSON, "certificate");
    if (certificate) { 
    if(!cJSON_IsString(certificate))
    {
    goto end; //ByteArray
    }
    }

    // v1beta1_certificate_signing_request_status->conditions
    cJSON *conditions = cJSON_GetObjectItemCaseSensitive(v1beta1_certificate_signing_request_statusJSON, "conditions");
    list_t *conditionsList;
    if (conditions) { 
    cJSON *conditions_local_nonprimitive;
    if(!cJSON_IsArray(conditions)){
        goto end; //nonprimitive container
    }

    conditionsList = list_create();

    cJSON_ArrayForEach(conditions_local_nonprimitive,conditions )
    {
        if(!cJSON_IsObject(conditions_local_nonprimitive)){
            goto end;
        }
        v1beta1_certificate_signing_request_condition_t *conditionsItem = v1beta1_certificate_signing_request_condition_parseFromJSON(conditions_local_nonprimitive);

        list_addElement(conditionsList, conditionsItem);
    }
    }


    v1beta1_certificate_signing_request_status_local_var = v1beta1_certificate_signing_request_status_create (
        certificate ? strdup(certificate->valuestring) : NULL,
        conditions ? conditionsList : NULL
        );

    return v1beta1_certificate_signing_request_status_local_var;
end:
    return NULL;

}
