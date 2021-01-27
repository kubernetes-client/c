#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_token_review_status.h"



v1beta1_token_review_status_t *v1beta1_token_review_status_create(
    list_t *audiences,
    int authenticated,
    char *error,
    v1beta1_user_info_t *user
    ) {
    v1beta1_token_review_status_t *v1beta1_token_review_status_local_var = malloc(sizeof(v1beta1_token_review_status_t));
    if (!v1beta1_token_review_status_local_var) {
        return NULL;
    }
    v1beta1_token_review_status_local_var->audiences = audiences;
    v1beta1_token_review_status_local_var->authenticated = authenticated;
    v1beta1_token_review_status_local_var->error = error;
    v1beta1_token_review_status_local_var->user = user;

    return v1beta1_token_review_status_local_var;
}


void v1beta1_token_review_status_free(v1beta1_token_review_status_t *v1beta1_token_review_status) {
    if(NULL == v1beta1_token_review_status){
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta1_token_review_status->audiences) {
        list_ForEach(listEntry, v1beta1_token_review_status->audiences) {
            free(listEntry->data);
        }
        list_free(v1beta1_token_review_status->audiences);
        v1beta1_token_review_status->audiences = NULL;
    }
    if (v1beta1_token_review_status->error) {
        free(v1beta1_token_review_status->error);
        v1beta1_token_review_status->error = NULL;
    }
    if (v1beta1_token_review_status->user) {
        v1beta1_user_info_free(v1beta1_token_review_status->user);
        v1beta1_token_review_status->user = NULL;
    }
    free(v1beta1_token_review_status);
}

cJSON *v1beta1_token_review_status_convertToJSON(v1beta1_token_review_status_t *v1beta1_token_review_status) {
    cJSON *item = cJSON_CreateObject();

    // v1beta1_token_review_status->audiences
    if(v1beta1_token_review_status->audiences) { 
    cJSON *audiences = cJSON_AddArrayToObject(item, "audiences");
    if(audiences == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *audiencesListEntry;
    list_ForEach(audiencesListEntry, v1beta1_token_review_status->audiences) {
    if(cJSON_AddStringToObject(audiences, "", (char*)audiencesListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 


    // v1beta1_token_review_status->authenticated
    if(v1beta1_token_review_status->authenticated) { 
    if(cJSON_AddBoolToObject(item, "authenticated", v1beta1_token_review_status->authenticated) == NULL) {
    goto fail; //Bool
    }
     } 


    // v1beta1_token_review_status->error
    if(v1beta1_token_review_status->error) { 
    if(cJSON_AddStringToObject(item, "error", v1beta1_token_review_status->error) == NULL) {
    goto fail; //String
    }
     } 


    // v1beta1_token_review_status->user
    if(v1beta1_token_review_status->user) { 
    cJSON *user_local_JSON = v1beta1_user_info_convertToJSON(v1beta1_token_review_status->user);
    if(user_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "user", user_local_JSON);
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

v1beta1_token_review_status_t *v1beta1_token_review_status_parseFromJSON(cJSON *v1beta1_token_review_statusJSON){

    v1beta1_token_review_status_t *v1beta1_token_review_status_local_var = NULL;

    // v1beta1_token_review_status->audiences
    cJSON *audiences = cJSON_GetObjectItemCaseSensitive(v1beta1_token_review_statusJSON, "audiences");
    list_t *audiencesList;
    if (audiences) { 
    cJSON *audiences_local;
    if(!cJSON_IsArray(audiences)) {
        goto end;//primitive container
    }
    audiencesList = list_create();

    cJSON_ArrayForEach(audiences_local, audiences)
    {
        if(!cJSON_IsString(audiences_local))
        {
            goto end;
        }
        list_addElement(audiencesList , strdup(audiences_local->valuestring));
    }
    }

    // v1beta1_token_review_status->authenticated
    cJSON *authenticated = cJSON_GetObjectItemCaseSensitive(v1beta1_token_review_statusJSON, "authenticated");
    if (authenticated) { 
    if(!cJSON_IsBool(authenticated))
    {
    goto end; //Bool
    }
    }

    // v1beta1_token_review_status->error
    cJSON *error = cJSON_GetObjectItemCaseSensitive(v1beta1_token_review_statusJSON, "error");
    if (error) { 
    if(!cJSON_IsString(error))
    {
    goto end; //String
    }
    }

    // v1beta1_token_review_status->user
    cJSON *user = cJSON_GetObjectItemCaseSensitive(v1beta1_token_review_statusJSON, "user");
    v1beta1_user_info_t *user_local_nonprim = NULL;
    if (user) { 
    user_local_nonprim = v1beta1_user_info_parseFromJSON(user); //nonprimitive
    }


    v1beta1_token_review_status_local_var = v1beta1_token_review_status_create (
        audiences ? audiencesList : NULL,
        authenticated ? authenticated->valueint : 0,
        error ? strdup(error->valuestring) : NULL,
        user ? user_local_nonprim : NULL
        );

    return v1beta1_token_review_status_local_var;
end:
    if (user_local_nonprim) {
        v1beta1_user_info_free(user_local_nonprim);
        user_local_nonprim = NULL;
    }
    return NULL;

}
