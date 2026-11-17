#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_limited_priority_level_configuration.h"



static v1_limited_priority_level_configuration_t *v1_limited_priority_level_configuration_create_internal(
    int *borrowing_limit_percent,
    int *lendable_percent,
    v1_limit_response_t *limit_response,
    int *nominal_concurrency_shares
    ) {
    v1_limited_priority_level_configuration_t *v1_limited_priority_level_configuration_local_var = malloc(sizeof(v1_limited_priority_level_configuration_t));
    if (!v1_limited_priority_level_configuration_local_var) {
        return NULL;
    }
    memset(v1_limited_priority_level_configuration_local_var, 0, sizeof(v1_limited_priority_level_configuration_t));
    v1_limited_priority_level_configuration_local_var->_library_owned = 1;
    v1_limited_priority_level_configuration_local_var->borrowing_limit_percent = borrowing_limit_percent;
    v1_limited_priority_level_configuration_local_var->lendable_percent = lendable_percent;
    v1_limited_priority_level_configuration_local_var->limit_response = limit_response;
    v1_limited_priority_level_configuration_local_var->nominal_concurrency_shares = nominal_concurrency_shares;
    return v1_limited_priority_level_configuration_local_var;
}

__attribute__((deprecated)) v1_limited_priority_level_configuration_t *v1_limited_priority_level_configuration_create(
    int *borrowing_limit_percent,
    int *lendable_percent,
    v1_limit_response_t *limit_response,
    int *nominal_concurrency_shares
    ) {
    int *borrowing_limit_percent_copy = NULL;
    if (borrowing_limit_percent) {
        borrowing_limit_percent_copy = malloc(sizeof(int));
        if (borrowing_limit_percent_copy) *borrowing_limit_percent_copy = *borrowing_limit_percent;
    }
    int *lendable_percent_copy = NULL;
    if (lendable_percent) {
        lendable_percent_copy = malloc(sizeof(int));
        if (lendable_percent_copy) *lendable_percent_copy = *lendable_percent;
    }
    int *nominal_concurrency_shares_copy = NULL;
    if (nominal_concurrency_shares) {
        nominal_concurrency_shares_copy = malloc(sizeof(int));
        if (nominal_concurrency_shares_copy) *nominal_concurrency_shares_copy = *nominal_concurrency_shares;
    }
    v1_limited_priority_level_configuration_t *result = v1_limited_priority_level_configuration_create_internal (
        borrowing_limit_percent_copy,
        lendable_percent_copy,
        limit_response,
        nominal_concurrency_shares_copy
        );
    if (!result) {
        free(borrowing_limit_percent_copy);
        free(lendable_percent_copy);
        free(nominal_concurrency_shares_copy);
    }
    return result;
}

void v1_limited_priority_level_configuration_free(v1_limited_priority_level_configuration_t *v1_limited_priority_level_configuration) {
    if(NULL == v1_limited_priority_level_configuration){
        return ;
    }
    if(v1_limited_priority_level_configuration->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_limited_priority_level_configuration_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_limited_priority_level_configuration->borrowing_limit_percent) {
        free(v1_limited_priority_level_configuration->borrowing_limit_percent);
        v1_limited_priority_level_configuration->borrowing_limit_percent = NULL;
    }
    if (v1_limited_priority_level_configuration->lendable_percent) {
        free(v1_limited_priority_level_configuration->lendable_percent);
        v1_limited_priority_level_configuration->lendable_percent = NULL;
    }
    if (v1_limited_priority_level_configuration->limit_response) {
        v1_limit_response_free(v1_limited_priority_level_configuration->limit_response);
        v1_limited_priority_level_configuration->limit_response = NULL;
    }
    if (v1_limited_priority_level_configuration->nominal_concurrency_shares) {
        free(v1_limited_priority_level_configuration->nominal_concurrency_shares);
        v1_limited_priority_level_configuration->nominal_concurrency_shares = NULL;
    }
    free(v1_limited_priority_level_configuration);
}

