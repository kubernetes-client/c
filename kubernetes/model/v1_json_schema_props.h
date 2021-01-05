/*
 * v1_json_schema_props.h
 *
 * JSONSchemaProps is a JSON-Schema following Specification Draft 4 (http://json-schema.org/).
 */

#ifndef _v1_json_schema_props_H_
#define _v1_json_schema_props_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_json_schema_props_t v1_json_schema_props_t;

#include "object.h"
#include "v1_external_documentation.h"



typedef struct v1_json_schema_props_t {
    char *ref; // string
    char *schema; // string
    object_t *additional_items; //object
    object_t *additional_properties; //object
    list_t *all_of; //nonprimitive container
    list_t *any_of; //nonprimitive container
    object_t *_default; //object
    list_t* definitions; //map
    list_t* dependencies; //map
    char *description; // string
    list_t *_enum; //nonprimitive container
    object_t *example; //object
    int exclusive_maximum; //boolean
    int exclusive_minimum; //boolean
    struct v1_external_documentation_t *external_docs; //model
    char *format; // string
    char *id; // string
    object_t *items; //object
    long max_items; //numeric
    long max_length; //numeric
    long max_properties; //numeric
    double maximum; //numeric
    long min_items; //numeric
    long min_length; //numeric
    long min_properties; //numeric
    double minimum; //numeric
    double multiple_of; //numeric
    struct v1_json_schema_props_t *_not; //model
    int nullable; //boolean
    list_t *one_of; //nonprimitive container
    char *pattern; // string
    list_t* pattern_properties; //map
    list_t* properties; //map
    list_t *required; //primitive container
    char *title; // string
    char *type; // string
    int unique_items; //boolean
    int x_kubernetes_embedded_resource; //boolean
    int x_kubernetes_int_or_string; //boolean
    list_t *x_kubernetes_list_map_keys; //primitive container
    char *x_kubernetes_list_type; // string
    char *x_kubernetes_map_type; // string
    int x_kubernetes_preserve_unknown_fields; //boolean

} v1_json_schema_props_t;

v1_json_schema_props_t *v1_json_schema_props_create(
    char *ref,
    char *schema,
    object_t *additional_items,
    object_t *additional_properties,
    list_t *all_of,
    list_t *any_of,
    object_t *_default,
    list_t* definitions,
    list_t* dependencies,
    char *description,
    list_t *_enum,
    object_t *example,
    int exclusive_maximum,
    int exclusive_minimum,
    v1_external_documentation_t *external_docs,
    char *format,
    char *id,
    object_t *items,
    long max_items,
    long max_length,
    long max_properties,
    double maximum,
    long min_items,
    long min_length,
    long min_properties,
    double minimum,
    double multiple_of,
    v1_json_schema_props_t *_not,
    int nullable,
    list_t *one_of,
    char *pattern,
    list_t* pattern_properties,
    list_t* properties,
    list_t *required,
    char *title,
    char *type,
    int unique_items,
    int x_kubernetes_embedded_resource,
    int x_kubernetes_int_or_string,
    list_t *x_kubernetes_list_map_keys,
    char *x_kubernetes_list_type,
    char *x_kubernetes_map_type,
    int x_kubernetes_preserve_unknown_fields
);

void v1_json_schema_props_free(v1_json_schema_props_t *v1_json_schema_props);

v1_json_schema_props_t *v1_json_schema_props_parseFromJSON(cJSON *v1_json_schema_propsJSON);

cJSON *v1_json_schema_props_convertToJSON(v1_json_schema_props_t *v1_json_schema_props);

#endif /* _v1_json_schema_props_H_ */

