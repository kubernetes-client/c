#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_node_config_status.h"



v1_node_config_status_t *v1_node_config_status_create(
    v1_node_config_source_t *active,
    v1_node_config_source_t *assigned,
    char *error,
    v1_node_config_source_t *last_known_good
    ) {
    v1_node_config_status_t *v1_node_config_status_local_var = malloc(sizeof(v1_node_config_status_t));
    if (!v1_node_config_status_local_var) {
        return NULL;
    }
    v1_node_config_status_local_var->active = active;
    v1_node_config_status_local_var->assigned = assigned;
    v1_node_config_status_local_var->error = error;
    v1_node_config_status_local_var->last_known_good = last_known_good;

    return v1_node_config_status_local_var;
}


void v1_node_config_status_free(v1_node_config_status_t *v1_node_config_status) {
    if(NULL == v1_node_config_status){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_node_config_status->active) {
        v1_node_config_source_free(v1_node_config_status->active);
        v1_node_config_status->active = NULL;
    }
    if (v1_node_config_status->assigned) {
        v1_node_config_source_free(v1_node_config_status->assigned);
        v1_node_config_status->assigned = NULL;
    }
    if (v1_node_config_status->error) {
        free(v1_node_config_status->error);
        v1_node_config_status->error = NULL;
    }
    if (v1_node_config_status->last_known_good) {
        v1_node_config_source_free(v1_node_config_status->last_known_good);
        v1_node_config_status->last_known_good = NULL;
    }
    free(v1_node_config_status);
}

cJSON *v1_node_config_status_convertToJSON(v1_node_config_status_t *v1_node_config_status) {
    cJSON *item = cJSON_CreateObject();

    // v1_node_config_status->active
    if(v1_node_config_status->active) { 
    cJSON *active_local_JSON = v1_node_config_source_convertToJSON(v1_node_config_status->active);
    if(active_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "active", active_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1_node_config_status->assigned
    if(v1_node_config_status->assigned) { 
    cJSON *assigned_local_JSON = v1_node_config_source_convertToJSON(v1_node_config_status->assigned);
    if(assigned_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "assigned", assigned_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1_node_config_status->error
    if(v1_node_config_status->error) { 
    if(cJSON_AddStringToObject(item, "error", v1_node_config_status->error) == NULL) {
    goto fail; //String
    }
     } 


    // v1_node_config_status->last_known_good
    if(v1_node_config_status->last_known_good) { 
    cJSON *last_known_good_local_JSON = v1_node_config_source_convertToJSON(v1_node_config_status->last_known_good);
    if(last_known_good_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "lastKnownGood", last_known_good_local_JSON);
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

v1_node_config_status_t *v1_node_config_status_parseFromJSON(cJSON *v1_node_config_statusJSON){

    v1_node_config_status_t *v1_node_config_status_local_var = NULL;

    // v1_node_config_status->active
    cJSON *active = cJSON_GetObjectItemCaseSensitive(v1_node_config_statusJSON, "active");
    v1_node_config_source_t *active_local_nonprim = NULL;
    if (active) { 
    active_local_nonprim = v1_node_config_source_parseFromJSON(active); //nonprimitive
    }

    // v1_node_config_status->assigned
    cJSON *assigned = cJSON_GetObjectItemCaseSensitive(v1_node_config_statusJSON, "assigned");
    v1_node_config_source_t *assigned_local_nonprim = NULL;
    if (assigned) { 
    assigned_local_nonprim = v1_node_config_source_parseFromJSON(assigned); //nonprimitive
    }

    // v1_node_config_status->error
    cJSON *error = cJSON_GetObjectItemCaseSensitive(v1_node_config_statusJSON, "error");
    if (error) { 
    if(!cJSON_IsString(error))
    {
    goto end; //String
    }
    }

    // v1_node_config_status->last_known_good
    cJSON *last_known_good = cJSON_GetObjectItemCaseSensitive(v1_node_config_statusJSON, "lastKnownGood");
    v1_node_config_source_t *last_known_good_local_nonprim = NULL;
    if (last_known_good) { 
    last_known_good_local_nonprim = v1_node_config_source_parseFromJSON(last_known_good); //nonprimitive
    }


    v1_node_config_status_local_var = v1_node_config_status_create (
        active ? active_local_nonprim : NULL,
        assigned ? assigned_local_nonprim : NULL,
        error ? strdup(error->valuestring) : NULL,
        last_known_good ? last_known_good_local_nonprim : NULL
        );

    return v1_node_config_status_local_var;
end:
    if (active_local_nonprim) {
        v1_node_config_source_free(active_local_nonprim);
        active_local_nonprim = NULL;
    }
    if (assigned_local_nonprim) {
        v1_node_config_source_free(assigned_local_nonprim);
        assigned_local_nonprim = NULL;
    }
    if (last_known_good_local_nonprim) {
        v1_node_config_source_free(last_known_good_local_nonprim);
        last_known_good_local_nonprim = NULL;
    }
    return NULL;

}
