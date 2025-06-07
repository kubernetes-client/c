#ifndef v1beta1_device_counter_consumption_TEST
#define v1beta1_device_counter_consumption_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1beta1_device_counter_consumption_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1beta1_device_counter_consumption.h"
v1beta1_device_counter_consumption_t* instantiate_v1beta1_device_counter_consumption(int include_optional);



v1beta1_device_counter_consumption_t* instantiate_v1beta1_device_counter_consumption(int include_optional) {
  v1beta1_device_counter_consumption_t* v1beta1_device_counter_consumption = NULL;
  if (include_optional) {
    v1beta1_device_counter_consumption = v1beta1_device_counter_consumption_create(
      "0",
      list_createList()
    );
  } else {
    v1beta1_device_counter_consumption = v1beta1_device_counter_consumption_create(
      "0",
      list_createList()
    );
  }

  return v1beta1_device_counter_consumption;
}


#ifdef v1beta1_device_counter_consumption_MAIN

void test_v1beta1_device_counter_consumption(int include_optional) {
    v1beta1_device_counter_consumption_t* v1beta1_device_counter_consumption_1 = instantiate_v1beta1_device_counter_consumption(include_optional);

	cJSON* jsonv1beta1_device_counter_consumption_1 = v1beta1_device_counter_consumption_convertToJSON(v1beta1_device_counter_consumption_1);
	printf("v1beta1_device_counter_consumption :\n%s\n", cJSON_Print(jsonv1beta1_device_counter_consumption_1));
	v1beta1_device_counter_consumption_t* v1beta1_device_counter_consumption_2 = v1beta1_device_counter_consumption_parseFromJSON(jsonv1beta1_device_counter_consumption_1);
	cJSON* jsonv1beta1_device_counter_consumption_2 = v1beta1_device_counter_consumption_convertToJSON(v1beta1_device_counter_consumption_2);
	printf("repeating v1beta1_device_counter_consumption:\n%s\n", cJSON_Print(jsonv1beta1_device_counter_consumption_2));
}

int main() {
  test_v1beta1_device_counter_consumption(1);
  test_v1beta1_device_counter_consumption(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1beta1_device_counter_consumption_MAIN
#endif // v1beta1_device_counter_consumption_TEST
