#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_self_subject_rules_review_spec.h"



v1_self_subject_rules_review_spec_t *v1_self_subject_rules_review_spec_create(
    char *_namespace
    ) {
    v1_self_subject_rules_review_spec_t *v1_self_subject_rules_review_spec_local_var = malloc(sizeof(v1_self_subject_rules_review_spec_t));
    if (!v1_self_subject_rules_review_spec_local_var) {
        return NULL;
    }
    v1_self_subject_rules_review_spec_local_var->_namespace = _namespace;

    return v1_self_subject_rules_review_spec_local_var;
}


void v1_self_subject_rules_review_spec_free(v1_self_subject_rules_review_spec_t *v1_self_subject_rules_review_spec) {
    if(NULL == v1_self_subject_rules_review_spec){
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

    // v1_self_subject_rules_review_spec->_namespace
    cJSON *_namespace = cJSON_GetObjectItemCaseSensitive(v1_self_subject_rules_review_specJSON, "namespace");
    if (_namespace) { 
    if(!cJSON_IsString(_namespace))
    {
    goto end; //String
    }
    }


    v1_self_subject_rules_review_spec_local_var = v1_self_subject_rules_review_spec_create (
        _namespace ? strdup(_namespace->valuestring) : NULL
        );

    return v1_self_subject_rules_review_spec_local_var;
end:
    return NULL;

}
