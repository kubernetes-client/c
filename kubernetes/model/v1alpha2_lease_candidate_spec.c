#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha2_lease_candidate_spec.h"



static v1alpha2_lease_candidate_spec_t *v1alpha2_lease_candidate_spec_create_internal(
    char *binary_version,
    char *emulation_version,
    char *lease_name,
    char *ping_time,
    char *renew_time,
    char *strategy
    ) {
    v1alpha2_lease_candidate_spec_t *v1alpha2_lease_candidate_spec_local_var = malloc(sizeof(v1alpha2_lease_candidate_spec_t));
    if (!v1alpha2_lease_candidate_spec_local_var) {
        return NULL;
    }
    v1alpha2_lease_candidate_spec_local_var->binary_version = binary_version;
    v1alpha2_lease_candidate_spec_local_var->emulation_version = emulation_version;
    v1alpha2_lease_candidate_spec_local_var->lease_name = lease_name;
    v1alpha2_lease_candidate_spec_local_var->ping_time = ping_time;
    v1alpha2_lease_candidate_spec_local_var->renew_time = renew_time;
    v1alpha2_lease_candidate_spec_local_var->strategy = strategy;

    v1alpha2_lease_candidate_spec_local_var->_library_owned = 1;
    return v1alpha2_lease_candidate_spec_local_var;
}

__attribute__((deprecated)) v1alpha2_lease_candidate_spec_t *v1alpha2_lease_candidate_spec_create(
    char *binary_version,
    char *emulation_version,
    char *lease_name,
    char *ping_time,
    char *renew_time,
    char *strategy
    ) {
    return v1alpha2_lease_candidate_spec_create_internal (
        binary_version,
        emulation_version,
        lease_name,
        ping_time,
        renew_time,
        strategy
        );
}

void v1alpha2_lease_candidate_spec_free(v1alpha2_lease_candidate_spec_t *v1alpha2_lease_candidate_spec) {
    if(NULL == v1alpha2_lease_candidate_spec){
        return ;
    }
    if(v1alpha2_lease_candidate_spec->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1alpha2_lease_candidate_spec_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha2_lease_candidate_spec->binary_version) {
        free(v1alpha2_lease_candidate_spec->binary_version);
        v1alpha2_lease_candidate_spec->binary_version = NULL;
    }
    if (v1alpha2_lease_candidate_spec->emulation_version) {
        free(v1alpha2_lease_candidate_spec->emulation_version);
        v1alpha2_lease_candidate_spec->emulation_version = NULL;
    }
    if (v1alpha2_lease_candidate_spec->lease_name) {
        free(v1alpha2_lease_candidate_spec->lease_name);
        v1alpha2_lease_candidate_spec->lease_name = NULL;
    }
    if (v1alpha2_lease_candidate_spec->ping_time) {
        free(v1alpha2_lease_candidate_spec->ping_time);
        v1alpha2_lease_candidate_spec->ping_time = NULL;
    }
    if (v1alpha2_lease_candidate_spec->renew_time) {
        free(v1alpha2_lease_candidate_spec->renew_time);
        v1alpha2_lease_candidate_spec->renew_time = NULL;
    }
    if (v1alpha2_lease_candidate_spec->strategy) {
        free(v1alpha2_lease_candidate_spec->strategy);
        v1alpha2_lease_candidate_spec->strategy = NULL;
    }
    free(v1alpha2_lease_candidate_spec);
}

