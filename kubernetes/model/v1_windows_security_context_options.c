#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_windows_security_context_options.h"



static v1_windows_security_context_options_t *v1_windows_security_context_options_create_internal(
    char *gmsa_credential_spec,
    char *gmsa_credential_spec_name,
    int *host_process,
    char *run_as_user_name
    ) {
    v1_windows_security_context_options_t *v1_windows_security_context_options_local_var = malloc(sizeof(v1_windows_security_context_options_t));
    if (!v1_windows_security_context_options_local_var) {
        return NULL;
    }
    memset(v1_windows_security_context_options_local_var, 0, sizeof(v1_windows_security_context_options_t));
    v1_windows_security_context_options_local_var->_library_owned = 1;
    v1_windows_security_context_options_local_var->gmsa_credential_spec = gmsa_credential_spec;
    v1_windows_security_context_options_local_var->gmsa_credential_spec_name = gmsa_credential_spec_name;
    v1_windows_security_context_options_local_var->host_process = host_process;
    v1_windows_security_context_options_local_var->run_as_user_name = run_as_user_name;
    return v1_windows_security_context_options_local_var;
}

__attribute__((deprecated)) v1_windows_security_context_options_t *v1_windows_security_context_options_create(
    char *gmsa_credential_spec,
    char *gmsa_credential_spec_name,
    int *host_process,
    char *run_as_user_name
    ) {
    int *host_process_copy = NULL;
    if (host_process) {
        host_process_copy = malloc(sizeof(int));
        if (host_process_copy) *host_process_copy = *host_process;
    }
    v1_windows_security_context_options_t *result = v1_windows_security_context_options_create_internal (
        gmsa_credential_spec,
        gmsa_credential_spec_name,
        host_process_copy,
        run_as_user_name
        );
    if (!result) {
        free(host_process_copy);
    }
    return result;
}

void v1_windows_security_context_options_free(v1_windows_security_context_options_t *v1_windows_security_context_options) {
    if(NULL == v1_windows_security_context_options){
        return ;
    }
    if(v1_windows_security_context_options->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_windows_security_context_options_free");
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
    if (v1_windows_security_context_options->host_process) {
        free(v1_windows_security_context_options->host_process);
        v1_windows_security_context_options->host_process = NULL;
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


    // v1_windows_security_context_options->host_process
    if(v1_windows_security_context_options->host_process) {
    if(cJSON_AddBoolToObject(item, "hostProcess", *v1_windows_security_context_options->host_process) == NULL) {
    goto fail; //Bool
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

    char *gmsa_credential_spec_local_str = NULL;

    char *gmsa_credential_spec_name_local_str = NULL;

    // define the local variable for v1_windows_security_context_options->host_process
    int *host_process_local_var = NULL;

    char *run_as_user_name_local_str = NULL;

    // v1_windows_security_context_options->gmsa_credential_spec
    cJSON *gmsa_credential_spec = cJSON_GetObjectItemCaseSensitive(v1_windows_security_context_optionsJSON, "gmsaCredentialSpec");
    if (cJSON_IsNull(gmsa_credential_spec)) {
        gmsa_credential_spec = NULL;
    }
    if (gmsa_credential_spec) { 
    if(!cJSON_IsString(gmsa_credential_spec) && !cJSON_IsNull(gmsa_credential_spec))
    {
    goto end; //String
    }
    }

    // v1_windows_security_context_options->gmsa_credential_spec_name
    cJSON *gmsa_credential_spec_name = cJSON_GetObjectItemCaseSensitive(v1_windows_security_context_optionsJSON, "gmsaCredentialSpecName");
    if (cJSON_IsNull(gmsa_credential_spec_name)) {
        gmsa_credential_spec_name = NULL;
    }
    if (gmsa_credential_spec_name) { 
    if(!cJSON_IsString(gmsa_credential_spec_name) && !cJSON_IsNull(gmsa_credential_spec_name))
    {
    goto end; //String
    }
    }

    // v1_windows_security_context_options->host_process
    cJSON *host_process = cJSON_GetObjectItemCaseSensitive(v1_windows_security_context_optionsJSON, "hostProcess");
    if (cJSON_IsNull(host_process)) {
        host_process = NULL;
    }
    if (host_process) { 
    if(!cJSON_IsBool(host_process))
    {
    goto end; //Bool
    }
    host_process_local_var = malloc(sizeof(int));
    if(!host_process_local_var)
    {
        goto end;
    }
    *host_process_local_var = host_process->valueint;
    }

    // v1_windows_security_context_options->run_as_user_name
    cJSON *run_as_user_name = cJSON_GetObjectItemCaseSensitive(v1_windows_security_context_optionsJSON, "runAsUserName");
    if (cJSON_IsNull(run_as_user_name)) {
        run_as_user_name = NULL;
    }
    if (run_as_user_name) { 
    if(!cJSON_IsString(run_as_user_name) && !cJSON_IsNull(run_as_user_name))
    {
    goto end; //String
    }
    }


    if (gmsa_credential_spec && !cJSON_IsNull(gmsa_credential_spec)) gmsa_credential_spec_local_str = strdup(gmsa_credential_spec->valuestring);
    if (gmsa_credential_spec_name && !cJSON_IsNull(gmsa_credential_spec_name)) gmsa_credential_spec_name_local_str = strdup(gmsa_credential_spec_name->valuestring);
    if (run_as_user_name && !cJSON_IsNull(run_as_user_name)) run_as_user_name_local_str = strdup(run_as_user_name->valuestring);

    v1_windows_security_context_options_local_var = v1_windows_security_context_options_create_internal (
        gmsa_credential_spec_local_str,
        gmsa_credential_spec_name_local_str,
        host_process_local_var,
        run_as_user_name_local_str
        );

    if (!v1_windows_security_context_options_local_var) {
        goto end;
    }

    return v1_windows_security_context_options_local_var;
end:
    if (gmsa_credential_spec_local_str) {
        free(gmsa_credential_spec_local_str);
        gmsa_credential_spec_local_str = NULL;
    }
    if (gmsa_credential_spec_name_local_str) {
        free(gmsa_credential_spec_name_local_str);
        gmsa_credential_spec_name_local_str = NULL;
    }
    if (host_process_local_var) {
        free(host_process_local_var);
        host_process_local_var = NULL;
    }
    if (run_as_user_name_local_str) {
        free(run_as_user_name_local_str);
        run_as_user_name_local_str = NULL;
    }
    return NULL;

}
