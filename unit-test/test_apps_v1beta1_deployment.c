#ifndef apps_v1beta1_deployment_TEST
#define apps_v1beta1_deployment_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define apps_v1beta1_deployment_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/apps_v1beta1_deployment.h"
apps_v1beta1_deployment_t* instantiate_apps_v1beta1_deployment(int include_optional);

#include "test_v1_object_meta.c"
#include "test_apps_v1beta1_deployment_spec.c"
#include "test_apps_v1beta1_deployment_status.c"


apps_v1beta1_deployment_t* instantiate_apps_v1beta1_deployment(int include_optional) {
  apps_v1beta1_deployment_t* apps_v1beta1_deployment = NULL;
  if (include_optional) {
    apps_v1beta1_deployment = apps_v1beta1_deployment_create(
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_v1_object_meta(0),
       // false, not to have infinite recursion
      instantiate_apps_v1beta1_deployment_spec(0),
       // false, not to have infinite recursion
      instantiate_apps_v1beta1_deployment_status(0)
    );
  } else {
    apps_v1beta1_deployment = apps_v1beta1_deployment_create(
      "0",
      "0",
      NULL,
      NULL,
      NULL
    );
  }

  return apps_v1beta1_deployment;
}


#ifdef apps_v1beta1_deployment_MAIN

void test_apps_v1beta1_deployment(int include_optional) {
    apps_v1beta1_deployment_t* apps_v1beta1_deployment_1 = instantiate_apps_v1beta1_deployment(include_optional);

	cJSON* jsonapps_v1beta1_deployment_1 = apps_v1beta1_deployment_convertToJSON(apps_v1beta1_deployment_1);
	printf("apps_v1beta1_deployment :\n%s\n", cJSON_Print(jsonapps_v1beta1_deployment_1));
	apps_v1beta1_deployment_t* apps_v1beta1_deployment_2 = apps_v1beta1_deployment_parseFromJSON(jsonapps_v1beta1_deployment_1);
	cJSON* jsonapps_v1beta1_deployment_2 = apps_v1beta1_deployment_convertToJSON(apps_v1beta1_deployment_2);
	printf("repeating apps_v1beta1_deployment:\n%s\n", cJSON_Print(jsonapps_v1beta1_deployment_2));
}

int main() {
  test_apps_v1beta1_deployment(1);
  test_apps_v1beta1_deployment(0);

  printf("Hello world \n");
  return 0;
}

#endif // apps_v1beta1_deployment_MAIN
#endif // apps_v1beta1_deployment_TEST
