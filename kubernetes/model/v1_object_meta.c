#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_object_meta.h"



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
    ) {
    v1_object_meta_t *v1_object_meta_local_var = malloc(sizeof(v1_object_meta_t));
    if (!v1_object_meta_local_var) {
        return NULL;
    }
    v1_object_meta_local_var->annotations = annotations;
    v1_object_meta_local_var->cluster_name = cluster_name;
    v1_object_meta_local_var->creation_timestamp = creation_timestamp;
    v1_object_meta_local_var->deletion_grace_period_seconds = deletion_grace_period_seconds;
    v1_object_meta_local_var->deletion_timestamp = deletion_timestamp;
    v1_object_meta_local_var->finalizers = finalizers;
    v1_object_meta_local_var->generate_name = generate_name;
    v1_object_meta_local_var->generation = generation;
    v1_object_meta_local_var->labels = labels;
    v1_object_meta_local_var->managed_fields = managed_fields;
    v1_object_meta_local_var->name = name;
    v1_object_meta_local_var->_namespace = _namespace;
    v1_object_meta_local_var->owner_references = owner_references;
    v1_object_meta_local_var->resource_version = resource_version;
    v1_object_meta_local_var->self_link = self_link;
    v1_object_meta_local_var->uid = uid;

    return v1_object_meta_local_var;
}


