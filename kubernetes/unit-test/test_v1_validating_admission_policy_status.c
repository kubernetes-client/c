#ifndef v1_validating_admission_policy_status_TEST
#define v1_validating_admission_policy_status_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_validating_admission_policy_status_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_validating_admission_policy_status.h"
v1_validating_admission_policy_status_t* instantiate_v1_validating_admission_policy_status(int include_optional);

#include "test_v1_type_checking.c"


v1_validating_admission_policy_status_t* instantiate_v1_validating_admission_policy_status(int include_optional) {
  v1_validating_admission_policy_status_t* v1_validating_admission_policy_status = NULL;
  if (include_optional) {
    v1_validating_admission_policy_status = v1_validating_admission_policy_status_create(
      list_createList(),
      56,
       // false, not to have infinite recursion
      instantiate_v1_type_checking(0)
    );
  } else {
    v1_validating_admission_policy_status = v1_validating_admission_policy_status_create(
      list_createList(),
      56,
      NULL
    );
  }

  return v1_validating_admission_policy_status;
}


#ifdef v1_validating_admission_policy_status_MAIN

void test_v1_validating_admission_policy_status(int include_optional) {
    v1_validating_admission_policy_status_t* v1_validating_admission_policy_status_1 = instantiate_v1_validating_admission_policy_status(include_optional);

	cJSON* jsonv1_validating_admission_policy_status_1 = v1_validating_admission_policy_status_convertToJSON(v1_validating_admission_policy_status_1);
	printf("v1_validating_admission_policy_status :\n%s\n", cJSON_Print(jsonv1_validating_admission_policy_status_1));
	v1_validating_admission_policy_status_t* v1_validating_admission_policy_status_2 = v1_validating_admission_policy_status_parseFromJSON(jsonv1_validating_admission_policy_status_1);
	cJSON* jsonv1_validating_admission_policy_status_2 = v1_validating_admission_policy_status_convertToJSON(v1_validating_admission_policy_status_2);
	printf("repeating v1_validating_admission_policy_status:\n%s\n", cJSON_Print(jsonv1_validating_admission_policy_status_2));
}

int main() {
  test_v1_validating_admission_policy_status(1);
  test_v1_validating_admission_policy_status(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_validating_admission_policy_status_MAIN
#endif // v1_validating_admission_policy_status_TEST
