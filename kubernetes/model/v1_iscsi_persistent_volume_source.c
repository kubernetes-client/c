#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_iscsi_persistent_volume_source.h"



static v1_iscsi_persistent_volume_source_t *v1_iscsi_persistent_volume_source_create_internal(
    int chap_auth_discovery,
    int chap_auth_session,
    char *fs_type,
    char *initiator_name,
    char *iqn,
    char *iscsi_interface,
    int lun,
    list_t *portals,
    int read_only,
    v1_secret_reference_t *secret_ref,
    char *target_portal
    ) {
    v1_iscsi_persistent_volume_source_t *v1_iscsi_persistent_volume_source_local_var = malloc(sizeof(v1_iscsi_persistent_volume_source_t));
    if (!v1_iscsi_persistent_volume_source_local_var) {
        return NULL;
    }
    v1_iscsi_persistent_volume_source_local_var->chap_auth_discovery = chap_auth_discovery;
    v1_iscsi_persistent_volume_source_local_var->chap_auth_session = chap_auth_session;
    v1_iscsi_persistent_volume_source_local_var->fs_type = fs_type;
    v1_iscsi_persistent_volume_source_local_var->initiator_name = initiator_name;
    v1_iscsi_persistent_volume_source_local_var->iqn = iqn;
    v1_iscsi_persistent_volume_source_local_var->iscsi_interface = iscsi_interface;
    v1_iscsi_persistent_volume_source_local_var->lun = lun;
    v1_iscsi_persistent_volume_source_local_var->portals = portals;
    v1_iscsi_persistent_volume_source_local_var->read_only = read_only;
    v1_iscsi_persistent_volume_source_local_var->secret_ref = secret_ref;
    v1_iscsi_persistent_volume_source_local_var->target_portal = target_portal;

    v1_iscsi_persistent_volume_source_local_var->_library_owned = 1;
    return v1_iscsi_persistent_volume_source_local_var;
}

__attribute__((deprecated)) v1_iscsi_persistent_volume_source_t *v1_iscsi_persistent_volume_source_create(
    int chap_auth_discovery,
    int chap_auth_session,
    char *fs_type,
    char *initiator_name,
    char *iqn,
    char *iscsi_interface,
    int lun,
    list_t *portals,
    int read_only,
    v1_secret_reference_t *secret_ref,
    char *target_portal
    ) {
    return v1_iscsi_persistent_volume_source_create_internal (
        chap_auth_discovery,
        chap_auth_session,
        fs_type,
        initiator_name,
        iqn,
        iscsi_interface,
        lun,
        portals,
        read_only,
        secret_ref,
        target_portal
        );
}

void v1_iscsi_persistent_volume_source_free(v1_iscsi_persistent_volume_source_t *v1_iscsi_persistent_volume_source) {
    if(NULL == v1_iscsi_persistent_volume_source){
        return ;
    }
    if(v1_iscsi_persistent_volume_source->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_iscsi_persistent_volume_source_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_iscsi_persistent_volume_source->fs_type) {
        free(v1_iscsi_persistent_volume_source->fs_type);
        v1_iscsi_persistent_volume_source->fs_type = NULL;
    }
    if (v1_iscsi_persistent_volume_source->initiator_name) {
        free(v1_iscsi_persistent_volume_source->initiator_name);
        v1_iscsi_persistent_volume_source->initiator_name = NULL;
    }
    if (v1_iscsi_persistent_volume_source->iqn) {
        free(v1_iscsi_persistent_volume_source->iqn);
        v1_iscsi_persistent_volume_source->iqn = NULL;
    }
    if (v1_iscsi_persistent_volume_source->iscsi_interface) {
        free(v1_iscsi_persistent_volume_source->iscsi_interface);
        v1_iscsi_persistent_volume_source->iscsi_interface = NULL;
    }
    if (v1_iscsi_persistent_volume_source->portals) {
        list_ForEach(listEntry, v1_iscsi_persistent_volume_source->portals) {
            free(listEntry->data);
        }
        list_freeList(v1_iscsi_persistent_volume_source->portals);
        v1_iscsi_persistent_volume_source->portals = NULL;
    }
    if (v1_iscsi_persistent_volume_source->secret_ref) {
        v1_secret_reference_free(v1_iscsi_persistent_volume_source->secret_ref);
        v1_iscsi_persistent_volume_source->secret_ref = NULL;
    }
    if (v1_iscsi_persistent_volume_source->target_portal) {
        free(v1_iscsi_persistent_volume_source->target_portal);
        v1_iscsi_persistent_volume_source->target_portal = NULL;
    }
    free(v1_iscsi_persistent_volume_source);
}

