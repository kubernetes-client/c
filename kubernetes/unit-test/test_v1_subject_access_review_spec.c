#ifndef v1_subject_access_review_spec_TEST
#define v1_subject_access_review_spec_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_subject_access_review_spec_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_subject_access_review_spec.h"
v1_subject_access_review_spec_t* instantiate_v1_subject_access_review_spec(int include_optional);

#include "test_v1_non_resource_attributes.c"
#include "test_v1_resource_attributes.c"


v1_subject_access_review_spec_t* instantiate_v1_subject_access_review_spec(int include_optional) {
  v1_subject_access_review_spec_t* v1_subject_access_review_spec = NULL;
  if (include_optional) {
    v1_subject_access_review_spec = v1_subject_access_review_spec_create(
      list_create(),
      list_create(),
       // false, not to have infinite recursion
      instantiate_v1_non_resource_attributes(0),
       // false, not to have infinite recursion
      instantiate_v1_resource_attributes(0),
      "0",
      "0"
    );
  } else {
    v1_subject_access_review_spec = v1_subject_access_review_spec_create(
      list_create(),
      list_create(),
      NULL,
      NULL,
      "0",
      "0"
    );
  }

  return v1_subject_access_review_spec;
}


#ifdef v1_subject_access_review_spec_MAIN

void test_v1_subject_access_review_spec(int include_optional) {
    v1_subject_access_review_spec_t* v1_subject_access_review_spec_1 = instantiate_v1_subject_access_review_spec(include_optional);

	cJSON* jsonv1_subject_access_review_spec_1 = v1_subject_access_review_spec_convertToJSON(v1_subject_access_review_spec_1);
	printf("v1_subject_access_review_spec :\n%s\n", cJSON_Print(jsonv1_subject_access_review_spec_1));
	v1_subject_access_review_spec_t* v1_subject_access_review_spec_2 = v1_subject_access_review_spec_parseFromJSON(jsonv1_subject_access_review_spec_1);
	cJSON* jsonv1_subject_access_review_spec_2 = v1_subject_access_review_spec_convertToJSON(v1_subject_access_review_spec_2);
	printf("repeating v1_subject_access_review_spec:\n%s\n", cJSON_Print(jsonv1_subject_access_review_spec_2));
}

int main() {
  test_v1_subject_access_review_spec(1);
  test_v1_subject_access_review_spec(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_subject_access_review_spec_MAIN
#endif // v1_subject_access_review_spec_TEST
