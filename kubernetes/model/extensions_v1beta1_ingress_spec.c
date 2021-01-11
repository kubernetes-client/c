#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "extensions_v1beta1_ingress_spec.h"



extensions_v1beta1_ingress_spec_t *extensions_v1beta1_ingress_spec_create(
    extensions_v1beta1_ingress_backend_t *backend,
    list_t *rules,
    list_t *tls
    ) {
    extensions_v1beta1_ingress_spec_t *extensions_v1beta1_ingress_spec_local_var = malloc(sizeof(extensions_v1beta1_ingress_spec_t));
    if (!extensions_v1beta1_ingress_spec_local_var) {
        return NULL;
    }
    extensions_v1beta1_ingress_spec_local_var->backend = backend;
    extensions_v1beta1_ingress_spec_local_var->rules = rules;
    extensions_v1beta1_ingress_spec_local_var->tls = tls;

    return extensions_v1beta1_ingress_spec_local_var;
}


void extensions_v1beta1_ingress_spec_free(extensions_v1beta1_ingress_spec_t *extensions_v1beta1_ingress_spec) {
    if(NULL == extensions_v1beta1_ingress_spec){
        return ;
    }
    listEntry_t *listEntry;
    if (extensions_v1beta1_ingress_spec->backend) {
        extensions_v1beta1_ingress_backend_free(extensions_v1beta1_ingress_spec->backend);
        extensions_v1beta1_ingress_spec->backend = NULL;
    }
    if (extensions_v1beta1_ingress_spec->rules) {
        list_ForEach(listEntry, extensions_v1beta1_ingress_spec->rules) {
            extensions_v1beta1_ingress_rule_free(listEntry->data);
        }
        list_free(extensions_v1beta1_ingress_spec->rules);
        extensions_v1beta1_ingress_spec->rules = NULL;
    }
    if (extensions_v1beta1_ingress_spec->tls) {
        list_ForEach(listEntry, extensions_v1beta1_ingress_spec->tls) {
            extensions_v1beta1_ingress_tls_free(listEntry->data);
        }
        list_free(extensions_v1beta1_ingress_spec->tls);
        extensions_v1beta1_ingress_spec->tls = NULL;
    }
    free(extensions_v1beta1_ingress_spec);
}

cJSON *extensions_v1beta1_ingress_spec_convertToJSON(extensions_v1beta1_ingress_spec_t *extensions_v1beta1_ingress_spec) {
    cJSON *item = cJSON_CreateObject();

    // extensions_v1beta1_ingress_spec->backend
    if(extensions_v1beta1_ingress_spec->backend) { 
    cJSON *backend_local_JSON = extensions_v1beta1_ingress_backend_convertToJSON(extensions_v1beta1_ingress_spec->backend);
    if(backend_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "backend", backend_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // extensions_v1beta1_ingress_spec->rules
    if(extensions_v1beta1_ingress_spec->rules) { 
    cJSON *rules = cJSON_AddArrayToObject(item, "rules");
    if(rules == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *rulesListEntry;
    if (extensions_v1beta1_ingress_spec->rules) {
    list_ForEach(rulesListEntry, extensions_v1beta1_ingress_spec->rules) {
    cJSON *itemLocal = extensions_v1beta1_ingress_rule_convertToJSON(rulesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(rules, itemLocal);
    }
    }
     } 


    // extensions_v1beta1_ingress_spec->tls
    if(extensions_v1beta1_ingress_spec->tls) { 
    cJSON *tls = cJSON_AddArrayToObject(item, "tls");
    if(tls == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *tlsListEntry;
    if (extensions_v1beta1_ingress_spec->tls) {
    list_ForEach(tlsListEntry, extensions_v1beta1_ingress_spec->tls) {
    cJSON *itemLocal = extensions_v1beta1_ingress_tls_convertToJSON(tlsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(tls, itemLocal);
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

extensions_v1beta1_ingress_spec_t *extensions_v1beta1_ingress_spec_parseFromJSON(cJSON *extensions_v1beta1_ingress_specJSON){

    extensions_v1beta1_ingress_spec_t *extensions_v1beta1_ingress_spec_local_var = NULL;

    // extensions_v1beta1_ingress_spec->backend
    cJSON *backend = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_ingress_specJSON, "backend");
    extensions_v1beta1_ingress_backend_t *backend_local_nonprim = NULL;
    if (backend) { 
    backend_local_nonprim = extensions_v1beta1_ingress_backend_parseFromJSON(backend); //nonprimitive
    }

    // extensions_v1beta1_ingress_spec->rules
    cJSON *rules = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_ingress_specJSON, "rules");
    list_t *rulesList;
    if (rules) { 
    cJSON *rules_local_nonprimitive;
    if(!cJSON_IsArray(rules)){
        goto end; //nonprimitive container
    }

    rulesList = list_create();

    cJSON_ArrayForEach(rules_local_nonprimitive,rules )
    {
        if(!cJSON_IsObject(rules_local_nonprimitive)){
            goto end;
        }
        extensions_v1beta1_ingress_rule_t *rulesItem = extensions_v1beta1_ingress_rule_parseFromJSON(rules_local_nonprimitive);

        list_addElement(rulesList, rulesItem);
    }
    }

    // extensions_v1beta1_ingress_spec->tls
    cJSON *tls = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_ingress_specJSON, "tls");
    list_t *tlsList;
    if (tls) { 
    cJSON *tls_local_nonprimitive;
    if(!cJSON_IsArray(tls)){
        goto end; //nonprimitive container
    }

    tlsList = list_create();

    cJSON_ArrayForEach(tls_local_nonprimitive,tls )
    {
        if(!cJSON_IsObject(tls_local_nonprimitive)){
            goto end;
        }
        extensions_v1beta1_ingress_tls_t *tlsItem = extensions_v1beta1_ingress_tls_parseFromJSON(tls_local_nonprimitive);

        list_addElement(tlsList, tlsItem);
    }
    }


    extensions_v1beta1_ingress_spec_local_var = extensions_v1beta1_ingress_spec_create (
        backend ? backend_local_nonprim : NULL,
        rules ? rulesList : NULL,
        tls ? tlsList : NULL
        );

    return extensions_v1beta1_ingress_spec_local_var;
end:
    if (backend_local_nonprim) {
        extensions_v1beta1_ingress_backend_free(backend_local_nonprim);
        backend_local_nonprim = NULL;
    }
    return NULL;

}
