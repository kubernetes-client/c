#ifndef v1_endpoint_TEST
#define v1_endpoint_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_endpoint_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_endpoint.h"
v1_endpoint_t* instantiate_v1_endpoint(int include_optional);

#include "test_v1_endpoint_conditions.c"
#include "test_v1_endpoint_hints.c"
#include "test_v1_object_reference.c"


v1_endpoint_t* instantiate_v1_endpoint(int include_optional) {
  v1_endpoint_t* v1_endpoint = NULL;
  if (include_optional) {
    v1_endpoint = v1_endpoint_create(
      list_create(),
       // false, not to have infinite recursion
      instantiate_v1_endpoint_conditions(0),
      list_create(),
       // false, not to have infinite recursion
      instantiate_v1_endpoint_hints(0),
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_v1_object_reference(0),
      "0"
    );
  } else {
    v1_endpoint = v1_endpoint_create(
      list_create(),
      NULL,
      list_create(),
      NULL,
      "0",
      "0",
      NULL,
      "0"
    );
  }

  return v1_endpoint;
}


#ifdef v1_endpoint_MAIN

void test_v1_endpoint(int include_optional) {
    v1_endpoint_t* v1_endpoint_1 = instantiate_v1_endpoint(include_optional);

	cJSON* jsonv1_endpoint_1 = v1_endpoint_convertToJSON(v1_endpoint_1);
	printf("v1_endpoint :\n%s\n", cJSON_Print(jsonv1_endpoint_1));
	v1_endpoint_t* v1_endpoint_2 = v1_endpoint_parseFromJSON(jsonv1_endpoint_1);
	cJSON* jsonv1_endpoint_2 = v1_endpoint_convertToJSON(v1_endpoint_2);
	printf("repeating v1_endpoint:\n%s\n", cJSON_Print(jsonv1_endpoint_2));
}

int main() {
  test_v1_endpoint(1);
  test_v1_endpoint(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_endpoint_MAIN
#endif // v1_endpoint_TEST
