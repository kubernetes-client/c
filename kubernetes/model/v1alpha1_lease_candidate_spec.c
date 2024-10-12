#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha1_lease_candidate_spec.h"



v1alpha1_lease_candidate_spec_t *v1alpha1_lease_candidate_spec_create(
    char *binary_version,
    char *emulation_version,
    char *lease_name,
    char *ping_time,
    list_t *preferred_strategies,
    char *renew_time
    ) {
    v1alpha1_lease_candidate_spec_t *v1alpha1_lease_candidate_spec_local_var = malloc(sizeof(v1alpha1_lease_candidate_spec_t));
    if (!v1alpha1_lease_candidate_spec_local_var) {
        return NULL;
    }
    v1alpha1_lease_candidate_spec_local_var->binary_version = binary_version;
    v1alpha1_lease_candidate_spec_local_var->emulation_version = emulation_version;
    v1alpha1_lease_candidate_spec_local_var->lease_name = lease_name;
    v1alpha1_lease_candidate_spec_local_var->ping_time = ping_time;
    v1alpha1_lease_candidate_spec_local_var->preferred_strategies = preferred_strategies;
    v1alpha1_lease_candidate_spec_local_var->renew_time = renew_time;

    return v1alpha1_lease_candidate_spec_local_var;
}


void v1alpha1_lease_candidate_spec_free(v1alpha1_lease_candidate_spec_t *v1alpha1_lease_candidate_spec) {
    if(NULL == v1alpha1_lease_candidate_spec){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha1_lease_candidate_spec->binary_version) {
        free(v1alpha1_lease_candidate_spec->binary_version);
        v1alpha1_lease_candidate_spec->binary_version = NULL;
    }
    if (v1alpha1_lease_candidate_spec->emulation_version) {
        free(v1alpha1_lease_candidate_spec->emulation_version);
        v1alpha1_lease_candidate_spec->emulation_version = NULL;
    }
    if (v1alpha1_lease_candidate_spec->lease_name) {
        free(v1alpha1_lease_candidate_spec->lease_name);
        v1alpha1_lease_candidate_spec->lease_name = NULL;
    }
    if (v1alpha1_lease_candidate_spec->ping_time) {
        free(v1alpha1_lease_candidate_spec->ping_time);
        v1alpha1_lease_candidate_spec->ping_time = NULL;
    }
    if (v1alpha1_lease_candidate_spec->preferred_strategies) {
        list_ForEach(listEntry, v1alpha1_lease_candidate_spec->preferred_strategies) {
            free(listEntry->data);
        }
        list_freeList(v1alpha1_lease_candidate_spec->preferred_strategies);
        v1alpha1_lease_candidate_spec->preferred_strategies = NULL;
    }
    if (v1alpha1_lease_candidate_spec->renew_time) {
        free(v1alpha1_lease_candidate_spec->renew_time);
        v1alpha1_lease_candidate_spec->renew_time = NULL;
    }
    free(v1alpha1_lease_candidate_spec);
}

