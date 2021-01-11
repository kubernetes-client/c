#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_json_schema_props.h"



v1beta1_json_schema_props_t *v1beta1_json_schema_props_create(
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
    v1beta1_external_documentation_t *external_docs,
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
    v1beta1_json_schema_props_t *_not,
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
    ) {
    v1beta1_json_schema_props_t *v1beta1_json_schema_props_local_var = malloc(sizeof(v1beta1_json_schema_props_t));
    if (!v1beta1_json_schema_props_local_var) {
        return NULL;
    }
    v1beta1_json_schema_props_local_var->ref = ref;
    v1beta1_json_schema_props_local_var->schema = schema;
    v1beta1_json_schema_props_local_var->additional_items = additional_items;
    v1beta1_json_schema_props_local_var->additional_properties = additional_properties;
    v1beta1_json_schema_props_local_var->all_of = all_of;
    v1beta1_json_schema_props_local_var->any_of = any_of;
    v1beta1_json_schema_props_local_var->_default = _default;
    v1beta1_json_schema_props_local_var->definitions = definitions;
    v1beta1_json_schema_props_local_var->dependencies = dependencies;
    v1beta1_json_schema_props_local_var->description = description;
    v1beta1_json_schema_props_local_var->_enum = _enum;
    v1beta1_json_schema_props_local_var->example = example;
    v1beta1_json_schema_props_local_var->exclusive_maximum = exclusive_maximum;
    v1beta1_json_schema_props_local_var->exclusive_minimum = exclusive_minimum;
    v1beta1_json_schema_props_local_var->external_docs = external_docs;
    v1beta1_json_schema_props_local_var->format = format;
    v1beta1_json_schema_props_local_var->id = id;
    v1beta1_json_schema_props_local_var->items = items;
    v1beta1_json_schema_props_local_var->max_items = max_items;
    v1beta1_json_schema_props_local_var->max_length = max_length;
    v1beta1_json_schema_props_local_var->max_properties = max_properties;
    v1beta1_json_schema_props_local_var->maximum = maximum;
    v1beta1_json_schema_props_local_var->min_items = min_items;
    v1beta1_json_schema_props_local_var->min_length = min_length;
    v1beta1_json_schema_props_local_var->min_properties = min_properties;
    v1beta1_json_schema_props_local_var->minimum = minimum;
    v1beta1_json_schema_props_local_var->multiple_of = multiple_of;
    v1beta1_json_schema_props_local_var->_not = _not;
    v1beta1_json_schema_props_local_var->nullable = nullable;
    v1beta1_json_schema_props_local_var->one_of = one_of;
    v1beta1_json_schema_props_local_var->pattern = pattern;
    v1beta1_json_schema_props_local_var->pattern_properties = pattern_properties;
    v1beta1_json_schema_props_local_var->properties = properties;
    v1beta1_json_schema_props_local_var->required = required;
    v1beta1_json_schema_props_local_var->title = title;
    v1beta1_json_schema_props_local_var->type = type;
    v1beta1_json_schema_props_local_var->unique_items = unique_items;
    v1beta1_json_schema_props_local_var->x_kubernetes_embedded_resource = x_kubernetes_embedded_resource;
    v1beta1_json_schema_props_local_var->x_kubernetes_int_or_string = x_kubernetes_int_or_string;
    v1beta1_json_schema_props_local_var->x_kubernetes_list_map_keys = x_kubernetes_list_map_keys;
    v1beta1_json_schema_props_local_var->x_kubernetes_list_type = x_kubernetes_list_type;
    v1beta1_json_schema_props_local_var->x_kubernetes_map_type = x_kubernetes_map_type;
    v1beta1_json_schema_props_local_var->x_kubernetes_preserve_unknown_fields = x_kubernetes_preserve_unknown_fields;

    return v1beta1_json_schema_props_local_var;
}


