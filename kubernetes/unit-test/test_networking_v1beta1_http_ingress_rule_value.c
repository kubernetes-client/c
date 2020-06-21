#ifndef networking_v1beta1_http_ingress_rule_value_TEST
#define networking_v1beta1_http_ingress_rule_value_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define networking_v1beta1_http_ingress_rule_value_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/networking_v1beta1_http_ingress_rule_value.h"
networking_v1beta1_http_ingress_rule_value_t* instantiate_networking_v1beta1_http_ingress_rule_value(int include_optional);



networking_v1beta1_http_ingress_rule_value_t* instantiate_networking_v1beta1_http_ingress_rule_value(int include_optional) {
  networking_v1beta1_http_ingress_rule_value_t* networking_v1beta1_http_ingress_rule_value = NULL;
  if (include_optional) {
    networking_v1beta1_http_ingress_rule_value = networking_v1beta1_http_ingress_rule_value_create(
      list_create()
    );
  } else {
    networking_v1beta1_http_ingress_rule_value = networking_v1beta1_http_ingress_rule_value_create(
      list_create()
    );
  }

  return networking_v1beta1_http_ingress_rule_value;
}


#ifdef networking_v1beta1_http_ingress_rule_value_MAIN

void test_networking_v1beta1_http_ingress_rule_value(int include_optional) {
    networking_v1beta1_http_ingress_rule_value_t* networking_v1beta1_http_ingress_rule_value_1 = instantiate_networking_v1beta1_http_ingress_rule_value(include_optional);

	cJSON* jsonnetworking_v1beta1_http_ingress_rule_value_1 = networking_v1beta1_http_ingress_rule_value_convertToJSON(networking_v1beta1_http_ingress_rule_value_1);
	printf("networking_v1beta1_http_ingress_rule_value :\n%s\n", cJSON_Print(jsonnetworking_v1beta1_http_ingress_rule_value_1));
	networking_v1beta1_http_ingress_rule_value_t* networking_v1beta1_http_ingress_rule_value_2 = networking_v1beta1_http_ingress_rule_value_parseFromJSON(jsonnetworking_v1beta1_http_ingress_rule_value_1);
	cJSON* jsonnetworking_v1beta1_http_ingress_rule_value_2 = networking_v1beta1_http_ingress_rule_value_convertToJSON(networking_v1beta1_http_ingress_rule_value_2);
	printf("repeating networking_v1beta1_http_ingress_rule_value:\n%s\n", cJSON_Print(jsonnetworking_v1beta1_http_ingress_rule_value_2));
}

int main() {
  test_networking_v1beta1_http_ingress_rule_value(1);
  test_networking_v1beta1_http_ingress_rule_value(0);

  printf("Hello world \n");
  return 0;
}

#endif // networking_v1beta1_http_ingress_rule_value_MAIN
#endif // networking_v1beta1_http_ingress_rule_value_TEST
