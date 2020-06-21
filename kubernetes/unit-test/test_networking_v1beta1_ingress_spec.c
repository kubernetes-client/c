#ifndef networking_v1beta1_ingress_spec_TEST
#define networking_v1beta1_ingress_spec_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define networking_v1beta1_ingress_spec_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/networking_v1beta1_ingress_spec.h"
networking_v1beta1_ingress_spec_t* instantiate_networking_v1beta1_ingress_spec(int include_optional);

#include "test_networking_v1beta1_ingress_backend.c"


networking_v1beta1_ingress_spec_t* instantiate_networking_v1beta1_ingress_spec(int include_optional) {
  networking_v1beta1_ingress_spec_t* networking_v1beta1_ingress_spec = NULL;
  if (include_optional) {
    networking_v1beta1_ingress_spec = networking_v1beta1_ingress_spec_create(
       // false, not to have infinite recursion
      instantiate_networking_v1beta1_ingress_backend(0),
      list_create(),
      list_create()
    );
  } else {
    networking_v1beta1_ingress_spec = networking_v1beta1_ingress_spec_create(
      NULL,
      list_create(),
      list_create()
    );
  }

  return networking_v1beta1_ingress_spec;
}


#ifdef networking_v1beta1_ingress_spec_MAIN

void test_networking_v1beta1_ingress_spec(int include_optional) {
    networking_v1beta1_ingress_spec_t* networking_v1beta1_ingress_spec_1 = instantiate_networking_v1beta1_ingress_spec(include_optional);

	cJSON* jsonnetworking_v1beta1_ingress_spec_1 = networking_v1beta1_ingress_spec_convertToJSON(networking_v1beta1_ingress_spec_1);
	printf("networking_v1beta1_ingress_spec :\n%s\n", cJSON_Print(jsonnetworking_v1beta1_ingress_spec_1));
	networking_v1beta1_ingress_spec_t* networking_v1beta1_ingress_spec_2 = networking_v1beta1_ingress_spec_parseFromJSON(jsonnetworking_v1beta1_ingress_spec_1);
	cJSON* jsonnetworking_v1beta1_ingress_spec_2 = networking_v1beta1_ingress_spec_convertToJSON(networking_v1beta1_ingress_spec_2);
	printf("repeating networking_v1beta1_ingress_spec:\n%s\n", cJSON_Print(jsonnetworking_v1beta1_ingress_spec_2));
}

int main() {
  test_networking_v1beta1_ingress_spec(1);
  test_networking_v1beta1_ingress_spec(0);

  printf("Hello world \n");
  return 0;
}

#endif // networking_v1beta1_ingress_spec_MAIN
#endif // networking_v1beta1_ingress_spec_TEST
