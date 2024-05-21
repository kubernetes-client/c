#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_audit_annotation.h"



v1_audit_annotation_t *v1_audit_annotation_create(
    char *key,
    char *value_expression
    ) {
    v1_audit_annotation_t *v1_audit_annotation_local_var = malloc(sizeof(v1_audit_annotation_t));
    if (!v1_audit_annotation_local_var) {
        return NULL;
    }
    v1_audit_annotation_local_var->key = key;
    v1_audit_annotation_local_var->value_expression = value_expression;

    return v1_audit_annotation_local_var;
}


void v1_audit_annotation_free(v1_audit_annotation_t *v1_audit_annotation) {
    if(NULL == v1_audit_annotation){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_audit_annotation->key) {
        free(v1_audit_annotation->key);
        v1_audit_annotation->key = NULL;
    }
    if (v1_audit_annotation->value_expression) {
        free(v1_audit_annotation->value_expression);
        v1_audit_annotation->value_expression = NULL;
    }
    free(v1_audit_annotation);
}

cJSON *v1_audit_annotation_convertToJSON(v1_audit_annotation_t *v1_audit_annotation) {
    cJSON *item = cJSON_CreateObject();

    // v1_audit_annotation->key
    if (!v1_audit_annotation->key) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "key", v1_audit_annotation->key) == NULL) {
    goto fail; //String
    }


    // v1_audit_annotation->value_expression
    if (!v1_audit_annotation->value_expression) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "valueExpression", v1_audit_annotation->value_expression) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_audit_annotation_t *v1_audit_annotation_parseFromJSON(cJSON *v1_audit_annotationJSON){

    v1_audit_annotation_t *v1_audit_annotation_local_var = NULL;

    // v1_audit_annotation->key
    cJSON *key = cJSON_GetObjectItemCaseSensitive(v1_audit_annotationJSON, "key");
    if (!key) {
        goto end;
    }

    
    if(!cJSON_IsString(key))
    {
    goto end; //String
    }

    // v1_audit_annotation->value_expression
    cJSON *value_expression = cJSON_GetObjectItemCaseSensitive(v1_audit_annotationJSON, "valueExpression");
    if (!value_expression) {
        goto end;
    }

    
    if(!cJSON_IsString(value_expression))
    {
    goto end; //String
    }


    v1_audit_annotation_local_var = v1_audit_annotation_create (
        strdup(key->valuestring),
        strdup(value_expression->valuestring)
        );

    return v1_audit_annotation_local_var;
end:
    return NULL;

}