cJSON *v1alpha1_lease_candidate_spec_convertToJSON(v1alpha1_lease_candidate_spec_t *v1alpha1_lease_candidate_spec) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha1_lease_candidate_spec->binary_version
    if(v1alpha1_lease_candidate_spec->binary_version) {
    if(cJSON_AddStringToObject(item, "binaryVersion", v1alpha1_lease_candidate_spec->binary_version) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha1_lease_candidate_spec->emulation_version
    if(v1alpha1_lease_candidate_spec->emulation_version) {
    if(cJSON_AddStringToObject(item, "emulationVersion", v1alpha1_lease_candidate_spec->emulation_version) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha1_lease_candidate_spec->lease_name
    if (!v1alpha1_lease_candidate_spec->lease_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "leaseName", v1alpha1_lease_candidate_spec->lease_name) == NULL) {
    goto fail; //String
    }


    // v1alpha1_lease_candidate_spec->ping_time
    if(v1alpha1_lease_candidate_spec->ping_time) {
    if(cJSON_AddStringToObject(item, "pingTime", v1alpha1_lease_candidate_spec->ping_time) == NULL) {
    goto fail; //Date-Time
    }
    }


    // v1alpha1_lease_candidate_spec->preferred_strategies
    if (!v1alpha1_lease_candidate_spec->preferred_strategies) {
        goto fail;
    }
    cJSON *preferred_strategies = cJSON_AddArrayToObject(item, "preferredStrategies");
    if(preferred_strategies == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *preferred_strategiesListEntry;
    list_ForEach(preferred_strategiesListEntry, v1alpha1_lease_candidate_spec->preferred_strategies) {
    if(cJSON_AddStringToObject(preferred_strategies, "", (char*)preferred_strategiesListEntry->data) == NULL)
    {
        goto fail;
    }
    }


    // v1alpha1_lease_candidate_spec->renew_time
    if(v1alpha1_lease_candidate_spec->renew_time) {
    if(cJSON_AddStringToObject(item, "renewTime", v1alpha1_lease_candidate_spec->renew_time) == NULL) {
    goto fail; //Date-Time
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1alpha1_lease_candidate_spec_t *v1alpha1_lease_candidate_spec_parseFromJSON(cJSON *v1alpha1_lease_candidate_specJSON){

    v1alpha1_lease_candidate_spec_t *v1alpha1_lease_candidate_spec_local_var = NULL;

    // define the local list for v1alpha1_lease_candidate_spec->preferred_strategies
    list_t *preferred_strategiesList = NULL;

    // v1alpha1_lease_candidate_spec->binary_version
    cJSON *binary_version = cJSON_GetObjectItemCaseSensitive(v1alpha1_lease_candidate_specJSON, "binaryVersion");
    if (binary_version) { 
    if(!cJSON_IsString(binary_version) && !cJSON_IsNull(binary_version))
    {
    goto end; //String
    }
    }

    // v1alpha1_lease_candidate_spec->emulation_version
    cJSON *emulation_version = cJSON_GetObjectItemCaseSensitive(v1alpha1_lease_candidate_specJSON, "emulationVersion");
    if (emulation_version) { 
    if(!cJSON_IsString(emulation_version) && !cJSON_IsNull(emulation_version))
    {
    goto end; //String
    }
    }

    // v1alpha1_lease_candidate_spec->lease_name
    cJSON *lease_name = cJSON_GetObjectItemCaseSensitive(v1alpha1_lease_candidate_specJSON, "leaseName");
    if (!lease_name) {
        goto end;
    }

    
    if(!cJSON_IsString(lease_name))
    {
    goto end; //String
    }

    // v1alpha1_lease_candidate_spec->ping_time
    cJSON *ping_time = cJSON_GetObjectItemCaseSensitive(v1alpha1_lease_candidate_specJSON, "pingTime");
    if (ping_time) { 
    if(!cJSON_IsString(ping_time) && !cJSON_IsNull(ping_time))
    {
    goto end; //DateTime
    }
    }

    // v1alpha1_lease_candidate_spec->preferred_strategies
    cJSON *preferred_strategies = cJSON_GetObjectItemCaseSensitive(v1alpha1_lease_candidate_specJSON, "preferredStrategies");
    if (!preferred_strategies) {
        goto end;
    }

    
    cJSON *preferred_strategies_local = NULL;
    if(!cJSON_IsArray(preferred_strategies)) {
        goto end;//primitive container
    }
    preferred_strategiesList = list_createList();

    cJSON_ArrayForEach(preferred_strategies_local, preferred_strategies)
    {
        if(!cJSON_IsString(preferred_strategies_local))
        {
            goto end;
        }
        list_addElement(preferred_strategiesList , strdup(preferred_strategies_local->valuestring));
    }

    // v1alpha1_lease_candidate_spec->renew_time
    cJSON *renew_time = cJSON_GetObjectItemCaseSensitive(v1alpha1_lease_candidate_specJSON, "renewTime");
    if (renew_time) { 
    if(!cJSON_IsString(renew_time) && !cJSON_IsNull(renew_time))
    {
    goto end; //DateTime
    }
    }


    v1alpha1_lease_candidate_spec_local_var = v1alpha1_lease_candidate_spec_create (
        binary_version && !cJSON_IsNull(binary_version) ? strdup(binary_version->valuestring) : NULL,
        emulation_version && !cJSON_IsNull(emulation_version) ? strdup(emulation_version->valuestring) : NULL,
        strdup(lease_name->valuestring),
        ping_time && !cJSON_IsNull(ping_time) ? strdup(ping_time->valuestring) : NULL,
        preferred_strategiesList,
        renew_time && !cJSON_IsNull(renew_time) ? strdup(renew_time->valuestring) : NULL
        );

    return v1alpha1_lease_candidate_spec_local_var;
end:
    if (preferred_strategiesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, preferred_strategiesList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(preferred_strategiesList);
        preferred_strategiesList = NULL;
    }
    return NULL;

}
