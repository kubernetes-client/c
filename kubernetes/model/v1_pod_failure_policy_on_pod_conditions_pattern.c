#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_pod_failure_policy_on_pod_conditions_pattern.h"



v1_pod_failure_policy_on_pod_conditions_pattern_t *v1_pod_failure_policy_on_pod_conditions_pattern_create(
    char *status,
    char *type
    ) {
    v1_pod_failure_policy_on_pod_conditions_pattern_t *v1_pod_failure_policy_on_pod_conditions_pattern_local_var = malloc(sizeof(v1_pod_failure_policy_on_pod_conditions_pattern_t));
    if (!v1_pod_failure_policy_on_pod_conditions_pattern_local_var) {
        return NULL;
    }
    v1_pod_failure_policy_on_pod_conditions_pattern_local_var->status = status;
    v1_pod_failure_policy_on_pod_conditions_pattern_local_var->type = type;

    return v1_pod_failure_policy_on_pod_conditions_pattern_local_var;
}


void v1_pod_failure_policy_on_pod_conditions_pattern_free(v1_pod_failure_policy_on_pod_conditions_pattern_t *v1_pod_failure_policy_on_pod_conditions_pattern) {
    if(NULL == v1_pod_failure_policy_on_pod_conditions_pattern){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_pod_failure_policy_on_pod_conditions_pattern->status) {
        free(v1_pod_failure_policy_on_pod_conditions_pattern->status);
        v1_pod_failure_policy_on_pod_conditions_pattern->status = NULL;
    }
    if (v1_pod_failure_policy_on_pod_conditions_pattern->type) {
        free(v1_pod_failure_policy_on_pod_conditions_pattern->type);
        v1_pod_failure_policy_on_pod_conditions_pattern->type = NULL;
    }
    free(v1_pod_failure_policy_on_pod_conditions_pattern);
}

cJSON *v1_pod_failure_policy_on_pod_conditions_pattern_convertToJSON(v1_pod_failure_policy_on_pod_conditions_pattern_t *v1_pod_failure_policy_on_pod_conditions_pattern) {
    cJSON *item = cJSON_CreateObject();

    // v1_pod_failure_policy_on_pod_conditions_pattern->status
    if (!v1_pod_failure_policy_on_pod_conditions_pattern->status) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "status", v1_pod_failure_policy_on_pod_conditions_pattern->status) == NULL) {
    goto fail; //String
    }


    // v1_pod_failure_policy_on_pod_conditions_pattern->type
    if (!v1_pod_failure_policy_on_pod_conditions_pattern->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", v1_pod_failure_policy_on_pod_conditions_pattern->type) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_pod_failure_policy_on_pod_conditions_pattern_t *v1_pod_failure_policy_on_pod_conditions_pattern_parseFromJSON(cJSON *v1_pod_failure_policy_on_pod_conditions_patternJSON){

    v1_pod_failure_policy_on_pod_conditions_pattern_t *v1_pod_failure_policy_on_pod_conditions_pattern_local_var = NULL;

    // v1_pod_failure_policy_on_pod_conditions_pattern->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(v1_pod_failure_policy_on_pod_conditions_patternJSON, "status");
    if (!status) {
        goto end;
    }

    
    if(!cJSON_IsString(status))
    {
    goto end; //String
    }

    // v1_pod_failure_policy_on_pod_conditions_pattern->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(v1_pod_failure_policy_on_pod_conditions_patternJSON, "type");
    if (!type) {
        goto end;
    }

    
    if(!cJSON_IsString(type))
    {
    goto end; //String
    }


    v1_pod_failure_policy_on_pod_conditions_pattern_local_var = v1_pod_failure_policy_on_pod_conditions_pattern_create (
        strdup(status->valuestring),
        strdup(type->valuestring)
        );

    return v1_pod_failure_policy_on_pod_conditions_pattern_local_var;
end:
    return NULL;

}
