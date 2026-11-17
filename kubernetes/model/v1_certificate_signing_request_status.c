#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_certificate_signing_request_status.h"



static v1_certificate_signing_request_status_t *v1_certificate_signing_request_status_create_internal(
    char *certificate,
    list_t *conditions
    ) {
    v1_certificate_signing_request_status_t *v1_certificate_signing_request_status_local_var = malloc(sizeof(v1_certificate_signing_request_status_t));
    if (!v1_certificate_signing_request_status_local_var) {
        return NULL;
    }
    memset(v1_certificate_signing_request_status_local_var, 0, sizeof(v1_certificate_signing_request_status_t));
    v1_certificate_signing_request_status_local_var->_library_owned = 1;
    v1_certificate_signing_request_status_local_var->certificate = certificate;
    v1_certificate_signing_request_status_local_var->conditions = conditions;
    return v1_certificate_signing_request_status_local_var;
}

__attribute__((deprecated)) v1_certificate_signing_request_status_t *v1_certificate_signing_request_status_create(
    char *certificate,
    list_t *conditions
    ) {
    v1_certificate_signing_request_status_t *result = v1_certificate_signing_request_status_create_internal (
        certificate,
        conditions
        );
    if (!result) {
    }
    return result;
}

void v1_certificate_signing_request_status_free(v1_certificate_signing_request_status_t *v1_certificate_signing_request_status) {
    if(NULL == v1_certificate_signing_request_status){
        return ;
    }
    if(v1_certificate_signing_request_status->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_certificate_signing_request_status_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_certificate_signing_request_status->certificate) {
        free(v1_certificate_signing_request_status->certificate);
        v1_certificate_signing_request_status->certificate = NULL;
    }
    if (v1_certificate_signing_request_status->conditions) {
        list_ForEach(listEntry, v1_certificate_signing_request_status->conditions) {
            v1_certificate_signing_request_condition_free(listEntry->data);
        }
        list_freeList(v1_certificate_signing_request_status->conditions);
        v1_certificate_signing_request_status->conditions = NULL;
    }
    free(v1_certificate_signing_request_status);
}

cJSON *v1_certificate_signing_request_status_convertToJSON(v1_certificate_signing_request_status_t *v1_certificate_signing_request_status) {
    cJSON *item = cJSON_CreateObject();

    // v1_certificate_signing_request_status->certificate
    if(v1_certificate_signing_request_status->certificate) {
    if(cJSON_AddStringToObject(item, "certificate", v1_certificate_signing_request_status->certificate) == NULL) {
    goto fail; //ByteArray
    }
    }


    // v1_certificate_signing_request_status->conditions
    if(v1_certificate_signing_request_status->conditions) {
    cJSON *conditions = cJSON_AddArrayToObject(item, "conditions");
    if(conditions == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *conditionsListEntry;
    if (v1_certificate_signing_request_status->conditions) {
    list_ForEach(conditionsListEntry, v1_certificate_signing_request_status->conditions) {
    cJSON *itemLocal = v1_certificate_signing_request_condition_convertToJSON(conditionsListEntry->data);
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

v1_certificate_signing_request_status_t *v1_certificate_signing_request_status_parseFromJSON(cJSON *v1_certificate_signing_request_statusJSON){

    v1_certificate_signing_request_status_t *v1_certificate_signing_request_status_local_var = NULL;

    char *certificate_local_str = NULL;

    // define the local list for v1_certificate_signing_request_status->conditions
    list_t *conditionsList = NULL;

    // v1_certificate_signing_request_status->certificate
    cJSON *certificate = cJSON_GetObjectItemCaseSensitive(v1_certificate_signing_request_statusJSON, "certificate");
    if (cJSON_IsNull(certificate)) {
        certificate = NULL;
    }
    if (certificate) { 
    if(!cJSON_IsString(certificate))
    {
    goto end; //ByteArray
    }
    }

    // v1_certificate_signing_request_status->conditions
    cJSON *conditions = cJSON_GetObjectItemCaseSensitive(v1_certificate_signing_request_statusJSON, "conditions");
    if (cJSON_IsNull(conditions)) {
        conditions = NULL;
    }
    if (conditions) { 
    cJSON *conditions_local_nonprimitive = NULL;
    if(!cJSON_IsArray(conditions)){
        goto end; //nonprimitive container
    }

    conditionsList = list_createList();

    cJSON_ArrayForEach(conditions_local_nonprimitive,conditions )
    {
        if(!cJSON_IsObject(conditions_local_nonprimitive)){
            goto end;
        }
        v1_certificate_signing_request_condition_t *conditionsItem = v1_certificate_signing_request_condition_parseFromJSON(conditions_local_nonprimitive);

        list_addElement(conditionsList, conditionsItem);
    }
    }


    if (certificate) certificate_local_str = strdup(certificate->valuestring);

    v1_certificate_signing_request_status_local_var = v1_certificate_signing_request_status_create_internal (
        certificate_local_str,
        conditions ? conditionsList : NULL
        );

    if (!v1_certificate_signing_request_status_local_var) {
        goto end;
    }

    return v1_certificate_signing_request_status_local_var;
end:
    if (certificate_local_str) {
        free(certificate_local_str);
        certificate_local_str = NULL;
    }
    if (conditionsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, conditionsList) {
            v1_certificate_signing_request_condition_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(conditionsList);
        conditionsList = NULL;
    }
    return NULL;

}
