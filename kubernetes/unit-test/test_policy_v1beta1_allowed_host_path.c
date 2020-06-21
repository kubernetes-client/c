#ifndef policy_v1beta1_allowed_host_path_TEST
#define policy_v1beta1_allowed_host_path_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define policy_v1beta1_allowed_host_path_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/policy_v1beta1_allowed_host_path.h"
policy_v1beta1_allowed_host_path_t* instantiate_policy_v1beta1_allowed_host_path(int include_optional);



policy_v1beta1_allowed_host_path_t* instantiate_policy_v1beta1_allowed_host_path(int include_optional) {
  policy_v1beta1_allowed_host_path_t* policy_v1beta1_allowed_host_path = NULL;
  if (include_optional) {
    policy_v1beta1_allowed_host_path = policy_v1beta1_allowed_host_path_create(
      "0",
      1
    );
  } else {
    policy_v1beta1_allowed_host_path = policy_v1beta1_allowed_host_path_create(
      "0",
      1
    );
  }

  return policy_v1beta1_allowed_host_path;
}


#ifdef policy_v1beta1_allowed_host_path_MAIN

void test_policy_v1beta1_allowed_host_path(int include_optional) {
    policy_v1beta1_allowed_host_path_t* policy_v1beta1_allowed_host_path_1 = instantiate_policy_v1beta1_allowed_host_path(include_optional);

	cJSON* jsonpolicy_v1beta1_allowed_host_path_1 = policy_v1beta1_allowed_host_path_convertToJSON(policy_v1beta1_allowed_host_path_1);
	printf("policy_v1beta1_allowed_host_path :\n%s\n", cJSON_Print(jsonpolicy_v1beta1_allowed_host_path_1));
	policy_v1beta1_allowed_host_path_t* policy_v1beta1_allowed_host_path_2 = policy_v1beta1_allowed_host_path_parseFromJSON(jsonpolicy_v1beta1_allowed_host_path_1);
	cJSON* jsonpolicy_v1beta1_allowed_host_path_2 = policy_v1beta1_allowed_host_path_convertToJSON(policy_v1beta1_allowed_host_path_2);
	printf("repeating policy_v1beta1_allowed_host_path:\n%s\n", cJSON_Print(jsonpolicy_v1beta1_allowed_host_path_2));
}

int main() {
  test_policy_v1beta1_allowed_host_path(1);
  test_policy_v1beta1_allowed_host_path(0);

  printf("Hello world \n");
  return 0;
}

#endif // policy_v1beta1_allowed_host_path_MAIN
#endif // policy_v1beta1_allowed_host_path_TEST
