#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "extensions_v1beta1_se_linux_strategy_options.h"



extensions_v1beta1_se_linux_strategy_options_t *extensions_v1beta1_se_linux_strategy_options_create(
    char *rule,
    v1_se_linux_options_t *se_linux_options
    ) {
    extensions_v1beta1_se_linux_strategy_options_t *extensions_v1beta1_se_linux_strategy_options_local_var = malloc(sizeof(extensions_v1beta1_se_linux_strategy_options_t));
    if (!extensions_v1beta1_se_linux_strategy_options_local_var) {
        return NULL;
    }
    extensions_v1beta1_se_linux_strategy_options_local_var->rule = rule;
    extensions_v1beta1_se_linux_strategy_options_local_var->se_linux_options = se_linux_options;

    return extensions_v1beta1_se_linux_strategy_options_local_var;
}


void extensions_v1beta1_se_linux_strategy_options_free(extensions_v1beta1_se_linux_strategy_options_t *extensions_v1beta1_se_linux_strategy_options) {
    if(NULL == extensions_v1beta1_se_linux_strategy_options){
        return ;
    }
    listEntry_t *listEntry;
    if (extensions_v1beta1_se_linux_strategy_options->rule) {
        free(extensions_v1beta1_se_linux_strategy_options->rule);
        extensions_v1beta1_se_linux_strategy_options->rule = NULL;
    }
    if (extensions_v1beta1_se_linux_strategy_options->se_linux_options) {
        v1_se_linux_options_free(extensions_v1beta1_se_linux_strategy_options->se_linux_options);
        extensions_v1beta1_se_linux_strategy_options->se_linux_options = NULL;
    }
    free(extensions_v1beta1_se_linux_strategy_options);
}

cJSON *extensions_v1beta1_se_linux_strategy_options_convertToJSON(extensions_v1beta1_se_linux_strategy_options_t *extensions_v1beta1_se_linux_strategy_options) {
    cJSON *item = cJSON_CreateObject();

    // extensions_v1beta1_se_linux_strategy_options->rule
    if (!extensions_v1beta1_se_linux_strategy_options->rule) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "rule", extensions_v1beta1_se_linux_strategy_options->rule) == NULL) {
    goto fail; //String
    }


    // extensions_v1beta1_se_linux_strategy_options->se_linux_options
    if(extensions_v1beta1_se_linux_strategy_options->se_linux_options) { 
    cJSON *se_linux_options_local_JSON = v1_se_linux_options_convertToJSON(extensions_v1beta1_se_linux_strategy_options->se_linux_options);
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

extensions_v1beta1_se_linux_strategy_options_t *extensions_v1beta1_se_linux_strategy_options_parseFromJSON(cJSON *extensions_v1beta1_se_linux_strategy_optionsJSON){

    extensions_v1beta1_se_linux_strategy_options_t *extensions_v1beta1_se_linux_strategy_options_local_var = NULL;

    // extensions_v1beta1_se_linux_strategy_options->rule
    cJSON *rule = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_se_linux_strategy_optionsJSON, "rule");
    if (!rule) {
        goto end;
    }

    
    if(!cJSON_IsString(rule))
    {
    goto end; //String
    }

    // extensions_v1beta1_se_linux_strategy_options->se_linux_options
    cJSON *se_linux_options = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_se_linux_strategy_optionsJSON, "seLinuxOptions");
    v1_se_linux_options_t *se_linux_options_local_nonprim = NULL;
    if (se_linux_options) { 
    se_linux_options_local_nonprim = v1_se_linux_options_parseFromJSON(se_linux_options); //nonprimitive
    }


    extensions_v1beta1_se_linux_strategy_options_local_var = extensions_v1beta1_se_linux_strategy_options_create (
        strdup(rule->valuestring),
        se_linux_options ? se_linux_options_local_nonprim : NULL
        );

    return extensions_v1beta1_se_linux_strategy_options_local_var;
end:
    if (se_linux_options_local_nonprim) {
        v1_se_linux_options_free(se_linux_options_local_nonprim);
        se_linux_options_local_nonprim = NULL;
    }
    return NULL;

}
