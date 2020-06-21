#ifndef policy_v1beta1_host_port_range_TEST
#define policy_v1beta1_host_port_range_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define policy_v1beta1_host_port_range_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/policy_v1beta1_host_port_range.h"
policy_v1beta1_host_port_range_t* instantiate_policy_v1beta1_host_port_range(int include_optional);



policy_v1beta1_host_port_range_t* instantiate_policy_v1beta1_host_port_range(int include_optional) {
  policy_v1beta1_host_port_range_t* policy_v1beta1_host_port_range = NULL;
  if (include_optional) {
    policy_v1beta1_host_port_range = policy_v1beta1_host_port_range_create(
      56,
      56
    );
  } else {
    policy_v1beta1_host_port_range = policy_v1beta1_host_port_range_create(
      56,
      56
    );
  }

  return policy_v1beta1_host_port_range;
}


#ifdef policy_v1beta1_host_port_range_MAIN

void test_policy_v1beta1_host_port_range(int include_optional) {
    policy_v1beta1_host_port_range_t* policy_v1beta1_host_port_range_1 = instantiate_policy_v1beta1_host_port_range(include_optional);

	cJSON* jsonpolicy_v1beta1_host_port_range_1 = policy_v1beta1_host_port_range_convertToJSON(policy_v1beta1_host_port_range_1);
	printf("policy_v1beta1_host_port_range :\n%s\n", cJSON_Print(jsonpolicy_v1beta1_host_port_range_1));
	policy_v1beta1_host_port_range_t* policy_v1beta1_host_port_range_2 = policy_v1beta1_host_port_range_parseFromJSON(jsonpolicy_v1beta1_host_port_range_1);
	cJSON* jsonpolicy_v1beta1_host_port_range_2 = policy_v1beta1_host_port_range_convertToJSON(policy_v1beta1_host_port_range_2);
	printf("repeating policy_v1beta1_host_port_range:\n%s\n", cJSON_Print(jsonpolicy_v1beta1_host_port_range_2));
}

int main() {
  test_policy_v1beta1_host_port_range(1);
  test_policy_v1beta1_host_port_range(0);

  printf("Hello world \n");
  return 0;
}

#endif // policy_v1beta1_host_port_range_MAIN
#endif // policy_v1beta1_host_port_range_TEST
