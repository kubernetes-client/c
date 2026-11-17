#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_token_request_spec.h"



static v1_token_request_spec_t *v1_token_request_spec_create_internal(
    list_t* attestations,
    list_t *audiences,
    v1_bound_object_reference_t *bound_object_ref,
    long *expiration_seconds
    ) {
    v1_token_request_spec_t *v1_token_request_spec_local_var = malloc(sizeof(v1_token_request_spec_t));
    if (!v1_token_request_spec_local_var) {
        return NULL;
    }
    memset(v1_token_request_spec_local_var, 0, sizeof(v1_token_request_spec_t));
    v1_token_request_spec_local_var->_library_owned = 1;
    v1_token_request_spec_local_var->attestations = attestations;
    v1_token_request_spec_local_var->audiences = audiences;
    v1_token_request_spec_local_var->bound_object_ref = bound_object_ref;
    v1_token_request_spec_local_var->expiration_seconds = expiration_seconds;
    return v1_token_request_spec_local_var;
}

__attribute__((deprecated)) v1_token_request_spec_t *v1_token_request_spec_create(
    list_t* attestations,
    list_t *audiences,
    v1_bound_object_reference_t *bound_object_ref,
    long *expiration_seconds
    ) {
    long *expiration_seconds_copy = NULL;
    if (expiration_seconds) {
        expiration_seconds_copy = malloc(sizeof(long));
        if (expiration_seconds_copy) *expiration_seconds_copy = *expiration_seconds;
    }
    v1_token_request_spec_t *result = v1_token_request_spec_create_internal (
        attestations,
        audiences,
        bound_object_ref,
        expiration_seconds_copy
        );
    if (!result) {
        free(expiration_seconds_copy);
    }
    return result;
}

