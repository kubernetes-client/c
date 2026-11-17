#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_node_allocatable_resource.h"



static v1_node_allocatable_resource_t *v1_node_allocatable_resource_create_internal(
    v1_node_allocatable_mapping_t *mapping,
    v1_node_allocatable_overhead_t *overhead
    ) {
    v1_node_allocatable_resource_t *v1_node_allocatable_resource_local_var = malloc(sizeof(v1_node_allocatable_resource_t));
    if (!v1_node_allocatable_resource_local_var) {
        return NULL;
    }
    memset(v1_node_allocatable_resource_local_var, 0, sizeof(v1_node_allocatable_resource_t));
    v1_node_allocatable_resource_local_var->_library_owned = 1;
    v1_node_allocatable_resource_local_var->mapping = mapping;
    v1_node_allocatable_resource_local_var->overhead = overhead;
    return v1_node_allocatable_resource_local_var;
}

__attribute__((deprecated)) v1_node_allocatable_resource_t *v1_node_allocatable_resource_create(
    v1_node_allocatable_mapping_t *mapping,
    v1_node_allocatable_overhead_t *overhead
    ) {
    v1_node_allocatable_resource_t *result = v1_node_allocatable_resource_create_internal (
        mapping,
        overhead
        );
    if (!result) {
    }
    return result;
}

void v1_node_allocatable_resource_free(v1_node_allocatable_resource_t *v1_node_allocatable_resource) {
    if(NULL == v1_node_allocatable_resource){
        return ;
    }
    if(v1_node_allocatable_resource->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_node_allocatable_resource_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_node_allocatable_resource->mapping) {
        v1_node_allocatable_mapping_free(v1_node_allocatable_resource->mapping);
        v1_node_allocatable_resource->mapping = NULL;
    }
    if (v1_node_allocatable_resource->overhead) {
        v1_node_allocatable_overhead_free(v1_node_allocatable_resource->overhead);
        v1_node_allocatable_resource->overhead = NULL;
    }
    free(v1_node_allocatable_resource);
}

cJSON *v1_node_allocatable_resource_convertToJSON(v1_node_allocatable_resource_t *v1_node_allocatable_resource) {
    cJSON *item = cJSON_CreateObject();

    // v1_node_allocatable_resource->mapping
    if(v1_node_allocatable_resource->mapping) {
    cJSON *mapping_local_JSON = v1_node_allocatable_mapping_convertToJSON(v1_node_allocatable_resource->mapping);
    if(mapping_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "mapping", mapping_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_node_allocatable_resource->overhead
    if(v1_node_allocatable_resource->overhead) {
    cJSON *overhead_local_JSON = v1_node_allocatable_overhead_convertToJSON(v1_node_allocatable_resource->overhead);
    if(overhead_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "overhead", overhead_local_JSON);
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

v1_node_allocatable_resource_t *v1_node_allocatable_resource_parseFromJSON(cJSON *v1_node_allocatable_resourceJSON){

    v1_node_allocatable_resource_t *v1_node_allocatable_resource_local_var = NULL;

    // define the local variable for v1_node_allocatable_resource->mapping
    v1_node_allocatable_mapping_t *mapping_local_nonprim = NULL;

    // define the local variable for v1_node_allocatable_resource->overhead
    v1_node_allocatable_overhead_t *overhead_local_nonprim = NULL;

    // v1_node_allocatable_resource->mapping
    cJSON *mapping = cJSON_GetObjectItemCaseSensitive(v1_node_allocatable_resourceJSON, "mapping");
    if (cJSON_IsNull(mapping)) {
        mapping = NULL;
    }
    if (mapping) { 
    mapping_local_nonprim = v1_node_allocatable_mapping_parseFromJSON(mapping); //nonprimitive
    }

    // v1_node_allocatable_resource->overhead
    cJSON *overhead = cJSON_GetObjectItemCaseSensitive(v1_node_allocatable_resourceJSON, "overhead");
    if (cJSON_IsNull(overhead)) {
        overhead = NULL;
    }
    if (overhead) { 
    overhead_local_nonprim = v1_node_allocatable_overhead_parseFromJSON(overhead); //nonprimitive
    }



    v1_node_allocatable_resource_local_var = v1_node_allocatable_resource_create_internal (
        mapping ? mapping_local_nonprim : NULL,
        overhead ? overhead_local_nonprim : NULL
        );

    if (!v1_node_allocatable_resource_local_var) {
        goto end;
    }

    return v1_node_allocatable_resource_local_var;
end:
    if (mapping_local_nonprim) {
        v1_node_allocatable_mapping_free(mapping_local_nonprim);
        mapping_local_nonprim = NULL;
    }
    if (overhead_local_nonprim) {
        v1_node_allocatable_overhead_free(overhead_local_nonprim);
        overhead_local_nonprim = NULL;
    }
    return NULL;

}
