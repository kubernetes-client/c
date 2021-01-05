#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_resource_attributes.h"



v1beta1_resource_attributes_t *v1beta1_resource_attributes_create(
    char *group,
    char *name,
    char *_namespace,
    char *resource,
    char *subresource,
    char *verb,
    char *version
    ) {
    v1beta1_resource_attributes_t *v1beta1_resource_attributes_local_var = malloc(sizeof(v1beta1_resource_attributes_t));
    if (!v1beta1_resource_attributes_local_var) {
        return NULL;
    }
    v1beta1_resource_attributes_local_var->group = group;
    v1beta1_resource_attributes_local_var->name = name;
    v1beta1_resource_attributes_local_var->_namespace = _namespace;
    v1beta1_resource_attributes_local_var->resource = resource;
    v1beta1_resource_attributes_local_var->subresource = subresource;
    v1beta1_resource_attributes_local_var->verb = verb;
    v1beta1_resource_attributes_local_var->version = version;

    return v1beta1_resource_attributes_local_var;
}


void v1beta1_resource_attributes_free(v1beta1_resource_attributes_t *v1beta1_resource_attributes) {
    if(NULL == v1beta1_resource_attributes){
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta1_resource_attributes->group) {
        free(v1beta1_resource_attributes->group);
        v1beta1_resource_attributes->group = NULL;
    }
    if (v1beta1_resource_attributes->name) {
        free(v1beta1_resource_attributes->name);
        v1beta1_resource_attributes->name = NULL;
    }
    if (v1beta1_resource_attributes->_namespace) {
        free(v1beta1_resource_attributes->_namespace);
        v1beta1_resource_attributes->_namespace = NULL;
    }
    if (v1beta1_resource_attributes->resource) {
        free(v1beta1_resource_attributes->resource);
        v1beta1_resource_attributes->resource = NULL;
    }
    if (v1beta1_resource_attributes->subresource) {
        free(v1beta1_resource_attributes->subresource);
        v1beta1_resource_attributes->subresource = NULL;
    }
    if (v1beta1_resource_attributes->verb) {
        free(v1beta1_resource_attributes->verb);
        v1beta1_resource_attributes->verb = NULL;
    }
    if (v1beta1_resource_attributes->version) {
        free(v1beta1_resource_attributes->version);
        v1beta1_resource_attributes->version = NULL;
    }
    free(v1beta1_resource_attributes);
}

cJSON *v1beta1_resource_attributes_convertToJSON(v1beta1_resource_attributes_t *v1beta1_resource_attributes) {
    cJSON *item = cJSON_CreateObject();

    // v1beta1_resource_attributes->group
    if(v1beta1_resource_attributes->group) { 
    if(cJSON_AddStringToObject(item, "group", v1beta1_resource_attributes->group) == NULL) {
    goto fail; //String
    }
     } 


    // v1beta1_resource_attributes->name
    if(v1beta1_resource_attributes->name) { 
    if(cJSON_AddStringToObject(item, "name", v1beta1_resource_attributes->name) == NULL) {
    goto fail; //String
    }
     } 


    // v1beta1_resource_attributes->_namespace
    if(v1beta1_resource_attributes->_namespace) { 
    if(cJSON_AddStringToObject(item, "namespace", v1beta1_resource_attributes->_namespace) == NULL) {
    goto fail; //String
    }
     } 


    // v1beta1_resource_attributes->resource
    if(v1beta1_resource_attributes->resource) { 
    if(cJSON_AddStringToObject(item, "resource", v1beta1_resource_attributes->resource) == NULL) {
    goto fail; //String
    }
     } 


    // v1beta1_resource_attributes->subresource
    if(v1beta1_resource_attributes->subresource) { 
    if(cJSON_AddStringToObject(item, "subresource", v1beta1_resource_attributes->subresource) == NULL) {
    goto fail; //String
    }
     } 


    // v1beta1_resource_attributes->verb
    if(v1beta1_resource_attributes->verb) { 
    if(cJSON_AddStringToObject(item, "verb", v1beta1_resource_attributes->verb) == NULL) {
    goto fail; //String
    }
     } 


    // v1beta1_resource_attributes->version
    if(v1beta1_resource_attributes->version) { 
    if(cJSON_AddStringToObject(item, "version", v1beta1_resource_attributes->version) == NULL) {
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

v1beta1_resource_attributes_t *v1beta1_resource_attributes_parseFromJSON(cJSON *v1beta1_resource_attributesJSON){

    v1beta1_resource_attributes_t *v1beta1_resource_attributes_local_var = NULL;

    // v1beta1_resource_attributes->group
    cJSON *group = cJSON_GetObjectItemCaseSensitive(v1beta1_resource_attributesJSON, "group");
    if (group) { 
    if(!cJSON_IsString(group))
    {
    goto end; //String
    }
    }

    // v1beta1_resource_attributes->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1beta1_resource_attributesJSON, "name");
    if (name) { 
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }
    }

    // v1beta1_resource_attributes->_namespace
    cJSON *_namespace = cJSON_GetObjectItemCaseSensitive(v1beta1_resource_attributesJSON, "namespace");
    if (_namespace) { 
    if(!cJSON_IsString(_namespace))
    {
    goto end; //String
    }
    }

    // v1beta1_resource_attributes->resource
    cJSON *resource = cJSON_GetObjectItemCaseSensitive(v1beta1_resource_attributesJSON, "resource");
    if (resource) { 
    if(!cJSON_IsString(resource))
    {
    goto end; //String
    }
    }

    // v1beta1_resource_attributes->subresource
    cJSON *subresource = cJSON_GetObjectItemCaseSensitive(v1beta1_resource_attributesJSON, "subresource");
    if (subresource) { 
    if(!cJSON_IsString(subresource))
    {
    goto end; //String
    }
    }

    // v1beta1_resource_attributes->verb
    cJSON *verb = cJSON_GetObjectItemCaseSensitive(v1beta1_resource_attributesJSON, "verb");
    if (verb) { 
    if(!cJSON_IsString(verb))
    {
    goto end; //String
    }
    }

    // v1beta1_resource_attributes->version
    cJSON *version = cJSON_GetObjectItemCaseSensitive(v1beta1_resource_attributesJSON, "version");
    if (version) { 
    if(!cJSON_IsString(version))
    {
    goto end; //String
    }
    }


    v1beta1_resource_attributes_local_var = v1beta1_resource_attributes_create (
        group ? strdup(group->valuestring) : NULL,
        name ? strdup(name->valuestring) : NULL,
        _namespace ? strdup(_namespace->valuestring) : NULL,
        resource ? strdup(resource->valuestring) : NULL,
        subresource ? strdup(subresource->valuestring) : NULL,
        verb ? strdup(verb->valuestring) : NULL,
        version ? strdup(version->valuestring) : NULL
        );

    return v1beta1_resource_attributes_local_var;
end:
    return NULL;

}
