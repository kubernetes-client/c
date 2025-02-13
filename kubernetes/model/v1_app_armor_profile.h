/*
 * v1_app_armor_profile.h
 *
 * AppArmorProfile defines a pod or container&#39;s AppArmor settings.
 */

#ifndef _v1_app_armor_profile_H_
#define _v1_app_armor_profile_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_app_armor_profile_t v1_app_armor_profile_t;




typedef struct v1_app_armor_profile_t {
    char *localhost_profile; // string
    char *type; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1_app_armor_profile_t;

__attribute__((deprecated)) v1_app_armor_profile_t *v1_app_armor_profile_create(
    char *localhost_profile,
    char *type
);

void v1_app_armor_profile_free(v1_app_armor_profile_t *v1_app_armor_profile);

v1_app_armor_profile_t *v1_app_armor_profile_parseFromJSON(cJSON *v1_app_armor_profileJSON);

cJSON *v1_app_armor_profile_convertToJSON(v1_app_armor_profile_t *v1_app_armor_profile);

#endif /* _v1_app_armor_profile_H_ */

