#ifndef apps_v1beta1_scale_TEST
#define apps_v1beta1_scale_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define apps_v1beta1_scale_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/apps_v1beta1_scale.h"
apps_v1beta1_scale_t* instantiate_apps_v1beta1_scale(int include_optional);

#include "test_v1_object_meta.c"
#include "test_apps_v1beta1_scale_spec.c"
#include "test_apps_v1beta1_scale_status.c"


apps_v1beta1_scale_t* instantiate_apps_v1beta1_scale(int include_optional) {
  apps_v1beta1_scale_t* apps_v1beta1_scale = NULL;
  if (include_optional) {
    apps_v1beta1_scale = apps_v1beta1_scale_create(
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_v1_object_meta(0),
       // false, not to have infinite recursion
      instantiate_apps_v1beta1_scale_spec(0),
       // false, not to have infinite recursion
      instantiate_apps_v1beta1_scale_status(0)
    );
  } else {
    apps_v1beta1_scale = apps_v1beta1_scale_create(
      "0",
      "0",
      NULL,
      NULL,
      NULL
    );
  }

  return apps_v1beta1_scale;
}


#ifdef apps_v1beta1_scale_MAIN

void test_apps_v1beta1_scale(int include_optional) {
    apps_v1beta1_scale_t* apps_v1beta1_scale_1 = instantiate_apps_v1beta1_scale(include_optional);

	cJSON* jsonapps_v1beta1_scale_1 = apps_v1beta1_scale_convertToJSON(apps_v1beta1_scale_1);
	printf("apps_v1beta1_scale :\n%s\n", cJSON_Print(jsonapps_v1beta1_scale_1));
	apps_v1beta1_scale_t* apps_v1beta1_scale_2 = apps_v1beta1_scale_parseFromJSON(jsonapps_v1beta1_scale_1);
	cJSON* jsonapps_v1beta1_scale_2 = apps_v1beta1_scale_convertToJSON(apps_v1beta1_scale_2);
	printf("repeating apps_v1beta1_scale:\n%s\n", cJSON_Print(jsonapps_v1beta1_scale_2));
}

int main() {
  test_apps_v1beta1_scale(1);
  test_apps_v1beta1_scale(0);

  printf("Hello world \n");
  return 0;
}

#endif // apps_v1beta1_scale_MAIN
#endif // apps_v1beta1_scale_TEST
