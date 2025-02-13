#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_stateful_set_persistent_volume_claim_retention_policy.h"



static v1_stateful_set_persistent_volume_claim_retention_policy_t *v1_stateful_set_persistent_volume_claim_retention_policy_create_internal(
    char *when_deleted,
    char *when_scaled
    ) {
    v1_stateful_set_persistent_volume_claim_retention_policy_t *v1_stateful_set_persistent_volume_claim_retention_policy_local_var = malloc(sizeof(v1_stateful_set_persistent_volume_claim_retention_policy_t));
    if (!v1_stateful_set_persistent_volume_claim_retention_policy_local_var) {
        return NULL;
    }
    v1_stateful_set_persistent_volume_claim_retention_policy_local_var->when_deleted = when_deleted;
    v1_stateful_set_persistent_volume_claim_retention_policy_local_var->when_scaled = when_scaled;

    v1_stateful_set_persistent_volume_claim_retention_policy_local_var->_library_owned = 1;
    return v1_stateful_set_persistent_volume_claim_retention_policy_local_var;
}

__attribute__((deprecated)) v1_stateful_set_persistent_volume_claim_retention_policy_t *v1_stateful_set_persistent_volume_claim_retention_policy_create(
    char *when_deleted,
    char *when_scaled
    ) {
    return v1_stateful_set_persistent_volume_claim_retention_policy_create_internal (
        when_deleted,
        when_scaled
        );
}

void v1_stateful_set_persistent_volume_claim_retention_policy_free(v1_stateful_set_persistent_volume_claim_retention_policy_t *v1_stateful_set_persistent_volume_claim_retention_policy) {
    if(NULL == v1_stateful_set_persistent_volume_claim_retention_policy){
        return ;
    }
    if(v1_stateful_set_persistent_volume_claim_retention_policy->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_stateful_set_persistent_volume_claim_retention_policy_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_stateful_set_persistent_volume_claim_retention_policy->when_deleted) {
        free(v1_stateful_set_persistent_volume_claim_retention_policy->when_deleted);
        v1_stateful_set_persistent_volume_claim_retention_policy->when_deleted = NULL;
    }
    if (v1_stateful_set_persistent_volume_claim_retention_policy->when_scaled) {
        free(v1_stateful_set_persistent_volume_claim_retention_policy->when_scaled);
        v1_stateful_set_persistent_volume_claim_retention_policy->when_scaled = NULL;
    }
    free(v1_stateful_set_persistent_volume_claim_retention_policy);
}

cJSON *v1_stateful_set_persistent_volume_claim_retention_policy_convertToJSON(v1_stateful_set_persistent_volume_claim_retention_policy_t *v1_stateful_set_persistent_volume_claim_retention_policy) {
    cJSON *item = cJSON_CreateObject();

    // v1_stateful_set_persistent_volume_claim_retention_policy->when_deleted
    if(v1_stateful_set_persistent_volume_claim_retention_policy->when_deleted) {
    if(cJSON_AddStringToObject(item, "whenDeleted", v1_stateful_set_persistent_volume_claim_retention_policy->when_deleted) == NULL) {
    goto fail; //String
    }
    }


    // v1_stateful_set_persistent_volume_claim_retention_policy->when_scaled
    if(v1_stateful_set_persistent_volume_claim_retention_policy->when_scaled) {
    if(cJSON_AddStringToObject(item, "whenScaled", v1_stateful_set_persistent_volume_claim_retention_policy->when_scaled) == NULL) {
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

v1_stateful_set_persistent_volume_claim_retention_policy_t *v1_stateful_set_persistent_volume_claim_retention_policy_parseFromJSON(cJSON *v1_stateful_set_persistent_volume_claim_retention_policyJSON){

    v1_stateful_set_persistent_volume_claim_retention_policy_t *v1_stateful_set_persistent_volume_claim_retention_policy_local_var = NULL;

    // v1_stateful_set_persistent_volume_claim_retention_policy->when_deleted
    cJSON *when_deleted = cJSON_GetObjectItemCaseSensitive(v1_stateful_set_persistent_volume_claim_retention_policyJSON, "whenDeleted");
    if (cJSON_IsNull(when_deleted)) {
        when_deleted = NULL;
    }
    if (when_deleted) { 
    if(!cJSON_IsString(when_deleted) && !cJSON_IsNull(when_deleted))
    {
    goto end; //String
    }
    }

    // v1_stateful_set_persistent_volume_claim_retention_policy->when_scaled
    cJSON *when_scaled = cJSON_GetObjectItemCaseSensitive(v1_stateful_set_persistent_volume_claim_retention_policyJSON, "whenScaled");
    if (cJSON_IsNull(when_scaled)) {
        when_scaled = NULL;
    }
    if (when_scaled) { 
    if(!cJSON_IsString(when_scaled) && !cJSON_IsNull(when_scaled))
    {
    goto end; //String
    }
    }


    v1_stateful_set_persistent_volume_claim_retention_policy_local_var = v1_stateful_set_persistent_volume_claim_retention_policy_create_internal (
        when_deleted && !cJSON_IsNull(when_deleted) ? strdup(when_deleted->valuestring) : NULL,
        when_scaled && !cJSON_IsNull(when_scaled) ? strdup(when_scaled->valuestring) : NULL
        );

    return v1_stateful_set_persistent_volume_claim_retention_policy_local_var;
end:
    return NULL;

}
