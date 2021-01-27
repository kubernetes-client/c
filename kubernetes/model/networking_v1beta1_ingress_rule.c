#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "networking_v1beta1_ingress_rule.h"



networking_v1beta1_ingress_rule_t *networking_v1beta1_ingress_rule_create(
    char *host,
    networking_v1beta1_http_ingress_rule_value_t *http
    ) {
    networking_v1beta1_ingress_rule_t *networking_v1beta1_ingress_rule_local_var = malloc(sizeof(networking_v1beta1_ingress_rule_t));
    if (!networking_v1beta1_ingress_rule_local_var) {
        return NULL;
    }
    networking_v1beta1_ingress_rule_local_var->host = host;
    networking_v1beta1_ingress_rule_local_var->http = http;

    return networking_v1beta1_ingress_rule_local_var;
}


void networking_v1beta1_ingress_rule_free(networking_v1beta1_ingress_rule_t *networking_v1beta1_ingress_rule) {
    if(NULL == networking_v1beta1_ingress_rule){
        return ;
    }
    listEntry_t *listEntry;
    if (networking_v1beta1_ingress_rule->host) {
        free(networking_v1beta1_ingress_rule->host);
        networking_v1beta1_ingress_rule->host = NULL;
    }
    if (networking_v1beta1_ingress_rule->http) {
        networking_v1beta1_http_ingress_rule_value_free(networking_v1beta1_ingress_rule->http);
        networking_v1beta1_ingress_rule->http = NULL;
    }
    free(networking_v1beta1_ingress_rule);
}

cJSON *networking_v1beta1_ingress_rule_convertToJSON(networking_v1beta1_ingress_rule_t *networking_v1beta1_ingress_rule) {
    cJSON *item = cJSON_CreateObject();

    // networking_v1beta1_ingress_rule->host
    if(networking_v1beta1_ingress_rule->host) { 
    if(cJSON_AddStringToObject(item, "host", networking_v1beta1_ingress_rule->host) == NULL) {
    goto fail; //String
    }
     } 


    // networking_v1beta1_ingress_rule->http
    if(networking_v1beta1_ingress_rule->http) { 
    cJSON *http_local_JSON = networking_v1beta1_http_ingress_rule_value_convertToJSON(networking_v1beta1_ingress_rule->http);
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

networking_v1beta1_ingress_rule_t *networking_v1beta1_ingress_rule_parseFromJSON(cJSON *networking_v1beta1_ingress_ruleJSON){

    networking_v1beta1_ingress_rule_t *networking_v1beta1_ingress_rule_local_var = NULL;

    // networking_v1beta1_ingress_rule->host
    cJSON *host = cJSON_GetObjectItemCaseSensitive(networking_v1beta1_ingress_ruleJSON, "host");
    if (host) { 
    if(!cJSON_IsString(host))
    {
    goto end; //String
    }
    }

    // networking_v1beta1_ingress_rule->http
    cJSON *http = cJSON_GetObjectItemCaseSensitive(networking_v1beta1_ingress_ruleJSON, "http");
    networking_v1beta1_http_ingress_rule_value_t *http_local_nonprim = NULL;
    if (http) { 
    http_local_nonprim = networking_v1beta1_http_ingress_rule_value_parseFromJSON(http); //nonprimitive
    }


    networking_v1beta1_ingress_rule_local_var = networking_v1beta1_ingress_rule_create (
        host ? strdup(host->valuestring) : NULL,
        http ? http_local_nonprim : NULL
        );

    return networking_v1beta1_ingress_rule_local_var;
end:
    if (http_local_nonprim) {
        networking_v1beta1_http_ingress_rule_value_free(http_local_nonprim);
        http_local_nonprim = NULL;
    }
    return NULL;

}
