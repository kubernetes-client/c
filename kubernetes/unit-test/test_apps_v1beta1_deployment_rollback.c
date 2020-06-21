#ifndef apps_v1beta1_deployment_rollback_TEST
#define apps_v1beta1_deployment_rollback_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define apps_v1beta1_deployment_rollback_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/apps_v1beta1_deployment_rollback.h"
apps_v1beta1_deployment_rollback_t* instantiate_apps_v1beta1_deployment_rollback(int include_optional);

#include "test_apps_v1beta1_rollback_config.c"


apps_v1beta1_deployment_rollback_t* instantiate_apps_v1beta1_deployment_rollback(int include_optional) {
  apps_v1beta1_deployment_rollback_t* apps_v1beta1_deployment_rollback = NULL;
  if (include_optional) {
    apps_v1beta1_deployment_rollback = apps_v1beta1_deployment_rollback_create(
      "0",
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_apps_v1beta1_rollback_config(0),
      list_create()
    );
  } else {
    apps_v1beta1_deployment_rollback = apps_v1beta1_deployment_rollback_create(
      "0",
      "0",
      "0",
      NULL,
      list_create()
    );
  }

  return apps_v1beta1_deployment_rollback;
}


#ifdef apps_v1beta1_deployment_rollback_MAIN

void test_apps_v1beta1_deployment_rollback(int include_optional) {
    apps_v1beta1_deployment_rollback_t* apps_v1beta1_deployment_rollback_1 = instantiate_apps_v1beta1_deployment_rollback(include_optional);

	cJSON* jsonapps_v1beta1_deployment_rollback_1 = apps_v1beta1_deployment_rollback_convertToJSON(apps_v1beta1_deployment_rollback_1);
	printf("apps_v1beta1_deployment_rollback :\n%s\n", cJSON_Print(jsonapps_v1beta1_deployment_rollback_1));
	apps_v1beta1_deployment_rollback_t* apps_v1beta1_deployment_rollback_2 = apps_v1beta1_deployment_rollback_parseFromJSON(jsonapps_v1beta1_deployment_rollback_1);
	cJSON* jsonapps_v1beta1_deployment_rollback_2 = apps_v1beta1_deployment_rollback_convertToJSON(apps_v1beta1_deployment_rollback_2);
	printf("repeating apps_v1beta1_deployment_rollback:\n%s\n", cJSON_Print(jsonapps_v1beta1_deployment_rollback_2));
}

int main() {
  test_apps_v1beta1_deployment_rollback(1);
  test_apps_v1beta1_deployment_rollback(0);

  printf("Hello world \n");
  return 0;
}

#endif // apps_v1beta1_deployment_rollback_MAIN
#endif // apps_v1beta1_deployment_rollback_TEST
