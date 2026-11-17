/*
 * v1alpha3_shareable_summary_status.h
 *
 * ShareableSummaryStatus reports aggregate capacity for a pool that contains devices with AllowMultipleAllocations.
 */

#ifndef _v1alpha3_shareable_summary_status_H_
#define _v1alpha3_shareable_summary_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha3_shareable_summary_status_t v1alpha3_shareable_summary_status_t;

#include "v1alpha3_shareable_capacity_status.h"



typedef struct v1alpha3_shareable_summary_status_t {
    list_t *capacity; //nonprimitive container
    int *fully_available_devices; //numeric
    int *partially_available_devices; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} v1alpha3_shareable_summary_status_t;

__attribute__((deprecated)) v1alpha3_shareable_summary_status_t *v1alpha3_shareable_summary_status_create(
    list_t *capacity,
    int *fully_available_devices,
    int *partially_available_devices
);

void v1alpha3_shareable_summary_status_free(v1alpha3_shareable_summary_status_t *v1alpha3_shareable_summary_status);

v1alpha3_shareable_summary_status_t *v1alpha3_shareable_summary_status_parseFromJSON(cJSON *v1alpha3_shareable_summary_statusJSON);

cJSON *v1alpha3_shareable_summary_status_convertToJSON(v1alpha3_shareable_summary_status_t *v1alpha3_shareable_summary_status);

#endif /* _v1alpha3_shareable_summary_status_H_ */

