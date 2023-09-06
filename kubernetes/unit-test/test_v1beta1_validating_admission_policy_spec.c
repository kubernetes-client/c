#ifndef v1beta1_validating_admission_policy_spec_TEST
#define v1beta1_validating_admission_policy_spec_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1beta1_validating_admission_policy_spec_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1beta1_validating_admission_policy_spec.h"
v1beta1_validating_admission_policy_spec_t* instantiate_v1beta1_validating_admission_policy_spec(int include_optional);

#include "test_v1beta1_match_resources.c"
#include "test_v1beta1_param_kind.c"


v1beta1_validating_admission_policy_spec_t* instantiate_v1beta1_validating_admission_policy_spec(int include_optional) {
  v1beta1_validating_admission_policy_spec_t* v1beta1_validating_admission_policy_spec = NULL;
  if (include_optional) {
    v1beta1_validating_admission_policy_spec = v1beta1_validating_admission_policy_spec_create(
      list_createList(),
      "0",
      list_createList(),
       // false, not to have infinite recursion
      instantiate_v1beta1_match_resources(0),
       // false, not to have infinite recursion
      instantiate_v1beta1_param_kind(0),
      list_createList(),
      list_createList()
    );
  } else {
    v1beta1_validating_admission_policy_spec = v1beta1_validating_admission_policy_spec_create(
      list_createList(),
      "0",
      list_createList(),
      NULL,
      NULL,
      list_createList(),
      list_createList()
    );
  }

  return v1beta1_validating_admission_policy_spec;
}


#ifdef v1beta1_validating_admission_policy_spec_MAIN

void test_v1beta1_validating_admission_policy_spec(int include_optional) {
    v1beta1_validating_admission_policy_spec_t* v1beta1_validating_admission_policy_spec_1 = instantiate_v1beta1_validating_admission_policy_spec(include_optional);

	cJSON* jsonv1beta1_validating_admission_policy_spec_1 = v1beta1_validating_admission_policy_spec_convertToJSON(v1beta1_validating_admission_policy_spec_1);
	printf("v1beta1_validating_admission_policy_spec :\n%s\n", cJSON_Print(jsonv1beta1_validating_admission_policy_spec_1));
	v1beta1_validating_admission_policy_spec_t* v1beta1_validating_admission_policy_spec_2 = v1beta1_validating_admission_policy_spec_parseFromJSON(jsonv1beta1_validating_admission_policy_spec_1);
	cJSON* jsonv1beta1_validating_admission_policy_spec_2 = v1beta1_validating_admission_policy_spec_convertToJSON(v1beta1_validating_admission_policy_spec_2);
	printf("repeating v1beta1_validating_admission_policy_spec:\n%s\n", cJSON_Print(jsonv1beta1_validating_admission_policy_spec_2));
}

int main() {
  test_v1beta1_validating_admission_policy_spec(1);
  test_v1beta1_validating_admission_policy_spec(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1beta1_validating_admission_policy_spec_MAIN
#endif // v1beta1_validating_admission_policy_spec_TEST
