#ifndef v2beta2_hpa_scaling_rules_TEST
#define v2beta2_hpa_scaling_rules_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v2beta2_hpa_scaling_rules_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v2beta2_hpa_scaling_rules.h"
v2beta2_hpa_scaling_rules_t* instantiate_v2beta2_hpa_scaling_rules(int include_optional);



v2beta2_hpa_scaling_rules_t* instantiate_v2beta2_hpa_scaling_rules(int include_optional) {
  v2beta2_hpa_scaling_rules_t* v2beta2_hpa_scaling_rules = NULL;
  if (include_optional) {
    v2beta2_hpa_scaling_rules = v2beta2_hpa_scaling_rules_create(
      list_createList(),
      "0",
      56
    );
  } else {
    v2beta2_hpa_scaling_rules = v2beta2_hpa_scaling_rules_create(
      list_createList(),
      "0",
      56
    );
  }

  return v2beta2_hpa_scaling_rules;
}


#ifdef v2beta2_hpa_scaling_rules_MAIN

void test_v2beta2_hpa_scaling_rules(int include_optional) {
    v2beta2_hpa_scaling_rules_t* v2beta2_hpa_scaling_rules_1 = instantiate_v2beta2_hpa_scaling_rules(include_optional);

	cJSON* jsonv2beta2_hpa_scaling_rules_1 = v2beta2_hpa_scaling_rules_convertToJSON(v2beta2_hpa_scaling_rules_1);
	printf("v2beta2_hpa_scaling_rules :\n%s\n", cJSON_Print(jsonv2beta2_hpa_scaling_rules_1));
	v2beta2_hpa_scaling_rules_t* v2beta2_hpa_scaling_rules_2 = v2beta2_hpa_scaling_rules_parseFromJSON(jsonv2beta2_hpa_scaling_rules_1);
	cJSON* jsonv2beta2_hpa_scaling_rules_2 = v2beta2_hpa_scaling_rules_convertToJSON(v2beta2_hpa_scaling_rules_2);
	printf("repeating v2beta2_hpa_scaling_rules:\n%s\n", cJSON_Print(jsonv2beta2_hpa_scaling_rules_2));
}

int main() {
  test_v2beta2_hpa_scaling_rules(1);
  test_v2beta2_hpa_scaling_rules(0);

  printf("Hello world \n");
  return 0;
}

#endif // v2beta2_hpa_scaling_rules_MAIN
#endif // v2beta2_hpa_scaling_rules_TEST
