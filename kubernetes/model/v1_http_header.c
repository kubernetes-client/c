#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_http_header.h"



static v1_http_header_t *v1_http_header_create_internal(
    char *name,
    char *value
    ) {
    v1_http_header_t *v1_http_header_local_var = malloc(sizeof(v1_http_header_t));
    if (!v1_http_header_local_var) {
        return NULL;
    }
    memset(v1_http_header_local_var, 0, sizeof(v1_http_header_t));
    v1_http_header_local_var->_library_owned = 1;
    v1_http_header_local_var->name = name;
    v1_http_header_local_var->value = value;
    return v1_http_header_local_var;
}

__attribute__((deprecated)) v1_http_header_t *v1_http_header_create(
    char *name,
    char *value
    ) {
    v1_http_header_t *result = v1_http_header_create_internal (
        name,
        value
        );
    if (!result) {
    }
    return result;
}

void v1_http_header_free(v1_http_header_t *v1_http_header) {
    if(NULL == v1_http_header){
        return ;
    }
    if(v1_http_header->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_http_header_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_http_header->name) {
        free(v1_http_header->name);
        v1_http_header->name = NULL;
    }
    if (v1_http_header->value) {
        free(v1_http_header->value);
        v1_http_header->value = NULL;
    }
    free(v1_http_header);
}

cJSON *v1_http_header_convertToJSON(v1_http_header_t *v1_http_header) {
    cJSON *item = cJSON_CreateObject();

    // v1_http_header->name
    if (!v1_http_header->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", v1_http_header->name) == NULL) {
    goto fail; //String
    }


    // v1_http_header->value
    if (!v1_http_header->value) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "value", v1_http_header->value) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_http_header_t *v1_http_header_parseFromJSON(cJSON *v1_http_headerJSON){

    v1_http_header_t *v1_http_header_local_var = NULL;

    char *name_local_str = NULL;

    char *value_local_str = NULL;

    // v1_http_header->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1_http_headerJSON, "name");
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

    // v1_http_header->value
    cJSON *value = cJSON_GetObjectItemCaseSensitive(v1_http_headerJSON, "value");
    if (cJSON_IsNull(value)) {
        value = NULL;
    }
    if (!value) {
        goto end;
    }

    
    if(!cJSON_IsString(value))
    {
    goto end; //String
    }


    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);
    if (value && !cJSON_IsNull(value)) value_local_str = strdup(value->valuestring);

    v1_http_header_local_var = v1_http_header_create_internal (
        name_local_str,
        value_local_str
        );

    if (!v1_http_header_local_var) {
        goto end;
    }

    return v1_http_header_local_var;
end:
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    if (value_local_str) {
        free(value_local_str);
        value_local_str = NULL;
    }
    return NULL;

}
