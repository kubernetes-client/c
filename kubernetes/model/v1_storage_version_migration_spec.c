#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_storage_version_migration_spec.h"



static v1_storage_version_migration_spec_t *v1_storage_version_migration_spec_create_internal(
    v1_group_resource_t *resource
    ) {
    v1_storage_version_migration_spec_t *v1_storage_version_migration_spec_local_var = malloc(sizeof(v1_storage_version_migration_spec_t));
    if (!v1_storage_version_migration_spec_local_var) {
        return NULL;
    }
    memset(v1_storage_version_migration_spec_local_var, 0, sizeof(v1_storage_version_migration_spec_t));
    v1_storage_version_migration_spec_local_var->_library_owned = 1;
    v1_storage_version_migration_spec_local_var->resource = resource;
    return v1_storage_version_migration_spec_local_var;
}

__attribute__((deprecated)) v1_storage_version_migration_spec_t *v1_storage_version_migration_spec_create(
    v1_group_resource_t *resource
    ) {
    v1_storage_version_migration_spec_t *result = v1_storage_version_migration_spec_create_internal (
        resource
        );
    if (!result) {
    }
    return result;
}

void v1_storage_version_migration_spec_free(v1_storage_version_migration_spec_t *v1_storage_version_migration_spec) {
    if(NULL == v1_storage_version_migration_spec){
        return ;
    }
    if(v1_storage_version_migration_spec->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_storage_version_migration_spec_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_storage_version_migration_spec->resource) {
        v1_group_resource_free(v1_storage_version_migration_spec->resource);
        v1_storage_version_migration_spec->resource = NULL;
    }
    free(v1_storage_version_migration_spec);
}

cJSON *v1_storage_version_migration_spec_convertToJSON(v1_storage_version_migration_spec_t *v1_storage_version_migration_spec) {
    cJSON *item = cJSON_CreateObject();

    // v1_storage_version_migration_spec->resource
    if (!v1_storage_version_migration_spec->resource) {
        goto fail;
    }
    cJSON *resource_local_JSON = v1_group_resource_convertToJSON(v1_storage_version_migration_spec->resource);
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

v1_storage_version_migration_spec_t *v1_storage_version_migration_spec_parseFromJSON(cJSON *v1_storage_version_migration_specJSON){

    v1_storage_version_migration_spec_t *v1_storage_version_migration_spec_local_var = NULL;

    // define the local variable for v1_storage_version_migration_spec->resource
    v1_group_resource_t *resource_local_nonprim = NULL;

    // v1_storage_version_migration_spec->resource
    cJSON *resource = cJSON_GetObjectItemCaseSensitive(v1_storage_version_migration_specJSON, "resource");
    if (cJSON_IsNull(resource)) {
        resource = NULL;
    }
    if (!resource) {
        goto end;
    }

    
    resource_local_nonprim = v1_group_resource_parseFromJSON(resource); //nonprimitive



    v1_storage_version_migration_spec_local_var = v1_storage_version_migration_spec_create_internal (
        resource_local_nonprim
        );

    if (!v1_storage_version_migration_spec_local_var) {
        goto end;
    }

    return v1_storage_version_migration_spec_local_var;
end:
    if (resource_local_nonprim) {
        v1_group_resource_free(resource_local_nonprim);
        resource_local_nonprim = NULL;
    }
    return NULL;

}
