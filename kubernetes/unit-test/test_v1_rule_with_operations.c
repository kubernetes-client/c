#ifndef v1_rule_with_operations_TEST
#define v1_rule_with_operations_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_rule_with_operations_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_rule_with_operations.h"
v1_rule_with_operations_t* instantiate_v1_rule_with_operations(int include_optional);



v1_rule_with_operations_t* instantiate_v1_rule_with_operations(int include_optional) {
  v1_rule_with_operations_t* v1_rule_with_operations = NULL;
  if (include_optional) {
    v1_rule_with_operations = v1_rule_with_operations_create(
      list_create(),
      list_create(),
      list_create(),
      list_create(),
      "0"
    );
  } else {
    v1_rule_with_operations = v1_rule_with_operations_create(
      list_create(),
      list_create(),
      list_create(),
      list_create(),
      "0"
    );
  }

  return v1_rule_with_operations;
}


#ifdef v1_rule_with_operations_MAIN

void test_v1_rule_with_operations(int include_optional) {
    v1_rule_with_operations_t* v1_rule_with_operations_1 = instantiate_v1_rule_with_operations(include_optional);

	cJSON* jsonv1_rule_with_operations_1 = v1_rule_with_operations_convertToJSON(v1_rule_with_operations_1);
	printf("v1_rule_with_operations :\n%s\n", cJSON_Print(jsonv1_rule_with_operations_1));
	v1_rule_with_operations_t* v1_rule_with_operations_2 = v1_rule_with_operations_parseFromJSON(jsonv1_rule_with_operations_1);
	cJSON* jsonv1_rule_with_operations_2 = v1_rule_with_operations_convertToJSON(v1_rule_with_operations_2);
	printf("repeating v1_rule_with_operations:\n%s\n", cJSON_Print(jsonv1_rule_with_operations_2));
}

int main() {
  test_v1_rule_with_operations(1);
  test_v1_rule_with_operations(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_rule_with_operations_MAIN
#endif // v1_rule_with_operations_TEST
