#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_json_schema_props.h"



static v1_json_schema_props_t *v1_json_schema_props_create_internal(
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
    int x_kubernetes_preserve_unknown_fields,
    list_t *x_kubernetes_validations
    ) {
    v1_json_schema_props_t *v1_json_schema_props_local_var = malloc(sizeof(v1_json_schema_props_t));
    if (!v1_json_schema_props_local_var) {
        return NULL;
    }
    v1_json_schema_props_local_var->ref = ref;
    v1_json_schema_props_local_var->schema = schema;
    v1_json_schema_props_local_var->additional_items = additional_items;
    v1_json_schema_props_local_var->additional_properties = additional_properties;
    v1_json_schema_props_local_var->all_of = all_of;
    v1_json_schema_props_local_var->any_of = any_of;
    v1_json_schema_props_local_var->_default = _default;
    v1_json_schema_props_local_var->definitions = definitions;
    v1_json_schema_props_local_var->dependencies = dependencies;
    v1_json_schema_props_local_var->description = description;
    v1_json_schema_props_local_var->_enum = _enum;
    v1_json_schema_props_local_var->example = example;
    v1_json_schema_props_local_var->exclusive_maximum = exclusive_maximum;
    v1_json_schema_props_local_var->exclusive_minimum = exclusive_minimum;
    v1_json_schema_props_local_var->external_docs = external_docs;
    v1_json_schema_props_local_var->format = format;
    v1_json_schema_props_local_var->id = id;
    v1_json_schema_props_local_var->items = items;
    v1_json_schema_props_local_var->max_items = max_items;
    v1_json_schema_props_local_var->max_length = max_length;
    v1_json_schema_props_local_var->max_properties = max_properties;
    v1_json_schema_props_local_var->maximum = maximum;
    v1_json_schema_props_local_var->min_items = min_items;
    v1_json_schema_props_local_var->min_length = min_length;
    v1_json_schema_props_local_var->min_properties = min_properties;
    v1_json_schema_props_local_var->minimum = minimum;
    v1_json_schema_props_local_var->multiple_of = multiple_of;
    v1_json_schema_props_local_var->_not = _not;
    v1_json_schema_props_local_var->nullable = nullable;
    v1_json_schema_props_local_var->one_of = one_of;
    v1_json_schema_props_local_var->pattern = pattern;
    v1_json_schema_props_local_var->pattern_properties = pattern_properties;
    v1_json_schema_props_local_var->properties = properties;
    v1_json_schema_props_local_var->required = required;
    v1_json_schema_props_local_var->title = title;
    v1_json_schema_props_local_var->type = type;
    v1_json_schema_props_local_var->unique_items = unique_items;
    v1_json_schema_props_local_var->x_kubernetes_embedded_resource = x_kubernetes_embedded_resource;
    v1_json_schema_props_local_var->x_kubernetes_int_or_string = x_kubernetes_int_or_string;
    v1_json_schema_props_local_var->x_kubernetes_list_map_keys = x_kubernetes_list_map_keys;
    v1_json_schema_props_local_var->x_kubernetes_list_type = x_kubernetes_list_type;
    v1_json_schema_props_local_var->x_kubernetes_map_type = x_kubernetes_map_type;
    v1_json_schema_props_local_var->x_kubernetes_preserve_unknown_fields = x_kubernetes_preserve_unknown_fields;
    v1_json_schema_props_local_var->x_kubernetes_validations = x_kubernetes_validations;

    v1_json_schema_props_local_var->_library_owned = 1;
    return v1_json_schema_props_local_var;
}

__attribute__((deprecated)) v1_json_schema_props_t *v1_json_schema_props_create(
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
    int x_kubernetes_preserve_unknown_fields,
    list_t *x_kubernetes_validations
    ) {
    return v1_json_schema_props_create_internal (
        ref,
        schema,
        additional_items,
        additional_properties,
        all_of,
        any_of,
        _default,
        definitions,
        dependencies,
        description,
        _enum,
        example,
        exclusive_maximum,
        exclusive_minimum,
        external_docs,
        format,
        id,
        items,
        max_items,
        max_length,
        max_properties,
        maximum,
        min_items,
        min_length,
        min_properties,
        minimum,
        multiple_of,
        _not,
        nullable,
        one_of,
        pattern,
        pattern_properties,
        properties,
        required,
        title,
        type,
        unique_items,
        x_kubernetes_embedded_resource,
        x_kubernetes_int_or_string,
        x_kubernetes_list_map_keys,
        x_kubernetes_list_type,
        x_kubernetes_map_type,
        x_kubernetes_preserve_unknown_fields,
        x_kubernetes_validations
        );
}

