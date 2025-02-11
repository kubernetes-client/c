#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_success_policy_rule.h"



static v1_success_policy_rule_t *v1_success_policy_rule_create_internal(
    int succeeded_count,
    char *succeeded_indexes
    ) {
    v1_success_policy_rule_t *v1_success_policy_rule_local_var = malloc(sizeof(v1_success_policy_rule_t));
    if (!v1_success_policy_rule_local_var) {
        return NULL;
    }
    v1_success_policy_rule_local_var->succeeded_count = succeeded_count;
    v1_success_policy_rule_local_var->succeeded_indexes = succeeded_indexes;

    v1_success_policy_rule_local_var->_library_owned = 1;
    return v1_success_policy_rule_local_var;
}

__attribute__((deprecated)) v1_success_policy_rule_t *v1_success_policy_rule_create(
    int succeeded_count,
    char *succeeded_indexes
    ) {
    return v1_success_policy_rule_create_internal (
        succeeded_count,
        succeeded_indexes
        );
}

void v1_success_policy_rule_free(v1_success_policy_rule_t *v1_success_policy_rule) {
    if(NULL == v1_success_policy_rule){
        return ;
    }
    if(v1_success_policy_rule->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_success_policy_rule_free");
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
    if (cJSON_IsNull(succeeded_count)) {
        succeeded_count = NULL;
    }
    if (succeeded_count) { 
    if(!cJSON_IsNumber(succeeded_count))
    {
    goto end; //Numeric
    }
    }

    // v1_success_policy_rule->succeeded_indexes
    cJSON *succeeded_indexes = cJSON_GetObjectItemCaseSensitive(v1_success_policy_ruleJSON, "succeededIndexes");
    if (cJSON_IsNull(succeeded_indexes)) {
        succeeded_indexes = NULL;
    }
    if (succeeded_indexes) { 
    if(!cJSON_IsString(succeeded_indexes) && !cJSON_IsNull(succeeded_indexes))
    {
    goto end; //String
    }
    }


    v1_success_policy_rule_local_var = v1_success_policy_rule_create_internal (
        succeeded_count ? succeeded_count->valuedouble : 0,
        succeeded_indexes && !cJSON_IsNull(succeeded_indexes) ? strdup(succeeded_indexes->valuestring) : NULL
        );

    return v1_success_policy_rule_local_var;
end:
    return NULL;

}
