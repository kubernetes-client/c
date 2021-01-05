#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "policy_v1beta1_fs_group_strategy_options.h"



policy_v1beta1_fs_group_strategy_options_t *policy_v1beta1_fs_group_strategy_options_create(
    list_t *ranges,
    char *rule
    ) {
    policy_v1beta1_fs_group_strategy_options_t *policy_v1beta1_fs_group_strategy_options_local_var = malloc(sizeof(policy_v1beta1_fs_group_strategy_options_t));
    if (!policy_v1beta1_fs_group_strategy_options_local_var) {
        return NULL;
    }
    policy_v1beta1_fs_group_strategy_options_local_var->ranges = ranges;
    policy_v1beta1_fs_group_strategy_options_local_var->rule = rule;

    return policy_v1beta1_fs_group_strategy_options_local_var;
}


void policy_v1beta1_fs_group_strategy_options_free(policy_v1beta1_fs_group_strategy_options_t *policy_v1beta1_fs_group_strategy_options) {
    if(NULL == policy_v1beta1_fs_group_strategy_options){
        return ;
    }
    listEntry_t *listEntry;
    if (policy_v1beta1_fs_group_strategy_options->ranges) {
        list_ForEach(listEntry, policy_v1beta1_fs_group_strategy_options->ranges) {
            policy_v1beta1_id_range_free(listEntry->data);
        }
        list_free(policy_v1beta1_fs_group_strategy_options->ranges);
        policy_v1beta1_fs_group_strategy_options->ranges = NULL;
    }
    if (policy_v1beta1_fs_group_strategy_options->rule) {
        free(policy_v1beta1_fs_group_strategy_options->rule);
        policy_v1beta1_fs_group_strategy_options->rule = NULL;
    }
    free(policy_v1beta1_fs_group_strategy_options);
}

cJSON *policy_v1beta1_fs_group_strategy_options_convertToJSON(policy_v1beta1_fs_group_strategy_options_t *policy_v1beta1_fs_group_strategy_options) {
    cJSON *item = cJSON_CreateObject();

    // policy_v1beta1_fs_group_strategy_options->ranges
    if(policy_v1beta1_fs_group_strategy_options->ranges) { 
    cJSON *ranges = cJSON_AddArrayToObject(item, "ranges");
    if(ranges == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *rangesListEntry;
    if (policy_v1beta1_fs_group_strategy_options->ranges) {
    list_ForEach(rangesListEntry, policy_v1beta1_fs_group_strategy_options->ranges) {
    cJSON *itemLocal = policy_v1beta1_id_range_convertToJSON(rangesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(ranges, itemLocal);
    }
    }
     } 


    // policy_v1beta1_fs_group_strategy_options->rule
    if(policy_v1beta1_fs_group_strategy_options->rule) { 
    if(cJSON_AddStringToObject(item, "rule", policy_v1beta1_fs_group_strategy_options->rule) == NULL) {
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

policy_v1beta1_fs_group_strategy_options_t *policy_v1beta1_fs_group_strategy_options_parseFromJSON(cJSON *policy_v1beta1_fs_group_strategy_optionsJSON){

    policy_v1beta1_fs_group_strategy_options_t *policy_v1beta1_fs_group_strategy_options_local_var = NULL;

    // policy_v1beta1_fs_group_strategy_options->ranges
    cJSON *ranges = cJSON_GetObjectItemCaseSensitive(policy_v1beta1_fs_group_strategy_optionsJSON, "ranges");
    list_t *rangesList;
    if (ranges) { 
    cJSON *ranges_local_nonprimitive;
    if(!cJSON_IsArray(ranges)){
        goto end; //nonprimitive container
    }

    rangesList = list_create();

    cJSON_ArrayForEach(ranges_local_nonprimitive,ranges )
    {
        if(!cJSON_IsObject(ranges_local_nonprimitive)){
            goto end;
        }
        policy_v1beta1_id_range_t *rangesItem = policy_v1beta1_id_range_parseFromJSON(ranges_local_nonprimitive);

        list_addElement(rangesList, rangesItem);
    }
    }

    // policy_v1beta1_fs_group_strategy_options->rule
    cJSON *rule = cJSON_GetObjectItemCaseSensitive(policy_v1beta1_fs_group_strategy_optionsJSON, "rule");
    if (rule) { 
    if(!cJSON_IsString(rule))
    {
    goto end; //String
    }
    }


    policy_v1beta1_fs_group_strategy_options_local_var = policy_v1beta1_fs_group_strategy_options_create (
        ranges ? rangesList : NULL,
        rule ? strdup(rule->valuestring) : NULL
        );

    return policy_v1beta1_fs_group_strategy_options_local_var;
end:
    return NULL;

}
