#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_resource_attributes.h"



v1_resource_attributes_t *v1_resource_attributes_create(
    v1_field_selector_attributes_t *field_selector,
    char *group,
    v1_label_selector_attributes_t *label_selector,
    char *name,
    char *_namespace,
    char *resource,
    char *subresource,
    char *verb,
    char *version
    ) {
    v1_resource_attributes_t *v1_resource_attributes_local_var = malloc(sizeof(v1_resource_attributes_t));
    if (!v1_resource_attributes_local_var) {
        return NULL;
    }
    v1_resource_attributes_local_var->field_selector = field_selector;
    v1_resource_attributes_local_var->group = group;
    v1_resource_attributes_local_var->label_selector = label_selector;
    v1_resource_attributes_local_var->name = name;
    v1_resource_attributes_local_var->_namespace = _namespace;
    v1_resource_attributes_local_var->resource = resource;
    v1_resource_attributes_local_var->subresource = subresource;
    v1_resource_attributes_local_var->verb = verb;
    v1_resource_attributes_local_var->version = version;

    return v1_resource_attributes_local_var;
}


void v1_resource_attributes_free(v1_resource_attributes_t *v1_resource_attributes) {
    if(NULL == v1_resource_attributes){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_resource_attributes->field_selector) {
        v1_field_selector_attributes_free(v1_resource_attributes->field_selector);
        v1_resource_attributes->field_selector = NULL;
    }
    if (v1_resource_attributes->group) {
        free(v1_resource_attributes->group);
        v1_resource_attributes->group = NULL;
    }
    if (v1_resource_attributes->label_selector) {
        v1_label_selector_attributes_free(v1_resource_attributes->label_selector);
        v1_resource_attributes->label_selector = NULL;
    }
    if (v1_resource_attributes->name) {
        free(v1_resource_attributes->name);
        v1_resource_attributes->name = NULL;
    }
    if (v1_resource_attributes->_namespace) {
        free(v1_resource_attributes->_namespace);
        v1_resource_attributes->_namespace = NULL;
    }
    if (v1_resource_attributes->resource) {
        free(v1_resource_attributes->resource);
        v1_resource_attributes->resource = NULL;
    }
    if (v1_resource_attributes->subresource) {
        free(v1_resource_attributes->subresource);
        v1_resource_attributes->subresource = NULL;
    }
    if (v1_resource_attributes->verb) {
        free(v1_resource_attributes->verb);
        v1_resource_attributes->verb = NULL;
    }
    if (v1_resource_attributes->version) {
        free(v1_resource_attributes->version);
        v1_resource_attributes->version = NULL;
    }
    free(v1_resource_attributes);
}

