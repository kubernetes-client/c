#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "int_or_string.h"

int_or_string_t *int_or_string_create()
{
    int_or_string_t *ios = calloc(sizeof(int_or_string_t), 1);
    if (!ios) {
        return NULL;
    }
    ios->type = IOS_DATA_TYPE_INT;
    ios->s = NULL;
    return ios;
}

void int_or_string_free(int_or_string_t * ios)
{
    if (!ios) {
        return;
    }
    if (IOS_DATA_TYPE_STRING == ios->type && ios->s) {
        free(ios->s);
        ios->s = NULL;
    }
    free(ios);
}

cJSON *int_or_string_convertToJSON(int_or_string_t * ios)
{
    if (IOS_DATA_TYPE_INT == ios->type) {
        return cJSON_CreateNumber(ios->i);
    }
    if (IOS_DATA_TYPE_STRING == ios->type && ios->s) {
        return cJSON_CreateString(ios->s);
    }
    return NULL;
}

int_or_string_t *int_or_string_parseFromJSON(cJSON * cjson)
{
    int_or_string_t *ios = int_or_string_create();
    if (!ios) {
        return NULL;
    }
    if (cJSON_IsNumber(cjson)) {
        ios->i = cjson->valuedouble;
        ios->type = IOS_DATA_TYPE_INT;
        return ios;
    }
    if (cJSON_IsString(cjson)) {
        ios->s = strdup(cjson->valuestring);
        ios->type = IOS_DATA_TYPE_STRING;
        return ios;
    }
    if (ios) {
        int_or_string_free(ios);
        ios = NULL;
    }
    return NULL;
}
