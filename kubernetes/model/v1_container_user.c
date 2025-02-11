#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_container_user.h"



static v1_container_user_t *v1_container_user_create_internal(
    v1_linux_container_user_t *_linux
    ) {
    v1_container_user_t *v1_container_user_local_var = malloc(sizeof(v1_container_user_t));
    if (!v1_container_user_local_var) {
        return NULL;
    }
    v1_container_user_local_var->_linux = _linux;

    v1_container_user_local_var->_library_owned = 1;
    return v1_container_user_local_var;
}

__attribute__((deprecated)) v1_container_user_t *v1_container_user_create(
    v1_linux_container_user_t *_linux
    ) {
    return v1_container_user_create_internal (
        _linux
        );
}

void v1_container_user_free(v1_container_user_t *v1_container_user) {
    if(NULL == v1_container_user){
        return ;
    }
    if(v1_container_user->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_container_user_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_container_user->_linux) {
        v1_linux_container_user_free(v1_container_user->_linux);
        v1_container_user->_linux = NULL;
    }
    free(v1_container_user);
}

cJSON *v1_container_user_convertToJSON(v1_container_user_t *v1_container_user) {
    cJSON *item = cJSON_CreateObject();

    // v1_container_user->_linux
    if(v1_container_user->_linux) {
    cJSON *_linux_local_JSON = v1_linux_container_user_convertToJSON(v1_container_user->_linux);
    if(_linux_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "linux", _linux_local_JSON);
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

v1_container_user_t *v1_container_user_parseFromJSON(cJSON *v1_container_userJSON){

    v1_container_user_t *v1_container_user_local_var = NULL;

    // define the local variable for v1_container_user->_linux
    v1_linux_container_user_t *_linux_local_nonprim = NULL;

    // v1_container_user->_linux
    cJSON *_linux = cJSON_GetObjectItemCaseSensitive(v1_container_userJSON, "linux");
    if (cJSON_IsNull(_linux)) {
        _linux = NULL;
    }
    if (_linux) { 
    _linux_local_nonprim = v1_linux_container_user_parseFromJSON(_linux); //nonprimitive
    }


    v1_container_user_local_var = v1_container_user_create_internal (
        _linux ? _linux_local_nonprim : NULL
        );

    return v1_container_user_local_var;
end:
    if (_linux_local_nonprim) {
        v1_linux_container_user_free(_linux_local_nonprim);
        _linux_local_nonprim = NULL;
    }
    return NULL;

}
