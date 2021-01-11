#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha1_priority_level_configuration_spec.h"



v1alpha1_priority_level_configuration_spec_t *v1alpha1_priority_level_configuration_spec_create(
    v1alpha1_limited_priority_level_configuration_t *limited,
    char *type
    ) {
    v1alpha1_priority_level_configuration_spec_t *v1alpha1_priority_level_configuration_spec_local_var = malloc(sizeof(v1alpha1_priority_level_configuration_spec_t));
    if (!v1alpha1_priority_level_configuration_spec_local_var) {
        return NULL;
    }
    v1alpha1_priority_level_configuration_spec_local_var->limited = limited;
    v1alpha1_priority_level_configuration_spec_local_var->type = type;

    return v1alpha1_priority_level_configuration_spec_local_var;
}


void v1alpha1_priority_level_configuration_spec_free(v1alpha1_priority_level_configuration_spec_t *v1alpha1_priority_level_configuration_spec) {
    if(NULL == v1alpha1_priority_level_configuration_spec){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha1_priority_level_configuration_spec->limited) {
        v1alpha1_limited_priority_level_configuration_free(v1alpha1_priority_level_configuration_spec->limited);
        v1alpha1_priority_level_configuration_spec->limited = NULL;
    }
    if (v1alpha1_priority_level_configuration_spec->type) {
        free(v1alpha1_priority_level_configuration_spec->type);
        v1alpha1_priority_level_configuration_spec->type = NULL;
    }
    free(v1alpha1_priority_level_configuration_spec);
}

cJSON *v1alpha1_priority_level_configuration_spec_convertToJSON(v1alpha1_priority_level_configuration_spec_t *v1alpha1_priority_level_configuration_spec) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha1_priority_level_configuration_spec->limited
    if(v1alpha1_priority_level_configuration_spec->limited) { 
    cJSON *limited_local_JSON = v1alpha1_limited_priority_level_configuration_convertToJSON(v1alpha1_priority_level_configuration_spec->limited);
    if(limited_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "limited", limited_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1alpha1_priority_level_configuration_spec->type
    if (!v1alpha1_priority_level_configuration_spec->type) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "type", v1alpha1_priority_level_configuration_spec->type) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1alpha1_priority_level_configuration_spec_t *v1alpha1_priority_level_configuration_spec_parseFromJSON(cJSON *v1alpha1_priority_level_configuration_specJSON){

    v1alpha1_priority_level_configuration_spec_t *v1alpha1_priority_level_configuration_spec_local_var = NULL;

    // v1alpha1_priority_level_configuration_spec->limited
    cJSON *limited = cJSON_GetObjectItemCaseSensitive(v1alpha1_priority_level_configuration_specJSON, "limited");
    v1alpha1_limited_priority_level_configuration_t *limited_local_nonprim = NULL;
    if (limited) { 
    limited_local_nonprim = v1alpha1_limited_priority_level_configuration_parseFromJSON(limited); //nonprimitive
    }

    // v1alpha1_priority_level_configuration_spec->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(v1alpha1_priority_level_configuration_specJSON, "type");
    if (!type) {
        goto end;
    }

    
    if(!cJSON_IsString(type))
    {
    goto end; //String
    }


    v1alpha1_priority_level_configuration_spec_local_var = v1alpha1_priority_level_configuration_spec_create (
        limited ? limited_local_nonprim : NULL,
        strdup(type->valuestring)
        );

    return v1alpha1_priority_level_configuration_spec_local_var;
end:
    if (limited_local_nonprim) {
        v1alpha1_limited_priority_level_configuration_free(limited_local_nonprim);
        limited_local_nonprim = NULL;
    }
    return NULL;

}
