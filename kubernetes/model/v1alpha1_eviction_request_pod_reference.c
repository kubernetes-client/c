#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha1_eviction_request_pod_reference.h"



static v1alpha1_eviction_request_pod_reference_t *v1alpha1_eviction_request_pod_reference_create_internal(
    char *name,
    char *uid
    ) {
    v1alpha1_eviction_request_pod_reference_t *v1alpha1_eviction_request_pod_reference_local_var = malloc(sizeof(v1alpha1_eviction_request_pod_reference_t));
    if (!v1alpha1_eviction_request_pod_reference_local_var) {
        return NULL;
    }
    memset(v1alpha1_eviction_request_pod_reference_local_var, 0, sizeof(v1alpha1_eviction_request_pod_reference_t));
    v1alpha1_eviction_request_pod_reference_local_var->_library_owned = 1;
    v1alpha1_eviction_request_pod_reference_local_var->name = name;
    v1alpha1_eviction_request_pod_reference_local_var->uid = uid;
    return v1alpha1_eviction_request_pod_reference_local_var;
}

__attribute__((deprecated)) v1alpha1_eviction_request_pod_reference_t *v1alpha1_eviction_request_pod_reference_create(
    char *name,
    char *uid
    ) {
    v1alpha1_eviction_request_pod_reference_t *result = v1alpha1_eviction_request_pod_reference_create_internal (
        name,
        uid
        );
    if (!result) {
    }
    return result;
}

void v1alpha1_eviction_request_pod_reference_free(v1alpha1_eviction_request_pod_reference_t *v1alpha1_eviction_request_pod_reference) {
    if(NULL == v1alpha1_eviction_request_pod_reference){
        return ;
    }
    if(v1alpha1_eviction_request_pod_reference->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1alpha1_eviction_request_pod_reference_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha1_eviction_request_pod_reference->name) {
        free(v1alpha1_eviction_request_pod_reference->name);
        v1alpha1_eviction_request_pod_reference->name = NULL;
    }
    if (v1alpha1_eviction_request_pod_reference->uid) {
        free(v1alpha1_eviction_request_pod_reference->uid);
        v1alpha1_eviction_request_pod_reference->uid = NULL;
    }
    free(v1alpha1_eviction_request_pod_reference);
}

cJSON *v1alpha1_eviction_request_pod_reference_convertToJSON(v1alpha1_eviction_request_pod_reference_t *v1alpha1_eviction_request_pod_reference) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha1_eviction_request_pod_reference->name
    if (!v1alpha1_eviction_request_pod_reference->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", v1alpha1_eviction_request_pod_reference->name) == NULL) {
    goto fail; //String
    }


    // v1alpha1_eviction_request_pod_reference->uid
    if (!v1alpha1_eviction_request_pod_reference->uid) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "uid", v1alpha1_eviction_request_pod_reference->uid) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1alpha1_eviction_request_pod_reference_t *v1alpha1_eviction_request_pod_reference_parseFromJSON(cJSON *v1alpha1_eviction_request_pod_referenceJSON){

    v1alpha1_eviction_request_pod_reference_t *v1alpha1_eviction_request_pod_reference_local_var = NULL;

    char *name_local_str = NULL;

    char *uid_local_str = NULL;

    // v1alpha1_eviction_request_pod_reference->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1alpha1_eviction_request_pod_referenceJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // v1alpha1_eviction_request_pod_reference->uid
    cJSON *uid = cJSON_GetObjectItemCaseSensitive(v1alpha1_eviction_request_pod_referenceJSON, "uid");
    if (cJSON_IsNull(uid)) {
        uid = NULL;
    }
    if (!uid) {
        goto end;
    }

    
    if(!cJSON_IsString(uid))
    {
    goto end; //String
    }


    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);
    if (uid && !cJSON_IsNull(uid)) uid_local_str = strdup(uid->valuestring);

    v1alpha1_eviction_request_pod_reference_local_var = v1alpha1_eviction_request_pod_reference_create_internal (
        name_local_str,
        uid_local_str
        );

    if (!v1alpha1_eviction_request_pod_reference_local_var) {
        goto end;
    }

    return v1alpha1_eviction_request_pod_reference_local_var;
end:
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    if (uid_local_str) {
        free(uid_local_str);
        uid_local_str = NULL;
    }
    return NULL;

}
