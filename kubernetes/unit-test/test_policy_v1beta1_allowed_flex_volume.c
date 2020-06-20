#ifndef policy_v1beta1_allowed_flex_volume_TEST
#define policy_v1beta1_allowed_flex_volume_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define policy_v1beta1_allowed_flex_volume_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/policy_v1beta1_allowed_flex_volume.h"
policy_v1beta1_allowed_flex_volume_t* instantiate_policy_v1beta1_allowed_flex_volume(int include_optional);



policy_v1beta1_allowed_flex_volume_t* instantiate_policy_v1beta1_allowed_flex_volume(int include_optional) {
  policy_v1beta1_allowed_flex_volume_t* policy_v1beta1_allowed_flex_volume = NULL;
  if (include_optional) {
    policy_v1beta1_allowed_flex_volume = policy_v1beta1_allowed_flex_volume_create(
      "0"
    );
  } else {
    policy_v1beta1_allowed_flex_volume = policy_v1beta1_allowed_flex_volume_create(
      "0"
    );
  }

  return policy_v1beta1_allowed_flex_volume;
}


#ifdef policy_v1beta1_allowed_flex_volume_MAIN

void test_policy_v1beta1_allowed_flex_volume(int include_optional) {
    policy_v1beta1_allowed_flex_volume_t* policy_v1beta1_allowed_flex_volume_1 = instantiate_policy_v1beta1_allowed_flex_volume(include_optional);

	cJSON* jsonpolicy_v1beta1_allowed_flex_volume_1 = policy_v1beta1_allowed_flex_volume_convertToJSON(policy_v1beta1_allowed_flex_volume_1);
	printf("policy_v1beta1_allowed_flex_volume :\n%s\n", cJSON_Print(jsonpolicy_v1beta1_allowed_flex_volume_1));
	policy_v1beta1_allowed_flex_volume_t* policy_v1beta1_allowed_flex_volume_2 = policy_v1beta1_allowed_flex_volume_parseFromJSON(jsonpolicy_v1beta1_allowed_flex_volume_1);
	cJSON* jsonpolicy_v1beta1_allowed_flex_volume_2 = policy_v1beta1_allowed_flex_volume_convertToJSON(policy_v1beta1_allowed_flex_volume_2);
	printf("repeating policy_v1beta1_allowed_flex_volume:\n%s\n", cJSON_Print(jsonpolicy_v1beta1_allowed_flex_volume_2));
}

int main() {
  test_policy_v1beta1_allowed_flex_volume(1);
  test_policy_v1beta1_allowed_flex_volume(0);

  printf("Hello world \n");
  return 0;
}

#endif // policy_v1beta1_allowed_flex_volume_MAIN
#endif // policy_v1beta1_allowed_flex_volume_TEST
