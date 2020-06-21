#ifndef apps_v1beta1_deployment_status_TEST
#define apps_v1beta1_deployment_status_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define apps_v1beta1_deployment_status_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/apps_v1beta1_deployment_status.h"
apps_v1beta1_deployment_status_t* instantiate_apps_v1beta1_deployment_status(int include_optional);



apps_v1beta1_deployment_status_t* instantiate_apps_v1beta1_deployment_status(int include_optional) {
  apps_v1beta1_deployment_status_t* apps_v1beta1_deployment_status = NULL;
  if (include_optional) {
    apps_v1beta1_deployment_status = apps_v1beta1_deployment_status_create(
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
    apps_v1beta1_deployment_status = apps_v1beta1_deployment_status_create(
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

  return apps_v1beta1_deployment_status;
}


#ifdef apps_v1beta1_deployment_status_MAIN

void test_apps_v1beta1_deployment_status(int include_optional) {
    apps_v1beta1_deployment_status_t* apps_v1beta1_deployment_status_1 = instantiate_apps_v1beta1_deployment_status(include_optional);

	cJSON* jsonapps_v1beta1_deployment_status_1 = apps_v1beta1_deployment_status_convertToJSON(apps_v1beta1_deployment_status_1);
	printf("apps_v1beta1_deployment_status :\n%s\n", cJSON_Print(jsonapps_v1beta1_deployment_status_1));
	apps_v1beta1_deployment_status_t* apps_v1beta1_deployment_status_2 = apps_v1beta1_deployment_status_parseFromJSON(jsonapps_v1beta1_deployment_status_1);
	cJSON* jsonapps_v1beta1_deployment_status_2 = apps_v1beta1_deployment_status_convertToJSON(apps_v1beta1_deployment_status_2);
	printf("repeating apps_v1beta1_deployment_status:\n%s\n", cJSON_Print(jsonapps_v1beta1_deployment_status_2));
}

int main() {
  test_apps_v1beta1_deployment_status(1);
  test_apps_v1beta1_deployment_status(0);

  printf("Hello world \n");
  return 0;
}

#endif // apps_v1beta1_deployment_status_MAIN
#endif // apps_v1beta1_deployment_status_TEST
