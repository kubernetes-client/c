/*
 * v1alpha1_scheduling.h
 *
 * Scheduling specifies the scheduling constraints for nodes supporting a RuntimeClass.
 */

#ifndef _v1alpha1_scheduling_H_
#define _v1alpha1_scheduling_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha1_scheduling_t v1alpha1_scheduling_t;

#include "v1_toleration.h"



typedef struct v1alpha1_scheduling_t {
    list_t* node_selector; //map
    list_t *tolerations; //nonprimitive container

} v1alpha1_scheduling_t;

v1alpha1_scheduling_t *v1alpha1_scheduling_create(
    list_t* node_selector,
    list_t *tolerations
);

void v1alpha1_scheduling_free(v1alpha1_scheduling_t *v1alpha1_scheduling);

v1alpha1_scheduling_t *v1alpha1_scheduling_parseFromJSON(cJSON *v1alpha1_schedulingJSON);

cJSON *v1alpha1_scheduling_convertToJSON(v1alpha1_scheduling_t *v1alpha1_scheduling);

#endif /* _v1alpha1_scheduling_H_ */

