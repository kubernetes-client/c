#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_object_field_selector.h"



static v1_object_field_selector_t *v1_object_field_selector_create_internal(
    char *api_version,
    char *field_path
    ) {
    v1_object_field_selector_t *v1_object_field_selector_local_var = malloc(sizeof(v1_object_field_selector_t));
    if (!v1_object_field_selector_local_var) {
        return NULL;
    }
    v1_object_field_selector_local_var->api_version = api_version;
    v1_object_field_selector_local_var->field_path = field_path;

    v1_object_field_selector_local_var->_library_owned = 1;
    return v1_object_field_selector_local_var;
}

__attribute__((deprecated)) v1_object_field_selector_t *v1_object_field_selector_create(
    char *api_version,
    char *field_path
    ) {
    return v1_object_field_selector_create_internal (
        api_version,
        field_path
        );
}

void v1_object_field_selector_free(v1_object_field_selector_t *v1_object_field_selector) {
    if(NULL == v1_object_field_selector){
        return ;
    }
    if(v1_object_field_selector->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_object_field_selector_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_object_field_selector->api_version) {
        free(v1_object_field_selector->api_version);
        v1_object_field_selector->api_version = NULL;
    }
    if (v1_object_field_selector->field_path) {
        free(v1_object_field_selector->field_path);
        v1_object_field_selector->field_path = NULL;
    }
    free(v1_object_field_selector);
}

cJSON *v1_object_field_selector_convertToJSON(v1_object_field_selector_t *v1_object_field_selector) {
    cJSON *item = cJSON_CreateObject();

    // v1_object_field_selector->api_version
    if(v1_object_field_selector->api_version) {
    if(cJSON_AddStringToObject(item, "apiVersion", v1_object_field_selector->api_version) == NULL) {
    goto fail; //String
    }
    }


    // v1_object_field_selector->field_path
    if (!v1_object_field_selector->field_path) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "fieldPath", v1_object_field_selector->field_path) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_object_field_selector_t *v1_object_field_selector_parseFromJSON(cJSON *v1_object_field_selectorJSON){

    v1_object_field_selector_t *v1_object_field_selector_local_var = NULL;

    // v1_object_field_selector->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1_object_field_selectorJSON, "apiVersion");
    if (cJSON_IsNull(api_version)) {
        api_version = NULL;
    }
    if (api_version) { 
    if(!cJSON_IsString(api_version) && !cJSON_IsNull(api_version))
    {
    goto end; //String
    }
    }

    // v1_object_field_selector->field_path
    cJSON *field_path = cJSON_GetObjectItemCaseSensitive(v1_object_field_selectorJSON, "fieldPath");
    if (cJSON_IsNull(field_path)) {
        field_path = NULL;
    }
    if (!field_path) {
        goto end;
    }

    
    if(!cJSON_IsString(field_path))
    {
    goto end; //String
    }


    v1_object_field_selector_local_var = v1_object_field_selector_create_internal (
        api_version && !cJSON_IsNull(api_version) ? strdup(api_version->valuestring) : NULL,
        strdup(field_path->valuestring)
        );

    return v1_object_field_selector_local_var;
end:
    return NULL;

}
