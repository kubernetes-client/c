#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_resource_claim.h"



v1_resource_claim_t *v1_resource_claim_create(
    char *name
    ) {
    v1_resource_claim_t *v1_resource_claim_local_var = malloc(sizeof(v1_resource_claim_t));
    if (!v1_resource_claim_local_var) {
        return NULL;
    }
    v1_resource_claim_local_var->name = name;

    return v1_resource_claim_local_var;
}


void v1_resource_claim_free(v1_resource_claim_t *v1_resource_claim) {
    if(NULL == v1_resource_claim){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_resource_claim->name) {
        free(v1_resource_claim->name);
        v1_resource_claim->name = NULL;
    }
    free(v1_resource_claim);
}

cJSON *v1_resource_claim_convertToJSON(v1_resource_claim_t *v1_resource_claim) {
    cJSON *item = cJSON_CreateObject();

    // v1_resource_claim->name
    if (!v1_resource_claim->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", v1_resource_claim->name) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_resource_claim_t *v1_resource_claim_parseFromJSON(cJSON *v1_resource_claimJSON){

    v1_resource_claim_t *v1_resource_claim_local_var = NULL;

    // v1_resource_claim->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1_resource_claimJSON, "name");
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }


    v1_resource_claim_local_var = v1_resource_claim_create (
        strdup(name->valuestring)
        );

    return v1_resource_claim_local_var;
end:
    return NULL;

}
