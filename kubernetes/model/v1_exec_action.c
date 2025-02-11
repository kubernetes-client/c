#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_exec_action.h"



static v1_exec_action_t *v1_exec_action_create_internal(
    list_t *command
    ) {
    v1_exec_action_t *v1_exec_action_local_var = malloc(sizeof(v1_exec_action_t));
    if (!v1_exec_action_local_var) {
        return NULL;
    }
    v1_exec_action_local_var->command = command;

    v1_exec_action_local_var->_library_owned = 1;
    return v1_exec_action_local_var;
}

__attribute__((deprecated)) v1_exec_action_t *v1_exec_action_create(
    list_t *command
    ) {
    return v1_exec_action_create_internal (
        command
        );
}

void v1_exec_action_free(v1_exec_action_t *v1_exec_action) {
    if(NULL == v1_exec_action){
        return ;
    }
    if(v1_exec_action->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_exec_action_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_exec_action->command) {
        list_ForEach(listEntry, v1_exec_action->command) {
            free(listEntry->data);
        }
        list_freeList(v1_exec_action->command);
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
    if(cJSON_AddStringToObject(command, "", commandListEntry->data) == NULL)
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

    // define the local list for v1_exec_action->command
    list_t *commandList = NULL;

    // v1_exec_action->command
    cJSON *command = cJSON_GetObjectItemCaseSensitive(v1_exec_actionJSON, "command");
    if (cJSON_IsNull(command)) {
        command = NULL;
    }
    if (command) { 
    cJSON *command_local = NULL;
    if(!cJSON_IsArray(command)) {
        goto end;//primitive container
    }
    commandList = list_createList();

    cJSON_ArrayForEach(command_local, command)
    {
        if(!cJSON_IsString(command_local))
        {
            goto end;
        }
        list_addElement(commandList , strdup(command_local->valuestring));
    }
    }


    v1_exec_action_local_var = v1_exec_action_create_internal (
        command ? commandList : NULL
        );

    return v1_exec_action_local_var;
end:
    if (commandList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, commandList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(commandList);
        commandList = NULL;
    }
    return NULL;

}
