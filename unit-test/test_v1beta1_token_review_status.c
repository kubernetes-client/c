#ifndef v1beta1_token_review_status_TEST
#define v1beta1_token_review_status_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1beta1_token_review_status_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1beta1_token_review_status.h"
v1beta1_token_review_status_t* instantiate_v1beta1_token_review_status(int include_optional);

#include "test_v1beta1_user_info.c"


v1beta1_token_review_status_t* instantiate_v1beta1_token_review_status(int include_optional) {
  v1beta1_token_review_status_t* v1beta1_token_review_status = NULL;
  if (include_optional) {
    v1beta1_token_review_status = v1beta1_token_review_status_create(
      list_create(),
      1,
      "0",
       // false, not to have infinite recursion
      instantiate_v1beta1_user_info(0)
    );
  } else {
    v1beta1_token_review_status = v1beta1_token_review_status_create(
      list_create(),
      1,
      "0",
      NULL
    );
  }

  return v1beta1_token_review_status;
}


#ifdef v1beta1_token_review_status_MAIN

void test_v1beta1_token_review_status(int include_optional) {
    v1beta1_token_review_status_t* v1beta1_token_review_status_1 = instantiate_v1beta1_token_review_status(include_optional);

	cJSON* jsonv1beta1_token_review_status_1 = v1beta1_token_review_status_convertToJSON(v1beta1_token_review_status_1);
	printf("v1beta1_token_review_status :\n%s\n", cJSON_Print(jsonv1beta1_token_review_status_1));
	v1beta1_token_review_status_t* v1beta1_token_review_status_2 = v1beta1_token_review_status_parseFromJSON(jsonv1beta1_token_review_status_1);
	cJSON* jsonv1beta1_token_review_status_2 = v1beta1_token_review_status_convertToJSON(v1beta1_token_review_status_2);
	printf("repeating v1beta1_token_review_status:\n%s\n", cJSON_Print(jsonv1beta1_token_review_status_2));
}

int main() {
  test_v1beta1_token_review_status(1);
  test_v1beta1_token_review_status(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1beta1_token_review_status_MAIN
#endif // v1beta1_token_review_status_TEST
