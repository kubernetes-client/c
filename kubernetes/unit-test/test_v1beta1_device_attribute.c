#ifndef v1beta1_device_attribute_TEST
#define v1beta1_device_attribute_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1beta1_device_attribute_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1beta1_device_attribute.h"
v1beta1_device_attribute_t* instantiate_v1beta1_device_attribute(int include_optional);



v1beta1_device_attribute_t* instantiate_v1beta1_device_attribute(int include_optional) {
  v1beta1_device_attribute_t* v1beta1_device_attribute = NULL;
  if (include_optional) {
    v1beta1_device_attribute = v1beta1_device_attribute_create(
      1,
      56,
      "0",
      "0"
    );
  } else {
    v1beta1_device_attribute = v1beta1_device_attribute_create(
      1,
      56,
      "0",
      "0"
    );
  }

  return v1beta1_device_attribute;
}


#ifdef v1beta1_device_attribute_MAIN

void test_v1beta1_device_attribute(int include_optional) {
    v1beta1_device_attribute_t* v1beta1_device_attribute_1 = instantiate_v1beta1_device_attribute(include_optional);

	cJSON* jsonv1beta1_device_attribute_1 = v1beta1_device_attribute_convertToJSON(v1beta1_device_attribute_1);
	printf("v1beta1_device_attribute :\n%s\n", cJSON_Print(jsonv1beta1_device_attribute_1));
	v1beta1_device_attribute_t* v1beta1_device_attribute_2 = v1beta1_device_attribute_parseFromJSON(jsonv1beta1_device_attribute_1);
	cJSON* jsonv1beta1_device_attribute_2 = v1beta1_device_attribute_convertToJSON(v1beta1_device_attribute_2);
	printf("repeating v1beta1_device_attribute:\n%s\n", cJSON_Print(jsonv1beta1_device_attribute_2));
}

int main() {
  test_v1beta1_device_attribute(1);
  test_v1beta1_device_attribute(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1beta1_device_attribute_MAIN
#endif // v1beta1_device_attribute_TEST
