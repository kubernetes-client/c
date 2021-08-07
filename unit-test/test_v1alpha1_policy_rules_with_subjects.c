#ifndef v1alpha1_policy_rules_with_subjects_TEST
#define v1alpha1_policy_rules_with_subjects_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1alpha1_policy_rules_with_subjects_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1alpha1_policy_rules_with_subjects.h"
v1alpha1_policy_rules_with_subjects_t* instantiate_v1alpha1_policy_rules_with_subjects(int include_optional);



v1alpha1_policy_rules_with_subjects_t* instantiate_v1alpha1_policy_rules_with_subjects(int include_optional) {
  v1alpha1_policy_rules_with_subjects_t* v1alpha1_policy_rules_with_subjects = NULL;
  if (include_optional) {
    v1alpha1_policy_rules_with_subjects = v1alpha1_policy_rules_with_subjects_create(
      list_create(),
      list_create(),
      list_create()
    );
  } else {
    v1alpha1_policy_rules_with_subjects = v1alpha1_policy_rules_with_subjects_create(
      list_create(),
      list_create(),
      list_create()
    );
  }

  return v1alpha1_policy_rules_with_subjects;
}


#ifdef v1alpha1_policy_rules_with_subjects_MAIN

void test_v1alpha1_policy_rules_with_subjects(int include_optional) {
    v1alpha1_policy_rules_with_subjects_t* v1alpha1_policy_rules_with_subjects_1 = instantiate_v1alpha1_policy_rules_with_subjects(include_optional);

	cJSON* jsonv1alpha1_policy_rules_with_subjects_1 = v1alpha1_policy_rules_with_subjects_convertToJSON(v1alpha1_policy_rules_with_subjects_1);
	printf("v1alpha1_policy_rules_with_subjects :\n%s\n", cJSON_Print(jsonv1alpha1_policy_rules_with_subjects_1));
	v1alpha1_policy_rules_with_subjects_t* v1alpha1_policy_rules_with_subjects_2 = v1alpha1_policy_rules_with_subjects_parseFromJSON(jsonv1alpha1_policy_rules_with_subjects_1);
	cJSON* jsonv1alpha1_policy_rules_with_subjects_2 = v1alpha1_policy_rules_with_subjects_convertToJSON(v1alpha1_policy_rules_with_subjects_2);
	printf("repeating v1alpha1_policy_rules_with_subjects:\n%s\n", cJSON_Print(jsonv1alpha1_policy_rules_with_subjects_2));
}

int main() {
  test_v1alpha1_policy_rules_with_subjects(1);
  test_v1alpha1_policy_rules_with_subjects(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1alpha1_policy_rules_with_subjects_MAIN
#endif // v1alpha1_policy_rules_with_subjects_TEST
