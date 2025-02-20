#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_validation_rule.h"



static v1_validation_rule_t *v1_validation_rule_create_internal(
    char *field_path,
    char *message,
    char *message_expression,
    int optional_old_self,
    char *reason,
    char *rule
    ) {
    v1_validation_rule_t *v1_validation_rule_local_var = malloc(sizeof(v1_validation_rule_t));
    if (!v1_validation_rule_local_var) {
        return NULL;
    }
    v1_validation_rule_local_var->field_path = field_path;
    v1_validation_rule_local_var->message = message;
    v1_validation_rule_local_var->message_expression = message_expression;
    v1_validation_rule_local_var->optional_old_self = optional_old_self;
    v1_validation_rule_local_var->reason = reason;
    v1_validation_rule_local_var->rule = rule;

    v1_validation_rule_local_var->_library_owned = 1;
    return v1_validation_rule_local_var;
}

__attribute__((deprecated)) v1_validation_rule_t *v1_validation_rule_create(
    char *field_path,
    char *message,
    char *message_expression,
    int optional_old_self,
    char *reason,
    char *rule
    ) {
    return v1_validation_rule_create_internal (
        field_path,
        message,
        message_expression,
        optional_old_self,
        reason,
        rule
        );
}

void v1_validation_rule_free(v1_validation_rule_t *v1_validation_rule) {
    if(NULL == v1_validation_rule){
        return ;
    }
    if(v1_validation_rule->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_validation_rule_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_validation_rule->field_path) {
        free(v1_validation_rule->field_path);
        v1_validation_rule->field_path = NULL;
    }
    if (v1_validation_rule->message) {
        free(v1_validation_rule->message);
        v1_validation_rule->message = NULL;
    }
    if (v1_validation_rule->message_expression) {
        free(v1_validation_rule->message_expression);
        v1_validation_rule->message_expression = NULL;
    }
    if (v1_validation_rule->reason) {
        free(v1_validation_rule->reason);
        v1_validation_rule->reason = NULL;
    }
    if (v1_validation_rule->rule) {
        free(v1_validation_rule->rule);
        v1_validation_rule->rule = NULL;
    }
    free(v1_validation_rule);
}

cJSON *v1_validation_rule_convertToJSON(v1_validation_rule_t *v1_validation_rule) {
    cJSON *item = cJSON_CreateObject();

    // v1_validation_rule->field_path
    if(v1_validation_rule->field_path) {
    if(cJSON_AddStringToObject(item, "fieldPath", v1_validation_rule->field_path) == NULL) {
    goto fail; //String
    }
    }


    // v1_validation_rule->message
    if(v1_validation_rule->message) {
    if(cJSON_AddStringToObject(item, "message", v1_validation_rule->message) == NULL) {
    goto fail; //String
    }
    }


    // v1_validation_rule->message_expression
    if(v1_validation_rule->message_expression) {
    if(cJSON_AddStringToObject(item, "messageExpression", v1_validation_rule->message_expression) == NULL) {
    goto fail; //String
    }
    }


    // v1_validation_rule->optional_old_self
    if(v1_validation_rule->optional_old_self) {
    if(cJSON_AddBoolToObject(item, "optionalOldSelf", v1_validation_rule->optional_old_self) == NULL) {
    goto fail; //Bool
    }
    }


    // v1_validation_rule->reason
    if(v1_validation_rule->reason) {
    if(cJSON_AddStringToObject(item, "reason", v1_validation_rule->reason) == NULL) {
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

    // v1_validation_rule->field_path
    cJSON *field_path = cJSON_GetObjectItemCaseSensitive(v1_validation_ruleJSON, "fieldPath");
    if (cJSON_IsNull(field_path)) {
        field_path = NULL;
    }
    if (field_path) { 
    if(!cJSON_IsString(field_path) && !cJSON_IsNull(field_path))
    {
    goto end; //String
    }
    }

    // v1_validation_rule->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(v1_validation_ruleJSON, "message");
    if (cJSON_IsNull(message)) {
        message = NULL;
    }
    if (message) { 
    if(!cJSON_IsString(message) && !cJSON_IsNull(message))
    {
    goto end; //String
    }
    }

    // v1_validation_rule->message_expression
    cJSON *message_expression = cJSON_GetObjectItemCaseSensitive(v1_validation_ruleJSON, "messageExpression");
    if (cJSON_IsNull(message_expression)) {
        message_expression = NULL;
    }
    if (message_expression) { 
    if(!cJSON_IsString(message_expression) && !cJSON_IsNull(message_expression))
    {
    goto end; //String
    }
    }

    // v1_validation_rule->optional_old_self
    cJSON *optional_old_self = cJSON_GetObjectItemCaseSensitive(v1_validation_ruleJSON, "optionalOldSelf");
    if (cJSON_IsNull(optional_old_self)) {
        optional_old_self = NULL;
    }
    if (optional_old_self) { 
    if(!cJSON_IsBool(optional_old_self))
    {
    goto end; //Bool
    }
    }

    // v1_validation_rule->reason
    cJSON *reason = cJSON_GetObjectItemCaseSensitive(v1_validation_ruleJSON, "reason");
    if (cJSON_IsNull(reason)) {
        reason = NULL;
    }
    if (reason) { 
    if(!cJSON_IsString(reason) && !cJSON_IsNull(reason))
    {
    goto end; //String
    }
    }

    // v1_validation_rule->rule
    cJSON *rule = cJSON_GetObjectItemCaseSensitive(v1_validation_ruleJSON, "rule");
    if (cJSON_IsNull(rule)) {
        rule = NULL;
    }
    if (!rule) {
        goto end;
    }

    
    if(!cJSON_IsString(rule))
    {
    goto end; //String
    }


    v1_validation_rule_local_var = v1_validation_rule_create_internal (
        field_path && !cJSON_IsNull(field_path) ? strdup(field_path->valuestring) : NULL,
        message && !cJSON_IsNull(message) ? strdup(message->valuestring) : NULL,
        message_expression && !cJSON_IsNull(message_expression) ? strdup(message_expression->valuestring) : NULL,
        optional_old_self ? optional_old_self->valueint : 0,
        reason && !cJSON_IsNull(reason) ? strdup(reason->valuestring) : NULL,
        strdup(rule->valuestring)
        );

    return v1_validation_rule_local_var;
end:
    return NULL;

}
