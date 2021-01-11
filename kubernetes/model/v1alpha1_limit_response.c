#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha1_limit_response.h"



v1alpha1_limit_response_t *v1alpha1_limit_response_create(
    v1alpha1_queuing_configuration_t *queuing,
    char *type
    ) {
    v1alpha1_limit_response_t *v1alpha1_limit_response_local_var = malloc(sizeof(v1alpha1_limit_response_t));
    if (!v1alpha1_limit_response_local_var) {
        return NULL;
    }
    v1alpha1_limit_response_local_var->queuing = queuing;
    v1alpha1_limit_response_local_var->type = type;

    return v1alpha1_limit_response_local_var;
}


void v1alpha1_limit_response_free(v1alpha1_limit_response_t *v1alpha1_limit_response) {
    if(NULL == v1alpha1_limit_response){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha1_limit_response->queuing) {
        v1alpha1_queuing_configuration_free(v1alpha1_limit_response->queuing);
        v1alpha1_limit_response->queuing = NULL;
    }
    if (v1alpha1_limit_response->type) {
        free(v1alpha1_limit_response->type);
        v1alpha1_limit_response->type = NULL;
    }
    free(v1alpha1_limit_response);
}

cJSON *v1alpha1_limit_response_convertToJSON(v1alpha1_limit_response_t *v1alpha1_limit_response) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha1_limit_response->queuing
    if(v1alpha1_limit_response->queuing) { 
    cJSON *queuing_local_JSON = v1alpha1_queuing_configuration_convertToJSON(v1alpha1_limit_response->queuing);
    if(queuing_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "queuing", queuing_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1alpha1_limit_response->type
    if (!v1alpha1_limit_response->type) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "type", v1alpha1_limit_response->type) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1alpha1_limit_response_t *v1alpha1_limit_response_parseFromJSON(cJSON *v1alpha1_limit_responseJSON){

    v1alpha1_limit_response_t *v1alpha1_limit_response_local_var = NULL;

    // v1alpha1_limit_response->queuing
    cJSON *queuing = cJSON_GetObjectItemCaseSensitive(v1alpha1_limit_responseJSON, "queuing");
    v1alpha1_queuing_configuration_t *queuing_local_nonprim = NULL;
    if (queuing) { 
    queuing_local_nonprim = v1alpha1_queuing_configuration_parseFromJSON(queuing); //nonprimitive
    }

    // v1alpha1_limit_response->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(v1alpha1_limit_responseJSON, "type");
    if (!type) {
        goto end;
    }

    
    if(!cJSON_IsString(type))
    {
    goto end; //String
    }


    v1alpha1_limit_response_local_var = v1alpha1_limit_response_create (
        queuing ? queuing_local_nonprim : NULL,
        strdup(type->valuestring)
        );

    return v1alpha1_limit_response_local_var;
end:
    if (queuing_local_nonprim) {
        v1alpha1_queuing_configuration_free(queuing_local_nonprim);
        queuing_local_nonprim = NULL;
    }
    return NULL;

}
