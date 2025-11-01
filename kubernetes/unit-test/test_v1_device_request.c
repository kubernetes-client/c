#ifndef v1_device_request_TEST
#define v1_device_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_device_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_device_request.h"
v1_device_request_t* instantiate_v1_device_request(int include_optional);

#include "test_v1_exact_device_request.c"


v1_device_request_t* instantiate_v1_device_request(int include_optional) {
  v1_device_request_t* v1_device_request = NULL;
  if (include_optional) {
    v1_device_request = v1_device_request_create(
       // false, not to have infinite recursion
      instantiate_v1_exact_device_request(0),
      list_createList(),
      "0"
    );
  } else {
    v1_device_request = v1_device_request_create(
      NULL,
      list_createList(),
      "0"
    );
  }

  return v1_device_request;
}


#ifdef v1_device_request_MAIN

void test_v1_device_request(int include_optional) {
    v1_device_request_t* v1_device_request_1 = instantiate_v1_device_request(include_optional);

	cJSON* jsonv1_device_request_1 = v1_device_request_convertToJSON(v1_device_request_1);
	printf("v1_device_request :\n%s\n", cJSON_Print(jsonv1_device_request_1));
	v1_device_request_t* v1_device_request_2 = v1_device_request_parseFromJSON(jsonv1_device_request_1);
	cJSON* jsonv1_device_request_2 = v1_device_request_convertToJSON(v1_device_request_2);
	printf("repeating v1_device_request:\n%s\n", cJSON_Print(jsonv1_device_request_2));
}

int main() {
  test_v1_device_request(1);
  test_v1_device_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_device_request_MAIN
#endif // v1_device_request_TEST
