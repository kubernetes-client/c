#ifndef v1_endpoint_hints_TEST
#define v1_endpoint_hints_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_endpoint_hints_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_endpoint_hints.h"
v1_endpoint_hints_t* instantiate_v1_endpoint_hints(int include_optional);



v1_endpoint_hints_t* instantiate_v1_endpoint_hints(int include_optional) {
  v1_endpoint_hints_t* v1_endpoint_hints = NULL;
  if (include_optional) {
    v1_endpoint_hints = v1_endpoint_hints_create(
      list_create()
    );
  } else {
    v1_endpoint_hints = v1_endpoint_hints_create(
      list_create()
    );
  }

  return v1_endpoint_hints;
}


#ifdef v1_endpoint_hints_MAIN

void test_v1_endpoint_hints(int include_optional) {
    v1_endpoint_hints_t* v1_endpoint_hints_1 = instantiate_v1_endpoint_hints(include_optional);

	cJSON* jsonv1_endpoint_hints_1 = v1_endpoint_hints_convertToJSON(v1_endpoint_hints_1);
	printf("v1_endpoint_hints :\n%s\n", cJSON_Print(jsonv1_endpoint_hints_1));
	v1_endpoint_hints_t* v1_endpoint_hints_2 = v1_endpoint_hints_parseFromJSON(jsonv1_endpoint_hints_1);
	cJSON* jsonv1_endpoint_hints_2 = v1_endpoint_hints_convertToJSON(v1_endpoint_hints_2);
	printf("repeating v1_endpoint_hints:\n%s\n", cJSON_Print(jsonv1_endpoint_hints_2));
}

int main() {
  test_v1_endpoint_hints(1);
  test_v1_endpoint_hints(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_endpoint_hints_MAIN
#endif // v1_endpoint_hints_TEST
