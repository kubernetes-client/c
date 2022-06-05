#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_endpoint_slice.h"



v1_endpoint_slice_t *v1_endpoint_slice_create(
    char *address_type,
    char *api_version,
    list_t *endpoints,
    char *kind,
    v1_object_meta_t *metadata,
    list_t *ports
    ) {
    v1_endpoint_slice_t *v1_endpoint_slice_local_var = malloc(sizeof(v1_endpoint_slice_t));
    if (!v1_endpoint_slice_local_var) {
        return NULL;
    }
    v1_endpoint_slice_local_var->address_type = address_type;
    v1_endpoint_slice_local_var->api_version = api_version;
    v1_endpoint_slice_local_var->endpoints = endpoints;
    v1_endpoint_slice_local_var->kind = kind;
    v1_endpoint_slice_local_var->metadata = metadata;
    v1_endpoint_slice_local_var->ports = ports;

    return v1_endpoint_slice_local_var;
}


void v1_endpoint_slice_free(v1_endpoint_slice_t *v1_endpoint_slice) {
    if(NULL == v1_endpoint_slice){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_endpoint_slice->address_type) {
        free(v1_endpoint_slice->address_type);
        v1_endpoint_slice->address_type = NULL;
    }
    if (v1_endpoint_slice->api_version) {
        free(v1_endpoint_slice->api_version);
        v1_endpoint_slice->api_version = NULL;
    }
    if (v1_endpoint_slice->endpoints) {
        list_ForEach(listEntry, v1_endpoint_slice->endpoints) {
            v1_endpoint_free(listEntry->data);
        }
        list_freeList(v1_endpoint_slice->endpoints);
        v1_endpoint_slice->endpoints = NULL;
    }
    if (v1_endpoint_slice->kind) {
        free(v1_endpoint_slice->kind);
        v1_endpoint_slice->kind = NULL;
    }
    if (v1_endpoint_slice->metadata) {
        v1_object_meta_free(v1_endpoint_slice->metadata);
        v1_endpoint_slice->metadata = NULL;
    }
    if (v1_endpoint_slice->ports) {
        list_ForEach(listEntry, v1_endpoint_slice->ports) {
            discovery_v1_endpoint_port_free(listEntry->data);
        }
        list_freeList(v1_endpoint_slice->ports);
        v1_endpoint_slice->ports = NULL;
    }
    free(v1_endpoint_slice);
}

cJSON *v1_endpoint_slice_convertToJSON(v1_endpoint_slice_t *v1_endpoint_slice) {
    cJSON *item = cJSON_CreateObject();

    // v1_endpoint_slice->address_type
    if (!v1_endpoint_slice->address_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "addressType", v1_endpoint_slice->address_type) == NULL) {
    goto fail; //String
    }


    // v1_endpoint_slice->api_version
    if(v1_endpoint_slice->api_version) {
    if(cJSON_AddStringToObject(item, "apiVersion", v1_endpoint_slice->api_version) == NULL) {
    goto fail; //String
    }
    }


    // v1_endpoint_slice->endpoints
    if (!v1_endpoint_slice->endpoints) {
        goto fail;
    }
    cJSON *endpoints = cJSON_AddArrayToObject(item, "endpoints");
    if(endpoints == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *endpointsListEntry;
    if (v1_endpoint_slice->endpoints) {
    list_ForEach(endpointsListEntry, v1_endpoint_slice->endpoints) {
    cJSON *itemLocal = v1_endpoint_convertToJSON(endpointsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(endpoints, itemLocal);
    }
    }


    // v1_endpoint_slice->kind
    if(v1_endpoint_slice->kind) {
    if(cJSON_AddStringToObject(item, "kind", v1_endpoint_slice->kind) == NULL) {
    goto fail; //String
    }
    }


    // v1_endpoint_slice->metadata
    if(v1_endpoint_slice->metadata) {
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1_endpoint_slice->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_endpoint_slice->ports
    if(v1_endpoint_slice->ports) {
    cJSON *ports = cJSON_AddArrayToObject(item, "ports");
    if(ports == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *portsListEntry;
    if (v1_endpoint_slice->ports) {
    list_ForEach(portsListEntry, v1_endpoint_slice->ports) {
    cJSON *itemLocal = discovery_v1_endpoint_port_convertToJSON(portsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(ports, itemLocal);
    }
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_endpoint_slice_t *v1_endpoint_slice_parseFromJSON(cJSON *v1_endpoint_sliceJSON){

    v1_endpoint_slice_t *v1_endpoint_slice_local_var = NULL;

    // define the local list for v1_endpoint_slice->endpoints
    list_t *endpointsList = NULL;

    // define the local variable for v1_endpoint_slice->metadata
    v1_object_meta_t *metadata_local_nonprim = NULL;

    // define the local list for v1_endpoint_slice->ports
    list_t *portsList = NULL;

    // v1_endpoint_slice->address_type
    cJSON *address_type = cJSON_GetObjectItemCaseSensitive(v1_endpoint_sliceJSON, "addressType");
    if (!address_type) {
        goto end;
    }

    
    if(!cJSON_IsString(address_type))
    {
    goto end; //String
    }

    // v1_endpoint_slice->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1_endpoint_sliceJSON, "apiVersion");
    if (api_version) { 
    if(!cJSON_IsString(api_version))
    {
    goto end; //String
    }
    }

    // v1_endpoint_slice->endpoints
    cJSON *endpoints = cJSON_GetObjectItemCaseSensitive(v1_endpoint_sliceJSON, "endpoints");
    if (!endpoints) {
        goto end;
    }

    
    cJSON *endpoints_local_nonprimitive = NULL;
    if(!cJSON_IsArray(endpoints)){
        goto end; //nonprimitive container
    }

    endpointsList = list_createList();

    cJSON_ArrayForEach(endpoints_local_nonprimitive,endpoints )
    {
        if(!cJSON_IsObject(endpoints_local_nonprimitive)){
            goto end;
        }
        v1_endpoint_t *endpointsItem = v1_endpoint_parseFromJSON(endpoints_local_nonprimitive);

        list_addElement(endpointsList, endpointsItem);
    }

    // v1_endpoint_slice->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_endpoint_sliceJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // v1_endpoint_slice->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1_endpoint_sliceJSON, "metadata");
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1_endpoint_slice->ports
    cJSON *ports = cJSON_GetObjectItemCaseSensitive(v1_endpoint_sliceJSON, "ports");
    if (ports) { 
    cJSON *ports_local_nonprimitive = NULL;
    if(!cJSON_IsArray(ports)){
        goto end; //nonprimitive container
    }

    portsList = list_createList();

    cJSON_ArrayForEach(ports_local_nonprimitive,ports )
    {
        if(!cJSON_IsObject(ports_local_nonprimitive)){
            goto end;
        }
        discovery_v1_endpoint_port_t *portsItem = discovery_v1_endpoint_port_parseFromJSON(ports_local_nonprimitive);

        list_addElement(portsList, portsItem);
    }
    }


    v1_endpoint_slice_local_var = v1_endpoint_slice_create (
        strdup(address_type->valuestring),
        api_version ? strdup(api_version->valuestring) : NULL,
        endpointsList,
        kind ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        ports ? portsList : NULL
        );

    return v1_endpoint_slice_local_var;
end:
    if (endpointsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, endpointsList) {
            v1_endpoint_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(endpointsList);
        endpointsList = NULL;
    }
    if (metadata_local_nonprim) {
        v1_object_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    if (portsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, portsList) {
            discovery_v1_endpoint_port_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(portsList);
        portsList = NULL;
    }
    return NULL;

}
