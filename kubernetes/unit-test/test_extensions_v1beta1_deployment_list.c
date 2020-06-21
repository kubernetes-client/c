#ifndef extensions_v1beta1_deployment_list_TEST
#define extensions_v1beta1_deployment_list_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define extensions_v1beta1_deployment_list_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/extensions_v1beta1_deployment_list.h"
extensions_v1beta1_deployment_list_t* instantiate_extensions_v1beta1_deployment_list(int include_optional);

#include "test_v1_list_meta.c"


extensions_v1beta1_deployment_list_t* instantiate_extensions_v1beta1_deployment_list(int include_optional) {
  extensions_v1beta1_deployment_list_t* extensions_v1beta1_deployment_list = NULL;
  if (include_optional) {
    extensions_v1beta1_deployment_list = extensions_v1beta1_deployment_list_create(
      "0",
      list_create(),
      "0",
       // false, not to have infinite recursion
      instantiate_v1_list_meta(0)
    );
  } else {
    extensions_v1beta1_deployment_list = extensions_v1beta1_deployment_list_create(
      "0",
      list_create(),
      "0",
      NULL
    );
  }

  return extensions_v1beta1_deployment_list;
}


#ifdef extensions_v1beta1_deployment_list_MAIN

void test_extensions_v1beta1_deployment_list(int include_optional) {
    extensions_v1beta1_deployment_list_t* extensions_v1beta1_deployment_list_1 = instantiate_extensions_v1beta1_deployment_list(include_optional);

	cJSON* jsonextensions_v1beta1_deployment_list_1 = extensions_v1beta1_deployment_list_convertToJSON(extensions_v1beta1_deployment_list_1);
	printf("extensions_v1beta1_deployment_list :\n%s\n", cJSON_Print(jsonextensions_v1beta1_deployment_list_1));
	extensions_v1beta1_deployment_list_t* extensions_v1beta1_deployment_list_2 = extensions_v1beta1_deployment_list_parseFromJSON(jsonextensions_v1beta1_deployment_list_1);
	cJSON* jsonextensions_v1beta1_deployment_list_2 = extensions_v1beta1_deployment_list_convertToJSON(extensions_v1beta1_deployment_list_2);
	printf("repeating extensions_v1beta1_deployment_list:\n%s\n", cJSON_Print(jsonextensions_v1beta1_deployment_list_2));
}

int main() {
  test_extensions_v1beta1_deployment_list(1);
  test_extensions_v1beta1_deployment_list(0);

  printf("Hello world \n");
  return 0;
}

#endif // extensions_v1beta1_deployment_list_MAIN
#endif // extensions_v1beta1_deployment_list_TEST
