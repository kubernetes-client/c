#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_weighted_pod_affinity_term.h"



static v1_weighted_pod_affinity_term_t *v1_weighted_pod_affinity_term_create_internal(
    v1_pod_affinity_term_t *pod_affinity_term,
    int *weight
    ) {
    v1_weighted_pod_affinity_term_t *v1_weighted_pod_affinity_term_local_var = malloc(sizeof(v1_weighted_pod_affinity_term_t));
    if (!v1_weighted_pod_affinity_term_local_var) {
        return NULL;
    }
    memset(v1_weighted_pod_affinity_term_local_var, 0, sizeof(v1_weighted_pod_affinity_term_t));
    v1_weighted_pod_affinity_term_local_var->_library_owned = 1;
    v1_weighted_pod_affinity_term_local_var->pod_affinity_term = pod_affinity_term;
    v1_weighted_pod_affinity_term_local_var->weight = weight;
    return v1_weighted_pod_affinity_term_local_var;
}

__attribute__((deprecated)) v1_weighted_pod_affinity_term_t *v1_weighted_pod_affinity_term_create(
    v1_pod_affinity_term_t *pod_affinity_term,
    int *weight
    ) {
    int *weight_copy = NULL;
    if (weight) {
        weight_copy = malloc(sizeof(int));
        if (weight_copy) *weight_copy = *weight;
    }
    v1_weighted_pod_affinity_term_t *result = v1_weighted_pod_affinity_term_create_internal (
        pod_affinity_term,
        weight_copy
        );
    if (!result) {
        free(weight_copy);
    }
    return result;
}

void v1_weighted_pod_affinity_term_free(v1_weighted_pod_affinity_term_t *v1_weighted_pod_affinity_term) {
    if(NULL == v1_weighted_pod_affinity_term){
        return ;
    }
    if(v1_weighted_pod_affinity_term->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_weighted_pod_affinity_term_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_weighted_pod_affinity_term->pod_affinity_term) {
        v1_pod_affinity_term_free(v1_weighted_pod_affinity_term->pod_affinity_term);
        v1_weighted_pod_affinity_term->pod_affinity_term = NULL;
    }
    if (v1_weighted_pod_affinity_term->weight) {
        free(v1_weighted_pod_affinity_term->weight);
        v1_weighted_pod_affinity_term->weight = NULL;
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
    if(cJSON_AddNumberToObject(item, "weight", *v1_weighted_pod_affinity_term->weight) == NULL) {
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

    // define the local variable for v1_weighted_pod_affinity_term->pod_affinity_term
    v1_pod_affinity_term_t *pod_affinity_term_local_nonprim = NULL;

    // define the local variable for v1_weighted_pod_affinity_term->weight
    int *weight_local_var = NULL;

    // v1_weighted_pod_affinity_term->pod_affinity_term
    cJSON *pod_affinity_term = cJSON_GetObjectItemCaseSensitive(v1_weighted_pod_affinity_termJSON, "podAffinityTerm");
    if (cJSON_IsNull(pod_affinity_term)) {
        pod_affinity_term = NULL;
    }
    if (!pod_affinity_term) {
        goto end;
    }

    
    pod_affinity_term_local_nonprim = v1_pod_affinity_term_parseFromJSON(pod_affinity_term); //nonprimitive

    // v1_weighted_pod_affinity_term->weight
    cJSON *weight = cJSON_GetObjectItemCaseSensitive(v1_weighted_pod_affinity_termJSON, "weight");
    if (cJSON_IsNull(weight)) {
        weight = NULL;
    }
    if (!weight) {
        goto end;
    }

    
    if(!cJSON_IsNumber(weight))
    {
    goto end; //Numeric
    }
    weight_local_var = malloc(sizeof(int));
    if(!weight_local_var)
    {
        goto end;
    }
    *weight_local_var = weight->valuedouble;



    v1_weighted_pod_affinity_term_local_var = v1_weighted_pod_affinity_term_create_internal (
        pod_affinity_term_local_nonprim,
        weight_local_var
        );

    if (!v1_weighted_pod_affinity_term_local_var) {
        goto end;
    }

    return v1_weighted_pod_affinity_term_local_var;
end:
    if (pod_affinity_term_local_nonprim) {
        v1_pod_affinity_term_free(pod_affinity_term_local_nonprim);
        pod_affinity_term_local_nonprim = NULL;
    }
    if (weight_local_var) {
        free(weight_local_var);
        weight_local_var = NULL;
    }
    return NULL;

}
