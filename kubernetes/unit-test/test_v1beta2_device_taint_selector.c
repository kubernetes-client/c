#ifndef v1beta2_device_taint_selector_TEST
#define v1beta2_device_taint_selector_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1beta2_device_taint_selector_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1beta2_device_taint_selector.h"
v1beta2_device_taint_selector_t* instantiate_v1beta2_device_taint_selector(int include_optional);



v1beta2_device_taint_selector_t* instantiate_v1beta2_device_taint_selector(int include_optional) {
  v1beta2_device_taint_selector_t* v1beta2_device_taint_selector = NULL;
  if (include_optional) {
    v1beta2_device_taint_selector = v1beta2_device_taint_selector_create(
      "0",
      "0",
      "0"
    );
  } else {
    v1beta2_device_taint_selector = v1beta2_device_taint_selector_create(
      "0",
      "0",
      "0"
    );
  }

  return v1beta2_device_taint_selector;
}


#ifdef v1beta2_device_taint_selector_MAIN

void test_v1beta2_device_taint_selector(int include_optional) {
    v1beta2_device_taint_selector_t* v1beta2_device_taint_selector_1 = instantiate_v1beta2_device_taint_selector(include_optional);

	cJSON* jsonv1beta2_device_taint_selector_1 = v1beta2_device_taint_selector_convertToJSON(v1beta2_device_taint_selector_1);
	printf("v1beta2_device_taint_selector :\n%s\n", cJSON_Print(jsonv1beta2_device_taint_selector_1));
	v1beta2_device_taint_selector_t* v1beta2_device_taint_selector_2 = v1beta2_device_taint_selector_parseFromJSON(jsonv1beta2_device_taint_selector_1);
	cJSON* jsonv1beta2_device_taint_selector_2 = v1beta2_device_taint_selector_convertToJSON(v1beta2_device_taint_selector_2);
	printf("repeating v1beta2_device_taint_selector:\n%s\n", cJSON_Print(jsonv1beta2_device_taint_selector_2));
}

int main() {
  test_v1beta2_device_taint_selector(1);
  test_v1beta2_device_taint_selector(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1beta2_device_taint_selector_MAIN
#endif // v1beta2_device_taint_selector_TEST
