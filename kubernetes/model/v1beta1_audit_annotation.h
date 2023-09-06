/*
 * v1beta1_audit_annotation.h
 *
 * AuditAnnotation describes how to produce an audit annotation for an API request.
 */

#ifndef _v1beta1_audit_annotation_H_
#define _v1beta1_audit_annotation_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_audit_annotation_t v1beta1_audit_annotation_t;




typedef struct v1beta1_audit_annotation_t {
    char *key; // string
    char *value_expression; // string

} v1beta1_audit_annotation_t;

v1beta1_audit_annotation_t *v1beta1_audit_annotation_create(
    char *key,
    char *value_expression
);

void v1beta1_audit_annotation_free(v1beta1_audit_annotation_t *v1beta1_audit_annotation);

v1beta1_audit_annotation_t *v1beta1_audit_annotation_parseFromJSON(cJSON *v1beta1_audit_annotationJSON);

cJSON *v1beta1_audit_annotation_convertToJSON(v1beta1_audit_annotation_t *v1beta1_audit_annotation);

#endif /* _v1beta1_audit_annotation_H_ */

