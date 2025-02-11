#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_limit_response.h"



static v1_limit_response_t *v1_limit_response_create_internal(
    v1_queuing_configuration_t *queuing,
    char *type
    ) {
    v1_limit_response_t *v1_limit_response_local_var = malloc(sizeof(v1_limit_response_t));
    if (!v1_limit_response_local_var) {
        return NULL;
    }
    v1_limit_response_local_var->queuing = queuing;
    v1_limit_response_local_var->type = type;

    v1_limit_response_local_var->_library_owned = 1;
    return v1_limit_response_local_var;
}

__attribute__((deprecated)) v1_limit_response_t *v1_limit_response_create(
    v1_queuing_configuration_t *queuing,
    char *type
    ) {
    return v1_limit_response_create_internal (
        queuing,
        type
        );
}

void v1_limit_response_free(v1_limit_response_t *v1_limit_response) {
    if(NULL == v1_limit_response){
        return ;
    }
    if(v1_limit_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_limit_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_limit_response->queuing) {
        v1_queuing_configuration_free(v1_limit_response->queuing);
        v1_limit_response->queuing = NULL;
    }
    if (v1_limit_response->type) {
        free(v1_limit_response->type);
        v1_limit_response->type = NULL;
    }
    free(v1_limit_response);
}

cJSON *v1_limit_response_convertToJSON(v1_limit_response_t *v1_limit_response) {
    cJSON *item = cJSON_CreateObject();

    // v1_limit_response->queuing
    if(v1_limit_response->queuing) {
    cJSON *queuing_local_JSON = v1_queuing_configuration_convertToJSON(v1_limit_response->queuing);
    if(queuing_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "queuing", queuing_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_limit_response->type
    if (!v1_limit_response->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", v1_limit_response->type) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_limit_response_t *v1_limit_response_parseFromJSON(cJSON *v1_limit_responseJSON){

    v1_limit_response_t *v1_limit_response_local_var = NULL;

    // define the local variable for v1_limit_response->queuing
    v1_queuing_configuration_t *queuing_local_nonprim = NULL;

    // v1_limit_response->queuing
    cJSON *queuing = cJSON_GetObjectItemCaseSensitive(v1_limit_responseJSON, "queuing");
    if (cJSON_IsNull(queuing)) {
        queuing = NULL;
    }
    if (queuing) { 
    queuing_local_nonprim = v1_queuing_configuration_parseFromJSON(queuing); //nonprimitive
    }

    // v1_limit_response->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(v1_limit_responseJSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    if (!type) {
        goto end;
    }

    
    if(!cJSON_IsString(type))
    {
    goto end; //String
    }


    v1_limit_response_local_var = v1_limit_response_create_internal (
        queuing ? queuing_local_nonprim : NULL,
        strdup(type->valuestring)
        );

    return v1_limit_response_local_var;
end:
    if (queuing_local_nonprim) {
        v1_queuing_configuration_free(queuing_local_nonprim);
        queuing_local_nonprim = NULL;
    }
    return NULL;

}
