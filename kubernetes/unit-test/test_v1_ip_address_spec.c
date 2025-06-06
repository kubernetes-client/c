#ifndef v1_ip_address_spec_TEST
#define v1_ip_address_spec_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_ip_address_spec_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_ip_address_spec.h"
v1_ip_address_spec_t* instantiate_v1_ip_address_spec(int include_optional);

#include "test_v1_parent_reference.c"


v1_ip_address_spec_t* instantiate_v1_ip_address_spec(int include_optional) {
  v1_ip_address_spec_t* v1_ip_address_spec = NULL;
  if (include_optional) {
    v1_ip_address_spec = v1_ip_address_spec_create(
       // false, not to have infinite recursion
      instantiate_v1_parent_reference(0)
    );
  } else {
    v1_ip_address_spec = v1_ip_address_spec_create(
      NULL
    );
  }

  return v1_ip_address_spec;
}


#ifdef v1_ip_address_spec_MAIN

void test_v1_ip_address_spec(int include_optional) {
    v1_ip_address_spec_t* v1_ip_address_spec_1 = instantiate_v1_ip_address_spec(include_optional);

	cJSON* jsonv1_ip_address_spec_1 = v1_ip_address_spec_convertToJSON(v1_ip_address_spec_1);
	printf("v1_ip_address_spec :\n%s\n", cJSON_Print(jsonv1_ip_address_spec_1));
	v1_ip_address_spec_t* v1_ip_address_spec_2 = v1_ip_address_spec_parseFromJSON(jsonv1_ip_address_spec_1);
	cJSON* jsonv1_ip_address_spec_2 = v1_ip_address_spec_convertToJSON(v1_ip_address_spec_2);
	printf("repeating v1_ip_address_spec:\n%s\n", cJSON_Print(jsonv1_ip_address_spec_2));
}

int main() {
  test_v1_ip_address_spec(1);
  test_v1_ip_address_spec(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_ip_address_spec_MAIN
#endif // v1_ip_address_spec_TEST
