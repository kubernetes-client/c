#ifndef v1alpha1_user_subject_TEST
#define v1alpha1_user_subject_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1alpha1_user_subject_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1alpha1_user_subject.h"
v1alpha1_user_subject_t* instantiate_v1alpha1_user_subject(int include_optional);



v1alpha1_user_subject_t* instantiate_v1alpha1_user_subject(int include_optional) {
  v1alpha1_user_subject_t* v1alpha1_user_subject = NULL;
  if (include_optional) {
    v1alpha1_user_subject = v1alpha1_user_subject_create(
      "0"
    );
  } else {
    v1alpha1_user_subject = v1alpha1_user_subject_create(
      "0"
    );
  }

  return v1alpha1_user_subject;
}


#ifdef v1alpha1_user_subject_MAIN

void test_v1alpha1_user_subject(int include_optional) {
    v1alpha1_user_subject_t* v1alpha1_user_subject_1 = instantiate_v1alpha1_user_subject(include_optional);

	cJSON* jsonv1alpha1_user_subject_1 = v1alpha1_user_subject_convertToJSON(v1alpha1_user_subject_1);
	printf("v1alpha1_user_subject :\n%s\n", cJSON_Print(jsonv1alpha1_user_subject_1));
	v1alpha1_user_subject_t* v1alpha1_user_subject_2 = v1alpha1_user_subject_parseFromJSON(jsonv1alpha1_user_subject_1);
	cJSON* jsonv1alpha1_user_subject_2 = v1alpha1_user_subject_convertToJSON(v1alpha1_user_subject_2);
	printf("repeating v1alpha1_user_subject:\n%s\n", cJSON_Print(jsonv1alpha1_user_subject_2));
}

int main() {
  test_v1alpha1_user_subject(1);
  test_v1alpha1_user_subject(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1alpha1_user_subject_MAIN
#endif // v1alpha1_user_subject_TEST
