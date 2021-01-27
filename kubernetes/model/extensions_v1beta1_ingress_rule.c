#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "extensions_v1beta1_ingress_rule.h"



extensions_v1beta1_ingress_rule_t *extensions_v1beta1_ingress_rule_create(
    char *host,
    extensions_v1beta1_http_ingress_rule_value_t *http
    ) {
    extensions_v1beta1_ingress_rule_t *extensions_v1beta1_ingress_rule_local_var = malloc(sizeof(extensions_v1beta1_ingress_rule_t));
    if (!extensions_v1beta1_ingress_rule_local_var) {
        return NULL;
    }
    extensions_v1beta1_ingress_rule_local_var->host = host;
    extensions_v1beta1_ingress_rule_local_var->http = http;

    return extensions_v1beta1_ingress_rule_local_var;
}


void extensions_v1beta1_ingress_rule_free(extensions_v1beta1_ingress_rule_t *extensions_v1beta1_ingress_rule) {
    if(NULL == extensions_v1beta1_ingress_rule){
        return ;
    }
    listEntry_t *listEntry;
    if (extensions_v1beta1_ingress_rule->host) {
        free(extensions_v1beta1_ingress_rule->host);
        extensions_v1beta1_ingress_rule->host = NULL;
    }
    if (extensions_v1beta1_ingress_rule->http) {
        extensions_v1beta1_http_ingress_rule_value_free(extensions_v1beta1_ingress_rule->http);
        extensions_v1beta1_ingress_rule->http = NULL;
    }
    free(extensions_v1beta1_ingress_rule);
}

cJSON *extensions_v1beta1_ingress_rule_convertToJSON(extensions_v1beta1_ingress_rule_t *extensions_v1beta1_ingress_rule) {
    cJSON *item = cJSON_CreateObject();

    // extensions_v1beta1_ingress_rule->host
    if(extensions_v1beta1_ingress_rule->host) { 
    if(cJSON_AddStringToObject(item, "host", extensions_v1beta1_ingress_rule->host) == NULL) {
    goto fail; //String
    }
     } 


    // extensions_v1beta1_ingress_rule->http
    if(extensions_v1beta1_ingress_rule->http) { 
    cJSON *http_local_JSON = extensions_v1beta1_http_ingress_rule_value_convertToJSON(extensions_v1beta1_ingress_rule->http);
    if(http_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "http", http_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

extensions_v1beta1_ingress_rule_t *extensions_v1beta1_ingress_rule_parseFromJSON(cJSON *extensions_v1beta1_ingress_ruleJSON){

    extensions_v1beta1_ingress_rule_t *extensions_v1beta1_ingress_rule_local_var = NULL;

    // extensions_v1beta1_ingress_rule->host
    cJSON *host = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_ingress_ruleJSON, "host");
    if (host) { 
    if(!cJSON_IsString(host))
    {
    goto end; //String
    }
    }

    // extensions_v1beta1_ingress_rule->http
    cJSON *http = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_ingress_ruleJSON, "http");
    extensions_v1beta1_http_ingress_rule_value_t *http_local_nonprim = NULL;
    if (http) { 
    http_local_nonprim = extensions_v1beta1_http_ingress_rule_value_parseFromJSON(http); //nonprimitive
    }


    extensions_v1beta1_ingress_rule_local_var = extensions_v1beta1_ingress_rule_create (
        host ? strdup(host->valuestring) : NULL,
        http ? http_local_nonprim : NULL
        );

    return extensions_v1beta1_ingress_rule_local_var;
end:
    if (http_local_nonprim) {
        extensions_v1beta1_http_ingress_rule_value_free(http_local_nonprim);
        http_local_nonprim = NULL;
    }
    return NULL;

}
