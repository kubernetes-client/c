#ifndef extensions_v1beta1_ingress_rule_TEST
#define extensions_v1beta1_ingress_rule_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define extensions_v1beta1_ingress_rule_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/extensions_v1beta1_ingress_rule.h"
extensions_v1beta1_ingress_rule_t* instantiate_extensions_v1beta1_ingress_rule(int include_optional);

#include "test_extensions_v1beta1_http_ingress_rule_value.c"


extensions_v1beta1_ingress_rule_t* instantiate_extensions_v1beta1_ingress_rule(int include_optional) {
  extensions_v1beta1_ingress_rule_t* extensions_v1beta1_ingress_rule = NULL;
  if (include_optional) {
    extensions_v1beta1_ingress_rule = extensions_v1beta1_ingress_rule_create(
      "0",
       // false, not to have infinite recursion
      instantiate_extensions_v1beta1_http_ingress_rule_value(0)
    );
  } else {
    extensions_v1beta1_ingress_rule = extensions_v1beta1_ingress_rule_create(
      "0",
      NULL
    );
  }

  return extensions_v1beta1_ingress_rule;
}


#ifdef extensions_v1beta1_ingress_rule_MAIN

void test_extensions_v1beta1_ingress_rule(int include_optional) {
    extensions_v1beta1_ingress_rule_t* extensions_v1beta1_ingress_rule_1 = instantiate_extensions_v1beta1_ingress_rule(include_optional);

	cJSON* jsonextensions_v1beta1_ingress_rule_1 = extensions_v1beta1_ingress_rule_convertToJSON(extensions_v1beta1_ingress_rule_1);
	printf("extensions_v1beta1_ingress_rule :\n%s\n", cJSON_Print(jsonextensions_v1beta1_ingress_rule_1));
	extensions_v1beta1_ingress_rule_t* extensions_v1beta1_ingress_rule_2 = extensions_v1beta1_ingress_rule_parseFromJSON(jsonextensions_v1beta1_ingress_rule_1);
	cJSON* jsonextensions_v1beta1_ingress_rule_2 = extensions_v1beta1_ingress_rule_convertToJSON(extensions_v1beta1_ingress_rule_2);
	printf("repeating extensions_v1beta1_ingress_rule:\n%s\n", cJSON_Print(jsonextensions_v1beta1_ingress_rule_2));
}

int main() {
  test_extensions_v1beta1_ingress_rule(1);
  test_extensions_v1beta1_ingress_rule(0);

  printf("Hello world \n");
  return 0;
}

#endif // extensions_v1beta1_ingress_rule_MAIN
#endif // extensions_v1beta1_ingress_rule_TEST
