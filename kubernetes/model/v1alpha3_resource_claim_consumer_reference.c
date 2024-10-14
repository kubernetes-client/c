#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha3_resource_claim_consumer_reference.h"



v1alpha3_resource_claim_consumer_reference_t *v1alpha3_resource_claim_consumer_reference_create(
    char *api_group,
    char *name,
    char *resource,
    char *uid
    ) {
    v1alpha3_resource_claim_consumer_reference_t *v1alpha3_resource_claim_consumer_reference_local_var = malloc(sizeof(v1alpha3_resource_claim_consumer_reference_t));
    if (!v1alpha3_resource_claim_consumer_reference_local_var) {
        return NULL;
    }
    v1alpha3_resource_claim_consumer_reference_local_var->api_group = api_group;
    v1alpha3_resource_claim_consumer_reference_local_var->name = name;
    v1alpha3_resource_claim_consumer_reference_local_var->resource = resource;
    v1alpha3_resource_claim_consumer_reference_local_var->uid = uid;

    return v1alpha3_resource_claim_consumer_reference_local_var;
}


void v1alpha3_resource_claim_consumer_reference_free(v1alpha3_resource_claim_consumer_reference_t *v1alpha3_resource_claim_consumer_reference) {
    if(NULL == v1alpha3_resource_claim_consumer_reference){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha3_resource_claim_consumer_reference->api_group) {
        free(v1alpha3_resource_claim_consumer_reference->api_group);
        v1alpha3_resource_claim_consumer_reference->api_group = NULL;
    }
    if (v1alpha3_resource_claim_consumer_reference->name) {
        free(v1alpha3_resource_claim_consumer_reference->name);
        v1alpha3_resource_claim_consumer_reference->name = NULL;
    }
    if (v1alpha3_resource_claim_consumer_reference->resource) {
        free(v1alpha3_resource_claim_consumer_reference->resource);
        v1alpha3_resource_claim_consumer_reference->resource = NULL;
    }
    if (v1alpha3_resource_claim_consumer_reference->uid) {
        free(v1alpha3_resource_claim_consumer_reference->uid);
        v1alpha3_resource_claim_consumer_reference->uid = NULL;
    }
    free(v1alpha3_resource_claim_consumer_reference);
}

cJSON *v1alpha3_resource_claim_consumer_reference_convertToJSON(v1alpha3_resource_claim_consumer_reference_t *v1alpha3_resource_claim_consumer_reference) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha3_resource_claim_consumer_reference->api_group
    if(v1alpha3_resource_claim_consumer_reference->api_group) {
    if(cJSON_AddStringToObject(item, "apiGroup", v1alpha3_resource_claim_consumer_reference->api_group) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha3_resource_claim_consumer_reference->name
    if (!v1alpha3_resource_claim_consumer_reference->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", v1alpha3_resource_claim_consumer_reference->name) == NULL) {
    goto fail; //String
    }


    // v1alpha3_resource_claim_consumer_reference->resource
    if (!v1alpha3_resource_claim_consumer_reference->resource) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "resource", v1alpha3_resource_claim_consumer_reference->resource) == NULL) {
    goto fail; //String
    }


    // v1alpha3_resource_claim_consumer_reference->uid
    if (!v1alpha3_resource_claim_consumer_reference->uid) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "uid", v1alpha3_resource_claim_consumer_reference->uid) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1alpha3_resource_claim_consumer_reference_t *v1alpha3_resource_claim_consumer_reference_parseFromJSON(cJSON *v1alpha3_resource_claim_consumer_referenceJSON){

    v1alpha3_resource_claim_consumer_reference_t *v1alpha3_resource_claim_consumer_reference_local_var = NULL;

    // v1alpha3_resource_claim_consumer_reference->api_group
    cJSON *api_group = cJSON_GetObjectItemCaseSensitive(v1alpha3_resource_claim_consumer_referenceJSON, "apiGroup");
    if (api_group) { 
    if(!cJSON_IsString(api_group) && !cJSON_IsNull(api_group))
    {
    goto end; //String
    }
    }

    // v1alpha3_resource_claim_consumer_reference->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1alpha3_resource_claim_consumer_referenceJSON, "name");
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // v1alpha3_resource_claim_consumer_reference->resource
    cJSON *resource = cJSON_GetObjectItemCaseSensitive(v1alpha3_resource_claim_consumer_referenceJSON, "resource");
    if (!resource) {
        goto end;
    }

    
    if(!cJSON_IsString(resource))
    {
    goto end; //String
    }

    // v1alpha3_resource_claim_consumer_reference->uid
    cJSON *uid = cJSON_GetObjectItemCaseSensitive(v1alpha3_resource_claim_consumer_referenceJSON, "uid");
    if (!uid) {
        goto end;
    }

    
    if(!cJSON_IsString(uid))
    {
    goto end; //String
    }


    v1alpha3_resource_claim_consumer_reference_local_var = v1alpha3_resource_claim_consumer_reference_create (
        api_group && !cJSON_IsNull(api_group) ? strdup(api_group->valuestring) : NULL,
        strdup(name->valuestring),
        strdup(resource->valuestring),
        strdup(uid->valuestring)
        );

    return v1alpha3_resource_claim_consumer_reference_local_var;
end:
    return NULL;

}
