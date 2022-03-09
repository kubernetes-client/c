#ifndef v1beta1_policy_rules_with_subjects_TEST
#define v1beta1_policy_rules_with_subjects_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1beta1_policy_rules_with_subjects_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1beta1_policy_rules_with_subjects.h"
v1beta1_policy_rules_with_subjects_t* instantiate_v1beta1_policy_rules_with_subjects(int include_optional);



v1beta1_policy_rules_with_subjects_t* instantiate_v1beta1_policy_rules_with_subjects(int include_optional) {
  v1beta1_policy_rules_with_subjects_t* v1beta1_policy_rules_with_subjects = NULL;
  if (include_optional) {
    v1beta1_policy_rules_with_subjects = v1beta1_policy_rules_with_subjects_create(
      list_createList(),
      list_createList(),
      list_createList()
    );
  } else {
    v1beta1_policy_rules_with_subjects = v1beta1_policy_rules_with_subjects_create(
      list_createList(),
      list_createList(),
      list_createList()
    );
  }

  return v1beta1_policy_rules_with_subjects;
}


#ifdef v1beta1_policy_rules_with_subjects_MAIN

void test_v1beta1_policy_rules_with_subjects(int include_optional) {
    v1beta1_policy_rules_with_subjects_t* v1beta1_policy_rules_with_subjects_1 = instantiate_v1beta1_policy_rules_with_subjects(include_optional);

	cJSON* jsonv1beta1_policy_rules_with_subjects_1 = v1beta1_policy_rules_with_subjects_convertToJSON(v1beta1_policy_rules_with_subjects_1);
	printf("v1beta1_policy_rules_with_subjects :\n%s\n", cJSON_Print(jsonv1beta1_policy_rules_with_subjects_1));
	v1beta1_policy_rules_with_subjects_t* v1beta1_policy_rules_with_subjects_2 = v1beta1_policy_rules_with_subjects_parseFromJSON(jsonv1beta1_policy_rules_with_subjects_1);
	cJSON* jsonv1beta1_policy_rules_with_subjects_2 = v1beta1_policy_rules_with_subjects_convertToJSON(v1beta1_policy_rules_with_subjects_2);
	printf("repeating v1beta1_policy_rules_with_subjects:\n%s\n", cJSON_Print(jsonv1beta1_policy_rules_with_subjects_2));
}

int main() {
  test_v1beta1_policy_rules_with_subjects(1);
  test_v1beta1_policy_rules_with_subjects(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1beta1_policy_rules_with_subjects_MAIN
#endif // v1beta1_policy_rules_with_subjects_TEST
