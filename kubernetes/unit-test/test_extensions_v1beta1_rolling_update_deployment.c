#ifndef extensions_v1beta1_rolling_update_deployment_TEST
#define extensions_v1beta1_rolling_update_deployment_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define extensions_v1beta1_rolling_update_deployment_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/extensions_v1beta1_rolling_update_deployment.h"
extensions_v1beta1_rolling_update_deployment_t* instantiate_extensions_v1beta1_rolling_update_deployment(int include_optional);



extensions_v1beta1_rolling_update_deployment_t* instantiate_extensions_v1beta1_rolling_update_deployment(int include_optional) {
  extensions_v1beta1_rolling_update_deployment_t* extensions_v1beta1_rolling_update_deployment = NULL;
  if (include_optional) {
    extensions_v1beta1_rolling_update_deployment = extensions_v1beta1_rolling_update_deployment_create(
      0,
      0
    );
  } else {
    extensions_v1beta1_rolling_update_deployment = extensions_v1beta1_rolling_update_deployment_create(
      0,
      0
    );
  }

  return extensions_v1beta1_rolling_update_deployment;
}


#ifdef extensions_v1beta1_rolling_update_deployment_MAIN

void test_extensions_v1beta1_rolling_update_deployment(int include_optional) {
    extensions_v1beta1_rolling_update_deployment_t* extensions_v1beta1_rolling_update_deployment_1 = instantiate_extensions_v1beta1_rolling_update_deployment(include_optional);

	cJSON* jsonextensions_v1beta1_rolling_update_deployment_1 = extensions_v1beta1_rolling_update_deployment_convertToJSON(extensions_v1beta1_rolling_update_deployment_1);
	printf("extensions_v1beta1_rolling_update_deployment :\n%s\n", cJSON_Print(jsonextensions_v1beta1_rolling_update_deployment_1));
	extensions_v1beta1_rolling_update_deployment_t* extensions_v1beta1_rolling_update_deployment_2 = extensions_v1beta1_rolling_update_deployment_parseFromJSON(jsonextensions_v1beta1_rolling_update_deployment_1);
	cJSON* jsonextensions_v1beta1_rolling_update_deployment_2 = extensions_v1beta1_rolling_update_deployment_convertToJSON(extensions_v1beta1_rolling_update_deployment_2);
	printf("repeating extensions_v1beta1_rolling_update_deployment:\n%s\n", cJSON_Print(jsonextensions_v1beta1_rolling_update_deployment_2));
}

int main() {
  test_extensions_v1beta1_rolling_update_deployment(1);
  test_extensions_v1beta1_rolling_update_deployment(0);

  printf("Hello world \n");
  return 0;
}

#endif // extensions_v1beta1_rolling_update_deployment_MAIN
#endif // extensions_v1beta1_rolling_update_deployment_TEST
