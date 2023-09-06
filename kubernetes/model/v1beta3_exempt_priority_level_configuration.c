#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta3_exempt_priority_level_configuration.h"



v1beta3_exempt_priority_level_configuration_t *v1beta3_exempt_priority_level_configuration_create(
    int lendable_percent,
    int nominal_concurrency_shares
    ) {
    v1beta3_exempt_priority_level_configuration_t *v1beta3_exempt_priority_level_configuration_local_var = malloc(sizeof(v1beta3_exempt_priority_level_configuration_t));
    if (!v1beta3_exempt_priority_level_configuration_local_var) {
        return NULL;
    }
    v1beta3_exempt_priority_level_configuration_local_var->lendable_percent = lendable_percent;
    v1beta3_exempt_priority_level_configuration_local_var->nominal_concurrency_shares = nominal_concurrency_shares;

    return v1beta3_exempt_priority_level_configuration_local_var;
}


void v1beta3_exempt_priority_level_configuration_free(v1beta3_exempt_priority_level_configuration_t *v1beta3_exempt_priority_level_configuration) {
    if(NULL == v1beta3_exempt_priority_level_configuration){
        return ;
    }
    listEntry_t *listEntry;
    free(v1beta3_exempt_priority_level_configuration);
}

cJSON *v1beta3_exempt_priority_level_configuration_convertToJSON(v1beta3_exempt_priority_level_configuration_t *v1beta3_exempt_priority_level_configuration) {
    cJSON *item = cJSON_CreateObject();

    // v1beta3_exempt_priority_level_configuration->lendable_percent
    if(v1beta3_exempt_priority_level_configuration->lendable_percent) {
    if(cJSON_AddNumberToObject(item, "lendablePercent", v1beta3_exempt_priority_level_configuration->lendable_percent) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1beta3_exempt_priority_level_configuration->nominal_concurrency_shares
    if(v1beta3_exempt_priority_level_configuration->nominal_concurrency_shares) {
    if(cJSON_AddNumberToObject(item, "nominalConcurrencyShares", v1beta3_exempt_priority_level_configuration->nominal_concurrency_shares) == NULL) {
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

v1beta3_exempt_priority_level_configuration_t *v1beta3_exempt_priority_level_configuration_parseFromJSON(cJSON *v1beta3_exempt_priority_level_configurationJSON){

    v1beta3_exempt_priority_level_configuration_t *v1beta3_exempt_priority_level_configuration_local_var = NULL;

    // v1beta3_exempt_priority_level_configuration->lendable_percent
    cJSON *lendable_percent = cJSON_GetObjectItemCaseSensitive(v1beta3_exempt_priority_level_configurationJSON, "lendablePercent");
    if (lendable_percent) { 
    if(!cJSON_IsNumber(lendable_percent))
    {
    goto end; //Numeric
    }
    }

    // v1beta3_exempt_priority_level_configuration->nominal_concurrency_shares
    cJSON *nominal_concurrency_shares = cJSON_GetObjectItemCaseSensitive(v1beta3_exempt_priority_level_configurationJSON, "nominalConcurrencyShares");
    if (nominal_concurrency_shares) { 
    if(!cJSON_IsNumber(nominal_concurrency_shares))
    {
    goto end; //Numeric
    }
    }


    v1beta3_exempt_priority_level_configuration_local_var = v1beta3_exempt_priority_level_configuration_create (
        lendable_percent ? lendable_percent->valuedouble : 0,
        nominal_concurrency_shares ? nominal_concurrency_shares->valuedouble : 0
        );

    return v1beta3_exempt_priority_level_configuration_local_var;
end:
    return NULL;

}
