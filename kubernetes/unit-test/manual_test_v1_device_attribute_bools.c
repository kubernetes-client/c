// Self-check for boolean primitive lists: parse -> inspect -> serialize -> free.
// Build: gcc manual_test_v1_device_attribute_bools.c -I.. -L../build -lkubernetes -lyaml -lwebsockets
#include <assert.h>
#include <stdio.h>
#include "../external/cJSON.h"
#include "../model/v1_device_attribute.h"

int main(void) {
    cJSON *in = cJSON_Parse("{\"bools\":[true,false,true]}");
    assert(in);

    v1_device_attribute_t *attr = v1_device_attribute_parseFromJSON(in);
    assert(attr && attr->bools);
    assert(attr->bools->count == 3);

    int expected[] = {1, 0, 1};
    int i = 0;
    listEntry_t *entry;
    list_ForEach(entry, attr->bools) {
        assert(*(cJSON_bool *)entry->data == expected[i]);
        i++;
    }

    cJSON *out = v1_device_attribute_convertToJSON(attr);
    assert(out);
    cJSON *arr = cJSON_GetObjectItemCaseSensitive(out, "bools");
    assert(cJSON_IsArray(arr) && cJSON_GetArraySize(arr) == 3);
    assert(cJSON_IsTrue(cJSON_GetArrayItem(arr, 0)));
    assert(cJSON_IsFalse(cJSON_GetArrayItem(arr, 1)));
    assert(cJSON_IsTrue(cJSON_GetArrayItem(arr, 2)));

    v1_device_attribute_free(attr);
    cJSON_Delete(out);
    cJSON_Delete(in);
    printf("manual_test_v1_device_attribute_bools: OK\n");
    return 0;
}
