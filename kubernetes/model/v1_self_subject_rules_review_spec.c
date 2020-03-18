#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_self_subject_rules_review_spec.h"



v1_self_subject_rules_review_spec_t *v1_self_subject_rules_review_spec_create(
    char *namespace
    ) {
    v1_self_subject_rules_review_spec_t *v1_self_subject_rules_review_spec_local_var = malloc(sizeof(v1_self_subject_rules_review_spec_t));
    if (!v1_self_subject_rules_review_spec_local_var) {
        return NULL;
    }
    v1_self_subject_rules_review_spec_local_var->namespace = namespace;

    return v1_self_subject_rules_review_spec_local_var;
}


void v1_self_subject_rules_review_spec_free(v1_self_subject_rules_review_spec_t *v1_self_subject_rules_review_spec) {
    if(NULL == v1_self_subject_rules_review_spec){
        return ;
    }
    listEntry_t *listEntry;
    free(v1_self_subject_rules_review_spec->namespace);
    free(v1_self_subject_rules_review_spec);
}

cJSON *v1_self_subject_rules_review_spec_convertToJSON(v1_self_subject_rules_review_spec_t *v1_self_subject_rules_review_spec) {
    cJSON *item = cJSON_CreateObject();

    // v1_self_subject_rules_review_spec->namespace
    if(v1_self_subject_rules_review_spec->namespace) { 
    if(cJSON_AddStringToObject(item, "namespace", v1_self_subject_rules_review_spec->namespace) == NULL) {
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

    // v1_self_subject_rules_review_spec->namespace
    cJSON *namespace = cJSON_GetObjectItemCaseSensitive(v1_self_subject_rules_review_specJSON, "namespace");
    if (namespace) { 
    if(!cJSON_IsString(namespace))
    {
    goto end; //String
    }
    }


    v1_self_subject_rules_review_spec_local_var = v1_self_subject_rules_review_spec_create (
        namespace ? strdup(namespace->valuestring) : NULL
        );

    return v1_self_subject_rules_review_spec_local_var;
end:
    return NULL;

}
