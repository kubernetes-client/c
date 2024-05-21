#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha2_named_resources_request.h"



v1alpha2_named_resources_request_t *v1alpha2_named_resources_request_create(
    char *selector
    ) {
    v1alpha2_named_resources_request_t *v1alpha2_named_resources_request_local_var = malloc(sizeof(v1alpha2_named_resources_request_t));
    if (!v1alpha2_named_resources_request_local_var) {
        return NULL;
    }
    v1alpha2_named_resources_request_local_var->selector = selector;

    return v1alpha2_named_resources_request_local_var;
}


void v1alpha2_named_resources_request_free(v1alpha2_named_resources_request_t *v1alpha2_named_resources_request) {
    if(NULL == v1alpha2_named_resources_request){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha2_named_resources_request->selector) {
        free(v1alpha2_named_resources_request->selector);
        v1alpha2_named_resources_request->selector = NULL;
    }
    free(v1alpha2_named_resources_request);
}

cJSON *v1alpha2_named_resources_request_convertToJSON(v1alpha2_named_resources_request_t *v1alpha2_named_resources_request) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha2_named_resources_request->selector
    if (!v1alpha2_named_resources_request->selector) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "selector", v1alpha2_named_resources_request->selector) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1alpha2_named_resources_request_t *v1alpha2_named_resources_request_parseFromJSON(cJSON *v1alpha2_named_resources_requestJSON){

    v1alpha2_named_resources_request_t *v1alpha2_named_resources_request_local_var = NULL;

    // v1alpha2_named_resources_request->selector
    cJSON *selector = cJSON_GetObjectItemCaseSensitive(v1alpha2_named_resources_requestJSON, "selector");
    if (!selector) {
        goto end;
    }

    
    if(!cJSON_IsString(selector))
    {
    goto end; //String
    }


    v1alpha2_named_resources_request_local_var = v1alpha2_named_resources_request_create (
        strdup(selector->valuestring)
        );

    return v1alpha2_named_resources_request_local_var;
end:
    return NULL;

}
