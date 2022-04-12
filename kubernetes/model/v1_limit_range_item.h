/*
 * v1_limit_range_item.h
 *
 * LimitRangeItem defines a min/max usage limit for any resource that matches on kind.
 */

#ifndef _v1_limit_range_item_H_
#define _v1_limit_range_item_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_limit_range_item_t v1_limit_range_item_t;


// Enum TYPE for v1_limit_range_item

typedef enum  { kubernetes_v1_limit_range_item_TYPE_NULL = 0, kubernetes_v1_limit_range_item_TYPE_Container, kubernetes_v1_limit_range_item_TYPE_PersistentVolumeClaim, kubernetes_v1_limit_range_item_TYPE_Pod } kubernetes_v1_limit_range_item_TYPE_e;

char* v1_limit_range_item_type_ToString(kubernetes_v1_limit_range_item_TYPE_e type);

kubernetes_v1_limit_range_item_TYPE_e v1_limit_range_item_type_FromString(char* type);



typedef struct v1_limit_range_item_t {
    list_t* _default; //map
    list_t* default_request; //map
    list_t* max; //map
    list_t* max_limit_request_ratio; //map
    list_t* min; //map
    kubernetes_v1_limit_range_item_TYPE_e type; //enum

} v1_limit_range_item_t;

v1_limit_range_item_t *v1_limit_range_item_create(
    list_t* _default,
    list_t* default_request,
    list_t* max,
    list_t* max_limit_request_ratio,
    list_t* min,
    kubernetes_v1_limit_range_item_TYPE_e type
);

void v1_limit_range_item_free(v1_limit_range_item_t *v1_limit_range_item);

v1_limit_range_item_t *v1_limit_range_item_parseFromJSON(cJSON *v1_limit_range_itemJSON);

cJSON *v1_limit_range_item_convertToJSON(v1_limit_range_item_t *v1_limit_range_item);

#endif /* _v1_limit_range_item_H_ */

