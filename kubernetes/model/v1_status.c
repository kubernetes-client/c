#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_status.h"



v1_status_t *v1_status_create(
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

    return v1_status_local_var;
}


void v1_status_free(v1_status_t *v1_status) {
    if(NULL == v1_status){
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

    // v1_status->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1_statusJSON, "apiVersion");
    if (api_version) { 
    if(!cJSON_IsString(api_version))
    {
    goto end; //String
    }
    }

    // v1_status->code
    cJSON *code = cJSON_GetObjectItemCaseSensitive(v1_statusJSON, "code");
    if (code) { 
    if(!cJSON_IsNumber(code))
    {
    goto end; //Numeric
    }
    }

    // v1_status->details
    cJSON *details = cJSON_GetObjectItemCaseSensitive(v1_statusJSON, "details");
    v1_status_details_t *details_local_nonprim = NULL;
    if (details) { 
    details_local_nonprim = v1_status_details_parseFromJSON(details); //nonprimitive
    }

    // v1_status->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_statusJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // v1_status->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(v1_statusJSON, "message");
    if (message) { 
    if(!cJSON_IsString(message))
    {
    goto end; //String
    }
    }

    // v1_status->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1_statusJSON, "metadata");
    v1_list_meta_t *metadata_local_nonprim = NULL;
    if (metadata) { 
    metadata_local_nonprim = v1_list_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1_status->reason
    cJSON *reason = cJSON_GetObjectItemCaseSensitive(v1_statusJSON, "reason");
    if (reason) { 
    if(!cJSON_IsString(reason))
    {
    goto end; //String
    }
    }

    // v1_status->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(v1_statusJSON, "status");
    if (status) { 
    if(!cJSON_IsString(status))
    {
    goto end; //String
    }
    }


    v1_status_local_var = v1_status_create (
        api_version ? strdup(api_version->valuestring) : NULL,
        code ? code->valuedouble : 0,
        details ? details_local_nonprim : NULL,
        kind ? strdup(kind->valuestring) : NULL,
        message ? strdup(message->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        reason ? strdup(reason->valuestring) : NULL,
        status ? strdup(status->valuestring) : NULL
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
