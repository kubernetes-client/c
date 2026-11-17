#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_endpoint_address.h"



static v1_endpoint_address_t *v1_endpoint_address_create_internal(
    char *hostname,
    char *ip,
    char *node_name,
    v1_object_reference_t *target_ref
    ) {
    v1_endpoint_address_t *v1_endpoint_address_local_var = malloc(sizeof(v1_endpoint_address_t));
    if (!v1_endpoint_address_local_var) {
        return NULL;
    }
    memset(v1_endpoint_address_local_var, 0, sizeof(v1_endpoint_address_t));
    v1_endpoint_address_local_var->_library_owned = 1;
    v1_endpoint_address_local_var->hostname = hostname;
    v1_endpoint_address_local_var->ip = ip;
    v1_endpoint_address_local_var->node_name = node_name;
    v1_endpoint_address_local_var->target_ref = target_ref;
    return v1_endpoint_address_local_var;
}

__attribute__((deprecated)) v1_endpoint_address_t *v1_endpoint_address_create(
    char *hostname,
    char *ip,
    char *node_name,
    v1_object_reference_t *target_ref
    ) {
    v1_endpoint_address_t *result = v1_endpoint_address_create_internal (
        hostname,
        ip,
        node_name,
        target_ref
        );
    if (!result) {
    }
    return result;
}

void v1_endpoint_address_free(v1_endpoint_address_t *v1_endpoint_address) {
    if(NULL == v1_endpoint_address){
        return ;
    }
    if(v1_endpoint_address->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_endpoint_address_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_endpoint_address->hostname) {
        free(v1_endpoint_address->hostname);
        v1_endpoint_address->hostname = NULL;
    }
    if (v1_endpoint_address->ip) {
        free(v1_endpoint_address->ip);
        v1_endpoint_address->ip = NULL;
    }
    if (v1_endpoint_address->node_name) {
        free(v1_endpoint_address->node_name);
        v1_endpoint_address->node_name = NULL;
    }
    if (v1_endpoint_address->target_ref) {
        v1_object_reference_free(v1_endpoint_address->target_ref);
        v1_endpoint_address->target_ref = NULL;
    }
    free(v1_endpoint_address);
}

cJSON *v1_endpoint_address_convertToJSON(v1_endpoint_address_t *v1_endpoint_address) {
    cJSON *item = cJSON_CreateObject();

    // v1_endpoint_address->hostname
    if(v1_endpoint_address->hostname) {
    if(cJSON_AddStringToObject(item, "hostname", v1_endpoint_address->hostname) == NULL) {
    goto fail; //String
    }
    }


    // v1_endpoint_address->ip
    if (!v1_endpoint_address->ip) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "ip", v1_endpoint_address->ip) == NULL) {
    goto fail; //String
    }


    // v1_endpoint_address->node_name
    if(v1_endpoint_address->node_name) {
    if(cJSON_AddStringToObject(item, "nodeName", v1_endpoint_address->node_name) == NULL) {
    goto fail; //String
    }
    }


    // v1_endpoint_address->target_ref
    if(v1_endpoint_address->target_ref) {
    cJSON *target_ref_local_JSON = v1_object_reference_convertToJSON(v1_endpoint_address->target_ref);
    if(target_ref_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "targetRef", target_ref_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_endpoint_address_t *v1_endpoint_address_parseFromJSON(cJSON *v1_endpoint_addressJSON){

    v1_endpoint_address_t *v1_endpoint_address_local_var = NULL;

    char *hostname_local_str = NULL;

    char *ip_local_str = NULL;

    char *node_name_local_str = NULL;

    // define the local variable for v1_endpoint_address->target_ref
    v1_object_reference_t *target_ref_local_nonprim = NULL;

    // v1_endpoint_address->hostname
    cJSON *hostname = cJSON_GetObjectItemCaseSensitive(v1_endpoint_addressJSON, "hostname");
    if (cJSON_IsNull(hostname)) {
        hostname = NULL;
    }
    if (hostname) { 
    if(!cJSON_IsString(hostname) && !cJSON_IsNull(hostname))
    {
    goto end; //String
    }
    }

    // v1_endpoint_address->ip
    cJSON *ip = cJSON_GetObjectItemCaseSensitive(v1_endpoint_addressJSON, "ip");
    if (cJSON_IsNull(ip)) {
        ip = NULL;
    }
    if (!ip) {
        goto end;
    }

    
    if(!cJSON_IsString(ip))
    {
    goto end; //String
    }

    // v1_endpoint_address->node_name
    cJSON *node_name = cJSON_GetObjectItemCaseSensitive(v1_endpoint_addressJSON, "nodeName");
    if (cJSON_IsNull(node_name)) {
        node_name = NULL;
    }
    if (node_name) { 
    if(!cJSON_IsString(node_name) && !cJSON_IsNull(node_name))
    {
    goto end; //String
    }
    }

    // v1_endpoint_address->target_ref
    cJSON *target_ref = cJSON_GetObjectItemCaseSensitive(v1_endpoint_addressJSON, "targetRef");
    if (cJSON_IsNull(target_ref)) {
        target_ref = NULL;
    }
    if (target_ref) { 
    target_ref_local_nonprim = v1_object_reference_parseFromJSON(target_ref); //nonprimitive
    }


    if (hostname && !cJSON_IsNull(hostname)) hostname_local_str = strdup(hostname->valuestring);
    if (ip && !cJSON_IsNull(ip)) ip_local_str = strdup(ip->valuestring);
    if (node_name && !cJSON_IsNull(node_name)) node_name_local_str = strdup(node_name->valuestring);

    v1_endpoint_address_local_var = v1_endpoint_address_create_internal (
        hostname_local_str,
        ip_local_str,
        node_name_local_str,
        target_ref ? target_ref_local_nonprim : NULL
        );

    if (!v1_endpoint_address_local_var) {
        goto end;
    }

    return v1_endpoint_address_local_var;
end:
    if (hostname_local_str) {
        free(hostname_local_str);
        hostname_local_str = NULL;
    }
    if (ip_local_str) {
        free(ip_local_str);
        ip_local_str = NULL;
    }
    if (node_name_local_str) {
        free(node_name_local_str);
        node_name_local_str = NULL;
    }
    if (target_ref_local_nonprim) {
        v1_object_reference_free(target_ref_local_nonprim);
        target_ref_local_nonprim = NULL;
    }
    return NULL;

}
