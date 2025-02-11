#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_self_subject_access_review_spec.h"



static v1_self_subject_access_review_spec_t *v1_self_subject_access_review_spec_create_internal(
    v1_non_resource_attributes_t *non_resource_attributes,
    v1_resource_attributes_t *resource_attributes
    ) {
    v1_self_subject_access_review_spec_t *v1_self_subject_access_review_spec_local_var = malloc(sizeof(v1_self_subject_access_review_spec_t));
    if (!v1_self_subject_access_review_spec_local_var) {
        return NULL;
    }
    v1_self_subject_access_review_spec_local_var->non_resource_attributes = non_resource_attributes;
    v1_self_subject_access_review_spec_local_var->resource_attributes = resource_attributes;

    v1_self_subject_access_review_spec_local_var->_library_owned = 1;
    return v1_self_subject_access_review_spec_local_var;
}

__attribute__((deprecated)) v1_self_subject_access_review_spec_t *v1_self_subject_access_review_spec_create(
    v1_non_resource_attributes_t *non_resource_attributes,
    v1_resource_attributes_t *resource_attributes
    ) {
    return v1_self_subject_access_review_spec_create_internal (
        non_resource_attributes,
        resource_attributes
        );
}

void v1_self_subject_access_review_spec_free(v1_self_subject_access_review_spec_t *v1_self_subject_access_review_spec) {
    if(NULL == v1_self_subject_access_review_spec){
        return ;
    }
    if(v1_self_subject_access_review_spec->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_self_subject_access_review_spec_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_self_subject_access_review_spec->non_resource_attributes) {
        v1_non_resource_attributes_free(v1_self_subject_access_review_spec->non_resource_attributes);
        v1_self_subject_access_review_spec->non_resource_attributes = NULL;
    }
    if (v1_self_subject_access_review_spec->resource_attributes) {
        v1_resource_attributes_free(v1_self_subject_access_review_spec->resource_attributes);
        v1_self_subject_access_review_spec->resource_attributes = NULL;
    }
    free(v1_self_subject_access_review_spec);
}

cJSON *v1_self_subject_access_review_spec_convertToJSON(v1_self_subject_access_review_spec_t *v1_self_subject_access_review_spec) {
    cJSON *item = cJSON_CreateObject();

    // v1_self_subject_access_review_spec->non_resource_attributes
    if(v1_self_subject_access_review_spec->non_resource_attributes) {
    cJSON *non_resource_attributes_local_JSON = v1_non_resource_attributes_convertToJSON(v1_self_subject_access_review_spec->non_resource_attributes);
    if(non_resource_attributes_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "nonResourceAttributes", non_resource_attributes_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_self_subject_access_review_spec->resource_attributes
    if(v1_self_subject_access_review_spec->resource_attributes) {
    cJSON *resource_attributes_local_JSON = v1_resource_attributes_convertToJSON(v1_self_subject_access_review_spec->resource_attributes);
    if(resource_attributes_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "resourceAttributes", resource_attributes_local_JSON);
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

v1_self_subject_access_review_spec_t *v1_self_subject_access_review_spec_parseFromJSON(cJSON *v1_self_subject_access_review_specJSON){

    v1_self_subject_access_review_spec_t *v1_self_subject_access_review_spec_local_var = NULL;

    // define the local variable for v1_self_subject_access_review_spec->non_resource_attributes
    v1_non_resource_attributes_t *non_resource_attributes_local_nonprim = NULL;

    // define the local variable for v1_self_subject_access_review_spec->resource_attributes
    v1_resource_attributes_t *resource_attributes_local_nonprim = NULL;

    // v1_self_subject_access_review_spec->non_resource_attributes
    cJSON *non_resource_attributes = cJSON_GetObjectItemCaseSensitive(v1_self_subject_access_review_specJSON, "nonResourceAttributes");
    if (cJSON_IsNull(non_resource_attributes)) {
        non_resource_attributes = NULL;
    }
    if (non_resource_attributes) { 
    non_resource_attributes_local_nonprim = v1_non_resource_attributes_parseFromJSON(non_resource_attributes); //nonprimitive
    }

    // v1_self_subject_access_review_spec->resource_attributes
    cJSON *resource_attributes = cJSON_GetObjectItemCaseSensitive(v1_self_subject_access_review_specJSON, "resourceAttributes");
    if (cJSON_IsNull(resource_attributes)) {
        resource_attributes = NULL;
    }
    if (resource_attributes) { 
    resource_attributes_local_nonprim = v1_resource_attributes_parseFromJSON(resource_attributes); //nonprimitive
    }


    v1_self_subject_access_review_spec_local_var = v1_self_subject_access_review_spec_create_internal (
        non_resource_attributes ? non_resource_attributes_local_nonprim : NULL,
        resource_attributes ? resource_attributes_local_nonprim : NULL
        );

    return v1_self_subject_access_review_spec_local_var;
end:
    if (non_resource_attributes_local_nonprim) {
        v1_non_resource_attributes_free(non_resource_attributes_local_nonprim);
        non_resource_attributes_local_nonprim = NULL;
    }
    if (resource_attributes_local_nonprim) {
        v1_resource_attributes_free(resource_attributes_local_nonprim);
        resource_attributes_local_nonprim = NULL;
    }
    return NULL;

}
