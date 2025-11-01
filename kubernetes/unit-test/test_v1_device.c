#ifndef v1_device_TEST
#define v1_device_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_device_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_device.h"
v1_device_t* instantiate_v1_device(int include_optional);

#include "test_v1_node_selector.c"


v1_device_t* instantiate_v1_device(int include_optional) {
  v1_device_t* v1_device = NULL;
  if (include_optional) {
    v1_device = v1_device_create(
      1,
      1,
      list_createList(),
      list_createList(),
      list_createList(),
      1,
      list_createList(),
      list_createList(),
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_v1_node_selector(0),
      list_createList()
    );
  } else {
    v1_device = v1_device_create(
      1,
      1,
      list_createList(),
      list_createList(),
      list_createList(),
      1,
      list_createList(),
      list_createList(),
      "0",
      "0",
      NULL,
      list_createList()
    );
  }

  return v1_device;
}


#ifdef v1_device_MAIN

void test_v1_device(int include_optional) {
    v1_device_t* v1_device_1 = instantiate_v1_device(include_optional);

	cJSON* jsonv1_device_1 = v1_device_convertToJSON(v1_device_1);
	printf("v1_device :\n%s\n", cJSON_Print(jsonv1_device_1));
	v1_device_t* v1_device_2 = v1_device_parseFromJSON(jsonv1_device_1);
	cJSON* jsonv1_device_2 = v1_device_convertToJSON(v1_device_2);
	printf("repeating v1_device:\n%s\n", cJSON_Print(jsonv1_device_2));
}

int main() {
  test_v1_device(1);
  test_v1_device(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_device_MAIN
#endif // v1_device_TEST
