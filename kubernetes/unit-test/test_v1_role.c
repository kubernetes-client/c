#ifndef v1_role_TEST
#define v1_role_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_role_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_role.h"
v1_role_t* instantiate_v1_role(int include_optional);

#include "test_v1_object_meta.c"


v1_role_t* instantiate_v1_role(int include_optional) {
  v1_role_t* v1_role = NULL;
  if (include_optional) {
    v1_role = v1_role_create(
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_v1_object_meta(0),
      list_createList()
    );
  } else {
    v1_role = v1_role_create(
      "0",
      "0",
      NULL,
      list_createList()
    );
  }

  return v1_role;
}


#ifdef v1_role_MAIN

void test_v1_role(int include_optional) {
    v1_role_t* v1_role_1 = instantiate_v1_role(include_optional);

	cJSON* jsonv1_role_1 = v1_role_convertToJSON(v1_role_1);
	printf("v1_role :\n%s\n", cJSON_Print(jsonv1_role_1));
	v1_role_t* v1_role_2 = v1_role_parseFromJSON(jsonv1_role_1);
	cJSON* jsonv1_role_2 = v1_role_convertToJSON(v1_role_2);
	printf("repeating v1_role:\n%s\n", cJSON_Print(jsonv1_role_2));
}

int main() {
  test_v1_role(1);
  test_v1_role(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_role_MAIN
#endif // v1_role_TEST