void v1beta1_json_schema_props_free(v1beta1_json_schema_props_t *v1beta1_json_schema_props) {
    if(NULL == v1beta1_json_schema_props){
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta1_json_schema_props->ref) {
        free(v1beta1_json_schema_props->ref);
        v1beta1_json_schema_props->ref = NULL;
    }
    if (v1beta1_json_schema_props->schema) {
        free(v1beta1_json_schema_props->schema);
        v1beta1_json_schema_props->schema = NULL;
    }
    if (v1beta1_json_schema_props->additional_items) {
        object_free(v1beta1_json_schema_props->additional_items);
        v1beta1_json_schema_props->additional_items = NULL;
    }
    if (v1beta1_json_schema_props->additional_properties) {
        object_free(v1beta1_json_schema_props->additional_properties);
        v1beta1_json_schema_props->additional_properties = NULL;
    }
    if (v1beta1_json_schema_props->all_of) {
        list_ForEach(listEntry, v1beta1_json_schema_props->all_of) {
            v1beta1_json_schema_props_free(listEntry->data);
        }
        list_free(v1beta1_json_schema_props->all_of);
        v1beta1_json_schema_props->all_of = NULL;
    }
    if (v1beta1_json_schema_props->any_of) {
        list_ForEach(listEntry, v1beta1_json_schema_props->any_of) {
            v1beta1_json_schema_props_free(listEntry->data);
        }
        list_free(v1beta1_json_schema_props->any_of);
        v1beta1_json_schema_props->any_of = NULL;
    }
    if (v1beta1_json_schema_props->_default) {
        object_free(v1beta1_json_schema_props->_default);
        v1beta1_json_schema_props->_default = NULL;
    }
    if (v1beta1_json_schema_props->definitions) {
        list_ForEach(listEntry, v1beta1_json_schema_props->definitions) {
            keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_free(v1beta1_json_schema_props->definitions);
        v1beta1_json_schema_props->definitions = NULL;
    }
    if (v1beta1_json_schema_props->dependencies) {
        list_ForEach(listEntry, v1beta1_json_schema_props->dependencies) {
            keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_free(v1beta1_json_schema_props->dependencies);
        v1beta1_json_schema_props->dependencies = NULL;
    }
    if (v1beta1_json_schema_props->description) {
        free(v1beta1_json_schema_props->description);
        v1beta1_json_schema_props->description = NULL;
    }
    if (v1beta1_json_schema_props->_enum) {
        list_ForEach(listEntry, v1beta1_json_schema_props->_enum) {
            object_free(listEntry->data);
        }
        list_free(v1beta1_json_schema_props->_enum);
        v1beta1_json_schema_props->_enum = NULL;
    }
    if (v1beta1_json_schema_props->example) {
        object_free(v1beta1_json_schema_props->example);
        v1beta1_json_schema_props->example = NULL;
    }
    if (v1beta1_json_schema_props->external_docs) {
        v1beta1_external_documentation_free(v1beta1_json_schema_props->external_docs);
        v1beta1_json_schema_props->external_docs = NULL;
    }
    if (v1beta1_json_schema_props->format) {
        free(v1beta1_json_schema_props->format);
        v1beta1_json_schema_props->format = NULL;
    }
    if (v1beta1_json_schema_props->id) {
        free(v1beta1_json_schema_props->id);
        v1beta1_json_schema_props->id = NULL;
    }
    if (v1beta1_json_schema_props->items) {
        object_free(v1beta1_json_schema_props->items);
        v1beta1_json_schema_props->items = NULL;
    }
    if (v1beta1_json_schema_props->_not) {
        v1beta1_json_schema_props_free(v1beta1_json_schema_props->_not);
        v1beta1_json_schema_props->_not = NULL;
    }
    if (v1beta1_json_schema_props->one_of) {
        list_ForEach(listEntry, v1beta1_json_schema_props->one_of) {
            v1beta1_json_schema_props_free(listEntry->data);
        }
        list_free(v1beta1_json_schema_props->one_of);
        v1beta1_json_schema_props->one_of = NULL;
    }
    if (v1beta1_json_schema_props->pattern) {
        free(v1beta1_json_schema_props->pattern);
        v1beta1_json_schema_props->pattern = NULL;
    }
    if (v1beta1_json_schema_props->pattern_properties) {
        list_ForEach(listEntry, v1beta1_json_schema_props->pattern_properties) {
            keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_free(v1beta1_json_schema_props->pattern_properties);
        v1beta1_json_schema_props->pattern_properties = NULL;
    }
    if (v1beta1_json_schema_props->properties) {
        list_ForEach(listEntry, v1beta1_json_schema_props->properties) {
            keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_free(v1beta1_json_schema_props->properties);
        v1beta1_json_schema_props->properties = NULL;
    }
    if (v1beta1_json_schema_props->required) {
        list_ForEach(listEntry, v1beta1_json_schema_props->required) {
            free(listEntry->data);
        }
        list_free(v1beta1_json_schema_props->required);
        v1beta1_json_schema_props->required = NULL;
    }
    if (v1beta1_json_schema_props->title) {
        free(v1beta1_json_schema_props->title);
        v1beta1_json_schema_props->title = NULL;
    }
    if (v1beta1_json_schema_props->type) {
        free(v1beta1_json_schema_props->type);
        v1beta1_json_schema_props->type = NULL;
    }
    if (v1beta1_json_schema_props->x_kubernetes_list_map_keys) {
        list_ForEach(listEntry, v1beta1_json_schema_props->x_kubernetes_list_map_keys) {
            free(listEntry->data);
        }
        list_free(v1beta1_json_schema_props->x_kubernetes_list_map_keys);
        v1beta1_json_schema_props->x_kubernetes_list_map_keys = NULL;
    }
    if (v1beta1_json_schema_props->x_kubernetes_list_type) {
        free(v1beta1_json_schema_props->x_kubernetes_list_type);
        v1beta1_json_schema_props->x_kubernetes_list_type = NULL;
    }
    if (v1beta1_json_schema_props->x_kubernetes_map_type) {
        free(v1beta1_json_schema_props->x_kubernetes_map_type);
        v1beta1_json_schema_props->x_kubernetes_map_type = NULL;
    }
    free(v1beta1_json_schema_props);
}

cJSON *v1beta1_json_schema_props_convertToJSON(v1beta1_json_schema_props_t *v1beta1_json_schema_props) {
    cJSON *item = cJSON_CreateObject();

    // v1beta1_json_schema_props->ref
    if(v1beta1_json_schema_props->ref) { 
    if(cJSON_AddStringToObject(item, "$ref", v1beta1_json_schema_props->ref) == NULL) {
    goto fail; //String
    }
     } 


    // v1beta1_json_schema_props->schema
    if(v1beta1_json_schema_props->schema) { 
    if(cJSON_AddStringToObject(item, "$schema", v1beta1_json_schema_props->schema) == NULL) {
    goto fail; //String
    }
     } 


    // v1beta1_json_schema_props->additional_items
    if(v1beta1_json_schema_props->additional_items) { 
    cJSON *additional_items_object = object_convertToJSON(v1beta1_json_schema_props->additional_items);
    if(additional_items_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "additionalItems", additional_items_object);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1beta1_json_schema_props->additional_properties
    if(v1beta1_json_schema_props->additional_properties) { 
    cJSON *additional_properties_object = object_convertToJSON(v1beta1_json_schema_props->additional_properties);
    if(additional_properties_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "additionalProperties", additional_properties_object);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1beta1_json_schema_props->all_of
    if(v1beta1_json_schema_props->all_of) { 
    cJSON *all_of = cJSON_AddArrayToObject(item, "allOf");
    if(all_of == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *all_ofListEntry;
    if (v1beta1_json_schema_props->all_of) {
    list_ForEach(all_ofListEntry, v1beta1_json_schema_props->all_of) {
    cJSON *itemLocal = v1beta1_json_schema_props_convertToJSON(all_ofListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(all_of, itemLocal);
    }
    }
     } 


    // v1beta1_json_schema_props->any_of
    if(v1beta1_json_schema_props->any_of) { 
    cJSON *any_of = cJSON_AddArrayToObject(item, "anyOf");
    if(any_of == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *any_ofListEntry;
    if (v1beta1_json_schema_props->any_of) {
    list_ForEach(any_ofListEntry, v1beta1_json_schema_props->any_of) {
    cJSON *itemLocal = v1beta1_json_schema_props_convertToJSON(any_ofListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(any_of, itemLocal);
    }
    }
     } 


    // v1beta1_json_schema_props->_default
    if(v1beta1_json_schema_props->_default) { 
    cJSON *_default_object = object_convertToJSON(v1beta1_json_schema_props->_default);
    if(_default_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "default", _default_object);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1beta1_json_schema_props->definitions
    if(v1beta1_json_schema_props->definitions) { 
    cJSON *definitions = cJSON_AddObjectToObject(item, "definitions");
    if(definitions == NULL) {
        goto fail; //primitive map container
    }
    cJSON *localMapObject = definitions;
    listEntry_t *definitionsListEntry;
    if (v1beta1_json_schema_props->definitions) {
    list_ForEach(definitionsListEntry, v1beta1_json_schema_props->definitions) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)definitionsListEntry->data;
    }
    }
     } 


    // v1beta1_json_schema_props->dependencies
    if(v1beta1_json_schema_props->dependencies) { 
    cJSON *dependencies = cJSON_AddObjectToObject(item, "dependencies");
    if(dependencies == NULL) {
        goto fail; //primitive map container
    }
    cJSON *localMapObject = dependencies;
    listEntry_t *dependenciesListEntry;
    if (v1beta1_json_schema_props->dependencies) {
    list_ForEach(dependenciesListEntry, v1beta1_json_schema_props->dependencies) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)dependenciesListEntry->data;
    }
    }
     } 


    // v1beta1_json_schema_props->description
    if(v1beta1_json_schema_props->description) { 
    if(cJSON_AddStringToObject(item, "description", v1beta1_json_schema_props->description) == NULL) {
    goto fail; //String
    }
     } 


    // v1beta1_json_schema_props->_enum
    if(v1beta1_json_schema_props->_enum) { 
    cJSON *_enum = cJSON_AddArrayToObject(item, "enum");
    if(_enum == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *_enumListEntry;
    if (v1beta1_json_schema_props->_enum) {
    list_ForEach(_enumListEntry, v1beta1_json_schema_props->_enum) {
    cJSON *itemLocal = object_convertToJSON(_enumListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(_enum, itemLocal);
    }
    }
     } 


    // v1beta1_json_schema_props->example
    if(v1beta1_json_schema_props->example) { 
    cJSON *example_object = object_convertToJSON(v1beta1_json_schema_props->example);
    if(example_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "example", example_object);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1beta1_json_schema_props->exclusive_maximum
    if(v1beta1_json_schema_props->exclusive_maximum) { 
    if(cJSON_AddBoolToObject(item, "exclusiveMaximum", v1beta1_json_schema_props->exclusive_maximum) == NULL) {
    goto fail; //Bool
    }
     } 


    // v1beta1_json_schema_props->exclusive_minimum
    if(v1beta1_json_schema_props->exclusive_minimum) { 
    if(cJSON_AddBoolToObject(item, "exclusiveMinimum", v1beta1_json_schema_props->exclusive_minimum) == NULL) {
    goto fail; //Bool
    }
     } 


    // v1beta1_json_schema_props->external_docs
    if(v1beta1_json_schema_props->external_docs) { 
    cJSON *external_docs_local_JSON = v1beta1_external_documentation_convertToJSON(v1beta1_json_schema_props->external_docs);
    if(external_docs_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "externalDocs", external_docs_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1beta1_json_schema_props->format
    if(v1beta1_json_schema_props->format) { 
    if(cJSON_AddStringToObject(item, "format", v1beta1_json_schema_props->format) == NULL) {
    goto fail; //String
    }
     } 


    // v1beta1_json_schema_props->id
    if(v1beta1_json_schema_props->id) { 
    if(cJSON_AddStringToObject(item, "id", v1beta1_json_schema_props->id) == NULL) {
    goto fail; //String
    }
     } 


    // v1beta1_json_schema_props->items
    if(v1beta1_json_schema_props->items) { 
    cJSON *items_object = object_convertToJSON(v1beta1_json_schema_props->items);
    if(items_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "items", items_object);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1beta1_json_schema_props->max_items
    if(v1beta1_json_schema_props->max_items) { 
    if(cJSON_AddNumberToObject(item, "maxItems", v1beta1_json_schema_props->max_items) == NULL) {
    goto fail; //Numeric
    }
     } 


    // v1beta1_json_schema_props->max_length
    if(v1beta1_json_schema_props->max_length) { 
    if(cJSON_AddNumberToObject(item, "maxLength", v1beta1_json_schema_props->max_length) == NULL) {
    goto fail; //Numeric
    }
     } 


    // v1beta1_json_schema_props->max_properties
    if(v1beta1_json_schema_props->max_properties) { 
    if(cJSON_AddNumberToObject(item, "maxProperties", v1beta1_json_schema_props->max_properties) == NULL) {
    goto fail; //Numeric
    }
     } 


    // v1beta1_json_schema_props->maximum
    if(v1beta1_json_schema_props->maximum) { 
    if(cJSON_AddNumberToObject(item, "maximum", v1beta1_json_schema_props->maximum) == NULL) {
    goto fail; //Numeric
    }
     } 


    // v1beta1_json_schema_props->min_items
    if(v1beta1_json_schema_props->min_items) { 
    if(cJSON_AddNumberToObject(item, "minItems", v1beta1_json_schema_props->min_items) == NULL) {
    goto fail; //Numeric
    }
     } 


    // v1beta1_json_schema_props->min_length
    if(v1beta1_json_schema_props->min_length) { 
    if(cJSON_AddNumberToObject(item, "minLength", v1beta1_json_schema_props->min_length) == NULL) {
    goto fail; //Numeric
    }
     } 


    // v1beta1_json_schema_props->min_properties
    if(v1beta1_json_schema_props->min_properties) { 
    if(cJSON_AddNumberToObject(item, "minProperties", v1beta1_json_schema_props->min_properties) == NULL) {
    goto fail; //Numeric
    }
     } 


    // v1beta1_json_schema_props->minimum
    if(v1beta1_json_schema_props->minimum) { 
    if(cJSON_AddNumberToObject(item, "minimum", v1beta1_json_schema_props->minimum) == NULL) {
    goto fail; //Numeric
    }
     } 


    // v1beta1_json_schema_props->multiple_of
    if(v1beta1_json_schema_props->multiple_of) { 
    if(cJSON_AddNumberToObject(item, "multipleOf", v1beta1_json_schema_props->multiple_of) == NULL) {
    goto fail; //Numeric
    }
     } 


    // v1beta1_json_schema_props->_not
    if(v1beta1_json_schema_props->_not) { 
    cJSON *_not_local_JSON = v1beta1_json_schema_props_convertToJSON(v1beta1_json_schema_props->_not);
    if(_not_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "not", _not_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1beta1_json_schema_props->nullable
    if(v1beta1_json_schema_props->nullable) { 
    if(cJSON_AddBoolToObject(item, "nullable", v1beta1_json_schema_props->nullable) == NULL) {
    goto fail; //Bool
    }
     } 


    // v1beta1_json_schema_props->one_of
    if(v1beta1_json_schema_props->one_of) { 
    cJSON *one_of = cJSON_AddArrayToObject(item, "oneOf");
    if(one_of == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *one_ofListEntry;
    if (v1beta1_json_schema_props->one_of) {
    list_ForEach(one_ofListEntry, v1beta1_json_schema_props->one_of) {
    cJSON *itemLocal = v1beta1_json_schema_props_convertToJSON(one_ofListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(one_of, itemLocal);
    }
    }
     } 


    // v1beta1_json_schema_props->pattern
    if(v1beta1_json_schema_props->pattern) { 
    if(cJSON_AddStringToObject(item, "pattern", v1beta1_json_schema_props->pattern) == NULL) {
    goto fail; //String
    }
     } 


    // v1beta1_json_schema_props->pattern_properties
    if(v1beta1_json_schema_props->pattern_properties) { 
    cJSON *pattern_properties = cJSON_AddObjectToObject(item, "patternProperties");
    if(pattern_properties == NULL) {
        goto fail; //primitive map container
    }
    cJSON *localMapObject = pattern_properties;
    listEntry_t *pattern_propertiesListEntry;
    if (v1beta1_json_schema_props->pattern_properties) {
    list_ForEach(pattern_propertiesListEntry, v1beta1_json_schema_props->pattern_properties) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)pattern_propertiesListEntry->data;
    }
    }
     } 


    // v1beta1_json_schema_props->properties
    if(v1beta1_json_schema_props->properties) { 
    cJSON *properties = cJSON_AddObjectToObject(item, "properties");
    if(properties == NULL) {
        goto fail; //primitive map container
    }
    cJSON *localMapObject = properties;
    listEntry_t *propertiesListEntry;
    if (v1beta1_json_schema_props->properties) {
    list_ForEach(propertiesListEntry, v1beta1_json_schema_props->properties) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)propertiesListEntry->data;
    }
    }
     } 


    // v1beta1_json_schema_props->required
    if(v1beta1_json_schema_props->required) { 
    cJSON *required = cJSON_AddArrayToObject(item, "required");
    if(required == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *requiredListEntry;
    list_ForEach(requiredListEntry, v1beta1_json_schema_props->required) {
    if(cJSON_AddStringToObject(required, "", (char*)requiredListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 


    // v1beta1_json_schema_props->title
    if(v1beta1_json_schema_props->title) { 
    if(cJSON_AddStringToObject(item, "title", v1beta1_json_schema_props->title) == NULL) {
    goto fail; //String
    }
     } 


    // v1beta1_json_schema_props->type
    if(v1beta1_json_schema_props->type) { 
    if(cJSON_AddStringToObject(item, "type", v1beta1_json_schema_props->type) == NULL) {
    goto fail; //String
    }
     } 


    // v1beta1_json_schema_props->unique_items
    if(v1beta1_json_schema_props->unique_items) { 
    if(cJSON_AddBoolToObject(item, "uniqueItems", v1beta1_json_schema_props->unique_items) == NULL) {
    goto fail; //Bool
    }
     } 


    // v1beta1_json_schema_props->x_kubernetes_embedded_resource
    if(v1beta1_json_schema_props->x_kubernetes_embedded_resource) { 
    if(cJSON_AddBoolToObject(item, "x-kubernetes-embedded-resource", v1beta1_json_schema_props->x_kubernetes_embedded_resource) == NULL) {
    goto fail; //Bool
    }
     } 


    // v1beta1_json_schema_props->x_kubernetes_int_or_string
    if(v1beta1_json_schema_props->x_kubernetes_int_or_string) { 
    if(cJSON_AddBoolToObject(item, "x-kubernetes-int-or-string", v1beta1_json_schema_props->x_kubernetes_int_or_string) == NULL) {
    goto fail; //Bool
    }
     } 


    // v1beta1_json_schema_props->x_kubernetes_list_map_keys
    if(v1beta1_json_schema_props->x_kubernetes_list_map_keys) { 
    cJSON *x_kubernetes_list_map_keys = cJSON_AddArrayToObject(item, "x-kubernetes-list-map-keys");
    if(x_kubernetes_list_map_keys == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *x_kubernetes_list_map_keysListEntry;
    list_ForEach(x_kubernetes_list_map_keysListEntry, v1beta1_json_schema_props->x_kubernetes_list_map_keys) {
    if(cJSON_AddStringToObject(x_kubernetes_list_map_keys, "", (char*)x_kubernetes_list_map_keysListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 


    // v1beta1_json_schema_props->x_kubernetes_list_type
    if(v1beta1_json_schema_props->x_kubernetes_list_type) { 
    if(cJSON_AddStringToObject(item, "x-kubernetes-list-type", v1beta1_json_schema_props->x_kubernetes_list_type) == NULL) {
    goto fail; //String
    }
     } 


    // v1beta1_json_schema_props->x_kubernetes_map_type
    if(v1beta1_json_schema_props->x_kubernetes_map_type) { 
    if(cJSON_AddStringToObject(item, "x-kubernetes-map-type", v1beta1_json_schema_props->x_kubernetes_map_type) == NULL) {
    goto fail; //String
    }
     } 


    // v1beta1_json_schema_props->x_kubernetes_preserve_unknown_fields
    if(v1beta1_json_schema_props->x_kubernetes_preserve_unknown_fields) { 
    if(cJSON_AddBoolToObject(item, "x-kubernetes-preserve-unknown-fields", v1beta1_json_schema_props->x_kubernetes_preserve_unknown_fields) == NULL) {
    goto fail; //Bool
    }
     } 

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1beta1_json_schema_props_t *v1beta1_json_schema_props_parseFromJSON(cJSON *v1beta1_json_schema_propsJSON){

    v1beta1_json_schema_props_t *v1beta1_json_schema_props_local_var = NULL;

    // v1beta1_json_schema_props->ref
    cJSON *ref = cJSON_GetObjectItemCaseSensitive(v1beta1_json_schema_propsJSON, "$ref");
    if (ref) { 
    if(!cJSON_IsString(ref))
    {
    goto end; //String
    }
    }

    // v1beta1_json_schema_props->schema
    cJSON *schema = cJSON_GetObjectItemCaseSensitive(v1beta1_json_schema_propsJSON, "$schema");
    if (schema) { 
    if(!cJSON_IsString(schema))
    {
    goto end; //String
    }
    }

    // v1beta1_json_schema_props->additional_items
    cJSON *additional_items = cJSON_GetObjectItemCaseSensitive(v1beta1_json_schema_propsJSON, "additionalItems");
    object_t *additional_items_local_object = NULL;
    if (additional_items) { 
    additional_items_local_object = object_parseFromJSON(additional_items); //object
    }

    // v1beta1_json_schema_props->additional_properties
    cJSON *additional_properties = cJSON_GetObjectItemCaseSensitive(v1beta1_json_schema_propsJSON, "additionalProperties");
    object_t *additional_properties_local_object = NULL;
    if (additional_properties) { 
    additional_properties_local_object = object_parseFromJSON(additional_properties); //object
    }

    // v1beta1_json_schema_props->all_of
    cJSON *all_of = cJSON_GetObjectItemCaseSensitive(v1beta1_json_schema_propsJSON, "allOf");
    list_t *all_ofList;
    if (all_of) { 
    cJSON *all_of_local_nonprimitive;
    if(!cJSON_IsArray(all_of)){
        goto end; //nonprimitive container
    }

    all_ofList = list_create();

    cJSON_ArrayForEach(all_of_local_nonprimitive,all_of )
    {
        if(!cJSON_IsObject(all_of_local_nonprimitive)){
            goto end;
        }
        v1beta1_json_schema_props_t *all_ofItem = v1beta1_json_schema_props_parseFromJSON(all_of_local_nonprimitive);

        list_addElement(all_ofList, all_ofItem);
    }
    }

    // v1beta1_json_schema_props->any_of
    cJSON *any_of = cJSON_GetObjectItemCaseSensitive(v1beta1_json_schema_propsJSON, "anyOf");
    list_t *any_ofList;
    if (any_of) { 
    cJSON *any_of_local_nonprimitive;
    if(!cJSON_IsArray(any_of)){
        goto end; //nonprimitive container
    }

    any_ofList = list_create();

    cJSON_ArrayForEach(any_of_local_nonprimitive,any_of )
    {
        if(!cJSON_IsObject(any_of_local_nonprimitive)){
            goto end;
        }
        v1beta1_json_schema_props_t *any_ofItem = v1beta1_json_schema_props_parseFromJSON(any_of_local_nonprimitive);

        list_addElement(any_ofList, any_ofItem);
    }
    }

    // v1beta1_json_schema_props->_default
    cJSON *_default = cJSON_GetObjectItemCaseSensitive(v1beta1_json_schema_propsJSON, "default");
    object_t *_default_local_object = NULL;
    if (_default) { 
    _default_local_object = object_parseFromJSON(_default); //object
    }

    // v1beta1_json_schema_props->definitions
    cJSON *definitions = cJSON_GetObjectItemCaseSensitive(v1beta1_json_schema_propsJSON, "definitions");
    list_t *definitionsList;
    if (definitions) { 
    cJSON *definitions_local_map;
    if(!cJSON_IsObject(definitions)) {
        goto end;//primitive map container
    }
    definitionsList = list_create();
    keyValuePair_t *localMapKeyPair;
    cJSON_ArrayForEach(definitions_local_map, definitions)
    {
		cJSON *localMapObject = definitions_local_map;
        list_addElement(definitionsList , localMapKeyPair);
    }
    }

    // v1beta1_json_schema_props->dependencies
    cJSON *dependencies = cJSON_GetObjectItemCaseSensitive(v1beta1_json_schema_propsJSON, "dependencies");
    list_t *dependenciesList;
    if (dependencies) { 
    cJSON *dependencies_local_map;
    if(!cJSON_IsObject(dependencies)) {
        goto end;//primitive map container
    }
    dependenciesList = list_create();
    keyValuePair_t *localMapKeyPair;
    cJSON_ArrayForEach(dependencies_local_map, dependencies)
    {
		cJSON *localMapObject = dependencies_local_map;
        list_addElement(dependenciesList , localMapKeyPair);
    }
    }

    // v1beta1_json_schema_props->description
    cJSON *description = cJSON_GetObjectItemCaseSensitive(v1beta1_json_schema_propsJSON, "description");
    if (description) { 
    if(!cJSON_IsString(description))
    {
    goto end; //String
    }
    }

    // v1beta1_json_schema_props->_enum
    cJSON *_enum = cJSON_GetObjectItemCaseSensitive(v1beta1_json_schema_propsJSON, "enum");
    list_t *_enumList;
    if (_enum) { 
    cJSON *_enum_local_nonprimitive;
    if(!cJSON_IsArray(_enum)){
        goto end; //nonprimitive container
    }

    _enumList = list_create();

    cJSON_ArrayForEach(_enum_local_nonprimitive,_enum )
    {
        if(!cJSON_IsObject(_enum_local_nonprimitive)){
            goto end;
        }
        object_t *_enumItem = object_parseFromJSON(_enum_local_nonprimitive);

        list_addElement(_enumList, _enumItem);
    }
    }

    // v1beta1_json_schema_props->example
    cJSON *example = cJSON_GetObjectItemCaseSensitive(v1beta1_json_schema_propsJSON, "example");
    object_t *example_local_object = NULL;
    if (example) { 
    example_local_object = object_parseFromJSON(example); //object
    }

    // v1beta1_json_schema_props->exclusive_maximum
    cJSON *exclusive_maximum = cJSON_GetObjectItemCaseSensitive(v1beta1_json_schema_propsJSON, "exclusiveMaximum");
    if (exclusive_maximum) { 
    if(!cJSON_IsBool(exclusive_maximum))
    {
    goto end; //Bool
    }
    }

    // v1beta1_json_schema_props->exclusive_minimum
    cJSON *exclusive_minimum = cJSON_GetObjectItemCaseSensitive(v1beta1_json_schema_propsJSON, "exclusiveMinimum");
    if (exclusive_minimum) { 
    if(!cJSON_IsBool(exclusive_minimum))
    {
    goto end; //Bool
    }
    }

    // v1beta1_json_schema_props->external_docs
    cJSON *external_docs = cJSON_GetObjectItemCaseSensitive(v1beta1_json_schema_propsJSON, "externalDocs");
    v1beta1_external_documentation_t *external_docs_local_nonprim = NULL;
    if (external_docs) { 
    external_docs_local_nonprim = v1beta1_external_documentation_parseFromJSON(external_docs); //nonprimitive
    }

    // v1beta1_json_schema_props->format
    cJSON *format = cJSON_GetObjectItemCaseSensitive(v1beta1_json_schema_propsJSON, "format");
    if (format) { 
    if(!cJSON_IsString(format))
    {
    goto end; //String
    }
    }

    // v1beta1_json_schema_props->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(v1beta1_json_schema_propsJSON, "id");
    if (id) { 
    if(!cJSON_IsString(id))
    {
    goto end; //String
    }
    }

    // v1beta1_json_schema_props->items
    cJSON *items = cJSON_GetObjectItemCaseSensitive(v1beta1_json_schema_propsJSON, "items");
    object_t *items_local_object = NULL;
    if (items) { 
    items_local_object = object_parseFromJSON(items); //object
    }

    // v1beta1_json_schema_props->max_items
    cJSON *max_items = cJSON_GetObjectItemCaseSensitive(v1beta1_json_schema_propsJSON, "maxItems");
    if (max_items) { 
    if(!cJSON_IsNumber(max_items))
    {
    goto end; //Numeric
    }
    }

    // v1beta1_json_schema_props->max_length
    cJSON *max_length = cJSON_GetObjectItemCaseSensitive(v1beta1_json_schema_propsJSON, "maxLength");
    if (max_length) { 
    if(!cJSON_IsNumber(max_length))
    {
    goto end; //Numeric
    }
    }

    // v1beta1_json_schema_props->max_properties
    cJSON *max_properties = cJSON_GetObjectItemCaseSensitive(v1beta1_json_schema_propsJSON, "maxProperties");
    if (max_properties) { 
    if(!cJSON_IsNumber(max_properties))
    {
    goto end; //Numeric
    }
    }

    // v1beta1_json_schema_props->maximum
    cJSON *maximum = cJSON_GetObjectItemCaseSensitive(v1beta1_json_schema_propsJSON, "maximum");
    if (maximum) { 
    if(!cJSON_IsNumber(maximum))
    {
    goto end; //Numeric
    }
    }

    // v1beta1_json_schema_props->min_items
    cJSON *min_items = cJSON_GetObjectItemCaseSensitive(v1beta1_json_schema_propsJSON, "minItems");
    if (min_items) { 
    if(!cJSON_IsNumber(min_items))
    {
    goto end; //Numeric
    }
    }

    // v1beta1_json_schema_props->min_length
    cJSON *min_length = cJSON_GetObjectItemCaseSensitive(v1beta1_json_schema_propsJSON, "minLength");
    if (min_length) { 
    if(!cJSON_IsNumber(min_length))
    {
    goto end; //Numeric
    }
    }

    // v1beta1_json_schema_props->min_properties
    cJSON *min_properties = cJSON_GetObjectItemCaseSensitive(v1beta1_json_schema_propsJSON, "minProperties");
    if (min_properties) { 
    if(!cJSON_IsNumber(min_properties))
    {
    goto end; //Numeric
    }
    }

    // v1beta1_json_schema_props->minimum
    cJSON *minimum = cJSON_GetObjectItemCaseSensitive(v1beta1_json_schema_propsJSON, "minimum");
    if (minimum) { 
    if(!cJSON_IsNumber(minimum))
    {
    goto end; //Numeric
    }
    }

    // v1beta1_json_schema_props->multiple_of
    cJSON *multiple_of = cJSON_GetObjectItemCaseSensitive(v1beta1_json_schema_propsJSON, "multipleOf");
    if (multiple_of) { 
    if(!cJSON_IsNumber(multiple_of))
    {
    goto end; //Numeric
    }
    }

    // v1beta1_json_schema_props->_not
    cJSON *_not = cJSON_GetObjectItemCaseSensitive(v1beta1_json_schema_propsJSON, "not");
    v1beta1_json_schema_props_t *_not_local_nonprim = NULL;
    if (_not) { 
    _not_local_nonprim = v1beta1_json_schema_props_parseFromJSON(_not); //nonprimitive
    }

    // v1beta1_json_schema_props->nullable
    cJSON *nullable = cJSON_GetObjectItemCaseSensitive(v1beta1_json_schema_propsJSON, "nullable");
    if (nullable) { 
    if(!cJSON_IsBool(nullable))
    {
    goto end; //Bool
    }
    }

    // v1beta1_json_schema_props->one_of
    cJSON *one_of = cJSON_GetObjectItemCaseSensitive(v1beta1_json_schema_propsJSON, "oneOf");
    list_t *one_ofList;
    if (one_of) { 
    cJSON *one_of_local_nonprimitive;
    if(!cJSON_IsArray(one_of)){
        goto end; //nonprimitive container
    }

    one_ofList = list_create();

    cJSON_ArrayForEach(one_of_local_nonprimitive,one_of )
    {
        if(!cJSON_IsObject(one_of_local_nonprimitive)){
            goto end;
        }
        v1beta1_json_schema_props_t *one_ofItem = v1beta1_json_schema_props_parseFromJSON(one_of_local_nonprimitive);

        list_addElement(one_ofList, one_ofItem);
    }
    }

    // v1beta1_json_schema_props->pattern
    cJSON *pattern = cJSON_GetObjectItemCaseSensitive(v1beta1_json_schema_propsJSON, "pattern");
    if (pattern) { 
    if(!cJSON_IsString(pattern))
    {
    goto end; //String
    }
    }

    // v1beta1_json_schema_props->pattern_properties
    cJSON *pattern_properties = cJSON_GetObjectItemCaseSensitive(v1beta1_json_schema_propsJSON, "patternProperties");
    list_t *pattern_propertiesList;
    if (pattern_properties) { 
    cJSON *pattern_properties_local_map;
    if(!cJSON_IsObject(pattern_properties)) {
        goto end;//primitive map container
    }
    pattern_propertiesList = list_create();
    keyValuePair_t *localMapKeyPair;
    cJSON_ArrayForEach(pattern_properties_local_map, pattern_properties)
    {
		cJSON *localMapObject = pattern_properties_local_map;
        list_addElement(pattern_propertiesList , localMapKeyPair);
    }
    }

    // v1beta1_json_schema_props->properties
    cJSON *properties = cJSON_GetObjectItemCaseSensitive(v1beta1_json_schema_propsJSON, "properties");
    list_t *propertiesList;
    if (properties) { 
    cJSON *properties_local_map;
    if(!cJSON_IsObject(properties)) {
        goto end;//primitive map container
    }
    propertiesList = list_create();
    keyValuePair_t *localMapKeyPair;
    cJSON_ArrayForEach(properties_local_map, properties)
    {
		cJSON *localMapObject = properties_local_map;
        list_addElement(propertiesList , localMapKeyPair);
    }
    }

    // v1beta1_json_schema_props->required
    cJSON *required = cJSON_GetObjectItemCaseSensitive(v1beta1_json_schema_propsJSON, "required");
    list_t *requiredList;
    if (required) { 
    cJSON *required_local;
    if(!cJSON_IsArray(required)) {
        goto end;//primitive container
    }
    requiredList = list_create();

    cJSON_ArrayForEach(required_local, required)
    {
        if(!cJSON_IsString(required_local))
        {
            goto end;
        }
        list_addElement(requiredList , strdup(required_local->valuestring));
    }
    }

    // v1beta1_json_schema_props->title
    cJSON *title = cJSON_GetObjectItemCaseSensitive(v1beta1_json_schema_propsJSON, "title");
    if (title) { 
    if(!cJSON_IsString(title))
    {
    goto end; //String
    }
    }

    // v1beta1_json_schema_props->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(v1beta1_json_schema_propsJSON, "type");
    if (type) { 
    if(!cJSON_IsString(type))
    {
    goto end; //String
    }
    }

    // v1beta1_json_schema_props->unique_items
    cJSON *unique_items = cJSON_GetObjectItemCaseSensitive(v1beta1_json_schema_propsJSON, "uniqueItems");
    if (unique_items) { 
    if(!cJSON_IsBool(unique_items))
    {
    goto end; //Bool
    }
    }

    // v1beta1_json_schema_props->x_kubernetes_embedded_resource
    cJSON *x_kubernetes_embedded_resource = cJSON_GetObjectItemCaseSensitive(v1beta1_json_schema_propsJSON, "x-kubernetes-embedded-resource");
    if (x_kubernetes_embedded_resource) { 
    if(!cJSON_IsBool(x_kubernetes_embedded_resource))
    {
    goto end; //Bool
    }
    }

    // v1beta1_json_schema_props->x_kubernetes_int_or_string
    cJSON *x_kubernetes_int_or_string = cJSON_GetObjectItemCaseSensitive(v1beta1_json_schema_propsJSON, "x-kubernetes-int-or-string");
    if (x_kubernetes_int_or_string) { 
    if(!cJSON_IsBool(x_kubernetes_int_or_string))
    {
    goto end; //Bool
    }
    }

    // v1beta1_json_schema_props->x_kubernetes_list_map_keys
    cJSON *x_kubernetes_list_map_keys = cJSON_GetObjectItemCaseSensitive(v1beta1_json_schema_propsJSON, "x-kubernetes-list-map-keys");
    list_t *x_kubernetes_list_map_keysList;
    if (x_kubernetes_list_map_keys) { 
    cJSON *x_kubernetes_list_map_keys_local;
    if(!cJSON_IsArray(x_kubernetes_list_map_keys)) {
        goto end;//primitive container
    }
    x_kubernetes_list_map_keysList = list_create();

    cJSON_ArrayForEach(x_kubernetes_list_map_keys_local, x_kubernetes_list_map_keys)
    {
        if(!cJSON_IsString(x_kubernetes_list_map_keys_local))
        {
            goto end;
        }
        list_addElement(x_kubernetes_list_map_keysList , strdup(x_kubernetes_list_map_keys_local->valuestring));
    }
    }

    // v1beta1_json_schema_props->x_kubernetes_list_type
    cJSON *x_kubernetes_list_type = cJSON_GetObjectItemCaseSensitive(v1beta1_json_schema_propsJSON, "x-kubernetes-list-type");
    if (x_kubernetes_list_type) { 
    if(!cJSON_IsString(x_kubernetes_list_type))
    {
    goto end; //String
    }
    }

    // v1beta1_json_schema_props->x_kubernetes_map_type
    cJSON *x_kubernetes_map_type = cJSON_GetObjectItemCaseSensitive(v1beta1_json_schema_propsJSON, "x-kubernetes-map-type");
    if (x_kubernetes_map_type) { 
    if(!cJSON_IsString(x_kubernetes_map_type))
    {
    goto end; //String
    }
    }

    // v1beta1_json_schema_props->x_kubernetes_preserve_unknown_fields
    cJSON *x_kubernetes_preserve_unknown_fields = cJSON_GetObjectItemCaseSensitive(v1beta1_json_schema_propsJSON, "x-kubernetes-preserve-unknown-fields");
    if (x_kubernetes_preserve_unknown_fields) { 
    if(!cJSON_IsBool(x_kubernetes_preserve_unknown_fields))
    {
    goto end; //Bool
    }
    }


    v1beta1_json_schema_props_local_var = v1beta1_json_schema_props_create (
        ref ? strdup(ref->valuestring) : NULL,
        schema ? strdup(schema->valuestring) : NULL,
        additional_items ? additional_items_local_object : NULL,
        additional_properties ? additional_properties_local_object : NULL,
        all_of ? all_ofList : NULL,
        any_of ? any_ofList : NULL,
        _default ? _default_local_object : NULL,
        definitions ? definitionsList : NULL,
        dependencies ? dependenciesList : NULL,
        description ? strdup(description->valuestring) : NULL,
        _enum ? _enumList : NULL,
        example ? example_local_object : NULL,
        exclusive_maximum ? exclusive_maximum->valueint : 0,
        exclusive_minimum ? exclusive_minimum->valueint : 0,
        external_docs ? external_docs_local_nonprim : NULL,
        format ? strdup(format->valuestring) : NULL,
        id ? strdup(id->valuestring) : NULL,
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
        pattern ? strdup(pattern->valuestring) : NULL,
        pattern_properties ? pattern_propertiesList : NULL,
        properties ? propertiesList : NULL,
        required ? requiredList : NULL,
        title ? strdup(title->valuestring) : NULL,
        type ? strdup(type->valuestring) : NULL,
        unique_items ? unique_items->valueint : 0,
        x_kubernetes_embedded_resource ? x_kubernetes_embedded_resource->valueint : 0,
        x_kubernetes_int_or_string ? x_kubernetes_int_or_string->valueint : 0,
        x_kubernetes_list_map_keys ? x_kubernetes_list_map_keysList : NULL,
        x_kubernetes_list_type ? strdup(x_kubernetes_list_type->valuestring) : NULL,
        x_kubernetes_map_type ? strdup(x_kubernetes_map_type->valuestring) : NULL,
        x_kubernetes_preserve_unknown_fields ? x_kubernetes_preserve_unknown_fields->valueint : 0
        );

    return v1beta1_json_schema_props_local_var;
end:
    if (external_docs_local_nonprim) {
        v1beta1_external_documentation_free(external_docs_local_nonprim);
        external_docs_local_nonprim = NULL;
    }
    if (_not_local_nonprim) {
        v1beta1_json_schema_props_free(_not_local_nonprim);
        _not_local_nonprim = NULL;
    }
    return NULL;

}
