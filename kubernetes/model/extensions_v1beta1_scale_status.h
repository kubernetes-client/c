/*
 * extensions_v1beta1_scale_status.h
 *
 * represents the current status of a scale subresource.
 */

#ifndef _extensions_v1beta1_scale_status_H_
#define _extensions_v1beta1_scale_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct extensions_v1beta1_scale_status_t extensions_v1beta1_scale_status_t;




typedef struct extensions_v1beta1_scale_status_t {
    int replicas; //numeric
    list_t* selector; //map
    char *target_selector; // string

} extensions_v1beta1_scale_status_t;

extensions_v1beta1_scale_status_t *extensions_v1beta1_scale_status_create(
    int replicas,
    list_t* selector,
    char *target_selector
);

void extensions_v1beta1_scale_status_free(extensions_v1beta1_scale_status_t *extensions_v1beta1_scale_status);

extensions_v1beta1_scale_status_t *extensions_v1beta1_scale_status_parseFromJSON(cJSON *extensions_v1beta1_scale_statusJSON);

cJSON *extensions_v1beta1_scale_status_convertToJSON(extensions_v1beta1_scale_status_t *extensions_v1beta1_scale_status);

#endif /* _extensions_v1beta1_scale_status_H_ */

