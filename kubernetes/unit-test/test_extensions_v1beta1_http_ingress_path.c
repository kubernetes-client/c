#ifndef extensions_v1beta1_http_ingress_path_TEST
#define extensions_v1beta1_http_ingress_path_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define extensions_v1beta1_http_ingress_path_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/extensions_v1beta1_http_ingress_path.h"
extensions_v1beta1_http_ingress_path_t* instantiate_extensions_v1beta1_http_ingress_path(int include_optional);

#include "test_extensions_v1beta1_ingress_backend.c"


extensions_v1beta1_http_ingress_path_t* instantiate_extensions_v1beta1_http_ingress_path(int include_optional) {
  extensions_v1beta1_http_ingress_path_t* extensions_v1beta1_http_ingress_path = NULL;
  if (include_optional) {
    extensions_v1beta1_http_ingress_path = extensions_v1beta1_http_ingress_path_create(
       // false, not to have infinite recursion
      instantiate_extensions_v1beta1_ingress_backend(0),
      "0"
    );
  } else {
    extensions_v1beta1_http_ingress_path = extensions_v1beta1_http_ingress_path_create(
      NULL,
      "0"
    );
  }

  return extensions_v1beta1_http_ingress_path;
}


#ifdef extensions_v1beta1_http_ingress_path_MAIN

void test_extensions_v1beta1_http_ingress_path(int include_optional) {
    extensions_v1beta1_http_ingress_path_t* extensions_v1beta1_http_ingress_path_1 = instantiate_extensions_v1beta1_http_ingress_path(include_optional);

	cJSON* jsonextensions_v1beta1_http_ingress_path_1 = extensions_v1beta1_http_ingress_path_convertToJSON(extensions_v1beta1_http_ingress_path_1);
	printf("extensions_v1beta1_http_ingress_path :\n%s\n", cJSON_Print(jsonextensions_v1beta1_http_ingress_path_1));
	extensions_v1beta1_http_ingress_path_t* extensions_v1beta1_http_ingress_path_2 = extensions_v1beta1_http_ingress_path_parseFromJSON(jsonextensions_v1beta1_http_ingress_path_1);
	cJSON* jsonextensions_v1beta1_http_ingress_path_2 = extensions_v1beta1_http_ingress_path_convertToJSON(extensions_v1beta1_http_ingress_path_2);
	printf("repeating extensions_v1beta1_http_ingress_path:\n%s\n", cJSON_Print(jsonextensions_v1beta1_http_ingress_path_2));
}

int main() {
  test_extensions_v1beta1_http_ingress_path(1);
  test_extensions_v1beta1_http_ingress_path(0);

  printf("Hello world \n");
  return 0;
}

#endif // extensions_v1beta1_http_ingress_path_MAIN
#endif // extensions_v1beta1_http_ingress_path_TEST
