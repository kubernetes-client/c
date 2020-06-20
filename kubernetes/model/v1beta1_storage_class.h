/*
 * v1beta1_storage_class.h
 *
 * StorageClass describes the parameters for a class of storage for which PersistentVolumes can be dynamically provisioned.  StorageClasses are non-namespaced; the name of the storage class according to etcd is in ObjectMeta.Name.
 */

#ifndef _v1beta1_storage_class_H_
#define _v1beta1_storage_class_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_storage_class_t v1beta1_storage_class_t;

#include "v1_object_meta.h"
#include "v1_topology_selector_term.h"



typedef struct v1beta1_storage_class_t {
    int allow_volume_expansion; //boolean
    list_t *allowed_topologies; //nonprimitive container
    char *api_version; // string
    char *kind; // string
    struct v1_object_meta_t *metadata; //model
    list_t *mount_options; //primitive container
    list_t* parameters; //map
    char *provisioner; // string
    char *reclaim_policy; // string
    char *volume_binding_mode; // string

} v1beta1_storage_class_t;

v1beta1_storage_class_t *v1beta1_storage_class_create(
    int allow_volume_expansion,
    list_t *allowed_topologies,
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    list_t *mount_options,
    list_t* parameters,
    char *provisioner,
    char *reclaim_policy,
    char *volume_binding_mode
);

void v1beta1_storage_class_free(v1beta1_storage_class_t *v1beta1_storage_class);

v1beta1_storage_class_t *v1beta1_storage_class_parseFromJSON(cJSON *v1beta1_storage_classJSON);

cJSON *v1beta1_storage_class_convertToJSON(v1beta1_storage_class_t *v1beta1_storage_class);

#endif /* _v1beta1_storage_class_H_ */

