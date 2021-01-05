#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha1_policy_rules_with_subjects.h"



v1alpha1_policy_rules_with_subjects_t *v1alpha1_policy_rules_with_subjects_create(
    list_t *non_resource_rules,
    list_t *resource_rules,
    list_t *subjects
    ) {
    v1alpha1_policy_rules_with_subjects_t *v1alpha1_policy_rules_with_subjects_local_var = malloc(sizeof(v1alpha1_policy_rules_with_subjects_t));
    if (!v1alpha1_policy_rules_with_subjects_local_var) {
        return NULL;
    }
    v1alpha1_policy_rules_with_subjects_local_var->non_resource_rules = non_resource_rules;
    v1alpha1_policy_rules_with_subjects_local_var->resource_rules = resource_rules;
    v1alpha1_policy_rules_with_subjects_local_var->subjects = subjects;

    return v1alpha1_policy_rules_with_subjects_local_var;
}


void v1alpha1_policy_rules_with_subjects_free(v1alpha1_policy_rules_with_subjects_t *v1alpha1_policy_rules_with_subjects) {
    if(NULL == v1alpha1_policy_rules_with_subjects){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha1_policy_rules_with_subjects->non_resource_rules) {
        list_ForEach(listEntry, v1alpha1_policy_rules_with_subjects->non_resource_rules) {
            v1alpha1_non_resource_policy_rule_free(listEntry->data);
        }
        list_free(v1alpha1_policy_rules_with_subjects->non_resource_rules);
        v1alpha1_policy_rules_with_subjects->non_resource_rules = NULL;
    }
    if (v1alpha1_policy_rules_with_subjects->resource_rules) {
        list_ForEach(listEntry, v1alpha1_policy_rules_with_subjects->resource_rules) {
            v1alpha1_resource_policy_rule_free(listEntry->data);
        }
        list_free(v1alpha1_policy_rules_with_subjects->resource_rules);
        v1alpha1_policy_rules_with_subjects->resource_rules = NULL;
    }
    if (v1alpha1_policy_rules_with_subjects->subjects) {
        list_ForEach(listEntry, v1alpha1_policy_rules_with_subjects->subjects) {
            flowcontrol_v1alpha1_subject_free(listEntry->data);
        }
        list_free(v1alpha1_policy_rules_with_subjects->subjects);
        v1alpha1_policy_rules_with_subjects->subjects = NULL;
    }
    free(v1alpha1_policy_rules_with_subjects);
}

