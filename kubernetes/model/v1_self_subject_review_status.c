#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_self_subject_review_status.h"



v1_self_subject_review_status_t *v1_self_subject_review_status_create(
    v1_user_info_t *user_info
    ) {
    v1_self_subject_review_status_t *v1_self_subject_review_status_local_var = malloc(sizeof(v1_self_subject_review_status_t));
    if (!v1_self_subject_review_status_local_var) {
        return NULL;
    }
    v1_self_subject_review_status_local_var->user_info = user_info;

    return v1_self_subject_review_status_local_var;
}


void v1_self_subject_review_status_free(v1_self_subject_review_status_t *v1_self_subject_review_status) {
    if(NULL == v1_self_subject_review_status){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_self_subject_review_status->user_info) {
        v1_user_info_free(v1_self_subject_review_status->user_info);
        v1_self_subject_review_status->user_info = NULL;
    }
    free(v1_self_subject_review_status);
}

cJSON *v1_self_subject_review_status_convertToJSON(v1_self_subject_review_status_t *v1_self_subject_review_status) {
    cJSON *item = cJSON_CreateObject();

    // v1_self_subject_review_status->user_info
    if(v1_self_subject_review_status->user_info) {
    cJSON *user_info_local_JSON = v1_user_info_convertToJSON(v1_self_subject_review_status->user_info);
    if(user_info_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "userInfo", user_info_local_JSON);
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

v1_self_subject_review_status_t *v1_self_subject_review_status_parseFromJSON(cJSON *v1_self_subject_review_statusJSON){

    v1_self_subject_review_status_t *v1_self_subject_review_status_local_var = NULL;

    // define the local variable for v1_self_subject_review_status->user_info
    v1_user_info_t *user_info_local_nonprim = NULL;

    // v1_self_subject_review_status->user_info
    cJSON *user_info = cJSON_GetObjectItemCaseSensitive(v1_self_subject_review_statusJSON, "userInfo");
    if (user_info) { 
    user_info_local_nonprim = v1_user_info_parseFromJSON(user_info); //nonprimitive
    }


    v1_self_subject_review_status_local_var = v1_self_subject_review_status_create (
        user_info ? user_info_local_nonprim : NULL
        );

    return v1_self_subject_review_status_local_var;
end:
    if (user_info_local_nonprim) {
        v1_user_info_free(user_info_local_nonprim);
        user_info_local_nonprim = NULL;
    }
    return NULL;

}
