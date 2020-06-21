#ifndef v1_lease_TEST
#define v1_lease_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_lease_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_lease.h"
v1_lease_t* instantiate_v1_lease(int include_optional);

#include "test_v1_object_meta.c"
#include "test_v1_lease_spec.c"


v1_lease_t* instantiate_v1_lease(int include_optional) {
  v1_lease_t* v1_lease = NULL;
  if (include_optional) {
    v1_lease = v1_lease_create(
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_v1_object_meta(0),
       // false, not to have infinite recursion
      instantiate_v1_lease_spec(0)
    );
  } else {
    v1_lease = v1_lease_create(
      "0",
      "0",
      NULL,
      NULL
    );
  }

  return v1_lease;
}


#ifdef v1_lease_MAIN

void test_v1_lease(int include_optional) {
    v1_lease_t* v1_lease_1 = instantiate_v1_lease(include_optional);

	cJSON* jsonv1_lease_1 = v1_lease_convertToJSON(v1_lease_1);
	printf("v1_lease :\n%s\n", cJSON_Print(jsonv1_lease_1));
	v1_lease_t* v1_lease_2 = v1_lease_parseFromJSON(jsonv1_lease_1);
	cJSON* jsonv1_lease_2 = v1_lease_convertToJSON(v1_lease_2);
	printf("repeating v1_lease:\n%s\n", cJSON_Print(jsonv1_lease_2));
}

int main() {
  test_v1_lease(1);
  test_v1_lease(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_lease_MAIN
#endif // v1_lease_TEST
