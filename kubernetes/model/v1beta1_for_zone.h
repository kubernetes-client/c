/*
 * v1beta1_for_zone.h
 *
 * ForZone provides information about which zones should consume this endpoint.
 */

#ifndef _v1beta1_for_zone_H_
#define _v1beta1_for_zone_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_for_zone_t v1beta1_for_zone_t;




typedef struct v1beta1_for_zone_t {
    char *name; // string

} v1beta1_for_zone_t;

v1beta1_for_zone_t *v1beta1_for_zone_create(
    char *name
);

void v1beta1_for_zone_free(v1beta1_for_zone_t *v1beta1_for_zone);

v1beta1_for_zone_t *v1beta1_for_zone_parseFromJSON(cJSON *v1beta1_for_zoneJSON);

cJSON *v1beta1_for_zone_convertToJSON(v1beta1_for_zone_t *v1beta1_for_zone);

#endif /* _v1beta1_for_zone_H_ */

