#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_validation_rule.h"



v1_validation_rule_t *v1_validation_rule_create(
    char *message,
    char *rule
    ) {
    v1_validation_rule_t *v1_validation_rule_local_var = malloc(sizeof(v1_validation_rule_t));
    if (!v1_validation_rule_local_var) {
        return NULL;
    }
    v1_validation_rule_local_var->message = message;
    v1_validation_rule_local_var->rule = rule;

    return v1_validation_rule_local_var;
}


void v1_validation_rule_free(v1_validation_rule_t *v1_validation_rule) {
    if(NULL == v1_validation_rule){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_validation_rule->message) {
        free(v1_validation_rule->message);
        v1_validation_rule->message = NULL;
    }
    if (v1_validation_rule->rule) {
        free(v1_validation_rule->rule);
        v1_validation_rule->rule = NULL;
    }
    free(v1_validation_rule);
}

cJSON *v1_validation_rule_convertToJSON(v1_validation_rule_t *v1_validation_rule) {
    cJSON *item = cJSON_CreateObject();

    // v1_validation_rule->message
    if(v1_validation_rule->message) {
    if(cJSON_AddStringToObject(item, "message", v1_validation_rule->message) == NULL) {
    goto fail; //String
    }
    }


    // v1_validation_rule->rule
    if (!v1_validation_rule->rule) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "rule", v1_validation_rule->rule) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_validation_rule_t *v1_validation_rule_parseFromJSON(cJSON *v1_validation_ruleJSON){

    v1_validation_rule_t *v1_validation_rule_local_var = NULL;

    // v1_validation_rule->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(v1_validation_ruleJSON, "message");
    if (message) { 
    if(!cJSON_IsString(message) && !cJSON_IsNull(message))
    {
    goto end; //String
    }
    }

    // v1_validation_rule->rule
    cJSON *rule = cJSON_GetObjectItemCaseSensitive(v1_validation_ruleJSON, "rule");
    if (!rule) {
        goto end;
    }

    
    if(!cJSON_IsString(rule))
    {
    goto end; //String
    }


    v1_validation_rule_local_var = v1_validation_rule_create (
        message && !cJSON_IsNull(message) ? strdup(message->valuestring) : NULL,
        strdup(rule->valuestring)
        );

    return v1_validation_rule_local_var;
end:
    return NULL;

}
