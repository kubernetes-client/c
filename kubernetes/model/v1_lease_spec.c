#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_lease_spec.h"



static v1_lease_spec_t *v1_lease_spec_create_internal(
    char *acquire_time,
    char *holder_identity,
    int *lease_duration_seconds,
    int *lease_transitions,
    char *preferred_holder,
    char *renew_time,
    char *strategy
    ) {
    v1_lease_spec_t *v1_lease_spec_local_var = malloc(sizeof(v1_lease_spec_t));
    if (!v1_lease_spec_local_var) {
        return NULL;
    }
    memset(v1_lease_spec_local_var, 0, sizeof(v1_lease_spec_t));
    v1_lease_spec_local_var->_library_owned = 1;
    v1_lease_spec_local_var->acquire_time = acquire_time;
    v1_lease_spec_local_var->holder_identity = holder_identity;
    v1_lease_spec_local_var->lease_duration_seconds = lease_duration_seconds;
    v1_lease_spec_local_var->lease_transitions = lease_transitions;
    v1_lease_spec_local_var->preferred_holder = preferred_holder;
    v1_lease_spec_local_var->renew_time = renew_time;
    v1_lease_spec_local_var->strategy = strategy;
    return v1_lease_spec_local_var;
}

__attribute__((deprecated)) v1_lease_spec_t *v1_lease_spec_create(
    char *acquire_time,
    char *holder_identity,
    int *lease_duration_seconds,
    int *lease_transitions,
    char *preferred_holder,
    char *renew_time,
    char *strategy
    ) {
    int *lease_duration_seconds_copy = NULL;
    if (lease_duration_seconds) {
        lease_duration_seconds_copy = malloc(sizeof(int));
        if (lease_duration_seconds_copy) *lease_duration_seconds_copy = *lease_duration_seconds;
    }
    int *lease_transitions_copy = NULL;
    if (lease_transitions) {
        lease_transitions_copy = malloc(sizeof(int));
        if (lease_transitions_copy) *lease_transitions_copy = *lease_transitions;
    }
    v1_lease_spec_t *result = v1_lease_spec_create_internal (
        acquire_time,
        holder_identity,
        lease_duration_seconds_copy,
        lease_transitions_copy,
        preferred_holder,
        renew_time,
        strategy
        );
    if (!result) {
        free(lease_duration_seconds_copy);
        free(lease_transitions_copy);
    }
    return result;
}

