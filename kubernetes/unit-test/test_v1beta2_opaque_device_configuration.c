#ifndef v1beta2_opaque_device_configuration_TEST
#define v1beta2_opaque_device_configuration_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1beta2_opaque_device_configuration_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1beta2_opaque_device_configuration.h"
v1beta2_opaque_device_configuration_t* instantiate_v1beta2_opaque_device_configuration(int include_optional);



v1beta2_opaque_device_configuration_t* instantiate_v1beta2_opaque_device_configuration(int include_optional) {
  v1beta2_opaque_device_configuration_t* v1beta2_opaque_device_configuration = NULL;
  if (include_optional) {
    v1beta2_opaque_device_configuration = v1beta2_opaque_device_configuration_create(
      "0",
      0
    );
  } else {
    v1beta2_opaque_device_configuration = v1beta2_opaque_device_configuration_create(
      "0",
      0
    );
  }

  return v1beta2_opaque_device_configuration;
}


#ifdef v1beta2_opaque_device_configuration_MAIN

void test_v1beta2_opaque_device_configuration(int include_optional) {
    v1beta2_opaque_device_configuration_t* v1beta2_opaque_device_configuration_1 = instantiate_v1beta2_opaque_device_configuration(include_optional);

	cJSON* jsonv1beta2_opaque_device_configuration_1 = v1beta2_opaque_device_configuration_convertToJSON(v1beta2_opaque_device_configuration_1);
	printf("v1beta2_opaque_device_configuration :\n%s\n", cJSON_Print(jsonv1beta2_opaque_device_configuration_1));
	v1beta2_opaque_device_configuration_t* v1beta2_opaque_device_configuration_2 = v1beta2_opaque_device_configuration_parseFromJSON(jsonv1beta2_opaque_device_configuration_1);
	cJSON* jsonv1beta2_opaque_device_configuration_2 = v1beta2_opaque_device_configuration_convertToJSON(v1beta2_opaque_device_configuration_2);
	printf("repeating v1beta2_opaque_device_configuration:\n%s\n", cJSON_Print(jsonv1beta2_opaque_device_configuration_2));
}

int main() {
  test_v1beta2_opaque_device_configuration(1);
  test_v1beta2_opaque_device_configuration(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1beta2_opaque_device_configuration_MAIN
#endif // v1beta2_opaque_device_configuration_TEST
