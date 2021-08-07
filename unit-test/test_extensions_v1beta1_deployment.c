#ifndef extensions_v1beta1_deployment_TEST
#define extensions_v1beta1_deployment_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define extensions_v1beta1_deployment_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/extensions_v1beta1_deployment.h"
extensions_v1beta1_deployment_t* instantiate_extensions_v1beta1_deployment(int include_optional);

#include "test_v1_object_meta.c"
#include "test_extensions_v1beta1_deployment_spec.c"
#include "test_extensions_v1beta1_deployment_status.c"


extensions_v1beta1_deployment_t* instantiate_extensions_v1beta1_deployment(int include_optional) {
  extensions_v1beta1_deployment_t* extensions_v1beta1_deployment = NULL;
  if (include_optional) {
    extensions_v1beta1_deployment = extensions_v1beta1_deployment_create(
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_v1_object_meta(0),
       // false, not to have infinite recursion
      instantiate_extensions_v1beta1_deployment_spec(0),
       // false, not to have infinite recursion
      instantiate_extensions_v1beta1_deployment_status(0)
    );
  } else {
    extensions_v1beta1_deployment = extensions_v1beta1_deployment_create(
      "0",
      "0",
      NULL,
      NULL,
      NULL
    );
  }

  return extensions_v1beta1_deployment;
}


#ifdef extensions_v1beta1_deployment_MAIN

void test_extensions_v1beta1_deployment(int include_optional) {
    extensions_v1beta1_deployment_t* extensions_v1beta1_deployment_1 = instantiate_extensions_v1beta1_deployment(include_optional);

	cJSON* jsonextensions_v1beta1_deployment_1 = extensions_v1beta1_deployment_convertToJSON(extensions_v1beta1_deployment_1);
	printf("extensions_v1beta1_deployment :\n%s\n", cJSON_Print(jsonextensions_v1beta1_deployment_1));
	extensions_v1beta1_deployment_t* extensions_v1beta1_deployment_2 = extensions_v1beta1_deployment_parseFromJSON(jsonextensions_v1beta1_deployment_1);
	cJSON* jsonextensions_v1beta1_deployment_2 = extensions_v1beta1_deployment_convertToJSON(extensions_v1beta1_deployment_2);
	printf("repeating extensions_v1beta1_deployment:\n%s\n", cJSON_Print(jsonextensions_v1beta1_deployment_2));
}

int main() {
  test_extensions_v1beta1_deployment(1);
  test_extensions_v1beta1_deployment(0);

  printf("Hello world \n");
  return 0;
}

#endif // extensions_v1beta1_deployment_MAIN
#endif // extensions_v1beta1_deployment_TEST
