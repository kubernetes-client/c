#ifndef v1beta2_rolling_update_deployment_TEST
#define v1beta2_rolling_update_deployment_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1beta2_rolling_update_deployment_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1beta2_rolling_update_deployment.h"
v1beta2_rolling_update_deployment_t* instantiate_v1beta2_rolling_update_deployment(int include_optional);



v1beta2_rolling_update_deployment_t* instantiate_v1beta2_rolling_update_deployment(int include_optional) {
  v1beta2_rolling_update_deployment_t* v1beta2_rolling_update_deployment = NULL;
  if (include_optional) {
    v1beta2_rolling_update_deployment = v1beta2_rolling_update_deployment_create(
      0,
      0
    );
  } else {
    v1beta2_rolling_update_deployment = v1beta2_rolling_update_deployment_create(
      0,
      0
    );
  }

  return v1beta2_rolling_update_deployment;
}


#ifdef v1beta2_rolling_update_deployment_MAIN

void test_v1beta2_rolling_update_deployment(int include_optional) {
    v1beta2_rolling_update_deployment_t* v1beta2_rolling_update_deployment_1 = instantiate_v1beta2_rolling_update_deployment(include_optional);

	cJSON* jsonv1beta2_rolling_update_deployment_1 = v1beta2_rolling_update_deployment_convertToJSON(v1beta2_rolling_update_deployment_1);
	printf("v1beta2_rolling_update_deployment :\n%s\n", cJSON_Print(jsonv1beta2_rolling_update_deployment_1));
	v1beta2_rolling_update_deployment_t* v1beta2_rolling_update_deployment_2 = v1beta2_rolling_update_deployment_parseFromJSON(jsonv1beta2_rolling_update_deployment_1);
	cJSON* jsonv1beta2_rolling_update_deployment_2 = v1beta2_rolling_update_deployment_convertToJSON(v1beta2_rolling_update_deployment_2);
	printf("repeating v1beta2_rolling_update_deployment:\n%s\n", cJSON_Print(jsonv1beta2_rolling_update_deployment_2));
}

int main() {
  test_v1beta2_rolling_update_deployment(1);
  test_v1beta2_rolling_update_deployment(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1beta2_rolling_update_deployment_MAIN
#endif // v1beta2_rolling_update_deployment_TEST
