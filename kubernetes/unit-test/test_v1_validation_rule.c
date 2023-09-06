#ifndef v1_validation_rule_TEST
#define v1_validation_rule_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_validation_rule_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_validation_rule.h"
v1_validation_rule_t* instantiate_v1_validation_rule(int include_optional);



v1_validation_rule_t* instantiate_v1_validation_rule(int include_optional) {
  v1_validation_rule_t* v1_validation_rule = NULL;
  if (include_optional) {
    v1_validation_rule = v1_validation_rule_create(
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  } else {
    v1_validation_rule = v1_validation_rule_create(
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  }

  return v1_validation_rule;
}


#ifdef v1_validation_rule_MAIN

void test_v1_validation_rule(int include_optional) {
    v1_validation_rule_t* v1_validation_rule_1 = instantiate_v1_validation_rule(include_optional);

	cJSON* jsonv1_validation_rule_1 = v1_validation_rule_convertToJSON(v1_validation_rule_1);
	printf("v1_validation_rule :\n%s\n", cJSON_Print(jsonv1_validation_rule_1));
	v1_validation_rule_t* v1_validation_rule_2 = v1_validation_rule_parseFromJSON(jsonv1_validation_rule_1);
	cJSON* jsonv1_validation_rule_2 = v1_validation_rule_convertToJSON(v1_validation_rule_2);
	printf("repeating v1_validation_rule:\n%s\n", cJSON_Print(jsonv1_validation_rule_2));
}

int main() {
  test_v1_validation_rule(1);
  test_v1_validation_rule(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_validation_rule_MAIN
#endif // v1_validation_rule_TEST
