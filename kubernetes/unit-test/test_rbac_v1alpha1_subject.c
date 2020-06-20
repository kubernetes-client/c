#ifndef rbac_v1alpha1_subject_TEST
#define rbac_v1alpha1_subject_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define rbac_v1alpha1_subject_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/rbac_v1alpha1_subject.h"
rbac_v1alpha1_subject_t* instantiate_rbac_v1alpha1_subject(int include_optional);



rbac_v1alpha1_subject_t* instantiate_rbac_v1alpha1_subject(int include_optional) {
  rbac_v1alpha1_subject_t* rbac_v1alpha1_subject = NULL;
  if (include_optional) {
    rbac_v1alpha1_subject = rbac_v1alpha1_subject_create(
      "0",
      "0",
      "0",
      "0"
    );
  } else {
    rbac_v1alpha1_subject = rbac_v1alpha1_subject_create(
      "0",
      "0",
      "0",
      "0"
    );
  }

  return rbac_v1alpha1_subject;
}


#ifdef rbac_v1alpha1_subject_MAIN

void test_rbac_v1alpha1_subject(int include_optional) {
    rbac_v1alpha1_subject_t* rbac_v1alpha1_subject_1 = instantiate_rbac_v1alpha1_subject(include_optional);

	cJSON* jsonrbac_v1alpha1_subject_1 = rbac_v1alpha1_subject_convertToJSON(rbac_v1alpha1_subject_1);
	printf("rbac_v1alpha1_subject :\n%s\n", cJSON_Print(jsonrbac_v1alpha1_subject_1));
	rbac_v1alpha1_subject_t* rbac_v1alpha1_subject_2 = rbac_v1alpha1_subject_parseFromJSON(jsonrbac_v1alpha1_subject_1);
	cJSON* jsonrbac_v1alpha1_subject_2 = rbac_v1alpha1_subject_convertToJSON(rbac_v1alpha1_subject_2);
	printf("repeating rbac_v1alpha1_subject:\n%s\n", cJSON_Print(jsonrbac_v1alpha1_subject_2));
}

int main() {
  test_rbac_v1alpha1_subject(1);
  test_rbac_v1alpha1_subject(0);

  printf("Hello world \n");
  return 0;
}

#endif // rbac_v1alpha1_subject_MAIN
#endif // rbac_v1alpha1_subject_TEST
