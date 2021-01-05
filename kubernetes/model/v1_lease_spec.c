#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_lease_spec.h"



v1_lease_spec_t *v1_lease_spec_create(
    char *acquire_time,
    char *holder_identity,
    int lease_duration_seconds,
    int lease_transitions,
    char *renew_time
    ) {
    v1_lease_spec_t *v1_lease_spec_local_var = malloc(sizeof(v1_lease_spec_t));
    if (!v1_lease_spec_local_var) {
        return NULL;
    }
    v1_lease_spec_local_var->acquire_time = acquire_time;
    v1_lease_spec_local_var->holder_identity = holder_identity;
    v1_lease_spec_local_var->lease_duration_seconds = lease_duration_seconds;
    v1_lease_spec_local_var->lease_transitions = lease_transitions;
    v1_lease_spec_local_var->renew_time = renew_time;

    return v1_lease_spec_local_var;
}


void v1_lease_spec_free(v1_lease_spec_t *v1_lease_spec) {
    if(NULL == v1_lease_spec){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_lease_spec->acquire_time) {
        free(v1_lease_spec->acquire_time);
        v1_lease_spec->acquire_time = NULL;
    }
    if (v1_lease_spec->holder_identity) {
        free(v1_lease_spec->holder_identity);
        v1_lease_spec->holder_identity = NULL;
    }
    if (v1_lease_spec->renew_time) {
        free(v1_lease_spec->renew_time);
        v1_lease_spec->renew_time = NULL;
    }
    free(v1_lease_spec);
}

cJSON *v1_lease_spec_convertToJSON(v1_lease_spec_t *v1_lease_spec) {
    cJSON *item = cJSON_CreateObject();

    // v1_lease_spec->acquire_time
    if(v1_lease_spec->acquire_time) { 
    if(cJSON_AddStringToObject(item, "acquireTime", v1_lease_spec->acquire_time) == NULL) {
    goto fail; //Date-Time
    }
     } 


    // v1_lease_spec->holder_identity
    if(v1_lease_spec->holder_identity) { 
    if(cJSON_AddStringToObject(item, "holderIdentity", v1_lease_spec->holder_identity) == NULL) {
    goto fail; //String
    }
     } 


    // v1_lease_spec->lease_duration_seconds
    if(v1_lease_spec->lease_duration_seconds) { 
    if(cJSON_AddNumberToObject(item, "leaseDurationSeconds", v1_lease_spec->lease_duration_seconds) == NULL) {
    goto fail; //Numeric
    }
     } 


    // v1_lease_spec->lease_transitions
    if(v1_lease_spec->lease_transitions) { 
    if(cJSON_AddNumberToObject(item, "leaseTransitions", v1_lease_spec->lease_transitions) == NULL) {
    goto fail; //Numeric
    }
     } 


    // v1_lease_spec->renew_time
    if(v1_lease_spec->renew_time) { 
    if(cJSON_AddStringToObject(item, "renewTime", v1_lease_spec->renew_time) == NULL) {
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

v1_lease_spec_t *v1_lease_spec_parseFromJSON(cJSON *v1_lease_specJSON){

    v1_lease_spec_t *v1_lease_spec_local_var = NULL;

    // v1_lease_spec->acquire_time
    cJSON *acquire_time = cJSON_GetObjectItemCaseSensitive(v1_lease_specJSON, "acquireTime");
    if (acquire_time) { 
    if(!cJSON_IsString(acquire_time))
    {
    goto end; //DateTime
    }
    }

    // v1_lease_spec->holder_identity
    cJSON *holder_identity = cJSON_GetObjectItemCaseSensitive(v1_lease_specJSON, "holderIdentity");
    if (holder_identity) { 
    if(!cJSON_IsString(holder_identity))
    {
    goto end; //String
    }
    }

    // v1_lease_spec->lease_duration_seconds
    cJSON *lease_duration_seconds = cJSON_GetObjectItemCaseSensitive(v1_lease_specJSON, "leaseDurationSeconds");
    if (lease_duration_seconds) { 
    if(!cJSON_IsNumber(lease_duration_seconds))
    {
    goto end; //Numeric
    }
    }

    // v1_lease_spec->lease_transitions
    cJSON *lease_transitions = cJSON_GetObjectItemCaseSensitive(v1_lease_specJSON, "leaseTransitions");
    if (lease_transitions) { 
    if(!cJSON_IsNumber(lease_transitions))
    {
    goto end; //Numeric
    }
    }

    // v1_lease_spec->renew_time
    cJSON *renew_time = cJSON_GetObjectItemCaseSensitive(v1_lease_specJSON, "renewTime");
    if (renew_time) { 
    if(!cJSON_IsString(renew_time))
    {
    goto end; //DateTime
    }
    }


    v1_lease_spec_local_var = v1_lease_spec_create (
        acquire_time ? strdup(acquire_time->valuestring) : NULL,
        holder_identity ? strdup(holder_identity->valuestring) : NULL,
        lease_duration_seconds ? lease_duration_seconds->valuedouble : 0,
        lease_transitions ? lease_transitions->valuedouble : 0,
        renew_time ? strdup(renew_time->valuestring) : NULL
        );

    return v1_lease_spec_local_var;
end:
    return NULL;

}
