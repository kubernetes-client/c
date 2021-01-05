#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_endpoint_subset.h"



v1_endpoint_subset_t *v1_endpoint_subset_create(
    list_t *addresses,
    list_t *not_ready_addresses,
    list_t *ports
    ) {
    v1_endpoint_subset_t *v1_endpoint_subset_local_var = malloc(sizeof(v1_endpoint_subset_t));
    if (!v1_endpoint_subset_local_var) {
        return NULL;
    }
    v1_endpoint_subset_local_var->addresses = addresses;
    v1_endpoint_subset_local_var->not_ready_addresses = not_ready_addresses;
    v1_endpoint_subset_local_var->ports = ports;

    return v1_endpoint_subset_local_var;
}


void v1_endpoint_subset_free(v1_endpoint_subset_t *v1_endpoint_subset) {
    if(NULL == v1_endpoint_subset){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_endpoint_subset->addresses) {
        list_ForEach(listEntry, v1_endpoint_subset->addresses) {
            v1_endpoint_address_free(listEntry->data);
        }
        list_free(v1_endpoint_subset->addresses);
        v1_endpoint_subset->addresses = NULL;
    }
    if (v1_endpoint_subset->not_ready_addresses) {
        list_ForEach(listEntry, v1_endpoint_subset->not_ready_addresses) {
            v1_endpoint_address_free(listEntry->data);
        }
        list_free(v1_endpoint_subset->not_ready_addresses);
        v1_endpoint_subset->not_ready_addresses = NULL;
    }
    if (v1_endpoint_subset->ports) {
        list_ForEach(listEntry, v1_endpoint_subset->ports) {
            v1_endpoint_port_free(listEntry->data);
        }
        list_free(v1_endpoint_subset->ports);
        v1_endpoint_subset->ports = NULL;
    }
    free(v1_endpoint_subset);
}

cJSON *v1_endpoint_subset_convertToJSON(v1_endpoint_subset_t *v1_endpoint_subset) {
    cJSON *item = cJSON_CreateObject();

    // v1_endpoint_subset->addresses
    if(v1_endpoint_subset->addresses) { 
    cJSON *addresses = cJSON_AddArrayToObject(item, "addresses");
    if(addresses == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *addressesListEntry;
    if (v1_endpoint_subset->addresses) {
    list_ForEach(addressesListEntry, v1_endpoint_subset->addresses) {
    cJSON *itemLocal = v1_endpoint_address_convertToJSON(addressesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(addresses, itemLocal);
    }
    }
     } 


    // v1_endpoint_subset->not_ready_addresses
    if(v1_endpoint_subset->not_ready_addresses) { 
    cJSON *not_ready_addresses = cJSON_AddArrayToObject(item, "notReadyAddresses");
    if(not_ready_addresses == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *not_ready_addressesListEntry;
    if (v1_endpoint_subset->not_ready_addresses) {
    list_ForEach(not_ready_addressesListEntry, v1_endpoint_subset->not_ready_addresses) {
    cJSON *itemLocal = v1_endpoint_address_convertToJSON(not_ready_addressesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(not_ready_addresses, itemLocal);
    }
    }
     } 


    // v1_endpoint_subset->ports
    if(v1_endpoint_subset->ports) { 
    cJSON *ports = cJSON_AddArrayToObject(item, "ports");
    if(ports == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *portsListEntry;
    if (v1_endpoint_subset->ports) {
    list_ForEach(portsListEntry, v1_endpoint_subset->ports) {
    cJSON *itemLocal = v1_endpoint_port_convertToJSON(portsListEntry->data);
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

v1_endpoint_subset_t *v1_endpoint_subset_parseFromJSON(cJSON *v1_endpoint_subsetJSON){

    v1_endpoint_subset_t *v1_endpoint_subset_local_var = NULL;

    // v1_endpoint_subset->addresses
    cJSON *addresses = cJSON_GetObjectItemCaseSensitive(v1_endpoint_subsetJSON, "addresses");
    list_t *addressesList;
    if (addresses) { 
    cJSON *addresses_local_nonprimitive;
    if(!cJSON_IsArray(addresses)){
        goto end; //nonprimitive container
    }

    addressesList = list_create();

    cJSON_ArrayForEach(addresses_local_nonprimitive,addresses )
    {
        if(!cJSON_IsObject(addresses_local_nonprimitive)){
            goto end;
        }
        v1_endpoint_address_t *addressesItem = v1_endpoint_address_parseFromJSON(addresses_local_nonprimitive);

        list_addElement(addressesList, addressesItem);
    }
    }

    // v1_endpoint_subset->not_ready_addresses
    cJSON *not_ready_addresses = cJSON_GetObjectItemCaseSensitive(v1_endpoint_subsetJSON, "notReadyAddresses");
    list_t *not_ready_addressesList;
    if (not_ready_addresses) { 
    cJSON *not_ready_addresses_local_nonprimitive;
    if(!cJSON_IsArray(not_ready_addresses)){
        goto end; //nonprimitive container
    }

    not_ready_addressesList = list_create();

    cJSON_ArrayForEach(not_ready_addresses_local_nonprimitive,not_ready_addresses )
    {
        if(!cJSON_IsObject(not_ready_addresses_local_nonprimitive)){
            goto end;
        }
        v1_endpoint_address_t *not_ready_addressesItem = v1_endpoint_address_parseFromJSON(not_ready_addresses_local_nonprimitive);

        list_addElement(not_ready_addressesList, not_ready_addressesItem);
    }
    }

    // v1_endpoint_subset->ports
    cJSON *ports = cJSON_GetObjectItemCaseSensitive(v1_endpoint_subsetJSON, "ports");
    list_t *portsList;
    if (ports) { 
    cJSON *ports_local_nonprimitive;
    if(!cJSON_IsArray(ports)){
        goto end; //nonprimitive container
    }

    portsList = list_create();

    cJSON_ArrayForEach(ports_local_nonprimitive,ports )
    {
        if(!cJSON_IsObject(ports_local_nonprimitive)){
            goto end;
        }
        v1_endpoint_port_t *portsItem = v1_endpoint_port_parseFromJSON(ports_local_nonprimitive);

        list_addElement(portsList, portsItem);
    }
    }


    v1_endpoint_subset_local_var = v1_endpoint_subset_create (
        addresses ? addressesList : NULL,
        not_ready_addresses ? not_ready_addressesList : NULL,
        ports ? portsList : NULL
        );

    return v1_endpoint_subset_local_var;
end:
    return NULL;

}
