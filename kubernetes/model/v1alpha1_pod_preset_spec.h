/*
 * v1alpha1_pod_preset_spec.h
 *
 * PodPresetSpec is a description of a pod preset.
 */

#ifndef _v1alpha1_pod_preset_spec_H_
#define _v1alpha1_pod_preset_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha1_pod_preset_spec_t v1alpha1_pod_preset_spec_t;

#include "v1_env_from_source.h"
#include "v1_env_var.h"
#include "v1_label_selector.h"
#include "v1_volume.h"
#include "v1_volume_mount.h"



typedef struct v1alpha1_pod_preset_spec_t {
    list_t *env; //nonprimitive container
    list_t *env_from; //nonprimitive container
    struct v1_label_selector_t *selector; //model
    list_t *volume_mounts; //nonprimitive container
    list_t *volumes; //nonprimitive container

} v1alpha1_pod_preset_spec_t;

v1alpha1_pod_preset_spec_t *v1alpha1_pod_preset_spec_create(
    list_t *env,
    list_t *env_from,
    v1_label_selector_t *selector,
    list_t *volume_mounts,
    list_t *volumes
);

void v1alpha1_pod_preset_spec_free(v1alpha1_pod_preset_spec_t *v1alpha1_pod_preset_spec);

v1alpha1_pod_preset_spec_t *v1alpha1_pod_preset_spec_parseFromJSON(cJSON *v1alpha1_pod_preset_specJSON);

cJSON *v1alpha1_pod_preset_spec_convertToJSON(v1alpha1_pod_preset_spec_t *v1alpha1_pod_preset_spec);

#endif /* _v1alpha1_pod_preset_spec_H_ */