cJSON *v1_iscsi_persistent_volume_source_convertToJSON(v1_iscsi_persistent_volume_source_t *v1_iscsi_persistent_volume_source) {
    cJSON *item = cJSON_CreateObject();

    // v1_iscsi_persistent_volume_source->chap_auth_discovery
    if(v1_iscsi_persistent_volume_source->chap_auth_discovery) {
    if(cJSON_AddBoolToObject(item, "chapAuthDiscovery", v1_iscsi_persistent_volume_source->chap_auth_discovery) == NULL) {
    goto fail; //Bool
    }
    }


    // v1_iscsi_persistent_volume_source->chap_auth_session
    if(v1_iscsi_persistent_volume_source->chap_auth_session) {
    if(cJSON_AddBoolToObject(item, "chapAuthSession", v1_iscsi_persistent_volume_source->chap_auth_session) == NULL) {
    goto fail; //Bool
    }
    }


    // v1_iscsi_persistent_volume_source->fs_type
    if(v1_iscsi_persistent_volume_source->fs_type) {
    if(cJSON_AddStringToObject(item, "fsType", v1_iscsi_persistent_volume_source->fs_type) == NULL) {
    goto fail; //String
    }
    }


    // v1_iscsi_persistent_volume_source->initiator_name
    if(v1_iscsi_persistent_volume_source->initiator_name) {
    if(cJSON_AddStringToObject(item, "initiatorName", v1_iscsi_persistent_volume_source->initiator_name) == NULL) {
    goto fail; //String
    }
    }


    // v1_iscsi_persistent_volume_source->iqn
    if (!v1_iscsi_persistent_volume_source->iqn) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "iqn", v1_iscsi_persistent_volume_source->iqn) == NULL) {
    goto fail; //String
    }


    // v1_iscsi_persistent_volume_source->iscsi_interface
    if(v1_iscsi_persistent_volume_source->iscsi_interface) {
    if(cJSON_AddStringToObject(item, "iscsiInterface", v1_iscsi_persistent_volume_source->iscsi_interface) == NULL) {
    goto fail; //String
    }
    }


    // v1_iscsi_persistent_volume_source->lun
    if (!v1_iscsi_persistent_volume_source->lun) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "lun", v1_iscsi_persistent_volume_source->lun) == NULL) {
    goto fail; //Numeric
    }


    // v1_iscsi_persistent_volume_source->portals
    if(v1_iscsi_persistent_volume_source->portals) {
    cJSON *portals = cJSON_AddArrayToObject(item, "portals");
    if(portals == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *portalsListEntry;
    list_ForEach(portalsListEntry, v1_iscsi_persistent_volume_source->portals) {
    if(cJSON_AddStringToObject(portals, "", portalsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // v1_iscsi_persistent_volume_source->read_only
    if(v1_iscsi_persistent_volume_source->read_only) {
    if(cJSON_AddBoolToObject(item, "readOnly", v1_iscsi_persistent_volume_source->read_only) == NULL) {
    goto fail; //Bool
    }
    }


    // v1_iscsi_persistent_volume_source->secret_ref
    if(v1_iscsi_persistent_volume_source->secret_ref) {
    cJSON *secret_ref_local_JSON = v1_secret_reference_convertToJSON(v1_iscsi_persistent_volume_source->secret_ref);
    if(secret_ref_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "secretRef", secret_ref_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_iscsi_persistent_volume_source->target_portal
    if (!v1_iscsi_persistent_volume_source->target_portal) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "targetPortal", v1_iscsi_persistent_volume_source->target_portal) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_iscsi_persistent_volume_source_t *v1_iscsi_persistent_volume_source_parseFromJSON(cJSON *v1_iscsi_persistent_volume_sourceJSON){

    v1_iscsi_persistent_volume_source_t *v1_iscsi_persistent_volume_source_local_var = NULL;

    // define the local list for v1_iscsi_persistent_volume_source->portals
    list_t *portalsList = NULL;

    // define the local variable for v1_iscsi_persistent_volume_source->secret_ref
    v1_secret_reference_t *secret_ref_local_nonprim = NULL;

    // v1_iscsi_persistent_volume_source->chap_auth_discovery
    cJSON *chap_auth_discovery = cJSON_GetObjectItemCaseSensitive(v1_iscsi_persistent_volume_sourceJSON, "chapAuthDiscovery");
    if (cJSON_IsNull(chap_auth_discovery)) {
        chap_auth_discovery = NULL;
    }
    if (chap_auth_discovery) { 
    if(!cJSON_IsBool(chap_auth_discovery))
    {
    goto end; //Bool
    }
    }

    // v1_iscsi_persistent_volume_source->chap_auth_session
    cJSON *chap_auth_session = cJSON_GetObjectItemCaseSensitive(v1_iscsi_persistent_volume_sourceJSON, "chapAuthSession");
    if (cJSON_IsNull(chap_auth_session)) {
        chap_auth_session = NULL;
    }
    if (chap_auth_session) { 
    if(!cJSON_IsBool(chap_auth_session))
    {
    goto end; //Bool
    }
    }

    // v1_iscsi_persistent_volume_source->fs_type
    cJSON *fs_type = cJSON_GetObjectItemCaseSensitive(v1_iscsi_persistent_volume_sourceJSON, "fsType");
    if (cJSON_IsNull(fs_type)) {
        fs_type = NULL;
    }
    if (fs_type) { 
    if(!cJSON_IsString(fs_type) && !cJSON_IsNull(fs_type))
    {
    goto end; //String
    }
    }

    // v1_iscsi_persistent_volume_source->initiator_name
    cJSON *initiator_name = cJSON_GetObjectItemCaseSensitive(v1_iscsi_persistent_volume_sourceJSON, "initiatorName");
    if (cJSON_IsNull(initiator_name)) {
        initiator_name = NULL;
    }
    if (initiator_name) { 
    if(!cJSON_IsString(initiator_name) && !cJSON_IsNull(initiator_name))
    {
    goto end; //String
    }
    }

    // v1_iscsi_persistent_volume_source->iqn
    cJSON *iqn = cJSON_GetObjectItemCaseSensitive(v1_iscsi_persistent_volume_sourceJSON, "iqn");
    if (cJSON_IsNull(iqn)) {
        iqn = NULL;
    }
    if (!iqn) {
        goto end;
    }

    
    if(!cJSON_IsString(iqn))
    {
    goto end; //String
    }

    // v1_iscsi_persistent_volume_source->iscsi_interface
    cJSON *iscsi_interface = cJSON_GetObjectItemCaseSensitive(v1_iscsi_persistent_volume_sourceJSON, "iscsiInterface");
    if (cJSON_IsNull(iscsi_interface)) {
        iscsi_interface = NULL;
    }
    if (iscsi_interface) { 
    if(!cJSON_IsString(iscsi_interface) && !cJSON_IsNull(iscsi_interface))
    {
    goto end; //String
    }
    }

    // v1_iscsi_persistent_volume_source->lun
    cJSON *lun = cJSON_GetObjectItemCaseSensitive(v1_iscsi_persistent_volume_sourceJSON, "lun");
    if (cJSON_IsNull(lun)) {
        lun = NULL;
    }
    if (!lun) {
        goto end;
    }

    
    if(!cJSON_IsNumber(lun))
    {
    goto end; //Numeric
    }

    // v1_iscsi_persistent_volume_source->portals
    cJSON *portals = cJSON_GetObjectItemCaseSensitive(v1_iscsi_persistent_volume_sourceJSON, "portals");
    if (cJSON_IsNull(portals)) {
        portals = NULL;
    }
    if (portals) { 
    cJSON *portals_local = NULL;
    if(!cJSON_IsArray(portals)) {
        goto end;//primitive container
    }
    portalsList = list_createList();

    cJSON_ArrayForEach(portals_local, portals)
    {
        if(!cJSON_IsString(portals_local))
        {
            goto end;
        }
        list_addElement(portalsList , strdup(portals_local->valuestring));
    }
    }

    // v1_iscsi_persistent_volume_source->read_only
    cJSON *read_only = cJSON_GetObjectItemCaseSensitive(v1_iscsi_persistent_volume_sourceJSON, "readOnly");
    if (cJSON_IsNull(read_only)) {
        read_only = NULL;
    }
    if (read_only) { 
    if(!cJSON_IsBool(read_only))
    {
    goto end; //Bool
    }
    }

    // v1_iscsi_persistent_volume_source->secret_ref
    cJSON *secret_ref = cJSON_GetObjectItemCaseSensitive(v1_iscsi_persistent_volume_sourceJSON, "secretRef");
    if (cJSON_IsNull(secret_ref)) {
        secret_ref = NULL;
    }
    if (secret_ref) { 
    secret_ref_local_nonprim = v1_secret_reference_parseFromJSON(secret_ref); //nonprimitive
    }

    // v1_iscsi_persistent_volume_source->target_portal
    cJSON *target_portal = cJSON_GetObjectItemCaseSensitive(v1_iscsi_persistent_volume_sourceJSON, "targetPortal");
    if (cJSON_IsNull(target_portal)) {
        target_portal = NULL;
    }
    if (!target_portal) {
        goto end;
    }

    
    if(!cJSON_IsString(target_portal))
    {
    goto end; //String
    }


    v1_iscsi_persistent_volume_source_local_var = v1_iscsi_persistent_volume_source_create_internal (
        chap_auth_discovery ? chap_auth_discovery->valueint : 0,
        chap_auth_session ? chap_auth_session->valueint : 0,
        fs_type && !cJSON_IsNull(fs_type) ? strdup(fs_type->valuestring) : NULL,
        initiator_name && !cJSON_IsNull(initiator_name) ? strdup(initiator_name->valuestring) : NULL,
        strdup(iqn->valuestring),
        iscsi_interface && !cJSON_IsNull(iscsi_interface) ? strdup(iscsi_interface->valuestring) : NULL,
        lun->valuedouble,
        portals ? portalsList : NULL,
        read_only ? read_only->valueint : 0,
        secret_ref ? secret_ref_local_nonprim : NULL,
        strdup(target_portal->valuestring)
        );

    return v1_iscsi_persistent_volume_source_local_var;
end:
    if (portalsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, portalsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(portalsList);
        portalsList = NULL;
    }
    if (secret_ref_local_nonprim) {
        v1_secret_reference_free(secret_ref_local_nonprim);
        secret_ref_local_nonprim = NULL;
    }
    return NULL;

}
