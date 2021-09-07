/*
 * v1_object_meta.h
 *
 * ObjectMeta is metadata that all persisted resources must have, which includes all objects users must create.
 */

#ifndef _v1_object_meta_H_
#define _v1_object_meta_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_object_meta_t v1_object_meta_t;

#include "v1_managed_fields_entry.h"
#include "v1_owner_reference.h"



typedef struct v1_object_meta_t {
    list_t* annotations; //map
    char *cluster_name; // string
    char *creation_timestamp; //date time
    long deletion_grace_period_seconds; //numeric
    char *deletion_timestamp; //date time
    list_t *finalizers; //primitive container
    char *generate_name; // string
    long generation; //numeric
    list_t* labels; //map
    list_t *managed_fields; //nonprimitive container
    char *name; // string
    char *_namespace; // string
    list_t *owner_references; //nonprimitive container
    char *resource_version; // string
    char *self_link; // string
    char *uid; // string

} v1_object_meta_t;

v1_object_meta_t *v1_object_meta_create(
    list_t* annotations,
    char *cluster_name,
    char *creation_timestamp,
    long deletion_grace_period_seconds,
    char *deletion_timestamp,
    list_t *finalizers,
    char *generate_name,
    long generation,
    list_t* labels,
    list_t *managed_fields,
    char *name,
    char *_namespace,
    list_t *owner_references,
    char *resource_version,
    char *self_link,
    char *uid
);

void v1_object_meta_free(v1_object_meta_t *v1_object_meta);

v1_object_meta_t *v1_object_meta_parseFromJSON(cJSON *v1_object_metaJSON);

cJSON *v1_object_meta_convertToJSON(v1_object_meta_t *v1_object_meta);

#endif /* _v1_object_meta_H_ */

