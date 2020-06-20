#ifndef apps_v1beta1_rolling_update_deployment_TEST
#define apps_v1beta1_rolling_update_deployment_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define apps_v1beta1_rolling_update_deployment_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/apps_v1beta1_rolling_update_deployment.h"
apps_v1beta1_rolling_update_deployment_t* instantiate_apps_v1beta1_rolling_update_deployment(int include_optional);



apps_v1beta1_rolling_update_deployment_t* instantiate_apps_v1beta1_rolling_update_deployment(int include_optional) {
  apps_v1beta1_rolling_update_deployment_t* apps_v1beta1_rolling_update_deployment = NULL;
  if (include_optional) {
    apps_v1beta1_rolling_update_deployment = apps_v1beta1_rolling_update_deployment_create(
      0,
      0
    );
  } else {
    apps_v1beta1_rolling_update_deployment = apps_v1beta1_rolling_update_deployment_create(
      0,
      0
    );
  }

  return apps_v1beta1_rolling_update_deployment;
}


#ifdef apps_v1beta1_rolling_update_deployment_MAIN

void test_apps_v1beta1_rolling_update_deployment(int include_optional) {
    apps_v1beta1_rolling_update_deployment_t* apps_v1beta1_rolling_update_deployment_1 = instantiate_apps_v1beta1_rolling_update_deployment(include_optional);

	cJSON* jsonapps_v1beta1_rolling_update_deployment_1 = apps_v1beta1_rolling_update_deployment_convertToJSON(apps_v1beta1_rolling_update_deployment_1);
	printf("apps_v1beta1_rolling_update_deployment :\n%s\n", cJSON_Print(jsonapps_v1beta1_rolling_update_deployment_1));
	apps_v1beta1_rolling_update_deployment_t* apps_v1beta1_rolling_update_deployment_2 = apps_v1beta1_rolling_update_deployment_parseFromJSON(jsonapps_v1beta1_rolling_update_deployment_1);
	cJSON* jsonapps_v1beta1_rolling_update_deployment_2 = apps_v1beta1_rolling_update_deployment_convertToJSON(apps_v1beta1_rolling_update_deployment_2);
	printf("repeating apps_v1beta1_rolling_update_deployment:\n%s\n", cJSON_Print(jsonapps_v1beta1_rolling_update_deployment_2));
}

int main() {
  test_apps_v1beta1_rolling_update_deployment(1);
  test_apps_v1beta1_rolling_update_deployment(0);

  printf("Hello world \n");
  return 0;
}

#endif // apps_v1beta1_rolling_update_deployment_MAIN
#endif // apps_v1beta1_rolling_update_deployment_TEST
