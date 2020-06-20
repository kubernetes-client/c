#ifndef networking_v1beta1_ingress_list_TEST
#define networking_v1beta1_ingress_list_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define networking_v1beta1_ingress_list_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/networking_v1beta1_ingress_list.h"
networking_v1beta1_ingress_list_t* instantiate_networking_v1beta1_ingress_list(int include_optional);

#include "test_v1_list_meta.c"


networking_v1beta1_ingress_list_t* instantiate_networking_v1beta1_ingress_list(int include_optional) {
  networking_v1beta1_ingress_list_t* networking_v1beta1_ingress_list = NULL;
  if (include_optional) {
    networking_v1beta1_ingress_list = networking_v1beta1_ingress_list_create(
      "0",
      list_create(),
      "0",
       // false, not to have infinite recursion
      instantiate_v1_list_meta(0)
    );
  } else {
    networking_v1beta1_ingress_list = networking_v1beta1_ingress_list_create(
      "0",
      list_create(),
      "0",
      NULL
    );
  }

  return networking_v1beta1_ingress_list;
}


#ifdef networking_v1beta1_ingress_list_MAIN

void test_networking_v1beta1_ingress_list(int include_optional) {
    networking_v1beta1_ingress_list_t* networking_v1beta1_ingress_list_1 = instantiate_networking_v1beta1_ingress_list(include_optional);

	cJSON* jsonnetworking_v1beta1_ingress_list_1 = networking_v1beta1_ingress_list_convertToJSON(networking_v1beta1_ingress_list_1);
	printf("networking_v1beta1_ingress_list :\n%s\n", cJSON_Print(jsonnetworking_v1beta1_ingress_list_1));
	networking_v1beta1_ingress_list_t* networking_v1beta1_ingress_list_2 = networking_v1beta1_ingress_list_parseFromJSON(jsonnetworking_v1beta1_ingress_list_1);
	cJSON* jsonnetworking_v1beta1_ingress_list_2 = networking_v1beta1_ingress_list_convertToJSON(networking_v1beta1_ingress_list_2);
	printf("repeating networking_v1beta1_ingress_list:\n%s\n", cJSON_Print(jsonnetworking_v1beta1_ingress_list_2));
}

int main() {
  test_networking_v1beta1_ingress_list(1);
  test_networking_v1beta1_ingress_list(0);

  printf("Hello world \n");
  return 0;
}

#endif // networking_v1beta1_ingress_list_MAIN
#endif // networking_v1beta1_ingress_list_TEST