void v1_object_meta_free(v1_object_meta_t *v1_object_meta) {
    if(NULL == v1_object_meta){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_object_meta->annotations) {
        list_ForEach(listEntry, v1_object_meta->annotations) {
            keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_free(v1_object_meta->annotations);
        v1_object_meta->annotations = NULL;
    }
    if (v1_object_meta->cluster_name) {
        free(v1_object_meta->cluster_name);
        v1_object_meta->cluster_name = NULL;
    }
    if (v1_object_meta->creation_timestamp) {
        free(v1_object_meta->creation_timestamp);
        v1_object_meta->creation_timestamp = NULL;
    }
    if (v1_object_meta->deletion_timestamp) {
        free(v1_object_meta->deletion_timestamp);
        v1_object_meta->deletion_timestamp = NULL;
    }
    if (v1_object_meta->finalizers) {
        list_ForEach(listEntry, v1_object_meta->finalizers) {
            free(listEntry->data);
        }
        list_free(v1_object_meta->finalizers);
        v1_object_meta->finalizers = NULL;
    }
    if (v1_object_meta->generate_name) {
        free(v1_object_meta->generate_name);
        v1_object_meta->generate_name = NULL;
    }
    if (v1_object_meta->labels) {
        list_ForEach(listEntry, v1_object_meta->labels) {
            keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_free(v1_object_meta->labels);
        v1_object_meta->labels = NULL;
    }
    if (v1_object_meta->managed_fields) {
        list_ForEach(listEntry, v1_object_meta->managed_fields) {
            v1_managed_fields_entry_free(listEntry->data);
        }
        list_free(v1_object_meta->managed_fields);
        v1_object_meta->managed_fields = NULL;
    }
    if (v1_object_meta->name) {
        free(v1_object_meta->name);
        v1_object_meta->name = NULL;
    }
    if (v1_object_meta->_namespace) {
        free(v1_object_meta->_namespace);
        v1_object_meta->_namespace = NULL;
    }
    if (v1_object_meta->owner_references) {
        list_ForEach(listEntry, v1_object_meta->owner_references) {
            v1_owner_reference_free(listEntry->data);
        }
        list_free(v1_object_meta->owner_references);
        v1_object_meta->owner_references = NULL;
    }
    if (v1_object_meta->resource_version) {
        free(v1_object_meta->resource_version);
        v1_object_meta->resource_version = NULL;
    }
    if (v1_object_meta->self_link) {
        free(v1_object_meta->self_link);
        v1_object_meta->self_link = NULL;
    }
    if (v1_object_meta->uid) {
        free(v1_object_meta->uid);
        v1_object_meta->uid = NULL;
    }
    free(v1_object_meta);
}

cJSON *v1_object_meta_convertToJSON(v1_object_meta_t *v1_object_meta) {
    cJSON *item = cJSON_CreateObject();

    // v1_object_meta->annotations
    if(v1_object_meta->annotations) { 
    cJSON *annotations = cJSON_AddObjectToObject(item, "annotations");
    if(annotations == NULL) {
        goto fail; //primitive map container
    }
    cJSON *localMapObject = annotations;
    listEntry_t *annotationsListEntry;
    if (v1_object_meta->annotations) {
    list_ForEach(annotationsListEntry, v1_object_meta->annotations) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)annotationsListEntry->data;
        if(cJSON_AddStringToObject(localMapObject, localKeyValue->key, (char*)localKeyValue->value) == NULL)
        {
            goto fail;
        }
    }
    }
     } 


    // v1_object_meta->cluster_name
    if(v1_object_meta->cluster_name) { 
    if(cJSON_AddStringToObject(item, "clusterName", v1_object_meta->cluster_name) == NULL) {
    goto fail; //String
    }
     } 


    // v1_object_meta->creation_timestamp
    if(v1_object_meta->creation_timestamp) { 
    if(cJSON_AddStringToObject(item, "creationTimestamp", v1_object_meta->creation_timestamp) == NULL) {
    goto fail; //Date-Time
    }
     } 


    // v1_object_meta->deletion_grace_period_seconds
    if(v1_object_meta->deletion_grace_period_seconds) { 
    if(cJSON_AddNumberToObject(item, "deletionGracePeriodSeconds", v1_object_meta->deletion_grace_period_seconds) == NULL) {
    goto fail; //Numeric
    }
     } 


    // v1_object_meta->deletion_timestamp
    if(v1_object_meta->deletion_timestamp) { 
    if(cJSON_AddStringToObject(item, "deletionTimestamp", v1_object_meta->deletion_timestamp) == NULL) {
    goto fail; //Date-Time
    }
     } 


    // v1_object_meta->finalizers
    if(v1_object_meta->finalizers) { 
    cJSON *finalizers = cJSON_AddArrayToObject(item, "finalizers");
    if(finalizers == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *finalizersListEntry;
    list_ForEach(finalizersListEntry, v1_object_meta->finalizers) {
    if(cJSON_AddStringToObject(finalizers, "", (char*)finalizersListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 


    // v1_object_meta->generate_name
    if(v1_object_meta->generate_name) { 
    if(cJSON_AddStringToObject(item, "generateName", v1_object_meta->generate_name) == NULL) {
    goto fail; //String
    }
     } 


    // v1_object_meta->generation
    if(v1_object_meta->generation) { 
    if(cJSON_AddNumberToObject(item, "generation", v1_object_meta->generation) == NULL) {
    goto fail; //Numeric
    }
     } 


    // v1_object_meta->labels
    if(v1_object_meta->labels) { 
    cJSON *labels = cJSON_AddObjectToObject(item, "labels");
    if(labels == NULL) {
        goto fail; //primitive map container
    }
    cJSON *localMapObject = labels;
    listEntry_t *labelsListEntry;
    if (v1_object_meta->labels) {
    list_ForEach(labelsListEntry, v1_object_meta->labels) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)labelsListEntry->data;
        if(cJSON_AddStringToObject(localMapObject, localKeyValue->key, (char*)localKeyValue->value) == NULL)
        {
            goto fail;
        }
    }
    }
     } 


    // v1_object_meta->managed_fields
    if(v1_object_meta->managed_fields) { 
    cJSON *managed_fields = cJSON_AddArrayToObject(item, "managedFields");
    if(managed_fields == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *managed_fieldsListEntry;
    if (v1_object_meta->managed_fields) {
    list_ForEach(managed_fieldsListEntry, v1_object_meta->managed_fields) {
    cJSON *itemLocal = v1_managed_fields_entry_convertToJSON(managed_fieldsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(managed_fields, itemLocal);
    }
    }
     } 


    // v1_object_meta->name
    if(v1_object_meta->name) { 
    if(cJSON_AddStringToObject(item, "name", v1_object_meta->name) == NULL) {
    goto fail; //String
    }
     } 


    // v1_object_meta->_namespace
    if(v1_object_meta->_namespace) { 
    if(cJSON_AddStringToObject(item, "namespace", v1_object_meta->_namespace) == NULL) {
    goto fail; //String
    }
     } 


    // v1_object_meta->owner_references
    if(v1_object_meta->owner_references) { 
    cJSON *owner_references = cJSON_AddArrayToObject(item, "ownerReferences");
    if(owner_references == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *owner_referencesListEntry;
    if (v1_object_meta->owner_references) {
    list_ForEach(owner_referencesListEntry, v1_object_meta->owner_references) {
    cJSON *itemLocal = v1_owner_reference_convertToJSON(owner_referencesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(owner_references, itemLocal);
    }
    }
     } 


    // v1_object_meta->resource_version
    if(v1_object_meta->resource_version) { 
    if(cJSON_AddStringToObject(item, "resourceVersion", v1_object_meta->resource_version) == NULL) {
    goto fail; //String
    }
     } 


    // v1_object_meta->self_link
    if(v1_object_meta->self_link) { 
    if(cJSON_AddStringToObject(item, "selfLink", v1_object_meta->self_link) == NULL) {
    goto fail; //String
    }
     } 


    // v1_object_meta->uid
    if(v1_object_meta->uid) { 
    if(cJSON_AddStringToObject(item, "uid", v1_object_meta->uid) == NULL) {
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

v1_object_meta_t *v1_object_meta_parseFromJSON(cJSON *v1_object_metaJSON){

    v1_object_meta_t *v1_object_meta_local_var = NULL;

    // v1_object_meta->annotations
    cJSON *annotations = cJSON_GetObjectItemCaseSensitive(v1_object_metaJSON, "annotations");
    list_t *annotationsList;
    if (annotations) { 
    cJSON *annotations_local_map;
    if(!cJSON_IsObject(annotations)) {
        goto end;//primitive map container
    }
    annotationsList = list_create();
    keyValuePair_t *localMapKeyPair;
    cJSON_ArrayForEach(annotations_local_map, annotations)
    {
		cJSON *localMapObject = annotations_local_map;
        if(!cJSON_IsString(localMapObject))
        {
            goto end;
        }
        localMapKeyPair = keyValuePair_create(strdup(localMapObject->string),strdup(localMapObject->valuestring));
        list_addElement(annotationsList , localMapKeyPair);
    }
    }

    // v1_object_meta->cluster_name
    cJSON *cluster_name = cJSON_GetObjectItemCaseSensitive(v1_object_metaJSON, "clusterName");
    if (cluster_name) { 
    if(!cJSON_IsString(cluster_name))
    {
    goto end; //String
    }
    }

    // v1_object_meta->creation_timestamp
    cJSON *creation_timestamp = cJSON_GetObjectItemCaseSensitive(v1_object_metaJSON, "creationTimestamp");
    if (creation_timestamp) { 
    if(!cJSON_IsString(creation_timestamp))
    {
    goto end; //DateTime
    }
    }

    // v1_object_meta->deletion_grace_period_seconds
    cJSON *deletion_grace_period_seconds = cJSON_GetObjectItemCaseSensitive(v1_object_metaJSON, "deletionGracePeriodSeconds");
    if (deletion_grace_period_seconds) { 
    if(!cJSON_IsNumber(deletion_grace_period_seconds))
    {
    goto end; //Numeric
    }
    }

    // v1_object_meta->deletion_timestamp
    cJSON *deletion_timestamp = cJSON_GetObjectItemCaseSensitive(v1_object_metaJSON, "deletionTimestamp");
    if (deletion_timestamp) { 
    if(!cJSON_IsString(deletion_timestamp))
    {
    goto end; //DateTime
    }
    }

    // v1_object_meta->finalizers
    cJSON *finalizers = cJSON_GetObjectItemCaseSensitive(v1_object_metaJSON, "finalizers");
    list_t *finalizersList;
    if (finalizers) { 
    cJSON *finalizers_local;
    if(!cJSON_IsArray(finalizers)) {
        goto end;//primitive container
    }
    finalizersList = list_create();

    cJSON_ArrayForEach(finalizers_local, finalizers)
    {
        if(!cJSON_IsString(finalizers_local))
        {
            goto end;
        }
        list_addElement(finalizersList , strdup(finalizers_local->valuestring));
    }
    }

    // v1_object_meta->generate_name
    cJSON *generate_name = cJSON_GetObjectItemCaseSensitive(v1_object_metaJSON, "generateName");
    if (generate_name) { 
    if(!cJSON_IsString(generate_name))
    {
    goto end; //String
    }
    }

    // v1_object_meta->generation
    cJSON *generation = cJSON_GetObjectItemCaseSensitive(v1_object_metaJSON, "generation");
    if (generation) { 
    if(!cJSON_IsNumber(generation))
    {
    goto end; //Numeric
    }
    }

    // v1_object_meta->labels
    cJSON *labels = cJSON_GetObjectItemCaseSensitive(v1_object_metaJSON, "labels");
    list_t *labelsList;
    if (labels) { 
    cJSON *labels_local_map;
    if(!cJSON_IsObject(labels)) {
        goto end;//primitive map container
    }
    labelsList = list_create();
    keyValuePair_t *localMapKeyPair;
    cJSON_ArrayForEach(labels_local_map, labels)
    {
		cJSON *localMapObject = labels_local_map;
        if(!cJSON_IsString(localMapObject))
        {
            goto end;
        }
        localMapKeyPair = keyValuePair_create(strdup(localMapObject->string),strdup(localMapObject->valuestring));
        list_addElement(labelsList , localMapKeyPair);
    }
    }

    // v1_object_meta->managed_fields
    cJSON *managed_fields = cJSON_GetObjectItemCaseSensitive(v1_object_metaJSON, "managedFields");
    list_t *managed_fieldsList;
    if (managed_fields) { 
    cJSON *managed_fields_local_nonprimitive;
    if(!cJSON_IsArray(managed_fields)){
        goto end; //nonprimitive container
    }

    managed_fieldsList = list_create();

    cJSON_ArrayForEach(managed_fields_local_nonprimitive,managed_fields )
    {
        if(!cJSON_IsObject(managed_fields_local_nonprimitive)){
            goto end;
        }
        v1_managed_fields_entry_t *managed_fieldsItem = v1_managed_fields_entry_parseFromJSON(managed_fields_local_nonprimitive);

        list_addElement(managed_fieldsList, managed_fieldsItem);
    }
    }

    // v1_object_meta->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1_object_metaJSON, "name");
    if (name) { 
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }
    }

    // v1_object_meta->_namespace
    cJSON *_namespace = cJSON_GetObjectItemCaseSensitive(v1_object_metaJSON, "namespace");
    if (_namespace) { 
    if(!cJSON_IsString(_namespace))
    {
    goto end; //String
    }
    }

    // v1_object_meta->owner_references
    cJSON *owner_references = cJSON_GetObjectItemCaseSensitive(v1_object_metaJSON, "ownerReferences");
    list_t *owner_referencesList;
    if (owner_references) { 
    cJSON *owner_references_local_nonprimitive;
    if(!cJSON_IsArray(owner_references)){
        goto end; //nonprimitive container
    }

    owner_referencesList = list_create();

    cJSON_ArrayForEach(owner_references_local_nonprimitive,owner_references )
    {
        if(!cJSON_IsObject(owner_references_local_nonprimitive)){
            goto end;
        }
        v1_owner_reference_t *owner_referencesItem = v1_owner_reference_parseFromJSON(owner_references_local_nonprimitive);

        list_addElement(owner_referencesList, owner_referencesItem);
    }
    }

    // v1_object_meta->resource_version
    cJSON *resource_version = cJSON_GetObjectItemCaseSensitive(v1_object_metaJSON, "resourceVersion");
    if (resource_version) { 
    if(!cJSON_IsString(resource_version))
    {
    goto end; //String
    }
    }

    // v1_object_meta->self_link
    cJSON *self_link = cJSON_GetObjectItemCaseSensitive(v1_object_metaJSON, "selfLink");
    if (self_link) { 
    if(!cJSON_IsString(self_link))
    {
    goto end; //String
    }
    }

    // v1_object_meta->uid
    cJSON *uid = cJSON_GetObjectItemCaseSensitive(v1_object_metaJSON, "uid");
    if (uid) { 
    if(!cJSON_IsString(uid))
    {
    goto end; //String
    }
    }


    v1_object_meta_local_var = v1_object_meta_create (
        annotations ? annotationsList : NULL,
        cluster_name ? strdup(cluster_name->valuestring) : NULL,
        creation_timestamp ? strdup(creation_timestamp->valuestring) : NULL,
        deletion_grace_period_seconds ? deletion_grace_period_seconds->valuedouble : 0,
        deletion_timestamp ? strdup(deletion_timestamp->valuestring) : NULL,
        finalizers ? finalizersList : NULL,
        generate_name ? strdup(generate_name->valuestring) : NULL,
        generation ? generation->valuedouble : 0,
        labels ? labelsList : NULL,
        managed_fields ? managed_fieldsList : NULL,
        name ? strdup(name->valuestring) : NULL,
        _namespace ? strdup(_namespace->valuestring) : NULL,
        owner_references ? owner_referencesList : NULL,
        resource_version ? strdup(resource_version->valuestring) : NULL,
        self_link ? strdup(self_link->valuestring) : NULL,
        uid ? strdup(uid->valuestring) : NULL
        );

    return v1_object_meta_local_var;
end:
    return NULL;

}
