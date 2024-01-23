#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_priority_level_configuration_spec.h"



v1_priority_level_configuration_spec_t *v1_priority_level_configuration_spec_create(
    v1_exempt_priority_level_configuration_t *exempt,
    v1_limited_priority_level_configuration_t *limited,
    char *type
    ) {
    v1_priority_level_configuration_spec_t *v1_priority_level_configuration_spec_local_var = malloc(sizeof(v1_priority_level_configuration_spec_t));
    if (!v1_priority_level_configuration_spec_local_var) {
        return NULL;
    }
    v1_priority_level_configuration_spec_local_var->exempt = exempt;
    v1_priority_level_configuration_spec_local_var->limited = limited;
    v1_priority_level_configuration_spec_local_var->type = type;

    return v1_priority_level_configuration_spec_local_var;
}


void v1_priority_level_configuration_spec_free(v1_priority_level_configuration_spec_t *v1_priority_level_configuration_spec) {
    if(NULL == v1_priority_level_configuration_spec){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_priority_level_configuration_spec->exempt) {
        v1_exempt_priority_level_configuration_free(v1_priority_level_configuration_spec->exempt);
        v1_priority_level_configuration_spec->exempt = NULL;
    }
    if (v1_priority_level_configuration_spec->limited) {
        v1_limited_priority_level_configuration_free(v1_priority_level_configuration_spec->limited);
        v1_priority_level_configuration_spec->limited = NULL;
    }
    if (v1_priority_level_configuration_spec->type) {
        free(v1_priority_level_configuration_spec->type);
        v1_priority_level_configuration_spec->type = NULL;
    }
    free(v1_priority_level_configuration_spec);
}

cJSON *v1_priority_level_configuration_spec_convertToJSON(v1_priority_level_configuration_spec_t *v1_priority_level_configuration_spec) {
    cJSON *item = cJSON_CreateObject();

    // v1_priority_level_configuration_spec->exempt
    if(v1_priority_level_configuration_spec->exempt) {
    cJSON *exempt_local_JSON = v1_exempt_priority_level_configuration_convertToJSON(v1_priority_level_configuration_spec->exempt);
    if(exempt_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "exempt", exempt_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_priority_level_configuration_spec->limited
    if(v1_priority_level_configuration_spec->limited) {
    cJSON *limited_local_JSON = v1_limited_priority_level_configuration_convertToJSON(v1_priority_level_configuration_spec->limited);
    if(limited_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "limited", limited_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_priority_level_configuration_spec->type
    if (!v1_priority_level_configuration_spec->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", v1_priority_level_configuration_spec->type) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_priority_level_configuration_spec_t *v1_priority_level_configuration_spec_parseFromJSON(cJSON *v1_priority_level_configuration_specJSON){

    v1_priority_level_configuration_spec_t *v1_priority_level_configuration_spec_local_var = NULL;

    // define the local variable for v1_priority_level_configuration_spec->exempt
    v1_exempt_priority_level_configuration_t *exempt_local_nonprim = NULL;

    // define the local variable for v1_priority_level_configuration_spec->limited
    v1_limited_priority_level_configuration_t *limited_local_nonprim = NULL;

    // v1_priority_level_configuration_spec->exempt
    cJSON *exempt = cJSON_GetObjectItemCaseSensitive(v1_priority_level_configuration_specJSON, "exempt");
    if (exempt) { 
    exempt_local_nonprim = v1_exempt_priority_level_configuration_parseFromJSON(exempt); //nonprimitive
    }

    // v1_priority_level_configuration_spec->limited
    cJSON *limited = cJSON_GetObjectItemCaseSensitive(v1_priority_level_configuration_specJSON, "limited");
    if (limited) { 
    limited_local_nonprim = v1_limited_priority_level_configuration_parseFromJSON(limited); //nonprimitive
    }

    // v1_priority_level_configuration_spec->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(v1_priority_level_configuration_specJSON, "type");
    if (!type) {
        goto end;
    }

    
    if(!cJSON_IsString(type))
    {
    goto end; //String
    }


    v1_priority_level_configuration_spec_local_var = v1_priority_level_configuration_spec_create (
        exempt ? exempt_local_nonprim : NULL,
        limited ? limited_local_nonprim : NULL,
        strdup(type->valuestring)
        );

    return v1_priority_level_configuration_spec_local_var;
end:
    if (exempt_local_nonprim) {
        v1_exempt_priority_level_configuration_free(exempt_local_nonprim);
        exempt_local_nonprim = NULL;
    }
    if (limited_local_nonprim) {
        v1_limited_priority_level_configuration_free(limited_local_nonprim);
        limited_local_nonprim = NULL;
    }
    return NULL;

}
