#ifndef v1_secret_TEST
#define v1_secret_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_secret_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_secret.h"
v1_secret_t* instantiate_v1_secret(int include_optional);

#include "test_v1_object_meta.c"


v1_secret_t* instantiate_v1_secret(int include_optional) {
  v1_secret_t* v1_secret = NULL;
  if (include_optional) {
    v1_secret = v1_secret_create(
      "0",
      list_create(),
      "0",
       // false, not to have infinite recursion
      instantiate_v1_object_meta(0),
      list_create(),
      "0"
    );
  } else {
    v1_secret = v1_secret_create(
      "0",
      list_create(),
      "0",
      NULL,
      list_create(),
      "0"
    );
  }

  return v1_secret;
}


#ifdef v1_secret_MAIN

void test_v1_secret(int include_optional) {
    v1_secret_t* v1_secret_1 = instantiate_v1_secret(include_optional);

	cJSON* jsonv1_secret_1 = v1_secret_convertToJSON(v1_secret_1);
	printf("v1_secret :\n%s\n", cJSON_Print(jsonv1_secret_1));
	v1_secret_t* v1_secret_2 = v1_secret_parseFromJSON(jsonv1_secret_1);
	cJSON* jsonv1_secret_2 = v1_secret_convertToJSON(v1_secret_2);
	printf("repeating v1_secret:\n%s\n", cJSON_Print(jsonv1_secret_2));
}

int main() {
  test_v1_secret(1);
  test_v1_secret(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_secret_MAIN
#endif // v1_secret_TEST
