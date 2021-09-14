#ifndef authentication_v1_token_request_TEST
#define authentication_v1_token_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define authentication_v1_token_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/authentication_v1_token_request.h"
authentication_v1_token_request_t* instantiate_authentication_v1_token_request(int include_optional);

#include "test_v1_object_meta.c"
#include "test_v1_token_request_spec.c"
#include "test_v1_token_request_status.c"


authentication_v1_token_request_t* instantiate_authentication_v1_token_request(int include_optional) {
  authentication_v1_token_request_t* authentication_v1_token_request = NULL;
  if (include_optional) {
    authentication_v1_token_request = authentication_v1_token_request_create(
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
    authentication_v1_token_request = authentication_v1_token_request_create(
      "0",
      "0",
      NULL,
      NULL,
      NULL
    );
  }

  return authentication_v1_token_request;
}


#ifdef authentication_v1_token_request_MAIN

void test_authentication_v1_token_request(int include_optional) {
    authentication_v1_token_request_t* authentication_v1_token_request_1 = instantiate_authentication_v1_token_request(include_optional);

	cJSON* jsonauthentication_v1_token_request_1 = authentication_v1_token_request_convertToJSON(authentication_v1_token_request_1);
	printf("authentication_v1_token_request :\n%s\n", cJSON_Print(jsonauthentication_v1_token_request_1));
	authentication_v1_token_request_t* authentication_v1_token_request_2 = authentication_v1_token_request_parseFromJSON(jsonauthentication_v1_token_request_1);
	cJSON* jsonauthentication_v1_token_request_2 = authentication_v1_token_request_convertToJSON(authentication_v1_token_request_2);
	printf("repeating authentication_v1_token_request:\n%s\n", cJSON_Print(jsonauthentication_v1_token_request_2));
}

int main() {
  test_authentication_v1_token_request(1);
  test_authentication_v1_token_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // authentication_v1_token_request_MAIN
#endif // authentication_v1_token_request_TEST
