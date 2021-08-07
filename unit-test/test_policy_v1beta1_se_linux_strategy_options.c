#ifndef policy_v1beta1_se_linux_strategy_options_TEST
#define policy_v1beta1_se_linux_strategy_options_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define policy_v1beta1_se_linux_strategy_options_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/policy_v1beta1_se_linux_strategy_options.h"
policy_v1beta1_se_linux_strategy_options_t* instantiate_policy_v1beta1_se_linux_strategy_options(int include_optional);

#include "test_v1_se_linux_options.c"


policy_v1beta1_se_linux_strategy_options_t* instantiate_policy_v1beta1_se_linux_strategy_options(int include_optional) {
  policy_v1beta1_se_linux_strategy_options_t* policy_v1beta1_se_linux_strategy_options = NULL;
  if (include_optional) {
    policy_v1beta1_se_linux_strategy_options = policy_v1beta1_se_linux_strategy_options_create(
      "0",
       // false, not to have infinite recursion
      instantiate_v1_se_linux_options(0)
    );
  } else {
    policy_v1beta1_se_linux_strategy_options = policy_v1beta1_se_linux_strategy_options_create(
      "0",
      NULL
    );
  }

  return policy_v1beta1_se_linux_strategy_options;
}


#ifdef policy_v1beta1_se_linux_strategy_options_MAIN

void test_policy_v1beta1_se_linux_strategy_options(int include_optional) {
    policy_v1beta1_se_linux_strategy_options_t* policy_v1beta1_se_linux_strategy_options_1 = instantiate_policy_v1beta1_se_linux_strategy_options(include_optional);

	cJSON* jsonpolicy_v1beta1_se_linux_strategy_options_1 = policy_v1beta1_se_linux_strategy_options_convertToJSON(policy_v1beta1_se_linux_strategy_options_1);
	printf("policy_v1beta1_se_linux_strategy_options :\n%s\n", cJSON_Print(jsonpolicy_v1beta1_se_linux_strategy_options_1));
	policy_v1beta1_se_linux_strategy_options_t* policy_v1beta1_se_linux_strategy_options_2 = policy_v1beta1_se_linux_strategy_options_parseFromJSON(jsonpolicy_v1beta1_se_linux_strategy_options_1);
	cJSON* jsonpolicy_v1beta1_se_linux_strategy_options_2 = policy_v1beta1_se_linux_strategy_options_convertToJSON(policy_v1beta1_se_linux_strategy_options_2);
	printf("repeating policy_v1beta1_se_linux_strategy_options:\n%s\n", cJSON_Print(jsonpolicy_v1beta1_se_linux_strategy_options_2));
}

int main() {
  test_policy_v1beta1_se_linux_strategy_options(1);
  test_policy_v1beta1_se_linux_strategy_options(0);

  printf("Hello world \n");
  return 0;
}

#endif // policy_v1beta1_se_linux_strategy_options_MAIN
#endif // policy_v1beta1_se_linux_strategy_options_TEST
