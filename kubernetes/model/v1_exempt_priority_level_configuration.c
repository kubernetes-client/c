#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_exempt_priority_level_configuration.h"



static v1_exempt_priority_level_configuration_t *v1_exempt_priority_level_configuration_create_internal(
    int lendable_percent,
    int nominal_concurrency_shares
    ) {
    v1_exempt_priority_level_configuration_t *v1_exempt_priority_level_configuration_local_var = malloc(sizeof(v1_exempt_priority_level_configuration_t));
    if (!v1_exempt_priority_level_configuration_local_var) {
        return NULL;
    }
    v1_exempt_priority_level_configuration_local_var->lendable_percent = lendable_percent;
    v1_exempt_priority_level_configuration_local_var->nominal_concurrency_shares = nominal_concurrency_shares;

    v1_exempt_priority_level_configuration_local_var->_library_owned = 1;
    return v1_exempt_priority_level_configuration_local_var;
}

__attribute__((deprecated)) v1_exempt_priority_level_configuration_t *v1_exempt_priority_level_configuration_create(
    int lendable_percent,
    int nominal_concurrency_shares
    ) {
    return v1_exempt_priority_level_configuration_create_internal (
        lendable_percent,
        nominal_concurrency_shares
        );
}

void v1_exempt_priority_level_configuration_free(v1_exempt_priority_level_configuration_t *v1_exempt_priority_level_configuration) {
    if(NULL == v1_exempt_priority_level_configuration){
        return ;
    }
    if(v1_exempt_priority_level_configuration->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_exempt_priority_level_configuration_free");
        return ;
    }
    listEntry_t *listEntry;
    free(v1_exempt_priority_level_configuration);
}

cJSON *v1_exempt_priority_level_configuration_convertToJSON(v1_exempt_priority_level_configuration_t *v1_exempt_priority_level_configuration) {
    cJSON *item = cJSON_CreateObject();

    // v1_exempt_priority_level_configuration->lendable_percent
    if(v1_exempt_priority_level_configuration->lendable_percent) {
    if(cJSON_AddNumberToObject(item, "lendablePercent", v1_exempt_priority_level_configuration->lendable_percent) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_exempt_priority_level_configuration->nominal_concurrency_shares
    if(v1_exempt_priority_level_configuration->nominal_concurrency_shares) {
    if(cJSON_AddNumberToObject(item, "nominalConcurrencyShares", v1_exempt_priority_level_configuration->nominal_concurrency_shares) == NULL) {
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

v1_exempt_priority_level_configuration_t *v1_exempt_priority_level_configuration_parseFromJSON(cJSON *v1_exempt_priority_level_configurationJSON){

    v1_exempt_priority_level_configuration_t *v1_exempt_priority_level_configuration_local_var = NULL;

    // v1_exempt_priority_level_configuration->lendable_percent
    cJSON *lendable_percent = cJSON_GetObjectItemCaseSensitive(v1_exempt_priority_level_configurationJSON, "lendablePercent");
    if (cJSON_IsNull(lendable_percent)) {
        lendable_percent = NULL;
    }
    if (lendable_percent) { 
    if(!cJSON_IsNumber(lendable_percent))
    {
    goto end; //Numeric
    }
    }

    // v1_exempt_priority_level_configuration->nominal_concurrency_shares
    cJSON *nominal_concurrency_shares = cJSON_GetObjectItemCaseSensitive(v1_exempt_priority_level_configurationJSON, "nominalConcurrencyShares");
    if (cJSON_IsNull(nominal_concurrency_shares)) {
        nominal_concurrency_shares = NULL;
    }
    if (nominal_concurrency_shares) { 
    if(!cJSON_IsNumber(nominal_concurrency_shares))
    {
    goto end; //Numeric
    }
    }


    v1_exempt_priority_level_configuration_local_var = v1_exempt_priority_level_configuration_create_internal (
        lendable_percent ? lendable_percent->valuedouble : 0,
        nominal_concurrency_shares ? nominal_concurrency_shares->valuedouble : 0
        );

    return v1_exempt_priority_level_configuration_local_var;
end:
    return NULL;

}
