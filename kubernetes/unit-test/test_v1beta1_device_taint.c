#ifndef v1beta1_device_taint_TEST
#define v1beta1_device_taint_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1beta1_device_taint_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1beta1_device_taint.h"
v1beta1_device_taint_t* instantiate_v1beta1_device_taint(int include_optional);



v1beta1_device_taint_t* instantiate_v1beta1_device_taint(int include_optional) {
  v1beta1_device_taint_t* v1beta1_device_taint = NULL;
  if (include_optional) {
    v1beta1_device_taint = v1beta1_device_taint_create(
      "0",
      "0",
      "2013-10-20T19:20:30+01:00",
      "0"
    );
  } else {
    v1beta1_device_taint = v1beta1_device_taint_create(
      "0",
      "0",
      "2013-10-20T19:20:30+01:00",
      "0"
    );
  }

  return v1beta1_device_taint;
}


#ifdef v1beta1_device_taint_MAIN

void test_v1beta1_device_taint(int include_optional) {
    v1beta1_device_taint_t* v1beta1_device_taint_1 = instantiate_v1beta1_device_taint(include_optional);

	cJSON* jsonv1beta1_device_taint_1 = v1beta1_device_taint_convertToJSON(v1beta1_device_taint_1);
	printf("v1beta1_device_taint :\n%s\n", cJSON_Print(jsonv1beta1_device_taint_1));
	v1beta1_device_taint_t* v1beta1_device_taint_2 = v1beta1_device_taint_parseFromJSON(jsonv1beta1_device_taint_1);
	cJSON* jsonv1beta1_device_taint_2 = v1beta1_device_taint_convertToJSON(v1beta1_device_taint_2);
	printf("repeating v1beta1_device_taint:\n%s\n", cJSON_Print(jsonv1beta1_device_taint_2));
}

int main() {
  test_v1beta1_device_taint(1);
  test_v1beta1_device_taint(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1beta1_device_taint_MAIN
#endif // v1beta1_device_taint_TEST
