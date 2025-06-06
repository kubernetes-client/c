#ifndef v2_hpa_scaling_rules_TEST
#define v2_hpa_scaling_rules_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v2_hpa_scaling_rules_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v2_hpa_scaling_rules.h"
v2_hpa_scaling_rules_t* instantiate_v2_hpa_scaling_rules(int include_optional);



v2_hpa_scaling_rules_t* instantiate_v2_hpa_scaling_rules(int include_optional) {
  v2_hpa_scaling_rules_t* v2_hpa_scaling_rules = NULL;
  if (include_optional) {
    v2_hpa_scaling_rules = v2_hpa_scaling_rules_create(
      list_createList(),
      "0",
      56,
      "0"
    );
  } else {
    v2_hpa_scaling_rules = v2_hpa_scaling_rules_create(
      list_createList(),
      "0",
      56,
      "0"
    );
  }

  return v2_hpa_scaling_rules;
}


#ifdef v2_hpa_scaling_rules_MAIN

void test_v2_hpa_scaling_rules(int include_optional) {
    v2_hpa_scaling_rules_t* v2_hpa_scaling_rules_1 = instantiate_v2_hpa_scaling_rules(include_optional);

	cJSON* jsonv2_hpa_scaling_rules_1 = v2_hpa_scaling_rules_convertToJSON(v2_hpa_scaling_rules_1);
	printf("v2_hpa_scaling_rules :\n%s\n", cJSON_Print(jsonv2_hpa_scaling_rules_1));
	v2_hpa_scaling_rules_t* v2_hpa_scaling_rules_2 = v2_hpa_scaling_rules_parseFromJSON(jsonv2_hpa_scaling_rules_1);
	cJSON* jsonv2_hpa_scaling_rules_2 = v2_hpa_scaling_rules_convertToJSON(v2_hpa_scaling_rules_2);
	printf("repeating v2_hpa_scaling_rules:\n%s\n", cJSON_Print(jsonv2_hpa_scaling_rules_2));
}

int main() {
  test_v2_hpa_scaling_rules(1);
  test_v2_hpa_scaling_rules(0);

  printf("Hello world \n");
  return 0;
}

#endif // v2_hpa_scaling_rules_MAIN
#endif // v2_hpa_scaling_rules_TEST
