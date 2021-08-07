#ifndef extensions_v1beta1_ingress_spec_TEST
#define extensions_v1beta1_ingress_spec_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define extensions_v1beta1_ingress_spec_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/extensions_v1beta1_ingress_spec.h"
extensions_v1beta1_ingress_spec_t* instantiate_extensions_v1beta1_ingress_spec(int include_optional);

#include "test_extensions_v1beta1_ingress_backend.c"


extensions_v1beta1_ingress_spec_t* instantiate_extensions_v1beta1_ingress_spec(int include_optional) {
  extensions_v1beta1_ingress_spec_t* extensions_v1beta1_ingress_spec = NULL;
  if (include_optional) {
    extensions_v1beta1_ingress_spec = extensions_v1beta1_ingress_spec_create(
       // false, not to have infinite recursion
      instantiate_extensions_v1beta1_ingress_backend(0),
      list_create(),
      list_create()
    );
  } else {
    extensions_v1beta1_ingress_spec = extensions_v1beta1_ingress_spec_create(
      NULL,
      list_create(),
      list_create()
    );
  }

  return extensions_v1beta1_ingress_spec;
}


#ifdef extensions_v1beta1_ingress_spec_MAIN

void test_extensions_v1beta1_ingress_spec(int include_optional) {
    extensions_v1beta1_ingress_spec_t* extensions_v1beta1_ingress_spec_1 = instantiate_extensions_v1beta1_ingress_spec(include_optional);

	cJSON* jsonextensions_v1beta1_ingress_spec_1 = extensions_v1beta1_ingress_spec_convertToJSON(extensions_v1beta1_ingress_spec_1);
	printf("extensions_v1beta1_ingress_spec :\n%s\n", cJSON_Print(jsonextensions_v1beta1_ingress_spec_1));
	extensions_v1beta1_ingress_spec_t* extensions_v1beta1_ingress_spec_2 = extensions_v1beta1_ingress_spec_parseFromJSON(jsonextensions_v1beta1_ingress_spec_1);
	cJSON* jsonextensions_v1beta1_ingress_spec_2 = extensions_v1beta1_ingress_spec_convertToJSON(extensions_v1beta1_ingress_spec_2);
	printf("repeating extensions_v1beta1_ingress_spec:\n%s\n", cJSON_Print(jsonextensions_v1beta1_ingress_spec_2));
}

int main() {
  test_extensions_v1beta1_ingress_spec(1);
  test_extensions_v1beta1_ingress_spec(0);

  printf("Hello world \n");
  return 0;
}

#endif // extensions_v1beta1_ingress_spec_MAIN
#endif // extensions_v1beta1_ingress_spec_TEST
