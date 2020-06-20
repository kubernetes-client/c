#ifndef extensions_v1beta1_ingress_TEST
#define extensions_v1beta1_ingress_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define extensions_v1beta1_ingress_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/extensions_v1beta1_ingress.h"
extensions_v1beta1_ingress_t* instantiate_extensions_v1beta1_ingress(int include_optional);

#include "test_v1_object_meta.c"
#include "test_extensions_v1beta1_ingress_spec.c"
#include "test_extensions_v1beta1_ingress_status.c"


extensions_v1beta1_ingress_t* instantiate_extensions_v1beta1_ingress(int include_optional) {
  extensions_v1beta1_ingress_t* extensions_v1beta1_ingress = NULL;
  if (include_optional) {
    extensions_v1beta1_ingress = extensions_v1beta1_ingress_create(
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_v1_object_meta(0),
       // false, not to have infinite recursion
      instantiate_extensions_v1beta1_ingress_spec(0),
       // false, not to have infinite recursion
      instantiate_extensions_v1beta1_ingress_status(0)
    );
  } else {
    extensions_v1beta1_ingress = extensions_v1beta1_ingress_create(
      "0",
      "0",
      NULL,
      NULL,
      NULL
    );
  }

  return extensions_v1beta1_ingress;
}


#ifdef extensions_v1beta1_ingress_MAIN

void test_extensions_v1beta1_ingress(int include_optional) {
    extensions_v1beta1_ingress_t* extensions_v1beta1_ingress_1 = instantiate_extensions_v1beta1_ingress(include_optional);

	cJSON* jsonextensions_v1beta1_ingress_1 = extensions_v1beta1_ingress_convertToJSON(extensions_v1beta1_ingress_1);
	printf("extensions_v1beta1_ingress :\n%s\n", cJSON_Print(jsonextensions_v1beta1_ingress_1));
	extensions_v1beta1_ingress_t* extensions_v1beta1_ingress_2 = extensions_v1beta1_ingress_parseFromJSON(jsonextensions_v1beta1_ingress_1);
	cJSON* jsonextensions_v1beta1_ingress_2 = extensions_v1beta1_ingress_convertToJSON(extensions_v1beta1_ingress_2);
	printf("repeating extensions_v1beta1_ingress:\n%s\n", cJSON_Print(jsonextensions_v1beta1_ingress_2));
}

int main() {
  test_extensions_v1beta1_ingress(1);
  test_extensions_v1beta1_ingress(0);

  printf("Hello world \n");
  return 0;
}

#endif // extensions_v1beta1_ingress_MAIN
#endif // extensions_v1beta1_ingress_TEST
