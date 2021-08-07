#ifndef policy_v1beta1_pod_security_policy_TEST
#define policy_v1beta1_pod_security_policy_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define policy_v1beta1_pod_security_policy_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/policy_v1beta1_pod_security_policy.h"
policy_v1beta1_pod_security_policy_t* instantiate_policy_v1beta1_pod_security_policy(int include_optional);

#include "test_v1_object_meta.c"
#include "test_policy_v1beta1_pod_security_policy_spec.c"


policy_v1beta1_pod_security_policy_t* instantiate_policy_v1beta1_pod_security_policy(int include_optional) {
  policy_v1beta1_pod_security_policy_t* policy_v1beta1_pod_security_policy = NULL;
  if (include_optional) {
    policy_v1beta1_pod_security_policy = policy_v1beta1_pod_security_policy_create(
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_v1_object_meta(0),
       // false, not to have infinite recursion
      instantiate_policy_v1beta1_pod_security_policy_spec(0)
    );
  } else {
    policy_v1beta1_pod_security_policy = policy_v1beta1_pod_security_policy_create(
      "0",
      "0",
      NULL,
      NULL
    );
  }

  return policy_v1beta1_pod_security_policy;
}


#ifdef policy_v1beta1_pod_security_policy_MAIN

void test_policy_v1beta1_pod_security_policy(int include_optional) {
    policy_v1beta1_pod_security_policy_t* policy_v1beta1_pod_security_policy_1 = instantiate_policy_v1beta1_pod_security_policy(include_optional);

	cJSON* jsonpolicy_v1beta1_pod_security_policy_1 = policy_v1beta1_pod_security_policy_convertToJSON(policy_v1beta1_pod_security_policy_1);
	printf("policy_v1beta1_pod_security_policy :\n%s\n", cJSON_Print(jsonpolicy_v1beta1_pod_security_policy_1));
	policy_v1beta1_pod_security_policy_t* policy_v1beta1_pod_security_policy_2 = policy_v1beta1_pod_security_policy_parseFromJSON(jsonpolicy_v1beta1_pod_security_policy_1);
	cJSON* jsonpolicy_v1beta1_pod_security_policy_2 = policy_v1beta1_pod_security_policy_convertToJSON(policy_v1beta1_pod_security_policy_2);
	printf("repeating policy_v1beta1_pod_security_policy:\n%s\n", cJSON_Print(jsonpolicy_v1beta1_pod_security_policy_2));
}

int main() {
  test_policy_v1beta1_pod_security_policy(1);
  test_policy_v1beta1_pod_security_policy(0);

  printf("Hello world \n");
  return 0;
}

#endif // policy_v1beta1_pod_security_policy_MAIN
#endif // policy_v1beta1_pod_security_policy_TEST
