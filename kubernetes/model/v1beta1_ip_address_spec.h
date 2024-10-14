/*
 * v1beta1_ip_address_spec.h
 *
 * IPAddressSpec describe the attributes in an IP Address.
 */

#ifndef _v1beta1_ip_address_spec_H_
#define _v1beta1_ip_address_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_ip_address_spec_t v1beta1_ip_address_spec_t;

#include "v1beta1_parent_reference.h"



typedef struct v1beta1_ip_address_spec_t {
    struct v1beta1_parent_reference_t *parent_ref; //model

} v1beta1_ip_address_spec_t;

v1beta1_ip_address_spec_t *v1beta1_ip_address_spec_create(
    v1beta1_parent_reference_t *parent_ref
);

void v1beta1_ip_address_spec_free(v1beta1_ip_address_spec_t *v1beta1_ip_address_spec);

v1beta1_ip_address_spec_t *v1beta1_ip_address_spec_parseFromJSON(cJSON *v1beta1_ip_address_specJSON);

cJSON *v1beta1_ip_address_spec_convertToJSON(v1beta1_ip_address_spec_t *v1beta1_ip_address_spec);

#endif /* _v1beta1_ip_address_spec_H_ */

