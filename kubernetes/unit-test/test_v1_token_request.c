#ifndef v1_token_request_TEST
#define v1_token_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_token_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_token_request.h"
v1_token_request_t* instantiate_v1_token_request(int include_optional);

#include "test_v1_object_meta.c"
#include "test_v1_token_request_spec.c"
#include "test_v1_token_request_status.c"


v1_token_request_t* instantiate_v1_token_request(int include_optional) {
  v1_token_request_t* v1_token_request = NULL;
  if (include_optional) {
    v1_token_request = v1_token_request_create(
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_v1_object_meta(0),
       // false, not to have infinite recursion
      instantiate_v1_token_request_spec(0),
       // false, not to have infinite recursion
      instantiate_v1_token_request_status(0)
    );
  } else {
    v1_token_request = v1_token_request_create(
      "0",
      "0",
      NULL,
      NULL,
      NULL
    );
  }

  return v1_token_request;
}


#ifdef v1_token_request_MAIN

void test_v1_token_request(int include_optional) {
    v1_token_request_t* v1_token_request_1 = instantiate_v1_token_request(include_optional);

	cJSON* jsonv1_token_request_1 = v1_token_request_convertToJSON(v1_token_request_1);
	printf("v1_token_request :\n%s\n", cJSON_Print(jsonv1_token_request_1));
	v1_token_request_t* v1_token_request_2 = v1_token_request_parseFromJSON(jsonv1_token_request_1);
	cJSON* jsonv1_token_request_2 = v1_token_request_convertToJSON(v1_token_request_2);
	printf("repeating v1_token_request:\n%s\n", cJSON_Print(jsonv1_token_request_2));
}

int main() {
  test_v1_token_request(1);
  test_v1_token_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_token_request_MAIN
#endif // v1_token_request_TEST
