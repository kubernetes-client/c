#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_priority_level_configuration_reference.h"



static v1_priority_level_configuration_reference_t *v1_priority_level_configuration_reference_create_internal(
    char *name
    ) {
    v1_priority_level_configuration_reference_t *v1_priority_level_configuration_reference_local_var = malloc(sizeof(v1_priority_level_configuration_reference_t));
    if (!v1_priority_level_configuration_reference_local_var) {
        return NULL;
    }
    v1_priority_level_configuration_reference_local_var->name = name;

    v1_priority_level_configuration_reference_local_var->_library_owned = 1;
    return v1_priority_level_configuration_reference_local_var;
}

__attribute__((deprecated)) v1_priority_level_configuration_reference_t *v1_priority_level_configuration_reference_create(
    char *name
    ) {
    return v1_priority_level_configuration_reference_create_internal (
        name
        );
}

void v1_priority_level_configuration_reference_free(v1_priority_level_configuration_reference_t *v1_priority_level_configuration_reference) {
    if(NULL == v1_priority_level_configuration_reference){
        return ;
    }
    if(v1_priority_level_configuration_reference->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_priority_level_configuration_reference_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_priority_level_configuration_reference->name) {
        free(v1_priority_level_configuration_reference->name);
        v1_priority_level_configuration_reference->name = NULL;
    }
    free(v1_priority_level_configuration_reference);
}

cJSON *v1_priority_level_configuration_reference_convertToJSON(v1_priority_level_configuration_reference_t *v1_priority_level_configuration_reference) {
    cJSON *item = cJSON_CreateObject();

    // v1_priority_level_configuration_reference->name
    if (!v1_priority_level_configuration_reference->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", v1_priority_level_configuration_reference->name) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_priority_level_configuration_reference_t *v1_priority_level_configuration_reference_parseFromJSON(cJSON *v1_priority_level_configuration_referenceJSON){

    v1_priority_level_configuration_reference_t *v1_priority_level_configuration_reference_local_var = NULL;

    // v1_priority_level_configuration_reference->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1_priority_level_configuration_referenceJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }


    v1_priority_level_configuration_reference_local_var = v1_priority_level_configuration_reference_create_internal (
        strdup(name->valuestring)
        );

    return v1_priority_level_configuration_reference_local_var;
end:
    return NULL;

}
