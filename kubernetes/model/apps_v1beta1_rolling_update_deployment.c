#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "apps_v1beta1_rolling_update_deployment.h"



apps_v1beta1_rolling_update_deployment_t *apps_v1beta1_rolling_update_deployment_create(
    object_t *max_surge,
    object_t *max_unavailable
    ) {
    apps_v1beta1_rolling_update_deployment_t *apps_v1beta1_rolling_update_deployment_local_var = malloc(sizeof(apps_v1beta1_rolling_update_deployment_t));
    if (!apps_v1beta1_rolling_update_deployment_local_var) {
        return NULL;
    }
    apps_v1beta1_rolling_update_deployment_local_var->max_surge = max_surge;
    apps_v1beta1_rolling_update_deployment_local_var->max_unavailable = max_unavailable;

    return apps_v1beta1_rolling_update_deployment_local_var;
}


void apps_v1beta1_rolling_update_deployment_free(apps_v1beta1_rolling_update_deployment_t *apps_v1beta1_rolling_update_deployment) {
    if(NULL == apps_v1beta1_rolling_update_deployment){
        return ;
    }
    listEntry_t *listEntry;
    if (apps_v1beta1_rolling_update_deployment->max_surge) {
        object_free(apps_v1beta1_rolling_update_deployment->max_surge);
        apps_v1beta1_rolling_update_deployment->max_surge = NULL;
    }
    if (apps_v1beta1_rolling_update_deployment->max_unavailable) {
        object_free(apps_v1beta1_rolling_update_deployment->max_unavailable);
        apps_v1beta1_rolling_update_deployment->max_unavailable = NULL;
    }
    free(apps_v1beta1_rolling_update_deployment);
}

cJSON *apps_v1beta1_rolling_update_deployment_convertToJSON(apps_v1beta1_rolling_update_deployment_t *apps_v1beta1_rolling_update_deployment) {
    cJSON *item = cJSON_CreateObject();

    // apps_v1beta1_rolling_update_deployment->max_surge
    if(apps_v1beta1_rolling_update_deployment->max_surge) { 
    cJSON *max_surge_object = object_convertToJSON(apps_v1beta1_rolling_update_deployment->max_surge);
    if(max_surge_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "maxSurge", max_surge_object);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // apps_v1beta1_rolling_update_deployment->max_unavailable
    if(apps_v1beta1_rolling_update_deployment->max_unavailable) { 
    cJSON *max_unavailable_object = object_convertToJSON(apps_v1beta1_rolling_update_deployment->max_unavailable);
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

apps_v1beta1_rolling_update_deployment_t *apps_v1beta1_rolling_update_deployment_parseFromJSON(cJSON *apps_v1beta1_rolling_update_deploymentJSON){

    apps_v1beta1_rolling_update_deployment_t *apps_v1beta1_rolling_update_deployment_local_var = NULL;

    // apps_v1beta1_rolling_update_deployment->max_surge
    cJSON *max_surge = cJSON_GetObjectItemCaseSensitive(apps_v1beta1_rolling_update_deploymentJSON, "maxSurge");
    object_t *max_surge_local_object = NULL;
    if (max_surge) { 
    max_surge_local_object = object_parseFromJSON(max_surge); //object
    }

    // apps_v1beta1_rolling_update_deployment->max_unavailable
    cJSON *max_unavailable = cJSON_GetObjectItemCaseSensitive(apps_v1beta1_rolling_update_deploymentJSON, "maxUnavailable");
    object_t *max_unavailable_local_object = NULL;
    if (max_unavailable) { 
    max_unavailable_local_object = object_parseFromJSON(max_unavailable); //object
    }


    apps_v1beta1_rolling_update_deployment_local_var = apps_v1beta1_rolling_update_deployment_create (
        max_surge ? max_surge_local_object : NULL,
        max_unavailable ? max_unavailable_local_object : NULL
        );

    return apps_v1beta1_rolling_update_deployment_local_var;
end:
    return NULL;

}
