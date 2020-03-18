#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha1_non_resource_policy_rule.h"



v1alpha1_non_resource_policy_rule_t *v1alpha1_non_resource_policy_rule_create(
    list_t *non_resource_ur_ls,
    list_t *verbs
    ) {
    v1alpha1_non_resource_policy_rule_t *v1alpha1_non_resource_policy_rule_local_var = malloc(sizeof(v1alpha1_non_resource_policy_rule_t));
    if (!v1alpha1_non_resource_policy_rule_local_var) {
        return NULL;
    }
    v1alpha1_non_resource_policy_rule_local_var->non_resource_ur_ls = non_resource_ur_ls;
    v1alpha1_non_resource_policy_rule_local_var->verbs = verbs;

    return v1alpha1_non_resource_policy_rule_local_var;
}


void v1alpha1_non_resource_policy_rule_free(v1alpha1_non_resource_policy_rule_t *v1alpha1_non_resource_policy_rule) {
    if(NULL == v1alpha1_non_resource_policy_rule){
        return ;
    }
    listEntry_t *listEntry;
    list_ForEach(listEntry, v1alpha1_non_resource_policy_rule->non_resource_ur_ls) {
        free(listEntry->data);
    }
    list_free(v1alpha1_non_resource_policy_rule->non_resource_ur_ls);
    list_ForEach(listEntry, v1alpha1_non_resource_policy_rule->verbs) {
        free(listEntry->data);
    }
    list_free(v1alpha1_non_resource_policy_rule->verbs);
    free(v1alpha1_non_resource_policy_rule);
}

cJSON *v1alpha1_non_resource_policy_rule_convertToJSON(v1alpha1_non_resource_policy_rule_t *v1alpha1_non_resource_policy_rule) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha1_non_resource_policy_rule->non_resource_ur_ls
    if (!v1alpha1_non_resource_policy_rule->non_resource_ur_ls) {
        goto fail;
    }
    
    cJSON *non_resource_ur_ls = cJSON_AddArrayToObject(item, "nonResourceURLs");
    if(non_resource_ur_ls == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *non_resource_ur_lsListEntry;
    list_ForEach(non_resource_ur_lsListEntry, v1alpha1_non_resource_policy_rule->non_resource_ur_ls) {
    if(cJSON_AddStringToObject(non_resource_ur_ls, "", (char*)non_resource_ur_lsListEntry->data) == NULL)
    {
        goto fail;
    }
    }


    // v1alpha1_non_resource_policy_rule->verbs
    if (!v1alpha1_non_resource_policy_rule->verbs) {
        goto fail;
    }
    
    cJSON *verbs = cJSON_AddArrayToObject(item, "verbs");
    if(verbs == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *verbsListEntry;
    list_ForEach(verbsListEntry, v1alpha1_non_resource_policy_rule->verbs) {
    if(cJSON_AddStringToObject(verbs, "", (char*)verbsListEntry->data) == NULL)
    {
        goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1alpha1_non_resource_policy_rule_t *v1alpha1_non_resource_policy_rule_parseFromJSON(cJSON *v1alpha1_non_resource_policy_ruleJSON){

    v1alpha1_non_resource_policy_rule_t *v1alpha1_non_resource_policy_rule_local_var = NULL;

    // v1alpha1_non_resource_policy_rule->non_resource_ur_ls
    cJSON *non_resource_ur_ls = cJSON_GetObjectItemCaseSensitive(v1alpha1_non_resource_policy_ruleJSON, "nonResourceURLs");
    if (!non_resource_ur_ls) {
        goto end;
    }

    list_t *non_resource_ur_lsList;
    
    cJSON *non_resource_ur_ls_local;
    if(!cJSON_IsArray(non_resource_ur_ls)) {
        goto end;//primitive container
    }
    non_resource_ur_lsList = list_create();

    cJSON_ArrayForEach(non_resource_ur_ls_local, non_resource_ur_ls)
    {
        if(!cJSON_IsString(non_resource_ur_ls_local))
        {
            goto end;
        }
        list_addElement(non_resource_ur_lsList , strdup(non_resource_ur_ls_local->valuestring));
    }

    // v1alpha1_non_resource_policy_rule->verbs
    cJSON *verbs = cJSON_GetObjectItemCaseSensitive(v1alpha1_non_resource_policy_ruleJSON, "verbs");
    if (!verbs) {
        goto end;
    }

    list_t *verbsList;
    
    cJSON *verbs_local;
    if(!cJSON_IsArray(verbs)) {
        goto end;//primitive container
    }
    verbsList = list_create();

    cJSON_ArrayForEach(verbs_local, verbs)
    {
        if(!cJSON_IsString(verbs_local))
        {
            goto end;
        }
        list_addElement(verbsList , strdup(verbs_local->valuestring));
    }


    v1alpha1_non_resource_policy_rule_local_var = v1alpha1_non_resource_policy_rule_create (
        non_resource_ur_lsList,
        verbsList
        );

    return v1alpha1_non_resource_policy_rule_local_var;
end:
    return NULL;

}
