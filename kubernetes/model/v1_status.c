#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_status.h"



static v1_status_t *v1_status_create_internal(
    char *api_version,
    int code,
    v1_status_details_t *details,
    char *kind,
    char *message,
    v1_list_meta_t *metadata,
    char *reason,
    char *status
    ) {
    v1_status_t *v1_status_local_var = malloc(sizeof(v1_status_t));
    if (!v1_status_local_var) {
        return NULL;
    }
    v1_status_local_var->api_version = api_version;
    v1_status_local_var->code = code;
    v1_status_local_var->details = details;
    v1_status_local_var->kind = kind;
    v1_status_local_var->message = message;
    v1_status_local_var->metadata = metadata;
    v1_status_local_var->reason = reason;
    v1_status_local_var->status = status;

    v1_status_local_var->_library_owned = 1;
    return v1_status_local_var;
}

__attribute__((deprecated)) v1_status_t *v1_status_create(
    char *api_version,
    int code,
    v1_status_details_t *details,
    char *kind,
    char *message,
    v1_list_meta_t *metadata,
    char *reason,
    char *status
    ) {
    return v1_status_create_internal (
        api_version,
        code,
        details,
        kind,
        message,
        metadata,
        reason,
        status
        );
}

void v1_status_free(v1_status_t *v1_status) {
    if(NULL == v1_status){
        return ;
    }
    if(v1_status->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_status_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_status->api_version) {
        free(v1_status->api_version);
        v1_status->api_version = NULL;
    }
    if (v1_status->details) {
        v1_status_details_free(v1_status->details);
        v1_status->details = NULL;
    }
    if (v1_status->kind) {
        free(v1_status->kind);
        v1_status->kind = NULL;
    }
    if (v1_status->message) {
        free(v1_status->message);
        v1_status->message = NULL;
    }
    if (v1_status->metadata) {
        v1_list_meta_free(v1_status->metadata);
        v1_status->metadata = NULL;
    }
    if (v1_status->reason) {
        free(v1_status->reason);
        v1_status->reason = NULL;
    }
    if (v1_status->status) {
        free(v1_status->status);
        v1_status->status = NULL;
    }
    free(v1_status);
}

cJSON *v1_status_convertToJSON(v1_status_t *v1_status) {
    cJSON *item = cJSON_CreateObject();

    // v1_status->api_version
    if(v1_status->api_version) {
    if(cJSON_AddStringToObject(item, "apiVersion", v1_status->api_version) == NULL) {
    goto fail; //String
    }
    }


    // v1_status->code
    if(v1_status->code) {
    if(cJSON_AddNumberToObject(item, "code", v1_status->code) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_status->details
    if(v1_status->details) {
    cJSON *details_local_JSON = v1_status_details_convertToJSON(v1_status->details);
    if(details_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "details", details_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_status->kind
    if(v1_status->kind) {
    if(cJSON_AddStringToObject(item, "kind", v1_status->kind) == NULL) {
    goto fail; //String
    }
    }


    // v1_status->message
    if(v1_status->message) {
    if(cJSON_AddStringToObject(item, "message", v1_status->message) == NULL) {
    goto fail; //String
    }
    }


    // v1_status->metadata
    if(v1_status->metadata) {
    cJSON *metadata_local_JSON = v1_list_meta_convertToJSON(v1_status->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_status->reason
    if(v1_status->reason) {
    if(cJSON_AddStringToObject(item, "reason", v1_status->reason) == NULL) {
    goto fail; //String
    }
    }


    // v1_status->status
    if(v1_status->status) {
    if(cJSON_AddStringToObject(item, "status", v1_status->status) == NULL) {
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

v1_status_t *v1_status_parseFromJSON(cJSON *v1_statusJSON){

    v1_status_t *v1_status_local_var = NULL;

    // define the local variable for v1_status->details
    v1_status_details_t *details_local_nonprim = NULL;

    // define the local variable for v1_status->metadata
    v1_list_meta_t *metadata_local_nonprim = NULL;

    // v1_status->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1_statusJSON, "apiVersion");
    if (cJSON_IsNull(api_version)) {
        api_version = NULL;
    }
    if (api_version) { 
    if(!cJSON_IsString(api_version) && !cJSON_IsNull(api_version))
    {
    goto end; //String
    }
    }

    // v1_status->code
    cJSON *code = cJSON_GetObjectItemCaseSensitive(v1_statusJSON, "code");
    if (cJSON_IsNull(code)) {
        code = NULL;
    }
    if (code) { 
    if(!cJSON_IsNumber(code))
    {
    goto end; //Numeric
    }
    }

    // v1_status->details
    cJSON *details = cJSON_GetObjectItemCaseSensitive(v1_statusJSON, "details");
    if (cJSON_IsNull(details)) {
        details = NULL;
    }
    if (details) { 
    details_local_nonprim = v1_status_details_parseFromJSON(details); //nonprimitive
    }

    // v1_status->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_statusJSON, "kind");
    if (cJSON_IsNull(kind)) {
        kind = NULL;
    }
    if (kind) { 
    if(!cJSON_IsString(kind) && !cJSON_IsNull(kind))
    {
    goto end; //String
    }
    }

    // v1_status->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(v1_statusJSON, "message");
    if (cJSON_IsNull(message)) {
        message = NULL;
    }
    if (message) { 
    if(!cJSON_IsString(message) && !cJSON_IsNull(message))
    {
    goto end; //String
    }
    }

    // v1_status->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1_statusJSON, "metadata");
    if (cJSON_IsNull(metadata)) {
        metadata = NULL;
    }
    if (metadata) { 
    metadata_local_nonprim = v1_list_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1_status->reason
    cJSON *reason = cJSON_GetObjectItemCaseSensitive(v1_statusJSON, "reason");
    if (cJSON_IsNull(reason)) {
        reason = NULL;
    }
    if (reason) { 
    if(!cJSON_IsString(reason) && !cJSON_IsNull(reason))
    {
    goto end; //String
    }
    }

    // v1_status->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(v1_statusJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (status) { 
    if(!cJSON_IsString(status) && !cJSON_IsNull(status))
    {
    goto end; //String
    }
    }


    v1_status_local_var = v1_status_create_internal (
        api_version && !cJSON_IsNull(api_version) ? strdup(api_version->valuestring) : NULL,
        code ? code->valuedouble : 0,
        details ? details_local_nonprim : NULL,
        kind && !cJSON_IsNull(kind) ? strdup(kind->valuestring) : NULL,
        message && !cJSON_IsNull(message) ? strdup(message->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        reason && !cJSON_IsNull(reason) ? strdup(reason->valuestring) : NULL,
        status && !cJSON_IsNull(status) ? strdup(status->valuestring) : NULL
        );

    return v1_status_local_var;
end:
    if (details_local_nonprim) {
        v1_status_details_free(details_local_nonprim);
        details_local_nonprim = NULL;
    }
    if (metadata_local_nonprim) {
        v1_list_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    return NULL;

}
