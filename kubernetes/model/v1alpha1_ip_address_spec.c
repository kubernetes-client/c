#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha1_ip_address_spec.h"



v1alpha1_ip_address_spec_t *v1alpha1_ip_address_spec_create(
    v1alpha1_parent_reference_t *parent_ref
    ) {
    v1alpha1_ip_address_spec_t *v1alpha1_ip_address_spec_local_var = malloc(sizeof(v1alpha1_ip_address_spec_t));
    if (!v1alpha1_ip_address_spec_local_var) {
        return NULL;
    }
    v1alpha1_ip_address_spec_local_var->parent_ref = parent_ref;

    return v1alpha1_ip_address_spec_local_var;
}


void v1alpha1_ip_address_spec_free(v1alpha1_ip_address_spec_t *v1alpha1_ip_address_spec) {
    if(NULL == v1alpha1_ip_address_spec){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha1_ip_address_spec->parent_ref) {
        v1alpha1_parent_reference_free(v1alpha1_ip_address_spec->parent_ref);
        v1alpha1_ip_address_spec->parent_ref = NULL;
    }
    free(v1alpha1_ip_address_spec);
}

cJSON *v1alpha1_ip_address_spec_convertToJSON(v1alpha1_ip_address_spec_t *v1alpha1_ip_address_spec) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha1_ip_address_spec->parent_ref
    if(v1alpha1_ip_address_spec->parent_ref) {
    cJSON *parent_ref_local_JSON = v1alpha1_parent_reference_convertToJSON(v1alpha1_ip_address_spec->parent_ref);
    if(parent_ref_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "parentRef", parent_ref_local_JSON);
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

v1alpha1_ip_address_spec_t *v1alpha1_ip_address_spec_parseFromJSON(cJSON *v1alpha1_ip_address_specJSON){

    v1alpha1_ip_address_spec_t *v1alpha1_ip_address_spec_local_var = NULL;

    // define the local variable for v1alpha1_ip_address_spec->parent_ref
    v1alpha1_parent_reference_t *parent_ref_local_nonprim = NULL;

    // v1alpha1_ip_address_spec->parent_ref
    cJSON *parent_ref = cJSON_GetObjectItemCaseSensitive(v1alpha1_ip_address_specJSON, "parentRef");
    if (parent_ref) { 
    parent_ref_local_nonprim = v1alpha1_parent_reference_parseFromJSON(parent_ref); //nonprimitive
    }


    v1alpha1_ip_address_spec_local_var = v1alpha1_ip_address_spec_create (
        parent_ref ? parent_ref_local_nonprim : NULL
        );

    return v1alpha1_ip_address_spec_local_var;
end:
    if (parent_ref_local_nonprim) {
        v1alpha1_parent_reference_free(parent_ref_local_nonprim);
        parent_ref_local_nonprim = NULL;
    }
    return NULL;

}
