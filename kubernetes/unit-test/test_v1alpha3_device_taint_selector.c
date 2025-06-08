#ifndef v1alpha3_device_taint_selector_TEST
#define v1alpha3_device_taint_selector_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1alpha3_device_taint_selector_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1alpha3_device_taint_selector.h"
v1alpha3_device_taint_selector_t* instantiate_v1alpha3_device_taint_selector(int include_optional);



v1alpha3_device_taint_selector_t* instantiate_v1alpha3_device_taint_selector(int include_optional) {
  v1alpha3_device_taint_selector_t* v1alpha3_device_taint_selector = NULL;
  if (include_optional) {
    v1alpha3_device_taint_selector = v1alpha3_device_taint_selector_create(
      "0",
      "0",
      "0",
      "0",
      list_createList()
    );
  } else {
    v1alpha3_device_taint_selector = v1alpha3_device_taint_selector_create(
      "0",
      "0",
      "0",
      "0",
      list_createList()
    );
  }

  return v1alpha3_device_taint_selector;
}


#ifdef v1alpha3_device_taint_selector_MAIN

void test_v1alpha3_device_taint_selector(int include_optional) {
    v1alpha3_device_taint_selector_t* v1alpha3_device_taint_selector_1 = instantiate_v1alpha3_device_taint_selector(include_optional);

	cJSON* jsonv1alpha3_device_taint_selector_1 = v1alpha3_device_taint_selector_convertToJSON(v1alpha3_device_taint_selector_1);
	printf("v1alpha3_device_taint_selector :\n%s\n", cJSON_Print(jsonv1alpha3_device_taint_selector_1));
	v1alpha3_device_taint_selector_t* v1alpha3_device_taint_selector_2 = v1alpha3_device_taint_selector_parseFromJSON(jsonv1alpha3_device_taint_selector_1);
	cJSON* jsonv1alpha3_device_taint_selector_2 = v1alpha3_device_taint_selector_convertToJSON(v1alpha3_device_taint_selector_2);
	printf("repeating v1alpha3_device_taint_selector:\n%s\n", cJSON_Print(jsonv1alpha3_device_taint_selector_2));
}

int main() {
  test_v1alpha3_device_taint_selector(1);
  test_v1alpha3_device_taint_selector(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1alpha3_device_taint_selector_MAIN
#endif // v1alpha3_device_taint_selector_TEST
