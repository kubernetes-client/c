#ifndef v1alpha1_webhook_TEST
#define v1alpha1_webhook_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1alpha1_webhook_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1alpha1_webhook.h"
v1alpha1_webhook_t* instantiate_v1alpha1_webhook(int include_optional);

#include "test_v1alpha1_webhook_client_config.c"
#include "test_v1alpha1_webhook_throttle_config.c"


v1alpha1_webhook_t* instantiate_v1alpha1_webhook(int include_optional) {
  v1alpha1_webhook_t* v1alpha1_webhook = NULL;
  if (include_optional) {
    v1alpha1_webhook = v1alpha1_webhook_create(
       // false, not to have infinite recursion
      instantiate_v1alpha1_webhook_client_config(0),
       // false, not to have infinite recursion
      instantiate_v1alpha1_webhook_throttle_config(0)
    );
  } else {
    v1alpha1_webhook = v1alpha1_webhook_create(
      NULL,
      NULL
    );
  }

  return v1alpha1_webhook;
}


#ifdef v1alpha1_webhook_MAIN

void test_v1alpha1_webhook(int include_optional) {
    v1alpha1_webhook_t* v1alpha1_webhook_1 = instantiate_v1alpha1_webhook(include_optional);

	cJSON* jsonv1alpha1_webhook_1 = v1alpha1_webhook_convertToJSON(v1alpha1_webhook_1);
	printf("v1alpha1_webhook :\n%s\n", cJSON_Print(jsonv1alpha1_webhook_1));
	v1alpha1_webhook_t* v1alpha1_webhook_2 = v1alpha1_webhook_parseFromJSON(jsonv1alpha1_webhook_1);
	cJSON* jsonv1alpha1_webhook_2 = v1alpha1_webhook_convertToJSON(v1alpha1_webhook_2);
	printf("repeating v1alpha1_webhook:\n%s\n", cJSON_Print(jsonv1alpha1_webhook_2));
}

int main() {
  test_v1alpha1_webhook(1);
  test_v1alpha1_webhook(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1alpha1_webhook_MAIN
#endif // v1alpha1_webhook_TEST
