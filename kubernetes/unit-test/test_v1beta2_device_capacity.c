#ifndef v1beta2_device_capacity_TEST
#define v1beta2_device_capacity_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1beta2_device_capacity_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1beta2_device_capacity.h"
v1beta2_device_capacity_t* instantiate_v1beta2_device_capacity(int include_optional);

#include "test_v1beta2_capacity_request_policy.c"


v1beta2_device_capacity_t* instantiate_v1beta2_device_capacity(int include_optional) {
  v1beta2_device_capacity_t* v1beta2_device_capacity = NULL;
  if (include_optional) {
    v1beta2_device_capacity = v1beta2_device_capacity_create(
       // false, not to have infinite recursion
      instantiate_v1beta2_capacity_request_policy(0),
      "0"
    );
  } else {
    v1beta2_device_capacity = v1beta2_device_capacity_create(
      NULL,
      "0"
    );
  }

  return v1beta2_device_capacity;
}


#ifdef v1beta2_device_capacity_MAIN

void test_v1beta2_device_capacity(int include_optional) {
    v1beta2_device_capacity_t* v1beta2_device_capacity_1 = instantiate_v1beta2_device_capacity(include_optional);

	cJSON* jsonv1beta2_device_capacity_1 = v1beta2_device_capacity_convertToJSON(v1beta2_device_capacity_1);
	printf("v1beta2_device_capacity :\n%s\n", cJSON_Print(jsonv1beta2_device_capacity_1));
	v1beta2_device_capacity_t* v1beta2_device_capacity_2 = v1beta2_device_capacity_parseFromJSON(jsonv1beta2_device_capacity_1);
	cJSON* jsonv1beta2_device_capacity_2 = v1beta2_device_capacity_convertToJSON(v1beta2_device_capacity_2);
	printf("repeating v1beta2_device_capacity:\n%s\n", cJSON_Print(jsonv1beta2_device_capacity_2));
}

int main() {
  test_v1beta2_device_capacity(1);
  test_v1beta2_device_capacity(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1beta2_device_capacity_MAIN
#endif // v1beta2_device_capacity_TEST
