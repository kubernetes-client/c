#ifndef v1beta1_rule_with_operations_TEST
#define v1beta1_rule_with_operations_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1beta1_rule_with_operations_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1beta1_rule_with_operations.h"
v1beta1_rule_with_operations_t* instantiate_v1beta1_rule_with_operations(int include_optional);



v1beta1_rule_with_operations_t* instantiate_v1beta1_rule_with_operations(int include_optional) {
  v1beta1_rule_with_operations_t* v1beta1_rule_with_operations = NULL;
  if (include_optional) {
    v1beta1_rule_with_operations = v1beta1_rule_with_operations_create(
      list_create(),
      list_create(),
      list_create(),
      list_create(),
      "0"
    );
  } else {
    v1beta1_rule_with_operations = v1beta1_rule_with_operations_create(
      list_create(),
      list_create(),
      list_create(),
      list_create(),
      "0"
    );
  }

  return v1beta1_rule_with_operations;
}


#ifdef v1beta1_rule_with_operations_MAIN

void test_v1beta1_rule_with_operations(int include_optional) {
    v1beta1_rule_with_operations_t* v1beta1_rule_with_operations_1 = instantiate_v1beta1_rule_with_operations(include_optional);

	cJSON* jsonv1beta1_rule_with_operations_1 = v1beta1_rule_with_operations_convertToJSON(v1beta1_rule_with_operations_1);
	printf("v1beta1_rule_with_operations :\n%s\n", cJSON_Print(jsonv1beta1_rule_with_operations_1));
	v1beta1_rule_with_operations_t* v1beta1_rule_with_operations_2 = v1beta1_rule_with_operations_parseFromJSON(jsonv1beta1_rule_with_operations_1);
	cJSON* jsonv1beta1_rule_with_operations_2 = v1beta1_rule_with_operations_convertToJSON(v1beta1_rule_with_operations_2);
	printf("repeating v1beta1_rule_with_operations:\n%s\n", cJSON_Print(jsonv1beta1_rule_with_operations_2));
}

int main() {
  test_v1beta1_rule_with_operations(1);
  test_v1beta1_rule_with_operations(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1beta1_rule_with_operations_MAIN
#endif // v1beta1_rule_with_operations_TEST
