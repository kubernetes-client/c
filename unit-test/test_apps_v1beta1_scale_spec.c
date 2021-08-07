#ifndef apps_v1beta1_scale_spec_TEST
#define apps_v1beta1_scale_spec_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define apps_v1beta1_scale_spec_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/apps_v1beta1_scale_spec.h"
apps_v1beta1_scale_spec_t* instantiate_apps_v1beta1_scale_spec(int include_optional);



apps_v1beta1_scale_spec_t* instantiate_apps_v1beta1_scale_spec(int include_optional) {
  apps_v1beta1_scale_spec_t* apps_v1beta1_scale_spec = NULL;
  if (include_optional) {
    apps_v1beta1_scale_spec = apps_v1beta1_scale_spec_create(
      56
    );
  } else {
    apps_v1beta1_scale_spec = apps_v1beta1_scale_spec_create(
      56
    );
  }

  return apps_v1beta1_scale_spec;
}


#ifdef apps_v1beta1_scale_spec_MAIN

void test_apps_v1beta1_scale_spec(int include_optional) {
    apps_v1beta1_scale_spec_t* apps_v1beta1_scale_spec_1 = instantiate_apps_v1beta1_scale_spec(include_optional);

	cJSON* jsonapps_v1beta1_scale_spec_1 = apps_v1beta1_scale_spec_convertToJSON(apps_v1beta1_scale_spec_1);
	printf("apps_v1beta1_scale_spec :\n%s\n", cJSON_Print(jsonapps_v1beta1_scale_spec_1));
	apps_v1beta1_scale_spec_t* apps_v1beta1_scale_spec_2 = apps_v1beta1_scale_spec_parseFromJSON(jsonapps_v1beta1_scale_spec_1);
	cJSON* jsonapps_v1beta1_scale_spec_2 = apps_v1beta1_scale_spec_convertToJSON(apps_v1beta1_scale_spec_2);
	printf("repeating apps_v1beta1_scale_spec:\n%s\n", cJSON_Print(jsonapps_v1beta1_scale_spec_2));
}

int main() {
  test_apps_v1beta1_scale_spec(1);
  test_apps_v1beta1_scale_spec(0);

  printf("Hello world \n");
  return 0;
}

#endif // apps_v1beta1_scale_spec_MAIN
#endif // apps_v1beta1_scale_spec_TEST
