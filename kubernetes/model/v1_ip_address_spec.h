/*
 * v1_ip_address_spec.h
 *
 * IPAddressSpec describe the attributes in an IP Address.
 */

#ifndef _v1_ip_address_spec_H_
#define _v1_ip_address_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_ip_address_spec_t v1_ip_address_spec_t;

#include "v1_parent_reference.h"



typedef struct v1_ip_address_spec_t {
    struct v1_parent_reference_t *parent_ref; //model

    int _library_owned; // Is the library responsible for freeing this object?
} v1_ip_address_spec_t;

__attribute__((deprecated)) v1_ip_address_spec_t *v1_ip_address_spec_create(
    v1_parent_reference_t *parent_ref
);

void v1_ip_address_spec_free(v1_ip_address_spec_t *v1_ip_address_spec);

v1_ip_address_spec_t *v1_ip_address_spec_parseFromJSON(cJSON *v1_ip_address_specJSON);

cJSON *v1_ip_address_spec_convertToJSON(v1_ip_address_spec_t *v1_ip_address_spec);

#endif /* _v1_ip_address_spec_H_ */

