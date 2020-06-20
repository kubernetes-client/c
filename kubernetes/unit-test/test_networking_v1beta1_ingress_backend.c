#ifndef networking_v1beta1_ingress_backend_TEST
#define networking_v1beta1_ingress_backend_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define networking_v1beta1_ingress_backend_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/networking_v1beta1_ingress_backend.h"
networking_v1beta1_ingress_backend_t* instantiate_networking_v1beta1_ingress_backend(int include_optional);



networking_v1beta1_ingress_backend_t* instantiate_networking_v1beta1_ingress_backend(int include_optional) {
  networking_v1beta1_ingress_backend_t* networking_v1beta1_ingress_backend = NULL;
  if (include_optional) {
    networking_v1beta1_ingress_backend = networking_v1beta1_ingress_backend_create(
      "0",
      0
    );
  } else {
    networking_v1beta1_ingress_backend = networking_v1beta1_ingress_backend_create(
      "0",
      0
    );
  }

  return networking_v1beta1_ingress_backend;
}


#ifdef networking_v1beta1_ingress_backend_MAIN

void test_networking_v1beta1_ingress_backend(int include_optional) {
    networking_v1beta1_ingress_backend_t* networking_v1beta1_ingress_backend_1 = instantiate_networking_v1beta1_ingress_backend(include_optional);

	cJSON* jsonnetworking_v1beta1_ingress_backend_1 = networking_v1beta1_ingress_backend_convertToJSON(networking_v1beta1_ingress_backend_1);
	printf("networking_v1beta1_ingress_backend :\n%s\n", cJSON_Print(jsonnetworking_v1beta1_ingress_backend_1));
	networking_v1beta1_ingress_backend_t* networking_v1beta1_ingress_backend_2 = networking_v1beta1_ingress_backend_parseFromJSON(jsonnetworking_v1beta1_ingress_backend_1);
	cJSON* jsonnetworking_v1beta1_ingress_backend_2 = networking_v1beta1_ingress_backend_convertToJSON(networking_v1beta1_ingress_backend_2);
	printf("repeating networking_v1beta1_ingress_backend:\n%s\n", cJSON_Print(jsonnetworking_v1beta1_ingress_backend_2));
}

int main() {
  test_networking_v1beta1_ingress_backend(1);
  test_networking_v1beta1_ingress_backend(0);

  printf("Hello world \n");
  return 0;
}

#endif // networking_v1beta1_ingress_backend_MAIN
#endif // networking_v1beta1_ingress_backend_TEST
