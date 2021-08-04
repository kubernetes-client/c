#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_api_service_spec.h"



v1beta1_api_service_spec_t *v1beta1_api_service_spec_create(
    char *ca_bundle,
    char *group,
    int group_priority_minimum,
    int insecure_skip_tls_verify,
    apiregistration_v1beta1_service_reference_t *service,
    char *version,
    int version_priority
    ) {
    v1beta1_api_service_spec_t *v1beta1_api_service_spec_local_var = malloc(sizeof(v1beta1_api_service_spec_t));
    if (!v1beta1_api_service_spec_local_var) {
        return NULL;
    }
    v1beta1_api_service_spec_local_var->ca_bundle = ca_bundle;
    v1beta1_api_service_spec_local_var->group = group;
    v1beta1_api_service_spec_local_var->group_priority_minimum = group_priority_minimum;
    v1beta1_api_service_spec_local_var->insecure_skip_tls_verify = insecure_skip_tls_verify;
    v1beta1_api_service_spec_local_var->service = service;
    v1beta1_api_service_spec_local_var->version = version;
    v1beta1_api_service_spec_local_var->version_priority = version_priority;

    return v1beta1_api_service_spec_local_var;
}


void v1beta1_api_service_spec_free(v1beta1_api_service_spec_t *v1beta1_api_service_spec) {
    if(NULL == v1beta1_api_service_spec){
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta1_api_service_spec->ca_bundle) {
        free(v1beta1_api_service_spec->ca_bundle);
        v1beta1_api_service_spec->ca_bundle = NULL;
    }
    if (v1beta1_api_service_spec->group) {
        free(v1beta1_api_service_spec->group);
        v1beta1_api_service_spec->group = NULL;
    }
    if (v1beta1_api_service_spec->service) {
        apiregistration_v1beta1_service_reference_free(v1beta1_api_service_spec->service);
        v1beta1_api_service_spec->service = NULL;
    }
    if (v1beta1_api_service_spec->version) {
        free(v1beta1_api_service_spec->version);
        v1beta1_api_service_spec->version = NULL;
    }
    free(v1beta1_api_service_spec);
}

cJSON *v1beta1_api_service_spec_convertToJSON(v1beta1_api_service_spec_t *v1beta1_api_service_spec) {
    cJSON *item = cJSON_CreateObject();

    // v1beta1_api_service_spec->ca_bundle
    if(v1beta1_api_service_spec->ca_bundle) { 
    if(cJSON_AddStringToObject(item, "caBundle", v1beta1_api_service_spec->ca_bundle) == NULL) {
    goto fail; //ByteArray
    }
     } 


    // v1beta1_api_service_spec->group
    if(v1beta1_api_service_spec->group) { 
    if(cJSON_AddStringToObject(item, "group", v1beta1_api_service_spec->group) == NULL) {
    goto fail; //String
    }
     } 


    // v1beta1_api_service_spec->group_priority_minimum
    if (!v1beta1_api_service_spec->group_priority_minimum) {
        goto fail;
    }
    
    if(cJSON_AddNumberToObject(item, "groupPriorityMinimum", v1beta1_api_service_spec->group_priority_minimum) == NULL) {
    goto fail; //Numeric
    }


    // v1beta1_api_service_spec->insecure_skip_tls_verify
    if(v1beta1_api_service_spec->insecure_skip_tls_verify) { 
    if(cJSON_AddBoolToObject(item, "insecureSkipTLSVerify", v1beta1_api_service_spec->insecure_skip_tls_verify) == NULL) {
    goto fail; //Bool
    }
     } 


    // v1beta1_api_service_spec->service
    if (!v1beta1_api_service_spec->service) {
        goto fail;
    }
    
    cJSON *service_local_JSON = apiregistration_v1beta1_service_reference_convertToJSON(v1beta1_api_service_spec->service);
    if(service_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "service", service_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // v1beta1_api_service_spec->version
    if(v1beta1_api_service_spec->version) { 
    if(cJSON_AddStringToObject(item, "version", v1beta1_api_service_spec->version) == NULL) {
    goto fail; //String
    }
     } 


    // v1beta1_api_service_spec->version_priority
    if (!v1beta1_api_service_spec->version_priority) {
        goto fail;
    }
    
    if(cJSON_AddNumberToObject(item, "versionPriority", v1beta1_api_service_spec->version_priority) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1beta1_api_service_spec_t *v1beta1_api_service_spec_parseFromJSON(cJSON *v1beta1_api_service_specJSON){

    v1beta1_api_service_spec_t *v1beta1_api_service_spec_local_var = NULL;

    // v1beta1_api_service_spec->ca_bundle
    cJSON *ca_bundle = cJSON_GetObjectItemCaseSensitive(v1beta1_api_service_specJSON, "caBundle");
    if (ca_bundle) { 
    if(!cJSON_IsString(ca_bundle))
    {
    goto end; //ByteArray
    }
    }

    // v1beta1_api_service_spec->group
    cJSON *group = cJSON_GetObjectItemCaseSensitive(v1beta1_api_service_specJSON, "group");
    if (group) { 
    if(!cJSON_IsString(group))
    {
    goto end; //String
    }
    }

    // v1beta1_api_service_spec->group_priority_minimum
    cJSON *group_priority_minimum = cJSON_GetObjectItemCaseSensitive(v1beta1_api_service_specJSON, "groupPriorityMinimum");
    if (!group_priority_minimum) {
        goto end;
    }

    
    if(!cJSON_IsNumber(group_priority_minimum))
    {
    goto end; //Numeric
    }

    // v1beta1_api_service_spec->insecure_skip_tls_verify
    cJSON *insecure_skip_tls_verify = cJSON_GetObjectItemCaseSensitive(v1beta1_api_service_specJSON, "insecureSkipTLSVerify");
    if (insecure_skip_tls_verify) { 
    if(!cJSON_IsBool(insecure_skip_tls_verify))
    {
    goto end; //Bool
    }
    }

    // v1beta1_api_service_spec->service
    cJSON *service = cJSON_GetObjectItemCaseSensitive(v1beta1_api_service_specJSON, "service");
    if (!service) {
        goto end;
    }

    apiregistration_v1beta1_service_reference_t *service_local_nonprim = NULL;
    
    service_local_nonprim = apiregistration_v1beta1_service_reference_parseFromJSON(service); //nonprimitive

    // v1beta1_api_service_spec->version
    cJSON *version = cJSON_GetObjectItemCaseSensitive(v1beta1_api_service_specJSON, "version");
    if (version) { 
    if(!cJSON_IsString(version))
    {
    goto end; //String
    }
    }

    // v1beta1_api_service_spec->version_priority
    cJSON *version_priority = cJSON_GetObjectItemCaseSensitive(v1beta1_api_service_specJSON, "versionPriority");
    if (!version_priority) {
        goto end;
    }

    
    if(!cJSON_IsNumber(version_priority))
    {
    goto end; //Numeric
    }


    v1beta1_api_service_spec_local_var = v1beta1_api_service_spec_create (
        ca_bundle ? strdup(ca_bundle->valuestring) : NULL,
        group ? strdup(group->valuestring) : NULL,
        group_priority_minimum->valuedouble,
        insecure_skip_tls_verify ? insecure_skip_tls_verify->valueint : 0,
        service_local_nonprim,
        version ? strdup(version->valuestring) : NULL,
        version_priority->valuedouble
        );

    return v1beta1_api_service_spec_local_var;
end:
    if (service_local_nonprim) {
        apiregistration_v1beta1_service_reference_free(service_local_nonprim);
        service_local_nonprim = NULL;
    }
    return NULL;

}
