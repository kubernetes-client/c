#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "networking_v1beta1_ingress_spec.h"



networking_v1beta1_ingress_spec_t *networking_v1beta1_ingress_spec_create(
    networking_v1beta1_ingress_backend_t *backend,
    list_t *rules,
    list_t *tls
    ) {
    networking_v1beta1_ingress_spec_t *networking_v1beta1_ingress_spec_local_var = malloc(sizeof(networking_v1beta1_ingress_spec_t));
    if (!networking_v1beta1_ingress_spec_local_var) {
        return NULL;
    }
    networking_v1beta1_ingress_spec_local_var->backend = backend;
    networking_v1beta1_ingress_spec_local_var->rules = rules;
    networking_v1beta1_ingress_spec_local_var->tls = tls;

    return networking_v1beta1_ingress_spec_local_var;
}


void networking_v1beta1_ingress_spec_free(networking_v1beta1_ingress_spec_t *networking_v1beta1_ingress_spec) {
    if(NULL == networking_v1beta1_ingress_spec){
        return ;
    }
    listEntry_t *listEntry;
    if (networking_v1beta1_ingress_spec->backend) {
        networking_v1beta1_ingress_backend_free(networking_v1beta1_ingress_spec->backend);
        networking_v1beta1_ingress_spec->backend = NULL;
    }
    if (networking_v1beta1_ingress_spec->rules) {
        list_ForEach(listEntry, networking_v1beta1_ingress_spec->rules) {
            networking_v1beta1_ingress_rule_free(listEntry->data);
        }
        list_free(networking_v1beta1_ingress_spec->rules);
        networking_v1beta1_ingress_spec->rules = NULL;
    }
    if (networking_v1beta1_ingress_spec->tls) {
        list_ForEach(listEntry, networking_v1beta1_ingress_spec->tls) {
            networking_v1beta1_ingress_tls_free(listEntry->data);
        }
        list_free(networking_v1beta1_ingress_spec->tls);
        networking_v1beta1_ingress_spec->tls = NULL;
    }
    free(networking_v1beta1_ingress_spec);
}

cJSON *networking_v1beta1_ingress_spec_convertToJSON(networking_v1beta1_ingress_spec_t *networking_v1beta1_ingress_spec) {
    cJSON *item = cJSON_CreateObject();

    // networking_v1beta1_ingress_spec->backend
    if(networking_v1beta1_ingress_spec->backend) { 
    cJSON *backend_local_JSON = networking_v1beta1_ingress_backend_convertToJSON(networking_v1beta1_ingress_spec->backend);
    if(backend_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "backend", backend_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // networking_v1beta1_ingress_spec->rules
    if(networking_v1beta1_ingress_spec->rules) { 
    cJSON *rules = cJSON_AddArrayToObject(item, "rules");
    if(rules == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *rulesListEntry;
    if (networking_v1beta1_ingress_spec->rules) {
    list_ForEach(rulesListEntry, networking_v1beta1_ingress_spec->rules) {
    cJSON *itemLocal = networking_v1beta1_ingress_rule_convertToJSON(rulesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(rules, itemLocal);
    }
    }
     } 


    // networking_v1beta1_ingress_spec->tls
    if(networking_v1beta1_ingress_spec->tls) { 
    cJSON *tls = cJSON_AddArrayToObject(item, "tls");
    if(tls == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *tlsListEntry;
    if (networking_v1beta1_ingress_spec->tls) {
    list_ForEach(tlsListEntry, networking_v1beta1_ingress_spec->tls) {
    cJSON *itemLocal = networking_v1beta1_ingress_tls_convertToJSON(tlsListEntry->data);
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

networking_v1beta1_ingress_spec_t *networking_v1beta1_ingress_spec_parseFromJSON(cJSON *networking_v1beta1_ingress_specJSON){

    networking_v1beta1_ingress_spec_t *networking_v1beta1_ingress_spec_local_var = NULL;

    // networking_v1beta1_ingress_spec->backend
    cJSON *backend = cJSON_GetObjectItemCaseSensitive(networking_v1beta1_ingress_specJSON, "backend");
    networking_v1beta1_ingress_backend_t *backend_local_nonprim = NULL;
    if (backend) { 
    backend_local_nonprim = networking_v1beta1_ingress_backend_parseFromJSON(backend); //nonprimitive
    }

    // networking_v1beta1_ingress_spec->rules
    cJSON *rules = cJSON_GetObjectItemCaseSensitive(networking_v1beta1_ingress_specJSON, "rules");
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
        networking_v1beta1_ingress_rule_t *rulesItem = networking_v1beta1_ingress_rule_parseFromJSON(rules_local_nonprimitive);

        list_addElement(rulesList, rulesItem);
    }
    }

    // networking_v1beta1_ingress_spec->tls
    cJSON *tls = cJSON_GetObjectItemCaseSensitive(networking_v1beta1_ingress_specJSON, "tls");
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
        networking_v1beta1_ingress_tls_t *tlsItem = networking_v1beta1_ingress_tls_parseFromJSON(tls_local_nonprimitive);

        list_addElement(tlsList, tlsItem);
    }
    }


    networking_v1beta1_ingress_spec_local_var = networking_v1beta1_ingress_spec_create (
        backend ? backend_local_nonprim : NULL,
        rules ? rulesList : NULL,
        tls ? tlsList : NULL
        );

    return networking_v1beta1_ingress_spec_local_var;
end:
    if (backend_local_nonprim) {
        networking_v1beta1_ingress_backend_free(backend_local_nonprim);
        backend_local_nonprim = NULL;
    }
    return NULL;

}
