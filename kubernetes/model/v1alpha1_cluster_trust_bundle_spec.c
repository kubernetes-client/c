#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha1_cluster_trust_bundle_spec.h"



static v1alpha1_cluster_trust_bundle_spec_t *v1alpha1_cluster_trust_bundle_spec_create_internal(
    char *signer_name,
    char *trust_bundle
    ) {
    v1alpha1_cluster_trust_bundle_spec_t *v1alpha1_cluster_trust_bundle_spec_local_var = malloc(sizeof(v1alpha1_cluster_trust_bundle_spec_t));
    if (!v1alpha1_cluster_trust_bundle_spec_local_var) {
        return NULL;
    }
    v1alpha1_cluster_trust_bundle_spec_local_var->signer_name = signer_name;
    v1alpha1_cluster_trust_bundle_spec_local_var->trust_bundle = trust_bundle;

    v1alpha1_cluster_trust_bundle_spec_local_var->_library_owned = 1;
    return v1alpha1_cluster_trust_bundle_spec_local_var;
}

__attribute__((deprecated)) v1alpha1_cluster_trust_bundle_spec_t *v1alpha1_cluster_trust_bundle_spec_create(
    char *signer_name,
    char *trust_bundle
    ) {
    return v1alpha1_cluster_trust_bundle_spec_create_internal (
        signer_name,
        trust_bundle
        );
}

void v1alpha1_cluster_trust_bundle_spec_free(v1alpha1_cluster_trust_bundle_spec_t *v1alpha1_cluster_trust_bundle_spec) {
    if(NULL == v1alpha1_cluster_trust_bundle_spec){
        return ;
    }
    if(v1alpha1_cluster_trust_bundle_spec->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1alpha1_cluster_trust_bundle_spec_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha1_cluster_trust_bundle_spec->signer_name) {
        free(v1alpha1_cluster_trust_bundle_spec->signer_name);
        v1alpha1_cluster_trust_bundle_spec->signer_name = NULL;
    }
    if (v1alpha1_cluster_trust_bundle_spec->trust_bundle) {
        free(v1alpha1_cluster_trust_bundle_spec->trust_bundle);
        v1alpha1_cluster_trust_bundle_spec->trust_bundle = NULL;
    }
    free(v1alpha1_cluster_trust_bundle_spec);
}

cJSON *v1alpha1_cluster_trust_bundle_spec_convertToJSON(v1alpha1_cluster_trust_bundle_spec_t *v1alpha1_cluster_trust_bundle_spec) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha1_cluster_trust_bundle_spec->signer_name
    if(v1alpha1_cluster_trust_bundle_spec->signer_name) {
    if(cJSON_AddStringToObject(item, "signerName", v1alpha1_cluster_trust_bundle_spec->signer_name) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha1_cluster_trust_bundle_spec->trust_bundle
    if (!v1alpha1_cluster_trust_bundle_spec->trust_bundle) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "trustBundle", v1alpha1_cluster_trust_bundle_spec->trust_bundle) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1alpha1_cluster_trust_bundle_spec_t *v1alpha1_cluster_trust_bundle_spec_parseFromJSON(cJSON *v1alpha1_cluster_trust_bundle_specJSON){

    v1alpha1_cluster_trust_bundle_spec_t *v1alpha1_cluster_trust_bundle_spec_local_var = NULL;

    // v1alpha1_cluster_trust_bundle_spec->signer_name
    cJSON *signer_name = cJSON_GetObjectItemCaseSensitive(v1alpha1_cluster_trust_bundle_specJSON, "signerName");
    if (cJSON_IsNull(signer_name)) {
        signer_name = NULL;
    }
    if (signer_name) { 
    if(!cJSON_IsString(signer_name) && !cJSON_IsNull(signer_name))
    {
    goto end; //String
    }
    }

    // v1alpha1_cluster_trust_bundle_spec->trust_bundle
    cJSON *trust_bundle = cJSON_GetObjectItemCaseSensitive(v1alpha1_cluster_trust_bundle_specJSON, "trustBundle");
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


    v1alpha1_cluster_trust_bundle_spec_local_var = v1alpha1_cluster_trust_bundle_spec_create_internal (
        signer_name && !cJSON_IsNull(signer_name) ? strdup(signer_name->valuestring) : NULL,
        strdup(trust_bundle->valuestring)
        );

    return v1alpha1_cluster_trust_bundle_spec_local_var;
end:
    return NULL;

}
