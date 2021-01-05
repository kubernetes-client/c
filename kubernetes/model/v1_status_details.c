#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_status_details.h"



v1_status_details_t *v1_status_details_create(
    list_t *causes,
    char *group,
    char *kind,
    char *name,
    int retry_after_seconds,
    char *uid
    ) {
    v1_status_details_t *v1_status_details_local_var = malloc(sizeof(v1_status_details_t));
    if (!v1_status_details_local_var) {
        return NULL;
    }
    v1_status_details_local_var->causes = causes;
    v1_status_details_local_var->group = group;
    v1_status_details_local_var->kind = kind;
    v1_status_details_local_var->name = name;
    v1_status_details_local_var->retry_after_seconds = retry_after_seconds;
    v1_status_details_local_var->uid = uid;

    return v1_status_details_local_var;
}


void v1_status_details_free(v1_status_details_t *v1_status_details) {
    if(NULL == v1_status_details){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_status_details->causes) {
        list_ForEach(listEntry, v1_status_details->causes) {
            v1_status_cause_free(listEntry->data);
        }
        list_free(v1_status_details->causes);
        v1_status_details->causes = NULL;
    }
    if (v1_status_details->group) {
        free(v1_status_details->group);
        v1_status_details->group = NULL;
    }
    if (v1_status_details->kind) {
        free(v1_status_details->kind);
        v1_status_details->kind = NULL;
    }
    if (v1_status_details->name) {
        free(v1_status_details->name);
        v1_status_details->name = NULL;
    }
    if (v1_status_details->uid) {
        free(v1_status_details->uid);
        v1_status_details->uid = NULL;
    }
    free(v1_status_details);
}

cJSON *v1_status_details_convertToJSON(v1_status_details_t *v1_status_details) {
    cJSON *item = cJSON_CreateObject();

    // v1_status_details->causes
    if(v1_status_details->causes) { 
    cJSON *causes = cJSON_AddArrayToObject(item, "causes");
    if(causes == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *causesListEntry;
    if (v1_status_details->causes) {
    list_ForEach(causesListEntry, v1_status_details->causes) {
    cJSON *itemLocal = v1_status_cause_convertToJSON(causesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(causes, itemLocal);
    }
    }
     } 


    // v1_status_details->group
    if(v1_status_details->group) { 
    if(cJSON_AddStringToObject(item, "group", v1_status_details->group) == NULL) {
    goto fail; //String
    }
     } 


    // v1_status_details->kind
    if(v1_status_details->kind) { 
    if(cJSON_AddStringToObject(item, "kind", v1_status_details->kind) == NULL) {
    goto fail; //String
    }
     } 


    // v1_status_details->name
    if(v1_status_details->name) { 
    if(cJSON_AddStringToObject(item, "name", v1_status_details->name) == NULL) {
    goto fail; //String
    }
     } 


    // v1_status_details->retry_after_seconds
    if(v1_status_details->retry_after_seconds) { 
    if(cJSON_AddNumberToObject(item, "retryAfterSeconds", v1_status_details->retry_after_seconds) == NULL) {
    goto fail; //Numeric
    }
     } 


    // v1_status_details->uid
    if(v1_status_details->uid) { 
    if(cJSON_AddStringToObject(item, "uid", v1_status_details->uid) == NULL) {
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

v1_status_details_t *v1_status_details_parseFromJSON(cJSON *v1_status_detailsJSON){

    v1_status_details_t *v1_status_details_local_var = NULL;

    // v1_status_details->causes
    cJSON *causes = cJSON_GetObjectItemCaseSensitive(v1_status_detailsJSON, "causes");
    list_t *causesList;
    if (causes) { 
    cJSON *causes_local_nonprimitive;
    if(!cJSON_IsArray(causes)){
        goto end; //nonprimitive container
    }

    causesList = list_create();

    cJSON_ArrayForEach(causes_local_nonprimitive,causes )
    {
        if(!cJSON_IsObject(causes_local_nonprimitive)){
            goto end;
        }
        v1_status_cause_t *causesItem = v1_status_cause_parseFromJSON(causes_local_nonprimitive);

        list_addElement(causesList, causesItem);
    }
    }

    // v1_status_details->group
    cJSON *group = cJSON_GetObjectItemCaseSensitive(v1_status_detailsJSON, "group");
    if (group) { 
    if(!cJSON_IsString(group))
    {
    goto end; //String
    }
    }

    // v1_status_details->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_status_detailsJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // v1_status_details->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1_status_detailsJSON, "name");
    if (name) { 
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }
    }

    // v1_status_details->retry_after_seconds
    cJSON *retry_after_seconds = cJSON_GetObjectItemCaseSensitive(v1_status_detailsJSON, "retryAfterSeconds");
    if (retry_after_seconds) { 
    if(!cJSON_IsNumber(retry_after_seconds))
    {
    goto end; //Numeric
    }
    }

    // v1_status_details->uid
    cJSON *uid = cJSON_GetObjectItemCaseSensitive(v1_status_detailsJSON, "uid");
    if (uid) { 
    if(!cJSON_IsString(uid))
    {
    goto end; //String
    }
    }


    v1_status_details_local_var = v1_status_details_create (
        causes ? causesList : NULL,
        group ? strdup(group->valuestring) : NULL,
        kind ? strdup(kind->valuestring) : NULL,
        name ? strdup(name->valuestring) : NULL,
        retry_after_seconds ? retry_after_seconds->valuedouble : 0,
        uid ? strdup(uid->valuestring) : NULL
        );

    return v1_status_details_local_var;
end:
    return NULL;

}
