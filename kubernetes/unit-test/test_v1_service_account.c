#ifndef v1_service_account_TEST
#define v1_service_account_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_service_account_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_service_account.h"
v1_service_account_t* instantiate_v1_service_account(int include_optional);

#include "test_v1_object_meta.c"


v1_service_account_t* instantiate_v1_service_account(int include_optional) {
  v1_service_account_t* v1_service_account = NULL;
  if (include_optional) {
    v1_service_account = v1_service_account_create(
      "0",
      1,
      list_create(),
      "0",
       // false, not to have infinite recursion
      instantiate_v1_object_meta(0),
      list_create()
    );
  } else {
    v1_service_account = v1_service_account_create(
      "0",
      1,
      list_create(),
      "0",
      NULL,
      list_create()
    );
  }

  return v1_service_account;
}


#ifdef v1_service_account_MAIN

void test_v1_service_account(int include_optional) {
    v1_service_account_t* v1_service_account_1 = instantiate_v1_service_account(include_optional);

	cJSON* jsonv1_service_account_1 = v1_service_account_convertToJSON(v1_service_account_1);
	printf("v1_service_account :\n%s\n", cJSON_Print(jsonv1_service_account_1));
	v1_service_account_t* v1_service_account_2 = v1_service_account_parseFromJSON(jsonv1_service_account_1);
	cJSON* jsonv1_service_account_2 = v1_service_account_convertToJSON(v1_service_account_2);
	printf("repeating v1_service_account:\n%s\n", cJSON_Print(jsonv1_service_account_2));
}

int main() {
  test_v1_service_account(1);
  test_v1_service_account(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_service_account_MAIN
#endif // v1_service_account_TEST
