#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_se_linux_strategy_options.h"



v1beta1_se_linux_strategy_options_t *v1beta1_se_linux_strategy_options_create(
    char *rule,
    v1_se_linux_options_t *se_linux_options
    ) {
    v1beta1_se_linux_strategy_options_t *v1beta1_se_linux_strategy_options_local_var = malloc(sizeof(v1beta1_se_linux_strategy_options_t));
    if (!v1beta1_se_linux_strategy_options_local_var) {
        return NULL;
    }
    v1beta1_se_linux_strategy_options_local_var->rule = rule;
    v1beta1_se_linux_strategy_options_local_var->se_linux_options = se_linux_options;

    return v1beta1_se_linux_strategy_options_local_var;
}


void v1beta1_se_linux_strategy_options_free(v1beta1_se_linux_strategy_options_t *v1beta1_se_linux_strategy_options) {
    if(NULL == v1beta1_se_linux_strategy_options){
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta1_se_linux_strategy_options->rule) {
        free(v1beta1_se_linux_strategy_options->rule);
        v1beta1_se_linux_strategy_options->rule = NULL;
    }
    if (v1beta1_se_linux_strategy_options->se_linux_options) {
        v1_se_linux_options_free(v1beta1_se_linux_strategy_options->se_linux_options);
        v1beta1_se_linux_strategy_options->se_linux_options = NULL;
    }
    free(v1beta1_se_linux_strategy_options);
}

cJSON *v1beta1_se_linux_strategy_options_convertToJSON(v1beta1_se_linux_strategy_options_t *v1beta1_se_linux_strategy_options) {
    cJSON *item = cJSON_CreateObject();

    // v1beta1_se_linux_strategy_options->rule
    if (!v1beta1_se_linux_strategy_options->rule) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "rule", v1beta1_se_linux_strategy_options->rule) == NULL) {
    goto fail; //String
    }


    // v1beta1_se_linux_strategy_options->se_linux_options
    if(v1beta1_se_linux_strategy_options->se_linux_options) { 
    cJSON *se_linux_options_local_JSON = v1_se_linux_options_convertToJSON(v1beta1_se_linux_strategy_options->se_linux_options);
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

v1beta1_se_linux_strategy_options_t *v1beta1_se_linux_strategy_options_parseFromJSON(cJSON *v1beta1_se_linux_strategy_optionsJSON){

    v1beta1_se_linux_strategy_options_t *v1beta1_se_linux_strategy_options_local_var = NULL;

    // define the local variable for v1beta1_se_linux_strategy_options->se_linux_options
    v1_se_linux_options_t *se_linux_options_local_nonprim = NULL;

    // v1beta1_se_linux_strategy_options->rule
    cJSON *rule = cJSON_GetObjectItemCaseSensitive(v1beta1_se_linux_strategy_optionsJSON, "rule");
    if (!rule) {
        goto end;
    }

    
    if(!cJSON_IsString(rule))
    {
    goto end; //String
    }

    // v1beta1_se_linux_strategy_options->se_linux_options
    cJSON *se_linux_options = cJSON_GetObjectItemCaseSensitive(v1beta1_se_linux_strategy_optionsJSON, "seLinuxOptions");
    if (se_linux_options) { 
    se_linux_options_local_nonprim = v1_se_linux_options_parseFromJSON(se_linux_options); //nonprimitive
    }


    v1beta1_se_linux_strategy_options_local_var = v1beta1_se_linux_strategy_options_create (
        strdup(rule->valuestring),
        se_linux_options ? se_linux_options_local_nonprim : NULL
        );

    return v1beta1_se_linux_strategy_options_local_var;
end:
    if (se_linux_options_local_nonprim) {
        v1_se_linux_options_free(se_linux_options_local_nonprim);
        se_linux_options_local_nonprim = NULL;
    }
    return NULL;

}
