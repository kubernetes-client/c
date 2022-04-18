#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_port_status.h"


char* protocolv1_port_status_ToString(kubernetes_v1_port_status_PROTOCOL_e protocol) {
    char* protocolArray[] =  { "NULL", "SCTP", "TCP", "UDP" };
	return protocolArray[protocol];
}

kubernetes_v1_port_status_PROTOCOL_e protocolv1_port_status_FromString(char* protocol){
    int stringToReturn = 0;
    char *protocolArray[] =  { "NULL", "SCTP", "TCP", "UDP" };
    size_t sizeofArray = sizeof(protocolArray) / sizeof(protocolArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(protocol, protocolArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

v1_port_status_t *v1_port_status_create(
    char *error,
    int port,
    kubernetes_v1_port_status_PROTOCOL_e protocol
    ) {
    v1_port_status_t *v1_port_status_local_var = malloc(sizeof(v1_port_status_t));
    if (!v1_port_status_local_var) {
        return NULL;
    }
    v1_port_status_local_var->error = error;
    v1_port_status_local_var->port = port;
    v1_port_status_local_var->protocol = protocol;

    return v1_port_status_local_var;
}


void v1_port_status_free(v1_port_status_t *v1_port_status) {
    if(NULL == v1_port_status){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_port_status->error) {
        free(v1_port_status->error);
        v1_port_status->error = NULL;
    }
    free(v1_port_status);
}

cJSON *v1_port_status_convertToJSON(v1_port_status_t *v1_port_status) {
    cJSON *item = cJSON_CreateObject();

    // v1_port_status->error
    if(v1_port_status->error) {
    if(cJSON_AddStringToObject(item, "error", v1_port_status->error) == NULL) {
    goto fail; //String
    }
    }


    // v1_port_status->port
    if (!v1_port_status->port) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "port", v1_port_status->port) == NULL) {
    goto fail; //Numeric
    }


    // v1_port_status->protocol
    if (kubernetes_v1_port_status_PROTOCOL_NULL == v1_port_status->protocol) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "protocol", protocolv1_port_status_ToString(v1_port_status->protocol)) == NULL)
    {
    goto fail; //Enum
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_port_status_t *v1_port_status_parseFromJSON(cJSON *v1_port_statusJSON){

    v1_port_status_t *v1_port_status_local_var = NULL;

    // v1_port_status->error
    cJSON *error = cJSON_GetObjectItemCaseSensitive(v1_port_statusJSON, "error");
    if (error) { 
    if(!cJSON_IsString(error))
    {
    goto end; //String
    }
    }

    // v1_port_status->port
    cJSON *port = cJSON_GetObjectItemCaseSensitive(v1_port_statusJSON, "port");
    if (!port) {
        goto end;
    }

    
    if(!cJSON_IsNumber(port))
    {
    goto end; //Numeric
    }

    // v1_port_status->protocol
    cJSON *protocol = cJSON_GetObjectItemCaseSensitive(v1_port_statusJSON, "protocol");
    if (!protocol) {
        goto end;
    }

    kubernetes_v1_port_status_PROTOCOL_e protocolVariable;
    
    if(!cJSON_IsString(protocol))
    {
    goto end; //Enum
    }
    protocolVariable = protocolv1_port_status_FromString(protocol->valuestring);


    v1_port_status_local_var = v1_port_status_create (
        error ? strdup(error->valuestring) : NULL,
        port->valuedouble,
        protocolVariable
        );

    return v1_port_status_local_var;
end:
    return NULL;

}
