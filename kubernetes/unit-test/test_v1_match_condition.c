#ifndef v1_match_condition_TEST
#define v1_match_condition_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_match_condition_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_match_condition.h"
v1_match_condition_t* instantiate_v1_match_condition(int include_optional);



v1_match_condition_t* instantiate_v1_match_condition(int include_optional) {
  v1_match_condition_t* v1_match_condition = NULL;
  if (include_optional) {
    v1_match_condition = v1_match_condition_create(
      "0",
      "0"
    );
  } else {
    v1_match_condition = v1_match_condition_create(
      "0",
      "0"
    );
  }

  return v1_match_condition;
}


#ifdef v1_match_condition_MAIN

void test_v1_match_condition(int include_optional) {
    v1_match_condition_t* v1_match_condition_1 = instantiate_v1_match_condition(include_optional);

	cJSON* jsonv1_match_condition_1 = v1_match_condition_convertToJSON(v1_match_condition_1);
	printf("v1_match_condition :\n%s\n", cJSON_Print(jsonv1_match_condition_1));
	v1_match_condition_t* v1_match_condition_2 = v1_match_condition_parseFromJSON(jsonv1_match_condition_1);
	cJSON* jsonv1_match_condition_2 = v1_match_condition_convertToJSON(v1_match_condition_2);
	printf("repeating v1_match_condition:\n%s\n", cJSON_Print(jsonv1_match_condition_2));
}

int main() {
  test_v1_match_condition(1);
  test_v1_match_condition(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_match_condition_MAIN
#endif // v1_match_condition_TEST
