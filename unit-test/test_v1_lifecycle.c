#ifndef v1_lifecycle_TEST
#define v1_lifecycle_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_lifecycle_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_lifecycle.h"
v1_lifecycle_t* instantiate_v1_lifecycle(int include_optional);

#include "test_v1_handler.c"
#include "test_v1_handler.c"


v1_lifecycle_t* instantiate_v1_lifecycle(int include_optional) {
  v1_lifecycle_t* v1_lifecycle = NULL;
  if (include_optional) {
    v1_lifecycle = v1_lifecycle_create(
       // false, not to have infinite recursion
      instantiate_v1_handler(0),
       // false, not to have infinite recursion
      instantiate_v1_handler(0)
    );
  } else {
    v1_lifecycle = v1_lifecycle_create(
      NULL,
      NULL
    );
  }

  return v1_lifecycle;
}


#ifdef v1_lifecycle_MAIN

void test_v1_lifecycle(int include_optional) {
    v1_lifecycle_t* v1_lifecycle_1 = instantiate_v1_lifecycle(include_optional);

	cJSON* jsonv1_lifecycle_1 = v1_lifecycle_convertToJSON(v1_lifecycle_1);
	printf("v1_lifecycle :\n%s\n", cJSON_Print(jsonv1_lifecycle_1));
	v1_lifecycle_t* v1_lifecycle_2 = v1_lifecycle_parseFromJSON(jsonv1_lifecycle_1);
	cJSON* jsonv1_lifecycle_2 = v1_lifecycle_convertToJSON(v1_lifecycle_2);
	printf("repeating v1_lifecycle:\n%s\n", cJSON_Print(jsonv1_lifecycle_2));
}

int main() {
  test_v1_lifecycle(1);
  test_v1_lifecycle(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_lifecycle_MAIN
#endif // v1_lifecycle_TEST
