#ifndef v1_http_ingress_rule_value_TEST
#define v1_http_ingress_rule_value_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_http_ingress_rule_value_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_http_ingress_rule_value.h"
v1_http_ingress_rule_value_t* instantiate_v1_http_ingress_rule_value(int include_optional);



v1_http_ingress_rule_value_t* instantiate_v1_http_ingress_rule_value(int include_optional) {
  v1_http_ingress_rule_value_t* v1_http_ingress_rule_value = NULL;
  if (include_optional) {
    v1_http_ingress_rule_value = v1_http_ingress_rule_value_create(
      list_createList()
    );
  } else {
    v1_http_ingress_rule_value = v1_http_ingress_rule_value_create(
      list_createList()
    );
  }

  return v1_http_ingress_rule_value;
}


#ifdef v1_http_ingress_rule_value_MAIN

void test_v1_http_ingress_rule_value(int include_optional) {
    v1_http_ingress_rule_value_t* v1_http_ingress_rule_value_1 = instantiate_v1_http_ingress_rule_value(include_optional);

	cJSON* jsonv1_http_ingress_rule_value_1 = v1_http_ingress_rule_value_convertToJSON(v1_http_ingress_rule_value_1);
	printf("v1_http_ingress_rule_value :\n%s\n", cJSON_Print(jsonv1_http_ingress_rule_value_1));
	v1_http_ingress_rule_value_t* v1_http_ingress_rule_value_2 = v1_http_ingress_rule_value_parseFromJSON(jsonv1_http_ingress_rule_value_1);
	cJSON* jsonv1_http_ingress_rule_value_2 = v1_http_ingress_rule_value_convertToJSON(v1_http_ingress_rule_value_2);
	printf("repeating v1_http_ingress_rule_value:\n%s\n", cJSON_Print(jsonv1_http_ingress_rule_value_2));
}

int main() {
  test_v1_http_ingress_rule_value(1);
  test_v1_http_ingress_rule_value(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_http_ingress_rule_value_MAIN
#endif // v1_http_ingress_rule_value_TEST
