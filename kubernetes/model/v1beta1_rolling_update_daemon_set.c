#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_rolling_update_daemon_set.h"



v1beta1_rolling_update_daemon_set_t *v1beta1_rolling_update_daemon_set_create(
    object_t *max_unavailable
    ) {
    v1beta1_rolling_update_daemon_set_t *v1beta1_rolling_update_daemon_set_local_var = malloc(sizeof(v1beta1_rolling_update_daemon_set_t));
    if (!v1beta1_rolling_update_daemon_set_local_var) {
        return NULL;
    }
    v1beta1_rolling_update_daemon_set_local_var->max_unavailable = max_unavailable;

    return v1beta1_rolling_update_daemon_set_local_var;
}


void v1beta1_rolling_update_daemon_set_free(v1beta1_rolling_update_daemon_set_t *v1beta1_rolling_update_daemon_set) {
    if(NULL == v1beta1_rolling_update_daemon_set){
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta1_rolling_update_daemon_set->max_unavailable) {
        object_free(v1beta1_rolling_update_daemon_set->max_unavailable);
        v1beta1_rolling_update_daemon_set->max_unavailable = NULL;
    }
    free(v1beta1_rolling_update_daemon_set);
}

cJSON *v1beta1_rolling_update_daemon_set_convertToJSON(v1beta1_rolling_update_daemon_set_t *v1beta1_rolling_update_daemon_set) {
    cJSON *item = cJSON_CreateObject();

    // v1beta1_rolling_update_daemon_set->max_unavailable
    if(v1beta1_rolling_update_daemon_set->max_unavailable) { 
    cJSON *max_unavailable_object = object_convertToJSON(v1beta1_rolling_update_daemon_set->max_unavailable);
    if(max_unavailable_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "maxUnavailable", max_unavailable_object);
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

v1beta1_rolling_update_daemon_set_t *v1beta1_rolling_update_daemon_set_parseFromJSON(cJSON *v1beta1_rolling_update_daemon_setJSON){

    v1beta1_rolling_update_daemon_set_t *v1beta1_rolling_update_daemon_set_local_var = NULL;

    // v1beta1_rolling_update_daemon_set->max_unavailable
    cJSON *max_unavailable = cJSON_GetObjectItemCaseSensitive(v1beta1_rolling_update_daemon_setJSON, "maxUnavailable");
    object_t *max_unavailable_local_object = NULL;
    if (max_unavailable) { 
    max_unavailable_local_object = object_parseFromJSON(max_unavailable); //object
    }


    v1beta1_rolling_update_daemon_set_local_var = v1beta1_rolling_update_daemon_set_create (
        max_unavailable ? max_unavailable_local_object : NULL
        );

    return v1beta1_rolling_update_daemon_set_local_var;
end:
    return NULL;

}
