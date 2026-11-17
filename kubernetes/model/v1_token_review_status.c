#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_token_review_status.h"



static v1_token_review_status_t *v1_token_review_status_create_internal(
    list_t *audiences,
    int *authenticated,
    char *error,
    v1_user_info_t *user
    ) {
    v1_token_review_status_t *v1_token_review_status_local_var = malloc(sizeof(v1_token_review_status_t));
    if (!v1_token_review_status_local_var) {
        return NULL;
    }
    memset(v1_token_review_status_local_var, 0, sizeof(v1_token_review_status_t));
    v1_token_review_status_local_var->_library_owned = 1;
    v1_token_review_status_local_var->audiences = audiences;
    v1_token_review_status_local_var->authenticated = authenticated;
    v1_token_review_status_local_var->error = error;
    v1_token_review_status_local_var->user = user;
    return v1_token_review_status_local_var;
}

__attribute__((deprecated)) v1_token_review_status_t *v1_token_review_status_create(
    list_t *audiences,
    int *authenticated,
    char *error,
    v1_user_info_t *user
    ) {
    int *authenticated_copy = NULL;
    if (authenticated) {
        authenticated_copy = malloc(sizeof(int));
        if (authenticated_copy) *authenticated_copy = *authenticated;
    }
    v1_token_review_status_t *result = v1_token_review_status_create_internal (
        audiences,
        authenticated_copy,
        error,
        user
        );
    if (!result) {
        free(authenticated_copy);
    }
    return result;
}

void v1_token_review_status_free(v1_token_review_status_t *v1_token_review_status) {
    if(NULL == v1_token_review_status){
        return ;
    }
    if(v1_token_review_status->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_token_review_status_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_token_review_status->audiences) {
        list_ForEach(listEntry, v1_token_review_status->audiences) {
            free(listEntry->data);
        }
        list_freeList(v1_token_review_status->audiences);
        v1_token_review_status->audiences = NULL;
    }
    if (v1_token_review_status->authenticated) {
        free(v1_token_review_status->authenticated);
        v1_token_review_status->authenticated = NULL;
    }
    if (v1_token_review_status->error) {
        free(v1_token_review_status->error);
        v1_token_review_status->error = NULL;
    }
    if (v1_token_review_status->user) {
        v1_user_info_free(v1_token_review_status->user);
        v1_token_review_status->user = NULL;
    }
    free(v1_token_review_status);
}

cJSON *v1_token_review_status_convertToJSON(v1_token_review_status_t *v1_token_review_status) {
    cJSON *item = cJSON_CreateObject();

    // v1_token_review_status->audiences
    if(v1_token_review_status->audiences) {
    cJSON *audiences = cJSON_AddArrayToObject(item, "audiences");
    if(audiences == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *audiencesListEntry;
    list_ForEach(audiencesListEntry, v1_token_review_status->audiences) {
    if(cJSON_AddStringToObject(audiences, "", audiencesListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // v1_token_review_status->authenticated
    if(v1_token_review_status->authenticated) {
    if(cJSON_AddBoolToObject(item, "authenticated", *v1_token_review_status->authenticated) == NULL) {
    goto fail; //Bool
    }
    }


    // v1_token_review_status->error
    if(v1_token_review_status->error) {
    if(cJSON_AddStringToObject(item, "error", v1_token_review_status->error) == NULL) {
    goto fail; //String
    }
    }


    // v1_token_review_status->user
    if(v1_token_review_status->user) {
    cJSON *user_local_JSON = v1_user_info_convertToJSON(v1_token_review_status->user);
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

v1_token_review_status_t *v1_token_review_status_parseFromJSON(cJSON *v1_token_review_statusJSON){

    v1_token_review_status_t *v1_token_review_status_local_var = NULL;

    // define the local list for v1_token_review_status->audiences
    list_t *audiencesList = NULL;

    // define the local variable for v1_token_review_status->authenticated
    int *authenticated_local_var = NULL;

    char *error_local_str = NULL;

    // define the local variable for v1_token_review_status->user
    v1_user_info_t *user_local_nonprim = NULL;

    // v1_token_review_status->audiences
    cJSON *audiences = cJSON_GetObjectItemCaseSensitive(v1_token_review_statusJSON, "audiences");
    if (cJSON_IsNull(audiences)) {
        audiences = NULL;
    }
    if (audiences) { 
    cJSON *audiences_local = NULL;
    if(!cJSON_IsArray(audiences)) {
        goto end;//primitive container
    }
    audiencesList = list_createList();

    cJSON_ArrayForEach(audiences_local, audiences)
    {
        if(!cJSON_IsString(audiences_local))
        {
            goto end;
        }
        list_addElement(audiencesList , strdup(audiences_local->valuestring));
    }
    }

    // v1_token_review_status->authenticated
    cJSON *authenticated = cJSON_GetObjectItemCaseSensitive(v1_token_review_statusJSON, "authenticated");
    if (cJSON_IsNull(authenticated)) {
        authenticated = NULL;
    }
    if (authenticated) { 
    if(!cJSON_IsBool(authenticated))
    {
    goto end; //Bool
    }
    authenticated_local_var = malloc(sizeof(int));
    if(!authenticated_local_var)
    {
        goto end;
    }
    *authenticated_local_var = authenticated->valueint;
    }

    // v1_token_review_status->error
    cJSON *error = cJSON_GetObjectItemCaseSensitive(v1_token_review_statusJSON, "error");
    if (cJSON_IsNull(error)) {
        error = NULL;
    }
    if (error) { 
    if(!cJSON_IsString(error) && !cJSON_IsNull(error))
    {
    goto end; //String
    }
    }

    // v1_token_review_status->user
    cJSON *user = cJSON_GetObjectItemCaseSensitive(v1_token_review_statusJSON, "user");
    if (cJSON_IsNull(user)) {
        user = NULL;
    }
    if (user) { 
    user_local_nonprim = v1_user_info_parseFromJSON(user); //nonprimitive
    }


    if (error && !cJSON_IsNull(error)) error_local_str = strdup(error->valuestring);

    v1_token_review_status_local_var = v1_token_review_status_create_internal (
        audiences ? audiencesList : NULL,
        authenticated_local_var,
        error_local_str,
        user ? user_local_nonprim : NULL
        );

    if (!v1_token_review_status_local_var) {
        goto end;
    }

    return v1_token_review_status_local_var;
end:
    if (audiencesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, audiencesList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(audiencesList);
        audiencesList = NULL;
    }
    if (authenticated_local_var) {
        free(authenticated_local_var);
        authenticated_local_var = NULL;
    }
    if (error_local_str) {
        free(error_local_str);
        error_local_str = NULL;
    }
    if (user_local_nonprim) {
        v1_user_info_free(user_local_nonprim);
        user_local_nonprim = NULL;
    }
    return NULL;

}
