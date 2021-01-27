#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "policy_v1beta1_se_linux_strategy_options.h"



policy_v1beta1_se_linux_strategy_options_t *policy_v1beta1_se_linux_strategy_options_create(
    char *rule,
    v1_se_linux_options_t *se_linux_options
    ) {
    policy_v1beta1_se_linux_strategy_options_t *policy_v1beta1_se_linux_strategy_options_local_var = malloc(sizeof(policy_v1beta1_se_linux_strategy_options_t));
    if (!policy_v1beta1_se_linux_strategy_options_local_var) {
        return NULL;
    }
    policy_v1beta1_se_linux_strategy_options_local_var->rule = rule;
    policy_v1beta1_se_linux_strategy_options_local_var->se_linux_options = se_linux_options;

    return policy_v1beta1_se_linux_strategy_options_local_var;
}


void policy_v1beta1_se_linux_strategy_options_free(policy_v1beta1_se_linux_strategy_options_t *policy_v1beta1_se_linux_strategy_options) {
    if(NULL == policy_v1beta1_se_linux_strategy_options){
        return ;
    }
    listEntry_t *listEntry;
    if (policy_v1beta1_se_linux_strategy_options->rule) {
        free(policy_v1beta1_se_linux_strategy_options->rule);
        policy_v1beta1_se_linux_strategy_options->rule = NULL;
    }
    if (policy_v1beta1_se_linux_strategy_options->se_linux_options) {
        v1_se_linux_options_free(policy_v1beta1_se_linux_strategy_options->se_linux_options);
        policy_v1beta1_se_linux_strategy_options->se_linux_options = NULL;
    }
    free(policy_v1beta1_se_linux_strategy_options);
}

cJSON *policy_v1beta1_se_linux_strategy_options_convertToJSON(policy_v1beta1_se_linux_strategy_options_t *policy_v1beta1_se_linux_strategy_options) {
    cJSON *item = cJSON_CreateObject();

    // policy_v1beta1_se_linux_strategy_options->rule
    if (!policy_v1beta1_se_linux_strategy_options->rule) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "rule", policy_v1beta1_se_linux_strategy_options->rule) == NULL) {
    goto fail; //String
    }


    // policy_v1beta1_se_linux_strategy_options->se_linux_options
    if(policy_v1beta1_se_linux_strategy_options->se_linux_options) { 
    cJSON *se_linux_options_local_JSON = v1_se_linux_options_convertToJSON(policy_v1beta1_se_linux_strategy_options->se_linux_options);
    if(se_linux_options_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "seLinuxOptions", se_linux_options_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

policy_v1beta1_se_linux_strategy_options_t *policy_v1beta1_se_linux_strategy_options_parseFromJSON(cJSON *policy_v1beta1_se_linux_strategy_optionsJSON){

    policy_v1beta1_se_linux_strategy_options_t *policy_v1beta1_se_linux_strategy_options_local_var = NULL;

    // policy_v1beta1_se_linux_strategy_options->rule
    cJSON *rule = cJSON_GetObjectItemCaseSensitive(policy_v1beta1_se_linux_strategy_optionsJSON, "rule");
    if (!rule) {
        goto end;
    }

    
    if(!cJSON_IsString(rule))
    {
    goto end; //String
    }

    // policy_v1beta1_se_linux_strategy_options->se_linux_options
    cJSON *se_linux_options = cJSON_GetObjectItemCaseSensitive(policy_v1beta1_se_linux_strategy_optionsJSON, "seLinuxOptions");
    v1_se_linux_options_t *se_linux_options_local_nonprim = NULL;
    if (se_linux_options) { 
    se_linux_options_local_nonprim = v1_se_linux_options_parseFromJSON(se_linux_options); //nonprimitive
    }


    policy_v1beta1_se_linux_strategy_options_local_var = policy_v1beta1_se_linux_strategy_options_create (
        strdup(rule->valuestring),
        se_linux_options ? se_linux_options_local_nonprim : NULL
        );

    return policy_v1beta1_se_linux_strategy_options_local_var;
end:
    if (se_linux_options_local_nonprim) {
        v1_se_linux_options_free(se_linux_options_local_nonprim);
        se_linux_options_local_nonprim = NULL;
    }
    return NULL;

}
