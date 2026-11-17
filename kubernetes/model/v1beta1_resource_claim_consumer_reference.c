#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_resource_claim_consumer_reference.h"



static v1beta1_resource_claim_consumer_reference_t *v1beta1_resource_claim_consumer_reference_create_internal(
    char *api_group,
    char *name,
    char *resource,
    char *uid
    ) {
    v1beta1_resource_claim_consumer_reference_t *v1beta1_resource_claim_consumer_reference_local_var = malloc(sizeof(v1beta1_resource_claim_consumer_reference_t));
    if (!v1beta1_resource_claim_consumer_reference_local_var) {
        return NULL;
    }
    memset(v1beta1_resource_claim_consumer_reference_local_var, 0, sizeof(v1beta1_resource_claim_consumer_reference_t));
    v1beta1_resource_claim_consumer_reference_local_var->_library_owned = 1;
    v1beta1_resource_claim_consumer_reference_local_var->api_group = api_group;
    v1beta1_resource_claim_consumer_reference_local_var->name = name;
    v1beta1_resource_claim_consumer_reference_local_var->resource = resource;
    v1beta1_resource_claim_consumer_reference_local_var->uid = uid;
    return v1beta1_resource_claim_consumer_reference_local_var;
}

__attribute__((deprecated)) v1beta1_resource_claim_consumer_reference_t *v1beta1_resource_claim_consumer_reference_create(
    char *api_group,
    char *name,
    char *resource,
    char *uid
    ) {
    v1beta1_resource_claim_consumer_reference_t *result = v1beta1_resource_claim_consumer_reference_create_internal (
        api_group,
        name,
        resource,
        uid
        );
    if (!result) {
    }
    return result;
}

void v1beta1_resource_claim_consumer_reference_free(v1beta1_resource_claim_consumer_reference_t *v1beta1_resource_claim_consumer_reference) {
    if(NULL == v1beta1_resource_claim_consumer_reference){
        return ;
    }
    if(v1beta1_resource_claim_consumer_reference->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1beta1_resource_claim_consumer_reference_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta1_resource_claim_consumer_reference->api_group) {
        free(v1beta1_resource_claim_consumer_reference->api_group);
        v1beta1_resource_claim_consumer_reference->api_group = NULL;
    }
    if (v1beta1_resource_claim_consumer_reference->name) {
        free(v1beta1_resource_claim_consumer_reference->name);
        v1beta1_resource_claim_consumer_reference->name = NULL;
    }
    if (v1beta1_resource_claim_consumer_reference->resource) {
        free(v1beta1_resource_claim_consumer_reference->resource);
        v1beta1_resource_claim_consumer_reference->resource = NULL;
    }
    if (v1beta1_resource_claim_consumer_reference->uid) {
        free(v1beta1_resource_claim_consumer_reference->uid);
        v1beta1_resource_claim_consumer_reference->uid = NULL;
    }
    free(v1beta1_resource_claim_consumer_reference);
}

cJSON *v1beta1_resource_claim_consumer_reference_convertToJSON(v1beta1_resource_claim_consumer_reference_t *v1beta1_resource_claim_consumer_reference) {
    cJSON *item = cJSON_CreateObject();

    // v1beta1_resource_claim_consumer_reference->api_group
    if(v1beta1_resource_claim_consumer_reference->api_group) {
    if(cJSON_AddStringToObject(item, "apiGroup", v1beta1_resource_claim_consumer_reference->api_group) == NULL) {
    goto fail; //String
    }
    }


    // v1beta1_resource_claim_consumer_reference->name
    if (!v1beta1_resource_claim_consumer_reference->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", v1beta1_resource_claim_consumer_reference->name) == NULL) {
    goto fail; //String
    }


    // v1beta1_resource_claim_consumer_reference->resource
    if (!v1beta1_resource_claim_consumer_reference->resource) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "resource", v1beta1_resource_claim_consumer_reference->resource) == NULL) {
    goto fail; //String
    }


    // v1beta1_resource_claim_consumer_reference->uid
    if (!v1beta1_resource_claim_consumer_reference->uid) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "uid", v1beta1_resource_claim_consumer_reference->uid) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1beta1_resource_claim_consumer_reference_t *v1beta1_resource_claim_consumer_reference_parseFromJSON(cJSON *v1beta1_resource_claim_consumer_referenceJSON){

    v1beta1_resource_claim_consumer_reference_t *v1beta1_resource_claim_consumer_reference_local_var = NULL;

    char *api_group_local_str = NULL;

    char *name_local_str = NULL;

    char *resource_local_str = NULL;

    char *uid_local_str = NULL;

    // v1beta1_resource_claim_consumer_reference->api_group
    cJSON *api_group = cJSON_GetObjectItemCaseSensitive(v1beta1_resource_claim_consumer_referenceJSON, "apiGroup");
    if (cJSON_IsNull(api_group)) {
        api_group = NULL;
    }
    if (api_group) { 
    if(!cJSON_IsString(api_group) && !cJSON_IsNull(api_group))
    {
    goto end; //String
    }
    }

    // v1beta1_resource_claim_consumer_reference->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1beta1_resource_claim_consumer_referenceJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // v1beta1_resource_claim_consumer_reference->resource
    cJSON *resource = cJSON_GetObjectItemCaseSensitive(v1beta1_resource_claim_consumer_referenceJSON, "resource");
    if (cJSON_IsNull(resource)) {
        resource = NULL;
    }
    if (!resource) {
        goto end;
    }

    
    if(!cJSON_IsString(resource))
    {
    goto end; //String
    }

    // v1beta1_resource_claim_consumer_reference->uid
    cJSON *uid = cJSON_GetObjectItemCaseSensitive(v1beta1_resource_claim_consumer_referenceJSON, "uid");
    if (cJSON_IsNull(uid)) {
        uid = NULL;
    }
    if (!uid) {
        goto end;
    }

    
    if(!cJSON_IsString(uid))
    {
    goto end; //String
    }


    if (api_group && !cJSON_IsNull(api_group)) api_group_local_str = strdup(api_group->valuestring);
    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);
    if (resource && !cJSON_IsNull(resource)) resource_local_str = strdup(resource->valuestring);
    if (uid && !cJSON_IsNull(uid)) uid_local_str = strdup(uid->valuestring);

    v1beta1_resource_claim_consumer_reference_local_var = v1beta1_resource_claim_consumer_reference_create_internal (
        api_group_local_str,
        name_local_str,
        resource_local_str,
        uid_local_str
        );

    if (!v1beta1_resource_claim_consumer_reference_local_var) {
        goto end;
    }

    return v1beta1_resource_claim_consumer_reference_local_var;
end:
    if (api_group_local_str) {
        free(api_group_local_str);
        api_group_local_str = NULL;
    }
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    if (resource_local_str) {
        free(resource_local_str);
        resource_local_str = NULL;
    }
    if (uid_local_str) {
        free(uid_local_str);
        uid_local_str = NULL;
    }
    return NULL;

}
