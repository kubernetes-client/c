#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_self_subject_rules_review_spec.h"



v1beta1_self_subject_rules_review_spec_t *v1beta1_self_subject_rules_review_spec_create(
    char *_namespace
    ) {
    v1beta1_self_subject_rules_review_spec_t *v1beta1_self_subject_rules_review_spec_local_var = malloc(sizeof(v1beta1_self_subject_rules_review_spec_t));
    if (!v1beta1_self_subject_rules_review_spec_local_var) {
        return NULL;
    }
    v1beta1_self_subject_rules_review_spec_local_var->_namespace = _namespace;

    return v1beta1_self_subject_rules_review_spec_local_var;
}


void v1beta1_self_subject_rules_review_spec_free(v1beta1_self_subject_rules_review_spec_t *v1beta1_self_subject_rules_review_spec) {
    if(NULL == v1beta1_self_subject_rules_review_spec){
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta1_self_subject_rules_review_spec->_namespace) {
        free(v1beta1_self_subject_rules_review_spec->_namespace);
        v1beta1_self_subject_rules_review_spec->_namespace = NULL;
    }
    free(v1beta1_self_subject_rules_review_spec);
}

cJSON *v1beta1_self_subject_rules_review_spec_convertToJSON(v1beta1_self_subject_rules_review_spec_t *v1beta1_self_subject_rules_review_spec) {
    cJSON *item = cJSON_CreateObject();

    // v1beta1_self_subject_rules_review_spec->_namespace
    if(v1beta1_self_subject_rules_review_spec->_namespace) { 
    if(cJSON_AddStringToObject(item, "namespace", v1beta1_self_subject_rules_review_spec->_namespace) == NULL) {
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

v1beta1_self_subject_rules_review_spec_t *v1beta1_self_subject_rules_review_spec_parseFromJSON(cJSON *v1beta1_self_subject_rules_review_specJSON){

    v1beta1_self_subject_rules_review_spec_t *v1beta1_self_subject_rules_review_spec_local_var = NULL;

    // v1beta1_self_subject_rules_review_spec->_namespace
    cJSON *_namespace = cJSON_GetObjectItemCaseSensitive(v1beta1_self_subject_rules_review_specJSON, "namespace");
    if (_namespace) { 
    if(!cJSON_IsString(_namespace))
    {
    goto end; //String
    }
    }


    v1beta1_self_subject_rules_review_spec_local_var = v1beta1_self_subject_rules_review_spec_create (
        _namespace ? strdup(_namespace->valuestring) : NULL
        );

    return v1beta1_self_subject_rules_review_spec_local_var;
end:
    return NULL;

}
