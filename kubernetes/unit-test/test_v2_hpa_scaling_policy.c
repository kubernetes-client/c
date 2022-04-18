#ifndef v2_hpa_scaling_policy_TEST
#define v2_hpa_scaling_policy_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v2_hpa_scaling_policy_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v2_hpa_scaling_policy.h"
v2_hpa_scaling_policy_t* instantiate_v2_hpa_scaling_policy(int include_optional);



v2_hpa_scaling_policy_t* instantiate_v2_hpa_scaling_policy(int include_optional) {
  v2_hpa_scaling_policy_t* v2_hpa_scaling_policy = NULL;
  if (include_optional) {
    v2_hpa_scaling_policy = v2_hpa_scaling_policy_create(
      56,
      "0",
      56
    );
  } else {
    v2_hpa_scaling_policy = v2_hpa_scaling_policy_create(
      56,
      "0",
      56
    );
  }

  return v2_hpa_scaling_policy;
}


#ifdef v2_hpa_scaling_policy_MAIN

void test_v2_hpa_scaling_policy(int include_optional) {
    v2_hpa_scaling_policy_t* v2_hpa_scaling_policy_1 = instantiate_v2_hpa_scaling_policy(include_optional);

	cJSON* jsonv2_hpa_scaling_policy_1 = v2_hpa_scaling_policy_convertToJSON(v2_hpa_scaling_policy_1);
	printf("v2_hpa_scaling_policy :\n%s\n", cJSON_Print(jsonv2_hpa_scaling_policy_1));
	v2_hpa_scaling_policy_t* v2_hpa_scaling_policy_2 = v2_hpa_scaling_policy_parseFromJSON(jsonv2_hpa_scaling_policy_1);
	cJSON* jsonv2_hpa_scaling_policy_2 = v2_hpa_scaling_policy_convertToJSON(v2_hpa_scaling_policy_2);
	printf("repeating v2_hpa_scaling_policy:\n%s\n", cJSON_Print(jsonv2_hpa_scaling_policy_2));
}

int main() {
  test_v2_hpa_scaling_policy(1);
  test_v2_hpa_scaling_policy(0);

  printf("Hello world \n");
  return 0;
}

#endif // v2_hpa_scaling_policy_MAIN
#endif // v2_hpa_scaling_policy_TEST
