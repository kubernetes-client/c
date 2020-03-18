#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "apps_v1beta1_rollback_config.h"



apps_v1beta1_rollback_config_t *apps_v1beta1_rollback_config_create(
    long revision
    ) {
    apps_v1beta1_rollback_config_t *apps_v1beta1_rollback_config_local_var = malloc(sizeof(apps_v1beta1_rollback_config_t));
    if (!apps_v1beta1_rollback_config_local_var) {
        return NULL;
    }
    apps_v1beta1_rollback_config_local_var->revision = revision;

    return apps_v1beta1_rollback_config_local_var;
}


void apps_v1beta1_rollback_config_free(apps_v1beta1_rollback_config_t *apps_v1beta1_rollback_config) {
    if(NULL == apps_v1beta1_rollback_config){
        return ;
    }
    listEntry_t *listEntry;
    free(apps_v1beta1_rollback_config);
}

cJSON *apps_v1beta1_rollback_config_convertToJSON(apps_v1beta1_rollback_config_t *apps_v1beta1_rollback_config) {
    cJSON *item = cJSON_CreateObject();

    // apps_v1beta1_rollback_config->revision
    if(apps_v1beta1_rollback_config->revision) { 
    if(cJSON_AddNumberToObject(item, "revision", apps_v1beta1_rollback_config->revision) == NULL) {
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

apps_v1beta1_rollback_config_t *apps_v1beta1_rollback_config_parseFromJSON(cJSON *apps_v1beta1_rollback_configJSON){

    apps_v1beta1_rollback_config_t *apps_v1beta1_rollback_config_local_var = NULL;

    // apps_v1beta1_rollback_config->revision
    cJSON *revision = cJSON_GetObjectItemCaseSensitive(apps_v1beta1_rollback_configJSON, "revision");
    if (revision) { 
    if(!cJSON_IsNumber(revision))
    {
    goto end; //Numeric
    }
    }


    apps_v1beta1_rollback_config_local_var = apps_v1beta1_rollback_config_create (
        revision ? revision->valuedouble : 0
        );

    return apps_v1beta1_rollback_config_local_var;
end:
    return NULL;

}
