#ifndef v1alpha2_driver_requests_TEST
#define v1alpha2_driver_requests_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1alpha2_driver_requests_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1alpha2_driver_requests.h"
v1alpha2_driver_requests_t* instantiate_v1alpha2_driver_requests(int include_optional);



v1alpha2_driver_requests_t* instantiate_v1alpha2_driver_requests(int include_optional) {
  v1alpha2_driver_requests_t* v1alpha2_driver_requests = NULL;
  if (include_optional) {
    v1alpha2_driver_requests = v1alpha2_driver_requests_create(
      "0",
      list_createList(),
      0
    );
  } else {
    v1alpha2_driver_requests = v1alpha2_driver_requests_create(
      "0",
      list_createList(),
      0
    );
  }

  return v1alpha2_driver_requests;
}


#ifdef v1alpha2_driver_requests_MAIN

void test_v1alpha2_driver_requests(int include_optional) {
    v1alpha2_driver_requests_t* v1alpha2_driver_requests_1 = instantiate_v1alpha2_driver_requests(include_optional);

	cJSON* jsonv1alpha2_driver_requests_1 = v1alpha2_driver_requests_convertToJSON(v1alpha2_driver_requests_1);
	printf("v1alpha2_driver_requests :\n%s\n", cJSON_Print(jsonv1alpha2_driver_requests_1));
	v1alpha2_driver_requests_t* v1alpha2_driver_requests_2 = v1alpha2_driver_requests_parseFromJSON(jsonv1alpha2_driver_requests_1);
	cJSON* jsonv1alpha2_driver_requests_2 = v1alpha2_driver_requests_convertToJSON(v1alpha2_driver_requests_2);
	printf("repeating v1alpha2_driver_requests:\n%s\n", cJSON_Print(jsonv1alpha2_driver_requests_2));
}

int main() {
  test_v1alpha2_driver_requests(1);
  test_v1alpha2_driver_requests(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1alpha2_driver_requests_MAIN
#endif // v1alpha2_driver_requests_TEST
