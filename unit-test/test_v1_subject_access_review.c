#ifndef v1_subject_access_review_TEST
#define v1_subject_access_review_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_subject_access_review_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_subject_access_review.h"
v1_subject_access_review_t* instantiate_v1_subject_access_review(int include_optional);

#include "test_v1_object_meta.c"
#include "test_v1_subject_access_review_spec.c"
#include "test_v1_subject_access_review_status.c"


v1_subject_access_review_t* instantiate_v1_subject_access_review(int include_optional) {
  v1_subject_access_review_t* v1_subject_access_review = NULL;
  if (include_optional) {
    v1_subject_access_review = v1_subject_access_review_create(
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_v1_object_meta(0),
       // false, not to have infinite recursion
      instantiate_v1_subject_access_review_spec(0),
       // false, not to have infinite recursion
      instantiate_v1_subject_access_review_status(0)
    );
  } else {
    v1_subject_access_review = v1_subject_access_review_create(
      "0",
      "0",
      NULL,
      NULL,
      NULL
    );
  }

  return v1_subject_access_review;
}


#ifdef v1_subject_access_review_MAIN

void test_v1_subject_access_review(int include_optional) {
    v1_subject_access_review_t* v1_subject_access_review_1 = instantiate_v1_subject_access_review(include_optional);

	cJSON* jsonv1_subject_access_review_1 = v1_subject_access_review_convertToJSON(v1_subject_access_review_1);
	printf("v1_subject_access_review :\n%s\n", cJSON_Print(jsonv1_subject_access_review_1));
	v1_subject_access_review_t* v1_subject_access_review_2 = v1_subject_access_review_parseFromJSON(jsonv1_subject_access_review_1);
	cJSON* jsonv1_subject_access_review_2 = v1_subject_access_review_convertToJSON(v1_subject_access_review_2);
	printf("repeating v1_subject_access_review:\n%s\n", cJSON_Print(jsonv1_subject_access_review_2));
}

int main() {
  test_v1_subject_access_review(1);
  test_v1_subject_access_review(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_subject_access_review_MAIN
#endif // v1_subject_access_review_TEST