cJSON *v1alpha1_policy_rules_with_subjects_convertToJSON(v1alpha1_policy_rules_with_subjects_t *v1alpha1_policy_rules_with_subjects) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha1_policy_rules_with_subjects->non_resource_rules
    if(v1alpha1_policy_rules_with_subjects->non_resource_rules) { 
    cJSON *non_resource_rules = cJSON_AddArrayToObject(item, "nonResourceRules");
    if(non_resource_rules == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *non_resource_rulesListEntry;
    if (v1alpha1_policy_rules_with_subjects->non_resource_rules) {
    list_ForEach(non_resource_rulesListEntry, v1alpha1_policy_rules_with_subjects->non_resource_rules) {
    cJSON *itemLocal = v1alpha1_non_resource_policy_rule_convertToJSON(non_resource_rulesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(non_resource_rules, itemLocal);
    }
    }
     } 


    // v1alpha1_policy_rules_with_subjects->resource_rules
    if(v1alpha1_policy_rules_with_subjects->resource_rules) { 
    cJSON *resource_rules = cJSON_AddArrayToObject(item, "resourceRules");
    if(resource_rules == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *resource_rulesListEntry;
    if (v1alpha1_policy_rules_with_subjects->resource_rules) {
    list_ForEach(resource_rulesListEntry, v1alpha1_policy_rules_with_subjects->resource_rules) {
    cJSON *itemLocal = v1alpha1_resource_policy_rule_convertToJSON(resource_rulesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(resource_rules, itemLocal);
    }
    }
     } 


    // v1alpha1_policy_rules_with_subjects->subjects
    if (!v1alpha1_policy_rules_with_subjects->subjects) {
        goto fail;
    }
    
    cJSON *subjects = cJSON_AddArrayToObject(item, "subjects");
    if(subjects == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *subjectsListEntry;
    if (v1alpha1_policy_rules_with_subjects->subjects) {
    list_ForEach(subjectsListEntry, v1alpha1_policy_rules_with_subjects->subjects) {
    cJSON *itemLocal = flowcontrol_v1alpha1_subject_convertToJSON(subjectsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(subjects, itemLocal);
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1alpha1_policy_rules_with_subjects_t *v1alpha1_policy_rules_with_subjects_parseFromJSON(cJSON *v1alpha1_policy_rules_with_subjectsJSON){

    v1alpha1_policy_rules_with_subjects_t *v1alpha1_policy_rules_with_subjects_local_var = NULL;

    // v1alpha1_policy_rules_with_subjects->non_resource_rules
    cJSON *non_resource_rules = cJSON_GetObjectItemCaseSensitive(v1alpha1_policy_rules_with_subjectsJSON, "nonResourceRules");
    list_t *non_resource_rulesList;
    if (non_resource_rules) { 
    cJSON *non_resource_rules_local_nonprimitive;
    if(!cJSON_IsArray(non_resource_rules)){
        goto end; //nonprimitive container
    }

    non_resource_rulesList = list_create();

    cJSON_ArrayForEach(non_resource_rules_local_nonprimitive,non_resource_rules )
    {
        if(!cJSON_IsObject(non_resource_rules_local_nonprimitive)){
            goto end;
        }
        v1alpha1_non_resource_policy_rule_t *non_resource_rulesItem = v1alpha1_non_resource_policy_rule_parseFromJSON(non_resource_rules_local_nonprimitive);

        list_addElement(non_resource_rulesList, non_resource_rulesItem);
    }
    }

    // v1alpha1_policy_rules_with_subjects->resource_rules
    cJSON *resource_rules = cJSON_GetObjectItemCaseSensitive(v1alpha1_policy_rules_with_subjectsJSON, "resourceRules");
    list_t *resource_rulesList;
    if (resource_rules) { 
    cJSON *resource_rules_local_nonprimitive;
    if(!cJSON_IsArray(resource_rules)){
        goto end; //nonprimitive container
    }

    resource_rulesList = list_create();

    cJSON_ArrayForEach(resource_rules_local_nonprimitive,resource_rules )
    {
        if(!cJSON_IsObject(resource_rules_local_nonprimitive)){
            goto end;
        }
        v1alpha1_resource_policy_rule_t *resource_rulesItem = v1alpha1_resource_policy_rule_parseFromJSON(resource_rules_local_nonprimitive);

        list_addElement(resource_rulesList, resource_rulesItem);
    }
    }

    // v1alpha1_policy_rules_with_subjects->subjects
    cJSON *subjects = cJSON_GetObjectItemCaseSensitive(v1alpha1_policy_rules_with_subjectsJSON, "subjects");
    if (!subjects) {
        goto end;
    }

    list_t *subjectsList;
    
    cJSON *subjects_local_nonprimitive;
    if(!cJSON_IsArray(subjects)){
        goto end; //nonprimitive container
    }

    subjectsList = list_create();

    cJSON_ArrayForEach(subjects_local_nonprimitive,subjects )
    {
        if(!cJSON_IsObject(subjects_local_nonprimitive)){
            goto end;
        }
        flowcontrol_v1alpha1_subject_t *subjectsItem = flowcontrol_v1alpha1_subject_parseFromJSON(subjects_local_nonprimitive);

        list_addElement(subjectsList, subjectsItem);
    }


    v1alpha1_policy_rules_with_subjects_local_var = v1alpha1_policy_rules_with_subjects_create (
        non_resource_rules ? non_resource_rulesList : NULL,
        resource_rules ? resource_rulesList : NULL,
        subjectsList
        );

    return v1alpha1_policy_rules_with_subjects_local_var;
end:
    return NULL;

}
