#ifndef apps_v1beta1_deployment_strategy_TEST
#define apps_v1beta1_deployment_strategy_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define apps_v1beta1_deployment_strategy_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/apps_v1beta1_deployment_strategy.h"
apps_v1beta1_deployment_strategy_t* instantiate_apps_v1beta1_deployment_strategy(int include_optional);

#include "test_apps_v1beta1_rolling_update_deployment.c"


apps_v1beta1_deployment_strategy_t* instantiate_apps_v1beta1_deployment_strategy(int include_optional) {
  apps_v1beta1_deployment_strategy_t* apps_v1beta1_deployment_strategy = NULL;
  if (include_optional) {
    apps_v1beta1_deployment_strategy = apps_v1beta1_deployment_strategy_create(
       // false, not to have infinite recursion
      instantiate_apps_v1beta1_rolling_update_deployment(0),
      "0"
    );
  } else {
    apps_v1beta1_deployment_strategy = apps_v1beta1_deployment_strategy_create(
      NULL,
      "0"
    );
  }

  return apps_v1beta1_deployment_strategy;
}


#ifdef apps_v1beta1_deployment_strategy_MAIN

void test_apps_v1beta1_deployment_strategy(int include_optional) {
    apps_v1beta1_deployment_strategy_t* apps_v1beta1_deployment_strategy_1 = instantiate_apps_v1beta1_deployment_strategy(include_optional);

	cJSON* jsonapps_v1beta1_deployment_strategy_1 = apps_v1beta1_deployment_strategy_convertToJSON(apps_v1beta1_deployment_strategy_1);
	printf("apps_v1beta1_deployment_strategy :\n%s\n", cJSON_Print(jsonapps_v1beta1_deployment_strategy_1));
	apps_v1beta1_deployment_strategy_t* apps_v1beta1_deployment_strategy_2 = apps_v1beta1_deployment_strategy_parseFromJSON(jsonapps_v1beta1_deployment_strategy_1);
	cJSON* jsonapps_v1beta1_deployment_strategy_2 = apps_v1beta1_deployment_strategy_convertToJSON(apps_v1beta1_deployment_strategy_2);
	printf("repeating apps_v1beta1_deployment_strategy:\n%s\n", cJSON_Print(jsonapps_v1beta1_deployment_strategy_2));
}

int main() {
  test_apps_v1beta1_deployment_strategy(1);
  test_apps_v1beta1_deployment_strategy(0);

  printf("Hello world \n");
  return 0;
}

#endif // apps_v1beta1_deployment_strategy_MAIN
#endif // apps_v1beta1_deployment_strategy_TEST
