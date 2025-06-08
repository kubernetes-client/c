#ifndef v1beta1_device_sub_request_TEST
#define v1beta1_device_sub_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1beta1_device_sub_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1beta1_device_sub_request.h"
v1beta1_device_sub_request_t* instantiate_v1beta1_device_sub_request(int include_optional);



v1beta1_device_sub_request_t* instantiate_v1beta1_device_sub_request(int include_optional) {
  v1beta1_device_sub_request_t* v1beta1_device_sub_request = NULL;
  if (include_optional) {
    v1beta1_device_sub_request = v1beta1_device_sub_request_create(
      "0",
      56,
      "0",
      "0",
      list_createList(),
      list_createList()
    );
  } else {
    v1beta1_device_sub_request = v1beta1_device_sub_request_create(
      "0",
      56,
      "0",
      "0",
      list_createList(),
      list_createList()
    );
  }

  return v1beta1_device_sub_request;
}


#ifdef v1beta1_device_sub_request_MAIN

void test_v1beta1_device_sub_request(int include_optional) {
    v1beta1_device_sub_request_t* v1beta1_device_sub_request_1 = instantiate_v1beta1_device_sub_request(include_optional);

	cJSON* jsonv1beta1_device_sub_request_1 = v1beta1_device_sub_request_convertToJSON(v1beta1_device_sub_request_1);
	printf("v1beta1_device_sub_request :\n%s\n", cJSON_Print(jsonv1beta1_device_sub_request_1));
	v1beta1_device_sub_request_t* v1beta1_device_sub_request_2 = v1beta1_device_sub_request_parseFromJSON(jsonv1beta1_device_sub_request_1);
	cJSON* jsonv1beta1_device_sub_request_2 = v1beta1_device_sub_request_convertToJSON(v1beta1_device_sub_request_2);
	printf("repeating v1beta1_device_sub_request:\n%s\n", cJSON_Print(jsonv1beta1_device_sub_request_2));
}

int main() {
  test_v1beta1_device_sub_request(1);
  test_v1beta1_device_sub_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1beta1_device_sub_request_MAIN
#endif // v1beta1_device_sub_request_TEST
