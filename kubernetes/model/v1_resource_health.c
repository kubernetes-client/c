#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_resource_health.h"



static v1_resource_health_t *v1_resource_health_create_internal(
    char *health,
    char *message,
    char *resource_id
    ) {
    v1_resource_health_t *v1_resource_health_local_var = malloc(sizeof(v1_resource_health_t));
    if (!v1_resource_health_local_var) {
        return NULL;
    }
    memset(v1_resource_health_local_var, 0, sizeof(v1_resource_health_t));
    v1_resource_health_local_var->_library_owned = 1;
    v1_resource_health_local_var->health = health;
    v1_resource_health_local_var->message = message;
    v1_resource_health_local_var->resource_id = resource_id;
    return v1_resource_health_local_var;
}

__attribute__((deprecated)) v1_resource_health_t *v1_resource_health_create(
    char *health,
    char *message,
    char *resource_id
    ) {
    v1_resource_health_t *result = v1_resource_health_create_internal (
        health,
        message,
        resource_id
        );
    if (!result) {
    }
    return result;
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
    if (v1_resource_health->message) {
        free(v1_resource_health->message);
        v1_resource_health->message = NULL;
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


    // v1_resource_health->message
    if(v1_resource_health->message) {
    if(cJSON_AddStringToObject(item, "message", v1_resource_health->message) == NULL) {
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

    char *health_local_str = NULL;

    char *message_local_str = NULL;

    char *resource_id_local_str = NULL;

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

    // v1_resource_health->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(v1_resource_healthJSON, "message");
    if (cJSON_IsNull(message)) {
        message = NULL;
    }
    if (message) { 
    if(!cJSON_IsString(message) && !cJSON_IsNull(message))
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


    if (health && !cJSON_IsNull(health)) health_local_str = strdup(health->valuestring);
    if (message && !cJSON_IsNull(message)) message_local_str = strdup(message->valuestring);
    if (resource_id && !cJSON_IsNull(resource_id)) resource_id_local_str = strdup(resource_id->valuestring);

    v1_resource_health_local_var = v1_resource_health_create_internal (
        health_local_str,
        message_local_str,
        resource_id_local_str
        );

    if (!v1_resource_health_local_var) {
        goto end;
    }

    return v1_resource_health_local_var;
end:
    if (health_local_str) {
        free(health_local_str);
        health_local_str = NULL;
    }
    if (message_local_str) {
        free(message_local_str);
        message_local_str = NULL;
    }
    if (resource_id_local_str) {
        free(resource_id_local_str);
        resource_id_local_str = NULL;
    }
    return NULL;

}
