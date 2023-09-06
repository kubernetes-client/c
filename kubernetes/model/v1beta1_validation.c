#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_validation.h"



v1beta1_validation_t *v1beta1_validation_create(
    char *expression,
    char *message,
    char *message_expression,
    char *reason
    ) {
    v1beta1_validation_t *v1beta1_validation_local_var = malloc(sizeof(v1beta1_validation_t));
    if (!v1beta1_validation_local_var) {
        return NULL;
    }
    v1beta1_validation_local_var->expression = expression;
    v1beta1_validation_local_var->message = message;
    v1beta1_validation_local_var->message_expression = message_expression;
    v1beta1_validation_local_var->reason = reason;

    return v1beta1_validation_local_var;
}


void v1beta1_validation_free(v1beta1_validation_t *v1beta1_validation) {
    if(NULL == v1beta1_validation){
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta1_validation->expression) {
        free(v1beta1_validation->expression);
        v1beta1_validation->expression = NULL;
    }
    if (v1beta1_validation->message) {
        free(v1beta1_validation->message);
        v1beta1_validation->message = NULL;
    }
    if (v1beta1_validation->message_expression) {
        free(v1beta1_validation->message_expression);
        v1beta1_validation->message_expression = NULL;
    }
    if (v1beta1_validation->reason) {
        free(v1beta1_validation->reason);
        v1beta1_validation->reason = NULL;
    }
    free(v1beta1_validation);
}

cJSON *v1beta1_validation_convertToJSON(v1beta1_validation_t *v1beta1_validation) {
    cJSON *item = cJSON_CreateObject();

    // v1beta1_validation->expression
    if (!v1beta1_validation->expression) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "expression", v1beta1_validation->expression) == NULL) {
    goto fail; //String
    }


    // v1beta1_validation->message
    if(v1beta1_validation->message) {
    if(cJSON_AddStringToObject(item, "message", v1beta1_validation->message) == NULL) {
    goto fail; //String
    }
    }


    // v1beta1_validation->message_expression
    if(v1beta1_validation->message_expression) {
    if(cJSON_AddStringToObject(item, "messageExpression", v1beta1_validation->message_expression) == NULL) {
    goto fail; //String
    }
    }


    // v1beta1_validation->reason
    if(v1beta1_validation->reason) {
    if(cJSON_AddStringToObject(item, "reason", v1beta1_validation->reason) == NULL) {
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

v1beta1_validation_t *v1beta1_validation_parseFromJSON(cJSON *v1beta1_validationJSON){

    v1beta1_validation_t *v1beta1_validation_local_var = NULL;

    // v1beta1_validation->expression
    cJSON *expression = cJSON_GetObjectItemCaseSensitive(v1beta1_validationJSON, "expression");
    if (!expression) {
        goto end;
    }

    
    if(!cJSON_IsString(expression))
    {
    goto end; //String
    }

    // v1beta1_validation->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(v1beta1_validationJSON, "message");
    if (message) { 
    if(!cJSON_IsString(message) && !cJSON_IsNull(message))
    {
    goto end; //String
    }
    }

    // v1beta1_validation->message_expression
    cJSON *message_expression = cJSON_GetObjectItemCaseSensitive(v1beta1_validationJSON, "messageExpression");
    if (message_expression) { 
    if(!cJSON_IsString(message_expression) && !cJSON_IsNull(message_expression))
    {
    goto end; //String
    }
    }

    // v1beta1_validation->reason
    cJSON *reason = cJSON_GetObjectItemCaseSensitive(v1beta1_validationJSON, "reason");
    if (reason) { 
    if(!cJSON_IsString(reason) && !cJSON_IsNull(reason))
    {
    goto end; //String
    }
    }


    v1beta1_validation_local_var = v1beta1_validation_create (
        strdup(expression->valuestring),
        message && !cJSON_IsNull(message) ? strdup(message->valuestring) : NULL,
        message_expression && !cJSON_IsNull(message_expression) ? strdup(message_expression->valuestring) : NULL,
        reason && !cJSON_IsNull(reason) ? strdup(reason->valuestring) : NULL
        );

    return v1beta1_validation_local_var;
end:
    return NULL;

}
