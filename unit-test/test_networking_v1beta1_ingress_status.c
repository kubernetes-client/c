#ifndef networking_v1beta1_ingress_status_TEST
#define networking_v1beta1_ingress_status_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define networking_v1beta1_ingress_status_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/networking_v1beta1_ingress_status.h"
networking_v1beta1_ingress_status_t* instantiate_networking_v1beta1_ingress_status(int include_optional);

#include "test_v1_load_balancer_status.c"


networking_v1beta1_ingress_status_t* instantiate_networking_v1beta1_ingress_status(int include_optional) {
  networking_v1beta1_ingress_status_t* networking_v1beta1_ingress_status = NULL;
  if (include_optional) {
    networking_v1beta1_ingress_status = networking_v1beta1_ingress_status_create(
       // false, not to have infinite recursion
      instantiate_v1_load_balancer_status(0)
    );
  } else {
    networking_v1beta1_ingress_status = networking_v1beta1_ingress_status_create(
      NULL
    );
  }

  return networking_v1beta1_ingress_status;
}


#ifdef networking_v1beta1_ingress_status_MAIN

void test_networking_v1beta1_ingress_status(int include_optional) {
    networking_v1beta1_ingress_status_t* networking_v1beta1_ingress_status_1 = instantiate_networking_v1beta1_ingress_status(include_optional);

	cJSON* jsonnetworking_v1beta1_ingress_status_1 = networking_v1beta1_ingress_status_convertToJSON(networking_v1beta1_ingress_status_1);
	printf("networking_v1beta1_ingress_status :\n%s\n", cJSON_Print(jsonnetworking_v1beta1_ingress_status_1));
	networking_v1beta1_ingress_status_t* networking_v1beta1_ingress_status_2 = networking_v1beta1_ingress_status_parseFromJSON(jsonnetworking_v1beta1_ingress_status_1);
	cJSON* jsonnetworking_v1beta1_ingress_status_2 = networking_v1beta1_ingress_status_convertToJSON(networking_v1beta1_ingress_status_2);
	printf("repeating networking_v1beta1_ingress_status:\n%s\n", cJSON_Print(jsonnetworking_v1beta1_ingress_status_2));
}

int main() {
  test_networking_v1beta1_ingress_status(1);
  test_networking_v1beta1_ingress_status(0);

  printf("Hello world \n");
  return 0;
}

#endif // networking_v1beta1_ingress_status_MAIN
#endif // networking_v1beta1_ingress_status_TEST
