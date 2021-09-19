#ifndef v1_ingress_rule_TEST
#define v1_ingress_rule_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_ingress_rule_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_ingress_rule.h"
v1_ingress_rule_t* instantiate_v1_ingress_rule(int include_optional);

#include "test_v1_http_ingress_rule_value.c"


v1_ingress_rule_t* instantiate_v1_ingress_rule(int include_optional) {
  v1_ingress_rule_t* v1_ingress_rule = NULL;
  if (include_optional) {
    v1_ingress_rule = v1_ingress_rule_create(
      "0",
       // false, not to have infinite recursion
      instantiate_v1_http_ingress_rule_value(0)
    );
  } else {
    v1_ingress_rule = v1_ingress_rule_create(
      "0",
      NULL
    );
  }

  return v1_ingress_rule;
}


#ifdef v1_ingress_rule_MAIN

void test_v1_ingress_rule(int include_optional) {
    v1_ingress_rule_t* v1_ingress_rule_1 = instantiate_v1_ingress_rule(include_optional);

	cJSON* jsonv1_ingress_rule_1 = v1_ingress_rule_convertToJSON(v1_ingress_rule_1);
	printf("v1_ingress_rule :\n%s\n", cJSON_Print(jsonv1_ingress_rule_1));
	v1_ingress_rule_t* v1_ingress_rule_2 = v1_ingress_rule_parseFromJSON(jsonv1_ingress_rule_1);
	cJSON* jsonv1_ingress_rule_2 = v1_ingress_rule_convertToJSON(v1_ingress_rule_2);
	printf("repeating v1_ingress_rule:\n%s\n", cJSON_Print(jsonv1_ingress_rule_2));
}

int main() {
  test_v1_ingress_rule(1);
  test_v1_ingress_rule(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_ingress_rule_MAIN
#endif // v1_ingress_rule_TEST
