/*
 * v1beta1_ip_address.h
 *
 * IPAddress represents a single IP of a single IP Family. The object is designed to be used by APIs that operate on IP addresses. The object is used by the Service core API for allocation of IP addresses. An IP address can be represented in different formats, to guarantee the uniqueness of the IP, the name of the object is the IP address in canonical format, four decimal digits separated by dots suppressing leading zeros for IPv4 and the representation defined by RFC 5952 for IPv6. Valid: 192.168.1.5 or 2001:db8::1 or 2001:db8:aaaa:bbbb:cccc:dddd:eeee:1 Invalid: 10.01.2.3 or 2001:db8:0:0:0::1
 */

#ifndef _v1beta1_ip_address_H_
#define _v1beta1_ip_address_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_ip_address_t v1beta1_ip_address_t;

#include "v1_object_meta.h"
#include "v1beta1_ip_address_spec.h"



typedef struct v1beta1_ip_address_t {
    char *api_version; // string
    char *kind; // string
    struct v1_object_meta_t *metadata; //model
    struct v1beta1_ip_address_spec_t *spec; //model

} v1beta1_ip_address_t;

v1beta1_ip_address_t *v1beta1_ip_address_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1beta1_ip_address_spec_t *spec
);

void v1beta1_ip_address_free(v1beta1_ip_address_t *v1beta1_ip_address);

v1beta1_ip_address_t *v1beta1_ip_address_parseFromJSON(cJSON *v1beta1_ip_addressJSON);

cJSON *v1beta1_ip_address_convertToJSON(v1beta1_ip_address_t *v1beta1_ip_address);

#endif /* _v1beta1_ip_address_H_ */

