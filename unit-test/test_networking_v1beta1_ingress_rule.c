#ifndef networking_v1beta1_ingress_rule_TEST
#define networking_v1beta1_ingress_rule_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define networking_v1beta1_ingress_rule_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/networking_v1beta1_ingress_rule.h"
networking_v1beta1_ingress_rule_t* instantiate_networking_v1beta1_ingress_rule(int include_optional);

#include "test_networking_v1beta1_http_ingress_rule_value.c"


networking_v1beta1_ingress_rule_t* instantiate_networking_v1beta1_ingress_rule(int include_optional) {
  networking_v1beta1_ingress_rule_t* networking_v1beta1_ingress_rule = NULL;
  if (include_optional) {
    networking_v1beta1_ingress_rule = networking_v1beta1_ingress_rule_create(
      "0",
       // false, not to have infinite recursion
      instantiate_networking_v1beta1_http_ingress_rule_value(0)
    );
  } else {
    networking_v1beta1_ingress_rule = networking_v1beta1_ingress_rule_create(
      "0",
      NULL
    );
  }

  return networking_v1beta1_ingress_rule;
}


#ifdef networking_v1beta1_ingress_rule_MAIN

void test_networking_v1beta1_ingress_rule(int include_optional) {
    networking_v1beta1_ingress_rule_t* networking_v1beta1_ingress_rule_1 = instantiate_networking_v1beta1_ingress_rule(include_optional);

	cJSON* jsonnetworking_v1beta1_ingress_rule_1 = networking_v1beta1_ingress_rule_convertToJSON(networking_v1beta1_ingress_rule_1);
	printf("networking_v1beta1_ingress_rule :\n%s\n", cJSON_Print(jsonnetworking_v1beta1_ingress_rule_1));
	networking_v1beta1_ingress_rule_t* networking_v1beta1_ingress_rule_2 = networking_v1beta1_ingress_rule_parseFromJSON(jsonnetworking_v1beta1_ingress_rule_1);
	cJSON* jsonnetworking_v1beta1_ingress_rule_2 = networking_v1beta1_ingress_rule_convertToJSON(networking_v1beta1_ingress_rule_2);
	printf("repeating networking_v1beta1_ingress_rule:\n%s\n", cJSON_Print(jsonnetworking_v1beta1_ingress_rule_2));
}

int main() {
  test_networking_v1beta1_ingress_rule(1);
  test_networking_v1beta1_ingress_rule(0);

  printf("Hello world \n");
  return 0;
}

#endif // networking_v1beta1_ingress_rule_MAIN
#endif // networking_v1beta1_ingress_rule_TEST
