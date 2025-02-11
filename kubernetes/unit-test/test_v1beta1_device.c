#ifndef v1beta1_device_TEST
#define v1beta1_device_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1beta1_device_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1beta1_device.h"
v1beta1_device_t* instantiate_v1beta1_device(int include_optional);

#include "test_v1beta1_basic_device.c"


v1beta1_device_t* instantiate_v1beta1_device(int include_optional) {
  v1beta1_device_t* v1beta1_device = NULL;
  if (include_optional) {
    v1beta1_device = v1beta1_device_create(
       // false, not to have infinite recursion
      instantiate_v1beta1_basic_device(0),
      "0"
    );
  } else {
    v1beta1_device = v1beta1_device_create(
      NULL,
      "0"
    );
  }

  return v1beta1_device;
}


#ifdef v1beta1_device_MAIN

void test_v1beta1_device(int include_optional) {
    v1beta1_device_t* v1beta1_device_1 = instantiate_v1beta1_device(include_optional);

	cJSON* jsonv1beta1_device_1 = v1beta1_device_convertToJSON(v1beta1_device_1);
	printf("v1beta1_device :\n%s\n", cJSON_Print(jsonv1beta1_device_1));
	v1beta1_device_t* v1beta1_device_2 = v1beta1_device_parseFromJSON(jsonv1beta1_device_1);
	cJSON* jsonv1beta1_device_2 = v1beta1_device_convertToJSON(v1beta1_device_2);
	printf("repeating v1beta1_device:\n%s\n", cJSON_Print(jsonv1beta1_device_2));
}

int main() {
  test_v1beta1_device(1);
  test_v1beta1_device(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1beta1_device_MAIN
#endif // v1beta1_device_TEST
