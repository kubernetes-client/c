#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_pod_disruption_budget_status.h"



v1beta1_pod_disruption_budget_status_t *v1beta1_pod_disruption_budget_status_create(
    int current_healthy,
    int desired_healthy,
    list_t* disrupted_pods,
    int disruptions_allowed,
    int expected_pods,
    long observed_generation
    ) {
    v1beta1_pod_disruption_budget_status_t *v1beta1_pod_disruption_budget_status_local_var = malloc(sizeof(v1beta1_pod_disruption_budget_status_t));
    if (!v1beta1_pod_disruption_budget_status_local_var) {
        return NULL;
    }
    v1beta1_pod_disruption_budget_status_local_var->current_healthy = current_healthy;
    v1beta1_pod_disruption_budget_status_local_var->desired_healthy = desired_healthy;
    v1beta1_pod_disruption_budget_status_local_var->disrupted_pods = disrupted_pods;
    v1beta1_pod_disruption_budget_status_local_var->disruptions_allowed = disruptions_allowed;
    v1beta1_pod_disruption_budget_status_local_var->expected_pods = expected_pods;
    v1beta1_pod_disruption_budget_status_local_var->observed_generation = observed_generation;

    return v1beta1_pod_disruption_budget_status_local_var;
}


void v1beta1_pod_disruption_budget_status_free(v1beta1_pod_disruption_budget_status_t *v1beta1_pod_disruption_budget_status) {
    if(NULL == v1beta1_pod_disruption_budget_status){
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta1_pod_disruption_budget_status->disrupted_pods) {
        list_ForEach(listEntry, v1beta1_pod_disruption_budget_status->disrupted_pods) {
            keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_free(v1beta1_pod_disruption_budget_status->disrupted_pods);
        v1beta1_pod_disruption_budget_status->disrupted_pods = NULL;
    }
    free(v1beta1_pod_disruption_budget_status);
}

cJSON *v1beta1_pod_disruption_budget_status_convertToJSON(v1beta1_pod_disruption_budget_status_t *v1beta1_pod_disruption_budget_status) {
    cJSON *item = cJSON_CreateObject();

    // v1beta1_pod_disruption_budget_status->current_healthy
    if (!v1beta1_pod_disruption_budget_status->current_healthy) {
        goto fail;
    }
    
    if(cJSON_AddNumberToObject(item, "currentHealthy", v1beta1_pod_disruption_budget_status->current_healthy) == NULL) {
    goto fail; //Numeric
    }


    // v1beta1_pod_disruption_budget_status->desired_healthy
    if (!v1beta1_pod_disruption_budget_status->desired_healthy) {
        goto fail;
    }
    
    if(cJSON_AddNumberToObject(item, "desiredHealthy", v1beta1_pod_disruption_budget_status->desired_healthy) == NULL) {
    goto fail; //Numeric
    }


    // v1beta1_pod_disruption_budget_status->disrupted_pods
    if(v1beta1_pod_disruption_budget_status->disrupted_pods) { 
    cJSON *disrupted_pods = cJSON_AddObjectToObject(item, "disruptedPods");
    if(disrupted_pods == NULL) {
        goto fail; //primitive map container
    }
    cJSON *localMapObject = disrupted_pods;
    listEntry_t *disrupted_podsListEntry;
    if (v1beta1_pod_disruption_budget_status->disrupted_pods) {
    list_ForEach(disrupted_podsListEntry, v1beta1_pod_disruption_budget_status->disrupted_pods) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)disrupted_podsListEntry->data;
    }
    }
     } 


    // v1beta1_pod_disruption_budget_status->disruptions_allowed
    if (!v1beta1_pod_disruption_budget_status->disruptions_allowed) {
        goto fail;
    }
    
    if(cJSON_AddNumberToObject(item, "disruptionsAllowed", v1beta1_pod_disruption_budget_status->disruptions_allowed) == NULL) {
    goto fail; //Numeric
    }


    // v1beta1_pod_disruption_budget_status->expected_pods
    if (!v1beta1_pod_disruption_budget_status->expected_pods) {
        goto fail;
    }
    
    if(cJSON_AddNumberToObject(item, "expectedPods", v1beta1_pod_disruption_budget_status->expected_pods) == NULL) {
    goto fail; //Numeric
    }


    // v1beta1_pod_disruption_budget_status->observed_generation
    if(v1beta1_pod_disruption_budget_status->observed_generation) { 
    if(cJSON_AddNumberToObject(item, "observedGeneration", v1beta1_pod_disruption_budget_status->observed_generation) == NULL) {
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

v1beta1_pod_disruption_budget_status_t *v1beta1_pod_disruption_budget_status_parseFromJSON(cJSON *v1beta1_pod_disruption_budget_statusJSON){

    v1beta1_pod_disruption_budget_status_t *v1beta1_pod_disruption_budget_status_local_var = NULL;

    // v1beta1_pod_disruption_budget_status->current_healthy
    cJSON *current_healthy = cJSON_GetObjectItemCaseSensitive(v1beta1_pod_disruption_budget_statusJSON, "currentHealthy");
    if (!current_healthy) {
        goto end;
    }

    
    if(!cJSON_IsNumber(current_healthy))
    {
    goto end; //Numeric
    }

    // v1beta1_pod_disruption_budget_status->desired_healthy
    cJSON *desired_healthy = cJSON_GetObjectItemCaseSensitive(v1beta1_pod_disruption_budget_statusJSON, "desiredHealthy");
    if (!desired_healthy) {
        goto end;
    }

    
    if(!cJSON_IsNumber(desired_healthy))
    {
    goto end; //Numeric
    }

    // v1beta1_pod_disruption_budget_status->disrupted_pods
    cJSON *disrupted_pods = cJSON_GetObjectItemCaseSensitive(v1beta1_pod_disruption_budget_statusJSON, "disruptedPods");
    list_t *disrupted_podsList;
    if (disrupted_pods) { 
    cJSON *disrupted_pods_local_map;
    if(!cJSON_IsObject(disrupted_pods)) {
        goto end;//primitive map container
    }
    disrupted_podsList = list_create();
    keyValuePair_t *localMapKeyPair;
    cJSON_ArrayForEach(disrupted_pods_local_map, disrupted_pods)
    {
		cJSON *localMapObject = disrupted_pods_local_map;
        list_addElement(disrupted_podsList , localMapKeyPair);
    }
    }

    // v1beta1_pod_disruption_budget_status->disruptions_allowed
    cJSON *disruptions_allowed = cJSON_GetObjectItemCaseSensitive(v1beta1_pod_disruption_budget_statusJSON, "disruptionsAllowed");
    if (!disruptions_allowed) {
        goto end;
    }

    
    if(!cJSON_IsNumber(disruptions_allowed))
    {
    goto end; //Numeric
    }

    // v1beta1_pod_disruption_budget_status->expected_pods
    cJSON *expected_pods = cJSON_GetObjectItemCaseSensitive(v1beta1_pod_disruption_budget_statusJSON, "expectedPods");
    if (!expected_pods) {
        goto end;
    }

    
    if(!cJSON_IsNumber(expected_pods))
    {
    goto end; //Numeric
    }

    // v1beta1_pod_disruption_budget_status->observed_generation
    cJSON *observed_generation = cJSON_GetObjectItemCaseSensitive(v1beta1_pod_disruption_budget_statusJSON, "observedGeneration");
    if (observed_generation) { 
    if(!cJSON_IsNumber(observed_generation))
    {
    goto end; //Numeric
    }
    }


    v1beta1_pod_disruption_budget_status_local_var = v1beta1_pod_disruption_budget_status_create (
        current_healthy->valuedouble,
        desired_healthy->valuedouble,
        disrupted_pods ? disrupted_podsList : NULL,
        disruptions_allowed->valuedouble,
        expected_pods->valuedouble,
        observed_generation ? observed_generation->valuedouble : 0
        );

    return v1beta1_pod_disruption_budget_status_local_var;
end:
    return NULL;

}