void v1_json_schema_props_free(v1_json_schema_props_t *v1_json_schema_props) {
    if(NULL == v1_json_schema_props){
        return ;
    }
    if(v1_json_schema_props->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_json_schema_props_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_json_schema_props->ref) {
        free(v1_json_schema_props->ref);
        v1_json_schema_props->ref = NULL;
    }
    if (v1_json_schema_props->schema) {
        free(v1_json_schema_props->schema);
        v1_json_schema_props->schema = NULL;
    }
    if (v1_json_schema_props->additional_items) {
        object_free(v1_json_schema_props->additional_items);
        v1_json_schema_props->additional_items = NULL;
    }
    if (v1_json_schema_props->additional_properties) {
        object_free(v1_json_schema_props->additional_properties);
        v1_json_schema_props->additional_properties = NULL;
    }
    if (v1_json_schema_props->all_of) {
        list_ForEach(listEntry, v1_json_schema_props->all_of) {
            v1_json_schema_props_free(listEntry->data);
        }
        list_freeList(v1_json_schema_props->all_of);
        v1_json_schema_props->all_of = NULL;
    }
    if (v1_json_schema_props->any_of) {
        list_ForEach(listEntry, v1_json_schema_props->any_of) {
            v1_json_schema_props_free(listEntry->data);
        }
        list_freeList(v1_json_schema_props->any_of);
        v1_json_schema_props->any_of = NULL;
    }
    if (v1_json_schema_props->_default) {
        object_free(v1_json_schema_props->_default);
        v1_json_schema_props->_default = NULL;
    }
    if (v1_json_schema_props->definitions) {
        list_ForEach(listEntry, v1_json_schema_props->definitions) {
            keyValuePair_t *localKeyValue = listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_freeList(v1_json_schema_props->definitions);
        v1_json_schema_props->definitions = NULL;
    }
    if (v1_json_schema_props->dependencies) {
        list_ForEach(listEntry, v1_json_schema_props->dependencies) {
            keyValuePair_t *localKeyValue = listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_freeList(v1_json_schema_props->dependencies);
        v1_json_schema_props->dependencies = NULL;
    }
    if (v1_json_schema_props->description) {
        free(v1_json_schema_props->description);
        v1_json_schema_props->description = NULL;
    }
    if (v1_json_schema_props->_enum) {
        list_ForEach(listEntry, v1_json_schema_props->_enum) {
            object_free(listEntry->data);
        }
        list_freeList(v1_json_schema_props->_enum);
        v1_json_schema_props->_enum = NULL;
    }
    if (v1_json_schema_props->example) {
        object_free(v1_json_schema_props->example);
        v1_json_schema_props->example = NULL;
    }
    if (v1_json_schema_props->external_docs) {
        v1_external_documentation_free(v1_json_schema_props->external_docs);
        v1_json_schema_props->external_docs = NULL;
    }
    if (v1_json_schema_props->format) {
        free(v1_json_schema_props->format);
        v1_json_schema_props->format = NULL;
    }
    if (v1_json_schema_props->id) {
        free(v1_json_schema_props->id);
        v1_json_schema_props->id = NULL;
    }
    if (v1_json_schema_props->items) {
        object_free(v1_json_schema_props->items);
        v1_json_schema_props->items = NULL;
    }
    if (v1_json_schema_props->_not) {
        v1_json_schema_props_free(v1_json_schema_props->_not);
        v1_json_schema_props->_not = NULL;
    }
    if (v1_json_schema_props->one_of) {
        list_ForEach(listEntry, v1_json_schema_props->one_of) {
            v1_json_schema_props_free(listEntry->data);
        }
        list_freeList(v1_json_schema_props->one_of);
        v1_json_schema_props->one_of = NULL;
    }
    if (v1_json_schema_props->pattern) {
        free(v1_json_schema_props->pattern);
        v1_json_schema_props->pattern = NULL;
    }
    if (v1_json_schema_props->pattern_properties) {
        list_ForEach(listEntry, v1_json_schema_props->pattern_properties) {
            keyValuePair_t *localKeyValue = listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_freeList(v1_json_schema_props->pattern_properties);
        v1_json_schema_props->pattern_properties = NULL;
    }
    if (v1_json_schema_props->properties) {
        list_ForEach(listEntry, v1_json_schema_props->properties) {
            keyValuePair_t *localKeyValue = listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_freeList(v1_json_schema_props->properties);
        v1_json_schema_props->properties = NULL;
    }
    if (v1_json_schema_props->required) {
        list_ForEach(listEntry, v1_json_schema_props->required) {
            free(listEntry->data);
        }
        list_freeList(v1_json_schema_props->required);
        v1_json_schema_props->required = NULL;
    }
    if (v1_json_schema_props->title) {
        free(v1_json_schema_props->title);
        v1_json_schema_props->title = NULL;
    }
    if (v1_json_schema_props->type) {
        free(v1_json_schema_props->type);
        v1_json_schema_props->type = NULL;
    }
    if (v1_json_schema_props->x_kubernetes_list_map_keys) {
        list_ForEach(listEntry, v1_json_schema_props->x_kubernetes_list_map_keys) {
            free(listEntry->data);
        }
        list_freeList(v1_json_schema_props->x_kubernetes_list_map_keys);
        v1_json_schema_props->x_kubernetes_list_map_keys = NULL;
    }
    if (v1_json_schema_props->x_kubernetes_list_type) {
        free(v1_json_schema_props->x_kubernetes_list_type);
        v1_json_schema_props->x_kubernetes_list_type = NULL;
    }
    if (v1_json_schema_props->x_kubernetes_map_type) {
        free(v1_json_schema_props->x_kubernetes_map_type);
        v1_json_schema_props->x_kubernetes_map_type = NULL;
    }
    if (v1_json_schema_props->x_kubernetes_validations) {
        list_ForEach(listEntry, v1_json_schema_props->x_kubernetes_validations) {
            v1_validation_rule_free(listEntry->data);
        }
        list_freeList(v1_json_schema_props->x_kubernetes_validations);
        v1_json_schema_props->x_kubernetes_validations = NULL;
    }
    free(v1_json_schema_props);
}

cJSON *v1_json_schema_props_convertToJSON(v1_json_schema_props_t *v1_json_schema_props) {
    cJSON *item = cJSON_CreateObject();

    // v1_json_schema_props->ref
    if(v1_json_schema_props->ref) {
    if(cJSON_AddStringToObject(item, "$ref", v1_json_schema_props->ref) == NULL) {
    goto fail; //String
    }
    }


    // v1_json_schema_props->schema
    if(v1_json_schema_props->schema) {
    if(cJSON_AddStringToObject(item, "$schema", v1_json_schema_props->schema) == NULL) {
    goto fail; //String
    }
    }


    // v1_json_schema_props->additional_items
    if(v1_json_schema_props->additional_items) {
    cJSON *additional_items_object = object_convertToJSON(v1_json_schema_props->additional_items);
    if(additional_items_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "additionalItems", additional_items_object);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_json_schema_props->additional_properties
    if(v1_json_schema_props->additional_properties) {
    cJSON *additional_properties_object = object_convertToJSON(v1_json_schema_props->additional_properties);
    if(additional_properties_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "additionalProperties", additional_properties_object);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_json_schema_props->all_of
    if(v1_json_schema_props->all_of) {
    cJSON *all_of = cJSON_AddArrayToObject(item, "allOf");
    if(all_of == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *all_ofListEntry;
    if (v1_json_schema_props->all_of) {
    list_ForEach(all_ofListEntry, v1_json_schema_props->all_of) {
    cJSON *itemLocal = v1_json_schema_props_convertToJSON(all_ofListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(all_of, itemLocal);
    }
    }
    }


    // v1_json_schema_props->any_of
    if(v1_json_schema_props->any_of) {
    cJSON *any_of = cJSON_AddArrayToObject(item, "anyOf");
    if(any_of == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *any_ofListEntry;
    if (v1_json_schema_props->any_of) {
    list_ForEach(any_ofListEntry, v1_json_schema_props->any_of) {
    cJSON *itemLocal = v1_json_schema_props_convertToJSON(any_ofListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(any_of, itemLocal);
    }
    }
    }


    // v1_json_schema_props->_default
    if(v1_json_schema_props->_default) {
    cJSON *_default_object = object_convertToJSON(v1_json_schema_props->_default);
    if(_default_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "default", _default_object);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_json_schema_props->definitions
    if(v1_json_schema_props->definitions) {
    cJSON *definitions = cJSON_AddObjectToObject(item, "definitions");
    if(definitions == NULL) {
        goto fail; //primitive map container
    }
    cJSON *localMapObject = definitions;
    listEntry_t *definitionsListEntry;
    if (v1_json_schema_props->definitions) {
    list_ForEach(definitionsListEntry, v1_json_schema_props->definitions) {
        keyValuePair_t *localKeyValue = definitionsListEntry->data;
    }
    }
    }


    // v1_json_schema_props->dependencies
    if(v1_json_schema_props->dependencies) {
    cJSON *dependencies = cJSON_AddObjectToObject(item, "dependencies");
    if(dependencies == NULL) {
        goto fail; //primitive map container
    }
    cJSON *localMapObject = dependencies;
    listEntry_t *dependenciesListEntry;
    if (v1_json_schema_props->dependencies) {
    list_ForEach(dependenciesListEntry, v1_json_schema_props->dependencies) {
        keyValuePair_t *localKeyValue = dependenciesListEntry->data;
    }
    }
    }


    // v1_json_schema_props->description
    if(v1_json_schema_props->description) {
    if(cJSON_AddStringToObject(item, "description", v1_json_schema_props->description) == NULL) {
    goto fail; //String
    }
    }


    // v1_json_schema_props->_enum
    if(v1_json_schema_props->_enum) {
    cJSON *_enum = cJSON_AddArrayToObject(item, "enum");
    if(_enum == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *_enumListEntry;
    if (v1_json_schema_props->_enum) {
    list_ForEach(_enumListEntry, v1_json_schema_props->_enum) {
    cJSON *itemLocal = object_convertToJSON(_enumListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(_enum, itemLocal);
    }
    }
    }


    // v1_json_schema_props->example
    if(v1_json_schema_props->example) {
    cJSON *example_object = object_convertToJSON(v1_json_schema_props->example);
    if(example_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "example", example_object);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_json_schema_props->exclusive_maximum
    if(v1_json_schema_props->exclusive_maximum) {
    if(cJSON_AddBoolToObject(item, "exclusiveMaximum", v1_json_schema_props->exclusive_maximum) == NULL) {
    goto fail; //Bool
    }
    }


    // v1_json_schema_props->exclusive_minimum
    if(v1_json_schema_props->exclusive_minimum) {
    if(cJSON_AddBoolToObject(item, "exclusiveMinimum", v1_json_schema_props->exclusive_minimum) == NULL) {
    goto fail; //Bool
    }
    }


    // v1_json_schema_props->external_docs
    if(v1_json_schema_props->external_docs) {
    cJSON *external_docs_local_JSON = v1_external_documentation_convertToJSON(v1_json_schema_props->external_docs);
    if(external_docs_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "externalDocs", external_docs_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_json_schema_props->format
    if(v1_json_schema_props->format) {
    if(cJSON_AddStringToObject(item, "format", v1_json_schema_props->format) == NULL) {
    goto fail; //String
    }
    }


    // v1_json_schema_props->id
    if(v1_json_schema_props->id) {
    if(cJSON_AddStringToObject(item, "id", v1_json_schema_props->id) == NULL) {
    goto fail; //String
    }
    }


    // v1_json_schema_props->items
    if(v1_json_schema_props->items) {
    cJSON *items_object = object_convertToJSON(v1_json_schema_props->items);
    if(items_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "items", items_object);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_json_schema_props->max_items
    if(v1_json_schema_props->max_items) {
    if(cJSON_AddNumberToObject(item, "maxItems", v1_json_schema_props->max_items) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_json_schema_props->max_length
    if(v1_json_schema_props->max_length) {
    if(cJSON_AddNumberToObject(item, "maxLength", v1_json_schema_props->max_length) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_json_schema_props->max_properties
    if(v1_json_schema_props->max_properties) {
    if(cJSON_AddNumberToObject(item, "maxProperties", v1_json_schema_props->max_properties) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_json_schema_props->maximum
    if(v1_json_schema_props->maximum) {
    if(cJSON_AddNumberToObject(item, "maximum", v1_json_schema_props->maximum) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_json_schema_props->min_items
    if(v1_json_schema_props->min_items) {
    if(cJSON_AddNumberToObject(item, "minItems", v1_json_schema_props->min_items) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_json_schema_props->min_length
    if(v1_json_schema_props->min_length) {
    if(cJSON_AddNumberToObject(item, "minLength", v1_json_schema_props->min_length) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_json_schema_props->min_properties
    if(v1_json_schema_props->min_properties) {
    if(cJSON_AddNumberToObject(item, "minProperties", v1_json_schema_props->min_properties) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_json_schema_props->minimum
    if(v1_json_schema_props->minimum) {
    if(cJSON_AddNumberToObject(item, "minimum", v1_json_schema_props->minimum) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_json_schema_props->multiple_of
    if(v1_json_schema_props->multiple_of) {
    if(cJSON_AddNumberToObject(item, "multipleOf", v1_json_schema_props->multiple_of) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_json_schema_props->_not
    if(v1_json_schema_props->_not) {
    cJSON *_not_local_JSON = v1_json_schema_props_convertToJSON(v1_json_schema_props->_not);
    if(_not_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "not", _not_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_json_schema_props->nullable
    if(v1_json_schema_props->nullable) {
    if(cJSON_AddBoolToObject(item, "nullable", v1_json_schema_props->nullable) == NULL) {
    goto fail; //Bool
    }
    }


    // v1_json_schema_props->one_of
    if(v1_json_schema_props->one_of) {
    cJSON *one_of = cJSON_AddArrayToObject(item, "oneOf");
    if(one_of == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *one_ofListEntry;
    if (v1_json_schema_props->one_of) {
    list_ForEach(one_ofListEntry, v1_json_schema_props->one_of) {
    cJSON *itemLocal = v1_json_schema_props_convertToJSON(one_ofListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(one_of, itemLocal);
    }
    }
    }


    // v1_json_schema_props->pattern
    if(v1_json_schema_props->pattern) {
    if(cJSON_AddStringToObject(item, "pattern", v1_json_schema_props->pattern) == NULL) {
    goto fail; //String
    }
    }


    // v1_json_schema_props->pattern_properties
    if(v1_json_schema_props->pattern_properties) {
    cJSON *pattern_properties = cJSON_AddObjectToObject(item, "patternProperties");
    if(pattern_properties == NULL) {
        goto fail; //primitive map container
    }
    cJSON *localMapObject = pattern_properties;
    listEntry_t *pattern_propertiesListEntry;
    if (v1_json_schema_props->pattern_properties) {
    list_ForEach(pattern_propertiesListEntry, v1_json_schema_props->pattern_properties) {
        keyValuePair_t *localKeyValue = pattern_propertiesListEntry->data;
    }
    }
    }


    // v1_json_schema_props->properties
    if(v1_json_schema_props->properties) {
    cJSON *properties = cJSON_AddObjectToObject(item, "properties");
    if(properties == NULL) {
        goto fail; //primitive map container
    }
    cJSON *localMapObject = properties;
    listEntry_t *propertiesListEntry;
    if (v1_json_schema_props->properties) {
    list_ForEach(propertiesListEntry, v1_json_schema_props->properties) {
        keyValuePair_t *localKeyValue = propertiesListEntry->data;
    }
    }
    }


    // v1_json_schema_props->required
    if(v1_json_schema_props->required) {
    cJSON *required = cJSON_AddArrayToObject(item, "required");
    if(required == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *requiredListEntry;
    list_ForEach(requiredListEntry, v1_json_schema_props->required) {
    if(cJSON_AddStringToObject(required, "", requiredListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // v1_json_schema_props->title
    if(v1_json_schema_props->title) {
    if(cJSON_AddStringToObject(item, "title", v1_json_schema_props->title) == NULL) {
    goto fail; //String
    }
    }


    // v1_json_schema_props->type
    if(v1_json_schema_props->type) {
    if(cJSON_AddStringToObject(item, "type", v1_json_schema_props->type) == NULL) {
    goto fail; //String
    }
    }


    // v1_json_schema_props->unique_items
    if(v1_json_schema_props->unique_items) {
    if(cJSON_AddBoolToObject(item, "uniqueItems", v1_json_schema_props->unique_items) == NULL) {
    goto fail; //Bool
    }
    }


    // v1_json_schema_props->x_kubernetes_embedded_resource
    if(v1_json_schema_props->x_kubernetes_embedded_resource) {
    if(cJSON_AddBoolToObject(item, "x-kubernetes-embedded-resource", v1_json_schema_props->x_kubernetes_embedded_resource) == NULL) {
    goto fail; //Bool
    }
    }


    // v1_json_schema_props->x_kubernetes_int_or_string
    if(v1_json_schema_props->x_kubernetes_int_or_string) {
    if(cJSON_AddBoolToObject(item, "x-kubernetes-int-or-string", v1_json_schema_props->x_kubernetes_int_or_string) == NULL) {
    goto fail; //Bool
    }
    }


    // v1_json_schema_props->x_kubernetes_list_map_keys
    if(v1_json_schema_props->x_kubernetes_list_map_keys) {
    cJSON *x_kubernetes_list_map_keys = cJSON_AddArrayToObject(item, "x-kubernetes-list-map-keys");
    if(x_kubernetes_list_map_keys == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *x_kubernetes_list_map_keysListEntry;
    list_ForEach(x_kubernetes_list_map_keysListEntry, v1_json_schema_props->x_kubernetes_list_map_keys) {
    if(cJSON_AddStringToObject(x_kubernetes_list_map_keys, "", x_kubernetes_list_map_keysListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // v1_json_schema_props->x_kubernetes_list_type
    if(v1_json_schema_props->x_kubernetes_list_type) {
    if(cJSON_AddStringToObject(item, "x-kubernetes-list-type", v1_json_schema_props->x_kubernetes_list_type) == NULL) {
    goto fail; //String
    }
    }


    // v1_json_schema_props->x_kubernetes_map_type
    if(v1_json_schema_props->x_kubernetes_map_type) {
    if(cJSON_AddStringToObject(item, "x-kubernetes-map-type", v1_json_schema_props->x_kubernetes_map_type) == NULL) {
    goto fail; //String
    }
    }


    // v1_json_schema_props->x_kubernetes_preserve_unknown_fields
    if(v1_json_schema_props->x_kubernetes_preserve_unknown_fields) {
    if(cJSON_AddBoolToObject(item, "x-kubernetes-preserve-unknown-fields", v1_json_schema_props->x_kubernetes_preserve_unknown_fields) == NULL) {
    goto fail; //Bool
    }
    }


    // v1_json_schema_props->x_kubernetes_validations
    if(v1_json_schema_props->x_kubernetes_validations) {
    cJSON *x_kubernetes_validations = cJSON_AddArrayToObject(item, "x-kubernetes-validations");
    if(x_kubernetes_validations == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *x_kubernetes_validationsListEntry;
    if (v1_json_schema_props->x_kubernetes_validations) {
    list_ForEach(x_kubernetes_validationsListEntry, v1_json_schema_props->x_kubernetes_validations) {
    cJSON *itemLocal = v1_validation_rule_convertToJSON(x_kubernetes_validationsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(x_kubernetes_validations, itemLocal);
    }
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_json_schema_props_t *v1_json_schema_props_parseFromJSON(cJSON *v1_json_schema_propsJSON){

    v1_json_schema_props_t *v1_json_schema_props_local_var = NULL;

    // define the local list for v1_json_schema_props->all_of
    list_t *all_ofList = NULL;

    // define the local list for v1_json_schema_props->any_of
    list_t *any_ofList = NULL;

    // define the local map for v1_json_schema_props->definitions
    list_t *definitionsList = NULL;

    // define the local map for v1_json_schema_props->dependencies
    list_t *dependenciesList = NULL;

    // define the local list for v1_json_schema_props->_enum
    list_t *_enumList = NULL;

    // define the local variable for v1_json_schema_props->external_docs
    v1_external_documentation_t *external_docs_local_nonprim = NULL;

    // define the local variable for v1_json_schema_props->_not
    v1_json_schema_props_t *_not_local_nonprim = NULL;

    // define the local list for v1_json_schema_props->one_of
    list_t *one_ofList = NULL;

    // define the local map for v1_json_schema_props->pattern_properties
    list_t *pattern_propertiesList = NULL;

    // define the local map for v1_json_schema_props->properties
    list_t *propertiesList = NULL;

    // define the local list for v1_json_schema_props->required
    list_t *requiredList = NULL;

    // define the local list for v1_json_schema_props->x_kubernetes_list_map_keys
    list_t *x_kubernetes_list_map_keysList = NULL;

    // define the local list for v1_json_schema_props->x_kubernetes_validations
    list_t *x_kubernetes_validationsList = NULL;

    // v1_json_schema_props->ref
    cJSON *ref = cJSON_GetObjectItemCaseSensitive(v1_json_schema_propsJSON, "$ref");
    if (cJSON_IsNull(ref)) {
        ref = NULL;
    }
    if (ref) { 
    if(!cJSON_IsString(ref) && !cJSON_IsNull(ref))
    {
    goto end; //String
    }
    }

    // v1_json_schema_props->schema
    cJSON *schema = cJSON_GetObjectItemCaseSensitive(v1_json_schema_propsJSON, "$schema");
    if (cJSON_IsNull(schema)) {
        schema = NULL;
    }
    if (schema) { 
    if(!cJSON_IsString(schema) && !cJSON_IsNull(schema))
    {
    goto end; //String
    }
    }

    // v1_json_schema_props->additional_items
    cJSON *additional_items = cJSON_GetObjectItemCaseSensitive(v1_json_schema_propsJSON, "additionalItems");
    if (cJSON_IsNull(additional_items)) {
        additional_items = NULL;
    }
    object_t *additional_items_local_object = NULL;
    if (additional_items) { 
    additional_items_local_object = object_parseFromJSON(additional_items); //object
    }

    // v1_json_schema_props->additional_properties
    cJSON *additional_properties = cJSON_GetObjectItemCaseSensitive(v1_json_schema_propsJSON, "additionalProperties");
    if (cJSON_IsNull(additional_properties)) {
        additional_properties = NULL;
    }
    object_t *additional_properties_local_object = NULL;
    if (additional_properties) { 
    additional_properties_local_object = object_parseFromJSON(additional_properties); //object
    }

    // v1_json_schema_props->all_of
    cJSON *all_of = cJSON_GetObjectItemCaseSensitive(v1_json_schema_propsJSON, "allOf");
    if (cJSON_IsNull(all_of)) {
        all_of = NULL;
    }
    if (all_of) { 
    cJSON *all_of_local_nonprimitive = NULL;
    if(!cJSON_IsArray(all_of)){
        goto end; //nonprimitive container
    }

    all_ofList = list_createList();

    cJSON_ArrayForEach(all_of_local_nonprimitive,all_of )
    {
        if(!cJSON_IsObject(all_of_local_nonprimitive)){
            goto end;
        }
        v1_json_schema_props_t *all_ofItem = v1_json_schema_props_parseFromJSON(all_of_local_nonprimitive);

        list_addElement(all_ofList, all_ofItem);
    }
    }

    // v1_json_schema_props->any_of
    cJSON *any_of = cJSON_GetObjectItemCaseSensitive(v1_json_schema_propsJSON, "anyOf");
    if (cJSON_IsNull(any_of)) {
        any_of = NULL;
    }
    if (any_of) { 
    cJSON *any_of_local_nonprimitive = NULL;
    if(!cJSON_IsArray(any_of)){
        goto end; //nonprimitive container
    }

    any_ofList = list_createList();

    cJSON_ArrayForEach(any_of_local_nonprimitive,any_of )
    {
        if(!cJSON_IsObject(any_of_local_nonprimitive)){
            goto end;
        }
        v1_json_schema_props_t *any_ofItem = v1_json_schema_props_parseFromJSON(any_of_local_nonprimitive);

        list_addElement(any_ofList, any_ofItem);
    }
    }

    // v1_json_schema_props->_default
    cJSON *_default = cJSON_GetObjectItemCaseSensitive(v1_json_schema_propsJSON, "default");
    if (cJSON_IsNull(_default)) {
        _default = NULL;
    }
    object_t *_default_local_object = NULL;
    if (_default) { 
    _default_local_object = object_parseFromJSON(_default); //object
    }

    // v1_json_schema_props->definitions
    cJSON *definitions = cJSON_GetObjectItemCaseSensitive(v1_json_schema_propsJSON, "definitions");
    if (cJSON_IsNull(definitions)) {
        definitions = NULL;
    }
    if (definitions) { 

    // The data type of the elements in v1_json_schema_props->definitions is currently not supported.

    }

    // v1_json_schema_props->dependencies
    cJSON *dependencies = cJSON_GetObjectItemCaseSensitive(v1_json_schema_propsJSON, "dependencies");
    if (cJSON_IsNull(dependencies)) {
        dependencies = NULL;
    }
    if (dependencies) { 
    cJSON *dependencies_local_map = NULL;
    if(!cJSON_IsObject(dependencies) && !cJSON_IsNull(dependencies))
    {
        goto end;//primitive map container
    }
    if(cJSON_IsObject(dependencies))
    {
        dependenciesList = list_createList();
        keyValuePair_t *localMapKeyPair;
        cJSON_ArrayForEach(dependencies_local_map, dependencies)
        {
            cJSON *localMapObject = dependencies_local_map;
            list_addElement(dependenciesList , localMapKeyPair);
        }
    }
    }

    // v1_json_schema_props->description
    cJSON *description = cJSON_GetObjectItemCaseSensitive(v1_json_schema_propsJSON, "description");
    if (cJSON_IsNull(description)) {
        description = NULL;
    }
    if (description) { 
    if(!cJSON_IsString(description) && !cJSON_IsNull(description))
    {
    goto end; //String
    }
    }

    // v1_json_schema_props->_enum
    cJSON *_enum = cJSON_GetObjectItemCaseSensitive(v1_json_schema_propsJSON, "enum");
    if (cJSON_IsNull(_enum)) {
        _enum = NULL;
    }
    if (_enum) { 
    cJSON *_enum_local_nonprimitive = NULL;
    if(!cJSON_IsArray(_enum)){
        goto end; //nonprimitive container
    }

    _enumList = list_createList();

    cJSON_ArrayForEach(_enum_local_nonprimitive,_enum )
    {
        if(!cJSON_IsObject(_enum_local_nonprimitive)){
            goto end;
        }
        object_t *_enumItem = object_parseFromJSON(_enum_local_nonprimitive);

        list_addElement(_enumList, _enumItem);
    }
    }

    // v1_json_schema_props->example
    cJSON *example = cJSON_GetObjectItemCaseSensitive(v1_json_schema_propsJSON, "example");
    if (cJSON_IsNull(example)) {
        example = NULL;
    }
    object_t *example_local_object = NULL;
    if (example) { 
    example_local_object = object_parseFromJSON(example); //object
    }

    // v1_json_schema_props->exclusive_maximum
    cJSON *exclusive_maximum = cJSON_GetObjectItemCaseSensitive(v1_json_schema_propsJSON, "exclusiveMaximum");
    if (cJSON_IsNull(exclusive_maximum)) {
        exclusive_maximum = NULL;
    }
    if (exclusive_maximum) { 
    if(!cJSON_IsBool(exclusive_maximum))
    {
    goto end; //Bool
    }
    }

    // v1_json_schema_props->exclusive_minimum
    cJSON *exclusive_minimum = cJSON_GetObjectItemCaseSensitive(v1_json_schema_propsJSON, "exclusiveMinimum");
    if (cJSON_IsNull(exclusive_minimum)) {
        exclusive_minimum = NULL;
    }
    if (exclusive_minimum) { 
    if(!cJSON_IsBool(exclusive_minimum))
    {
    goto end; //Bool
    }
    }

    // v1_json_schema_props->external_docs
    cJSON *external_docs = cJSON_GetObjectItemCaseSensitive(v1_json_schema_propsJSON, "externalDocs");
    if (cJSON_IsNull(external_docs)) {
        external_docs = NULL;
    }
    if (external_docs) { 
    external_docs_local_nonprim = v1_external_documentation_parseFromJSON(external_docs); //nonprimitive
    }

    // v1_json_schema_props->format
    cJSON *format = cJSON_GetObjectItemCaseSensitive(v1_json_schema_propsJSON, "format");
    if (cJSON_IsNull(format)) {
        format = NULL;
    }
    if (format) { 
    if(!cJSON_IsString(format) && !cJSON_IsNull(format))
    {
    goto end; //String
    }
    }

    // v1_json_schema_props->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(v1_json_schema_propsJSON, "id");
    if (cJSON_IsNull(id)) {
        id = NULL;
    }
    if (id) { 
    if(!cJSON_IsString(id) && !cJSON_IsNull(id))
    {
    goto end; //String
    }
    }

    // v1_json_schema_props->items
    cJSON *items = cJSON_GetObjectItemCaseSensitive(v1_json_schema_propsJSON, "items");
    if (cJSON_IsNull(items)) {
        items = NULL;
    }
    object_t *items_local_object = NULL;
    if (items) { 
    items_local_object = object_parseFromJSON(items); //object
    }

    // v1_json_schema_props->max_items
    cJSON *max_items = cJSON_GetObjectItemCaseSensitive(v1_json_schema_propsJSON, "maxItems");
    if (cJSON_IsNull(max_items)) {
        max_items = NULL;
    }
    if (max_items) { 
    if(!cJSON_IsNumber(max_items))
    {
    goto end; //Numeric
    }
    }

    // v1_json_schema_props->max_length
    cJSON *max_length = cJSON_GetObjectItemCaseSensitive(v1_json_schema_propsJSON, "maxLength");
    if (cJSON_IsNull(max_length)) {
        max_length = NULL;
    }
    if (max_length) { 
    if(!cJSON_IsNumber(max_length))
    {
    goto end; //Numeric
    }
    }

    // v1_json_schema_props->max_properties
    cJSON *max_properties = cJSON_GetObjectItemCaseSensitive(v1_json_schema_propsJSON, "maxProperties");
    if (cJSON_IsNull(max_properties)) {
        max_properties = NULL;
    }
    if (max_properties) { 
    if(!cJSON_IsNumber(max_properties))
    {
    goto end; //Numeric
    }
    }

    // v1_json_schema_props->maximum
    cJSON *maximum = cJSON_GetObjectItemCaseSensitive(v1_json_schema_propsJSON, "maximum");
    if (cJSON_IsNull(maximum)) {
        maximum = NULL;
    }
    if (maximum) { 
    if(!cJSON_IsNumber(maximum))
    {
    goto end; //Numeric
    }
    }

    // v1_json_schema_props->min_items
    cJSON *min_items = cJSON_GetObjectItemCaseSensitive(v1_json_schema_propsJSON, "minItems");
    if (cJSON_IsNull(min_items)) {
        min_items = NULL;
    }
    if (min_items) { 
    if(!cJSON_IsNumber(min_items))
    {
    goto end; //Numeric
    }
    }

    // v1_json_schema_props->min_length
    cJSON *min_length = cJSON_GetObjectItemCaseSensitive(v1_json_schema_propsJSON, "minLength");
    if (cJSON_IsNull(min_length)) {
        min_length = NULL;
    }
    if (min_length) { 
    if(!cJSON_IsNumber(min_length))
    {
    goto end; //Numeric
    }
    }

    // v1_json_schema_props->min_properties
    cJSON *min_properties = cJSON_GetObjectItemCaseSensitive(v1_json_schema_propsJSON, "minProperties");
    if (cJSON_IsNull(min_properties)) {
        min_properties = NULL;
    }
    if (min_properties) { 
    if(!cJSON_IsNumber(min_properties))
    {
    goto end; //Numeric
    }
    }

    // v1_json_schema_props->minimum
    cJSON *minimum = cJSON_GetObjectItemCaseSensitive(v1_json_schema_propsJSON, "minimum");
    if (cJSON_IsNull(minimum)) {
        minimum = NULL;
    }
    if (minimum) { 
    if(!cJSON_IsNumber(minimum))
    {
    goto end; //Numeric
    }
    }

    // v1_json_schema_props->multiple_of
    cJSON *multiple_of = cJSON_GetObjectItemCaseSensitive(v1_json_schema_propsJSON, "multipleOf");
    if (cJSON_IsNull(multiple_of)) {
        multiple_of = NULL;
    }
    if (multiple_of) { 
    if(!cJSON_IsNumber(multiple_of))
    {
    goto end; //Numeric
    }
    }

    // v1_json_schema_props->_not
    cJSON *_not = cJSON_GetObjectItemCaseSensitive(v1_json_schema_propsJSON, "not");
    if (cJSON_IsNull(_not)) {
        _not = NULL;
    }
    if (_not) { 
    _not_local_nonprim = v1_json_schema_props_parseFromJSON(_not); //nonprimitive
    }

    // v1_json_schema_props->nullable
    cJSON *nullable = cJSON_GetObjectItemCaseSensitive(v1_json_schema_propsJSON, "nullable");
    if (cJSON_IsNull(nullable)) {
        nullable = NULL;
    }
    if (nullable) { 
    if(!cJSON_IsBool(nullable))
    {
    goto end; //Bool
    }
    }

    // v1_json_schema_props->one_of
    cJSON *one_of = cJSON_GetObjectItemCaseSensitive(v1_json_schema_propsJSON, "oneOf");
    if (cJSON_IsNull(one_of)) {
        one_of = NULL;
    }
    if (one_of) { 
    cJSON *one_of_local_nonprimitive = NULL;
    if(!cJSON_IsArray(one_of)){
        goto end; //nonprimitive container
    }

    one_ofList = list_createList();

    cJSON_ArrayForEach(one_of_local_nonprimitive,one_of )
    {
        if(!cJSON_IsObject(one_of_local_nonprimitive)){
            goto end;
        }
        v1_json_schema_props_t *one_ofItem = v1_json_schema_props_parseFromJSON(one_of_local_nonprimitive);

        list_addElement(one_ofList, one_ofItem);
    }
    }

    // v1_json_schema_props->pattern
    cJSON *pattern = cJSON_GetObjectItemCaseSensitive(v1_json_schema_propsJSON, "pattern");
    if (cJSON_IsNull(pattern)) {
        pattern = NULL;
    }
    if (pattern) { 
    if(!cJSON_IsString(pattern) && !cJSON_IsNull(pattern))
    {
    goto end; //String
    }
    }

    // v1_json_schema_props->pattern_properties
    cJSON *pattern_properties = cJSON_GetObjectItemCaseSensitive(v1_json_schema_propsJSON, "patternProperties");
    if (cJSON_IsNull(pattern_properties)) {
        pattern_properties = NULL;
    }
    if (pattern_properties) { 

    // The data type of the elements in v1_json_schema_props->pattern_properties is currently not supported.

    }

    // v1_json_schema_props->properties
    cJSON *properties = cJSON_GetObjectItemCaseSensitive(v1_json_schema_propsJSON, "properties");
    if (cJSON_IsNull(properties)) {
        properties = NULL;
    }
    if (properties) { 

    // The data type of the elements in v1_json_schema_props->properties is currently not supported.

    }

    // v1_json_schema_props->required
    cJSON *required = cJSON_GetObjectItemCaseSensitive(v1_json_schema_propsJSON, "required");
    if (cJSON_IsNull(required)) {
        required = NULL;
    }
    if (required) { 
    cJSON *required_local = NULL;
    if(!cJSON_IsArray(required)) {
        goto end;//primitive container
    }
    requiredList = list_createList();

    cJSON_ArrayForEach(required_local, required)
    {
        if(!cJSON_IsString(required_local))
        {
            goto end;
        }
        list_addElement(requiredList , strdup(required_local->valuestring));
    }
    }

    // v1_json_schema_props->title
    cJSON *title = cJSON_GetObjectItemCaseSensitive(v1_json_schema_propsJSON, "title");
    if (cJSON_IsNull(title)) {
        title = NULL;
    }
    if (title) { 
    if(!cJSON_IsString(title) && !cJSON_IsNull(title))
    {
    goto end; //String
    }
    }

    // v1_json_schema_props->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(v1_json_schema_propsJSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    if (type) { 
    if(!cJSON_IsString(type) && !cJSON_IsNull(type))
    {
    goto end; //String
    }
    }

    // v1_json_schema_props->unique_items
    cJSON *unique_items = cJSON_GetObjectItemCaseSensitive(v1_json_schema_propsJSON, "uniqueItems");
    if (cJSON_IsNull(unique_items)) {
        unique_items = NULL;
    }
    if (unique_items) { 
    if(!cJSON_IsBool(unique_items))
    {
    goto end; //Bool
    }
    }

    // v1_json_schema_props->x_kubernetes_embedded_resource
    cJSON *x_kubernetes_embedded_resource = cJSON_GetObjectItemCaseSensitive(v1_json_schema_propsJSON, "x-kubernetes-embedded-resource");
    if (cJSON_IsNull(x_kubernetes_embedded_resource)) {
        x_kubernetes_embedded_resource = NULL;
    }
    if (x_kubernetes_embedded_resource) { 
    if(!cJSON_IsBool(x_kubernetes_embedded_resource))
    {
    goto end; //Bool
    }
    }

    // v1_json_schema_props->x_kubernetes_int_or_string
    cJSON *x_kubernetes_int_or_string = cJSON_GetObjectItemCaseSensitive(v1_json_schema_propsJSON, "x-kubernetes-int-or-string");
    if (cJSON_IsNull(x_kubernetes_int_or_string)) {
        x_kubernetes_int_or_string = NULL;
    }
    if (x_kubernetes_int_or_string) { 
    if(!cJSON_IsBool(x_kubernetes_int_or_string))
    {
    goto end; //Bool
    }
    }

    // v1_json_schema_props->x_kubernetes_list_map_keys
    cJSON *x_kubernetes_list_map_keys = cJSON_GetObjectItemCaseSensitive(v1_json_schema_propsJSON, "x-kubernetes-list-map-keys");
    if (cJSON_IsNull(x_kubernetes_list_map_keys)) {
        x_kubernetes_list_map_keys = NULL;
    }
    if (x_kubernetes_list_map_keys) { 
    cJSON *x_kubernetes_list_map_keys_local = NULL;
    if(!cJSON_IsArray(x_kubernetes_list_map_keys)) {
        goto end;//primitive container
    }
    x_kubernetes_list_map_keysList = list_createList();

    cJSON_ArrayForEach(x_kubernetes_list_map_keys_local, x_kubernetes_list_map_keys)
    {
        if(!cJSON_IsString(x_kubernetes_list_map_keys_local))
        {
            goto end;
        }
        list_addElement(x_kubernetes_list_map_keysList , strdup(x_kubernetes_list_map_keys_local->valuestring));
    }
    }

    // v1_json_schema_props->x_kubernetes_list_type
    cJSON *x_kubernetes_list_type = cJSON_GetObjectItemCaseSensitive(v1_json_schema_propsJSON, "x-kubernetes-list-type");
    if (cJSON_IsNull(x_kubernetes_list_type)) {
        x_kubernetes_list_type = NULL;
    }
    if (x_kubernetes_list_type) { 
    if(!cJSON_IsString(x_kubernetes_list_type) && !cJSON_IsNull(x_kubernetes_list_type))
    {
    goto end; //String
    }
    }

    // v1_json_schema_props->x_kubernetes_map_type
    cJSON *x_kubernetes_map_type = cJSON_GetObjectItemCaseSensitive(v1_json_schema_propsJSON, "x-kubernetes-map-type");
    if (cJSON_IsNull(x_kubernetes_map_type)) {
        x_kubernetes_map_type = NULL;
    }
    if (x_kubernetes_map_type) { 
    if(!cJSON_IsString(x_kubernetes_map_type) && !cJSON_IsNull(x_kubernetes_map_type))
    {
    goto end; //String
    }
    }

    // v1_json_schema_props->x_kubernetes_preserve_unknown_fields
    cJSON *x_kubernetes_preserve_unknown_fields = cJSON_GetObjectItemCaseSensitive(v1_json_schema_propsJSON, "x-kubernetes-preserve-unknown-fields");
    if (cJSON_IsNull(x_kubernetes_preserve_unknown_fields)) {
        x_kubernetes_preserve_unknown_fields = NULL;
    }
    if (x_kubernetes_preserve_unknown_fields) { 
    if(!cJSON_IsBool(x_kubernetes_preserve_unknown_fields))
    {
    goto end; //Bool
    }
    }

    // v1_json_schema_props->x_kubernetes_validations
    cJSON *x_kubernetes_validations = cJSON_GetObjectItemCaseSensitive(v1_json_schema_propsJSON, "x-kubernetes-validations");
    if (cJSON_IsNull(x_kubernetes_validations)) {
        x_kubernetes_validations = NULL;
    }
    if (x_kubernetes_validations) { 
    cJSON *x_kubernetes_validations_local_nonprimitive = NULL;
    if(!cJSON_IsArray(x_kubernetes_validations)){
        goto end; //nonprimitive container
    }

    x_kubernetes_validationsList = list_createList();

    cJSON_ArrayForEach(x_kubernetes_validations_local_nonprimitive,x_kubernetes_validations )
    {
        if(!cJSON_IsObject(x_kubernetes_validations_local_nonprimitive)){
            goto end;
        }
        v1_validation_rule_t *x_kubernetes_validationsItem = v1_validation_rule_parseFromJSON(x_kubernetes_validations_local_nonprimitive);

        list_addElement(x_kubernetes_validationsList, x_kubernetes_validationsItem);
    }
    }


    v1_json_schema_props_local_var = v1_json_schema_props_create_internal (
        ref && !cJSON_IsNull(ref) ? strdup(ref->valuestring) : NULL,
        schema && !cJSON_IsNull(schema) ? strdup(schema->valuestring) : NULL,
        additional_items ? additional_items_local_object : NULL,
        additional_properties ? additional_properties_local_object : NULL,
        all_of ? all_ofList : NULL,
        any_of ? any_ofList : NULL,
        _default ? _default_local_object : NULL,
        definitions ? definitionsList : NULL,
        dependencies ? dependenciesList : NULL,
        description && !cJSON_IsNull(description) ? strdup(description->valuestring) : NULL,
        _enum ? _enumList : NULL,
        example ? example_local_object : NULL,
        exclusive_maximum ? exclusive_maximum->valueint : 0,
        exclusive_minimum ? exclusive_minimum->valueint : 0,
        external_docs ? external_docs_local_nonprim : NULL,
        format && !cJSON_IsNull(format) ? strdup(format->valuestring) : NULL,
        id && !cJSON_IsNull(id) ? strdup(id->valuestring) : NULL,
        items ? items_local_object : NULL,
        max_items ? max_items->valuedouble : 0,
        max_length ? max_length->valuedouble : 0,
        max_properties ? max_properties->valuedouble : 0,
        maximum ? maximum->valuedouble : 0,
        min_items ? min_items->valuedouble : 0,
        min_length ? min_length->valuedouble : 0,
        min_properties ? min_properties->valuedouble : 0,
        minimum ? minimum->valuedouble : 0,
        multiple_of ? multiple_of->valuedouble : 0,
        _not ? _not_local_nonprim : NULL,
        nullable ? nullable->valueint : 0,
        one_of ? one_ofList : NULL,
        pattern && !cJSON_IsNull(pattern) ? strdup(pattern->valuestring) : NULL,
        pattern_properties ? pattern_propertiesList : NULL,
        properties ? propertiesList : NULL,
        required ? requiredList : NULL,
        title && !cJSON_IsNull(title) ? strdup(title->valuestring) : NULL,
        type && !cJSON_IsNull(type) ? strdup(type->valuestring) : NULL,
        unique_items ? unique_items->valueint : 0,
        x_kubernetes_embedded_resource ? x_kubernetes_embedded_resource->valueint : 0,
        x_kubernetes_int_or_string ? x_kubernetes_int_or_string->valueint : 0,
        x_kubernetes_list_map_keys ? x_kubernetes_list_map_keysList : NULL,
        x_kubernetes_list_type && !cJSON_IsNull(x_kubernetes_list_type) ? strdup(x_kubernetes_list_type->valuestring) : NULL,
        x_kubernetes_map_type && !cJSON_IsNull(x_kubernetes_map_type) ? strdup(x_kubernetes_map_type->valuestring) : NULL,
        x_kubernetes_preserve_unknown_fields ? x_kubernetes_preserve_unknown_fields->valueint : 0,
        x_kubernetes_validations ? x_kubernetes_validationsList : NULL
        );

    return v1_json_schema_props_local_var;
end:
    if (all_ofList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, all_ofList) {
            v1_json_schema_props_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(all_ofList);
        all_ofList = NULL;
    }
    if (any_ofList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, any_ofList) {
            v1_json_schema_props_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(any_ofList);
        any_ofList = NULL;
    }

    // The data type of the elements in v1_json_schema_props->definitions is currently not supported.

    if (dependenciesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, dependenciesList) {
            keyValuePair_t *localKeyValue = listEntry->data;
            free(localKeyValue->key);
            localKeyValue->key = NULL;
            keyValuePair_free(localKeyValue);
            localKeyValue = NULL;
        }
        list_freeList(dependenciesList);
        dependenciesList = NULL;
    }
    if (_enumList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, _enumList) {
            object_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(_enumList);
        _enumList = NULL;
    }
    if (external_docs_local_nonprim) {
        v1_external_documentation_free(external_docs_local_nonprim);
        external_docs_local_nonprim = NULL;
    }
    if (_not_local_nonprim) {
        v1_json_schema_props_free(_not_local_nonprim);
        _not_local_nonprim = NULL;
    }
    if (one_ofList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, one_ofList) {
            v1_json_schema_props_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(one_ofList);
        one_ofList = NULL;
    }

    // The data type of the elements in v1_json_schema_props->pattern_properties is currently not supported.


    // The data type of the elements in v1_json_schema_props->properties is currently not supported.

    if (requiredList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, requiredList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(requiredList);
        requiredList = NULL;
    }
    if (x_kubernetes_list_map_keysList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, x_kubernetes_list_map_keysList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(x_kubernetes_list_map_keysList);
        x_kubernetes_list_map_keysList = NULL;
    }
    if (x_kubernetes_validationsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, x_kubernetes_validationsList) {
            v1_validation_rule_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(x_kubernetes_validationsList);
        x_kubernetes_validationsList = NULL;
    }
    return NULL;

}
