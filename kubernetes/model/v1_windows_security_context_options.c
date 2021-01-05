#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_windows_security_context_options.h"



v1_windows_security_context_options_t *v1_windows_security_context_options_create(
    char *gmsa_credential_spec,
    char *gmsa_credential_spec_name,
    char *run_as_user_name
    ) {
    v1_windows_security_context_options_t *v1_windows_security_context_options_local_var = malloc(sizeof(v1_windows_security_context_options_t));
    if (!v1_windows_security_context_options_local_var) {
        return NULL;
    }
    v1_windows_security_context_options_local_var->gmsa_credential_spec = gmsa_credential_spec;
    v1_windows_security_context_options_local_var->gmsa_credential_spec_name = gmsa_credential_spec_name;
    v1_windows_security_context_options_local_var->run_as_user_name = run_as_user_name;

    return v1_windows_security_context_options_local_var;
}


void v1_windows_security_context_options_free(v1_windows_security_context_options_t *v1_windows_security_context_options) {
    if(NULL == v1_windows_security_context_options){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_windows_security_context_options->gmsa_credential_spec) {
        free(v1_windows_security_context_options->gmsa_credential_spec);
        v1_windows_security_context_options->gmsa_credential_spec = NULL;
    }
    if (v1_windows_security_context_options->gmsa_credential_spec_name) {
        free(v1_windows_security_context_options->gmsa_credential_spec_name);
        v1_windows_security_context_options->gmsa_credential_spec_name = NULL;
    }
    if (v1_windows_security_context_options->run_as_user_name) {
        free(v1_windows_security_context_options->run_as_user_name);
        v1_windows_security_context_options->run_as_user_name = NULL;
    }
    free(v1_windows_security_context_options);
}

cJSON *v1_windows_security_context_options_convertToJSON(v1_windows_security_context_options_t *v1_windows_security_context_options) {
    cJSON *item = cJSON_CreateObject();

    // v1_windows_security_context_options->gmsa_credential_spec
    if(v1_windows_security_context_options->gmsa_credential_spec) { 
    if(cJSON_AddStringToObject(item, "gmsaCredentialSpec", v1_windows_security_context_options->gmsa_credential_spec) == NULL) {
    goto fail; //String
    }
     } 


    // v1_windows_security_context_options->gmsa_credential_spec_name
    if(v1_windows_security_context_options->gmsa_credential_spec_name) { 
    if(cJSON_AddStringToObject(item, "gmsaCredentialSpecName", v1_windows_security_context_options->gmsa_credential_spec_name) == NULL) {
    goto fail; //String
    }
     } 


    // v1_windows_security_context_options->run_as_user_name
    if(v1_windows_security_context_options->run_as_user_name) { 
    if(cJSON_AddStringToObject(item, "runAsUserName", v1_windows_security_context_options->run_as_user_name) == NULL) {
    goto fail; //String
    }
     } 

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_windows_security_context_options_t *v1_windows_security_context_options_parseFromJSON(cJSON *v1_windows_security_context_optionsJSON){

    v1_windows_security_context_options_t *v1_windows_security_context_options_local_var = NULL;

    // v1_windows_security_context_options->gmsa_credential_spec
    cJSON *gmsa_credential_spec = cJSON_GetObjectItemCaseSensitive(v1_windows_security_context_optionsJSON, "gmsaCredentialSpec");
    if (gmsa_credential_spec) { 
    if(!cJSON_IsString(gmsa_credential_spec))
    {
    goto end; //String
    }
    }

    // v1_windows_security_context_options->gmsa_credential_spec_name
    cJSON *gmsa_credential_spec_name = cJSON_GetObjectItemCaseSensitive(v1_windows_security_context_optionsJSON, "gmsaCredentialSpecName");
    if (gmsa_credential_spec_name) { 
    if(!cJSON_IsString(gmsa_credential_spec_name))
    {
    goto end; //String
    }
    }

    // v1_windows_security_context_options->run_as_user_name
    cJSON *run_as_user_name = cJSON_GetObjectItemCaseSensitive(v1_windows_security_context_optionsJSON, "runAsUserName");
    if (run_as_user_name) { 
    if(!cJSON_IsString(run_as_user_name))
    {
    goto end; //String
    }
    }


    v1_windows_security_context_options_local_var = v1_windows_security_context_options_create (
        gmsa_credential_spec ? strdup(gmsa_credential_spec->valuestring) : NULL,
        gmsa_credential_spec_name ? strdup(gmsa_credential_spec_name->valuestring) : NULL,
        run_as_user_name ? strdup(run_as_user_name->valuestring) : NULL
        );

    return v1_windows_security_context_options_local_var;
end:
    return NULL;

}
