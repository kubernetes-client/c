#ifndef v1_certificate_signing_request_spec_TEST
#define v1_certificate_signing_request_spec_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_certificate_signing_request_spec_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_certificate_signing_request_spec.h"
v1_certificate_signing_request_spec_t* instantiate_v1_certificate_signing_request_spec(int include_optional);



v1_certificate_signing_request_spec_t* instantiate_v1_certificate_signing_request_spec(int include_optional) {
  v1_certificate_signing_request_spec_t* v1_certificate_signing_request_spec = NULL;
  if (include_optional) {
    v1_certificate_signing_request_spec = v1_certificate_signing_request_spec_create(
      56,
      list_createList(),
      list_createList(),
      "YQ==",
      "0",
      "0",
      list_createList(),
      "0"
    );
  } else {
    v1_certificate_signing_request_spec = v1_certificate_signing_request_spec_create(
      56,
      list_createList(),
      list_createList(),
      "YQ==",
      "0",
      "0",
      list_createList(),
      "0"
    );
  }

  return v1_certificate_signing_request_spec;
}


#ifdef v1_certificate_signing_request_spec_MAIN

void test_v1_certificate_signing_request_spec(int include_optional) {
    v1_certificate_signing_request_spec_t* v1_certificate_signing_request_spec_1 = instantiate_v1_certificate_signing_request_spec(include_optional);

	cJSON* jsonv1_certificate_signing_request_spec_1 = v1_certificate_signing_request_spec_convertToJSON(v1_certificate_signing_request_spec_1);
	printf("v1_certificate_signing_request_spec :\n%s\n", cJSON_Print(jsonv1_certificate_signing_request_spec_1));
	v1_certificate_signing_request_spec_t* v1_certificate_signing_request_spec_2 = v1_certificate_signing_request_spec_parseFromJSON(jsonv1_certificate_signing_request_spec_1);
	cJSON* jsonv1_certificate_signing_request_spec_2 = v1_certificate_signing_request_spec_convertToJSON(v1_certificate_signing_request_spec_2);
	printf("repeating v1_certificate_signing_request_spec:\n%s\n", cJSON_Print(jsonv1_certificate_signing_request_spec_2));
}

int main() {
  test_v1_certificate_signing_request_spec(1);
  test_v1_certificate_signing_request_spec(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_certificate_signing_request_spec_MAIN
#endif // v1_certificate_signing_request_spec_TEST
