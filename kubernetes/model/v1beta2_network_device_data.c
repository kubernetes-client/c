#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta2_network_device_data.h"



static v1beta2_network_device_data_t *v1beta2_network_device_data_create_internal(
    char *hardware_address,
    char *interface_name,
    list_t *ips
    ) {
    v1beta2_network_device_data_t *v1beta2_network_device_data_local_var = malloc(sizeof(v1beta2_network_device_data_t));
    if (!v1beta2_network_device_data_local_var) {
        return NULL;
    }
    v1beta2_network_device_data_local_var->hardware_address = hardware_address;
    v1beta2_network_device_data_local_var->interface_name = interface_name;
    v1beta2_network_device_data_local_var->ips = ips;

    v1beta2_network_device_data_local_var->_library_owned = 1;
    return v1beta2_network_device_data_local_var;
}

__attribute__((deprecated)) v1beta2_network_device_data_t *v1beta2_network_device_data_create(
    char *hardware_address,
    char *interface_name,
    list_t *ips
    ) {
    return v1beta2_network_device_data_create_internal (
        hardware_address,
        interface_name,
        ips
        );
}

void v1beta2_network_device_data_free(v1beta2_network_device_data_t *v1beta2_network_device_data) {
    if(NULL == v1beta2_network_device_data){
        return ;
    }
    if(v1beta2_network_device_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1beta2_network_device_data_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta2_network_device_data->hardware_address) {
        free(v1beta2_network_device_data->hardware_address);
        v1beta2_network_device_data->hardware_address = NULL;
    }
    if (v1beta2_network_device_data->interface_name) {
        free(v1beta2_network_device_data->interface_name);
        v1beta2_network_device_data->interface_name = NULL;
    }
    if (v1beta2_network_device_data->ips) {
        list_ForEach(listEntry, v1beta2_network_device_data->ips) {
            free(listEntry->data);
        }
        list_freeList(v1beta2_network_device_data->ips);
        v1beta2_network_device_data->ips = NULL;
    }
    free(v1beta2_network_device_data);
}

cJSON *v1beta2_network_device_data_convertToJSON(v1beta2_network_device_data_t *v1beta2_network_device_data) {
    cJSON *item = cJSON_CreateObject();

    // v1beta2_network_device_data->hardware_address
    if(v1beta2_network_device_data->hardware_address) {
    if(cJSON_AddStringToObject(item, "hardwareAddress", v1beta2_network_device_data->hardware_address) == NULL) {
    goto fail; //String
    }
    }


    // v1beta2_network_device_data->interface_name
    if(v1beta2_network_device_data->interface_name) {
    if(cJSON_AddStringToObject(item, "interfaceName", v1beta2_network_device_data->interface_name) == NULL) {
    goto fail; //String
    }
    }


    // v1beta2_network_device_data->ips
    if(v1beta2_network_device_data->ips) {
    cJSON *ips = cJSON_AddArrayToObject(item, "ips");
    if(ips == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *ipsListEntry;
    list_ForEach(ipsListEntry, v1beta2_network_device_data->ips) {
    if(cJSON_AddStringToObject(ips, "", ipsListEntry->data) == NULL)
    {
        goto fail;
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

v1beta2_network_device_data_t *v1beta2_network_device_data_parseFromJSON(cJSON *v1beta2_network_device_dataJSON){

    v1beta2_network_device_data_t *v1beta2_network_device_data_local_var = NULL;

    // define the local list for v1beta2_network_device_data->ips
    list_t *ipsList = NULL;

    // v1beta2_network_device_data->hardware_address
    cJSON *hardware_address = cJSON_GetObjectItemCaseSensitive(v1beta2_network_device_dataJSON, "hardwareAddress");
    if (cJSON_IsNull(hardware_address)) {
        hardware_address = NULL;
    }
    if (hardware_address) { 
    if(!cJSON_IsString(hardware_address) && !cJSON_IsNull(hardware_address))
    {
    goto end; //String
    }
    }

    // v1beta2_network_device_data->interface_name
    cJSON *interface_name = cJSON_GetObjectItemCaseSensitive(v1beta2_network_device_dataJSON, "interfaceName");
    if (cJSON_IsNull(interface_name)) {
        interface_name = NULL;
    }
    if (interface_name) { 
    if(!cJSON_IsString(interface_name) && !cJSON_IsNull(interface_name))
    {
    goto end; //String
    }
    }

    // v1beta2_network_device_data->ips
    cJSON *ips = cJSON_GetObjectItemCaseSensitive(v1beta2_network_device_dataJSON, "ips");
    if (cJSON_IsNull(ips)) {
        ips = NULL;
    }
    if (ips) { 
    cJSON *ips_local = NULL;
    if(!cJSON_IsArray(ips)) {
        goto end;//primitive container
    }
    ipsList = list_createList();

    cJSON_ArrayForEach(ips_local, ips)
    {
        if(!cJSON_IsString(ips_local))
        {
            goto end;
        }
        list_addElement(ipsList , strdup(ips_local->valuestring));
    }
    }


    v1beta2_network_device_data_local_var = v1beta2_network_device_data_create_internal (
        hardware_address && !cJSON_IsNull(hardware_address) ? strdup(hardware_address->valuestring) : NULL,
        interface_name && !cJSON_IsNull(interface_name) ? strdup(interface_name->valuestring) : NULL,
        ips ? ipsList : NULL
        );

    return v1beta2_network_device_data_local_var;
end:
    if (ipsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, ipsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(ipsList);
        ipsList = NULL;
    }
    return NULL;

}
