#ifndef v1_service_account_subject_TEST
#define v1_service_account_subject_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_service_account_subject_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_service_account_subject.h"
v1_service_account_subject_t* instantiate_v1_service_account_subject(int include_optional);



v1_service_account_subject_t* instantiate_v1_service_account_subject(int include_optional) {
  v1_service_account_subject_t* v1_service_account_subject = NULL;
  if (include_optional) {
    v1_service_account_subject = v1_service_account_subject_create(
      "0",
      "0"
    );
  } else {
    v1_service_account_subject = v1_service_account_subject_create(
      "0",
      "0"
    );
  }

  return v1_service_account_subject;
}


#ifdef v1_service_account_subject_MAIN

void test_v1_service_account_subject(int include_optional) {
    v1_service_account_subject_t* v1_service_account_subject_1 = instantiate_v1_service_account_subject(include_optional);

	cJSON* jsonv1_service_account_subject_1 = v1_service_account_subject_convertToJSON(v1_service_account_subject_1);
	printf("v1_service_account_subject :\n%s\n", cJSON_Print(jsonv1_service_account_subject_1));
	v1_service_account_subject_t* v1_service_account_subject_2 = v1_service_account_subject_parseFromJSON(jsonv1_service_account_subject_1);
	cJSON* jsonv1_service_account_subject_2 = v1_service_account_subject_convertToJSON(v1_service_account_subject_2);
	printf("repeating v1_service_account_subject:\n%s\n", cJSON_Print(jsonv1_service_account_subject_2));
}

int main() {
  test_v1_service_account_subject(1);
  test_v1_service_account_subject(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_service_account_subject_MAIN
#endif // v1_service_account_subject_TEST
