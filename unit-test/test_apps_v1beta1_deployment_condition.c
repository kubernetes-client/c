#ifndef apps_v1beta1_deployment_condition_TEST
#define apps_v1beta1_deployment_condition_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define apps_v1beta1_deployment_condition_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/apps_v1beta1_deployment_condition.h"
apps_v1beta1_deployment_condition_t* instantiate_apps_v1beta1_deployment_condition(int include_optional);



apps_v1beta1_deployment_condition_t* instantiate_apps_v1beta1_deployment_condition(int include_optional) {
  apps_v1beta1_deployment_condition_t* apps_v1beta1_deployment_condition = NULL;
  if (include_optional) {
    apps_v1beta1_deployment_condition = apps_v1beta1_deployment_condition_create(
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00",
      "0",
      "0",
      "0",
      "0"
    );
  } else {
    apps_v1beta1_deployment_condition = apps_v1beta1_deployment_condition_create(
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00",
      "0",
      "0",
      "0",
      "0"
    );
  }

  return apps_v1beta1_deployment_condition;
}


#ifdef apps_v1beta1_deployment_condition_MAIN

void test_apps_v1beta1_deployment_condition(int include_optional) {
    apps_v1beta1_deployment_condition_t* apps_v1beta1_deployment_condition_1 = instantiate_apps_v1beta1_deployment_condition(include_optional);

	cJSON* jsonapps_v1beta1_deployment_condition_1 = apps_v1beta1_deployment_condition_convertToJSON(apps_v1beta1_deployment_condition_1);
	printf("apps_v1beta1_deployment_condition :\n%s\n", cJSON_Print(jsonapps_v1beta1_deployment_condition_1));
	apps_v1beta1_deployment_condition_t* apps_v1beta1_deployment_condition_2 = apps_v1beta1_deployment_condition_parseFromJSON(jsonapps_v1beta1_deployment_condition_1);
	cJSON* jsonapps_v1beta1_deployment_condition_2 = apps_v1beta1_deployment_condition_convertToJSON(apps_v1beta1_deployment_condition_2);
	printf("repeating apps_v1beta1_deployment_condition:\n%s\n", cJSON_Print(jsonapps_v1beta1_deployment_condition_2));
}

int main() {
  test_apps_v1beta1_deployment_condition(1);
  test_apps_v1beta1_deployment_condition(0);

  printf("Hello world \n");
  return 0;
}

#endif // apps_v1beta1_deployment_condition_MAIN
#endif // apps_v1beta1_deployment_condition_TEST
