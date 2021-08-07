#ifndef extensions_v1beta1_deployment_status_TEST
#define extensions_v1beta1_deployment_status_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define extensions_v1beta1_deployment_status_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/extensions_v1beta1_deployment_status.h"
extensions_v1beta1_deployment_status_t* instantiate_extensions_v1beta1_deployment_status(int include_optional);



extensions_v1beta1_deployment_status_t* instantiate_extensions_v1beta1_deployment_status(int include_optional) {
  extensions_v1beta1_deployment_status_t* extensions_v1beta1_deployment_status = NULL;
  if (include_optional) {
    extensions_v1beta1_deployment_status = extensions_v1beta1_deployment_status_create(
      56,
      56,
      list_create(),
      56,
      56,
      56,
      56,
      56
    );
  } else {
    extensions_v1beta1_deployment_status = extensions_v1beta1_deployment_status_create(
      56,
      56,
      list_create(),
      56,
      56,
      56,
      56,
      56
    );
  }

  return extensions_v1beta1_deployment_status;
}


#ifdef extensions_v1beta1_deployment_status_MAIN

void test_extensions_v1beta1_deployment_status(int include_optional) {
    extensions_v1beta1_deployment_status_t* extensions_v1beta1_deployment_status_1 = instantiate_extensions_v1beta1_deployment_status(include_optional);

	cJSON* jsonextensions_v1beta1_deployment_status_1 = extensions_v1beta1_deployment_status_convertToJSON(extensions_v1beta1_deployment_status_1);
	printf("extensions_v1beta1_deployment_status :\n%s\n", cJSON_Print(jsonextensions_v1beta1_deployment_status_1));
	extensions_v1beta1_deployment_status_t* extensions_v1beta1_deployment_status_2 = extensions_v1beta1_deployment_status_parseFromJSON(jsonextensions_v1beta1_deployment_status_1);
	cJSON* jsonextensions_v1beta1_deployment_status_2 = extensions_v1beta1_deployment_status_convertToJSON(extensions_v1beta1_deployment_status_2);
	printf("repeating extensions_v1beta1_deployment_status:\n%s\n", cJSON_Print(jsonextensions_v1beta1_deployment_status_2));
}

int main() {
  test_extensions_v1beta1_deployment_status(1);
  test_extensions_v1beta1_deployment_status(0);

  printf("Hello world \n");
  return 0;
}

#endif // extensions_v1beta1_deployment_status_MAIN
#endif // extensions_v1beta1_deployment_status_TEST
