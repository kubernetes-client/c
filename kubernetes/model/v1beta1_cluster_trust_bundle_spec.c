#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_cluster_trust_bundle_spec.h"



static v1beta1_cluster_trust_bundle_spec_t *v1beta1_cluster_trust_bundle_spec_create_internal(
    char *signer_name,
    char *trust_bundle
    ) {
    v1beta1_cluster_trust_bundle_spec_t *v1beta1_cluster_trust_bundle_spec_local_var = malloc(sizeof(v1beta1_cluster_trust_bundle_spec_t));
    if (!v1beta1_cluster_trust_bundle_spec_local_var) {
        return NULL;
    }
    memset(v1beta1_cluster_trust_bundle_spec_local_var, 0, sizeof(v1beta1_cluster_trust_bundle_spec_t));
    v1beta1_cluster_trust_bundle_spec_local_var->_library_owned = 1;
    v1beta1_cluster_trust_bundle_spec_local_var->signer_name = signer_name;
    v1beta1_cluster_trust_bundle_spec_local_var->trust_bundle = trust_bundle;
    return v1beta1_cluster_trust_bundle_spec_local_var;
}

__attribute__((deprecated)) v1beta1_cluster_trust_bundle_spec_t *v1beta1_cluster_trust_bundle_spec_create(
    char *signer_name,
    char *trust_bundle
    ) {
    v1beta1_cluster_trust_bundle_spec_t *result = v1beta1_cluster_trust_bundle_spec_create_internal (
        signer_name,
        trust_bundle
        );
    if (!result) {
    }
    return result;
}

void v1beta1_cluster_trust_bundle_spec_free(v1beta1_cluster_trust_bundle_spec_t *v1beta1_cluster_trust_bundle_spec) {
    if(NULL == v1beta1_cluster_trust_bundle_spec){
        return ;
    }
    if(v1beta1_cluster_trust_bundle_spec->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1beta1_cluster_trust_bundle_spec_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta1_cluster_trust_bundle_spec->signer_name) {
        free(v1beta1_cluster_trust_bundle_spec->signer_name);
        v1beta1_cluster_trust_bundle_spec->signer_name = NULL;
    }
    if (v1beta1_cluster_trust_bundle_spec->trust_bundle) {
        free(v1beta1_cluster_trust_bundle_spec->trust_bundle);
        v1beta1_cluster_trust_bundle_spec->trust_bundle = NULL;
    }
    free(v1beta1_cluster_trust_bundle_spec);
}

cJSON *v1beta1_cluster_trust_bundle_spec_convertToJSON(v1beta1_cluster_trust_bundle_spec_t *v1beta1_cluster_trust_bundle_spec) {
    cJSON *item = cJSON_CreateObject();

    // v1beta1_cluster_trust_bundle_spec->signer_name
    if(v1beta1_cluster_trust_bundle_spec->signer_name) {
    if(cJSON_AddStringToObject(item, "signerName", v1beta1_cluster_trust_bundle_spec->signer_name) == NULL) {
    goto fail; //String
    }
    }


    // v1beta1_cluster_trust_bundle_spec->trust_bundle
    if (!v1beta1_cluster_trust_bundle_spec->trust_bundle) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "trustBundle", v1beta1_cluster_trust_bundle_spec->trust_bundle) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1beta1_cluster_trust_bundle_spec_t *v1beta1_cluster_trust_bundle_spec_parseFromJSON(cJSON *v1beta1_cluster_trust_bundle_specJSON){

    v1beta1_cluster_trust_bundle_spec_t *v1beta1_cluster_trust_bundle_spec_local_var = NULL;

    char *signer_name_local_str = NULL;

    char *trust_bundle_local_str = NULL;

    // v1beta1_cluster_trust_bundle_spec->signer_name
    cJSON *signer_name = cJSON_GetObjectItemCaseSensitive(v1beta1_cluster_trust_bundle_specJSON, "signerName");
    if (cJSON_IsNull(signer_name)) {
        signer_name = NULL;
    }
    if (signer_name) { 
    if(!cJSON_IsString(signer_name) && !cJSON_IsNull(signer_name))
    {
    goto end; //String
    }
    }

    // v1beta1_cluster_trust_bundle_spec->trust_bundle
    cJSON *trust_bundle = cJSON_GetObjectItemCaseSensitive(v1beta1_cluster_trust_bundle_specJSON, "trustBundle");
    if (cJSON_IsNull(trust_bundle)) {
        trust_bundle = NULL;
    }
    if (!trust_bundle) {
        goto end;
    }

    
    if(!cJSON_IsString(trust_bundle))
    {
    goto end; //String
    }


    if (signer_name && !cJSON_IsNull(signer_name)) signer_name_local_str = strdup(signer_name->valuestring);
    if (trust_bundle && !cJSON_IsNull(trust_bundle)) trust_bundle_local_str = strdup(trust_bundle->valuestring);

    v1beta1_cluster_trust_bundle_spec_local_var = v1beta1_cluster_trust_bundle_spec_create_internal (
        signer_name_local_str,
        trust_bundle_local_str
        );

    if (!v1beta1_cluster_trust_bundle_spec_local_var) {
        goto end;
    }

    return v1beta1_cluster_trust_bundle_spec_local_var;
end:
    if (signer_name_local_str) {
        free(signer_name_local_str);
        signer_name_local_str = NULL;
    }
    if (trust_bundle_local_str) {
        free(trust_bundle_local_str);
        trust_bundle_local_str = NULL;
    }
    return NULL;

}
