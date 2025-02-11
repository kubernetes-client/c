#ifndef v1alpha3_network_device_data_TEST
#define v1alpha3_network_device_data_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1alpha3_network_device_data_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1alpha3_network_device_data.h"
v1alpha3_network_device_data_t* instantiate_v1alpha3_network_device_data(int include_optional);



v1alpha3_network_device_data_t* instantiate_v1alpha3_network_device_data(int include_optional) {
  v1alpha3_network_device_data_t* v1alpha3_network_device_data = NULL;
  if (include_optional) {
    v1alpha3_network_device_data = v1alpha3_network_device_data_create(
      "0",
      "0",
      list_createList()
    );
  } else {
    v1alpha3_network_device_data = v1alpha3_network_device_data_create(
      "0",
      "0",
      list_createList()
    );
  }

  return v1alpha3_network_device_data;
}


#ifdef v1alpha3_network_device_data_MAIN

void test_v1alpha3_network_device_data(int include_optional) {
    v1alpha3_network_device_data_t* v1alpha3_network_device_data_1 = instantiate_v1alpha3_network_device_data(include_optional);

	cJSON* jsonv1alpha3_network_device_data_1 = v1alpha3_network_device_data_convertToJSON(v1alpha3_network_device_data_1);
	printf("v1alpha3_network_device_data :\n%s\n", cJSON_Print(jsonv1alpha3_network_device_data_1));
	v1alpha3_network_device_data_t* v1alpha3_network_device_data_2 = v1alpha3_network_device_data_parseFromJSON(jsonv1alpha3_network_device_data_1);
	cJSON* jsonv1alpha3_network_device_data_2 = v1alpha3_network_device_data_convertToJSON(v1alpha3_network_device_data_2);
	printf("repeating v1alpha3_network_device_data:\n%s\n", cJSON_Print(jsonv1alpha3_network_device_data_2));
}

int main() {
  test_v1alpha3_network_device_data(1);
  test_v1alpha3_network_device_data(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1alpha3_network_device_data_MAIN
#endif // v1alpha3_network_device_data_TEST
