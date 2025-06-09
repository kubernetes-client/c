#ifndef v1beta1_device_toleration_TEST
#define v1beta1_device_toleration_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1beta1_device_toleration_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1beta1_device_toleration.h"
v1beta1_device_toleration_t* instantiate_v1beta1_device_toleration(int include_optional);



v1beta1_device_toleration_t* instantiate_v1beta1_device_toleration(int include_optional) {
  v1beta1_device_toleration_t* v1beta1_device_toleration = NULL;
  if (include_optional) {
    v1beta1_device_toleration = v1beta1_device_toleration_create(
      "0",
      "0",
      "0",
      56,
      "0"
    );
  } else {
    v1beta1_device_toleration = v1beta1_device_toleration_create(
      "0",
      "0",
      "0",
      56,
      "0"
    );
  }

  return v1beta1_device_toleration;
}


#ifdef v1beta1_device_toleration_MAIN

void test_v1beta1_device_toleration(int include_optional) {
    v1beta1_device_toleration_t* v1beta1_device_toleration_1 = instantiate_v1beta1_device_toleration(include_optional);

	cJSON* jsonv1beta1_device_toleration_1 = v1beta1_device_toleration_convertToJSON(v1beta1_device_toleration_1);
	printf("v1beta1_device_toleration :\n%s\n", cJSON_Print(jsonv1beta1_device_toleration_1));
	v1beta1_device_toleration_t* v1beta1_device_toleration_2 = v1beta1_device_toleration_parseFromJSON(jsonv1beta1_device_toleration_1);
	cJSON* jsonv1beta1_device_toleration_2 = v1beta1_device_toleration_convertToJSON(v1beta1_device_toleration_2);
	printf("repeating v1beta1_device_toleration:\n%s\n", cJSON_Print(jsonv1beta1_device_toleration_2));
}

int main() {
  test_v1beta1_device_toleration(1);
  test_v1beta1_device_toleration(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1beta1_device_toleration_MAIN
#endif // v1beta1_device_toleration_TEST
