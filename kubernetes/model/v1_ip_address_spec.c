#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_ip_address_spec.h"



static v1_ip_address_spec_t *v1_ip_address_spec_create_internal(
    v1_parent_reference_t *parent_ref
    ) {
    v1_ip_address_spec_t *v1_ip_address_spec_local_var = malloc(sizeof(v1_ip_address_spec_t));
    if (!v1_ip_address_spec_local_var) {
        return NULL;
    }
    v1_ip_address_spec_local_var->parent_ref = parent_ref;

    v1_ip_address_spec_local_var->_library_owned = 1;
    return v1_ip_address_spec_local_var;
}

__attribute__((deprecated)) v1_ip_address_spec_t *v1_ip_address_spec_create(
    v1_parent_reference_t *parent_ref
    ) {
    return v1_ip_address_spec_create_internal (
        parent_ref
        );
}

void v1_ip_address_spec_free(v1_ip_address_spec_t *v1_ip_address_spec) {
    if(NULL == v1_ip_address_spec){
        return ;
    }
    if(v1_ip_address_spec->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_ip_address_spec_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_ip_address_spec->parent_ref) {
        v1_parent_reference_free(v1_ip_address_spec->parent_ref);
        v1_ip_address_spec->parent_ref = NULL;
    }
    free(v1_ip_address_spec);
}

cJSON *v1_ip_address_spec_convertToJSON(v1_ip_address_spec_t *v1_ip_address_spec) {
    cJSON *item = cJSON_CreateObject();

    // v1_ip_address_spec->parent_ref
    if (!v1_ip_address_spec->parent_ref) {
        goto fail;
    }
    cJSON *parent_ref_local_JSON = v1_parent_reference_convertToJSON(v1_ip_address_spec->parent_ref);
    if(parent_ref_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "parentRef", parent_ref_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_ip_address_spec_t *v1_ip_address_spec_parseFromJSON(cJSON *v1_ip_address_specJSON){

    v1_ip_address_spec_t *v1_ip_address_spec_local_var = NULL;

    // define the local variable for v1_ip_address_spec->parent_ref
    v1_parent_reference_t *parent_ref_local_nonprim = NULL;

    // v1_ip_address_spec->parent_ref
    cJSON *parent_ref = cJSON_GetObjectItemCaseSensitive(v1_ip_address_specJSON, "parentRef");
    if (cJSON_IsNull(parent_ref)) {
        parent_ref = NULL;
    }
    if (!parent_ref) {
        goto end;
    }

    
    parent_ref_local_nonprim = v1_parent_reference_parseFromJSON(parent_ref); //nonprimitive


    v1_ip_address_spec_local_var = v1_ip_address_spec_create_internal (
        parent_ref_local_nonprim
        );

    return v1_ip_address_spec_local_var;
end:
    if (parent_ref_local_nonprim) {
        v1_parent_reference_free(parent_ref_local_nonprim);
        parent_ref_local_nonprim = NULL;
    }
    return NULL;

}
