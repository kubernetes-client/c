#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha2_named_resources_filter.h"



v1alpha2_named_resources_filter_t *v1alpha2_named_resources_filter_create(
    char *selector
    ) {
    v1alpha2_named_resources_filter_t *v1alpha2_named_resources_filter_local_var = malloc(sizeof(v1alpha2_named_resources_filter_t));
    if (!v1alpha2_named_resources_filter_local_var) {
        return NULL;
    }
    v1alpha2_named_resources_filter_local_var->selector = selector;

    return v1alpha2_named_resources_filter_local_var;
}


void v1alpha2_named_resources_filter_free(v1alpha2_named_resources_filter_t *v1alpha2_named_resources_filter) {
    if(NULL == v1alpha2_named_resources_filter){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha2_named_resources_filter->selector) {
        free(v1alpha2_named_resources_filter->selector);
        v1alpha2_named_resources_filter->selector = NULL;
    }
    free(v1alpha2_named_resources_filter);
}

cJSON *v1alpha2_named_resources_filter_convertToJSON(v1alpha2_named_resources_filter_t *v1alpha2_named_resources_filter) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha2_named_resources_filter->selector
    if (!v1alpha2_named_resources_filter->selector) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "selector", v1alpha2_named_resources_filter->selector) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1alpha2_named_resources_filter_t *v1alpha2_named_resources_filter_parseFromJSON(cJSON *v1alpha2_named_resources_filterJSON){

    v1alpha2_named_resources_filter_t *v1alpha2_named_resources_filter_local_var = NULL;

    // v1alpha2_named_resources_filter->selector
    cJSON *selector = cJSON_GetObjectItemCaseSensitive(v1alpha2_named_resources_filterJSON, "selector");
    if (!selector) {
        goto end;
    }

    
    if(!cJSON_IsString(selector))
    {
    goto end; //String
    }


    v1alpha2_named_resources_filter_local_var = v1alpha2_named_resources_filter_create (
        strdup(selector->valuestring)
        );

    return v1alpha2_named_resources_filter_local_var;
end:
    return NULL;

}
