#ifndef v1beta2_device_class_TEST
#define v1beta2_device_class_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1beta2_device_class_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1beta2_device_class.h"
v1beta2_device_class_t* instantiate_v1beta2_device_class(int include_optional);

#include "test_v1_object_meta.c"
#include "test_v1beta2_device_class_spec.c"


v1beta2_device_class_t* instantiate_v1beta2_device_class(int include_optional) {
  v1beta2_device_class_t* v1beta2_device_class = NULL;
  if (include_optional) {
    v1beta2_device_class = v1beta2_device_class_create(
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_v1_object_meta(0),
       // false, not to have infinite recursion
      instantiate_v1beta2_device_class_spec(0)
    );
  } else {
    v1beta2_device_class = v1beta2_device_class_create(
      "0",
      "0",
      NULL,
      NULL
    );
  }

  return v1beta2_device_class;
}


#ifdef v1beta2_device_class_MAIN

void test_v1beta2_device_class(int include_optional) {
    v1beta2_device_class_t* v1beta2_device_class_1 = instantiate_v1beta2_device_class(include_optional);

	cJSON* jsonv1beta2_device_class_1 = v1beta2_device_class_convertToJSON(v1beta2_device_class_1);
	printf("v1beta2_device_class :\n%s\n", cJSON_Print(jsonv1beta2_device_class_1));
	v1beta2_device_class_t* v1beta2_device_class_2 = v1beta2_device_class_parseFromJSON(jsonv1beta2_device_class_1);
	cJSON* jsonv1beta2_device_class_2 = v1beta2_device_class_convertToJSON(v1beta2_device_class_2);
	printf("repeating v1beta2_device_class:\n%s\n", cJSON_Print(jsonv1beta2_device_class_2));
}

int main() {
  test_v1beta2_device_class(1);
  test_v1beta2_device_class(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1beta2_device_class_MAIN
#endif // v1beta2_device_class_TEST
