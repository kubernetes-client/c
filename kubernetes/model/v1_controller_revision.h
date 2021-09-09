/*
 * v1_controller_revision.h
 *
 * ControllerRevision implements an immutable snapshot of state data. Clients are responsible for serializing and deserializing the objects that contain their internal state. Once a ControllerRevision has been successfully created, it can not be updated. The API Server will fail validation of all requests that attempt to mutate the Data field. ControllerRevisions may, however, be deleted. Note that, due to its use by both the DaemonSet and StatefulSet controllers for update and rollback, this object is beta. However, it may be subject to name and representation changes in future releases, and clients should not depend on its stability. It is primarily for internal use by controllers.
 */

#ifndef _v1_controller_revision_H_
#define _v1_controller_revision_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_controller_revision_t v1_controller_revision_t;

#include "object.h"
#include "v1_object_meta.h"



typedef struct v1_controller_revision_t {
    char *api_version; // string
    object_t *data; //object
    char *kind; // string
    struct v1_object_meta_t *metadata; //model
    long revision; //numeric

} v1_controller_revision_t;

v1_controller_revision_t *v1_controller_revision_create(
    char *api_version,
    object_t *data,
    char *kind,
    v1_object_meta_t *metadata,
    long revision
);

void v1_controller_revision_free(v1_controller_revision_t *v1_controller_revision);

v1_controller_revision_t *v1_controller_revision_parseFromJSON(cJSON *v1_controller_revisionJSON);

cJSON *v1_controller_revision_convertToJSON(v1_controller_revision_t *v1_controller_revision);

#endif /* _v1_controller_revision_H_ */

