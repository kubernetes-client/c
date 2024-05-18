#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha1_storage_version_migration_spec.h"



v1alpha1_storage_version_migration_spec_t *v1alpha1_storage_version_migration_spec_create(
    char *continue_token,
    v1alpha1_group_version_resource_t *resource
    ) {
    v1alpha1_storage_version_migration_spec_t *v1alpha1_storage_version_migration_spec_local_var = malloc(sizeof(v1alpha1_storage_version_migration_spec_t));
    if (!v1alpha1_storage_version_migration_spec_local_var) {
        return NULL;
    }
    v1alpha1_storage_version_migration_spec_local_var->continue_token = continue_token;
    v1alpha1_storage_version_migration_spec_local_var->resource = resource;

    return v1alpha1_storage_version_migration_spec_local_var;
}


void v1alpha1_storage_version_migration_spec_free(v1alpha1_storage_version_migration_spec_t *v1alpha1_storage_version_migration_spec) {
    if(NULL == v1alpha1_storage_version_migration_spec){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha1_storage_version_migration_spec->continue_token) {
        free(v1alpha1_storage_version_migration_spec->continue_token);
        v1alpha1_storage_version_migration_spec->continue_token = NULL;
    }
    if (v1alpha1_storage_version_migration_spec->resource) {
        v1alpha1_group_version_resource_free(v1alpha1_storage_version_migration_spec->resource);
        v1alpha1_storage_version_migration_spec->resource = NULL;
    }
    free(v1alpha1_storage_version_migration_spec);
}

cJSON *v1alpha1_storage_version_migration_spec_convertToJSON(v1alpha1_storage_version_migration_spec_t *v1alpha1_storage_version_migration_spec) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha1_storage_version_migration_spec->continue_token
    if(v1alpha1_storage_version_migration_spec->continue_token) {
    if(cJSON_AddStringToObject(item, "continueToken", v1alpha1_storage_version_migration_spec->continue_token) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha1_storage_version_migration_spec->resource
    if (!v1alpha1_storage_version_migration_spec->resource) {
        goto fail;
    }
    cJSON *resource_local_JSON = v1alpha1_group_version_resource_convertToJSON(v1alpha1_storage_version_migration_spec->resource);
    if(resource_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "resource", resource_local_JSON);
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

v1alpha1_storage_version_migration_spec_t *v1alpha1_storage_version_migration_spec_parseFromJSON(cJSON *v1alpha1_storage_version_migration_specJSON){

    v1alpha1_storage_version_migration_spec_t *v1alpha1_storage_version_migration_spec_local_var = NULL;

    // define the local variable for v1alpha1_storage_version_migration_spec->resource
    v1alpha1_group_version_resource_t *resource_local_nonprim = NULL;

    // v1alpha1_storage_version_migration_spec->continue_token
    cJSON *continue_token = cJSON_GetObjectItemCaseSensitive(v1alpha1_storage_version_migration_specJSON, "continueToken");
    if (continue_token) { 
    if(!cJSON_IsString(continue_token) && !cJSON_IsNull(continue_token))
    {
    goto end; //String
    }
    }

    // v1alpha1_storage_version_migration_spec->resource
    cJSON *resource = cJSON_GetObjectItemCaseSensitive(v1alpha1_storage_version_migration_specJSON, "resource");
    if (!resource) {
        goto end;
    }

    
    resource_local_nonprim = v1alpha1_group_version_resource_parseFromJSON(resource); //nonprimitive


    v1alpha1_storage_version_migration_spec_local_var = v1alpha1_storage_version_migration_spec_create (
        continue_token && !cJSON_IsNull(continue_token) ? strdup(continue_token->valuestring) : NULL,
        resource_local_nonprim
        );

    return v1alpha1_storage_version_migration_spec_local_var;
end:
    if (resource_local_nonprim) {
        v1alpha1_group_version_resource_free(resource_local_nonprim);
        resource_local_nonprim = NULL;
    }
    return NULL;

}
