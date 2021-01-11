#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_token_request_spec.h"



v1_token_request_spec_t *v1_token_request_spec_create(
    list_t *audiences,
    v1_bound_object_reference_t *bound_object_ref,
    long expiration_seconds
    ) {
    v1_token_request_spec_t *v1_token_request_spec_local_var = malloc(sizeof(v1_token_request_spec_t));
    if (!v1_token_request_spec_local_var) {
        return NULL;
    }
    v1_token_request_spec_local_var->audiences = audiences;
    v1_token_request_spec_local_var->bound_object_ref = bound_object_ref;
    v1_token_request_spec_local_var->expiration_seconds = expiration_seconds;

    return v1_token_request_spec_local_var;
}


void v1_token_request_spec_free(v1_token_request_spec_t *v1_token_request_spec) {
    if(NULL == v1_token_request_spec){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_token_request_spec->audiences) {
        list_ForEach(listEntry, v1_token_request_spec->audiences) {
            free(listEntry->data);
        }
        list_free(v1_token_request_spec->audiences);
        v1_token_request_spec->audiences = NULL;
    }
    if (v1_token_request_spec->bound_object_ref) {
        v1_bound_object_reference_free(v1_token_request_spec->bound_object_ref);
        v1_token_request_spec->bound_object_ref = NULL;
    }
    free(v1_token_request_spec);
}

cJSON *v1_token_request_spec_convertToJSON(v1_token_request_spec_t *v1_token_request_spec) {
    cJSON *item = cJSON_CreateObject();

    // v1_token_request_spec->audiences
    if (!v1_token_request_spec->audiences) {
        goto fail;
    }
    
    cJSON *audiences = cJSON_AddArrayToObject(item, "audiences");
    if(audiences == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *audiencesListEntry;
    list_ForEach(audiencesListEntry, v1_token_request_spec->audiences) {
    if(cJSON_AddStringToObject(audiences, "", (char*)audiencesListEntry->data) == NULL)
    {
        goto fail;
    }
    }


    // v1_token_request_spec->bound_object_ref
    if(v1_token_request_spec->bound_object_ref) { 
    cJSON *bound_object_ref_local_JSON = v1_bound_object_reference_convertToJSON(v1_token_request_spec->bound_object_ref);
    if(bound_object_ref_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "boundObjectRef", bound_object_ref_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1_token_request_spec->expiration_seconds
    if(v1_token_request_spec->expiration_seconds) { 
    if(cJSON_AddNumberToObject(item, "expirationSeconds", v1_token_request_spec->expiration_seconds) == NULL) {
    goto fail; //Numeric
    }
     } 

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_token_request_spec_t *v1_token_request_spec_parseFromJSON(cJSON *v1_token_request_specJSON){

    v1_token_request_spec_t *v1_token_request_spec_local_var = NULL;

    // v1_token_request_spec->audiences
    cJSON *audiences = cJSON_GetObjectItemCaseSensitive(v1_token_request_specJSON, "audiences");
    if (!audiences) {
        goto end;
    }

    list_t *audiencesList;
    
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

    // v1_token_request_spec->bound_object_ref
    cJSON *bound_object_ref = cJSON_GetObjectItemCaseSensitive(v1_token_request_specJSON, "boundObjectRef");
    v1_bound_object_reference_t *bound_object_ref_local_nonprim = NULL;
    if (bound_object_ref) { 
    bound_object_ref_local_nonprim = v1_bound_object_reference_parseFromJSON(bound_object_ref); //nonprimitive
    }

    // v1_token_request_spec->expiration_seconds
    cJSON *expiration_seconds = cJSON_GetObjectItemCaseSensitive(v1_token_request_specJSON, "expirationSeconds");
    if (expiration_seconds) { 
    if(!cJSON_IsNumber(expiration_seconds))
    {
    goto end; //Numeric
    }
    }


    v1_token_request_spec_local_var = v1_token_request_spec_create (
        audiencesList,
        bound_object_ref ? bound_object_ref_local_nonprim : NULL,
        expiration_seconds ? expiration_seconds->valuedouble : 0
        );

    return v1_token_request_spec_local_var;
end:
    if (bound_object_ref_local_nonprim) {
        v1_bound_object_reference_free(bound_object_ref_local_nonprim);
        bound_object_ref_local_nonprim = NULL;
    }
    return NULL;

}
