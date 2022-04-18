#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_queuing_configuration.h"



v1beta1_queuing_configuration_t *v1beta1_queuing_configuration_create(
    int hand_size,
    int queue_length_limit,
    int queues
    ) {
    v1beta1_queuing_configuration_t *v1beta1_queuing_configuration_local_var = malloc(sizeof(v1beta1_queuing_configuration_t));
    if (!v1beta1_queuing_configuration_local_var) {
        return NULL;
    }
    v1beta1_queuing_configuration_local_var->hand_size = hand_size;
    v1beta1_queuing_configuration_local_var->queue_length_limit = queue_length_limit;
    v1beta1_queuing_configuration_local_var->queues = queues;

    return v1beta1_queuing_configuration_local_var;
}


void v1beta1_queuing_configuration_free(v1beta1_queuing_configuration_t *v1beta1_queuing_configuration) {
    if(NULL == v1beta1_queuing_configuration){
        return ;
    }
    listEntry_t *listEntry;
    free(v1beta1_queuing_configuration);
}

cJSON *v1beta1_queuing_configuration_convertToJSON(v1beta1_queuing_configuration_t *v1beta1_queuing_configuration) {
    cJSON *item = cJSON_CreateObject();

    // v1beta1_queuing_configuration->hand_size
    if(v1beta1_queuing_configuration->hand_size) {
    if(cJSON_AddNumberToObject(item, "handSize", v1beta1_queuing_configuration->hand_size) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1beta1_queuing_configuration->queue_length_limit
    if(v1beta1_queuing_configuration->queue_length_limit) {
    if(cJSON_AddNumberToObject(item, "queueLengthLimit", v1beta1_queuing_configuration->queue_length_limit) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1beta1_queuing_configuration->queues
    if(v1beta1_queuing_configuration->queues) {
    if(cJSON_AddNumberToObject(item, "queues", v1beta1_queuing_configuration->queues) == NULL) {
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

v1beta1_queuing_configuration_t *v1beta1_queuing_configuration_parseFromJSON(cJSON *v1beta1_queuing_configurationJSON){

    v1beta1_queuing_configuration_t *v1beta1_queuing_configuration_local_var = NULL;

    // v1beta1_queuing_configuration->hand_size
    cJSON *hand_size = cJSON_GetObjectItemCaseSensitive(v1beta1_queuing_configurationJSON, "handSize");
    if (hand_size) { 
    if(!cJSON_IsNumber(hand_size))
    {
    goto end; //Numeric
    }
    }

    // v1beta1_queuing_configuration->queue_length_limit
    cJSON *queue_length_limit = cJSON_GetObjectItemCaseSensitive(v1beta1_queuing_configurationJSON, "queueLengthLimit");
    if (queue_length_limit) { 
    if(!cJSON_IsNumber(queue_length_limit))
    {
    goto end; //Numeric
    }
    }

    // v1beta1_queuing_configuration->queues
    cJSON *queues = cJSON_GetObjectItemCaseSensitive(v1beta1_queuing_configurationJSON, "queues");
    if (queues) { 
    if(!cJSON_IsNumber(queues))
    {
    goto end; //Numeric
    }
    }


    v1beta1_queuing_configuration_local_var = v1beta1_queuing_configuration_create (
        hand_size ? hand_size->valuedouble : 0,
        queue_length_limit ? queue_length_limit->valuedouble : 0,
        queues ? queues->valuedouble : 0
        );

    return v1beta1_queuing_configuration_local_var;
end:
    return NULL;

}
