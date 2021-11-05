#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_ingress_rule.h"



v1_ingress_rule_t *v1_ingress_rule_create(
    char *host,
    v1_http_ingress_rule_value_t *http
    ) {
    v1_ingress_rule_t *v1_ingress_rule_local_var = malloc(sizeof(v1_ingress_rule_t));
    if (!v1_ingress_rule_local_var) {
        return NULL;
    }
    v1_ingress_rule_local_var->host = host;
    v1_ingress_rule_local_var->http = http;

    return v1_ingress_rule_local_var;
}


void v1_ingress_rule_free(v1_ingress_rule_t *v1_ingress_rule) {
    if(NULL == v1_ingress_rule){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_ingress_rule->host) {
        free(v1_ingress_rule->host);
        v1_ingress_rule->host = NULL;
    }
    if (v1_ingress_rule->http) {
        v1_http_ingress_rule_value_free(v1_ingress_rule->http);
        v1_ingress_rule->http = NULL;
    }
    free(v1_ingress_rule);
}

cJSON *v1_ingress_rule_convertToJSON(v1_ingress_rule_t *v1_ingress_rule) {
    cJSON *item = cJSON_CreateObject();

    // v1_ingress_rule->host
    if(v1_ingress_rule->host) { 
    if(cJSON_AddStringToObject(item, "host", v1_ingress_rule->host) == NULL) {
    goto fail; //String
    }
     } 


    // v1_ingress_rule->http
    if(v1_ingress_rule->http) { 
    cJSON *http_local_JSON = v1_http_ingress_rule_value_convertToJSON(v1_ingress_rule->http);
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

v1_ingress_rule_t *v1_ingress_rule_parseFromJSON(cJSON *v1_ingress_ruleJSON){

    v1_ingress_rule_t *v1_ingress_rule_local_var = NULL;

    // define the local variable for v1_ingress_rule->http
    v1_http_ingress_rule_value_t *http_local_nonprim = NULL;

    // v1_ingress_rule->host
    cJSON *host = cJSON_GetObjectItemCaseSensitive(v1_ingress_ruleJSON, "host");
    if (host) { 
    if(!cJSON_IsString(host))
    {
    goto end; //String
    }
    }

    // v1_ingress_rule->http
    cJSON *http = cJSON_GetObjectItemCaseSensitive(v1_ingress_ruleJSON, "http");
    if (http) { 
    http_local_nonprim = v1_http_ingress_rule_value_parseFromJSON(http); //nonprimitive
    }


    v1_ingress_rule_local_var = v1_ingress_rule_create (
        host ? strdup(host->valuestring) : NULL,
        http ? http_local_nonprim : NULL
        );

    return v1_ingress_rule_local_var;
end:
    if (http_local_nonprim) {
        v1_http_ingress_rule_value_free(http_local_nonprim);
        http_local_nonprim = NULL;
    }
    return NULL;

}
