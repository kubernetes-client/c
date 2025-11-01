#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_mutation.h"



static v1beta1_mutation_t *v1beta1_mutation_create_internal(
    v1beta1_apply_configuration_t *apply_configuration,
    v1beta1_json_patch_t *json_patch,
    char *patch_type
    ) {
    v1beta1_mutation_t *v1beta1_mutation_local_var = malloc(sizeof(v1beta1_mutation_t));
    if (!v1beta1_mutation_local_var) {
        return NULL;
    }
    v1beta1_mutation_local_var->apply_configuration = apply_configuration;
    v1beta1_mutation_local_var->json_patch = json_patch;
    v1beta1_mutation_local_var->patch_type = patch_type;

    v1beta1_mutation_local_var->_library_owned = 1;
    return v1beta1_mutation_local_var;
}

__attribute__((deprecated)) v1beta1_mutation_t *v1beta1_mutation_create(
    v1beta1_apply_configuration_t *apply_configuration,
    v1beta1_json_patch_t *json_patch,
    char *patch_type
    ) {
    return v1beta1_mutation_create_internal (
        apply_configuration,
        json_patch,
        patch_type
        );
}

void v1beta1_mutation_free(v1beta1_mutation_t *v1beta1_mutation) {
    if(NULL == v1beta1_mutation){
        return ;
    }
    if(v1beta1_mutation->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1beta1_mutation_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta1_mutation->apply_configuration) {
        v1beta1_apply_configuration_free(v1beta1_mutation->apply_configuration);
        v1beta1_mutation->apply_configuration = NULL;
    }
    if (v1beta1_mutation->json_patch) {
        v1beta1_json_patch_free(v1beta1_mutation->json_patch);
        v1beta1_mutation->json_patch = NULL;
    }
    if (v1beta1_mutation->patch_type) {
        free(v1beta1_mutation->patch_type);
        v1beta1_mutation->patch_type = NULL;
    }
    free(v1beta1_mutation);
}

cJSON *v1beta1_mutation_convertToJSON(v1beta1_mutation_t *v1beta1_mutation) {
    cJSON *item = cJSON_CreateObject();

    // v1beta1_mutation->apply_configuration
    if(v1beta1_mutation->apply_configuration) {
    cJSON *apply_configuration_local_JSON = v1beta1_apply_configuration_convertToJSON(v1beta1_mutation->apply_configuration);
    if(apply_configuration_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "applyConfiguration", apply_configuration_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1beta1_mutation->json_patch
    if(v1beta1_mutation->json_patch) {
    cJSON *json_patch_local_JSON = v1beta1_json_patch_convertToJSON(v1beta1_mutation->json_patch);
    if(json_patch_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "jsonPatch", json_patch_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1beta1_mutation->patch_type
    if (!v1beta1_mutation->patch_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "patchType", v1beta1_mutation->patch_type) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1beta1_mutation_t *v1beta1_mutation_parseFromJSON(cJSON *v1beta1_mutationJSON){

    v1beta1_mutation_t *v1beta1_mutation_local_var = NULL;

    // define the local variable for v1beta1_mutation->apply_configuration
    v1beta1_apply_configuration_t *apply_configuration_local_nonprim = NULL;

    // define the local variable for v1beta1_mutation->json_patch
    v1beta1_json_patch_t *json_patch_local_nonprim = NULL;

    // v1beta1_mutation->apply_configuration
    cJSON *apply_configuration = cJSON_GetObjectItemCaseSensitive(v1beta1_mutationJSON, "applyConfiguration");
    if (cJSON_IsNull(apply_configuration)) {
        apply_configuration = NULL;
    }
    if (apply_configuration) { 
    apply_configuration_local_nonprim = v1beta1_apply_configuration_parseFromJSON(apply_configuration); //nonprimitive
    }

    // v1beta1_mutation->json_patch
    cJSON *json_patch = cJSON_GetObjectItemCaseSensitive(v1beta1_mutationJSON, "jsonPatch");
    if (cJSON_IsNull(json_patch)) {
        json_patch = NULL;
    }
    if (json_patch) { 
    json_patch_local_nonprim = v1beta1_json_patch_parseFromJSON(json_patch); //nonprimitive
    }

    // v1beta1_mutation->patch_type
    cJSON *patch_type = cJSON_GetObjectItemCaseSensitive(v1beta1_mutationJSON, "patchType");
    if (cJSON_IsNull(patch_type)) {
        patch_type = NULL;
    }
    if (!patch_type) {
        goto end;
    }

    
    if(!cJSON_IsString(patch_type))
    {
    goto end; //String
    }


    v1beta1_mutation_local_var = v1beta1_mutation_create_internal (
        apply_configuration ? apply_configuration_local_nonprim : NULL,
        json_patch ? json_patch_local_nonprim : NULL,
        strdup(patch_type->valuestring)
        );

    return v1beta1_mutation_local_var;
end:
    if (apply_configuration_local_nonprim) {
        v1beta1_apply_configuration_free(apply_configuration_local_nonprim);
        apply_configuration_local_nonprim = NULL;
    }
    if (json_patch_local_nonprim) {
        v1beta1_json_patch_free(json_patch_local_nonprim);
        json_patch_local_nonprim = NULL;
    }
    return NULL;

}
