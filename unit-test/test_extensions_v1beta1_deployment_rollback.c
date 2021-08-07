#ifndef extensions_v1beta1_deployment_rollback_TEST
#define extensions_v1beta1_deployment_rollback_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define extensions_v1beta1_deployment_rollback_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/extensions_v1beta1_deployment_rollback.h"
extensions_v1beta1_deployment_rollback_t* instantiate_extensions_v1beta1_deployment_rollback(int include_optional);

#include "test_extensions_v1beta1_rollback_config.c"


extensions_v1beta1_deployment_rollback_t* instantiate_extensions_v1beta1_deployment_rollback(int include_optional) {
  extensions_v1beta1_deployment_rollback_t* extensions_v1beta1_deployment_rollback = NULL;
  if (include_optional) {
    extensions_v1beta1_deployment_rollback = extensions_v1beta1_deployment_rollback_create(
      "0",
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_extensions_v1beta1_rollback_config(0),
      list_create()
    );
  } else {
    extensions_v1beta1_deployment_rollback = extensions_v1beta1_deployment_rollback_create(
      "0",
      "0",
      "0",
      NULL,
      list_create()
    );
  }

  return extensions_v1beta1_deployment_rollback;
}


#ifdef extensions_v1beta1_deployment_rollback_MAIN

void test_extensions_v1beta1_deployment_rollback(int include_optional) {
    extensions_v1beta1_deployment_rollback_t* extensions_v1beta1_deployment_rollback_1 = instantiate_extensions_v1beta1_deployment_rollback(include_optional);

	cJSON* jsonextensions_v1beta1_deployment_rollback_1 = extensions_v1beta1_deployment_rollback_convertToJSON(extensions_v1beta1_deployment_rollback_1);
	printf("extensions_v1beta1_deployment_rollback :\n%s\n", cJSON_Print(jsonextensions_v1beta1_deployment_rollback_1));
	extensions_v1beta1_deployment_rollback_t* extensions_v1beta1_deployment_rollback_2 = extensions_v1beta1_deployment_rollback_parseFromJSON(jsonextensions_v1beta1_deployment_rollback_1);
	cJSON* jsonextensions_v1beta1_deployment_rollback_2 = extensions_v1beta1_deployment_rollback_convertToJSON(extensions_v1beta1_deployment_rollback_2);
	printf("repeating extensions_v1beta1_deployment_rollback:\n%s\n", cJSON_Print(jsonextensions_v1beta1_deployment_rollback_2));
}

int main() {
  test_extensions_v1beta1_deployment_rollback(1);
  test_extensions_v1beta1_deployment_rollback(0);

  printf("Hello world \n");
  return 0;
}

#endif // extensions_v1beta1_deployment_rollback_MAIN
#endif // extensions_v1beta1_deployment_rollback_TEST
