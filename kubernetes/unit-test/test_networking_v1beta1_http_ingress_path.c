#ifndef networking_v1beta1_http_ingress_path_TEST
#define networking_v1beta1_http_ingress_path_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define networking_v1beta1_http_ingress_path_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/networking_v1beta1_http_ingress_path.h"
networking_v1beta1_http_ingress_path_t* instantiate_networking_v1beta1_http_ingress_path(int include_optional);

#include "test_networking_v1beta1_ingress_backend.c"


networking_v1beta1_http_ingress_path_t* instantiate_networking_v1beta1_http_ingress_path(int include_optional) {
  networking_v1beta1_http_ingress_path_t* networking_v1beta1_http_ingress_path = NULL;
  if (include_optional) {
    networking_v1beta1_http_ingress_path = networking_v1beta1_http_ingress_path_create(
       // false, not to have infinite recursion
      instantiate_networking_v1beta1_ingress_backend(0),
      "0"
    );
  } else {
    networking_v1beta1_http_ingress_path = networking_v1beta1_http_ingress_path_create(
      NULL,
      "0"
    );
  }

  return networking_v1beta1_http_ingress_path;
}


#ifdef networking_v1beta1_http_ingress_path_MAIN

void test_networking_v1beta1_http_ingress_path(int include_optional) {
    networking_v1beta1_http_ingress_path_t* networking_v1beta1_http_ingress_path_1 = instantiate_networking_v1beta1_http_ingress_path(include_optional);

	cJSON* jsonnetworking_v1beta1_http_ingress_path_1 = networking_v1beta1_http_ingress_path_convertToJSON(networking_v1beta1_http_ingress_path_1);
	printf("networking_v1beta1_http_ingress_path :\n%s\n", cJSON_Print(jsonnetworking_v1beta1_http_ingress_path_1));
	networking_v1beta1_http_ingress_path_t* networking_v1beta1_http_ingress_path_2 = networking_v1beta1_http_ingress_path_parseFromJSON(jsonnetworking_v1beta1_http_ingress_path_1);
	cJSON* jsonnetworking_v1beta1_http_ingress_path_2 = networking_v1beta1_http_ingress_path_convertToJSON(networking_v1beta1_http_ingress_path_2);
	printf("repeating networking_v1beta1_http_ingress_path:\n%s\n", cJSON_Print(jsonnetworking_v1beta1_http_ingress_path_2));
}

int main() {
  test_networking_v1beta1_http_ingress_path(1);
  test_networking_v1beta1_http_ingress_path(0);

  printf("Hello world \n");
  return 0;
}

#endif // networking_v1beta1_http_ingress_path_MAIN
#endif // networking_v1beta1_http_ingress_path_TEST
