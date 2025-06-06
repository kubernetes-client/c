#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_validation.h"



static v1_validation_t *v1_validation_create_internal(
    char *expression,
    char *message,
    char *message_expression,
    char *reason
    ) {
    v1_validation_t *v1_validation_local_var = malloc(sizeof(v1_validation_t));
    if (!v1_validation_local_var) {
        return NULL;
    }
    v1_validation_local_var->expression = expression;
    v1_validation_local_var->message = message;
    v1_validation_local_var->message_expression = message_expression;
    v1_validation_local_var->reason = reason;

    v1_validation_local_var->_library_owned = 1;
    return v1_validation_local_var;
}

__attribute__((deprecated)) v1_validation_t *v1_validation_create(
    char *expression,
    char *message,
    char *message_expression,
    char *reason
    ) {
    return v1_validation_create_internal (
        expression,
        message,
        message_expression,
        reason
        );
}

void v1_validation_free(v1_validation_t *v1_validation) {
    if(NULL == v1_validation){
        return ;
    }
    if(v1_validation->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_validation_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_validation->expression) {
        free(v1_validation->expression);
        v1_validation->expression = NULL;
    }
    if (v1_validation->message) {
        free(v1_validation->message);
        v1_validation->message = NULL;
    }
    if (v1_validation->message_expression) {
        free(v1_validation->message_expression);
        v1_validation->message_expression = NULL;
    }
    if (v1_validation->reason) {
        free(v1_validation->reason);
        v1_validation->reason = NULL;
    }
    free(v1_validation);
}

cJSON *v1_validation_convertToJSON(v1_validation_t *v1_validation) {
    cJSON *item = cJSON_CreateObject();

    // v1_validation->expression
    if (!v1_validation->expression) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "expression", v1_validation->expression) == NULL) {
    goto fail; //String
    }


    // v1_validation->message
    if(v1_validation->message) {
    if(cJSON_AddStringToObject(item, "message", v1_validation->message) == NULL) {
    goto fail; //String
    }
    }


    // v1_validation->message_expression
    if(v1_validation->message_expression) {
    if(cJSON_AddStringToObject(item, "messageExpression", v1_validation->message_expression) == NULL) {
    goto fail; //String
    }
    }


    // v1_validation->reason
    if(v1_validation->reason) {
    if(cJSON_AddStringToObject(item, "reason", v1_validation->reason) == NULL) {
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

v1_validation_t *v1_validation_parseFromJSON(cJSON *v1_validationJSON){

    v1_validation_t *v1_validation_local_var = NULL;

    // v1_validation->expression
    cJSON *expression = cJSON_GetObjectItemCaseSensitive(v1_validationJSON, "expression");
    if (cJSON_IsNull(expression)) {
        expression = NULL;
    }
    if (!expression) {
        goto end;
    }

    
    if(!cJSON_IsString(expression))
    {
    goto end; //String
    }

    // v1_validation->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(v1_validationJSON, "message");
    if (cJSON_IsNull(message)) {
        message = NULL;
    }
    if (message) { 
    if(!cJSON_IsString(message) && !cJSON_IsNull(message))
    {
    goto end; //String
    }
    }

    // v1_validation->message_expression
    cJSON *message_expression = cJSON_GetObjectItemCaseSensitive(v1_validationJSON, "messageExpression");
    if (cJSON_IsNull(message_expression)) {
        message_expression = NULL;
    }
    if (message_expression) { 
    if(!cJSON_IsString(message_expression) && !cJSON_IsNull(message_expression))
    {
    goto end; //String
    }
    }

    // v1_validation->reason
    cJSON *reason = cJSON_GetObjectItemCaseSensitive(v1_validationJSON, "reason");
    if (cJSON_IsNull(reason)) {
        reason = NULL;
    }
    if (reason) { 
    if(!cJSON_IsString(reason) && !cJSON_IsNull(reason))
    {
    goto end; //String
    }
    }


    v1_validation_local_var = v1_validation_create_internal (
        strdup(expression->valuestring),
        message && !cJSON_IsNull(message) ? strdup(message->valuestring) : NULL,
        message_expression && !cJSON_IsNull(message_expression) ? strdup(message_expression->valuestring) : NULL,
        reason && !cJSON_IsNull(reason) ? strdup(reason->valuestring) : NULL
        );

    return v1_validation_local_var;
end:
    return NULL;

}
