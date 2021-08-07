#ifndef v1alpha1_webhook_client_config_TEST
#define v1alpha1_webhook_client_config_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1alpha1_webhook_client_config_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1alpha1_webhook_client_config.h"
v1alpha1_webhook_client_config_t* instantiate_v1alpha1_webhook_client_config(int include_optional);

#include "test_v1alpha1_service_reference.c"


v1alpha1_webhook_client_config_t* instantiate_v1alpha1_webhook_client_config(int include_optional) {
  v1alpha1_webhook_client_config_t* v1alpha1_webhook_client_config = NULL;
  if (include_optional) {
    v1alpha1_webhook_client_config = v1alpha1_webhook_client_config_create(
      "YQ==",
       // false, not to have infinite recursion
      instantiate_v1alpha1_service_reference(0),
      "0"
    );
  } else {
    v1alpha1_webhook_client_config = v1alpha1_webhook_client_config_create(
      "YQ==",
      NULL,
      "0"
    );
  }

  return v1alpha1_webhook_client_config;
}


#ifdef v1alpha1_webhook_client_config_MAIN

void test_v1alpha1_webhook_client_config(int include_optional) {
    v1alpha1_webhook_client_config_t* v1alpha1_webhook_client_config_1 = instantiate_v1alpha1_webhook_client_config(include_optional);

	cJSON* jsonv1alpha1_webhook_client_config_1 = v1alpha1_webhook_client_config_convertToJSON(v1alpha1_webhook_client_config_1);
	printf("v1alpha1_webhook_client_config :\n%s\n", cJSON_Print(jsonv1alpha1_webhook_client_config_1));
	v1alpha1_webhook_client_config_t* v1alpha1_webhook_client_config_2 = v1alpha1_webhook_client_config_parseFromJSON(jsonv1alpha1_webhook_client_config_1);
	cJSON* jsonv1alpha1_webhook_client_config_2 = v1alpha1_webhook_client_config_convertToJSON(v1alpha1_webhook_client_config_2);
	printf("repeating v1alpha1_webhook_client_config:\n%s\n", cJSON_Print(jsonv1alpha1_webhook_client_config_2));
}

int main() {
  test_v1alpha1_webhook_client_config(1);
  test_v1alpha1_webhook_client_config(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1alpha1_webhook_client_config_MAIN
#endif // v1alpha1_webhook_client_config_TEST
