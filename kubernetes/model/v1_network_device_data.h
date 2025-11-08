/*
 * v1_network_device_data.h
 *
 * NetworkDeviceData provides network-related details for the allocated device. This information may be filled by drivers or other components to configure or identify the device within a network context.
 */

#ifndef _v1_network_device_data_H_
#define _v1_network_device_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_network_device_data_t v1_network_device_data_t;




typedef struct v1_network_device_data_t {
    char *hardware_address; // string
    char *interface_name; // string
    list_t *ips; //primitive container

    int _library_owned; // Is the library responsible for freeing this object?
} v1_network_device_data_t;

__attribute__((deprecated)) v1_network_device_data_t *v1_network_device_data_create(
    char *hardware_address,
    char *interface_name,
    list_t *ips
);

void v1_network_device_data_free(v1_network_device_data_t *v1_network_device_data);

v1_network_device_data_t *v1_network_device_data_parseFromJSON(cJSON *v1_network_device_dataJSON);

cJSON *v1_network_device_data_convertToJSON(v1_network_device_data_t *v1_network_device_data);

#endif /* _v1_network_device_data_H_ */

