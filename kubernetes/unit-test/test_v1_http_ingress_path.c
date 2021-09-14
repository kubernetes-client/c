#ifndef v1_http_ingress_path_TEST
#define v1_http_ingress_path_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_http_ingress_path_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_http_ingress_path.h"
v1_http_ingress_path_t* instantiate_v1_http_ingress_path(int include_optional);

#include "test_v1_ingress_backend.c"


v1_http_ingress_path_t* instantiate_v1_http_ingress_path(int include_optional) {
  v1_http_ingress_path_t* v1_http_ingress_path = NULL;
  if (include_optional) {
    v1_http_ingress_path = v1_http_ingress_path_create(
       // false, not to have infinite recursion
      instantiate_v1_ingress_backend(0),
      "0",
      "0"
    );
  } else {
    v1_http_ingress_path = v1_http_ingress_path_create(
      NULL,
      "0",
      "0"
    );
  }

  return v1_http_ingress_path;
}


#ifdef v1_http_ingress_path_MAIN

void test_v1_http_ingress_path(int include_optional) {
    v1_http_ingress_path_t* v1_http_ingress_path_1 = instantiate_v1_http_ingress_path(include_optional);

	cJSON* jsonv1_http_ingress_path_1 = v1_http_ingress_path_convertToJSON(v1_http_ingress_path_1);
	printf("v1_http_ingress_path :\n%s\n", cJSON_Print(jsonv1_http_ingress_path_1));
	v1_http_ingress_path_t* v1_http_ingress_path_2 = v1_http_ingress_path_parseFromJSON(jsonv1_http_ingress_path_1);
	cJSON* jsonv1_http_ingress_path_2 = v1_http_ingress_path_convertToJSON(v1_http_ingress_path_2);
	printf("repeating v1_http_ingress_path:\n%s\n", cJSON_Print(jsonv1_http_ingress_path_2));
}

int main() {
  test_v1_http_ingress_path(1);
  test_v1_http_ingress_path(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_http_ingress_path_MAIN
#endif // v1_http_ingress_path_TEST
