#ifndef policy_v1beta1_pod_security_policy_spec_TEST
#define policy_v1beta1_pod_security_policy_spec_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define policy_v1beta1_pod_security_policy_spec_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/policy_v1beta1_pod_security_policy_spec.h"
policy_v1beta1_pod_security_policy_spec_t* instantiate_policy_v1beta1_pod_security_policy_spec(int include_optional);

#include "test_policy_v1beta1_fs_group_strategy_options.c"
#include "test_policy_v1beta1_run_as_group_strategy_options.c"
#include "test_policy_v1beta1_run_as_user_strategy_options.c"
#include "test_policy_v1beta1_runtime_class_strategy_options.c"
#include "test_policy_v1beta1_se_linux_strategy_options.c"
#include "test_policy_v1beta1_supplemental_groups_strategy_options.c"


policy_v1beta1_pod_security_policy_spec_t* instantiate_policy_v1beta1_pod_security_policy_spec(int include_optional) {
  policy_v1beta1_pod_security_policy_spec_t* policy_v1beta1_pod_security_policy_spec = NULL;
  if (include_optional) {
    policy_v1beta1_pod_security_policy_spec = policy_v1beta1_pod_security_policy_spec_create(
      1,
      list_create(),
      list_create(),
      list_create(),
      list_create(),
      list_create(),
      list_create(),
      list_create(),
      1,
      list_create(),
       // false, not to have infinite recursion
      instantiate_policy_v1beta1_fs_group_strategy_options(0),
      1,
      1,
      1,
      list_create(),
      1,
      1,
      list_create(),
       // false, not to have infinite recursion
      instantiate_policy_v1beta1_run_as_group_strategy_options(0),
       // false, not to have infinite recursion
      instantiate_policy_v1beta1_run_as_user_strategy_options(0),
       // false, not to have infinite recursion
      instantiate_policy_v1beta1_runtime_class_strategy_options(0),
       // false, not to have infinite recursion
      instantiate_policy_v1beta1_se_linux_strategy_options(0),
       // false, not to have infinite recursion
      instantiate_policy_v1beta1_supplemental_groups_strategy_options(0),
      list_create()
    );
  } else {
    policy_v1beta1_pod_security_policy_spec = policy_v1beta1_pod_security_policy_spec_create(
      1,
      list_create(),
      list_create(),
      list_create(),
      list_create(),
      list_create(),
      list_create(),
      list_create(),
      1,
      list_create(),
      NULL,
      1,
      1,
      1,
      list_create(),
      1,
      1,
      list_create(),
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      list_create()
    );
  }

  return policy_v1beta1_pod_security_policy_spec;
}


#ifdef policy_v1beta1_pod_security_policy_spec_MAIN

void test_policy_v1beta1_pod_security_policy_spec(int include_optional) {
    policy_v1beta1_pod_security_policy_spec_t* policy_v1beta1_pod_security_policy_spec_1 = instantiate_policy_v1beta1_pod_security_policy_spec(include_optional);

	cJSON* jsonpolicy_v1beta1_pod_security_policy_spec_1 = policy_v1beta1_pod_security_policy_spec_convertToJSON(policy_v1beta1_pod_security_policy_spec_1);
	printf("policy_v1beta1_pod_security_policy_spec :\n%s\n", cJSON_Print(jsonpolicy_v1beta1_pod_security_policy_spec_1));
	policy_v1beta1_pod_security_policy_spec_t* policy_v1beta1_pod_security_policy_spec_2 = policy_v1beta1_pod_security_policy_spec_parseFromJSON(jsonpolicy_v1beta1_pod_security_policy_spec_1);
	cJSON* jsonpolicy_v1beta1_pod_security_policy_spec_2 = policy_v1beta1_pod_security_policy_spec_convertToJSON(policy_v1beta1_pod_security_policy_spec_2);
	printf("repeating policy_v1beta1_pod_security_policy_spec:\n%s\n", cJSON_Print(jsonpolicy_v1beta1_pod_security_policy_spec_2));
}

int main() {
  test_policy_v1beta1_pod_security_policy_spec(1);
  test_policy_v1beta1_pod_security_policy_spec(0);

  printf("Hello world \n");
  return 0;
}

#endif // policy_v1beta1_pod_security_policy_spec_MAIN
#endif // policy_v1beta1_pod_security_policy_spec_TEST
