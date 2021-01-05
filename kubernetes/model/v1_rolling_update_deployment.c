#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_rolling_update_deployment.h"



v1_rolling_update_deployment_t *v1_rolling_update_deployment_create(
    object_t *max_surge,
    object_t *max_unavailable
    ) {
    v1_rolling_update_deployment_t *v1_rolling_update_deployment_local_var = malloc(sizeof(v1_rolling_update_deployment_t));
    if (!v1_rolling_update_deployment_local_var) {
        return NULL;
    }
    v1_rolling_update_deployment_local_var->max_surge = max_surge;
    v1_rolling_update_deployment_local_var->max_unavailable = max_unavailable;

    return v1_rolling_update_deployment_local_var;
}


void v1_rolling_update_deployment_free(v1_rolling_update_deployment_t *v1_rolling_update_deployment) {
    if(NULL == v1_rolling_update_deployment){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_rolling_update_deployment->max_surge) {
        object_free(v1_rolling_update_deployment->max_surge);
        v1_rolling_update_deployment->max_surge = NULL;
    }
    if (v1_rolling_update_deployment->max_unavailable) {
        object_free(v1_rolling_update_deployment->max_unavailable);
        v1_rolling_update_deployment->max_unavailable = NULL;
    }
    free(v1_rolling_update_deployment);
}

cJSON *v1_rolling_update_deployment_convertToJSON(v1_rolling_update_deployment_t *v1_rolling_update_deployment) {
    cJSON *item = cJSON_CreateObject();

    // v1_rolling_update_deployment->max_surge
    if(v1_rolling_update_deployment->max_surge) { 
    cJSON *max_surge_object = object_convertToJSON(v1_rolling_update_deployment->max_surge);
    if(max_surge_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "maxSurge", max_surge_object);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1_rolling_update_deployment->max_unavailable
    if(v1_rolling_update_deployment->max_unavailable) { 
    cJSON *max_unavailable_object = object_convertToJSON(v1_rolling_update_deployment->max_unavailable);
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

v1_rolling_update_deployment_t *v1_rolling_update_deployment_parseFromJSON(cJSON *v1_rolling_update_deploymentJSON){

    v1_rolling_update_deployment_t *v1_rolling_update_deployment_local_var = NULL;

    // v1_rolling_update_deployment->max_surge
    cJSON *max_surge = cJSON_GetObjectItemCaseSensitive(v1_rolling_update_deploymentJSON, "maxSurge");
    object_t *max_surge_local_object = NULL;
    if (max_surge) { 
    max_surge_local_object = object_parseFromJSON(max_surge); //object
    }

    // v1_rolling_update_deployment->max_unavailable
    cJSON *max_unavailable = cJSON_GetObjectItemCaseSensitive(v1_rolling_update_deploymentJSON, "maxUnavailable");
    object_t *max_unavailable_local_object = NULL;
    if (max_unavailable) { 
    max_unavailable_local_object = object_parseFromJSON(max_unavailable); //object
    }


    v1_rolling_update_deployment_local_var = v1_rolling_update_deployment_create (
        max_surge ? max_surge_local_object : NULL,
        max_unavailable ? max_unavailable_local_object : NULL
        );

    return v1_rolling_update_deployment_local_var;
end:
    return NULL;

}
