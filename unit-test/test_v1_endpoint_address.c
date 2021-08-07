#ifndef v1_endpoint_address_TEST
#define v1_endpoint_address_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_endpoint_address_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_endpoint_address.h"
v1_endpoint_address_t* instantiate_v1_endpoint_address(int include_optional);

#include "test_v1_object_reference.c"


v1_endpoint_address_t* instantiate_v1_endpoint_address(int include_optional) {
  v1_endpoint_address_t* v1_endpoint_address = NULL;
  if (include_optional) {
    v1_endpoint_address = v1_endpoint_address_create(
      "0",
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_v1_object_reference(0)
    );
  } else {
    v1_endpoint_address = v1_endpoint_address_create(
      "0",
      "0",
      "0",
      NULL
    );
  }

  return v1_endpoint_address;
}


#ifdef v1_endpoint_address_MAIN

void test_v1_endpoint_address(int include_optional) {
    v1_endpoint_address_t* v1_endpoint_address_1 = instantiate_v1_endpoint_address(include_optional);

	cJSON* jsonv1_endpoint_address_1 = v1_endpoint_address_convertToJSON(v1_endpoint_address_1);
	printf("v1_endpoint_address :\n%s\n", cJSON_Print(jsonv1_endpoint_address_1));
	v1_endpoint_address_t* v1_endpoint_address_2 = v1_endpoint_address_parseFromJSON(jsonv1_endpoint_address_1);
	cJSON* jsonv1_endpoint_address_2 = v1_endpoint_address_convertToJSON(v1_endpoint_address_2);
	printf("repeating v1_endpoint_address:\n%s\n", cJSON_Print(jsonv1_endpoint_address_2));
}

int main() {
  test_v1_endpoint_address(1);
  test_v1_endpoint_address(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_endpoint_address_MAIN
#endif // v1_endpoint_address_TEST
