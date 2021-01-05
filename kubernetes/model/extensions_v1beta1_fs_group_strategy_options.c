#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "extensions_v1beta1_fs_group_strategy_options.h"



extensions_v1beta1_fs_group_strategy_options_t *extensions_v1beta1_fs_group_strategy_options_create(
    list_t *ranges,
    char *rule
    ) {
    extensions_v1beta1_fs_group_strategy_options_t *extensions_v1beta1_fs_group_strategy_options_local_var = malloc(sizeof(extensions_v1beta1_fs_group_strategy_options_t));
    if (!extensions_v1beta1_fs_group_strategy_options_local_var) {
        return NULL;
    }
    extensions_v1beta1_fs_group_strategy_options_local_var->ranges = ranges;
    extensions_v1beta1_fs_group_strategy_options_local_var->rule = rule;

    return extensions_v1beta1_fs_group_strategy_options_local_var;
}


void extensions_v1beta1_fs_group_strategy_options_free(extensions_v1beta1_fs_group_strategy_options_t *extensions_v1beta1_fs_group_strategy_options) {
    if(NULL == extensions_v1beta1_fs_group_strategy_options){
        return ;
    }
    listEntry_t *listEntry;
    if (extensions_v1beta1_fs_group_strategy_options->ranges) {
        list_ForEach(listEntry, extensions_v1beta1_fs_group_strategy_options->ranges) {
            extensions_v1beta1_id_range_free(listEntry->data);
        }
        list_free(extensions_v1beta1_fs_group_strategy_options->ranges);
        extensions_v1beta1_fs_group_strategy_options->ranges = NULL;
    }
    if (extensions_v1beta1_fs_group_strategy_options->rule) {
        free(extensions_v1beta1_fs_group_strategy_options->rule);
        extensions_v1beta1_fs_group_strategy_options->rule = NULL;
    }
    free(extensions_v1beta1_fs_group_strategy_options);
}

cJSON *extensions_v1beta1_fs_group_strategy_options_convertToJSON(extensions_v1beta1_fs_group_strategy_options_t *extensions_v1beta1_fs_group_strategy_options) {
    cJSON *item = cJSON_CreateObject();

    // extensions_v1beta1_fs_group_strategy_options->ranges
    if(extensions_v1beta1_fs_group_strategy_options->ranges) { 
    cJSON *ranges = cJSON_AddArrayToObject(item, "ranges");
    if(ranges == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *rangesListEntry;
    if (extensions_v1beta1_fs_group_strategy_options->ranges) {
    list_ForEach(rangesListEntry, extensions_v1beta1_fs_group_strategy_options->ranges) {
    cJSON *itemLocal = extensions_v1beta1_id_range_convertToJSON(rangesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(ranges, itemLocal);
    }
    }
     } 


    // extensions_v1beta1_fs_group_strategy_options->rule
    if(extensions_v1beta1_fs_group_strategy_options->rule) { 
    if(cJSON_AddStringToObject(item, "rule", extensions_v1beta1_fs_group_strategy_options->rule) == NULL) {
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

extensions_v1beta1_fs_group_strategy_options_t *extensions_v1beta1_fs_group_strategy_options_parseFromJSON(cJSON *extensions_v1beta1_fs_group_strategy_optionsJSON){

    extensions_v1beta1_fs_group_strategy_options_t *extensions_v1beta1_fs_group_strategy_options_local_var = NULL;

    // extensions_v1beta1_fs_group_strategy_options->ranges
    cJSON *ranges = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_fs_group_strategy_optionsJSON, "ranges");
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
        extensions_v1beta1_id_range_t *rangesItem = extensions_v1beta1_id_range_parseFromJSON(ranges_local_nonprimitive);

        list_addElement(rangesList, rangesItem);
    }
    }

    // extensions_v1beta1_fs_group_strategy_options->rule
    cJSON *rule = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_fs_group_strategy_optionsJSON, "rule");
    if (rule) { 
    if(!cJSON_IsString(rule))
    {
    goto end; //String
    }
    }


    extensions_v1beta1_fs_group_strategy_options_local_var = extensions_v1beta1_fs_group_strategy_options_create (
        ranges ? rangesList : NULL,
        rule ? strdup(rule->valuestring) : NULL
        );

    return extensions_v1beta1_fs_group_strategy_options_local_var;
end:
    return NULL;

}
