#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_limit_range_spec.h"



v1_limit_range_spec_t *v1_limit_range_spec_create(
    list_t *limits
    ) {
    v1_limit_range_spec_t *v1_limit_range_spec_local_var = malloc(sizeof(v1_limit_range_spec_t));
    if (!v1_limit_range_spec_local_var) {
        return NULL;
    }
    v1_limit_range_spec_local_var->limits = limits;

    return v1_limit_range_spec_local_var;
}


void v1_limit_range_spec_free(v1_limit_range_spec_t *v1_limit_range_spec) {
    if(NULL == v1_limit_range_spec){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_limit_range_spec->limits) {
        list_ForEach(listEntry, v1_limit_range_spec->limits) {
            v1_limit_range_item_free(listEntry->data);
        }
        list_free(v1_limit_range_spec->limits);
        v1_limit_range_spec->limits = NULL;
    }
    free(v1_limit_range_spec);
}

cJSON *v1_limit_range_spec_convertToJSON(v1_limit_range_spec_t *v1_limit_range_spec) {
    cJSON *item = cJSON_CreateObject();

    // v1_limit_range_spec->limits
    if (!v1_limit_range_spec->limits) {
        goto fail;
    }
    
    cJSON *limits = cJSON_AddArrayToObject(item, "limits");
    if(limits == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *limitsListEntry;
    if (v1_limit_range_spec->limits) {
    list_ForEach(limitsListEntry, v1_limit_range_spec->limits) {
    cJSON *itemLocal = v1_limit_range_item_convertToJSON(limitsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(limits, itemLocal);
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_limit_range_spec_t *v1_limit_range_spec_parseFromJSON(cJSON *v1_limit_range_specJSON){

    v1_limit_range_spec_t *v1_limit_range_spec_local_var = NULL;

    // v1_limit_range_spec->limits
    cJSON *limits = cJSON_GetObjectItemCaseSensitive(v1_limit_range_specJSON, "limits");
    if (!limits) {
        goto end;
    }

    list_t *limitsList;
    
    cJSON *limits_local_nonprimitive;
    if(!cJSON_IsArray(limits)){
        goto end; //nonprimitive container
    }

    limitsList = list_create();

    cJSON_ArrayForEach(limits_local_nonprimitive,limits )
    {
        if(!cJSON_IsObject(limits_local_nonprimitive)){
            goto end;
        }
        v1_limit_range_item_t *limitsItem = v1_limit_range_item_parseFromJSON(limits_local_nonprimitive);

        list_addElement(limitsList, limitsItem);
    }


    v1_limit_range_spec_local_var = v1_limit_range_spec_create (
        limitsList
        );

    return v1_limit_range_spec_local_var;
end:
    return NULL;

}
