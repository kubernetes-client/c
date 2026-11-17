#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_preferred_scheduling_term.h"



static v1_preferred_scheduling_term_t *v1_preferred_scheduling_term_create_internal(
    v1_node_selector_term_t *preference,
    int *weight
    ) {
    v1_preferred_scheduling_term_t *v1_preferred_scheduling_term_local_var = malloc(sizeof(v1_preferred_scheduling_term_t));
    if (!v1_preferred_scheduling_term_local_var) {
        return NULL;
    }
    memset(v1_preferred_scheduling_term_local_var, 0, sizeof(v1_preferred_scheduling_term_t));
    v1_preferred_scheduling_term_local_var->_library_owned = 1;
    v1_preferred_scheduling_term_local_var->preference = preference;
    v1_preferred_scheduling_term_local_var->weight = weight;
    return v1_preferred_scheduling_term_local_var;
}

__attribute__((deprecated)) v1_preferred_scheduling_term_t *v1_preferred_scheduling_term_create(
    v1_node_selector_term_t *preference,
    int *weight
    ) {
    int *weight_copy = NULL;
    if (weight) {
        weight_copy = malloc(sizeof(int));
        if (weight_copy) *weight_copy = *weight;
    }
    v1_preferred_scheduling_term_t *result = v1_preferred_scheduling_term_create_internal (
        preference,
        weight_copy
        );
    if (!result) {
        free(weight_copy);
    }
    return result;
}

void v1_preferred_scheduling_term_free(v1_preferred_scheduling_term_t *v1_preferred_scheduling_term) {
    if(NULL == v1_preferred_scheduling_term){
        return ;
    }
    if(v1_preferred_scheduling_term->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_preferred_scheduling_term_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_preferred_scheduling_term->preference) {
        v1_node_selector_term_free(v1_preferred_scheduling_term->preference);
        v1_preferred_scheduling_term->preference = NULL;
    }
    if (v1_preferred_scheduling_term->weight) {
        free(v1_preferred_scheduling_term->weight);
        v1_preferred_scheduling_term->weight = NULL;
    }
    free(v1_preferred_scheduling_term);
}

cJSON *v1_preferred_scheduling_term_convertToJSON(v1_preferred_scheduling_term_t *v1_preferred_scheduling_term) {
    cJSON *item = cJSON_CreateObject();

    // v1_preferred_scheduling_term->preference
    if (!v1_preferred_scheduling_term->preference) {
        goto fail;
    }
    cJSON *preference_local_JSON = v1_node_selector_term_convertToJSON(v1_preferred_scheduling_term->preference);
    if(preference_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "preference", preference_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // v1_preferred_scheduling_term->weight
    if (!v1_preferred_scheduling_term->weight) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "weight", *v1_preferred_scheduling_term->weight) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_preferred_scheduling_term_t *v1_preferred_scheduling_term_parseFromJSON(cJSON *v1_preferred_scheduling_termJSON){

    v1_preferred_scheduling_term_t *v1_preferred_scheduling_term_local_var = NULL;

    // define the local variable for v1_preferred_scheduling_term->preference
    v1_node_selector_term_t *preference_local_nonprim = NULL;

    // define the local variable for v1_preferred_scheduling_term->weight
    int *weight_local_var = NULL;

    // v1_preferred_scheduling_term->preference
    cJSON *preference = cJSON_GetObjectItemCaseSensitive(v1_preferred_scheduling_termJSON, "preference");
    if (cJSON_IsNull(preference)) {
        preference = NULL;
    }
    if (!preference) {
        goto end;
    }

    
    preference_local_nonprim = v1_node_selector_term_parseFromJSON(preference); //nonprimitive

    // v1_preferred_scheduling_term->weight
    cJSON *weight = cJSON_GetObjectItemCaseSensitive(v1_preferred_scheduling_termJSON, "weight");
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



    v1_preferred_scheduling_term_local_var = v1_preferred_scheduling_term_create_internal (
        preference_local_nonprim,
        weight_local_var
        );

    if (!v1_preferred_scheduling_term_local_var) {
        goto end;
    }

    return v1_preferred_scheduling_term_local_var;
end:
    if (preference_local_nonprim) {
        v1_node_selector_term_free(preference_local_nonprim);
        preference_local_nonprim = NULL;
    }
    if (weight_local_var) {
        free(weight_local_var);
        weight_local_var = NULL;
    }
    return NULL;

}