cJSON *v1_resource_attributes_convertToJSON(v1_resource_attributes_t *v1_resource_attributes) {
    cJSON *item = cJSON_CreateObject();

    // v1_resource_attributes->field_selector
    if(v1_resource_attributes->field_selector) {
    cJSON *field_selector_local_JSON = v1_field_selector_attributes_convertToJSON(v1_resource_attributes->field_selector);
    if(field_selector_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "fieldSelector", field_selector_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_resource_attributes->group
    if(v1_resource_attributes->group) {
    if(cJSON_AddStringToObject(item, "group", v1_resource_attributes->group) == NULL) {
    goto fail; //String
    }
    }


    // v1_resource_attributes->label_selector
    if(v1_resource_attributes->label_selector) {
    cJSON *label_selector_local_JSON = v1_label_selector_attributes_convertToJSON(v1_resource_attributes->label_selector);
    if(label_selector_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "labelSelector", label_selector_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_resource_attributes->name
    if(v1_resource_attributes->name) {
    if(cJSON_AddStringToObject(item, "name", v1_resource_attributes->name) == NULL) {
    goto fail; //String
    }
    }


    // v1_resource_attributes->_namespace
    if(v1_resource_attributes->_namespace) {
    if(cJSON_AddStringToObject(item, "namespace", v1_resource_attributes->_namespace) == NULL) {
    goto fail; //String
    }
    }


    // v1_resource_attributes->resource
    if(v1_resource_attributes->resource) {
    if(cJSON_AddStringToObject(item, "resource", v1_resource_attributes->resource) == NULL) {
    goto fail; //String
    }
    }


    // v1_resource_attributes->subresource
    if(v1_resource_attributes->subresource) {
    if(cJSON_AddStringToObject(item, "subresource", v1_resource_attributes->subresource) == NULL) {
    goto fail; //String
    }
    }


    // v1_resource_attributes->verb
    if(v1_resource_attributes->verb) {
    if(cJSON_AddStringToObject(item, "verb", v1_resource_attributes->verb) == NULL) {
    goto fail; //String
    }
    }


    // v1_resource_attributes->version
    if(v1_resource_attributes->version) {
    if(cJSON_AddStringToObject(item, "version", v1_resource_attributes->version) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_resource_attributes_t *v1_resource_attributes_parseFromJSON(cJSON *v1_resource_attributesJSON){

    v1_resource_attributes_t *v1_resource_attributes_local_var = NULL;

    // define the local variable for v1_resource_attributes->field_selector
    v1_field_selector_attributes_t *field_selector_local_nonprim = NULL;

    // define the local variable for v1_resource_attributes->label_selector
    v1_label_selector_attributes_t *label_selector_local_nonprim = NULL;

    // v1_resource_attributes->field_selector
    cJSON *field_selector = cJSON_GetObjectItemCaseSensitive(v1_resource_attributesJSON, "fieldSelector");
    if (field_selector) { 
    field_selector_local_nonprim = v1_field_selector_attributes_parseFromJSON(field_selector); //nonprimitive
    }

    // v1_resource_attributes->group
    cJSON *group = cJSON_GetObjectItemCaseSensitive(v1_resource_attributesJSON, "group");
    if (group) { 
    if(!cJSON_IsString(group) && !cJSON_IsNull(group))
    {
    goto end; //String
    }
    }

    // v1_resource_attributes->label_selector
    cJSON *label_selector = cJSON_GetObjectItemCaseSensitive(v1_resource_attributesJSON, "labelSelector");
    if (label_selector) { 
    label_selector_local_nonprim = v1_label_selector_attributes_parseFromJSON(label_selector); //nonprimitive
    }

    // v1_resource_attributes->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1_resource_attributesJSON, "name");
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // v1_resource_attributes->_namespace
    cJSON *_namespace = cJSON_GetObjectItemCaseSensitive(v1_resource_attributesJSON, "namespace");
    if (_namespace) { 
    if(!cJSON_IsString(_namespace) && !cJSON_IsNull(_namespace))
    {
    goto end; //String
    }
    }

    // v1_resource_attributes->resource
    cJSON *resource = cJSON_GetObjectItemCaseSensitive(v1_resource_attributesJSON, "resource");
    if (resource) { 
    if(!cJSON_IsString(resource) && !cJSON_IsNull(resource))
    {
    goto end; //String
    }
    }

    // v1_resource_attributes->subresource
    cJSON *subresource = cJSON_GetObjectItemCaseSensitive(v1_resource_attributesJSON, "subresource");
    if (subresource) { 
    if(!cJSON_IsString(subresource) && !cJSON_IsNull(subresource))
    {
    goto end; //String
    }
    }

    // v1_resource_attributes->verb
    cJSON *verb = cJSON_GetObjectItemCaseSensitive(v1_resource_attributesJSON, "verb");
    if (verb) { 
    if(!cJSON_IsString(verb) && !cJSON_IsNull(verb))
    {
    goto end; //String
    }
    }

    // v1_resource_attributes->version
    cJSON *version = cJSON_GetObjectItemCaseSensitive(v1_resource_attributesJSON, "version");
    if (version) { 
    if(!cJSON_IsString(version) && !cJSON_IsNull(version))
    {
    goto end; //String
    }
    }


    v1_resource_attributes_local_var = v1_resource_attributes_create (
        field_selector ? field_selector_local_nonprim : NULL,
        group && !cJSON_IsNull(group) ? strdup(group->valuestring) : NULL,
        label_selector ? label_selector_local_nonprim : NULL,
        name && !cJSON_IsNull(name) ? strdup(name->valuestring) : NULL,
        _namespace && !cJSON_IsNull(_namespace) ? strdup(_namespace->valuestring) : NULL,
        resource && !cJSON_IsNull(resource) ? strdup(resource->valuestring) : NULL,
        subresource && !cJSON_IsNull(subresource) ? strdup(subresource->valuestring) : NULL,
        verb && !cJSON_IsNull(verb) ? strdup(verb->valuestring) : NULL,
        version && !cJSON_IsNull(version) ? strdup(version->valuestring) : NULL
        );

    return v1_resource_attributes_local_var;
end:
    if (field_selector_local_nonprim) {
        v1_field_selector_attributes_free(field_selector_local_nonprim);
        field_selector_local_nonprim = NULL;
    }
    if (label_selector_local_nonprim) {
        v1_label_selector_attributes_free(label_selector_local_nonprim);
        label_selector_local_nonprim = NULL;
    }
    return NULL;

}
