#ifndef v1alpha3_device_TEST
#define v1alpha3_device_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1alpha3_device_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1alpha3_device.h"
v1alpha3_device_t* instantiate_v1alpha3_device(int include_optional);

#include "test_v1alpha3_basic_device.c"


v1alpha3_device_t* instantiate_v1alpha3_device(int include_optional) {
  v1alpha3_device_t* v1alpha3_device = NULL;
  if (include_optional) {
    v1alpha3_device = v1alpha3_device_create(
       // false, not to have infinite recursion
      instantiate_v1alpha3_basic_device(0),
      "0"
    );
  } else {
    v1alpha3_device = v1alpha3_device_create(
      NULL,
      "0"
    );
  }

  return v1alpha3_device;
}


#ifdef v1alpha3_device_MAIN

void test_v1alpha3_device(int include_optional) {
    v1alpha3_device_t* v1alpha3_device_1 = instantiate_v1alpha3_device(include_optional);

	cJSON* jsonv1alpha3_device_1 = v1alpha3_device_convertToJSON(v1alpha3_device_1);
	printf("v1alpha3_device :\n%s\n", cJSON_Print(jsonv1alpha3_device_1));
	v1alpha3_device_t* v1alpha3_device_2 = v1alpha3_device_parseFromJSON(jsonv1alpha3_device_1);
	cJSON* jsonv1alpha3_device_2 = v1alpha3_device_convertToJSON(v1alpha3_device_2);
	printf("repeating v1alpha3_device:\n%s\n", cJSON_Print(jsonv1alpha3_device_2));
}

int main() {
  test_v1alpha3_device(1);
  test_v1alpha3_device(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1alpha3_device_MAIN
#endif // v1alpha3_device_TEST
