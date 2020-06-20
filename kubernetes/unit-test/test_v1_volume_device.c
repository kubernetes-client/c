#ifndef v1_volume_device_TEST
#define v1_volume_device_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_volume_device_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_volume_device.h"
v1_volume_device_t* instantiate_v1_volume_device(int include_optional);



v1_volume_device_t* instantiate_v1_volume_device(int include_optional) {
  v1_volume_device_t* v1_volume_device = NULL;
  if (include_optional) {
    v1_volume_device = v1_volume_device_create(
      "0",
      "0"
    );
  } else {
    v1_volume_device = v1_volume_device_create(
      "0",
      "0"
    );
  }

  return v1_volume_device;
}


#ifdef v1_volume_device_MAIN

void test_v1_volume_device(int include_optional) {
    v1_volume_device_t* v1_volume_device_1 = instantiate_v1_volume_device(include_optional);

	cJSON* jsonv1_volume_device_1 = v1_volume_device_convertToJSON(v1_volume_device_1);
	printf("v1_volume_device :\n%s\n", cJSON_Print(jsonv1_volume_device_1));
	v1_volume_device_t* v1_volume_device_2 = v1_volume_device_parseFromJSON(jsonv1_volume_device_1);
	cJSON* jsonv1_volume_device_2 = v1_volume_device_convertToJSON(v1_volume_device_2);
	printf("repeating v1_volume_device:\n%s\n", cJSON_Print(jsonv1_volume_device_2));
}

int main() {
  test_v1_volume_device(1);
  test_v1_volume_device(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_volume_device_MAIN
#endif // v1_volume_device_TEST
