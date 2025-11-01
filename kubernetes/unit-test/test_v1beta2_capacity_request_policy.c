#ifndef v1beta2_capacity_request_policy_TEST
#define v1beta2_capacity_request_policy_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1beta2_capacity_request_policy_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1beta2_capacity_request_policy.h"
v1beta2_capacity_request_policy_t* instantiate_v1beta2_capacity_request_policy(int include_optional);

#include "test_v1beta2_capacity_request_policy_range.c"


v1beta2_capacity_request_policy_t* instantiate_v1beta2_capacity_request_policy(int include_optional) {
  v1beta2_capacity_request_policy_t* v1beta2_capacity_request_policy = NULL;
  if (include_optional) {
    v1beta2_capacity_request_policy = v1beta2_capacity_request_policy_create(
      "0",
       // false, not to have infinite recursion
      instantiate_v1beta2_capacity_request_policy_range(0),
      list_createList()
    );
  } else {
    v1beta2_capacity_request_policy = v1beta2_capacity_request_policy_create(
      "0",
      NULL,
      list_createList()
    );
  }

  return v1beta2_capacity_request_policy;
}


#ifdef v1beta2_capacity_request_policy_MAIN

void test_v1beta2_capacity_request_policy(int include_optional) {
    v1beta2_capacity_request_policy_t* v1beta2_capacity_request_policy_1 = instantiate_v1beta2_capacity_request_policy(include_optional);

	cJSON* jsonv1beta2_capacity_request_policy_1 = v1beta2_capacity_request_policy_convertToJSON(v1beta2_capacity_request_policy_1);
	printf("v1beta2_capacity_request_policy :\n%s\n", cJSON_Print(jsonv1beta2_capacity_request_policy_1));
	v1beta2_capacity_request_policy_t* v1beta2_capacity_request_policy_2 = v1beta2_capacity_request_policy_parseFromJSON(jsonv1beta2_capacity_request_policy_1);
	cJSON* jsonv1beta2_capacity_request_policy_2 = v1beta2_capacity_request_policy_convertToJSON(v1beta2_capacity_request_policy_2);
	printf("repeating v1beta2_capacity_request_policy:\n%s\n", cJSON_Print(jsonv1beta2_capacity_request_policy_2));
}

int main() {
  test_v1beta2_capacity_request_policy(1);
  test_v1beta2_capacity_request_policy(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1beta2_capacity_request_policy_MAIN
#endif // v1beta2_capacity_request_policy_TEST