cJSON *v1_limited_priority_level_configuration_convertToJSON(v1_limited_priority_level_configuration_t *v1_limited_priority_level_configuration) {
    cJSON *item = cJSON_CreateObject();

    // v1_limited_priority_level_configuration->borrowing_limit_percent
    if(v1_limited_priority_level_configuration->borrowing_limit_percent) {
    if(cJSON_AddNumberToObject(item, "borrowingLimitPercent", *v1_limited_priority_level_configuration->borrowing_limit_percent) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_limited_priority_level_configuration->lendable_percent
    if(v1_limited_priority_level_configuration->lendable_percent) {
    if(cJSON_AddNumberToObject(item, "lendablePercent", *v1_limited_priority_level_configuration->lendable_percent) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_limited_priority_level_configuration->limit_response
    if (!v1_limited_priority_level_configuration->limit_response) {
        goto fail;
    }
    cJSON *limit_response_local_JSON = v1_limit_response_convertToJSON(v1_limited_priority_level_configuration->limit_response);
    if(limit_response_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "limitResponse", limit_response_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // v1_limited_priority_level_configuration->nominal_concurrency_shares
    if(v1_limited_priority_level_configuration->nominal_concurrency_shares) {
    if(cJSON_AddNumberToObject(item, "nominalConcurrencyShares", *v1_limited_priority_level_configuration->nominal_concurrency_shares) == NULL) {
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

v1_limited_priority_level_configuration_t *v1_limited_priority_level_configuration_parseFromJSON(cJSON *v1_limited_priority_level_configurationJSON){

    v1_limited_priority_level_configuration_t *v1_limited_priority_level_configuration_local_var = NULL;

    // define the local variable for v1_limited_priority_level_configuration->borrowing_limit_percent
    int *borrowing_limit_percent_local_var = NULL;

    // define the local variable for v1_limited_priority_level_configuration->lendable_percent
    int *lendable_percent_local_var = NULL;

    // define the local variable for v1_limited_priority_level_configuration->limit_response
    v1_limit_response_t *limit_response_local_nonprim = NULL;

    // define the local variable for v1_limited_priority_level_configuration->nominal_concurrency_shares
    int *nominal_concurrency_shares_local_var = NULL;

    // v1_limited_priority_level_configuration->borrowing_limit_percent
    cJSON *borrowing_limit_percent = cJSON_GetObjectItemCaseSensitive(v1_limited_priority_level_configurationJSON, "borrowingLimitPercent");
    if (cJSON_IsNull(borrowing_limit_percent)) {
        borrowing_limit_percent = NULL;
    }
    if (borrowing_limit_percent) { 
    if(!cJSON_IsNumber(borrowing_limit_percent))
    {
    goto end; //Numeric
    }
    borrowing_limit_percent_local_var = malloc(sizeof(int));
    if(!borrowing_limit_percent_local_var)
    {
        goto end;
    }
    *borrowing_limit_percent_local_var = borrowing_limit_percent->valuedouble;
    }

    // v1_limited_priority_level_configuration->lendable_percent
    cJSON *lendable_percent = cJSON_GetObjectItemCaseSensitive(v1_limited_priority_level_configurationJSON, "lendablePercent");
    if (cJSON_IsNull(lendable_percent)) {
        lendable_percent = NULL;
    }
    if (lendable_percent) { 
    if(!cJSON_IsNumber(lendable_percent))
    {
    goto end; //Numeric
    }
    lendable_percent_local_var = malloc(sizeof(int));
    if(!lendable_percent_local_var)
    {
        goto end;
    }
    *lendable_percent_local_var = lendable_percent->valuedouble;
    }

    // v1_limited_priority_level_configuration->limit_response
    cJSON *limit_response = cJSON_GetObjectItemCaseSensitive(v1_limited_priority_level_configurationJSON, "limitResponse");
    if (cJSON_IsNull(limit_response)) {
        limit_response = NULL;
    }
    if (!limit_response) {
        goto end;
    }

    
    limit_response_local_nonprim = v1_limit_response_parseFromJSON(limit_response); //nonprimitive

    // v1_limited_priority_level_configuration->nominal_concurrency_shares
    cJSON *nominal_concurrency_shares = cJSON_GetObjectItemCaseSensitive(v1_limited_priority_level_configurationJSON, "nominalConcurrencyShares");
    if (cJSON_IsNull(nominal_concurrency_shares)) {
        nominal_concurrency_shares = NULL;
    }
    if (nominal_concurrency_shares) { 
    if(!cJSON_IsNumber(nominal_concurrency_shares))
    {
    goto end; //Numeric
    }
    nominal_concurrency_shares_local_var = malloc(sizeof(int));
    if(!nominal_concurrency_shares_local_var)
    {
        goto end;
    }
    *nominal_concurrency_shares_local_var = nominal_concurrency_shares->valuedouble;
    }



    v1_limited_priority_level_configuration_local_var = v1_limited_priority_level_configuration_create_internal (
        borrowing_limit_percent_local_var,
        lendable_percent_local_var,
        limit_response_local_nonprim,
        nominal_concurrency_shares_local_var
        );

    if (!v1_limited_priority_level_configuration_local_var) {
        goto end;
    }

    return v1_limited_priority_level_configuration_local_var;
end:
    if (borrowing_limit_percent_local_var) {
        free(borrowing_limit_percent_local_var);
        borrowing_limit_percent_local_var = NULL;
    }
    if (lendable_percent_local_var) {
        free(lendable_percent_local_var);
        lendable_percent_local_var = NULL;
    }
    if (limit_response_local_nonprim) {
        v1_limit_response_free(limit_response_local_nonprim);
        limit_response_local_nonprim = NULL;
    }
    if (nominal_concurrency_shares_local_var) {
        free(nominal_concurrency_shares_local_var);
        nominal_concurrency_shares_local_var = NULL;
    }
    return NULL;

}
