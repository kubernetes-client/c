#ifndef apps_v1beta1_rollback_config_TEST
#define apps_v1beta1_rollback_config_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define apps_v1beta1_rollback_config_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/apps_v1beta1_rollback_config.h"
apps_v1beta1_rollback_config_t* instantiate_apps_v1beta1_rollback_config(int include_optional);



apps_v1beta1_rollback_config_t* instantiate_apps_v1beta1_rollback_config(int include_optional) {
  apps_v1beta1_rollback_config_t* apps_v1beta1_rollback_config = NULL;
  if (include_optional) {
    apps_v1beta1_rollback_config = apps_v1beta1_rollback_config_create(
      56
    );
  } else {
    apps_v1beta1_rollback_config = apps_v1beta1_rollback_config_create(
      56
    );
  }

  return apps_v1beta1_rollback_config;
}


#ifdef apps_v1beta1_rollback_config_MAIN

void test_apps_v1beta1_rollback_config(int include_optional) {
    apps_v1beta1_rollback_config_t* apps_v1beta1_rollback_config_1 = instantiate_apps_v1beta1_rollback_config(include_optional);

	cJSON* jsonapps_v1beta1_rollback_config_1 = apps_v1beta1_rollback_config_convertToJSON(apps_v1beta1_rollback_config_1);
	printf("apps_v1beta1_rollback_config :\n%s\n", cJSON_Print(jsonapps_v1beta1_rollback_config_1));
	apps_v1beta1_rollback_config_t* apps_v1beta1_rollback_config_2 = apps_v1beta1_rollback_config_parseFromJSON(jsonapps_v1beta1_rollback_config_1);
	cJSON* jsonapps_v1beta1_rollback_config_2 = apps_v1beta1_rollback_config_convertToJSON(apps_v1beta1_rollback_config_2);
	printf("repeating apps_v1beta1_rollback_config:\n%s\n", cJSON_Print(jsonapps_v1beta1_rollback_config_2));
}

int main() {
  test_apps_v1beta1_rollback_config(1);
  test_apps_v1beta1_rollback_config(0);

  printf("Hello world \n");
  return 0;
}

#endif // apps_v1beta1_rollback_config_MAIN
#endif // apps_v1beta1_rollback_config_TEST
