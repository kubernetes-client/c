#ifndef v1alpha1_lease_candidate_TEST
#define v1alpha1_lease_candidate_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1alpha1_lease_candidate_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1alpha1_lease_candidate.h"
v1alpha1_lease_candidate_t* instantiate_v1alpha1_lease_candidate(int include_optional);

#include "test_v1_object_meta.c"
#include "test_v1alpha1_lease_candidate_spec.c"


v1alpha1_lease_candidate_t* instantiate_v1alpha1_lease_candidate(int include_optional) {
  v1alpha1_lease_candidate_t* v1alpha1_lease_candidate = NULL;
  if (include_optional) {
    v1alpha1_lease_candidate = v1alpha1_lease_candidate_create(
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_v1_object_meta(0),
       // false, not to have infinite recursion
      instantiate_v1alpha1_lease_candidate_spec(0)
    );
  } else {
    v1alpha1_lease_candidate = v1alpha1_lease_candidate_create(
      "0",
      "0",
      NULL,
      NULL
    );
  }

  return v1alpha1_lease_candidate;
}


#ifdef v1alpha1_lease_candidate_MAIN

void test_v1alpha1_lease_candidate(int include_optional) {
    v1alpha1_lease_candidate_t* v1alpha1_lease_candidate_1 = instantiate_v1alpha1_lease_candidate(include_optional);

	cJSON* jsonv1alpha1_lease_candidate_1 = v1alpha1_lease_candidate_convertToJSON(v1alpha1_lease_candidate_1);
	printf("v1alpha1_lease_candidate :\n%s\n", cJSON_Print(jsonv1alpha1_lease_candidate_1));
	v1alpha1_lease_candidate_t* v1alpha1_lease_candidate_2 = v1alpha1_lease_candidate_parseFromJSON(jsonv1alpha1_lease_candidate_1);
	cJSON* jsonv1alpha1_lease_candidate_2 = v1alpha1_lease_candidate_convertToJSON(v1alpha1_lease_candidate_2);
	printf("repeating v1alpha1_lease_candidate:\n%s\n", cJSON_Print(jsonv1alpha1_lease_candidate_2));
}

int main() {
  test_v1alpha1_lease_candidate(1);
  test_v1alpha1_lease_candidate(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1alpha1_lease_candidate_MAIN
#endif // v1alpha1_lease_candidate_TEST
