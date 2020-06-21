#ifndef v1alpha1_webhook_throttle_config_TEST
#define v1alpha1_webhook_throttle_config_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1alpha1_webhook_throttle_config_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1alpha1_webhook_throttle_config.h"
v1alpha1_webhook_throttle_config_t* instantiate_v1alpha1_webhook_throttle_config(int include_optional);



v1alpha1_webhook_throttle_config_t* instantiate_v1alpha1_webhook_throttle_config(int include_optional) {
  v1alpha1_webhook_throttle_config_t* v1alpha1_webhook_throttle_config = NULL;
  if (include_optional) {
    v1alpha1_webhook_throttle_config = v1alpha1_webhook_throttle_config_create(
      56,
      56
    );
  } else {
    v1alpha1_webhook_throttle_config = v1alpha1_webhook_throttle_config_create(
      56,
      56
    );
  }

  return v1alpha1_webhook_throttle_config;
}


#ifdef v1alpha1_webhook_throttle_config_MAIN

void test_v1alpha1_webhook_throttle_config(int include_optional) {
    v1alpha1_webhook_throttle_config_t* v1alpha1_webhook_throttle_config_1 = instantiate_v1alpha1_webhook_throttle_config(include_optional);

	cJSON* jsonv1alpha1_webhook_throttle_config_1 = v1alpha1_webhook_throttle_config_convertToJSON(v1alpha1_webhook_throttle_config_1);
	printf("v1alpha1_webhook_throttle_config :\n%s\n", cJSON_Print(jsonv1alpha1_webhook_throttle_config_1));
	v1alpha1_webhook_throttle_config_t* v1alpha1_webhook_throttle_config_2 = v1alpha1_webhook_throttle_config_parseFromJSON(jsonv1alpha1_webhook_throttle_config_1);
	cJSON* jsonv1alpha1_webhook_throttle_config_2 = v1alpha1_webhook_throttle_config_convertToJSON(v1alpha1_webhook_throttle_config_2);
	printf("repeating v1alpha1_webhook_throttle_config:\n%s\n", cJSON_Print(jsonv1alpha1_webhook_throttle_config_2));
}

int main() {
  test_v1alpha1_webhook_throttle_config(1);
  test_v1alpha1_webhook_throttle_config(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1alpha1_webhook_throttle_config_MAIN
#endif // v1alpha1_webhook_throttle_config_TEST