cJSON *v1alpha2_lease_candidate_spec_convertToJSON(v1alpha2_lease_candidate_spec_t *v1alpha2_lease_candidate_spec) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha2_lease_candidate_spec->binary_version
    if (!v1alpha2_lease_candidate_spec->binary_version) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "binaryVersion", v1alpha2_lease_candidate_spec->binary_version) == NULL) {
    goto fail; //String
    }


    // v1alpha2_lease_candidate_spec->emulation_version
    if(v1alpha2_lease_candidate_spec->emulation_version) {
    if(cJSON_AddStringToObject(item, "emulationVersion", v1alpha2_lease_candidate_spec->emulation_version) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha2_lease_candidate_spec->lease_name
    if (!v1alpha2_lease_candidate_spec->lease_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "leaseName", v1alpha2_lease_candidate_spec->lease_name) == NULL) {
    goto fail; //String
    }


    // v1alpha2_lease_candidate_spec->ping_time
    if(v1alpha2_lease_candidate_spec->ping_time) {
    if(cJSON_AddStringToObject(item, "pingTime", v1alpha2_lease_candidate_spec->ping_time) == NULL) {
    goto fail; //Date-Time
    }
    }


    // v1alpha2_lease_candidate_spec->renew_time
    if(v1alpha2_lease_candidate_spec->renew_time) {
    if(cJSON_AddStringToObject(item, "renewTime", v1alpha2_lease_candidate_spec->renew_time) == NULL) {
    goto fail; //Date-Time
    }
    }


    // v1alpha2_lease_candidate_spec->strategy
    if (!v1alpha2_lease_candidate_spec->strategy) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "strategy", v1alpha2_lease_candidate_spec->strategy) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1alpha2_lease_candidate_spec_t *v1alpha2_lease_candidate_spec_parseFromJSON(cJSON *v1alpha2_lease_candidate_specJSON){

    v1alpha2_lease_candidate_spec_t *v1alpha2_lease_candidate_spec_local_var = NULL;

    // v1alpha2_lease_candidate_spec->binary_version
    cJSON *binary_version = cJSON_GetObjectItemCaseSensitive(v1alpha2_lease_candidate_specJSON, "binaryVersion");
    if (cJSON_IsNull(binary_version)) {
        binary_version = NULL;
    }
    if (!binary_version) {
        goto end;
    }

    
    if(!cJSON_IsString(binary_version))
    {
    goto end; //String
    }

    // v1alpha2_lease_candidate_spec->emulation_version
    cJSON *emulation_version = cJSON_GetObjectItemCaseSensitive(v1alpha2_lease_candidate_specJSON, "emulationVersion");
    if (cJSON_IsNull(emulation_version)) {
        emulation_version = NULL;
    }
    if (emulation_version) { 
    if(!cJSON_IsString(emulation_version) && !cJSON_IsNull(emulation_version))
    {
    goto end; //String
    }
    }

    // v1alpha2_lease_candidate_spec->lease_name
    cJSON *lease_name = cJSON_GetObjectItemCaseSensitive(v1alpha2_lease_candidate_specJSON, "leaseName");
    if (cJSON_IsNull(lease_name)) {
        lease_name = NULL;
    }
    if (!lease_name) {
        goto end;
    }

    
    if(!cJSON_IsString(lease_name))
    {
    goto end; //String
    }

    // v1alpha2_lease_candidate_spec->ping_time
    cJSON *ping_time = cJSON_GetObjectItemCaseSensitive(v1alpha2_lease_candidate_specJSON, "pingTime");
    if (cJSON_IsNull(ping_time)) {
        ping_time = NULL;
    }
    if (ping_time) { 
    if(!cJSON_IsString(ping_time) && !cJSON_IsNull(ping_time))
    {
    goto end; //DateTime
    }
    }

    // v1alpha2_lease_candidate_spec->renew_time
    cJSON *renew_time = cJSON_GetObjectItemCaseSensitive(v1alpha2_lease_candidate_specJSON, "renewTime");
    if (cJSON_IsNull(renew_time)) {
        renew_time = NULL;
    }
    if (renew_time) { 
    if(!cJSON_IsString(renew_time) && !cJSON_IsNull(renew_time))
    {
    goto end; //DateTime
    }
    }

    // v1alpha2_lease_candidate_spec->strategy
    cJSON *strategy = cJSON_GetObjectItemCaseSensitive(v1alpha2_lease_candidate_specJSON, "strategy");
    if (cJSON_IsNull(strategy)) {
        strategy = NULL;
    }
    if (!strategy) {
        goto end;
    }

    
    if(!cJSON_IsString(strategy))
    {
    goto end; //String
    }


    v1alpha2_lease_candidate_spec_local_var = v1alpha2_lease_candidate_spec_create_internal (
        strdup(binary_version->valuestring),
        emulation_version && !cJSON_IsNull(emulation_version) ? strdup(emulation_version->valuestring) : NULL,
        strdup(lease_name->valuestring),
        ping_time && !cJSON_IsNull(ping_time) ? strdup(ping_time->valuestring) : NULL,
        renew_time && !cJSON_IsNull(renew_time) ? strdup(renew_time->valuestring) : NULL,
        strdup(strategy->valuestring)
        );

    return v1alpha2_lease_candidate_spec_local_var;
end:
    return NULL;

}
