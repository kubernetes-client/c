#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_weighted_pod_affinity_term.h"



v1_weighted_pod_affinity_term_t *v1_weighted_pod_affinity_term_create(
    v1_pod_affinity_term_t *pod_affinity_term,
    int weight
    ) {
    v1_weighted_pod_affinity_term_t *v1_weighted_pod_affinity_term_local_var = malloc(sizeof(v1_weighted_pod_affinity_term_t));
    if (!v1_weighted_pod_affinity_term_local_var) {
        return NULL;
    }
    v1_weighted_pod_affinity_term_local_var->pod_affinity_term = pod_affinity_term;
    v1_weighted_pod_affinity_term_local_var->weight = weight;

    return v1_weighted_pod_affinity_term_local_var;
}


void v1_weighted_pod_affinity_term_free(v1_weighted_pod_affinity_term_t *v1_weighted_pod_affinity_term) {
    if(NULL == v1_weighted_pod_affinity_term){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_weighted_pod_affinity_term->pod_affinity_term) {
        v1_pod_affinity_term_free(v1_weighted_pod_affinity_term->pod_affinity_term);
        v1_weighted_pod_affinity_term->pod_affinity_term = NULL;
    }
    free(v1_weighted_pod_affinity_term);
}

cJSON *v1_weighted_pod_affinity_term_convertToJSON(v1_weighted_pod_affinity_term_t *v1_weighted_pod_affinity_term) {
    cJSON *item = cJSON_CreateObject();

    // v1_weighted_pod_affinity_term->pod_affinity_term
    if (!v1_weighted_pod_affinity_term->pod_affinity_term) {
        goto fail;
    }
    
    cJSON *pod_affinity_term_local_JSON = v1_pod_affinity_term_convertToJSON(v1_weighted_pod_affinity_term->pod_affinity_term);
    if(pod_affinity_term_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "podAffinityTerm", pod_affinity_term_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // v1_weighted_pod_affinity_term->weight
    if (!v1_weighted_pod_affinity_term->weight) {
        goto fail;
    }
    
    if(cJSON_AddNumberToObject(item, "weight", v1_weighted_pod_affinity_term->weight) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_weighted_pod_affinity_term_t *v1_weighted_pod_affinity_term_parseFromJSON(cJSON *v1_weighted_pod_affinity_termJSON){

    v1_weighted_pod_affinity_term_t *v1_weighted_pod_affinity_term_local_var = NULL;

    // v1_weighted_pod_affinity_term->pod_affinity_term
    cJSON *pod_affinity_term = cJSON_GetObjectItemCaseSensitive(v1_weighted_pod_affinity_termJSON, "podAffinityTerm");
    if (!pod_affinity_term) {
        goto end;
    }

    v1_pod_affinity_term_t *pod_affinity_term_local_nonprim = NULL;
    
    pod_affinity_term_local_nonprim = v1_pod_affinity_term_parseFromJSON(pod_affinity_term); //nonprimitive

    // v1_weighted_pod_affinity_term->weight
    cJSON *weight = cJSON_GetObjectItemCaseSensitive(v1_weighted_pod_affinity_termJSON, "weight");
    if (!weight) {
        goto end;
    }

    
    if(!cJSON_IsNumber(weight))
    {
    goto end; //Numeric
    }


    v1_weighted_pod_affinity_term_local_var = v1_weighted_pod_affinity_term_create (
        pod_affinity_term_local_nonprim,
        weight->valuedouble
        );

    return v1_weighted_pod_affinity_term_local_var;
end:
    if (pod_affinity_term_local_nonprim) {
        v1_pod_affinity_term_free(pod_affinity_term_local_nonprim);
        pod_affinity_term_local_nonprim = NULL;
    }
    return NULL;

}
