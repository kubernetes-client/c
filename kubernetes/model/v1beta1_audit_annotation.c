#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_audit_annotation.h"



static v1beta1_audit_annotation_t *v1beta1_audit_annotation_create_internal(
    char *key,
    char *value_expression
    ) {
    v1beta1_audit_annotation_t *v1beta1_audit_annotation_local_var = malloc(sizeof(v1beta1_audit_annotation_t));
    if (!v1beta1_audit_annotation_local_var) {
        return NULL;
    }
    v1beta1_audit_annotation_local_var->key = key;
    v1beta1_audit_annotation_local_var->value_expression = value_expression;

    v1beta1_audit_annotation_local_var->_library_owned = 1;
    return v1beta1_audit_annotation_local_var;
}

__attribute__((deprecated)) v1beta1_audit_annotation_t *v1beta1_audit_annotation_create(
    char *key,
    char *value_expression
    ) {
    return v1beta1_audit_annotation_create_internal (
        key,
        value_expression
        );
}

void v1beta1_audit_annotation_free(v1beta1_audit_annotation_t *v1beta1_audit_annotation) {
    if(NULL == v1beta1_audit_annotation){
        return ;
    }
    if(v1beta1_audit_annotation->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1beta1_audit_annotation_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta1_audit_annotation->key) {
        free(v1beta1_audit_annotation->key);
        v1beta1_audit_annotation->key = NULL;
    }
    if (v1beta1_audit_annotation->value_expression) {
        free(v1beta1_audit_annotation->value_expression);
        v1beta1_audit_annotation->value_expression = NULL;
    }
    free(v1beta1_audit_annotation);
}

cJSON *v1beta1_audit_annotation_convertToJSON(v1beta1_audit_annotation_t *v1beta1_audit_annotation) {
    cJSON *item = cJSON_CreateObject();

    // v1beta1_audit_annotation->key
    if (!v1beta1_audit_annotation->key) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "key", v1beta1_audit_annotation->key) == NULL) {
    goto fail; //String
    }


    // v1beta1_audit_annotation->value_expression
    if (!v1beta1_audit_annotation->value_expression) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "valueExpression", v1beta1_audit_annotation->value_expression) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1beta1_audit_annotation_t *v1beta1_audit_annotation_parseFromJSON(cJSON *v1beta1_audit_annotationJSON){

    v1beta1_audit_annotation_t *v1beta1_audit_annotation_local_var = NULL;

    // v1beta1_audit_annotation->key
    cJSON *key = cJSON_GetObjectItemCaseSensitive(v1beta1_audit_annotationJSON, "key");
    if (cJSON_IsNull(key)) {
        key = NULL;
    }
    if (!key) {
        goto end;
    }

    
    if(!cJSON_IsString(key))
    {
    goto end; //String
    }

    // v1beta1_audit_annotation->value_expression
    cJSON *value_expression = cJSON_GetObjectItemCaseSensitive(v1beta1_audit_annotationJSON, "valueExpression");
    if (cJSON_IsNull(value_expression)) {
        value_expression = NULL;
    }
    if (!value_expression) {
        goto end;
    }

    
    if(!cJSON_IsString(value_expression))
    {
    goto end; //String
    }


    v1beta1_audit_annotation_local_var = v1beta1_audit_annotation_create_internal (
        strdup(key->valuestring),
        strdup(value_expression->valuestring)
        );

    return v1beta1_audit_annotation_local_var;
end:
    return NULL;

}
