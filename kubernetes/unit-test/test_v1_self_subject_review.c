#ifndef v1_self_subject_review_TEST
#define v1_self_subject_review_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_self_subject_review_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_self_subject_review.h"
v1_self_subject_review_t* instantiate_v1_self_subject_review(int include_optional);

#include "test_v1_object_meta.c"
#include "test_v1_self_subject_review_status.c"


v1_self_subject_review_t* instantiate_v1_self_subject_review(int include_optional) {
  v1_self_subject_review_t* v1_self_subject_review = NULL;
  if (include_optional) {
    v1_self_subject_review = v1_self_subject_review_create(
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_v1_object_meta(0),
       // false, not to have infinite recursion
      instantiate_v1_self_subject_review_status(0)
    );
  } else {
    v1_self_subject_review = v1_self_subject_review_create(
      "0",
      "0",
      NULL,
      NULL
    );
  }

  return v1_self_subject_review;
}


#ifdef v1_self_subject_review_MAIN

void test_v1_self_subject_review(int include_optional) {
    v1_self_subject_review_t* v1_self_subject_review_1 = instantiate_v1_self_subject_review(include_optional);

	cJSON* jsonv1_self_subject_review_1 = v1_self_subject_review_convertToJSON(v1_self_subject_review_1);
	printf("v1_self_subject_review :\n%s\n", cJSON_Print(jsonv1_self_subject_review_1));
	v1_self_subject_review_t* v1_self_subject_review_2 = v1_self_subject_review_parseFromJSON(jsonv1_self_subject_review_1);
	cJSON* jsonv1_self_subject_review_2 = v1_self_subject_review_convertToJSON(v1_self_subject_review_2);
	printf("repeating v1_self_subject_review:\n%s\n", cJSON_Print(jsonv1_self_subject_review_2));
}

int main() {
  test_v1_self_subject_review(1);
  test_v1_self_subject_review(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_self_subject_review_MAIN
#endif // v1_self_subject_review_TEST
