#ifndef v1_capacity_request_policy_range_TEST
#define v1_capacity_request_policy_range_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_capacity_request_policy_range_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_capacity_request_policy_range.h"
v1_capacity_request_policy_range_t* instantiate_v1_capacity_request_policy_range(int include_optional);



v1_capacity_request_policy_range_t* instantiate_v1_capacity_request_policy_range(int include_optional) {
  v1_capacity_request_policy_range_t* v1_capacity_request_policy_range = NULL;
  if (include_optional) {
    v1_capacity_request_policy_range = v1_capacity_request_policy_range_create(
      "0",
      "0",
      "0"
    );
  } else {
    v1_capacity_request_policy_range = v1_capacity_request_policy_range_create(
      "0",
      "0",
      "0"
    );
  }

  return v1_capacity_request_policy_range;
}


#ifdef v1_capacity_request_policy_range_MAIN

void test_v1_capacity_request_policy_range(int include_optional) {
    v1_capacity_request_policy_range_t* v1_capacity_request_policy_range_1 = instantiate_v1_capacity_request_policy_range(include_optional);

	cJSON* jsonv1_capacity_request_policy_range_1 = v1_capacity_request_policy_range_convertToJSON(v1_capacity_request_policy_range_1);
	printf("v1_capacity_request_policy_range :\n%s\n", cJSON_Print(jsonv1_capacity_request_policy_range_1));
	v1_capacity_request_policy_range_t* v1_capacity_request_policy_range_2 = v1_capacity_request_policy_range_parseFromJSON(jsonv1_capacity_request_policy_range_1);
	cJSON* jsonv1_capacity_request_policy_range_2 = v1_capacity_request_policy_range_convertToJSON(v1_capacity_request_policy_range_2);
	printf("repeating v1_capacity_request_policy_range:\n%s\n", cJSON_Print(jsonv1_capacity_request_policy_range_2));
}

int main() {
  test_v1_capacity_request_policy_range(1);
  test_v1_capacity_request_policy_range(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_capacity_request_policy_range_MAIN
#endif // v1_capacity_request_policy_range_TEST
