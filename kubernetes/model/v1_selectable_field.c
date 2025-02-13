#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_selectable_field.h"



static v1_selectable_field_t *v1_selectable_field_create_internal(
    char *json_path
    ) {
    v1_selectable_field_t *v1_selectable_field_local_var = malloc(sizeof(v1_selectable_field_t));
    if (!v1_selectable_field_local_var) {
        return NULL;
    }
    v1_selectable_field_local_var->json_path = json_path;

    v1_selectable_field_local_var->_library_owned = 1;
    return v1_selectable_field_local_var;
}

__attribute__((deprecated)) v1_selectable_field_t *v1_selectable_field_create(
    char *json_path
    ) {
    return v1_selectable_field_create_internal (
        json_path
        );
}

void v1_selectable_field_free(v1_selectable_field_t *v1_selectable_field) {
    if(NULL == v1_selectable_field){
        return ;
    }
    if(v1_selectable_field->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_selectable_field_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_selectable_field->json_path) {
        free(v1_selectable_field->json_path);
        v1_selectable_field->json_path = NULL;
    }
    free(v1_selectable_field);
}

cJSON *v1_selectable_field_convertToJSON(v1_selectable_field_t *v1_selectable_field) {
    cJSON *item = cJSON_CreateObject();

    // v1_selectable_field->json_path
    if (!v1_selectable_field->json_path) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "jsonPath", v1_selectable_field->json_path) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_selectable_field_t *v1_selectable_field_parseFromJSON(cJSON *v1_selectable_fieldJSON){

    v1_selectable_field_t *v1_selectable_field_local_var = NULL;

    // v1_selectable_field->json_path
    cJSON *json_path = cJSON_GetObjectItemCaseSensitive(v1_selectable_fieldJSON, "jsonPath");
    if (cJSON_IsNull(json_path)) {
        json_path = NULL;
    }
    if (!json_path) {
        goto end;
    }

    
    if(!cJSON_IsString(json_path))
    {
    goto end; //String
    }


    v1_selectable_field_local_var = v1_selectable_field_create_internal (
        strdup(json_path->valuestring)
        );

    return v1_selectable_field_local_var;
end:
    return NULL;

}
