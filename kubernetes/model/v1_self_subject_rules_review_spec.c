#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_self_subject_rules_review_spec.h"



static v1_self_subject_rules_review_spec_t *v1_self_subject_rules_review_spec_create_internal(
    char *_namespace
    ) {
    v1_self_subject_rules_review_spec_t *v1_self_subject_rules_review_spec_local_var = malloc(sizeof(v1_self_subject_rules_review_spec_t));
    if (!v1_self_subject_rules_review_spec_local_var) {
        return NULL;
    }
    memset(v1_self_subject_rules_review_spec_local_var, 0, sizeof(v1_self_subject_rules_review_spec_t));
    v1_self_subject_rules_review_spec_local_var->_library_owned = 1;
    v1_self_subject_rules_review_spec_local_var->_namespace = _namespace;
    return v1_self_subject_rules_review_spec_local_var;
}

__attribute__((deprecated)) v1_self_subject_rules_review_spec_t *v1_self_subject_rules_review_spec_create(
    char *_namespace
    ) {
    v1_self_subject_rules_review_spec_t *result = v1_self_subject_rules_review_spec_create_internal (
        _namespace
        );
    if (!result) {
    }
    return result;
}

void v1_self_subject_rules_review_spec_free(v1_self_subject_rules_review_spec_t *v1_self_subject_rules_review_spec) {
    if(NULL == v1_self_subject_rules_review_spec){
        return ;
    }
    if(v1_self_subject_rules_review_spec->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_self_subject_rules_review_spec_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_self_subject_rules_review_spec->_namespace) {
        free(v1_self_subject_rules_review_spec->_namespace);
        v1_self_subject_rules_review_spec->_namespace = NULL;
    }
    free(v1_self_subject_rules_review_spec);
}

cJSON *v1_self_subject_rules_review_spec_convertToJSON(v1_self_subject_rules_review_spec_t *v1_self_subject_rules_review_spec) {
    cJSON *item = cJSON_CreateObject();

    // v1_self_subject_rules_review_spec->_namespace
    if(v1_self_subject_rules_review_spec->_namespace) {
    if(cJSON_AddStringToObject(item, "namespace", v1_self_subject_rules_review_spec->_namespace) == NULL) {
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

v1_self_subject_rules_review_spec_t *v1_self_subject_rules_review_spec_parseFromJSON(cJSON *v1_self_subject_rules_review_specJSON){

    v1_self_subject_rules_review_spec_t *v1_self_subject_rules_review_spec_local_var = NULL;

    char *_namespace_local_str = NULL;

    // v1_self_subject_rules_review_spec->_namespace
    cJSON *_namespace = cJSON_GetObjectItemCaseSensitive(v1_self_subject_rules_review_specJSON, "namespace");
    if (cJSON_IsNull(_namespace)) {
        _namespace = NULL;
    }
    if (_namespace) { 
    if(!cJSON_IsString(_namespace) && !cJSON_IsNull(_namespace))
    {
    goto end; //String
    }
    }


    if (_namespace && !cJSON_IsNull(_namespace)) _namespace_local_str = strdup(_namespace->valuestring);

    v1_self_subject_rules_review_spec_local_var = v1_self_subject_rules_review_spec_create_internal (
        _namespace_local_str
        );

    if (!v1_self_subject_rules_review_spec_local_var) {
        goto end;
    }

    return v1_self_subject_rules_review_spec_local_var;
end:
    if (_namespace_local_str) {
        free(_namespace_local_str);
        _namespace_local_str = NULL;
    }
    return NULL;

}
