#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_iscsi_persistent_volume_source.h"



static v1_iscsi_persistent_volume_source_t *v1_iscsi_persistent_volume_source_create_internal(
    int *chap_auth_discovery,
    int *chap_auth_session,
    char *fs_type,
    char *initiator_name,
    char *iqn,
    char *iscsi_interface,
    int *lun,
    list_t *portals,
    int *read_only,
    v1_secret_reference_t *secret_ref,
    char *target_portal
    ) {
    v1_iscsi_persistent_volume_source_t *v1_iscsi_persistent_volume_source_local_var = malloc(sizeof(v1_iscsi_persistent_volume_source_t));
    if (!v1_iscsi_persistent_volume_source_local_var) {
        return NULL;
    }
    memset(v1_iscsi_persistent_volume_source_local_var, 0, sizeof(v1_iscsi_persistent_volume_source_t));
    v1_iscsi_persistent_volume_source_local_var->_library_owned = 1;
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
    return v1_iscsi_persistent_volume_source_local_var;
}

__attribute__((deprecated)) v1_iscsi_persistent_volume_source_t *v1_iscsi_persistent_volume_source_create(
    int *chap_auth_discovery,
    int *chap_auth_session,
    char *fs_type,
    char *initiator_name,
    char *iqn,
    char *iscsi_interface,
    int *lun,
    list_t *portals,
    int *read_only,
    v1_secret_reference_t *secret_ref,
    char *target_portal
    ) {
    int *chap_auth_discovery_copy = NULL;
    if (chap_auth_discovery) {
        chap_auth_discovery_copy = malloc(sizeof(int));
        if (chap_auth_discovery_copy) *chap_auth_discovery_copy = *chap_auth_discovery;
    }
    int *chap_auth_session_copy = NULL;
    if (chap_auth_session) {
        chap_auth_session_copy = malloc(sizeof(int));
        if (chap_auth_session_copy) *chap_auth_session_copy = *chap_auth_session;
    }
    int *lun_copy = NULL;
    if (lun) {
        lun_copy = malloc(sizeof(int));
        if (lun_copy) *lun_copy = *lun;
    }
    int *read_only_copy = NULL;
    if (read_only) {
        read_only_copy = malloc(sizeof(int));
        if (read_only_copy) *read_only_copy = *read_only;
    }
    v1_iscsi_persistent_volume_source_t *result = v1_iscsi_persistent_volume_source_create_internal (
        chap_auth_discovery_copy,
        chap_auth_session_copy,
        fs_type,
        initiator_name,
        iqn,
        iscsi_interface,
        lun_copy,
        portals,
        read_only_copy,
        secret_ref,
        target_portal
        );
    if (!result) {
        free(chap_auth_discovery_copy);
        free(chap_auth_session_copy);
        free(lun_copy);
        free(read_only_copy);
    }
    return result;
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
    if (v1_iscsi_persistent_volume_source->chap_auth_discovery) {
        free(v1_iscsi_persistent_volume_source->chap_auth_discovery);
        v1_iscsi_persistent_volume_source->chap_auth_discovery = NULL;
    }
    if (v1_iscsi_persistent_volume_source->chap_auth_session) {
        free(v1_iscsi_persistent_volume_source->chap_auth_session);
        v1_iscsi_persistent_volume_source->chap_auth_session = NULL;
    }
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
    if (v1_iscsi_persistent_volume_source->lun) {
        free(v1_iscsi_persistent_volume_source->lun);
        v1_iscsi_persistent_volume_source->lun = NULL;
    }
    if (v1_iscsi_persistent_volume_source->portals) {
        list_ForEach(listEntry, v1_iscsi_persistent_volume_source->portals) {
            free(listEntry->data);
        }
        list_freeList(v1_iscsi_persistent_volume_source->portals);
        v1_iscsi_persistent_volume_source->portals = NULL;
    }
    if (v1_iscsi_persistent_volume_source->read_only) {
        free(v1_iscsi_persistent_volume_source->read_only);
        v1_iscsi_persistent_volume_source->read_only = NULL;
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
    if(cJSON_AddBoolToObject(item, "chapAuthDiscovery", *v1_iscsi_persistent_volume_source->chap_auth_discovery) == NULL) {
    goto fail; //Bool
    }
    }


    // v1_iscsi_persistent_volume_source->chap_auth_session
    if(v1_iscsi_persistent_volume_source->chap_auth_session) {
    if(cJSON_AddBoolToObject(item, "chapAuthSession", *v1_iscsi_persistent_volume_source->chap_auth_session) == NULL) {
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
    if(cJSON_AddNumberToObject(item, "lun", *v1_iscsi_persistent_volume_source->lun) == NULL) {
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
    if(cJSON_AddBoolToObject(item, "readOnly", *v1_iscsi_persistent_volume_source->read_only) == NULL) {
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

    // define the local variable for v1_iscsi_persistent_volume_source->chap_auth_discovery
    int *chap_auth_discovery_local_var = NULL;

    // define the local variable for v1_iscsi_persistent_volume_source->chap_auth_session
    int *chap_auth_session_local_var = NULL;

    char *fs_type_local_str = NULL;

    char *initiator_name_local_str = NULL;

    char *iqn_local_str = NULL;

    char *iscsi_interface_local_str = NULL;

    // define the local variable for v1_iscsi_persistent_volume_source->lun
    int *lun_local_var = NULL;

    // define the local list for v1_iscsi_persistent_volume_source->portals
    list_t *portalsList = NULL;

    // define the local variable for v1_iscsi_persistent_volume_source->read_only
    int *read_only_local_var = NULL;

    // define the local variable for v1_iscsi_persistent_volume_source->secret_ref
    v1_secret_reference_t *secret_ref_local_nonprim = NULL;

    char *target_portal_local_str = NULL;

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
    chap_auth_discovery_local_var = malloc(sizeof(int));
    if(!chap_auth_discovery_local_var)
    {
        goto end;
    }
    *chap_auth_discovery_local_var = chap_auth_discovery->valueint;
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
    chap_auth_session_local_var = malloc(sizeof(int));
    if(!chap_auth_session_local_var)
    {
        goto end;
    }
    *chap_auth_session_local_var = chap_auth_session->valueint;
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
    lun_local_var = malloc(sizeof(int));
    if(!lun_local_var)
    {
        goto end;
    }
    *lun_local_var = lun->valuedouble;

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
    read_only_local_var = malloc(sizeof(int));
    if(!read_only_local_var)
    {
        goto end;
    }
    *read_only_local_var = read_only->valueint;
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


    if (fs_type && !cJSON_IsNull(fs_type)) fs_type_local_str = strdup(fs_type->valuestring);
    if (initiator_name && !cJSON_IsNull(initiator_name)) initiator_name_local_str = strdup(initiator_name->valuestring);
    if (iqn && !cJSON_IsNull(iqn)) iqn_local_str = strdup(iqn->valuestring);
    if (iscsi_interface && !cJSON_IsNull(iscsi_interface)) iscsi_interface_local_str = strdup(iscsi_interface->valuestring);
    if (target_portal && !cJSON_IsNull(target_portal)) target_portal_local_str = strdup(target_portal->valuestring);

    v1_iscsi_persistent_volume_source_local_var = v1_iscsi_persistent_volume_source_create_internal (
        chap_auth_discovery_local_var,
        chap_auth_session_local_var,
        fs_type_local_str,
        initiator_name_local_str,
        iqn_local_str,
        iscsi_interface_local_str,
        lun_local_var,
        portals ? portalsList : NULL,
        read_only_local_var,
        secret_ref ? secret_ref_local_nonprim : NULL,
        target_portal_local_str
        );

    if (!v1_iscsi_persistent_volume_source_local_var) {
        goto end;
    }

    return v1_iscsi_persistent_volume_source_local_var;
end:
    if (chap_auth_discovery_local_var) {
        free(chap_auth_discovery_local_var);
        chap_auth_discovery_local_var = NULL;
    }
    if (chap_auth_session_local_var) {
        free(chap_auth_session_local_var);
        chap_auth_session_local_var = NULL;
    }
    if (fs_type_local_str) {
        free(fs_type_local_str);
        fs_type_local_str = NULL;
    }
    if (initiator_name_local_str) {
        free(initiator_name_local_str);
        initiator_name_local_str = NULL;
    }
    if (iqn_local_str) {
        free(iqn_local_str);
        iqn_local_str = NULL;
    }
    if (iscsi_interface_local_str) {
        free(iscsi_interface_local_str);
        iscsi_interface_local_str = NULL;
    }
    if (lun_local_var) {
        free(lun_local_var);
        lun_local_var = NULL;
    }
    if (portalsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, portalsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(portalsList);
        portalsList = NULL;
    }
    if (read_only_local_var) {
        free(read_only_local_var);
        read_only_local_var = NULL;
    }
    if (secret_ref_local_nonprim) {
        v1_secret_reference_free(secret_ref_local_nonprim);
        secret_ref_local_nonprim = NULL;
    }
    if (target_portal_local_str) {
        free(target_portal_local_str);
        target_portal_local_str = NULL;
    }
    return NULL;

}
