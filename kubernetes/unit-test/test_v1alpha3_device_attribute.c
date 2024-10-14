#ifndef v1alpha3_device_attribute_TEST
#define v1alpha3_device_attribute_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1alpha3_device_attribute_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1alpha3_device_attribute.h"
v1alpha3_device_attribute_t* instantiate_v1alpha3_device_attribute(int include_optional);



v1alpha3_device_attribute_t* instantiate_v1alpha3_device_attribute(int include_optional) {
  v1alpha3_device_attribute_t* v1alpha3_device_attribute = NULL;
  if (include_optional) {
    v1alpha3_device_attribute = v1alpha3_device_attribute_create(
      1,
      56,
      "0",
      "0"
    );
  } else {
    v1alpha3_device_attribute = v1alpha3_device_attribute_create(
      1,
      56,
      "0",
      "0"
    );
  }

  return v1alpha3_device_attribute;
}


#ifdef v1alpha3_device_attribute_MAIN

void test_v1alpha3_device_attribute(int include_optional) {
    v1alpha3_device_attribute_t* v1alpha3_device_attribute_1 = instantiate_v1alpha3_device_attribute(include_optional);

	cJSON* jsonv1alpha3_device_attribute_1 = v1alpha3_device_attribute_convertToJSON(v1alpha3_device_attribute_1);
	printf("v1alpha3_device_attribute :\n%s\n", cJSON_Print(jsonv1alpha3_device_attribute_1));
	v1alpha3_device_attribute_t* v1alpha3_device_attribute_2 = v1alpha3_device_attribute_parseFromJSON(jsonv1alpha3_device_attribute_1);
	cJSON* jsonv1alpha3_device_attribute_2 = v1alpha3_device_attribute_convertToJSON(v1alpha3_device_attribute_2);
	printf("repeating v1alpha3_device_attribute:\n%s\n", cJSON_Print(jsonv1alpha3_device_attribute_2));
}

int main() {
  test_v1alpha3_device_attribute(1);
  test_v1alpha3_device_attribute(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1alpha3_device_attribute_MAIN
#endif // v1alpha3_device_attribute_TEST
