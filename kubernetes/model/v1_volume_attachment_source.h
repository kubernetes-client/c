/*
 * v1_volume_attachment_source.h
 *
 * VolumeAttachmentSource represents a volume that should be attached. Right now only PersistentVolumes can be attached via external attacher, in the future we may allow also inline volumes in pods. Exactly one member can be set.
 */

#ifndef _v1_volume_attachment_source_H_
#define _v1_volume_attachment_source_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_volume_attachment_source_t v1_volume_attachment_source_t;

#include "v1_persistent_volume_spec.h"



typedef struct v1_volume_attachment_source_t {
    struct v1_persistent_volume_spec_t *inline_volume_spec; //model
    char *persistent_volume_name; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1_volume_attachment_source_t;

__attribute__((deprecated)) v1_volume_attachment_source_t *v1_volume_attachment_source_create(
    v1_persistent_volume_spec_t *inline_volume_spec,
    char *persistent_volume_name
);

void v1_volume_attachment_source_free(v1_volume_attachment_source_t *v1_volume_attachment_source);

v1_volume_attachment_source_t *v1_volume_attachment_source_parseFromJSON(cJSON *v1_volume_attachment_sourceJSON);

cJSON *v1_volume_attachment_source_convertToJSON(v1_volume_attachment_source_t *v1_volume_attachment_source);

#endif /* _v1_volume_attachment_source_H_ */

