#ifndef v1beta1_subject_TEST
#define v1beta1_subject_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1beta1_subject_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1beta1_subject.h"
v1beta1_subject_t* instantiate_v1beta1_subject(int include_optional);



v1beta1_subject_t* instantiate_v1beta1_subject(int include_optional) {
  v1beta1_subject_t* v1beta1_subject = NULL;
  if (include_optional) {
    v1beta1_subject = v1beta1_subject_create(
      "0",
      "0",
      "0",
      "0"
    );
  } else {
    v1beta1_subject = v1beta1_subject_create(
      "0",
      "0",
      "0",
      "0"
    );
  }

  return v1beta1_subject;
}


#ifdef v1beta1_subject_MAIN

void test_v1beta1_subject(int include_optional) {
    v1beta1_subject_t* v1beta1_subject_1 = instantiate_v1beta1_subject(include_optional);

	cJSON* jsonv1beta1_subject_1 = v1beta1_subject_convertToJSON(v1beta1_subject_1);
	printf("v1beta1_subject :\n%s\n", cJSON_Print(jsonv1beta1_subject_1));
	v1beta1_subject_t* v1beta1_subject_2 = v1beta1_subject_parseFromJSON(jsonv1beta1_subject_1);
	cJSON* jsonv1beta1_subject_2 = v1beta1_subject_convertToJSON(v1beta1_subject_2);
	printf("repeating v1beta1_subject:\n%s\n", cJSON_Print(jsonv1beta1_subject_2));
}

int main() {
  test_v1beta1_subject(1);
  test_v1beta1_subject(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1beta1_subject_MAIN
#endif // v1beta1_subject_TEST
