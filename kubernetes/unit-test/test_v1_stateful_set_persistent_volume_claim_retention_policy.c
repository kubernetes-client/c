#ifndef v1_stateful_set_persistent_volume_claim_retention_policy_TEST
#define v1_stateful_set_persistent_volume_claim_retention_policy_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_stateful_set_persistent_volume_claim_retention_policy_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_stateful_set_persistent_volume_claim_retention_policy.h"
v1_stateful_set_persistent_volume_claim_retention_policy_t* instantiate_v1_stateful_set_persistent_volume_claim_retention_policy(int include_optional);



v1_stateful_set_persistent_volume_claim_retention_policy_t* instantiate_v1_stateful_set_persistent_volume_claim_retention_policy(int include_optional) {
  v1_stateful_set_persistent_volume_claim_retention_policy_t* v1_stateful_set_persistent_volume_claim_retention_policy = NULL;
  if (include_optional) {
    v1_stateful_set_persistent_volume_claim_retention_policy = v1_stateful_set_persistent_volume_claim_retention_policy_create(
      "0",
      "0"
    );
  } else {
    v1_stateful_set_persistent_volume_claim_retention_policy = v1_stateful_set_persistent_volume_claim_retention_policy_create(
      "0",
      "0"
    );
  }

  return v1_stateful_set_persistent_volume_claim_retention_policy;
}


#ifdef v1_stateful_set_persistent_volume_claim_retention_policy_MAIN

void test_v1_stateful_set_persistent_volume_claim_retention_policy(int include_optional) {
    v1_stateful_set_persistent_volume_claim_retention_policy_t* v1_stateful_set_persistent_volume_claim_retention_policy_1 = instantiate_v1_stateful_set_persistent_volume_claim_retention_policy(include_optional);

	cJSON* jsonv1_stateful_set_persistent_volume_claim_retention_policy_1 = v1_stateful_set_persistent_volume_claim_retention_policy_convertToJSON(v1_stateful_set_persistent_volume_claim_retention_policy_1);
	printf("v1_stateful_set_persistent_volume_claim_retention_policy :\n%s\n", cJSON_Print(jsonv1_stateful_set_persistent_volume_claim_retention_policy_1));
	v1_stateful_set_persistent_volume_claim_retention_policy_t* v1_stateful_set_persistent_volume_claim_retention_policy_2 = v1_stateful_set_persistent_volume_claim_retention_policy_parseFromJSON(jsonv1_stateful_set_persistent_volume_claim_retention_policy_1);
	cJSON* jsonv1_stateful_set_persistent_volume_claim_retention_policy_2 = v1_stateful_set_persistent_volume_claim_retention_policy_convertToJSON(v1_stateful_set_persistent_volume_claim_retention_policy_2);
	printf("repeating v1_stateful_set_persistent_volume_claim_retention_policy:\n%s\n", cJSON_Print(jsonv1_stateful_set_persistent_volume_claim_retention_policy_2));
}

int main() {
  test_v1_stateful_set_persistent_volume_claim_retention_policy(1);
  test_v1_stateful_set_persistent_volume_claim_retention_policy(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_stateful_set_persistent_volume_claim_retention_policy_MAIN
#endif // v1_stateful_set_persistent_volume_claim_retention_policy_TEST
