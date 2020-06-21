#ifndef networking_v1beta1_ingress_tls_TEST
#define networking_v1beta1_ingress_tls_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define networking_v1beta1_ingress_tls_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/networking_v1beta1_ingress_tls.h"
networking_v1beta1_ingress_tls_t* instantiate_networking_v1beta1_ingress_tls(int include_optional);



networking_v1beta1_ingress_tls_t* instantiate_networking_v1beta1_ingress_tls(int include_optional) {
  networking_v1beta1_ingress_tls_t* networking_v1beta1_ingress_tls = NULL;
  if (include_optional) {
    networking_v1beta1_ingress_tls = networking_v1beta1_ingress_tls_create(
      list_create(),
      "0"
    );
  } else {
    networking_v1beta1_ingress_tls = networking_v1beta1_ingress_tls_create(
      list_create(),
      "0"
    );
  }

  return networking_v1beta1_ingress_tls;
}


#ifdef networking_v1beta1_ingress_tls_MAIN

void test_networking_v1beta1_ingress_tls(int include_optional) {
    networking_v1beta1_ingress_tls_t* networking_v1beta1_ingress_tls_1 = instantiate_networking_v1beta1_ingress_tls(include_optional);

	cJSON* jsonnetworking_v1beta1_ingress_tls_1 = networking_v1beta1_ingress_tls_convertToJSON(networking_v1beta1_ingress_tls_1);
	printf("networking_v1beta1_ingress_tls :\n%s\n", cJSON_Print(jsonnetworking_v1beta1_ingress_tls_1));
	networking_v1beta1_ingress_tls_t* networking_v1beta1_ingress_tls_2 = networking_v1beta1_ingress_tls_parseFromJSON(jsonnetworking_v1beta1_ingress_tls_1);
	cJSON* jsonnetworking_v1beta1_ingress_tls_2 = networking_v1beta1_ingress_tls_convertToJSON(networking_v1beta1_ingress_tls_2);
	printf("repeating networking_v1beta1_ingress_tls:\n%s\n", cJSON_Print(jsonnetworking_v1beta1_ingress_tls_2));
}

int main() {
  test_networking_v1beta1_ingress_tls(1);
  test_networking_v1beta1_ingress_tls(0);

  printf("Hello world \n");
  return 0;
}

#endif // networking_v1beta1_ingress_tls_MAIN
#endif // networking_v1beta1_ingress_tls_TEST
