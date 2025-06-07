#ifndef v1alpha3_device_sub_request_TEST
#define v1alpha3_device_sub_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1alpha3_device_sub_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1alpha3_device_sub_request.h"
v1alpha3_device_sub_request_t* instantiate_v1alpha3_device_sub_request(int include_optional);



v1alpha3_device_sub_request_t* instantiate_v1alpha3_device_sub_request(int include_optional) {
  v1alpha3_device_sub_request_t* v1alpha3_device_sub_request = NULL;
  if (include_optional) {
    v1alpha3_device_sub_request = v1alpha3_device_sub_request_create(
      "0",
      56,
      "0",
      "0",
      list_createList(),
      list_createList()
    );
  } else {
    v1alpha3_device_sub_request = v1alpha3_device_sub_request_create(
      "0",
      56,
      "0",
      "0",
      list_createList(),
      list_createList()
    );
  }

  return v1alpha3_device_sub_request;
}


#ifdef v1alpha3_device_sub_request_MAIN

void test_v1alpha3_device_sub_request(int include_optional) {
    v1alpha3_device_sub_request_t* v1alpha3_device_sub_request_1 = instantiate_v1alpha3_device_sub_request(include_optional);

	cJSON* jsonv1alpha3_device_sub_request_1 = v1alpha3_device_sub_request_convertToJSON(v1alpha3_device_sub_request_1);
	printf("v1alpha3_device_sub_request :\n%s\n", cJSON_Print(jsonv1alpha3_device_sub_request_1));
	v1alpha3_device_sub_request_t* v1alpha3_device_sub_request_2 = v1alpha3_device_sub_request_parseFromJSON(jsonv1alpha3_device_sub_request_1);
	cJSON* jsonv1alpha3_device_sub_request_2 = v1alpha3_device_sub_request_convertToJSON(v1alpha3_device_sub_request_2);
	printf("repeating v1alpha3_device_sub_request:\n%s\n", cJSON_Print(jsonv1alpha3_device_sub_request_2));
}

int main() {
  test_v1alpha3_device_sub_request(1);
  test_v1alpha3_device_sub_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1alpha3_device_sub_request_MAIN
#endif // v1alpha3_device_sub_request_TEST
