#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha1_eviction_request_spec.h"



static v1alpha1_eviction_request_spec_t *v1alpha1_eviction_request_spec_create_internal(
    char *intent,
    char *requester,
    v1alpha1_eviction_request_target_t *target
    ) {
    v1alpha1_eviction_request_spec_t *v1alpha1_eviction_request_spec_local_var = malloc(sizeof(v1alpha1_eviction_request_spec_t));
    if (!v1alpha1_eviction_request_spec_local_var) {
        return NULL;
    }
    memset(v1alpha1_eviction_request_spec_local_var, 0, sizeof(v1alpha1_eviction_request_spec_t));
    v1alpha1_eviction_request_spec_local_var->_library_owned = 1;
    v1alpha1_eviction_request_spec_local_var->intent = intent;
    v1alpha1_eviction_request_spec_local_var->requester = requester;
    v1alpha1_eviction_request_spec_local_var->target = target;
    return v1alpha1_eviction_request_spec_local_var;
}

__attribute__((deprecated)) v1alpha1_eviction_request_spec_t *v1alpha1_eviction_request_spec_create(
    char *intent,
    char *requester,
    v1alpha1_eviction_request_target_t *target
    ) {
    v1alpha1_eviction_request_spec_t *result = v1alpha1_eviction_request_spec_create_internal (
        intent,
        requester,
        target
        );
    if (!result) {
    }
    return result;
}

void v1alpha1_eviction_request_spec_free(v1alpha1_eviction_request_spec_t *v1alpha1_eviction_request_spec) {
    if(NULL == v1alpha1_eviction_request_spec){
        return ;
    }
    if(v1alpha1_eviction_request_spec->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1alpha1_eviction_request_spec_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha1_eviction_request_spec->intent) {
        free(v1alpha1_eviction_request_spec->intent);
        v1alpha1_eviction_request_spec->intent = NULL;
    }
    if (v1alpha1_eviction_request_spec->requester) {
        free(v1alpha1_eviction_request_spec->requester);
        v1alpha1_eviction_request_spec->requester = NULL;
    }
    if (v1alpha1_eviction_request_spec->target) {
        v1alpha1_eviction_request_target_free(v1alpha1_eviction_request_spec->target);
        v1alpha1_eviction_request_spec->target = NULL;
    }
    free(v1alpha1_eviction_request_spec);
}

cJSON *v1alpha1_eviction_request_spec_convertToJSON(v1alpha1_eviction_request_spec_t *v1alpha1_eviction_request_spec) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha1_eviction_request_spec->intent
    if (!v1alpha1_eviction_request_spec->intent) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "intent", v1alpha1_eviction_request_spec->intent) == NULL) {
    goto fail; //String
    }


    // v1alpha1_eviction_request_spec->requester
    if (!v1alpha1_eviction_request_spec->requester) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "requester", v1alpha1_eviction_request_spec->requester) == NULL) {
    goto fail; //String
    }


    // v1alpha1_eviction_request_spec->target
    if (!v1alpha1_eviction_request_spec->target) {
        goto fail;
    }
    cJSON *target_local_JSON = v1alpha1_eviction_request_target_convertToJSON(v1alpha1_eviction_request_spec->target);
    if(target_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "target", target_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1alpha1_eviction_request_spec_t *v1alpha1_eviction_request_spec_parseFromJSON(cJSON *v1alpha1_eviction_request_specJSON){

    v1alpha1_eviction_request_spec_t *v1alpha1_eviction_request_spec_local_var = NULL;

    char *intent_local_str = NULL;

    char *requester_local_str = NULL;

    // define the local variable for v1alpha1_eviction_request_spec->target
    v1alpha1_eviction_request_target_t *target_local_nonprim = NULL;

    // v1alpha1_eviction_request_spec->intent
    cJSON *intent = cJSON_GetObjectItemCaseSensitive(v1alpha1_eviction_request_specJSON, "intent");
    if (cJSON_IsNull(intent)) {
        intent = NULL;
    }
    if (!intent) {
        goto end;
    }

    
    if(!cJSON_IsString(intent))
    {
    goto end; //String
    }

    // v1alpha1_eviction_request_spec->requester
    cJSON *requester = cJSON_GetObjectItemCaseSensitive(v1alpha1_eviction_request_specJSON, "requester");
    if (cJSON_IsNull(requester)) {
        requester = NULL;
    }
    if (!requester) {
        goto end;
    }

    
    if(!cJSON_IsString(requester))
    {
    goto end; //String
    }

    // v1alpha1_eviction_request_spec->target
    cJSON *target = cJSON_GetObjectItemCaseSensitive(v1alpha1_eviction_request_specJSON, "target");
    if (cJSON_IsNull(target)) {
        target = NULL;
    }
    if (!target) {
        goto end;
    }

    
    target_local_nonprim = v1alpha1_eviction_request_target_parseFromJSON(target); //nonprimitive


    if (intent && !cJSON_IsNull(intent)) intent_local_str = strdup(intent->valuestring);
    if (requester && !cJSON_IsNull(requester)) requester_local_str = strdup(requester->valuestring);

    v1alpha1_eviction_request_spec_local_var = v1alpha1_eviction_request_spec_create_internal (
        intent_local_str,
        requester_local_str,
        target_local_nonprim
        );

    if (!v1alpha1_eviction_request_spec_local_var) {
        goto end;
    }

    return v1alpha1_eviction_request_spec_local_var;
end:
    if (intent_local_str) {
        free(intent_local_str);
        intent_local_str = NULL;
    }
    if (requester_local_str) {
        free(requester_local_str);
        requester_local_str = NULL;
    }
    if (target_local_nonprim) {
        v1alpha1_eviction_request_target_free(target_local_nonprim);
        target_local_nonprim = NULL;
    }
    return NULL;

}
