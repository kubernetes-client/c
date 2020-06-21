#ifndef v1beta1_endpoint_TEST
#define v1beta1_endpoint_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1beta1_endpoint_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1beta1_endpoint.h"
v1beta1_endpoint_t* instantiate_v1beta1_endpoint(int include_optional);

#include "test_v1beta1_endpoint_conditions.c"
#include "test_v1_object_reference.c"


v1beta1_endpoint_t* instantiate_v1beta1_endpoint(int include_optional) {
  v1beta1_endpoint_t* v1beta1_endpoint = NULL;
  if (include_optional) {
    v1beta1_endpoint = v1beta1_endpoint_create(
      list_create(),
       // false, not to have infinite recursion
      instantiate_v1beta1_endpoint_conditions(0),
      "0",
       // false, not to have infinite recursion
      instantiate_v1_object_reference(0),
      list_create()
    );
  } else {
    v1beta1_endpoint = v1beta1_endpoint_create(
      list_create(),
      NULL,
      "0",
      NULL,
      list_create()
    );
  }

  return v1beta1_endpoint;
}


#ifdef v1beta1_endpoint_MAIN

void test_v1beta1_endpoint(int include_optional) {
    v1beta1_endpoint_t* v1beta1_endpoint_1 = instantiate_v1beta1_endpoint(include_optional);

	cJSON* jsonv1beta1_endpoint_1 = v1beta1_endpoint_convertToJSON(v1beta1_endpoint_1);
	printf("v1beta1_endpoint :\n%s\n", cJSON_Print(jsonv1beta1_endpoint_1));
	v1beta1_endpoint_t* v1beta1_endpoint_2 = v1beta1_endpoint_parseFromJSON(jsonv1beta1_endpoint_1);
	cJSON* jsonv1beta1_endpoint_2 = v1beta1_endpoint_convertToJSON(v1beta1_endpoint_2);
	printf("repeating v1beta1_endpoint:\n%s\n", cJSON_Print(jsonv1beta1_endpoint_2));
}

int main() {
  test_v1beta1_endpoint(1);
  test_v1beta1_endpoint(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1beta1_endpoint_MAIN
#endif // v1beta1_endpoint_TEST
