#ifndef v1beta1_aggregation_rule_TEST
#define v1beta1_aggregation_rule_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1beta1_aggregation_rule_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1beta1_aggregation_rule.h"
v1beta1_aggregation_rule_t* instantiate_v1beta1_aggregation_rule(int include_optional);



v1beta1_aggregation_rule_t* instantiate_v1beta1_aggregation_rule(int include_optional) {
  v1beta1_aggregation_rule_t* v1beta1_aggregation_rule = NULL;
  if (include_optional) {
    v1beta1_aggregation_rule = v1beta1_aggregation_rule_create(
      list_create()
    );
  } else {
    v1beta1_aggregation_rule = v1beta1_aggregation_rule_create(
      list_create()
    );
  }

  return v1beta1_aggregation_rule;
}


#ifdef v1beta1_aggregation_rule_MAIN

void test_v1beta1_aggregation_rule(int include_optional) {
    v1beta1_aggregation_rule_t* v1beta1_aggregation_rule_1 = instantiate_v1beta1_aggregation_rule(include_optional);

	cJSON* jsonv1beta1_aggregation_rule_1 = v1beta1_aggregation_rule_convertToJSON(v1beta1_aggregation_rule_1);
	printf("v1beta1_aggregation_rule :\n%s\n", cJSON_Print(jsonv1beta1_aggregation_rule_1));
	v1beta1_aggregation_rule_t* v1beta1_aggregation_rule_2 = v1beta1_aggregation_rule_parseFromJSON(jsonv1beta1_aggregation_rule_1);
	cJSON* jsonv1beta1_aggregation_rule_2 = v1beta1_aggregation_rule_convertToJSON(v1beta1_aggregation_rule_2);
	printf("repeating v1beta1_aggregation_rule:\n%s\n", cJSON_Print(jsonv1beta1_aggregation_rule_2));
}

int main() {
  test_v1beta1_aggregation_rule(1);
  test_v1beta1_aggregation_rule(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1beta1_aggregation_rule_MAIN
#endif // v1beta1_aggregation_rule_TEST
