#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_http_header.h"



v1_http_header_t *v1_http_header_create(
    char *name,
    char *value
    ) {
    v1_http_header_t *v1_http_header_local_var = malloc(sizeof(v1_http_header_t));
    if (!v1_http_header_local_var) {
        return NULL;
    }
    v1_http_header_local_var->name = name;
    v1_http_header_local_var->value = value;

    return v1_http_header_local_var;
}


void v1_http_header_free(v1_http_header_t *v1_http_header) {
    if(NULL == v1_http_header){
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

    // v1_http_header->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1_http_headerJSON, "name");
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // v1_http_header->value
    cJSON *value = cJSON_GetObjectItemCaseSensitive(v1_http_headerJSON, "value");
    if (!value) {
        goto end;
    }

    
    if(!cJSON_IsString(value))
    {
    goto end; //String
    }


    v1_http_header_local_var = v1_http_header_create (
        strdup(name->valuestring),
        strdup(value->valuestring)
        );

    return v1_http_header_local_var;
end:
    return NULL;

}
