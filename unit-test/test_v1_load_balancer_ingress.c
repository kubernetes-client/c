#ifndef v1_load_balancer_ingress_TEST
#define v1_load_balancer_ingress_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_load_balancer_ingress_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_load_balancer_ingress.h"
v1_load_balancer_ingress_t* instantiate_v1_load_balancer_ingress(int include_optional);



v1_load_balancer_ingress_t* instantiate_v1_load_balancer_ingress(int include_optional) {
  v1_load_balancer_ingress_t* v1_load_balancer_ingress = NULL;
  if (include_optional) {
    v1_load_balancer_ingress = v1_load_balancer_ingress_create(
      "0",
      "0"
    );
  } else {
    v1_load_balancer_ingress = v1_load_balancer_ingress_create(
      "0",
      "0"
    );
  }

  return v1_load_balancer_ingress;
}


#ifdef v1_load_balancer_ingress_MAIN

void test_v1_load_balancer_ingress(int include_optional) {
    v1_load_balancer_ingress_t* v1_load_balancer_ingress_1 = instantiate_v1_load_balancer_ingress(include_optional);

	cJSON* jsonv1_load_balancer_ingress_1 = v1_load_balancer_ingress_convertToJSON(v1_load_balancer_ingress_1);
	printf("v1_load_balancer_ingress :\n%s\n", cJSON_Print(jsonv1_load_balancer_ingress_1));
	v1_load_balancer_ingress_t* v1_load_balancer_ingress_2 = v1_load_balancer_ingress_parseFromJSON(jsonv1_load_balancer_ingress_1);
	cJSON* jsonv1_load_balancer_ingress_2 = v1_load_balancer_ingress_convertToJSON(v1_load_balancer_ingress_2);
	printf("repeating v1_load_balancer_ingress:\n%s\n", cJSON_Print(jsonv1_load_balancer_ingress_2));
}

int main() {
  test_v1_load_balancer_ingress(1);
  test_v1_load_balancer_ingress(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_load_balancer_ingress_MAIN
#endif // v1_load_balancer_ingress_TEST
