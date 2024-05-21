#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha2_named_resources_allocation_result.h"



v1alpha2_named_resources_allocation_result_t *v1alpha2_named_resources_allocation_result_create(
    char *name
    ) {
    v1alpha2_named_resources_allocation_result_t *v1alpha2_named_resources_allocation_result_local_var = malloc(sizeof(v1alpha2_named_resources_allocation_result_t));
    if (!v1alpha2_named_resources_allocation_result_local_var) {
        return NULL;
    }
    v1alpha2_named_resources_allocation_result_local_var->name = name;

    return v1alpha2_named_resources_allocation_result_local_var;
}


void v1alpha2_named_resources_allocation_result_free(v1alpha2_named_resources_allocation_result_t *v1alpha2_named_resources_allocation_result) {
    if(NULL == v1alpha2_named_resources_allocation_result){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha2_named_resources_allocation_result->name) {
        free(v1alpha2_named_resources_allocation_result->name);
        v1alpha2_named_resources_allocation_result->name = NULL;
    }
    free(v1alpha2_named_resources_allocation_result);
}

cJSON *v1alpha2_named_resources_allocation_result_convertToJSON(v1alpha2_named_resources_allocation_result_t *v1alpha2_named_resources_allocation_result) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha2_named_resources_allocation_result->name
    if (!v1alpha2_named_resources_allocation_result->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", v1alpha2_named_resources_allocation_result->name) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1alpha2_named_resources_allocation_result_t *v1alpha2_named_resources_allocation_result_parseFromJSON(cJSON *v1alpha2_named_resources_allocation_resultJSON){

    v1alpha2_named_resources_allocation_result_t *v1alpha2_named_resources_allocation_result_local_var = NULL;

    // v1alpha2_named_resources_allocation_result->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1alpha2_named_resources_allocation_resultJSON, "name");
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }


    v1alpha2_named_resources_allocation_result_local_var = v1alpha2_named_resources_allocation_result_create (
        strdup(name->valuestring)
        );

    return v1alpha2_named_resources_allocation_result_local_var;
end:
    return NULL;

}
