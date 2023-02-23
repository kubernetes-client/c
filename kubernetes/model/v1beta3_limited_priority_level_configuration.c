#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta3_limited_priority_level_configuration.h"



v1beta3_limited_priority_level_configuration_t *v1beta3_limited_priority_level_configuration_create(
    int borrowing_limit_percent,
    int lendable_percent,
    v1beta3_limit_response_t *limit_response,
    int nominal_concurrency_shares
    ) {
    v1beta3_limited_priority_level_configuration_t *v1beta3_limited_priority_level_configuration_local_var = malloc(sizeof(v1beta3_limited_priority_level_configuration_t));
    if (!v1beta3_limited_priority_level_configuration_local_var) {
        return NULL;
    }
    v1beta3_limited_priority_level_configuration_local_var->borrowing_limit_percent = borrowing_limit_percent;
    v1beta3_limited_priority_level_configuration_local_var->lendable_percent = lendable_percent;
    v1beta3_limited_priority_level_configuration_local_var->limit_response = limit_response;
    v1beta3_limited_priority_level_configuration_local_var->nominal_concurrency_shares = nominal_concurrency_shares;

    return v1beta3_limited_priority_level_configuration_local_var;
}


void v1beta3_limited_priority_level_configuration_free(v1beta3_limited_priority_level_configuration_t *v1beta3_limited_priority_level_configuration) {
    if(NULL == v1beta3_limited_priority_level_configuration){
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta3_limited_priority_level_configuration->limit_response) {
        v1beta3_limit_response_free(v1beta3_limited_priority_level_configuration->limit_response);
        v1beta3_limited_priority_level_configuration->limit_response = NULL;
    }
    free(v1beta3_limited_priority_level_configuration);
}

cJSON *v1beta3_limited_priority_level_configuration_convertToJSON(v1beta3_limited_priority_level_configuration_t *v1beta3_limited_priority_level_configuration) {
    cJSON *item = cJSON_CreateObject();

    // v1beta3_limited_priority_level_configuration->borrowing_limit_percent
    if(v1beta3_limited_priority_level_configuration->borrowing_limit_percent) {
    if(cJSON_AddNumberToObject(item, "borrowingLimitPercent", v1beta3_limited_priority_level_configuration->borrowing_limit_percent) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1beta3_limited_priority_level_configuration->lendable_percent
    if(v1beta3_limited_priority_level_configuration->lendable_percent) {
    if(cJSON_AddNumberToObject(item, "lendablePercent", v1beta3_limited_priority_level_configuration->lendable_percent) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1beta3_limited_priority_level_configuration->limit_response
    if(v1beta3_limited_priority_level_configuration->limit_response) {
    cJSON *limit_response_local_JSON = v1beta3_limit_response_convertToJSON(v1beta3_limited_priority_level_configuration->limit_response);
    if(limit_response_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "limitResponse", limit_response_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1beta3_limited_priority_level_configuration->nominal_concurrency_shares
    if(v1beta3_limited_priority_level_configuration->nominal_concurrency_shares) {
    if(cJSON_AddNumberToObject(item, "nominalConcurrencyShares", v1beta3_limited_priority_level_configuration->nominal_concurrency_shares) == NULL) {
    goto fail; //Numeric
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1beta3_limited_priority_level_configuration_t *v1beta3_limited_priority_level_configuration_parseFromJSON(cJSON *v1beta3_limited_priority_level_configurationJSON){

    v1beta3_limited_priority_level_configuration_t *v1beta3_limited_priority_level_configuration_local_var = NULL;

    // define the local variable for v1beta3_limited_priority_level_configuration->limit_response
    v1beta3_limit_response_t *limit_response_local_nonprim = NULL;

    // v1beta3_limited_priority_level_configuration->borrowing_limit_percent
    cJSON *borrowing_limit_percent = cJSON_GetObjectItemCaseSensitive(v1beta3_limited_priority_level_configurationJSON, "borrowingLimitPercent");
    if (borrowing_limit_percent) { 
    if(!cJSON_IsNumber(borrowing_limit_percent))
    {
    goto end; //Numeric
    }
    }

    // v1beta3_limited_priority_level_configuration->lendable_percent
    cJSON *lendable_percent = cJSON_GetObjectItemCaseSensitive(v1beta3_limited_priority_level_configurationJSON, "lendablePercent");
    if (lendable_percent) { 
    if(!cJSON_IsNumber(lendable_percent))
    {
    goto end; //Numeric
    }
    }

    // v1beta3_limited_priority_level_configuration->limit_response
    cJSON *limit_response = cJSON_GetObjectItemCaseSensitive(v1beta3_limited_priority_level_configurationJSON, "limitResponse");
    if (limit_response) { 
    limit_response_local_nonprim = v1beta3_limit_response_parseFromJSON(limit_response); //nonprimitive
    }

    // v1beta3_limited_priority_level_configuration->nominal_concurrency_shares
    cJSON *nominal_concurrency_shares = cJSON_GetObjectItemCaseSensitive(v1beta3_limited_priority_level_configurationJSON, "nominalConcurrencyShares");
    if (nominal_concurrency_shares) { 
    if(!cJSON_IsNumber(nominal_concurrency_shares))
    {
    goto end; //Numeric
    }
    }


    v1beta3_limited_priority_level_configuration_local_var = v1beta3_limited_priority_level_configuration_create (
        borrowing_limit_percent ? borrowing_limit_percent->valuedouble : 0,
        lendable_percent ? lendable_percent->valuedouble : 0,
        limit_response ? limit_response_local_nonprim : NULL,
        nominal_concurrency_shares ? nominal_concurrency_shares->valuedouble : 0
        );

    return v1beta3_limited_priority_level_configuration_local_var;
end:
    if (limit_response_local_nonprim) {
        v1beta3_limit_response_free(limit_response_local_nonprim);
        limit_response_local_nonprim = NULL;
    }
    return NULL;

}
