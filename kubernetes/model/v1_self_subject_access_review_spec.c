#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_self_subject_access_review_spec.h"



v1_self_subject_access_review_spec_t *v1_self_subject_access_review_spec_create(
    v1_non_resource_attributes_t *non_resource_attributes,
    v1_resource_attributes_t *resource_attributes
    ) {
    v1_self_subject_access_review_spec_t *v1_self_subject_access_review_spec_local_var = malloc(sizeof(v1_self_subject_access_review_spec_t));
    if (!v1_self_subject_access_review_spec_local_var) {
        return NULL;
    }
    v1_self_subject_access_review_spec_local_var->non_resource_attributes = non_resource_attributes;
    v1_self_subject_access_review_spec_local_var->resource_attributes = resource_attributes;

    return v1_self_subject_access_review_spec_local_var;
}


void v1_self_subject_access_review_spec_free(v1_self_subject_access_review_spec_t *v1_self_subject_access_review_spec) {
    if(NULL == v1_self_subject_access_review_spec){
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

    // v1_self_subject_access_review_spec->non_resource_attributes
    cJSON *non_resource_attributes = cJSON_GetObjectItemCaseSensitive(v1_self_subject_access_review_specJSON, "nonResourceAttributes");
    v1_non_resource_attributes_t *non_resource_attributes_local_nonprim = NULL;
    if (non_resource_attributes) { 
    non_resource_attributes_local_nonprim = v1_non_resource_attributes_parseFromJSON(non_resource_attributes); //nonprimitive
    }

    // v1_self_subject_access_review_spec->resource_attributes
    cJSON *resource_attributes = cJSON_GetObjectItemCaseSensitive(v1_self_subject_access_review_specJSON, "resourceAttributes");
    v1_resource_attributes_t *resource_attributes_local_nonprim = NULL;
    if (resource_attributes) { 
    resource_attributes_local_nonprim = v1_resource_attributes_parseFromJSON(resource_attributes); //nonprimitive
    }


    v1_self_subject_access_review_spec_local_var = v1_self_subject_access_review_spec_create (
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
