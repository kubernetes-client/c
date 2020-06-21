#ifndef policy_v1beta1_pod_security_policy_list_TEST
#define policy_v1beta1_pod_security_policy_list_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define policy_v1beta1_pod_security_policy_list_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/policy_v1beta1_pod_security_policy_list.h"
policy_v1beta1_pod_security_policy_list_t* instantiate_policy_v1beta1_pod_security_policy_list(int include_optional);

#include "test_v1_list_meta.c"


policy_v1beta1_pod_security_policy_list_t* instantiate_policy_v1beta1_pod_security_policy_list(int include_optional) {
  policy_v1beta1_pod_security_policy_list_t* policy_v1beta1_pod_security_policy_list = NULL;
  if (include_optional) {
    policy_v1beta1_pod_security_policy_list = policy_v1beta1_pod_security_policy_list_create(
      "0",
      list_create(),
      "0",
       // false, not to have infinite recursion
      instantiate_v1_list_meta(0)
    );
  } else {
    policy_v1beta1_pod_security_policy_list = policy_v1beta1_pod_security_policy_list_create(
      "0",
      list_create(),
      "0",
      NULL
    );
  }

  return policy_v1beta1_pod_security_policy_list;
}


#ifdef policy_v1beta1_pod_security_policy_list_MAIN

void test_policy_v1beta1_pod_security_policy_list(int include_optional) {
    policy_v1beta1_pod_security_policy_list_t* policy_v1beta1_pod_security_policy_list_1 = instantiate_policy_v1beta1_pod_security_policy_list(include_optional);

	cJSON* jsonpolicy_v1beta1_pod_security_policy_list_1 = policy_v1beta1_pod_security_policy_list_convertToJSON(policy_v1beta1_pod_security_policy_list_1);
	printf("policy_v1beta1_pod_security_policy_list :\n%s\n", cJSON_Print(jsonpolicy_v1beta1_pod_security_policy_list_1));
	policy_v1beta1_pod_security_policy_list_t* policy_v1beta1_pod_security_policy_list_2 = policy_v1beta1_pod_security_policy_list_parseFromJSON(jsonpolicy_v1beta1_pod_security_policy_list_1);
	cJSON* jsonpolicy_v1beta1_pod_security_policy_list_2 = policy_v1beta1_pod_security_policy_list_convertToJSON(policy_v1beta1_pod_security_policy_list_2);
	printf("repeating policy_v1beta1_pod_security_policy_list:\n%s\n", cJSON_Print(jsonpolicy_v1beta1_pod_security_policy_list_2));
}

int main() {
  test_policy_v1beta1_pod_security_policy_list(1);
  test_policy_v1beta1_pod_security_policy_list(0);

  printf("Hello world \n");
  return 0;
}

#endif // policy_v1beta1_pod_security_policy_list_MAIN
#endif // policy_v1beta1_pod_security_policy_list_TEST
