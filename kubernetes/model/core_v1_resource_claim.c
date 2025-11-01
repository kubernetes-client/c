#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "core_v1_resource_claim.h"



static core_v1_resource_claim_t *core_v1_resource_claim_create_internal(
    char *name,
    char *request
    ) {
    core_v1_resource_claim_t *core_v1_resource_claim_local_var = malloc(sizeof(core_v1_resource_claim_t));
    if (!core_v1_resource_claim_local_var) {
        return NULL;
    }
    core_v1_resource_claim_local_var->name = name;
    core_v1_resource_claim_local_var->request = request;

    core_v1_resource_claim_local_var->_library_owned = 1;
    return core_v1_resource_claim_local_var;
}

__attribute__((deprecated)) core_v1_resource_claim_t *core_v1_resource_claim_create(
    char *name,
    char *request
    ) {
    return core_v1_resource_claim_create_internal (
        name,
        request
        );
}

void core_v1_resource_claim_free(core_v1_resource_claim_t *core_v1_resource_claim) {
    if(NULL == core_v1_resource_claim){
        return ;
    }
    if(core_v1_resource_claim->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "core_v1_resource_claim_free");
        return ;
    }
    listEntry_t *listEntry;
    if (core_v1_resource_claim->name) {
        free(core_v1_resource_claim->name);
        core_v1_resource_claim->name = NULL;
    }
    if (core_v1_resource_claim->request) {
        free(core_v1_resource_claim->request);
        core_v1_resource_claim->request = NULL;
    }
    free(core_v1_resource_claim);
}

cJSON *core_v1_resource_claim_convertToJSON(core_v1_resource_claim_t *core_v1_resource_claim) {
    cJSON *item = cJSON_CreateObject();

    // core_v1_resource_claim->name
    if (!core_v1_resource_claim->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", core_v1_resource_claim->name) == NULL) {
    goto fail; //String
    }


    // core_v1_resource_claim->request
    if(core_v1_resource_claim->request) {
    if(cJSON_AddStringToObject(item, "request", core_v1_resource_claim->request) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

core_v1_resource_claim_t *core_v1_resource_claim_parseFromJSON(cJSON *core_v1_resource_claimJSON){

    core_v1_resource_claim_t *core_v1_resource_claim_local_var = NULL;

    // core_v1_resource_claim->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(core_v1_resource_claimJSON, "name");
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

    // core_v1_resource_claim->request
    cJSON *request = cJSON_GetObjectItemCaseSensitive(core_v1_resource_claimJSON, "request");
    if (cJSON_IsNull(request)) {
        request = NULL;
    }
    if (request) { 
    if(!cJSON_IsString(request) && !cJSON_IsNull(request))
    {
    goto end; //String
    }
    }


    core_v1_resource_claim_local_var = core_v1_resource_claim_create_internal (
        strdup(name->valuestring),
        request && !cJSON_IsNull(request) ? strdup(request->valuestring) : NULL
        );

    return core_v1_resource_claim_local_var;
end:
    return NULL;

}
