#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_device_attribute.h"



static v1beta1_device_attribute_t *v1beta1_device_attribute_create_internal(
    int *_bool,
    list_t *bools,
    long *_int,
    list_t *ints,
    char *string,
    list_t *strings,
    char *version,
    list_t *versions
    ) {
    v1beta1_device_attribute_t *v1beta1_device_attribute_local_var = malloc(sizeof(v1beta1_device_attribute_t));
    if (!v1beta1_device_attribute_local_var) {
        return NULL;
    }
    memset(v1beta1_device_attribute_local_var, 0, sizeof(v1beta1_device_attribute_t));
    v1beta1_device_attribute_local_var->_library_owned = 1;
    v1beta1_device_attribute_local_var->_bool = _bool;
    v1beta1_device_attribute_local_var->bools = bools;
    v1beta1_device_attribute_local_var->_int = _int;
    v1beta1_device_attribute_local_var->ints = ints;
    v1beta1_device_attribute_local_var->string = string;
    v1beta1_device_attribute_local_var->strings = strings;
    v1beta1_device_attribute_local_var->version = version;
    v1beta1_device_attribute_local_var->versions = versions;
    return v1beta1_device_attribute_local_var;
}

__attribute__((deprecated)) v1beta1_device_attribute_t *v1beta1_device_attribute_create(
    int *_bool,
    list_t *bools,
    long *_int,
    list_t *ints,
    char *string,
    list_t *strings,
    char *version,
    list_t *versions
    ) {
    int *_bool_copy = NULL;
    if (_bool) {
        _bool_copy = malloc(sizeof(int));
        if (_bool_copy) *_bool_copy = *_bool;
    }
    long *_int_copy = NULL;
    if (_int) {
        _int_copy = malloc(sizeof(long));
        if (_int_copy) *_int_copy = *_int;
    }
    v1beta1_device_attribute_t *result = v1beta1_device_attribute_create_internal (
        _bool_copy,
        bools,
        _int_copy,
        ints,
        string,
        strings,
        version,
        versions
        );
    if (!result) {
        free(_bool_copy);
        free(_int_copy);
    }
    return result;
}

void v1beta1_device_attribute_free(v1beta1_device_attribute_t *v1beta1_device_attribute) {
    if(NULL == v1beta1_device_attribute){
        return ;
    }
    if(v1beta1_device_attribute->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1beta1_device_attribute_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta1_device_attribute->_bool) {
        free(v1beta1_device_attribute->_bool);
        v1beta1_device_attribute->_bool = NULL;
    }
    if (v1beta1_device_attribute->bools) {
        list_ForEach(listEntry, v1beta1_device_attribute->bools) {
            free(listEntry->data);
        }
        list_freeList(v1beta1_device_attribute->bools);
        v1beta1_device_attribute->bools = NULL;
    }
    if (v1beta1_device_attribute->_int) {
        free(v1beta1_device_attribute->_int);
        v1beta1_device_attribute->_int = NULL;
    }
    if (v1beta1_device_attribute->ints) {
        list_ForEach(listEntry, v1beta1_device_attribute->ints) {
            free(listEntry->data);
        }
        list_freeList(v1beta1_device_attribute->ints);
        v1beta1_device_attribute->ints = NULL;
    }
    if (v1beta1_device_attribute->string) {
        free(v1beta1_device_attribute->string);
        v1beta1_device_attribute->string = NULL;
    }
    if (v1beta1_device_attribute->strings) {
        list_ForEach(listEntry, v1beta1_device_attribute->strings) {
            free(listEntry->data);
        }
        list_freeList(v1beta1_device_attribute->strings);
        v1beta1_device_attribute->strings = NULL;
    }
    if (v1beta1_device_attribute->version) {
        free(v1beta1_device_attribute->version);
        v1beta1_device_attribute->version = NULL;
    }
    if (v1beta1_device_attribute->versions) {
        list_ForEach(listEntry, v1beta1_device_attribute->versions) {
            free(listEntry->data);
        }
        list_freeList(v1beta1_device_attribute->versions);
        v1beta1_device_attribute->versions = NULL;
    }
    free(v1beta1_device_attribute);
}

