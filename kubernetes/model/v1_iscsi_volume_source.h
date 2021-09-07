/*
 * v1_iscsi_volume_source.h
 *
 * Represents an ISCSI disk. ISCSI volumes can only be mounted as read/write once. ISCSI volumes support ownership management and SELinux relabeling.
 */

#ifndef _v1_iscsi_volume_source_H_
#define _v1_iscsi_volume_source_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_iscsi_volume_source_t v1_iscsi_volume_source_t;

#include "v1_local_object_reference.h"



typedef struct v1_iscsi_volume_source_t {
    int chap_auth_discovery; //boolean
    int chap_auth_session; //boolean
    char *fs_type; // string
    char *initiator_name; // string
    char *iqn; // string
    char *iscsi_interface; // string
    int lun; //numeric
    list_t *portals; //primitive container
    int read_only; //boolean
    struct v1_local_object_reference_t *secret_ref; //model
    char *target_portal; // string

} v1_iscsi_volume_source_t;

v1_iscsi_volume_source_t *v1_iscsi_volume_source_create(
    int chap_auth_discovery,
    int chap_auth_session,
    char *fs_type,
    char *initiator_name,
    char *iqn,
    char *iscsi_interface,
    int lun,
    list_t *portals,
    int read_only,
    v1_local_object_reference_t *secret_ref,
    char *target_portal
);

void v1_iscsi_volume_source_free(v1_iscsi_volume_source_t *v1_iscsi_volume_source);

v1_iscsi_volume_source_t *v1_iscsi_volume_source_parseFromJSON(cJSON *v1_iscsi_volume_sourceJSON);

cJSON *v1_iscsi_volume_source_convertToJSON(v1_iscsi_volume_source_t *v1_iscsi_volume_source);

#endif /* _v1_iscsi_volume_source_H_ */

