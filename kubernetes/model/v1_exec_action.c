#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_exec_action.h"



v1_exec_action_t *v1_exec_action_create(
    list_t *command
    ) {
    v1_exec_action_t *v1_exec_action_local_var = malloc(sizeof(v1_exec_action_t));
    if (!v1_exec_action_local_var) {
        return NULL;
    }
    v1_exec_action_local_var->command = command;

    return v1_exec_action_local_var;
}


void v1_exec_action_free(v1_exec_action_t *v1_exec_action) {
    if(NULL == v1_exec_action){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_exec_action->command) {
        list_ForEach(listEntry, v1_exec_action->command) {
            free(listEntry->data);
        }
        list_free(v1_exec_action->command);
        v1_exec_action->command = NULL;
    }
    free(v1_exec_action);
}

cJSON *v1_exec_action_convertToJSON(v1_exec_action_t *v1_exec_action) {
    cJSON *item = cJSON_CreateObject();

    // v1_exec_action->command
    if(v1_exec_action->command) { 
    cJSON *command = cJSON_AddArrayToObject(item, "command");
    if(command == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *commandListEntry;
    list_ForEach(commandListEntry, v1_exec_action->command) {
    if(cJSON_AddStringToObject(command, "", (char*)commandListEntry->data) == NULL)
    {
        goto fail;
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

v1_exec_action_t *v1_exec_action_parseFromJSON(cJSON *v1_exec_actionJSON){

    v1_exec_action_t *v1_exec_action_local_var = NULL;

    // v1_exec_action->command
    cJSON *command = cJSON_GetObjectItemCaseSensitive(v1_exec_actionJSON, "command");
    list_t *commandList;
    if (command) { 
    cJSON *command_local;
    if(!cJSON_IsArray(command)) {
        goto end;//primitive container
    }
    commandList = list_create();

    cJSON_ArrayForEach(command_local, command)
    {
        if(!cJSON_IsString(command_local))
        {
            goto end;
        }
        list_addElement(commandList , strdup(command_local->valuestring));
    }
    }


    v1_exec_action_local_var = v1_exec_action_create (
        command ? commandList : NULL
        );

    return v1_exec_action_local_var;
end:
    return NULL;

}
