#ifndef v1alpha1_policy_TEST
#define v1alpha1_policy_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1alpha1_policy_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1alpha1_policy.h"
v1alpha1_policy_t* instantiate_v1alpha1_policy(int include_optional);



v1alpha1_policy_t* instantiate_v1alpha1_policy(int include_optional) {
  v1alpha1_policy_t* v1alpha1_policy = NULL;
  if (include_optional) {
    v1alpha1_policy = v1alpha1_policy_create(
      "0",
      list_create()
    );
  } else {
    v1alpha1_policy = v1alpha1_policy_create(
      "0",
      list_create()
    );
  }

  return v1alpha1_policy;
}


#ifdef v1alpha1_policy_MAIN

void test_v1alpha1_policy(int include_optional) {
    v1alpha1_policy_t* v1alpha1_policy_1 = instantiate_v1alpha1_policy(include_optional);

	cJSON* jsonv1alpha1_policy_1 = v1alpha1_policy_convertToJSON(v1alpha1_policy_1);
	printf("v1alpha1_policy :\n%s\n", cJSON_Print(jsonv1alpha1_policy_1));
	v1alpha1_policy_t* v1alpha1_policy_2 = v1alpha1_policy_parseFromJSON(jsonv1alpha1_policy_1);
	cJSON* jsonv1alpha1_policy_2 = v1alpha1_policy_convertToJSON(v1alpha1_policy_2);
	printf("repeating v1alpha1_policy:\n%s\n", cJSON_Print(jsonv1alpha1_policy_2));
}

int main() {
  test_v1alpha1_policy(1);
  test_v1alpha1_policy(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1alpha1_policy_MAIN
#endif // v1alpha1_policy_TEST
