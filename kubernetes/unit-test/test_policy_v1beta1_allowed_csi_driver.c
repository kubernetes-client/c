#ifndef policy_v1beta1_allowed_csi_driver_TEST
#define policy_v1beta1_allowed_csi_driver_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define policy_v1beta1_allowed_csi_driver_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/policy_v1beta1_allowed_csi_driver.h"
policy_v1beta1_allowed_csi_driver_t* instantiate_policy_v1beta1_allowed_csi_driver(int include_optional);



policy_v1beta1_allowed_csi_driver_t* instantiate_policy_v1beta1_allowed_csi_driver(int include_optional) {
  policy_v1beta1_allowed_csi_driver_t* policy_v1beta1_allowed_csi_driver = NULL;
  if (include_optional) {
    policy_v1beta1_allowed_csi_driver = policy_v1beta1_allowed_csi_driver_create(
      "0"
    );
  } else {
    policy_v1beta1_allowed_csi_driver = policy_v1beta1_allowed_csi_driver_create(
      "0"
    );
  }

  return policy_v1beta1_allowed_csi_driver;
}


#ifdef policy_v1beta1_allowed_csi_driver_MAIN

void test_policy_v1beta1_allowed_csi_driver(int include_optional) {
    policy_v1beta1_allowed_csi_driver_t* policy_v1beta1_allowed_csi_driver_1 = instantiate_policy_v1beta1_allowed_csi_driver(include_optional);

	cJSON* jsonpolicy_v1beta1_allowed_csi_driver_1 = policy_v1beta1_allowed_csi_driver_convertToJSON(policy_v1beta1_allowed_csi_driver_1);
	printf("policy_v1beta1_allowed_csi_driver :\n%s\n", cJSON_Print(jsonpolicy_v1beta1_allowed_csi_driver_1));
	policy_v1beta1_allowed_csi_driver_t* policy_v1beta1_allowed_csi_driver_2 = policy_v1beta1_allowed_csi_driver_parseFromJSON(jsonpolicy_v1beta1_allowed_csi_driver_1);
	cJSON* jsonpolicy_v1beta1_allowed_csi_driver_2 = policy_v1beta1_allowed_csi_driver_convertToJSON(policy_v1beta1_allowed_csi_driver_2);
	printf("repeating policy_v1beta1_allowed_csi_driver:\n%s\n", cJSON_Print(jsonpolicy_v1beta1_allowed_csi_driver_2));
}

int main() {
  test_policy_v1beta1_allowed_csi_driver(1);
  test_policy_v1beta1_allowed_csi_driver(0);

  printf("Hello world \n");
  return 0;
}

#endif // policy_v1beta1_allowed_csi_driver_MAIN
#endif // policy_v1beta1_allowed_csi_driver_TEST
