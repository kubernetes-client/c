#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_rolling_update_deployment.h"



v1_rolling_update_deployment_t *v1_rolling_update_deployment_create(
    int_or_string_t *max_surge,
    int_or_string_t *max_unavailable
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
        int_or_string_free(v1_rolling_update_deployment->max_surge);
        v1_rolling_update_deployment->max_surge = NULL;
    }
    if (v1_rolling_update_deployment->max_unavailable) {
        int_or_string_free(v1_rolling_update_deployment->max_unavailable);
        v1_rolling_update_deployment->max_unavailable = NULL;
    }
    free(v1_rolling_update_deployment);
}

cJSON *v1_rolling_update_deployment_convertToJSON(v1_rolling_update_deployment_t *v1_rolling_update_deployment) {
    cJSON *item = cJSON_CreateObject();

    // v1_rolling_update_deployment->max_surge
    if(v1_rolling_update_deployment->max_surge) { 
    cJSON *max_surge_local_JSON = int_or_string_convertToJSON(v1_rolling_update_deployment->max_surge);
    if(max_surge_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "maxSurge", max_surge_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
     } 


    // v1_rolling_update_deployment->max_unavailable
    if(v1_rolling_update_deployment->max_unavailable) { 
    cJSON *max_unavailable_local_JSON = int_or_string_convertToJSON(v1_rolling_update_deployment->max_unavailable);
    if(max_unavailable_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "maxUnavailable", max_unavailable_local_JSON);
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

    // define the local variable for v1_rolling_update_deployment->max_surge
    int_or_string_t *max_surge_local_nonprim = NULL;

    // define the local variable for v1_rolling_update_deployment->max_unavailable
    int_or_string_t *max_unavailable_local_nonprim = NULL;

    // v1_rolling_update_deployment->max_surge
    cJSON *max_surge = cJSON_GetObjectItemCaseSensitive(v1_rolling_update_deploymentJSON, "maxSurge");
    if (max_surge) { 
    max_surge_local_nonprim = int_or_string_parseFromJSON(max_surge); //custom
    }

    // v1_rolling_update_deployment->max_unavailable
    cJSON *max_unavailable = cJSON_GetObjectItemCaseSensitive(v1_rolling_update_deploymentJSON, "maxUnavailable");
    if (max_unavailable) { 
    max_unavailable_local_nonprim = int_or_string_parseFromJSON(max_unavailable); //custom
    }


    v1_rolling_update_deployment_local_var = v1_rolling_update_deployment_create (
        max_surge ? max_surge_local_nonprim : NULL,
        max_unavailable ? max_unavailable_local_nonprim : NULL
        );

    return v1_rolling_update_deployment_local_var;
end:
    if (max_surge_local_nonprim) {
        int_or_string_free(max_surge_local_nonprim);
        max_surge_local_nonprim = NULL;
    }
    if (max_unavailable_local_nonprim) {
        int_or_string_free(max_unavailable_local_nonprim);
        max_unavailable_local_nonprim = NULL;
    }
    return NULL;

}
