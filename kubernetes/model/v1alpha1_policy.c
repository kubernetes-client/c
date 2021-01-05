#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha1_policy.h"



v1alpha1_policy_t *v1alpha1_policy_create(
    char *level,
    list_t *stages
    ) {
    v1alpha1_policy_t *v1alpha1_policy_local_var = malloc(sizeof(v1alpha1_policy_t));
    if (!v1alpha1_policy_local_var) {
        return NULL;
    }
    v1alpha1_policy_local_var->level = level;
    v1alpha1_policy_local_var->stages = stages;

    return v1alpha1_policy_local_var;
}


void v1alpha1_policy_free(v1alpha1_policy_t *v1alpha1_policy) {
    if(NULL == v1alpha1_policy){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha1_policy->level) {
        free(v1alpha1_policy->level);
        v1alpha1_policy->level = NULL;
    }
    if (v1alpha1_policy->stages) {
        list_ForEach(listEntry, v1alpha1_policy->stages) {
            free(listEntry->data);
        }
        list_free(v1alpha1_policy->stages);
        v1alpha1_policy->stages = NULL;
    }
    free(v1alpha1_policy);
}

cJSON *v1alpha1_policy_convertToJSON(v1alpha1_policy_t *v1alpha1_policy) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha1_policy->level
    if (!v1alpha1_policy->level) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "level", v1alpha1_policy->level) == NULL) {
    goto fail; //String
    }


    // v1alpha1_policy->stages
    if(v1alpha1_policy->stages) { 
    cJSON *stages = cJSON_AddArrayToObject(item, "stages");
    if(stages == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *stagesListEntry;
    list_ForEach(stagesListEntry, v1alpha1_policy->stages) {
    if(cJSON_AddStringToObject(stages, "", (char*)stagesListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1alpha1_policy_t *v1alpha1_policy_parseFromJSON(cJSON *v1alpha1_policyJSON){

    v1alpha1_policy_t *v1alpha1_policy_local_var = NULL;

    // v1alpha1_policy->level
    cJSON *level = cJSON_GetObjectItemCaseSensitive(v1alpha1_policyJSON, "level");
    if (!level) {
        goto end;
    }

    
    if(!cJSON_IsString(level))
    {
    goto end; //String
    }

    // v1alpha1_policy->stages
    cJSON *stages = cJSON_GetObjectItemCaseSensitive(v1alpha1_policyJSON, "stages");
    list_t *stagesList;
    if (stages) { 
    cJSON *stages_local;
    if(!cJSON_IsArray(stages)) {
        goto end;//primitive container
    }
    stagesList = list_create();

    cJSON_ArrayForEach(stages_local, stages)
    {
        if(!cJSON_IsString(stages_local))
        {
            goto end;
        }
        list_addElement(stagesList , strdup(stages_local->valuestring));
    }
    }


    v1alpha1_policy_local_var = v1alpha1_policy_create (
        strdup(level->valuestring),
        stages ? stagesList : NULL
        );

    return v1alpha1_policy_local_var;
end:
    return NULL;

}
