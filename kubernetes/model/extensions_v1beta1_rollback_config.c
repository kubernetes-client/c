#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "extensions_v1beta1_rollback_config.h"



extensions_v1beta1_rollback_config_t *extensions_v1beta1_rollback_config_create(
    long revision
    ) {
    extensions_v1beta1_rollback_config_t *extensions_v1beta1_rollback_config_local_var = malloc(sizeof(extensions_v1beta1_rollback_config_t));
    if (!extensions_v1beta1_rollback_config_local_var) {
        return NULL;
    }
    extensions_v1beta1_rollback_config_local_var->revision = revision;

    return extensions_v1beta1_rollback_config_local_var;
}


void extensions_v1beta1_rollback_config_free(extensions_v1beta1_rollback_config_t *extensions_v1beta1_rollback_config) {
    if(NULL == extensions_v1beta1_rollback_config){
        return ;
    }
    listEntry_t *listEntry;
    free(extensions_v1beta1_rollback_config);
}

cJSON *extensions_v1beta1_rollback_config_convertToJSON(extensions_v1beta1_rollback_config_t *extensions_v1beta1_rollback_config) {
    cJSON *item = cJSON_CreateObject();

    // extensions_v1beta1_rollback_config->revision
    if(extensions_v1beta1_rollback_config->revision) { 
    if(cJSON_AddNumberToObject(item, "revision", extensions_v1beta1_rollback_config->revision) == NULL) {
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

extensions_v1beta1_rollback_config_t *extensions_v1beta1_rollback_config_parseFromJSON(cJSON *extensions_v1beta1_rollback_configJSON){

    extensions_v1beta1_rollback_config_t *extensions_v1beta1_rollback_config_local_var = NULL;

    // extensions_v1beta1_rollback_config->revision
    cJSON *revision = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_rollback_configJSON, "revision");
    if (revision) { 
    if(!cJSON_IsNumber(revision))
    {
    goto end; //Numeric
    }
    }


    extensions_v1beta1_rollback_config_local_var = extensions_v1beta1_rollback_config_create (
        revision ? revision->valuedouble : 0
        );

    return extensions_v1beta1_rollback_config_local_var;
end:
    return NULL;

}
