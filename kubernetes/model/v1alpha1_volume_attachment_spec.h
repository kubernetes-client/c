/*
 * v1alpha1_volume_attachment_spec.h
 *
 * VolumeAttachmentSpec is the specification of a VolumeAttachment request.
 */

#ifndef _v1alpha1_volume_attachment_spec_H_
#define _v1alpha1_volume_attachment_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha1_volume_attachment_spec_t v1alpha1_volume_attachment_spec_t;

#include "v1alpha1_volume_attachment_source.h"



typedef struct v1alpha1_volume_attachment_spec_t {
    char *attacher; // string
    char *node_name; // string
    struct v1alpha1_volume_attachment_source_t *source; //model

} v1alpha1_volume_attachment_spec_t;

v1alpha1_volume_attachment_spec_t *v1alpha1_volume_attachment_spec_create(
    char *attacher,
    char *node_name,
    v1alpha1_volume_attachment_source_t *source
);

void v1alpha1_volume_attachment_spec_free(v1alpha1_volume_attachment_spec_t *v1alpha1_volume_attachment_spec);

v1alpha1_volume_attachment_spec_t *v1alpha1_volume_attachment_spec_parseFromJSON(cJSON *v1alpha1_volume_attachment_specJSON);

cJSON *v1alpha1_volume_attachment_spec_convertToJSON(v1alpha1_volume_attachment_spec_t *v1alpha1_volume_attachment_spec);

#endif /* _v1alpha1_volume_attachment_spec_H_ */

