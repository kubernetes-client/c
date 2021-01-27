#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha1_audit_sink_spec.h"



v1alpha1_audit_sink_spec_t *v1alpha1_audit_sink_spec_create(
    v1alpha1_policy_t *policy,
    v1alpha1_webhook_t *webhook
    ) {
    v1alpha1_audit_sink_spec_t *v1alpha1_audit_sink_spec_local_var = malloc(sizeof(v1alpha1_audit_sink_spec_t));
    if (!v1alpha1_audit_sink_spec_local_var) {
        return NULL;
    }
    v1alpha1_audit_sink_spec_local_var->policy = policy;
    v1alpha1_audit_sink_spec_local_var->webhook = webhook;

    return v1alpha1_audit_sink_spec_local_var;
}


void v1alpha1_audit_sink_spec_free(v1alpha1_audit_sink_spec_t *v1alpha1_audit_sink_spec) {
    if(NULL == v1alpha1_audit_sink_spec){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha1_audit_sink_spec->policy) {
        v1alpha1_policy_free(v1alpha1_audit_sink_spec->policy);
        v1alpha1_audit_sink_spec->policy = NULL;
    }
    if (v1alpha1_audit_sink_spec->webhook) {
        v1alpha1_webhook_free(v1alpha1_audit_sink_spec->webhook);
        v1alpha1_audit_sink_spec->webhook = NULL;
    }
    free(v1alpha1_audit_sink_spec);
}

cJSON *v1alpha1_audit_sink_spec_convertToJSON(v1alpha1_audit_sink_spec_t *v1alpha1_audit_sink_spec) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha1_audit_sink_spec->policy
    if (!v1alpha1_audit_sink_spec->policy) {
        goto fail;
    }
    
    cJSON *policy_local_JSON = v1alpha1_policy_convertToJSON(v1alpha1_audit_sink_spec->policy);
    if(policy_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "policy", policy_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // v1alpha1_audit_sink_spec->webhook
    if (!v1alpha1_audit_sink_spec->webhook) {
        goto fail;
    }
    
    cJSON *webhook_local_JSON = v1alpha1_webhook_convertToJSON(v1alpha1_audit_sink_spec->webhook);
    if(webhook_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "webhook", webhook_local_JSON);
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

v1alpha1_audit_sink_spec_t *v1alpha1_audit_sink_spec_parseFromJSON(cJSON *v1alpha1_audit_sink_specJSON){

    v1alpha1_audit_sink_spec_t *v1alpha1_audit_sink_spec_local_var = NULL;

    // v1alpha1_audit_sink_spec->policy
    cJSON *policy = cJSON_GetObjectItemCaseSensitive(v1alpha1_audit_sink_specJSON, "policy");
    if (!policy) {
        goto end;
    }

    v1alpha1_policy_t *policy_local_nonprim = NULL;
    
    policy_local_nonprim = v1alpha1_policy_parseFromJSON(policy); //nonprimitive

    // v1alpha1_audit_sink_spec->webhook
    cJSON *webhook = cJSON_GetObjectItemCaseSensitive(v1alpha1_audit_sink_specJSON, "webhook");
    if (!webhook) {
        goto end;
    }

    v1alpha1_webhook_t *webhook_local_nonprim = NULL;
    
    webhook_local_nonprim = v1alpha1_webhook_parseFromJSON(webhook); //nonprimitive


    v1alpha1_audit_sink_spec_local_var = v1alpha1_audit_sink_spec_create (
        policy_local_nonprim,
        webhook_local_nonprim
        );

    return v1alpha1_audit_sink_spec_local_var;
end:
    if (policy_local_nonprim) {
        v1alpha1_policy_free(policy_local_nonprim);
        policy_local_nonprim = NULL;
    }
    if (webhook_local_nonprim) {
        v1alpha1_webhook_free(webhook_local_nonprim);
        webhook_local_nonprim = NULL;
    }
    return NULL;

}