cJSON *v1beta1_device_attribute_convertToJSON(v1beta1_device_attribute_t *v1beta1_device_attribute) {
    cJSON *item = cJSON_CreateObject();

    // v1beta1_device_attribute->_bool
    if(v1beta1_device_attribute->_bool) {
    if(cJSON_AddBoolToObject(item, "bool", *v1beta1_device_attribute->_bool) == NULL) {
    goto fail; //Bool
    }
    }


    // v1beta1_device_attribute->bools
    if(v1beta1_device_attribute->bools) {
    cJSON *bools = cJSON_AddArrayToObject(item, "bools");
    if(bools == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *boolsListEntry;
    list_ForEach(boolsListEntry, v1beta1_device_attribute->bools) {
    if(cJSON_AddBoolToObject(bools, "", *(cJSON_bool *)boolsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // v1beta1_device_attribute->_int
    if(v1beta1_device_attribute->_int) {
    if(cJSON_AddNumberToObject(item, "int", *v1beta1_device_attribute->_int) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1beta1_device_attribute->ints
    if(v1beta1_device_attribute->ints) {
    cJSON *ints = cJSON_AddArrayToObject(item, "ints");
    if(ints == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *intsListEntry;
    list_ForEach(intsListEntry, v1beta1_device_attribute->ints) {
    if(cJSON_AddNumberToObject(ints, "", *(double *)intsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // v1beta1_device_attribute->string
    if(v1beta1_device_attribute->string) {
    if(cJSON_AddStringToObject(item, "string", v1beta1_device_attribute->string) == NULL) {
    goto fail; //String
    }
    }


    // v1beta1_device_attribute->strings
    if(v1beta1_device_attribute->strings) {
    cJSON *strings = cJSON_AddArrayToObject(item, "strings");
    if(strings == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *stringsListEntry;
    list_ForEach(stringsListEntry, v1beta1_device_attribute->strings) {
    if(cJSON_AddStringToObject(strings, "", stringsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // v1beta1_device_attribute->version
    if(v1beta1_device_attribute->version) {
    if(cJSON_AddStringToObject(item, "version", v1beta1_device_attribute->version) == NULL) {
    goto fail; //String
    }
    }


    // v1beta1_device_attribute->versions
    if(v1beta1_device_attribute->versions) {
    cJSON *versions = cJSON_AddArrayToObject(item, "versions");
    if(versions == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *versionsListEntry;
    list_ForEach(versionsListEntry, v1beta1_device_attribute->versions) {
    if(cJSON_AddStringToObject(versions, "", versionsListEntry->data) == NULL)
    {
        goto fail;
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

v1beta1_device_attribute_t *v1beta1_device_attribute_parseFromJSON(cJSON *v1beta1_device_attributeJSON){

    v1beta1_device_attribute_t *v1beta1_device_attribute_local_var = NULL;

    // define the local variable for v1beta1_device_attribute->_bool
    int *_bool_local_var = NULL;

    // define the local list for v1beta1_device_attribute->bools
    list_t *boolsList = NULL;

    // define the local variable for v1beta1_device_attribute->_int
    long *_int_local_var = NULL;

    // define the local list for v1beta1_device_attribute->ints
    list_t *intsList = NULL;

    char *string_local_str = NULL;

    // define the local list for v1beta1_device_attribute->strings
    list_t *stringsList = NULL;

    char *version_local_str = NULL;

    // define the local list for v1beta1_device_attribute->versions
    list_t *versionsList = NULL;

    // v1beta1_device_attribute->_bool
    cJSON *_bool = cJSON_GetObjectItemCaseSensitive(v1beta1_device_attributeJSON, "bool");
    if (cJSON_IsNull(_bool)) {
        _bool = NULL;
    }
    if (_bool) { 
    if(!cJSON_IsBool(_bool))
    {
    goto end; //Bool
    }
    _bool_local_var = malloc(sizeof(int));
    if(!_bool_local_var)
    {
        goto end;
    }
    *_bool_local_var = _bool->valueint;
    }

    // v1beta1_device_attribute->bools
    cJSON *bools = cJSON_GetObjectItemCaseSensitive(v1beta1_device_attributeJSON, "bools");
    if (cJSON_IsNull(bools)) {
        bools = NULL;
    }
    if (bools) { 
    cJSON *bools_local = NULL;
    if(!cJSON_IsArray(bools)) {
        goto end;//primitive container
    }
    boolsList = list_createList();

    cJSON_ArrayForEach(bools_local, bools)
    {
        if(!cJSON_IsBool(bools_local))
        {
            goto end;
        }
        cJSON_bool *bools_local_value = calloc(1, sizeof(cJSON_bool));
        if(!bools_local_value)
        {
            goto end;
        }
        *bools_local_value = bools_local->valueint;
        list_addElement(boolsList , bools_local_value);
    }
    }

    // v1beta1_device_attribute->_int
    cJSON *_int = cJSON_GetObjectItemCaseSensitive(v1beta1_device_attributeJSON, "int");
    if (cJSON_IsNull(_int)) {
        _int = NULL;
    }
    if (_int) { 
    if(!cJSON_IsNumber(_int))
    {
    goto end; //Numeric
    }
    _int_local_var = malloc(sizeof(long));
    if(!_int_local_var)
    {
        goto end;
    }
    *_int_local_var = _int->valuedouble;
    }

    // v1beta1_device_attribute->ints
    cJSON *ints = cJSON_GetObjectItemCaseSensitive(v1beta1_device_attributeJSON, "ints");
    if (cJSON_IsNull(ints)) {
        ints = NULL;
    }
    if (ints) { 
    cJSON *ints_local = NULL;
    if(!cJSON_IsArray(ints)) {
        goto end;//primitive container
    }
    intsList = list_createList();

    cJSON_ArrayForEach(ints_local, ints)
    {
        if(!cJSON_IsNumber(ints_local))
        {
            goto end;
        }
        double *ints_local_value = calloc(1, sizeof(double));
        if(!ints_local_value)
        {
            goto end;
        }
        *ints_local_value = ints_local->valuedouble;
        list_addElement(intsList , ints_local_value);
    }
    }

    // v1beta1_device_attribute->string
    cJSON *string = cJSON_GetObjectItemCaseSensitive(v1beta1_device_attributeJSON, "string");
    if (cJSON_IsNull(string)) {
        string = NULL;
    }
    if (string) { 
    if(!cJSON_IsString(string) && !cJSON_IsNull(string))
    {
    goto end; //String
    }
    }

    // v1beta1_device_attribute->strings
    cJSON *strings = cJSON_GetObjectItemCaseSensitive(v1beta1_device_attributeJSON, "strings");
    if (cJSON_IsNull(strings)) {
        strings = NULL;
    }
    if (strings) { 
    cJSON *strings_local = NULL;
    if(!cJSON_IsArray(strings)) {
        goto end;//primitive container
    }
    stringsList = list_createList();

    cJSON_ArrayForEach(strings_local, strings)
    {
        if(!cJSON_IsString(strings_local))
        {
            goto end;
        }
        list_addElement(stringsList , strdup(strings_local->valuestring));
    }
    }

    // v1beta1_device_attribute->version
    cJSON *version = cJSON_GetObjectItemCaseSensitive(v1beta1_device_attributeJSON, "version");
    if (cJSON_IsNull(version)) {
        version = NULL;
    }
    if (version) { 
    if(!cJSON_IsString(version) && !cJSON_IsNull(version))
    {
    goto end; //String
    }
    }

    // v1beta1_device_attribute->versions
    cJSON *versions = cJSON_GetObjectItemCaseSensitive(v1beta1_device_attributeJSON, "versions");
    if (cJSON_IsNull(versions)) {
        versions = NULL;
    }
    if (versions) { 
    cJSON *versions_local = NULL;
    if(!cJSON_IsArray(versions)) {
        goto end;//primitive container
    }
    versionsList = list_createList();

    cJSON_ArrayForEach(versions_local, versions)
    {
        if(!cJSON_IsString(versions_local))
        {
            goto end;
        }
        list_addElement(versionsList , strdup(versions_local->valuestring));
    }
    }


    if (string && !cJSON_IsNull(string)) string_local_str = strdup(string->valuestring);
    if (version && !cJSON_IsNull(version)) version_local_str = strdup(version->valuestring);

    v1beta1_device_attribute_local_var = v1beta1_device_attribute_create_internal (
        _bool_local_var,
        bools ? boolsList : NULL,
        _int_local_var,
        ints ? intsList : NULL,
        string_local_str,
        strings ? stringsList : NULL,
        version_local_str,
        versions ? versionsList : NULL
        );

    if (!v1beta1_device_attribute_local_var) {
        goto end;
    }

    return v1beta1_device_attribute_local_var;
end:
    if (_bool_local_var) {
        free(_bool_local_var);
        _bool_local_var = NULL;
    }
    if (boolsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, boolsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(boolsList);
        boolsList = NULL;
    }
    if (_int_local_var) {
        free(_int_local_var);
        _int_local_var = NULL;
    }
    if (intsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, intsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(intsList);
        intsList = NULL;
    }
    if (string_local_str) {
        free(string_local_str);
        string_local_str = NULL;
    }
    if (stringsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, stringsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(stringsList);
        stringsList = NULL;
    }
    if (version_local_str) {
        free(version_local_str);
        version_local_str = NULL;
    }
    if (versionsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, versionsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(versionsList);
        versionsList = NULL;
    }
    return NULL;

}
