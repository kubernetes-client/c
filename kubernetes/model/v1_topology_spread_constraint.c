#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_topology_spread_constraint.h"



v1_topology_spread_constraint_t *v1_topology_spread_constraint_create(
    v1_label_selector_t *label_selector,
    int max_skew,
    char *topology_key,
    char *when_unsatisfiable
    ) {
    v1_topology_spread_constraint_t *v1_topology_spread_constraint_local_var = malloc(sizeof(v1_topology_spread_constraint_t));
    if (!v1_topology_spread_constraint_local_var) {
        return NULL;
    }
    v1_topology_spread_constraint_local_var->label_selector = label_selector;
    v1_topology_spread_constraint_local_var->max_skew = max_skew;
    v1_topology_spread_constraint_local_var->topology_key = topology_key;
    v1_topology_spread_constraint_local_var->when_unsatisfiable = when_unsatisfiable;

    return v1_topology_spread_constraint_local_var;
}


void v1_topology_spread_constraint_free(v1_topology_spread_constraint_t *v1_topology_spread_constraint) {
    if(NULL == v1_topology_spread_constraint){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_topology_spread_constraint->label_selector) {
        v1_label_selector_free(v1_topology_spread_constraint->label_selector);
        v1_topology_spread_constraint->label_selector = NULL;
    }
    if (v1_topology_spread_constraint->topology_key) {
        free(v1_topology_spread_constraint->topology_key);
        v1_topology_spread_constraint->topology_key = NULL;
    }
    if (v1_topology_spread_constraint->when_unsatisfiable) {
        free(v1_topology_spread_constraint->when_unsatisfiable);
        v1_topology_spread_constraint->when_unsatisfiable = NULL;
    }
    free(v1_topology_spread_constraint);
}

cJSON *v1_topology_spread_constraint_convertToJSON(v1_topology_spread_constraint_t *v1_topology_spread_constraint) {
    cJSON *item = cJSON_CreateObject();

    // v1_topology_spread_constraint->label_selector
    if(v1_topology_spread_constraint->label_selector) { 
    cJSON *label_selector_local_JSON = v1_label_selector_convertToJSON(v1_topology_spread_constraint->label_selector);
    if(label_selector_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "labelSelector", label_selector_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1_topology_spread_constraint->max_skew
    if (!v1_topology_spread_constraint->max_skew) {
        goto fail;
    }
    
    if(cJSON_AddNumberToObject(item, "maxSkew", v1_topology_spread_constraint->max_skew) == NULL) {
    goto fail; //Numeric
    }


    // v1_topology_spread_constraint->topology_key
    if (!v1_topology_spread_constraint->topology_key) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "topologyKey", v1_topology_spread_constraint->topology_key) == NULL) {
    goto fail; //String
    }


    // v1_topology_spread_constraint->when_unsatisfiable
    if (!v1_topology_spread_constraint->when_unsatisfiable) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "whenUnsatisfiable", v1_topology_spread_constraint->when_unsatisfiable) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_topology_spread_constraint_t *v1_topology_spread_constraint_parseFromJSON(cJSON *v1_topology_spread_constraintJSON){

    v1_topology_spread_constraint_t *v1_topology_spread_constraint_local_var = NULL;

    // v1_topology_spread_constraint->label_selector
    cJSON *label_selector = cJSON_GetObjectItemCaseSensitive(v1_topology_spread_constraintJSON, "labelSelector");
    v1_label_selector_t *label_selector_local_nonprim = NULL;
    if (label_selector) { 
    label_selector_local_nonprim = v1_label_selector_parseFromJSON(label_selector); //nonprimitive
    }

    // v1_topology_spread_constraint->max_skew
    cJSON *max_skew = cJSON_GetObjectItemCaseSensitive(v1_topology_spread_constraintJSON, "maxSkew");
    if (!max_skew) {
        goto end;
    }

    
    if(!cJSON_IsNumber(max_skew))
    {
    goto end; //Numeric
    }

    // v1_topology_spread_constraint->topology_key
    cJSON *topology_key = cJSON_GetObjectItemCaseSensitive(v1_topology_spread_constraintJSON, "topologyKey");
    if (!topology_key) {
        goto end;
    }

    
    if(!cJSON_IsString(topology_key))
    {
    goto end; //String
    }

    // v1_topology_spread_constraint->when_unsatisfiable
    cJSON *when_unsatisfiable = cJSON_GetObjectItemCaseSensitive(v1_topology_spread_constraintJSON, "whenUnsatisfiable");
    if (!when_unsatisfiable) {
        goto end;
    }

    
    if(!cJSON_IsString(when_unsatisfiable))
    {
    goto end; //String
    }


    v1_topology_spread_constraint_local_var = v1_topology_spread_constraint_create (
        label_selector ? label_selector_local_nonprim : NULL,
        max_skew->valuedouble,
        strdup(topology_key->valuestring),
        strdup(when_unsatisfiable->valuestring)
        );

    return v1_topology_spread_constraint_local_var;
end:
    if (label_selector_local_nonprim) {
        v1_label_selector_free(label_selector_local_nonprim);
        label_selector_local_nonprim = NULL;
    }
    return NULL;

}
