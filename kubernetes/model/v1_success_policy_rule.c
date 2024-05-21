#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_success_policy_rule.h"



v1_success_policy_rule_t *v1_success_policy_rule_create(
    int succeeded_count,
    char *succeeded_indexes
    ) {
    v1_success_policy_rule_t *v1_success_policy_rule_local_var = malloc(sizeof(v1_success_policy_rule_t));
    if (!v1_success_policy_rule_local_var) {
        return NULL;
    }
    v1_success_policy_rule_local_var->succeeded_count = succeeded_count;
    v1_success_policy_rule_local_var->succeeded_indexes = succeeded_indexes;

    return v1_success_policy_rule_local_var;
}


void v1_success_policy_rule_free(v1_success_policy_rule_t *v1_success_policy_rule) {
    if(NULL == v1_success_policy_rule){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_success_policy_rule->succeeded_indexes) {
        free(v1_success_policy_rule->succeeded_indexes);
        v1_success_policy_rule->succeeded_indexes = NULL;
    }
    free(v1_success_policy_rule);
}

cJSON *v1_success_policy_rule_convertToJSON(v1_success_policy_rule_t *v1_success_policy_rule) {
    cJSON *item = cJSON_CreateObject();

    // v1_success_policy_rule->succeeded_count
    if(v1_success_policy_rule->succeeded_count) {
    if(cJSON_AddNumberToObject(item, "succeededCount", v1_success_policy_rule->succeeded_count) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_success_policy_rule->succeeded_indexes
    if(v1_success_policy_rule->succeeded_indexes) {
    if(cJSON_AddStringToObject(item, "succeededIndexes", v1_success_policy_rule->succeeded_indexes) == NULL) {
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

v1_success_policy_rule_t *v1_success_policy_rule_parseFromJSON(cJSON *v1_success_policy_ruleJSON){

    v1_success_policy_rule_t *v1_success_policy_rule_local_var = NULL;

    // v1_success_policy_rule->succeeded_count
    cJSON *succeeded_count = cJSON_GetObjectItemCaseSensitive(v1_success_policy_ruleJSON, "succeededCount");
    if (succeeded_count) { 
    if(!cJSON_IsNumber(succeeded_count))
    {
    goto end; //Numeric
    }
    }

    // v1_success_policy_rule->succeeded_indexes
    cJSON *succeeded_indexes = cJSON_GetObjectItemCaseSensitive(v1_success_policy_ruleJSON, "succeededIndexes");
    if (succeeded_indexes) { 
    if(!cJSON_IsString(succeeded_indexes) && !cJSON_IsNull(succeeded_indexes))
    {
    goto end; //String
    }
    }


    v1_success_policy_rule_local_var = v1_success_policy_rule_create (
        succeeded_count ? succeeded_count->valuedouble : 0,
        succeeded_indexes && !cJSON_IsNull(succeeded_indexes) ? strdup(succeeded_indexes->valuestring) : NULL
        );

    return v1_success_policy_rule_local_var;
end:
    return NULL;

}
