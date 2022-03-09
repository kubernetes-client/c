#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_fs_group_strategy_options.h"



v1beta1_fs_group_strategy_options_t *v1beta1_fs_group_strategy_options_create(
    list_t *ranges,
    char *rule
    ) {
    v1beta1_fs_group_strategy_options_t *v1beta1_fs_group_strategy_options_local_var = malloc(sizeof(v1beta1_fs_group_strategy_options_t));
    if (!v1beta1_fs_group_strategy_options_local_var) {
        return NULL;
    }
    v1beta1_fs_group_strategy_options_local_var->ranges = ranges;
    v1beta1_fs_group_strategy_options_local_var->rule = rule;

    return v1beta1_fs_group_strategy_options_local_var;
}


void v1beta1_fs_group_strategy_options_free(v1beta1_fs_group_strategy_options_t *v1beta1_fs_group_strategy_options) {
    if(NULL == v1beta1_fs_group_strategy_options){
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta1_fs_group_strategy_options->ranges) {
        list_ForEach(listEntry, v1beta1_fs_group_strategy_options->ranges) {
            v1beta1_id_range_free(listEntry->data);
        }
        list_freeList(v1beta1_fs_group_strategy_options->ranges);
        v1beta1_fs_group_strategy_options->ranges = NULL;
    }
    if (v1beta1_fs_group_strategy_options->rule) {
        free(v1beta1_fs_group_strategy_options->rule);
        v1beta1_fs_group_strategy_options->rule = NULL;
    }
    free(v1beta1_fs_group_strategy_options);
}

cJSON *v1beta1_fs_group_strategy_options_convertToJSON(v1beta1_fs_group_strategy_options_t *v1beta1_fs_group_strategy_options) {
    cJSON *item = cJSON_CreateObject();

    // v1beta1_fs_group_strategy_options->ranges
    if(v1beta1_fs_group_strategy_options->ranges) { 
    cJSON *ranges = cJSON_AddArrayToObject(item, "ranges");
    if(ranges == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *rangesListEntry;
    if (v1beta1_fs_group_strategy_options->ranges) {
    list_ForEach(rangesListEntry, v1beta1_fs_group_strategy_options->ranges) {
    cJSON *itemLocal = v1beta1_id_range_convertToJSON(rangesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(ranges, itemLocal);
    }
    }
     } 


    // v1beta1_fs_group_strategy_options->rule
    if(v1beta1_fs_group_strategy_options->rule) { 
    if(cJSON_AddStringToObject(item, "rule", v1beta1_fs_group_strategy_options->rule) == NULL) {
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

v1beta1_fs_group_strategy_options_t *v1beta1_fs_group_strategy_options_parseFromJSON(cJSON *v1beta1_fs_group_strategy_optionsJSON){

    v1beta1_fs_group_strategy_options_t *v1beta1_fs_group_strategy_options_local_var = NULL;

    // v1beta1_fs_group_strategy_options->ranges
    cJSON *ranges = cJSON_GetObjectItemCaseSensitive(v1beta1_fs_group_strategy_optionsJSON, "ranges");
    list_t *rangesList;
    if (ranges) { 
    cJSON *ranges_local_nonprimitive;
    if(!cJSON_IsArray(ranges)){
        goto end; //nonprimitive container
    }

    rangesList = list_createList();

    cJSON_ArrayForEach(ranges_local_nonprimitive,ranges )
    {
        if(!cJSON_IsObject(ranges_local_nonprimitive)){
            goto end;
        }
        v1beta1_id_range_t *rangesItem = v1beta1_id_range_parseFromJSON(ranges_local_nonprimitive);

        list_addElement(rangesList, rangesItem);
    }
    }

    // v1beta1_fs_group_strategy_options->rule
    cJSON *rule = cJSON_GetObjectItemCaseSensitive(v1beta1_fs_group_strategy_optionsJSON, "rule");
    if (rule) { 
    if(!cJSON_IsString(rule))
    {
    goto end; //String
    }
    }


    v1beta1_fs_group_strategy_options_local_var = v1beta1_fs_group_strategy_options_create (
        ranges ? rangesList : NULL,
        rule ? strdup(rule->valuestring) : NULL
        );

    return v1beta1_fs_group_strategy_options_local_var;
end:
    return NULL;

}
