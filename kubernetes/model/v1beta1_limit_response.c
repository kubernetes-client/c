#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_limit_response.h"



v1beta1_limit_response_t *v1beta1_limit_response_create(
    v1beta1_queuing_configuration_t *queuing,
    char *type
    ) {
    v1beta1_limit_response_t *v1beta1_limit_response_local_var = malloc(sizeof(v1beta1_limit_response_t));
    if (!v1beta1_limit_response_local_var) {
        return NULL;
    }
    v1beta1_limit_response_local_var->queuing = queuing;
    v1beta1_limit_response_local_var->type = type;

    return v1beta1_limit_response_local_var;
}


void v1beta1_limit_response_free(v1beta1_limit_response_t *v1beta1_limit_response) {
    if(NULL == v1beta1_limit_response){
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta1_limit_response->queuing) {
        v1beta1_queuing_configuration_free(v1beta1_limit_response->queuing);
        v1beta1_limit_response->queuing = NULL;
    }
    if (v1beta1_limit_response->type) {
        free(v1beta1_limit_response->type);
        v1beta1_limit_response->type = NULL;
    }
    free(v1beta1_limit_response);
}

cJSON *v1beta1_limit_response_convertToJSON(v1beta1_limit_response_t *v1beta1_limit_response) {
    cJSON *item = cJSON_CreateObject();

    // v1beta1_limit_response->queuing
    if(v1beta1_limit_response->queuing) { 
    cJSON *queuing_local_JSON = v1beta1_queuing_configuration_convertToJSON(v1beta1_limit_response->queuing);
    if(queuing_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "queuing", queuing_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1beta1_limit_response->type
    if (!v1beta1_limit_response->type) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "type", v1beta1_limit_response->type) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1beta1_limit_response_t *v1beta1_limit_response_parseFromJSON(cJSON *v1beta1_limit_responseJSON){

    v1beta1_limit_response_t *v1beta1_limit_response_local_var = NULL;

    // define the local variable for v1beta1_limit_response->queuing
    v1beta1_queuing_configuration_t *queuing_local_nonprim = NULL;

    // v1beta1_limit_response->queuing
    cJSON *queuing = cJSON_GetObjectItemCaseSensitive(v1beta1_limit_responseJSON, "queuing");
    if (queuing) { 
    queuing_local_nonprim = v1beta1_queuing_configuration_parseFromJSON(queuing); //nonprimitive
    }

    // v1beta1_limit_response->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(v1beta1_limit_responseJSON, "type");
    if (!type) {
        goto end;
    }

    
    if(!cJSON_IsString(type))
    {
    goto end; //String
    }


    v1beta1_limit_response_local_var = v1beta1_limit_response_create (
        queuing ? queuing_local_nonprim : NULL,
        strdup(type->valuestring)
        );

    return v1beta1_limit_response_local_var;
end:
    if (queuing_local_nonprim) {
        v1beta1_queuing_configuration_free(queuing_local_nonprim);
        queuing_local_nonprim = NULL;
    }
    return NULL;

}
