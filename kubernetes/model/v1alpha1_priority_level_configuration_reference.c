#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha1_priority_level_configuration_reference.h"



v1alpha1_priority_level_configuration_reference_t *v1alpha1_priority_level_configuration_reference_create(
    char *name
    ) {
    v1alpha1_priority_level_configuration_reference_t *v1alpha1_priority_level_configuration_reference_local_var = malloc(sizeof(v1alpha1_priority_level_configuration_reference_t));
    if (!v1alpha1_priority_level_configuration_reference_local_var) {
        return NULL;
    }
    v1alpha1_priority_level_configuration_reference_local_var->name = name;

    return v1alpha1_priority_level_configuration_reference_local_var;
}


void v1alpha1_priority_level_configuration_reference_free(v1alpha1_priority_level_configuration_reference_t *v1alpha1_priority_level_configuration_reference) {
    if(NULL == v1alpha1_priority_level_configuration_reference){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha1_priority_level_configuration_reference->name) {
        free(v1alpha1_priority_level_configuration_reference->name);
        v1alpha1_priority_level_configuration_reference->name = NULL;
    }
    free(v1alpha1_priority_level_configuration_reference);
}

cJSON *v1alpha1_priority_level_configuration_reference_convertToJSON(v1alpha1_priority_level_configuration_reference_t *v1alpha1_priority_level_configuration_reference) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha1_priority_level_configuration_reference->name
    if (!v1alpha1_priority_level_configuration_reference->name) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "name", v1alpha1_priority_level_configuration_reference->name) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1alpha1_priority_level_configuration_reference_t *v1alpha1_priority_level_configuration_reference_parseFromJSON(cJSON *v1alpha1_priority_level_configuration_referenceJSON){

    v1alpha1_priority_level_configuration_reference_t *v1alpha1_priority_level_configuration_reference_local_var = NULL;

    // v1alpha1_priority_level_configuration_reference->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1alpha1_priority_level_configuration_referenceJSON, "name");
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }


    v1alpha1_priority_level_configuration_reference_local_var = v1alpha1_priority_level_configuration_reference_create (
        strdup(name->valuestring)
        );

    return v1alpha1_priority_level_configuration_reference_local_var;
end:
    return NULL;

}
