#ifndef v1beta1_certificate_signing_request_TEST
#define v1beta1_certificate_signing_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1beta1_certificate_signing_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1beta1_certificate_signing_request.h"
v1beta1_certificate_signing_request_t* instantiate_v1beta1_certificate_signing_request(int include_optional);

#include "test_v1_object_meta.c"
#include "test_v1beta1_certificate_signing_request_spec.c"
#include "test_v1beta1_certificate_signing_request_status.c"


v1beta1_certificate_signing_request_t* instantiate_v1beta1_certificate_signing_request(int include_optional) {
  v1beta1_certificate_signing_request_t* v1beta1_certificate_signing_request = NULL;
  if (include_optional) {
    v1beta1_certificate_signing_request = v1beta1_certificate_signing_request_create(
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_v1_object_meta(0),
       // false, not to have infinite recursion
      instantiate_v1beta1_certificate_signing_request_spec(0),
       // false, not to have infinite recursion
      instantiate_v1beta1_certificate_signing_request_status(0)
    );
  } else {
    v1beta1_certificate_signing_request = v1beta1_certificate_signing_request_create(
      "0",
      "0",
      NULL,
      NULL,
      NULL
    );
  }

  return v1beta1_certificate_signing_request;
}


#ifdef v1beta1_certificate_signing_request_MAIN

void test_v1beta1_certificate_signing_request(int include_optional) {
    v1beta1_certificate_signing_request_t* v1beta1_certificate_signing_request_1 = instantiate_v1beta1_certificate_signing_request(include_optional);

	cJSON* jsonv1beta1_certificate_signing_request_1 = v1beta1_certificate_signing_request_convertToJSON(v1beta1_certificate_signing_request_1);
	printf("v1beta1_certificate_signing_request :\n%s\n", cJSON_Print(jsonv1beta1_certificate_signing_request_1));
	v1beta1_certificate_signing_request_t* v1beta1_certificate_signing_request_2 = v1beta1_certificate_signing_request_parseFromJSON(jsonv1beta1_certificate_signing_request_1);
	cJSON* jsonv1beta1_certificate_signing_request_2 = v1beta1_certificate_signing_request_convertToJSON(v1beta1_certificate_signing_request_2);
	printf("repeating v1beta1_certificate_signing_request:\n%s\n", cJSON_Print(jsonv1beta1_certificate_signing_request_2));
}

int main() {
  test_v1beta1_certificate_signing_request(1);
  test_v1beta1_certificate_signing_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1beta1_certificate_signing_request_MAIN
#endif // v1beta1_certificate_signing_request_TEST
