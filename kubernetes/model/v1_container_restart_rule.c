#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_container_restart_rule.h"



static v1_container_restart_rule_t *v1_container_restart_rule_create_internal(
    char *action,
    v1_container_restart_rule_on_exit_codes_t *exit_codes
    ) {
    v1_container_restart_rule_t *v1_container_restart_rule_local_var = malloc(sizeof(v1_container_restart_rule_t));
    if (!v1_container_restart_rule_local_var) {
        return NULL;
    }
    memset(v1_container_restart_rule_local_var, 0, sizeof(v1_container_restart_rule_t));
    v1_container_restart_rule_local_var->_library_owned = 1;
    v1_container_restart_rule_local_var->action = action;
    v1_container_restart_rule_local_var->exit_codes = exit_codes;
    return v1_container_restart_rule_local_var;
}

__attribute__((deprecated)) v1_container_restart_rule_t *v1_container_restart_rule_create(
    char *action,
    v1_container_restart_rule_on_exit_codes_t *exit_codes
    ) {
    v1_container_restart_rule_t *result = v1_container_restart_rule_create_internal (
        action,
        exit_codes
        );
    if (!result) {
    }
    return result;
}

void v1_container_restart_rule_free(v1_container_restart_rule_t *v1_container_restart_rule) {
    if(NULL == v1_container_restart_rule){
        return ;
    }
    if(v1_container_restart_rule->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_container_restart_rule_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_container_restart_rule->action) {
        free(v1_container_restart_rule->action);
        v1_container_restart_rule->action = NULL;
    }
    if (v1_container_restart_rule->exit_codes) {
        v1_container_restart_rule_on_exit_codes_free(v1_container_restart_rule->exit_codes);
        v1_container_restart_rule->exit_codes = NULL;
    }
    free(v1_container_restart_rule);
}

cJSON *v1_container_restart_rule_convertToJSON(v1_container_restart_rule_t *v1_container_restart_rule) {
    cJSON *item = cJSON_CreateObject();

    // v1_container_restart_rule->action
    if (!v1_container_restart_rule->action) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "action", v1_container_restart_rule->action) == NULL) {
    goto fail; //String
    }


    // v1_container_restart_rule->exit_codes
    if(v1_container_restart_rule->exit_codes) {
    cJSON *exit_codes_local_JSON = v1_container_restart_rule_on_exit_codes_convertToJSON(v1_container_restart_rule->exit_codes);
    if(exit_codes_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "exitCodes", exit_codes_local_JSON);
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

v1_container_restart_rule_t *v1_container_restart_rule_parseFromJSON(cJSON *v1_container_restart_ruleJSON){

    v1_container_restart_rule_t *v1_container_restart_rule_local_var = NULL;

    char *action_local_str = NULL;

    // define the local variable for v1_container_restart_rule->exit_codes
    v1_container_restart_rule_on_exit_codes_t *exit_codes_local_nonprim = NULL;

    // v1_container_restart_rule->action
    cJSON *action = cJSON_GetObjectItemCaseSensitive(v1_container_restart_ruleJSON, "action");
    if (cJSON_IsNull(action)) {
        action = NULL;
    }
    if (!action) {
        goto end;
    }

    
    if(!cJSON_IsString(action))
    {
    goto end; //String
    }

    // v1_container_restart_rule->exit_codes
    cJSON *exit_codes = cJSON_GetObjectItemCaseSensitive(v1_container_restart_ruleJSON, "exitCodes");
    if (cJSON_IsNull(exit_codes)) {
        exit_codes = NULL;
    }
    if (exit_codes) { 
    exit_codes_local_nonprim = v1_container_restart_rule_on_exit_codes_parseFromJSON(exit_codes); //nonprimitive
    }


    if (action && !cJSON_IsNull(action)) action_local_str = strdup(action->valuestring);

    v1_container_restart_rule_local_var = v1_container_restart_rule_create_internal (
        action_local_str,
        exit_codes ? exit_codes_local_nonprim : NULL
        );

    if (!v1_container_restart_rule_local_var) {
        goto end;
    }

    return v1_container_restart_rule_local_var;
end:
    if (action_local_str) {
        free(action_local_str);
        action_local_str = NULL;
    }
    if (exit_codes_local_nonprim) {
        v1_container_restart_rule_on_exit_codes_free(exit_codes_local_nonprim);
        exit_codes_local_nonprim = NULL;
    }
    return NULL;

}
