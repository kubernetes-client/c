#ifndef v1beta1_certificate_signing_request_condition_TEST
#define v1beta1_certificate_signing_request_condition_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1beta1_certificate_signing_request_condition_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1beta1_certificate_signing_request_condition.h"
v1beta1_certificate_signing_request_condition_t* instantiate_v1beta1_certificate_signing_request_condition(int include_optional);



v1beta1_certificate_signing_request_condition_t* instantiate_v1beta1_certificate_signing_request_condition(int include_optional) {
  v1beta1_certificate_signing_request_condition_t* v1beta1_certificate_signing_request_condition = NULL;
  if (include_optional) {
    v1beta1_certificate_signing_request_condition = v1beta1_certificate_signing_request_condition_create(
      "2013-10-20T19:20:30+01:00",
      "0",
      "0",
      "0"
    );
  } else {
    v1beta1_certificate_signing_request_condition = v1beta1_certificate_signing_request_condition_create(
      "2013-10-20T19:20:30+01:00",
      "0",
      "0",
      "0"
    );
  }

  return v1beta1_certificate_signing_request_condition;
}


#ifdef v1beta1_certificate_signing_request_condition_MAIN

void test_v1beta1_certificate_signing_request_condition(int include_optional) {
    v1beta1_certificate_signing_request_condition_t* v1beta1_certificate_signing_request_condition_1 = instantiate_v1beta1_certificate_signing_request_condition(include_optional);

	cJSON* jsonv1beta1_certificate_signing_request_condition_1 = v1beta1_certificate_signing_request_condition_convertToJSON(v1beta1_certificate_signing_request_condition_1);
	printf("v1beta1_certificate_signing_request_condition :\n%s\n", cJSON_Print(jsonv1beta1_certificate_signing_request_condition_1));
	v1beta1_certificate_signing_request_condition_t* v1beta1_certificate_signing_request_condition_2 = v1beta1_certificate_signing_request_condition_parseFromJSON(jsonv1beta1_certificate_signing_request_condition_1);
	cJSON* jsonv1beta1_certificate_signing_request_condition_2 = v1beta1_certificate_signing_request_condition_convertToJSON(v1beta1_certificate_signing_request_condition_2);
	printf("repeating v1beta1_certificate_signing_request_condition:\n%s\n", cJSON_Print(jsonv1beta1_certificate_signing_request_condition_2));
}

int main() {
  test_v1beta1_certificate_signing_request_condition(1);
  test_v1beta1_certificate_signing_request_condition(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1beta1_certificate_signing_request_condition_MAIN
#endif // v1beta1_certificate_signing_request_condition_TEST