void v1_lease_spec_free(v1_lease_spec_t *v1_lease_spec) {
    if(NULL == v1_lease_spec){
        return ;
    }
    if(v1_lease_spec->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_lease_spec_free");
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
    if (v1_lease_spec->lease_duration_seconds) {
        free(v1_lease_spec->lease_duration_seconds);
        v1_lease_spec->lease_duration_seconds = NULL;
    }
    if (v1_lease_spec->lease_transitions) {
        free(v1_lease_spec->lease_transitions);
        v1_lease_spec->lease_transitions = NULL;
    }
    if (v1_lease_spec->preferred_holder) {
        free(v1_lease_spec->preferred_holder);
        v1_lease_spec->preferred_holder = NULL;
    }
    if (v1_lease_spec->renew_time) {
        free(v1_lease_spec->renew_time);
        v1_lease_spec->renew_time = NULL;
    }
    if (v1_lease_spec->strategy) {
        free(v1_lease_spec->strategy);
        v1_lease_spec->strategy = NULL;
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
    if(cJSON_AddNumberToObject(item, "leaseDurationSeconds", *v1_lease_spec->lease_duration_seconds) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_lease_spec->lease_transitions
    if(v1_lease_spec->lease_transitions) {
    if(cJSON_AddNumberToObject(item, "leaseTransitions", *v1_lease_spec->lease_transitions) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_lease_spec->preferred_holder
    if(v1_lease_spec->preferred_holder) {
    if(cJSON_AddStringToObject(item, "preferredHolder", v1_lease_spec->preferred_holder) == NULL) {
    goto fail; //String
    }
    }


    // v1_lease_spec->renew_time
    if(v1_lease_spec->renew_time) {
    if(cJSON_AddStringToObject(item, "renewTime", v1_lease_spec->renew_time) == NULL) {
    goto fail; //Date-Time
    }
    }


    // v1_lease_spec->strategy
    if(v1_lease_spec->strategy) {
    if(cJSON_AddStringToObject(item, "strategy", v1_lease_spec->strategy) == NULL) {
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

v1_lease_spec_t *v1_lease_spec_parseFromJSON(cJSON *v1_lease_specJSON){

    v1_lease_spec_t *v1_lease_spec_local_var = NULL;

    char *acquire_time_local_str = NULL;

    char *holder_identity_local_str = NULL;

    // define the local variable for v1_lease_spec->lease_duration_seconds
    int *lease_duration_seconds_local_var = NULL;

    // define the local variable for v1_lease_spec->lease_transitions
    int *lease_transitions_local_var = NULL;

    char *preferred_holder_local_str = NULL;

    char *renew_time_local_str = NULL;

    char *strategy_local_str = NULL;

    // v1_lease_spec->acquire_time
    cJSON *acquire_time = cJSON_GetObjectItemCaseSensitive(v1_lease_specJSON, "acquireTime");
    if (cJSON_IsNull(acquire_time)) {
        acquire_time = NULL;
    }
    if (acquire_time) { 
    if(!cJSON_IsString(acquire_time) && !cJSON_IsNull(acquire_time))
    {
    goto end; //DateTime
    }
    }

    // v1_lease_spec->holder_identity
    cJSON *holder_identity = cJSON_GetObjectItemCaseSensitive(v1_lease_specJSON, "holderIdentity");
    if (cJSON_IsNull(holder_identity)) {
        holder_identity = NULL;
    }
    if (holder_identity) { 
    if(!cJSON_IsString(holder_identity) && !cJSON_IsNull(holder_identity))
    {
    goto end; //String
    }
    }

    // v1_lease_spec->lease_duration_seconds
    cJSON *lease_duration_seconds = cJSON_GetObjectItemCaseSensitive(v1_lease_specJSON, "leaseDurationSeconds");
    if (cJSON_IsNull(lease_duration_seconds)) {
        lease_duration_seconds = NULL;
    }
    if (lease_duration_seconds) { 
    if(!cJSON_IsNumber(lease_duration_seconds))
    {
    goto end; //Numeric
    }
    lease_duration_seconds_local_var = malloc(sizeof(int));
    if(!lease_duration_seconds_local_var)
    {
        goto end;
    }
    *lease_duration_seconds_local_var = lease_duration_seconds->valuedouble;
    }

    // v1_lease_spec->lease_transitions
    cJSON *lease_transitions = cJSON_GetObjectItemCaseSensitive(v1_lease_specJSON, "leaseTransitions");
    if (cJSON_IsNull(lease_transitions)) {
        lease_transitions = NULL;
    }
    if (lease_transitions) { 
    if(!cJSON_IsNumber(lease_transitions))
    {
    goto end; //Numeric
    }
    lease_transitions_local_var = malloc(sizeof(int));
    if(!lease_transitions_local_var)
    {
        goto end;
    }
    *lease_transitions_local_var = lease_transitions->valuedouble;
    }

    // v1_lease_spec->preferred_holder
    cJSON *preferred_holder = cJSON_GetObjectItemCaseSensitive(v1_lease_specJSON, "preferredHolder");
    if (cJSON_IsNull(preferred_holder)) {
        preferred_holder = NULL;
    }
    if (preferred_holder) { 
    if(!cJSON_IsString(preferred_holder) && !cJSON_IsNull(preferred_holder))
    {
    goto end; //String
    }
    }

    // v1_lease_spec->renew_time
    cJSON *renew_time = cJSON_GetObjectItemCaseSensitive(v1_lease_specJSON, "renewTime");
    if (cJSON_IsNull(renew_time)) {
        renew_time = NULL;
    }
    if (renew_time) { 
    if(!cJSON_IsString(renew_time) && !cJSON_IsNull(renew_time))
    {
    goto end; //DateTime
    }
    }

    // v1_lease_spec->strategy
    cJSON *strategy = cJSON_GetObjectItemCaseSensitive(v1_lease_specJSON, "strategy");
    if (cJSON_IsNull(strategy)) {
        strategy = NULL;
    }
    if (strategy) { 
    if(!cJSON_IsString(strategy) && !cJSON_IsNull(strategy))
    {
    goto end; //String
    }
    }


    if (acquire_time && !cJSON_IsNull(acquire_time)) acquire_time_local_str = strdup(acquire_time->valuestring);
    if (holder_identity && !cJSON_IsNull(holder_identity)) holder_identity_local_str = strdup(holder_identity->valuestring);
    if (preferred_holder && !cJSON_IsNull(preferred_holder)) preferred_holder_local_str = strdup(preferred_holder->valuestring);
    if (renew_time && !cJSON_IsNull(renew_time)) renew_time_local_str = strdup(renew_time->valuestring);
    if (strategy && !cJSON_IsNull(strategy)) strategy_local_str = strdup(strategy->valuestring);

    v1_lease_spec_local_var = v1_lease_spec_create_internal (
        acquire_time_local_str,
        holder_identity_local_str,
        lease_duration_seconds_local_var,
        lease_transitions_local_var,
        preferred_holder_local_str,
        renew_time_local_str,
        strategy_local_str
        );

    if (!v1_lease_spec_local_var) {
        goto end;
    }

    return v1_lease_spec_local_var;
end:
    if (acquire_time_local_str) {
        free(acquire_time_local_str);
        acquire_time_local_str = NULL;
    }
    if (holder_identity_local_str) {
        free(holder_identity_local_str);
        holder_identity_local_str = NULL;
    }
    if (lease_duration_seconds_local_var) {
        free(lease_duration_seconds_local_var);
        lease_duration_seconds_local_var = NULL;
    }
    if (lease_transitions_local_var) {
        free(lease_transitions_local_var);
        lease_transitions_local_var = NULL;
    }
    if (preferred_holder_local_str) {
        free(preferred_holder_local_str);
        preferred_holder_local_str = NULL;
    }
    if (renew_time_local_str) {
        free(renew_time_local_str);
        renew_time_local_str = NULL;
    }
    if (strategy_local_str) {
        free(strategy_local_str);
        strategy_local_str = NULL;
    }
    return NULL;

}
