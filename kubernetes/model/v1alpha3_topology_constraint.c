#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha3_topology_constraint.h"



static v1alpha3_topology_constraint_t *v1alpha3_topology_constraint_create_internal(
    char *key
    ) {
    v1alpha3_topology_constraint_t *v1alpha3_topology_constraint_local_var = malloc(sizeof(v1alpha3_topology_constraint_t));
    if (!v1alpha3_topology_constraint_local_var) {
        return NULL;
    }
    memset(v1alpha3_topology_constraint_local_var, 0, sizeof(v1alpha3_topology_constraint_t));
    v1alpha3_topology_constraint_local_var->_library_owned = 1;
    v1alpha3_topology_constraint_local_var->key = key;
    return v1alpha3_topology_constraint_local_var;
}

__attribute__((deprecated)) v1alpha3_topology_constraint_t *v1alpha3_topology_constraint_create(
    char *key
    ) {
    v1alpha3_topology_constraint_t *result = v1alpha3_topology_constraint_create_internal (
        key
        );
    if (!result) {
    }
    return result;
}

void v1alpha3_topology_constraint_free(v1alpha3_topology_constraint_t *v1alpha3_topology_constraint) {
    if(NULL == v1alpha3_topology_constraint){
        return ;
    }
    if(v1alpha3_topology_constraint->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1alpha3_topology_constraint_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha3_topology_constraint->key) {
        free(v1alpha3_topology_constraint->key);
        v1alpha3_topology_constraint->key = NULL;
    }
    free(v1alpha3_topology_constraint);
}

cJSON *v1alpha3_topology_constraint_convertToJSON(v1alpha3_topology_constraint_t *v1alpha3_topology_constraint) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha3_topology_constraint->key
    if (!v1alpha3_topology_constraint->key) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "key", v1alpha3_topology_constraint->key) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1alpha3_topology_constraint_t *v1alpha3_topology_constraint_parseFromJSON(cJSON *v1alpha3_topology_constraintJSON){

    v1alpha3_topology_constraint_t *v1alpha3_topology_constraint_local_var = NULL;

    char *key_local_str = NULL;

    // v1alpha3_topology_constraint->key
    cJSON *key = cJSON_GetObjectItemCaseSensitive(v1alpha3_topology_constraintJSON, "key");
    if (cJSON_IsNull(key)) {
        key = NULL;
    }
    if (!key) {
        goto end;
    }

    
    if(!cJSON_IsString(key))
    {
    goto end; //String
    }


    if (key && !cJSON_IsNull(key)) key_local_str = strdup(key->valuestring);

    v1alpha3_topology_constraint_local_var = v1alpha3_topology_constraint_create_internal (
        key_local_str
        );

    if (!v1alpha3_topology_constraint_local_var) {
        goto end;
    }

    return v1alpha3_topology_constraint_local_var;
end:
    if (key_local_str) {
        free(key_local_str);
        key_local_str = NULL;
    }
    return NULL;

}
