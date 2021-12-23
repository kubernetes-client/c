/*
 * int_or_string.h
 */

#ifndef _INT_OR_STRING_H_
#define _INT_OR_STRING_H_

#include <string.h>
#include "../external/cJSON.h"

#ifdef  __cplusplus
extern "C" {
#endif

typedef enum {
    IOS_DATA_TYPE_INT = 1,
    IOS_DATA_TYPE_STRING = 2
} ios_data_type_t;

typedef struct int_or_string_t {
    ios_data_type_t type;
    union {
        int i;
        char *s;
    };
} int_or_string_t;

int_or_string_t *int_or_string_create();

void int_or_string_free(int_or_string_t *ios);

int_or_string_t *int_or_string_parseFromJSON(cJSON *cjson);

cJSON *int_or_string_convertToJSON(int_or_string_t *ios);

#ifdef  __cplusplus
}
#endif

#endif /* _INT_OR_STRING_H_ */
