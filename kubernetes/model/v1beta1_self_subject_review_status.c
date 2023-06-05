#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_self_subject_review_status.h"



v1beta1_self_subject_review_status_t *v1beta1_self_subject_review_status_create(
    v1_user_info_t *user_info
    ) {
    v1beta1_self_subject_review_status_t *v1beta1_self_subject_review_status_local_var = malloc(sizeof(v1beta1_self_subject_review_status_t));
    if (!v1beta1_self_subject_review_status_local_var) {
        return NULL;
    }
    v1beta1_self_subject_review_status_local_var->user_info = user_info;

    return v1beta1_self_subject_review_status_local_var;
}


void v1beta1_self_subject_review_status_free(v1beta1_self_subject_review_status_t *v1beta1_self_subject_review_status) {
    if(NULL == v1beta1_self_subject_review_status){
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta1_self_subject_review_status->user_info) {
        v1_user_info_free(v1beta1_self_subject_review_status->user_info);
        v1beta1_self_subject_review_status->user_info = NULL;
    }
    free(v1beta1_self_subject_review_status);
}

cJSON *v1beta1_self_subject_review_status_convertToJSON(v1beta1_self_subject_review_status_t *v1beta1_self_subject_review_status) {
    cJSON *item = cJSON_CreateObject();

    // v1beta1_self_subject_review_status->user_info
    if(v1beta1_self_subject_review_status->user_info) {
    cJSON *user_info_local_JSON = v1_user_info_convertToJSON(v1beta1_self_subject_review_status->user_info);
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

v1beta1_self_subject_review_status_t *v1beta1_self_subject_review_status_parseFromJSON(cJSON *v1beta1_self_subject_review_statusJSON){

    v1beta1_self_subject_review_status_t *v1beta1_self_subject_review_status_local_var = NULL;

    // define the local variable for v1beta1_self_subject_review_status->user_info
    v1_user_info_t *user_info_local_nonprim = NULL;

    // v1beta1_self_subject_review_status->user_info
    cJSON *user_info = cJSON_GetObjectItemCaseSensitive(v1beta1_self_subject_review_statusJSON, "userInfo");
    if (user_info) { 
    user_info_local_nonprim = v1_user_info_parseFromJSON(user_info); //nonprimitive
    }


    v1beta1_self_subject_review_status_local_var = v1beta1_self_subject_review_status_create (
        user_info ? user_info_local_nonprim : NULL
        );

    return v1beta1_self_subject_review_status_local_var;
end:
    if (user_info_local_nonprim) {
        v1_user_info_free(user_info_local_nonprim);
        user_info_local_nonprim = NULL;
    }
    return NULL;

}
