#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_service_backend_port.h"



static v1_service_backend_port_t *v1_service_backend_port_create_internal(
    char *name,
    int number
    ) {
    v1_service_backend_port_t *v1_service_backend_port_local_var = malloc(sizeof(v1_service_backend_port_t));
    if (!v1_service_backend_port_local_var) {
        return NULL;
    }
    v1_service_backend_port_local_var->name = name;
    v1_service_backend_port_local_var->number = number;

    v1_service_backend_port_local_var->_library_owned = 1;
    return v1_service_backend_port_local_var;
}

__attribute__((deprecated)) v1_service_backend_port_t *v1_service_backend_port_create(
    char *name,
    int number
    ) {
    return v1_service_backend_port_create_internal (
        name,
        number
        );
}

void v1_service_backend_port_free(v1_service_backend_port_t *v1_service_backend_port) {
    if(NULL == v1_service_backend_port){
        return ;
    }
    if(v1_service_backend_port->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_service_backend_port_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_service_backend_port->name) {
        free(v1_service_backend_port->name);
        v1_service_backend_port->name = NULL;
    }
    free(v1_service_backend_port);
}

cJSON *v1_service_backend_port_convertToJSON(v1_service_backend_port_t *v1_service_backend_port) {
    cJSON *item = cJSON_CreateObject();

    // v1_service_backend_port->name
    if(v1_service_backend_port->name) {
    if(cJSON_AddStringToObject(item, "name", v1_service_backend_port->name) == NULL) {
    goto fail; //String
    }
    }


    // v1_service_backend_port->number
    if(v1_service_backend_port->number) {
    if(cJSON_AddNumberToObject(item, "number", v1_service_backend_port->number) == NULL) {
    goto fail; //Numeric
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_service_backend_port_t *v1_service_backend_port_parseFromJSON(cJSON *v1_service_backend_portJSON){

    v1_service_backend_port_t *v1_service_backend_port_local_var = NULL;

    // v1_service_backend_port->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1_service_backend_portJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // v1_service_backend_port->number
    cJSON *number = cJSON_GetObjectItemCaseSensitive(v1_service_backend_portJSON, "number");
    if (cJSON_IsNull(number)) {
        number = NULL;
    }
    if (number) { 
    if(!cJSON_IsNumber(number))
    {
    goto end; //Numeric
    }
    }


    v1_service_backend_port_local_var = v1_service_backend_port_create_internal (
        name && !cJSON_IsNull(name) ? strdup(name->valuestring) : NULL,
        number ? number->valuedouble : 0
        );

    return v1_service_backend_port_local_var;
end:
    return NULL;

}
