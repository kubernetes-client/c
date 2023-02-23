#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_stateful_set_ordinals.h"



v1_stateful_set_ordinals_t *v1_stateful_set_ordinals_create(
    int start
    ) {
    v1_stateful_set_ordinals_t *v1_stateful_set_ordinals_local_var = malloc(sizeof(v1_stateful_set_ordinals_t));
    if (!v1_stateful_set_ordinals_local_var) {
        return NULL;
    }
    v1_stateful_set_ordinals_local_var->start = start;

    return v1_stateful_set_ordinals_local_var;
}


void v1_stateful_set_ordinals_free(v1_stateful_set_ordinals_t *v1_stateful_set_ordinals) {
    if(NULL == v1_stateful_set_ordinals){
        return ;
    }
    listEntry_t *listEntry;
    free(v1_stateful_set_ordinals);
}

cJSON *v1_stateful_set_ordinals_convertToJSON(v1_stateful_set_ordinals_t *v1_stateful_set_ordinals) {
    cJSON *item = cJSON_CreateObject();

    // v1_stateful_set_ordinals->start
    if(v1_stateful_set_ordinals->start) {
    if(cJSON_AddNumberToObject(item, "start", v1_stateful_set_ordinals->start) == NULL) {
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

v1_stateful_set_ordinals_t *v1_stateful_set_ordinals_parseFromJSON(cJSON *v1_stateful_set_ordinalsJSON){

    v1_stateful_set_ordinals_t *v1_stateful_set_ordinals_local_var = NULL;

    // v1_stateful_set_ordinals->start
    cJSON *start = cJSON_GetObjectItemCaseSensitive(v1_stateful_set_ordinalsJSON, "start");
    if (start) { 
    if(!cJSON_IsNumber(start))
    {
    goto end; //Numeric
    }
    }


    v1_stateful_set_ordinals_local_var = v1_stateful_set_ordinals_create (
        start ? start->valuedouble : 0
        );

    return v1_stateful_set_ordinals_local_var;
end:
    return NULL;

}
