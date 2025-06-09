#ifndef v1beta2_network_device_data_TEST
#define v1beta2_network_device_data_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1beta2_network_device_data_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1beta2_network_device_data.h"
v1beta2_network_device_data_t* instantiate_v1beta2_network_device_data(int include_optional);



v1beta2_network_device_data_t* instantiate_v1beta2_network_device_data(int include_optional) {
  v1beta2_network_device_data_t* v1beta2_network_device_data = NULL;
  if (include_optional) {
    v1beta2_network_device_data = v1beta2_network_device_data_create(
      "0",
      "0",
      list_createList()
    );
  } else {
    v1beta2_network_device_data = v1beta2_network_device_data_create(
      "0",
      "0",
      list_createList()
    );
  }

  return v1beta2_network_device_data;
}


#ifdef v1beta2_network_device_data_MAIN

void test_v1beta2_network_device_data(int include_optional) {
    v1beta2_network_device_data_t* v1beta2_network_device_data_1 = instantiate_v1beta2_network_device_data(include_optional);

	cJSON* jsonv1beta2_network_device_data_1 = v1beta2_network_device_data_convertToJSON(v1beta2_network_device_data_1);
	printf("v1beta2_network_device_data :\n%s\n", cJSON_Print(jsonv1beta2_network_device_data_1));
	v1beta2_network_device_data_t* v1beta2_network_device_data_2 = v1beta2_network_device_data_parseFromJSON(jsonv1beta2_network_device_data_1);
	cJSON* jsonv1beta2_network_device_data_2 = v1beta2_network_device_data_convertToJSON(v1beta2_network_device_data_2);
	printf("repeating v1beta2_network_device_data:\n%s\n", cJSON_Print(jsonv1beta2_network_device_data_2));
}

int main() {
  test_v1beta2_network_device_data(1);
  test_v1beta2_network_device_data(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1beta2_network_device_data_MAIN
#endif // v1beta2_network_device_data_TEST