void v1_token_request_spec_free(v1_token_request_spec_t *v1_token_request_spec) {
    if(NULL == v1_token_request_spec){
        return ;
    }
    if(v1_token_request_spec->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_token_request_spec_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_token_request_spec->attestations) {
        list_ForEach(listEntry, v1_token_request_spec->attestations) {
            keyValuePair_t *localKeyValue = listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_freeList(v1_token_request_spec->attestations);
        v1_token_request_spec->attestations = NULL;
    }
    if (v1_token_request_spec->audiences) {
        list_ForEach(listEntry, v1_token_request_spec->audiences) {
            free(listEntry->data);
        }
        list_freeList(v1_token_request_spec->audiences);
        v1_token_request_spec->audiences = NULL;
    }
    if (v1_token_request_spec->bound_object_ref) {
        v1_bound_object_reference_free(v1_token_request_spec->bound_object_ref);
        v1_token_request_spec->bound_object_ref = NULL;
    }
    if (v1_token_request_spec->expiration_seconds) {
        free(v1_token_request_spec->expiration_seconds);
        v1_token_request_spec->expiration_seconds = NULL;
    }
    free(v1_token_request_spec);
}

cJSON *v1_token_request_spec_convertToJSON(v1_token_request_spec_t *v1_token_request_spec) {
    cJSON *item = cJSON_CreateObject();

    // v1_token_request_spec->attestations
    if(v1_token_request_spec->attestations) {
    cJSON *attestations = cJSON_AddObjectToObject(item, "attestations");
    if(attestations == NULL) {
        goto fail; //primitive map container
    }
    cJSON *localMapObject = attestations;
    listEntry_t *attestationsListEntry;
    if (v1_token_request_spec->attestations) {
    list_ForEach(attestationsListEntry, v1_token_request_spec->attestations) {
        keyValuePair_t *localKeyValue = attestationsListEntry->data;
    }
    }
    }


    // v1_token_request_spec->audiences
    if(v1_token_request_spec->audiences) {
    cJSON *audiences = cJSON_AddArrayToObject(item, "audiences");
    if(audiences == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *audiencesListEntry;
    list_ForEach(audiencesListEntry, v1_token_request_spec->audiences) {
    if(cJSON_AddStringToObject(audiences, "", audiencesListEntry->data) == NULL)
    {
        goto fail;
    }
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
    if(cJSON_AddNumberToObject(item, "expirationSeconds", *v1_token_request_spec->expiration_seconds) == NULL) {
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

    // define the local map for v1_token_request_spec->attestations
    list_t *attestationsList = NULL;

    // define the local list for v1_token_request_spec->audiences
    list_t *audiencesList = NULL;

    // define the local variable for v1_token_request_spec->bound_object_ref
    v1_bound_object_reference_t *bound_object_ref_local_nonprim = NULL;

    // define the local variable for v1_token_request_spec->expiration_seconds
    long *expiration_seconds_local_var = NULL;

    // v1_token_request_spec->attestations
    cJSON *attestations = cJSON_GetObjectItemCaseSensitive(v1_token_request_specJSON, "attestations");
    if (cJSON_IsNull(attestations)) {
        attestations = NULL;
    }
    if (attestations) { 
    cJSON *attestations_local_map = NULL;
    if(!cJSON_IsObject(attestations) && !cJSON_IsNull(attestations))
    {
        goto end;//primitive map container
    }
    if(cJSON_IsObject(attestations))
    {
        attestationsList = list_createList();
        keyValuePair_t *localMapKeyPair;
        cJSON_ArrayForEach(attestations_local_map, attestations)
        {
            cJSON *localMapObject = attestations_local_map;
            list_addElement(attestationsList , localMapKeyPair);
        }
    }
    }

    // v1_token_request_spec->audiences
    cJSON *audiences = cJSON_GetObjectItemCaseSensitive(v1_token_request_specJSON, "audiences");
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

    // v1_token_request_spec->bound_object_ref
    cJSON *bound_object_ref = cJSON_GetObjectItemCaseSensitive(v1_token_request_specJSON, "boundObjectRef");
    if (cJSON_IsNull(bound_object_ref)) {
        bound_object_ref = NULL;
    }
    if (bound_object_ref) { 
    bound_object_ref_local_nonprim = v1_bound_object_reference_parseFromJSON(bound_object_ref); //nonprimitive
    }

    // v1_token_request_spec->expiration_seconds
    cJSON *expiration_seconds = cJSON_GetObjectItemCaseSensitive(v1_token_request_specJSON, "expirationSeconds");
    if (cJSON_IsNull(expiration_seconds)) {
        expiration_seconds = NULL;
    }
    if (expiration_seconds) { 
    if(!cJSON_IsNumber(expiration_seconds))
    {
    goto end; //Numeric
    }
    expiration_seconds_local_var = malloc(sizeof(long));
    if(!expiration_seconds_local_var)
    {
        goto end;
    }
    *expiration_seconds_local_var = expiration_seconds->valuedouble;
    }



    v1_token_request_spec_local_var = v1_token_request_spec_create_internal (
        attestations ? attestationsList : NULL,
        audiences ? audiencesList : NULL,
        bound_object_ref ? bound_object_ref_local_nonprim : NULL,
        expiration_seconds_local_var
        );

    if (!v1_token_request_spec_local_var) {
        goto end;
    }

    return v1_token_request_spec_local_var;
end:
    if (attestationsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, attestationsList) {
            keyValuePair_t *localKeyValue = listEntry->data;
            free(localKeyValue->key);
            localKeyValue->key = NULL;
            keyValuePair_free(localKeyValue);
            localKeyValue = NULL;
        }
        list_freeList(attestationsList);
        attestationsList = NULL;
    }
    if (audiencesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, audiencesList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(audiencesList);
        audiencesList = NULL;
    }
    if (bound_object_ref_local_nonprim) {
        v1_bound_object_reference_free(bound_object_ref_local_nonprim);
        bound_object_ref_local_nonprim = NULL;
    }
    if (expiration_seconds_local_var) {
        free(expiration_seconds_local_var);
        expiration_seconds_local_var = NULL;
    }
    return NULL;

}
