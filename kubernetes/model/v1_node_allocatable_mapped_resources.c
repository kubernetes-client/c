#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_node_allocatable_mapped_resources.h"



static v1_node_allocatable_mapped_resources_t *v1_node_allocatable_mapped_resources_create_internal(
    char *name,
    char *quantity
    ) {
    v1_node_allocatable_mapped_resources_t *v1_node_allocatable_mapped_resources_local_var = malloc(sizeof(v1_node_allocatable_mapped_resources_t));
    if (!v1_node_allocatable_mapped_resources_local_var) {
        return NULL;
    }
    memset(v1_node_allocatable_mapped_resources_local_var, 0, sizeof(v1_node_allocatable_mapped_resources_t));
    v1_node_allocatable_mapped_resources_local_var->_library_owned = 1;
    v1_node_allocatable_mapped_resources_local_var->name = name;
    v1_node_allocatable_mapped_resources_local_var->quantity = quantity;
    return v1_node_allocatable_mapped_resources_local_var;
}

__attribute__((deprecated)) v1_node_allocatable_mapped_resources_t *v1_node_allocatable_mapped_resources_create(
    char *name,
    char *quantity
    ) {
    v1_node_allocatable_mapped_resources_t *result = v1_node_allocatable_mapped_resources_create_internal (
        name,
        quantity
        );
    if (!result) {
    }
    return result;
}

void v1_node_allocatable_mapped_resources_free(v1_node_allocatable_mapped_resources_t *v1_node_allocatable_mapped_resources) {
    if(NULL == v1_node_allocatable_mapped_resources){
        return ;
    }
    if(v1_node_allocatable_mapped_resources->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_node_allocatable_mapped_resources_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_node_allocatable_mapped_resources->name) {
        free(v1_node_allocatable_mapped_resources->name);
        v1_node_allocatable_mapped_resources->name = NULL;
    }
    if (v1_node_allocatable_mapped_resources->quantity) {
        free(v1_node_allocatable_mapped_resources->quantity);
        v1_node_allocatable_mapped_resources->quantity = NULL;
    }
    free(v1_node_allocatable_mapped_resources);
}

cJSON *v1_node_allocatable_mapped_resources_convertToJSON(v1_node_allocatable_mapped_resources_t *v1_node_allocatable_mapped_resources) {
    cJSON *item = cJSON_CreateObject();

    // v1_node_allocatable_mapped_resources->name
    if (!v1_node_allocatable_mapped_resources->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", v1_node_allocatable_mapped_resources->name) == NULL) {
    goto fail; //String
    }


    // v1_node_allocatable_mapped_resources->quantity
    if (!v1_node_allocatable_mapped_resources->quantity) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "quantity", v1_node_allocatable_mapped_resources->quantity) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_node_allocatable_mapped_resources_t *v1_node_allocatable_mapped_resources_parseFromJSON(cJSON *v1_node_allocatable_mapped_resourcesJSON){

    v1_node_allocatable_mapped_resources_t *v1_node_allocatable_mapped_resources_local_var = NULL;

    char *name_local_str = NULL;

    char *quantity_local_str = NULL;

    // v1_node_allocatable_mapped_resources->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1_node_allocatable_mapped_resourcesJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // v1_node_allocatable_mapped_resources->quantity
    cJSON *quantity = cJSON_GetObjectItemCaseSensitive(v1_node_allocatable_mapped_resourcesJSON, "quantity");
    if (cJSON_IsNull(quantity)) {
        quantity = NULL;
    }
    if (!quantity) {
        goto end;
    }

    
    if(!cJSON_IsString(quantity))
    {
    goto end; //String
    }


    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);
    if (quantity && !cJSON_IsNull(quantity)) quantity_local_str = strdup(quantity->valuestring);

    v1_node_allocatable_mapped_resources_local_var = v1_node_allocatable_mapped_resources_create_internal (
        name_local_str,
        quantity_local_str
        );

    if (!v1_node_allocatable_mapped_resources_local_var) {
        goto end;
    }

    return v1_node_allocatable_mapped_resources_local_var;
end:
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    if (quantity_local_str) {
        free(quantity_local_str);
        quantity_local_str = NULL;
    }
    return NULL;

}
