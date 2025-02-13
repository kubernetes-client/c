#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_uncounted_terminated_pods.h"



static v1_uncounted_terminated_pods_t *v1_uncounted_terminated_pods_create_internal(
    list_t *failed,
    list_t *succeeded
    ) {
    v1_uncounted_terminated_pods_t *v1_uncounted_terminated_pods_local_var = malloc(sizeof(v1_uncounted_terminated_pods_t));
    if (!v1_uncounted_terminated_pods_local_var) {
        return NULL;
    }
    v1_uncounted_terminated_pods_local_var->failed = failed;
    v1_uncounted_terminated_pods_local_var->succeeded = succeeded;

    v1_uncounted_terminated_pods_local_var->_library_owned = 1;
    return v1_uncounted_terminated_pods_local_var;
}

__attribute__((deprecated)) v1_uncounted_terminated_pods_t *v1_uncounted_terminated_pods_create(
    list_t *failed,
    list_t *succeeded
    ) {
    return v1_uncounted_terminated_pods_create_internal (
        failed,
        succeeded
        );
}

void v1_uncounted_terminated_pods_free(v1_uncounted_terminated_pods_t *v1_uncounted_terminated_pods) {
    if(NULL == v1_uncounted_terminated_pods){
        return ;
    }
    if(v1_uncounted_terminated_pods->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_uncounted_terminated_pods_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_uncounted_terminated_pods->failed) {
        list_ForEach(listEntry, v1_uncounted_terminated_pods->failed) {
            free(listEntry->data);
        }
        list_freeList(v1_uncounted_terminated_pods->failed);
        v1_uncounted_terminated_pods->failed = NULL;
    }
    if (v1_uncounted_terminated_pods->succeeded) {
        list_ForEach(listEntry, v1_uncounted_terminated_pods->succeeded) {
            free(listEntry->data);
        }
        list_freeList(v1_uncounted_terminated_pods->succeeded);
        v1_uncounted_terminated_pods->succeeded = NULL;
    }
    free(v1_uncounted_terminated_pods);
}

cJSON *v1_uncounted_terminated_pods_convertToJSON(v1_uncounted_terminated_pods_t *v1_uncounted_terminated_pods) {
    cJSON *item = cJSON_CreateObject();

    // v1_uncounted_terminated_pods->failed
    if(v1_uncounted_terminated_pods->failed) {
    cJSON *failed = cJSON_AddArrayToObject(item, "failed");
    if(failed == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *failedListEntry;
    list_ForEach(failedListEntry, v1_uncounted_terminated_pods->failed) {
    if(cJSON_AddStringToObject(failed, "", failedListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // v1_uncounted_terminated_pods->succeeded
    if(v1_uncounted_terminated_pods->succeeded) {
    cJSON *succeeded = cJSON_AddArrayToObject(item, "succeeded");
    if(succeeded == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *succeededListEntry;
    list_ForEach(succeededListEntry, v1_uncounted_terminated_pods->succeeded) {
    if(cJSON_AddStringToObject(succeeded, "", succeededListEntry->data) == NULL)
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

v1_uncounted_terminated_pods_t *v1_uncounted_terminated_pods_parseFromJSON(cJSON *v1_uncounted_terminated_podsJSON){

    v1_uncounted_terminated_pods_t *v1_uncounted_terminated_pods_local_var = NULL;

    // define the local list for v1_uncounted_terminated_pods->failed
    list_t *failedList = NULL;

    // define the local list for v1_uncounted_terminated_pods->succeeded
    list_t *succeededList = NULL;

    // v1_uncounted_terminated_pods->failed
    cJSON *failed = cJSON_GetObjectItemCaseSensitive(v1_uncounted_terminated_podsJSON, "failed");
    if (cJSON_IsNull(failed)) {
        failed = NULL;
    }
    if (failed) { 
    cJSON *failed_local = NULL;
    if(!cJSON_IsArray(failed)) {
        goto end;//primitive container
    }
    failedList = list_createList();

    cJSON_ArrayForEach(failed_local, failed)
    {
        if(!cJSON_IsString(failed_local))
        {
            goto end;
        }
        list_addElement(failedList , strdup(failed_local->valuestring));
    }
    }

    // v1_uncounted_terminated_pods->succeeded
    cJSON *succeeded = cJSON_GetObjectItemCaseSensitive(v1_uncounted_terminated_podsJSON, "succeeded");
    if (cJSON_IsNull(succeeded)) {
        succeeded = NULL;
    }
    if (succeeded) { 
    cJSON *succeeded_local = NULL;
    if(!cJSON_IsArray(succeeded)) {
        goto end;//primitive container
    }
    succeededList = list_createList();

    cJSON_ArrayForEach(succeeded_local, succeeded)
    {
        if(!cJSON_IsString(succeeded_local))
        {
            goto end;
        }
        list_addElement(succeededList , strdup(succeeded_local->valuestring));
    }
    }


    v1_uncounted_terminated_pods_local_var = v1_uncounted_terminated_pods_create_internal (
        failed ? failedList : NULL,
        succeeded ? succeededList : NULL
        );

    return v1_uncounted_terminated_pods_local_var;
end:
    if (failedList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, failedList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(failedList);
        failedList = NULL;
    }
    if (succeededList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, succeededList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(succeededList);
        succeededList = NULL;
    }
    return NULL;

}
