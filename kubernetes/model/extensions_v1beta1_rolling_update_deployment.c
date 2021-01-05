#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "extensions_v1beta1_rolling_update_deployment.h"



extensions_v1beta1_rolling_update_deployment_t *extensions_v1beta1_rolling_update_deployment_create(
    object_t *max_surge,
    object_t *max_unavailable
    ) {
    extensions_v1beta1_rolling_update_deployment_t *extensions_v1beta1_rolling_update_deployment_local_var = malloc(sizeof(extensions_v1beta1_rolling_update_deployment_t));
    if (!extensions_v1beta1_rolling_update_deployment_local_var) {
        return NULL;
    }
    extensions_v1beta1_rolling_update_deployment_local_var->max_surge = max_surge;
    extensions_v1beta1_rolling_update_deployment_local_var->max_unavailable = max_unavailable;

    return extensions_v1beta1_rolling_update_deployment_local_var;
}


void extensions_v1beta1_rolling_update_deployment_free(extensions_v1beta1_rolling_update_deployment_t *extensions_v1beta1_rolling_update_deployment) {
    if(NULL == extensions_v1beta1_rolling_update_deployment){
        return ;
    }
    listEntry_t *listEntry;
    if (extensions_v1beta1_rolling_update_deployment->max_surge) {
        object_free(extensions_v1beta1_rolling_update_deployment->max_surge);
        extensions_v1beta1_rolling_update_deployment->max_surge = NULL;
    }
    if (extensions_v1beta1_rolling_update_deployment->max_unavailable) {
        object_free(extensions_v1beta1_rolling_update_deployment->max_unavailable);
        extensions_v1beta1_rolling_update_deployment->max_unavailable = NULL;
    }
    free(extensions_v1beta1_rolling_update_deployment);
}

cJSON *extensions_v1beta1_rolling_update_deployment_convertToJSON(extensions_v1beta1_rolling_update_deployment_t *extensions_v1beta1_rolling_update_deployment) {
    cJSON *item = cJSON_CreateObject();

    // extensions_v1beta1_rolling_update_deployment->max_surge
    if(extensions_v1beta1_rolling_update_deployment->max_surge) { 
    cJSON *max_surge_object = object_convertToJSON(extensions_v1beta1_rolling_update_deployment->max_surge);
    if(max_surge_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "maxSurge", max_surge_object);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // extensions_v1beta1_rolling_update_deployment->max_unavailable
    if(extensions_v1beta1_rolling_update_deployment->max_unavailable) { 
    cJSON *max_unavailable_object = object_convertToJSON(extensions_v1beta1_rolling_update_deployment->max_unavailable);
    if(max_unavailable_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "maxUnavailable", max_unavailable_object);
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

extensions_v1beta1_rolling_update_deployment_t *extensions_v1beta1_rolling_update_deployment_parseFromJSON(cJSON *extensions_v1beta1_rolling_update_deploymentJSON){

    extensions_v1beta1_rolling_update_deployment_t *extensions_v1beta1_rolling_update_deployment_local_var = NULL;

    // extensions_v1beta1_rolling_update_deployment->max_surge
    cJSON *max_surge = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_rolling_update_deploymentJSON, "maxSurge");
    object_t *max_surge_local_object = NULL;
    if (max_surge) { 
    max_surge_local_object = object_parseFromJSON(max_surge); //object
    }

    // extensions_v1beta1_rolling_update_deployment->max_unavailable
    cJSON *max_unavailable = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_rolling_update_deploymentJSON, "maxUnavailable");
    object_t *max_unavailable_local_object = NULL;
    if (max_unavailable) { 
    max_unavailable_local_object = object_parseFromJSON(max_unavailable); //object
    }


    extensions_v1beta1_rolling_update_deployment_local_var = extensions_v1beta1_rolling_update_deployment_create (
        max_surge ? max_surge_local_object : NULL,
        max_unavailable ? max_unavailable_local_object : NULL
        );

    return extensions_v1beta1_rolling_update_deployment_local_var;
end:
    return NULL;

}
