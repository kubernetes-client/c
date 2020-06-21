#ifndef apps_v1beta1_deployment_list_TEST
#define apps_v1beta1_deployment_list_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define apps_v1beta1_deployment_list_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/apps_v1beta1_deployment_list.h"
apps_v1beta1_deployment_list_t* instantiate_apps_v1beta1_deployment_list(int include_optional);

#include "test_v1_list_meta.c"


apps_v1beta1_deployment_list_t* instantiate_apps_v1beta1_deployment_list(int include_optional) {
  apps_v1beta1_deployment_list_t* apps_v1beta1_deployment_list = NULL;
  if (include_optional) {
    apps_v1beta1_deployment_list = apps_v1beta1_deployment_list_create(
      "0",
      list_create(),
      "0",
       // false, not to have infinite recursion
      instantiate_v1_list_meta(0)
    );
  } else {
    apps_v1beta1_deployment_list = apps_v1beta1_deployment_list_create(
      "0",
      list_create(),
      "0",
      NULL
    );
  }

  return apps_v1beta1_deployment_list;
}


#ifdef apps_v1beta1_deployment_list_MAIN

void test_apps_v1beta1_deployment_list(int include_optional) {
    apps_v1beta1_deployment_list_t* apps_v1beta1_deployment_list_1 = instantiate_apps_v1beta1_deployment_list(include_optional);

	cJSON* jsonapps_v1beta1_deployment_list_1 = apps_v1beta1_deployment_list_convertToJSON(apps_v1beta1_deployment_list_1);
	printf("apps_v1beta1_deployment_list :\n%s\n", cJSON_Print(jsonapps_v1beta1_deployment_list_1));
	apps_v1beta1_deployment_list_t* apps_v1beta1_deployment_list_2 = apps_v1beta1_deployment_list_parseFromJSON(jsonapps_v1beta1_deployment_list_1);
	cJSON* jsonapps_v1beta1_deployment_list_2 = apps_v1beta1_deployment_list_convertToJSON(apps_v1beta1_deployment_list_2);
	printf("repeating apps_v1beta1_deployment_list:\n%s\n", cJSON_Print(jsonapps_v1beta1_deployment_list_2));
}

int main() {
  test_apps_v1beta1_deployment_list(1);
  test_apps_v1beta1_deployment_list(0);

  printf("Hello world \n");
  return 0;
}

#endif // apps_v1beta1_deployment_list_MAIN
#endif // apps_v1beta1_deployment_list_TEST
