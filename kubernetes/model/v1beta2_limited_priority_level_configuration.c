#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta2_limited_priority_level_configuration.h"



v1beta2_limited_priority_level_configuration_t *v1beta2_limited_priority_level_configuration_create(
    int assured_concurrency_shares,
    v1beta2_limit_response_t *limit_response
    ) {
    v1beta2_limited_priority_level_configuration_t *v1beta2_limited_priority_level_configuration_local_var = malloc(sizeof(v1beta2_limited_priority_level_configuration_t));
    if (!v1beta2_limited_priority_level_configuration_local_var) {
        return NULL;
    }
    v1beta2_limited_priority_level_configuration_local_var->assured_concurrency_shares = assured_concurrency_shares;
    v1beta2_limited_priority_level_configuration_local_var->limit_response = limit_response;

    return v1beta2_limited_priority_level_configuration_local_var;
}


void v1beta2_limited_priority_level_configuration_free(v1beta2_limited_priority_level_configuration_t *v1beta2_limited_priority_level_configuration) {
    if(NULL == v1beta2_limited_priority_level_configuration){
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta2_limited_priority_level_configuration->limit_response) {
        v1beta2_limit_response_free(v1beta2_limited_priority_level_configuration->limit_response);
        v1beta2_limited_priority_level_configuration->limit_response = NULL;
    }
    free(v1beta2_limited_priority_level_configuration);
}

cJSON *v1beta2_limited_priority_level_configuration_convertToJSON(v1beta2_limited_priority_level_configuration_t *v1beta2_limited_priority_level_configuration) {
    cJSON *item = cJSON_CreateObject();

    // v1beta2_limited_priority_level_configuration->assured_concurrency_shares
    if(v1beta2_limited_priority_level_configuration->assured_concurrency_shares) { 
    if(cJSON_AddNumberToObject(item, "assuredConcurrencyShares", v1beta2_limited_priority_level_configuration->assured_concurrency_shares) == NULL) {
    goto fail; //Numeric
    }
     } 


    // v1beta2_limited_priority_level_configuration->limit_response
    if(v1beta2_limited_priority_level_configuration->limit_response) { 
    cJSON *limit_response_local_JSON = v1beta2_limit_response_convertToJSON(v1beta2_limited_priority_level_configuration->limit_response);
    if(limit_response_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "limitResponse", limit_response_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1beta2_limited_priority_level_configuration_t *v1beta2_limited_priority_level_configuration_parseFromJSON(cJSON *v1beta2_limited_priority_level_configurationJSON){

    v1beta2_limited_priority_level_configuration_t *v1beta2_limited_priority_level_configuration_local_var = NULL;

    // define the local variable for v1beta2_limited_priority_level_configuration->limit_response
    v1beta2_limit_response_t *limit_response_local_nonprim = NULL;

    // v1beta2_limited_priority_level_configuration->assured_concurrency_shares
    cJSON *assured_concurrency_shares = cJSON_GetObjectItemCaseSensitive(v1beta2_limited_priority_level_configurationJSON, "assuredConcurrencyShares");
    if (assured_concurrency_shares) { 
    if(!cJSON_IsNumber(assured_concurrency_shares))
    {
    goto end; //Numeric
    }
    }

    // v1beta2_limited_priority_level_configuration->limit_response
    cJSON *limit_response = cJSON_GetObjectItemCaseSensitive(v1beta2_limited_priority_level_configurationJSON, "limitResponse");
    if (limit_response) { 
    limit_response_local_nonprim = v1beta2_limit_response_parseFromJSON(limit_response); //nonprimitive
    }


    v1beta2_limited_priority_level_configuration_local_var = v1beta2_limited_priority_level_configuration_create (
        assured_concurrency_shares ? assured_concurrency_shares->valuedouble : 0,
        limit_response ? limit_response_local_nonprim : NULL
        );

    return v1beta2_limited_priority_level_configuration_local_var;
end:
    if (limit_response_local_nonprim) {
        v1beta2_limit_response_free(limit_response_local_nonprim);
        limit_response_local_nonprim = NULL;
    }
    return NULL;

}
