#ifndef extensions_v1beta1_deployment_strategy_TEST
#define extensions_v1beta1_deployment_strategy_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define extensions_v1beta1_deployment_strategy_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/extensions_v1beta1_deployment_strategy.h"
extensions_v1beta1_deployment_strategy_t* instantiate_extensions_v1beta1_deployment_strategy(int include_optional);

#include "test_extensions_v1beta1_rolling_update_deployment.c"


extensions_v1beta1_deployment_strategy_t* instantiate_extensions_v1beta1_deployment_strategy(int include_optional) {
  extensions_v1beta1_deployment_strategy_t* extensions_v1beta1_deployment_strategy = NULL;
  if (include_optional) {
    extensions_v1beta1_deployment_strategy = extensions_v1beta1_deployment_strategy_create(
       // false, not to have infinite recursion
      instantiate_extensions_v1beta1_rolling_update_deployment(0),
      "0"
    );
  } else {
    extensions_v1beta1_deployment_strategy = extensions_v1beta1_deployment_strategy_create(
      NULL,
      "0"
    );
  }

  return extensions_v1beta1_deployment_strategy;
}


#ifdef extensions_v1beta1_deployment_strategy_MAIN

void test_extensions_v1beta1_deployment_strategy(int include_optional) {
    extensions_v1beta1_deployment_strategy_t* extensions_v1beta1_deployment_strategy_1 = instantiate_extensions_v1beta1_deployment_strategy(include_optional);

	cJSON* jsonextensions_v1beta1_deployment_strategy_1 = extensions_v1beta1_deployment_strategy_convertToJSON(extensions_v1beta1_deployment_strategy_1);
	printf("extensions_v1beta1_deployment_strategy :\n%s\n", cJSON_Print(jsonextensions_v1beta1_deployment_strategy_1));
	extensions_v1beta1_deployment_strategy_t* extensions_v1beta1_deployment_strategy_2 = extensions_v1beta1_deployment_strategy_parseFromJSON(jsonextensions_v1beta1_deployment_strategy_1);
	cJSON* jsonextensions_v1beta1_deployment_strategy_2 = extensions_v1beta1_deployment_strategy_convertToJSON(extensions_v1beta1_deployment_strategy_2);
	printf("repeating extensions_v1beta1_deployment_strategy:\n%s\n", cJSON_Print(jsonextensions_v1beta1_deployment_strategy_2));
}

int main() {
  test_extensions_v1beta1_deployment_strategy(1);
  test_extensions_v1beta1_deployment_strategy(0);

  printf("Hello world \n");
  return 0;
}

#endif // extensions_v1beta1_deployment_strategy_MAIN
#endif // extensions_v1beta1_deployment_strategy_TEST
