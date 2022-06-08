#ifndef v1_namespace_condition_TEST
#define v1_namespace_condition_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_namespace_condition_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_namespace_condition.h"
v1_namespace_condition_t* instantiate_v1_namespace_condition(int include_optional);



v1_namespace_condition_t* instantiate_v1_namespace_condition(int include_optional) {
  v1_namespace_condition_t* v1_namespace_condition = NULL;
  if (include_optional) {
    v1_namespace_condition = v1_namespace_condition_create(
      "2013-10-20T19:20:30+01:00",
      "0",
      "0",
      "0",
      "0"
    );
  } else {
    v1_namespace_condition = v1_namespace_condition_create(
      "2013-10-20T19:20:30+01:00",
      "0",
      "0",
      "0",
      "0"
    );
  }

  return v1_namespace_condition;
}


#ifdef v1_namespace_condition_MAIN

void test_v1_namespace_condition(int include_optional) {
    v1_namespace_condition_t* v1_namespace_condition_1 = instantiate_v1_namespace_condition(include_optional);

	cJSON* jsonv1_namespace_condition_1 = v1_namespace_condition_convertToJSON(v1_namespace_condition_1);
	printf("v1_namespace_condition :\n%s\n", cJSON_Print(jsonv1_namespace_condition_1));
	v1_namespace_condition_t* v1_namespace_condition_2 = v1_namespace_condition_parseFromJSON(jsonv1_namespace_condition_1);
	cJSON* jsonv1_namespace_condition_2 = v1_namespace_condition_convertToJSON(v1_namespace_condition_2);
	printf("repeating v1_namespace_condition:\n%s\n", cJSON_Print(jsonv1_namespace_condition_2));
}

int main() {
  test_v1_namespace_condition(1);
  test_v1_namespace_condition(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_namespace_condition_MAIN
#endif // v1_namespace_condition_TEST
