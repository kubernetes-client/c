#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_resource_health.h"



static v1_resource_health_t *v1_resource_health_create_internal(
    char *health,
    char *resource_id
    ) {
    v1_resource_health_t *v1_resource_health_local_var = malloc(sizeof(v1_resource_health_t));
    if (!v1_resource_health_local_var) {
        return NULL;
    }
    v1_resource_health_local_var->health = health;
    v1_resource_health_local_var->resource_id = resource_id;

    v1_resource_health_local_var->_library_owned = 1;
    return v1_resource_health_local_var;
}

__attribute__((deprecated)) v1_resource_health_t *v1_resource_health_create(
    char *health,
    char *resource_id
    ) {
    return v1_resource_health_create_internal (
        health,
        resource_id
        );
}

void v1_resource_health_free(v1_resource_health_t *v1_resource_health) {
    if(NULL == v1_resource_health){
        return ;
    }
    if(v1_resource_health->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_resource_health_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_resource_health->health) {
        free(v1_resource_health->health);
        v1_resource_health->health = NULL;
    }
    if (v1_resource_health->resource_id) {
        free(v1_resource_health->resource_id);
        v1_resource_health->resource_id = NULL;
    }
    free(v1_resource_health);
}

cJSON *v1_resource_health_convertToJSON(v1_resource_health_t *v1_resource_health) {
    cJSON *item = cJSON_CreateObject();

    // v1_resource_health->health
    if(v1_resource_health->health) {
    if(cJSON_AddStringToObject(item, "health", v1_resource_health->health) == NULL) {
    goto fail; //String
    }
    }


    // v1_resource_health->resource_id
    if (!v1_resource_health->resource_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "resourceID", v1_resource_health->resource_id) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_resource_health_t *v1_resource_health_parseFromJSON(cJSON *v1_resource_healthJSON){

    v1_resource_health_t *v1_resource_health_local_var = NULL;

    // v1_resource_health->health
    cJSON *health = cJSON_GetObjectItemCaseSensitive(v1_resource_healthJSON, "health");
    if (cJSON_IsNull(health)) {
        health = NULL;
    }
    if (health) { 
    if(!cJSON_IsString(health) && !cJSON_IsNull(health))
    {
    goto end; //String
    }
    }

    // v1_resource_health->resource_id
    cJSON *resource_id = cJSON_GetObjectItemCaseSensitive(v1_resource_healthJSON, "resourceID");
    if (cJSON_IsNull(resource_id)) {
        resource_id = NULL;
    }
    if (!resource_id) {
        goto end;
    }

    
    if(!cJSON_IsString(resource_id))
    {
    goto end; //String
    }


    v1_resource_health_local_var = v1_resource_health_create_internal (
        health && !cJSON_IsNull(health) ? strdup(health->valuestring) : NULL,
        strdup(resource_id->valuestring)
        );

    return v1_resource_health_local_var;
end:
    return NULL;

}
