#ifndef networking_v1beta1_ingress_TEST
#define networking_v1beta1_ingress_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define networking_v1beta1_ingress_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/networking_v1beta1_ingress.h"
networking_v1beta1_ingress_t* instantiate_networking_v1beta1_ingress(int include_optional);

#include "test_v1_object_meta.c"
#include "test_networking_v1beta1_ingress_spec.c"
#include "test_networking_v1beta1_ingress_status.c"


networking_v1beta1_ingress_t* instantiate_networking_v1beta1_ingress(int include_optional) {
  networking_v1beta1_ingress_t* networking_v1beta1_ingress = NULL;
  if (include_optional) {
    networking_v1beta1_ingress = networking_v1beta1_ingress_create(
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_v1_object_meta(0),
       // false, not to have infinite recursion
      instantiate_networking_v1beta1_ingress_spec(0),
       // false, not to have infinite recursion
      instantiate_networking_v1beta1_ingress_status(0)
    );
  } else {
    networking_v1beta1_ingress = networking_v1beta1_ingress_create(
      "0",
      "0",
      NULL,
      NULL,
      NULL
    );
  }

  return networking_v1beta1_ingress;
}


#ifdef networking_v1beta1_ingress_MAIN

void test_networking_v1beta1_ingress(int include_optional) {
    networking_v1beta1_ingress_t* networking_v1beta1_ingress_1 = instantiate_networking_v1beta1_ingress(include_optional);

	cJSON* jsonnetworking_v1beta1_ingress_1 = networking_v1beta1_ingress_convertToJSON(networking_v1beta1_ingress_1);
	printf("networking_v1beta1_ingress :\n%s\n", cJSON_Print(jsonnetworking_v1beta1_ingress_1));
	networking_v1beta1_ingress_t* networking_v1beta1_ingress_2 = networking_v1beta1_ingress_parseFromJSON(jsonnetworking_v1beta1_ingress_1);
	cJSON* jsonnetworking_v1beta1_ingress_2 = networking_v1beta1_ingress_convertToJSON(networking_v1beta1_ingress_2);
	printf("repeating networking_v1beta1_ingress:\n%s\n", cJSON_Print(jsonnetworking_v1beta1_ingress_2));
}

int main() {
  test_networking_v1beta1_ingress(1);
  test_networking_v1beta1_ingress(0);

  printf("Hello world \n");
  return 0;
}

#endif // networking_v1beta1_ingress_MAIN
#endif // networking_v1beta1_ingress_TEST
